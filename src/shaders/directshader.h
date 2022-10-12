#ifndef DIRECTSHADER_H
#define DIRECTSHADER_H

#include "shader.h"


class DirectShader : public Shader
{
public:
    DirectShader();
    DirectShader(Vector3D color_,Vector3D bgColor_);

    Vector3D computeColor(const Ray& r,
        const std::vector<Shape*>& objList,
        const std::vector<PointLightSource>& lsList) const;

private:
    double maxDist = 9.0; //initializing maxDist with a value, as it will be used as a constant (Task 3)
    Vector3D color;
};

#endif // DIRECTSHADER_H
#pragma once