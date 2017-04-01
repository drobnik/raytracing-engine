#ifndef RAYTRACING_ENGINE_OBJPARSER_H
#define RAYTRACING_ENGINE_OBJPARSER_H
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "../Geometry/Vector3.h"
#include "../Materials/Material.h"
#include "../Geometry/Objects/Mesh.h"

enum objCommand{
    comment,
    geoVerticle,
    texVerticle,
    norVerticle,
    group,
    face,
    loadMaterial,
    useMaterial
};

//to avoid illegal statements
enum faceState{
    none, // no face is processed
    geoOnly, //a
    geoNor,  // a//b
    geoTexNor, //a/b/c
};

class ObjParser {
private:
    faceState faceMode;
    std::vector<Vector3> verticles;//TODO pair <vector3, float> aka weight
    std::vector<Vector3> normals;
    std::vector<Vector3> texCoords; //to be used later?
    std::vector<Triangle> triangles;
    Material currentMaterial;
    std::map<const std::string, objCommand> objFormat;
    void parseLine(std::vector<std::string> vec);
public:
    ObjParser();
    ~ObjParser();
    ObjParser(const ObjParser& p);
    Mesh loadMesh(std::ifstream file);
};


#endif //RAYTRACING_ENGINE_OBJPARSER_H
