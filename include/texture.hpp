#ifndef TEXTURE_HPP
#define TEXTURE_HPP

inline void CreateTexture(u32& id, i32 width, i32 height, int format = GL_RGBA, int type = GL_UNSIGNED_BYTE)
{
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, type, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);
}

inline void UpdateTexture(u32& id, i32 width, i32 height, void* data, int format = GL_RGBA, int type = GL_UNSIGNED_BYTE)
{
    glBindTexture(GL_TEXTURE_2D, id);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, format, type, data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

inline void BindTexture(u32 id, int slot = 0)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, id);
}

#endif