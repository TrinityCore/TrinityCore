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
SDName: Boss_Ormorok
SD%Complete:
SDComment:
SDCategory: The Nexus, The Nexus
EndScriptData */

#include "precompiled.h"
#include "def_nexus.h"

enum
{
//Spells
    SPELL_CRYSTAL_SPIKES_N                     = 47958, //Don't work, using walkaround
    SPELL_CRYSTAL_SPIKES_H                     = 57082, //Don't work, using walkaround
//Walkaround for spells Crystal Spikes -----------------
    SPELL_CRYSTALL_SPIKE_DAMAGE_N              = 47944,
    SPELL_CRYSTALL_SPIKE_DAMAGE_H              = 57067,
    SPELL_CRYSTAL_SPIKE_PREVISUAL              = 50442,
    MOB_CRYSTAL_SPIKE                          = 27099,
//------------------------------------------------------
    SPELL_SPELL_REFLECTION                     = 47981,
    SPELL_TRAMPLE_N                            = 48016,
    SPELL_TRAMPLE_H                            = 57066,
    SPELL_FRENZY                               = 48017,
    SPELL_SUMMON_CRYSTALLINE_TANGLER           = 61564, //summons npc 32665
    MOB_CRYSTALLINE_TANGLER                    = 32665,
    SPELL_ROOTS                                = 28858, //proper spell id is unknown

//Yell
    SAY_AGGRO                               = -1576020,
    SAY_DEATH                               = -1576021,
    SAY_REFLECT                             = -1576022,
    SAY_CRYSTAL_SPIKES                      = -1576023,
    SAY_KILL                                = -1576024
};

#define SPIKE_DISTANCE                            5.0f

