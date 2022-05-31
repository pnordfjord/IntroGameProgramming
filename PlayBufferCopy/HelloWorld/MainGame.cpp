#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"

int DISPLAY_WIDTH = 1280;
int DISPLAY_HEIGHT = 720;
int DISPLAY_SCALE = 1;

struct GameState
{
	int score = 0;
};

GameState gameState;

enum GameObjectType
{
	TYPE_NULL = -1,
	TYPE_PADDLE,
	TYPE_BALL,
};

void HandlePlayerControls();
void UpdateBall();
void UpdatePaddles();

void MainGameEntry(PLAY_IGNORE_COMMAND_LINE)
{
	Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
	Play::CentreAllSpriteOrigins();
	Play::LoadBackground("Data\\Backgrounds\\background.png");
	Play::CreateGameObject(TYPE_BALL, { (DISPLAY_WIDTH / 2), (DISPLAY_HEIGHT / 2) }, 50, "coin");
	Play::CreateGameObject(TYPE_PADDLE, { 50, DISPLAY_HEIGHT / 2 }, 50, "");
	Play::CreateGameObject(TYPE_PADDLE, { DISPLAY_WIDTH - 50, (DISPLAY_HEIGHT / 2) }, 50, "");

}

bool MainGameUpdate(float elapsedTime)
{
	Play::DrawBackground();
	HandlePlayerControls();
	UpdateBall();
	Play::PresentDrawingBuffer();
	return Play::KeyDown(VK_ESCAPE);
}

void UpdateBall() {
	GameObject& ball = Play::GetGameObjectByType(TYPE_BALL);
	if (ball.velocity.x == 0)
		ball.velocity = { -4, 0 };
	ball.acceleration = { 0, 0 };
	if (ball.velocity.x > 5) ball.velocity.x = 5.0f;
	if (ball.velocity.x < -5) ball.velocity.x = -5.0f;

	Play::UpdateGameObject(ball);
	Play::DrawObject(ball);
}

void HandlePaddleControl(GameObject& paddle, int upKey, int downKey) {
	if (Play::KeyDown(upKey)) {
		paddle.velocity.y = -4.0f;
	}
	else if (Play::KeyDown(downKey)) {
		paddle.velocity.y = 4.0f;
	}
	else {
		paddle.velocity.y = 0;
	}

	Play::UpdateGameObject(paddle);
	Play::DrawObject(paddle);

	GameObject& ball = Play::GetGameObjectByType(TYPE_BALL);
	if (Play::IsColliding(ball, paddle)) {
		ball.velocity.x = -ball.velocity.x * 1.1f;
	}
}

void HandlePlayerControls()
{
	auto paddles = Play::CollectGameObjectIDsByType(TYPE_PADDLE);
	HandlePaddleControl(Play::GetGameObject(paddles[0]), 0x57, 0x53);
	HandlePaddleControl(Play::GetGameObject(paddles[1]), VK_UP, VK_DOWN);
	//GameObject& obj_ball = Play::GetGameObjectByType(TYPE_BALL);
	//if (Play::KeyDown(VK_UP))
	//{
	//}
	//else if (Play::KeyDown(VK_DOWN))
	//{
	//	obj_ball.acceleration = { 0, 1 };
	//}
	//else
	//{
	//	obj_ball.velocity *= 0.5f;
	//	obj_ball.acceleration = { 0, 0 };
	//}
	//Play::UpdateGameObject(obj_ball);
	//if (Play::IsLeavingDisplayArea(obj_ball))
	//	obj_ball.pos = obj_ball.oldPos;
	//Play::DrawCircle( obj_ball.pos, 50, Play::cWhite);
	//Play::DrawObjectRotated(obj_ball);
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}