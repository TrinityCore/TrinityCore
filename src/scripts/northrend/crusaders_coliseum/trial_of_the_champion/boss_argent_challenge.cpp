/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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
SDName: Argent Challenge Encounter.
SD%Complete: 90 %
SDComment: Texts are not implemented.
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptedPch.h"
#include "trial_of_the_champion.h"

enum eSpells
{
    //Eadric
    SPELL_EADRIC_ACHIEVEMENT    = 68197,
    SPELL_HAMMER_JUSTICE        = 66863,
    SPELL_HAMMER_RIGHTEOUS      = 66867,
    SPELL_RADIANCE              = 66935,
    SPELL_VENGEANCE             = 66865,

    //Paletress
    SPELL_SMITE                 = 66536,
    SPELL_SMITE_H               = 67674,
    SPELL_HOLY_FIRE             = 66538,
    SPELL_HOLY_FIRE_H           = 67676,
    SPELL_RENEW                 = 66537,
    SPELL_RENEW_H               = 67675,
    SPELL_HOLY_NOVA             = 66546,
    SPELL_SHIELD                = 66515,
    SPELL_CONFESS               = 66680,
    SPELL_SUMMON_MEMORY         = 66545,

    //Memory
    SPELL_OLD_WOUNDS            = 66620,
    SPELL_OLD_WOUNDS_H          = 67679,
    SPELL_SHADOWS_PAST          = 66619,
    SPELL_SHADOWS_PAST_H        = 67678,
    SPELL_WAKING_NIGHTMARE      = 66552,
    SPELL_WAKING_NIGHTMARE_H    = 67677
};

struct TRINITY_DLL_DECL boss_eadricAI : public ScriptedAI
{
    boss_eadricAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint32 uiVenganceTimer;
    uint32 uiRadianceTimer;
    uint32 uiHammerJusticeTimer;

    void Reset()
    {
        uiVenganceTimer = 10000;
        uiRadianceTimer = 16000;
        uiHammerJusticeTimer = 25000;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if (uiHammerJusticeTimer <= uiDiff)
        {
            m_creature->InterruptNonMeleeSpells(true);

            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
            {
                if (pTarget && pTarget->isAlive())
                {
                    DoCast(pTarget, SPELL_HAMMER_JUSTICE);
                    DoCast(pTarget, SPELL_HAMMER_RIGHTEOUS);
                }
            }
            uiHammerJusticeTimer = 25000;
        } else uiHammerJusticeTimer -= uiDiff;

        if (uiVenganceTimer <= uiDiff)
        {
            DoCast(m_creature,SPELL_VENGEANCE);

            uiVenganceTimer = 10000;
        } else uiVenganceTimer -= uiDiff;

        if (uiRadianceTimer <= uiDiff)
        {
            DoCastAOE(SPELL_RADIANCE);

            uiRadianceTimer = 16000;
        } else uiRadianceTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_eadric(Creature* pCreature)
{
    return new boss_eadricAI(pCreature);
}

struct TRINITY_DLL_DECL boss_paletressAI : public ScriptedAI
{
    boss_paletressAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pMemory = NULL;
    }

    ScriptedInstance* pInstance;

    Creature* pMemory;

    bool bHealth;

    uint32 uiHolyFireTimer;
    uint32 uiHolySmiteTimer;
    uint32 uiRenewTimer;

    uint32 uiRandomSpell;

    void Reset()
    {
        m_creature->RemoveAllAuras();

        uiHolyFireTimer     = urand(9000,12000);
        uiHolySmiteTimer    = urand(5000,7000);
        uiRenewTimer        = urand(2000,5000);
        uiRandomSpell       = 0;

        bHealth = false;

        if (pMemory && pMemory->isAlive())
            pMemory->RemoveFromWorld();
    }

    void SetData(uint32 uiId, uint32 uiValue)
    {
        if (uiId == 1)
            m_creature->RemoveAura(SPELL_SHIELD);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if (uiHolyFireTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
            {
                if (pTarget && pTarget->isAlive())
                    DoCast(pTarget,DUNGEON_MODE(SPELL_HOLY_FIRE,SPELL_HOLY_FIRE_H));
            }
             if (m_creature->HasAura(SPELL_SHIELD))
                uiHolyFireTimer = 13000;
            else
                uiHolyFireTimer = urand(9000,12000);
        } else uiHolyFireTimer -= uiDiff;

        if (uiHolySmiteTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
            {
                if (pTarget && pTarget->isAlive())
                    DoCast(pTarget,DUNGEON_MODE(SPELL_SMITE,SPELL_SMITE_H));
            }
            if (m_creature->HasAura(SPELL_SHIELD))
                uiHolySmiteTimer = 9000;
            else
                uiHolySmiteTimer = urand(5000,7000);
        } else uiHolySmiteTimer -= uiDiff;

        if (m_creature->HasAura(SPELL_SHIELD))
            if (uiRenewTimer <= uiDiff)
            {
                m_creature->InterruptNonMeleeSpells(true);
                uint8 uiTarget = urand(0,1);
                switch(uiTarget)
                {
                    case 0:
                        DoCast(m_creature,DUNGEON_MODE(SPELL_RENEW,SPELL_RENEW_H));
                        break;
                    case 1:
                        if (pMemory && pMemory->isAlive())
                            DoCast(pMemory,DUNGEON_MODE(SPELL_RENEW,SPELL_RENEW_H));
                        break;
                }
                uiRenewTimer = urand(15000,17000);
            } else uiRenewTimer -= uiDiff;


        if (!bHealth && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 25)
        {
            m_creature->InterruptNonMeleeSpells(true);
            uiRandomSpell = urand(1,26);
            DoCastAOE(SPELL_HOLY_NOVA,false);
            DoCast(m_creature, SPELL_SHIELD);
            DoCastAOE(SPELL_SUMMON_MEMORY,false);
            DoCastAOE(SPELL_CONFESS,false);

            bHealth = true;
        }

        DoMeleeAttackIfReady();
    }

    void JustSummoned(Creature* pSummon)
    {
        pMemory = pSummon;
    }
};

CreatureAI* GetAI_boss_paletress(Creature* pCreature)
{
    return new boss_paletressAI(pCreature);
}

struct TRINITY_DLL_DECL npc_memoryAI : public ScriptedAI
{
    npc_memoryAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint32 uiOldWoundsTimer;
    uint32 uiShadowPastTimer;
    uint32 uiWakingNightmare;

