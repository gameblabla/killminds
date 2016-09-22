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

/*
 * The source code could be improved 
 * I could improve how the code is structured
 * I can also improve Input
 * 
 * At least it works
*/

#include "API.h"
#include "INPUT.h"
#include "main.h"
#include "defines.h"

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

/*
 * GLOBALS 
 * All variables are declared here
*/

struct hand_instructions
{
	unsigned char anim;
	unsigned char time;
} hand_inst;

struct instruction_screen
{
	unsigned char alpha;
	unsigned short time;
} inst_scr;

struct level_struct
{
	unsigned char level;
	unsigned long exp;
	unsigned char latency;
	unsigned char latency_time;
} lvl_struct;

struct sqr
{
	unsigned char position;
	unsigned char color;
	unsigned char chain;
} square;

unsigned char button_status[5];

unsigned char right_spot[4], left_spot[4], up_spot[4], down_spot[4];

short time_game = 0;
short game_status = 0;
short frame_gamemo = 0;

unsigned char lives = 3;
unsigned long score = 0;
unsigned long highscore = 0;
unsigned char game_mode = 0;
unsigned char score_showed[7], highscore_show[7];
unsigned char stop_game = 0;
unsigned char start_beginning = 2;
unsigned short pts_live = 0;
unsigned short go_time = 0;
unsigned char black_transition_alpha = 0;

/*
 * 
 * Main loop
 * 
*/

int main(int argc, char* argv[])
{
	InitializeGame();
	srand(time(NULL));

	while (!done)
	{
		Controls();
		GameLoop();
		Update_video();
	}

	Clearing(0);

	return 0;
}

/*
 * 
 * This function is used only at startup
 * 
*/
void InitializeGame()
{
	unsigned char i;
	
	Init_video();

	Load_Image(1,title_img,0);
	Load_Sounds();
	add_allsprites();

	for (i=0;i<7;i++)
	{
		score_showed[i] = 0;
		highscore_show[i] = 0;
	}
	
	Load_score();
	reset_case();
}


/*
 * 
 * This function is used only at startup
 * 
*/
void GameLoop()
{
	if (BUTTON.QUIT) done = 1;

	Put_image(1,0,0,1);
	
	switch(game_mode)
	{
		case TITLESCREEN:
			Titlescreen();
			Show_highscore();
			Show_startbutton();
			Show_copyright();
		break;

		case INGAME:
			Show_Game();
			Show_Square();
			Reload_time();
			if (game_status == 0) Move_Square();
		break;
		
		case INSTRUCTIONS_INGAME:
			Show_Instructions();
			Show_Square();
		break;
	}
}

void Titlescreen()
{
	if (BUTTON.START == 1 || BUTTON.A || touch.state == 1)
	{
		go_ingame();
	}
}

/*
 * Graphical stuff to put on screen
 * 
*/

void add_allsprites()
{
	// Sprite_case
	Load_Image(2,all_img,1);
	
	Load_Image(3,trophee_img,1);
	
	// Score_0, ... , Score_6, Lives_spr , Time_0, ... , Time_2
	Load_Image(5,score_img,1);
	
	// Press start button
	Load_Image(6,start_img,1);
	
	Load_Image(7,block_left_img,1);
	Load_Image(8,heart_img,1);
	Load_Image(9,block_right_img,1);
	Load_Image(10,block_up_img,1);
	Load_Image(11,block_down_img,1);
	Load_Image(12,block_img,1);
	Load_Image(13,hand_anim_img,1);
	Load_Image(14,inst_img,1);
	Load_Image(15,copyright_img,1);
}

