/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "black_rook_hold.h"

enum Spells
{
    /// Phase 1

    // Kurtalos
    SPELL_UNERRING_SHEAR            = 198635,
    
    SPELL_WHIRLING_BLADE            = 198641,
    SPELL_WHIRLING_BLADE_DAMAGE     = 198781,
    SPELL_WHIRLING_BLADE_AT         = 198782,
    NPC_WHIRLING_BLADE              = 100861,

    // Latosius
    SPELL_DARK_BLAST                = 198820,
    SPELL_SHADOW_BOLT               = 198833,
    SPELL_TELEPORT_OUT              = 198835,
    SPELL_TELEPORT_IN               = 199058,
    SPELL_SAP_SOUL                  = 198961,
    SPELL_DREADLORD_CONVERSATION    = 199239,
    SPELL_TRANSFORM                 = 199064,

    /// Phase 2 - Dantalionax
    SPELL_LEGACY_OF_THE_RAVENCREST  = 199368,

    SPELL_STINGING_SWARM            = 201733,
    SPELL_CLOUD_OF_HYPNOSIS         = 199092,

    SPELL_ITCHY                     = 199168,
    
    SPELL_DREADLORDS_GUILE          = 199193,
    SPELL_DARK_OBLITERATION         = 199567,

    SPELL_SHADOW_BOLT_VOLLEY        = 202019,
};

// 98965
struct boss_kurtalos_ravencrest : public BossAI
{
    boss_kurtalos_ravencrest(Creature* creature) : BossAI(creature, DATA_LORD_RAVENCREST) { }

    void Reset()
    {
        BossAI::Reset();

        latosiusActionDone = false;
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_UNERRING_SHEAR, 5s);
        events.ScheduleEvent(SPELL_WHIRLING_BLADE, 15s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(10, damage))
        {
            if (!latosiusActionDone)
            {
                if (Creature* latosius = instance->GetCreature(NPC_LATOSIUS))
                {
                    events.Reset();
                    me->SetReactState(REACT_PASSIVE);
                    latosius->AI()->DoAction(SPECIAL);
                    latosiusActionDone = true;
                }
            }

            damage = 0;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_UNERRING_SHEAR:
                me->CastSpell(me->GetVictim(), SPELL_UNERRING_SHEAR, false);
                events.Repeat(10s, 15s);
                break;
            case SPELL_WHIRLING_BLADE:
                me->CastSpell(nullptr, SPELL_WHIRLING_BLADE, false);
                events.Repeat(45s, 60s);
                break;
            default:
                break;
        }
    }

    void OnSuccessfulSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_WHIRLING_BLADE:
                if (Creature* whirlingBlade = me->SummonCreature(NPC_WHIRLING_BLADE, me->GetPosition()))
                {
                    whirlingBlade->CastSpell(nullptr, SPELL_WHIRLING_BLADE_AT, true);
                    //whirlingBlade->GetMotionMaster()->MovePoint();
                }
                break;
        }
    }

private:
    bool latosiusActionDone = false;
};

// Spell 198782
// AT 10185
struct at_kurtalos_whirling_blade : AreaTriggerAI
{
    at_kurtalos_whirling_blade(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            caster->CastSpell(unit, SPELL_WHIRLING_BLADE_DAMAGE, true);
    }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
            if (TempSummon* temp = caster->ToTempSummon())
                temp->DespawnOrUnsummon();
    }
};

// 98970
struct npc_latosius : public ScriptedAI
{
    npc_latosius(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->UpdateEntry(NPC_LATOSIUS);
    }

    void EnterCombat(Unit* /*attacker*/) override
    {
        me->CastSpell(nullptr, SPELL_TELEPORT_OUT, true);
        me->NearTeleportTo({ 3206.10f, 7416.93f, 276.54f, 3.451702f });

        events.ScheduleEvent(SPELL_DARK_BLAST, 10s);
        events.ScheduleEvent(SPELL_SHADOW_BOLT, 5s);
    }

    void DoAction(int32 action) override
    {
        if (action == SPECIAL)
        {
            events.Reset();

            me->CastSpell(nullptr, SPELL_TELEPORT_IN, true);
            me->NearTeleportTo({ 3185.36f, 7409.95f, 270.38f, 1.079803f });

            me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
            {
                me->CastSpell(nullptr, SPELL_SAP_SOUL, false);
            });

            me->GetScheduler().Schedule(9s, [this](TaskContext /*context*/)
            {
                me->CastSpell(nullptr, SPELL_DREADLORD_CONVERSATION, false);
                me->UpdateEntry(NPC_DANTALIONAX);
                me->CastSpell(nullptr, SPELL_TRANSFORM, false);
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (!UpdateVictim())
            return;

        ScriptedAI::UpdateAI(diff);

        switch (events.ExecuteEvent())
        {
            case SPELL_DARK_BLAST:
                me->CastSpell(nullptr, SPELL_DARK_BLAST, false);
                events.Repeat(10s);
                break;
            case SPELL_SHADOW_BOLT:
                me->CastSpell(nullptr, SPELL_SHADOW_BOLT, false);
                events.Repeat(5s);
                break;
        }
    }
};

void AddSC_boss_lord_kurtalos_ravencrest()
{
    RegisterCreatureAI(boss_kurtalos_ravencrest);
    RegisterAreaTriggerAI(at_kurtalos_whirling_blade);
}
