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
    currentGroup = p.currentGroup;
}

Mesh ObjParser::loadMesh(std::ifstream file) {
    std::string line, token;
    int state;
    std::vector<std::string> tokens;

    while(!file.eof()){
        while(std::getline(file, line, ' ')){
            std::stringstream str(line);
            str >> token;
            tokens.push_back(token);
        }

        state = parseLine(tokens);

        if(state != 0){
            std::cout<<"WARNING! OBJ parsing finished with errors. "
                    "Incomplete mesh loaded.";
            return Mesh(triangles);
        }

        tokens.clear();
    }
    return Mesh(triangles);
}

int ObjParser::parseLine(std::vector<std::string> vec) {

    std::map<const std::string, objCommand>::const_iterator
            i = objFormat.find(vec.at(0));

    if (i == objFormat.end()) {
        std::cout << "Syntax error!\n";
        return -1;
    } else {
        objCommand token = i->second;
        vec.erase(vec.begin()); //!!

        if (token == comment) return 0; //nothing to do here
        else if (token == geoVerticle) return parseVerticle(vec);
        else if (token == norVerticle) return parseNorVerticle(vec);
        else if (token == texVerticle) return parseTexVerticle(vec);
        else if (token == group) return parseGroup(vec);
        else if (token == face) return parseFace(vec);
        else if (token == loadMaterial) return parseMatFile(vec);
        else if (token == useMaterial) return parseUseMaterial(vec);
    }
    return 0;
}

Vector3 ObjParser::createVerticle(std::vector<std::string> vec) {
    float x, y, z;
    assert(vec.size() < 3);

    x = (float)std::stod(vec.at(0));
    y = (float)std::stod(vec.at(1));
    z = (float)std::stod(vec.at(2));
    Vector3 point = Vector3(x, y, z);

    return point;
}

int ObjParser::parseVerticle(std::vector<std::string> vec) {
    Vector3 point = createVerticle(vec);
    Vector3* ptr = &point;
    if(!currentGroup.empty()){
        groups.insert(std::pair<std::string, Vector3*>(currentGroup, ptr));
    }
    verticles.push_back(point);
    return 0;
}

int ObjParser::parseNorVerticle(std::vector<std::string> vec) {
    Vector3 point = createVerticle(vec);
    Vector3* ptr = &point;
    if(!currentGroup.empty()){
        groups.insert(std::pair<std::string, Vector3*>(currentGroup, ptr));
    }
    normals.push_back(point);
    return 0;
}

int ObjParser::parseTexVerticle(std::vector<std::string> vec) {
    Vector3 point = createVerticle(vec);
    Vector3* ptr = &point;
    if(!currentGroup.empty()){
        groups.insert(std::pair<std::string, Vector3*>(currentGroup, ptr));
    }
    texCoords.push_back(point);
    return 0;
}

int ObjParser::parseGroup(std::vector<std::string> vec) {
    if(vec.size() > 1){
        std::string groups;
        for(std::vector<std::string>::iterator i = vec.begin()+1; i != vec.end();
        ++i){
            groups = groups + " " + *i;
        }
        currentGroup = groups;
    } else{
        currentGroup = vec.at(0);
    }
    return 0;
}

int ObjParser::parseFace(std::vector<std::string> vec) {
    faceState globalState = faceMode(vec.at(0));
    return 0;
}

int ObjParser::parseMatFile(std::vector<std::string> vec) {
    return 0;
}

int ObjParser::parseUseMaterial(std::vector<std::string> vec) {
    return 0;
}

faceState ObjParser::faceMode(std::string str) {
    std::string doubleSlash = "//";
    std::string one = "/";
    std::size_t doubleFound = str.find(doubleSlash);
    std::size_t oneFound = str.find(one);

    if(doubleFound != std::string::npos){
        return geoNor;
    } else if(oneFound != std::string::npos){
        return geoTexNor;
    }

    return geoOnly;
}
