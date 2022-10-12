#include "mirror.h"
#include "../core/utils.h"
#include <iostream>

Mirror::Mirror(const Vector3D nc )
    : Material() 

{ 
    Nc = nc;
}

Vector3D Mirror::getReflectance(const Vector3D& n, const Vector3D& wo,
    const Vector3D& wi) const {


    Vector3D wr = Utils::computeReflectionDirection(wi, n);
    return -wr;


}
bool Mirror::hasSpecular()const {
    
     return true;
    
}
bool Mirror::hasDiffuseOrGlossy() const {
    
    return false;
    
}
bool Mirror::hasTransmission() const {
    
    return false;
    
}
