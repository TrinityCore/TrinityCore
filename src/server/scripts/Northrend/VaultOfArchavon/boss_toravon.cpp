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

enum Spells
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

    // Frost Warder
    SPELL_FROST_BLAST       = 72123,    // don't know cd... using 20 secs.
    SPELL_FROZEN_MALLET_2   = 72122
};

enum Events
{
    EVENT_FREEZING_GROUND   = 1,
    EVENT_FROZEN_ORB        = 2,
    EVENT_WHITEOUT          = 3,

    EVENT_FROST_BLAST       = 4
};

struct boss_toravon : public BossAI
{
    boss_toravon(Creature* creature) : BossAI(creature, DATA_TORAVON) { }

    void EnterCombat(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_FROZEN_MALLET);

        events.ScheduleEvent(EVENT_FROZEN_ORB, Seconds(12));
        events.ScheduleEvent(EVENT_WHITEOUT, Seconds(25));
        events.ScheduleEvent(EVENT_FREEZING_GROUND, Seconds(7));

        _EnterCombat();
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
                    me->CastCustomSpell(SPELL_FROZEN_ORB, SPELLVALUE_MAX_TARGETS, RAID_MODE(1, 3), me);
                    events.Repeat(Seconds(32));
                    break;
                case EVENT_WHITEOUT:
                    DoCastSelf(SPELL_WHITEOUT);
                    events.Repeat(Seconds(38));
                    break;
                case EVENT_FREEZING_GROUND:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        DoCast(target, SPELL_FREEZING_GROUND);
                    events.Repeat(Seconds(38));
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

struct npc_frost_warder : public ScriptedAI
{
    npc_frost_warder(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        DoZoneInCombat();

        DoCastSelf(SPELL_FROZEN_MALLET_2);

        _events.ScheduleEvent(EVENT_FROST_BLAST, 5000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (_events.ExecuteEvent() == EVENT_FROST_BLAST)
        {
            DoCastVictim(SPELL_FROST_BLAST);
            _events.ScheduleEvent(EVENT_FROST_BLAST, 20000);
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

struct npc_frozen_orb : public ScriptedAI
{
    npc_frozen_orb(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCastSelf(SPELL_FROZEN_ORB_AURA, true);
        DoCastSelf(SPELL_FROZEN_ORB_DMG, true);
        DoCastSelf(SPELL_RANDOM_AGGRO, true);

        if (Creature* toravon = me->GetInstanceScript()->GetCreature(DATA_TORAVON))
        {
            if (toravon->IsInCombat())
            {
                toravon->AI()->JustSummoned(me);
                me->SetInCombatWithZone();
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
        if (!caster->IsAIEnabled)
            return;

        caster->GetThreatManager().resetAllAggro();

        if (Unit* target = caster->AI()->SelectTarget(SELECT_TARGET_RANDOM, 1))
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
    RegisterVaultOfArchavonCreatureAI(npc_frost_warder);
    RegisterVaultOfArchavonCreatureAI(npc_frozen_orb);
    RegisterSpellScript(spell_toravon_random_aggro);
}