void Show_highscore()
{
	/* I could loop this but unlooping is faster */
	Put_sprite(5, 55, 360, 10, 10, highscore_show[0], 3);
	Put_sprite(5, 55+30, 360, 10, 10, highscore_show[1], 3);
	Put_sprite(5, 55+60, 360, 10, 10, highscore_show[2], 3);
	Put_sprite(5, 55+90, 360, 10, 10, highscore_show[3], 3);
	Put_sprite(5, 55+120, 360, 10, 10, highscore_show[4], 3);
	Put_sprite(5, 55+150, 360, 10, 10, highscore_show[5], 3);
	Put_sprite(5, 55+180, 360, 10, 10, highscore_show[6], 3);
	
	if (highscore > 10000)
		Put_sprite(3, 260, 400, 17, 16, 0, 1);
	else if (highscore > 5000)
		Put_sprite(3, 260, 400, 17, 16, 1, 1);
	else if (highscore > 1000)
		Put_sprite(3, 260, 400, 17, 16, 2, 1);
}

void Show_startbutton()
{
	static unsigned char time_press = 0;
	
	time_press++;
	
	if (time_press < 30)
	{
		Put_image(6, 60, 240, 2);
	}
	else if (time_press > 59) 
	{
		time_press = 0;
	}
}

void Show_copyright()
{
	Put_image(15, 56, 420, 1);
}

void Show_Square()
{
	static short frame = 0;

	Put_sprite(2, 122, 201, 40, 38, frame, 2);

	switch(game_status)
	{
		case 2:
			go_time++;
			
			// Show "Game Over" frame
			frame = 14;

			if (go_time > 180) go_back_titlescreen();
		break;
		
		case 1:
			frame = 13;

			if (frame_gamemo > 55)
			{
				game_status = 0;
				frame_gamemo = 0;
			}
			else 
			{
				frame_gamemo++;
			}
		break;
		
		case 0:
			// Show the square you're holding
			frame = square.position;
		break;
	}


}

void Put_slots()
{
	Put_image(7, 118-100, 197, 2);
	Put_image(12, 118, 197, 1);
	Put_image(9, 118+100, 197, 2);
	Put_image(10, 118, 197-100, 2);
	Put_image(11, 118, 197+100, 2);
}

void Put_score_lives()
{
	unsigned char i;

	//	Score_0 ,..., Score_6
	for (i=0;i<7;i++)
	{
		Put_sprite(5, 64+(i*30), 388, 10, 10, score_showed[i], 3);
	}
	
	//	Lives_spr
	Put_image(8, 120, 424, 5);
	Put_sprite(5, 172, 432, 10, 10, lives, 2);
}

inline void Put_time()
{
	unsigned char conv_time[3], lowtime;
	
	if (time_game < 33) 
	{
		lowtime = 10;
	}
	else 
	{
		lowtime = 0;
	}
	
	/* Convert time so it can be display with sprites */
	conv_time[0] = (time_game / 100) % 10;
	conv_time[1] = (time_game / 10) % 10;
	conv_time[2] = time_game % 10;
	
	//	Time sprites
	Put_sprite(5, 115, 48, 10, 10, conv_time[0]+lowtime, 3);
	Put_sprite(5, 115+30, 48, 10, 10, conv_time[1]+lowtime, 3);
	Put_sprite(5, 115+60, 48, 10, 10, conv_time[2]+lowtime, 3);
}

void Put_squares()
{
	unsigned char i;

	/*
	 * The following put the squares on screen
	 * If the square is empty then it is not shown
	*/

	for (i=0;i<4;i++)
	{
		if (left_spot[i] != 0) Put_sprite(2, 22, 201, 40, 38, left_spot[i], 2);
		if (right_spot[i] != 0) Put_sprite(2, 222, 201, 40, 38, right_spot[i], 2);
		if (up_spot[i] != 0) Put_sprite(2, 122, 201-100, 40, 38, up_spot[i], 2);
		if (down_spot[i] != 0) Put_sprite(2, 122, 201+100, 40, 38, down_spot[i], 2);
	}
}

