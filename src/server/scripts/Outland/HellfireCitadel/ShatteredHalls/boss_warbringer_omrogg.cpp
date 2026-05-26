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

/* Timers requires to be revisited */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "shattered_halls.h"

enum OmroggTexts
{
    EMOTE_ROAR                  = 0,

    SAY_AGGRO_1                 = 0,
    SAY_AGGRO_1_1               = 0,
    SAY_AGGRO_1_2               = 1,

    SAY_AGGRO_2                 = 2,
    SAY_AGGRO_2_1               = 1,

    SAY_AGGRO_3                 = 3,
    SAY_AGGRO_3_1               = 2,

    SAY_ATTACK_1                = 4,
    SAY_ATTACK_1_1              = 3,
    SAY_ATTACK_1_2              = 5,

    SAY_ATTACK_2                = 6,
    SAY_ATTACK_2_1              = 4,

    SAY_ATTACK_3                = 7,
    SAY_ATTACK_3_1              = 5,
    SAY_ATTACK_3_2              = 8,

    SAY_ATTACK_4                = 6,
    SAY_ATTACK_4_1              = 9,
    SAY_ATTACK_4_2              = 7,

    SAY_SLAY_1                  = 8,

    SAY_SLAY_2                  = 10,
    SAY_SLAY_2_1                = 9,

    SAY_DEATH_1                 = 11,
    SAY_DEATH_1_1               = 10
};

enum OmroggSpells
{
    SPELL_FEAR                  = 30584,
    SPELL_THUNDERCLAP           = 30633,
    SPELL_BEATDOWN              = 30618,
    SPELL_BURNING_MAUL          = 30598,    // Triggers 30620, what it does? (no, it doesn't trigger 30600)

    SPELL_BLAST_WAVE            = 30600
};

enum OmroggEvents
{
    EVENT_FEAR                  = 1,
    EVENT_THUNDERCLAP,
    EVENT_BEATDOWN,
    EVENT_BURNING_MAUL
};

enum OmroggActions
{
    ACTION_AGGRO_1              = 1,
    ACTION_AGGRO_2              = 2,
    ACTION_AGGRO_3              = 3,
    ACTION_ATTACK_1             = 4,
    ACTION_ATTACK_2             = 5,
    ACTION_ATTACK_3             = 6,
    ACTION_ATTACK_4             = 7,
    ACTION_SLAY_1               = 8,
    ACTION_SLAY_2               = 9,
    ACTION_DEATH                = 10
};

enum OmroggEquips
{
    EQUIP_ID_BURNING_MAUL       = 2
};

// 16809 - Warbringer O'mrogg
struct boss_warbringer_omrogg : public BossAI
{
    boss_warbringer_omrogg(Creature* creature) : BossAI(creature, DATA_OMROGG) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_FEAR, 20s, 30s);
        events.ScheduleEvent(EVENT_THUNDERCLAP, 15s, 25s);
        events.ScheduleEvent(EVENT_BEATDOWN, 25s, 30s);
        events.ScheduleEvent(EVENT_BURNING_MAUL, 50s, 60s);

        if (Creature* leftHead = instance->GetCreature(DATA_LEFT_HEAD))
            leftHead->AI()->DoAction(RAND(ACTION_AGGRO_1, ACTION_AGGRO_2, ACTION_AGGRO_3));
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        /// @todo: Threat reset and AttackStart should be in spell script
        if (spell->Id == SPELL_BEATDOWN)
        {
            ResetThreatList();

            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                AttackStart(target);

            // Apparently this and all other are handled by GameEvents since this spell sends GameEvent
            if (Creature* leftHead = instance->GetCreature(DATA_LEFT_HEAD))
                leftHead->AI()->DoAction(RAND(ACTION_ATTACK_1, ACTION_ATTACK_2, ACTION_ATTACK_3, ACTION_ATTACK_4));
        }

        if (spell->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_BURNING_MAUL, me))
            Talk(EMOTE_ROAR);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        if (Creature* leftHead = instance->GetCreature(DATA_LEFT_HEAD))
            leftHead->AI()->DoAction(RAND(ACTION_SLAY_1, ACTION_SLAY_2));
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        if (Creature* leftHead = instance->GetCreature(DATA_LEFT_HEAD))
            leftHead->AI()->DoAction(ACTION_DEATH);
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
                case EVENT_FEAR:
                    DoCastSelf(SPELL_FEAR);
                    events.Repeat(15s, 35s);
                    break;
                case EVENT_THUNDERCLAP:
                    DoCastSelf(SPELL_THUNDERCLAP);
                    events.Repeat(15s, 30s);
                    break;
                case EVENT_BEATDOWN:
                    DoCastSelf(SPELL_BEATDOWN);
                    events.Repeat(25s, 40s);
                    break;
                case EVENT_BURNING_MAUL:
                    DoCastSelf(SPELL_BURNING_MAUL);
                    events.Repeat(60s, 70s);
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

