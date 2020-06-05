# Find-The-Treasure-A-windows-console-game-with-AI-Implementation
This is a simple console game with matrix game map where you need to find the treasure! You can do it yourself or let the AI to handle it.

## About-The-Game

## The-Game-Map

The game map is a 4x4 matrix defined on the console! It is ideally a rectangle divided into 16 boxes by 4 row grids and 4 column grids. In the main function of the code file the drawRect() function defines the space or the size of the map and the drawGrid() function determines the numbers of grid and draws it.

Here in this game there are two target elements: one is the player bot and another is the Treasure!

## The-Treasure

The treasure is a fixed element of the game and the position of the treasure is entered manually through input. As the gamespace is a 4x4 matrix the coordinate of the Treasure element stays between 1 and 4 i.e. [1,4] for both x and y.

## The-Player-Bot

The player bot is a 'O' shaped element in this game and it is the only movable element in this game. The arrow key i.e. 'UP','DOWN','LEFT' and 'DOWN' keys are used to move the player bot.

The initial position of the player bot is generated randomly and in a way such that the initial positions of the player bot and the Treasure does not collide.

## The-AI

There is a AI to autometically solve the game for the player in a efficient way. To use the AI press the 'LEFT SHIFT' button while playing. Once pressed the AI will take command of the player bot and will automatically aolve and finish the game.

## The-Game

The goal of the game is to lead the player bot to the treasure. If the player bot finds the treasure,this is treated as a success. A successful attempt will lead the game to finish. While the player bot and the treasure are merged , a square made of * is formed(of size 4*4).

## Game-Board-Overview

--------------------
|     |      |     |
--------------------
|     |      |     |
--------------------
|     |      |     |
--------------------
|     |      |     |
--------------------
