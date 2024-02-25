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

#include "SmartScript.h"
#include "CellImpl.h"
#include "ChatTextBuilder.h"
#include "Containers.h"
#include "Creature.h"
#include "CreatureTextMgr.h"
#include "CreatureTextMgrImpl.h"
#include "GameEventMgr.h"
#include "GameEventSender.h"
#include "GameObject.h"
#include "GossipDef.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Language.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Random.h"
#include "SmartAI.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "WaypointDefines.h"
#include "WaypointManager.h"

SmartScript::SmartScript()
{
    go = nullptr;
    me = nullptr;
    player = nullptr;
    trigger = nullptr;
    areaTrigger = nullptr;
    sceneTemplate = nullptr;
    quest = nullptr;
    event = 0;
    mEventPhase = 0;
    mPathId = 0;
    mTextTimer = 0;
    mLastTextID = 0;
    mUseTextTimer = false;
    mTalkerEntry = 0;
    mScriptType = SMART_SCRIPT_TYPE_CREATURE;
    isProcessingTimedActionList = false;
    mCurrentPriority = 0;
    mEventSortingRequired = false;
    mNestedEventsCounter = 0;
    mAllEventFlags = 0;
}

SmartScript::~SmartScript()
{
}

bool SmartScript::IsSmart(Creature* c, bool silent) const
{
    if (!c)
        return false;

    bool smart = true;
    if (!dynamic_cast<SmartAI*>(c->AI()))
        smart = false;

    if (!smart && !silent)
        TC_LOG_ERROR("sql.sql", "SmartScript: Action target Creature (GUID: {} Entry: {}) is not using SmartAI, action called by Creature (GUID: {} Entry: {}) skipped to prevent crash.", c->GetSpawnId(), c->GetEntry(), uint64(me ? me->GetSpawnId() : UI64LIT(0)), me ? me->GetEntry() : 0);

    return smart;
}

bool SmartScript::IsSmart(GameObject* g, bool silent) const
{
    if (!g)
        return false;

    bool smart = true;
    if (!dynamic_cast<SmartGameObjectAI*>(g->AI()))
        smart = false;

    if (!smart && !silent)
        TC_LOG_ERROR("sql.sql", "SmartScript: Action target GameObject (GUID: {} Entry: {}) is not using SmartGameObjectAI, action called by GameObject (GUID: {} Entry: {}) skipped to prevent crash.", g->GetSpawnId(), g->GetEntry(), uint64(go ? go->GetSpawnId() : UI64LIT(0)), go ? go->GetEntry() : 0);

    return smart;
}

bool SmartScript::IsSmart(bool silent) const
{
    if (me)
        return IsSmart(me, silent);
    if (go)
        return IsSmart(go, silent);
    return false;
}

void SmartScript::StoreTargetList(ObjectVector const& targets, uint32 id)
{
    // insert or replace
    _storedTargets.erase(id);
    _storedTargets.emplace(id, ObjectGuidVector(targets));
}

void SmartScript::AddToStoredTargetList(ObjectVector const& targets, uint32 id)
{
    auto [itr, inserted] = _storedTargets.try_emplace(id, targets);
    if (!inserted)
        for (WorldObject* obj : targets)
            itr->second.AddGuid(obj->GetGUID());
}

ObjectVector const* SmartScript::GetStoredTargetVector(uint32 id, WorldObject const& ref) const
{
    auto itr = _storedTargets.find(id);
    if (itr != _storedTargets.end())
        return itr->second.GetObjectVector(ref);
    return nullptr;
}

void SmartScript::StoreCounter(uint32 id, uint32 value, uint32 reset)
{
    CounterMap::iterator itr = mCounterList.find(id);
    if (itr != mCounterList.end())
    {
        if (reset == 0)
            itr->second += value;
        else
            itr->second = value;
    }
    else
        mCounterList.insert(std::make_pair(id, value));

    ProcessEventsFor(SMART_EVENT_COUNTER_SET, nullptr, id);
}

uint32 SmartScript::GetCounterValue(uint32 id) const
{
    CounterMap::const_iterator itr = mCounterList.find(id);
    if (itr != mCounterList.end())
        return itr->second;
    return 0;
}

GameObject* SmartScript::FindGameObjectNear(WorldObject* searchObject, ObjectGuid::LowType guid) const
{
    auto bounds = searchObject->GetMap()->GetGameObjectBySpawnIdStore().equal_range(guid);
    if (bounds.first == bounds.second)
        return nullptr;

    return bounds.first->second;
}

Creature* SmartScript::FindCreatureNear(WorldObject* searchObject, ObjectGuid::LowType guid) const
{
    auto bounds = searchObject->GetMap()->GetCreatureBySpawnIdStore().equal_range(guid);
    if (bounds.first == bounds.second)
        return nullptr;

    auto creatureItr = std::find_if(bounds.first, bounds.second, [](Map::CreatureBySpawnIdContainer::value_type const& pair)
    {
        return pair.second->IsAlive();
    });

    return creatureItr != bounds.second ? creatureItr->second : bounds.first->second;
}

void SmartScript::OnReset()
{
    ResetBaseObject();
    for (SmartScriptHolder& event : mEvents)
    {
        if (!(event.event.event_flags & SMART_EVENT_FLAG_DONT_RESET))
        {
            InitTimer(event);
            event.runOnce = false;
        }

        if (event.priority != SmartScriptHolder::DEFAULT_PRIORITY)
        {
            event.priority = SmartScriptHolder::DEFAULT_PRIORITY;
            mEventSortingRequired = true;
        }
    }
    ProcessEventsFor(SMART_EVENT_RESET);
    mLastInvoker.Clear();
}

void SmartScript::ResetBaseObject()
{
    WorldObject* lookupRoot = me;
    if (!lookupRoot)
        lookupRoot = go;

    if (lookupRoot)
    {
        if (!meOrigGUID.IsEmpty())
        {
            if (Creature* m = ObjectAccessor::GetCreature(*lookupRoot, meOrigGUID))
            {
                me = m;
                go = nullptr;
                areaTrigger = nullptr;
                player = nullptr;
            }
        }

        if (!goOrigGUID.IsEmpty())
        {
            if (GameObject* o = ObjectAccessor::GetGameObject(*lookupRoot, goOrigGUID))
            {
                me = nullptr;
                go = o;
                areaTrigger = nullptr;
                player = nullptr;
            }
        }
    }
    goOrigGUID.Clear();
    meOrigGUID.Clear();
}

void SmartScript::ProcessEventsFor(SMART_EVENT e, Unit* unit, uint32 var0, uint32 var1, bool bvar, SpellInfo const* spell, GameObject* gob, std::string const& varString)
{
    mNestedEventsCounter++;

    // Allow only a fixed number of nested ProcessEventsFor calls
    if (mNestedEventsCounter > MAX_NESTED_EVENTS)
    {
        TC_LOG_WARN("scripts.ai", "SmartScript::ProcessEventsFor: reached the limit of max allowed nested ProcessEventsFor() calls with event {}, skipping!\n{}", e, GetBaseObject()->GetDebugInfo());
    }
    else
    {
        for (SmartScriptHolder& event : mEvents)
        {
            SMART_EVENT eventType = SMART_EVENT(event.GetEventType());
            if (eventType == SMART_EVENT_LINK)//special handling
                continue;

            if (eventType == e)
                if (sConditionMgr->IsObjectMeetingSmartEventConditions(event.entryOrGuid, event.event_id, event.source_type, unit, GetBaseObject()))
                    ProcessEvent(event, unit, var0, var1, bvar, spell, gob, varString);
        }
    }

    --mNestedEventsCounter;
}

