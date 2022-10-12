#include "directshader.h"
#include "../core/utils.h"

DirectShader::DirectShader() :
    color(Vector3D(1, 0, 0))
{ }

DirectShader::DirectShader(Vector3D color_, Vector3D bgColor_) :
    Shader(bgColor_), color(color_)
{ }

Vector3D  DirectShader::computeColor(const Ray& r, const std::vector<Shape*>& objList, const std::vector<PointLightSource>& lsList) const
{

    Intersection its;
    if (Utils::getClosestIntersection(r, objList, its))
    {
        Vector3D color = Vector3D(0, 0, 0);
        for (int i = 0; i < lsList.size(); i++)
        {
            Vector3D wo = (r.o - its.itsPoint);
            wo = wo.normalized();
            Vector3D wi = lsList[i].getPosition() - its.itsPoint;
            wi = wi.normalized();
            Ray r2 = Ray(its.itsPoint, wi);
            r2.maxT = (lsList[i].getPosition() - its.itsPoint).length();
            if(Utils::hasIntersection(r2,objList) == false)
            {
                Vector3D phong_reflectance = its.shape->getMaterial().getReflectance(its.normal, wo, wi);
                Vector3D lo = (lsList[i].getIntensity(its.itsPoint)) * (phong_reflectance);
                color = color + lo;
            }
        }
        return color;
    }
    else
        return bgColor;
}