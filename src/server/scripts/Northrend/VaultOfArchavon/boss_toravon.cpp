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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "vault_of_archavon.h"

enum ToravonSpells
{
    // Toravon
    SPELL_FREEZING_GROUND   = 72090,
    SPELL_FROZEN_ORB        = 72091,
    SPELL_WHITEOUT          = 72034,
    SPELL_FROZEN_MALLET     = 71993,

    // Frozen Orb
    SPELL_FROZEN_ORB_DMG    = 72081,
    SPELL_FROZEN_ORB_AURA   = 72067,
    SPELL_RANDOM_AGGRO      = 72084,

    // Frozen Orb Stalker
    FROZEN_ORB_STALKER_AURA = 72094
};

enum ToravonEvents
{
    EVENT_FREEZING_GROUND = 1,
    EVENT_FROZEN_ORB,
    EVENT_WHITEOUT
};

struct boss_toravon : public BossAI
{
    boss_toravon(Creature* creature) : BossAI(creature, DATA_TORAVON) { }

    void JustEngagedWith(Unit* who) override
    {
        DoCastSelf(SPELL_FROZEN_MALLET);

        events.ScheduleEvent(EVENT_FROZEN_ORB, 12s);
        events.ScheduleEvent(EVENT_WHITEOUT, 25s);
        events.ScheduleEvent(EVENT_FREEZING_GROUND, 7s);

        BossAI::JustEngagedWith(who);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FROZEN_ORB:
                {
                    me->CastSpell(me, SPELL_FROZEN_ORB, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, RAID_MODE(1, 3)));
                    events.Repeat(32s);
                    break;
                }
                case EVENT_WHITEOUT:
                    DoCastSelf(SPELL_WHITEOUT);
                    events.Repeat(38s);
                    break;
                case EVENT_FREEZING_GROUND:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1))
                        DoCast(target, SPELL_FREEZING_GROUND);
                    events.Repeat(38s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_frozen_orb_stalker : public ScriptedAI
{
    npc_frozen_orb_stalker(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        DoCastSelf(FROZEN_ORB_STALKER_AURA);
    }
};

struct npc_frozen_orb : public ScriptedAI
{
    npc_frozen_orb(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        DoCastSelf(SPELL_FROZEN_ORB_AURA, true);
        DoCastSelf(SPELL_FROZEN_ORB_DMG, true);
        DoCastSelf(SPELL_RANDOM_AGGRO, true);

        if (Creature* toravon = me->GetInstanceScript()->GetCreature(DATA_TORAVON))
        {
            if (toravon->IsInCombat())
            {
                toravon->AI()->JustSummoned(me);
                DoZoneInCombat();
            }
            else
                me->DespawnOrUnsummon();
        }
    }
};

// 46523 - Random Aggro
class spell_toravon_random_aggro : public SpellScript
{
    PrepareSpellScript(spell_toravon_random_aggro);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster()->ToCreature();

        caster->GetThreatManager().ResetAllThreat();

        if (CreatureAI* ai = caster->AI())
            if (Unit* target = ai->SelectTarget(SelectTargetMethod::Random, 1))
                caster->GetThreatManager().AddThreat(target, 1000000);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_toravon_random_aggro::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_toravon()
{
    RegisterVaultOfArchavonCreatureAI(boss_toravon);
    RegisterVaultOfArchavonCreatureAI(npc_frozen_orb_stalker);
    RegisterVaultOfArchavonCreatureAI(npc_frozen_orb);
    RegisterSpellScript(spell_toravon_random_aggro);
}