struct TRINITY_DLL_DECL boss_ormorokAI : public ScriptedAI
{
    boss_ormorokAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        HeroicMode = c->GetMap()->IsHeroic();
    }

    ScriptedInstance* pInstance;
    bool HeroicMode;
    bool Frenzy;
    bool CrystalSpikes;
    uint8 CrystalSpikes_Count;
    float BaseX;
    float BaseY;
    float BaseZ;
    float BaseO;
    float SpikeXY[4][2];

    uint32 SPELL_CRYSTAL_SPIKES_Timer;
    uint32 CRYSTAL_SPIKES_Timer;
    uint32 SPELL_TRAMPLE_Timer;
    uint32 SPELL_FRENZY_Timer;
    uint32 SPELL_SPELL_REFLECTION_Timer;
    uint32 SPELL_SUMMON_CRYSTALLINE_TANGLER_Timer;

    void Reset()
    {
        SPELL_CRYSTAL_SPIKES_Timer = 12000;
        SPELL_TRAMPLE_Timer = 10000;
        SPELL_SPELL_REFLECTION_Timer = 30000;
        SPELL_SUMMON_CRYSTALLINE_TANGLER_Timer = 17000;
        Frenzy = false;
        CrystalSpikes = false;

        if (pInstance)
            pInstance->SetData(DATA_ORMOROK_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_ORMOROK_EVENT, IN_PROGRESS);
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_ORMOROK_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(SAY_KILL, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
        {
            return;
        }
        if (CrystalSpikes)
            if (CRYSTAL_SPIKES_Timer < diff)
            {
                SpikeXY[0][0] = BaseX+(SPIKE_DISTANCE*CrystalSpikes_Count*cos(BaseO));
                SpikeXY[0][1] = BaseY+(SPIKE_DISTANCE*CrystalSpikes_Count*sin(BaseO));
                SpikeXY[1][0] = BaseX-(SPIKE_DISTANCE*CrystalSpikes_Count*cos(BaseO));
                SpikeXY[1][1] = BaseY-(SPIKE_DISTANCE*CrystalSpikes_Count*sin(BaseO));
                SpikeXY[2][0] = BaseX+(SPIKE_DISTANCE*CrystalSpikes_Count*cos(BaseO-(M_PI/2)));
                SpikeXY[2][1] = BaseY+(SPIKE_DISTANCE*CrystalSpikes_Count*sin(BaseO-(M_PI/2)));
                SpikeXY[3][0] = BaseX-(SPIKE_DISTANCE*CrystalSpikes_Count*cos(BaseO-(M_PI/2)));
                SpikeXY[3][1] = BaseY-(SPIKE_DISTANCE*CrystalSpikes_Count*sin(BaseO-(M_PI/2)));
                for (uint8 i = 0; i < 4; ++i)
                    Creature* Spike = m_creature->SummonCreature(MOB_CRYSTAL_SPIKE, SpikeXY[i][0], SpikeXY[i][1], BaseZ, 0, TEMPSUMMON_TIMED_DESPAWN, 7000);
                if (++CrystalSpikes_Count >= 13)
                    CrystalSpikes = false;
                CRYSTAL_SPIKES_Timer = 200;
            }else CRYSTAL_SPIKES_Timer -= diff;

        if (!Frenzy && (m_creature->GetHealth() < m_creature->GetMaxHealth() * 0.25))
        {
            DoCast(m_creature, SPELL_FRENZY);
            Frenzy = true;
        }

        if (SPELL_TRAMPLE_Timer < diff)
        {
            DoCast(m_creature, HEROIC(SPELL_TRAMPLE_N, SPELL_TRAMPLE_H));
            SPELL_TRAMPLE_Timer = 10000;
        }else SPELL_TRAMPLE_Timer -= diff;

        if (SPELL_SPELL_REFLECTION_Timer < diff)
        {
            DoScriptText(SAY_REFLECT, m_creature);
            DoCast(m_creature, SPELL_SPELL_REFLECTION);
            SPELL_SPELL_REFLECTION_Timer = 30000;
        }else SPELL_SPELL_REFLECTION_Timer -= diff;

        if (SPELL_CRYSTAL_SPIKES_Timer < diff)
        {
            DoScriptText(SAY_CRYSTAL_SPIKES, m_creature);
            CrystalSpikes = true;
            CrystalSpikes_Count = 1;
            CRYSTAL_SPIKES_Timer = 0;
            BaseX = m_creature->GetPositionX();
            BaseY = m_creature->GetPositionY();
            BaseZ = m_creature->GetPositionZ();
            BaseO = m_creature->GetOrientation();
            SPELL_CRYSTAL_SPIKES_Timer = 20000;
        }else SPELL_CRYSTAL_SPIKES_Timer -=diff;

        if (HeroicMode && (SPELL_SUMMON_CRYSTALLINE_TANGLER_Timer < diff))
        {
            Creature* Crystalline_Tangler = m_creature->SummonCreature(MOB_CRYSTALLINE_TANGLER, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000);
            if (Crystalline_Tangler)
            {
                Unit* target = NULL;
                uint8 Healer = 0;
                for (uint8 j = 1; j<=4; j++)
                {
                    switch (j)
                    {
                        case 1: Healer = CLASS_PRIEST; break;
                        case 2: Healer = CLASS_PALADIN; break;
                        case 3: Healer = CLASS_DRUID; break;
                        case 4: Healer = CLASS_SHAMAN; break;
                    }
                    std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin();
                    for (; i != m_creature->getThreatManager().getThreatList().end(); ++i)
                    {
                        Unit* pTemp = Unit::GetUnit((*m_creature),(*i)->getUnitGuid());
                        if (pTemp && pTemp->GetTypeId() == TYPEID_PLAYER && pTemp->getClass() == Healer)
                        {
                            target = pTemp;
                            break;
                        }
                    }
                    if (target)
                        break;
                }
                if (!target)
                    target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                if (target)
                {
                    Crystalline_Tangler->AI()->AttackStart(target);
                    Crystalline_Tangler->getThreatManager().addThreat(target, 1000000000.0f);
                }
            }
            SPELL_SUMMON_CRYSTALLINE_TANGLER_Timer = 17000;
        }else SPELL_SUMMON_CRYSTALLINE_TANGLER_Timer -=diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL mob_crystal_spikeAI : public Scripted_NoMovementAI
{
    mob_crystal_spikeAI(Creature *c) : Scripted_NoMovementAI(c)
    {
        HeroicMode = c->GetMap()->IsHeroic();
    }

    bool HeroicMode;

    uint32 SPELL_CRYSTALL_SPIKE_DAMAGE_Timer;
    uint32 SPELL_CRYSTAL_SPIKE_PREVISUAL_Timer;

    void Reset()
    {
        SPELL_CRYSTALL_SPIKE_DAMAGE_Timer = 3700;
        SPELL_CRYSTAL_SPIKE_PREVISUAL_Timer = 1000;
        m_creature->SetLevel(80);                                        //
        m_creature->setFaction(16);                                      //Walkaround to be independent from data in DB
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE); //
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE); //
    }

    void UpdateAI(const uint32 diff)
    {
        if (SPELL_CRYSTAL_SPIKE_PREVISUAL_Timer < diff)
        {
            DoCast(m_creature, SPELL_CRYSTAL_SPIKE_PREVISUAL);
            SPELL_CRYSTAL_SPIKE_PREVISUAL_Timer = 10000;
        }else SPELL_CRYSTAL_SPIKE_PREVISUAL_Timer -=diff;

        if (SPELL_CRYSTALL_SPIKE_DAMAGE_Timer < diff)
        {
            DoCast(m_creature, HEROIC(SPELL_CRYSTALL_SPIKE_DAMAGE_N, SPELL_CRYSTALL_SPIKE_DAMAGE_H));
            SPELL_CRYSTALL_SPIKE_DAMAGE_Timer = 10000;
        }else SPELL_CRYSTALL_SPIKE_DAMAGE_Timer -=diff;
    }
};

struct TRINITY_DLL_DECL mob_crystalline_tanglerAI : public ScriptedAI
{
    mob_crystalline_tanglerAI(Creature *c) : ScriptedAI(c) {}

    uint32 SPELL_ROOTS_Timer;

    void Reset()
    {
        SPELL_ROOTS_Timer = 1000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (SPELL_ROOTS_Timer < diff)
        {
            if (m_creature->IsWithinDist(m_creature->getVictim(), 5.0f, false))
            {
                DoCast(m_creature->getVictim(), SPELL_ROOTS);
                SPELL_ROOTS_Timer = 15000;
            }
        }else SPELL_ROOTS_Timer -=diff;
    }
};

CreatureAI* GetAI_mob_crystal_spike(Creature* pCreature)
{
    return new mob_crystal_spikeAI (pCreature);
}

CreatureAI* GetAI_mob_crystalline_tangler(Creature* pCreature)
{
    return new mob_crystalline_tanglerAI (pCreature);
}

CreatureAI* GetAI_boss_ormorok(Creature* pCreature)
{
    return new boss_ormorokAI (pCreature);
}

void AddSC_boss_ormorok()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_ormorok";
    newscript->GetAI = &GetAI_boss_ormorok;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_crystal_spike";
    newscript->GetAI = &GetAI_mob_crystal_spike;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_crystalline_tangler";
    newscript->GetAI = &GetAI_mob_crystalline_tangler;
    newscript->RegisterSelf();
}
