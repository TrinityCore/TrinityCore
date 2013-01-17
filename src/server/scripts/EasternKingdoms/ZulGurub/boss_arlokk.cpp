/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Arlokk
SD%Complete: 95
SDComment: Wrong cleave and red aura is missing.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulgurub.h"

enum Says
{
    SAY_AGGRO                   = 0,
    SAY_FEAST_PANTHER           = 1,
    SAY_DEATH                   = 2
};

enum Spells
{
    SPELL_SHADOW_WORD_PAIN      = 23952,
    SPELL_GOUGE                 = 24698,
    SPELL_MARK                  = 24210,
    SPELL_CLEAVE                = 26350, // Perhaps not right. Not a red aura...
    SPELL_PANTHER_TRANSFORM     = 24190
};

enum Events
{
    EVENT_SHADOW_WORD_PAIN      = 0,
    EVENT_GOUGE                 = 1,
    EVENT_MARK                  = 2,
    EVENT_CLEAVE                = 3,
    EVENT_VANISH                = 4,
    EVENT_VISIBLE               = 5,
    EVENT_SUMMON                = 6
};

enum Phases
{
    PHASE_ONE                 = 1,
    PHASE_TWO                 = 2
};

enum ModelIds
{
    MODEL_ID_NORMAL             = 15218,
    MODEL_ID_PANTHER            = 15215,
    MODEL_ID_BLANK              = 11686
};

Position const PosSummonProwlers[2] =
{
    { -11532.7998f, -1649.6734f, 41.4800f, 0.0f },
    { -11532.9970f, -1606.4840f, 41.2979f, 0.0f }
};

class boss_arlokk : public CreatureScript
{
    public: boss_arlokk() : CreatureScript("boss_arlokk") {}

        struct boss_arlokkAI : public BossAI
        {
            boss_arlokkAI(Creature* creature) : BossAI(creature, DATA_ARLOKK) { }

            void Reset()
            {
                summonCount = 0;
                markedTargetGUID = 0;
                me->SetDisplayId(MODEL_ID_NORMAL);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
                me->SetDisplayId(MODEL_ID_NORMAL);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000, 0, PHASE_ONE);
                events.ScheduleEvent(EVENT_MARK, 35000, 0, PHASE_ONE);
                events.ScheduleEvent(EVENT_SUMMON, 5000);
                events.ScheduleEvent(EVENT_VANISH, 60000);
                Talk(SAY_AGGRO);
            }

            void JustReachedHome()
            {
                instance->SetBossState(DATA_ARLOKK, NOT_STARTED);
                me->DespawnOrUnsummon();
            }

            void DoSummonPhanters()
            {
                if (summonCount > 30)
                    return;

                if (markedTargetGUID)
                    Talk(SAY_FEAST_PANTHER, markedTargetGUID);
                me->SummonCreature(NPC_ZULIAN_PROWLER, PosSummonProwlers[0], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                me->SummonCreature(NPC_ZULIAN_PROWLER, PosSummonProwlers[1], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
            }

            void JustSummoned(Creature* summoned)
            {
                if (Unit* markedTarget = Unit::GetUnit(*me, markedTargetGUID))
                    summoned->AI()->AttackStart(markedTarget);
                ++summonCount;
            }

            void UpdateAI(uint32 const diff)
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
                        case EVENT_SHADOW_WORD_PAIN:
                            DoCastVictim(SPELL_SHADOW_WORD_PAIN, true);
                            events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 15000, 0, PHASE_ONE);
                            break;
                        case EVENT_MARK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_MARK);
                            events.ScheduleEvent(EVENT_MARK, 15000, 0, PHASE_ONE);
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_SHADOW_WORD_PAIN, true);
                            events.ScheduleEvent(EVENT_CLEAVE, 16000, 0, PHASE_TWO);
                            break;
                        case EVENT_GOUGE:
                            DoCastVictim(SPELL_SHADOW_WORD_PAIN, true);
                            events.ScheduleEvent(EVENT_GOUGE, urand(17000, 27000), 0, PHASE_TWO);
                            break;
                        case EVENT_SUMMON:
                            DoSummonPhanters();
                            events.ScheduleEvent(EVENT_SUMMON, 5000);
                            break;
                        case EVENT_VANISH:
                            me->SetDisplayId(MODEL_ID_BLANK);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            me->AttackStop();
                            DoResetThreat();
                            events.ScheduleEvent(EVENT_VISIBLE, 6000);
                            break;
                        case EVENT_VISIBLE:
                        {
                            me->SetDisplayId(MODEL_ID_PANTHER);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            const CreatureTemplate* cinfo = me->GetCreatureTemplate();
                            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 35)));
                            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 35)));
                            me->UpdateDamagePhysical(BASE_ATTACK);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                AttackStart(target);
                            events.ScheduleEvent(EVENT_VANISH, 39000);
                            events.ScheduleEvent(EVENT_CLEAVE, 0, PHASE_TWO);
                            events.ScheduleEvent(EVENT_GOUGE, 14000, 0, PHASE_TWO);
                            events.SetPhase(PHASE_TWO);
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint32 summonCount;
            uint64 markedTargetGUID;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetZulGurubAI<boss_arlokkAI>(creature);
        }
};

class go_gong_of_bethekk : public GameObjectScript
{
    public: go_gong_of_bethekk() : GameObjectScript("go_gong_of_bethekk") {}

        bool OnGossipHello(Player* /*player*/, GameObject* go)
        {
            if (InstanceScript* instance = go->GetInstanceScript())
            {
                if (instance->GetBossState(DATA_ARLOKK) == DONE || instance->GetBossState(DATA_ARLOKK) == IN_PROGRESS)
                    return true;
                instance->SetBossState(DATA_ARLOKK, IN_PROGRESS);
                return true;
            }

            return true;
        }
};

void AddSC_boss_arlokk()
{
    new boss_arlokk();
    new go_gong_of_bethekk();
}

