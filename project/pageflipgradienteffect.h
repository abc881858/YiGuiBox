#ifndef PAGEFLIPGRADIENTEFFECT_H
#define PAGEFLIPGRADIENTEFFECT_H

#include "qglshaderprogrameffect.h"
#include <QtOpenGL/qglshaderprogram.h>

class PageFlipGradientEffect : public QGLShaderProgramEffect
{
public:
    PageFlipGradientEffect();
    ~PageFlipGradientEffect();

    void setAlphaValue(GLfloat value);
};
#endif // PAGEFLIPGRADIENTEFFECT_H
