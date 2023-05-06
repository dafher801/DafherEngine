
#include "CoreMinimal.h"
#include "Engine.h"
#include "GraphicDevice.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "DescriptorHeap.h"

void Engine::Init(const WindowInfo& windowInfo)
{
	this->windowInfo = windowInfo;

	ResizeWindow(windowInfo.width, windowInfo.height);

	viewport = { 0, 0, static_cast<FLOAT>(windowInfo.width), static_cast<FLOAT>(windowInfo.height), 0.0f, 1.0f };
	scissorRect = Rect(0, 0, windowInfo.width, windowInfo.height);

	graphicDevice = boost::make_shared<GraphicDevice>();
	commandQueue = boost::make_shared<CommandQueue>();
	swapChain = boost::make_shared<SwapChain>();
	descriptorHeap = boost::make_shared<DescriptorHeap>();

	graphicDevice->Init();
	commandQueue->Init(graphicDevice->GetDevice(), swapChain, descriptorHeap);
}

void Engine::Render()
{
}

void Engine::ResizeWindow(uint32 width, uint32 height)
{
	windowInfo.width = width;
	windowInfo.height = height;

	Rect rect = { 0, 0, width, height };

	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	::SetWindowPos(windowInfo.hwnd, 0, 100, 100, width, height, 0);
}
