#pragma once
#include <string>
#include "Board.h"
#include "Tetrominoes.h"

class Game1
{
public:
	Game1(int width, int height, int fps, std::string title);
	Game1(const Game1& other) = delete;
	Game1& operator=(const Game1& other) = delete;

	~Game1() noexcept;
	bool GameShouldClose() const;
	void Tick();

private:
	void Draw();
	void Update();

	Board board;
	Jay tetromino;

};
