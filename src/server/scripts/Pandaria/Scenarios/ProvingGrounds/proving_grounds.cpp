///*
//* Copyright 2023 AzgathCore
//*
//* This program is free software; you can redistribute it and/or modify it
//* under the terms of the GNU General Public License as published by the
//* Free Software Foundation; either version 2 of the License, or (at your
//* option) any later version.
//*
//* This program is distributed in the hope that it will be useful, but WITHOUT
//* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//* more details.
//*
//* You should have received a copy of the GNU General Public License along
//* with this program. If not, see <http://www.gnu.org/licenses/>.
//*/
//
//#include "proving_grounds.h"
//#include "ScriptedCreature.h"
//#include "ScriptMgr.h"
//#include "ScriptedGossip.h"
//#include "ScriptedEscortAI.h"
//#include "CreatureAI.h"
//#include "MoveSplineInit.h"
//#include "SpellScript.h"
//#include "Vehicle.h"
//#include "ScenarioMgr.h"
//#include "LFGMgr.h"
//
//enum Spells
//{
//    SPELL_DEFEND = 142174,
//    SPELL_AMBER_GLOBULE_LINK = 142190,
//    SPELL_AMBER_GLOBULE = 142189,
//    SPELL_AMBER_GLOBULE_DETONATION = 142191,
//    SPELL_AMBER_GLOBULE_VISUAL = 147287,
//    SPELL_AMBER_GLOBULE_AT = 147292,
//    SPELL_HEAL_ILLUSION = 142238,
//    SPELL_BANANASTORM = 142639,
//    SPELL_BANANASTORM_SELECTOR = 142627,
//    SPELL_BANANASTORM_MISSLE = 142628,
//    SPELL_BANANASTORM_EFF = 142629,
//    SPELL_TIMER_10 = 141577,
//    SPELL_TIMER_15 = 141557,
//    SPELL_TIMER_18 = 141579,
//    SPELL_TIMER_20 = 141580,
//    SPELL_TIMER_25 = 141581,
//    SPELL_TIMER_30 = 141582,
//    SPELL_TIMER_35 = 141583,
//    SPELL_TIMER_40 = 141584,
//    SPELL_EXPOSED = 142489,
//    SPELL_PROTECTION_SHIELD = 142427,
//
//    // Tank Trial
//    SPELL_CHOMP = 144113,
//    SPELL_FOCUSED_CHI_BURST = 144103,
//    SPELL_CRACKLING_JADE_THUNDER = 144076,
//    SPELL_RENEWING_MIST = 144080,
//    SPELL_PYROBLAST = 147601,
//    SPELL_INVOKE_LAVA = 144374,
//    SPELL_INVOKE_LAVA_MISSLE = 144376,
//    SPELL_INVOKE_LAVA_AT = 144377,
//    SPELL_INVOKE_LAVA_EFF = 144383,
//    SPELL_WING_BLAST = 144106,
//    SPELL_FAN_OF_BANANAS = 144398,
//    SPELL_ENRAGE = 144404,
//    SPELL_POWERFUL_SLAM = 144401,
//
//    // Healer Trial
//    SPELL_SHIELD_WALL = 145057,
//    SPELL_DEFENSIVE_STANCE = 145044,
//    SPELL_SHIELD_BLOCK = 145054,
//    SPELL_DEVASTATE = 145060,
//    SPELL_TAUNT = 145058,
//    SPELL_CHARGE_S = 145048,
//    SPELL_THUNDER_CLAP = 145046,
//    SPELL_SKULL_BASH = 142657, // not sure
//    SPELL_SHOCKWAVE = 145047,
//    SPELL_ENVENOM = 145416,
//    SPELL_MUTILATE_OFFH = 145413,
//    SPELL_MUTILATE = 145414,
//    SPELL_RUPTURE = 145417,
//    SPELL_KICK = 145427,
//    SPELL_FAN_OF_KNIVES = 145422,
//    SPELL_SLICE_AND_DICE = 145418,
//    SPELL_DEADLY_POISON = 145421,
//    SPELL_STEALTH = 145423,
//    SPELL_CHEAP_SHOT = 145424,
//    SPELL_ARCANE_MISSLES = 145436,
//    SPELL_ARCANE_BLAST = 145434,
//    SPELL_ARCANE_BARRAGE = 145437,
//    SPELL_COUNTERSPELL = 145530,
//    SPELL_TIME_WARP = 145534,
//    SPELL_COBRA_SHOT = 145654,
//    SPELL_EXPLOSIVE_SHOT = 145661,
//    SPELL_MULTI_SHOT = 145667,
//    SPELL_FEIGN_DEATH = 145666,
//    SPELL_SERPENT_STRING = 145656,
//    SPELL_AUTO_SHOT = 145759,
//    SPELL_COUNTER_SHOT = 147362,
//    SPELL_CALL_SPEEDY = 145412, // hunter turtle
//
//    // Creatures from Healer Trial
//    SPELL_SONIC_BLAST = 145200,
//    SPELL_AQUA_BOMB = 145206,
//    SPELL_AQUA_BOMB_EFF = 145208,
//    SPELL_CHOMP_H = 145263,
//    SPELL_BURROW = 145260,
//    SPELL_ENRAGE_H = 145411,
//
//    // Misc
//    SPELL_BERSERKING_AT = 147294,
//    SPELL_BERSERKING_EFF = 147293,
//};
//
//std::map<uint32, uint32> interruptType =
//{
//    { NPC_OTO_THE_PROTECTOR,     SPELL_SKULL_BASH   },
//    { NPC_SOOLI_THE_SURVIVALIST, SPELL_COUNTER_SHOT },
//    { NPC_KAVAN_THE_ARCANIST,    SPELL_COUNTERSPELL },
//    { NPC_KI_THE_ASSASSIN,       SPELL_KICK         },
//};
//
//void AddSC_proving_grounds()
//{
//    
//}
