#include "OrthoCamera.h"

OrthoCamera::OrthoCamera() : Camera() { }

OrthoCamera::OrthoCamera(Vector3 e, Vector3 look, float near, float far)
        : Camera(e, look, near, far){ }

float colorDiff(LightIntensity lights[5]){
    //auto p = std::minmax(lights);
    //return(p.second - p.first);
    return 0.5f;
}

LightIntensity colorPoint(float x, float y, Ray ray, float plane,
                          Tracer *tracer){
    Vector3 vc = (Vector3(x, y, plane));
    ray.setOrigin(vc);
    return tracer->rayTrace(ray);
}

LightIntensity innerSampler(int depth, float pixS, Vector3 point,
                            LightIntensity intern, Ray ray, Tracer* tracer,
                            float plane){
    LightIntensity a, b, c, d, e;

    a = colorPoint(point.getX(), point.getY(), ray, plane, tracer);
    b = colorPoint(point.getX()+pixS*0.5f, point.getY(), ray, plane, tracer);
    c = colorPoint(point.getX()+pixS*0.5f,
                   point.getY()+pixS*0.5f, ray, plane, tracer);
    d = colorPoint(point.getX(),
                        point.getY()+pixS*0.5f, ray, plane, tracer);
    e = colorPoint(point.getX()*0.5f, point.getY()*0.5f, ray, plane, tracer);

    LightIntensity lights[] = {a, b, c, d, e};
    LightIntensity sum = LightIntensity(0.0f, 0.0f, 0.0f); //FIXME
    float diff = colorDiff(lights);

    if(depth > MAX_DEPTH || diff < SPATIAL) {
        return intern;
    }
    else{
        intern = intern + sum;
        innerSampler((depth + 1), pixS, point, intern, ray, tracer, plane);
    }

}

LightIntensity sampler(float pixS, Vector3 point, float plane, Tracer *tracer){
    LightIntensity colorA, colorB, colorD, colorE, a, b, c, d, e;
    Ray ray;
    ray.setDirection(Vector3(0.0f, 0.0f, 1.0f));

    colorA = colorPoint(point.getX(), point.getY(), ray, plane, tracer);
    colorB = colorPoint(point.getX()+pixS*0.5f, point.getY(), ray, plane, tracer);
    colorD = colorPoint(point.getX(),
                        point.getY()+pixS*0.5f, ray, plane, tracer);
    colorE = colorPoint(point.getX()*0.5f, point.getY()*0.5f, ray, plane, tracer);

    a = colorA + colorE;
    a = a *0.5f;
    b = colorB + colorE;
    b = b *0.5f;
    c = (colorD + colorE);
    c = c * 0.5f;
    c = c + a;
    c = c + b;
    d = innerSampler(0, 1.0f, point, LightIntensity(0.0f, 0.0f, 0.0f),
            ray, tracer, plane);//!!
    d = d * 0.5f;
    e = c + d;

    return 0.25f * e;
}

EngineImage
OrthoCamera::renderScene(ViewPlane &plane, LightIntensity &light, Tracer *tracer) {
    LightIntensity color;
    std::string name = tracer->sceneName();
    EngineImage image = EngineImage(plane.getWRes(), plane.getHRes(), light,
                                    name);
    image.resetPixels(light);
    float x, y;
    Ray ray;
    Vector3 vc;

    ray.setDirection(Vector3(0.0f, 0.0f, 1.0f));
    for(unsigned int r = 0; r < plane.getWRes(); r++){ //up
        for(unsigned int c = 0; c < plane.getHRes(); c++){ //horizontal
            x = plane.getPixSize() * (c - 0.5f *(plane.getHRes() - 1.0f));
            y = plane.getPixSize() * (r - 0.5f *(plane.getWRes() - 1.0f));
            vc = (Vector3(x, y, Camera::nearPlane));
            ray.setOrigin(vc);
            color = tracer->rayTrace(ray);
            image.setPixel((int)r, (int)c, color);
        }
    }
    return image;
}