#include "MODEL.h"
extern COLOR_MODE ColorMode;
//MODEL���p�������S�ẴN���X�ŋ��L����C���X�^���X
MATRIX MODEL::view;
MATRIX MODEL::proj;
VECTOR MODEL::lightPos;

MODEL::MODEL() {
}
MODEL::~MODEL() {
    if (OPositions)delete[] OPositions;
    if (ONormals)delete[] ONormals;
    if (Positions)delete[] Positions;
    if (Indices)delete[] Indices;
    if (Colors)delete[] Colors;
}
void MODEL::allocateMemory() {
    if (NumVertices == 0) {
        print("���_����ݒ肵�Ă��Ȃ�");
    }
    if (NumTriangles == 0) {
        print("�O�p�|���S������ݒ肵�Ă��Ȃ�");
    }
    //�ʒu�Ɩ@���x�N�g���i���_�o�b�t�@�j
    OPositions = new VECTOR[NumVertices];
    ONormals = new VECTOR[NumVertices];
    //���W�ϊ���̈ʒu
    Positions = new VECTOR[NumVertices];
    //�v�Z��̒��_�̐F�i���邳�j
    Colors = new COLOR[NumVertices];
    //�C���f�b�N�X�o�b�t�@
    NumIndices = NumTriangles * 3;
    Indices = new int[NumIndices];
}
void MODEL::draw(const MATRIX& world, const COLOR& color, float ambient) {
    //world�����]�E�g��k���v�f�����o��
    MATRIX mRS = world;
    mRS._14 = mRS._24 = mRS._34 = 0;
    //��]��̖@��
    VECTOR normal;
    //�S���_�̌v�Z
    for (int i = 0; i < NumVertices; i++) {
        //���[���h���W
        Positions[i] = world * OPositions[i];
        //�r���[���W
        Positions[i] = view * Positions[i];
        //���e���W
        Positions[i] = proj * Positions[i];
        //�F�E���邳
        if (Lighting) {
            normal = normalize(mRS * ONormals[i]);
            float bright = max(ambient, dot(normal, lightPos));
            if (ColorMode == RGB) {
                Colors[i] = color * bright;
            }
            else {
                Colors[i] = color;
                Colors[i].b *= bright;
            }
        }
        else {
            //�w��F���̂܂�
            Colors[i] = color;
        }
    }
    //�`��
    for (int i = 0; i < NumTriangles; i++) {
        //�`�悷��O�p�`�̃C���f�b�N�Xj,k,l
        int ref = i * 3;
        int j = Indices[ref + 0];
        int k = Indices[ref + 1];
        int l = Indices[ref + 2];
        if (Culling) {
            //j,k,l�����O�p�`��"�\"���ǂ������肷��
            VECTOR a = Positions[k] - Positions[j];
            VECTOR b = Positions[l] - Positions[j];
            //�\��������`�悷��
            if (a.crossZ(b) > 0) {
                triangle3D(Positions[j], Positions[k], Positions[l]
                    , Colors[j], Colors[k], Colors[l]);
            }
        }
        else {
            //���ʂł��`�悷��
            triangle3D(Positions[j], Positions[k], Positions[l]
                , Colors[j], Colors[k], Colors[l]);
        }
    }
}
void MODEL::noCulling() {
    Culling = 0;
}
void MODEL::noLighting() {
    Lighting = 0;
}
