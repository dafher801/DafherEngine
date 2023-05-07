
#ifndef __CORE_MINIMAL_H__
#define __CORE_MINIMAL_H__

#define DEBUG

#include <vector.hpp>
#include <smart_ptr.hpp>
#include <make_unique.hpp>

#include "d3dx12.h"

#include <d3d12.h>
#include <wrl.h>
#include <d3dcompiler.h>
#include <dxgi.h>
#include <d3d12sdklayers.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXColors.h>

#pragma comment(lib, "d3d12")
#pragma comment(lib, "dxgi")
#pragma comment(lib, "dxguid")
#pragma comment(lib, "d3dcompiler")

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;

using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

using Vector2 = DirectX::XMFLOAT2;
using Vector3 = DirectX::XMFLOAT3;
using Vector4 = DirectX::XMFLOAT4;
using Matrix = DirectX::XMMATRIX;
using Viewport = D3D12_VIEWPORT;
using Rect = D3D12_RECT;

enum 
{ 
	SWAP_CHAIN_BUFFER_COUNT = 2
};

struct WindowInfo
{
	HWND hwnd;
	uint32 width;
	uint32 height;
	bool windowed;
};

#endif
