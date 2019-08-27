//
// Created by pioziol on 18.08.2019.
//

#ifndef OPENGLTUT_TEXTURE_H
#define OPENGLTUT_TEXTURE_H

#include "Renderer.h"
#include <string>

class Texture {
private:
    unsigned int m_RendererID;
    std::string m_FilePath;
    unsigned char *m_LocalBuffer;
    int m_Width, m_Height, m_BPP;
public:
    explicit Texture(const std::string& path);

    ~Texture();

    void Bind(unsigned int slot = 0);

    void Unbind();

    inline int GetWidth() const { return m_Width; }

    inline int GetHeight() const { return m_Height; }
};


#endif //OPENGLTUT_TEXTURE_H
