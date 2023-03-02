/*
 *
 */

#include "scriptPCH.h"
#include "boss_dragon_of_nightmare.h"

enum
{
    SAY_TAERAR_AGGRO                = -1000399,
    SAY_SUMMON_SHADE                = -1000400,

    SPELL_ARCANE_BLAST              = 24857,
    SPELL_BELLOWING_ROAR            = 22686,

    SPELL_SHADE_OF_TAERAR_LEFT      = 24841,
    SPELL_SHADE_OF_TAERAR_RIGHT     = 24842,
    SPELL_SHADE_OF_TAERAR_FRONT     = 24843,
    SPELL_SELF_STUN                 = 24883,

    // Shade of Taerar spells
    SPELL_ACID_BREATH               = 24839,
    SPELL_POISON_CLOUD              = 24840,

    NPC_SHADE_OF_TAERAR             = 15302
};

/*
 *
 */

boss_taerarAI::boss_taerarAI(Creature* pCreature) : boss_dragon_of_nightmareAI(pCreature)
{
    boss_taerarAI::Reset();
}

void boss_taerarAI::Reset()
{
    boss_dragon_of_nightmareAI::Reset();

    m_uiArcaneBlastTimer       = urand(11000, 13000);
    m_uiBellowingRoarTimer     = urand(27000, 30000);
    m_uiShadesTimeoutTimer     = 0;

    m_uiShadesDead             = 0;
}

void boss_taerarAI::Aggro(Unit* pWho)
{
    boss_dragon_of_nightmareAI::Aggro(pWho);

    DoScriptText(SAY_TAERAR_AGGRO, m_creature);
}

void boss_taerarAI::EnterEvadeMode()
{
    DoUnbanish();

    boss_dragon_of_nightmareAI::EnterEvadeMode();
}

bool boss_taerarAI::DoSpecialAbility()
{
    if (DoCastSpellIfCan(m_creature, SPELL_SELF_STUN) == CAST_OK)
    {
        DoCastSpellIfCan(m_creature, SPELL_SHADE_OF_TAERAR_LEFT,  CF_TRIGGERED);
        DoCastSpellIfCan(m_creature, SPELL_SHADE_OF_TAERAR_RIGHT, CF_TRIGGERED);
        DoCastSpellIfCan(m_creature, SPELL_SHADE_OF_TAERAR_FRONT, CF_TRIGGERED);

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        DoScriptText(SAY_SUMMON_SHADE, m_creature);

        m_uiShadesTimeoutTimer = 120000;

        return true;
    }

    return false;
}

void boss_taerarAI::SummonedCreatureJustDied(Creature* pSummoned)
{
    if (pSummoned->GetEntry() == NPC_SHADE_OF_TAERAR)
    {
        ++m_uiShadesDead;

        if (m_uiShadesDead == 3)
        {
            DoUnbanish();
            m_creature->RemoveGuardians();
        }            
    }
}

void boss_taerarAI::DoUnbanish()
{
    m_creature->RemoveAurasDueToSpell(SPELL_SELF_STUN);
    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

    m_uiShadesTimeoutTimer = 0;
    m_uiShadesDead = 0;
}

bool boss_taerarAI::UpdateDragonAI(uint32 const uiDiff)
{
    if (m_uiShadesTimeoutTimer)
    {
        m_creature->UpdateLeashExtensionTime();

        if (m_uiShadesTimeoutTimer <= uiDiff)
            DoUnbanish();
        else
            m_uiShadesTimeoutTimer -= uiDiff;

        return false;
    }

    if (m_uiArcaneBlastTimer <= uiDiff)
    {
        Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER_NOT_GM);
        if (pTarget && DoCastSpellIfCan(pTarget, SPELL_ARCANE_BLAST) == CAST_OK)
            m_uiArcaneBlastTimer = urand(10000, 16000);
    }
    else
        m_uiArcaneBlastTimer -= uiDiff;

    if (m_uiBellowingRoarTimer <= uiDiff)
    {
        if (DoCastSpellIfCan(m_creature, SPELL_BELLOWING_ROAR) == CAST_OK)
            m_uiBellowingRoarTimer = urand(25000, 28000);
    }
    else
        m_uiBellowingRoarTimer -= uiDiff;

    return true;
}

/*
 *
 */

npc_shade_of_taerarAI::npc_shade_of_taerarAI(Creature* pCreature) : ScriptedPetAI(pCreature)
{
    if (m_creature->GetCharmInfo())
        m_creature->GetCharmInfo()->SetReactState(REACT_AGGRESSIVE);

    npc_shade_of_taerarAI::Reset();
}

void npc_shade_of_taerarAI::Reset()
{
    m_uiAcidBreathTimer = urand(10000, 12000);
    m_uiPoisonCloudTimer = urand(8000, 15000);
}

void npc_shade_of_taerarAI::UpdatePetAI(uint32 const uiDiff)
{
    if (m_uiAcidBreathTimer <= uiDiff)
    {
        if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ACID_BREATH) == CAST_OK)
            m_uiAcidBreathTimer = urand(10000, 15000);
    }
    else
        m_uiAcidBreathTimer -= uiDiff;

    if (m_uiPoisonCloudTimer <= uiDiff)
    {
        if (DoCastSpellIfCan(m_creature, SPELL_POISON_CLOUD) == CAST_OK)
            m_uiPoisonCloudTimer = urand(15000, 20000);
    }
    else
        m_uiPoisonCloudTimer -= uiDiff;

    ScriptedPetAI::UpdatePetAI(uiDiff);
}
