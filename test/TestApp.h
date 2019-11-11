//
// Created by Madatt on 12.11.2019.
//

#ifndef IRULAN_TESTAPP_H
#define IRULAN_TESTAPP_H

#include "irulan.h"

class TestApp : public Iru::App{

protected:
    void init() override;

private:
    void draw(double) override;

    void step(double) override;

    Iru::VertexBuffer* vbo;
    Iru::VertexArray* vao;
    Iru::Shader* shd;
    unsigned int vv;

    Iru::Matrix Proj;
    Iru::Matrix View;
    float test = 3;

    Iru::Vector3 dir;
    Iru::Vector3 forw;
    Iru::Vector3 frm;

    Iru::Texture2D tex;
};



#endif //IRULAN_TESTAPP_H
