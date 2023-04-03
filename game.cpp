#include "game.h"
#include <raylib.h>
#include <assert.h>
#include "settings.h"
#include "raylibWrapper.h"
#include <iostream>
#include "vec2.h"

Game::Game(int width, int height, int fps, std::string title)
    :
    ball(Vec2{ width / 2, height / 2 }, Vec2{ 3,3 }),
    paddle1(Vec2{ 15, height / 2}, KEY_W, KEY_S),
    paddle2(Vec2{ width - 15, height / 2 }, KEY_UP, KEY_DOWN)
{
    assert(!GetWindowHandle()); //window already open
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());

}

Game::~Game() noexcept
{
    assert(GetWindowHandle()); //window is already closed
    CloseWindow();
}

bool Game::GameShouldClose() const
{
    return WindowShouldClose();
}

void Game::Tick()
{
    BeginDrawing();
    Update();
    Draw();
    DrawFPS(10, 10);
    EndDrawing();
}

void Game::Update()
{
    ball.Update();
    paddle1.Update();
    paddle2.Update();

    //paddle 1 hits ball
    if (paddle1.getPosition().GetX() + paddle1.getWidthHeight().GetX() >= ball.getPosition().GetX())
    {
        if (paddle1.getPosition().GetY() < ball.getPosition().GetY() &&
            paddle1.getPosition().GetY() + paddle1.getWidthHeight().GetY() > ball.getPosition().GetY())
        {
            ball.setVelocity({ -ball.getVelocity().GetX(), ball.getVelocity().GetY() });
        }
    }
    
    //paddle 2 hits ball
    if (paddle2.getPosition().GetX() <= ball.getPosition().GetX())
    {
        if (paddle2.getPosition().GetY() < ball.getPosition().GetY() &&
            paddle2.getPosition().GetY() + paddle2.getWidthHeight().GetY() > ball.getPosition().GetY())
        {
            ball.setVelocity({ -ball.getVelocity().GetX(), ball.getVelocity().GetY() });
        }
    }

    if (ball.getPosition().GetX() < 0)
    {
        //player 2 has scored
        paddle2.score += 1;
        ball.setPosition({ GetScreenWidth() / 2, GetScreenHeight() / 2 });
        ball.setVelocity(Vec2{ -ball.getVelocity().GetX(), ball.getVelocity().GetY() }); //ball starts towards winner
    }
    else if (ball.getPosition().GetX() > GetScreenWidth())
    {
        //player 1 has scored
        paddle1.score += 1;
        ball.setPosition({ GetScreenWidth() / 2, GetScreenHeight() / 2 });
        ball.setVelocity(Vec2{ - ball.getVelocity().GetX(), ball.getVelocity().GetY()}); //ball starts towards winner
    }
}

void Game::Draw()
{
    ClearBackground(BLACK);
    ball.Draw();
    paddle1.Draw();
    paddle2.Draw();

    //dividing line down middle
    raylibWrapper::DrawRectangle({ (GetScreenWidth() / 2) - 5 , 0}, { 10, GetScreenHeight() }, WHITE);


    char buffer[50];

    printf(buffer, "%d", paddle1.score);
    DrawText(buffer, (GetScreenWidth() / 2) - 50, 30, 40, WHITE);
    printf(buffer, "%d", paddle2.score);
    DrawText(buffer, (GetScreenWidth() / 2) + 50, 30, 40, WHITE);

}