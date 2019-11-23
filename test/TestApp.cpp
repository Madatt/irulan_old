//
// Created by Madatt on 12.11.2019.
//

#include "TestApp.h"

TestApp::TestApp()
:App(Iru::Vector2i(1280, 720)){

}

void TestApp::draw(double t_delta){
    clear();

    render(text);

    flip();
}

void TestApp::step(double t_delta) {
    test += t_delta * 60;

}

void TestApp::init() {
    std::string vers = "#version 450 core\n"
                       "layout (location = 0) in vec2 aPos;\n"
                       "layout (location = 1) in vec2 aTex;\n"
                       "uniform mat4 u_tra;\n"
                       "uniform mat4 u_ort;\n"
                       "out vec2 Tex;\n"
                       "\n"
                       "void main()\n"
                       "{\n"
                       "    gl_Position = u_ort * u_tra * vec4(aPos.x, aPos.y, 0.0, 1.0);\n"
                       "    Tex = aTex;\n"
                       "}";

    std::string frags = "#version 450 core\n"
                        "out vec4 FragColor;\n"
                        "in vec2 Tex;\n"
                        "uniform sampler2D u_tex;\n"
                        "void main()\n"
                        "{\n"
                        "    FragColor = vec4(1, 1, 1,1)*texture(u_tex, Tex);\n"
                        "} ";

    App::init();



    shd = new Iru::Shader(vers, frags);

    forw = Iru::Vector3f(0, 0, 4);
    dir = Iru::Vector3f(0, 0, 4);
    frm = Iru::Vector3f(0.5, 0, 0);


    tex = Iru::Texture2D::_loadBMP("font.BMP");

    font.setTexture(tex, 7, 18, 7, 10);

    text.setFont(font);
    text.setShader(*shd);
    text.setTransform(Iru::Matrix::createScale(Iru::Vector3f(10, 10, 0)));
    text.set("abcd");

}
