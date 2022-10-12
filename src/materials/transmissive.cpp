#include "transmissive.h"
#include "../core/utils.h"
#include <iostream>

Transmissive::Transmissive(const Vector3D ks, const Vector3D kd, const float nc)
    : Material() 

{ 
    Ks = ks;
    Kd = kd;
    Nc = nc;
}

Vector3D Transmissive::getReflectance(const Vector3D& n, const Vector3D& wo,
    const Vector3D& wi) const {


    Vector3D wr = Utils::computeReflectionDirection(wi, n);
    return Kd * dot(wi, n) + Ks * pow(dot(wo, wr), Nc);


}
bool Transmissive::hasSpecular()const {
    
     return false;
    
}
bool Transmissive::hasDiffuseOrGlossy() const {
    
    return false;
    
}
bool Transmissive::hasTransmission() const {
    
    return false;
    
}
