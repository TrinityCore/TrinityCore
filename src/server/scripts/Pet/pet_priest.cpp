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
#include "Creature.h"
#include "PassiveAI.h"
#include "PetAI.h"
#include "TemporarySummon.h"

enum PriestSpells
{
    SPELL_PRIEST_GLYPH_OF_SHADOWFIEND       = 58228,
    SPELL_PRIEST_SHADOWFIEND_DEATH          = 57989,
    SPELL_PRIEST_LIGHTWELL_CHARGES          = 59907,
    SPELL_PRIEST_INVOKE_THE_NAARU           = 196687,
    SPELL_PRIEST_DIVINE_IMAGE_SPELL_CHECK   = 405216
};

// 189820 - Lightwell
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

// 19668 - Shadowfiend
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

// 198236 - Divine Image
struct npc_pet_pri_divine_image : public PassiveAI
{
    npc_pet_pri_divine_image(Creature* creature) : PassiveAI(creature) { }

    void IsSummonedBy(WorldObject* summoner) override
    {
        me->CastSpell(me, SPELL_PRIEST_INVOKE_THE_NAARU);
        if (me->ToTempSummon()->IsGuardian() && summoner->IsUnit())
            static_cast<Guardian*>(me)->SetBonusDamage(summoner->ToUnit()->SpellBaseHealingBonusDone(SPELL_SCHOOL_MASK_HOLY));
    }

    void OnDespawn() override
    {
        if (Unit* owner = me->GetOwner())
            owner->RemoveAura(SPELL_PRIEST_DIVINE_IMAGE_SPELL_CHECK);
    }
};

void AddSC_priest_pet_scripts()
{
    RegisterCreatureAI(npc_pet_pri_lightwell);
    RegisterCreatureAI(npc_pet_pri_shadowfiend);
    RegisterCreatureAI(npc_pet_pri_divine_image);
}
