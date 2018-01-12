#include "OrthoCamera.h"

OrthoCamera::OrthoCamera(const Vector3 &e, const Vector3 &look, unsigned int height, unsigned int width, float pixSize,
                         const Vector3 &u) : Camera(e, look, u, width, height, pixSize) {
    viewDistance = 0;
    zoom = 4.0f;
}

OrthoCamera::OrthoCamera(const OrthoCamera& cam) : Camera(cam){ }

// check it later
LightIntensity sampler(int depth, Ray &ray, std::unique_ptr<Tracer> const &tracer, float pixSize) {

    LightIntensity la, lb, lc, ld, le, final;
    Vector3 direction = Vector3(0.0f, 0.0f, 1.0f);
    Ray sampleR = ray;
    Ray ra, rb, rc, rd;
    ra.setDirection(direction);
    rb.setDirection(direction);
    rc.setDirection(direction);
    rd.setDirection(direction);
    float offset;

    if(depth >= Camera::ANTI_MAX){
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

EngineImage OrthoCamera::RenderScene(LightIntensity &background, std::unique_ptr<Tracer> const &tracer) {
    LightIntensity pixelColor = LightIntensity(1.0f, 1.0f, 1.0f);
    std::string sceneName = tracer->sceneName();
    EngineImage image = EngineImage(viewHeight, viewWidth, background, sceneName);

    Ray ray = Ray(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f));
    pixelSize = pixelSize / zoom;
    float x, y;
    image.resetPixels(background);

    for(size_t r = 0; r < viewHeight; r++){ //up
        for(size_t c = 0; c < viewWidth; c++){ //horizontal
            x = pixelSize * (c - 0.5f *(viewWidth - 1.0f));
            y = pixelSize * (r - 0.5f *(viewHeight - 1.0f));

            ray.setOrigin(Vector3(x, y, viewDistance));
            ray.setDirection(Vector3(0.0f, 0.0f, -1.0f));

            pixelColor = sampler(0, ray, tracer, pixelSize);
            image.setPixel((int)r, (int)c, pixelColor);
        }
    }
    return image;
}
