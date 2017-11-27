#pragma once

#include <Neso\Common\DeviceResources.h>

namespace Neso
{
    class TextRenderer
    {
    public:
        TextRenderer(
            std::shared_ptr<DX::DeviceResources> deviceResources, 
            uint32_t textureWidth, 
            uint32_t textureHeight);

        ~TextRenderer();

        void RenderTextOffscreen(const std::wstring& str);

        void CreateDeviceDependentResources();
        void ReleaseDeviceDependentResources();

        ID3D11ShaderResourceView* GetTexture() const { return m_shaderResourceView.Get(); };
        ID3D11SamplerState*       GetSampler() const { return m_pointSampler.Get(); };

    private:
        // Cached pointer to device resources.
        std::shared_ptr<DX::DeviceResources> m_deviceResources;

        // Direct3D resources for rendering text to an off-screen render target.
        Microsoft::WRL::ComPtr<ID3D11Texture2D>             m_texture;
        Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>    m_shaderResourceView;
        Microsoft::WRL::ComPtr<ID3D11SamplerState>          m_pointSampler;
        Microsoft::WRL::ComPtr<ID3D11RenderTargetView>      m_renderTargetView;
        Microsoft::WRL::ComPtr<ID2D1RenderTarget>           m_d2dRenderTarget;
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush>        m_whiteBrush;
        Microsoft::WRL::ComPtr<IDWriteTextFormat>           m_textFormat;

        std::wstring m_previousString;

        // CPU-based variables for configuring the offscreen render target.
        const uint32_t m_textureWidth;
        const uint32_t m_textureHeight;
    };
}
