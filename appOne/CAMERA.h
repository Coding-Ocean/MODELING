#pragma once
#include"VECTOR.h"
class CAMERA{
    VECTOR CamPos;
    VECTOR LookPos;
    VECTOR UpVec;
    float Longitude = 0;//�o�x(����)
    float Latitude = 0;//�ܓx(��k)
    float Radius = 0;
    float Speed = 0;
    float PosOffsetY = 0;
public:
    CAMERA();
    void update();
};

