#pragma once
#include "WindowsApplication.hpp"

namespace My {
class OpenGLApplication : public WindowsApplication {
   public:
    using WindowsApplication::WindowsApplication;

    void Finalize() override;
    void Tick() override;

    void CreateMainWindow() override;

   private:
    HDC m_hDC;
    HGLRC m_RenderContext;
    int m_nPixelFormat;
    PIXELFORMATDESCRIPTOR m_pfd;
};
}  // namespace My
