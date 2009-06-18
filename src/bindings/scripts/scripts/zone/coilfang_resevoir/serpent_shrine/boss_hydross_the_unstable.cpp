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
SDName: Boss_Hydross_The_Unstable
SD%Complete: 90
SDComment: Some details and adjustments left to do, probably nothing major. Spawns may be spawned in different way/location. code cleanup needed
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "precompiled.h"
#include "def_serpent_shrine.h"

enum
{
    SAY_AGGRO                   = -1548000,
    SAY_SWITCH_TO_CLEAN         = -1548001,
    SAY_CLEAN_SLAY1             = -1548002,
    SAY_CLEAN_SLAY2             = -1548003,
    SAY_CLEAN_DEATH             = -1548004,
    SAY_SWITCH_TO_CORRUPT       = -1548005,
    SAY_CORRUPT_SLAY1           = -1548006,
    SAY_CORRUPT_SLAY2           = -1548007,
    SAY_CORRUPT_DEATH           = -1548008,

    SWITCH_RADIUS               = 18,

    MODEL_CORRUPT               = 20609,
    MODEL_CLEAN                 = 20162,

    SPELL_WATER_TOMB            = 38235,
    SPELL_MARK_OF_HYDROSS1      = 38215,
    SPELL_MARK_OF_HYDROSS2      = 38216,
    SPELL_MARK_OF_HYDROSS3      = 38217,
    SPELL_MARK_OF_HYDROSS4      = 38218,
    SPELL_MARK_OF_HYDROSS5      = 38231,
    SPELL_MARK_OF_HYDROSS6      = 40584,
    SPELL_MARK_OF_CORRUPTION1   = 38219,
    SPELL_MARK_OF_CORRUPTION2   = 38220,
    SPELL_MARK_OF_CORRUPTION3   = 38221,
    SPELL_MARK_OF_CORRUPTION4   = 38222,
    SPELL_MARK_OF_CORRUPTION5   = 38230,
    SPELL_MARK_OF_CORRUPTION6   = 40583,
    SPELL_VILE_SLUDGE           = 38246,
    SPELL_ENRAGE                = 27680,                    //this spell need verification
    SPELL_SUMMON_WATER_ELEMENT  = 36459,                    //not in use yet(in use ever?)
    SPELL_ELEMENTAL_SPAWNIN     = 25035,
    SPELL_BLUE_BEAM             = 38015,                    //channeled Hydross Beam Helper (not in use yet)

    NPC_PURE_SPAWN              = 22035,
    NPC_TAINTED_SPAWN           = 22036
};

const float afSpawnDiffs[4][2] =
{
    {6.934003f  , -11.255012f},                             // diff 1
    {-6.934003f , 11.255012f },                             // diff 2
    {-12.577011f, -4.72702f  },                             // diff 3
    {12.577011f , 4.72702f   }                              // diff 4
};

struct TRINITY_DLL_DECL boss_hydross_the_unstableAI : public ScriptedAI
{
    boss_hydross_the_unstableAI(Creature *c) : ScriptedAI(c)
    {
        m_pInstance = c->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;                          // the instance

    uint32 m_uiPosCheck_Timer;
    uint32 m_uiMarkOfHydross_Timer;
    uint32 m_uiMarkOfCorruption_Timer;
    uint32 m_uiWaterTomb_Timer;
    uint32 m_uiVileSludge_Timer;
    uint32 m_uiMarkOfHydross_Count;
    uint32 m_uiMarkOfCorruption_Count;
    uint32 m_uiEnrageTimer;
    bool   m_bCorruptedForm;

    void Reset()
    {
        m_uiPosCheck_Timer          = 2500;
        m_uiMarkOfHydross_Timer     = 15000;
        m_uiMarkOfCorruption_Timer  = 15000;
        m_uiWaterTomb_Timer         = 7000;
        m_uiVileSludge_Timer        = 7000;
        m_uiMarkOfHydross_Count     = 0;
        m_uiMarkOfCorruption_Count  = 0;
        m_uiEnrageTimer             = 600000;

        m_bCorruptedForm = false;

        m_creature->SetMeleeDamageSchool(SPELL_SCHOOL_FROST);
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, false);

        m_creature->SetDisplayId(MODEL_CLEAN);

        if (m_pInstance)
            m_pInstance->SetData(DATA_HYDROSSTHEUNSTABLEEVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(DATA_HYDROSSTHEUNSTABLEEVENT, IN_PROGRESS);
    }

    void KilledUnit(Unit* pVictim)
    {
        if (m_bCorruptedForm)
            DoScriptText(urand(0,1) ? SAY_CORRUPT_SLAY1 : SAY_CORRUPT_SLAY2, m_creature);
        else
            DoScriptText(urand(0,1) ? SAY_CLEAN_SLAY1 : SAY_CLEAN_SLAY2, m_creature);
    }

    void JustSummoned(Creature* pSummoned)
    {
        if (pSummoned->GetEntry() == NPC_PURE_SPAWN)
            pSummoned->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
        else if (pSummoned->GetEntry() == NPC_TAINTED_SPAWN)
            pSummoned->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);

        pSummoned->CastSpell(pSummoned, SPELL_ELEMENTAL_SPAWNIN, true);
    }

