#include "normalshader.h"
#include "../core/utils.h"


NormalShader::NormalShader() :

    hitColor(Vector3D(0, 1, 0))
{ }

NormalShader::NormalShader(Vector3D hitColor_, Vector3D bgColor_) :
    Shader(bgColor_), hitColor(hitColor_)
{ }

Vector3D NormalShader::computeColor(const Ray& r, const std::vector<Shape*>& objList, const std::vector<PointLightSource>& lsList) const
{
    Intersection its;
    if (Utils::getClosestIntersection(r, objList, its)) {
        Vector3D norm = Vector3D(0, 0, 1);
        Vector3D hitColor = (its.normal+(1.0,1.0,1.0))/2.0;
        return hitColor;
    }
        
    else{
        return bgColor;
}}