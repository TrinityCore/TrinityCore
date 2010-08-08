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
    SAY_AGGRO                                   = -1658001,
    SAY_SLAY_1                                  = -1658002,
    SAY_SLAY_2                                  = -1658003,
    SAY_DEATH                                   = -1658004,
    SAY_PHASE2                                  = -1658005,
    SAY_PHASE3                                  = -1658006,

    SAY_TYRANNUS_DEATH                          = -1659007,
};

enum eEvents
{
    EVENT_NONE,
    EVENT_PERMAFROST,
    EVENT_THROW_SARONITE,
    EVENT_CHILLINGWAVE,
    EVENT_DEEPFREEZE,
};

enum Spells
{
    SPELL_PERMAFROST                            = 70326,
    SPELL_PERMAFROST_TRIGGER                    = 68786, // triggered by PERMAFROST. Used to check aura
    SPELL_THROW_SARONITE                        = 68788,
    SPELL_THUNDERING_STOMP                      = 68771,
    SPELL_CHILLING_WAVE                         = 68778,
    H_SPELL_CHILLING_WAVE                       = 70333,
    SPELL_DEEP_FREEZE                           = 70381,
    H_SPELL_DEEP_FREEZE                         = 72930,
    SPELL_FORGE_MACE                            = 68785,
    H_SPELL_FORGE_MACE                          = 70335,
    SPELL_FORGE_BLADE                           = 68774,
    H_SPELL_FORGE_BLADE                         = 70334,
};

enum eEnums
{
    EQUIP_ID_SWORD                              = 49345,
    EQUIP_ID_MACE                               = 49344,
    ACHIEV_DOESNT_GO_TO_ELEVEN                  = 4524,
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

        bool phase2;
        bool phase3;
        bool bAchievement;

        InstanceScript* pInstance;
        EventMap events;

        void Reset()
        {
            events.Reset();

            phase2 = false;
            phase3 = false;
            bAchievement = true;

            if (pInstance)
                pInstance->SetData(DATA_GARFROST_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
            DoCast(me, SPELL_PERMAFROST);

            if (pInstance)
                pInstance->SetData(DATA_GARFROST_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_THROW_SARONITE, 45000);
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32& /*uiDamage*/)
        {
            if (HealthBelowPct(66) && !phase2)
            {
                phase2 = true;
                DoCast(me, SPELL_THUNDERING_STOMP);
                // TODO: should go to a forge
                DoCast(me, SPELL_FORGE_BLADE);
                // TODO: should equip when spell completes
                SetEquipmentSlots(false, EQUIP_ID_SWORD, -1, -1);
                me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);
                events.ScheduleEvent(EVENT_CHILLINGWAVE, 10000);
            }

            if (HealthBelowPct(33) && !phase3)
            {
                phase3 = true;
                DoCast(me, SPELL_THUNDERING_STOMP);
                // TODO: should go to a forge
                DoCast(me, SPELL_FORGE_MACE);
                // TODO: should equip when spell completes
                SetEquipmentSlots(false, EQUIP_ID_MACE, -1, -1);
                me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);
                events.CancelEvent(EVENT_CHILLINGWAVE); // cast only in phase 2.
                events.ScheduleEvent(EVENT_DEEPFREEZE, 10000);
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

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->hasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_THROW_SARONITE:
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_THROW_SARONITE);
                        events.RescheduleEvent(EVENT_THROW_SARONITE, 35000);
                        return;
                    case EVENT_DEEPFREEZE:
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_DEEP_FREEZE);
                        events.RescheduleEvent(EVENT_DEEPFREEZE, 35000);
                        return;
                    case EVENT_CHILLINGWAVE:
                        DoCastAOE(SPELL_CHILLING_WAVE);
                        events.RescheduleEvent(EVENT_CHILLINGWAVE, 40000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};


void AddSC_boss_garfrost()
{
    new boss_garfrost();
}