// 19523 - O'mrogg's Left Head
// 19524 - O'mrogg's Right Head
struct npc_omrogg_heads : public ScriptedAI
{
    npc_omrogg_heads(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void RightHeadTalk(uint32 text)
    {
        if (Creature* rightHead = _instance->GetCreature(DATA_RIGHT_HEAD))
            rightHead->AI()->Talk(text);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_AGGRO_1:
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            Talk(SAY_AGGRO_1);
                            task.Repeat(3s);
                            break;
                        case 1:
                            RightHeadTalk(SAY_AGGRO_1_1);
                            task.Repeat(3s);
                            break;
                        case 2:
                            Talk(SAY_AGGRO_1_2);
                            break;
                        default:
                            break;
                    }
                });
                break;
            case ACTION_AGGRO_2:
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            Talk(SAY_AGGRO_2);
                            task.Repeat(3s);
                            break;
                        case 1:
                            RightHeadTalk(SAY_AGGRO_2_1);
                            break;
                        default:
                            break;
                    }
                });
                break;
            case ACTION_AGGRO_3:
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            Talk(SAY_AGGRO_3);
                            task.Repeat(3s);
                            break;
                        case 1:
                            RightHeadTalk(SAY_AGGRO_3_1);
                            break;
                        default:
                            break;
                    }
                });
                break;
            case ACTION_ATTACK_1:
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            Talk(SAY_ATTACK_1);
                            task.Repeat(3s);
                            break;
                        case 1:
                            RightHeadTalk(SAY_ATTACK_1_1);
                            task.Repeat(3s);
                            break;
                        case 2:
                            Talk(SAY_ATTACK_1_2);
                            break;
                        default:
                            break;
                    }
                });
                break;
            case ACTION_ATTACK_2:
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            Talk(SAY_ATTACK_2);
                            task.Repeat(3s);
                            break;
                        case 1:
                            RightHeadTalk(SAY_ATTACK_2_1);
                            break;
                        default:
                            break;
                    }
                });
                break;
            case ACTION_ATTACK_3:
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            Talk(SAY_ATTACK_3);
                            task.Repeat(3s);
                            break;
                        case 1:
                            RightHeadTalk(SAY_ATTACK_3_1);
                            task.Repeat(3s);
                            break;
                        case 2:
                            Talk(SAY_ATTACK_3_2);
                            break;
                        default:
                            break;
                    }
                });
                break;
            case ACTION_ATTACK_4:
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            RightHeadTalk(SAY_ATTACK_4);
                            task.Repeat(2s);
                            break;
                        case 1:
                            Talk(SAY_ATTACK_4_1);
                            task.Repeat(2s);
                            break;
                        case 2:
                            RightHeadTalk(SAY_ATTACK_4_2);
                            break;
                        default:
                            break;
                    }
                });
                break;
            case ACTION_SLAY_1:
                _scheduler.Schedule(0s, [this](TaskContext /*task*/)
                {
                    RightHeadTalk(SAY_SLAY_1);
                });
                break;
            case ACTION_SLAY_2:
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            Talk(SAY_SLAY_2);
                            task.Repeat(3s);
                            break;
                        case 1:
                            RightHeadTalk(SAY_SLAY_2_1);
                            break;
                        default:
                            break;
                    }
                });
                break;
            case ACTION_DEATH:
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            Talk(SAY_DEATH_1);
                            task.Repeat(3s);
                            break;
                        case 1:
                            RightHeadTalk(SAY_DEATH_1_1);
                            me->DespawnOrUnsummon(4s);
                            if (Creature* rightHead = _instance->GetCreature(DATA_RIGHT_HEAD))
                                rightHead->DespawnOrUnsummon(4s);
                            break;
                        default:
                            break;
                    }
                });
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

/// @todo: This requires additional research. Is it handled correctly? Isn't it too over-powered?
// That's a lot of damage if all melee attacks are successful so we cast it not always for now. No ProcCategoryRecovery for both spells
// 30598, 36056 - Burning Maul
class spell_omrogg_burning_maul : public AuraScript
{
    PrepareAuraScript(spell_omrogg_burning_maul);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLAST_WAVE });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
            creature->LoadEquipment(EQUIP_ID_BURNING_MAUL);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
            creature->LoadEquipment(creature->GetOriginalEquipmentId());
    }

    void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        if (roll_chance_i(50))
            GetTarget()->CastSpell(GetTarget(), SPELL_BLAST_WAVE);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_omrogg_burning_maul::OnApply, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_omrogg_burning_maul::OnRemove, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectProc += AuraEffectProcFn(spell_omrogg_burning_maul::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

void AddSC_boss_warbringer_omrogg()
{
    RegisterShatteredHallsCreatureAI(boss_warbringer_omrogg);
    RegisterShatteredHallsCreatureAI(npc_omrogg_heads);
    RegisterSpellScript(spell_omrogg_burning_maul);
}