void Put_hands()
{
	const unsigned char hand_frames[8] = {0,1,2,3,2,1,128};
	if (start_beginning > 0)
	{
		Put_sprite(13, 24, 180, 40, 22, hand_frames[hand_inst.anim], 3);
		Put_sprite(13, 24+200, 180, 40, 22, hand_frames[hand_inst.anim], 3);
		Put_sprite(13, 124, 180-100+17, 40, 22, hand_frames[hand_inst.anim], 3);
		Put_sprite(13, 124, 180+100+17, 40, 22, hand_frames[hand_inst.anim], 3);
		
		hand_inst.time++;
		if (hand_inst.time > 2)
		{
			hand_inst.anim++;
			if (hand_frames[hand_inst.anim] == 128) hand_inst.anim = 0;
			hand_inst.time = 0;
		}
	}
}

/*
 * In-Game main functions
 * 
*/

inline void Show_Game()
{
	Put_slots();
	Put_squares();
	Put_score_lives();
	Put_time();
	Put_hands();

	/* Gameplay, increase difficulty as player progresses */
	if (lvl_struct.exp > 100+(lvl_struct.level*15))
	{
		lvl_struct.exp = 0;
		if (lvl_struct.level < 99) lvl_struct.level++;
		if (lvl_struct.latency > 0) lvl_struct.latency--;
	}
	
	if (pts_live > 1000)
	{
		if (lives < 9) lives++;
		pts_live = 0;
	}
}

/*
 * The introduction screen at the very beginning
 * 
*/
inline void Show_Instructions()
{
	Put_slots();
	Put_squares();
	Put_image_alpha(14, inst_scr.alpha);	
	
	if (inst_scr.time > 0) inst_scr.time--;
	if (inst_scr.time == 0) 
	{
		if (inst_scr.alpha > 3) 
		{
			inst_scr.alpha = inst_scr.alpha - 4;
		}
		else 
		{
			inst_scr.alpha = inst_scr.alpha - inst_scr.alpha;
		}
	}
	if (inst_scr.alpha < 12 || (touch.state == 1 || BUTTON.A)) 
	{
		game_mode = INGAME;
	}
}

/*
 * 
 * In-Game functions
 * 
*/

unsigned short check_square_score(unsigned char* square_tmp)
{
	// Check if all squares are green
	unsigned char i;
	unsigned short score_togive;

	for(i=0;i<3;i++)
	{
		if (square_tmp[0] == 1+(4*i) && square_tmp[1] == 2+(4*i) && square_tmp[2] == 3+(4*i) && square_tmp[3] == 4+(4*i))
		{
			lvl_struct.exp = lvl_struct.exp + 50;
			pts_live += 300;
			square.chain += 1;
			score_togive = 300*square.chain;
			Play_SFX(7);
			return score_togive;
		}
	}
	
	square.chain = 0;
	lvl_struct.exp = lvl_struct.exp + 25;
	pts_live += 30;
	return 30;
}

unsigned char touch_sqr(unsigned short x, unsigned short x2, unsigned short y, unsigned short y2)
{
	if (touch.x > x && touch.x < x2 && touch.y > y && touch.y < y2 && touch.state == 1)
		return 1;
	else
		return 0;
}

void Reload_time()
{
	lvl_struct.latency_time++;
	if (lvl_struct.latency_time > lvl_struct.latency)
	{
		if (game_status == 0) 
		{
			if (start_beginning == 0 || (start_beginning > 0 && time_game > 100))
			{
				time_game--;
			}
		}
		lvl_struct.latency_time = 0;
	}	
}

/*
 *
 * Look at this monstrosity... 
 * 
*/