    void Reset()
    {
        uiOldWoundsTimer = 12000;
        uiShadowPastTimer = 5000;
        uiWakingNightmare = 7000;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if (uiOldWoundsTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
            {
                if (pTarget && pTarget->isAlive())
                    DoCast(pTarget, DUNGEON_MODE(SPELL_OLD_WOUNDS,SPELL_OLD_WOUNDS_H));
            }
            uiOldWoundsTimer = 12000;
        }else uiOldWoundsTimer -= uiDiff;

        if (uiWakingNightmare <= uiDiff)
        {
            DoCast(m_creature, DUNGEON_MODE(SPELL_WAKING_NIGHTMARE,SPELL_WAKING_NIGHTMARE_H));
            uiWakingNightmare = 7000;
        }else uiWakingNightmare -= uiDiff;

        if (uiShadowPastTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
            {
                if (pTarget && pTarget->isAlive())
                    DoCast(pTarget,DUNGEON_MODE(SPELL_SHADOWS_PAST,SPELL_SHADOWS_PAST_H));
            }
            uiShadowPastTimer = 5000;
        }else uiShadowPastTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (m_creature->isSummon())
            if (Unit* pSummoner = CAST_SUM(m_creature)->GetSummoner())
            {
                if (pSummoner && pSummoner->isAlive())
                    CAST_CRE(pSummoner)->AI()->SetData(1,0);
            }
    }
};

CreatureAI* GetAI_npc_memory(Creature* pCreature)
{
    return new npc_memoryAI(pCreature);
}

void AddSC_boss_argent_challenge()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "boss_eadric";
    NewScript->GetAI = &GetAI_boss_eadric;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "boss_paletress";
    NewScript->GetAI = &GetAI_boss_paletress;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "npc_memory";
    NewScript->GetAI = &GetAI_npc_memory;
    NewScript->RegisterSelf();
}
