#ifndef RAYTRACING_ENGINE_OBJPARSER_H
#define RAYTRACING_ENGINE_OBJPARSER_H
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <utility>
#include "../Geometry/Vector3.h"
#include "../Materials/Material.h"
#include "../Geometry/Objects/Mesh.h"

//typedef groupName std::string;

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
    geoOnly, //a
    geoNor,  // a//b
    geoTexNor, //a/b/c
};

class ObjParser {
private:
    std::vector<Vector3> verticles;//TODO pair <vector3, float> aka weight
    std::vector<Vector3> normals;
    std::vector<Vector3> texCoords; //to be used later?
    std::vector<Triangle> triangles;
    Material currentMaterial;
    std::map<const std::string, objCommand> objFormat;
    std::string currentGroup;
    std::map<std::string, Vector3*> groups; //string -> group name

    int parseLine(std::vector<std::string> vec);
    int parseVerticle(std::vector<std::string> vec);
    int parseNorVerticle(std::vector<std::string> vec);
    int parseTexVerticle(std::vector<std::string> vec);
    int parseGroup(std::vector<std::string> vec);
    int parseFace(std::vector<std::string> vec);
    int parseMatFile(std::vector<std::string> vec);
    int parseUseMaterial(std::vector<std::string> vec);
    Vector3 createVerticle(std::vector<std::string> vec);
    faceState faceMode(std::string str);
    std::vector<int> faceIntoTokens(std::string delimiter,
                                             std::string s);
    int makeFace(std::vector<int>, std::vector<int>, std::vector<int>, faceState);

public:
    ObjParser();
    ~ObjParser();
    ObjParser(const ObjParser& p);
    Mesh loadMesh(std::ifstream file);
};


#endif //RAYTRACING_ENGINE_OBJPARSER_H
