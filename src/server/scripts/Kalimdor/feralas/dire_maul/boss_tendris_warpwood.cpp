/* Copyright (C) 2009 - 2010 Nostalrius <http://nostalrius.ath.cx/>
 * Auteur        : Daemon
 * All rights reserved */

#include "scriptPCH.h"
#include "dire_maul.h"

enum
{
    SAY_TENDRIS_AGGRO          = -1900168,

    SPELL_TRAMPLE              = 5568,
    SPELL_UPPERCUT             = 22916,
    SPELL_GRASPING_VINES       = 22924,
    SPELL_ENCHEVETREMENT       = 22994,
    SPELL_ENRAGE               = 8269,
    
    NPC_IRONBARK_PROTECTOR     = 11459,
    NPC_ANCIENT_EQUINE_SPIRIT  = 14566, 
};

// boss_tendris_warpwood
struct boss_tendris_warpwoodAI : public ScriptedAI
{
    boss_tendris_warpwoodAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_dire_maul*) pCreature->GetInstanceData();
        m_uiAggroProtector = false;
        Reset();
    }

    instance_dire_maul* m_pInstance;
    uint32 m_uiTrampleTimer;
    uint32 m_uiUppercutTimer;
    uint32 m_uiGraspingVinesTimer;
    uint32 m_uiInvocation_Timer;
    bool   m_uiAggroProtector;

    bool ManageTimer(uint32 const diff, uint32* timer, uint32 cooldown)
    {
        if ((*timer) < diff)
        {
            (*timer) = cooldown;
            return true;
        }
        (*timer) -= diff;
        return false;
    }

    void JustDied(Unit* pKiller) override
    {
        m_creature->SummonCreature(NPC_ANCIENT_EQUINE_SPIRIT, 
                                   pKiller->GetPositionX(), 
                                   pKiller->GetPositionY(), 
                                   pKiller->GetPositionZ(), 
                                   pKiller->GetOrientation(), 
                                   TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60000);
    }

    void Aggro(Unit* pWho) override
    {
        if (!m_uiAggroProtector)
        {
            // World of Warcraft Client Patch 1.10.0 (2006-03-28)
            // - Tendris Warpwood will now call upon any protectors still alive to aid him.
            if (sWorld.GetWowPatch() >= WOW_PATCH_110)
            {
                std::list<Creature*> m_AggroList;
                GetCreatureListWithEntryInGrid(m_AggroList, m_creature, NPC_IRONBARK_PROTECTOR, 1800.0f);
                for (const auto& it : m_AggroList)
                {
                    if (it->IsAlive())
                        it->SetInCombatWithZone();
                }
            }
            m_uiAggroProtector = true;
            DoScriptText(SAY_TENDRIS_AGGRO, m_creature);
        }
    }

    void Reset() override
    {
        m_uiInvocation_Timer       = 0;
        m_uiTrampleTimer           = urand(5000, 9000);
        m_uiUppercutTimer          = urand(2000, 4000);
        m_uiGraspingVinesTimer     = urand(9000, 12000);
        m_uiAggroProtector         = false;
    }

    void AttackStart(Unit* Who) override
    {
        ScriptedAI::AttackStart(Who);
        if (m_pInstance)
            m_pInstance->SetData(DATA_TENDRIS_AGGRO, IN_PROGRESS);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim() || m_creature->IsNonMeleeSpellCasted(false))
            return;

        if (ManageTimer(uiDiff, &m_uiTrampleTimer,              urand(9000, 14000)))
            DoCastSpellIfCan(m_creature, SPELL_TRAMPLE);

        if (ManageTimer(uiDiff, &m_uiUppercutTimer,             urand(12000, 15000)))
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_UPPERCUT);

        if (ManageTimer(uiDiff, &m_uiGraspingVinesTimer,       urand(17000, 22000)))
            DoCastSpellIfCan(m_creature, SPELL_GRASPING_VINES);

        if (m_creature->GetHealthPercent() < 30.0f && !m_creature->HasAura(SPELL_ENRAGE))
            m_creature->CastSpell(m_creature, SPELL_ENRAGE, true);

        /** Invoque player in front of him */
        if (m_uiInvocation_Timer < uiDiff)
        {
            Unit* pUnit = m_creature->GetVictim();
            if (m_creature->GetDistance(pUnit) > 7.0f)
            {
                float x = m_creature->GetPositionX();
                float y = m_creature->GetPositionY();
                float z = m_creature->GetPositionZ() + 1;
                float orientation = pUnit->GetOrientation();
                m_creature->SendSpellGo(pUnit, 25681);
                pUnit->NearTeleportTo(x, y, z, orientation);
                m_uiInvocation_Timer = urand(10000, 15000);
                DoCastSpellIfCan(pUnit, SPELL_ENCHEVETREMENT);
            }
        }
        else
            m_uiInvocation_Timer -= uiDiff;


        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_tendris_warpwood(Creature* pCreature)
{
    return new boss_tendris_warpwoodAI(pCreature);
}

void AddSC_boss_tendris_warpwood()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "boss_tendris_warpwood";
    pNewScript->GetAI = &GetAI_boss_tendris_warpwood;
    pNewScript->RegisterSelf();
}
