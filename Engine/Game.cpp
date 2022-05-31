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
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::shape()
{
	int line = 0;
	//blue = 0;
	for (int i = 0; i < 255; i++)	
	{
		red = red + 1;
		vertlines[line] = blue | (green << 8) | (red << 16);
		line++;
	}
	line--;
	for (int i = 0; i < 255; i++) 
	{
		green = green + 1;
		vertlines[line] = blue | (green << 8) | (red << 16);
		line++;
	}
	line--;
	for (int i = 0; i < 255; i++) 
	{
		red = red -1;
		vertlines[line] = blue | (green << 8) | (red << 16);
		line++;
	}
	line--;
	for (int i = 0; i < 255; i++) 
	{
		blue = blue + 1;
		vertlines[line] = blue | (green << 8) | (red << 16);
		line++;
	}
	line--;
	for (int i = 0; i < 255; i++) 
	{
		green = green - 1;
		vertlines[line] = blue | (green << 8) | (red << 16);
		line++;
	}
	line--;
	for (int i = 0; i < 255; i++)	
	{
		blue= blue - 1;
		vertlines[line] = blue | (green << 8) | (red << 16);
		line++;
	}
	line--;
	if (line)
		int flop = 4;
}

void Game::UpdateModel()
{
	//while (framen < 0xffff)
	//{
	//	int line;
	//	for (int i = 0; i < 255; i++)	// red stays up, green stays down and blue goes down
	//	{
	//		blue--;
	//		framen++;
	//		line = framen % 800;
	//		vertlines[line] = blue | (green << 8) | (red << 16);
	//		//pt(framen, line, vertlines[line]);
	//	}
	//	for (int i = 0; i < 255; i++) // now red stays up and rise green
	//	{
	//		green++;
	//		framen++;
	//		line = framen % 800;
	//		vertlines[line] = blue | (green << 8) | (red << 16);
	//		//pt(framen, line, vertlines[line]);
	//	}
	//	for (int i = 0; i < 255; i++) // now red downs to 0 while green stays up
	//	{
	//		red++;
	//		framen++;
	//		line = framen % 800;
	//		vertlines[line] = blue | (green << 8) | (red << 16);
	//		//pt(framen, line, vertlines[line]);
	//	}
	//	for (int i = 0; i < 255; i++) // red stays down and blue rises while green stays up
	//	{
	//		blue++;
	//		framen++;
	//		line = framen % 800;
	//		vertlines[line] = blue | (green << 8) | (red << 16);
	//		//pt(framen, line, vertlines[line]);
	//	}
	//	for (int i = 0; i < 255; i++) // red down green downs to 0 while blue stays up
	//	{
	//		green--;
	//		framen++;
	//		line = framen % 800;
	//		vertlines[line] = blue | (green << 8) | (red << 16);
	//		//pt(framen, line, vertlines[line]);
	//	}
	//	for (int i = 0; i < 255; i++)	// red rising up, green stays down blue stays up
	//	{
	//		red--;
	//		framen++;
	//		line = framen % 800;
	//		vertlines[line] = blue | (green << 8) | (red << 16);
	//		//pt(framen, line, vertlines[line]);
	//	}
	//	for (int i = 0; i < 255; i++)	// red rising up, green stays down blue stays up
	//	{
	//		blue++;
	//		framen++;
	//		line = framen % 800;
	//		vertlines[line] = blue | (green << 8) | (red << 16);
	//		//pt(framen, line, vertlines[line]);
	//	}
	//}

}

void Game::ComposeFrame()
{
	for (int i = 0; i < 800; i++)
	{
		gfx.VertLine(i, 20, 100, vertlines[(framen)%(1524)]);
		//gfx.VertLine(i, 20, 100, vertlines[(framen) % (800)]);
		float ret = 0.0f;
		while (ret < 333.0f)
			ret = ret + 0.001f;
		framen++;
		framen = framen & 0xfffffff;
	}
}

