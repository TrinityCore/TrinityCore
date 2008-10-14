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
SDName: Boss_Void_Reaver
SD%Complete: 100
SDComment:
SDCategory: Tempest Keep, The Eye
EndScriptData */

#include "precompiled.h"
#include "def_the_eye.h"

#define SPELL_POUNDING              34162
#define SPELL_ARCANE_ORB_TRIGGER    34172
#define SPELL_KNOCK_AWAY            11130
#define SPELL_BERSERK               27680

#define SAY_AGGRO               "Alert, you are marked for extermination!"
#define SAY_SLAY1               "Extermination, successful."
#define SAY_SLAY2               "Imbecile life form, no longer functional."
#define SAY_SLAY3               "Threat neutralized."
#define SAY_DEATH               "Systems... shutting... down..."
#define SAY_POUNDING1           "Alternative measure commencing..."
#define SAY_POUNDING2           "Calculating force parameters..."

#define SOUND_AGGRO             11213
#define SOUND_SLAY1             11215
#define SOUND_SLAY2             11216
#define SOUND_SLAY3             11217
#define SOUND_DEATH             11214
#define SOUND_POUNDING1         11218
#define SOUND_POUNDING2         11219

#define CREATURE_ORB_TARGET     19577

struct TRINITY_DLL_DECL boss_void_reaverAI : public ScriptedAI
{
    boss_void_reaverAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;

    uint32 Pounding_Timer;
    uint32 ArcaneOrb_Timer;
    uint32 KnockAway_Timer;
    uint32 Berserk_Timer;

    void Reset()
    {
        Pounding_Timer = 12000;
        ArcaneOrb_Timer = 3000;
        KnockAway_Timer = 30000;
        Berserk_Timer = 600000;

        if(pInstance)
            pInstance->SetData(DATA_VOIDREAVEREVENT, NOT_STARTED);
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

        if(pInstance)
            pInstance->SetData(DATA_VOIDREAVEREVENT, NOT_STARTED);
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);

        if(pInstance)
            pInstance->SetData(DATA_VOIDREAVEREVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        // Pounding
        if(Pounding_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_POUNDING);

            switch(rand()%2)
            {
                case 0:
                    DoPlaySoundToSet(m_creature, SOUND_POUNDING1);
                    DoYell(SAY_POUNDING1, LANG_UNIVERSAL, NULL);
                    break;
                case 1:
                    DoPlaySoundToSet(m_creature, SOUND_POUNDING2);
                    DoYell(SAY_POUNDING2, LANG_UNIVERSAL, NULL);
                    break;
            }
            Pounding_Timer = 12000;
        }else Pounding_Timer -= diff;

        // Arcane Orb
        if(ArcaneOrb_Timer < diff)
        {
            Unit *target;
            std::list<HostilReference *> t_list = m_creature->getThreatManager().getThreatList();
            std::vector<Unit *> target_list;
            for(std::list<HostilReference *>::iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
            {
                target = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());
                                                            //15 yard radius minimum
                if(target && target->GetDistance2d(m_creature) > 15)
                    target_list.push_back(target);
                target = NULL;
            }
            if(target_list.size())
                target = *(target_list.begin()+rand()%target_list.size());

            if (target)
            {
                Unit* Spawn = NULL;
                Spawn = m_creature->SummonCreature(CREATURE_ORB_TARGET, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
                if (Spawn)
                    m_creature->CastSpell(Spawn, SPELL_ARCANE_ORB_TRIGGER, true);
            }

            ArcaneOrb_Timer = 3000;
        }else ArcaneOrb_Timer -= diff;

        // Single Target knock back, reduces aggro
        if(KnockAway_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_KNOCK_AWAY);

            //Drop 25% aggro
            if(m_creature->getThreatManager().getThreat(m_creature->getVictim()))
                m_creature->getThreatManager().modifyThreatPercent(m_creature->getVictim(),-25);

            KnockAway_Timer = 30000;
        }else KnockAway_Timer -= diff;

        //Berserk
        if(Berserk_Timer < diff)
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_creature->InterruptNonMeleeSpells(false);

            DoCast(m_creature,SPELL_BERSERK);
            Berserk_Timer = 600000;
        }else Berserk_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_void_reaver(Creature *_Creature)
{
    return new boss_void_reaverAI (_Creature);
}

void AddSC_boss_void_reaver()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_void_reaver";
    newscript->GetAI = GetAI_boss_void_reaver;
    m_scripts[nrscripts++] = newscript;
}
