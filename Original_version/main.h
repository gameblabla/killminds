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

#define title_img "title.bmp"
#define all_img "all.bmp"
#define ready_img "ready.bmp"
#define score_img "score.bmp"
#define start_img "startbutton.bmp"
#define background_img "back.bmp"

#define heart_img "heart.bmp"
#define block_up_img "block_up.bmp"
#define block_left_img "block_left.bmp"
#define block_right_img "block_right.bmp"
#define block_down_img "block_down.bmp"
#define block_img "block.bmp"
#define hand_anim_img "hand_anim.bmp"
#define inst_img "inst.bmp"
#define trophee_img "trophees.bmp"
#define copyright_img "copyright.bmp"
	
#define gameover_sfx "gameover.wav"
#define miss_sfx "miss.wav"
#define move_sfx "move1.wav"

#define move2_sfx "move2.wav"
#define move3_sfx "move3.wav"
#define move4_sfx "move4.wav"

#define fullsqr_sfx "fullsquare.wav"

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
unsigned short check_square_score(unsigned char* square_tmp);

void Put_hands();
void Put_squares();
void Put_score_lives();
void Put_slots();
inline void Put_time();
void Reload_time();

inline void Show_Instructions();

void Show_copyright();
