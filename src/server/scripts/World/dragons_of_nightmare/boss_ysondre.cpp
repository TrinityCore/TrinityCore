/*
 *
 */

#include "scriptPCH.h"
#include "boss_dragon_of_nightmare.h"

enum
{
    // Ysondre
    SAY_YSONDRE_AGGRO               = -1000360,
    SAY_SUMMON_DRUIDS               = -1000361,

    SPELL_LIGHTNINGWAVE             = 24819,
    SPELL_SUMMONDRUIDS              = 24795,

    // Druid spells
    SPELL_CURSE_OF_THORNS           = 16247,
    SPELL_MOONFIRE                  = 24957,
    SPELL_SILENCE                   = 6726,

    NPC_DRUID_SPIRIT                = 15260
};

/*
 *
 */

boss_ysondreAI::boss_ysondreAI(Creature* pCreature) : boss_dragon_of_nightmareAI(pCreature)
{
    boss_ysondreAI::Reset();
}
    
void boss_ysondreAI::Reset()
{
    boss_dragon_of_nightmareAI::Reset();

    m_uiLightningWaveTimer = urand(10000, 13000);
}

void boss_ysondreAI::Aggro(Unit* pWho)
{
    boss_dragon_of_nightmareAI::Aggro(pWho);
        
    DoScriptText(SAY_YSONDRE_AGGRO, m_creature);
}

void boss_ysondreAI::JustSummoned(Creature* pSummoned)
{
    if (pSummoned->GetEntry() == NPC_DRUID_SPIRIT)
    {
        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER_NOT_GM))
            pSummoned->AI()->AttackStart(pTarget);
    }
}

bool boss_ysondreAI::DoSpecialAbility()
{
    auto const& attackers = m_creature->GetThreatManager().getThreatList();
    uint8 attackersCount = 0;

    for (const auto attacker : attackers)
    {
        Player* pPlayer = m_creature->GetMap()->GetPlayer(attacker->getUnitGuid());
        if (pPlayer && pPlayer->IsAlive() && !pPlayer->IsGameMaster())
            ++attackersCount;
    }

    uint8 amount = attackersCount < 20 ? attackersCount * 0.75f : 15;
    amount = amount < 3 ? 3 : amount;

    for (uint8 i = 0; i < amount; ++i)
    {
        DoSpawnCreature(NPC_DRUID_SPIRIT, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30);            
    }

    DoScriptText(SAY_SUMMON_DRUIDS, m_creature);

    return true;
}
    
bool boss_ysondreAI::UpdateDragonAI(uint32 const uiDiff)
{
    // Lightning Wave
    if (m_uiLightningWaveTimer < uiDiff)
    {
        Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER_NOT_GM);

        if (pTarget && DoCastSpellIfCan(pTarget, SPELL_LIGHTNINGWAVE) == CAST_OK)
            m_uiLightningWaveTimer = urand(8000, 12000);
    }
    else
        m_uiLightningWaveTimer -= uiDiff;

    return true;
}

/*
 *
 */

npc_demented_druidAI::npc_demented_druidAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    npc_demented_druidAI::Reset();
}

void npc_demented_druidAI::Reset()
{
    m_uiCurseOfThornsTimer  = urand(4000, 10000);
    m_uiMoonFireTimer       = urand(1000, 5000);
    m_uiSilenceTimer        = urand(5000, 12000);
}

void npc_demented_druidAI::UpdateAI(uint32 const uiDiff)
{
    if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        return;
        
    // Curse of Thorns
    if (m_uiCurseOfThornsTimer < uiDiff)
    {                    
        Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER_NOT_GM);

        if (target && !target->HasAura(SPELL_CURSE_OF_THORNS))
        {    
            if (DoCastSpellIfCan(target, SPELL_CURSE_OF_THORNS, CF_AURA_NOT_PRESENT) == CAST_OK)
                m_uiCurseOfThornsTimer = urand(13000, 16000);
        }
    }
    else
        m_uiCurseOfThornsTimer -= uiDiff;

    // MoonFire
    if (m_uiMoonFireTimer < uiDiff)
    {
        if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MOONFIRE) == CAST_OK)
            m_uiMoonFireTimer = urand(3000, 6000);
    }
    else
        m_uiMoonFireTimer -= uiDiff;

    // Silence
    if (m_uiSilenceTimer < uiDiff)
    {
        Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER_NOT_GM | SELECT_FLAG_POWER_MANA);

        if (target && DoCastSpellIfCan(target, SPELL_SILENCE, CF_AURA_NOT_PRESENT) == CAST_OK)
            m_uiSilenceTimer = urand(10000, 14000);
    }
    else 
        m_uiSilenceTimer -= uiDiff;

    DoMeleeAttackIfReady();
}
