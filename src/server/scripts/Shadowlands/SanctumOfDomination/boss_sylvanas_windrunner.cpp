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
#include "ConversationAI.h"
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

enum SylvanasSpells
{
    // Stances
    SPELL_RANGER_BOW_STANCE                              = 347560,
    SPELL_RANGER_DAGGERS_STANCE                          = 348010,

    // Miscellanea
    SPELL_GENERIC_ANCHOR_HERE                            = 45313,
    SPELL_GENERIC_DUAL_WIELD                             = 42459,
    SPELL_SYLVANAS_DISPLAY_POWER_SUFFERING               = 352311,
    SPELL_SYLVANAS_ROOT                                  = 347608
};

enum SylvanasPhases
{
    PHASE_ONE                                            = 1,
    PHASE_INTERMISSION                                   = 4,
    PHASE_TWO                                            = 2,
    PHASE_THREE                                          = 3,
    PHASE_INTERMISSION_WORLD_STATE                       = 11
};

enum SylvanasEventGroups
{
    EVENT_GROUP_NORMAL_EVENTS                            = 1,
    EVENT_GROUP_WINDRUNNER_EVENTS                        = 2
};

enum SylvanasEvents
{
    EVENT_INTRODUCTION                                   = 1,
    EVENT_SIZE_MAX                                       = 200
};

enum SylvanasTexts
{
    SAY_ENGAGE                                           = 0,
    SAY_SLAY                                             = 1,
    SAY_DISENGAGE                                        = 2
};

enum SylvanasConversations
{
    CONVERSATION_SYLVANAS_INTRODUCTION                   = 17368,
    CONVERSATION_SYLVANAS_INTRODUCTION_ACTOR_SYLVANAS_ID = 0,
    CONVERSATION_SYLVANAS_INTRODUCTION_ACTOR_BOLVAR_ID   = 1
};

enum SylvanasSpawnGroups
{
    SPAWN_GROUP_CHAMPIONS_FIRST_PHASE                    = 0,
    SPAWN_GROUP_CHAMPIONS_THIRD_PHASE,
    SPAWN_GROUP_CHAMPIONS_OUTRODUCTION
};

enum SylvanasPoints
{
    POINT_INTRODUCTION                                   = 1
};

enum SylvanasSpellVisualKits
{
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_01       = 150067,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_02       = 150068,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_03       = 150069,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_04       = 150071,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_05       = 150072,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_06       = 150070,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_07       = 150074,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_08       = 150077,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_09       = 150076,
    SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_10       = 150075,
    SPELL_VISUAL_KIT_BOLVAR_INTRODUCTION_TALK_01         = 150073,

    SPELL_VISUAL_KIT_SYLVANAS_TELEPORT                   = 150078
};

// 178355 - Sylvanas Shadowcopy (Riding)
struct npc_sylvanas_windrunner_shadowcopy_riding : public ScriptedAI
{
    npc_sylvanas_windrunner_shadowcopy_riding(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetImmuneToAll(true, true);
        me->SetUninteractible(true);
        me->SetReactState(REACT_PASSIVE);
    }
};

// 175732 - Sylvanas Windrunner
struct boss_sylvanas_windrunner : public BossAI
{
    boss_sylvanas_windrunner(Creature* creature) : BossAI(creature, DATA_SYLVANAS_WINDRUNNER) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_GENERIC_DUAL_WIELD, true);
        DoCastSelf(SPELL_SYLVANAS_DISPLAY_POWER_SUFFERING, true);

        me->SetPower(me->GetPowerType(), 0);

        if (instance->GetData(DATA_SYLVANAS_INTRODUCTION) == DONE)
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
        me->SummonCreatureGroup(SPAWN_GROUP_CHAMPIONS_FIRST_PHASE);

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

        if (id == POINT_INTRODUCTION)
            DoCastSelf(SPELL_GENERIC_ANCHOR_HERE, true);
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        Talk(SAY_ENGAGE);

        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, PHASE_ONE);

        events.SetPhase(PHASE_ONE);

        // Note: Sylvanas uses her root with 2s at the beginning of the encounter, most likely to avoid moving when engaging at stance switch.
        DoCastSelf(SPELL_SYLVANAS_ROOT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2000));

        // Note: we won't allow engaging until Phase 1 PR is merged.
        me->Say("Only introduction is implemented so far, evading.", LANG_UNIVERSAL);
        EnterEvadeMode(EvadeReason::Other);
    }
};

// 45 - Sylvanas Windrunner's Position Z Check (Serverside)
struct at_sylvanas_windrunner_z_check : AreaTriggerAI
{
    at_sylvanas_windrunner_z_check(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsAlive())
            return;

        if (Player* player = unit->ToPlayer())
        {
            if (player->IsGameMaster())
                return;

            if (player->IsAlive())
                player->KillSelf(false);
        }
    }
};

// 46 - Sylvanas Windrunner's Conversation Introduction (Serverside)
struct at_sylvanas_windrunner_introduction : AreaTriggerAI
{
    at_sylvanas_windrunner_introduction(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)  { }

    void OnUnitEnter(Unit* unit) override
    {
        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            Conversation::CreateConversation(CONVERSATION_SYLVANAS_INTRODUCTION, sylvanas, sylvanas->GetPosition(), ObjectGuid::Empty);

        at->Remove();
    }
};

// 17368 - Sylvanas Windrunner's Introduction (Conversation)
class conversation_sylvanas_windrunner_introduction : public ConversationAI
{
public:
    conversation_sylvanas_windrunner_introduction(Conversation* conversation) : ConversationAI(conversation) { }