void Move_Square()
{
	unsigned char i;
	unsigned short sqr_score_filled;
	unsigned char canmove_square;
	
	// Player can play after some ms (or right now if instructions are shown)
	canmove_square = (time_game < 93 && start_beginning == 0) || (time_game == 100 && start_beginning > 0);
	
	if (time_game < 1)	// Player lose a live after running out of time
	{
		lose_a_life();
		reset_case();
	}
	else if (canmove_square)
	{
		if (BUTTON.UP || touch_sqr(100, 212, 97, 188))
		{
			for(i=0;i<4;i++)
			{
				if ((square.position == 1+i || square.position == 5+i || square.position == 9+i || square.position == 13+i))
				{
					if (up_spot[i] == 0)
					{
						Play_SFX(3);
						if (start_beginning > 0) start_beginning--;
						up_spot[i] = square.position;
					}
					else if (up_spot[i] > 0)
					{
						lose_a_life();
					}
				}	
			}
			
			if (up_spot[0] > 0 && up_spot[1] > 0 && up_spot[2] > 0 && up_spot[3] > 0)
			{
				sqr_score_filled = check_square_score(up_spot);
				for(i=0;i<4;i++) 
				{
					up_spot[i] = 0;
				}
				score = score + sqr_score_filled;
				calcul_score();
			}

			reset_case();
		}

		else if (BUTTON.DOWN || touch_sqr(100, 212, 292, 391))
		{

			for(i=0;i<4;i++)
			{
				if ((square.position == 1+i || square.position == 5+i || square.position == 9+i || square.position == 13+i))
				{
					if (down_spot[i] == 0)
					{
						Play_SFX(4);
						if (start_beginning > 0) start_beginning--;
						down_spot[i] = square.position;
					}
					else if (down_spot[i] > 0)
					{
						lose_a_life();
					}
				}	
			}
			
			if (down_spot[0] > 0 && down_spot[1] > 0 && down_spot[2] > 0 && down_spot[3] > 0)
			{
				sqr_score_filled = check_square_score(down_spot);
				for(i=0;i<4;i++) 
				{
					down_spot[i] = 0;
				}
				score = score + sqr_score_filled;
				calcul_score();
			}

			reset_case();
		}
	
		else if (BUTTON.LEFT || touch_sqr(4, 98, 193, 286))
		{
			
			for(i=0;i<4;i++)
			{
				if ((square.position == 1+i || square.position == 5+i || square.position == 9+i || square.position == 13+i))
				{
					if (left_spot[i] == 0)
					{
						Play_SFX(5);
						if (start_beginning > 0) start_beginning--;
						left_spot[i] = square.position;
					}
					else if (left_spot[i] > 0)
					{
						lose_a_life();
					}
				}	
			}

			if (left_spot[0] > 0 && left_spot[1] > 0 && left_spot[2] > 0 && left_spot[3] > 0)
			{
				sqr_score_filled = check_square_score(left_spot);
				for(i=0;i<4;i++) 
				{
					left_spot[i] = 0;
				}
				score = score + sqr_score_filled;
				calcul_score();
			}

			reset_case();
		}

		else if (BUTTON.RIGHT  || touch_sqr(212, 317, 185, 286))
		{
			
				for(i=0;i<4;i++)
				{
					if ((square.position == 1+i || square.position == 5+i || square.position == 9+i || square.position == 13+i))
					{
						if (right_spot[i] == 0)
						{
							Play_SFX(6);
							if (start_beginning > 0) start_beginning--;
							right_spot[i] = square.position;
						}
						else if (right_spot[i] > 0)
						{
							lose_a_life();
						}
					}	
				}
			
				if (right_spot[0] > 0 && right_spot[1] > 0 && right_spot[2] > 0 && right_spot[3] > 0)
				{
					sqr_score_filled = check_square_score(right_spot);
					for(i=0;i<4;i++) 
					{
						right_spot[i] = 0;
					}
					score = score + sqr_score_filled;
					calcul_score();
				}

			reset_case();
		}
	}

}

