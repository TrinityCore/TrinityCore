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
SDName: Boss_Marli
SD%Complete: 100
SDComment: Vilebranch Speaker respawned when wipe?
SDCategory: Zul'Gurub
EndScriptData */

#include "scriptPCH.h"
#include "zulgurub.h"

enum
{
    GO_EGG                      = 179985,

    // the spider
    NPC_SPAWN_OF_MARLI          = 15041,

    SAY_AGGRO                   = -1309005,
    SAY_TRANSFORM               = -1309006,
    SAY_SPIDER_SPAWN            = -1309007,
    SAY_DEATH                   = -1309008,

    SPELL_CHARGE                = 22911,
    SPELL_ENVELOPINGWEBS        = 24110,
    SPELL_POISONVOLLEY          = 24099,
    SPELL_SPIDER_FORM           = 24084,
    SPELL_DRAIN_LIFE            = 24300,
    SPELL_CORROSIVE_POISON      = 24111,
    SPELL_TRANSFORM_BACK        = 24085,
    SPELL_TRASH                 = 3391,
    SPELL_HATCH                 = 24083,                    //visual
    SPELL_AGGRANDIR             = 24109,

    //The Spider Spells
    SPELL_LEVELUP               = 24312                     //visual
};

struct boss_marliAI : public ScriptedAI
{
    boss_marliAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_uiDefaultModel = m_creature->GetDisplayId();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiPoisonVolley_Timer;
    uint32 m_uiSpawnSpider_Timer;
    uint32 m_uiCharge_Timer;
    uint32 m_uiAspect_Timer;
    uint32 m_uiTransformBack_Timer;
    uint32 m_uiDrainLife_Timer;
    uint32 m_uiCorrosivePoison_Timer;
    uint32 m_uiWebs_Timer;
    uint32 m_uiTrash_Timer;
    uint32 m_uiAggrandir_Timer;

    bool m_bFirstSpidersAreSpawned;
    bool m_bIsInPhaseTwo;
    bool m_bHasWebbed;

    uint32 m_uiDefaultModel;

