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
SDName: Boss_Morogrim_Tidewalker
SD%Complete: 90
SDComment:
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "precompiled.h"
#include "def_serpent_shrine.h"

enum
{
    SAY_AGGRO                       = -1548030,
    SAY_SUMMON1                     = -1548031,
    SAY_SUMMON2                     = -1548032,
    SAY_SUMMON_BUBL1                = -1548033,
    SAY_SUMMON_BUBL2                = -1548034,
    SAY_SLAY1                       = -1548035,
    SAY_SLAY2                       = -1548036,
    SAY_SLAY3                       = -1548037,
    SAY_DEATH                       = -1548038,
    EMOTE_WATERY_GRAVE              = -1548039,
    EMOTE_EARTHQUAKE                = -1548040,
    EMOTE_WATERY_GLOBULES           = -1548041,

    SPELL_TIDAL_WAVE                = 37730,
    SPELL_EARTHQUAKE                = 37764,

    SPELL_WATERY_GRAVE_1            = 37850,
    SPELL_WATERY_GRAVE_2            = 38023,
    SPELL_WATERY_GRAVE_3            = 38024,
    SPELL_WATERY_GRAVE_4            = 38025,

    SPELL_SUMMON_MURLOC_A6          = 39813,
    SPELL_SUMMON_MURLOC_A7          = 39814,
    SPELL_SUMMON_MURLOC_A8          = 39815,
    SPELL_SUMMON_MURLOC_A9          = 39816,
    SPELL_SUMMON_MURLOC_A10         = 39817,

    SPELL_SUMMON_MURLOC_B6          = 39818,
    SPELL_SUMMON_MURLOC_B7          = 39819,
    SPELL_SUMMON_MURLOC_B8          = 39820,
    SPELL_SUMMON_MURLOC_B9          = 39821,
    SPELL_SUMMON_MURLOC_B10         = 39822,

    SPELL_SUMMON_GLOBULE_1          = 37854,
    SPELL_SUMMON_GLOBULE_2          = 37858,
    SPELL_SUMMON_GLOBULE_3          = 37860,
    SPELL_SUMMON_GLOBULE_4          = 37861,

    NPC_WATER_GLOBULE               = 21913,
    NPC_TIDEWALKER_LURKER           = 21920
};

