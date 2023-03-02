/* ScriptData
SDName: Blackrock Depths T0.5 Arena Challenge NPC AI
SDCategory: Blackrock Depths
EndScriptData */

/* ContentData
npc_theldren
npc_korv
npc_va_jashni
*/

#include "scriptPCH.h"
#include "blackrock_depths.h"

/*######
## npc_theldren
######*/

enum
{
    SPELL_THELDREN_MORTAL_STRIKE        = 17547,
    SPELL_THELDREN_CHARGE               = 22911,
    SPELL_THELDREN_INTIMIDATING_SHOUT   = 19134,

    SPELL_VA_JASHNI_FLASH_HEAL          = 17138,
    SPELL_VA_JASHNI_SHIELD              = 20697,
    SPELL_VA_JASHNI_RENEW               = 23895,

    SPELL_KORV_FROST_SHOCK              = 21401,
    SPELL_KORV_EARTHBIND_TOTEM          = 15786,
    SPELL_KORV_FIRENOVA_TOTEM           = 11314,

    SPELL_LEFTY_FIVE_FAT_FINGERS        = 27673,

    SPELL_SNOKH_BLACKSPINE_PYROBLAST    = 17273,
    SPELL_SNOKH_BLACKSPINE_SCORCH       = 13878,
    SPELL_SNOKH_BLACKSPINE_FLAMESTRIKE  = 18399,
    SPELL_SNOKH_BLACKSPINE_POLYMORPH    = 13323,

    SPELL_VOLIDA_BLIZZARD               = 27618,
    SPELL_VOLIDA_CONEOFCOLD             = 12557,

    SPELL_MALGEN_LONGSPEAR_AIMED_SHOT   = 20902,
    SPELL_MALGEN_LONGSPEAR_MULTISHOT    = 20735,
    SPELL_MALGEN_LONGSPEAR_FEIGN_DEATH  = 5384,
    SPELL_MALGEN_LONGSPEAR_FROST_TRAP   = 13809,
    SPELL_MALGEN_LONGSPEAR_PET          = 19561,
    SPELL_MALGEN_LONGSPEAR_SHOOT        = 6660,

    NPC_MALGEN_LONGSPEAR_PET_GNASHJAW   = 16095
};

struct npc_theldrenAI : public ScriptedAI
{
    npc_theldrenAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiInterceptTimer;
    uint32 m_uiMortalStrikeTimer;
    uint32 m_uiFearTimer;

    void Reset() override
    {
        m_uiInterceptTimer = 10000;
        m_uiMortalStrikeTimer = 10000;
        m_uiFearTimer = 30000;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiInterceptTimer < diff)
        {
            Unit *target = GetPlayerAtMinimumRange(8.0f);

            if (target && DoCastSpellIfCan(target, SPELL_THELDREN_CHARGE) == CAST_OK)
                m_uiInterceptTimer = urand(20000, 30000);
        }
        else
            m_uiInterceptTimer -= diff;

        if (m_uiMortalStrikeTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_THELDREN_MORTAL_STRIKE) == CAST_OK)
                m_uiMortalStrikeTimer = urand(8000, 15000);
        }
        else
            m_uiMortalStrikeTimer -= diff;

        if (m_uiFearTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_THELDREN_INTIMIDATING_SHOUT) == CAST_OK)
                m_uiFearTimer = urand(30000, 40000);
        }
        else
            m_uiFearTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_theldren(Creature* pCreature)
{
    return new npc_theldrenAI(pCreature);
}

struct npc_va_jashniAI : public ScriptedAI
{
    npc_va_jashniAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiFlashHealTimer;
    uint32 m_uiShieldTimer;
    uint32 m_uiRenewTimer;

    void Reset() override
    {
        // The values on the heals are huge... Maybe wrong spells. If not, they
        // should have massive cooldowns
        m_uiFlashHealTimer = 10000;
        m_uiShieldTimer = 20000; // shield is 5000 health...
        m_uiRenewTimer = 30000;  // renew is 2000 health every 3 sec...
    }

