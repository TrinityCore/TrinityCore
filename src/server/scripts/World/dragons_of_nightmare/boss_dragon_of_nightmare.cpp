/*
 *
 */

#include "scriptPCH.h"
#include "ScriptedPetAI.h"
#include "boss_dragon_of_nightmare.h"
#include "HardcodedEvents.h"

uint32 GetDrakeVar(uint32 entry)
{
    switch (entry)
    {
        case NPC_YSONDRE:  return VAR_PERM_1;
        case NPC_LETHON:   return VAR_PERM_2;
        case NPC_EMERISS:  return VAR_PERM_3;
        default:           return VAR_PERM_4; // Taerar
    }
}

boss_dragon_of_nightmareAI::boss_dragon_of_nightmareAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    boss_dragon_of_nightmareAI::Reset();

    // The entry changes back to the default when the boss respawns. Re-apply
    // the current permutation by ensuring the AI is re-initialized on respawn
    m_creature->SetAInitializeOnRespawn(true);
}

void boss_dragon_of_nightmareAI::Reset()
{
    m_uiAuraOfNatureTimer       = 0;
    m_uiSeepingFogTimer         = 20000;
    m_uiNoxiousBreathTimer      = urand(7000, 10000);
    m_uiTailSweepTimer          = 10000;
    m_uiSummonPlayerTimer       = 0;

    m_uiEventCounter = 1;
}

void boss_dragon_of_nightmareAI::Aggro(Unit* /*pWho*/)
{
    DoCastSpellIfCan(m_creature, SPELL_MARK_OF_NATURE, CF_TRIGGERED | CF_AURA_NOT_PRESENT);
}

void boss_dragon_of_nightmareAI::EnterEvadeMode()
{
    m_creature->RemoveGuardians();
    m_creature->RemoveAurasDueToSpell(SPELL_MARK_OF_NATURE);

    ScriptedAI::EnterEvadeMode();
}

void boss_dragon_of_nightmareAI::JustDied(Unit* pKiller)
{
    ScriptedAI::JustDied(pKiller);
}

void boss_dragon_of_nightmareAI::UpdateAI(uint32 const uiDiff)
{
    if (m_uiAuraOfNatureTimer <= uiDiff)
    {
        if (DoCastSpellIfCan(m_creature, SPELL_AURA_OF_NATURE) == CAST_OK)
            m_uiAuraOfNatureTimer = urand(3000, 5000);
    }
    else
        m_uiAuraOfNatureTimer -= uiDiff;

    if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        return;

    EnterEvadeIfOutOfHomeArea();

    if (m_creature->GetHealthPercent() < 100.0f - m_uiEventCounter * 25.0f && DoSpecialAbility())
        ++m_uiEventCounter;

    if (!UpdateDragonAI(uiDiff))
        return;

    auto pTarget = m_creature->GetVictim();

    if (!m_creature->CanReachWithMeleeAutoAttack(pTarget) || !m_creature->IsWithinLOSInMap(pTarget))
    {
        m_uiSummonPlayerTimer += uiDiff;

        if (m_uiSummonPlayerTimer > 6000)
        {
            if (DoCastSpellIfCan(pTarget, SPELL_SUMMON_PLAYER, CF_TRIGGERED) == CAST_OK)
                m_uiSummonPlayerTimer = 0;
        }
    }
    else
        m_uiSummonPlayerTimer = 0;

    if (m_uiSeepingFogTimer <= uiDiff)
    {
        DoCastSpellIfCan(m_creature, SPELL_SEEPING_FOG_RIGHT, CF_TRIGGERED);
        DoCastSpellIfCan(m_creature, SPELL_SEEPING_FOG_LEFT, CF_TRIGGERED);

        m_uiSeepingFogTimer = 2 * MINUTE*IN_MILLISECONDS + 300;
    }
    else
        m_uiSeepingFogTimer -= uiDiff;

    if (m_uiNoxiousBreathTimer <= uiDiff)
    {
        if (DoCastSpellIfCan(pTarget, SPELL_NOXIOUS_BREATH) == CAST_OK)
            m_uiNoxiousBreathTimer = urand(9000, 11000);
    }
    else
        m_uiNoxiousBreathTimer -= uiDiff;

    if (m_uiTailSweepTimer <= uiDiff)
    {
        if (DoCastSpellIfCan(m_creature, SPELL_TAIL_SWEEP) == CAST_OK)
            m_uiTailSweepTimer = urand(6000, 8000);
    }
    else
        m_uiTailSweepTimer -= uiDiff;

    DoMeleeAttackIfReady();
}

/*
 *
 */

