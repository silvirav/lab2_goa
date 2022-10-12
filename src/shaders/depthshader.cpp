#include "depthshader.h"
#include "../core/utils.h"


DepthShader::DepthShader() :

    hitColor(Vector3D(0, 1, 0))
{ }

DepthShader::DepthShader(Vector3D hitColor_, Vector3D bgColor_) :
    Shader(bgColor_), hitColor(hitColor_)
{ }

Vector3D DepthShader::computeColor(const Ray& r, const std::vector<Shape*>& objList, const std::vector<PointLightSource>& lsList) const
{
    Intersection its;

    if (Utils::getClosestIntersection(r, objList, its)) {
        double yy = std::max(1.0 - (r.maxT /8.0), 0.0);
        Vector3D hitColor = Vector3D(0, yy, 0);
        return hitColor;
    }
        
    else{
        return bgColor;
}}