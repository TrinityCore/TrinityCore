#include "scriptPCH.h"
#include "dire_maul.h"


enum
{
    SPELL_BERSERKER_CHARGE  = 22886,
    SPELL_MORTAL_STRIKE     = 15708,
    SPELL_WAR_STOMP         = 16727,
    SPELL_SUNDER_ARMOR      = 15572,
    
    SAY_AGGRO               = -1900045,
};

struct boss_king_gordokAI : public ScriptedAI
{
    boss_king_gordokAI(Creature* pCreature) : ScriptedAI(pCreature) 
    {
        pInstance = (instance_dire_maul*)pCreature->GetInstanceData();
        Reset();
    }

    instance_dire_maul* pInstance;

    uint32 m_uiMortalStrike_Timer;
    uint32 m_uiWarStomp_Timer;
    uint32 m_uiBerserkerCharge_Timer;
    uint32 m_uiSunderArmor_Timer;
    uint32 m_uiPhase;
    
    // World of Warcraft Client Patch 1.9.3 (2006-02-07)
    // - King Gordok can no longer be seperated from Cho'Rush the Observer in Dire Maul.
    bool const m_bLinkCheckEnabled = sWorld.GetWowPatch() >= WOW_PATCH_109;
    uint32 m_uiLinkCheckTimer;
    
    
    void Reset() override
    {
        m_uiWarStomp_Timer        = urand(7000, 8000);
        m_uiMortalStrike_Timer    = urand(15000, 25000);
        m_uiSunderArmor_Timer     = urand(4000, 8000);
        m_uiBerserkerCharge_Timer = urand(9000, 12000);
        m_uiPhase = 0;
              
        m_uiLinkCheckTimer = 2500;
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Sunder Armor
        if (m_uiSunderArmor_Timer < uiDiff) 
        {
            Unit* pTarget = m_creature->GetVictim();
            if (pTarget) 
            {
                DoCastSpellIfCan(pTarget, SPELL_SUNDER_ARMOR);
                if (Aura* pAura = pTarget->GetAura(SPELL_SUNDER_ARMOR, EFFECT_INDEX_0)) 
                {
                    if (pAura->GetStackAmount() == 5)
                        m_uiSunderArmor_Timer = urand(15000, 25000);
                    else 
                        m_uiSunderArmor_Timer = urand(5000, 15000);
                } 
                else 
                    m_uiSunderArmor_Timer = urand(5000, 15000);
            }
        } 
        else 
            m_uiSunderArmor_Timer -= uiDiff;

        // Mortal Strike
        if (m_uiMortalStrike_Timer < uiDiff) 
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MORTAL_STRIKE) == CAST_OK)
                m_uiMortalStrike_Timer = urand(12000, 20000);
        } 
        else 
            m_uiMortalStrike_Timer -= uiDiff;

        // War Stomp
        if (m_uiWarStomp_Timer < uiDiff) 
        {
            if (DoCastSpellIfCan(m_creature, SPELL_WAR_STOMP) == CAST_OK)
                m_uiWarStomp_Timer = urand(20000, 30000);
        } 
        else 
            m_uiWarStomp_Timer -= uiDiff;

        // Berserker Charge
        if (m_uiBerserkerCharge_Timer < uiDiff) 
        {
            if (DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1, nullptr, SELECT_FLAG_PLAYER), SPELL_BERSERKER_CHARGE) == CAST_OK)
                m_uiBerserkerCharge_Timer = urand(25000, 30000);
        } 
        else 
            m_uiBerserkerCharge_Timer -= uiDiff;

        DoMeleeAttackIfReady();
        
        if (m_bLinkCheckEnabled)
        {
            // Prevent splitting King from the Observer
            if (m_uiLinkCheckTimer < uiDiff)
            {
                if (Creature* pChorush = m_creature->GetMap()->GetCreature(pInstance->GetData64(NPC_CHORUSH)))
                {
                    if (pChorush->IsAlive() && !pChorush->IsInCombat())
                        pChorush->AI()->AttackStart(m_creature->GetVictim());
                }
                m_uiLinkCheckTimer = 2500;
            }
            else
                m_uiLinkCheckTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_boss_king_gordok(Creature* pCreature)
{
    return new boss_king_gordokAI(pCreature);
}

enum
{
    // Mage
    SPELL_ARCANE_EXPLOSION  = 13745, // // m_uiSpellTimers[1]
    SPELL_FIREBALL          = 17290, // // m_uiSpellTimers[0]
    SPELL_FROST_NOVA        = 15331, // d 8s // m_uiSpellTimers[2]
    SPELL_BLOODLUST         = 16170, // d 30s // m_uiSpellTimers[3]

    // Shaman
    SPELL_CHAIN_LIGHTNING   = 15305, // m_uiSpellTimers[1]
    SPELL_EARTHGRAB_TOTEM   = 8376, // d 30s m_uiSpellTimers[2]
    SPELL_HEALING_WAVE      = 15982, // // m_uiSpellTimers[3]
    SPELL_LIGHTNING_BOLT    = 15234, // m_uiSpellTimers[0]

    // Priest
    SPELL_MIND_BLAST        = 17194, // m_uiSpellTimers[0]
    SPELL_HEAL              = 22883, // m_uiSpellTimers[3]
    SPELL_POWER_WORD_SHIELD = 17139, // m_uiSpellTimers[1]
    SPELL_PSYCHIC_SCREAM    = 22884, // m_uiSpellTimers[2]

    NPC_EARTHGRAB_TOTEM     = 6066,

    MAGE_EQUIPMENT          = 12072,
    SHAMAN_EQUIPMENT        = 12071,
    PRIST_EQUIPMENT         = 12070,

    MAX_SPELLS              = 4,
    SET_MAGE                = 1,
    SET_SHAMAN              = 2,
    SET_PRIST               = 3,
};

struct boss_chorushAI : public ScriptedAI
{
    boss_chorushAI(Creature* pCreature) : ScriptedAI(pCreature) 
    {
        pInstance = (instance_dire_maul*)pCreature->GetInstanceData();
        Reset();
    }

    instance_dire_maul* pInstance;

    uint8 m_uiEquipment;
    uint32 m_uiSpellTimers[MAX_SPELLS];
    bool m_bInMeele;
    
    // World of Warcraft Client Patch 1.9.3 (2006-02-07)
    // - King Gordok can no longer be seperated from Cho'Rush the Observer in Dire Maul.
    bool const m_bLinkCheckEnabled = sWorld.GetWowPatch() >= WOW_PATCH_109;
    uint32 m_uiLinkCheckTimer;

    void Reset() override
    {
        m_uiLinkCheckTimer = 2500;
        m_uiEquipment = 0;
        m_bInMeele = true;
        if (pInstance)
            m_uiEquipment = pInstance->GetChoRushEquipment();

        for (uint32 & timer : m_uiSpellTimers)
            timer = urand(1000, 2000);

        switch (m_uiEquipment)
        {
            case SET_MAGE: m_creature->LoadEquipment(MAGE_EQUIPMENT, true);
                SetCombatMovement(true);
                break;
            case SET_SHAMAN: m_creature->LoadEquipment(SHAMAN_EQUIPMENT, true);
                SetCombatMovement(true);
                break;
            case SET_PRIST: m_creature->LoadEquipment(PRIST_EQUIPMENT, true);
                SetCombatMovement(true);
                break;
        }
    }

    void UpdateAIMage(uint32 const uiDiff);
    void UpdateAIShaman(uint32 const uiDiff);
    void UpdateAIPrist(uint32 const uiDiff);

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        switch (m_uiEquipment)
        {
            case SET_MAGE:
                UpdateAIMage(uiDiff);
                break;
            case SET_SHAMAN:
                UpdateAIShaman(uiDiff);
                break;
            case SET_PRIST:
                UpdateAIPrist(uiDiff);
                break;
        }

        DoMeleeAttackIfReady();
        
        if (m_bLinkCheckEnabled)
        {
            // Prevent splitting Observer from the King
            if (m_uiLinkCheckTimer < uiDiff)
            {
                if (Creature* pKing = m_creature->GetMap()->GetCreature(pInstance->GetData64(NPC_KING_GORDOK)))
                {
                    if (!pKing->IsInCombat())
                        pKing->AI()->AttackStart(m_creature->GetVictim());
                }
                m_uiLinkCheckTimer = 2500;
            }
            else
                m_uiLinkCheckTimer -= uiDiff;
        }
    }
};

