#include "../include/Utility.h"

namespace Utility {
    void logPoint(Vector3 point, rayState &state) {
        if(state > 0) {
            std::cout << "The nearest point of intersection: " << point <<"\n";
        }
    }

    void logResults(const rayState &state, const std::string &rayName, const std::string &primitive) {
        std::cout << "Ray " << rayName << " ";
        if(state > 0){
            std::cout << "intersects a " << primitive;
            if(state == 1) std::cout << " in 2 points.\n";
            else if(state == 3) std::cout << " in 1 point from the back.\n";
            else std::cout << " in 1 point.\n";
        }
        if(state == 0) std::cout <<"misses the primitive.\n\n";
    }
};