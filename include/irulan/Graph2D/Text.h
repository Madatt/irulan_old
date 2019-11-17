//
// Created by Madatt on 12.11.2019.
//

#ifndef IRULAN_TEXT_H
#define IRULAN_TEXT_H

#include "Graph2D/BitmapFont.h"
#include "Graph/Primitives/VertexT.h"
#include <vector>

namespace Iru {
    class Text {
    public:
        Text() = default;
        Text(BitmapFont& t_font, std::string t_text);
        Text(BitmapFont& t_font);

        void construct();
        void setFont(BitmapFont& t_font){m_font = &t_font;};
        void set(std::string t_text){m_text = t_text;};

        std::vector<VertexT>& getVers(){return m_vers;};

    private:
        std::vector<VertexT> m_vers;
        BitmapFont* m_font;
        std::string m_text;
    };
}

#endif //IRULAN_TEXT_H
