#pragma once
#include"MODEL.h"
class PLANE : public MODEL {
public:
    PLANE() {
        //「座標」「法線ベクトル」「インデックス」の設定前に
        //必ずこの３行の設定を行う！
        NumVertices = 4;
        NumTriangles = 2;
        allocateMemory();

        //座標設定
        OPositions[0].set(-0.5f, 0.5f, 0);
        OPositions[1].set(-0.5f, -0.5f, 0);
        OPositions[2].set(0.5f, 0.5f, 0);
        OPositions[3].set(0.5f, -0.5f, 0);

        //法線ベクトル設定（平面でも１頂点に１つ必要）
        ONormals[0].set(0, 0, 1);
        ONormals[1].set(0, 0, 1);
        ONormals[2].set(0, 0, 1);
        ONormals[3].set(0, 0, 1);

        //インデックス設定
        Indices[0] = 0;
        Indices[1] = 1;
        Indices[2] = 2;

        Indices[3] = 2;
        Indices[4] = 1;
        Indices[5] = 3;
    }
};
