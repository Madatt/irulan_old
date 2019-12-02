//
// Created by Madatt on 01.12.2019.
//

#ifndef IRULAN_ANIMATEDMESH_H
#define IRULAN_ANIMATEDMESH_H

#include <irulan/Graph/Render/Drawable.h>
#include <irulan/Graph/VertexBuffer.h>
#include <irulan/Graph/VertexArray.h>
#include "AnimatedMeshData.h"

namespace Iru
{
    class AnimatedMesh : public Drawable{
    public:
        AnimatedMesh() = default;
        ~AnimatedMesh() = default;

        void setAnimation(const AnimatedMeshData* t_amd);
        void setSpeed(float t_spd);
        void animate(int t_time);

        void setShader(const Shader* t_sh);
        void setTexture(const Texture2D* t_tex);
        void setMVP(Matrix t_mvp);

        void draw(RenderTarget &t_ren) override;
    private:
        const Shader* m_sh;
        const Texture2D* m_tex;
        const AnimatedMeshData* m_amd;

        VertexBuffer m_vb[2];
        VertexArray m_va;

        int m_last = 0;
        int m_curr = 0;
        float m_spd = 0;
        int m_time = 0;
        bool m_fr = false;

        Matrix m_mvp;

        std::vector<float> m_data;
    };
}

#endif //IRULAN_ANIMATEDMESH_H
