/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Mograine_And_Whitemane
SD%Complete: 90
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "ScriptPCH.h"
#include "scarlet_monastery.h"

enum eEnums
{
    //Mograine says
    SAY_MO_AGGRO                 = -1189005,
    SAY_MO_KILL                  = -1189006,
    SAY_MO_RESSURECTED           = -1189007,

    //Whitemane says
    SAY_WH_INTRO                 = -1189008,
    SAY_WH_KILL                  = -1189009,
    SAY_WH_RESSURECT             = -1189010,

    //Mograine Spells
    SPELL_CRUSADERSTRIKE         = 14518,
    SPELL_HAMMEROFJUSTICE        = 5589,
    SPELL_LAYONHANDS             = 9257,
    SPELL_RETRIBUTIONAURA        = 8990,

    //Whitemanes Spells
    SPELL_DEEPSLEEP              = 9256,
    SPELL_SCARLETRESURRECTION    = 9232,
    SPELL_DOMINATEMIND           = 14515,
    SPELL_HOLYSMITE              = 9481,
    SPELL_HEAL                   = 12039,
    SPELL_POWERWORDSHIELD        = 22187
};

class boss_scarlet_commander_mograine : public CreatureScript
{
public:
    boss_scarlet_commander_mograine() : CreatureScript("boss_scarlet_commander_mograine") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_scarlet_commander_mograineAI (creature);
    }

    struct boss_scarlet_commander_mograineAI : public ScriptedAI
    {
        boss_scarlet_commander_mograineAI(Creature* creature) : ScriptedAI(creature)
        {
            m_instance = creature->GetInstanceScript();
        }

        InstanceScript* m_instance;

        uint32 m_uiCrusaderStrike_Timer;
        uint32 m_uiHammerOfJustice_Timer;

        bool m_bHasDied;
        bool m_bHeal;
        bool m_bFakeDeath;

        void Reset()
        {
            m_uiCrusaderStrike_Timer = 10000;
            m_uiHammerOfJustice_Timer = 10000;

            //Incase wipe during phase that mograine fake death
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetStandState(UNIT_STAND_STATE_STAND);

            if (m_instance)
                if (me->isAlive())
                    m_instance->SetData(TYPE_MOGRAINE_AND_WHITE_EVENT, NOT_STARTED);

            m_bHasDied = false;
            m_bHeal = false;
            m_bFakeDeath = false;
        }

        void JustReachedHome()
        {
            if (m_instance)
            {
                if (m_instance->GetData(TYPE_MOGRAINE_AND_WHITE_EVENT != NOT_STARTED))
                    m_instance->SetData(TYPE_MOGRAINE_AND_WHITE_EVENT, FAIL);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_MO_AGGRO, me);
            DoCast(me, SPELL_RETRIBUTIONAURA);

            me->CallForHelp(VISIBLE_RANGE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(SAY_MO_KILL, me);
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage)
        {
            if (uiDamage < me->GetHealth() || m_bHasDied || m_bFakeDeath)
                return;

            if (!m_instance)
                return;

            //On first death, fake death and open door, as well as initiate whitemane if exist
            if (Unit* Whitemane = Unit::GetUnit((*me), m_instance->GetData64(DATA_WHITEMANE)))
            {
                m_instance->SetData(TYPE_MOGRAINE_AND_WHITE_EVENT, IN_PROGRESS);

                Whitemane->GetMotionMaster()->MovePoint(1, 1163.113370f, 1398.856812f, 32.527786f);

                me->GetMotionMaster()->MovementExpired();
                me->GetMotionMaster()->MoveIdle();

                me->SetHealth(0);

                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(false);

                me->ClearComboPointHolders();
                me->RemoveAllAuras();
                me->ClearAllReactives();

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetStandState(UNIT_STAND_STATE_DEAD);

                m_bHasDied = true;
                m_bFakeDeath = true;

                uiDamage = 0;
            }
        }

        void SpellHit(Unit* /*who*/, const SpellInfo* pSpell)
        {
            //When hit with ressurection say text
            if (pSpell->Id == SPELL_SCARLETRESURRECTION)
            {
                DoScriptText(SAY_MO_RESSURECTED, me);
                m_bFakeDeath = false;

                if (m_instance)
                    m_instance->SetData(TYPE_MOGRAINE_AND_WHITE_EVENT, SPECIAL);
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (m_bHasDied && !m_bHeal && m_instance && m_instance->GetData(TYPE_MOGRAINE_AND_WHITE_EVENT) == SPECIAL)
            {
                //On ressurection, stop fake death and heal whitemane and resume fight
                if (Unit* Whitemane = Unit::GetUnit((*me), m_instance->GetData64(DATA_WHITEMANE)))
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    DoCast(Whitemane, SPELL_LAYONHANDS);

                    m_uiCrusaderStrike_Timer = 10000;
                    m_uiHammerOfJustice_Timer = 10000;

                    if (me->getVictim())
                        me->GetMotionMaster()->MoveChase(me->getVictim());

                    m_bHeal = true;
                }
            }

            //This if-check to make sure mograine does not attack while fake death
            if (m_bFakeDeath)
                return;

            //m_uiCrusaderStrike_Timer
            if (m_uiCrusaderStrike_Timer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_CRUSADERSTRIKE);
                m_uiCrusaderStrike_Timer = 10000;
            } else m_uiCrusaderStrike_Timer -= uiDiff;

            //m_uiHammerOfJustice_Timer
            if (m_uiHammerOfJustice_Timer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_HAMMEROFJUSTICE);
                m_uiHammerOfJustice_Timer = 60000;
            } else m_uiHammerOfJustice_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};

