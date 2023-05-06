
#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "CoreMinimal.h"

class Engine
{
public:

	void Init(const WindowInfo& windowInfo);

	void Render();

	void ResizeWindow(uint32 width, uint32 height);

private:

	Engine() = default;

	Engine(const Engine& engine) = default;

	Engine& operator=(const Engine& engine) = default;

private:

	WindowInfo windowInfo;

	Viewport viewport = {};

	Rect scissorRect = {};

	boost::shared_ptr<class GraphicDevice> graphicDevice;

	boost::shared_ptr<class CommandQueue> commandQueue;

	boost::shared_ptr<class SwapChain> swapChain;

	boost::shared_ptr<class DescriptorHeap> descriptorHeap;

};

#endif
