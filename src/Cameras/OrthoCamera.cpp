#include "OrthoCamera.h"

OrthoCamera::OrthoCamera() : Camera() { }

OrthoCamera::OrthoCamera(Vector3 e, Vector3 look, float near, float far)
        : Camera(e, look, near, far){ }

LightIntensity sampler(int depth, Ray &ray, std::shared_ptr<Tracer> tracer, float pixSize) { //add viewplane

    LightIntensity la, lb, lc, ld, le, final;
    Vector3 direction = Vector3(0.0f, 0.0f, 1.0f);
    Ray sampleR = ray;
    Ray ra, rb, rc, rd;
    ra.setDirection(direction);
    rb.setDirection(direction);
    rc.setDirection(direction);
    rd.setDirection(direction);
    float offset;

    if(depth >= ANTI_MAX){
        final = tracer->rayTrace(ray);
        return final;
    }
    else{
        offset = pixSize * (float)pow(0.5f, (depth + 1)); //FIXME 0.5f
        ra.setOrigin(Vector3(ray.getOrigin().getX() - offset, ray.getOrigin().getY(), //directio
                             ray.getOrigin().getZ()));
        rb.setOrigin(Vector3(ray.getOrigin().getX() - offset,
                             ray.getOrigin().getY()  - offset,
                             ray.getOrigin().getZ()));
        rc.setOrigin(Vector3(ray.getOrigin().getX(), ray.getOrigin().getY(),
                             ray.getOrigin().getZ()));
        rd.setOrigin(Vector3(ray.getOrigin().getX(), ray.getOrigin().getY() - offset,
                             ray.getOrigin().getZ()));

        //middle first
        le = tracer->rayTrace(ray);
        la = tracer->rayTrace(ra);
        lb = tracer->rayTrace(rb);
        lc = tracer->rayTrace(rc);
        ld = tracer->rayTrace(rd);

        if(le != la){
            la = sampler((depth + 1), ray, tracer, pixSize);
        }
        else if(le != lb){
            lb = sampler((depth + 1), ray, tracer, pixSize);
        }
        else if(le != lc){
            lc = sampler((depth + 1), ray, tracer, pixSize);
        }
        else if(le != ld){
            ld = sampler((depth + 1), ray, tracer, pixSize);
        }

        float finR, finG, finB;
        finR = (la.red() + lb.red() + lc.red() + ld.red())/4.0f;
        finG = (la.green() + lb.green() + lc.green() + ld.green())/4.0f;
        finB = (la.blue() + lb.blue() + lc.blue() + ld.blue())/4.0f;

        final = LightIntensity(finR, finG, finB);
        return final;
    }
}

EngineImage
OrthoCamera::renderScene(ViewPlane &plane, LightIntensity &light, std::shared_ptr<Tracer> tracer) {
    //the camera works on the exact size of the image, not its resolution.
    LightIntensity color;
    std::string name = tracer->sceneName();
    EngineImage image = EngineImage(plane.getWRes(), plane.getHRes(), light,
                                    name);
    Ray ray;
    Vector3 vc;

    float x, y;
    image.resetPixels(light);
    calcUVW();

    Vector3 direction = u * lookAt.getX() + (v * lookAt.getY() - w * lookAt.getZ());
    direction = direction.normalize();
    ray.setDirection(direction);

    for(unsigned int r = 0; r < (unsigned)plane.getWRes(); r++){ //up
        for(unsigned int c = 0; c < (unsigned)plane.getHRes(); c++){ //horizontal
            x = plane.getPixSize() * (c - 0.5f *(plane.getHRes() - 1.0f));
            y = plane.getPixSize() * (r - 0.5f *(plane.getWRes() - 1.0f));
            vc = (Vector3(x, y, eye.getZ()));
            ray.setOrigin(vc);
            color = sampler(0, ray, tracer, plane.getPixSize());//t
            image.setPixel((int)r, (int)c, color);
        }
    }
    return image;
}