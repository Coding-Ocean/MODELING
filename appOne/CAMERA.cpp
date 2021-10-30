#include"input.h"
#include"mathUtil.h"
#include"MODEL.h"
#include "CAMERA.h"
CAMERA::CAMERA()
    :LookPos(0, 0, 0)
    , UpVec(0, 1, 0)
    , Longitude(0)//�o�x(����)
    , Latitude(0.15f)//�ܓx(��k)
    , Speed(0.01f)
    , Radius(8)
    , PosOffsetY(0.0f)
{
}
void CAMERA::update(){
    //�o�x�i�����j
    if (isPress(KEY_J)) { Longitude -= Speed; }
    if (isPress(KEY_L)) { Longitude += Speed; }
    //�ܓx�i��k�j
    if (isPress(KEY_I)) { Latitude += Speed; }
    if (isPress(KEY_K)) { Latitude -= Speed; }
    //�Y�[��
    if (isPress(KEY_U)) { Radius -= Speed; }
    if (isPress(KEY_O)) { Radius += Speed; }
    //�㉺
    if (isPress(KEY_Y)) { PosOffsetY += Speed; }
    if (isPress(KEY_H)) { PosOffsetY -= Speed; }
    //�J�����ʒu�i�RD�ɍ��W�j
    CamPos.x = sin(Longitude) * cos(Latitude) * Radius;
    CamPos.y =                  sin(Latitude) * Radius;
    CamPos.z = cos(Longitude) * cos(Latitude) * Radius;
    CamPos.y += PosOffsetY;
    LookPos.y = PosOffsetY;
    UpVec.y = cos(Latitude);
    MODEL::view.camera(CamPos, LookPos, UpVec);
}
