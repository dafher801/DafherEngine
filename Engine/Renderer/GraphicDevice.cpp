
#include "GraphicDevice.h"

void GraphicDevice::Init()
{
#ifdef DEBUG
	::D3D12GetDebugInterface(IID_PPV_ARGS(&debugController));
#endif

	::CreateDXGIFactory(IID_PPV_ARGS(&dxgi));
	::D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device));
}

inline Microsoft::WRL::ComPtr<IDXGIFactory> GraphicDevice::GetDXGI() const
{
	return dxgi;
}

inline Microsoft::WRL::ComPtr<ID3D12Device> GraphicDevice::GetDevice() const
{
	return device;
}
