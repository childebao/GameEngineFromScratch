#pragma once
#include <cstdint>
#include <iostream>

namespace My {
struct GfxConfiguration {
    /// Inline all-elements constructor.
    /// \param[in] r the red color depth in bits
    /// \param[in] g the green color depth in bits
    /// \param[in] b the blue color depth in bits
    /// \param[in] a the alpha color depth in bits
    /// \param[in] d the depth buffer depth in bits
    /// \param[in] s the stencil buffer depth in bits
    /// \param[in] msaa the msaa sample count
    /// \param[in] width the screen width in pixel
    /// \param[in] height the screen height in pixel
    explicit GfxConfiguration(uint32_t r = 8, uint32_t g = 8, uint32_t b = 8,
                              uint32_t a = 8, uint32_t d = 24, uint32_t s = 0,
                              uint32_t msaa = 1, uint32_t width = 1920,
                              uint32_t height = 1080,
                              const char* app_name = "GameEngineFromScratch")
        : redBits(r),
          greenBits(g),
          blueBits(b),
          alphaBits(a),
          depthBits(d),
          stencilBits(s),
          msaaSamples(msaa),
          screenWidth(width),
          screenHeight(height),
          appName(app_name) {}

    uint32_t redBits{8};      ///< red color channel depth in bits
    uint32_t greenBits{8};    ///< green color channel depth in bits
    uint32_t blueBits{8};     ///< blue color channel depth in bits
    uint32_t alphaBits{8};    ///< alpha color channel depth in bits
    uint32_t depthBits{24};   ///< depth buffer depth in bits
    uint32_t stencilBits{8};  ///< stencil buffer depth in bits
    uint32_t msaaSamples{4};  ///< MSAA samples
    uint32_t screenWidth{1920};
    uint32_t screenHeight{1080};
    static const uint32_t kMaxInFlightFrameCount{2};
    static const uint32_t kMaxSceneObjectCount{2048};
    static const uint32_t kMaxTexturePerMaterialCount{16};
    static const uint32_t kMaxShadowMapCount{8};
    static const uint32_t kMaxGlobalShadowMapCount{1};
    static const uint32_t kMaxCubeShadowMapCount{2};

    static const uint32_t kShadowMapWidth = 512;       // normal shadow map
    static const uint32_t kShadowMapHeight = 512;      // normal shadow map
    static const uint32_t kCubeShadowMapWidth = 512;   // cube shadow map
    static const uint32_t kCubeShadowMapHeight = 512;  // cube shadow map
    static const uint32_t kGlobalShadowMapWidth =
        2048;  // shadow map for sun light
    static const uint32_t kGlobalShadowMapHeight =
        2048;  // shadow map for sun light

    const char* appName;

    bool fixOpenGLPerspectiveMatrix = false;

    friend std::ostream& operator<<(std::ostream& out,
                                    const GfxConfiguration& conf) {
        out << "App Name:" << conf.appName << std::endl;
        out << "GfxConfiguration:"
            << " R:" << conf.redBits << " G:" << conf.greenBits
            << " B:" << conf.blueBits << " A:" << conf.alphaBits
            << " D:" << conf.depthBits << " S:" << conf.stencilBits
            << " M:" << conf.msaaSamples << " W:" << conf.screenWidth
            << " H:" << conf.screenHeight << std::endl;
        return out;
    }
};
}  // namespace My