    void Reset() override
    {
        m_uiPoisonVolley_Timer = 15000;
        m_uiSpawnSpider_Timer = 20000;
        m_uiAspect_Timer = 12000;
        m_uiTransformBack_Timer = 35000;
        m_uiDrainLife_Timer = 30000;
        m_uiCorrosivePoison_Timer = 1000;
        m_uiWebs_Timer = 5000;
        m_uiTrash_Timer = 5000;
        m_uiAggrandir_Timer = 0;

        m_bFirstSpidersAreSpawned = false;
        m_bIsInPhaseTwo = false;
        m_bHasWebbed = false;

        if (m_pInstance)
            if (m_pInstance->GetData(TYPE_MARLI) != DONE)
                m_pInstance->SetData(TYPE_MARLI, NOT_STARTED);

        std::list<GameObject*> lSpiderEggs;
        GetGameObjectListWithEntryInGrid(lSpiderEggs, m_creature, GO_EGG, DEFAULT_VISIBILITY_INSTANCE);
        if (lSpiderEggs.empty())
            sLog.outDebug("boss_marli, no Eggs with the entry %u were found", GO_EGG);
        else
        {
            for (const auto& pGo : lSpiderEggs)
            {
                if (pGo->GetGoState() == GO_STATE_ACTIVE)
                    pGo->SetGoState(GO_STATE_READY);
            }
        }

        // World of Warcraft Client Patch 1.8.0 (2005-10-11)
        // - High Priestess Mar'li will now despawn her summoned spiders when 
        //   she returns from combat.
        if (sWorld.GetWowPatch() >= WOW_PATCH_108)
        {
            std::list<Creature*> lSummonedSpiders;
            GetCreatureListWithEntryInGrid(lSummonedSpiders, m_creature, NPC_SPAWN_OF_MARLI, DEFAULT_VISIBILITY_INSTANCE);
            for (const auto& pSpider : lSummonedSpiders)
            {
                if (pSpider->IsTemporarySummon())
                    static_cast<TemporarySummon*>(pSpider)->UnSummon();
            }
        }

        // Annule les changements de buffs de transition de phases.
        m_creature->ResetStats();
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (m_pInstance)
            if (m_pInstance->GetData(TYPE_MARLI) != IN_PROGRESS)
                m_pInstance->SetData(TYPE_MARLI, IN_PROGRESS);

        if (!m_bFirstSpidersAreSpawned)
        {
            DoScriptText(SAY_SPIDER_SPAWN, m_creature);
            DoCastSpellIfCan(m_creature, SPELL_HATCH);

            for (uint8 i = 0; i < 4 ; ++i)
            {
                if (GameObject *pEgg = SelectNextEgg())
                {
                    pEgg->SetGoState(GO_STATE_ACTIVE);
                    m_creature->SummonCreature(NPC_SPAWN_OF_MARLI, pEgg->GetPositionX(), pEgg->GetPositionY(), pEgg->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                }
            }

            m_bFirstSpidersAreSpawned = true;
        }
    }

    GameObject* SelectNextEgg()
    {
        std::list<GameObject*> lEggs;
        GetGameObjectListWithEntryInGrid(lEggs, m_creature, GO_EGG, DEFAULT_VISIBILITY_INSTANCE);
        if (lEggs.empty())
            sLog.outDebug("boss_marli, no Eggs with the entry %i were found", GO_EGG);
        else
        {
            lEggs.sort(ObjectDistanceOrder(m_creature));
            for (const auto& pEgg : lEggs)
            {
                if (pEgg->GetGoState() == (GO_STATE_READY))
                    return pEgg;
            }
        }
        return nullptr;
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_SPAWN_OF_MARLI)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                pSummoned->AI()->AttackStart(pTarget);
        }
    }

    void JustDied(Unit* pKiller) override
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_MARLI, DONE);

        // Remove a Hakkar Power stack.
        m_creature->CastSpell(m_creature, SPELL_HAKKAR_POWER_DOWN, true);
    }

    void SpellHitTarget(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (!pCaster)
            return;

        if (pSpell->Id == SPELL_ENVELOPINGWEBS)
        {
            if (pCaster->GetTypeId() != TYPEID_PLAYER)
                return;

            m_creature->GetThreatManager().modifyThreatPercent(pCaster, -100);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Troll
        if (!m_bIsInPhaseTwo)
        {
            if (m_uiPoisonVolley_Timer < uiDiff)
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_POISONVOLLEY);
                m_uiPoisonVolley_Timer = urand(10000, 20000);
            }
            else
                m_uiPoisonVolley_Timer -= uiDiff;

            if (m_uiDrainLife_Timer < uiDiff)
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_DRAIN_LIFE);
                m_uiDrainLife_Timer = urand(20000, 50000);
            }
            else
                m_uiDrainLife_Timer -= uiDiff;

            if (m_uiSpawnSpider_Timer < uiDiff)
            {
                // Mar'li doit invoquer entre 1 et 4 "rejetons"
                uint32 uiInvocCount = urand(1, 4);
                for (uint8 i = 0; i < uiInvocCount; ++i)
                {
                    if (GameObject *pEgg = SelectNextEgg())
                    {
                        pEgg->SetGoState(GO_STATE_ACTIVE);
                        m_creature->SummonCreature(NPC_SPAWN_OF_MARLI, pEgg->GetPositionX(), pEgg->GetPositionY(), pEgg->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                    }
                }
                m_uiSpawnSpider_Timer = urand(20000, 30000);
            }
            else
                m_uiSpawnSpider_Timer -= uiDiff;

            if (m_uiAggrandir_Timer < uiDiff)
            {
                if (!m_creature->HasAura(SPELL_AGGRANDIR))
                    DoCastSpellIfCan(m_creature, SPELL_AGGRANDIR);

                m_uiAggrandir_Timer = urand(10000, 20000);
            }
            else
                m_uiAggrandir_Timer -= uiDiff;

        }
        // Araignee
        else
        {
            if (!m_bHasWebbed && m_uiWebs_Timer < uiDiff)
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ENVELOPINGWEBS);
                m_uiWebs_Timer = urand(10000, 15000);
                m_uiCharge_Timer = 1000;
                m_bHasWebbed = true;
            }
            else
                m_uiWebs_Timer -= uiDiff;

            if (m_bHasWebbed && m_uiCharge_Timer < uiDiff)
            {
                //Shouldn't be random target but highestaggro not Webbed player
                if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0))
                {
                    DoCastSpellIfCan(pTarget, SPELL_CHARGE);
                    DoResetThreat();
                    AttackStart(pTarget);
                    m_bHasWebbed = false;
                    /*
                        DoResetThreat();
                        Unit* pTarget = nullptr;
                        uint8 i = 0 ;
                        while (i < 5)                               // max 3 tries to get a random target with power_mana
                        {
                            ++i;                                    //not aggro leader
                            pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM,0);
                            if (pTarget && pTarget->GetPowerType() == POWER_MANA)
                                i=5;
                        }
                    */
                }
                m_uiWebs_Timer = urand(10000, 20000);
            }
            else
                m_uiCharge_Timer -= uiDiff;

            if (m_uiCorrosivePoison_Timer < uiDiff)
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CORROSIVE_POISON);
                m_uiCorrosivePoison_Timer = urand(25000, 35000);
            }
            else
                m_uiCorrosivePoison_Timer -= uiDiff;
        }

        if (m_uiTransformBack_Timer < uiDiff)
        {
            if (!m_bIsInPhaseTwo)
            {
                if (m_creature->IsNonMeleeSpellCasted(false))
                    m_creature->InterruptNonMeleeSpells(false);

                DoScriptText(SAY_TRANSFORM, m_creature);
                DoCastSpellIfCan(m_creature, SPELL_SPIDER_FORM);

                CreatureInfo const *cinfo = m_creature->GetCreatureInfo();
                m_creature->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->dmg_min + ((cinfo->dmg_min / 100) * 35)));
                m_creature->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->dmg_max + ((cinfo->dmg_max / 100) * 35)));
                m_creature->UpdateDamagePhysical(BASE_ATTACK);

                DoResetThreat();

                m_bIsInPhaseTwo = true;
            }
            else
            {
                if (m_creature->IsNonMeleeSpellCasted(false))
                    m_creature->InterruptNonMeleeSpells(false);

                DoCastSpellIfCan(m_creature, SPELL_TRANSFORM_BACK);

                m_creature->SetDisplayId(m_uiDefaultModel);

                CreatureInfo const *cinfo = m_creature->GetCreatureInfo();
                m_creature->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->dmg_min + ((cinfo->dmg_min / 100) * 1)));
                m_creature->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->dmg_max + ((cinfo->dmg_max / 100) * 1)));
                m_creature->UpdateDamagePhysical(BASE_ATTACK);

                m_bIsInPhaseTwo = false;
            }

            m_uiTransformBack_Timer = 35000;
        }
        else
            m_uiTransformBack_Timer -= uiDiff;

        if (m_uiTrash_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_TRASH);
            m_uiTrash_Timer = urand(10000, 20000);
        }
        else
            m_uiTrash_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

//Spawn of Marli
struct mob_spawn_of_marliAI : public ScriptedAI
{
    mob_spawn_of_marliAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        m_pInstance = (ScriptedInstance*)m_creature->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;
    uint32 m_uiLevelUp_Timer;

    void Reset() override
    {
        m_uiLevelUp_Timer = 3000;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiLevelUp_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_LEVELUP);
            m_creature->SetLevel(m_creature->GetLevel() + 1);
            m_uiLevelUp_Timer = 3000;
        }
        else
            m_uiLevelUp_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_marli(Creature* pCreature)
{
    return new boss_marliAI(pCreature);
}

CreatureAI* GetAI_mob_spawn_of_marli(Creature* pCreature)
{
    return new mob_spawn_of_marliAI(pCreature);
}

void AddSC_boss_marli()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_marli";
    newscript->GetAI = &GetAI_boss_marli;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_spawn_of_marli";
    newscript->GetAI = &GetAI_mob_spawn_of_marli;
    newscript->RegisterSelf();
}
