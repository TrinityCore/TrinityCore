/* ScriptData
SDName: Western_Plaguelands
SD%Complete: 90
SDComment: Quest support: 5216,5219,5222,5225,5229,5231,5233,5235.
SDCategory: Western Plaguelands
EndScriptData */

/* ContentData
npc_myranda_hag
npc_the_scourge_cauldron
EndContentData */

#include "scriptPCH.h"

/*######
## npc_the_scourge_cauldron
######*/

struct npc_the_scourge_cauldronAI : public ScriptedAI
{
    npc_the_scourge_cauldronAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    void Reset() override {}

    void DoDie()
    {
        //summoner dies here
        m_creature->DealDamage(m_creature, m_creature->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
        //override any database `spawntimesecs` to prevent duplicated summons
        uint32 rTime = m_creature->GetRespawnDelay();
        if (rTime < 600)
            m_creature->SetRespawnDelay(600);
    }

    void MoveInLineOfSight(Unit *who) override
    {
        if (!who || who->GetTypeId() != TYPEID_PLAYER)
            return;

        if (who->GetTypeId() == TYPEID_PLAYER)
        {
            switch (m_creature->GetAreaId())
            {
                case 199:                                   //felstone
                    if (((Player*)who)->GetQuestStatus(5216) == QUEST_STATUS_INCOMPLETE ||
                            ((Player*)who)->GetQuestStatus(5229) == QUEST_STATUS_INCOMPLETE)
                    {
                        m_creature->SummonCreature(11075, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000);
                        DoDie();
                    }
                    break;
                case 200:                                   //dalson
                    if (((Player*)who)->GetQuestStatus(5219) == QUEST_STATUS_INCOMPLETE ||
                            ((Player*)who)->GetQuestStatus(5231) == QUEST_STATUS_INCOMPLETE)
                    {
                        m_creature->SummonCreature(11077, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000);
                        DoDie();
                    }
                    break;
                case 201:                                   //gahrron
                    if (((Player*)who)->GetQuestStatus(5225) == QUEST_STATUS_INCOMPLETE ||
                            ((Player*)who)->GetQuestStatus(5235) == QUEST_STATUS_INCOMPLETE)
                    {
                        m_creature->SummonCreature(11078, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000);
                        DoDie();
                    }
                    break;
                case 202:                                   //writhing
                    if (((Player*)who)->GetQuestStatus(5222) == QUEST_STATUS_INCOMPLETE ||
                            ((Player*)who)->GetQuestStatus(5233) == QUEST_STATUS_INCOMPLETE)
                    {
                        m_creature->SummonCreature(11076, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000);
                        DoDie();
                    }
                    break;
            }
        }
    }
};
CreatureAI* GetAI_npc_the_scourge_cauldron(Creature* pCreature)
{
    return new npc_the_scourge_cauldronAI(pCreature);
}

enum eAndorhalTower
{
    GO_BEACON_TORCH                             = 176093
};

struct npc_andorhal_towerAI : public Scripted_NoMovementAI
{
    npc_andorhal_towerAI(Creature *c) : Scripted_NoMovementAI(c) {}

    void Reset() override
    {

    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (!pWho || pWho->GetTypeId() != TYPEID_PLAYER)
            return;

        if (GetClosestGameObjectWithEntry(m_creature, GO_BEACON_TORCH, 20.0f))
            ((Player*)pWho)->KilledMonsterCredit(m_creature->GetEntry(), m_creature->GetGUID());
    }
};

CreatureAI* GetAI_npc_andorhal_tower(Creature* pCreature)
{
    return new npc_andorhal_towerAI(pCreature);
}

/*######
## npc_HighProtectorLorik
######*/

enum
{
    NPC_HIGHPROTECTORLORIK   = 1846,
    SPELL_RETRIBUTIONAURA    = 8990,
    SPELL_ARCANEBLAST        = 10833,
    SPELL_DIVINESHIELD       = 13874,
    SPELL_HOLYLIGHT          = 15493,
    SPELL_SHIELDSLAM         = 15655
};

struct npc_highprotectorlorikAI : public ScriptedAI
{
    npc_highprotectorlorikAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiGlobalCooldown;
    uint32 m_uiDiff_Add;
    uint32 m_uiArcaneBlastTimer;
    uint32 m_uiDivineShieldTimer;
    uint32 m_uiHolyLightTimer;
    uint32 m_uiShieldSlamTimer;

    void Reset() override
    {
        m_uiGlobalCooldown          = 0;
        m_uiDiff_Add                = 0;
        m_uiArcaneBlastTimer        = 7000;
        m_uiDivineShieldTimer       = 2000;
        m_uiHolyLightTimer          = 2000;
        m_uiShieldSlamTimer         = 2000;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->HasAura(SPELL_RETRIBUTIONAURA))
            m_creature->CastSpell(m_creature, SPELL_RETRIBUTIONAURA, true);

        // Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // GlobalCD non ecoule.
        if (m_uiGlobalCooldown > uiDiff)
            m_uiGlobalCooldown -= uiDiff;
        else
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_uiGlobalCooldown = 1;
            else
                m_uiGlobalCooldown = 0;
        }

        // DIVINESHIELD
        if (m_uiDivineShieldTimer < uiDiff)
        {
            if ((m_uiGlobalCooldown == 0) && (m_creature->GetHealthPercent() <= 15.0f))
            {
                if (DoCastSpellIfCan(m_creature, SPELL_DIVINESHIELD) == CAST_OK)
                {
                    m_uiDivineShieldTimer = 45000;
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiDivineShieldTimer -= uiDiff;

        // ARCANE BLAST
        if (m_uiArcaneBlastTimer < uiDiff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ARCANEBLAST) == CAST_OK)
                {
                    m_uiArcaneBlastTimer = urand(10000, 12000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiArcaneBlastTimer -= uiDiff;

        // HOLYLIGHT
        if (m_uiHolyLightTimer < uiDiff)
        {
            if (!m_uiGlobalCooldown && m_creature->GetHealthPercent() <= 60.0f && m_creature->GetPower(POWER_MANA) > 700)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_HOLYLIGHT) == CAST_OK)
                {
                    m_uiHolyLightTimer = urand(2000, 6000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiHolyLightTimer -= uiDiff;

        // SHIELDSLAM
        if (m_uiShieldSlamTimer < uiDiff)
        {
            if (!m_uiGlobalCooldown && m_creature->GetVictim()->IsNonMeleeSpellCasted(false))
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHIELDSLAM) == CAST_OK)
                {
                    m_uiShieldSlamTimer = 9000;
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiShieldSlamTimer -= uiDiff;

        DoMeleeAttackIfReady();

    }
};

CreatureAI* GetAI_npc_highprotectorlorik(Creature* pCreature)
{
    return new npc_highprotectorlorikAI(pCreature);
}


/*######
##
######*/

void AddSC_western_plaguelands()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_the_scourge_cauldron";
    newscript->GetAI = &GetAI_npc_the_scourge_cauldron;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_andorhal_tower";
    newscript->GetAI = &GetAI_npc_andorhal_tower;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_highprotectorlorik";
    newscript->GetAI = &GetAI_npc_highprotectorlorik;
    newscript->RegisterSelf();
}
