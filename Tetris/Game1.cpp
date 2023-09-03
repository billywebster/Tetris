#include <assert.h>
#include "Game.h"
#include "raylibCpp.h"
#include "Settings.h"

Game1::Game1(int width, int height, int fps, std::string title)
	:
	board(settings::boardPosition,
		settings::boardWidthHeight,
		settings::cellSize,
		settings::padding),
	tetromino(board)
{
	assert(!GetWindowHandle());	//If assertion triggers : Window is already opened
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
}

Game1::~Game1() noexcept
{
	assert(GetWindowHandle()); //If assertion triggers : Window is already closed
	CloseWindow();
}

bool Game1::GameShouldClose() const
{
	return WindowShouldClose();
}

void Game1::Tick()
{
	BeginDrawing();
	Update();
	Draw();
	EndDrawing();
}

void Game1::Update()
{
	if (IsKeyPressed(KEY_E))
	{
		tetromino.RotateClockwise();
	}
	if (IsKeyPressed(KEY_Q))
	{
		tetromino.RotateCounterClockwise();
	}
}

void Game1::Draw()
{
	ClearBackground(BLACK);
	board.Draw();
	tetromino.Draw();
}