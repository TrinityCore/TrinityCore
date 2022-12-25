/*
 * Copyright 2023 AzgathCore
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
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "uldir.h"

enum Spells
{
    SPELL_OMEGA_VECTOR_CLOSEST_TARGET_SELECTOR = 277764,
    SPELL_OMEGA_VECTOR_TARGET_SELECTOR = 276439,
    SPELL_OMEGA_VECTOR_JUMP = 265140,
    SPELL_OMEGA_VECTOR_DAMAGE = 265143,
    SPELL_ENERGY_FILL = 265249,
    SPELL_LINGERING_INFECTION = 281080,
    SPELL_LINGERING_INFECTION_AURA = 265127,
    SPELL_EVOLVING_AFFLICTION = 265178,
    SPELL_CONTAGION = 267242,
    SPELL_GESTATE_TARGET_SELECTOR = 265208,
    SPELL_GESTATE = 265209,
    SPELL_GESTATE_SUMMON = 265215,
    SPELL_GESTATE_DAMAGE = 266077,
    SPELL_LIQUEFY = 265217,
    SPELL_LIQUEFY_CANCEL_COSMETIC = 265291,
    SPELL_BLOOD_GEYSER_TARGET_SELECTOR = 265928,
    SPELL_BLOOD_GEYSER_CREATE_AT = 277438,
    SPELL_BLOOD_GEYSER_DAMAGE = 265370,
    SPELL_BLOOD_GEYSER_CAST = 265281,
    SPELL_PLAGUE_BOMB_CAST = 266459,
    SPELL_PLAGUE_BOMB = 266926,
    SPELL_PLAGUE_BOMB_SUMMON_AMALGAM = 266953,
    SPELL_PLAGUE_BOMB_MISSILE_SUMMON = 277542,
    SPELL_PLAGUE_BOMB_AT = 267648,
    SPELL_BURSTING_LESIONS = 274990,
    SPELL_SPAWN_PARASITE = 275053,
    SPELL_TERMINAL_ERUPTION = 274989,
    SPELL_IMMUNOSUPPRESSION = 265206,
    SPELL_PATHOGEN_BOMB_VISUAL = 269676,
    SPELL_CAUSTIC_BITE = 275170,
    SPELL_PARASITIC_DISCHARGE = 276276,
    SPELL_LIQUEFY_CHANGE_MODEL = 277765,
};

enum Texts
{
    SAY_AGGRO,
    SAY_OMEGA_VECTOR,
    SAY_GESTATE,
    SAY_LIQUEFY,
    SAY_DEATH,
};

enum Events
{
    EVENT_GESTATE = 1,
    EVENT_CONTAGION,
    EVENT_EVOLVING_AFFLICTION,
    EVENT_LIQUEFY,
    EVENT_BLOOD_GEYSER,
    EVENT_PLAGUE_BOMB,
    EVENT_CHANGE_PHASE,
    EVENT_IMMUNOSUPPRESSION,
};

const int OmegaVectorAuras[4] =
{
    267160,267161, 267162, 267163
};

const Position VectisLiquefyPos[4] =
{
{ 710.08f, -239.776f, 694.698f, 3.85f },
{ 705.77f, -271.224f, 694.698f, 2.73f },
{ 619.86f, -226.085f, 694.698f, 5.43f },
{ 621.06f, -283.571f, 694.698f, 0.73f },
};

const Position PlagueBombPos[12] =
{
{ 640.71f, -264.544f, 694.698f, 3.85f },
{ 629.74f, -264.857f, 694.698f, 2.73f },
{ 618.33f, -264.711f, 694.698f, 5.43f },
{ 678.93f, -264.877f, 694.698f, 0.73f },
{ 688.71f, -264.808f, 694.698f, 3.85f },
{ 698.46f, -264.965f, 694.698f, 2.73f },
{ 698.86f, -256.172f, 694.698f, 5.43f },
{ 689.23f, -256.232f, 694.698f, 0.73f },
{ 679.75f, -256.292f, 694.698f, 3.85f },
{ 668.16f, -256.365f, 694.698f, 2.73f },
{ 629.98f, -247.196f, 694.698f, 5.43f },
{ 618.10f, -247.182f, 694.698f, 0.73f },
};

enum Misc
{
    ACHIEVEMENT_VECTIS_MYTHIC = 12529,
};

void AddSC_boss_vectis()
{
   
}