void SmartScript::ProcessAction(SmartScriptHolder& e, Unit* unit, uint32 var0, uint32 var1, bool bvar, SpellInfo const* spell, GameObject* gob, std::string const& varString)
{
    e.runOnce = true; //used for repeat check

    // calc random
    if (e.GetEventType() != SMART_EVENT_LINK && e.event.event_chance < 100 && e.event.event_chance && !(e.event.event_flags & SMART_EVENT_FLAG_TEMP_IGNORE_CHANCE_ROLL))
    {
        if (!roll_chance_i(e.event.event_chance))
            return;
    }

    // Remove SMART_EVENT_FLAG_TEMP_IGNORE_CHANCE_ROLL flag after processing roll chances as it's not needed anymore
    e.event.event_flags &= ~SMART_EVENT_FLAG_TEMP_IGNORE_CHANCE_ROLL;

    if (unit)
        mLastInvoker = unit->GetGUID();

    if (Unit* tempInvoker = GetLastInvoker())
        TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: Invoker: {} {}", tempInvoker->GetName(), tempInvoker->GetGUID().ToString());

    ObjectVector targets;
    GetTargets(targets, e, Coalesce<WorldObject>(unit, gob));

    switch (e.GetActionType())
    {
        case SMART_ACTION_TALK:
        {
            Creature* talker = e.target.type == 0 ? me : nullptr;
            Unit* talkTarget = nullptr;

            for (WorldObject* target : targets)
            {
                if (IsCreature(target) && !target->ToCreature()->IsPet()) // Prevented sending text to pets.
                {
                    if (e.action.talk.useTalkTarget)
                    {
                        talker = me;
                        talkTarget = target->ToCreature();
                    }
                    else
                        talker = target->ToCreature();
                    break;
                }
                else if (IsPlayer(target))
                {
                    talker = me;
                    talkTarget = target->ToPlayer();
                    break;
                }
            }

            if (!talkTarget)
                talkTarget = GetLastInvoker();

            if (!talker)
                break;

            mTalkerEntry = talker->GetEntry();
            mLastTextID = e.action.talk.textGroupID;
            mTextTimer = e.action.talk.duration;
            mUseTextTimer = true;
            sCreatureTextMgr->SendChat(talker, uint8(e.action.talk.textGroupID), talkTarget);
            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_TALK: talker: {} {}, textGuid: {}",
                talker->GetName(), talker->GetGUID().ToString(), talkTarget ? talkTarget->GetGUID().ToString().c_str() : "Empty");
            break;
        }
        case SMART_ACTION_SIMPLE_TALK:
        {
            for (WorldObject* target : targets)
            {
                if (IsCreature(target))
                    sCreatureTextMgr->SendChat(target->ToCreature(), uint8(e.action.simpleTalk.textGroupID), IsPlayer(GetLastInvoker()) ? GetLastInvoker() : nullptr);
                else if (IsPlayer(target) && me)
                {
                    Unit* templastInvoker = GetLastInvoker();
                    sCreatureTextMgr->SendChat(me, uint8(e.action.simpleTalk.textGroupID), IsPlayer(templastInvoker) ? templastInvoker : nullptr, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, SoundKitPlayType::Normal, TEAM_OTHER, false, target->ToPlayer());
                }
                TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_SIMPLE_TALK: talker: {} {}, textGroupId: {}",
                    target->GetName(), target->GetGUID().ToString(), uint8(e.action.simpleTalk.textGroupID));
            }
            break;
        }
        case SMART_ACTION_PLAY_EMOTE:
        {
            for (WorldObject* target : targets)
            {
                if (IsUnit(target))
                {
                    target->ToUnit()->HandleEmoteCommand(static_cast<Emote>(e.action.emote.emote));
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_PLAY_EMOTE: target: {} {}, emote: {}",
                        target->GetName(), target->GetGUID().ToString(), e.action.emote.emote);
                }
            }
            break;
        }
        case SMART_ACTION_SOUND:
        {
            for (WorldObject* target : targets)
            {
                if (IsUnit(target))
                {
                    if (e.action.sound.distance == 1)
                        target->PlayDistanceSound(e.action.sound.sound, e.action.sound.onlySelf ? target->ToPlayer() : nullptr);
                    else
                        target->PlayDirectSound(e.action.sound.sound, e.action.sound.onlySelf ? target->ToPlayer() : nullptr, e.action.sound.keyBroadcastTextId);

                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_SOUND: target: {} {}, sound: {}, onlyself: {}",
                        target->GetName(), target->GetGUID().ToString(), e.action.sound.sound, e.action.sound.onlySelf);
                }
            }
            break;
        }
        case SMART_ACTION_SET_FACTION:
        {
            for (WorldObject* target : targets)
            {
                if (IsCreature(target))
                {
                    if (e.action.faction.factionID)
                    {
                        target->ToCreature()->SetFaction(e.action.faction.factionID);
                        TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_SET_FACTION: Creature {} set faction to {}",
                            target->GetGUID().ToString(), e.action.faction.factionID);
                    }
                    else
                    {
                        if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(target->ToCreature()->GetEntry()))
                        {
                            if (target->ToCreature()->GetFaction() != ci->faction)
                            {
                                target->ToCreature()->SetFaction(ci->faction);
                                TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_SET_FACTION: Creature {} set faction to {}",
                                    target->GetGUID().ToString(), ci->faction);
                            }
                        }
                    }
                }
            }
            break;
        }
        case SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL:
        {
            for (WorldObject* target : targets)
            {
                if (!IsCreature(target))
                    continue;

                if (e.action.morphOrMount.creature || e.action.morphOrMount.model)
                {
                    //set model based on entry from creature_template
                    if (e.action.morphOrMount.creature)
                    {
                        if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(e.action.morphOrMount.creature))
                        {
                            CreatureModel const* model = ObjectMgr::ChooseDisplayId(ci);
                            target->ToCreature()->SetDisplayId(model->CreatureDisplayID);
                            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL: Creature {} set displayid to {}",
                                target->GetGUID().ToString(), model->CreatureDisplayID);
                        }
                    }
                    //if no param1, then use value from param2 (modelId)
                    else
                    {
                        target->ToCreature()->SetDisplayId(e.action.morphOrMount.model);
                        TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL: Creature {} set displayid to {}",
                            target->GetGUID().ToString(), e.action.morphOrMount.model);
                    }
                }
                else
                {
                    target->ToCreature()->DeMorph();
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL: Creature {} demorphs.",
                        target->GetGUID().ToString());
                }
            }
            break;
        }
        case SMART_ACTION_FAIL_QUEST:
        {
            for (WorldObject* target : targets)
            {
                if (IsPlayer(target))
                {
                    target->ToPlayer()->FailQuest(e.action.quest.quest);
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_FAIL_QUEST: Player {} fails quest {}",
                        target->GetGUID().ToString(), e.action.quest.quest);
                }
            }
            break;
        }
        case SMART_ACTION_OFFER_QUEST:
        {
            for (WorldObject* target : targets)
            {
                if (Player* player = target->ToPlayer())
                {
                    if (Quest const* q = sObjectMgr->GetQuestTemplate(e.action.questOffer.questID))
                    {
                        if (me && e.action.questOffer.directAdd == 0)
                        {
                            if (player->CanTakeQuest(q, true))
                            {
                                if (WorldSession* session = player->GetSession())
                                {
                                    PlayerMenu menu(session);
                                    menu.SendQuestGiverQuestDetails(q, me->GetGUID(), true, false);
                                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_OFFER_QUEST: Player {} - offering quest {}", player->GetGUID().ToString(), e.action.questOffer.questID);
                                }
                            }
                        }
                        else
                        {
                            player->AddQuestAndCheckCompletion(q, nullptr);
                            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_OFFER_QUEST: Player {} - quest {} added",
                                player->GetGUID().ToString(), e.action.questOffer.questID);
                        }
                    }
                }
            }
            break;
        }
        case SMART_ACTION_SET_REACT_STATE:
        {
            for (WorldObject* target : targets)
            {
                if (!IsCreature(target))
                    continue;

                target->ToCreature()->SetReactState(ReactStates(e.action.react.state));
            }
            break;
        }
        case SMART_ACTION_RANDOM_EMOTE:
        {
            std::vector<uint32> emotes;
            std::copy_if(std::begin(e.action.randomEmote.emotes), std::end(e.action.randomEmote.emotes),
                std::back_inserter(emotes), [](uint32 emote) { return emote != 0; });

            for (WorldObject* target : targets)
            {
                if (IsUnit(target))
                {
                    Emote emote = static_cast<Emote>(Trinity::Containers::SelectRandomContainerElement(emotes));
                    target->ToUnit()->HandleEmoteCommand(emote);
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_RANDOM_EMOTE: Creature {} handle random emote {}",
                        target->GetGUID().ToString(), emote);
                }
            }
            break;
        }
        case SMART_ACTION_THREAT_ALL_PCT:
        {
            if (!me)
                break;

            for (auto* ref : me->GetThreatManager().GetModifiableThreatList())
            {
                ref->ModifyThreatByPercent(std::max<int32>(-100,int32(e.action.threatPCT.threatINC) - int32(e.action.threatPCT.threatDEC)));
                TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_THREAT_ALL_PCT: Creature {} modify threat for unit {}, value {}",
                    me->GetGUID().ToString(), ref->GetVictim()->GetGUID().ToString(), int32(e.action.threatPCT.threatINC)-int32(e.action.threatPCT.threatDEC));
            }
            break;
        }
        case SMART_ACTION_THREAT_SINGLE_PCT:
        {
            if (!me)
                break;

            for (WorldObject* target : targets)
            {
                if (IsUnit(target))
                {
                    me->GetThreatManager().ModifyThreatByPercent(target->ToUnit(), std::max<int32>(-100, int32(e.action.threatPCT.threatINC) - int32(e.action.threatPCT.threatDEC)));
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_THREAT_SINGLE_PCT: Creature {} modify threat for unit {}, value {}",
                        me->GetGUID().ToString(), target->GetGUID().ToString(), int32(e.action.threatPCT.threatINC) - int32(e.action.threatPCT.threatDEC));
                }
            }
            break;
        }
        case SMART_ACTION_CALL_AREAEXPLOREDOREVENTHAPPENS:
        {
            for (WorldObject* target : targets)
            {
                // Special handling for vehicles
                if (IsUnit(target))
                    if (Vehicle* vehicle = target->ToUnit()->GetVehicleKit())
                        for (std::pair<int8 const, VehicleSeat>& seat : vehicle->Seats)
                            if (Player* player = ObjectAccessor::GetPlayer(*target, seat.second.Passenger.Guid))
                                player->AreaExploredOrEventHappens(e.action.quest.quest);

                if (IsPlayer(target))
                {
                    target->ToPlayer()->AreaExploredOrEventHappens(e.action.quest.quest);

                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_CALL_AREAEXPLOREDOREVENTHAPPENS: Player {} credited quest {}",
                        target->GetGUID().ToString(), e.action.quest.quest);
                }
            }
            break;
        }
        case SMART_ACTION_CAST:
        {
            if (targets.empty())
                break;

            if (e.action.cast.targetsLimit > 0 && targets.size() > e.action.cast.targetsLimit)
                Trinity::Containers::RandomResize(targets, e.action.cast.targetsLimit);

            bool failedSpellCast = false, successfulSpellCast = false;

            for (WorldObject* target : targets)
            {
                // may be nullptr
                if (go)
                    go->CastSpell(target->ToUnit(), e.action.cast.spell);

                if (!IsUnit(target))
                    continue;

                if (!(e.action.cast.castFlags & SMARTCAST_AURA_NOT_PRESENT) || !target->ToUnit()->HasAura(e.action.cast.spell))
                {
                    TriggerCastFlags triggerFlag = TRIGGERED_NONE;
                    if (e.action.cast.castFlags & SMARTCAST_TRIGGERED)
                    {
                        if (e.action.cast.triggerFlags)
                            triggerFlag = TriggerCastFlags(e.action.cast.triggerFlags);
                        else
                            triggerFlag = TRIGGERED_FULL_MASK;
                    }

                    if (me)
                    {
                        if (e.action.cast.castFlags & SMARTCAST_INTERRUPT_PREVIOUS)
                            me->InterruptNonMeleeSpells(false);

                        SpellCastResult result = me->CastSpell(target->ToUnit(), e.action.cast.spell, triggerFlag);
                        bool spellCastFailed = (result != SPELL_CAST_OK && result != SPELL_FAILED_SPELL_IN_PROGRESS);

                        if (e.action.cast.castFlags & SMARTCAST_COMBAT_MOVE)
                        {
                            // If cast flag SMARTCAST_COMBAT_MOVE is set combat movement will not be allowed unless target is outside spell range, out of mana, or LOS.
                            ENSURE_AI(SmartAI, me->AI())->SetCombatMove(spellCastFailed, true);
                        }

                        if (spellCastFailed)
                            failedSpellCast = true;
                        else
                            successfulSpellCast = true;
                    }
                    else if (go)
                        go->CastSpell(target->ToUnit(), e.action.cast.spell, triggerFlag);

                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_CAST:: {} casts spell {} on target {} with castflags {}",
                        me ? me->GetGUID().ToString() : go->GetGUID().ToString(), e.action.cast.spell, target->GetGUID().ToString(), e.action.cast.castFlags);
                }
                else
                    TC_LOG_DEBUG("scripts.ai", "Spell {} not cast because it has flag SMARTCAST_AURA_NOT_PRESENT and the target ({}) already has the aura", e.action.cast.spell, target->GetGUID().ToString());
            }

            // If there is at least 1 failed cast and no successful casts at all, retry again on next loop
            if (failedSpellCast && !successfulSpellCast)
            {
                RetryLater(e, true);
                // Don't execute linked events
                return;
            }
            break;
        }
        case SMART_ACTION_SELF_CAST:
        {
            if (targets.empty())
                break;

            if (e.action.cast.targetsLimit)
                Trinity::Containers::RandomResize(targets, e.action.cast.targetsLimit);

            TriggerCastFlags triggerFlags = TRIGGERED_NONE;
            if (e.action.cast.castFlags & SMARTCAST_TRIGGERED)
            {
                if (e.action.cast.triggerFlags)
                    triggerFlags = TriggerCastFlags(e.action.cast.triggerFlags);
                else
                    triggerFlags = TRIGGERED_FULL_MASK;
            }

            for (WorldObject* target : targets)
            {
                Unit* uTarget = target->ToUnit();
                if (!uTarget)
                    continue;

                if (!(e.action.cast.castFlags & SMARTCAST_AURA_NOT_PRESENT) || !uTarget->HasAura(e.action.cast.spell))
                {
                    if (e.action.cast.castFlags & SMARTCAST_INTERRUPT_PREVIOUS)
                        uTarget->InterruptNonMeleeSpells(false);

                    uTarget->CastSpell(uTarget, e.action.cast.spell, triggerFlags);
                }
            }
            break;
        }
        case SMART_ACTION_INVOKER_CAST:
        {
            Unit* tempLastInvoker = GetLastInvoker(unit);
            if (!tempLastInvoker)
                break;

            if (targets.empty())
                break;

            if (e.action.cast.targetsLimit)
                Trinity::Containers::RandomResize(targets, e.action.cast.targetsLimit);

            for (WorldObject* target : targets)
            {
                if (!IsUnit(target))
                    continue;

                if (!(e.action.cast.castFlags & SMARTCAST_AURA_NOT_PRESENT) || !target->ToUnit()->HasAura(e.action.cast.spell))
                {
                    if (e.action.cast.castFlags & SMARTCAST_INTERRUPT_PREVIOUS)
                        tempLastInvoker->InterruptNonMeleeSpells(false);

                    TriggerCastFlags triggerFlag = TRIGGERED_NONE;
                    if (e.action.cast.castFlags & SMARTCAST_TRIGGERED)
                    {
                        if (e.action.cast.triggerFlags)
                            triggerFlag = TriggerCastFlags(e.action.cast.triggerFlags);
                        else
                            triggerFlag = TRIGGERED_FULL_MASK;
                    }

                    tempLastInvoker->CastSpell(target->ToUnit(), e.action.cast.spell, triggerFlag);
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_INVOKER_CAST: Invoker {} casts spell {} on target {} with castflags {}",
                        tempLastInvoker->GetGUID().ToString(), e.action.cast.spell, target->GetGUID().ToString(), e.action.cast.castFlags);
                }
                else
                    TC_LOG_DEBUG("scripts.ai", "Spell {} not cast because it has flag SMARTCAST_AURA_NOT_PRESENT and the target ({}) already has the aura", e.action.cast.spell, target->GetGUID().ToString());
            }
            break;
        }
        case SMART_ACTION_ACTIVATE_GOBJECT:
        {
            for (WorldObject* target : targets)
            {
                if (IsGameObject(target))
                {
                    // Activate
                    target->ToGameObject()->SetLootState(GO_READY);
                    target->ToGameObject()->UseDoorOrButton(0, false, unit);
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_ACTIVATE_GOBJECT. Gameobject {} activated",
                        target->GetGUID().ToString());
                }
            }
            break;
        }
        case SMART_ACTION_RESET_GOBJECT:
        {
            for (WorldObject* target : targets)
            {
                if (IsGameObject(target))
                {
                    target->ToGameObject()->ResetDoorOrButton();
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_RESET_GOBJECT. Gameobject {} reset",
                        target->GetGUID().ToString());
                }
            }
            break;
        }
        case SMART_ACTION_SET_EMOTE_STATE:
        {
            for (WorldObject* target : targets)
            {
                if (IsUnit(target))
                {
                    target->ToUnit()->SetEmoteState(Emote(e.action.emote.emote));
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_SET_EMOTE_STATE. Unit {} set emotestate to {}",
                        target->GetGUID().ToString(), e.action.emote.emote);
                }
            }
            break;
        }
        case SMART_ACTION_AUTO_ATTACK:
        {
            me->SetCanMelee(e.action.autoAttack.attack != 0);
            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_AUTO_ATTACK: Creature: {} bool on = {}",
                me->GetGUID().ToString(), e.action.autoAttack.attack);
            break;
        }
        case SMART_ACTION_ALLOW_COMBAT_MOVEMENT:
        {
            if (!IsSmart())
                break;

            bool move = e.action.combatMove.move != 0;
            ENSURE_AI(SmartAI, me->AI())->SetCombatMove(move);
            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_ALLOW_COMBAT_MOVEMENT: Creature {} bool on = {}",
                me->GetGUID().ToString(), e.action.combatMove.move);
            break;
        }
        case SMART_ACTION_SET_EVENT_PHASE:
        {
            if (!GetBaseObject())
                break;

            SetPhase(e.action.setEventPhase.phase);
            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_SET_EVENT_PHASE: Creature {} set event phase {}",
                GetBaseObject()->GetGUID().ToString(), e.action.setEventPhase.phase);
            break;
        }
        case SMART_ACTION_INC_EVENT_PHASE:
        {
            if (!GetBaseObject())
                break;

            IncPhase(e.action.incEventPhase.inc);
            DecPhase(e.action.incEventPhase.dec);
            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_INC_EVENT_PHASE: Creature {} inc event phase by {}, "
                "decrease by {}", GetBaseObject()->GetGUID().ToString(), e.action.incEventPhase.inc, e.action.incEventPhase.dec);
            break;
        }
        case SMART_ACTION_EVADE:
        {
            if (!me)
                break;

            // Reset home position to respawn position if specified in the parameters
            if (e.action.evade.toRespawnPosition == 0)
            {
                float homeX, homeY, homeZ, homeO;
                me->GetRespawnPosition(homeX, homeY, homeZ, &homeO);
                me->SetHomePosition(homeX, homeY, homeZ, homeO);
            }

            me->AI()->EnterEvadeMode();
            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_EVADE: Creature {} EnterEvadeMode", me->GetGUID().ToString());
            break;
        }
        case SMART_ACTION_FLEE_FOR_ASSIST:
        {
            if (!me)
                break;

            me->DoFleeToGetAssistance();

            if (e.action.fleeAssist.withEmote)
            {
                Trinity::BroadcastTextBuilder builder(me, CHAT_MSG_MONSTER_EMOTE, BROADCAST_TEXT_FLEE_FOR_ASSIST, me->GetGender());
                CreatureTextMgr::SendChatPacket(me, builder, CHAT_MSG_MONSTER_EMOTE);
            }
            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_FLEE_FOR_ASSIST: Creature {} DoFleeToGetAssistance", me->GetGUID().ToString());
            break;
        }
        case SMART_ACTION_CALL_GROUPEVENTHAPPENS:
        {
            if (!unit)
                break;

            // If invoker was pet or charm
            Player* playerCharmed = unit->GetCharmerOrOwnerPlayerOrPlayerItself();
            if (playerCharmed && GetBaseObject())
            {
                playerCharmed->GroupEventHappens(e.action.quest.quest, GetBaseObject());
                TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_CALL_GROUPEVENTHAPPENS: Player {}, group credit for quest {}",
                    unit->GetGUID().ToString(), e.action.quest.quest);
            }

            // Special handling for vehicles
            if (Vehicle* vehicle = unit->GetVehicleKit())
                for (std::pair<int8 const, VehicleSeat>& seat : vehicle->Seats)
                    if (Player* passenger = ObjectAccessor::GetPlayer(*unit, seat.second.Passenger.Guid))
                        passenger->GroupEventHappens(e.action.quest.quest, GetBaseObject());
            break;
        }
        case SMART_ACTION_COMBAT_STOP:
        {
            if (!me)
                break;

            me->CombatStop(true);
            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_COMBAT_STOP: {} CombatStop", me->GetGUID().ToString());
            break;
        }
        case SMART_ACTION_REMOVEAURASFROMSPELL:
        {
            for (WorldObject* target : targets)
            {
                if (!IsUnit(target))
                    continue;

                if (e.action.removeAura.spell)
                {
                    ObjectGuid casterGUID;
                    if (e.action.removeAura.onlyOwnedAuras)
                    {
                        if (!me)
                            break;
                        casterGUID = me->GetGUID();
                    }

                    if (e.action.removeAura.charges)
                    {
                        if (Aura* aur = target->ToUnit()->GetAura(e.action.removeAura.spell, casterGUID))
                            aur->ModCharges(-static_cast<int32>(e.action.removeAura.charges), AURA_REMOVE_BY_EXPIRE);
                    }
                    else
                        target->ToUnit()->RemoveAurasDueToSpell(e.action.removeAura.spell, casterGUID);
                }
                else
                    target->ToUnit()->RemoveAllAuras();

                TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_REMOVEAURASFROMSPELL: Unit {}, spell {}",
                    target->GetGUID().ToString(), e.action.removeAura.spell);
            }
            break;
        }
        case SMART_ACTION_FOLLOW:
        {
            if (!IsSmart())
                break;

            if (targets.empty())
            {
                ENSURE_AI(SmartAI, me->AI())->StopFollow(false);
                break;
            }

            for (WorldObject* target : targets)
            {
                if (IsUnit(target))
                {
                    float angle = e.action.follow.angle > 6 ? (e.action.follow.angle * M_PI / 180.0f) : e.action.follow.angle;
                    ENSURE_AI(SmartAI, me->AI())->SetFollow(target->ToUnit(), float(e.action.follow.dist) + 0.1f, angle, e.action.follow.credit, e.action.follow.entry, e.action.follow.creditType);
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_FOLLOW: Creature {} following target {}",
                        me->GetGUID().ToString(), target->GetGUID().ToString());
                    break;
                }
            }
            break;
        }
        case SMART_ACTION_RANDOM_PHASE:
        {
            if (!GetBaseObject())
                break;

            std::vector<uint32> phases;
            std::copy_if(std::begin(e.action.randomPhase.phases), std::end(e.action.randomPhase.phases),
                std::back_inserter(phases), [](uint32 phase) { return phase != 0; });

            uint32 phase = Trinity::Containers::SelectRandomContainerElement(phases);
            SetPhase(phase);
            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_RANDOM_PHASE: Creature {} sets event phase to {}",
                GetBaseObject()->GetGUID().ToString(), phase);
            break;
        }
        case SMART_ACTION_RANDOM_PHASE_RANGE:
        {
            if (!GetBaseObject())
                break;

            uint32 phase = urand(e.action.randomPhaseRange.phaseMin, e.action.randomPhaseRange.phaseMax);
            SetPhase(phase);
            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_RANDOM_PHASE_RANGE: Creature {} sets event phase to {}",
                GetBaseObject()->GetGUID().ToString(), phase);
            break;
        }
        case SMART_ACTION_CALL_KILLEDMONSTER:
        {
            if (e.target.type == SMART_TARGET_NONE || e.target.type == SMART_TARGET_SELF) // Loot recipient and his group members
            {
                if (!me)
                    break;

                for (ObjectGuid tapperGuid : me->GetTapList())
                {
                    if (Player* tapper = ObjectAccessor::GetPlayer(*me, tapperGuid))
                    {
                        tapper->KilledMonsterCredit(e.action.killedMonster.creature, me->GetGUID());
                        TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_CALL_KILLEDMONSTER: Player {}, Killcredit: {}",
                            tapper->GetGUID().ToString(), e.action.killedMonster.creature);
                    }
                }
            }
            else // Specific target type
            {
                for (WorldObject* target : targets)
                {
                    if (IsPlayer(target))
                    {
                        target->ToPlayer()->KilledMonsterCredit(e.action.killedMonster.creature);
                        TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_CALL_KILLEDMONSTER: Player {}, Killcredit: {}",
                            target->GetGUID().ToString(), e.action.killedMonster.creature);
                    }
                    else if (IsUnit(target)) // Special handling for vehicles
                        if (Vehicle* vehicle = target->ToUnit()->GetVehicleKit())
                            for (std::pair<int8 const, VehicleSeat>& seat : vehicle->Seats)
                                if (Player* player = ObjectAccessor::GetPlayer(*target, seat.second.Passenger.Guid))
                                    player->KilledMonsterCredit(e.action.killedMonster.creature);
                }
            }
            break;
        }
        case SMART_ACTION_SET_INST_DATA:
        {
            WorldObject* obj = GetBaseObject();
            if (!obj)
                obj = unit;

            if (!obj)
                break;

            InstanceScript* instance = obj->GetInstanceScript();
            if (!instance)
            {
                TC_LOG_ERROR("sql.sql", "SmartScript: Event {} attempt to set instance data without instance script. EntryOrGuid {}", e.GetEventType(), e.entryOrGuid);
                break;
            }

            switch (e.action.setInstanceData.type)
            {
                case 0:
                    instance->SetData(e.action.setInstanceData.field, e.action.setInstanceData.data);
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_SET_INST_DATA: SetData Field: {}, data: {}",
                        e.action.setInstanceData.field, e.action.setInstanceData.data);
                    break;
                case 1:
                    instance->SetBossState(e.action.setInstanceData.field, static_cast<EncounterState>(e.action.setInstanceData.data));
                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_SET_INST_DATA: SetBossState BossId: {}, State: {} ({})",
                        e.action.setInstanceData.field, e.action.setInstanceData.data, InstanceScript::GetBossStateName(e.action.setInstanceData.data));
                    break;
                default: // Static analysis
                    break;
            }
            break;
        }
        case SMART_ACTION_SET_INST_DATA64:
        {
            WorldObject* obj = GetBaseObject();
            if (!obj)
                obj = unit;

            if (!obj)
                break;

            InstanceScript* instance = obj->GetInstanceScript();
            if (!instance)
            {
                TC_LOG_ERROR("sql.sql", "SmartScript: Event {} attempt to set instance data without instance script. EntryOrGuid {}", e.GetEventType(), e.entryOrGuid);
                break;
            }

            if (targets.empty())
                break;

            instance->SetGuidData(e.action.setInstanceData64.field, targets.front()->GetGUID());
            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_SET_INST_DATA64: Field: {}, data: {}",
                e.action.setInstanceData64.field, targets.front()->GetGUID().ToString());
            break;
        }
        case SMART_ACTION_UPDATE_TEMPLATE:
        {
            for (WorldObject* target : targets)
                if (IsCreature(target))
                    target->ToCreature()->UpdateEntry(e.action.updateTemplate.creature, nullptr, e.action.updateTemplate.updateLevel != 0);
            break;
        }
        case SMART_ACTION_DIE:
        {
            if (me && !me->isDead())
            {
                me->KillSelf();
                TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_DIE: Creature {}", me->GetGUID().ToString());
            }
            break;
        }
        case SMART_ACTION_SET_IN_COMBAT_WITH_ZONE:
        {
            if (me && me->IsAIEnabled())
            {
                me->AI()->DoZoneInCombat();
                TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_SET_IN_COMBAT_WITH_ZONE: Creature {}", me->GetGUID().ToString());
            }
            break;
        }
        case SMART_ACTION_CALL_FOR_HELP:
        {
            if (me)
            {
                me->CallForHelp(float(e.action.callHelp.range));
                if (e.action.callHelp.withEmote)
                {
                    Trinity::BroadcastTextBuilder builder(me, CHAT_MSG_MONSTER_EMOTE, BROADCAST_TEXT_CALL_FOR_HELP, me->GetGender());
                    sCreatureTextMgr->SendChatPacket(me, builder, CHAT_MSG_MONSTER_EMOTE);
                }
                TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_CALL_FOR_HELP: Creature {}", me->GetGUID().ToString());
            }
            break;
        }
        case SMART_ACTION_SET_SHEATH:
        {
            if (me)
            {
                me->SetSheath(SheathState(e.action.setSheath.sheath));
                TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_SET_SHEATH: Creature {}, State: {}",
                    me->GetGUID().ToString(), e.action.setSheath.sheath);
            }
            break;
        }
        case SMART_ACTION_FORCE_DESPAWN:
        {
            // there should be at least a world update tick before despawn, to avoid breaking linked actions
            Milliseconds despawnDelay(e.action.forceDespawn.delay);
            if (despawnDelay <= 0ms)
                despawnDelay = 1ms;

            Seconds forceRespawnTimer(e.action.forceDespawn.forceRespawnTimer);

            for (WorldObject* target : targets)
            {
                if (Creature* creature = target->ToCreature())
                    creature->DespawnOrUnsummon(despawnDelay, forceRespawnTimer);
                else if (GameObject* goTarget = target->ToGameObject())
                    goTarget->DespawnOrUnsummon(despawnDelay, forceRespawnTimer);
            }
            break;
        }
        case SMART_ACTION_SET_INGAME_PHASE_ID:
        {
            for (WorldObject* target : targets)
            {
                if (e.action.ingamePhaseId.apply == 1)
                    PhasingHandler::AddPhase(target, e.action.ingamePhaseId.id, true);
                else
                    PhasingHandler::RemovePhase(target, e.action.ingamePhaseId.id, true);
            }
            break;
        }
        case SMART_ACTION_SET_INGAME_PHASE_GROUP:
        {
            for (WorldObject* target : targets)
            {
                if (e.action.ingamePhaseGroup.apply == 1)
                    PhasingHandler::AddPhaseGroup(target, e.action.ingamePhaseGroup.groupId, true);
                else
                    PhasingHandler::RemovePhaseGroup(target, e.action.ingamePhaseGroup.groupId, true);
            }
            break;
        }
        case SMART_ACTION_MOUNT_TO_ENTRY_OR_MODEL:
        {
            for (WorldObject* target : targets)
            {
                if (!IsUnit(target))
                    continue;

                if (e.action.morphOrMount.creature || e.action.morphOrMount.model)
                {
                    if (e.action.morphOrMount.creature > 0)
                    {
                        if (CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(e.action.morphOrMount.creature))
                            target->ToUnit()->Mount(ObjectMgr::ChooseDisplayId(cInfo)->CreatureDisplayID);
                    }
                    else
                        target->ToUnit()->Mount(e.action.morphOrMount.model);
                }
                else
                    target->ToUnit()->Dismount();
            }
            break;
        }
        case SMART_ACTION_SET_INVINCIBILITY_HP_LEVEL:
        {
            for (WorldObject* target : targets)
            {
                if (IsCreature(target))
                {
                    SmartAI* ai = CAST_AI(SmartAI, target->ToCreature()->AI());
                    if (!ai)
                        continue;

                    if (e.action.invincHP.percent)
                        ai->SetInvincibilityHpLevel(target->ToCreature()->CountPctFromMaxHealth(e.action.invincHP.percent));
                    else
                        ai->SetInvincibilityHpLevel(e.action.invincHP.minHP);
                }
            }
            break;
        }
        case SMART_ACTION_SET_DATA:
        {
            for (WorldObject* target : targets)
            {
                if (Creature* cTarget = target->ToCreature())
                {
                    CreatureAI* ai = cTarget->AI();
                    if (IsSmart(cTarget, true))
                        ENSURE_AI(SmartAI, ai)->SetData(e.action.setData.field, e.action.setData.data, me);
                    else
                        ai->SetData(e.action.setData.field, e.action.setData.data);
                }
                else if (GameObject* oTarget = target->ToGameObject())
                {
                    GameObjectAI* ai = oTarget->AI();
                    if (IsSmart(oTarget, true))
                        ENSURE_AI(SmartGameObjectAI, ai)->SetData(e.action.setData.field, e.action.setData.data, me);
                    else
                        ai->SetData(e.action.setData.field, e.action.setData.data);
                }
            }
            break;
        }
        case SMART_ACTION_ATTACK_STOP:
        {
            for (WorldObject* target : targets)
                if (Unit* unitTarget = target->ToUnit())
                    unitTarget->AttackStop();
            break;
        }
        case SMART_ACTION_MOVE_OFFSET:
        {
            for (WorldObject* target : targets)
            {
                if (!IsCreature(target))
                    continue;

                if (!(e.event.event_flags & SMART_EVENT_FLAG_WHILE_CHARMED) && IsCharmedCreature(target))
                    continue;

                Position pos = target->GetPosition();

                // Use forward/backward/left/right cartesian plane movement
                float x, y, z, o;
                o = pos.GetOrientation();
                x = pos.GetPositionX() + (std::cos(o - (M_PI / 2))*e.target.x) + (std::cos(o)*e.target.y);
                y = pos.GetPositionY() + (std::sin(o - (M_PI / 2))*e.target.x) + (std::sin(o)*e.target.y);
                z = pos.GetPositionZ() + e.target.z;
                target->ToCreature()->GetMotionMaster()->MovePoint(e.action.moveOffset.PointId, x, y, z);
            }
            break;
        }
        case SMART_ACTION_SET_VISIBILITY:
        {
            for (WorldObject* target : targets)
                if (IsUnit(target))
                    target->ToUnit()->SetVisible(e.action.visibility.state ? true : false);
            break;
        }
        case SMART_ACTION_SET_ACTIVE:
        {
            for (WorldObject* target : targets)
                target->setActive(e.action.active.state ? true : false);
            break;
        }
        case SMART_ACTION_ATTACK_START:
        {
            if (!me)
                break;

            if (targets.empty())
                break;

            // attack random target
            if (Unit * target = Trinity::Containers::SelectRandomContainerElement(targets)->ToUnit())
                me->AI()->AttackStart(target);
            break;
        }
        case SMART_ACTION_SUMMON_CREATURE:
        {
            EnumFlag<SmartActionSummonCreatureFlags> flags(static_cast<SmartActionSummonCreatureFlags>(e.action.summonCreature.flags));
            bool preferUnit = flags.HasFlag(SmartActionSummonCreatureFlags::PreferUnit);
            WorldObject* summoner = preferUnit ? unit : GetBaseObjectOrUnitInvoker(unit);
            if (!summoner)
                break;

            ObjectGuid privateObjectOwner;
            if (flags.HasFlag(SmartActionSummonCreatureFlags::PersonalSpawn))
                privateObjectOwner = summoner->IsPrivateObject() ? summoner->GetPrivateObjectOwner() : summoner->GetGUID();
            uint32 spawnsCount = std::max(e.action.summonCreature.count, 1u);

            float x, y, z, o;
            for (WorldObject* target : targets)
            {
                target->GetPosition(x, y, z, o);
                x += e.target.x;
                y += e.target.y;
                z += e.target.z;
                o += e.target.o;
                for (uint32 counter = 0; counter < spawnsCount; counter++)
                {
                    if (Creature* summon = summoner->SummonCreature(e.action.summonCreature.creature, x, y, z, o, (TempSummonType)e.action.summonCreature.type, Milliseconds(e.action.summonCreature.duration), privateObjectOwner))
                        if (e.action.summonCreature.attackInvoker)
                            summon->AI()->AttackStart(target->ToUnit());
                }
            }

            if (e.GetTargetType() != SMART_TARGET_POSITION)
                break;

            for (uint32 counter = 0; counter < spawnsCount; counter++)
            {
                if (Creature* summon = summoner->SummonCreature(e.action.summonCreature.creature, e.target.x, e.target.y, e.target.z, e.target.o, (TempSummonType)e.action.summonCreature.type, Milliseconds(e.action.summonCreature.duration), privateObjectOwner))
                    if (unit && e.action.summonCreature.attackInvoker)
                        summon->AI()->AttackStart(unit);
            }
            break;
        }
        case SMART_ACTION_SUMMON_GO:
        {
            WorldObject* summoner = GetBaseObjectOrUnitInvoker(unit);
            if (!summoner)
                break;

            for (WorldObject* target : targets)
            {
                Position pos = target->GetPositionWithOffset(Position(e.target.x, e.target.y, e.target.z, e.target.o));
                QuaternionData rot = QuaternionData::fromEulerAnglesZYX(pos.GetOrientation(), 0.f, 0.f);
                summoner->SummonGameObject(e.action.summonGO.entry, pos, rot, Seconds(e.action.summonGO.despawnTime), GOSummonType(e.action.summonGO.summonType));
            }

            if (e.GetTargetType() != SMART_TARGET_POSITION)
                break;

            QuaternionData rot = QuaternionData::fromEulerAnglesZYX(e.target.o, 0.f, 0.f);
            summoner->SummonGameObject(e.action.summonGO.entry, Position(e.target.x, e.target.y, e.target.z, e.target.o), rot, Seconds(e.action.summonGO.despawnTime), GOSummonType(e.action.summonGO.summonType));
            break;
        }
        case SMART_ACTION_KILL_UNIT:
        {
            for (WorldObject* target : targets)
            {
                if (!IsUnit(target))
                    continue;

                target->ToUnit()->KillSelf();
            }
            break;
        }
        case SMART_ACTION_ADD_ITEM:
        {
            for (WorldObject* target : targets)
            {
                if (!IsPlayer(target))
                    continue;

                target->ToPlayer()->AddItem(e.action.item.entry, e.action.item.count);
            }
            break;
        }
        case SMART_ACTION_REMOVE_ITEM:
        {
            for (WorldObject* target : targets)
            {
                if (!IsPlayer(target))
                    continue;

                target->ToPlayer()->DestroyItemCount(e.action.item.entry, e.action.item.count, true);
            }
            break;
        }
        case SMART_ACTION_STORE_TARGET_LIST:
        {
            StoreTargetList(targets, e.action.storeTargets.id);
            break;
        }
        case SMART_ACTION_TELEPORT:
        {
            for (WorldObject* target : targets)
            {
                if (IsPlayer(target))
                    target->ToPlayer()->TeleportTo(e.action.teleport.mapID, e.target.x, e.target.y, e.target.z, e.target.o);
                else if (IsCreature(target))
                    target->ToCreature()->NearTeleportTo(e.target.x, e.target.y, e.target.z, e.target.o);
            }
            break;
        }
        case SMART_ACTION_SET_DISABLE_GRAVITY:
        {
            if (!IsSmart())
                break;

            ENSURE_AI(SmartAI, me->AI())->SetDisableGravity(e.action.setDisableGravity.disable != 0);
            break;
        }
        case SMART_ACTION_SET_RUN:
        {
            if (!IsSmart())
                break;

            ENSURE_AI(SmartAI, me->AI())->SetRun(e.action.setRun.run != 0);
            break;
        }
        case SMART_ACTION_SET_COUNTER:
        {
            if (!targets.empty())
            {
                for (WorldObject* target : targets)
                {
                    if (IsCreature(target))
                    {
                        if (SmartAI* ai = CAST_AI(SmartAI, target->ToCreature()->AI()))
                            ai->GetScript()->StoreCounter(e.action.setCounter.counterId, e.action.setCounter.value, e.action.setCounter.reset);
                        else
                            TC_LOG_ERROR("sql.sql", "SmartScript: Action target for SMART_ACTION_SET_COUNTER is not using SmartAI, skipping");
                    }
                    else if (IsGameObject(target))
                    {
                        if (SmartGameObjectAI* ai = CAST_AI(SmartGameObjectAI, target->ToGameObject()->AI()))
                            ai->GetScript()->StoreCounter(e.action.setCounter.counterId, e.action.setCounter.value, e.action.setCounter.reset);
                        else
                            TC_LOG_ERROR("sql.sql", "SmartScript: Action target for SMART_ACTION_SET_COUNTER is not using SmartGameObjectAI, skipping");
                    }
                }
            }
            else
                StoreCounter(e.action.setCounter.counterId, e.action.setCounter.value, e.action.setCounter.reset);
            break;
        }
        case SMART_ACTION_WP_START:
        {
            if (!IsSmart())
                break;

            uint32 entry = e.action.wpStart.pathID;
            bool repeat = e.action.wpStart.repeat != 0;

            for (WorldObject* target : targets)
            {
                if (IsPlayer(target))
                {
                    StoreTargetList(targets, SMART_ESCORT_TARGETS);
                    break;
                }
            }

            ENSURE_AI(SmartAI, me->AI())->StartPath(entry, repeat, unit);

            uint32 quest = e.action.wpStart.quest;
            uint32 DespawnTime = e.action.wpStart.despawnTime;
            ENSURE_AI(SmartAI, me->AI())->SetEscortQuest(quest);
            ENSURE_AI(SmartAI, me->AI())->SetDespawnTime(DespawnTime);
            break;
        }
        case SMART_ACTION_WP_PAUSE:
        {
            if (!IsSmart())
                break;

            uint32 delay = e.action.wpPause.delay;
            ENSURE_AI(SmartAI, me->AI())->PausePath(delay, true);
            break;
        }
        case SMART_ACTION_WP_STOP:
        {
            if (!IsSmart())
                break;

            uint32 DespawnTime = e.action.wpStop.despawnTime;
            uint32 quest = e.action.wpStop.quest;
            bool fail = e.action.wpStop.fail != 0;
            ENSURE_AI(SmartAI, me->AI())->StopPath(DespawnTime, quest, fail);
            break;
        }
        case SMART_ACTION_WP_RESUME:
        {
            if (!IsSmart())
                break;

            // Set the timer to 1 ms so the path will be resumed on next update loop
            if (ENSURE_AI(SmartAI, me->AI())->CanResumePath())
                ENSURE_AI(SmartAI, me->AI())->SetWPPauseTimer(1);
            break;
        }
        case SMART_ACTION_SET_ORIENTATION:
        {
            if (!me)
                break;

            if (e.GetTargetType() == SMART_TARGET_SELF)
                me->SetFacingTo((me->GetTransport() ? me->GetTransportHomePosition() : me->GetHomePosition()).GetOrientation());
            else if (e.GetTargetType() == SMART_TARGET_POSITION)
                me->SetFacingTo(e.target.o);
            else if (!targets.empty())
                me->SetFacingToObject(targets.front());
            break;
        }
        case SMART_ACTION_PLAYMOVIE:
        {
            for (WorldObject* target : targets)
            {
                if (!IsPlayer(target))
                    continue;

                target->ToPlayer()->SendMovieStart(e.action.movie.entry);
            }
            break;
        }
        case SMART_ACTION_MOVE_TO_POS:
        {
            if (!IsSmart())
                break;

            WorldObject* target = nullptr;

            // we want to move to random element
            if (!targets.empty())
                target = Trinity::Containers::SelectRandomContainerElement(targets);

            if (target)
            {
                float x, y, z;
                target->GetPosition(x, y, z);
                if (e.action.moveToPos.ContactDistance > 0)
                    target->GetContactPoint(me, x, y, z, e.action.moveToPos.ContactDistance);
                me->GetMotionMaster()->MovePoint(e.action.moveToPos.pointId, x + e.target.x, y + e.target.y, z + e.target.z, e.action.moveToPos.disablePathfinding == 0);
            }

            if (e.GetTargetType() != SMART_TARGET_POSITION)
                break;

            Position dest(e.target.x, e.target.y, e.target.z);
            if (e.action.moveToPos.transport)
                if (TransportBase* trans = me->GetDirectTransport())
                    trans->CalculatePassengerPosition(dest.m_positionX, dest.m_positionY, dest.m_positionZ);

            me->GetMotionMaster()->MovePoint(e.action.moveToPos.pointId, dest, e.action.moveToPos.disablePathfinding == 0);
            break;
        }
        case SMART_ACTION_ENABLE_TEMP_GOBJ:
        {
            for (WorldObject* target : targets)
            {
                if (IsCreature(target))
                    TC_LOG_WARN("sql.sql", "Invalid creature target '{}' (entry {}, spawnId {}) specified for SMART_ACTION_ENABLE_TEMP_GOBJ", target->GetName(), target->GetEntry(), target->ToCreature()->GetSpawnId());
                else if (IsGameObject(target))
                {
                    if (target->ToGameObject()->isSpawnedByDefault())
                        TC_LOG_WARN("sql.sql", "Invalid gameobject target '{}' (entry {}, spawnId {}) for SMART_ACTION_ENABLE_TEMP_GOBJ - the object is spawned by default", target->GetName(), target->GetEntry(), target->ToGameObject()->GetSpawnId());
                    else
                        target->ToGameObject()->SetRespawnTime(e.action.enableTempGO.duration);
                }
            }
            break;
        }
        case SMART_ACTION_CLOSE_GOSSIP:
        {
            for (WorldObject* target : targets)
                if (IsPlayer(target))
                    target->ToPlayer()->PlayerTalkClass->SendCloseGossip();
            break;
        }
        case SMART_ACTION_EQUIP:
        {
            for (WorldObject* target : targets)
            {
                if (Creature* npc = target->ToCreature())
                {
                    std::array<EquipmentItem, MAX_EQUIPMENT_ITEMS> slot;
                    if (int8 equipId = static_cast<int8>(e.action.equip.entry))
                    {
                        EquipmentInfo const* eInfo = sObjectMgr->GetEquipmentInfo(npc->GetEntry(), equipId);
                        if (!eInfo)
                        {
                            TC_LOG_ERROR("sql.sql", "SmartScript: SMART_ACTION_EQUIP uses non-existent equipment info id {} for creature {}", equipId, npc->GetEntry());
                            break;
                        }

                        npc->SetCurrentEquipmentId(equipId);

                        std::copy(std::begin(eInfo->Items), std::end(eInfo->Items), std::begin(slot));
                    }
                    else
                    {
                        slot[0].ItemId = e.action.equip.slot1;
                        slot[1].ItemId = e.action.equip.slot2;
                        slot[2].ItemId = e.action.equip.slot3;
                    }

                    for (uint32 i = 0; i < MAX_EQUIPMENT_ITEMS; ++i)
                        if (!e.action.equip.mask || (e.action.equip.mask & (1 << i)))
                            npc->SetVirtualItem(i, slot[i].ItemId, slot[i].AppearanceModId, slot[i].ItemVisual);
                }
            }
            break;
        }
        case SMART_ACTION_CREATE_TIMED_EVENT:
        {
            SmartEvent ne = SmartEvent();
            ne.type = (SMART_EVENT)SMART_EVENT_UPDATE;
            ne.event_chance = e.action.timeEvent.chance;
            if (!ne.event_chance) ne.event_chance = 100;

            ne.minMaxRepeat.min = e.action.timeEvent.min;
            ne.minMaxRepeat.max = e.action.timeEvent.max;
            ne.minMaxRepeat.repeatMin = e.action.timeEvent.repeatMin;
            ne.minMaxRepeat.repeatMax = e.action.timeEvent.repeatMax;

            ne.event_flags = 0;
            if (!ne.minMaxRepeat.repeatMin && !ne.minMaxRepeat.repeatMax)
                ne.event_flags |= SMART_EVENT_FLAG_NOT_REPEATABLE;

            SmartAction ac = SmartAction();
            ac.type = (SMART_ACTION)SMART_ACTION_TRIGGER_TIMED_EVENT;
            ac.timeEvent.id = e.action.timeEvent.id;

            SmartScriptHolder ev = SmartScriptHolder();
            ev.event = ne;
            ev.event_id = e.action.timeEvent.id;
            ev.target = e.target;
            ev.action = ac;
            InitTimer(ev);
            mStoredEvents.push_back(ev);
            break;
        }
        case SMART_ACTION_TRIGGER_TIMED_EVENT:
        {
            ProcessEventsFor((SMART_EVENT)SMART_EVENT_TIMED_EVENT_TRIGGERED, nullptr, e.action.timeEvent.id);

            // remove this event if not repeatable
            if (e.event.event_flags & SMART_EVENT_FLAG_NOT_REPEATABLE)
                mRemIDs.push_back(e.action.timeEvent.id);
            break;
        }
        case SMART_ACTION_REMOVE_TIMED_EVENT:
        {
            mRemIDs.push_back(e.action.timeEvent.id);
            break;
        }
        case SMART_ACTION_CALL_SCRIPT_RESET:
        {
            SetPhase(0);
            OnReset();
            break;
        }
        case SMART_ACTION_SET_RANGED_MOVEMENT:
        {
            if (!IsSmart())
                break;

            float attackDistance = float(e.action.setRangedMovement.distance);
            float attackAngle = float(e.action.setRangedMovement.angle) / 180.0f * float(M_PI);

            for (WorldObject* target : targets)
            {
                if (Creature* creature = target->ToCreature())
                    if (IsSmart(creature) && creature->GetVictim())
                        if (ENSURE_AI(SmartAI, creature->AI())->CanCombatMove())
                            creature->StartDefaultCombatMovement(creature->GetVictim(), attackDistance, attackAngle);
            }

            break;
        }
        case SMART_ACTION_CALL_TIMED_ACTIONLIST:
        {
            if (e.GetTargetType() == SMART_TARGET_NONE)
            {
                TC_LOG_ERROR("sql.sql", "SmartScript: Entry {} SourceType {} Event {} Action {} is using TARGET_NONE(0) for Script9 target. Please correct target_type in database.", e.entryOrGuid, e.GetScriptType(), e.GetEventType(), e.GetActionType());
                break;
            }

            for (WorldObject* target : targets)
            {
                if (Creature* creature = target->ToCreature())
                {
                    if (IsSmart(creature))
                        ENSURE_AI(SmartAI, creature->AI())->SetTimedActionList(e, e.action.timedActionList.id, GetLastInvoker());
                }
                else if (GameObject* goTarget = target->ToGameObject())
                {
                    if (IsSmart(goTarget))
                        ENSURE_AI(SmartGameObjectAI, goTarget->AI())->SetTimedActionList(e, e.action.timedActionList.id, GetLastInvoker());
                }
                else if (AreaTrigger* areaTriggerTarget = target->ToAreaTrigger())
                    if (SmartAreaTriggerAI* atSAI = CAST_AI(SmartAreaTriggerAI, areaTriggerTarget->AI()))
                        atSAI->SetTimedActionList(e, e.action.timedActionList.id, GetLastInvoker());
            }
            break;
        }
        case SMART_ACTION_SET_NPC_FLAG:
        {
            for (WorldObject* target : targets)
                if (IsCreature(target))
                    target->ToUnit()->ReplaceAllNpcFlags(NPCFlags(e.action.flag.flag));
            break;
        }
        case SMART_ACTION_ADD_NPC_FLAG:
        {
            for (WorldObject* target : targets)
                if (IsCreature(target))
                    target->ToUnit()->SetNpcFlag(NPCFlags(e.action.flag.flag));
            break;
        }
        case SMART_ACTION_REMOVE_NPC_FLAG:
        {
            for (WorldObject* target : targets)
                if (IsCreature(target))
                    target->ToUnit()->RemoveNpcFlag(NPCFlags(e.action.flag.flag));
            break;
        }
        case SMART_ACTION_CROSS_CAST:
        {
            if (targets.empty())
                break;

            ObjectVector casters;
            GetTargets(casters, CreateSmartEvent(SMART_EVENT_UPDATE_IC, 0, 0, 0, 0, 0, 0, SMART_ACTION_NONE, 0, 0, 0, 0, 0, 0, 0, (SMARTAI_TARGETS)e.action.crossCast.targetType, e.action.crossCast.targetParam1, e.action.crossCast.targetParam2, e.action.crossCast.targetParam3, 0, 0), unit);

            for (WorldObject* caster : casters)
            {
                if (!IsUnit(caster))
                    continue;

                Unit* casterUnit = caster->ToUnit();

                bool interruptedSpell = false;

                for (WorldObject* target : targets)
                {
                    if (!IsUnit(target))
                        continue;

                    if (!(e.action.crossCast.castFlags & SMARTCAST_AURA_NOT_PRESENT) || !target->ToUnit()->HasAura(e.action.crossCast.spell))
                    {
                        if (!interruptedSpell && e.action.crossCast.castFlags & SMARTCAST_INTERRUPT_PREVIOUS)
                        {
                            casterUnit->InterruptNonMeleeSpells(false);
                            interruptedSpell = true;
                        }

                        casterUnit->CastSpell(target->ToUnit(), e.action.crossCast.spell, (e.action.crossCast.castFlags & SMARTCAST_TRIGGERED) != 0);
                    }
                    else
                        TC_LOG_DEBUG("scripts.ai", "Spell {} not cast because it has flag SMARTCAST_AURA_NOT_PRESENT and the target ({}) already has the aura", e.action.crossCast.spell, target->GetGUID().ToString());
                }
            }
            break;
        }
        case SMART_ACTION_CALL_RANDOM_TIMED_ACTIONLIST:
        {
            std::vector<uint32> actionLists;
            std::copy_if(std::begin(e.action.randTimedActionList.actionLists), std::end(e.action.randTimedActionList.actionLists),
                std::back_inserter(actionLists), [](uint32 actionList) { return actionList != 0; });

            uint32 id = Trinity::Containers::SelectRandomContainerElement(actionLists);
            if (e.GetTargetType() == SMART_TARGET_NONE)
            {
                TC_LOG_ERROR("sql.sql", "SmartScript: Entry {} SourceType {} Event {} Action {} is using TARGET_NONE(0) for Script9 target. Please correct target_type in database.", e.entryOrGuid, e.GetScriptType(), e.GetEventType(), e.GetActionType());
                break;
            }

            for (WorldObject* target : targets)
            {
                if (Creature* creature = target->ToCreature())
                {
                    if (IsSmart(creature))
                        ENSURE_AI(SmartAI, creature->AI())->SetTimedActionList(e, id, GetLastInvoker());
                }
                else if (GameObject* goTarget = target->ToGameObject())
                {
                    if (IsSmart(goTarget))
                        ENSURE_AI(SmartGameObjectAI, goTarget->AI())->SetTimedActionList(e, id, GetLastInvoker());
                }
                else if (AreaTrigger* areaTriggerTarget = target->ToAreaTrigger())
                    if (SmartAreaTriggerAI* atSAI = CAST_AI(SmartAreaTriggerAI, areaTriggerTarget->AI()))
                        atSAI->SetTimedActionList(e, id, GetLastInvoker());
            }
            break;
        }
        case SMART_ACTION_CALL_RANDOM_RANGE_TIMED_ACTIONLIST:
        {
            uint32 id = urand(e.action.randRangeTimedActionList.idMin, e.action.randRangeTimedActionList.idMax);
            if (e.GetTargetType() == SMART_TARGET_NONE)
            {
                TC_LOG_ERROR("sql.sql", "SmartScript: Entry {} SourceType {} Event {} Action {} is using TARGET_NONE(0) for Script9 target. Please correct target_type in database.", e.entryOrGuid, e.GetScriptType(), e.GetEventType(), e.GetActionType());
                break;
            }

            for (WorldObject* target : targets)
            {
                if (Creature* creature = target->ToCreature())
                {
                    if (IsSmart(creature))
                        ENSURE_AI(SmartAI, creature->AI())->SetTimedActionList(e, id, GetLastInvoker());
                }
                else if (GameObject* goTarget = target->ToGameObject())
                {
                    if (IsSmart(goTarget))
                        ENSURE_AI(SmartGameObjectAI, goTarget->AI())->SetTimedActionList(e, id, GetLastInvoker());
                }
                else if (AreaTrigger* areaTriggerTarget = target->ToAreaTrigger())
                    if (SmartAreaTriggerAI* atSAI = CAST_AI(SmartAreaTriggerAI, areaTriggerTarget->AI()))
                        atSAI->SetTimedActionList(e, id, GetLastInvoker());
            }
            break;
        }
        case SMART_ACTION_ACTIVATE_TAXI:
        {
            for (WorldObject* target : targets)
                if (IsPlayer(target))
                    target->ToPlayer()->ActivateTaxiPathTo(e.action.taxi.id);
            break;
        }
        case SMART_ACTION_RANDOM_MOVE:
        {
            bool foundTarget = false;

            for (WorldObject* target : targets)
            {
                if (IsCreature((target)))
                {
                    foundTarget = true;

                    if (e.action.moveRandom.distance)
                        target->ToCreature()->GetMotionMaster()->MoveRandom(float(e.action.moveRandom.distance));
                    else
                        target->ToCreature()->GetMotionMaster()->MoveIdle();
                }
            }

            if (!foundTarget && me && IsCreature(me))
            {
                if (e.action.moveRandom.distance)
                    me->GetMotionMaster()->MoveRandom(float(e.action.moveRandom.distance));
                else
                    me->GetMotionMaster()->MoveIdle();
            }
            break;
        }
        case SMART_ACTION_SET_UNIT_FIELD_BYTES_1:
        {
            for (WorldObject* target : targets)
                if (IsUnit(target))
                {
                    switch (e.action.setunitByte.type)
                    {
                        case 0:
                            target->ToUnit()->SetStandState(UnitStandStateType(e.action.setunitByte.byte1));
                            break;
                        case 1:
                            // pet talent points
                            break;
                        case 2:
                            target->ToUnit()->SetVisFlag(UnitVisFlags(e.action.setunitByte.byte1));
                            break;
                        case 3:
                            target->ToUnit()->SetAnimTier(AnimTier(e.action.setunitByte.byte1));
                            break;
                    }
                }
            break;
        }
        case SMART_ACTION_REMOVE_UNIT_FIELD_BYTES_1:
        {
            for (WorldObject* target : targets)
                if (IsUnit(target))
                {
                    switch (e.action.setunitByte.type)
                    {
                        case 0:
                            target->ToUnit()->SetStandState(UNIT_STAND_STATE_STAND);
                            break;
                        case 1:
                            // pet talent points
                            break;
                        case 2:
                            target->ToUnit()->RemoveVisFlag(UnitVisFlags(e.action.setunitByte.byte1));
                            break;
                        case 3:
                            target->ToUnit()->SetAnimTier(AnimTier::Ground);
                            break;
                    }
                }
            break;
        }
        case SMART_ACTION_INTERRUPT_SPELL:
        {
            for (WorldObject* target : targets)
                if (IsUnit(target))
                    target->ToUnit()->InterruptNonMeleeSpells(e.action.interruptSpellCasting.withDelayed != 0, e.action.interruptSpellCasting.spell_id, e.action.interruptSpellCasting.withInstant != 0);
            break;
        }
        case SMART_ACTION_JUMP_TO_POS:
        {
            WorldObject* target = nullptr;

            if (!targets.empty())
                target = Trinity::Containers::SelectRandomContainerElement(targets);

            Position pos(e.target.x, e.target.y, e.target.z);
            if (target)
            {
                float x, y, z;
                target->GetPosition(x, y, z);
                if (e.action.jump.ContactDistance > 0)
                    target->GetContactPoint(me, x, y, z, e.action.jump.ContactDistance);
                pos = Position(x + e.target.x, y + e.target.y, z + e.target.z);
            }
            else if (e.GetTargetType() != SMART_TARGET_POSITION)
                break;

            if (e.action.jump.Gravity || e.action.jump.UseDefaultGravity)
            {
                float gravity = e.action.jump.UseDefaultGravity ? Movement::gravity : e.action.jump.Gravity;
                me->GetMotionMaster()->MoveJumpWithGravity(pos, float(e.action.jump.SpeedXY), gravity, e.action.jump.PointId);
            }
            else
                me->GetMotionMaster()->MoveJump(pos, float(e.action.jump.SpeedXY), float(e.action.jump.SpeedZ), e.action.jump.PointId);

            break;
        }
        case SMART_ACTION_GO_SET_LOOT_STATE:
        {
            for (WorldObject* target : targets)
                if (IsGameObject(target))
                    target->ToGameObject()->SetLootState((LootState)e.action.setGoLootState.state);
            break;
        }
        case SMART_ACTION_GO_SET_GO_STATE:
        {
            for (WorldObject* target : targets)
                if (IsGameObject(target))
                    target->ToGameObject()->SetGoState((GOState)e.action.goState.state);
            break;
        }
        case SMART_ACTION_SEND_TARGET_TO_TARGET:
        {
            WorldObject* ref = GetBaseObject();
            if (!ref)
                ref = unit;

            if (!ref)
                break;

            ObjectVector const* storedTargets = GetStoredTargetVector(e.action.sendTargetToTarget.id, *ref);
            if (!storedTargets)
                break;

            for (WorldObject* target : targets)
            {
                if (IsCreature(target))
                {
                    if (SmartAI* ai = CAST_AI(SmartAI, target->ToCreature()->AI()))
                        ai->GetScript()->StoreTargetList(ObjectVector(*storedTargets), e.action.sendTargetToTarget.id);   // store a copy of target list
                    else
                        TC_LOG_ERROR("sql.sql", "SmartScript: Action target for SMART_ACTION_SEND_TARGET_TO_TARGET is not using SmartAI, skipping");
                }
                else if (IsGameObject(target))
                {
                    if (SmartGameObjectAI* ai = CAST_AI(SmartGameObjectAI, target->ToGameObject()->AI()))
                        ai->GetScript()->StoreTargetList(ObjectVector(*storedTargets), e.action.sendTargetToTarget.id);   // store a copy of target list
                    else
                        TC_LOG_ERROR("sql.sql", "SmartScript: Action target for SMART_ACTION_SEND_TARGET_TO_TARGET is not using SmartGameObjectAI, skipping");
                }
            }
            break;
        }
        case SMART_ACTION_SEND_GOSSIP_MENU:
        {
            if (!GetBaseObject() || !IsSmart())
                break;

            TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_SEND_GOSSIP_MENU: gossipMenuId {}, gossipNpcTextId {}",
                e.action.sendGossipMenu.gossipMenuId, e.action.sendGossipMenu.gossipNpcTextId);

            // override default gossip
            if (me)
                ENSURE_AI(SmartAI, me->AI())->SetGossipReturn(true);
            else if (go)
                ENSURE_AI(SmartGameObjectAI, go->AI())->SetGossipReturn(true);

            for (WorldObject* target : targets)
            {
                if (Player* player = target->ToPlayer())
                {
                    if (e.action.sendGossipMenu.gossipMenuId)
                        player->PrepareGossipMenu(GetBaseObject(), e.action.sendGossipMenu.gossipMenuId, true);
                    else
                        player->PlayerTalkClass->ClearMenus();

                    uint32 gossipNpcTextId = e.action.sendGossipMenu.gossipNpcTextId;
                    if (!gossipNpcTextId)
                        gossipNpcTextId = player->GetGossipTextId(e.action.sendGossipMenu.gossipMenuId, GetBaseObject());

                    player->PlayerTalkClass->SendGossipMenu(gossipNpcTextId, GetBaseObject()->GetGUID());
                }
            }
            break;
        }
        case SMART_ACTION_SET_HOME_POS:
        {
            for (WorldObject* target : targets)
            {
                if (IsCreature(target))
                {
                    if (e.GetTargetType() == SMART_TARGET_SELF)
                        target->ToCreature()->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    else if (e.GetTargetType() == SMART_TARGET_POSITION)
                        target->ToCreature()->SetHomePosition(e.target.x, e.target.y, e.target.z, e.target.o);
                    else if (e.GetTargetType() == SMART_TARGET_CREATURE_RANGE || e.GetTargetType() == SMART_TARGET_CREATURE_GUID ||
                             e.GetTargetType() == SMART_TARGET_CREATURE_DISTANCE || e.GetTargetType() == SMART_TARGET_GAMEOBJECT_RANGE ||
                             e.GetTargetType() == SMART_TARGET_GAMEOBJECT_GUID || e.GetTargetType() == SMART_TARGET_GAMEOBJECT_DISTANCE ||
                             e.GetTargetType() == SMART_TARGET_CLOSEST_CREATURE || e.GetTargetType() == SMART_TARGET_CLOSEST_GAMEOBJECT ||
                             e.GetTargetType() == SMART_TARGET_OWNER_OR_SUMMONER || e.GetTargetType() == SMART_TARGET_ACTION_INVOKER ||
                             e.GetTargetType() == SMART_TARGET_CLOSEST_ENEMY || e.GetTargetType() == SMART_TARGET_CLOSEST_FRIENDLY ||
                             e.GetTargetType() == SMART_TARGET_CLOSEST_UNSPAWNED_GAMEOBJECT)
                    {
                        target->ToCreature()->SetHomePosition(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
                    }
                    else
                        TC_LOG_ERROR("sql.sql", "SmartScript: Action target for SMART_ACTION_SET_HOME_POS is invalid, skipping");
                }
            }
            break;
        }
        case SMART_ACTION_SET_HEALTH_REGEN:
        {
            for (WorldObject* target : targets)
                if (IsCreature(target))
                    target->ToCreature()->SetRegenerateHealth(e.action.setHealthRegen.regenHealth != 0);
            break;
        }
        case SMART_ACTION_SET_ROOT:
        {
            for (WorldObject* target : targets)
                if (IsCreature(target))
                    target->ToCreature()->SetControlled(e.action.setRoot.root != 0, UNIT_STATE_ROOT);
            break;
        }
        case SMART_ACTION_SUMMON_CREATURE_GROUP:
        {
            std::list<TempSummon*> summonList;
            GetBaseObject()->SummonCreatureGroup(e.action.creatureGroup.group, &summonList);

            for (TempSummon* summon : summonList)
                if (unit && e.action.creatureGroup.attackInvoker)
                    summon->AI()->AttackStart(unit);
            break;
        }
        case SMART_ACTION_SET_POWER:
        {
            for (WorldObject* target : targets)
                if (IsUnit(target))
                    target->ToUnit()->SetPower(Powers(e.action.power.powerType), e.action.power.newPower);
            break;
        }
        case SMART_ACTION_ADD_POWER:
        {
            for (WorldObject* target : targets)
                if (IsUnit(target))
                    target->ToUnit()->SetPower(Powers(e.action.power.powerType), target->ToUnit()->GetPower(Powers(e.action.power.powerType)) + e.action.power.newPower);
            break;
        }
        case SMART_ACTION_REMOVE_POWER:
        {
            for (WorldObject* target : targets)
                if (IsUnit(target))
                    target->ToUnit()->SetPower(Powers(e.action.power.powerType), target->ToUnit()->GetPower(Powers(e.action.power.powerType)) - e.action.power.newPower);
            break;
        }
        case SMART_ACTION_GAME_EVENT_STOP:
        {
            uint32 eventId = e.action.gameEventStop.id;
            if (!sGameEventMgr->IsActiveEvent(eventId))
            {
                TC_LOG_ERROR("sql.sql", "SmartScript::ProcessAction: At case SMART_ACTION_GAME_EVENT_STOP, inactive event (id: {})", eventId);
                break;
            }
            sGameEventMgr->StopEvent(eventId, true);
            break;
        }
        case SMART_ACTION_GAME_EVENT_START:
        {
            uint32 eventId = e.action.gameEventStart.id;
            if (sGameEventMgr->IsActiveEvent(eventId))
            {
                TC_LOG_ERROR("sql.sql", "SmartScript::ProcessAction: At case SMART_ACTION_GAME_EVENT_START, already activated event (id: {})", eventId);
                break;
            }
            sGameEventMgr->StartEvent(eventId, true);
            break;
        }
        case SMART_ACTION_START_CLOSEST_WAYPOINT:
        {
            std::vector<uint32> waypoints;
            std::copy_if(std::begin(e.action.closestWaypointFromList.wps), std::end(e.action.closestWaypointFromList.wps),
                std::back_inserter(waypoints), [](uint32 wp) { return wp != 0; });

            float distanceToClosest = std::numeric_limits<float>::max();
            std::pair<uint32, uint32> closest = { 0, 0 };

            for (WorldObject* target : targets)
            {
                if (Creature* creature = target->ToCreature())
                {
                    if (IsSmart(creature))
                    {
                        for (uint32 pathId : waypoints)
                        {
                            WaypointPath const* path = sWaypointMgr->GetPath(pathId);
                            if (!path || path->Nodes.empty())
                                continue;

                            for (WaypointNode const& waypoint : path->Nodes)
                            {
                                float distanceToThisNode = creature->GetDistance(waypoint.X, waypoint.Y, waypoint.Z);
                                if (distanceToThisNode < distanceToClosest)
                                {
                                    distanceToClosest = distanceToThisNode;
                                    closest.first = pathId;
                                    closest.second = waypoint.Id;
                                }
                            }
                        }

                        if (closest.first != 0)
                            ENSURE_AI(SmartAI, creature->AI())->StartPath(closest.first, true, nullptr, closest.second);
                    }
                }
            }
            break;
        }
        case SMART_ACTION_RANDOM_SOUND:
        {
            std::vector<uint32> sounds;
            std::copy_if(std::begin(e.action.randomSound.sounds), std::end(e.action.randomSound.sounds),
                std::back_inserter(sounds), [](uint32 sound) { return sound != 0; });

            bool onlySelf = e.action.randomSound.onlySelf != 0;
            for (WorldObject* const target : targets)
            {
                if (IsUnit(target))
                {
                    uint32 sound = Trinity::Containers::SelectRandomContainerElement(sounds);

                    if (e.action.randomSound.distance == 1)
                        target->PlayDistanceSound(sound, onlySelf ? target->ToPlayer() : nullptr);
                    else
                        target->PlayDirectSound(sound, onlySelf ? target->ToPlayer() : nullptr);

                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_RANDOM_SOUND: target: {} ({}), sound: {}, onlyself: {}",
                        target->GetName(), target->GetGUID().ToString(), sound, onlySelf ? "true" : "false");
                }
            }
            break;
        }
        case SMART_ACTION_SET_CORPSE_DELAY:
        {
            for (WorldObject* const target : targets)
            {
                if (IsCreature(target))
                    target->ToCreature()->SetCorpseDelay(e.action.corpseDelay.timer, !e.action.corpseDelay.includeDecayRatio);
            }

            break;
        }
        case SMART_ACTION_SPAWN_SPAWNGROUP:
        {
            if (e.action.groupSpawn.minDelay == 0 && e.action.groupSpawn.maxDelay == 0)
            {
                bool const ignoreRespawn = ((e.action.groupSpawn.spawnflags & SMARTAI_SPAWN_FLAGS::SMARTAI_SPAWN_FLAG_IGNORE_RESPAWN) != 0);
                bool const force = ((e.action.groupSpawn.spawnflags & SMARTAI_SPAWN_FLAGS::SMARTAI_SPAWN_FLAG_FORCE_SPAWN) != 0);

                // Instant spawn
                GetBaseObject()->GetMap()->SpawnGroupSpawn(e.action.groupSpawn.groupId, ignoreRespawn, force);
            }
            else
            {
                // Delayed spawn (use values from parameter to schedule event to call us back
                SmartEvent ne = SmartEvent();
                ne.type = (SMART_EVENT)SMART_EVENT_UPDATE;
                ne.event_chance = 100;

                ne.minMaxRepeat.min = e.action.groupSpawn.minDelay;
                ne.minMaxRepeat.max = e.action.groupSpawn.maxDelay;
                ne.minMaxRepeat.repeatMin = 0;
                ne.minMaxRepeat.repeatMax = 0;

                ne.event_flags = 0;
                ne.event_flags |= SMART_EVENT_FLAG_NOT_REPEATABLE;

                SmartAction ac = SmartAction();
                ac.type = (SMART_ACTION)SMART_ACTION_SPAWN_SPAWNGROUP;
                ac.groupSpawn.groupId = e.action.groupSpawn.groupId;
                ac.groupSpawn.minDelay = 0;
                ac.groupSpawn.maxDelay = 0;
                ac.groupSpawn.spawnflags = e.action.groupSpawn.spawnflags;
                ac.timeEvent.id = e.action.timeEvent.id;

                SmartScriptHolder ev = SmartScriptHolder();
                ev.event = ne;
                ev.event_id = e.event_id;
                ev.target = e.target;
                ev.action = ac;
                InitTimer(ev);
                mStoredEvents.push_back(ev);
            }
            break;
        }
        case SMART_ACTION_DESPAWN_SPAWNGROUP:
        {
            if (e.action.groupSpawn.minDelay == 0 && e.action.groupSpawn.maxDelay == 0)
            {
                bool const deleteRespawnTimes = ((e.action.groupSpawn.spawnflags & SMARTAI_SPAWN_FLAGS::SMARTAI_SPAWN_FLAG_NOSAVE_RESPAWN) != 0);

                // Instant spawn
                GetBaseObject()->GetMap()->SpawnGroupDespawn(e.action.groupSpawn.groupId, deleteRespawnTimes);
            }
            else
            {
                // Delayed spawn (use values from parameter to schedule event to call us back
                SmartEvent ne = SmartEvent();
                ne.type = (SMART_EVENT)SMART_EVENT_UPDATE;
                ne.event_chance = 100;

                ne.minMaxRepeat.min = e.action.groupSpawn.minDelay;
                ne.minMaxRepeat.max = e.action.groupSpawn.maxDelay;
                ne.minMaxRepeat.repeatMin = 0;
                ne.minMaxRepeat.repeatMax = 0;

                ne.event_flags = 0;
                ne.event_flags |= SMART_EVENT_FLAG_NOT_REPEATABLE;

                SmartAction ac = SmartAction();
                ac.type = (SMART_ACTION)SMART_ACTION_DESPAWN_SPAWNGROUP;
                ac.groupSpawn.groupId = e.action.groupSpawn.groupId;
                ac.groupSpawn.minDelay = 0;
                ac.groupSpawn.maxDelay = 0;
                ac.groupSpawn.spawnflags = e.action.groupSpawn.spawnflags;
                ac.timeEvent.id = e.action.timeEvent.id;

                SmartScriptHolder ev = SmartScriptHolder();
                ev.event = ne;
                ev.event_id = e.event_id;
                ev.target = e.target;
                ev.action = ac;
                InitTimer(ev);
                mStoredEvents.push_back(ev);
            }
            break;
        }
        case SMART_ACTION_DISABLE_EVADE:
        {
            if (!IsSmart())
                break;

            ENSURE_AI(SmartAI, me->AI())->SetEvadeDisabled(e.action.disableEvade.disable != 0);
            break;
        }
        case SMART_ACTION_ADD_THREAT:
        {
            if (!me->CanHaveThreatList())
                break;
            for (WorldObject* const target : targets)
                if (IsUnit(target))
                    me->GetThreatManager().AddThreat(target->ToUnit(), float(e.action.threat.threatINC) - float(e.action.threat.threatDEC), nullptr, true, true);
            break;
        }
        case SMART_ACTION_LOAD_EQUIPMENT:
        {
            for (WorldObject* const target : targets)
                if (IsCreature(target))
                    target->ToCreature()->LoadEquipment(e.action.loadEquipment.id, e.action.loadEquipment.force != 0);
            break;
        }
        case SMART_ACTION_TRIGGER_RANDOM_TIMED_EVENT:
        {
            uint32 eventId = urand(e.action.randomTimedEvent.minId, e.action.randomTimedEvent.maxId);
            ProcessEventsFor((SMART_EVENT)SMART_EVENT_TIMED_EVENT_TRIGGERED, nullptr, eventId);
            break;
        }
        case SMART_ACTION_PAUSE_MOVEMENT:
        {
            for (WorldObject* const target : targets)
                if (IsUnit(target))
                    target->ToUnit()->PauseMovement(e.action.pauseMovement.pauseTimer, e.action.pauseMovement.movementSlot, e.action.pauseMovement.force);
            break;
        }
        case SMART_ACTION_RESPAWN_BY_SPAWNID:
        {
            Map* map = nullptr;
            if (WorldObject* obj = GetBaseObject())
                map = obj->GetMap();
            else if (!targets.empty())
                map = targets.front()->GetMap();

            if (map)
                map->Respawn(SpawnObjectType(e.action.respawnData.spawnType), e.action.respawnData.spawnId);
            else
                TC_LOG_ERROR("sql.sql", "SmartScript::ProcessAction: Entry {} SourceType {}, Event {} - tries to respawn by spawnId but does not provide a map", e.entryOrGuid, e.GetScriptType(), e.event_id);
            break;
        }
        case SMART_ACTION_PLAY_ANIMKIT:
        {
            for (WorldObject* const target : targets)
            {
                if (IsCreature(target))
                {
                    if (e.action.animKit.type == 0)
                        target->ToCreature()->PlayOneShotAnimKitId(e.action.animKit.animKit);
                    else if (e.action.animKit.type == 1)
                        target->ToCreature()->SetAIAnimKitId(e.action.animKit.animKit);
                    else if (e.action.animKit.type == 2)
                        target->ToCreature()->SetMeleeAnimKitId(e.action.animKit.animKit);
                    else if (e.action.animKit.type == 3)
                        target->ToCreature()->SetMovementAnimKitId(e.action.animKit.animKit);

                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_PLAY_ANIMKIT: target: {} ({}), AnimKit: {}, Type: {}",
                        target->GetName(), target->GetGUID().ToString(), e.action.animKit.animKit, e.action.animKit.type);
                }
                else if (IsGameObject(target))
                {
                    switch (e.action.animKit.type)
                    {
                        case 0:
                            target->ToGameObject()->SetAnimKitId(e.action.animKit.animKit, true);
                            break;
                        case 1:
                            target->ToGameObject()->SetAnimKitId(e.action.animKit.animKit, false);
                            break;
                        default:
                            break;
                    }

                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_PLAY_ANIMKIT: target: {} ({}), AnimKit: {}, Type: {}",
                        target->GetName(), target->GetGUID().ToString(), e.action.animKit.animKit, e.action.animKit.type);
                }
            }

            break;
        }
        case SMART_ACTION_SCENE_PLAY:
        {
            for (WorldObject* const target : targets)
                if (Player* playerTarget = target->ToPlayer())
                    playerTarget->GetSceneMgr().PlayScene(e.action.scene.sceneId);

            break;
        }
        case SMART_ACTION_SCENE_CANCEL:
        {
            for (WorldObject* const target : targets)
                if (Player* playerTarget = target->ToPlayer())
                    playerTarget->GetSceneMgr().CancelSceneBySceneId(e.action.scene.sceneId);

            break;
        }
        case SMART_ACTION_PLAY_CINEMATIC:
        {
            for (WorldObject* target : targets)
            {
                if (!IsPlayer(target))
                    continue;

                target->ToPlayer()->SendCinematicStart(e.action.cinematic.entry);
            }
            break;
        }
        case SMART_ACTION_SET_MOVEMENT_SPEED:
        {
            uint32 speedInteger = e.action.movementSpeed.speedInteger;
            uint32 speedFraction = e.action.movementSpeed.speedFraction;
            float speed = float(speedInteger) + float(speedFraction) / std::pow(10, std::floor(std::log10(float(speedFraction ? speedFraction : 1)) + 1));

            for (WorldObject* const target : targets)
                if (IsCreature(target))
                    target->ToCreature()->SetSpeed(UnitMoveType(e.action.movementSpeed.movementType), speed);

            break;
        }
        case SMART_ACTION_PLAY_SPELL_VISUAL_KIT:
        {
            for (WorldObject* const target : targets)
            {
                if (IsUnit(target))
                {
                    target->ToUnit()->SendPlaySpellVisualKit(e.action.spellVisualKit.spellVisualKitId, e.action.spellVisualKit.kitType,
                        e.action.spellVisualKit.duration);

                    TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_PLAY_SPELL_VISUAL_KIT: target: {} ({}), SpellVisualKit: {}",
                        target->GetName(), target->GetGUID().ToString(), e.action.spellVisualKit.spellVisualKitId);
                }
            }

            break;
        }
        case SMART_ACTION_OVERRIDE_LIGHT:
        {
            if (WorldObject* obj = GetBaseObject())
            {
                obj->GetMap()->SetZoneOverrideLight(e.action.overrideLight.zoneId, e.action.overrideLight.areaLightId, e.action.overrideLight.overrideLightId, Milliseconds(e.action.overrideLight.transitionMilliseconds));
                TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_OVERRIDE_LIGHT: {} sets zone override light (zoneId: {}, areaLightId: {}, overrideLightId: {}, transitionMilliseconds: {})",
                    obj->GetGUID().ToString(), e.action.overrideLight.zoneId, e.action.overrideLight.areaLightId, e.action.overrideLight.overrideLightId, e.action.overrideLight.transitionMilliseconds);
            }
            break;
        }
        case SMART_ACTION_OVERRIDE_WEATHER:
        {
            if (WorldObject* obj = GetBaseObject())
            {
                obj->GetMap()->SetZoneWeather(e.action.overrideWeather.zoneId, (WeatherState)e.action.overrideWeather.weatherId, float(e.action.overrideWeather.intensity));
                TC_LOG_DEBUG("scripts.ai", "SmartScript::ProcessAction: SMART_ACTION_OVERRIDE_WEATHER: {} sets zone weather (zoneId: {}, weatherId: {}, intensity: {})",
                    obj->GetGUID().ToString(), e.action.overrideWeather.zoneId, e.action.overrideWeather.weatherId, e.action.overrideWeather.intensity);
            }
            break;
        }
        case SMART_ACTION_SET_HOVER:
        {
            for (WorldObject* target : targets)
                if (IsUnit(target))
                    target->ToUnit()->SetHover(e.action.setHover.enable != 0);
            break;
        }
        case SMART_ACTION_SET_HEALTH_PCT:
        {
            for (WorldObject* target : targets)
                if (Unit* targetUnit = target->ToUnit())
                    targetUnit->SetHealth(targetUnit->CountPctFromMaxHealth(e.action.setHealthPct.percent));
            break;
        }
        case SMART_ACTION_CREATE_CONVERSATION:
        {
            WorldObject* baseObject = GetBaseObject();

            for (WorldObject* const target : targets)
            {
                if (Player* playerTarget = target->ToPlayer())
                {
                    Conversation* conversation = Conversation::CreateConversation(e.action.conversation.id, playerTarget,
                        *playerTarget, playerTarget->GetGUID(), nullptr);
                    if (!conversation)
                        TC_LOG_WARN("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_CREATE_CONVERSATION: id {}, baseObject {}, target {} - failed to create conversation",
                            e.action.conversation.id, !baseObject ? "" : baseObject->GetName().c_str(), playerTarget->GetName());
                }
            }

            break;
        }
        case SMART_ACTION_SET_IMMUNE_PC:
        {
            for (WorldObject* target : targets)
            {
                if (IsUnit(target))
                {
                    if (e.action.setImmunePC.immunePC)
                        target->ToUnit()->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    else
                        target->ToUnit()->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                }
            }
            break;
        }
        case SMART_ACTION_SET_IMMUNE_NPC:
        {
            for (WorldObject* target : targets)
            {
                if (IsUnit(target))
                {
                    if (e.action.setImmuneNPC.immuneNPC)
                        target->ToUnit()->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                    else
                        target->ToUnit()->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                }
            }
            break;
        }
        case SMART_ACTION_SET_UNINTERACTIBLE:
        {
            for (WorldObject* target : targets)
            {
                if (IsUnit(target))
                {
                    target->ToUnit()->SetUninteractible(e.action.setUninteractible.uninteractible != 0);
                }
            }
            break;
        }
        case SMART_ACTION_ACTIVATE_GAMEOBJECT:
        {
            for (WorldObject* target : targets)
            {
                if (GameObject* targetGo = target->ToGameObject())
                {
                    targetGo->ActivateObject(GameObjectActions(e.action.activateGameObject.gameObjectAction), e.action.activateGameObject.param, GetBaseObject());
                }
            }
            break;
        }
        case SMART_ACTION_ADD_TO_STORED_TARGET_LIST:
        {
            if (!targets.empty())
                AddToStoredTargetList(targets, e.action.addToStoredTargets.id);
            else
            {
                WorldObject* baseObject = GetBaseObject();
                TC_LOG_WARN("scripts.ai", "SmartScript::ProcessAction:: SMART_ACTION_ADD_TO_STORED_TARGET_LIST: var {}, baseObject {}, event {} - tried to add no targets to stored target list",
                    e.action.addToStoredTargets.id, !baseObject ? "" : baseObject->GetName().c_str(), e.event_id);
            }
            break;
        }
        case SMART_ACTION_BECOME_PERSONAL_CLONE_FOR_PLAYER:
        {
            WorldObject* baseObject = GetBaseObject();

            auto doCreatePersonalClone = [&](Position const& position, Player* privateObjectOwner)
            {
                if (Creature* summon = GetBaseObject()->SummonPersonalClone(position, TempSummonType(e.action.becomePersonalClone.type), Milliseconds(e.action.becomePersonalClone.duration), 0, 0, privateObjectOwner))
                    if (IsSmart(summon))
                        ENSURE_AI(SmartAI, summon->AI())->SetTimedActionList(e, e.entryOrGuid, privateObjectOwner, e.event_id + 1);
            };

            // if target is position then targets container was empty
            if (e.GetTargetType() != SMART_TARGET_POSITION)
            {
                for (WorldObject* target : targets)
                    if (Player* playerTarget = Object::ToPlayer(target))
                        doCreatePersonalClone(baseObject->GetPosition(), playerTarget);
            }
            else
            {
                if (Player* invoker = Object::ToPlayer(GetLastInvoker()))
                    doCreatePersonalClone({ e.target.x, e.target.y, e.target.z, e.target.o }, invoker);
            }

            // action list will continue on personal clones
            Trinity::Containers::EraseIf(mTimedActionList, [e](SmartScriptHolder const& script) { return script.event_id > e.event_id; });
            break;
        }
        case SMART_ACTION_TRIGGER_GAME_EVENT:
        {
            WorldObject* sourceObject = GetBaseObjectOrUnitInvoker(unit);
            for (WorldObject* target : targets)
            {
                if (e.action.triggerGameEvent.useSaiTargetAsGameEventSource)
                    GameEvents::Trigger(e.action.triggerGameEvent.eventId, target, sourceObject);
                else
                    GameEvents::Trigger(e.action.triggerGameEvent.eventId, sourceObject, target);
            }

            break;
        }
        case SMART_ACTION_DO_ACTION:
        {
            for (WorldObject* target : targets)
            {
                if (Unit* unitTarget = Object::ToUnit(target))
                {
                    if (unitTarget->GetAI())
                        unitTarget->GetAI()->DoAction(e.action.doAction.actionId);
                }
                else if (GameObject* goTarget = Object::ToGameObject(target))
                {
                    if (goTarget->AI())
                        goTarget->AI()->DoAction(e.action.doAction.actionId);
                }
            }

            break;
        }
        default:
            TC_LOG_ERROR("sql.sql", "SmartScript::ProcessAction: Entry {} SourceType {}, Event {}, Unhandled Action type {}", e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType());
            break;
    }

    if (e.link && e.link != e.event_id)
    {
        SmartScriptHolder& linked = SmartAIMgr::FindLinkedEvent(mEvents, e.link);
        if (linked)
            ProcessEvent(linked, unit, var0, var1, bvar, spell, gob, varString);
        else
            TC_LOG_DEBUG("sql.sql", "SmartScript::ProcessAction: Entry {} SourceType {}, Event {}, Link Event {} not found or invalid, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.link);
    }
}

