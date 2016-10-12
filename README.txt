The tetris project is the result of pair programming, the team consists of CHEN Yau Pun (20317253) and LEI Zhao (20327959).
===================
Class Design

——————
TetrisBlocks
——————
The class contains the basic information of a tetris block, including:
	a) Its shape, which is represented by the relative position of each of its squares.
	b) Its color, represented by Qt::GlobalColor to facilitate further implements, 
	c) The respective positions of its squares after a block is rotated.

The class contains public function that:
	a) Allows retrieval of basic information of a block, including its current shape, each composing square's position and color.
	b) Returns the minimum and maximum x, y value of a block to facilitate the implementation of other classes in the project. Otherwise, the other classes need to perform extra work on the information provided by TetrisBlocks Class.

(Acknowledge)
The design of the TetrisBlock Class is inspired by and adapted from the TetrixShape Class in Qt’s Tetrix Example. Number of Modifications were made to meet our project's objectives.

——————
TetrisGame
——————
The TetrisGame class handles core game logic. The class records the color of each square on a 10*20 map, which is a 2D array of Qt::GlobalColor, in which transparent square indicates that the square should be empty. The instance of this class respond to function calls by the UI Class TetrisWindow and manipulate the blocks on its map accordingly. The class returns the current map to the UI through public function getMap() for the UI the update the GameBoard. At the same time, it returns essential information about next block, current Level and Score to the User Interface.

——————
TetrisWindow
——————
TetrisWindow constitutes the User Interface of the Game. It accepts keyboard input through overridden keypressEvent and calls various function of game instance so that the respective operations can be further processed by the logic implemented in TetrisGame class. It also reads the gameboard Map from the TetrisGame class, updates and displays the position of blocks. 

In this way, the core game logic and UI is separated as implemented in two different classes.

===================
Compilation
-----------
Simply called "make" in terminal in the directory of the source codes.
If want to use "qmake", please make sure the qmake is provided by QT 5.3.2.
The Executable ./Tetris works with QT 5.3.2.