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
SDName: Boss_Anomalus
SD%Complete:
SDComment:
SDCategory: The Nexus, The Nexus
EndScriptData */

#include "precompiled.h"
#include "def_nexus.h"

bool DeadChaoticRift; // needed for achievement: Chaos Theory(2037)

enum
{
    ACHIEVEMENT_CHAOS_THEORY   = 2037,

    //Spells
    SPELL_SPARK_N              = 47751,
    SPELL_SPARK_H              = 57062,
    SPELL_RIFT_SHIELD          = 47748,
    SPELL_CHARGE_RIFT          = 47747, //Works wrong (affect players, not rifts)
    SPELL_CREATE_RIFT          = 47743, //Don't work, using WA
    SPELL_ARCANE_ATTRACTION    = 57063, //No idea, when it's used

    MOB_CRAZED_MANA_WRAITH              = 26746,
    MOB_CHAOTIC_RIFT                    = 26918,
    SPELL_CHAOTIC_ENERGY_BURST          = 47688,
    SPELL_CHARGED_CHAOTIC_ENERGY_BURST  = 47737,
    SPELL_ARCANEFORM                    = 48019, //Chaotic Rift visual

    //Yell
    SAY_AGGRO               = -1576010,
    SAY_DEATH               = -1576011,
    SAY_RIFT                = -1576012,
    SAY_SHIELD              = -1576013
};

float RiftLocation[6][3]=
{
    {652.64, -273.70, -8.75},
    {634.45, -265.94, -8.44},
    {620.73, -281.17, -9.02},
    {626.10, -304.67, -9.44},
    {639.87, -314.11, -9.49},
    {651.72, -297.44, -9.37}
};

