
#ifndef __COMMAND_QUEUE_H__
#define __COMMAND_QUEUE_H__

#include "CoreMinimal.h"

class CommandQueue
{
public:

	~CommandQueue();

public:

	void Init(const Microsoft::WRL::ComPtr<class ID3D12Device>& device,
			  const boost::shared_ptr<class SwapChain>& swapChain,
			  const boost::shared_ptr<class DescriptorHeap>& descriptorHeap);

	void WaitSync();

	void RenderBegin(const D3D12_VIEWPORT* viewport, const D3D12_RECT* rect);

	void RenderEnd();

private:

	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;

	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;

	Microsoft::WRL::ComPtr<ID3D12Fence> fence;

	uint32 fenceValue;

	HANDLE fenceEvent;

	boost::shared_ptr<class SwapChain> swapChain;

	boost::shared_ptr<class DescriptorHeap> descriptorHeap;

};

#endif