    void UpdateAI(uint32 const diff) override
    {
        if (m_uiFlashHealTimer < diff)
        {
            Unit *target = m_creature->FindLowestHpFriendlyUnit(40.0f, 1);

            if (target && DoCastSpellIfCan(target, SPELL_VA_JASHNI_FLASH_HEAL) == CAST_OK)
                m_uiFlashHealTimer = urand(8000, 14000);
        }
        else
            m_uiFlashHealTimer -= diff;

        if (m_uiShieldTimer < diff)
        {
            Unit *target = m_creature->FindLowestHpFriendlyUnit(40.0f, 1);

            if (target && DoCastSpellIfCan(target, SPELL_VA_JASHNI_SHIELD) == CAST_OK)
                m_uiShieldTimer = urand(40000, 50000);
        }
        else
            m_uiShieldTimer -= diff;

        if (m_uiRenewTimer < diff)
        {
            Unit *target = m_creature->FindLowestHpFriendlyUnit(40.0f, 1);

            if (target && DoCastSpellIfCan(target, SPELL_VA_JASHNI_RENEW) == CAST_OK)
                m_uiRenewTimer = urand(55000, 65000);
        }
        else
            m_uiRenewTimer -= diff;

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_va_jashni(Creature* pCreature)
{
    return new npc_va_jashniAI(pCreature);
}

struct npc_korvAI : public ScriptedAI
{
    npc_korvAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiFrostShockTimer;
    uint32 m_uiEarthbindTimer;
    uint32 m_uiFireNovaTimer;

    void Reset() override
    {
        m_uiFrostShockTimer = 10000;
        m_uiEarthbindTimer = 20000;
        m_uiFireNovaTimer = 20000;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiFrostShockTimer < diff)
        {
            // Spam dat frost shock on random players!
            Unit *target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);

            if (target && DoCastSpellIfCan(target, SPELL_KORV_FROST_SHOCK) == CAST_OK)
                m_uiFrostShockTimer = urand(10000, 12000);
        }
        else
            m_uiFrostShockTimer -= diff;

        if (m_uiEarthbindTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_KORV_EARTHBIND_TOTEM) == CAST_OK)
                m_uiEarthbindTimer = 20000;
        }
        else
            m_uiEarthbindTimer -= diff;

        if (m_uiFireNovaTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_KORV_FIRENOVA_TOTEM) == CAST_OK)
                m_uiFireNovaTimer = 20000;
        }
        else
            m_uiFireNovaTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_korv(Creature* pCreature)
{
    return new npc_korvAI(pCreature);
}

struct npc_leftyAI : public ScriptedAI
{
    npc_leftyAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiFiveFingerTimer;

    void Reset() override
    {
        m_uiFiveFingerTimer = 2000;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiFiveFingerTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_LEFTY_FIVE_FAT_FINGERS) == CAST_OK)
                m_uiFiveFingerTimer = urand(2000, 3000);
        }
        else
            m_uiFiveFingerTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_lefty(Creature* pCreature)
{
    return new npc_leftyAI(pCreature);
}

struct npc_snokh_blackspineAI : public ScriptedAI
{
    npc_snokh_blackspineAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiPyroblastTimer;
    uint32 m_uiScorchTimer;
    uint32 m_uiFlamestrikeTimer;
    uint32 m_uiPolymorphTimer;

    void Reset() override
    {
        m_uiPyroblastTimer = 15000;
        m_uiScorchTimer = 4000;
        m_uiFlamestrikeTimer = 20000;
        m_uiPolymorphTimer = 30000;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiPyroblastTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SNOKH_BLACKSPINE_PYROBLAST) == CAST_OK)
                m_uiPyroblastTimer = urand(10000, 20000);
        }
        else
            m_uiPyroblastTimer -= diff;

        if (m_uiScorchTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SNOKH_BLACKSPINE_SCORCH) == CAST_OK)
                m_uiScorchTimer = urand(3000, 5000);
        }
        else
            m_uiScorchTimer -= diff;

        if (m_uiFlamestrikeTimer < diff)
        {
            Unit *target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);

            if (target && DoCastSpellIfCan(target, SPELL_SNOKH_BLACKSPINE_FLAMESTRIKE) == CAST_OK)
                m_uiFlamestrikeTimer = urand(10000, 20000);
        }
        else
            m_uiFlamestrikeTimer -= diff;

        if (m_uiPolymorphTimer < diff)
        {
            Unit *target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);

            if (target && DoCastSpellIfCan(target, SPELL_SNOKH_BLACKSPINE_POLYMORPH) == CAST_OK)
                m_uiPolymorphTimer = urand(25000, 30000);
        }
        else
            m_uiPolymorphTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_snokh_blackspine(Creature* pCreature)
{
    return new npc_snokh_blackspineAI(pCreature);
}

struct npc_volidaAI : public ScriptedAI
{
    npc_volidaAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiBlizzardTimer;
    uint32 m_uiConeOfColdTimer;

    void Reset() override
    {
        m_uiBlizzardTimer = 4000;
        m_uiConeOfColdTimer = 20000;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiBlizzardTimer < diff)
        {
            Unit *target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);

