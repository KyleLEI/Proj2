The tetris project is the result of pair programming, the team consists of CHEN Yau Pun () and LEI Zhao (20327959).
Classes Design:

——————
TetrisBlocks
——————
The class contains the basic information of a tetris block, including:
	a) Its shape, which is represented by the coordinates of each of its squares, 
	b) Its color, represented by Qt::GlobalColor to facilitate further implements, 
	c) The coordinates after it is rotated.
The design of this class is derived from Qt’s Tetrix Example.

——————
TetrisGame
——————
The game class handles core game logic. The class records the color of each square on a 10*20 map, which is a 2D array of Qt::GlobalColor, in which transparency indicates that the square is empty. The instance of this class can handle key presses passed from UI and manipulate the blocks on its map accordingly. The class also returns the current map to the UI through public “constant get functions”.

——————
TetrisWindow
——————
TetrisWindow is mainly a UI. It accepts keyboard input through overridden keypressEvent and pass to the game logic class for further processing. It also reads from the game class and displays the position of blocks. In this way, the core game logic and UI is separated.