    void OnCreate(Unit* creator) override
    {
        InstanceScript* instance = creator->GetInstanceScript();
        if (!instance)
            return;

        Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE);
        if (!bolvar)
            return;

        instance->SetData(DATA_SYLVANAS_INTRODUCTION, IN_PROGRESS);
        conversation->AddActor(NPC_BOLVAR_FORDRAGON_PINNACLE, CONVERSATION_SYLVANAS_INTRODUCTION_ACTOR_BOLVAR_ID, bolvar->GetGUID());

        _events.ScheduleEvent(EVENT_INTRODUCTION, 5s + 500ms);
    }

    void OnUpdate(uint32 diff) override
    {
        _events.Update(diff);

        uint32 eventId = _events.ExecuteEvent();
        Creature* sylvanas = nullptr;
        Creature* bolvar = nullptr;

        if (eventId)
        {
            sylvanas = conversation->GetActorCreature(CONVERSATION_SYLVANAS_INTRODUCTION_ACTOR_SYLVANAS_ID);
            if (!sylvanas)
                return;

            bolvar = conversation->GetActorCreature(CONVERSATION_SYLVANAS_INTRODUCTION_ACTOR_BOLVAR_ID);
            if (!bolvar)
                return;
        }

        switch (eventId)
        {
            case EVENT_INTRODUCTION:
            {
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_01, 0, 0);
                sylvanas->SetFacingToObject(bolvar);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 1, 1s + 140ms);
                break;
            }

            case EVENT_INTRODUCTION + 1:
            {
                sylvanas->GetMotionMaster()->MovePoint(POINT_INTRODUCTION, SylvanasIntroPos[0], false);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 2, 1s + 500ms);
                break;
            }

            case EVENT_INTRODUCTION + 2:
            {
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_02, 0, 0);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 3, 3s + 360ms);
                break;
            }

            case EVENT_INTRODUCTION + 3:
            {
                sylvanas->GetMotionMaster()->MovePoint(POINT_INTRODUCTION, SylvanasIntroPos[1], false);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 4, 469ms);
                break;
            }

            case EVENT_INTRODUCTION + 4:
            {
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_03, 0, 0);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 5, 3s + 500ms);
                break;
            }

            case EVENT_INTRODUCTION + 5:
            {
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_04, 0, 0);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 6, 2s);
                break;
            }

            case EVENT_INTRODUCTION + 6:
            {
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_05, 0, 0);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 7, 5s);
                break;
            }

            case EVENT_INTRODUCTION + 7:
            {
                sylvanas->SetFacingToObject(bolvar);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 8, 750ms);
                break;
            }

            case EVENT_INTRODUCTION + 8:
            {
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_06, 0, 0);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 9, 457ms);
                break;
            }

            case EVENT_INTRODUCTION + 9:
            {
                sylvanas->GetMotionMaster()->MovePoint(POINT_INTRODUCTION, SylvanasIntroPos[2], false);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 10, 5s + 89ms);
                break;
            }

            case EVENT_INTRODUCTION + 10:
            {
                bolvar->SetFacingToObject(sylvanas);
                bolvar->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_BOLVAR_INTRODUCTION_TALK_01, 0, 0);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 11, 13s + 567ms);
                break;
            }

            case EVENT_INTRODUCTION + 11:
            {
                sylvanas->SetFacingToObject(bolvar);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 12, 484ms);
                break;
            }

            case EVENT_INTRODUCTION + 12:
            {
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_07, 0, 0);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 13, 5s + 516ms);
                break;
            }

            case EVENT_INTRODUCTION + 13:
            {
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_08, 0, 0);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 14, 1s + 516ms);
                break;
            }

            case EVENT_INTRODUCTION + 14:
            {
                sylvanas->NearTeleportTo(SylvanasIntroPos[3], false);
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_TELEPORT, 0, 0);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 15, 1s + 265ms);
                break;
            }

            case EVENT_INTRODUCTION + 15:
            {
                sylvanas->SetFacingToObject(bolvar);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 16, 969ms);
                break;
            }

            case EVENT_INTRODUCTION + 16:
            {
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_09, 0, 0);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 17, 4s + 766ms);
                break;
            }

            case EVENT_INTRODUCTION + 17:
            {
                sylvanas->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_SYLVANAS_INTRODUCTION_TALK_10, 0, 0);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 18, 3s + 250ms);
                break;
            }

            case EVENT_INTRODUCTION + 18:
            {
                sylvanas->CastSpell(sylvanas, SPELL_RANGER_BOW_STANCE);

                _events.ScheduleEvent(EVENT_INTRODUCTION + 19, 16ms);
                break;
            }

            case EVENT_INTRODUCTION + 19:
            {
                sylvanas->CastSpell(sylvanas, SPELL_GENERIC_ANCHOR_HERE);

                if (InstanceScript* instance = sylvanas->GetInstanceScript())
                    instance->SetData(DATA_SYLVANAS_INTRODUCTION, DONE);
                break;
            }

            default:
                break;
        }
    }

private:
    EventMap _events;
};

void AddSC_boss_sylvanas_windrunner()
{
    RegisterSanctumOfDominationCreatureAI(boss_sylvanas_windrunner);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_shadowcopy_riding);

    RegisterAreaTriggerAI(at_sylvanas_windrunner_z_check);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_introduction);

    RegisterConversationAI(conversation_sylvanas_windrunner_introduction);
}
