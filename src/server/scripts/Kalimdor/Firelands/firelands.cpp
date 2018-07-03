/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "Creature.h"
#include "firelands.h"
#include "GridNotifiers.h"
#include "Vehicle.h"
#include "MotionMaster.h"

enum Spells
{
    // Baleroc Trash
    SPELL_FLAME_TORRENT             = 100795,
    SPELL_FIERY_TORMENT             = 100797,
    SPELL_FIERY_TORMENT_DAMAGE      = 100802,
    SPELL_EARTHQUAKE                = 100724,
    SPELL_MAGMA_CONDUIT             = 100728,
    SPELL_ERUPTION                  = 100755,
    SPELL_SUMMON_MAGMAKIN           = 100746,

    // Legendary questline
    SPELL_SMOULDERING_QUEST_CHECK_A = 101089, // Alliance - Unverified
    SPELL_SMOULDERING_QUEST_CHECK_H = 101092  // Horde - Unverified
};

bool DelayedAttackStartEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    _owner->AI()->DoZoneInCombat(_owner, 200.0f);
    return true;
}

bool DelayedSpellCastEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    _owner->CastSpell(_target, _spellId, _triggered);
    return true;
}

void firelands_bossAI::EnterCombat(Unit* target)
{
    BossAI::EnterCombat(target);
    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
}

void firelands_bossAI::JustDied(Unit* killer)
{
    BossAI::JustDied(killer);
    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    me->m_Events.AddEvent(new DelayedSpellCastEvent(me, static_cast<Unit*>(nullptr), SPELL_SMOULDERING_1, false), me->m_Events.CalculateTime(2 * IN_MILLISECONDS));
    me->m_Events.AddEvent(new DelayedSpellCastEvent(me, static_cast<Unit*>(nullptr), SPELL_SMOULDERING_2, false), me->m_Events.CalculateTime(2 * IN_MILLISECONDS));
}

void firelands_bossAI::EnterEvadeMode(EvadeReason why)
{
    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

    // Copy paste ScriptedAI::EnterEvadeMode functionality to exclude Reset function call
    if (!_EnterEvadeMode(why))
        return;

    if (!me->GetVehicle()) // otherwise me will be in evade mode forever
    {
        if (Unit* owner = me->GetCharmerOrOwner())
        {
            me->GetMotionMaster()->Clear(false);
            me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle(), MOTION_SLOT_ACTIVE);
        }
        else
        {
            // Required to prevent attacking creatures that are evading and cause them to reenter combat
            // Does not apply to MoveFollow
            me->AddUnitState(UNIT_STATE_EVADE);
            me->GetMotionMaster()->MoveTargetedHome();
        }
    }

    // Copy paste reason
    //Reset();

    if (me->IsVehicle()) // use the same sequence of addtoworld, aireset may remove all summons!
        me->GetVehicleKit()->Reset(true);

    _DespawnAtEvade();
}

// http://www.wowhead.com/npc=54161/flame-archon
struct npc_firelands_flame_archon : public ScriptedAI
{
    npc_firelands_flame_archon(Creature* creature) : ScriptedAI(creature)
    {
        scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void EnterCombat(Unit* /*attacker*/) override
    {
        scheduler.Schedule(Seconds(10), Seconds(12), [this](TaskContext context)
        {
            DoCastAOE(SPELL_FLAME_TORRENT);
            context.Repeat(Seconds(15), Seconds(17));
        });
        scheduler.Schedule(Seconds(25), [this](TaskContext context)
        {
            DoCastAOE(SPELL_FIERY_TORMENT);
            context.Repeat(Seconds(45));
        });
    }

    void JustDied(Unit* killer) override
    {
        scheduler.CancelAll();
        ScriptedAI::JustDied(killer);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        scheduler.CancelAll();
        ScriptedAI::EnterEvadeMode(why);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler scheduler;
};

// http://www.wowhead.com/npc=54143/molten-flamefather
struct npc_firelands_molten_flamefather : public ScriptedAI
{
    npc_firelands_molten_flamefather(Creature* creature) : ScriptedAI(creature)
    {
        scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() != NPC_MAGMA_CONDUIT)
            return;

        summon->CastSpell(summon, SPELL_SUMMON_MAGMAKIN);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() != NPC_MAGMA_CONDUIT)
            return;

        summon->DespawnOrUnsummon();
    }

