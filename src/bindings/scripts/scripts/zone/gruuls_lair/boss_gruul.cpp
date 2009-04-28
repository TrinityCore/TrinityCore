/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Gruul
SD%Complete: 25
SDComment: Ground Slam seriously messed up due to core problem
SDCategory: Gruul's Lair
EndScriptData */

#include "precompiled.h"
#include "def_gruuls_lair.h"

#define SAY_AGGRO                   -1565010
#define SAY_SLAM1                   -1565011
#define SAY_SLAM2                   -1565012
#define SAY_SHATTER1                -1565013
#define SAY_SHATTER2                -1565014
#define SAY_SLAY1                   -1565015
#define SAY_SLAY2                   -1565016
#define SAY_SLAY3                   -1565017
#define SAY_DEATH                   -1565018
#define EMOTE_GROW                  -1565019

#define SPELL_GROWTH                36300
#define SPELL_CAVE_IN               36240
#define SPELL_GROUND_SLAM           33525                   //AoE Ground Slam applying Ground Slam to everyone with a script effect (most likely the knock back, we can code it to a set knockback)
#define SPELL_REVERBERATION         36297                   //AoE Silence
#define SPELL_SHATTER               33654

#define SPELL_SHATTER_EFFECT        33671
#define SPELL_HURTFUL_STRIKE        33813
#define SPELL_STONED                33652                   //Spell is self cast
#define SPELL_MAGNETIC_PULL         28337
#define SPELL_KNOCK_BACK            24199                   //Knockback spell until correct implementation is made

#define SPELL_GRONN_LORDS_GRASP     33572                   //Triggered by Ground Slam

struct TRINITY_DLL_DECL boss_gruulAI : public ScriptedAI
{
    boss_gruulAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance *pInstance;

    uint32 Growth_Timer;
    uint32 CaveIn_Timer;
    uint32 CaveIn_StaticTimer;
    uint32 GroundSlamTimer;
    uint32 GroundSlamStage;
    uint32 PerformingGroundSlam;
    uint32 HurtfulStrike_Timer;
    uint32 Reverberation_Timer;

