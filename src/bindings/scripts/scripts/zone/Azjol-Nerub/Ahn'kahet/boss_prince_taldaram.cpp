/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: boss_prince_taldaram
SD%Complete: 0
SDComment: Placeholder
SDCategory: Ahn'kahet
EndScriptData */

#include "precompiled.h"
#include "def_ahnkahet.h"

#define SPELL_BLOODTHIRST                   55968 //Trigger Spell + add aura
#define SPELL_CONJURE_FLAME_SPHERE          55931

#define SPELL_FLAME_SPHERE_SUMMON_1         55895// 1x 30106
#define H_SPELL_FLAME_SPHERE_SUMMON_1       59511// 1x 31686
#define H_SPELL_FLAME_SPHERE_SUMMON_2       59512// 1x 31687
#define SPELL_FLAME_SPHERE_SPAWN_EFFEKT     55891
#define SPELL_FLAME_SPHERE_VISUAL           55928
#define SPELL_FLAME_SPHERE_PERIODIC         55926
#define H_SPELL_FLAME_SPHERE_PERIODIC       59508
#define SPELL_FLAME_SPHERE_DEATH_EFFEKT     55947

#define SPELL_EMBRACE_OF_THE_VAMPYR         55959
#define H_SPELL_EMBRACE_OF_THE_VAMPYR       59513

#define SPELL_VANISH                        55964
