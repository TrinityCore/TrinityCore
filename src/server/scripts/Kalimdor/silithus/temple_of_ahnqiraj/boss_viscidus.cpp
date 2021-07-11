/*
 * Copyright (C) 2006-2011 ScriptDev2 <http://www.scriptdev2.com/>
 * Copyright (C) 2010-2011 ScriptDev0 <http://github.com/mangos-zero/scriptdev0>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Viscidus
SD%Complete: 90
SDComment: ToDo: Use aura proc to handle freeze event instead of direct function
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "scriptPCH.h"
#include "temple_of_ahnqiraj.h"
#include <bitset>

enum
{
    // emotes
    EMOTE_SLOW                  = -1531041, // Viscidus begins to slow.
    EMOTE_FREEZE                = -1531042, // Viscidus is freezing up.
    EMOTE_FROZEN                = -1531043, // Viscidus is frozen solid.
    // These are currently handled in UnitAuraProcHandler.cpp.
    EMOTE_CRACK                 = -1531044, // Viscidus begins to crack.
    EMOTE_SHATTER               = -1531045, // Viscidus looks ready to shatter.

    // Timer spells
    SPELL_POISON_SHOCK          = 25993,
    SPELL_POISONBOLT_VOLLEY     = 25991,
    SPELL_TOXIN                 = 26575,                    // Triggers toxin cloud - 25989
    SPELL_TOXIN_CLOUD           = 25989,

    // Debuffs gained by the boss on frost damage
    SPELL_VISCIDUS_SLOWED       = 26034,
    SPELL_VISCIDUS_SLOWED_MORE  = 26036,
    SPELL_VISCIDUS_FREEZE       = 25937,

    // When frost damage exceeds a certain limit, then boss explodes
    SPELL_REJOIN_VISCIDUS       = 25896,
    SPELL_VISCIDUS_EXPLODE      = 25938,
    SPELL_VISCIDUS_SUICIDE      = 26003,                    // cast when boss explodes and is below 5% Hp - should trigger 26002
    SPELL_DESPAWN_GLOBS         = 26608,

    SPELL_MEMBRANE_VISCIDUS     = 25994,                    // damage reduction spell
    SPELL_VISCIDUS_WEAKNESS     = 25926,                    // aura which procs at damage - should trigger the slow spells
    SPELL_VISCIDUS_SHRINKS      = 25893,
    SPELL_VISCIDUS_SHRINKS_HP   = 27934,                    // should be scripted properly
    SPELL_VISCIDUS_GROWS        = 25897,
    SPELL_SUMMON_GLOBS          = 25885,                    // summons npc 15667 using spells from 25865 to 25884; All spells have target coords
    SPELL_VISCIDUS_TELEPORT     = 25904,                    // teleport to room center
    SPELL_SUMMONT_TRIGGER       = 26564,                    // summons 15922

    SPELL_GLOB_SPEED            = 26633,                    // apply aura 26634 each second
    
    NPC_GLOB_OF_VISCIDUS        = 15667,
    NPC_VISCIDUS_TRIGGER        = 15922,                    // handles aura 26575

    MAX_VISCIDUS_GLOBS          = 20,                       // there are 20 summoned globs; each glob = 5% hp

    // hitcounts
    HITCOUNT_SLOW               = 100,
    HITCOUNT_SLOW_MORE          = 150,
    HITCOUNT_FREEZE             = 200,

    // phases
    PHASE_NORMAL                = 1,
    PHASE_FROZEN                = 2,
    PHASE_EXPLODED              = 3,

    SPELL_WAND_SHOOT            = 5019,
};

static uint32 const auiGlobSummonSpells[MAX_VISCIDUS_GLOBS] = { 25865, 25866, 25867, 25868, 25869, 25870, 25871, 25872, 25873, 25874, 25875, 25876, 25877, 25878, 25879, 25880, 25881, 25882, 25883, 25884 };

//-----------------------------------------------------------------------------
// mob_viscidus_globAI
//-----------------------------------------------------------------------------
struct mob_viscidus_globAI : public ScriptedAI
{
    // Acceleration delay
    uint32 m_uiGlobStartAccelerationTimer;
    // prevents SPELL_GLOB_SPEED casting multiple times
    bool m_spellCasted;

    // Everything is an approximated here. Need data from official.
    // Initial glob speed is 0.335625. They start acceleration with 4 seconds delay timer.
    // Each tick of the aura(id:26634) doubles their speed.
    // This solution gives smooth movement and acceleration.

    mob_viscidus_globAI(Creature* pCreature)
        : ScriptedAI(pCreature), m_uiGlobStartAccelerationTimer(4000), m_spellCasted(false)
    { }

    // dummy methods
    void Reset() override { }
    void AttackStart(Unit* /*pWho*/) override { }
    void MoveInLineOfSight(Unit* /*pWho*/) override { }

    // Implements acceleration on timer, prevents combat.
    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiGlobStartAccelerationTimer <= uiDiff)
        {
            // SPELL_GLOB_SPEED should be casted only once
            if (!m_spellCasted)
            {
                m_spellCasted = true;
                m_creature->CastSpell(m_creature, SPELL_GLOB_SPEED, true);
            }
        }
        else
        {
            m_uiGlobStartAccelerationTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_mob_viscidus_glob(Creature* pCreature)
{
    return new mob_viscidus_globAI(pCreature);
}

//-----------------------------------------------------------------------------
// mob_viscidus_triggerAI
//-----------------------------------------------------------------------------
struct mob_viscidus_triggerAI : public ScriptedAI
{
    // Acceleration delay
    uint32 m_uiToxinDelayTimer;
    bool m_spellCasted;

    mob_viscidus_triggerAI(Creature* pCreature)
     : ScriptedAI(pCreature), m_uiToxinDelayTimer(3000), m_spellCasted(false)
    { }

    // dummy methods
    void Reset() override { }
    void AttackStart(Unit* /*pWho*/) override { }
    void MoveInLineOfSight(Unit* /*pWho*/) override { }
    // Implements toxin cloud on timer, prevents combat.
    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiToxinDelayTimer <= uiDiff)
        {
            if (!m_spellCasted)
            {
                // set faction and flags before toxin cloud, so it won't damage a boss.
                m_creature->SetFactionTemplateId(14); // 14 is a hostile faction
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);

                m_spellCasted = true;
                // cast spell instantly, only once
                m_creature->CastSpell(m_creature, SPELL_TOXIN_CLOUD, true);
                // apply an aura, which will continously repeat this spell.
                m_creature->CastSpell(m_creature, SPELL_TOXIN, true);
            }
        }
        else
        {
            m_uiToxinDelayTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_mob_viscidus_trigger(Creature* pCreature)
{
    return new mob_viscidus_triggerAI(pCreature);
}

//-----------------------------------------------------------------------------
// boss_viscidusAI
//-----------------------------------------------------------------------------
struct boss_viscidusAI : public ScriptedAI
{
    ScriptedInstance* m_pInstance;

    uint32 m_uiRestoreTargetTimer;

    uint32 m_uiHitCount;
    uint32 m_uiToxinTimer;
    uint32 m_uiExplodeDelayTimer;
    uint32 m_uiPoisonShockTimer;
    uint32 m_uiPoisonBoltVolleyTimer;

    uint32 m_uiPhaseTimer;
    uint16 m_uiGrowTimer;
    uint8  m_uiPhase;

    float m_initialScale;
    uint8 m_uiGrowCount;

    GuidList m_lGlobesGuidList;
    std::bitset<20> track;

    boss_viscidusAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_initialScale = pCreature->GetObjectScale();
        Reset();
    }

    void Reset() override
    {
        m_uiGrowTimer = 0;
        m_uiPhase                 = PHASE_NORMAL;
        m_uiPhaseTimer            = 0;

        m_uiRestoreTargetTimer    = 0;

        m_uiHitCount              = 0;
        m_uiExplodeDelayTimer     = 0;
        m_uiToxinTimer            = urand(30000, 40000);
        m_uiPoisonShockTimer      = urand(7000, 12000);
        m_uiPoisonBoltVolleyTimer = urand(10000, 15000);
        m_uiGrowCount = 0;
        m_creature->SetObjectScale(m_initialScale);
        track.reset();

        DoCastSpellIfCan(m_creature, SPELL_MEMBRANE_VISCIDUS, CF_TRIGGERED);
        DoCastSpellIfCan(m_creature, SPELL_VISCIDUS_WEAKNESS, CF_TRIGGERED);

        ResetViscidusState();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER && !m_creature->GetVictim() && m_creature->IsWithinDistInMap(who, 95.0f, true))
        {
            AttackStart(who);
        }

        ScriptedAI::MoveInLineOfSight(who);
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_VISCIDUS, IN_PROGRESS);
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_VISCIDUS, FAIL);

        DoCastSpellIfCan(m_creature, SPELL_DESPAWN_GLOBS, CF_TRIGGERED);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_VISCIDUS, DONE);
    }

    void DamageTaken(Unit* pDealer, uint32 &damage) override
    {
        if (pDealer->IsCreature() && ((Creature*)pDealer)->GetEntry() == NPC_VISCIDUS)
            return;

        // Prevent Viscidus dying to the damage taken. We cannot modify the damage to be less,
        // because it eventually hits 0. At which point any damage dealt will be considered
        // 'absorbed' and have no effect. i.e. won't be able to shatter or freeze the
        // boss once he hits 1 hp.
        if (m_creature->GetHealthPercent() < 1.0f)
            m_creature->SetHealthPercent(1.0f);
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_GLOB_OF_VISCIDUS)
        {
            // Move all summoned globs to Viscidus's spawn point. The spawn point is essentially
            // the center of the room triangulated between 4 points with a distance of 100 between
            // points on the same gridline. Globs are spawned on a circle with 52 yard radius from
            // the center point
            pSummoned->GetMotionMaster()->MovePoint(1, -7993.956f, 926.309f, -52.699f, MOVE_FORCE_DESTINATION | MOVE_PATHFINDING | MOVE_RUN_MODE);

            m_lGlobesGuidList.push_back(pSummoned->GetObjectGuid());
        }
    }

    void ResetViscidusState()
    {
        if (m_creature->GetVisibility() == VISIBILITY_OFF)
        {
            DoCast(m_creature, SPELL_VISCIDUS_TELEPORT, true);
        }

        DoResetThreat();
        m_creature->SetVisibility(VISIBILITY_ON);
        m_creature->ClearUnitState(UNIT_STAT_FEIGN_DEATH);
        m_creature->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_uiPhase = PHASE_NORMAL;
        m_uiHitCount = 0;

        SetCombatMovement(true);
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_GLOB_OF_VISCIDUS)
        {
            // should be a spell script!
            if (DoCastSpellIfCan(m_creature, SPELL_VISCIDUS_SHRINKS_HP, CF_TRIGGERED) == CAST_OK)
            {
                auto health = m_creature->GetHealth() - static_cast<uint32>((m_creature->GetMaxHealth() * 0.05f));

                if (health && health <= m_creature->GetMaxHealth())
                {
                    m_creature->SetHealth(health);
                }
                else
                {
                    m_creature->SetHealthPercent(1.0f);
                }
            }

            m_lGlobesGuidList.remove(pSummoned->GetObjectGuid());

            if (m_lGlobesGuidList.empty())
            {
                ResetViscidusState();
            }
        }
    }

    void SummonedMovementInform(Creature* pSummoned, uint32 uiType, uint32 uiPointId) override
    {
        if (pSummoned->GetEntry() != NPC_GLOB_OF_VISCIDUS || uiType != POINT_MOTION_TYPE || !uiPointId)
            return;

        m_lGlobesGuidList.remove(pSummoned->GetObjectGuid());
        pSummoned->CastSpell(m_creature, SPELL_REJOIN_VISCIDUS, true);
        pSummoned->ForcedDespawn(650);
        ++m_uiGrowCount; // should be done in spell script

        if (m_lGlobesGuidList.empty())
        {
            ResetViscidusState();
        }
    }

    void SpellHit(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (pSpell->Id == SPELL_VISCIDUS_EXPLODE)
        {
            // suicide if required
            if (m_creature->GetHealthPercent() < 5.0f)
            {
                m_creature->SetVisibility(VISIBILITY_ON);

                if (DoCastSpellIfCan(m_creature, SPELL_VISCIDUS_SUICIDE, CF_TRIGGERED) == CAST_OK)
                    m_creature->DealDamage(m_creature, m_creature->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, nullptr, false);

                return;
            }

            m_uiPhase = PHASE_EXPLODED;
            m_lGlobesGuidList.clear();
            uint32 uiGlobeCount = m_creature->GetHealthPercent() / 5.0f;

            for (uint8 i = 0; i < uiGlobeCount; ++i)
                DoCastSpellIfCan(m_creature, auiGlobSummonSpells[i], CF_TRIGGERED);

            m_uiExplodeDelayTimer = 2500; // 2500(instead of 1000) makes glob summon effect more visible
            return;
        }

        if (m_uiPhase != PHASE_NORMAL)
            return;

        bool bIsFrostSpell = pSpell->School == SPELL_SCHOOL_FROST;

        // wand special case:
        // shoot's school is physical, as long we get a SpellEntry,
        // we need to check the caster currently equiped wand
        // if it's frost damage, use a trigger spell
        if (pSpell->Id == SPELL_WAND_SHOOT)
        {
            Player const* pPlayer = dynamic_cast<Player*>(pCaster);
            if (!pPlayer)
                return;

            const Item* pItem = pPlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
            if (!pItem)
                return;

            const ItemPrototype* pProto = pItem->GetProto();

            // Wand always have 1 damage type on vanilla
            bIsFrostSpell = pProto->Damage[0].DamageType == SPELL_SCHOOL_FROST;
        }

        if (bIsFrostSpell)
        {
            ++m_uiHitCount;

            if (m_uiHitCount >= HITCOUNT_FREEZE)
            {
                m_uiPhase = PHASE_FROZEN;
                m_uiHitCount = 0;

                DoScriptText(EMOTE_FROZEN, m_creature);
                m_creature->RemoveAurasDueToSpell(SPELL_VISCIDUS_SLOWED_MORE);
                DoCastSpellIfCan(m_creature, SPELL_VISCIDUS_FREEZE, CF_TRIGGERED);
            }
            else if (m_uiHitCount >= HITCOUNT_SLOW_MORE)
            {
                if (m_uiHitCount == HITCOUNT_SLOW_MORE)
                {
                    DoScriptText(EMOTE_FREEZE, m_creature);
                    m_creature->RemoveAurasDueToSpell(SPELL_VISCIDUS_SLOWED);
                }
                DoCastSpellIfCan(m_creature, SPELL_VISCIDUS_SLOWED_MORE, CF_TRIGGERED);
            }
            else if (m_uiHitCount >= HITCOUNT_SLOW)
            {
                if (m_uiHitCount == HITCOUNT_SLOW)
                {
                    DoScriptText(EMOTE_SLOW, m_creature);
                }
                DoCastSpellIfCan(m_creature, SPELL_VISCIDUS_SLOWED, CF_TRIGGERED);
            }
        }
    }

    void ResetFrozenPhase()
    {
        if (m_uiPhase == PHASE_EXPLODED)
            return;

        // reset phase if not already exploded
        m_uiPhase = PHASE_NORMAL;
        m_uiHitCount = 0;
    }

    void HackyScaleUpdate()
    {
        auto hp = static_cast<size_t>(m_creature->GetHealthPercent() / 5);

        if (hp != track.size() && !track.test(hp))
        {
            track.set(hp);
            m_creature->CastSpell(m_creature, SPELL_VISCIDUS_SHRINKS, true);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        HackyScaleUpdate();

        // should be spell scripted properly
        if (m_uiGrowTimer <= uiDiff)
        {
            if (m_uiGrowCount)
            {
                DoCastSpellIfCan(m_creature, SPELL_VISCIDUS_GROWS, CF_TRIGGERED);
                m_creature->SetObjectScale(m_creature->GetObjectScale() + 0.04f);
                --m_uiGrowCount;
            }
            m_uiGrowTimer = 150;
        }
        else
            m_uiGrowTimer -= uiDiff;

        if (m_uiExplodeDelayTimer)
        {
            if (m_uiExplodeDelayTimer <= uiDiff)
            {
                // Make invisible
                m_creature->SetVisibility(VISIBILITY_OFF);
                m_uiExplodeDelayTimer = 0;

                // should be part of SPELL_VISCIDUS_SHRINKS_HP script!
                auto scale = m_creature->GetObjectScale();
                scale -= 0.04 * m_lGlobesGuidList.size();
                m_creature->SetObjectScale(scale);
            }
            else
                m_uiExplodeDelayTimer -= uiDiff;
        }

        // Restore original target after "casting" a Toxic Cloud near someone.
        if (m_uiRestoreTargetTimer)
        {
            if (m_uiRestoreTargetTimer <= uiDiff)
            {
                if (Unit* pTarget = m_creature->GetVictim())
                {
                    m_creature->SetInFront(pTarget);
                    m_creature->SetTargetGuid(pTarget->GetObjectGuid());
                    m_uiRestoreTargetTimer = 0;
                }
            }
            else
                m_uiRestoreTargetTimer -= uiDiff;
        }

        if (m_uiPhase != PHASE_NORMAL)
            return;

        if (m_uiPoisonShockTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_POISON_SHOCK) == CAST_OK)
                m_uiPoisonShockTimer = urand(7000, 12000);
        }
        else
            m_uiPoisonShockTimer -= uiDiff;

        if (m_uiPoisonBoltVolleyTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_POISONBOLT_VOLLEY) == CAST_OK)
                m_uiPoisonBoltVolleyTimer = urand(10000, 15000);
        }
        else
            m_uiPoisonBoltVolleyTimer -= uiDiff;

        if (m_uiToxinTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_IN_LOS))
            {
                Creature* trigger = m_creature->SummonCreature(NPC_VISCIDUS_TRIGGER, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), pTarget->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 180000);
                m_uiToxinTimer = urand(30000, 40000);

                // visual spell effect, which predates Toxin Cloud.
                if (trigger)
                {
                    // visual effect doen't work if target is not selectable...
                    trigger->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    // set boss facing to the trigger
                    m_creature->SetInFront(trigger);
                    m_creature->SetTargetGuid(trigger->GetObjectGuid());
                    // cast spell, which will be completely resisted by trigger(immune) to simulate a visual effect
                    m_creature->CastSpell(trigger, 26601, true);
                    // restore boss orientation in 800 ms
                    m_uiRestoreTargetTimer = 800;
                    // restore trigger flag
                    trigger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
            }
        }
        else
            m_uiToxinTimer -= uiDiff;

        DoMeleeAttackIfReady();

        EnterEvadeIfOutOfCombatArea(uiDiff);
    }
};

CreatureAI* GetAI_boss_viscidus(Creature* pCreature)
{
    return new boss_viscidusAI(pCreature);
}

bool EffectAuraDummy_spell_aura_dummy_viscidus_freeze(Aura const* pAura, bool bApply)
{
    // On Aura removal inform the boss
    if (pAura->GetId() == SPELL_VISCIDUS_FREEZE && pAura->GetEffIndex() == EFFECT_INDEX_1 && !bApply)
    {
        if (Creature* pTarget = (Creature*)pAura->GetTarget())
        {
            if (boss_viscidusAI* pViscidusAI = dynamic_cast<boss_viscidusAI*>(pTarget->AI()))
                pViscidusAI->ResetFrozenPhase();
        }
    }
    return true;
}

void AddSC_boss_viscidus()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_viscidus";
    pNewScript->GetAI = &GetAI_boss_viscidus;
    pNewScript->pEffectAuraDummy = &EffectAuraDummy_spell_aura_dummy_viscidus_freeze;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_viscidus_glob";
    pNewScript->GetAI = &GetAI_mob_viscidus_glob;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_viscidus_trigger";
    pNewScript->GetAI = &GetAI_mob_viscidus_trigger;
    pNewScript->RegisterSelf();
}
