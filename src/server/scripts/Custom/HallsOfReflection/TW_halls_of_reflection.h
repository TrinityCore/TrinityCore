/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEF_HALLS_OF_REFLECTION_H
#define DEF_HALLS_OF_REFLECTION_H

enum Data
{
    DATA_FALRIC_EVENT,
    DATA_MARWYN_EVENT,
    DATA_LICHKING_EVENT,
    DATA_WAVE_COUNT,
    DATA_WAVE_CHECK,
    DATA_TEAM_IN_INSTANCE,
    DATA_GENERAL_EVENT,
    DATA_LK_SEND_WAVE,
};

enum Data64
{
    DATA_FALRIC,
    DATA_MARWYN,
    DATA_LICHKING,
    DATA_FROSTMOURNE,
    DATA_SYLVANAS2
};

enum Creatures
{
    NPC_FALRIC                                    = 38112,
    NPC_MARWYN                                    = 38113,
    NPC_LICH_KING_EVENT                           = 37226,
    NPC_LICH_KING_BOSS                            = 36954,
    NPC_GENERAL					  = 36723,

    NPC_UTHER                                     = 37225,
    NPC_JAINA_PART1                               = 37221,
    NPC_JAINA_PART2                               = 36955,
    NPC_SYLVANAS_PART1                            = 37223,
    NPC_SYLVANAS_PART2                            = 37554,

    NPC_WAVE_MERCENARY                            = 38177,
    NPC_WAVE_FOOTMAN                              = 38173,
    NPC_WAVE_RIFLEMAN                             = 38176,
    NPC_WAVE_PRIEST                               = 38175,
    NPC_WAVE_MAGE                                 = 38172,
};

enum GameObjects
{
    GO_FROSTMOURNE                                = 202302,
    GO_FROSTMOURNE_ALTAR                          = 202236,
    GO_FRONT_DOOR                                 = 201976,
    GO_ARTHAS_DOOR                                = 197341,
    GO_CHEST_A_1				  = 201710,
    GO_CHEST_H_1				  = 202212,
    GO_CHEST_A_2				  = 202336,
    GO_CHEST_H_2				  = 202337,
};

enum HorWorldStates
{
    WORLD_STATE_HOR                               = 4884,
    WORLD_STATE_HOR_WAVE_COUNT                    = 4882,
};

// Common actions from Instance Script to Boss Script
enum Actions
{
    ACTION_ENTER_COMBAT,
};

enum InstanceState{
	ISTATE_BEGIN,
	ISTATE_FALRIC_TRASH,
	ISTATE_FALRIC,
	ISTATE_MARWYN_TRASH,
	ISTATE_MARWYN,
	ISTATE_GENERAL,
	ISTATE_LICHKING,
	ISTATE_DONE
};

///TEMP
#define GO_ICE_WALL			201385

#define WP_SYL_0			5604.52f,	2204.57f,	731.36f
#define WP_SYL_1			5551.98f,	2100.76f,	731.13f
#define WP_SYL_2			5500.98f,	1986.35f,	736.09f
#define WP_SYL_3			5385.53f,	1814.35f,	759.87f
#define WP_SYL_4			5290.84f,	1713.62f,	781.08f
#define WP_SYL_5			5248.43f,	1660.40f,	784.51f

#define NPC_LICHKING2			37226
#define LK_SPAWN_LICHKING_POS		5547.17f,	2266.07f,	733.02f,		5.575f
#define NPC_SYLVANAS2_A			36955
#define NPC_SYLVANAS2_H			37554
#define NPC_SYLVANAS2			uiTeamInInstance==ALLIANCE?NPC_SYLVANAS2_A:NPC_SYLVANAS2_H
#define LK_SPAWN_SYLVANAS_POS		5556.91f,	2257.73f,	733.02f,		2.772f

#define NPC_GHOUL			36940
#define NPC_DOCTOR			36941
#define NPC_ABOMINATION			37069

#define DATA_LK_SEND_WAVE		400
#define DATA_LK_ADD_MOB			401
#define DATA_LK_DEL_MOB			402

#define NPC_SPIRITUAL_REFLECTION	37068


///Dummy AI for LK trash

struct TW_mob_hor_lk_dummyAI: public ScriptedAI{
	TW_mob_hor_lk_dummyAI( Creature* pCreature );
	
	InstanceScript *instance;
	bool isHeroic;
	uint32 ACTIVATION_TIMER, activation_timer;
	bool isActivated;
	
	void JustDied( Unit * /*pKiller*/ );
	
	void Activate( uint32 activate_in );
	bool ActivationCheck( const uint32 uiDiff );
	
	void JustReachedHome();
};


#endif
