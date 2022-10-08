/*
 *
 */

#include "scriptPCH.h"
#include "boss_dragon_of_nightmare.h"

enum
{
    SAY_EMERISS_AGGRO               = -1000401,
    SAY_CAST_CORRUPTION             = -1000402,

    SPELL_EMERISS_AURA              = 24906,
    SPELL_VOLATILE_INFECTION        = 24928,

    SPELL_CORRUPTION_OF_THE_EARTH   = 24910
};

/*
 *
 */

boss_emerissAI::boss_emerissAI(Creature* pCreature) : boss_dragon_of_nightmareAI(pCreature)
{
    boss_emerissAI::Reset();
}

void boss_emerissAI::Reset()
{
    boss_dragon_of_nightmareAI::Reset();

    m_uiEmerissAuraTimer       = 0;
    m_uiVolatileInfectionTimer = urand(11000, 13000);
}

void boss_emerissAI::Aggro(Unit* pWho)
{
    boss_dragon_of_nightmareAI::Aggro(pWho);

    DoScriptText(SAY_EMERISS_AGGRO, m_creature);
}

bool boss_emerissAI::DoSpecialAbility()
{
    if (DoCastSpellIfCan(m_creature, SPELL_CORRUPTION_OF_THE_EARTH) == CAST_OK)
    {
        DoScriptText(SAY_CAST_CORRUPTION, m_creature);

        return true;
    }

    return false;
}

bool boss_emerissAI::UpdateDragonAI(uint32 const uiDiff)
{
    // Emeriss Aura
    if (m_uiEmerissAuraTimer <= uiDiff)
    {
        if (DoCastSpellIfCan(m_creature, SPELL_EMERISS_AURA) == CAST_OK)
            m_uiEmerissAuraTimer = 10000;
    }
    else
        m_uiEmerissAuraTimer -= uiDiff;

    // Volatile Infection
    if (m_uiVolatileInfectionTimer <= uiDiff)
    {
        Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER_NOT_GM);
        if (pTarget && DoCastSpellIfCan(pTarget, SPELL_VOLATILE_INFECTION, CF_AURA_NOT_PRESENT) == CAST_OK)
            m_uiVolatileInfectionTimer = urand(10000, 16000);
    }
    else
        m_uiVolatileInfectionTimer -= uiDiff;

    return true;
}
