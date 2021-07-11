/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/*
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "npc_pet_pri_".
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "PassiveAI.h"
#include "PetAI.h"

enum PriestSpells
{
    SPELL_PRIEST_GLYPH_OF_SHADOWFIEND       = 58228,
    SPELL_PRIEST_SHADOWFIEND_DEATH          = 57989,
    SPELL_PRIEST_LIGHTWELL_CHARGES          = 59907
};

struct npc_pet_pri_lightwell : public PassiveAI
{
    npc_pet_pri_lightwell(Creature* creature) : PassiveAI(creature)
    {
        DoCast(me, SPELL_PRIEST_LIGHTWELL_CHARGES, false);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (!me->IsAlive())
            return;

        me->CombatStop(true);
        EngagementOver();
        me->ResetPlayerDamageReq();
    }
};

struct npc_pet_pri_shadowfiend : public PetAI
{
    npc_pet_pri_shadowfiend(Creature* creature) : PetAI(creature) { }

    void IsSummonedBy(WorldObject* summonerWO) override
    {
        Unit* summoner = summonerWO->ToUnit();
        if (!summoner)
            return;

        if (summoner->HasAura(SPELL_PRIEST_GLYPH_OF_SHADOWFIEND))
            DoCastAOE(SPELL_PRIEST_SHADOWFIEND_DEATH);
    }
};

void AddSC_priest_pet_scripts()
{
    RegisterCreatureAI(npc_pet_pri_lightwell);
    RegisterCreatureAI(npc_pet_pri_shadowfiend);
}
