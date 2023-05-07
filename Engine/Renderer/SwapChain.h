
#ifndef __SWAP_CHAIN_H__
#define __SWAP_CHAIN_H__

#include "CoreMinimal.h"

class SwapChain
{
public:

	void Init(const WindowInfo& windowInfo, 
			  const Microsoft::WRL::ComPtr<IDXGIFactory>& dxgi, 
			  const Microsoft::WRL::ComPtr<ID3D12CommandQueue>& commandQueue);

	void Present();

	void SwapIndex();

	inline Microsoft::WRL::ComPtr<IDXGISwapChain> GetSwapChain() const;

	inline Microsoft::WRL::ComPtr<ID3D12Resource> GetRenderTarget(uint32 index) const;

	inline uint32 GetCurrentBackBufferIndex() const;

	inline Microsoft::WRL::ComPtr<ID3D12Resource> GetCurrentBackBufferResource() const;

private:

	Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;

	Microsoft::WRL::ComPtr<ID3D12Resource> renderTargets[SWAP_CHAIN_BUFFER_COUNT];

	uint32 backBufferIndex = 0;

};

#endif