void SmartScript::ProcessTimedAction(SmartScriptHolder& e, uint32 const& min, uint32 const& max, Unit* unit, uint32 var0, uint32 var1, bool bvar, SpellInfo const* spell, GameObject* gob, std::string const& varString)
{
    // We may want to execute action rarely and because of this if condition is not fulfilled the action will be rechecked in a long time
    if (sConditionMgr->IsObjectMeetingSmartEventConditions(e.entryOrGuid, e.event_id, e.source_type, unit, GetBaseObject()))
    {
        RecalcTimer(e, min, max);
        ProcessAction(e, unit, var0, var1, bvar, spell, gob, varString);
    }
    else
        RecalcTimer(e, std::min<uint32>(min, 5000), std::min<uint32>(min, 5000));
}

SmartScriptHolder SmartScript::CreateSmartEvent(SMART_EVENT e, uint32 event_flags, uint32 event_param1, uint32 event_param2, uint32 event_param3, uint32 event_param4, uint32 event_param5, SMART_ACTION action, uint32 action_param1, uint32 action_param2, uint32 action_param3, uint32 action_param4, uint32 action_param5, uint32 action_param6, uint32 action_param7, SMARTAI_TARGETS t, uint32 target_param1, uint32 target_param2, uint32 target_param3, uint32 target_param4, uint32 phaseMask)
{
    SmartScriptHolder script;
    script.event.type = e;
    script.event.raw.param1 = event_param1;
    script.event.raw.param2 = event_param2;
    script.event.raw.param3 = event_param3;
    script.event.raw.param4 = event_param4;
    script.event.raw.param5 = event_param5;
    script.event.event_phase_mask = phaseMask;
    script.event.event_flags = event_flags;
    script.event.event_chance = 100;

    script.action.type = action;
    script.action.raw.param1 = action_param1;
    script.action.raw.param2 = action_param2;
    script.action.raw.param3 = action_param3;
    script.action.raw.param4 = action_param4;
    script.action.raw.param5 = action_param5;
    script.action.raw.param6 = action_param6;
    script.action.raw.param7 = action_param7;

    script.target.type = t;
    script.target.raw.param1 = target_param1;
    script.target.raw.param2 = target_param2;
    script.target.raw.param3 = target_param3;
    script.target.raw.param4 = target_param4;

    script.source_type = SMART_SCRIPT_TYPE_CREATURE;
    InitTimer(script);
    return script;
}

