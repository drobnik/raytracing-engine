#include "AdaptiveSampler.h"

AdaptiveSampler::AdaptiveSampler()
        : direction(Vector3(0.0f, 0.0f, 1.0f)),
          ra(Ray()),
          rb(Ray()),
          rc(Ray()),
          rd(Ray()) {}

LightIntensity AdaptiveSampler::AdaptiveSampling(Ray &ray, std::unique_ptr<Tracer> const &tracer, float pixSize,
                               int depth, bool isOrtho) {
    float offset;
    LightIntensity la, lb, lc, ld, le, final;

    if(isOrtho){
        ra.setDirection(direction);
        rb.setDirection(direction);
        rc.setDirection(direction);
        rd.setDirection(direction);
    }

    if(depth >= MAX_DEPTH){
        final = tracer->rayTrace(ray);
        resetRays();
        return final;
    }
    else{
        offset = pixSize * (float)pow(0.5f, (depth+1));

        if(isOrtho){
            orthoSetup(ray, offset);
        }
        else{
            perspectiveSetup(ray, offset);
        }

        le = tracer->rayTrace(ray);
        la = tracer->rayTrace(ra);
        lb = tracer->rayTrace(rb);
        lc = tracer->rayTrace(rc);
        ld = tracer->rayTrace(rd);

        if(le != la){
            la = AdaptiveSampling(ray, tracer, pixSize, (depth + 1), isOrtho);
        }
        else if(le != lb){
            lb = AdaptiveSampling(ray, tracer, pixSize, (depth + 1), isOrtho);
        }
        else if(le != lc){
            lc = AdaptiveSampling(ray, tracer, pixSize, (depth + 1), isOrtho);
        }
        else if(le != ld){
            ld = AdaptiveSampling(ray, tracer, pixSize, (depth + 1), isOrtho);
        }

        float finR, finG, finB;
        finR = (la.Red() + lb.Red() + lc.Red() + ld.Red())/4.0f;
        finG = (la.Green() + lb.Green() + lc.Green() + ld.Green())/4.0f;
        finB = (la.Blue() + lb.Blue() + lc.Blue() + ld.Blue())/4.0f;

        final = LightIntensity(finR, finG, finB);
        resetRays();

        return final;
    }
}

void AdaptiveSampler::orthoSetup(const Ray& ray, float offset) {
    ra.setOrigin(Vector3(ray.getOrigin().getX() - offset, ray.getOrigin().getY(),
                         ray.getOrigin().getZ()));
    rb.setOrigin(Vector3(ray.getOrigin().getX() - offset,
                         ray.getOrigin().getY()  - offset,
                         ray.getOrigin().getZ()));
    rc.setOrigin(Vector3(ray.getOrigin().getX(), ray.getOrigin().getY(),
                         ray.getOrigin().getZ()));
    rd.setOrigin(Vector3(ray.getOrigin().getX(), ray.getOrigin().getY() - offset,
                         ray.getOrigin().getZ()));
}

void AdaptiveSampler::perspectiveSetup(const Ray& ray, float offset) {
    Vector3 origin = ray.getOrigin();

    ra.setOrigin(origin), rb.setOrigin(origin), rc.setOrigin(origin);
    rd.setOrigin(origin);

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
}

void AdaptiveSampler::resetRays() {
    ra.resetRay();
    rb.resetRay();
    rc.resetRay();
    rd.resetRay();
}


const int AdaptiveSampler::MAX_DEPTH = 3;