// MAGE
void boss_chorushAI::UpdateAIMage(uint32 const uiDiff)
{
    // Fireball
    if (m_uiSpellTimers[0] < uiDiff) 
    {
        if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FIREBALL) == CAST_OK)
            m_uiSpellTimers[0] = (m_bInMeele ? urand(7000, 10000) : urand(3000, 4000));
    } 
    else 
        m_uiSpellTimers[0] -= uiDiff;

    // Bloodlust
    if (m_uiSpellTimers[3] < uiDiff)
    {
        Unit* pTarget = nullptr;

        if (!m_creature->HasAura(SPELL_BLOODLUST))
            pTarget = m_creature;

        Unit* pKing = m_creature->FindNearestCreature(NPC_KING_GORDOK, 30.f);

        if (pKing && !pKing->HasAura(SPELL_BLOODLUST) && urand(0, 1))
            pTarget = pKing;

        if (DoCastSpellIfCan(pTarget, SPELL_BLOODLUST) == CAST_OK)
            m_uiSpellTimers[3] = urand(10000, 20000);
    } 
    else
        m_uiSpellTimers[3] -= uiDiff;

    // Arcane Explosion
    if (m_uiSpellTimers[1] < uiDiff) 
    {
        bool m_bMeleeAttackers = false;
        Unit::AttackerSet attackers = m_creature->GetAttackers();
        for (const auto itr : attackers)
            if (Unit* attacker = m_creature->GetMap()->GetUnit(itr->GetGUID()))
                if (m_creature->IsInRange(attacker, 0.0f, 8.0f, false)) 
                {
                    m_bMeleeAttackers = true;
                    break;
                }
        if (m_bMeleeAttackers)
            if (DoCastSpellIfCan(m_creature, SPELL_ARCANE_EXPLOSION) == CAST_OK)
                m_uiSpellTimers[1] = (m_bInMeele ? urand(9000, 13000) : urand(15000, 25000));
    } 
    else 
        m_uiSpellTimers[1] -= uiDiff;
    
    
    // Frost Nova
    if (m_uiSpellTimers[2] < uiDiff) 
    {
        bool m_bMeleeAttackers = false;
        Unit::AttackerSet attackers = m_creature->GetAttackers();
        for (const auto itr : attackers)
            if (Unit* attacker = m_creature->GetMap()->GetUnit(itr->GetGUID()))
                if (m_creature->IsInRange(attacker, 0.0f, 8.0f, false)) 
                {
                    m_bMeleeAttackers = true;
                    break;
                }
        if (m_bMeleeAttackers)
            if (DoCastSpellIfCan(m_creature, SPELL_FROST_NOVA) == CAST_OK)
                m_uiSpellTimers[2] = urand(20000, 30000);
    } 
    else 
        m_uiSpellTimers[2] -= uiDiff;

    if (!IsCombatMovementEnabled())
    { //Melee
        if (!m_bInMeele && (m_creature->GetDistance2d(m_creature->GetVictim()) < 5.0f || m_creature->GetDistance2d(m_creature->GetVictim()) > 30.0f
          || !m_creature->IsWithinLOSInMap(m_creature->GetVictim()) || m_creature->GetPowerPercent(POWER_MANA) < 5.0f))
        {
            SetCombatMovement(true);
            DoStartMovement(m_creature->GetVictim());
            m_bInMeele = true;
            return;
        }
    }
    else                
    { //Range
        if (m_bInMeele && m_creature->GetDistance2d(m_creature->GetVictim()) >= 5.0f && m_creature->GetDistance2d(m_creature->GetVictim()) <= 30.0f
          && m_creature->IsWithinLOSInMap(m_creature->GetVictim()) && m_creature->GetPowerPercent(POWER_MANA) >= 5.0f)
        {
            SetCombatMovement(false);
            m_bInMeele = false;
            DoStartNoMovement(m_creature->GetVictim());
            return;
        }
    }
};

