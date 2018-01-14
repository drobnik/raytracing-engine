#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(const Vector3& e, const Vector3& look, const Vector3& u,
                                     unsigned int height, unsigned int width, float pixSize,
                                     const std::shared_ptr<AdaptiveSampler>& sampler, float field)
        : Camera(e, look, u, height, width, pixSize, sampler) {
    fieldOfView = field;
    // if distance is default -> calculate from field(ofView)
    calculateViewDistance();
    zoom = 4.0f;
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

    for(unsigned int r = 0; r < viewHeight; r++){ //up
        for(unsigned int c = 0; c < viewWidth; c++){ //horizontal
            x = pixelSize * (c - 0.5f *(viewWidth - 1.0f));
            y = pixelSize * (r - 0.5f *(viewHeight - 1.0f));
            vo = Vector3(x, y, viewDistance) - eye;
            d = vo.length();
            ray.setDirection(Vector3(x, y, d));
            color =  sampler->AdaptiveSampling(ray, tracer, pixelSize, 0, false);
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