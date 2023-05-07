
#ifndef __DESCRIPTOR_HEAP_H__
#define __DESCRIPTOR_HEAP_H__

#include "CoreMinimal.h"

class DescriptorHeap
{
public:

	void Init(const Microsoft::WRL::ComPtr<ID3D12Device>& device, 
			  const boost::shared_ptr<class SwapChain>& swapChain);

	inline D3D12_CPU_DESCRIPTOR_HANDLE GetRenderTargetView(uint32 index) const;

	inline D3D12_CPU_DESCRIPTOR_HANDLE GetBackBufferView() const;

private:

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> renderTargetViewHeap;

	uint32 renderTargetViewHeapSize = 0;

	D3D12_CPU_DESCRIPTOR_HANDLE renderTargetViewHandle[SWAP_CHAIN_BUFFER_COUNT];

	boost::shared_ptr<class SwapChain> swapChain;
};

#endif
