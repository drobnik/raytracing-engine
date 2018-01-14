#include "OrthoCamera.h"

OrthoCamera::OrthoCamera(const Vector3 &e, const Vector3 &look, unsigned int height, unsigned int width, float pixSize,
                         const std::shared_ptr<AdaptiveSampler>& sampler, const Vector3 &u)
        : Camera(e, look, u, width, height, pixSize, sampler) {
    viewDistance = 0;
    zoom = 6.0f;
}

OrthoCamera::OrthoCamera(const OrthoCamera& cam) : Camera(cam){ }

EngineImage OrthoCamera::RenderScene(LightIntensity &background, std::unique_ptr<Tracer> const &tracer) {
    LightIntensity pixelColor;
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

            pixelColor = sampler->AdaptiveSampling(ray, tracer, pixelSize, 0, true);
            image.setPixel((int)r, (int)c, pixelColor);
        }
    }
    return image;
}
