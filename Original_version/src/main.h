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
#ifdef ANDROID
#define KILLMINDS_DATA_PATH ""
#elif defined(SELFISHOS)
#define KILLMINDS_DATA_PATH ""
#else
#define KILLMINDS_DATA_PATH "data/"
#endif

#define title_img KILLMINDS_DATA_PATH"title.bmp"
#define all_img KILLMINDS_DATA_PATH"all.bmp"
#define ready_img KILLMINDS_DATA_PATH"ready.bmp"
#define score_img KILLMINDS_DATA_PATH"score.bmp"
#define start_img KILLMINDS_DATA_PATH"startbutton.bmp"
#define background_img KILLMINDS_DATA_PATH"back.bmp"

#define heart_img KILLMINDS_DATA_PATH"heart.bmp"
#define block_small_img KILLMINDS_DATA_PATH"smallblock.bmp"
#define block_img KILLMINDS_DATA_PATH"block.bmp"
#define hand_anim_img KILLMINDS_DATA_PATH"hand_anim.bmp"
#define inst_img KILLMINDS_DATA_PATH"inst.bmp"
#define trophee_img KILLMINDS_DATA_PATH"trophees.bmp"
#define copyright_img KILLMINDS_DATA_PATH"copyright.bmp"
#define font_img KILLMINDS_DATA_PATH"font.bmp"

#define gameover_sfx KILLMINDS_DATA_PATH"gameover.wav"
#define miss_sfx KILLMINDS_DATA_PATH"miss.wav"
#define move_sfx KILLMINDS_DATA_PATH"move1.wav"

#define move2_sfx KILLMINDS_DATA_PATH"move2.wav"
#define move3_sfx KILLMINDS_DATA_PATH"move3.wav"
#define move4_sfx KILLMINDS_DATA_PATH"move4.wav"

#define fullsqr_sfx KILLMINDS_DATA_PATH"fullsquare.wav"

#define upleft_sfx KILLMINDS_DATA_PATH"upleft.wav"
#define upright_sfx KILLMINDS_DATA_PATH"upright.wav"
#define downleft_sfx KILLMINDS_DATA_PATH"downleft.wav"
#define downright_sfx KILLMINDS_DATA_PATH"downright.wav"

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

static void Show_Instructions();

void Show_copyright();