    void EnterCombat(Unit* /*attacker*/) override
    {
        scheduler.Schedule(Seconds(5), [this](TaskContext context)
        {
            DoCastAOE(SPELL_MAGMA_CONDUIT);
            if (Is25ManRaid())
                DoCastAOE(SPELL_MAGMA_CONDUIT);
            context.Repeat(Seconds(25));
        });
        scheduler.Schedule(Milliseconds(12800), [this](TaskContext context)
        {
            DoCastAOE(SPELL_EARTHQUAKE);
            context.Repeat(Milliseconds(32500));
        });
    }

    void JustDied(Unit* killer) override
    {
        scheduler.CancelAll();
        ScriptedAI::JustDied(killer);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        scheduler.CancelAll();
        ScriptedAI::EnterEvadeMode(why);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler scheduler;
};

// http://www.wowhead.com/npc=54144/magmakin
struct npc_firelands_magmakin : public ScriptedAI
{
    npc_firelands_magmakin(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        //Not actually sniffed behavior
        Unit* target = me->SelectNearestTarget(50.0f, true);
        if (!target)
            return;

        me->AddThreat(target, 50000000.0f);
        me->TauntApply(target);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        DoSpellAttackIfReady(SPELL_ERUPTION);
    }
};

// http://www.wowhead.com/spell=100799/fiery-torment
class spell_firelands_fiery_torment : public SpellScript
{
    PrepareSpellScript(spell_firelands_fiery_torment);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FIERY_TORMENT_DAMAGE });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_FIERY_TORMENT_DAMAGE, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), true));
        targets.resize(1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_firelands_fiery_torment::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_firelands_fiery_torment::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// http://www.wowhead.com/spell=101089/smouldering
// http://www.wowhead.com/spell=101092/smouldering
class spell_firelands_smouldering : public SpellScript
{
    PrepareSpellScript(spell_firelands_smouldering);

    void CheckQuestStatus(std::list<WorldObject*>& targets)
    {
        uint32 questId = 0;
        switch (GetSpellInfo()->Id)
        {
            case SPELL_SMOULDERING_QUEST_CHECK_A:
                questId = QUEST_HEART_OF_FLAME_A;
                break;
            case SPELL_SMOULDERING_QUEST_CHECK_H:
                questId = QUEST_HEART_OF_FLAME_H;
                break;
            default:
                break;
        }

        bool raidHasQuest = targets.end() != std::find_if(targets.begin(), targets.end(), [questId](WorldObject* worldObject)
        {
            if (Player* player = worldObject->ToPlayer())
                if (player->GetQuestStatus(questId) == QUEST_STATUS_INCOMPLETE)
                    return true;

            return false;
        });

        targets.clear();
        if (raidHasQuest)
            targets.push_back(GetCaster());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_firelands_smouldering::CheckQuestStatus, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// http://www.wowhead.com/spell=101093/smouldering
class spell_firelands_smouldering_aura : public SpellScript
{
    PrepareSpellScript(spell_firelands_smouldering_aura);

    void SetTarget(WorldObject*& target)
    {
        target = GetCaster();
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_firelands_smouldering_aura::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

void AddSC_firelands()
{
    RegisterFirelandsAI(npc_firelands_flame_archon);
    RegisterFirelandsAI(npc_firelands_molten_flamefather);
    RegisterFirelandsAI(npc_firelands_magmakin);
    RegisterSpellScript(spell_firelands_fiery_torment);
    RegisterSpellScript(spell_firelands_smouldering);
    RegisterSpellScript(spell_firelands_smouldering_aura);
}