//Morogrim Tidewalker AI
struct TRINITY_DLL_DECL boss_morogrim_tidewalkerAI : public ScriptedAI
{
    boss_morogrim_tidewalkerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
    }

    ScriptedInstance* m_pInstance;                          // the instance

    // timers
    uint32 m_uiTidalWave_Timer;
    uint32 m_uiWateryGrave_Timer;
    uint32 m_uiEarthquake_Timer;
    uint32 m_uiWateryGlobules_Timer;

    bool m_bEarthquake;
    bool m_bPhase2;

    void Reset()
    {
        m_uiTidalWave_Timer      = 10000;
        m_uiWateryGrave_Timer    = 30000;
        m_uiEarthquake_Timer     = 40000;
        m_uiWateryGlobules_Timer = 0;

        m_bEarthquake = false;
        m_bPhase2     = false;

        if (m_pInstance)
            m_pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, NOT_STARTED);
    }

    void KilledUnit(Unit* pVictim)
    {
        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_SLAY1, m_creature); break;
            case 1: DoScriptText(SAY_SLAY2, m_creature); break;
            case 2: DoScriptText(SAY_SLAY3, m_creature); break;
        }
    }

    void JustDied(Unit* pVictim)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, NOT_STARTED);
    }

    void Aggro(Unit* pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, IN_PROGRESS);
    }

    void JustSummoned(Creature* pSummoned)
    {
        if (pSummoned->GetEntry() == NPC_TIDEWALKER_LURKER)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                pSummoned->AI()->AttackStart(pTarget);
        }

        if (pSummoned->GetEntry() == NPC_WATER_GLOBULE)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                pSummoned->GetMotionMaster()->MoveFollow(pTarget, 0.0f, 0.0f);
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //m_uiEarthquake_Timer
        if (m_uiEarthquake_Timer < uiDiff)
        {
            if (!m_bEarthquake)
            {
                DoCast(m_creature->getVictim(), SPELL_EARTHQUAKE);
                m_bEarthquake = true;
                m_uiEarthquake_Timer = 5000;
            }
            else
            {
                DoScriptText(urand(0,1) ? SAY_SUMMON1 : SAY_SUMMON2, m_creature);

                //north
                m_creature->CastSpell(m_creature,SPELL_SUMMON_MURLOC_A6,true);
                m_creature->CastSpell(m_creature,SPELL_SUMMON_MURLOC_A7,true);
                m_creature->CastSpell(m_creature,SPELL_SUMMON_MURLOC_A8,true);
                m_creature->CastSpell(m_creature,SPELL_SUMMON_MURLOC_A9,true);
                m_creature->CastSpell(m_creature,SPELL_SUMMON_MURLOC_A10,true);

                //south
                m_creature->CastSpell(m_creature,SPELL_SUMMON_MURLOC_B6,true);
                m_creature->CastSpell(m_creature,SPELL_SUMMON_MURLOC_B7,true);
                m_creature->CastSpell(m_creature,SPELL_SUMMON_MURLOC_B8,true);
                m_creature->CastSpell(m_creature,SPELL_SUMMON_MURLOC_B9,true);
                m_creature->CastSpell(m_creature,SPELL_SUMMON_MURLOC_B10,true);

                DoScriptText(EMOTE_EARTHQUAKE, m_creature);

                m_bEarthquake = false;
                m_uiEarthquake_Timer = 40000+rand()%5000;
            }
        }else m_uiEarthquake_Timer -= uiDiff;

        //m_uiTidalWave_Timer
        if (m_uiTidalWave_Timer < uiDiff)
        {
            DoCast(m_creature->getVictim(), SPELL_TIDAL_WAVE);
            m_uiTidalWave_Timer = 20000;
        }else m_uiTidalWave_Timer -= uiDiff;

        if (!m_bPhase2)
        {
            //m_uiWateryGrave_Timer
            if (m_uiWateryGrave_Timer < uiDiff)
            {
                //Teleport 4 players under the waterfalls
                for(uint8 i = 0; i < 4; i++)
                {
                    Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1);

                    if (pTarget && pTarget->GetTypeId() == TYPEID_PLAYER && !pTarget->HasAuraType(SPELL_AURA_MOD_STUN) && pTarget->IsWithinDistInMap(m_creature, 45.0f))
                    {
                        switch(i)
                        {
                            case 0: m_creature->CastSpell(pTarget,SPELL_WATERY_GRAVE_1,false); break;
                            case 1: m_creature->CastSpell(pTarget,SPELL_WATERY_GRAVE_2,false); break;
                            case 2: m_creature->CastSpell(pTarget,SPELL_WATERY_GRAVE_3,false); break;
                            case 3: m_creature->CastSpell(pTarget,SPELL_WATERY_GRAVE_4,false); break;
                        }
                    }
                }

                DoScriptText(urand(0,1) ? SAY_SUMMON_BUBL1 : SAY_SUMMON_BUBL2, m_creature);
                DoScriptText(EMOTE_WATERY_GRAVE, m_creature);

                m_uiWateryGrave_Timer = 30000;
            }else m_uiWateryGrave_Timer -= uiDiff;

            //Start Phase2
            if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 25)
                m_bPhase2 = true;
        }
        else
        {
            //m_uiWateryGlobules_Timer
            if (m_uiWateryGlobules_Timer < uiDiff)
            {
                DoScriptText(EMOTE_WATERY_GLOBULES, m_creature);

                m_creature->CastSpell(m_creature,SPELL_SUMMON_GLOBULE_1,true);
                m_creature->CastSpell(m_creature,SPELL_SUMMON_GLOBULE_2,true);
                m_creature->CastSpell(m_creature,SPELL_SUMMON_GLOBULE_3,true);
                m_creature->CastSpell(m_creature,SPELL_SUMMON_GLOBULE_4,false);

                m_uiWateryGlobules_Timer = 25000;
            }else m_uiWateryGlobules_Timer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};

//Water Globule AI
struct TRINITY_DLL_DECL mob_water_globuleAI : public ScriptedAI
{
    mob_water_globuleAI(Creature* c) : ScriptedAI(c) { }

    // timers
    uint32 m_uiCheck_Timer;

    void Reset()
    {
        m_uiCheck_Timer = 1000;
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void Aggro(Unit* pWho) {}

    void MoveInLineOfSight(Unit* pWho)
    {
        if (!pWho || m_creature->getVictim())
            return;

        if (pWho->isTargetableForAttack() && pWho->isInAccessiblePlaceFor(m_creature) && m_creature->IsHostileTo(pWho))
        {
            //no attack radius check - it attacks the first target that moves in his los
            //pWho->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
            AttackStart(pWho);
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (m_uiCheck_Timer < uiDiff)
        {
            if (m_creature->IsWithinDistInMap(m_creature->getVictim(), 5))
            {
                m_creature->DealDamage(m_creature->getVictim(), 4000+rand()%2000, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_FROST, NULL, false);

                //despawn
                m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }
            m_uiCheck_Timer = 500;
        }else m_uiCheck_Timer -= uiDiff;

        //do NOT deal any melee damage to the target.
    }
};

CreatureAI* GetAI_boss_morogrim_tidewalker(Creature* pCreature)
{
    return new boss_morogrim_tidewalkerAI (pCreature);
}
CreatureAI* GetAI_mob_water_globule(Creature* pCreature)
{
    return new mob_water_globuleAI (pCreature);
}

void AddSC_boss_morogrim_tidewalker()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_morogrim_tidewalker";
    newscript->GetAI = &GetAI_boss_morogrim_tidewalker;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_water_globule";
    newscript->GetAI = &GetAI_mob_water_globule;
    newscript->RegisterSelf();
}
