#pragma once

class Player {

private:
	float x = window_width / 2;
	float y = window_height / 2;
	float width = 30;
	float height = 30;
	Color color = BLUE;

	float speed = 6;

public:
	void draw() {
		DrawRectangle(x, y, width, height, color);
	}

	void move() {
		Vector2 delta = {0, 0};

		if (IsKeyDown(KEY_RIGHT)) {
			delta.x += 1;
		}
		if (IsKeyDown(KEY_LEFT)) {
			delta.x -= 1;
		}

		if (IsKeyDown(KEY_DOWN)) {
			delta.y += 1;
		}
		if (IsKeyDown(KEY_UP)) {
			delta.y -= 1;
		}

		if (delta.x != 0 or delta.y != 0) {
			float length = sqrt(delta.x * delta.x + delta.y * delta.y);
			float speed_factor = speed / length;

			delta.x *= speed_factor;
			delta.y *= speed_factor;
		}

		x += delta.x;
		y += delta.y;
	}

	void collision(Block& block) {
		if (x <= 0) {
			x = 0;
		}
		if (x >= window_width - width) {
			x = window_width - width;
		}

		if (y <= 0) {
			y = 0;
		}
		if (y >= window_height - height) {
			y = window_height - height;
		}

		if (CheckCollisionRecs(Rectangle{x, y, width, height}, Rectangle{block.x, block.y, block.width, block.height})) {
        float overlapx = fminf(x + width - block.x, block.x + block.width - x);
        float overlapy = fminf(y + height - block.y, block.y + block.height - y);

			if (overlapx < overlapy) {
				if (x + width / 2 < block.x + block.width / 2) {
					x -= overlapx;
				}
				else {
					x += overlapx;
				}
			}
			if (overlapx > overlapy) {
				if (y + height / 2 < block.y + block.height / 2) {
					y -= overlapy;
				}
				else {
					y += overlapy;
				}
			}
		}
	}
};