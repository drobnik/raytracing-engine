#include "ObjParser.h"

ObjParser::ObjParser() {
    objFormat = {{"#", comment},
                 {"v", geoVerticle},
                 {"vt", norVerticle},
                 {"vn", texVerticle},
                 {"g", group},
                 {"f", face},
                 {"mtlib", loadMaterial},
                 {"usemtl", useMaterial}};
}

ObjParser::~ObjParser() { }

ObjParser::ObjParser(const ObjParser &p) {
    verticles = p.verticles;
    normals = p.normals;
    texCoords = p.texCoords;
    triangles = p.triangles;
    currentMaterial = p.currentMaterial;
    currentGroup = p.currentGroup;
}

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

Mesh ObjParser::loadMesh(std::ifstream &file) {
    std::string line, token;
    int state;
    std::vector<std::string> tokens;

    while(!file.eof()){
        while(std::getline(file, line)) {
            tokens = split(line, ' ');
            state = parseLine(tokens);

            if (state != 0) {
                std::cout << "WARNING! OBJ parsing finished with errors. "
                        "Incomplete mesh loaded.\n";
                return Mesh(triangles);
            }

            tokens.clear();
        }
    }
    std::cout << "Mesh loaded.\n";
    return Mesh(triangles);
}

int ObjParser::parseLine(std::vector<std::string> vec) {
    if(!vec.empty()){
        if(vec.at(0).empty()){
            return 0;
        }
    } else return 0;

    std::map<const std::string, ObjCommand>::const_iterator
            i = objFormat.find(vec.at(0));

    if (i == objFormat.end()) {
        std::cout << "Syntax error!\n";
        return -1;
    } else {
        ObjCommand token = i->second;
        vec.erase(vec.begin());

        if (token == comment) return 0;
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
    assert(vec.size() == 3);

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
    faceState currentState;
    std::vector<int> verticleIndexes;
    std::vector<int> verticleNorIndexes;
    std::vector<int> verticleTexIndexes;
    std::vector<int> temp;

    if(globalState == geoOnly){
        for(std::vector<std::string>::iterator i = vec.begin(); i != vec.end();
                i++){
            currentState = faceMode(*i);
            if(currentState == globalState){
                verticleIndexes.push_back(stoi(*i));
            } else{
                std::cout<<"Syntax error in face definition!\n";
                return -1;
            }
        }
    } else if(globalState == geoNor){
        for(std::vector<std::string>::iterator i = vec.begin(); i != vec.end();
            i++){
            currentState = faceMode(*i);
            if(currentState == globalState){
                temp = faceIntoTokens("//", *i);
                assert(temp.size() == 2);

                int geo = temp.at(0);
                int nor = temp.at(1);

                verticleIndexes.push_back(geo);
                verticleNorIndexes.push_back(nor);
            } else{
                std::cout<<"Syntax error in face definition!\n";
                return -1;
            }
        }
    } else if(globalState == geoTexNor){
        for(std::vector<std::string>::iterator i = vec.begin(); i != vec.end();
            i++){
            currentState = faceMode(*i);
            if(currentState == globalState){
                temp = faceIntoTokens("/", *i);
                assert(temp.size() == 3);

                int geo = temp.at(0);
                int tex = temp.at(1);
                int nor = temp.at(2);

                verticleIndexes.push_back(geo);
                verticleNorIndexes.push_back(nor);
                verticleTexIndexes.push_back(tex);
            } else{
                std::cout<<"Syntax error in face definition!\n";
                return -1;
            }
        }
    }

    return makeFace(verticleIndexes, verticleTexIndexes, verticleNorIndexes,
           globalState);
}

int ObjParser::parseMatFile(std::vector<std::string> vec) { //ignore
    return 0;
}

int ObjParser::parseUseMaterial(std::vector<std::string> vec) { //ignore
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

std::vector<int>
ObjParser::faceIntoTokens(std::string delimiter, std::string s) {
    std::vector<int> tokens;
    std::string token;
    std::size_t next = 0;

    while((next = s.find(delimiter)) != std::string::npos){
        token = s.substr(0, next);
        tokens.push_back(stoi(token));
        s.erase(0, next + delimiter.length());
    }
    if(!s.empty()){
        tokens.push_back(stoi(s));
    }

    return tokens;
}

int ObjParser::makeFace(std::vector<int> geo, std::vector<int> tex, std::vector<int> nor,
                        faceState state) {

    if(state == geoOnly){
        Vector3 a, b, c;
        Triangle t;

        a = verticles.at((unsigned long long int) (geo.at(0)-1));
        b = verticles.at((unsigned long long int) (geo.at(1)-1));
        c = verticles.at((unsigned long long int) (geo.at(2)-1));

        t = Triangle(a, b, c);
        triangles.push_back(t); //4968

    } else if(state == geoNor){ //FIXME IGNORE NORMALS
        Vector3 a, b, c;
        Triangle t;
        a = verticles.at((unsigned long long int) (geo.at(0)-1));
        b = verticles.at((unsigned long long int) (geo.at(1)-1));
        c = verticles.at((unsigned long long int) (geo.at(2)-1));

        t = Triangle(a, b, c);
        triangles.push_back(t);
    } else if(state == geoTexNor){//FIXME IGNORE TEXTURE
        Vector3 a, b, c;
        Triangle t;
        a = verticles.at((unsigned long long int) (geo.at(0)-1));
        b = verticles.at((unsigned long long int) (geo.at(1)-1));
        c = verticles.at((unsigned long long int) (geo.at(2)-1));

        t = Triangle(a, b, c);
        triangles.push_back(t);
    }
    return 0;
}
