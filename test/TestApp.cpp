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
    renderer.setTexture(&tex, 0);
    renderer.setVA(vao);
    renderer.setShader(shd);
    //renderer.drawArrays(Iru::TRIANGLES, 0, 6);
    renderer.flush();

    Proj = Iru::Matrix();

    shd2->setMatrix("aPos2", Proj);
    shd2->setInt("atexture", 0);
    renderer.setTexture(&tex, 0);
    renderer.setShader(shd2);
    renderer.setVA(vao2);
    renderer.drawArrays(Iru::TRIANGLES, 0, 5);
    renderer.flush();

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

    std::string vers2 = "#version 330 core\n"
                       "layout (location = 0) in vec2 aPos;\n"
                       "layout (location = 1) in vec2 aTex;\n"
                       "uniform mat4 aPos2;\n"
                       "out vec2 Tex;\n"
                       "\n"
                       "void main()\n"
                       "{\n"
                       "    gl_Position = aPos2 * vec4(aPos.x, aPos.y, 0.0, 1.0);\n"
                       "    Tex = aTex;\n"
                       "}";

    std::string frags2 = "#version 330 core\n"
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
    shd2 = new Iru::Shader(vers2, frags2);


    forw = Iru::Vector3(0, 0, 4);
    dir = Iru::Vector3(0, 0, 4);
    frm = Iru::Vector3(0.5, 0, 0);


    //resources.setRoot("test");
    //resources.loadMesh("test.txt");


    tex = Iru::Texture2D::_loadBMP("font.bmp");
    tex.setFiltering(Iru::NEAREST);

    font.setTexture(tex, 7, 18);

    text.setFont(font);
    text.set("gowno");
    text.construct();

    vao2 = new Iru::VertexArray();
    vbo2 = new Iru::VertexBuffer();


    vao2->setAttrib(*vbo2, 0, 4, Iru::FLOAT, 4 * sizeof(float), (void *) 0);
    //vao2->setAttrib(*vbo2, 1, 4, Iru::FLOAT, 4 * sizeof(float), (void *) (18 * sizeof(float)));


    vbo2->setData(text.getVers().size() * sizeof(float) ,text.getVers().data());


}
