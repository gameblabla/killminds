/*
	Copyright (C) 2016 Gameblabla
	Licensed under the GAMEBLABLA's VIDEO GAME PUBLIC LICENSE version 1.0.
	See COPYING file for more details.
	If a COPYING file was not provided, you can ask the copyright holder for a copy at :
	<gameblabla@openmailbox.org>
		
	This Program is distributed without WITHOUT ANY WARRANTY; 
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
	See the GAMEBLABLA's VIDEO GAME PUBLIC LICENSE for more details.
*/

#define title_img "data/title.bmp"
#define all_img "data/all.bmp"
#define ready_img "data/ready.bmp"
#define score_img "data/score.bmp"
#define start_img "data/startbutton.bmp"
#define background_img "data/back.bmp"

#define heart_img "data/heart.bmp"
#define block_up_img "data/block_up.bmp"
#define block_left_img "data/block_left.bmp"
#define block_right_img "data/block_right.bmp"
#define block_down_img "data/block_down.bmp"
#define block_img "data/block.bmp"
#define hand_anim_img "data/hand_anim.bmp"
#define inst_img "data/inst.bmp"
#define trophee_img "data/trophees.bmp"
#define copyright_img "data/copyright.bmp"
#define font_img "data/font.bmp"

#define gameover_sfx "data/gameover.wav"
#define miss_sfx "data/miss.wav"
#define move_sfx "data/move1.wav"

#define move2_sfx "data/move2.wav"
#define move3_sfx "data/move3.wav"
#define move4_sfx "data/move4.wav"

#define fullsqr_sfx "data/fullsquare.wav"

#define upleft_sfx "data/upleft.wav"
#define upright_sfx "data/upright.wav"
#define downleft_sfx "data/downleft.wav"
#define downright_sfx "data/downright.wav"


// Initialize game
void InitializeGame();

// Game loop
void GameLoop();

// Show 1/4 chosen
void Show_Square();
void Move_Square();

void Show_highscore();
void Show_startbutton();

void Show_Game();

short reset_case();

void lose_a_life();
void add_allsprites();

void calcul_score();
void Titlescreen();
void RESET_EVERYTHING();

void go_back_titlescreen();
void go_ingame();

// Reset
void Reset();

void Load_Sounds();

short rand_a_b(short a, short b);

void Load_score();
void Save_score();

void Update_highscore();

short rand_a_b(short a, short b);
unsigned char touch_sqr(unsigned short x, unsigned short x2, unsigned short y, unsigned short y2);
unsigned short check_square_score(unsigned char* square_tmp, unsigned char spot);

void Set_Show_Score(unsigned int score, unsigned char spot);

void Put_hands();
void Put_squares();
void Put_score_lives();
void Put_slots();
inline void Put_time();
void Reload_time();

inline void Show_Instructions();

void Show_copyright();
