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
#include "TemporarySummon.h"
#include "uldir.h"

enum Spells
{
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_TERRIBLE_THRASH_DAMAGE = 262277,
    SPELL_ROTTING_REGURGITATION = 262292,
    SPELL_SHOCKWAVE_STOMP = 262288,
    SPELL_MALODOROUS_MIASMA_AURA = 262313,
    SPELL_FETID_FRENZY = 262378,
    SPELL_CONSUME_CORRUPTION = 262370,
    SPELL_ENTICING_ESSENCE = 262364,
    SPELL_TRASH_CHUTE_AT = 274470,
    SPELL_PUTRID_PAROXYSM = 262314,
    SPELL_BERSERK = 26662,
};

enum Events
{
    EVENT_TERRIBLE_THRASH = 1,
    EVENT_MALODOROUS_MIASMA,
    EVENT_WASTE_DISPOSAL_UNITS,
    EVENT_ROTTING_REGURGITATION,
    EVENT_SHOCKWAVE_STOMP,
    EVENT_GET_CORRUPTION,
    EVENT_BERSERK
};

enum Texts
{
    SAY_ROTTING_REGURGITATION,
    SAY_WASTE_DISPOSAL_UNITS,
};

enum Actions
{
    ACTION_GET_CORRUPTION = 1,
};

const Position corruption_corpuscle_spawn_pos = { 290.625f, -622.588f, 694.882f, 3.13f };
const Position corruption_corpuscle_spawn_pos2 = { 216.449f, -623.721f, 694.882f, 3.13f };
const Position corruption_corpuscle_spawn_pos3 = { 234.059f, -719.541f, 694.882f, 3.13f };
const Position corruption_corpuscle_spawn_pos4 = { 278.369f, -719.677f, 694.799f, 2.917f };

//133492
struct npc_corruption_corpuscle : public ScriptedAI
{
    npc_corruption_corpuscle(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }
};

void AddSC_boss_fetid_devourer()
{
    RegisterCreatureAI(npc_corruption_corpuscle);
}
