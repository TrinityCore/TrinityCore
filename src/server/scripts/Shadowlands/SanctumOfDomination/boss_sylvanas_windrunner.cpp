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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Conversation.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "sanctum_of_domination.h"

Position const SylvanasIntroPos[4] =
{
    { 231.15799f, -832.816f,   4105.0386f          },
    { 242.00348f, -840.51215f, 4105.0386f          },
    { 241.23091f, -830.0955f,  4105.0386f          },
    { 225.73611f, -844.0746f,  4104.9882f, 1.3613f }
};

enum Spells
{
    // Stances
    SPELL_RANGER_BOW_STANCE                             = 347560,
    SPELL_RANGER_DAGGERS_STANCE                         = 348010,

    // Miscelanea
    SPELL_GENERIC_ANCHOR_HERE                           = 45313,
    SPELL_GENERIC_DUAL_WIELD                            = 42459,
    SPELL_SYLVANAS_DISPLAY_POWER_SUFFERING              = 352311,
    SPELL_SYLVANAS_ROOT                                 = 347608
};

enum Phases
{
    PHASE_ONE                                           = 1,
    PHASE_INTERMISSION                                  = 4,
    PHASE_TWO                                           = 2,
    PHASE_THREE                                         = 3,
    PHASE_INTERMISSION_WORLD_STATE                      = 11
};

enum EventGroups
{
    EVENT_GROUP_NORMAL_EVENTS                           = 1,
    EVENT_GROUP_WINDRUNNER_EVENTS                       = 2,
    EVENT_GROUP_INTRODUCTION_EVENTS                     = 3
};

enum Events
{
    EVENT_INTRODUCTION                                  = 1,
    EVENT_SIZE_MAX                                      = 200
};

enum Texts
{
    SAY_AGGRO                                           = 0,
    SAY_SLAY                                            = 1,
    SAY_DISENGAGE                                       = 2
};

enum Conversations
{
    CONVERSATION_INTRO                                  = 17368
};

enum SpawnGroups
{
    SPAWN_GROUP_CHAMPIONS                               = 0
};

enum Points
{
    POINT_INTRO_01                                      = 1,
    POINT_INTRO_02                                      = 2,
    POINT_INTRO_03                                      = 3,
    POINT_INTRO_FINISHED                                = 4
};

enum SpellVisualKits
{
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_01      = 150067,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_02      = 150068,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_03      = 150069,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_04      = 150071,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_05      = 150072,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_06      = 150070,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_07      = 150074,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_08      = 150077,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_09      = 150076,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_10      = 150075,
    SPELL_VISUAL_KIT_BOLVAR_INTRODUCTION_TALK_01        = 150073,

    SPELL_VISUAL_KIT_SYLVANAS_TELEPORT                  = 150078
};

// 178355 - Sylvanas Shadowcopy (Riding)
struct npc_sylvanas_windrunner_shadowcopy_riding : public ScriptedAI
{
    npc_sylvanas_windrunner_shadowcopy_riding(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        me->SetImmuneToAll(true, true);
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetReactState(REACT_PASSIVE);
    }

private:
    InstanceScript* _instance;
};

