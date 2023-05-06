
#ifndef __GRAPHIC_DEVICE_H__
#define __GRAPHIC_DEVICE_H__

#include "CoreMinimal.h"

class GraphicDevice
{
public:

	void Init();

	inline Microsoft::WRL::ComPtr<ID3D12Device> GetDevice() const;

private:

	Microsoft::WRL::ComPtr<ID3D12Debug> debugController;

	Microsoft::WRL::ComPtr<IDXGIFactory> dxgi;

	Microsoft::WRL::ComPtr<ID3D12Device> device;

};

#endif
