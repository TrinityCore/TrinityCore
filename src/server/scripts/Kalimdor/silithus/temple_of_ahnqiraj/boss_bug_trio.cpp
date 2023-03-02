/*
AQ40 - The Bug Trio -- NOSTALRIUS VERSION
Reference: http://forum.nostalrius.org/viewtopic.php?f=51&t=35154

Stryg comments:

There is some problem with spell 25807 (Yauj fear) that prevents it from fearing more than 1 person at a time. In the meantime,
the script is using Magmadar's panic spell which has the exact same range and duration, just a different name/icon.
*/


#include "scriptPCH.h"
#include "temple_of_ahnqiraj.h"

enum
{
    // emote
    EMOTE_DEVOUR = -1388004,

    // kri
    SPELL_THRASH = 3391,
    SPELL_CLEAVE = 19983,
    SPELL_TOXIC_VOLLEY = 25812,
    SPELL_SUMMON_CLOUD = 25786,            // should be 26590 -> summons 15933 -> casts 25786 ("Toxic Vapors") in EventAI
    // the trigger that spawns was meleeing players and keeping them in combat, some better way to make it non-aggro?
    // yauj
    SPELL_RAVAGE = 24213,
    SPELL_HEAL = 25807,
    SPELL_FEAR = 19408,            // should be spell 25807, but will need to fix that spell fearing 1 person max first

    // vem
    SPELL_CHARGE = 26561,
    SPELL_KNOCKBACK = 18813,
    SPELL_KNOCKDOWN = 19128,
    SPELL_VENGEANCE = 25790,
};


//  Base class for handling shared mechanics
struct boss_bug_trioAI : public ScriptedAI
{
    boss_bug_trioAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;
    uint32 m_uiDevourTimer;
    uint32 m_uiEvadeCheckTimer;
    bool   m_bIsEating;

    void Reset() override
    {
        m_bIsEating = false;
        m_uiEvadeCheckTimer = 2500;
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_BUG_TRIO, FAIL);
    }

    void EnterEvadeMode() override
    {
        // If somehow a raid wipes during devour phase, restore normal speed/behavior
        m_creature->UpdateSpeed(MOVE_RUN, false);
        ScriptedAI::EnterEvadeMode();
    }

    void Aggro(Unit* /*pWho*/) override
    {
        // Reset the slain bug count on pull
        if (m_pInstance)
            m_pInstance->SetData(TYPE_BUG_TRIO, IN_PROGRESS);
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        // The bug trio have a larger than normal aggro radius
        if (pWho->GetTypeId() == TYPEID_PLAYER && !m_creature->IsInCombat() && m_creature->IsWithinDistInMap(pWho, 60.0f) && m_creature->IsWithinLOSInMap(pWho) && !pWho->HasAuraType(SPELL_AURA_FEIGN_DEATH))
        {
            AttackStart(pWho);
        }
        ScriptedAI::MoveInLineOfSight(pWho);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        // If another bug is still alive, prevent looting and trigger corpse despawn
        m_pInstance->SetData(TYPE_BUG_TRIO, SPECIAL);
        if (m_pInstance->GetData(TYPE_BUG_TRIO) != DONE)
        {
            m_creature->SetLootRecipient(nullptr);
            m_creature->ForcedDespawn(4000);

            if (Creature* pKri = m_pInstance->GetSingleCreatureFromStorage(NPC_KRI))
                if (boss_bug_trioAI* pFakerAI = dynamic_cast<boss_bug_trioAI*>(pKri->AI()))
                    pFakerAI->TriggerDevour(m_creature);
            if (Creature* pYauj = m_pInstance->GetSingleCreatureFromStorage(NPC_PRINCESS_YAUJ))
                if (boss_bug_trioAI* pFakerAI = dynamic_cast<boss_bug_trioAI*>(pYauj->AI()))
                    pFakerAI->TriggerDevour(m_creature);
            if (Creature* pVem = m_pInstance->GetSingleCreatureFromStorage(NPC_VEM))
                if (boss_bug_trioAI* pFakerAI = dynamic_cast<boss_bug_trioAI*>(pVem->AI()))
                    pFakerAI->TriggerDevour(m_creature);
        }
    }

    void CorpseRemoved(uint32& /*uiRespawnDelay*/) override
    {
        // Emote on devoured
        DoScriptText(EMOTE_DEVOUR, m_creature);
    }

    void MovementInform(uint32 uiMotionType, uint32 /*uiPointId*/) override
    {
        if (uiMotionType != POINT_MOTION_TYPE)
            return;

        // Stop movement after reaching corpse
        m_creature->GetMotionMaster()->MoveIdle();
    }

    void TriggerDevour(Unit* pWho)
    {
        if (m_creature->IsAlive())
        {
            m_uiDevourTimer = 4000;
            m_bIsEating = true;

            // Sprint to dead bug and clear target
            m_creature->UpdateSpeed(MOVE_RUN, true, 2.7f);
            m_creature->GetMotionMaster()->MovePoint(1, pWho->GetPositionX(), pWho->GetPositionY(), pWho->GetPositionZ());
            m_creature->SetTargetGuid(ObjectGuid());
        }
    }

    void LeashEncounter()
    {
        // Force evade all 3 bugs and respawn any that are already dead. We have to do this manually or linked bugs don't evade/respawn on region triggered EnterEvadeMode.
        if (Creature* pKri = m_pInstance->GetSingleCreatureFromStorage(NPC_KRI))
        {
            if (pKri->IsDead())
                pKri->Respawn();
            else
                pKri->AI()->EnterEvadeMode();
        }
        if (Creature* pYauj = m_pInstance->GetSingleCreatureFromStorage(NPC_PRINCESS_YAUJ))
        {
            if (pYauj->IsDead())
                pYauj->Respawn();
            else
                pYauj->AI()->EnterEvadeMode();
        }
        if (Creature* pVem = m_pInstance->GetSingleCreatureFromStorage(NPC_VEM))
        {
            if (pVem->IsDead())
                pVem->Respawn();
            else
                pVem->AI()->EnterEvadeMode();
        }
    }

    virtual bool UpdateBugAI(uint32 const /*uiDiff*/) { return true; }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_bIsEating)
        {
            if (m_uiDevourTimer < uiDiff)
            {
                // Reset threat, heal to full, restore target, and remove temporary speed buff
                DoResetThreat();
                m_bIsEating = false;
                m_creature->SetHealth(m_creature->GetMaxHealth());
                m_creature->SetTargetGuid(m_creature->GetVictim()->GetObjectGuid());
                m_creature->UpdateSpeed(MOVE_RUN, false);
                DoStartMovement(m_creature->GetVictim());
            }
            else
            {
                m_uiDevourTimer -= uiDiff;
                return;
            }
        }

        // Call bug specific virtual function
        if (!UpdateBugAI(uiDiff))
            return;

        DoMeleeAttackIfReady();

        // Evade if any bug leaves the room
        if (m_uiEvadeCheckTimer < uiDiff)
        {
            m_uiEvadeCheckTimer = 2500;
            if (m_creature->GetPositionY() < 2060 && m_creature->GetPositionX() > -8600)
                LeashEncounter();
        }
        else
            m_uiEvadeCheckTimer -= uiDiff;
    }
};