    void JustDied(Unit* pVictim)
    {
        DoScriptText(m_bCorruptedForm ? SAY_CORRUPT_DEATH : SAY_CLEAN_DEATH, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(DATA_HYDROSSTHEUNSTABLEEVENT, NOT_STARTED);
    }

    void SpawnAdds()
    {
        for(uint8 i = 0; i < 4; ++i)
            DoSpawnCreature(m_bCorruptedForm ? NPC_TAINTED_SPAWN : NPC_PURE_SPAWN,
                afSpawnDiffs[i][0], afSpawnDiffs[i][1], 0.0f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);

    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        // corrupted form
        if (m_bCorruptedForm)
        {
            //MarkOfCorruption_Timer
            if (m_uiMarkOfCorruption_Timer < uiDiff)
            {
                if (m_uiMarkOfCorruption_Count <= 5)
                {
                    uint32 uiMarkSpell = 0;

                    switch(m_uiMarkOfCorruption_Count)
                    {
                        case 0: uiMarkSpell = SPELL_MARK_OF_CORRUPTION1; break;
                        case 1: uiMarkSpell = SPELL_MARK_OF_CORRUPTION2; break;
                        case 2: uiMarkSpell = SPELL_MARK_OF_CORRUPTION3; break;
                        case 3: uiMarkSpell = SPELL_MARK_OF_CORRUPTION4; break;
                        case 4: uiMarkSpell = SPELL_MARK_OF_CORRUPTION5; break;
                        case 5: uiMarkSpell = SPELL_MARK_OF_CORRUPTION6; break;
                    }

                    DoCast(m_creature->getVictim(), uiMarkSpell);

                    if (m_uiMarkOfCorruption_Count < 5)
                        ++m_uiMarkOfCorruption_Count;
                }

                m_uiMarkOfCorruption_Timer = 15000;
            }else m_uiMarkOfCorruption_Timer -= uiDiff;

            //VileSludge_Timer
            if (m_uiVileSludge_Timer < uiDiff)
            {
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_VILE_SLUDGE);

                m_uiVileSludge_Timer = 15000;
            }else m_uiVileSludge_Timer -= uiDiff;

            //PosCheck_Timer
            if (m_uiPosCheck_Timer < uiDiff)
            {
                float fPosX, fPosY, fPosZ, fPosO;
                m_creature->GetHomePosition(fPosX, fPosY, fPosZ, fPosO);

                if (m_creature->GetDistance2d(fPosX, fPosY) < SWITCH_RADIUS)
                {
                    DoScriptText(SAY_SWITCH_TO_CLEAN, m_creature);

                    // switch to clean form
                    m_creature->SetDisplayId(MODEL_CLEAN);
                    m_uiMarkOfHydross_Count = 0;
                    DoResetThreat();

                    // spawn 4 adds
                    SpawnAdds();

                    m_creature->SetMeleeDamageSchool(SPELL_SCHOOL_FROST);
                    m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
                    m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, false);

                    m_bCorruptedForm = false;
                }

                m_uiPosCheck_Timer = 2500;
            }else m_uiPosCheck_Timer -=uiDiff;
        }
        // clean form
        else
        {
            //MarkOfHydross_Timer
            if (m_uiMarkOfHydross_Timer < uiDiff)
            {
                if (m_uiMarkOfHydross_Count <= 5)
                {
                    uint32 uiMarkSpell;

                    switch(m_uiMarkOfHydross_Count)
                    {
                        case 0: uiMarkSpell = SPELL_MARK_OF_HYDROSS1; break;
                        case 1: uiMarkSpell = SPELL_MARK_OF_HYDROSS2; break;
                        case 2: uiMarkSpell = SPELL_MARK_OF_HYDROSS3; break;
                        case 3: uiMarkSpell = SPELL_MARK_OF_HYDROSS4; break;
                        case 4: uiMarkSpell = SPELL_MARK_OF_HYDROSS5; break;
                        case 5: uiMarkSpell = SPELL_MARK_OF_HYDROSS6; break;
                    }

                    DoCast(m_creature->getVictim(), uiMarkSpell);

                    if (m_uiMarkOfHydross_Count < 5)
                        ++m_uiMarkOfHydross_Count;
                }

                m_uiMarkOfHydross_Timer = 15000;
            }else m_uiMarkOfHydross_Timer -= uiDiff;

            //WaterTomb_Timer
            if (m_uiWaterTomb_Timer < uiDiff)
            {
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_WATER_TOMB);

                m_uiWaterTomb_Timer = 7000;
            }else m_uiWaterTomb_Timer -= uiDiff;

            //PosCheck_Timer
            if (m_uiPosCheck_Timer < uiDiff)
            {
                float fPosX, fPosY, fPosZ, fPosO;
                m_creature->GetHomePosition(fPosX, fPosY, fPosZ, fPosO);

                if (m_creature->GetDistance2d(fPosX, fPosY) >= SWITCH_RADIUS)
                {
                    DoScriptText(SAY_SWITCH_TO_CORRUPT, m_creature);

                    // switch to corrupted form
                    m_creature->SetDisplayId(MODEL_CORRUPT);
                    m_uiMarkOfCorruption_Count = 0;
                    DoResetThreat();

                    // spawn 4 adds
                    SpawnAdds();

                    m_creature->SetMeleeDamageSchool(SPELL_SCHOOL_NATURE);
                    m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);
                    m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, false);

                    m_bCorruptedForm = true;
                }

                m_uiPosCheck_Timer = 2500;
            }else m_uiPosCheck_Timer -=uiDiff;
        }

        //EnrageTimer
        if (m_uiEnrageTimer < uiDiff)
        {
            DoCast(m_creature, SPELL_ENRAGE);
            m_uiEnrageTimer = 60000;
        }else m_uiEnrageTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_hydross_the_unstable(Creature* pCreature)
{
    return new boss_hydross_the_unstableAI(pCreature);
}

void AddSC_boss_hydross_the_unstable()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_hydross_the_unstable";
    newscript->GetAI = &GetAI_boss_hydross_the_unstable;
    newscript->RegisterSelf();
}