void SmartScript::GetTargets(ObjectVector& targets, SmartScriptHolder const& e, WorldObject* invoker /*= nullptr*/) const
{
    WorldObject* scriptTrigger = nullptr;
    if (invoker)
        scriptTrigger = invoker;
    else if (Unit* tempLastInvoker = GetLastInvoker())
        scriptTrigger = tempLastInvoker;

    WorldObject* baseObject = GetBaseObject();
    switch (e.GetTargetType())
    {
        case SMART_TARGET_SELF:
            if (baseObject)
                targets.push_back(baseObject);
            break;
        case SMART_TARGET_VICTIM:
            if (me)
                if (Unit* victim = me->GetVictim())
                    targets.push_back(victim);
            break;
        case SMART_TARGET_HOSTILE_SECOND_AGGRO:
            if (me)
            {
                if (e.target.hostilRandom.powerType)
                {
                    if (Unit* u = me->AI()->SelectTarget(SelectTargetMethod::MaxThreat, 1, PowerUsersSelector(me, Powers(e.target.hostilRandom.powerType - 1), float(e.target.hostilRandom.maxDist), e.target.hostilRandom.playerOnly != 0)))
                        targets.push_back(u);
                }
                else if (Unit* u = me->AI()->SelectTarget(SelectTargetMethod::MaxThreat, 1, float(e.target.hostilRandom.maxDist), e.target.hostilRandom.playerOnly != 0))
                    targets.push_back(u);
            }
            break;
        case SMART_TARGET_HOSTILE_LAST_AGGRO:
            if (me)
            {
                if (e.target.hostilRandom.powerType)
                {
                    if (Unit* u = me->AI()->SelectTarget(SelectTargetMethod::MinThreat, 0, PowerUsersSelector(me, Powers(e.target.hostilRandom.powerType - 1), float(e.target.hostilRandom.maxDist), e.target.hostilRandom.playerOnly != 0)))
                        targets.push_back(u);
                }
                else if (Unit* u = me->AI()->SelectTarget(SelectTargetMethod::MinThreat, 0, float(e.target.hostilRandom.maxDist), e.target.hostilRandom.playerOnly != 0))
                    targets.push_back(u);
            }
            break;
        case SMART_TARGET_HOSTILE_RANDOM:
            if (me)
            {
                if (e.target.hostilRandom.powerType)
                {
                    if (Unit* u = me->AI()->SelectTarget(SelectTargetMethod::Random, 0, PowerUsersSelector(me, Powers(e.target.hostilRandom.powerType - 1), float(e.target.hostilRandom.maxDist), e.target.hostilRandom.playerOnly != 0)))
                        targets.push_back(u);
                }
                else if (Unit* u = me->AI()->SelectTarget(SelectTargetMethod::Random, 0, float(e.target.hostilRandom.maxDist), e.target.hostilRandom.playerOnly != 0))
                    targets.push_back(u);
            }
            break;
        case SMART_TARGET_HOSTILE_RANDOM_NOT_TOP:
            if (me)
            {
                if (e.target.hostilRandom.powerType)
                {
                    if (Unit* u = me->AI()->SelectTarget(SelectTargetMethod::Random, 1, PowerUsersSelector(me, Powers(e.target.hostilRandom.powerType - 1), float(e.target.hostilRandom.maxDist), e.target.hostilRandom.playerOnly != 0)))
                        targets.push_back(u);
                }
                else if (Unit* u = me->AI()->SelectTarget(SelectTargetMethod::Random, 1, float(e.target.hostilRandom.maxDist), e.target.hostilRandom.playerOnly != 0))
                    targets.push_back(u);
            }
            break;
        case SMART_TARGET_FARTHEST:
            if (me)
            {
                if (Unit* u = me->AI()->SelectTarget(SelectTargetMethod::MaxDistance, 0, FarthestTargetSelector(me, float(e.target.farthest.maxDist), e.target.farthest.playerOnly != 0, e.target.farthest.isInLos != 0)))
                    targets.push_back(u);
            }
            break;
        case SMART_TARGET_ACTION_INVOKER:
            if (scriptTrigger)
                targets.push_back(scriptTrigger);
            break;
        case SMART_TARGET_ACTION_INVOKER_VEHICLE:
            if (scriptTrigger && scriptTrigger->ToUnit() && scriptTrigger->ToUnit()->GetVehicle() && scriptTrigger->ToUnit()->GetVehicle()->GetBase())
                targets.push_back(scriptTrigger->ToUnit()->GetVehicle()->GetBase());
            break;
        case SMART_TARGET_INVOKER_PARTY:
            if (scriptTrigger)
            {
                if (Player* player = scriptTrigger->ToPlayer())
                {
                    if (Group* group = player->GetGroup())
                    {
                        for (GroupReference* groupRef = group->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                            if (Player* member = groupRef->GetSource())
                                if (member->IsInMap(player))
                                    targets.push_back(member);
                    }
                    // We still add the player to the list if there is no group. If we do
                    // this even if there is a group (thus the else-check), it will add the
                    // same player to the list twice. We don't want that to happen.
                    else
                        targets.push_back(scriptTrigger);
                }
            }
            break;
        case SMART_TARGET_CREATURE_RANGE:
        {
            WorldObject* ref = baseObject;
            if (!ref)
                ref = scriptTrigger;

            if (!ref)
            {
                TC_LOG_ERROR("sql.sql", "SMART_TARGET_CREATURE_RANGE: Entry {} SourceType {} Event {} Action {} Target {} is missing base object or invoker.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.GetTargetType());
                break;
            }

            ObjectVector units;
            GetWorldObjectsInDist(units, static_cast<float>(e.target.unitRange.maxDist));

            for (WorldObject* unit : units)
            {
                if (!IsCreature(unit))
                    continue;

                if (me && me->GetGUID() == unit->GetGUID())
                    continue;

                if ((!e.target.unitRange.creature || unit->ToCreature()->GetEntry() == e.target.unitRange.creature) && ref->IsInRange(unit, float(e.target.unitRange.minDist), float(e.target.unitRange.maxDist)))
                    targets.push_back(unit);
            }

            if (e.target.unitRange.maxSize)
                Trinity::Containers::RandomResize(targets, e.target.unitRange.maxSize);
            break;
        }
        case SMART_TARGET_CREATURE_DISTANCE:
        {
            ObjectVector units;
            GetWorldObjectsInDist(units, static_cast<float>(e.target.unitDistance.dist));

            for (WorldObject* unit : units)
            {
                if (!IsCreature(unit))
                    continue;

                if (me && me->GetGUID() == unit->GetGUID())
                    continue;

                if (!e.target.unitDistance.creature || unit->ToCreature()->GetEntry() == e.target.unitDistance.creature)
                    targets.push_back(unit);
            }

            if (e.target.unitDistance.maxSize)
                Trinity::Containers::RandomResize(targets, e.target.unitDistance.maxSize);
            break;
        }
        case SMART_TARGET_GAMEOBJECT_DISTANCE:
        {
            ObjectVector units;
            GetWorldObjectsInDist(units, static_cast<float>(e.target.goDistance.dist));

            for (WorldObject* unit : units)
            {
                if (!IsGameObject(unit))
                    continue;

                if (go && go->GetGUID() == unit->GetGUID())
                    continue;

                if (!e.target.goDistance.entry || unit->ToGameObject()->GetEntry() == e.target.goDistance.entry)
                    targets.push_back(unit);
            }

            if (e.target.goDistance.maxSize)
                Trinity::Containers::RandomResize(targets, e.target.goDistance.maxSize);
            break;
        }
        case SMART_TARGET_GAMEOBJECT_RANGE:
        {
            WorldObject* ref = baseObject;
            if (!ref)
                ref = scriptTrigger;

            if (!ref)
            {
                TC_LOG_ERROR("sql.sql", "SMART_TARGET_GAMEOBJECT_RANGE: Entry {} SourceType {} Event {} Action {} Target {} is missing base object or invoker.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.GetTargetType());
                break;
            }

            ObjectVector units;
            GetWorldObjectsInDist(units, static_cast<float>(e.target.goRange.maxDist));

            for (WorldObject* unit : units)
            {
                if (!IsGameObject(unit))
                    continue;

                if (go && go->GetGUID() == unit->GetGUID())
                    continue;

                if ((!e.target.goRange.entry || unit->ToGameObject()->GetEntry() == e.target.goRange.entry) && ref->IsInRange(unit, float(e.target.goRange.minDist), float(e.target.goRange.maxDist)))
                    targets.push_back(unit);
            }

            if (e.target.goRange.maxSize)
                Trinity::Containers::RandomResize(targets, e.target.goRange.maxSize);
            break;
        }
        case SMART_TARGET_CREATURE_GUID:
        {
            if (!scriptTrigger && !baseObject)
            {
                TC_LOG_ERROR("sql.sql", "SMART_TARGET_CREATURE_GUID: Entry {} SourceType {} Event {} Action {} Target {} is missing base object or invoker.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.GetTargetType());
                break;
            }

            if (Creature* target = FindCreatureNear(scriptTrigger ? scriptTrigger : baseObject, e.target.unitGUID.dbGuid))
                if (!e.target.unitGUID.entry || target->GetEntry() == e.target.unitGUID.entry)
                    targets.push_back(target);
            break;
        }
        case SMART_TARGET_GAMEOBJECT_GUID:
        {
            if (!scriptTrigger && !baseObject)
            {
                TC_LOG_ERROR("sql.sql", "SMART_TARGET_GAMEOBJECT_GUID: Entry {} SourceType {} Event {} Action {} Target {} is missing base object or invoker.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.GetTargetType());
                break;
            }

            if (GameObject* target = FindGameObjectNear(scriptTrigger ? scriptTrigger : baseObject, e.target.goGUID.dbGuid))
                if (!e.target.goGUID.entry || target->GetEntry() == e.target.goGUID.entry)
                    targets.push_back(target);
            break;
        }
        case SMART_TARGET_PLAYER_RANGE:
        {
            ObjectVector units;
            GetWorldObjectsInDist(units, static_cast<float>(e.target.playerRange.maxDist));

            if (!units.empty() && baseObject)
                for (WorldObject* unit : units)
                    if (IsPlayer(unit) && baseObject->IsInRange(unit, float(e.target.playerRange.minDist), float(e.target.playerRange.maxDist)))
                        targets.push_back(unit);
            break;
        }
        case SMART_TARGET_PLAYER_DISTANCE:
        {
            ObjectVector units;
            GetWorldObjectsInDist(units, static_cast<float>(e.target.playerDistance.dist));

            for (WorldObject* unit : units)
                if (IsPlayer(unit))
                    targets.push_back(unit);
            break;
        }
        case SMART_TARGET_STORED:
        {
            WorldObject* ref = baseObject;
            if (!ref)
                ref = scriptTrigger;

            if (!ref)
            {
                TC_LOG_ERROR("sql.sql", "SMART_TARGET_STORED: Entry {} SourceType {} Event {} Action {} Target {} is missing base object or invoker.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.GetTargetType());
                break;
            }

            if (ObjectVector const* stored = GetStoredTargetVector(e.target.stored.id, *ref))
                targets.assign(stored->begin(), stored->end());
            break;
        }
        case SMART_TARGET_CLOSEST_CREATURE:
        {
            WorldObject* ref = baseObject;
            if (!ref)
                ref = scriptTrigger;

            if (!ref)
            {
                TC_LOG_ERROR("sql.sql", "SMART_TARGET_CLOSEST_CREATURE: Entry {} SourceType {} Event {} Action {} Target {} is missing base object or invoker.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.GetTargetType());
                break;
            }

            if (Creature* target = ref->FindNearestCreature(e.target.unitClosest.entry, float(e.target.unitClosest.dist ? e.target.unitClosest.dist : 100), !e.target.unitClosest.dead))
                targets.push_back(target);
            break;
        }
        case SMART_TARGET_CLOSEST_GAMEOBJECT:
        {
            WorldObject* ref = baseObject;
            if (!ref)
                ref = scriptTrigger;

            if (!ref)
            {
                TC_LOG_ERROR("sql.sql", "SMART_TARGET_CLOSEST_GAMEOBJECT: Entry {} SourceType {} Event {} Action {} Target {} is missing base object or invoker.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.GetTargetType());
                break;
            }

            if (GameObject* target = ref->FindNearestGameObject(e.target.goClosest.entry, float(e.target.goClosest.dist ? e.target.goClosest.dist : 100)))
                targets.push_back(target);
            break;
        }
        case SMART_TARGET_CLOSEST_PLAYER:
        {
            WorldObject* ref = baseObject;
            if (!ref)
                ref = scriptTrigger;

            if (!ref)
            {
                TC_LOG_ERROR("sql.sql", "SMART_TARGET_CLOSEST_PLAYER: Entry {} SourceType {} Event {} Action {} Target {} is missing base object or invoker.",
                    e.entryOrGuid, e.GetScriptType(), e.event_id, e.GetActionType(), e.GetTargetType());
                break;
            }

            if (Player* target = ref->SelectNearestPlayer(float(e.target.playerDistance.dist)))
                targets.push_back(target);
            break;
        }
        case SMART_TARGET_OWNER_OR_SUMMONER:
        {
            if (me)
            {
                ObjectGuid charmerOrOwnerGuid = me->GetCharmerOrOwnerGUID();

                if (!charmerOrOwnerGuid)
                    if (TempSummon* tempSummon = me->ToTempSummon())
                        if (WorldObject* summoner = tempSummon->GetSummoner())
                            charmerOrOwnerGuid = summoner->GetGUID();

                if (!charmerOrOwnerGuid)
                    charmerOrOwnerGuid = me->GetCreatorGUID();

                if (WorldObject* owner = ObjectAccessor::GetWorldObject(*me, charmerOrOwnerGuid))
                    targets.push_back(owner);
            }
            else if (go)
            {
                if (Unit* owner = ObjectAccessor::GetUnit(*go, go->GetOwnerGUID()))
                    targets.push_back(owner);
            }

            // Get owner of owner
            if (e.target.owner.useCharmerOrOwner && !targets.empty())
            {
                WorldObject* owner = targets.front();
                targets.clear();

                if (Unit* base = ObjectAccessor::GetUnit(*owner, owner->GetCharmerOrOwnerGUID()))
                    targets.push_back(base);
            }
            break;
        }
        case SMART_TARGET_THREAT_LIST:
        {
            if (me && me->CanHaveThreatList())
                for (auto* ref : me->GetThreatManager().GetUnsortedThreatList())
                    if (!e.target.threatList.maxDist || me->IsWithinCombatRange(ref->GetVictim(), float(e.target.threatList.maxDist)))
                        targets.push_back(ref->GetVictim());
            break;
        }
        case SMART_TARGET_CLOSEST_ENEMY:
        {
            if (me)
                if (Unit* target = me->SelectNearestTarget(e.target.closestAttackable.maxDist, e.target.closestAttackable.playerOnly != 0))
                    targets.push_back(target);
            break;
        }
        case SMART_TARGET_CLOSEST_FRIENDLY:
        {
            if (me)
                if (Unit* target = DoFindClosestFriendlyInRange(e.target.closestFriendly.maxDist, e.target.closestFriendly.playerOnly != 0))
                    targets.push_back(target);
            break;
        }
        case SMART_TARGET_LOOT_RECIPIENTS:
        {
            if (me)
                for (ObjectGuid tapperGuid : me->GetTapList())
                    if (Player* tapper = ObjectAccessor::GetPlayer(*me, tapperGuid))
                        targets.push_back(tapper);

            break;
        }
        case SMART_TARGET_VEHICLE_PASSENGER:
        {
            if (me && me->IsVehicle())
                for (std::pair<int8 const, VehicleSeat>& seat : me->GetVehicleKit()->Seats)
                    if (!e.target.vehicle.seatMask || (e.target.vehicle.seatMask & (1 << seat.first)))
                        if (Unit* u = ObjectAccessor::GetUnit(*me, seat.second.Passenger.Guid))
                            targets.push_back(u);
            break;
        }
        case SMART_TARGET_CLOSEST_UNSPAWNED_GAMEOBJECT:
        {
            if (GameObject* target = baseObject->FindNearestUnspawnedGameObject(e.target.goClosest.entry, float(e.target.goClosest.dist ? e.target.goClosest.dist : 100)))
                targets.push_back(target);
            break;
        }
        case SMART_TARGET_POSITION:
        case SMART_TARGET_NONE:
        default:
            break;
    }
}

void SmartScript::GetWorldObjectsInDist(ObjectVector& targets, float dist) const
{
    WorldObject* obj = GetBaseObject();
    if (!obj)
        return;

    Trinity::AllWorldObjectsInRange u_check(obj, dist);
    Trinity::WorldObjectListSearcher<Trinity::AllWorldObjectsInRange> searcher(obj, targets, u_check);
    Cell::VisitAllObjects(obj, searcher, dist);
}

void SmartScript::ProcessEvent(SmartScriptHolder& e, Unit* unit, uint32 var0, uint32 var1, bool bvar, SpellInfo const* spell, GameObject* gob, std::string const& varString)
{
    if (!e.active && e.GetEventType() != SMART_EVENT_LINK)
        return;

    if ((e.event.event_phase_mask && !IsInPhase(e.event.event_phase_mask)) || ((e.event.event_flags & SMART_EVENT_FLAG_NOT_REPEATABLE) && e.runOnce))
        return;

    if (!(e.event.event_flags & SMART_EVENT_FLAG_WHILE_CHARMED) && IsCharmedCreature(me))
        return;

    switch (e.GetEventType())
    {
        case SMART_EVENT_LINK://special handling
            ProcessAction(e, unit, var0, var1, bvar, spell, gob);
            break;
        //called from Update tick
        case SMART_EVENT_UPDATE:
            ProcessTimedAction(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            break;
        case SMART_EVENT_UPDATE_OOC:
            if (me && me->IsEngaged())
                return;
            ProcessTimedAction(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            break;
        case SMART_EVENT_UPDATE_IC:
            if (!me || !me->IsEngaged())
                return;
            ProcessTimedAction(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            break;
        case SMART_EVENT_HEALTH_PCT:
        {
            if (!me || !me->IsEngaged() || !me->GetMaxHealth())
                return;
            uint32 perc = (uint32)me->GetHealthPct();
            if (perc > e.event.minMaxRepeat.max || perc < e.event.minMaxRepeat.min)
                return;
            ProcessTimedAction(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            break;
        }
        case SMART_EVENT_MANA_PCT:
        {
            if (!me || !me->IsEngaged() || !me->GetMaxPower(POWER_MANA))
                return;
            uint32 perc = uint32(me->GetPowerPct(POWER_MANA));
            if (perc > e.event.minMaxRepeat.max || perc < e.event.minMaxRepeat.min)
                return;
            ProcessTimedAction(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            break;
        }
        case SMART_EVENT_RANGE:
        {
            if (!me || !me->IsEngaged() || !me->GetVictim())
                return;

            if (me->IsInRange(me->GetVictim(), (float)e.event.minMaxRepeat.min, (float)e.event.minMaxRepeat.max))
                ProcessTimedAction(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax, me->GetVictim());
            else // make it predictable
                RecalcTimer(e, 500, 500);
            break;
        }
        case SMART_EVENT_VICTIM_CASTING:
        {
            if (!me || !me->IsEngaged())
                return;

            Unit* victim = me->GetVictim();

            if (!victim || !victim->IsNonMeleeSpellCast(false, false, true))
                return;

            if (e.event.targetCasting.spellId > 0)
                if (Spell* currSpell = victim->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                    if (currSpell->m_spellInfo->Id != e.event.targetCasting.spellId)
                        return;

            ProcessTimedAction(e, e.event.targetCasting.repeatMin, e.event.targetCasting.repeatMax, me->GetVictim());
            break;
        }
        case SMART_EVENT_FRIENDLY_IS_CC:
        {
            if (!me || !me->IsEngaged())
                return;

            std::vector<Creature*> creatures;
            DoFindFriendlyCC(creatures, float(e.event.friendlyCC.radius));
            if (creatures.empty())
            {
                // if there are at least two same npcs, they will perform the same action immediately even if this is useless...
                RecalcTimer(e, 1000, 3000);
                return;
            }
            ProcessTimedAction(e, e.event.friendlyCC.repeatMin, e.event.friendlyCC.repeatMax, Trinity::Containers::SelectRandomContainerElement(creatures));
            break;
        }
        case SMART_EVENT_FRIENDLY_MISSING_BUFF:
        {
            std::vector<Creature*> creatures;
            DoFindFriendlyMissingBuff(creatures, float(e.event.missingBuff.radius), e.event.missingBuff.spell);

            if (creatures.empty())
                return;

            ProcessTimedAction(e, e.event.missingBuff.repeatMin, e.event.missingBuff.repeatMax, Trinity::Containers::SelectRandomContainerElement(creatures));
            break;
        }
        case SMART_EVENT_HAS_AURA:
        {
            if (!me)
                return;
            uint32 count = me->GetAuraCount(e.event.aura.spell);
            if ((!e.event.aura.count && !count) || (e.event.aura.count && count >= e.event.aura.count))
                ProcessTimedAction(e, e.event.aura.repeatMin, e.event.aura.repeatMax);
            break;
        }
        case SMART_EVENT_TARGET_BUFFED:
        {
            if (!me || !me->GetVictim())
                return;
            uint32 count = me->EnsureVictim()->GetAuraCount(e.event.aura.spell);
            if (count < e.event.aura.count)
                return;
            ProcessTimedAction(e, e.event.aura.repeatMin, e.event.aura.repeatMax, me->GetVictim());
            break;
        }
        case SMART_EVENT_CHARMED:
        {
            if (bvar == (e.event.charm.onRemove != 1))
                ProcessAction(e, unit, var0, var1, bvar, spell, gob);
            break;
        }
        case SMART_EVENT_QUEST_ACCEPTED:
        case SMART_EVENT_QUEST_COMPLETION:
        case SMART_EVENT_QUEST_REWARDED:
        case SMART_EVENT_QUEST_FAIL:
        {
            ProcessAction(e, unit);
            break;
        }
        case SMART_EVENT_QUEST_OBJ_COMPLETION:
        {
            if (var0 == (e.event.questObjective.id))
                ProcessAction(e, unit);
            break;
        }
        //no params
        case SMART_EVENT_AGGRO:
        case SMART_EVENT_DEATH:
        case SMART_EVENT_EVADE:
        case SMART_EVENT_REACHED_HOME:
        case SMART_EVENT_CORPSE_REMOVED:
        case SMART_EVENT_AI_INIT:
        case SMART_EVENT_TRANSPORT_ADDPLAYER:
        case SMART_EVENT_TRANSPORT_REMOVE_PLAYER:
        case SMART_EVENT_JUST_SUMMONED:
        case SMART_EVENT_RESET:
        case SMART_EVENT_JUST_CREATED:
        case SMART_EVENT_FOLLOW_COMPLETED:
        case SMART_EVENT_ON_SPELLCLICK:
        case SMART_EVENT_ON_DESPAWN:
        case SMART_EVENT_SEND_EVENT_TRIGGER:
            ProcessAction(e, unit, var0, var1, bvar, spell, gob);
            break;
        case SMART_EVENT_GOSSIP_HELLO:
            switch (e.event.gossipHello.filter)
            {
                case 0:
                    // no filter set, always execute action
                    break;
                case 1:
                    // OnGossipHello only filter set, skip action if OnReportUse
                    if (var0)
                        return;
                    break;
                case 2:
                    // OnReportUse only filter set, skip action if OnGossipHello
                    if (!var0)
                        return;
                    break;
                default:
                    // Ignore any other value
                    break;
            }

            ProcessAction(e, unit, var0, var1, bvar, spell, gob);
            break;
        case SMART_EVENT_RECEIVE_EMOTE:
            if (e.event.emote.emote == var0)
            {
                RecalcTimer(e, e.event.emote.cooldownMin, e.event.emote.cooldownMax);
                ProcessAction(e, unit);
            }
            break;
        case SMART_EVENT_KILL:
        {
            if (!me || !unit)
                return;
            if (e.event.kill.playerOnly && unit->GetTypeId() != TYPEID_PLAYER)
                return;
            if (e.event.kill.creature && unit->GetEntry() != e.event.kill.creature)
                return;
            RecalcTimer(e, e.event.kill.cooldownMin, e.event.kill.cooldownMax);
            ProcessAction(e, unit);
            break;
        }
        case SMART_EVENT_SPELLHIT_TARGET:
        case SMART_EVENT_SPELLHIT:
        {
            if (!spell)
                return;
            if ((!e.event.spellHit.spell || spell->Id == e.event.spellHit.spell) &&
                (!e.event.spellHit.school || (spell->SchoolMask & e.event.spellHit.school)))
                {
                    RecalcTimer(e, e.event.spellHit.cooldownMin, e.event.spellHit.cooldownMax);
                    ProcessAction(e, unit, 0, 0, bvar, spell, gob);
                }
            break;
        }
        case SMART_EVENT_ON_SPELL_CAST:
        case SMART_EVENT_ON_SPELL_FAILED:
        case SMART_EVENT_ON_SPELL_START:
        {
            if (!spell)
                return;

            if (spell->Id != e.event.spellCast.spell)
                return;

            RecalcTimer(e, e.event.spellCast.cooldownMin, e.event.spellCast.cooldownMax);
            ProcessAction(e, nullptr, 0, 0, bvar, spell);
            break;
        }
        case SMART_EVENT_OOC_LOS:
        {
            if (!me || me->IsEngaged())
                return;
            //can trigger if closer than fMaxAllowedRange
            float range = (float)e.event.los.maxDist;

            //if range is ok and we are actually in LOS
            if (me->IsWithinDistInMap(unit, range) && me->IsWithinLOSInMap(unit))
            {
                SmartEvent::LOSHostilityMode hostilityMode = static_cast<SmartEvent::LOSHostilityMode>(e.event.los.hostilityMode);
                //if friendly event&&who is not hostile OR hostile event&&who is hostile
                if ((hostilityMode == SmartEvent::LOSHostilityMode::Any) ||
                    (hostilityMode == SmartEvent::LOSHostilityMode::NotHostile && !me->IsHostileTo(unit)) ||
                    (hostilityMode == SmartEvent::LOSHostilityMode::Hostile && me->IsHostileTo(unit)))
                {
                    if (e.event.los.playerOnly && unit->GetTypeId() != TYPEID_PLAYER)
                        return;
                    RecalcTimer(e, e.event.los.cooldownMin, e.event.los.cooldownMax);
                    ProcessAction(e, unit);
                }
            }
            break;
        }
        case SMART_EVENT_IC_LOS:
        {
            if (!me || !me->IsEngaged())
                return;
            //can trigger if closer than fMaxAllowedRange
            float range = (float)e.event.los.maxDist;

            //if range is ok and we are actually in LOS
            if (me->IsWithinDistInMap(unit, range) && me->IsWithinLOSInMap(unit))
            {
                SmartEvent::LOSHostilityMode hostilityMode = static_cast<SmartEvent::LOSHostilityMode>(e.event.los.hostilityMode);
                //if friendly event&&who is not hostile OR hostile event&&who is hostile
                if ((hostilityMode == SmartEvent::LOSHostilityMode::Any) ||
                    (hostilityMode == SmartEvent::LOSHostilityMode::NotHostile && !me->IsHostileTo(unit)) ||
                    (hostilityMode == SmartEvent::LOSHostilityMode::Hostile && me->IsHostileTo(unit)))
                {
                    if (e.event.los.playerOnly && unit->GetTypeId() != TYPEID_PLAYER)
                        return;
                    RecalcTimer(e, e.event.los.cooldownMin, e.event.los.cooldownMax);
                    ProcessAction(e, unit);
                }
            }
            break;
        }
        case SMART_EVENT_RESPAWN:
        {
            if (!GetBaseObject())
                return;
            if (e.event.respawn.type == SMART_SCRIPT_RESPAWN_CONDITION_MAP && GetBaseObject()->GetMapId() != e.event.respawn.map)
                return;
            if (e.event.respawn.type == SMART_SCRIPT_RESPAWN_CONDITION_AREA && GetBaseObject()->GetZoneId() != e.event.respawn.area)
                return;
            ProcessAction(e);
            break;
        }
        case SMART_EVENT_SUMMONED_UNIT:
        case SMART_EVENT_SUMMONED_UNIT_DIES:
        {
            if (!IsCreature(unit))
                return;
            if (e.event.summoned.creature && unit->GetEntry() != e.event.summoned.creature)
                return;
            RecalcTimer(e, e.event.summoned.cooldownMin, e.event.summoned.cooldownMax);
            ProcessAction(e, unit);
            break;
        }
        case SMART_EVENT_RECEIVE_HEAL:
        case SMART_EVENT_DAMAGED:
        case SMART_EVENT_DAMAGED_TARGET:
        {
            if (var0 > e.event.minMaxRepeat.max || var0 < e.event.minMaxRepeat.min)
                return;
            RecalcTimer(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            ProcessAction(e, unit);
            break;
        }
        case SMART_EVENT_MOVEMENTINFORM:
        {
            if ((e.event.movementInform.type && var0 != e.event.movementInform.type) || (e.event.movementInform.id != 0xFFFFFFFF && var1 != e.event.movementInform.id))
                return;
            ProcessAction(e, unit, var0, var1);
            break;
        }
        case SMART_EVENT_TRANSPORT_RELOCATE:
        {
            if (e.event.transportRelocate.pointID && var0 != e.event.transportRelocate.pointID)
                return;
            ProcessAction(e, unit, var0);
            break;
        }
        case SMART_EVENT_WAYPOINT_REACHED:
        case SMART_EVENT_WAYPOINT_RESUMED:
        case SMART_EVENT_WAYPOINT_PAUSED:
        case SMART_EVENT_WAYPOINT_STOPPED:
        case SMART_EVENT_WAYPOINT_ENDED:
        {
            if (!me || (e.event.waypoint.pointID != 0xFFFFFFFF && var0 != e.event.waypoint.pointID) || (e.event.waypoint.pathID && var1 != e.event.waypoint.pathID))
                return;
            ProcessAction(e, unit);
            break;
        }
        case SMART_EVENT_SUMMON_DESPAWNED:
        {
            if (e.event.summoned.creature && e.event.summoned.creature != var0)
                return;
            RecalcTimer(e, e.event.summoned.cooldownMin, e.event.summoned.cooldownMax);
            ProcessAction(e, unit, var0);
            break;
        }
        case SMART_EVENT_INSTANCE_PLAYER_ENTER:
        {
            if (e.event.instancePlayerEnter.team && var0 != e.event.instancePlayerEnter.team)
                return;
            RecalcTimer(e, e.event.instancePlayerEnter.cooldownMin, e.event.instancePlayerEnter.cooldownMax);
            ProcessAction(e, unit, var0);
            break;
        }
        case SMART_EVENT_ACCEPTED_QUEST:
        case SMART_EVENT_REWARD_QUEST:
        {
            if (e.event.quest.quest && var0 != e.event.quest.quest)
                return;
            RecalcTimer(e, e.event.quest.cooldownMin, e.event.quest.cooldownMax);
            ProcessAction(e, unit, var0);
            break;
        }
        case SMART_EVENT_TRANSPORT_ADDCREATURE:
        {
            if (e.event.transportAddCreature.creature && var0 != e.event.transportAddCreature.creature)
                return;
            ProcessAction(e, unit, var0);
            break;
        }
        case SMART_EVENT_AREATRIGGER_ONTRIGGER:
        {
            if (e.event.areatrigger.id && var0 != e.event.areatrigger.id)
                return;
            ProcessAction(e, unit, var0);
            break;
        }
        case SMART_EVENT_TEXT_OVER:
        {
            if (var0 != e.event.textOver.textGroupID || (e.event.textOver.creatureEntry && e.event.textOver.creatureEntry != var1))
                return;
            ProcessAction(e, unit, var0);
            break;
        }
        case SMART_EVENT_DATA_SET:
        {
            if (e.event.dataSet.id != var0 || e.event.dataSet.value != var1)
                return;
            RecalcTimer(e, e.event.dataSet.cooldownMin, e.event.dataSet.cooldownMax);
            ProcessAction(e, unit, var0, var1);
            break;
        }
        case SMART_EVENT_PASSENGER_REMOVED:
        case SMART_EVENT_PASSENGER_BOARDED:
        {
            if (!unit)
                return;
            RecalcTimer(e, e.event.minMax.repeatMin, e.event.minMax.repeatMax);
            ProcessAction(e, unit);
            break;
        }
        case SMART_EVENT_TIMED_EVENT_TRIGGERED:
        {
            if (e.event.timedEvent.id == var0)
                ProcessAction(e, unit);
            break;
        }
        case SMART_EVENT_GOSSIP_SELECT:
        {
            TC_LOG_DEBUG("scripts.ai", "SmartScript: Gossip Select:  menu {} action {}", var0, var1);//little help for scripters
            if (e.event.gossip.sender != var0 || e.event.gossip.action != var1)
                return;
            ProcessAction(e, unit, var0, var1);
            break;
        }
        case SMART_EVENT_GAME_EVENT_START:
        case SMART_EVENT_GAME_EVENT_END:
        {
            if (e.event.gameEvent.gameEventId != var0)
                return;
            ProcessAction(e, nullptr, var0);
            break;
        }
        case SMART_EVENT_GO_LOOT_STATE_CHANGED:
        {
            if (e.event.goLootStateChanged.lootState != var0)
                return;
            ProcessAction(e, unit, var0, var1);
            break;
        }
        case SMART_EVENT_GO_EVENT_INFORM:
        {
            if (e.event.eventInform.eventId != var0)
                return;
            ProcessAction(e, nullptr, var0);
            break;
        }
        case SMART_EVENT_ACTION_DONE:
        {
            if (e.event.doAction.eventId != var0)
                return;
            ProcessAction(e, unit, var0);
            break;
        }
        case SMART_EVENT_FRIENDLY_HEALTH_PCT:
        {
            if (!me || !me->IsEngaged())
                return;

            Unit* unitTarget = nullptr;
            switch (e.GetTargetType())
            {
                case SMART_TARGET_CREATURE_RANGE:
                case SMART_TARGET_CREATURE_GUID:
                case SMART_TARGET_CREATURE_DISTANCE:
                case SMART_TARGET_CLOSEST_CREATURE:
                case SMART_TARGET_CLOSEST_PLAYER:
                case SMART_TARGET_PLAYER_RANGE:
                case SMART_TARGET_PLAYER_DISTANCE:
                {
                    ObjectVector targets;
                    GetTargets(targets, e);

                    for (WorldObject* target : targets)
                    {
                        if (IsUnit(target) && me->IsFriendlyTo(target->ToUnit()) && target->ToUnit()->IsAlive() && target->ToUnit()->IsInCombat())
                        {
                            uint32 healthPct = uint32(target->ToUnit()->GetHealthPct());
                            if (healthPct > e.event.friendlyHealthPct.maxHpPct || healthPct < e.event.friendlyHealthPct.minHpPct)
                                continue;

                            unitTarget = target->ToUnit();
                            break;
                        }
                    }
                    break;
                }
                case SMART_TARGET_ACTION_INVOKER:
                    unitTarget = DoSelectLowestHpPercentFriendly((float)e.event.friendlyHealthPct.radius, e.event.friendlyHealthPct.minHpPct, e.event.friendlyHealthPct.maxHpPct);
                    break;
                default:
                    return;
            }

            if (!unitTarget)
                return;

            ProcessTimedAction(e, e.event.friendlyHealthPct.repeatMin, e.event.friendlyHealthPct.repeatMax, unitTarget);
            break;
        }
        case SMART_EVENT_DISTANCE_CREATURE:
        {
            if (!me)
                return;

            Creature* creature = nullptr;

            if (e.event.distance.guid != 0)
            {
                creature = FindCreatureNear(me, e.event.distance.guid);
                if (!creature)
                    return;

                if (!me->IsInRange(creature, 0, static_cast<float>(e.event.distance.dist)))
                    return;
            }
            else if (e.event.distance.entry != 0)
            {
                std::list<Creature*> list;
                me->GetCreatureListWithEntryInGrid(list, e.event.distance.entry, static_cast<float>(e.event.distance.dist));

                if (!list.empty())
                    creature = list.front();
            }

            if (creature)
                ProcessTimedAction(e, e.event.distance.repeat, e.event.distance.repeat, creature);

            break;
        }
        case SMART_EVENT_DISTANCE_GAMEOBJECT:
        {
            if (!me)
                return;

            GameObject* gameobject = nullptr;

            if (e.event.distance.guid != 0)
            {
                gameobject = FindGameObjectNear(me, e.event.distance.guid);
                if (!gameobject)
                    return;

                if (!me->IsInRange(gameobject, 0, static_cast<float>(e.event.distance.dist)))
                    return;
            }
            else if (e.event.distance.entry != 0)
            {
                std::list<GameObject*> list;
                me->GetGameObjectListWithEntryInGrid(list, e.event.distance.entry, static_cast<float>(e.event.distance.dist));

                if (!list.empty())
                    gameobject = list.front();
            }

            if (gameobject)
                ProcessTimedAction(e, e.event.distance.repeat, e.event.distance.repeat, nullptr, 0, 0, false, nullptr, gameobject);

            break;
        }
        case SMART_EVENT_COUNTER_SET:
            if (e.event.counter.id != var0 || GetCounterValue(e.event.counter.id) != e.event.counter.value)
                return;

            ProcessTimedAction(e, e.event.counter.cooldownMin, e.event.counter.cooldownMax);
            break;
        case SMART_EVENT_SCENE_START:
        case SMART_EVENT_SCENE_CANCEL:
        case SMART_EVENT_SCENE_COMPLETE:
        {
            ProcessAction(e, unit);
            break;
        }
        case SMART_EVENT_SCENE_TRIGGER:
        {
            if (e.event.param_string != varString)
                return;

            ProcessAction(e, unit, var0, 0, false, nullptr, nullptr, varString);
            break;
        }
        default:
            TC_LOG_ERROR("sql.sql", "SmartScript::ProcessEvent: Unhandled Event type {}", e.GetEventType());
            break;
    }
}

void SmartScript::InitTimer(SmartScriptHolder& e)
{
    switch (e.GetEventType())
    {
        //set only events which have initial timers
        case SMART_EVENT_UPDATE:
        case SMART_EVENT_UPDATE_IC:
        case SMART_EVENT_UPDATE_OOC:
            RecalcTimer(e, e.event.minMaxRepeat.min, e.event.minMaxRepeat.max);
            break;
        case SMART_EVENT_DISTANCE_CREATURE:
        case SMART_EVENT_DISTANCE_GAMEOBJECT:
            RecalcTimer(e, e.event.distance.repeat, e.event.distance.repeat);
            break;
        default:
            e.active = true;
            break;
    }
}
void SmartScript::RecalcTimer(SmartScriptHolder& e, uint32 min, uint32 max)
{
    // min/max was checked at loading!
    e.timer = urand(min, max);
    e.active = e.timer ? false : true;
}

void SmartScript::UpdateTimer(SmartScriptHolder& e, uint32 const diff)
{
    if (e.GetEventType() == SMART_EVENT_LINK)
        return;

    if (e.event.event_phase_mask && !IsInPhase(e.event.event_phase_mask))
        return;

    if (e.GetEventType() == SMART_EVENT_UPDATE_IC && (!me || !me->IsEngaged()))
        return;

    if (e.GetEventType() == SMART_EVENT_UPDATE_OOC && (me && me->IsEngaged())) //can be used with me=nullptr (go script)
        return;

    if (e.timer < diff)
    {
        // delay spell cast event if another spell is being cast
        if (e.GetActionType() == SMART_ACTION_CAST)
        {
            if (!(e.action.cast.castFlags & SMARTCAST_INTERRUPT_PREVIOUS))
            {
                if (me && me->HasUnitState(UNIT_STATE_CASTING))
                {
                    RaisePriority(e);
                    return;
                }
            }
        }

        // Delay flee for assist event if stunned or rooted
        if (e.GetActionType() == SMART_ACTION_FLEE_FOR_ASSIST)
        {
            if (me && me->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_LOST_CONTROL))
            {
                e.timer = 1;
                return;
            }
        }

        e.active = true;//activate events with cooldown

        switch (e.GetEventType())//process ONLY timed events
        {
            case SMART_EVENT_UPDATE:
            case SMART_EVENT_UPDATE_OOC:
            case SMART_EVENT_UPDATE_IC:
            case SMART_EVENT_HEALTH_PCT:
            case SMART_EVENT_MANA_PCT:
            case SMART_EVENT_RANGE:
            case SMART_EVENT_VICTIM_CASTING:
            case SMART_EVENT_FRIENDLY_IS_CC:
            case SMART_EVENT_FRIENDLY_MISSING_BUFF:
            case SMART_EVENT_HAS_AURA:
            case SMART_EVENT_TARGET_BUFFED:
            case SMART_EVENT_FRIENDLY_HEALTH_PCT:
            case SMART_EVENT_DISTANCE_CREATURE:
            case SMART_EVENT_DISTANCE_GAMEOBJECT:
            {
                if (e.GetScriptType() == SMART_SCRIPT_TYPE_TIMED_ACTIONLIST)
                {
                    Unit* invoker = nullptr;
                    if (me && !mTimedActionListInvoker.IsEmpty())
                        invoker = ObjectAccessor::GetUnit(*me, mTimedActionListInvoker);
                    ProcessEvent(e, invoker);
                    e.enableTimed = false;//disable event if it is in an ActionList and was processed once
                    for (SmartScriptHolder& scriptholder : mTimedActionList)
                    {
                        //find the first event which is not the current one and enable it
                        if (scriptholder.event_id > e.event_id)
                        {
                            scriptholder.enableTimed = true;
                            break;
                        }
                    }
                }
                else
                    ProcessEvent(e);
                break;
            }
        }

        if (e.priority != SmartScriptHolder::DEFAULT_PRIORITY)
        {
            // Reset priority to default one only if the event hasn't been rescheduled again to next loop
            if (e.timer > 1)
            {
                // Re-sort events if this was moved to the top of the queue
                 mEventSortingRequired = true;
                // Reset priority to default one
                e.priority = SmartScriptHolder::DEFAULT_PRIORITY;
            }
        }
    }
    else
        e.timer -= diff;
}

bool SmartScript::CheckTimer(SmartScriptHolder const& e) const
{
    return e.active;
}

void SmartScript::InstallEvents()
{
    if (!mInstallEvents.empty())
    {
        for (SmartScriptHolder& installevent : mInstallEvents)
            mEvents.push_back(installevent);//must be before UpdateTimers

        mInstallEvents.clear();
    }
}

void SmartScript::RemoveStoredEvent(uint32 id)
{
    if (!mStoredEvents.empty())
    {
        for (auto i = mStoredEvents.begin(); i != mStoredEvents.end(); ++i)
        {
            if (i->event_id == id)
            {
                mStoredEvents.erase(i);
                return;
            }
        }
    }
}

WorldObject* SmartScript::GetBaseObject() const
{
    WorldObject* obj = nullptr;
    if (me)
        obj = me;
    else if (go)
        obj = go;
    else if (areaTrigger)
        obj = areaTrigger;
    else if (player)
        obj = player;
    return obj;
}

WorldObject* SmartScript::GetBaseObjectOrUnitInvoker(Unit* invoker)
{
    return Coalesce<WorldObject>(GetBaseObject(), invoker);
}

bool SmartScript::IsUnit(WorldObject* obj)
{
    return obj && (obj->GetTypeId() == TYPEID_UNIT || obj->GetTypeId() == TYPEID_PLAYER);
}

bool SmartScript::IsPlayer(WorldObject* obj)
{
    return obj && obj->GetTypeId() == TYPEID_PLAYER;
}

bool SmartScript::IsCreature(WorldObject* obj)
{
    return obj && obj->GetTypeId() == TYPEID_UNIT;
}

bool SmartScript::IsCharmedCreature(WorldObject* obj)
{
    if (!obj)
        return false;

    if (Creature* creatureObj = obj->ToCreature())
        return creatureObj->IsCharmed();

    return false;
}

bool SmartScript::IsGameObject(WorldObject* obj)
{
    return obj && obj->GetTypeId() == TYPEID_GAMEOBJECT;
}

void SmartScript::OnUpdate(uint32 const diff)
{
    if ((mScriptType == SMART_SCRIPT_TYPE_CREATURE
        || mScriptType == SMART_SCRIPT_TYPE_GAMEOBJECT
        || mScriptType == SMART_SCRIPT_TYPE_AREATRIGGER_ENTITY
        || mScriptType == SMART_SCRIPT_TYPE_AREATRIGGER_ENTITY_CUSTOM)
        && !GetBaseObject())
        return;

    // Don't run any action while evading
    if (me && me->IsInEvadeMode())
    {
        // Check if the timed action list finished and clear it if so.
        // This is required by SMART_ACTION_CALL_TIMED_ACTIONLIST failing if mTimedActionList is not empty.
        if (!mTimedActionList.empty())
        {
            bool needCleanup = true;
            for (SmartScriptHolder& scriptholder : mTimedActionList)
            {
                if (scriptholder.enableTimed)
                    needCleanup = false;
            }

            if (needCleanup)
                mTimedActionList.clear();
        }

        return;
    }

    InstallEvents();//before UpdateTimers

    if (mEventSortingRequired)
    {
        SortEvents(mEvents);
        mEventSortingRequired = false;
    }

    for (SmartScriptHolder& mEvent : mEvents)
        UpdateTimer(mEvent, diff);

    if (!mStoredEvents.empty())
    {
        SmartAIEventStoredList::iterator i, icurr;
        for (i = mStoredEvents.begin(); i != mStoredEvents.end();)
        {
            icurr = i++;
            UpdateTimer(*icurr, diff);
        }
    }

    bool needCleanup = true;
    if (!mTimedActionList.empty())
    {
        isProcessingTimedActionList = true;

        for (size_t i = 0; i < mTimedActionList.size(); ++i)
        {
            SmartScriptHolder& scriptHolder = mTimedActionList[i];
            if (scriptHolder.enableTimed)
            {
                UpdateTimer(scriptHolder, diff);
                needCleanup = false;
            }
        }

        isProcessingTimedActionList = false;
    }

    if (needCleanup)
        mTimedActionList.clear();

    if (!mRemIDs.empty())
    {
        for (auto i : mRemIDs)
            RemoveStoredEvent(i);

        mRemIDs.clear();
    }

    if (mUseTextTimer && me)
    {
        if (mTextTimer < diff)
        {
            uint32 textID = mLastTextID;
            mLastTextID = 0;
            uint32 entry = mTalkerEntry;
            mTalkerEntry = 0;
            mTextTimer = 0;
            mUseTextTimer = false;
            ProcessEventsFor(SMART_EVENT_TEXT_OVER, nullptr, textID, entry);
        } else mTextTimer -= diff;
    }
}

void SmartScript::SortEvents(SmartAIEventList& events)
{
    std::sort(events.begin(), events.end());
}

void SmartScript::RaisePriority(SmartScriptHolder& e)
{
    e.timer = 1;
    // Change priority only if it's set to default, otherwise keep the current order of events
    if (e.priority == SmartScriptHolder::DEFAULT_PRIORITY)
    {
        e.priority = mCurrentPriority++;
        mEventSortingRequired = true;
    }
}

void SmartScript::RetryLater(SmartScriptHolder& e, bool ignoreChanceRoll)
{
    RaisePriority(e);

    // This allows to retry the action later without rolling again the chance roll (which might fail and end up not executing the action)
    if (ignoreChanceRoll)
        e.event.event_flags |= SMART_EVENT_FLAG_TEMP_IGNORE_CHANCE_ROLL;

    e.runOnce = false;
}

void SmartScript::FillScript(SmartAIEventList e, WorldObject* obj, AreaTriggerEntry const* at, SceneTemplate const* scene, Quest const* quest, uint32 event)
{
    if (e.empty())
    {
        if (obj)
            TC_LOG_DEBUG("scripts.ai", "SmartScript: EventMap for Entry {} is empty but is using SmartScript.", obj->GetEntry());
        if (at)
            TC_LOG_DEBUG("scripts.ai", "SmartScript: EventMap for AreaTrigger {} is empty but is using SmartScript.", at->ID);
        if (scene)
            TC_LOG_DEBUG("scripts.ai", "SmartScript: EventMap for SceneId {} is empty but is using SmartScript.", scene->SceneId);
        if (quest)
            TC_LOG_DEBUG("scripts.ai", "SmartScript: EventMap for Quest {} is empty but is using SmartScript.", quest->GetQuestId());
        if (event)
            TC_LOG_DEBUG("scripts.ai", "SmartScript: EventMap for Event {} is empty but is using SmartScript.", event);
        return;
    }
    for (SmartScriptHolder& scriptholder : e)
    {
        #ifndef TRINITY_DEBUG
            if (scriptholder.event.event_flags & SMART_EVENT_FLAG_DEBUG_ONLY)
                continue;
        #endif

        if (obj && scriptholder.Difficulties.size())
        {
            bool foundValidDifficulty = false;
            for (Difficulty difficulty : scriptholder.Difficulties)
            {
                if (difficulty == obj->GetMap()->GetDifficultyID())
                {
                    foundValidDifficulty = true;
                    break;
                }
            }

            if (!foundValidDifficulty)
                continue;
        }

        mAllEventFlags |= scriptholder.event.event_flags;
        mEvents.push_back(scriptholder);
    }
}

void SmartScript::GetScript()
{
    SmartAIEventList e;

    // We must use script type to avoid ambiguities
    switch (mScriptType)
    {
        case SMART_SCRIPT_TYPE_CREATURE:
            e = sSmartScriptMgr->GetScript(-((int32)me->GetSpawnId()), mScriptType);
            if (e.empty())
                e = sSmartScriptMgr->GetScript((int32)me->GetEntry(), mScriptType);
            FillScript(std::move(e), me, nullptr, nullptr, nullptr, 0);
            break;
        case SMART_SCRIPT_TYPE_GAMEOBJECT:
            e = sSmartScriptMgr->GetScript(-((int32)go->GetSpawnId()), mScriptType);
            if (e.empty())
                e = sSmartScriptMgr->GetScript((int32)go->GetEntry(), mScriptType);
            FillScript(std::move(e), go, nullptr, nullptr, nullptr, 0);
            break;
        case SMART_SCRIPT_TYPE_AREATRIGGER_ENTITY:
        case SMART_SCRIPT_TYPE_AREATRIGGER_ENTITY_CUSTOM:
            e = sSmartScriptMgr->GetScript((int32)areaTrigger->GetEntry(), mScriptType);
            FillScript(std::move(e), areaTrigger, nullptr, nullptr, nullptr, 0);
            break;
        case SMART_SCRIPT_TYPE_AREATRIGGER:
            e = sSmartScriptMgr->GetScript((int32)trigger->ID, mScriptType);
            FillScript(std::move(e), nullptr, trigger, nullptr, nullptr, 0);
            break;
        case SMART_SCRIPT_TYPE_SCENE:
            e = sSmartScriptMgr->GetScript(sceneTemplate->SceneId, mScriptType);
            FillScript(std::move(e), nullptr, nullptr, sceneTemplate, nullptr, 0);
            break;
        case SMART_SCRIPT_TYPE_QUEST:
            e = sSmartScriptMgr->GetScript(quest->GetQuestId(), mScriptType);
            FillScript(std::move(e), nullptr, nullptr, nullptr, quest, 0);
            break;
        case SMART_SCRIPT_TYPE_EVENT:
            e = sSmartScriptMgr->GetScript((int32)event, mScriptType);
            FillScript(std::move(e), nullptr, nullptr, nullptr, nullptr, event);
            break;
        default:
            break;
    }
}

void SmartScript::OnInitialize(WorldObject* obj, AreaTriggerEntry const* at, SceneTemplate const* scene, Quest const* qst, uint32 evnt)
{
    if (at)
    {
        mScriptType = SMART_SCRIPT_TYPE_AREATRIGGER;
        trigger = at;
        player = obj->ToPlayer();

        if (!player)
        {
            TC_LOG_ERROR("misc", "SmartScript::OnInitialize: source is AreaTrigger with id {}, missing trigger player", trigger->ID);
            return;
        }

        TC_LOG_DEBUG("scripts.ai", "SmartScript::OnInitialize: source is AreaTrigger with id {}, triggered by player {}", trigger->ID, player->GetGUID().ToString());
    }
    else if (scene)
    {
        mScriptType = SMART_SCRIPT_TYPE_SCENE;
        sceneTemplate = scene;
        player = obj->ToPlayer();

        if (!player)
        {
            TC_LOG_ERROR("misc", "SmartScript::OnInitialize: source is Scene with id {}, missing trigger player", scene->SceneId);
            return;
        }

        TC_LOG_DEBUG("scripts.ai", "SmartScript::OnInitialize: source is Scene with id {}, triggered by player {}", scene->SceneId, player->GetGUID().ToString());
    }
    else if (qst)
    {
        mScriptType = SMART_SCRIPT_TYPE_QUEST;
        quest = qst;
        player = obj->ToPlayer();

        if (!player)
        {
            TC_LOG_ERROR("misc", "SmartScript::OnInitialize: source is Quest with id {}, missing trigger player", qst->GetQuestId());
            return;
        }

        TC_LOG_DEBUG("scripts.ai", "SmartScript::OnInitialize: source is Quest with id {}, triggered by player {}", qst->GetQuestId(), player->GetGUID().ToString());
    }
    else if (evnt)
    {
        mScriptType = SMART_SCRIPT_TYPE_EVENT;
        event = evnt;

        if (obj->IsPlayer())
        {
            player = obj->ToPlayer();
            TC_LOG_DEBUG("scripts.ai", "SmartScript::OnInitialize: source is Event {}, triggered by player {}", event, player->GetGUID().ToString());
        }
        else if (obj->IsCreature())
        {
            me = obj->ToCreature();
            TC_LOG_DEBUG("scripts.ai", "SmartScript::OnInitialize: source is Event {}, triggered by creature {}", event, me->GetEntry());
        }
        else if (obj->IsGameObject())
        {
            go = obj->ToGameObject();
            TC_LOG_DEBUG("scripts.ai", "SmartScript::OnInitialize: source is Event {}, triggered by gameobject {}", event, go->GetEntry());
        }
        else
        {
            TC_LOG_ERROR("misc", "SmartScript::OnInitialize: source is Event {}, missing trigger WorldObject", event);
            return;
        }
    }
    else if (obj) // Handle object based scripts
    {
        switch (obj->GetTypeId())
        {
            case TYPEID_UNIT:
                mScriptType = SMART_SCRIPT_TYPE_CREATURE;
                me = obj->ToCreature();
                TC_LOG_DEBUG("scripts.ai", "SmartScript::OnInitialize: source is Creature {}", me->GetEntry());
                break;
            case TYPEID_GAMEOBJECT:
                mScriptType = SMART_SCRIPT_TYPE_GAMEOBJECT;
                go = obj->ToGameObject();
                TC_LOG_DEBUG("scripts.ai", "SmartScript::OnInitialize: source is GameObject {}", go->GetEntry());
                break;
            case TYPEID_AREATRIGGER:
                areaTrigger = obj->ToAreaTrigger();
                mScriptType = areaTrigger->IsCustom() ? SMART_SCRIPT_TYPE_AREATRIGGER_ENTITY_CUSTOM : SMART_SCRIPT_TYPE_AREATRIGGER_ENTITY;
                TC_LOG_DEBUG("scripts.ai", "SmartScript::OnInitialize: source is AreaTrigger {}, IsCustom {}", areaTrigger->GetEntry(), uint32(areaTrigger->IsCustom()));
                break;
            default:
                TC_LOG_ERROR("misc", "SmartScript::OnInitialize: Unhandled TypeID !WARNING!");
                return;
        }
    }
    else
    {
        TC_LOG_ERROR("misc", "SmartScript::OnInitialize: !WARNING! Initialized objects are NULL.");
        return;
    }

    GetScript();//load copy of script

    for (SmartScriptHolder& event : mEvents)
        InitTimer(event);//calculate timers for first time use

    ProcessEventsFor(SMART_EVENT_AI_INIT);
    InstallEvents();
    ProcessEventsFor(SMART_EVENT_JUST_CREATED);
    mCounterList.clear();
}

void SmartScript::OnMoveInLineOfSight(Unit* who)
{
    if (!me)
        return;

    ProcessEventsFor(me->IsEngaged() ? SMART_EVENT_IC_LOS : SMART_EVENT_OOC_LOS, who);
}
// SmartScript end

Unit* SmartScript::DoSelectLowestHpFriendly(float range, uint32 MinHPDiff) const
{
    if (!me)
        return nullptr;

    Unit* unit = nullptr;

    Trinity::MostHPMissingInRange u_check(me, range, MinHPDiff);
    Trinity::UnitLastSearcher<Trinity::MostHPMissingInRange> searcher(me, unit, u_check);
    Cell::VisitGridObjects(me, searcher, range);
    return unit;
}

Unit* SmartScript::DoSelectLowestHpPercentFriendly(float range, uint32 minHpPct, uint32 maxHpPct) const
{
    if (!me)
        return nullptr;

    Unit* unit = nullptr;
    Trinity::MostHPPercentMissingInRange u_check(me, range, minHpPct, maxHpPct);
    Trinity::UnitLastSearcher<Trinity::MostHPPercentMissingInRange> searcher(me, unit, u_check);
    Cell::VisitGridObjects(me, searcher, range);
    return unit;
}

void SmartScript::DoFindFriendlyCC(std::vector<Creature*>& creatures, float range) const
{
    if (!me)
        return;

    Trinity::FriendlyCCedInRange u_check(me, range);
    Trinity::CreatureListSearcher<Trinity::FriendlyCCedInRange> searcher(me, creatures, u_check);
    Cell::VisitGridObjects(me, searcher, range);
}

void SmartScript::DoFindFriendlyMissingBuff(std::vector<Creature*>& creatures, float range, uint32 spellid) const
{
    if (!me)
        return;

    Trinity::FriendlyMissingBuffInRange u_check(me, range, spellid);
    Trinity::CreatureListSearcher<Trinity::FriendlyMissingBuffInRange> searcher(me, creatures, u_check);
    Cell::VisitGridObjects(me, searcher, range);
}

Unit* SmartScript::DoFindClosestFriendlyInRange(float range, bool playerOnly) const
{
    if (!me)
        return nullptr;

    Unit* unit = nullptr;
    Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(me, me, range, playerOnly);
    Trinity::UnitLastSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(me, unit, u_check);
    Cell::VisitAllObjects(me, searcher, range);
    return unit;
}

void SmartScript::SetTimedActionList(SmartScriptHolder& e, uint32 entry, Unit* invoker, uint32 startFromEventId)
{
    //do NOT clear mTimedActionList if it's being iterated because it will invalidate the iterator and delete
    // any SmartScriptHolder contained like the "e" parameter passed to this function
    if (isProcessingTimedActionList)
    {
        TC_LOG_ERROR("scripts.ai", "Entry {} SourceType {} Event {} Action {} is trying to overwrite timed action list from a timed action, this is not allowed!.", e.entryOrGuid, e.GetScriptType(), e.GetEventType(), e.GetActionType());
        return;
    }

    // Do NOT allow to start a new actionlist if a previous one is already running, unless explicitly allowed. We need to always finish the current actionlist
    if (e.GetActionType() == SMART_ACTION_CALL_TIMED_ACTIONLIST && !e.action.timedActionList.allowOverride && !mTimedActionList.empty())
        return;

    mTimedActionList.clear();
    mTimedActionList = sSmartScriptMgr->GetScript(entry, SMART_SCRIPT_TYPE_TIMED_ACTIONLIST);
    if (mTimedActionList.empty())
        return;

    Trinity::Containers::EraseIf(mTimedActionList, [startFromEventId](SmartScriptHolder const& script) { return script.event_id < startFromEventId; });

    mTimedActionListInvoker = invoker ? invoker->GetGUID() : ObjectGuid::Empty;
    for (SmartAIEventList::iterator i = mTimedActionList.begin(); i != mTimedActionList.end(); ++i)
    {
        i->enableTimed = i == mTimedActionList.begin();//enable processing only for the first action

        if (e.action.timedActionList.timerType == 0)
            i->event.type = SMART_EVENT_UPDATE_OOC;
        else if (e.action.timedActionList.timerType == 1)
            i->event.type = SMART_EVENT_UPDATE_IC;
        else if (e.action.timedActionList.timerType > 1)
            i->event.type = SMART_EVENT_UPDATE;

        InitTimer((*i));
    }
}

Unit* SmartScript::GetLastInvoker(Unit* invoker) const
{
    // Look for invoker only on map of base object... Prevents multithreaded crashes
    if (WorldObject* baseObject = GetBaseObject())
        return ObjectAccessor::GetUnit(*baseObject, mLastInvoker);
    // used for area triggers invoker cast
    else if (invoker)
        return ObjectAccessor::GetUnit(*invoker, mLastInvoker);

    return nullptr;
}

void SmartScript::IncPhase(uint32 p)
{
    // protect phase from overflowing
    SetPhase(std::min<uint32>(SMART_EVENT_PHASE_12, mEventPhase + p));
}

void SmartScript::DecPhase(uint32 p)
{
    if (p >= mEventPhase)
        SetPhase(0);
    else
        SetPhase(mEventPhase - p);
}

void SmartScript::SetPhase(uint32 p)
{
    mEventPhase = p;
}

bool SmartScript::IsInPhase(uint32 p) const
{
    if (mEventPhase == 0)
        return false;
    return ((1 << (mEventPhase - 1)) & p) != 0;
}
