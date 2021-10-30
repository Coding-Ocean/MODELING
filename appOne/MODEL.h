#pragma once
#include"libOne.h"
class MODEL {
protected:
    int NumVertices = 0;
    int NumTriangles = 0;
    int NumIndices = 0;
    //�v�Z�O��Original�f�[�^
    VECTOR* OPositions = 0;
    VECTOR* ONormals = 0;
    //�v�Z��̃f�[�^
    VECTOR* Positions = 0;
    COLOR* Colors = 0;
    //���_��I������C���f�b�N�X�z��
    int* Indices = 0;
    //���ʏ����t���b�O
    int Culling = 1;
    //���C�e�B���O�����t���b�O
    int Lighting = 1;
public:
    //���ׂĂ�MODEL�̃C���X�^���X�ŋ��L���郁���o�N���X
    static MATRIX view;
    static MATRIX proj;
    static VECTOR lightPos;
    //�����o�֐�
    MODEL();
    virtual ~MODEL();
    void allocateMemory();
    void draw(
        const MATRIX& world, 
        const COLOR& color=COLOR(255,255,255), 
        float ambient = 0
    );
    void noCulling();
    void noLighting();
};
