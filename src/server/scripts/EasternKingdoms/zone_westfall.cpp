/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "CombatAI.h"
#include "CreatureAIImpl.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "SharedDefines.h"

class spell_westfall_unbound_energy : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Unit* caster = GetCaster();
        targets.remove_if([caster](WorldObject const* target)->bool
        {
            return caster == target;
        });

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_westfall_unbound_energy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

enum ItsAlive
{
    // Events
    EVENT_CHECK_AREA                = 1,
    EVENT_DESPAWN_HARVESTER         = 2,

    // Texts
    SAY_ANNOUNCE_OUT_OF_AREA        = 0,

    // Area Ids
    AREA_ID_THE_MOEST_FARM          = 918,

    // Creatures
    NPC_ENERGIZED_HARVEST_REAPER    = 42342,
    NPC_OVERLOADED_HARVEST_GOLEM    = 42601
};

struct npc_westfall_overloaded_harvest_golem : public VehicleAI
{
    npc_westfall_overloaded_harvest_golem(Creature* creature) : VehicleAI(creature) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_CHECK_AREA, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHECK_AREA:
                    if (me->GetAreaId() != AREA_ID_THE_MOEST_FARM)
                    {
                        if (Unit* owner = me->GetCharmerOrOwner())
                            Talk(SAY_ANNOUNCE_OUT_OF_AREA, owner);
                        _events.ScheduleEvent(EVENT_DESPAWN_HARVESTER, 8s);
                    }
                    else
                        _events.Repeat(1s);
                    break;
                case EVENT_DESPAWN_HARVESTER:
                    if (me->GetAreaId() != AREA_ID_THE_MOEST_FARM)
                        me->DespawnOrUnsummon();
                    else
                        _events.ScheduleEvent(EVENT_CHECK_AREA, 1s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

class spell_westfall_reaping_blows : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Creature* reaper = GetTarget()->FindNearestCreature(NPC_ENERGIZED_HARVEST_REAPER, 5.f, true))
            GetTarget()->CastSpell(reaper, GetSpellInfo()->Effects[EFFECT_1].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_westfall_reaping_blows::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_westfall_wake_harvest_golem : public SpellScript
{
    SpellCastResult CheckTarget()
    {
        Unit* target = GetExplTargetUnit();
        if (!target || !target->IsCreature())
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->IsPlayer())
            return;

        if (Creature* target = GetHitCreature())
        {
            caster->ToPlayer()->KilledMonsterCredit(NPC_OVERLOADED_HARVEST_GOLEM);
            target->DespawnOrUnsummon(100ms);
        }
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_westfall_wake_harvest_golem::CheckTarget);
        OnEffectHitTarget.Register(&spell_westfall_wake_harvest_golem::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_westfall_quest_credit_jangolode_event : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->ExitVehicle();
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_westfall_quest_credit_jangolode_event::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum HoboGossip
{
    GOSSIP_MENU_ID_HOBO = 11635
};

enum HoboGossipOption
{
    OPTION_QUESTION = 0,
    OPTION_PAY      = 1,
};

enum HoboQuest
{
    QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME = 26209
};

enum HoboQuestObjective
{
    CLUE1 = 0,
    CLUE2 = 1,
    CLUE3 = 2,
    CLUE4 = 3
};

enum HoboSpell
{
    SPELL_HOBO_INFORMATION_1         = 79181,
    SPELL_HOBO_INFORMATION_2         = 79182,
    SPELL_HOBO_INFORMATION_3         = 79183,
    SPELL_HOBO_INFORMATION_4         = 79184,
    SPELL_SUMMON_RAGAMUFFIN_LOOTER   = 79169,
    SPELL_SUMMON_RAGAMUFFIN_LOOTER_1 = 79170,
    SPELL_SUMMON_RAGAMUFFIN_LOOTER_2 = 79171,
    SPELL_SUMMON_RAGAMUFFIN_LOOTER_3 = 79172,
    SPELL_SUMMON_RAGAMUFFIN_LOOTER_4 = 79173,
    SPELL_AGGRO_HOBO                 = 79168
};

enum HoboText
{
    SAY_CLUE1          = 0,
    SAY_CLUE2          = 1,
    SAY_CLUE3          = 2,
    SAY_CLUE4          = 3,
    SAY_AGGRO_BRIBE    = 4,
    SAY_AGGRO_CONVINCE = 5,
    SAY_EVENT          = 6,
    SAY_JACKPOT_INTRO  = 7,
    SAY_JACKPOT_END    = 8,
    SAY_PROPERTY_RAGE  = 9,
    SAY_FLEE           = 10
};

enum HoboEvent
{
    EVENT_TALK           = 1,
    EVENT_JACKPOT_INTRO  = 2,
    EVENT_CRY            = 3,
    EVENT_PROPERTY_RAGE  = 4,
    EVENT_JACKPOT_MIDDLE = 5,
    EVENT_JACKPOT_END    = 6,
    EVENT_RESUME_MOVE    = 7,
    EVENT_GROUP_OOC      = 1
};

enum HoboCreature
{
    NPC_HOMELESS_STORMWIND_CITIZEN_1 = 42386,
    NPC_HOMELESS_STORMWIND_CITIZEN_2 = 42384,
    NPC_WEST_PLAINS_DRIFTER          = 42391,
    NPC_TRANSIENT                    = 42383
};

enum HoboAction
{
    ACTION_AGGRO_HOBO      = 1,
    ACTION_AGGRO_HOBO_DONE = 2
};

struct npc_westfall_hobo_witness : public ScriptedAI
{
    npc_westfall_hobo_witness(Creature* creature) : ScriptedAI(creature), _bribeFailed(false), _hoboRage(false), _flee(false) { }

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        uint8 clueGainChance = 0;
        switch (gossipListId)
        {
           case OPTION_QUESTION:
           {
               clueGainChance = 25;
               break;
           }
           case OPTION_PAY:
           {
               clueGainChance = 75;
               _bribeFailed = true;
               break;
           }
           default:
               return true;
        }

        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        CloseGossipMenuFor(player);
        if (roll_chance_i(clueGainChance))
            GiveClue(player);
        else
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            AttackStart(player);
        }

        return false;
    }

    void GiveClue(Player* player)
    {
        if (!player)
            return;

        _events.CancelEventGroup(EVENT_GROUP_OOC);
        me->SetFacingToObject(player);

        uint16 slot = player->FindQuestSlot(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME);
        
        if (player->GetQuestSlotCounter(slot, CLUE1) == 0)
        {
            player->CastSpell(player, SPELL_HOBO_INFORMATION_1);
            Talk(SAY_CLUE1, player);
            me->DespawnOrUnsummon(12s);
            return;
        }
        
        if (player->GetQuestSlotCounter(slot, CLUE2) == 0)
        {
            player->CastSpell(player, SPELL_HOBO_INFORMATION_2);
            Talk(SAY_CLUE2, player);
            me->DespawnOrUnsummon(12s);
            return;
        }
        
        if (player->GetQuestSlotCounter(slot, CLUE3) == 0)
        {
            player->CastSpell(player, SPELL_HOBO_INFORMATION_3);
            Talk(SAY_CLUE3, player);
            me->DespawnOrUnsummon(12s);
            return;
        }
        
        if (player->GetQuestSlotCounter(slot, CLUE4) == 0)
        {
            player->CastSpell(player, SPELL_HOBO_INFORMATION_4);
            Talk(SAY_CLUE4, player);
            me->DespawnOrUnsummon(12s);
            return;
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        me->SetAIAnimKitId(0);
        _events.CancelEventGroup(EVENT_GROUP_OOC);

        if (!who->IsPlayer())
            return;

        Talk(_bribeFailed ? SAY_AGGRO_BRIBE : SAY_AGGRO_CONVINCE, who);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (!_flee && me->HealthBelowPctDamaged(20, damage))
        {
            _flee = true;
            me->DoFleeToGetAssistance();
            Talk(SAY_FLEE);
        }
    }

    void JustDied(Unit* who) override
    {
        if (who->IsCreature() && who->ToCreature()->IsAIEnabled)
            who->ToCreature()->AI()->DoAction(ACTION_AGGRO_HOBO_DONE);
        me->CastSpell(me, SPELL_SUMMON_RAGAMUFFIN_LOOTER);
    }
   
    void Reset() override
    {
        ScriptedAI::Reset();
        _events.Reset();
        _bribeFailed = false;
        _hoboRage = false;
        _flee = false;
        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        _events.ScheduleEvent(EVENT_RESUME_MOVE, 0, EVENT_GROUP_OOC);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_AGGRO_HOBO:
                if (Unit* target = ObjectAccessor::GetUnit(*me, _targetGUID))
                {
                    _hoboRage = true;
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    me->PauseMovement();
                    me->SetFacingToObject(target);
                    AttackStart(target);
                }
                break;
            case ACTION_AGGRO_HOBO_DONE:
                _hoboRage = false;
                break;
            default:
                return;
        }
    }

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        _targetGUID = guid;
        DoAction(ACTION_AGGRO_HOBO);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TALK:
                    me->PauseMovement();
                    Talk(SAY_EVENT);
                    _events.ScheduleEvent(EVENT_RESUME_MOVE, 6s, EVENT_GROUP_OOC);
                    break;
                case EVENT_JACKPOT_INTRO:
                    me->PauseMovement();
                    Talk(SAY_JACKPOT_INTRO);
                    _events.ScheduleEvent(EVENT_JACKPOT_MIDDLE, 2s + 500ms, EVENT_GROUP_OOC);
                    break;
                case EVENT_JACKPOT_MIDDLE:
                    me->SetAIAnimKitId(648);
                    Talk(SAY_JACKPOT_END);
                    _events.ScheduleEvent(EVENT_JACKPOT_END, 6s, EVENT_GROUP_OOC);
                    break;
                case EVENT_JACKPOT_END:
                    me->SetAIAnimKitId(0);
                    _events.ScheduleEvent(EVENT_RESUME_MOVE, 4s, EVENT_GROUP_OOC);
                    break;
                case EVENT_CRY:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
                    me->PauseMovement();
                    _events.ScheduleEvent(EVENT_RESUME_MOVE, 2s, EVENT_GROUP_OOC);
                    break;
                case EVENT_PROPERTY_RAGE:
                {
                    uint32 creatureId = RAND(NPC_HOMELESS_STORMWIND_CITIZEN_1, NPC_HOMELESS_STORMWIND_CITIZEN_2, NPC_WEST_PLAINS_DRIFTER, NPC_TRANSIENT);
                    if (Creature* creature = GetClosestCreatureWithEntry(me, creatureId, 25.0f))
                    {
                        if (!creature->IsAlive() || creature->IsInCombat())
                        {
                            _events.ScheduleEvent(EVENT_RESUME_MOVE, 0, EVENT_GROUP_OOC);
                            return;
                        }
                        _hoboRage = true;
                        Talk(SAY_PROPERTY_RAGE);
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        me->PauseMovement();
                        me->CastSpell(creature, SPELL_AGGRO_HOBO, true);
                        me->SetFacingToObject(creature);
                    }
                    else
                        _events.ScheduleEvent(EVENT_RESUME_MOVE, 0, EVENT_GROUP_OOC);
                    break;
                }
                case EVENT_RESUME_MOVE:
                    me->ResumeMovement();
                    if (roll_chance_i(50)) // prevent spam
                    {
                        if (roll_chance_i(70)) // chance to trigger simple talk event
                            _events.ScheduleEvent(EVENT_TALK, 30s, 80s, EVENT_GROUP_OOC);
                        else
                            _events.ScheduleEvent(urand(EVENT_JACKPOT_INTRO, EVENT_PROPERTY_RAGE), 30s, 80s, EVENT_GROUP_OOC);
                    }
                    else
                        _events.Repeat(30s, 80s);
                    break;
                default:
                    break;
            }
        }

        if (!_hoboRage)
            if (!UpdateVictim())
                return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    ObjectGuid _targetGUID;
    bool _bribeFailed;
    bool _hoboRage;
    bool _flee;
};

