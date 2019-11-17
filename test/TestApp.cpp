//
// Created by Madatt on 12.11.2019.
//

#include "TestApp.h"

void TestApp::draw(double t_delta) {
    renderer.clear();


    Iru::Quaternion quat =
            Iru::Quaternion::createRotation(Iru::Vector3(0, 1, 0), test) *
            Iru::Quaternion::createRotation(Iru::Vector3(1, 0, 0), -30);

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
    renderer.drawInstanced(Iru::TRIANGLES, 0, 6, 200);
    renderer.flush();

    Proj = Iru::Matrix();

    /*shd2->setMatrix("aPos2", Proj);
    shd2->setInt("atexture", 0);
    renderer.setTexture(&tex, 0);
    renderer.setVA(vao2);
    renderer.setShader(shd2);
    renderer.draw(Iru::TRIANGLES, 0, 3);
    renderer.flush();*/



    flip();
}

void TestApp::step(double t_delta) {
    test += t_delta * 60;

}

void TestApp::init() {
    std::string vers = "#version 450 core\n"
                       "layout (location = 0) in vec3 aPos;\n"
                       "layout (location = 1) in vec2 aTex;\n"
                       "uniform mat4 aPos2;\n"
                       "out vec2 Tex;\n"
                       "\n"
                       "void main()\n"
                       "{\n"
                       "    gl_Position = aPos2 * vec4(aPos.x + gl_InstanceID, aPos.y + gl_InstanceID, aPos.z, 1.0);\n"
                       "    Tex = aTex;\n"
                       "}";

    std::string frags = "#version 450 core\n"
                        "out vec4 FragColor;\n"
                        "in vec2 Tex;\n"
                        "uniform sampler2D atexture;\n"
                        "void main()\n"
                        "{\n"
                        "    FragColor = vec4(1, 1, 1,1)*texture(atexture, Tex);\n"
                        "} ";

    /*
      #version 450 core
  readonly restrict uniform layout(rgba8) image2D image;
  layout(location=0) out vec4 color;
  void main(void) {
    color = imageLoad(image, ivec4(gl_FragCoord).xy);
  }
     */

    std::string vers2 = "#version 450 core\n"
                       "layout (location = 0) in vec3 aPos;\n"
                       "uniform mat4 aPos2;\n"
                       "\n"
                       "void main()\n"
                       "{\n"
                       "    gl_Position = aPos2 * vec4(aPos.x + gl_InstanceID*2, aPos.y + gl_InstanceID*2, aPos.z, 1.0);\n"
                       "}";

    std::string frags2 = "#version 450 core\n"
                        "out vec4 FragColor;\n"
                        "readonly restrict uniform layout(rgba8) image2D image;\n"
                        "void main()\n"
                        "{\n"
                        "    FragColor = vec4(1, 1, 1,1)*imageLoad(image, ivec4(gl_FragCoord).xy);\n"
                        "} ";


    setDimensions(1280, 720);

    App::init();

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

    float ver2[] = {1.0f, 1.0f,
                   1.0f, 0.0f,
                   0.0f, 0.0f,

                   0.0f, 1.0f,
                   0.0f, 0.0f,
                   1.0f, 0.0f,

    };

    vao = new Iru::VertexArray();
    vbo = new Iru::VertexBuffer();
    /*vao2 = new Iru::VertexArray();
    vbo2 = new Iru::VertexBuffer();*/

    vbo->setData(sizeof(ver), ver);
    vao->bindVB(vbo, 0, 0, 3 * sizeof(float));
    vao->bindVB(vbo, 1, 18 * sizeof(float), 2 * sizeof(float));
    vao->setAttrib(0, 0, 3, 0);
    vao->setAttrib(1, 1, 2, 0);


    /*vbo2->setData(sizeof(ver2), ver2);
    vao2->bindData(vbo, 0, 0, 2*sizeof(float));
    vao2->bindVB(vbo, 1, 6*sizeof(float), 2*sizeof(float));
    vao2->setAttrib(0, 0, 2, 0);
    vao2->setAttrib(1, 1, 2, 0);*/

    shd = new Iru::Shader(vers, frags);
    shd2 = new Iru::Shader(vers2, frags2);


    forw = Iru::Vector3(0, 0, 4);
    dir = Iru::Vector3(0, 0, 4);
    frm = Iru::Vector3(0.5, 0, 0);


    tex = Iru::Texture2D::_loadBMP("test.BMP");

}
