
#include "SwapChain.h"

void SwapChain::Init(const WindowInfo& windowInfo, 
					 const Microsoft::WRL::ComPtr<IDXGIFactory>& dxgi, 
					 const Microsoft::WRL::ComPtr<ID3D12CommandQueue>& commandQueue)
{
	swapChain.Reset();

	DXGI_SWAP_CHAIN_DESC swapChainDescriptor;
	swapChainDescriptor.BufferDesc.Width = static_cast<uint32>(windowInfo.width);
	swapChainDescriptor.BufferDesc.Height = static_cast<uint32>(windowInfo.height);
	swapChainDescriptor.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDescriptor.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDescriptor.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDescriptor.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDescriptor.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapChainDescriptor.SampleDesc.Count = 1;
	swapChainDescriptor.SampleDesc.Quality = 0;
	swapChainDescriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDescriptor.BufferCount = SWAP_CHAIN_BUFFER_COUNT;
	swapChainDescriptor.OutputWindow = windowInfo.hwnd;
	swapChainDescriptor.Windowed = windowInfo.windowed;
	swapChainDescriptor.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDescriptor.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	dxgi->CreateSwapChain(commandQueue.Get(), &swapChainDescriptor, &swapChain);

	for (uint32 i = 0; i < SWAP_CHAIN_BUFFER_COUNT; ++i)
	{
		swapChain->GetBuffer(i, IID_PPV_ARGS(&renderTargets[i]));
	}
}

void SwapChain::Present()
{
	swapChain->Present(0, 0);
}

void SwapChain::SwapIndex()
{
	backBufferIndex = (backBufferIndex + 1) % SWAP_CHAIN_BUFFER_COUNT;
}

inline Microsoft::WRL::ComPtr<IDXGISwapChain> SwapChain::GetSwapChain() const
{
	return swapChain;
}

inline Microsoft::WRL::ComPtr<ID3D12Resource> SwapChain::GetRenderTarget(uint32 index) const
{
	return renderTargets[index];
}

inline uint32 SwapChain::GetCurrentBackBufferIndex() const
{
	return backBufferIndex;
}

inline Microsoft::WRL::ComPtr<ID3D12Resource> SwapChain::GetCurrentBackBufferResource() const
{
	return renderTargets[backBufferIndex];
}