//##########
// LORD KRI
//##########

struct boss_kriAI : public boss_bug_trioAI
{
    boss_kriAI(Creature* pCreature) : boss_bug_trioAI(pCreature) { Reset(); }

    uint32 m_uiThrashTimer;
    uint32 m_uiCleaveTimer;
    uint32 m_uiToxicVolleyTimer;

    void Reset() override
    {
        m_uiCleaveTimer = urand(4000, 8000);
        m_uiThrashTimer = urand(4000, 7000);
        m_uiToxicVolleyTimer = urand(8000, 10000);
    }

    void JustDied(Unit* pKiller) override
    {
        // Spawn Poison Cloud on death
        DoCastSpellIfCan(m_creature, SPELL_SUMMON_CLOUD, CF_TRIGGERED);
        boss_bug_trioAI::JustDied(pKiller);
    }

    bool UpdateBugAI(uint32 const uiDiff) override
    {
        // Cleave
        if (m_uiCleaveTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                m_uiCleaveTimer = urand(5000, 12000);
        }
        else
            m_uiCleaveTimer -= uiDiff;

        // Toxic Volley
        if (m_uiToxicVolleyTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_TOXIC_VOLLEY) == CAST_OK)
                m_uiToxicVolleyTimer = urand(8000, 14000);
        }
        else
            m_uiToxicVolleyTimer -= uiDiff;

        // Thrash
        if (m_uiThrashTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_THRASH) == CAST_OK)
                m_uiThrashTimer = urand(2000, 8000);
        }
        else
            m_uiThrashTimer -= uiDiff;

        return true;
    }
};

//###############
// PRINCESS YAUJ
//###############

struct boss_yaujAI : public boss_bug_trioAI
{
    boss_yaujAI(Creature* pCreature) : boss_bug_trioAI(pCreature) { Reset(); }

    uint32 m_uiHealTimer;
    uint32 m_uiFearTimer;
    uint32 m_uiRavageTimer;

    void Reset() override
    {
        m_uiHealTimer = urand(10000, 20000);
        m_uiFearTimer = urand(10000, 20000);
        m_uiRavageTimer = urand(4000, 9000);
    }

    void SpellHit(Unit* /*pCaster*/, SpellEntry const* pSpellEntry) override
    {
        // Yauj is immune to Curse of Tongues and Mind-Numbing Poison. These spells don't have a mechanic type to set an immunity mask to in vanilla so we simply remove them.
        if (m_creature->HasAuraType(SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK))
            m_creature->RemoveSpellsCausingAura(SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK);
    }