    void Reset()
    {
        Growth_Timer= 30000;
        CaveIn_Timer= 27000;
        CaveIn_StaticTimer = 30000;
        GroundSlamTimer= 35000;
        GroundSlamStage= 0;
        PerformingGroundSlam= false;
        HurtfulStrike_Timer= 8000;
        Reverberation_Timer= 60000+45000;

        if (pInstance)
            pInstance->SetData(DATA_GRUULEVENT, NOT_STARTED);

        m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_GRUULEVENT, IN_PROGRESS);
    }

    void KilledUnit()
    {
        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_SLAY1, m_creature); break;
            case 1: DoScriptText(SAY_SLAY2, m_creature); break;
            case 2: DoScriptText(SAY_SLAY3, m_creature); break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if(pInstance)
        {
            pInstance->SetData(DATA_GRUULEVENT, DONE);

            GameObject* EncounterDoor = GameObject::GetGameObject((*m_creature), pInstance->GetData64(DATA_GRUULDOOR));
            if (EncounterDoor)
                EncounterDoor->SetGoState(GO_STATE_ACTIVE);                   // Open the encounter door
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim() )
            return;

        // Growth
        // Gruul can cast this spell up to 30 times
        if (Growth_Timer < diff)
        {
            DoScriptText(EMOTE_GROW, m_creature);
            DoCast(m_creature,SPELL_GROWTH);
            Growth_Timer = 30000;
        }else Growth_Timer -= diff;

        if (PerformingGroundSlam)
        {
            if (GroundSlamTimer < diff)
            {
                switch(GroundSlamStage)
                {
                    case 0:
                    {
                        //Begin the whole ordeal
                        std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();

                        std::vector<Unit*> knockback_targets;

                        //First limit the list to only players
                        for(std::list<HostilReference*>::iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
                        {
                            Unit *target = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());

                            if (target && target->GetTypeId() == TYPEID_PLAYER)
                                knockback_targets.push_back(target);
                        }

                        //Now to totally disoriend those players
                        for(std::vector<Unit*>::iterator itr = knockback_targets.begin(); itr!= knockback_targets.end(); ++itr)
                        {
                            Unit *target = *itr;
                            Unit *target2 = *(knockback_targets.begin() + rand()%knockback_targets.size());

                            if (target && target2)
                            {
                                switch(rand()%2)
                                {
                                    case 0: target2->CastSpell(target, SPELL_MAGNETIC_PULL, true, NULL, NULL, m_creature->GetGUID()); break;
                                    case 1: target2->CastSpell(target, SPELL_KNOCK_BACK, true, NULL, NULL, m_creature->GetGUID()); break;
                                }
                            }
                        }

                        GroundSlamTimer = 7000;
                        break;
                    }

                    case 1:
                    {
                        //Players are going to get stoned
                        std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();

                        for(std::list<HostilReference*>::iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
                        {
                            Unit *target = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());

                            if(target)
                            {
                                target->RemoveAurasDueToSpell(SPELL_GRONN_LORDS_GRASP);
                                target->CastSpell(target, SPELL_STONED, true, NULL, NULL, m_creature->GetGUID());
                            }
                        }

                        GroundSlamTimer = 5000;
                        break;
                    }

                    case 2:
                    {
                        //The dummy shatter spell is cast
                        DoCast(m_creature, SPELL_SHATTER);
                        GroundSlamTimer = 1000;
                        break;
                    }

                    case 3:
                    {
                        //Shatter takes effect
                        std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();

                        for(std::list<HostilReference*>::iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
                        {
                            Unit *target = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());

                            if(target)
                            {
                                target->RemoveAurasDueToSpell(SPELL_STONED);

                                if(target->GetTypeId() == TYPEID_PLAYER)
                                    target->CastSpell(target, SPELL_SHATTER_EFFECT, false, NULL, NULL, m_creature->GetGUID());
                            }

                        }

                        m_creature->GetMotionMaster()->Clear();

                        Unit *victim = m_creature->getVictim();
                        if (victim)
                        {
                            m_creature->GetMotionMaster()->MoveChase(victim);
                            m_creature->SetUInt64Value(UNIT_FIELD_TARGET, victim->GetGUID());
                        }

                        PerformingGroundSlam = false;
                        GroundSlamTimer =120000;
                        HurtfulStrike_Timer= 8000;

                        if (Reverberation_Timer < 10000)     //Give a little time to the players to undo the damage from shatter
                            Reverberation_Timer += 10000;

                        break;
                    }
                }

                GroundSlamStage++;
            }
            else
                GroundSlamTimer-=diff;
        }
        else
        {
            // Hurtful Strike
            if (HurtfulStrike_Timer < diff)
            {
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_TOPAGGRO,1);

                if (target && m_creature->IsWithinMeleeRange(m_creature->getVictim()))
                    DoCast(target,SPELL_HURTFUL_STRIKE);
                else
                    DoCast(m_creature->getVictim(),SPELL_HURTFUL_STRIKE);

                HurtfulStrike_Timer= 8000;
            }else HurtfulStrike_Timer -= diff;

            // Reverberation
            if (Reverberation_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_REVERBERATION, true);
                Reverberation_Timer = 15000 + rand()%10000;
            }else Reverberation_Timer -= diff;

            // Cave In
            if (CaveIn_Timer < diff)
            {
                if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                    DoCast(target,SPELL_CAVE_IN);

                if(CaveIn_StaticTimer >= 4000)
                    CaveIn_StaticTimer -= 2000;

                    CaveIn_Timer = CaveIn_StaticTimer;

            }else CaveIn_Timer -= diff;

            // Ground Slam, Gronn Lord's Grasp, Stoned, Shatter
            if (GroundSlamTimer < diff)
            {
                m_creature->GetMotionMaster()->Clear();
                m_creature->GetMotionMaster()->MoveIdle();
                m_creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);

                PerformingGroundSlam= true;
                GroundSlamTimer = 0;
                GroundSlamStage = 0;
                DoCast(m_creature->getVictim(), SPELL_GROUND_SLAM);
            } else GroundSlamTimer -=diff;

            DoMeleeAttackIfReady();
        }
    }
};

CreatureAI* GetAI_boss_gruul(Creature *_Creature)
{
    return new boss_gruulAI (_Creature);
}

void AddSC_boss_gruul()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_gruul";
    newscript->GetAI = &GetAI_boss_gruul;
    newscript->RegisterSelf();
}

