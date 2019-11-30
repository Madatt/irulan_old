//
// Created by Madatt on 12.11.2019.
//

#include "TestApp.h"

TestApp::TestApp()
        : App(Iru::Vector2i(1280, 720)) {

}

void TestApp::draw(double t_delta) {
    clear();

    Iru::Quaternion quat =
            Iru::Quaternion::createRotation(Iru::Vector3f(0, 1, 0), test) * Iru::Quaternion::createRotation(Iru::Vector3f(1, 0, 0), -30);

    dir = quat.toMatrix().apply(forw);



    Iru::Vector3 pos = dir + frm;
    Iru::Vector3 up = Iru::Vector3f(0, 1, 0);


    View = Iru::Matrix::createLookAt(pos, frm, up);
    Proj = Iru::Matrix::createPerspective(70, 1280.f / 720.f, 0.001f, 100000.f);

    Proj *= View;


    render(text);
    render(quads);

    shd2->setMatrix("u_ort", Proj);
    shd2->setMatrix("u_tra", Iru::Matrix::createScale(Iru::Vector3f(0.5, 0.5, 0.5)));
    setVA(*va);
    setShader(*shd2);
    render(Iru::TRIANGLES, 0, c);

    flip();
}

void TestApp::step(double t_delta) {
    test += t_delta * 60;

    if (timer.getElapsed() >= 1000) {
        timer.reset();
        str += (char) (rand() % 100 + 32);
        text.set(str);
    }

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

    std::string vers2 = "#version 450 core\n"
                       "layout (location = 0) in vec3 aPos;\n"
                       "uniform mat4 u_tra;\n"
                       "uniform mat4 u_ort;\n"
                       "out vec3 Tex;\n"
                       "\n"
                       "void main()\n"
                       "{\n"
                       "    gl_Position = u_ort * u_tra * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                       "    Tex = aPos;\n"
                       "}";

    std::string frags2 = "#version 450 core\n"
                        "out vec4 FragColor;\n"
                        "in vec3 Tex;\n"
                        "void main()\n"
                        "{\n"
                        "    FragColor = vec4(Tex.x, Tex.y, Tex.z, 255);\n"
                        "} ";


    shd = new Iru::Shader(vers, frags);
    shd2 = new Iru::Shader(vers2, frags2);

    forw = Iru::Vector3f(0, 0, 4);
    dir = Iru::Vector3f(0, 0, 4);
    frm = Iru::Vector3f(0.5, 0, 0);


    tex = Iru::Texture2D::_loadBMP("font.bmp");
    tex2 = Iru::Texture2D::_loadBMP("test.bmp");

    addResource("test", tex);

    font.setTexture(*getResource<Iru::Texture2D>("test"), 6, 18, 7, 8);

    text.setFont(font);
    text.setShader(*shd);
    text.setTransform(Iru::Matrix::createTranslation(Iru::Vector3f(328, 56, 0)) *
                      Iru::Matrix::createScale(Iru::Vector3f(5, 5, 0)) *
                      Iru::Matrix::createRotation(Iru::Vector3f(0, 0, 1.f), 45.f));

    str = "huj dziala\nomg, nawet\nmultilinie!!";
    text.set(str);

    quads.add(Iru::Rectf(0, 0, 128, 128), Iru::Rectf(0, 0, 1, 1));
    quads.add(Iru::Rectf(256, 256, 128, 128), Iru::Rectf(0, 0, 1, 1));
    quads.setTexture(tex2);
    quads.setShader(*shd);


    timer.reset();

    addResource("mesh", Iru::MeshLoader::loadObj("teapot.obj"));

    va = new Iru::VertexArray();
    vb = new Iru::VertexBuffer();
    ib = new Iru::VertexBuffer();

    vb->setStorage(getResource<Iru::MeshData>("mesh")->getData().size() * sizeof(float),
                   (void *) getResource<Iru::MeshData>("mesh")->getData().data());

    c = getResource<Iru::MeshData>("mesh")->getData().size();
    std::cout << c <<std::endl;

    va->setAttrib(0, 0, 3, 0);
    va->attachVB(*vb, 0, 0, 3 * sizeof(float));
}
