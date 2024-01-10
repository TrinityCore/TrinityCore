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

/* ScriptData
SDName: Boss_Golemagg
SD%Complete: 90
SDComment: Timers need to be confirmed, Golemagg's Trust need to be checked
SDCategory: Molten Core
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "molten_core.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

enum Texts
{
    EMOTE_LOWHP             = 0,
};

enum Spells
{
    // Golemagg
    SPELL_MAGMASPLASH       = 13879,
    SPELL_PYROBLAST         = 20228,
    SPELL_EARTHQUAKE        = 19798,
    SPELL_ENRAGE            = 19953,
    SPELL_GOLEMAGG_TRUST    = 20553,

    // Core Rager
    SPELL_MANGLE            = 19820
};

enum Events
{
    EVENT_PYROBLAST     = 1,
    EVENT_EARTHQUAKE    = 2,
};

struct boss_golemagg : public BossAI
{
    boss_golemagg(Creature* creature) : BossAI(creature, BOSS_GOLEMAGG_THE_INCINERATOR) { }

    void Reset() override
    {
        BossAI::Reset();
        DoCast(me, SPELL_MAGMASPLASH, true);
    }

    void JustEngagedWith(Unit* victim) override
    {
        BossAI::JustEngagedWith(victim);
        events.ScheduleEvent(EVENT_PYROBLAST, 7s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!HealthBelowPct(10) || me->HasAura(SPELL_ENRAGE))
            return;

        DoCast(me, SPELL_ENRAGE, true);
        events.ScheduleEvent(EVENT_EARTHQUAKE, 3s);
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
                case EVENT_PYROBLAST:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_PYROBLAST);
                    events.ScheduleEvent(EVENT_PYROBLAST, 7s);
                    break;
                case EVENT_EARTHQUAKE:
                    DoCastVictim(SPELL_EARTHQUAKE);
                    events.ScheduleEvent(EVENT_EARTHQUAKE, 3s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

struct npc_core_rager : public ScriptedAI
{
    npc_core_rager(Creature* creature) : ScriptedAI(creature)
    {
        _instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(7s, [this](TaskContext task) // These times are probably wrong
        {
            DoCastVictim(SPELL_MANGLE);
            task.Repeat(10s);
        });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (HealthAbovePct(50) || !_instance)
            return;

        if (Creature* pGolemagg = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(BOSS_GOLEMAGG_THE_INCINERATOR)))
        {
            if (pGolemagg->IsAlive())
            {
                me->AddAura(SPELL_GOLEMAGG_TRUST, me);
                Talk(EMOTE_LOWHP);
                me->SetFullHealth();
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

void AddSC_boss_golemagg()
{
    RegisterMoltenCoreCreatureAI(boss_golemagg);
    RegisterMoltenCoreCreatureAI(npc_core_rager);
}
