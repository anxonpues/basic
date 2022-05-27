/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	x( 0 ),
	y( 0 ),
	c(255,255,255)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{


}


void Game::ComposeFrame()
{
	for (int i = 0; i < sw; i++)
	{
		int colnmb = (framecount / (262144)) % 12;
		int res = (framecount / 262144) % 128;
		red = 255 * (colnmb < 3 || colnmb >10) +
			(255 - res) * (colnmb == 3) +
			(128 - res) * (colnmb == 4) +
			res * (colnmb == 9) +
			(128 + res) * (colnmb == 10);
		green = res * (colnmb == 1) +
			(128 + res) * (colnmb == 2) +
			255 * (colnmb >= 2 && colnmb <= 6) +
			(255 - res) * (colnmb == 7) +
			(128 - res) * (colnmb == 8);
		blue = res * (colnmb == 5) +
			(128 + res) * (colnmb == 6) +
			255 * (colnmb >= 6 && colnmb <= 10) +
			(255 - res) * (colnmb == 11) +
			(128 - res) * (colnmb == 0);
		float retard = 1000.0f;
		while (retard > 0.0f)
		{
			retard = retard - 0.1f;

		}
			
		framecount++;
		x++;
		gfx.VertLine(i, y, 100, red, green, blue);
	}
		
	//if (!init) 
	//{
	//	for (int j = 0; j < 80; j++)
	//		for (int i = 0; i < 80; i++)
	//			gfx.PutPixel(x + i, y + j, c);
	//	for (int j = 00; j < 80; j++)
	//		for (int i = 80; i < 160; i++)
	//		{ 
	//			gfx.PutPixel(x + i, y + j, 255,255,0);
	//			Color  tc = gfx.GetPixel(x + i, y + j);
	//			unsigned char r, g, b;
	//			r = tc.GetR();
	//			g = tc.GetG();
	//			b = tc.GetB();

	//		}
	//	init = true;
	//}
	//else
	//{
	//	float  retard = 0;
	//	for (int j = 0; j < 80; j++)
	//		for (int i = 159; i >= 80; i--)
	//		{ 
	//			Color  tc = gfx.GetPixel(x + i, y + j);
	//			unsigned char r, g, b;
	//			r = tc.GetR();
	//			g = tc.GetG();
	//			b = tc.GetB();
	//			for (int k = 0; k < 255; k++)
	//			{
	//				retard = retard + 0.0001f;
	//				if (retard > 1000.0f)
	//				{
	//					retard = 0.0f;
	//					gfx.PutPixel(x + i - 80, y + j, (r+k) % 127, (g+k) % 63, (b+k) % 31);
	//					break;
	//				}
	//					
	//				//gfx.PutPixel(x + i - 80, y + j, r%127, g%63, b%31);
	//			}
	//			
	//		}
	//	init = false;
	//}
}

