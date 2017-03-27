#ifndef RAYTRACING_ENGINE_VIEWPLANE_H
#define RAYTRACING_ENGINE_VIEWPLANE_H


class ViewPlane {
private:
    int hResolution;
    int wResolution;
    float pixSize;
    float gamma;    //- monitor gamma factor

public:
    int getHRes() const;
    int getWRes() const;
    float getPixSize() const;
    void HRes(int hResolution);
    void WRes(int wResolution);
    void setPixSize(float pixSize);
    float getGamma() const;
    void setGamma(float gamma);
};


#endif //RAYTRACING_ENGINE_VIEWPLANE_H
