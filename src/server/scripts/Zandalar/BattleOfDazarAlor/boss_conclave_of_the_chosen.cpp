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

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "battle_of_dazaralor.h"

enum Texts
{
    //Paku
    SAY_PAKU_AGGRO = 0,
    SAY_PAKU_GIFT_OF_WIND,
    SAY_PAKU_DEATH,
    //Gonk
    SAY_GONK_RAPTORM_FORM = 0,
    SAY_GONK_CRAWLING_HEX,
    SAY_GONG_DEATH,
    //Kimbul
    SAY_KIMBUL_LACERATING_CLAWS = 0,
    SAY_KIMBUL_DEATH,
    //Akunda
    SAY_AKUNDA_THUNDERING_STORM = 0,
    SAY_AKUNDA_DEATH,
    //BWONSAMDI
    SAY_BWONSAMDIS_WRATH = 0
};

enum Spells
{
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_LOAS_WRATH = 282736,
    SPELL_LOAS_PACT = 282079,
    SPELL_HASTENING_WIND = 285945,
    SPELL_GIFT_OF_WIND = 282098,
    SPELL_PAKUS_WRATH = 282107,
    SPELL_WILD_MAUL = 285893,
    SPELL_CRAWLING_HEX = 282135,
    SPELL_GONKS_WRATH = 282155,
    SPELL_LACERATING_CLAWS = 282444,
    SPELL_BLEEDING_WOUNDS = 282592,
    SPELL_KIMBULS_WRATH_JUMP = 283508,
    SPELL_THUNDERING_STORM = 282411,
    SPELL_MIND_WIPE_SPAWN_EFFECT = 286708,
    SPELL_MIND_WIPE_PACIFY_SILENCE = 285879,
    SPELL_AKUNDAS_WRATH = 286811,
    SPELL_AKUNDAS_WRAT_EXP = 286821,
    SPELL_STATIC_ORB_CREATE_AT = 286833,
    //Heroic
    SPELL_CRY_OF_THE_FALLEN = 286060,
    SPELL_PACK_HUNTER = 286007,
    SPELL_KRAGWAS_WRATH_MAIN = 282636,
    //Mythic
    SPELL_BWONSAMDIS_WRATH = 284663,
};

enum Events
{
    EVENT_HASTENING_WIND = 1,
    EVENT_GIFT_OF_THE_WIND,
    EVENT_PAKUS_WRATH,

    EVENT_RAPTOR_FORM,
    EVENT_CRAWLING_HEX,
    EVENT_GONKS_WRATH,

    EVENT_LACERATING_CLAWS,
    EVENT_KIMBULS_WRATH,

    EVENT_THUNDERING_STORM,
    EVENT_MIND_WIPE,
    EVENT_AKUNDAS_WRATH,
    //Heroic
    EVENT_CRY_OF_THE_FALLEN,
    EVENT_KRAGWA,
    //Mythic
    EVENT_BWONSAMDIS_WRATH,
};

const Position middle_of_the_room = { -1095.421f, 804.986f, 203.865f, 1.53f };
const Position pakku_pos = { -1078.854f, 766.060f, 204.249f, 1.91f };

void AddSC_boss_conclave_of_the_chosen()
{
   
}