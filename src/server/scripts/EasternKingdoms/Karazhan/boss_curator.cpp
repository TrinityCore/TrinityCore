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
#include "karazhan.h"
#include "ScriptedCreature.h"

enum CuratorSays
{
    SAY_AGGRO                    = 0,
    SAY_SUMMON                   = 1,
    SAY_EVOCATE                  = 2,
    SAY_ENRAGE                   = 3,
    SAY_KILL                     = 4,
    SAY_DEATH                    = 5
};

enum CuratorSpells
{
    SPELL_HATEFUL_BOLT           = 30383,
    SPELL_EVOCATION              = 30254,
    SPELL_ARCANE_INFUSION        = 30403,
    SPELL_BERSERK                = 26662,
    SPELL_SUMMON_ASTRAL_FLARE_NE = 30236,
    SPELL_SUMMON_ASTRAL_FLARE_NW = 30239,
    SPELL_SUMMON_ASTRAL_FLARE_SE = 30240,
    SPELL_SUMMON_ASTRAL_FLARE_SW = 30241
};

enum CuratorEvents
{
    EVENT_HATEFUL_BOLT = 1,
    EVENT_SUMMON_ASTRAL_FLARE,
    EVENT_ARCANE_INFUSION,
    EVENT_BERSERK
};

class boss_curator : public CreatureScript
{
public:
    boss_curator() : CreatureScript("boss_curator") { }

    struct boss_curatorAI : public BossAI
    {
        boss_curatorAI(Creature* creature) : BossAI(creature, DATA_CURATOR), _infused(false) { }

        void Reset() override
        {
            _Reset();
            _infused = false;
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Talk(SAY_AGGRO);

            events.ScheduleEvent(EVENT_HATEFUL_BOLT, 12s);
            events.ScheduleEvent(EVENT_SUMMON_ASTRAL_FLARE, 10s);
            events.ScheduleEvent(EVENT_BERSERK, 12min);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (!HealthAbovePct(15) && !_infused)
            {
                _infused = true;
                events.ScheduleEvent(EVENT_ARCANE_INFUSION, Milliseconds(1));
                events.CancelEvent(EVENT_SUMMON_ASTRAL_FLARE);
            }
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_HATEFUL_BOLT:
                    if (Unit* target = SelectTarget(SelectTargetMethod::MaxThreat, 1))
                        DoCast(target, SPELL_HATEFUL_BOLT);
                    events.Repeat(Seconds(7), Seconds(15));
                    break;
                case EVENT_ARCANE_INFUSION:
                    DoCastSelf(SPELL_ARCANE_INFUSION, true);
                    break;
                case EVENT_SUMMON_ASTRAL_FLARE:
                    if (roll_chance_i(50))
                        Talk(SAY_SUMMON);

                    DoCastSelf(RAND(SPELL_SUMMON_ASTRAL_FLARE_NE, SPELL_SUMMON_ASTRAL_FLARE_NW, SPELL_SUMMON_ASTRAL_FLARE_SE, SPELL_SUMMON_ASTRAL_FLARE_SW), true);

                    if (int32 mana = int32(me->GetMaxPower(POWER_MANA) / 10))
                    {
                        me->ModifyPower(POWER_MANA, -mana);

                        if (me->GetPower(POWER_MANA) * 100 / me->GetMaxPower(POWER_MANA) < 10)
                        {
                            Talk(SAY_EVOCATE);
                            me->InterruptNonMeleeSpells(false);
                            DoCastSelf(SPELL_EVOCATION);
                        }
                    }
                    events.Repeat(Seconds(10));
                    break;
                case EVENT_BERSERK:
                    Talk(SAY_ENRAGE);
                    DoCastSelf(SPELL_BERSERK, true);
                    break;
                default:
                    break;
            }
        }

    private:
        bool _infused;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetKarazhanAI<boss_curatorAI>(creature);
    }
};

class npc_curator_astral_flare : public CreatureScript
{
public:
    npc_curator_astral_flare() : CreatureScript("npc_curator_astral_flare") { }

    struct npc_curator_astral_flareAI : public ScriptedAI
    {
        npc_curator_astral_flareAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            _scheduler.Schedule(Seconds(2), [this](TaskContext /*context*/)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                DoZoneInCombat();
            });
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

    private:
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetKarazhanAI<npc_curator_astral_flareAI>(creature);
    }
};

void AddSC_boss_curator()
{
    new boss_curator();
    new npc_curator_astral_flare();
}
