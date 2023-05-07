
#include "DescriptorHeap.h"
#include "SwapChain.h"

void DescriptorHeap::Init(const Microsoft::WRL::ComPtr<ID3D12Device>& device, 
						  const boost::shared_ptr<SwapChain>& swapChain)
{
	this->swapChain = swapChain;

	renderTargetViewHeapSize = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

	D3D12_DESCRIPTOR_HEAP_DESC renderTargetViewDescriptor;
	renderTargetViewDescriptor.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
	renderTargetViewDescriptor.NumDescriptors = SWAP_CHAIN_BUFFER_COUNT;
	renderTargetViewDescriptor.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
	renderTargetViewDescriptor.NodeMask = 0;

	device->CreateDescriptorHeap(&renderTargetViewDescriptor, IID_PPV_ARGS(&renderTargetViewHeap));

	D3D12_CPU_DESCRIPTOR_HANDLE renderTargetViewHeapBegin = renderTargetViewHeap->GetCPUDescriptorHandleForHeapStart();

	for (int i = 0; i < SWAP_CHAIN_BUFFER_COUNT; ++i)
	{
		renderTargetViewHandle[i] = CD3DX12_CPU_DESCRIPTOR_HANDLE(renderTargetViewHeapBegin, i * renderTargetViewHeapSize);
		device->CreateRenderTargetView(swapChain->GetRenderTarget(i).Get(), nullptr, renderTargetViewHandle[i]);
	}
}

inline D3D12_CPU_DESCRIPTOR_HANDLE DescriptorHeap::GetRenderTargetView(uint32 index) const
{
	return renderTargetViewHandle[index];
}

inline D3D12_CPU_DESCRIPTOR_HANDLE DescriptorHeap::GetBackBufferView() const
{
	return GetRenderTargetView(swapChain->GetCurrentBackBufferIndex());
}
