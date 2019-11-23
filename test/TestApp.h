//
// Created by Madatt on 12.11.2019.
//

#ifndef IRULAN_TESTAPP_H
#define IRULAN_TESTAPP_H

#include "irulan.h"

class TestApp : public Iru::App {
public:
    TestApp();

private:
    void init() override;
    void draw(double) override;
    void step(double) override;

    Iru::VertexBuffer *vbo;
    Iru::VertexArray *vao;
    Iru::Shader *shd;

    Iru::VertexBuffer *vbo2;
    Iru::VertexArray *vao2;
    Iru::Shader *shd2;

    Iru::Matrix Proj;
    Iru::Matrix View;
    float test = 3;

    Iru::Vector3f dir;
    Iru::Vector3f forw;
    Iru::Vector3f frm;

    Iru::Texture2D tex;
    Iru::BitmapFont font;
    Iru::Text text;
};


#endif //IRULAN_TESTAPP_H
