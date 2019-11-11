//
// Created by Madatt on 12.11.2019.
//

#include "TestApp.h"

void TestApp::draw(double t_delta) {
    renderer.clear();


    Iru::Quaternion quat =
            Iru::Quaternion::createRotation(Iru::Vector3(0, 1, 0), test) * Iru::Quaternion::createRotation(Iru::Vector3(1, 0, 0), -30);

    dir = forw.transform(
            quat.toMatrix()
    );


    Iru::Vector3 pos = dir + frm;
    Iru::Vector3 up = Iru::Vector3(0, 1, 0);


    View = Iru::Matrix::createLookAt(pos, frm, up);
    Proj = Iru::Matrix::createPerspective(70, 1280.f / 720.f, 0.1f, 1000.f);

    Proj *= View;

    shd->setMatrix("aPos2", Proj);
    shd->setInt("atexture", 0);
    //renderer.setTexture(&tex, 0);
    renderer.setVA(vao);
    renderer.setShader(shd);
    renderer.drawArrays(Iru::TRIANGLES, 0, 6);

    flip();
}

void TestApp::step(double t_delta) {
    test += t_delta * 60;

}

void TestApp::init() {
    std::string vers = "#version 330 core\n"
                       "layout (location = 0) in vec3 aPos;\n"
                       "layout (location = 1) in vec2 aTex;\n"
                       "uniform mat4 aPos2;\n"
                       "out vec2 Tex;\n"
                       "\n"
                       "void main()\n"
                       "{\n"
                       "    gl_Position = aPos2 * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                       "    Tex = aTex;\n"
                       "}";

    std::string frags = "#version 330 core\n"
                        "out vec4 FragColor;\n"
                        "in vec2 Tex;\n"
                        "uniform sampler2D atexture;\n"
                        "void main()\n"
                        "{\n"
                        "    FragColor = vec4(1, 1, 1,1)*texture(atexture, Tex);\n"
                        "} ";


    setDimensions(1280, 720);

    App::init();

    vao = new Iru::VertexArray();
    vbo = new Iru::VertexBuffer();


    vao->setAttrib(*vbo, 0, 3, Iru::FLOAT, 3 * sizeof(float), (void *) 0);
    vao->setAttrib(*vbo, 1, 2, Iru::FLOAT, 2 * sizeof(float), (void *) (18 * sizeof(float)));
    float ver[] = {1.0f, 1.0f, 0.0f,
                   1.0f, 0.0f, 0.0f,
                   0.0f, 0.0f, 0.0f,

                   0.0f, 0.0f, 0.0f,
                   0.0f, 1.0f, 0.0f,
                   1.0f, 1.0f, 0.0f,

                   0.0f, 1.0f,
                   0.0f, 0.0f,
                   1.0f, 0.0f,

                   1.0f, 0.0f,
                   1.0f, 1.0f,
                   0.0f, 1.0f,
    };

    vbo->setData(sizeof(ver), ver);


    shd = new Iru::Shader(vers, frags);


    forw = Iru::Vector3(0, 0, 4);
    dir = Iru::Vector3(0, 0, 4);
    frm = Iru::Vector3(0.5, 0, 0);


    //resources.setRoot("test");
    //resources.loadMesh("test.txt");


    //tex = resources.loadBMP("test.bmp");
    //tex.setFiltering(NEAREST);

}