class spell_westfall_summon_ragamuffin_looter : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SUMMON_RAGAMUFFIN_LOOTER_1,
                SPELL_SUMMON_RAGAMUFFIN_LOOTER_2,
                SPELL_SUMMON_RAGAMUFFIN_LOOTER_3,
                SPELL_SUMMON_RAGAMUFFIN_LOOTER_4
            });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_SUMMON_RAGAMUFFIN_LOOTER_1, true);
        caster->CastSpell(caster, SPELL_SUMMON_RAGAMUFFIN_LOOTER_2, true);
        caster->CastSpell(caster, SPELL_SUMMON_RAGAMUFFIN_LOOTER_3, true);
        caster->CastSpell(caster, SPELL_SUMMON_RAGAMUFFIN_LOOTER_4, true);
    }

    void Register() override
    {
        OnEffectLaunch.Register(&spell_westfall_summon_ragamuffin_looter::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_westfall_aggro_hobo : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
            if (creature->IsAIEnabled)
                creature->AI()->SetGUID(GetCaster()->GetGUID(), 0);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_westfall_aggro_hobo::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_westfall()
{
    RegisterSpellScript(spell_westfall_unbound_energy);
    RegisterCreatureAI(npc_westfall_overloaded_harvest_golem);
    RegisterSpellScript(spell_westfall_reaping_blows);
    RegisterSpellScript(spell_westfall_wake_harvest_golem);
    RegisterSpellScript(spell_westfall_quest_credit_jangolode_event);
    RegisterCreatureAI(npc_westfall_hobo_witness);
    RegisterSpellScript(spell_westfall_summon_ragamuffin_looter);
    RegisterSpellScript(spell_westfall_aggro_hobo);
}