// 175732 - Sylvanas Windrunner
struct boss_sylvanas_windrunner : public BossAI
{
    boss_sylvanas_windrunner(Creature* creature) : BossAI(creature, DATA_SYLVANAS_WINDRUNNER) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_GENERIC_DUAL_WIELD, true);
        DoCastSelf(SPELL_SYLVANAS_DISPLAY_POWER_SUFFERING, true);

        if (instance->GetData(DATA_SYLVANAS_INTRO) == DONE)
        {
            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetImmuneToAll(false);
            me->SetSpeed(MOVE_RUN, 14.0f);
        }
        else
        {
            me->SetUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetImmuneToAll(true);
            me->SetSpeed(MOVE_RUN, 4.0f);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(SAY_DISENGAGE);

        _EnterEvadeMode();

        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        _DespawnAtEvade();
    }

    void Reset() override
    {
        _Reset();

        // Note: every creature involved in the fight adds UNIT_FLAG_PET_IN_COMBAT or UNIT_FLAG_RENAME when engaging, meaning they're most likely summoned by Sylvanas.
        me->SummonCreatureGroup(SPAWN_GROUP_CHAMPIONS);

        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_ONE);

        events.Reset();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_INTRO_01 || id == POINT_INTRO_02 || id == POINT_INTRO_03)
            DoCastSelf(SPELL_GENERIC_ANCHOR_HERE, true);
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        // TODO: there should be an internal CD for this.
        Talk(SAY_SLAY);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        Talk(SAY_AGGRO);

        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_ONE);

        events.SetPhase(PHASE_ONE);

        // Note: Sylvanas uses her root with 2s at the beginning of the encounter, most likely to avoid moving when engaging at stance switch.
        DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2000));

        // Note: We won't allow engaging until Phase 1 PR is merged.
        EnterEvadeMode(CreatureAI::EvadeReason::EVADE_REASON_OTHER);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_SYLVANAS_INTRO:
                Conversation::CreateConversation(CONVERSATION_INTRO, me, me->GetPosition(), ObjectGuid::Empty);
                events.ScheduleEvent(EVENT_INTRODUCTION, 1s + 500ms, EVENT_GROUP_INTRODUCTION_EVENTS, PHASE_ONE);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRODUCTION:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_01, 0, 0);
                    if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        me->SetFacingToObject(bolvar);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 1, 1s + 140ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 1:
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_01, SylvanasIntroPos[0], false);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 2, 1s + 500ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 2:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_02, 0, 0);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 3, 3s + 360ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 3:
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_02, SylvanasIntroPos[1], false);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 4, 469ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 4:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_03, 0, 0);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 5, 3s + 500ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 5:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_04, 0, 0);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 6, 2s, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 6:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_05, 0, 0);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 7, 5s, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 7:
                    if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        me->SetFacingToObject(bolvar);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 8, 750ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 8:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_06, 0, 0);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 9, 457ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 9:
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_03, SylvanasIntroPos[2], false);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 10, 5s + 89ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 10:
                    if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                    {
                        bolvar->SetFacingToObject(me);
                        bolvar->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_BOLVAR_INTRODUCTION_TALK_01, 0, 0);
                    }
                    events.ScheduleEvent(EVENT_INTRODUCTION + 11, 13s + 567ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 11:
                    if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        me->SetFacingToObject(bolvar);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 12, 484ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 12:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_07, 0, 0);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 13, 5s + 516ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 13:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_08, 0, 0);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 14, 1s + 516ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 14:
                    me->NearTeleportTo(SylvanasIntroPos[3], false);
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_TELEPORT, 0, 0);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 15, 1s + 265ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 15:
                    if (Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        me->SetFacingToObject(bolvar);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 16, 969ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 16:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_09, 0, 0);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 17, 4s + 766ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 17:
                    me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_10, 0, 0);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 18, 3s + 250ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 18:
                    DoCastSelf(SPELL_RANGER_BOW_STANCE, false);
                    events.ScheduleEvent(EVENT_INTRODUCTION + 19, 16ms, EVENT_GROUP_INTRODUCTION_EVENTS);
                    break;

                case EVENT_INTRODUCTION + 19:
                    DoCastSelf(SPELL_GENERIC_ANCHOR_HERE, true);
                    instance->SetData(DATA_SYLVANAS_INTRO, DONE);
                    break;
            }
        }
    }
};

// Serverside - Sylvanas Windrunner's Position Z Check
struct at_sylvanas_windrunner_z_check : AreaTriggerAI
{
    at_sylvanas_windrunner_z_check(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsAlive())
            return;

        if (Player* player = unit->ToPlayer())
        {
            if (player->IsGameMaster())
                return;

            player->EnvironmentalDamage(DAMAGE_FALL_TO_VOID, uint32(player->GetMaxHealth()));

            if (player->IsAlive())
                player->KillPlayer();
        }
    }

private:
    InstanceScript* _instance;
};

// 17368 - Sylvanas Windrunner's Introduction Conversation
class conversation_sylvanas_windrunner_introduction : public ConversationScript
{
public:
    conversation_sylvanas_windrunner_introduction() : ConversationScript("conversation_sylvanas_windrunner_introduction") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        if (Creature* bolvar = creator->GetInstanceScript()->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
            conversation->AddActor(NPC_BOLVAR_FORDRAGON_PINNACLE, 1, bolvar->GetGUID());
    }
};

void AddSC_boss_sylvanas_windrunner()
{
    RegisterSanctumOfDominationCreatureAI(boss_sylvanas_windrunner);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_shadowcopy_riding);

    RegisterAreaTriggerAI(at_sylvanas_windrunner_z_check);

    new conversation_sylvanas_windrunner_introduction();
}
