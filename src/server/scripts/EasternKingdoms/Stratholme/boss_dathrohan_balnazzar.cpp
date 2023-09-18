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
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum DathrohanTexts
{
    SAY_AGGRO                       = 0,
    SAY_TRANSFORM                   = 0,
    SAY_DEATH                       = 1
};

enum DathrohanSpells
{
    // Dathrohan
    SPELL_CRUSADERS_HAMMER          = 17286,
    SPELL_CRUSADER_STRIKE           = 17281,
    SPELL_HOLY_STRIKE               = 17284,
    SPELL_MIND_BLAST                = 17287,

    SPELL_BALNAZZAR_TRANSFORM       = 17288,

    // Balnazzar
    SPELL_SHADOW_SHOCK              = 17399,
    SPELL_PSYCHIC_SCREAM            = 13704,
    SPELL_SLEEP                     = 12098,
    SPELL_DOMINATION                = 17405
};

enum DathrohanEvents
{
    EVENT_CRUSADERS_HAMMER          = 1,
    EVENT_CRUSADER_STRIKE,
    EVENT_HOLY_STRIKE,

    EVENT_MIND_BLAST,

    EVENT_SHADOW_SHOCK,
    EVENT_PSYCHIC_SCREAM,
    EVENT_SLEEP,
    EVENT_DOMINATION,

    EVENT_TRANSFORM_1,
    EVENT_TRANSFORM_2,
    EVENT_TRANSFORM_3,
    EVENT_TRANSFORM_4
};

enum DathrohanMisc
{
    NPC_DATHROHAN                   = 10812,
    NPC_BALNAZZAR                   = 10813,
    SUMMON_GROUP_DEATH              = 0
};

// 10812 - Grand Crusader Dathrohan
struct boss_dathrohan_balnazzar : public BossAI
{
    boss_dathrohan_balnazzar(Creature* creature) : BossAI(creature, BOSS_BALNAZZAR), _transformed(false) { }

    void Reset() override
    {
        BossAI::Reset();

        _transformed = false;

        if (me->GetEntry() == NPC_BALNAZZAR)
            me->UpdateEntry(NPC_DATHROHAN);

        SetEquipmentSlots(true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_CRUSADERS_HAMMER, 15s, 25s);
        events.ScheduleEvent(EVENT_CRUSADER_STRIKE, 5s, 10s);
        events.ScheduleEvent(EVENT_HOLY_STRIKE, 10s, 20s);
        events.ScheduleEvent(EVENT_MIND_BLAST, 5s, 15s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_transformed && me->HealthBelowPctDamaged(40, damage))
        {
            _transformed = true;
            events.ScheduleEvent(EVENT_TRANSFORM_1, 0s);
        }
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);

        Talk(SAY_DEATH);
        me->SummonCreatureGroup(SUMMON_GROUP_DEATH);
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
                case EVENT_CRUSADERS_HAMMER:
                    DoCastSelf(SPELL_CRUSADERS_HAMMER);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_CRUSADER_STRIKE:
                    DoCastVictim(SPELL_CRUSADER_STRIKE);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_HOLY_STRIKE:
                    DoCastVictim(SPELL_HOLY_STRIKE);
                    events.Repeat(10s, 15s);
                    break;

                case EVENT_MIND_BLAST:
                    DoCastVictim(SPELL_MIND_BLAST);
                    events.Repeat(10s, 15s);
                    break;

                case EVENT_SHADOW_SHOCK:
                    DoCastSelf(SPELL_SHADOW_SHOCK);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_PSYCHIC_SCREAM:
                    DoCastSelf(SPELL_PSYCHIC_SCREAM);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_SLEEP:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_SLEEP);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_DOMINATION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1))
                        DoCast(target, SPELL_DOMINATION);
                    events.Repeat(20s, 25s);
                    break;

                case EVENT_TRANSFORM_1:
                    events.CancelEvent(EVENT_CRUSADERS_HAMMER);
                    events.CancelEvent(EVENT_CRUSADER_STRIKE);
                    events.CancelEvent(EVENT_HOLY_STRIKE);
                    events.CancelEvent(EVENT_MIND_BLAST);
                    DoCastSelf(SPELL_BALNAZZAR_TRANSFORM);
                    me->SetReactState(REACT_PASSIVE);
                    events.ScheduleEvent(EVENT_TRANSFORM_2, 2s);
                    break;
                case EVENT_TRANSFORM_2:
                    me->UpdateEntry(NPC_BALNAZZAR);
                    me->SetReactState(REACT_PASSIVE);
                    SetEquipmentSlots(false, EQUIP_UNEQUIP);
                    events.ScheduleEvent(EVENT_TRANSFORM_3, 2s);
                    break;
                case EVENT_TRANSFORM_3:
                    Talk(SAY_TRANSFORM);
                    events.ScheduleEvent(EVENT_TRANSFORM_4, 4s);
                    break;
                case EVENT_TRANSFORM_4:
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_MIND_BLAST, 5s, 15s);
                    events.ScheduleEvent(EVENT_SHADOW_SHOCK, 10s, 15s);
                    events.ScheduleEvent(EVENT_PSYCHIC_SCREAM, 15s, 25s);
                    events.ScheduleEvent(EVENT_SLEEP, 5s, 15s);
                    events.ScheduleEvent(EVENT_DOMINATION, 15s, 25s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _transformed;
};

void AddSC_boss_dathrohan_balnazzar()
{
    RegisterStratholmeCreatureAI(boss_dathrohan_balnazzar);
}
