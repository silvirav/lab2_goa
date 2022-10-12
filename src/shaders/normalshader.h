#include "shader.h"


class NormalShader : public Shader
{
public:
    NormalShader();
    NormalShader(Vector3D hitColor, Vector3D bgColor_);

    virtual Vector3D computeColor(const Ray &r,
                             const std::vector<Shape*> &objList,
                             const std::vector<PointLightSource> &lsList) const;

    Vector3D hitColor;
};


