/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_Ragnaros
SD%Complete: 75
SDComment: Intro Dialog and event NYI
SDCategory: Molten Core
EndScriptData */

#include "precompiled.h"

#define SAY_REINFORCEMENTS1         -1409013
#define SAY_REINFORCEMENTS2         -1409014
#define SAY_HAND                    -1409015
#define SAY_WRATH                   -1409016
#define SAY_KILL                    -1409017
#define SAY_MAGMABURST              -1409018

#define SPELL_HANDOFRAGNAROS        19780
#define SPELL_WRATHOFRAGNAROS       20566
#define SPELL_LAVABURST             21158

#define SPELL_MAGMABURST            20565                   //Ranged attack

#define SPELL_SONSOFFLAME_DUMMY     21108                   //Server side effect
#define SPELL_RAGSUBMERGE           21107                   //Stealth aura
#define SPELL_RAGEMERGE             20568
#define SPELL_MELTWEAPON            21388
#define SPELL_ELEMENTALFIRE         20564
#define SPELL_ERRUPTION             17731

#define ADD_1X 848.740356
#define ADD_1Y -816.103455
#define ADD_1Z -229.74327
#define ADD_1O 2.615287

#define ADD_2X 852.560791
#define ADD_2Y -849.861511
#define ADD_2Z -228.560974
#define ADD_2O 2.836073

#define ADD_3X 808.710632
#define ADD_3Y -852.845764
#define ADD_3Z -227.914963
#define ADD_3O 0.964207

#define ADD_4X 786.597107
#define ADD_4Y -821.132874
#define ADD_4Z -226.350128
#define ADD_4O 0.949377

#define ADD_5X 796.219116
#define ADD_5Y -800.948059
#define ADD_5Z -226.010361
#define ADD_5O 0.560603

#define ADD_6X 821.602539
#define ADD_6Y -782.744109
#define ADD_6Z -226.023575
#define ADD_6O 6.157440

#define ADD_7X 844.924744
#define ADD_7Y -769.453735
#define ADD_7Z -225.521698
#define ADD_7O 4.4539958

#define ADD_8X 839.823364
#define ADD_8Y -810.869385
#define ADD_8Z -229.683182
#define ADD_8O 4.693108

struct TRINITY_DLL_DECL boss_ragnarosAI : public Scripted_NoMovementAI
{
    boss_ragnarosAI(Creature *c) : Scripted_NoMovementAI(c) {}

    uint32 WrathOfRagnaros_Timer;
    uint32 HandOfRagnaros_Timer;
    uint32 LavaBurst_Timer;
    uint32 MagmaBurst_Timer;
    uint32 ElementalFire_Timer;
    uint32 Erruption_Timer;
    uint32 Submerge_Timer;
    uint32 Attack_Timer;
    Creature *Summoned;
    bool HasYelledMagmaBurst;
    bool HasSubmergedOnce;
    bool WasBanished;
    bool HasAura;

    void Reset()
    {
        WrathOfRagnaros_Timer = 30000;
        HandOfRagnaros_Timer = 25000;
        LavaBurst_Timer = 10000;
        MagmaBurst_Timer = 2000;
        Erruption_Timer = 15000;
        ElementalFire_Timer = 3000;
        Submerge_Timer = 180000;
        Attack_Timer = 90000;
        HasYelledMagmaBurst = false;
        HasSubmergedOnce = false;
        WasBanished = false;

        m_creature->CastSpell(m_creature,SPELL_MELTWEAPON,true);
        HasAura = true;
    }