// Generate a random number
short reset_case() 
{
	unsigned char good, i;

	good = 0;

	// Avoid to give a square where it can't be placed anywhere
	// Loop until the game finds a good combinaison
	// In theory, the game could loop indefinitely but it never happened to me
	// If good = 1 then it means it found a good combinaison
	while (!good)
	{
		square.position = rand_a_b(1,12);
		
		if (up_spot[0] > 0 && right_spot[0] > 0 && left_spot[0] > 0 && down_spot[0] && (square.position == 1 || square.position == 5 || square.position == 9 || square.position == 13)) 
		{
			good = 0;
		}
		else if (up_spot[1] > 0 && right_spot[1] > 0 && left_spot[1] > 0 && down_spot[1] && (square.position == 2 || square.position == 6 || square.position == 10 || square.position == 14)) 
		{
			good = 0;
		}
		else if (up_spot[2] > 0 && right_spot[2] > 0 && left_spot[2] > 0 && down_spot[2] && (square.position == 3 || square.position == 7 || square.position == 11 || square.position == 15)) 
		{
			good = 0;
		}
		else if (up_spot[3] > 0 && right_spot[3] > 0 && left_spot[3] > 0 && down_spot[3] && (square.position == 4 || square.position == 8 || square.position == 12 || square.position == 16)) 
		{
			good = 0;
		}
		else
		{
			good = 1;
		}
	}
	
	for(i=0;i<4;i++)
	{
		if (square.position == 1+(4*i)) Play_SFX(8);
		if (square.position == 5+(4*i)) Play_SFX(9);
		if (square.position == 9+(4*i)) Play_SFX(10);
		if (square.position == 13+(4*i)) Play_SFX(11);
	}
	

	time_game = 100;
	frame_gamemo = 0;

	return 1;
}

void lose_a_life()
{
	lives = lives - 1;

	if (lives < 1)
	{
		Play_SFX(1);
		game_status = 2;
	}
	else
	{
		Play_SFX(2);
		game_status = 1;
	}
}

void calcul_score()
{
	score_showed[0] = (score / 1000000) % 10;
	score_showed[1] = (score / 100000) % 10;
	score_showed[2] = (score / 10000) % 10;
	score_showed[3] = (score / 1000) % 10;
	score_showed[4] = (score / 100) % 10;
	score_showed[5] = (score / 10) % 10;
	score_showed[6] = score % 10;
}

short rand_a_b(short a, short b)
{
    return rand()%(b-a) +a;
}


/*
 * 
 * Functions to change game_mode value
 * and switch between in-game and titlescreen;
 * 
*/

void go_back_titlescreen()
{
	Clear_screen();
	Load_Image(1,title_img,0);
	
	Update_highscore();
	Load_score();

	game_mode = TITLESCREEN;
}

void go_ingame()
{
	Clear_screen();
	RESET_EVERYTHING();

	Load_Image(1,background_img,0);

	time_game = 100;

	game_mode = INSTRUCTIONS_INGAME;
}


/* Set all the values to their default */
void RESET_EVERYTHING()
{
	unsigned char i;
	
	time_game = 0;
	game_status = 0;
	frame_gamemo = 0;
	score = 0;
	
	lives = 3;
	
	for (i=0;i<4;i++)
	{
		right_spot[i] = 0;
		left_spot[i] = 0;
		up_spot[i] = 0;
		down_spot[i] = 0;
	}
	
	for (i=0;i<7;i++)
	{
		score_showed[i] = 0;
	}
	
	hand_inst.anim = 0;
	hand_inst.time = 0;
	
	lvl_struct.level = 0;	
	lvl_struct.exp = 0;	
	lvl_struct.latency_time = 0;
	lvl_struct.latency = 2;
	
	inst_scr.alpha = 255;
	
	if (highscore > 100)
	{
		inst_scr.time = 60*6;
	}
	else
	{
		inst_scr.time = 260;
	}
	
	square.chain = 0;
	go_time = 0;
	
	black_transition_alpha = 0;
	start_beginning = 1;
}


/*
 * Load all sound effects at once in the game
*/

