//
// Created by Madatt on 01.12.2019.
//

#include "irulan/Graph/3D/Mesh/AnimatedMesh.h"
#include "irulan/Graph/Shader.h"

namespace Iru {
    void AnimatedMesh::draw(RenderTarget &t_ren) {
        m_sh->setMatrix("u_mvp", m_mvp);
        m_sh->setInt("u_tex", 0);
        t_ren.setTexture(*m_tex, 0);
        t_ren.setShader(*m_sh);
        t_ren.setVA(m_va);
        t_ren.render(Iru::TRIANGLES, 0, m_amd->getPrimitives() * 3);

        t_ren.flush();
    }

    void AnimatedMesh::setAnimation(const AnimatedMeshData *t_amd) {
        m_amd = t_amd;
        m_curr = 0;
        m_last = t_amd->getLength();
    }

    void AnimatedMesh::setSpeed(float t_spd) {
        m_spd = t_spd;
    }

    void AnimatedMesh::animate(int t_time) {
        if(t_time - m_time >= m_spd * 1000)
        {
            m_curr = (m_curr + 1) % m_last;
            m_fr = !m_fr;
        }
    }

    void AnimatedMesh::setShader(const Shader *t_sh) {
        m_sh = t_sh;
    }

    void AnimatedMesh::setTexture(const Texture2D *t_tex) {
        m_tex = t_tex;
    }

    void AnimatedMesh::setMVP(Matrix t_mvp) {
        m_mvp = t_mvp;
    }

}
