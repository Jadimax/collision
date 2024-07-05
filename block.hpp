#pragma once

class Block {

private:
	Color color = GREEN;

public:
	float x = window_width / 4;
	float y = window_height / 4;
	float width = 60;
	float height = 60;

	void draw() {
		DrawRectangle(x, y, width, height, color);
	}
};