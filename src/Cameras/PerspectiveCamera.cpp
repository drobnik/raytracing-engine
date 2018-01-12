#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(const Vector3& e, const Vector3& look, const Vector3& u,
                                     unsigned int height, unsigned int width, float pixSize, float field)
        : Camera(e, look, u, height, width, pixSize) {
    fieldOfView = field;
    // if distance is default -> calculate from field(ofView)
    calculateViewDistance();
    zoom = 4.0f;
}

LightIntensity sampler1(int depth, Ray &ray, const std::unique_ptr<Tracer>& tracer, float &pixSize) {

    LightIntensity la, lb, lc, ld, le, final;
    Vector3 direction = ray.getDirection();
    Vector3 orgi = ray.getOrigin();

    Ray sampleR = ray;
    Ray ra, rb, rc, rd;
    float offset;

    if(depth >= Camera::ANTI_MAX){
        final = tracer->rayTrace(ray);
        return final;
    }
    else{
        offset = pixSize * (float)pow(0.5f, (depth+1));

        ra.setOrigin(orgi), rb.setOrigin(orgi), rc.setOrigin(orgi);
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
            la = sampler1((depth + 1), ray, tracer, pixSize);
        }
        else if(le != lb){
            lb = sampler1((depth + 1), ray, tracer, pixSize);
        }
        else if(le != lc){
            lc = sampler1((depth + 1), ray, tracer, pixSize);
        }
        else if(le != ld){
            ld = sampler1((depth + 1), ray, tracer, pixSize);
        }

        float finR, finG, finB;
        finR = (la.red() + lb.red() + lc.red() + ld.red())/4.0f;
        finG = (la.green() + lb.green() + lc.green() + ld.green())/4.0f;
        finB = (la.blue() + lb.blue() + lc.blue() + ld.blue())/4.0f;

        final = LightIntensity(finR, finG, finB);
        return final;
    }
}
EngineImage PerspectiveCamera::RenderScene(LightIntensity &background, std::unique_ptr<Tracer> const &tracer) {
    LightIntensity color;
    std::string name = tracer->sceneName();
    EngineImage image = EngineImage(viewHeight, viewWidth, background, name);

    image.resetPixels(background);
    float x, y;
    float d;
    Ray ray;
    Vector3 vo;

    ray.setOrigin(eye);
    //Camera::calcUVW();
    for(unsigned int r = 0; r < viewHeight; r++){ //up
        for(unsigned int c = 0; c < viewWidth; c++){ //horizontal
            x = pixelSize * (c - 0.5f *(viewWidth - 1.0f));
            y = pixelSize * (r - 0.5f *(viewHeight - 1.0f));
            vo = Vector3(x, y, viewDistance) - eye;
            d = vo.length();
            ray.setDirection(Vector3(x, y, d));
            color = sampler1(0,ray,tracer,pixelSize);//
            image.setPixel((int)r, (int)c, color);
        }
    }
    return image;
}

PerspectiveCamera::PerspectiveCamera(const PerspectiveCamera& cam) :
        Camera(cam),
        fieldOfView(cam.fieldOfView){ }

void PerspectiveCamera::calculateViewDistance(){
    viewDistance = 400.0f;//viewWidth / (2.0f * tanf(Utility::degToRad(fieldOfView) * 0.5f));
}