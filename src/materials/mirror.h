#ifndef MIRROR
#define MIRROR

#include "../core/vector3d.h"
#include "material.h"

class Mirror : public Material
{
public:
    Mirror(const Vector3D nc);

    Vector3D getReflectance(const Vector3D &n, const Vector3D &wo,
                                    const Vector3D &wi) const ;
    bool hasSpecular() const;
    bool hasTransmission() const;
    bool hasDiffuseOrGlossy() const;

private:
    Vector3D Nc;
    
};


#endif // MIRROR
