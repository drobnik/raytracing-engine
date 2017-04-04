#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera() : Camera(){ }

PerspectiveCamera::PerspectiveCamera(Vector3 e, Vector3 look, float near,
                                     float far) : Camera(e, look, near, far){
    Camera::fieldOfView = 45;
}
//FIXME
int is = 0, ia = 0;
LightIntensity sampler1(int depth, Ray& ray, Tracer* tracer){ //add viewplane

    LightIntensity la, lb, lc, ld, le, final;
    Vector3 direction = ray.getDirection();//Vector3(0.0f, 0.0f, 1.0f);
    Vector3 orgi = ray.getOrigin();
   //
    // std::cout<<direction<<"\n";
    Ray sampleR = ray;
    Ray ra, rb, rc, rd;
    float offset;

    if(depth >= ANTI_MAX){
        // FIXME
        final = tracer->rayTrace(ray);
        return final;
    }
    else{
        //offset = 1.0f * (float)pow(0.5f, (depth + 1));
        offset = 1.0f * (float)pow(0.5f, (depth+1));

        ra.setOrigin(orgi);
        rb.setOrigin(orgi);
        rc.setOrigin(orgi);
        rd.setOrigin(orgi);

        ra.setDirection(Vector3(ray.getDirection().getX() - offset,
                                ray.getDirection().getY() - offset,
                                ray.getDirection().getZ()).normalize());
        rb.setDirection(Vector3(ray.getDirection().getX() + offset,
                                ray.getDirection().getY()  - offset,
                                ray.getDirection().getZ()).normalize());
        rc.setDirection(Vector3(ray.getDirection().getX() + offset,
                                ray.getDirection().getY() + offset,
                             ray.getDirection().getZ()).normalize());
        rd.setDirection(Vector3(ray.getDirection().getX() - offset,
                                ray.getDirection().getY() + offset,
                             ray.getDirection().getZ()).normalize());

        le = tracer->rayTrace(ray);
        la = tracer->rayTrace(ra);
        lb = tracer->rayTrace(rb);
        lc = tracer->rayTrace(rc);
        ld = tracer->rayTrace(rd);
        if(le != la){
            la = sampler1((depth + 1), ray, tracer);
        }
        else if(le != lb){
            lb = sampler1((depth + 1), ray, tracer);
        }
        else if(le != lc){
            lc = sampler1((depth + 1), ray, tracer);
        }
        else if(le != ld){
            ld = sampler1((depth + 1), ray, tracer);
        }

        float finR, finG, finB;
        finR = (la.red() + lb.red() + lc.red() + ld.red())/4.0f;
        finG = (la.green() + lb.green() + lc.green() + ld.green())/4.0f;
        finB = (la.blue() + lb.blue() + lc.blue() + ld.blue())/4.0f;

        //calc colors!
        final = LightIntensity(finR, finG, finB);
        return final;
    }
}
EngineImage
PerspectiveCamera::renderScene(ViewPlane &plane, LightIntensity &light,
                               Tracer *tracer) {
    LightIntensity color;
    std::string name = tracer->sceneName();
    EngineImage image = EngineImage(plane.getWRes(), plane.getHRes(), light,
                                    name);
    image.resetPixels(light);
    float x, y;
    float d;
    Ray ray;
    Vector3 vo;

    ray.setOrigin(eye);
    Camera::calcUVW();
    for(unsigned int r = 0; r < plane.getWRes(); r++){ //up
        for(unsigned int c = 0; c < plane.getHRes(); c++){ //horizontal
            x = plane.getPixSize() * (c - 0.5f *(plane.getHRes() - 1.0f));
            y = plane.getPixSize() * (r - 0.5f *(plane.getWRes() - 1.0f));
            vo = Vector3(x, y, nearPlane) - eye;
            d = vo.length();
            ray.setDirection(Vector3(x, y, d));
            color = sampler1(0,ray,tracer);
            image.setPixel((int)r, (int)c, color);
        }
    }
    return image;
}
