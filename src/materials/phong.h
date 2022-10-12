#ifndef PHONG
#define PHONG

#include "../core/vector3d.h"
#include "material.h"

class Phong : public Material
{
public:
    Phong(const Vector3D ks, const Vector3D kd, const float nc);

    Vector3D getReflectance(const Vector3D &n, const Vector3D &wo,
                                    const Vector3D &wi) const ;
    bool hasSpecular() const;
    bool hasTransmission() const;
    bool hasDiffuseOrGlossy() const;

private:
    Vector3D Ks;
    Vector3D Kd;
    double Nc;
    
};


#endif // PHONG