struct npc_dream_fogAI : ScriptedPetAI
{
    explicit npc_dream_fogAI(Creature* pCreature) : ScriptedPetAI(pCreature)
    {
        if (m_creature->GetCharmInfo())
            m_creature->GetCharmInfo()->SetReactState(REACT_AGGRESSIVE);

        npc_dream_fogAI::Reset();
        npc_dream_fogAI::ResetCreature();
    }

    uint32 m_uiChangeTargetTimer;

    void Reset() override
    {
        m_uiChangeTargetTimer = 0;
    }

    void ResetCreature() override
    {
        DoCastSpellIfCan(m_creature, SPELL_DREAM_FOG_AURA, CF_TRIGGERED | CF_AURA_NOT_PRESENT);
    }

    void AttackedBy(Unit*) override {}

    Unit* GetNextTarget() const
    {
        if (Unit* pOwner = m_creature->GetOwner())
        {
            if (pOwner->ToUnit())
            {
                if (Unit* pTarget = ((Creature*)pOwner)->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER_NOT_GM))
                {
                    if (pTarget != m_creature->GetVictim())
                        return pTarget;
                }
            }
        }

        return nullptr;
    }

    void ChangeTarget()
    {
        if (Unit* pTarget = GetNextTarget())
        {
            if (m_creature->GetVictim() && m_creature->GetThreatManager().getThreat(m_creature->GetVictim()))
                m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -100);

            AttackStart(pTarget);
            m_uiChangeTargetTimer = urand(6000, 10000);
        }
    }

    void UpdatePetAI(uint32 const uiDiff) override
    {
        if (m_uiChangeTargetTimer <= uiDiff)
            ChangeTarget();
        else
            m_uiChangeTargetTimer -= uiDiff;

        if (m_creature->IsWithinDistInMap(m_creature->GetVictim(), CONTACT_DISTANCE))
            m_uiChangeTargetTimer = urand(4000, 8000);
    }
};

/*
 *
 */

go_putrid_shroomAI::go_putrid_shroomAI(GameObject* pGo) : GameObjectAI(pGo)
{
    m_uiDespawnTimer = 2 * MINUTE*IN_MILLISECONDS + 1000;
}

void go_putrid_shroomAI::UpdateAI(uint32 const uiDiff)
{
    if (m_uiDespawnTimer < uiDiff)
        me->Delete();
    else
        m_uiDespawnTimer -= uiDiff;
}

CreatureAI* GetAI_npc_dream_fog(Creature* pCreature)
{
    return new npc_dream_fogAI(pCreature);
}

CreatureAI* GetAI_npc_spirit_shade(Creature* pCreature)
{
    return new npc_spirit_shadeAI(pCreature);
}

CreatureAI* GetAI_npc_shade_of_taerar(Creature* pCreature)
{
    return new npc_shade_of_taerarAI(pCreature);
}

CreatureAI* GetAI_npc_demented_druid(Creature* pCreature)
{
    return new npc_demented_druidAI(pCreature);
}

GameObjectAI* GetAI_go_putrid_shroom(GameObject* pGo)
{
    return new go_putrid_shroomAI(pGo);
}

CreatureAI* GetAI_boss_dragon_of_nightmare(Creature* pCreature)
{
    auto permVar = GetDrakeVar(pCreature->GetEntry());
    auto permEntry = sObjectMgr.GetSavedVariable(permVar, 0);

    if (permEntry && permEntry != pCreature->GetEntry())
        pCreature->UpdateEntry(permEntry);

    switch (pCreature->GetEntry())
    {
    case NPC_EMERISS:
        return new boss_emerissAI(pCreature);
    case NPC_LETHON:
        return new boss_lethonAI(pCreature);
    case NPC_TAERAR:
        return new boss_taerarAI(pCreature);
    case NPC_YSONDRE:
        return new boss_ysondreAI(pCreature);
    default:
        return nullptr;
    } 
}

void AddSC_dragons_of_nightmare()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "npc_dream_fog";
    pNewScript->GetAI = &GetAI_npc_dream_fog;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_spirit_shade";
    pNewScript->GetAI = &GetAI_npc_spirit_shade;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_shade_of_taerar";
    pNewScript->GetAI = &GetAI_npc_shade_of_taerar;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_demented_druid";
    pNewScript->GetAI = &GetAI_npc_demented_druid;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_dragon_of_nightmare";
    pNewScript->GetAI = &GetAI_boss_dragon_of_nightmare;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_putrid_shroom";
    pNewScript->GOGetAI = &GetAI_go_putrid_shroom;
    pNewScript->RegisterSelf();
}
