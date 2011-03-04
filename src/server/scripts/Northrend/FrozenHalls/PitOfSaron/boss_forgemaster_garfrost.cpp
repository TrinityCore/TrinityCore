/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "pit_of_saron.h"

enum Yells
{
    SAY_AGGRO           = -1658001,
    SAY_SLAY_1          = -1658002,
    SAY_SLAY_2          = -1658003,
    SAY_DEATH           = -1658004,
    SAY_PHASE2          = -1658005,
    SAY_PHASE3          = -1658006,
    SAY_TYRANNUS_DEATH  = -1659007
};

enum eEvents
{
    EVENT_NONE,
    EVENT_PERMAFROST,
    EVENT_THROW_SARONITE,
    EVENT_CHILLINGWAVE,
    EVENT_DEEPFREEZE,
    EVENT_FORGE_DONE
};

enum Spells
{
    SPELL_PERMAFROST            = 70326,
    SPELL_PERMAFROST_TRIGGER    = 68786, // triggered by PERMAFROST. Used to check aura
    SPELL_THROW_SARONITE        = 68788,
    SPELL_THUNDERING_STOMP      = 68771
};

#define SPELL_CHILLING_WAVE DUNGEON_MODE(68778,70333)
#define SPELL_DEEP_FREEZE   DUNGEON_MODE(70381,72930)
#define SPELL_FORGE_MACE    DUNGEON_MODE(68785,70335)
#define SPELL_FORGE_BLADE   DUNGEON_MODE(68774,70334)

enum eEnums
{
    EQUIP_ID_SWORD              = 49345,
    EQUIP_ID_MACE               = 49344,
    ACHIEV_DOESNT_GO_TO_ELEVEN  = 4524
};

static const Position PosSchmiede[2] =
{
    {642.793091f, -207.835632f, 528.931763f, 0.000000f},
    {720.546326f, -232.220337f, 527.048340f, 0.000000f}
};

class boss_garfrost : public CreatureScript
{
public:
    boss_garfrost() : CreatureScript("boss_garfrost") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_garfrostAI (pCreature);
    }

    struct boss_garfrostAI : public ScriptedAI
    {
        boss_garfrostAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        bool bAchievement;
        uint8 phase;

        void Reset()
        {
            events.Reset();
            me->LoadEquipment(10045, true);
            bAchievement = true;
            phase = 0;

            if (pInstance)
                pInstance->SetData(DATA_GARFROST_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
            DoCast(me, SPELL_PERMAFROST);

            if (pInstance)
                pInstance->SetData(DATA_GARFROST_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_THROW_SARONITE, 100);

            me->CallForHelp(50);
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32& /*uiDamage*/)
        {
            if ((HealthBelowPct(66) && phase == 0) || (HealthBelowPct(33) && phase == 1))
            {
                DoCast(me, SPELL_THUNDERING_STOMP);

                me->SetSpeed(MOVE_RUN, 2.5f, true);
                me->GetMotionMaster()->MovePoint(phase+1, PosSchmiede[phase]);

                ++phase;
            }
        }

        void KilledUnit(Unit * victim)
        {
            if (victim == me)
                return;

            DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            if (pInstance)
            {
                if (Creature *pTyrannus = me->GetCreature(*me, pInstance->GetData64(DATA_TYRANNUS)))
                    DoScriptText(SAY_TYRANNUS_DEATH, pTyrannus);

                pInstance->SetData(DATA_GARFROST_EVENT, DONE);
                if (IsHeroic() && bAchievement)
                    pInstance->DoCompleteAchievement(ACHIEV_DOESNT_GO_TO_ELEVEN);
            }
        }

        void SpellHitTarget(Unit* pTarget, const SpellEntry *spell)
        {
            if (spell->Id == SPELL_PERMAFROST_TRIGGER && bAchievement)
            {
                if (Aura *pAura = pTarget->GetAura(SPELL_PERMAFROST_TRIGGER))
                    if (pAura->GetStackAmount() > 10)
                        bAchievement = false;
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            me->GetMotionMaster()->MoveIdle();
            me->SetSpeed(MOVE_WALK, 1.5f, true);

            switch(id)
            {
                case 1: DoCast(me, SPELL_FORGE_BLADE); break;
                case 2: DoCast(me, SPELL_FORGE_MACE); break;
            }
            events.ScheduleEvent(EVENT_FORGE_DONE, 4000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_THROW_SARONITE:
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            if (phase == 0 || phase > 2)
                                DoCast(pTarget, SPELL_THROW_SARONITE);
                        events.RescheduleEvent(EVENT_THROW_SARONITE, 35000);
                        break;
                    case EVENT_FORGE_DONE:
                        if (phase == 1)
                        {
                            SetEquipmentSlots(false, EQUIP_ID_SWORD, -1, -1);
                            me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);
                            events.RescheduleEvent(EVENT_THROW_SARONITE, 1000);
                            events.ScheduleEvent(EVENT_CHILLINGWAVE, 10000);
                        }
                        else if (phase == 2)
                        {
                            me->RemoveAurasDueToSpell(SPELL_FORGE_BLADE);
                            SetEquipmentSlots(false, EQUIP_ID_MACE, -1, -1);
                            me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);
                            events.RescheduleEvent(EVENT_THROW_SARONITE, 1000);
                            events.ScheduleEvent(EVENT_DEEPFREEZE, 10000);
                            ++phase;
                        }
                        events.CancelEvent(EVENT_FORGE_DONE);
                        me->GetMotionMaster()->MoveChase(me->getVictim());
                        break;
                    case EVENT_CHILLINGWAVE:
                        DoCastAOE(SPELL_CHILLING_WAVE);
                        events.RescheduleEvent(EVENT_CHILLINGWAVE, 40000);
                        break;
                    case EVENT_DEEPFREEZE:
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_DEEP_FREEZE);
                        events.RescheduleEvent(EVENT_DEEPFREEZE, 35000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

};

class mob_belagerungsschmied_garfrost : public CreatureScript
{
public:
    mob_belagerungsschmied_garfrost() : CreatureScript("mob_belagerungsschmied_garfrost") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_belagerungsschmied_garfrostAI(pCreature);
    }

    struct mob_belagerungsschmied_garfrostAI : public ScriptedAI
    {
        mob_belagerungsschmied_garfrostAI(Creature *c) : ScriptedAI(c)
        {
        }

        void Reset()
        {
            me->SetFlag(UNIT_NPC_EMOTESTATE, EMOTE_STATE_WORK_MINING);
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->CallForHelp(50);
            me->RemoveFlag(UNIT_NPC_EMOTESTATE, EMOTE_STATE_WORK_MINING);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_garfrost()
{
    new boss_garfrost();
    new mob_belagerungsschmied_garfrost();
}
