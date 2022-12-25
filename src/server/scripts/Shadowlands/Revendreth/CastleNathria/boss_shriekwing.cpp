/*
* Copyright (C) 2021 AzgathCore
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

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuraEffects.h"
#include "castle_nathria.h"

enum Shriekwing
{
    SPELL_BLOOD_SHROUD_CAST = 343995,
    SPELL_SANGUINE_ICHOR_CREATE_AT = 340299,//21611
    EVENT_GAIN_ENERGY = 1,
    SPELL_EARSPITTING_SHRIEK_CAST = 330711,
    SPELL_EARSPITTING_SHRIEK_PERIODIC = 330713,
    SPELL_SANGUINE_ICHOR_AT_DAMAGE = 340324,
    SPELL_ECHOLOCATION_MARK = 342077,
    SPELL_DESCENT = 342923,
    SPELL_DEADLY_DESCENT = 343021,
    SPELL_EXSANGUINATING_BITE = 328857,
    SPELL_EXSANGUINATED_DEBUFF = 328897,
    SPELL_BLIND_SWIPE_CAST = 343005,
    SPELL_WAVE_OF_BLOOD = 345397,
    SPELL_ECHOING_SONAR_CAST = 329362,
    SPELL_ECHOING_SONAR_CREATE_AT = 329002,
    SPELL_ECHOING_SONAR_DAMAGE = 343022,
    EVENT_PHASE_ONE = 2,
    SPELL_BERSERK = 343364,
    SPELL_HORRIFIED = 343024,
    //Heroic
    SPELL_ECHOING_SCREECH_CAST = 342864,
    SPELL_ECHOING_SCREECH_CREATE_AT = 342865, //21833
    //Mythic
    SPELL_BLOOD_LANTER_APPLY_AT = 344124, //21734
    SPELL_BLOOD_LANTERN_GRANT_BUTTON = 341684,
    SPELL_BLOOD_LANTERN_STUN = 341490,
    SPELL_BLOOD_LANTER_APPLY_AT_2 = 341690, //21754
    SPELL_BLODLIGHT_APPLY_AT = 343303, //21961
    SPELL_BLOODLIGHT_PERIODIC_DUMMY = 341489,
    SPELL_RAVENOUS_HORROR_MISSILE = 344762,
    EVENT_ECHOING_SONAR_SPAWN = 3,
    EVENT_ECHOING_SCREECH_SPAWN = 4,
    SPELL_BLOODLIGHT_PERIODIC_DAMAGE_TRIGGER = 344235,
};

const Position middle_pos = { -1864.986f, 6779.375f, 4319.209f };
const Position echoingSonarSpawnPos = { -1864.157f, 6790.122f, 4319.208f };
const Position echoingSonarSpawnPos2 = { -1864.138f, 6759.732f, 4319.208f };

void AddSC_boss_shriekwing()
{
  
}
