#ifndef RAYTRACING_ENGINE_UTILITIES_H
#define RAYTRACING_ENGINE_UTILITIES_H
#include "Vector3.h"
#include "Primitive.h"

namespace Utility {
    void logResults(const rayState &state, const std::string &rayName, const std::string &primitive);
    void logPoint(Vector3 point, rayState& state);
};

#endif //RAYTRACING_ENGINE_UTILITIES_H