    void KilledUnit(Unit* victim)
    {
        if (rand()%5)
            return;

        DoScriptText(SAY_KILL, m_creature);
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (WasBanished && Attack_Timer < diff)
        {
            //Become unbanished again
            m_creature->setFaction(14);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            DoCast(m_creature,SPELL_RAGEMERGE);
            WasBanished = false;
        } else if (WasBanished)
        {
            Attack_Timer -= diff;
            //Do nothing while banished
            return;
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        //WrathOfRagnaros_Timer
        if (WrathOfRagnaros_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_WRATHOFRAGNAROS);

            if (rand()%2 == 0)
            {
                DoScriptText(SAY_WRATH, m_creature);
            }

            WrathOfRagnaros_Timer = 30000;
        }else WrathOfRagnaros_Timer -= diff;

        //HandOfRagnaros_Timer
        if (HandOfRagnaros_Timer < diff)
        {
            DoCast(m_creature,SPELL_HANDOFRAGNAROS);

            if (rand()%2==0)
            {
                DoScriptText(SAY_HAND, m_creature);
            }

            HandOfRagnaros_Timer = 25000;
        }else HandOfRagnaros_Timer -= diff;

        //LavaBurst_Timer
        if (LavaBurst_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_LAVABURST);
            LavaBurst_Timer = 10000;
        }else LavaBurst_Timer -= diff;

        //Erruption_Timer
        if (LavaBurst_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_ERRUPTION);
            Erruption_Timer = 20000 + rand()%25000;
        }else Erruption_Timer -= diff;

        //ElementalFire_Timer
        if (ElementalFire_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_ELEMENTALFIRE);
            ElementalFire_Timer = 10000 + rand()%4000;
        }else ElementalFire_Timer -= diff;

        //Submerge_Timer
        if (!WasBanished && Submerge_Timer < diff)
        {
            //Creature spawning and ragnaros becomming unattackable
            //is not very well supported in the core
            //so added normaly spawning and banish workaround and attack again after 90 secs.

            m_creature->InterruptNonMeleeSpells(false);
            //Root self
            DoCast(m_creature,23973);
            m_creature->setFaction(35);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_SUBMERGE);

            if (!HasSubmergedOnce)
            {
                DoScriptText(SAY_REINFORCEMENTS1, m_creature);

                // summon 10 elementals
                for(int i = 0; i < 9; ++i)
                {
                    if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                    {
                        if (Creature* pSummoned = m_creature->SummonCreature(12143,pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(),0.0f,TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN,900000))
                            pSummoned->AI()->AttackStart(pTarget);
                    }
                }

                HasSubmergedOnce = true;
                WasBanished = true;
                DoCast(m_creature,SPELL_RAGSUBMERGE);
                Attack_Timer = 90000;

            }
            else
            {
                DoScriptText(SAY_REINFORCEMENTS2, m_creature);

                for(int i = 0; i < 9; ++i)
                {
                    if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                    {
                        if (Creature* pSummoned = m_creature->SummonCreature(12143,pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(),0.0f,TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN,900000))
                        pSummoned->AI()->AttackStart(pTarget);
                    }
                }

                WasBanished = true;
                DoCast(m_creature,SPELL_RAGSUBMERGE);
                Attack_Timer = 90000;
            }

            Submerge_Timer = 180000;
        }else Submerge_Timer -= diff;

        //If we are within range melee the target
        if( m_creature->IsWithinMeleeRange(m_creature->getVictim()))
        {
            //Make sure our attack is ready and we arn't currently casting
            if( m_creature->isAttackReady() && !m_creature->IsNonMeleeSpellCasted(false))
            {
                m_creature->AttackerStateUpdate(m_creature->getVictim());
                m_creature->resetAttackTimer();
            }
        }
        else
        {
            //MagmaBurst_Timer
            if (MagmaBurst_Timer < diff)
            {
                DoCast(m_creature->getVictim(),SPELL_MAGMABURST);

                if (!HasYelledMagmaBurst)
                {
                    //Say our dialog
                    DoScriptText(SAY_MAGMABURST, m_creature);
                    HasYelledMagmaBurst = true;
                }

                MagmaBurst_Timer = 2500;
            }else MagmaBurst_Timer -= diff;
        }
    }
};
CreatureAI* GetAI_boss_ragnaros(Creature *_Creature)
{
    return new boss_ragnarosAI (_Creature);
}

void AddSC_boss_ragnaros()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_ragnaros";
    newscript->GetAI = &GetAI_boss_ragnaros;
    newscript->RegisterSelf();
}