// SHAMAN
void boss_chorushAI::UpdateAIShaman(uint32 const uiDiff)
{
    // Earthgrab Totem
    if (m_uiSpellTimers[2] < uiDiff) 
    {
        bool m_bMeleeAttackers = false;
        Unit::AttackerSet attackers = m_creature->GetAttackers();
        for (const auto itr : attackers)
            if (Unit* attacker = m_creature->GetMap()->GetUnit(itr->GetGUID()))
                if (m_creature->IsInRange(attacker, 0.0f, 6.0f, false)) 
                {
                    m_bMeleeAttackers = true;
                    break;
                }
        if (m_bMeleeAttackers)
            if (DoCastSpellIfCan(m_creature, SPELL_EARTHGRAB_TOTEM) == CAST_OK)
                m_uiSpellTimers[2] = urand(20000, 30000);
    } 
    else 
        m_uiSpellTimers[2] -= uiDiff;

    // Healing Wave
    if (m_uiSpellTimers[3] < uiDiff) 
    {
        Unit* pTarget = nullptr;
        if (pTarget = m_creature->FindLowestHpFriendlyUnit(40.0f, 15000));
        else if (m_creature->GetHealthPercent() < 50.0f)
            pTarget = m_creature;

        if (pTarget)
            if (DoCastSpellIfCan(pTarget, SPELL_HEALING_WAVE) == CAST_OK)
                m_uiSpellTimers[3] = urand(10000, 15000);
    } 
    else 
        m_uiSpellTimers[3] -= uiDiff;

    // Lightning Bolt
    if (m_uiSpellTimers[0] < uiDiff) 
    {
        if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_LIGHTNING_BOLT) == CAST_OK)
            m_uiSpellTimers[0] = (m_bInMeele ? urand(7000, 10000) : urand(3000, 4000));
    } 
    else 
        m_uiSpellTimers[0] -= uiDiff;

    // Chain Lightning
    if (m_uiSpellTimers[1] < uiDiff) 
    {
        if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CHAIN_LIGHTNING) == CAST_OK)
            m_uiSpellTimers[1] = urand(15000, 25000);
    } 
    else 
        m_uiSpellTimers[1] -= uiDiff;

    if (!IsCombatMovementEnabled())
    { //Melee
        if (!m_bInMeele && (m_creature->GetDistance2d(m_creature->GetVictim()) < 5.0f || m_creature->GetDistance2d(m_creature->GetVictim()) > 30.0f
          || !m_creature->IsWithinLOSInMap(m_creature->GetVictim()) || m_creature->GetPowerPercent(POWER_MANA) < 5.0f))
        {
            SetCombatMovement(true);
            DoStartMovement(m_creature->GetVictim());
            m_bInMeele = true;
            return;
        }
    }
    else
    { //Range
        if (m_bInMeele && m_creature->GetDistance2d(m_creature->GetVictim()) >= 5.0f && m_creature->GetDistance2d(m_creature->GetVictim()) <= 30.0f
          && m_creature->IsWithinLOSInMap(m_creature->GetVictim()) && m_creature->GetPowerPercent(POWER_MANA) >= 5.0f)
        {
            SetCombatMovement(false);
            m_bInMeele = false;
            DoStartNoMovement(m_creature->GetVictim());
            return;
        }
    }
};

