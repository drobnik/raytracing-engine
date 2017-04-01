#include "ObjParser.h"

ObjParser::ObjParser() {

}

ObjParser::~ObjParser() {
    objFormat = {{"#", comment},
                 {"v", geoVerticle},
                 {"vt", norVerticle},
                 {"vn", texVerticle},
                 {"g", group},
                 {"f", face},
                 {"mtlib", loadMaterial},
                 {"usemtl", useMaterial}};
}

ObjParser::ObjParser(const ObjParser &p) {
    verticles = p.verticles;
    normals = p.normals;
    texCoords = p.texCoords;
    triangles = p.triangles;
    currentMaterial = p.currentMaterial;
}

Mesh ObjParser::loadMesh(std::ifstream file) {
    std::string line, token;
    std::vector<std::string> tokens;

    while(!file.eof()){
        while(std::getline(file, line, ' ')){
            std::stringstream str(line);
            str >> token;
            tokens.push_back(token);
        }

        parseLine(tokens);
        tokens.clear();
    }

    return Mesh(triangles);
}

void ObjParser::parseLine(std::vector<std::string> vec) {
    if(vec.at(0) == "party"){

    }
}
