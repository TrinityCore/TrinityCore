/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Blackheart_the_Inciter
SD%Complete: 75
SDComment: Incite Chaos not functional since core lacks Mind Control support
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "precompiled.h"
#include "def_shadow_labyrinth.h"

#define SPELL_INCITE_CHAOS    33676
#define SPELL_INCITE_CHAOS_B  33684                         //debuff applied to each member of party
#define SPELL_CHARGE          33709
#define SPELL_WAR_STOMP       33707

#define SAY_AGGRO1            "You be dead people!"
#define SAY_AGGRO2            "Time to kill!"
#define SAY_AGGRO3            "I see dead people!"
#define SAY_SLAY1             "No coming back for you!"
#define SAY_SLAY2             "Nice try!"
#define SAY_SLAY3             "Now you gone for good!"
#define SAY_DEATH             "This...no...good.."

#define SOUND_AGGRO1          10498
#define SOUND_AGGRO2          10497
#define SOUND_AGGRO3          10488
#define SOUND_SLAY1           10489
#define SOUND_SLAY2           10490
#define SOUND_SLAY3           10499
#define SOUND_DEATH           10491

struct TRINITY_DLL_DECL boss_blackheart_the_inciterAI : public ScriptedAI
{
    boss_blackheart_the_inciterAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance *pInstance;

    bool InciteChaos;
    uint32 InciteChaos_Timer;
    uint32 InciteChaosWait_Timer;
    uint32 Charge_Timer;
    uint32 Knockback_Timer;

    void Reset()
    {
        InciteChaos = false;
        InciteChaos_Timer = 20000;
        InciteChaosWait_Timer = 15000;
        Charge_Timer = 5000;
        Knockback_Timer = 15000;

        if( pInstance )
            pInstance->SetData(DATA_BLACKHEARTTHEINCITEREVENT, NOT_STARTED);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%3)
        {
            case 0:
                DoYell(SAY_SLAY1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY1);
                break;
            case 1:
                DoYell(SAY_SLAY2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY2);
                break;
            case 2:
                DoYell(SAY_SLAY3, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY3);
                break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);

        if( pInstance )
            pInstance->SetData(DATA_BLACKHEARTTHEINCITEREVENT, DONE);
    }

    void Aggro(Unit *who)
    {
        switch(rand()%3)
        {
            case 0:
                DoYell(SAY_AGGRO1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_AGGRO1);
                break;
            case 1:
                DoYell(SAY_AGGRO2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_AGGRO2);
                break;
            case 2:
                DoYell(SAY_AGGRO3, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_AGGRO3);
                break;
        }

        if( pInstance )
            pInstance->SetData(DATA_BLACKHEARTTHEINCITEREVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if( InciteChaos )
        {
            if( InciteChaosWait_Timer < diff )
            {
                InciteChaos = false;
                InciteChaosWait_Timer = 15000;
            }else InciteChaosWait_Timer -= diff;

            return;
        }

        if( InciteChaos_Timer < diff )
        {
            DoCast(m_creature, SPELL_INCITE_CHAOS);

            std::list<HostilReference *> t_list = m_creature->getThreatManager().getThreatList();
            for( std::list<HostilReference *>::iterator itr = t_list.begin(); itr!= t_list.end(); ++itr )
            {
                Unit* target = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());
                if( target && target->GetTypeId() == TYPEID_PLAYER )
                    target->CastSpell(target,SPELL_INCITE_CHAOS_B,true);
            }

            DoResetThreat();
            InciteChaos = true;
            InciteChaos_Timer = 40000;
            return;
        }else InciteChaos_Timer -= diff;

        //Charge_Timer
        if( Charge_Timer < diff )
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 0) )
                DoCast(target, SPELL_CHARGE);
            Charge_Timer = 25000;
        }else Charge_Timer -= diff;

        //Knockback_Timer
        if( Knockback_Timer < diff )
        {
            DoCast(m_creature, SPELL_WAR_STOMP);
            Knockback_Timer = 20000;
        }else Knockback_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_blackheart_the_inciter(Creature *_Creature)
{
    return new boss_blackheart_the_inciterAI (_Creature);
}

void AddSC_boss_blackheart_the_inciter()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_blackheart_the_inciter";
    newscript->GetAI = GetAI_boss_blackheart_the_inciter;
    m_scripts[nrscripts++] = newscript;
}
