#include "Primitive.h"

Primitive::Primitive() { }

std::shared_ptr<Material> Primitive::getMaterial() { return material; }

void Primitive::setMaterial(const std::shared_ptr<Material>& material) { this->material = material;}
