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

    Iru::Shader *shd{};
    float test = 3;

    Iru::Texture2D tex;
    Iru::Texture2D tex2;
    Iru::BitmapFont font;
    Iru::Text text;
    std::string str = "";
    Iru::Timer timer;

    Iru::Quads quads;
    int c = 0;


};


#endif //IRULAN_TESTAPP_H