void Load_Sounds()
{
	Init_sound();

	Load_SFX(1, gameover_sfx);
	Load_SFX(2, miss_sfx);
	Load_SFX(3, move_sfx);
	Load_SFX(4, move2_sfx);
	Load_SFX(5, move3_sfx);
	Load_SFX(6, move4_sfx);
	Load_SFX(7, fullsqr_sfx);
	
	Load_SFX(8, "upleft.wav");
	Load_SFX(9, "upright.wav");
	Load_SFX(10, "downleft.wav");
	Load_SFX(11, "downright.wav");
}

/*
 * 
 * Loading/Saving score stuff
 * 
*/


void Load_score()
{
	FILE* file;
	char directory[256];
	unsigned char i;
		
	#if defined(ANDROID)
	snprintf(directory, sizeof(directory), "%s/killminds.save", SDL_AndroidGetInternalStoragePath());
	#elif defined(HOMEDIR)
	char letsgohomedir[256];
	snprintf(letsgohomedir, sizeof(letsgohomedir), "%s/.config/harbour-killminds", getenv("HOME"));
	mkdir(letsgohomedir, 0755);
	snprintf(directory, sizeof(directory), "%s/killminds.save", letsgohomedir);
	#else
	snprintf(directory, sizeof(directory), "killminds.save");
	#endif
		
	file = fopen(directory, "r+");
		
	if (file != NULL)
	{
		for(i=0;i<sizeof(highscore_show);i++)
		{
			highscore_show[i] = fgetc(file);
			/* If the file is somehow corrupted, set highscore to 0 */
			if (highscore_show[i] < 0 || highscore_show[i] > 9) highscore_show[i] = 0;
		}
	}
	else
	{
		// If the file does not exist then create it
		file = fopen(directory, "w");
	}
	
	highscore = (highscore_show[0] *  1000000);
	highscore += (highscore_show[1] * 100000);
	highscore += (highscore_show[2] * 10000);
	highscore += (highscore_show[3] * 1000);
	highscore += (highscore_show[4] * 100);
	highscore += (highscore_show[5] * 10);
	highscore += (highscore_show[6]);
	
	if (file) fclose(file);	
}

void Save_score()
{
	FILE* file;
	char directory[256];
	unsigned char i;
		
	#if defined(ANDROID)
	snprintf(directory, sizeof(directory), "%s/killminds.save", SDL_AndroidGetInternalStoragePath());
	#elif defined(HOMEDIR)
	char letsgohomedir[256];
	snprintf(letsgohomedir, sizeof(letsgohomedir), "%s/.config/harbour-killminds", getenv("HOME"));
	mkdir(letsgohomedir, 0755);
	snprintf(directory, sizeof(directory), "%s/killminds.save", letsgohomedir);
	#else
	snprintf(directory, sizeof(directory), "killminds.save");
	#endif
		
	highscore_show[0] = (highscore / 1000000) % 10;
	highscore_show[1] = (highscore / 100000) % 10;
	highscore_show[2] = (highscore / 10000) % 10;
	highscore_show[3] = (highscore / 1000) % 10;
	highscore_show[4] = (highscore / 100) % 10;
	highscore_show[5] = (highscore / 10) % 10;
	highscore_show[6] = highscore % 10;
		
	file = fopen(directory, "w+");
	
	for(i=0;i<7;i++)
	{
		fputc( highscore_show[i], file );
	}

	if (file) fclose(file);
}

void Update_highscore()
{
	if (score > highscore)
	{
		highscore = score;
			
		highscore_show[0] = (highscore / 1000000) % 10;
		highscore_show[1] = (highscore / 100000) % 10;
		highscore_show[2] = (highscore / 10000) % 10;
		highscore_show[3] = (highscore / 1000) % 10;
		highscore_show[4] = (highscore / 100) % 10;
		highscore_show[5] = (highscore / 10) % 10;
		highscore_show[6] = highscore % 10;
		Save_score();
	}
}