            if (target && DoCastSpellIfCan(target, SPELL_VOLIDA_BLIZZARD) == CAST_OK)
                m_uiBlizzardTimer = urand(14000, 18000);
        }
        else
            m_uiBlizzardTimer -= diff;

        if (m_uiConeOfColdTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_VOLIDA_CONEOFCOLD) == CAST_OK)
                m_uiConeOfColdTimer = 20000;
        }
        else
            m_uiConeOfColdTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_volida(Creature* pCreature)
{
    return new npc_volidaAI(pCreature);
}

struct npc_malgen_longspearAI : public ScriptedAI
{
    npc_malgen_longspearAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiAimedShotTimer;
    uint32 m_uiMultiShotTimer;
    uint32 m_uiFeignDeathTimer;
    uint32 m_uiFrostTrapTimer;
    bool m_bIsFeigned;
    ObjectGuid m_petGuid;

    void Reset() override
    {
        m_uiAimedShotTimer = 8000;
        m_uiMultiShotTimer = 15000;
        m_uiFeignDeathTimer = 10000;
        m_uiFrostTrapTimer = 0;

        m_bIsFeigned = false;

        m_petGuid = ObjectGuid();
    }

    void EnterEvadeMode() override
    {
        if (Creature *creature = m_creature->GetMap()->GetCreature(m_petGuid))
        {
            creature->ForcedDespawn();
            m_petGuid = ObjectGuid();
        }
    }

    void EnterCombat(Unit *enemy) override
    {
        // Summon pet
        if (Creature *creature = m_creature->GetMap()->GetCreature(m_petGuid))
            return;

        if (Creature *pet = m_creature->SummonCreature(NPC_MALGEN_LONGSPEAR_PET_GNASHJAW, m_creature->GetPositionX(),
            m_creature->GetPositionY(), m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000))
        {
            m_petGuid = pet->GetObjectGuid();
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_bIsFeigned && (!m_creature->SelectHostileTarget() || !m_creature->GetVictim()))
            return;

        if (m_uiFeignDeathTimer < diff)
        {
            // Feign death, lay trap, re-acquire target
            if (DoCastSpellIfCan(m_creature, SPELL_MALGEN_LONGSPEAR_FEIGN_DEATH, CF_TRIGGERED) == CAST_OK)
            {
                // Feign for 1 secs, then trap and repop
                m_bIsFeigned = true;
                m_uiFrostTrapTimer = 1000;
                m_uiFeignDeathTimer = urand(50000, 60000);
            }
        }
        else
            m_uiFeignDeathTimer -= diff;
        
        if (m_uiFrostTrapTimer)
        {
            if (m_uiFrostTrapTimer < diff)
            {
                m_creature->RemoveAurasDueToSpell(SPELL_MALGEN_LONGSPEAR_FEIGN_DEATH);
                
                DoCastSpellIfCan(m_creature, SPELL_MALGEN_LONGSPEAR_FROST_TRAP, CF_TRIGGERED);
                m_uiFrostTrapTimer = 0;

                m_bIsFeigned = false;

                Unit *target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
                if (target)
                {
                    m_creature->GetMotionMaster()->MoveChase(target);
                }
            }
            else
                m_uiFrostTrapTimer -= diff;
        }
        

        if (m_bIsFeigned)
            return;

        if (m_uiAimedShotTimer < diff)
        {
            Unit *target = GetPlayerAtMinimumRange(8.0f);

            if (target && DoCastSpellIfCan(target, SPELL_MALGEN_LONGSPEAR_AIMED_SHOT) == CAST_OK)
                m_uiAimedShotTimer = urand(18000, 24000);
        }
        else
            m_uiAimedShotTimer -= diff;

        if (m_uiMultiShotTimer < diff)
        {
            Unit *target = GetPlayerAtMinimumRange(8.0f);

            if (target && DoCastSpellIfCan(target, SPELL_MALGEN_LONGSPEAR_MULTISHOT) == CAST_OK)
                m_uiMultiShotTimer = 20000;
        }
        else
            m_uiMultiShotTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_malgen_longspear(Creature* pCreature)
{
    return new npc_malgen_longspearAI(pCreature);
}

void AddSC_blackrock_depths_arena_challenge()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_theldren";
    newscript->GetAI = &GetAI_npc_theldren;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_va_jashni";
    newscript->GetAI = &GetAI_npc_va_jashni;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_korv";
    newscript->GetAI = &GetAI_npc_korv;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_lefty";
    newscript->GetAI = &GetAI_npc_lefty;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_snokh_blackspine";
    newscript->GetAI = &GetAI_npc_snokh_blackspine;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_volida";
    newscript->GetAI = &GetAI_npc_volida;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_malgen_longspear";
    newscript->GetAI = &GetAI_npc_malgen_longspear;
    newscript->RegisterSelf();
}