/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	D3DGraphics.cpp																		  *
 *	Copyright 2011 PlanetChili.net														  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "D3DGraphics.h"
#include <assert.h>

D3DGraphics::D3DGraphics( HWND hWnd )
{
	backRect.pBits = NULL;

	pDirect3D = Direct3DCreate9( D3D_SDK_VERSION );

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp,sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

    pDirect3D->CreateDevice( D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,&d3dpp,&pDevice );

	pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer);
}

D3DGraphics::~D3DGraphics()
{
	if( pDevice )
	{
		pDevice->Release();
		pDevice = NULL;
	}
	if( pDirect3D )
	{
		pDirect3D->Release();
		pDirect3D = NULL;
	}
	if (pBackBuffer)
	{
		pBackBuffer->Release();
		pBackBuffer = NULL;
	}
}

void D3DGraphics::PutPixel( int x,int y,int r,int g,int b )
{
	assert(x >= 0);
	assert(y >= 0);
	assert(x < SCREENWIDTH);
	assert(y < SCREENHEIGHT);
	((D3DCOLOR*)backRect.pBits)[x + (backRect.Pitch >> 2) * y] = D3DCOLOR_XRGB(r, g, b);
}

void D3DGraphics::PutPixelClipped(int x, int y, int r, int g, int b)
{
	if (x >= 0 && y >= 0 && x < SCREENWIDTH && y < SCREENHEIGHT)
	{
		((D3DCOLOR*)backRect.pBits)[x + (backRect.Pitch >> 2) * y] = D3DCOLOR_XRGB(r, g, b);
	}
}

void D3DGraphics::DrawLine(int x1, int y1, int x2, int y2, int r, int g, int bl)
{

	int dX = x2 - x1;
	int dY = y2 - y1;

	if (abs(dY) > abs(dX))
	{
		int x;
		float m = (float)dX / (float)dY;
		float b = x1 - m * y1;

		if (y1 > y2)
		{
			int temp = y2;
			y2 = y1;
			y1 = temp;
			temp = x2;
			x2 = x1;
			x1 = temp;
		}

		for (int y = y1; y <= y2; ++y)
		{
			x = (int)(m * y + b + 0.5f);
			PutPixel(x, y, r, g, bl);
		}
	}
	else
	{
		int y;
		float m = (float)dY / (float)dX;
		float b = y1 - m * x1;

		if (x1 > x2)
		{
			int temp = x2;
			x2 = x1;
			x1 = temp;
			temp = y2;
			y2 = y1;
			y1 = temp;
		}

		for (int x = x1; x <= x2; ++x)
		{
			y = (int)(m * x + b + 0.5f);
			PutPixel(x, y, r, g, bl);
		}
	}
}

void D3DGraphics::DrawCircle(int cX, int cY, int rad, int r, int g, int b)
{
	float radSqr = (float)(rad * rad);
	int y;
	int x0 = (int)(0.7071068f * rad + 0.5f);
	for (int x = 0; x <= x0; ++x)
	{
		y = (int)(sqrt(radSqr - x * x) + 0.5f);
		PutPixel(cX + x, cY + y, r, g, b);
		PutPixel(cX + y, cY + x, r, g, b);
		PutPixel(cX - x, cY + y, r, g, b);
		PutPixel(cX - y, cY + x, r, g, b);
		PutPixel(cX + x, cY - y, r, g, b);
		PutPixel(cX + y, cY - x, r, g, b);
		PutPixel(cX - x, cY - y, r, g, b);
		PutPixel(cX - y, cY - x, r, g, b);
	}
}

void D3DGraphics::DrawDiscClipped(float cX, float cY, float rad, int r, int g, int b)
{
	for (int x = (int)(cX - rad + 0.5f); x < (int)(cX + rad + 0.5f); ++x)
	{
		for (int y = (int)(cY - rad + 0.5f); y < (int)(cY + rad + 0.5f); ++y)
		{
			if (sqrt((float)((x - cX) * (x - cX) + (y - cY) * (y - cY))) < rad)
			{
				PutPixelClipped(x, y, r, g, b);
			}
		}
	}
}

void D3DGraphics::BeginFrame()
{
	pDevice->Clear( 0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),0.0f,0 );
	pBackBuffer->LockRect(&backRect, NULL, NULL);
}

void D3DGraphics::EndFrame()
{
	pBackBuffer->UnlockRect();
	pDevice->Present( NULL,NULL,NULL,NULL );
}