class boss_high_inquisitor_whitemane : public CreatureScript
{
public:
    boss_high_inquisitor_whitemane() : CreatureScript("boss_high_inquisitor_whitemane") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_high_inquisitor_whitemaneAI (creature);
    }

    struct boss_high_inquisitor_whitemaneAI : public ScriptedAI
    {
        boss_high_inquisitor_whitemaneAI(Creature* creature) : ScriptedAI(creature)
        {
            m_instance = creature->GetInstanceScript();
        }

        InstanceScript* m_instance;

        uint32 m_uiHeal_Timer;
        uint32 m_uiPowerWordShield_Timer;
        uint32 m_uiHolySmite_Timer;
        uint32 m_uiWait_Timer;

        bool m_bCanResurrectCheck;
        bool m_bCanResurrect;

        void Reset()
        {
            m_uiWait_Timer = 7000;
            m_uiHeal_Timer = 10000;
            m_uiPowerWordShield_Timer = 15000;
            m_uiHolySmite_Timer = 6000;

            m_bCanResurrectCheck = false;
            m_bCanResurrect = false;

            if (m_instance)
                if (me->isAlive())
                    m_instance->SetData(TYPE_MOGRAINE_AND_WHITE_EVENT, NOT_STARTED);
        }

        void AttackStart(Unit* who)
        {
            if (m_instance && m_instance->GetData(TYPE_MOGRAINE_AND_WHITE_EVENT) == NOT_STARTED)
                return;

            ScriptedAI::AttackStart(who);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_WH_INTRO, me);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(SAY_WH_KILL, me);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (m_bCanResurrect)
            {
                //When casting resuruction make sure to delay so on rez when reinstate battle deepsleep runs out
                if (m_instance && m_uiWait_Timer <= uiDiff)
                {
                    if (Unit* Mograine = Unit::GetUnit((*me), m_instance->GetData64(DATA_MOGRAINE)))
                    {
                        DoCast(Mograine, SPELL_SCARLETRESURRECTION);
                        DoScriptText(SAY_WH_RESSURECT, me);
                        m_bCanResurrect = false;
                    }
                }
                else m_uiWait_Timer -= uiDiff;
            }

            //Cast Deep sleep when health is less than 50%
            if (!m_bCanResurrectCheck && !HealthAbovePct(50))
            {
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(false);

                DoCast(me->getVictim(), SPELL_DEEPSLEEP);
                m_bCanResurrectCheck = true;
                m_bCanResurrect = true;
                return;
            }

            //while in "resurrect-mode", don't do anything
            if (m_bCanResurrect)
                return;

            //If we are <75% hp cast healing spells at self or Mograine
            if (m_uiHeal_Timer <= uiDiff)
            {
                Creature* target = NULL;

                if (!HealthAbovePct(75))
                    target = me;

                if (m_instance)
                {
                    if (Creature* pMograine = Unit::GetCreature((*me), m_instance->GetData64(DATA_MOGRAINE)))
                    {
                        // checking m_bCanResurrectCheck prevents her healing Mograine while he is "faking death"
                        if (m_bCanResurrectCheck && pMograine->isAlive() && !pMograine->HealthAbovePct(75))
                            target = pMograine;
                    }
                }

                if (target)
                    DoCast(target, SPELL_HEAL);

                m_uiHeal_Timer = 13000;
            } else m_uiHeal_Timer -= uiDiff;

            //m_uiPowerWordShield_Timer
            if (m_uiPowerWordShield_Timer <= uiDiff)
            {
                DoCast(me, SPELL_POWERWORDSHIELD);
                m_uiPowerWordShield_Timer = 15000;
            } else m_uiPowerWordShield_Timer -= uiDiff;

            //m_uiHolySmite_Timer
            if (m_uiHolySmite_Timer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_HOLYSMITE);
                m_uiHolySmite_Timer = 6000;
            } else m_uiHolySmite_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_mograine_and_whitemane()
{
    new boss_scarlet_commander_mograine();
    new boss_high_inquisitor_whitemane();
}