// PRIEST
void boss_chorushAI::UpdateAIPrist(uint32 const uiDiff)
{
    // Heal
    if (m_uiSpellTimers[3] < uiDiff) 
    {
        Unit* pTarget = nullptr;
        if (pTarget = m_creature->FindLowestHpFriendlyUnit(40.0f, 15000));
        else if (m_creature->GetHealthPercent() < 50.0f)
            pTarget = m_creature;

        if (pTarget)
            if (DoCastSpellIfCan(pTarget, SPELL_HEAL) == CAST_OK)
                m_uiSpellTimers[3] = urand(10000, 15000);
    } 
    else 
        m_uiSpellTimers[3] -= uiDiff;

    // Mind Blast
    if (m_uiSpellTimers[0] < uiDiff) 
    {
        if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MIND_BLAST) == CAST_OK)
            m_uiSpellTimers[0] = (m_bInMeele ? urand(7000, 10000) : urand(2000, 3000));
    } 
    else 
        m_uiSpellTimers[0] -= uiDiff;

    // Power Word Shield
    if (m_uiSpellTimers[1] < uiDiff)
    {
        if (Unit* pTarget = m_creature->FindLowestHpFriendlyUnit(40.0f))
        {
            if (DoCastSpellIfCan(pTarget, SPELL_POWER_WORD_SHIELD) == CAST_OK)
                m_uiSpellTimers[1] = urand(17000, 22000);
        }
    } 
    else
        m_uiSpellTimers[1] -= uiDiff;

    // Psychic Scream
    if (m_uiSpellTimers[2] < uiDiff) 
    {
        bool m_bMeleeAttackers = false;
        Unit::AttackerSet attackers = m_creature->GetAttackers();
        for (const auto itr : attackers)
            if (Unit* attacker = m_creature->GetMap()->GetUnit(itr->GetGUID()))
                if (m_creature->IsInRange(attacker, 0.0f, 8.0f, false)) 
                {
                    m_bMeleeAttackers = true;
                    break;
                }
        if (m_bMeleeAttackers)
            if (DoCastSpellIfCan(m_creature, SPELL_PSYCHIC_SCREAM) == CAST_OK)
                m_uiSpellTimers[2] = urand(15000, 20000);
    } 
    else 
        m_uiSpellTimers[2] -= uiDiff;

    if (!IsCombatMovementEnabled())
    { //Melee
        if (!m_bInMeele && (m_creature->GetDistance2d(m_creature->GetVictim()) < 5.0f || m_creature->GetDistance2d(m_creature->GetVictim()) > 30.0f
            || !m_creature->IsWithinLOSInMap(m_creature->GetVictim()) || m_creature->GetPowerPercent(POWER_MANA) < 5.0f))
        {
            SetCombatMovement(true);
            DoStartMovement(m_creature->GetVictim());
            m_bInMeele = true;
            return;
        }
    }
    else
    { //Range
        if (m_bInMeele && m_creature->GetDistance2d(m_creature->GetVictim()) >= 5.0f && m_creature->GetDistance2d(m_creature->GetVictim()) <= 30.0f
            && m_creature->IsWithinLOSInMap(m_creature->GetVictim()) && m_creature->GetPowerPercent(POWER_MANA) >= 5.0f)
        {
            SetCombatMovement(false);
            m_bInMeele = false;
            DoStartNoMovement(m_creature->GetVictim());
            return;
        }
    }
};

CreatureAI* GetAI_boss_chorush(Creature* pCreature)
{
    return new boss_chorushAI(pCreature);
}

void AddSC_npc_king_gordok()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "boss_king_gordok";
    pNewScript->GetAI = &GetAI_boss_king_gordok;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_chorush";
    pNewScript->GetAI = &GetAI_boss_chorush;
    pNewScript->RegisterSelf();
}