struct TRINITY_DLL_DECL boss_anomalusAI : public ScriptedAI
{
    boss_anomalusAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        HeroicMode = c->GetMap()->IsHeroic();
    }

    ScriptedInstance* pInstance;
    bool HeroicMode;

    uint8 Phase;
    uint32 SPELL_SPARK_Timer;
    uint32 SPELL_CREATE_RIFT_Timer;
    uint64 ChaoticRiftGUID;

    void Reset()
    {
        Phase = 0;
        SPELL_SPARK_Timer = 5000;
        SPELL_CREATE_RIFT_Timer = 25000;
        ChaoticRiftGUID = 0;

        DeadChaoticRift = false;

        if (pInstance)
            pInstance->SetData(DATA_ANOMALUS_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_ANOMALUS_EVENT, IN_PROGRESS);
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (HeroicMode && !DeadChaoticRift)
        {
            AchievementEntry const *AchievChaosTheory = GetAchievementStore()->LookupEntry(ACHIEVEMENT_CHAOS_THEORY);
            if (AchievChaosTheory)
            {
                Map* pMap = m_creature->GetMap();
                if (pMap && pMap->IsDungeon())
                {
                    Map::PlayerList const &players = pMap->GetPlayers();
                    for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        itr->getSource()->CompletedAchievement(AchievChaosTheory);
                }
            }
        }

        if (pInstance)
            pInstance->SetData(DATA_ANOMALUS_EVENT, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (m_creature->HasAura(SPELL_RIFT_SHIELD))
        {
            if (ChaoticRiftGUID)
            {
                Unit* Rift = Unit::GetUnit((*m_creature), ChaoticRiftGUID);
                if (Rift && Rift->isDead())
                {
                    m_creature->RemoveAurasDueToSpell(SPELL_RIFT_SHIELD);
                    ChaoticRiftGUID = 0;
                }
                return;
            }
        } else
            ChaoticRiftGUID = 0;

        if ((Phase == 0) && (m_creature->GetHealth() < m_creature->GetMaxHealth() * 0.75))
        {
            Phase = 1;
            DoScriptText(SAY_SHIELD, m_creature);
            DoCast(m_creature, SPELL_RIFT_SHIELD);

            int tmp = rand()%(2);
            Creature* Rift = m_creature->SummonCreature(MOB_CHAOTIC_RIFT, RiftLocation[tmp][0], RiftLocation[tmp][1], RiftLocation[tmp][2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000);
            if (Rift)
            {
                //DoCast(Rift, SPELL_CHARGE_RIFT);
                if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    Rift->AI()->AttackStart(target);
                ChaoticRiftGUID = Rift->GetGUID();
                DoScriptText(SAY_RIFT , m_creature);
            }
        }

        if ((Phase == 1) && (m_creature->GetHealth() < m_creature->GetMaxHealth() * 0.50))
        {
            Phase = 2;
            DoScriptText(SAY_SHIELD , m_creature);
            DoCast(m_creature,SPELL_RIFT_SHIELD);

            int tmp = rand()%(2);
            Creature* Rift = m_creature->SummonCreature(MOB_CHAOTIC_RIFT, RiftLocation[tmp][0], RiftLocation[tmp][1], RiftLocation[tmp][2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000);
            if (Rift)
            {
                //DoCast(Rift, SPELL_CHARGE_RIFT);
                if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    Rift->AI()->AttackStart(target);
                ChaoticRiftGUID = Rift->GetGUID();
                DoScriptText(SAY_RIFT , m_creature);
            }
        }

        if ((Phase == 2) && (m_creature->GetHealth() < m_creature->GetMaxHealth() * 0.25))
        {
            Phase = 3;
            DoScriptText(SAY_SHIELD , m_creature);
            DoCast(m_creature,SPELL_RIFT_SHIELD);

            int tmp = rand()%(2);
            Creature* Rift = m_creature->SummonCreature(MOB_CHAOTIC_RIFT, RiftLocation[tmp][0], RiftLocation[tmp][1], RiftLocation[tmp][2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000);
            if (Rift)
            {
                //DoCast(Rift, SPELL_CHARGE_RIFT);
                if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    Rift->AI()->AttackStart(target);
                ChaoticRiftGUID = Rift->GetGUID();
                DoScriptText(SAY_RIFT , m_creature);
            }
        }

        if (SPELL_SPARK_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(target, HeroicMode ? SPELL_SPARK_H : SPELL_SPARK_N);
            SPELL_SPARK_Timer = 5000;
        }else SPELL_SPARK_Timer -=diff;

        if (SPELL_CREATE_RIFT_Timer < diff)
        {
            DoScriptText(SAY_RIFT , m_creature);

            int tmp = rand()%(2);
            Creature* Rift = m_creature->SummonCreature(MOB_CHAOTIC_RIFT, RiftLocation[tmp][0], RiftLocation[tmp][1], RiftLocation[tmp][2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000);
            if (Rift)
                if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    Rift->AI()->AttackStart(target);
            SPELL_CREATE_RIFT_Timer = 25000;
        }else SPELL_CREATE_RIFT_Timer -=diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_anomalus(Creature* pCreature)
{
    return new boss_anomalusAI (pCreature);
}

struct TRINITY_DLL_DECL mob_chaotic_riftAI : public Scripted_NoMovementAI
{
    mob_chaotic_riftAI(Creature *c) : Scripted_NoMovementAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 SPELL_CHAOTIC_ENERGY_BURST_Timer;
    uint32 SUMMON_CRAZED_MANA_WRAITH_Timer;

    void Reset()
    {
        SPELL_CHAOTIC_ENERGY_BURST_Timer = 1000;
        SUMMON_CRAZED_MANA_WRAITH_Timer = 5000;
        m_creature->SetDisplayId(25206); //For some reason in DB models for ally and horde are different.
                                         //Model for ally (1126) does not show auras. Horde model works perfect.
                                         //Set model to horde number
        DoCast(m_creature, SPELL_ARCANEFORM, false);
    }

    void JustDied(Unit *killer)
    {
        DeadChaoticRift = true;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (SPELL_CHAOTIC_ENERGY_BURST_Timer < diff)
        {
            Unit* Anomalus = Unit::GetUnit(*m_creature, pInstance ? pInstance->GetData64(DATA_ANOMALUS) : 0);
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                if (Anomalus && Anomalus->HasAura(SPELL_RIFT_SHIELD))
                    DoCast(target, SPELL_CHARGED_CHAOTIC_ENERGY_BURST);
                else
                    DoCast(target, SPELL_CHAOTIC_ENERGY_BURST);
            SPELL_CHAOTIC_ENERGY_BURST_Timer = 1000;
        }else SPELL_CHAOTIC_ENERGY_BURST_Timer -=diff;

        if (SUMMON_CRAZED_MANA_WRAITH_Timer < diff)
        {
            Creature* Wraith = m_creature->SummonCreature(MOB_CRAZED_MANA_WRAITH, m_creature->GetPositionX()+1, m_creature->GetPositionY()+1, m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000);
            if (Wraith)
                if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    Wraith->AI()->AttackStart(target);
            Unit* Anomalus = Unit::GetUnit(*m_creature, pInstance ? pInstance->GetData64(DATA_ANOMALUS) : 0);
            if (Anomalus && Anomalus->HasAura(SPELL_RIFT_SHIELD))
                SUMMON_CRAZED_MANA_WRAITH_Timer = 5000;
            else
                SUMMON_CRAZED_MANA_WRAITH_Timer = 10000;
        }else SUMMON_CRAZED_MANA_WRAITH_Timer -=diff;
    }
};

CreatureAI* GetAI_mob_chaotic_rift(Creature* pCreature)
{
    return new mob_chaotic_riftAI (pCreature);
}

void AddSC_boss_anomalus()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_anomalus";
    newscript->GetAI = &GetAI_boss_anomalus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_chaotic_rift";
    newscript->GetAI = &GetAI_mob_chaotic_rift;
    newscript->RegisterSelf();
}
