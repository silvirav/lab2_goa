#include "phong.h"
#include "../core/utils.h"
#include <iostream>

Phong::Phong(const Vector3D ks, const Vector3D kd, const float nc)
    : Material() 

{ 
    Ks = ks;
    Kd = kd;
    Nc = nc;
}

Vector3D Phong::getReflectance(const Vector3D& n, const Vector3D& wo,
    const Vector3D& wi) const {


    Vector3D wr = Utils::computeReflectionDirection(wi, n);
    return Kd * dot(wi, n) + Ks * pow(dot(wo, wr), Nc);


}
bool Phong::hasSpecular()const {
    
     return false;
    
}
bool Phong::hasDiffuseOrGlossy() const {
    
    return true;
    
}
bool Phong::hasTransmission() const {
    
    return false;
    
}
