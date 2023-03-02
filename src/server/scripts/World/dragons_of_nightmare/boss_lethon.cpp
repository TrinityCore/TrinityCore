/*
 *
 */

#include "scriptPCH.h"
#include "boss_dragon_of_nightmare.h"

enum
{
    SAY_LETHON_AGGRO                = -1000590,
    SAY_SUMMON_SHADE                = -1000591,

    SPELL_SHADOW_BOLT_WHIRL         = 24834,
    SPELL_DRAW_SPIRIT               = 24811,

    // Shade spells
    SPELL_DARK_OFFERING             = 24804,

    NPC_SPIRIT_SHADE                = 15261
};

boss_lethonAI::boss_lethonAI(Creature* pCreature) : boss_dragon_of_nightmareAI(pCreature)
{
    boss_lethonAI::Reset();
}

void boss_lethonAI::Reset()
{
    boss_dragon_of_nightmareAI::Reset();

    m_creature->RemoveAurasDueToSpell(SPELL_SHADOW_BOLT_WHIRL);
}

void boss_lethonAI::Aggro(Unit* pWho)
{
    boss_dragon_of_nightmareAI::Aggro(pWho);

    DoCastSpellIfCan(m_creature, SPELL_SHADOW_BOLT_WHIRL, CF_TRIGGERED | CF_AURA_NOT_PRESENT);
    DoScriptText(SAY_LETHON_AGGRO, m_creature);
}

void boss_lethonAI::SpellHitTarget(Unit* pTarget, SpellEntry const* pSpell)
{
    if (pSpell->Id == SPELL_DRAW_SPIRIT)
    {
        auto pPlayer = pTarget->ToPlayer();

        if (!pPlayer)
            return;

        float x, y, z, o;
        pPlayer->GetPosition(x, y, z);
        o = pPlayer->GetOrientation();

        if (auto pShade = m_creature->SummonCreature(NPC_SPIRIT_SHADE, x, y, z, o, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, MINUTE*IN_MILLISECONDS))
        {
            pShade->SetUInt32Value(UNIT_FIELD_BYTES_0, pPlayer->GetUInt32Value(UNIT_FIELD_BYTES_0));
            pShade->InitPlayerDisplayIds();
            pShade->SetDisplayId(pPlayer->GetDisplayId());

            if (auto pShadeAI = static_cast<npc_spirit_shadeAI*>(pShade->AI()))
                pShadeAI->m_lethonGuid = m_creature->GetObjectGuid();
        }
    }
}

void boss_lethonAI::SummonedMovementInform(Creature* pSummoned, uint32 uiMotionType, uint32 /*uiPointId*/)
{
    if (pSummoned->GetEntry() == NPC_SPIRIT_SHADE && uiMotionType == FOLLOW_MOTION_TYPE)
        pSummoned->CastSpell(m_creature, SPELL_DARK_OFFERING, true);
}

bool boss_lethonAI::DoSpecialAbility()
{
    if (DoCastSpellIfCan(m_creature, SPELL_DRAW_SPIRIT) == CAST_OK)
    {
        DoScriptText(SAY_SUMMON_SHADE, m_creature);

        return true;
    }

    return false;
}

/*
 * Spirit Shade
 */

npc_spirit_shadeAI::npc_spirit_shadeAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    npc_spirit_shadeAI::Reset();
}

void npc_spirit_shadeAI::Reset()
{
    m_uiDelay = 2500;

    m_creature->SetVisibility(VISIBILITY_OFF);
}

void npc_spirit_shadeAI::SpellHitTarget(Unit* /*pTarget*/, SpellEntry const* pSpell)
{
    if (pSpell->Id == SPELL_DARK_OFFERING)
        m_creature->ForcedDespawn(300);
}

void npc_spirit_shadeAI::UpdateAI(uint32 const uiDiff)
{
    if (m_uiDelay)
    {
        if (m_uiDelay <= uiDiff)
        {                        
            m_creature->SetVisibility(VISIBILITY_ON);

            if (Creature* pLethon = m_creature->GetMap()->GetCreature(m_lethonGuid))
            {
                if (pLethon->IsWithinDistInMap(m_creature, 5.0f))
                    m_creature->CastSpell(pLethon, SPELL_DARK_OFFERING, true);
                else
                    m_creature->GetMotionMaster()->MoveFollow(pLethon, 0.0f, 0.0f);
            }                
            else
                m_creature->ForcedDespawn();

            m_uiDelay = 0;
        }
        else
            m_uiDelay -= uiDiff;
    }
}