    void JustDied(Unit* pKiller) override
    {
        // Spawn 10 Yauj Brood on death
        float fX, fY, fZ;
        float const aCenterLoc[3] = { -8590.0f, 2138.0f, 0.0f };                    // define a central point in the room to use for LOS check

        for (int i = 0; i < 10; ++i)
        {
            m_creature->GetRandomPoint(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 40.0f, fX, fY, fZ);
            // prevent Yauj Brood from spawning under the world or in walls -- re-roll if random point is not in LOS
            if (m_creature->GetMap()->isInLineOfSight(aCenterLoc[0], aCenterLoc[1], aCenterLoc[2], fX, fY, fZ))
                m_creature->SummonCreature(NPC_YAUJ_BROOD, fX, fY, fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
            else
                --i;
        }
        boss_bug_trioAI::JustDied(pKiller);
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() != NPC_YAUJ_BROOD)
            return;

        pSummoned->SetInCombatWithZone();
    }

    bool UpdateBugAI(uint32 const uiDiff) override
    {
        // Fear
        if (m_uiFearTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_FEAR) == CAST_OK)
            {
                DoResetThreat();
                m_uiFearTimer = 20000;
            }
        }
        else
            m_uiFearTimer -= uiDiff;

        // Heal
        if (m_uiHealTimer < uiDiff)
        {
            // Yauj prioritizes herself with heal when under 93%
            if (m_creature->GetHealthPercent() <= 93.0f)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_HEAL) == CAST_OK)
                    m_uiHealTimer = 12000;
            }
            else if (Unit* pTarget = m_creature->FindLowestHpFriendlyUnit(100.0f))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_HEAL) == CAST_OK)
                    m_uiHealTimer = 12000;
            }
        }
        else
            m_uiHealTimer -= uiDiff;

        // Ravage
        if (m_uiRavageTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_RAVAGE) == CAST_OK)
                m_uiRavageTimer = urand(12000, 20000);
        }
        else
            m_uiRavageTimer -= uiDiff;

        return true;
    }
};

//#####
// VEM 
//#####

struct boss_vemAI : public boss_bug_trioAI
{
    boss_vemAI(Creature* pCreature) : boss_bug_trioAI(pCreature) { Reset(); }

    uint32 m_uiChargeTimer;
    uint32 m_uiKnockBackTimer;
    uint32 m_uiKnockdownTimer;

    void Reset() override
    {
        m_uiChargeTimer = urand(10000, 15000);
        m_uiKnockBackTimer = urand(15000, 20000);
        m_uiKnockdownTimer = urand(5000, 8000);
    }

    void JustDied(Unit* pKiller) override
    {
        // Enrage the other bugs on death
        DoCastSpellIfCan(m_creature, SPELL_VENGEANCE, CF_TRIGGERED);
        boss_bug_trioAI::JustDied(pKiller);
    }

    void SpellHitTarget(Unit* pTarget, SpellEntry const* pSpell) override
    {
        if ((pSpell->Id == SPELL_KNOCKBACK) && pTarget->GetTypeId() == TYPEID_PLAYER)
        {
            if (m_creature->GetThreatManager().getThreat(m_creature->GetVictim()))
                m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -80);
        }
    }

    bool UpdateBugAI(uint32 const uiDiff) override
    {
        // Charge
        if (m_uiChargeTimer < uiDiff)
        {
            // Only charge targets outside of melee range
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_CHARGE, SELECT_FLAG_NOT_IN_MELEE_RANGE))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_CHARGE) == CAST_OK)
                    m_uiChargeTimer = urand(15000, 20000);
            }
        }
        else
            m_uiChargeTimer -= uiDiff;

        // Knock Away
        if (m_uiKnockBackTimer < uiDiff)
        {
            if (m_creature->CanReachWithMeleeAutoAttack(m_creature->GetVictim()) && !m_creature->GetVictim()->HasUnitState(UNIT_STAT_STUNNED))
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCKBACK) == CAST_OK)
                    m_uiKnockBackTimer = urand(10000, 14000);
            }
        }
        else
            m_uiKnockBackTimer -= uiDiff;

        // Knockdown
        if (m_uiKnockdownTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_KNOCKDOWN, SELECT_FLAG_IN_MELEE_RANGE))
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCKDOWN) == CAST_OK)
                    m_uiKnockdownTimer = urand(15000, 20000);
            }
        }
        else
            m_uiKnockdownTimer -= uiDiff;

        return true;
    }
};

CreatureAI* GetAI_boss_kri(Creature* pCreature)
{
    return new boss_kriAI(pCreature);
}

CreatureAI* GetAI_boss_yauj(Creature* pCreature)
{
    return new boss_yaujAI(pCreature);
}

CreatureAI* GetAI_boss_vem(Creature* pCreature)
{
    return new boss_vemAI(pCreature);
}


void AddSC_bug_trio()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_kri";
    pNewScript->GetAI = &GetAI_boss_kri;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_yauj";
    pNewScript->GetAI = &GetAI_boss_yauj;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_vem";
    pNewScript->GetAI = &GetAI_boss_vem;
    pNewScript->RegisterSelf();
}
