/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "DatabaseEnv.h"
#include "ObjectMgr.h"
#include "ObjectDefines.h"
#include "GridDefines.h"
#include "GridNotifiers.h"
#include "SpellMgr.h"
#include "GridNotifiersImpl.h"
#include "Cell.h"
#include "CellImpl.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "GossipDef.h"
#include "ScriptedCreature.h"
#include "SmartScript.h"
#include "SmartAI.h"
#include "Group.h"
#include "Vehicle.h"
#include "ScriptedGossip.h"
#include "CreatureTextMgr.h"

class TrinityStringTextBuilder
{
    public:
        TrinityStringTextBuilder(WorldObject* obj, ChatMsg msgtype, int32 id, uint32 language, uint64 targetGUID)
            : _source(obj), _msgType(msgtype), _textId(id), _language(language), _targetGUID(targetGUID)
        {
        }

        size_t operator()(WorldPacket* data, LocaleConstant locale) const
        {
            std::string text = sObjectMgr->GetTrinityString(_textId, locale);
            char const* localizedName = _source->GetNameForLocaleIdx(locale);

            *data << uint8(_msgType);
            *data << uint32(_language);
            *data << uint64(_source->GetGUID());
            *data << uint32(1);                                      // 2.1.0
            *data << uint32(strlen(localizedName)+1);
            *data << localizedName;
            size_t whisperGUIDpos = data->wpos();
            *data << uint64(_targetGUID);                           // Unit Target
            if (_targetGUID && !IS_PLAYER_GUID(_targetGUID))
            {
                *data << uint32(1);                                  // target name length
                *data << uint8(0);                                   // target name
            }
            *data << uint32(text.length() + 1);
            *data << text;
            *data << uint8(0);                                       // ChatTag

            return whisperGUIDpos;
        }

        WorldObject* _source;
        ChatMsg _msgType;
        int32 _textId;
        uint32 _language;
        uint64 _targetGUID;
};

SmartScript::SmartScript()
{
    go = NULL;
    me = NULL;
    mEventPhase = 0;
    mPathId = 0;
    mTargetStorage = new ObjectListMap();
    mStoredEvents.clear();
    mTextTimer = 0;
    mLastTextID = 0;
    mTextGUID = 0;
    mUseTextTimer = false;
    mTalkerEntry = 0;
    mTemplate = SMARTAI_TEMPLATE_BASIC;
    meOrigGUID = 0;
    goOrigGUID = 0;
    mLastInvoker = 0;
}

SmartScript::~SmartScript()
{
    for (ObjectListMap::iterator itr = mTargetStorage->begin(); itr != mTargetStorage->end(); ++itr)
        delete itr->second;

    delete mTargetStorage;
}

void SmartScript::OnReset()
{
    SetPhase(0);
    ResetBaseObject();
    for (SmartAIEventList::iterator i = mEvents.begin(); i != mEvents.end(); ++i)
    {
        InitTimer((*i));
        (*i).runOnce = false;
    }
    ProcessEventsFor(SMART_EVENT_RESET);
    mLastInvoker = 0;
}

void SmartScript::ProcessEventsFor(SMART_EVENT e, Unit* unit, uint32 var0, uint32 var1, bool bvar, const SpellInfo* spell, GameObject* gob)
{
    for (SmartAIEventList::iterator i = mEvents.begin(); i != mEvents.end(); ++i)
    {
        SMART_EVENT eventType = SMART_EVENT((*i).GetEventType());
        if (eventType == SMART_EVENT_LINK)//special handling
            continue;

        if (eventType == e/* && (!(*i).event.event_phase_mask || IsInPhase((*i).event.event_phase_mask)) && !((*i).event.event_flags & SMART_EVENT_FLAG_NOT_REPEATABLE && (*i).runOnce)*/)
        {
            bool meets = true;
            ConditionList conds = sConditionMgr->GetConditionsForSmartEvent((*i).entryOrGuid, (*i).event_id, (*i).source_type);
            ConditionSourceInfo info = ConditionSourceInfo(unit, GetBaseObject());
            meets = sConditionMgr->IsObjectMeetToConditions(info, conds);

            if (meets)
                ProcessEvent(*i, unit, var0, var1, bvar, spell, gob);
        }
    }
}

void SmartScript::ProcessAction(SmartScriptHolder& e, Unit* unit, uint32 var0, uint32 var1, bool bvar, const SpellInfo* spell, GameObject* gob)
{
    //calc random
    if (e.GetEventType() != SMART_EVENT_LINK && e.event.event_chance < 100 && e.event.event_chance)
    {
        uint32 rnd = urand(0, 100);
        if (e.event.event_chance <= rnd)
            return;
    }
    e.runOnce = true;//used for repeat check

    if (unit)
        mLastInvoker = unit->GetGUID();

    if (Unit* tempInvoker = GetLastInvoker())
        sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: Invoker: %s (guidlow: %u)", tempInvoker->GetName(), tempInvoker->GetGUIDLow());

    switch (e.GetActionType())
    {
        case SMART_ACTION_TALK:
        {
            if (!me)
                break;

            ObjectList* targets = GetTargets(e, unit);
            Creature* talker = me;
            Player* targetPlayer = NULL;
            if (targets)
            {
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                {
                    if (IsCreature((*itr)))
                    {
                        talker = (*itr)->ToCreature();
                        break;
                    }
                    else if (IsPlayer((*itr)))
                    {
                        targetPlayer = (*itr)->ToPlayer();
                        break;
                    }
                }

                delete targets;
            }

            mTalkerEntry = talker->GetEntry();
            mLastTextID = e.action.talk.textGroupID;
            mTextTimer = e.action.talk.duration;
            if (IsPlayer(GetLastInvoker())) // used for $vars in texts and whisper target
                mTextGUID = GetLastInvoker()->GetGUID();
            else if (targetPlayer)
                mTextGUID = targetPlayer->GetGUID();
            else
                mTextGUID = 0;

            mUseTextTimer = true;
            sCreatureTextMgr->SendChat(talker, uint8(e.action.talk.textGroupID), mTextGUID);
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_TALK: talker: %s (GuidLow: %u), textGuid: %u",
                talker->GetName(), talker->GetGUIDLow(), GUID_LOPART(mTextGUID));
            break;
        }
        case SMART_ACTION_SIMPLE_TALK:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (targets)
            {
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                {
                    if (IsCreature(*itr))
                        sCreatureTextMgr->SendChat((*itr)->ToCreature(), uint8(e.action.talk.textGroupID), IsPlayer(GetLastInvoker())? GetLastInvoker()->GetGUID() : 0);
                    else if (IsPlayer(*itr) && me)
                    {
                        Unit* templastInvoker = GetLastInvoker();
                        sCreatureTextMgr->SendChat(me, uint8(e.action.talk.textGroupID), IsPlayer(templastInvoker) ? templastInvoker->GetGUID() : 0, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, (*itr)->ToPlayer());
                    }
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_SIMPLE_TALK: talker: %s (GuidLow: %u), textGroupId: %u",
                        (*itr)->GetName(), (*itr)->GetGUIDLow(), uint8(e.action.talk.textGroupID));
                }

                delete targets;
            }
            break;
        }
        case SMART_ACTION_PLAY_EMOTE:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (targets)
            {
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                {
                    if (IsUnit(*itr))
                    {
                        (*itr)->ToUnit()->HandleEmoteCommand(e.action.emote.emote);
                        sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_PLAY_EMOTE: target: %s (GuidLow: %u), emote: %u",
                            (*itr)->GetName(), (*itr)->GetGUIDLow(), e.action.emote.emote);
                    }
                }

                delete targets;
            }
            break;
        }
        case SMART_ACTION_SOUND:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (targets)
            {
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                {
                    if (IsUnit(*itr))
                    {
                        (*itr)->SendPlaySound(e.action.sound.sound, e.action.sound.range > 0 ? true : false);
                        sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_SOUND: target: %s (GuidLow: %u), sound: %u, onlyself: %u",
                            (*itr)->GetName(), (*itr)->GetGUIDLow(), e.action.sound.sound, e.action.sound.range);
                    }
                }

                delete targets;
            }
            break;
        }
        case SMART_ACTION_SET_FACTION:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (targets)
            {
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                {
                    if (IsCreature(*itr))
                    {
                        if (e.action.faction.factionID)
                        {
                            (*itr)->ToCreature()->setFaction(e.action.faction.factionID);
                            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_SET_FACTION: Creature entry %u, GuidLow %u set faction to %u",
                                (*itr)->GetEntry(), (*itr)->GetGUIDLow(), e.action.faction.factionID);
                        }
                        else
                        {
                            if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate((*itr)->ToCreature()->GetEntry()))
                            {
                                if ((*itr)->ToCreature()->getFaction() != ci->faction_A)
                                {
                                    (*itr)->ToCreature()->setFaction(ci->faction_A);
                                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_SET_FACTION: Creature entry %u, GuidLow %u set faction to %u",
                                        (*itr)->GetEntry(), (*itr)->GetGUIDLow(), ci->faction_A);
                                }
                            }
                        }
                    }
                }

                delete targets;
            }
            break;
        }
        case SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (!IsCreature(*itr))
                    continue;

                if (e.action.morphOrMount.creature || e.action.morphOrMount.model)
                {
                    //set model based on entry from creature_template
                    if (e.action.morphOrMount.creature)
                    {
                        if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(e.action.morphOrMount.creature))
                        {
                            uint32 display_id = sObjectMgr->ChooseDisplayId(0, ci);
                            (*itr)->ToCreature()->SetDisplayId(display_id);
                            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL: Creature entry %u, GuidLow %u set displayid to %u",
                                (*itr)->GetEntry(), (*itr)->GetGUIDLow(), display_id);
                        }
                    }
                    //if no param1, then use value from param2 (modelId)
                    else
                    {
                        (*itr)->ToCreature()->SetDisplayId(e.action.morphOrMount.model);
                        sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL: Creature entry %u, GuidLow %u set displayid to %u",
                            (*itr)->GetEntry(), (*itr)->GetGUIDLow(), e.action.morphOrMount.model);
                    }
                }
                else
                {
                    (*itr)->ToCreature()->DeMorph();
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL: Creature entry %u, GuidLow %u demorphs.",
                        (*itr)->GetEntry(), (*itr)->GetGUIDLow());
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_FAIL_QUEST:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsPlayer(*itr))
                {
                    (*itr)->ToPlayer()->FailQuest(e.action.quest.quest);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_FAIL_QUEST: Player guidLow %u fails quest %u",
                        (*itr)->GetGUIDLow(), e.action.quest.quest);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_ADD_QUEST:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsPlayer(*itr))
                {
                    if (Quest const* q = sObjectMgr->GetQuestTemplate(e.action.quest.quest))
                    {
                        (*itr)->ToPlayer()->AddQuest(q, NULL);
                        sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_ADD_QUEST: Player guidLow %u add quest %u",
                            (*itr)->GetGUIDLow(), e.action.quest.quest);
                    }
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_SET_REACT_STATE:
        {
            if (!me)
                break;

            me->SetReactState(ReactStates(e.action.react.state));
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_SET_REACT_STATE: Creature guidLow %u set reactstate %u",
                me->GetGUIDLow(), e.action.react.state);
            break;
        }
        case SMART_ACTION_RANDOM_EMOTE:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            uint32 emotes[SMART_ACTION_PARAM_COUNT];
            emotes[0] = e.action.randomEmote.emote1;
            emotes[1] = e.action.randomEmote.emote2;
            emotes[2] = e.action.randomEmote.emote3;
            emotes[3] = e.action.randomEmote.emote4;
            emotes[4] = e.action.randomEmote.emote5;
            emotes[5] = e.action.randomEmote.emote6;
            uint32 temp[SMART_ACTION_PARAM_COUNT];
            uint32 count = 0;
            for (uint8 i = 0; i < SMART_ACTION_PARAM_COUNT; i++)
            {
                if (emotes[i])
                {
                    temp[count] = emotes[i];
                    ++count;
                }
            }

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsUnit(*itr))
                {
                    uint32 emote = temp[urand(0, count)];
                    (*itr)->ToUnit()->HandleEmoteCommand(emote);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_RANDOM_EMOTE: Creature guidLow %u handle random emote %u",
                        (*itr)->GetGUIDLow(), emote);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_THREAT_ALL_PCT:
        {
            if (!me)
                break;

            std::list<HostileReference*> const& threatList = me->getThreatManager().getThreatList();
            for (std::list<HostileReference*>::const_iterator i = threatList.begin(); i != threatList.end(); ++i)
            {
                if (Unit* target = Unit::GetUnit(*me, (*i)->getUnitGuid()))
                {
                    me->getThreatManager().modifyThreatPercent(target, e.action.threatPCT.threatINC ? (int32)e.action.threatPCT.threatINC : -(int32)e.action.threatPCT.threatDEC);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_THREAT_ALL_PCT: Creature guidLow %u modify threat for unit %u, value %i",
                        me->GetGUIDLow(), target->GetGUIDLow(), e.action.threatPCT.threatINC ? (int32)e.action.threatPCT.threatINC : -(int32)e.action.threatPCT.threatDEC);
                }
            }
            break;
        }
        case SMART_ACTION_THREAT_SINGLE_PCT:
        {
            if (!me)
                break;

            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsUnit(*itr))
                {
                    me->getThreatManager().modifyThreatPercent((*itr)->ToUnit(), e.action.threatPCT.threatINC ? (int32)e.action.threatPCT.threatINC : -(int32)e.action.threatPCT.threatDEC);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_THREAT_SINGLE_PCT: Creature guidLow %u modify threat for unit %u, value %i",
                        me->GetGUIDLow(), (*itr)->GetGUIDLow(), e.action.threatPCT.threatINC ? (int32)e.action.threatPCT.threatINC : -(int32)e.action.threatPCT.threatDEC);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_CALL_AREAEXPLOREDOREVENTHAPPENS:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsPlayer(*itr))
                {
                    (*itr)->ToPlayer()->AreaExploredOrEventHappens(e.action.quest.quest);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_CALL_AREAEXPLOREDOREVENTHAPPENS: Player guidLow %u credited quest %u",
                        (*itr)->GetGUIDLow(), e.action.quest.quest);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_SEND_CASTCREATUREORGO:
        {
            if (!GetBaseObject())
                break;

            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsPlayer(*itr))
                {
                    (*itr)->ToPlayer()->CastedCreatureOrGO(e.action.castedCreatureOrGO.creature, GetBaseObject()->GetGUID(), e.action.castedCreatureOrGO.spell);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_SEND_CASTCREATUREORGO: Player guidLow %u.org Creature: %u, BaseObject GUID: "UI64FMTD", Spell: %u",
                        (*itr)->GetGUIDLow(), e.action.castedCreatureOrGO.creature, GetBaseObject()->GetGUID(), e.action.castedCreatureOrGO.spell);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_CAST:
        {
            if (!me)
                break;

            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsUnit(*itr))
                {
                    if (e.action.cast.flags & SMARTCAST_INTERRUPT_PREVIOUS)
                        me->InterruptNonMeleeSpells(false);

                    if (!(e.action.cast.flags & SMARTCAST_AURA_NOT_PRESENT) || !(*itr)->ToUnit()->HasAura(e.action.cast.spell))
                        me->CastSpell((*itr)->ToUnit(), e.action.cast.spell, (e.action.cast.flags & SMARTCAST_TRIGGERED) ? true : false);
                    else
                        sLog->outDebug(LOG_FILTER_DATABASE_AI, "Spell %u not casted because it has flag SMARTCAST_AURA_NOT_PRESENT and the target (Guid: " UI64FMTD " Entry: %u Type: %u) already has the aura", e.action.cast.spell, (*itr)->GetGUID(), (*itr)->GetEntry(), uint32((*itr)->GetTypeId()));
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_CAST:: Creature %u casts spell %u on target %u with castflags %u",
                        me->GetGUIDLow(), e.action.cast.spell, (*itr)->GetGUIDLow(), e.action.cast.flags);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_INVOKER_CAST:
        {
            Unit* tempLastInvoker = GetLastInvoker();
            if (!tempLastInvoker)
                break;

            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsUnit(*itr))
                {
                    if (e.action.cast.flags & SMARTCAST_INTERRUPT_PREVIOUS)
                        tempLastInvoker->InterruptNonMeleeSpells(false);

                    if (!(e.action.cast.flags & SMARTCAST_AURA_NOT_PRESENT) || !(*itr)->ToUnit()->HasAura(e.action.cast.spell))
                        tempLastInvoker->CastSpell((*itr)->ToUnit(), e.action.cast.spell, (e.action.cast.flags & SMARTCAST_TRIGGERED) ? true : false);
                    else
                        sLog->outDebug(LOG_FILTER_DATABASE_AI, "Spell %u not casted because it has flag SMARTCAST_AURA_NOT_PRESENT and the target (Guid: " UI64FMTD " Entry: %u Type: %u) already has the aura", e.action.cast.spell, (*itr)->GetGUID(), (*itr)->GetEntry(), uint32((*itr)->GetTypeId()));

                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_INVOKER_CAST: Invoker %u casts spell %u on target %u with castflags %u",
                        tempLastInvoker->GetGUIDLow(), e.action.cast.spell, (*itr)->GetGUIDLow(), e.action.cast.flags);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_ADD_AURA:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsUnit(*itr))
                {
                    (*itr)->ToUnit()->AddAura(e.action.cast.spell, (*itr)->ToUnit());
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_ADD_AURA: Adding aura %u to unit %u",
                        e.action.cast.spell, (*itr)->GetGUIDLow());
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_ACTIVATE_GOBJECT:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsGameObject(*itr))
                {
                    // Activate
                    (*itr)->ToGameObject()->SetLootState(GO_READY);
                    (*itr)->ToGameObject()->UseDoorOrButton(0, false, unit);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_ACTIVATE_GOBJECT. Gameobject %u (entry: %u) activated",
                        (*itr)->GetGUIDLow(), (*itr)->GetEntry());
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_RESET_GOBJECT:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsGameObject(*itr))
                {
                    (*itr)->ToGameObject()->ResetDoorOrButton();
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_RESET_GOBJECT. Gameobject %u (entry: %u) reset",
                        (*itr)->GetGUIDLow(), (*itr)->GetEntry());
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_SET_EMOTE_STATE:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsUnit(*itr))
                {
                    (*itr)->ToUnit()->SetUInt32Value(UNIT_NPC_EMOTESTATE, e.action.emote.emote);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_SET_EMOTE_STATE. Unit %u set emotestate to %u",
                        (*itr)->GetGUIDLow(), e.action.emote.emote);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_SET_UNIT_FLAG:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsUnit(*itr))
                {
                    (*itr)->ToUnit()->SetFlag(UNIT_FIELD_FLAGS, e.action.unitFlag.flag);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_SET_UNIT_FLAG. Unit %u added flag %u to UNIT_FIELD_FLAGS",
                        (*itr)->GetGUIDLow(), e.action.unitFlag.flag);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_REMOVE_UNIT_FLAG:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsUnit(*itr))
                {
                    (*itr)->ToUnit()->RemoveFlag(UNIT_FIELD_FLAGS, e.action.unitFlag.flag);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_REMOVE_UNIT_FLAG. Unit %u removed flag %u to UNIT_FIELD_FLAGS",
                        (*itr)->GetGUIDLow(), e.action.unitFlag.flag);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_AUTO_ATTACK:
        {
            if (!IsSmart())
                break;

            CAST_AI(SmartAI, me->AI())->SetAutoAttack(e.action.autoAttack.attack ? true : false);
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_AUTO_ATTACK: Creature: %u bool on = %u",
                me->GetGUIDLow(), e.action.autoAttack.attack);
            break;
        }
        case SMART_ACTION_ALLOW_COMBAT_MOVEMENT:
        {
            if (!IsSmart())
                break;

            bool move = e.action.combatMove.move ? true : false;
            CAST_AI(SmartAI, me->AI())->SetCombatMove(move);
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_ALLOW_COMBAT_MOVEMENT: Creature %u bool on = %u",
                me->GetGUIDLow(), e.action.combatMove.move);
            break;
        }
        case SMART_ACTION_SET_EVENT_PHASE:
        {
            if (!GetBaseObject())
                break;

            SetPhase(e.action.setEventPhase.phase);
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_SET_EVENT_PHASE: Creature %u set event phase %u",
                GetBaseObject()->GetGUIDLow(), e.action.setEventPhase.phase);
            break;
        }
        case SMART_ACTION_INC_EVENT_PHASE:
        {
            if (!GetBaseObject())
                break;

            IncPhase(e.action.incEventPhase.inc);
            DecPhase(e.action.incEventPhase.dec);
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_INC_EVENT_PHASE: Creature %u inc event phase by %u, "
                "decrease by %u", GetBaseObject()->GetGUIDLow(), e.action.incEventPhase.inc, e.action.incEventPhase.dec);
            break;
        }
        case SMART_ACTION_EVADE:
        {
            if (!me)
                break;

            me->AI()->EnterEvadeMode();
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_EVADE: Creature %u EnterEvadeMode", me->GetGUIDLow());
            return;
        }
        case SMART_ACTION_FLEE_FOR_ASSIST:
        {
            if (!me)
                break;

            me->DoFleeToGetAssistance();
            if (e.action.flee.withEmote)
            {
                TrinityStringTextBuilder builder(me, CHAT_MSG_MONSTER_EMOTE, LANG_FLEE, LANG_UNIVERSAL, 0);
                sCreatureTextMgr->SendChatPacket(me, builder, CHAT_MSG_MONSTER_EMOTE);
            }
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_FLEE_FOR_ASSIST: Creature %u DoFleeToGetAssistance", me->GetGUIDLow());
            break;
        }
        case SMART_ACTION_CALL_GROUPEVENTHAPPENS:
        {
            if (IsPlayer(unit) && GetBaseObject())
            {
                unit->ToPlayer()->GroupEventHappens(e.action.quest.quest, GetBaseObject());
                sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_CALL_GROUPEVENTHAPPENS: Player %u, group credit for quest %u",
                    unit->GetGUIDLow(), e.action.quest.quest);
            }
            break;
        }
        case SMART_ACTION_CALL_CASTEDCREATUREORGO:
        {
            if (!GetBaseObject())
                break;

            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsPlayer((*itr)))
                {
                    (*itr)->ToPlayer()->CastedCreatureOrGO(e.action.castedCreatureOrGO.creature, GetBaseObject()->GetGUID(), e.action.castedCreatureOrGO.spell);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_CALL_CASTEDCREATUREORGO: Player %u, target %u, spell %u",
                        (*itr)->GetGUIDLow(), e.action.castedCreatureOrGO.creature, e.action.castedCreatureOrGO.spell);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_REMOVEAURASFROMSPELL:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (!IsUnit((*itr)))
                    continue;

                (*itr)->ToUnit()->RemoveAurasDueToSpell(e.action.removeAura.spell);
                sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_REMOVEAURASFROMSPELL: Unit %u, spell %u",
                    (*itr)->GetGUIDLow(), e.action.removeAura.spell);
            }

            delete targets;
            break;
        }
        case SMART_ACTION_FOLLOW:
        {
            if (!IsSmart())
                break;

            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsUnit((*itr)))
                {
                    CAST_AI(SmartAI, me->AI())->SetFollow((*itr)->ToUnit(), (float)e.action.follow.dist, (float)e.action.follow.angle, e.action.follow.credit, e.action.follow.entry, e.action.follow.creditType);
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_FOLLOW: Creature %u following target %u",
                        me->GetGUIDLow(), (*itr)->GetGUIDLow());
                    break;
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_RANDOM_PHASE:
        {
            if (!GetBaseObject())
                break;

            uint32 phases[SMART_ACTION_PARAM_COUNT];
            phases[0] = e.action.randomPhase.phase1;
            phases[1] = e.action.randomPhase.phase2;
            phases[2] = e.action.randomPhase.phase3;
            phases[3] = e.action.randomPhase.phase4;
            phases[4] = e.action.randomPhase.phase5;
            phases[5] = e.action.randomPhase.phase6;
            uint32 temp[SMART_ACTION_PARAM_COUNT];
            uint32 count = 0;
            for (uint8 i = 0; i < SMART_ACTION_PARAM_COUNT; i++)
            {
                if (phases[i] > 0)
                {
                    temp[count] = phases[i];
                    ++count;
                }
            }

            uint32 phase = temp[urand(0, count)];
            SetPhase(phase);
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_RANDOM_PHASE: Creature %u sets event phase to %u",
                GetBaseObject()->GetGUIDLow(), phase);
            break;
        }
        case SMART_ACTION_RANDOM_PHASE_RANGE:
        {
            if (!GetBaseObject())
                break;

            uint32 phase = urand(e.action.randomPhaseRange.phaseMin, e.action.randomPhaseRange.phaseMax);
            SetPhase(phase);
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_RANDOM_PHASE_RANGE: Creature %u sets event phase to %u",
                GetBaseObject()->GetGUIDLow(), phase);
            break;
        }
        case SMART_ACTION_CALL_KILLEDMONSTER:
        {
            Player* player = NULL;
            if (me)
                player = me->GetLootRecipient();

            if (me && player)
                player->RewardPlayerAndGroupAtEvent(e.action.killedMonster.creature, player);
            else if (GetBaseObject())
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets)
                    break;

                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                {
                    if (!IsPlayer(*itr))
                        continue;

                    (*itr)->ToPlayer()->RewardPlayerAndGroupAtEvent(e.action.killedMonster.creature, (*itr)->ToPlayer());
                    sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_CALL_KILLEDMONSTER: Player %u, Killcredit: %u",
                        (*itr)->GetGUIDLow(), e.action.killedMonster.creature);
                }

                delete targets;
            }
            else if (trigger && IsPlayer(unit))
            {
                unit->ToPlayer()->RewardPlayerAndGroupAtEvent(e.action.killedMonster.creature, unit);
                sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_CALL_KILLEDMONSTER: (trigger == true) Player %u, Killcredit: %u",
                    unit->GetGUIDLow(), e.action.killedMonster.creature);
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
                sLog->outErrorDb("SmartScript: Event %u attempt to set instance data without instance script. EntryOrGuid %d", e.GetEventType(), e.entryOrGuid);
                break;
            }

            instance->SetData(e.action.setInstanceData.field, e.action.setInstanceData.data);
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_SET_INST_DATA: Field: %u, data: %u",
                e.action.setInstanceData.field, e.action.setInstanceData.data);
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
                sLog->outErrorDb("SmartScript: Event %u attempt to set instance data without instance script. EntryOrGuid %d", e.GetEventType(), e.entryOrGuid);
                break;
            }

            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            instance->SetData64(e.action.setInstanceData64.field, targets->front()->GetGUID());
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_SET_INST_DATA64: Field: %u, data: "UI64FMTD,
                e.action.setInstanceData64.field, targets->front()->GetGUID());

            delete targets;
            break;
        }
        case SMART_ACTION_UPDATE_TEMPLATE:
        {
            if (!me || me->GetEntry() == e.action.updateTemplate.creature)
                break;

            me->UpdateEntry(e.action.updateTemplate.creature, e.action.updateTemplate.team ? HORDE : ALLIANCE);
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_UPDATE_TEMPLATE: Creature %u, Template: %u, Team: %u",
                me->GetGUIDLow(), me->GetEntry(), e.action.updateTemplate.team ? HORDE : ALLIANCE);
            break;
        }
        case SMART_ACTION_DIE:
        {
            if (me && !me->isDead())
            {
                me->Kill(me);
                sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_DIE: Creature %u", me->GetGUIDLow());
            }
            break;
        }
        case SMART_ACTION_SET_IN_COMBAT_WITH_ZONE:
        {
            if (me)
            {
                me->SetInCombatWithZone();
                sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_SET_IN_COMBAT_WITH_ZONE: Creature %u", me->GetGUIDLow());
            }
            break;
        }
        case SMART_ACTION_CALL_FOR_HELP:
        {
            if (me)
            {
                me->CallForHelp((float)e.action.callHelp.range);
                sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_CALL_FOR_HELP: Creature %u", me->GetGUIDLow());
            }
            break;
        }
        case SMART_ACTION_SET_SHEATH:
        {
            if (me)
            {
                me->SetSheath(SheathState(e.action.setSheath.sheath));
                sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction: SMART_ACTION_SET_SHEATH: Creature %u, State: %u",
                    me->GetGUIDLow(), e.action.setSheath.sheath);
            }
            break;
        }
        case SMART_ACTION_FORCE_DESPAWN:
        {
            if (!IsSmart())
                break;

            CAST_AI(SmartAI, me->AI())->SetDespawnTime(e.action.forceDespawn.delay + 1);//next tick
            CAST_AI(SmartAI, me->AI())->StartDespawn();
            break;
        }
        case SMART_ACTION_SET_INGAME_PHASE_MASK:
        {
            if (GetBaseObject())
                GetBaseObject()->SetPhaseMask(e.action.ingamePhaseMask.mask, true);
            break;
        }
        case SMART_ACTION_MOUNT_TO_ENTRY_OR_MODEL:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (!IsUnit(*itr))
                    continue;

                if (e.action.morphOrMount.creature || e.action.morphOrMount.model)
                {
                    if (e.action.morphOrMount.creature > 0)
                    {
                        if (CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(e.action.morphOrMount.creature))
                        {
                            uint32 display_id = sObjectMgr->ChooseDisplayId(0, cInfo);
                            (*itr)->ToUnit()->Mount(display_id);
                        }
                    }
                    else
                        (*itr)->ToUnit()->Mount(e.action.morphOrMount.model);
                }
                else
                    (*itr)->ToUnit()->Dismount();
            }

            delete targets;
            break;
        }
        case SMART_ACTION_SET_INVINCIBILITY_HP_LEVEL:
        {
            if (!me)
                break;

            SmartAI* ai = CAST_AI(SmartAI, me->AI());

            if (!ai)
                break;

            if (e.action.invincHP.percent)
                ai->SetInvincibilityHpLevel(me->CountPctFromMaxHealth(e.action.invincHP.percent));
            else
                ai->SetInvincibilityHpLevel(e.action.invincHP.minHP);
            break;
        }
        case SMART_ACTION_SET_DATA:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsCreature(*itr))
                    (*itr)->ToCreature()->AI()->SetData(e.action.setData.field, e.action.setData.data);
                else if (IsGameObject(*itr))
                    (*itr)->ToGameObject()->AI()->SetData(e.action.setData.field, e.action.setData.data);
            }

            delete targets;
            break;
        }
        case SMART_ACTION_MOVE_FORWARD:
        {
            if (!me)
                break;

            float x, y, z;
            me->GetClosePoint(x, y, z, me->GetObjectSize() / 3, (float)e.action.moveRandom.distance);
            me->GetMotionMaster()->MovePoint(SMART_RANDOM_POINT, x, y, z);
            break;
        }
        case SMART_ACTION_SET_VISIBILITY:
        {
            if (me)
                me->SetVisible(e.action.visibility.state ? true : false);
            break;
        }
        case SMART_ACTION_SET_ACTIVE:
        {
            if (GetBaseObject())
                GetBaseObject()->setActive(true);
            break;
        }
        case SMART_ACTION_ATTACK_START:
        {
            if (!me)
                break;

            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsUnit(*itr))
                {
                    me->AI()->AttackStart((*itr)->ToUnit());
                    break;
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_SUMMON_CREATURE:
        {
            float x, y, z, o;
            ObjectList* targets = GetTargets(e, unit);
            if (targets)
            {
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                {
                    if (!IsUnit(*itr))
                        continue;

                    (*itr)->GetPosition(x, y, z, o);
                    if (Creature* summon = GetBaseObject()->SummonCreature(e.action.summonCreature.creature, x, y, z, o, (TempSummonType)e.action.summonCreature.type, e.action.summonCreature.duration))
                        if (unit && e.action.summonCreature.attackInvoker)
                            summon->AI()->AttackStart((*itr)->ToUnit());
                }

                delete targets;
            }

            if (e.GetTargetType() != SMART_TARGET_POSITION)
                break;

            if (Creature* summon = GetBaseObject()->SummonCreature(e.action.summonCreature.creature, e.target.x, e.target.y, e.target.z, e.target.o, (TempSummonType)e.action.summonCreature.type, e.action.summonCreature.duration))
                if (unit && e.action.summonCreature.attackInvoker)
                    summon->AI()->AttackStart(unit);
            break;
        }
        case SMART_ACTION_SUMMON_GO:
        {
            if (!GetBaseObject())
                break;

            float x, y, z, o;
            ObjectList* targets = GetTargets(e, unit);
            if (targets)
            {
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                {
                    if (!IsUnit(*itr))
                        continue;

                    (*itr)->GetPosition(x, y, z, o);
                    GetBaseObject()->SummonGameObject(e.action.summonGO.entry, x, y, z, o, 0, 0, 0, 0, e.action.summonGO.despawnTime);
                }

                delete targets;
            }

            if (e.GetTargetType() != SMART_TARGET_POSITION)
                break;

            GetBaseObject()->SummonGameObject(e.action.summonGO.entry, e.target.x, e.target.y, e.target.z, e.target.o, 0, 0, 0, 0, e.action.summonGO.despawnTime);
            break;
        }
        case SMART_ACTION_KILL_UNIT:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (!IsUnit(*itr))
                    continue;

                (*itr)->ToUnit()->Kill((*itr)->ToUnit());
            }

            delete targets;
            break;
        }
        case SMART_ACTION_INSTALL_AI_TEMPLATE:
        {
            InstallTemplate(e);
            break;
        }
        case SMART_ACTION_ADD_ITEM:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (!IsPlayer(*itr))
                    continue;

                (*itr)->ToPlayer()->AddItem(e.action.item.entry, e.action.item.count);
            }

            delete targets;
            break;
        }
        case SMART_ACTION_REMOVE_ITEM:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (!IsPlayer(*itr))
                    continue;

                (*itr)->ToPlayer()->DestroyItemCount(e.action.item.entry, e.action.item.count, true);
            }

            delete targets;
            break;
        }
        case SMART_ACTION_STORE_VARIABLE_DECIMAL:
        {
            if (mStoredDecimals.find(e.action.storeVar.id) != mStoredDecimals.end())
                mStoredDecimals.erase(e.action.storeVar.id);
            mStoredDecimals[e.action.storeVar.id] = e.action.storeVar.number;
            break;
        }
        case SMART_ACTION_STORE_TARGET_LIST:
        {
            ObjectList* targets = GetTargets(e, unit);
            StoreTargetList(targets, e.action.storeTargets.id);
            break;
        }
        case SMART_ACTION_TELEPORT:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (!IsPlayer(*itr))
                    continue;

                (*itr)->ToPlayer()->TeleportTo(e.action.teleport.mapID, e.target.x, e.target.y, e.target.z, e.target.o);
            }

            delete targets;
            break;
        }
        case SMART_ACTION_SET_FLY:
        {
            if (!IsSmart())
                break;

            CAST_AI(SmartAI, me->AI())->SetFly(e.action.setFly.fly ? true : false);
            break;
        }
        case SMART_ACTION_SET_RUN:
        {
            if (!IsSmart())
                break;

            CAST_AI(SmartAI, me->AI())->SetRun(e.action.setRun.run ? true : false);
            break;
        }
        case SMART_ACTION_SET_SWIM:
        {
            if (!IsSmart())
                break;

            CAST_AI(SmartAI, me->AI())->SetSwim(e.action.setSwim.swim ? true : false);
            break;
        }
        case SMART_ACTION_WP_START:
        {
            if (!IsSmart())
                break;

            bool run = e.action.wpStart.run ? true : false;
            uint32 entry = e.action.wpStart.pathID;
            bool repeat = e.action.wpStart.repeat ? true : false;
            ObjectList* targets = GetTargets(e, unit);
            StoreTargetList(targets, SMART_ESCORT_TARGETS);
            me->SetReactState((ReactStates)e.action.wpStart.reactState);
            CAST_AI(SmartAI, me->AI())->StartPath(run, entry, repeat, unit);

            uint32 quest = e.action.wpStart.quest;
            uint32 DespawnTime = e.action.wpStart.despawnTime;
            CAST_AI(SmartAI, me->AI())->mEscortQuestID = quest;
            CAST_AI(SmartAI, me->AI())->SetDespawnTime(DespawnTime);
            break;
        }
        case SMART_ACTION_WP_PAUSE:
        {
            if (!IsSmart())
                break;

            uint32 delay = e.action.wpPause.delay;
            CAST_AI(SmartAI, me->AI())->PausePath(delay, e.GetEventType() == SMART_EVENT_WAYPOINT_REACHED ? false : true);
            break;
        }
        case SMART_ACTION_WP_STOP:
        {
            if (!IsSmart())
                break;

            uint32 DespawnTime = e.action.wpStop.despawnTime;
            uint32 quest = e.action.wpStop.quest;
            bool fail = e.action.wpStop.fail ? true : false;
            CAST_AI(SmartAI, me->AI())->StopPath(DespawnTime, quest, fail);
            break;
        }
        case SMART_ACTION_WP_RESUME:
        {
            if (!IsSmart())
                break;

            CAST_AI(SmartAI, me->AI())->ResumePath();
            break;
        }
        case SMART_ACTION_SET_ORIENTATION:
        {
            if (!me)
                break;

            ObjectList* targets = GetTargets(e, unit);
            if (e.GetTargetType() == SMART_TARGET_SELF)
                me->SetFacingTo(me->GetHomePosition().GetOrientation());
            else if (e.GetTargetType() == SMART_TARGET_POSITION)
                me->SetFacingTo(e.target.o);
            else if (targets && !targets->empty())
                me->SetFacingToObject(*targets->begin());

            delete targets;
            break;
        }
        case SMART_ACTION_PLAYMOVIE:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (!IsPlayer(*itr))
                    continue;

                (*itr)->ToPlayer()->SendMovieStart(e.action.movie.entry);
            }

            delete targets;
            break;
        }
        case SMART_ACTION_MOVE_TO_POS:
        {
            if (!IsSmart())
                break;

            WorldObject* target = NULL;

            if (e.GetTargetType() == SMART_TARGET_CREATURE_RANGE || e.GetTargetType() == SMART_TARGET_CREATURE_GUID ||
                e.GetTargetType() == SMART_TARGET_CREATURE_DISTANCE || e.GetTargetType() == SMART_TARGET_GAMEOBJECT_RANGE ||
                e.GetTargetType() == SMART_TARGET_GAMEOBJECT_GUID || e.GetTargetType() == SMART_TARGET_GAMEOBJECT_DISTANCE ||
                e.GetTargetType() == SMART_TARGET_CLOSEST_CREATURE || e.GetTargetType() == SMART_TARGET_CLOSEST_GAMEOBJECT ||
                e.GetTargetType() == SMART_TARGET_OWNER_OR_SUMMONER || e.GetTargetType() == SMART_TARGET_ACTION_INVOKER)
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets)
                    break;

                target = targets->front();
                delete targets;
            }

            if (!target)
                me->GetMotionMaster()->MovePoint(e.action.MoveToPos.pointId, e.target.x, e.target.y, e.target.z);
            else
                me->GetMotionMaster()->MovePoint(e.action.MoveToPos.pointId, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
            break;
        }
        case SMART_ACTION_RESPAWN_TARGET:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsCreature(*itr))
                    (*itr)->ToCreature()->Respawn();
                else if (IsGameObject(*itr))
                    (*itr)->ToGameObject()->SetRespawnTime(e.action.RespawnTarget.goRespawnTime);
            }

            delete targets;
            break;
        }
        case SMART_ACTION_CLOSE_GOSSIP:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsPlayer(*itr))
                    (*itr)->ToPlayer()->PlayerTalkClass->SendCloseGossip();

            delete targets;
            break;
        }
        case SMART_ACTION_EQUIP:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (Creature* npc = (*itr)->ToCreature())
                {
                    uint32 slot[3];
                    if (e.action.equip.entry)
                    {
                        EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(e.action.equip.entry);
                        if (!einfo)
                        {
                            sLog->outErrorDb("SmartScript: SMART_ACTION_EQUIP uses non-existent equipment info entry %u", e.action.equip.entry);
                            return;
                        }
                        npc->SetCurrentEquipmentId(e.action.equip.entry);
                        slot[0] = einfo->ItemEntry[0];
                        slot[1] = einfo->ItemEntry[1];
                        slot[2] = einfo->ItemEntry[2];
                    }
                    else
                    {
                        slot[0] = e.action.equip.slot1;
                        slot[1] = e.action.equip.slot2;
                        slot[2] = e.action.equip.slot3;
                    }
                    if (!e.action.equip.mask || e.action.equip.mask & 1)
                        npc->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, slot[0]);
                    if (!e.action.equip.mask || e.action.equip.mask & 2)
                        npc->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, slot[1]);
                    if (!e.action.equip.mask || e.action.equip.mask & 4)
                        npc->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, slot[2]);
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_CREATE_TIMED_EVENT:
        {
            SmartEvent ne;
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

            SmartAction ac;
            ac.type = (SMART_ACTION)SMART_ACTION_TRIGGER_TIMED_EVENT;
            ac.timeEvent.id = e.action.timeEvent.id;

            SmartScriptHolder ev;
            ev.event = ne;
            ev.event_id = e.action.timeEvent.id;
            ev.target = e.target;
            ev.action = ac;
            InitTimer(ev);
            mStoredEvents.push_back(ev);
            break;
        }
        case SMART_ACTION_TRIGGER_TIMED_EVENT:
            ProcessEventsFor((SMART_EVENT)SMART_EVENT_TIMED_EVENT_TRIGGERED, NULL, e.action.timeEvent.id);
            break;
        case SMART_ACTION_REMOVE_TIMED_EVENT:
            mRemIDs.push_back(e.action.timeEvent.id);
            break;
        case SMART_ACTION_OVERRIDE_SCRIPT_BASE_OBJECT:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsCreature(*itr))
                {
                    if (!meOrigGUID)
                        meOrigGUID = me ? me->GetGUID() : 0;
                    if (!goOrigGUID)
                        goOrigGUID = go ? go->GetGUID() : 0;
                    go = NULL;
                    me = (*itr)->ToCreature();
                    break;
                }
                else if (IsGameObject(*itr))
                {
                    if (!meOrigGUID)
                        meOrigGUID = me ? me->GetGUID() : 0;
                    if (!goOrigGUID)
                        goOrigGUID = go ? go->GetGUID() : 0;
                    go = (*itr)->ToGameObject();
                    me = NULL;
                    break;
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_RESET_SCRIPT_BASE_OBJECT:
            ResetBaseObject();
            break;
        case SMART_ACTION_CALL_SCRIPT_RESET:
            OnReset();
            break;
        case SMART_ACTION_CALL_TIMED_ACTIONLIST:
        {
            if (e.GetTargetType() == SMART_TARGET_NONE)
            {
                sLog->outErrorDb("SmartScript: Entry %d SourceType %u Event %u Action %u is using TARGET_NONE(0) for Script9 target. Please correct target_type in database.", e.entryOrGuid, e.GetScriptType(), e.GetEventType(), e.GetActionType());
                break;
            }

            ObjectList* targets = GetTargets(e, unit);
            if (targets)
            {
                for (ObjectList::iterator itr = targets->begin(); itr != targets->end(); ++itr)
                {
                    if (Creature* target = (*itr)->ToCreature())
                    {
                        if (IsSmart(target))
                            CAST_AI(SmartAI, target->AI())->SetScript9(e, e.action.timedActionList.id, GetLastInvoker());
                    }
                    else if (GameObject* goTarget = (*itr)->ToGameObject())
                    {
                        if (IsSmartGO(goTarget))
                            CAST_AI(SmartGameObjectAI, goTarget->AI())->SetScript9(e, e.action.timedActionList.id, GetLastInvoker());
                    }
                }

                delete targets;
            }
            break;
        }
        case SMART_ACTION_SET_NPC_FLAG:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsUnit(*itr))
                    (*itr)->ToUnit()->SetUInt32Value(UNIT_NPC_FLAGS, e.action.unitFlag.flag);

            delete targets;
            break;
        }
        case SMART_ACTION_ADD_NPC_FLAG:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsUnit(*itr))
                    (*itr)->ToUnit()->SetFlag(UNIT_NPC_FLAGS, e.action.unitFlag.flag);

            delete targets;
            break;
        }
        case SMART_ACTION_REMOVE_NPC_FLAG:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsUnit(*itr))
                    (*itr)->ToUnit()->RemoveFlag(UNIT_NPC_FLAGS, e.action.unitFlag.flag);

            delete targets;
            break;
        }
        case SMART_ACTION_CROSS_CAST:
        {
            ObjectList* casters = GetTargets(CreateEvent(SMART_EVENT_UPDATE_IC, 0, 0, 0, 0, 0, SMART_ACTION_NONE, 0, 0, 0, 0, 0, 0, (SMARTAI_TARGETS)e.action.cast.targetType, e.action.cast.targetParam1, e.action.cast.targetParam2, e.action.cast.targetParam3, 0), unit);
            if (!casters)
                break;

            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
            {
                delete casters; // casters already validated, delete now
                break;
            }

            for (ObjectList::const_iterator itr = casters->begin(); itr != casters->end(); ++itr)
            {
                if (IsUnit(*itr))
                {
                    if (e.action.cast.flags & SMARTCAST_INTERRUPT_PREVIOUS)
                        (*itr)->ToUnit()->InterruptNonMeleeSpells(false);

                    for (ObjectList::const_iterator it = targets->begin(); it != targets->end(); ++it)
                    {
                        if (IsUnit(*it))
                        {
                            if (!(e.action.cast.flags & SMARTCAST_AURA_NOT_PRESENT) || !(*it)->ToUnit()->HasAura(e.action.cast.spell))
                                (*itr)->ToUnit()->CastSpell((*it)->ToUnit(), e.action.cast.spell, (e.action.cast.flags & SMARTCAST_TRIGGERED) ? true : false);
                            else
                                sLog->outDebug(LOG_FILTER_DATABASE_AI, "Spell %u not casted because it has flag SMARTCAST_AURA_NOT_PRESENT and the target (Guid: " UI64FMTD " Entry: %u Type: %u) already has the aura", e.action.cast.spell, (*it)->GetGUID(), (*it)->GetEntry(), uint32((*it)->GetTypeId()));
                        }
                    }
                }
            }

            delete targets;
            delete casters;
            break;
        }
        case SMART_ACTION_CALL_RANDOM_TIMED_ACTIONLIST:
        {
            uint32 actions[SMART_ACTION_PARAM_COUNT];
            actions[0] = e.action.randTimedActionList.entry1;
            actions[1] = e.action.randTimedActionList.entry2;
            actions[2] = e.action.randTimedActionList.entry3;
            actions[3] = e.action.randTimedActionList.entry4;
            actions[4] = e.action.randTimedActionList.entry5;
            actions[5] = e.action.randTimedActionList.entry6;
            uint32 temp[SMART_ACTION_PARAM_COUNT];
            uint32 count = 0;
            for (uint8 i = 0; i < SMART_ACTION_PARAM_COUNT; i++)
            {
                if (actions[i] > 0)
                {
                    temp[count] = actions[i];
                    ++count;
                }
            }

            uint32 id = temp[urand(0, count)];
            if (e.GetTargetType() == SMART_TARGET_NONE)
            {
                sLog->outErrorDb("SmartScript: Entry %d SourceType %u Event %u Action %u is using TARGET_NONE(0) for Script9 target. Please correct target_type in database.", e.entryOrGuid, e.GetScriptType(), e.GetEventType(), e.GetActionType());
                break;
            }

            ObjectList* targets = GetTargets(e, unit);
            if (targets)
            {
                for (ObjectList::iterator itr = targets->begin(); itr != targets->end(); ++itr)
                {
                    if (Creature* target = (*itr)->ToCreature())
                    {
                        if (IsSmart(target))
                            CAST_AI(SmartAI, target->AI())->SetScript9(e, id, GetLastInvoker());
                    }
                    else if (GameObject* goTarget = (*itr)->ToGameObject())
                    {
                        if (IsSmartGO(goTarget))
                            CAST_AI(SmartGameObjectAI, goTarget->AI())->SetScript9(e, id, GetLastInvoker());
                    }
                }

                delete targets;
            }
            break;
        }
        case SMART_ACTION_CALL_RANDOM_RANGE_TIMED_ACTIONLIST:
        {
            uint32 id = urand(e.action.randTimedActionList.entry1, e.action.randTimedActionList.entry2);
            if (e.GetTargetType() == SMART_TARGET_NONE)
            {
                sLog->outErrorDb("SmartScript: Entry %d SourceType %u Event %u Action %u is using TARGET_NONE(0) for Script9 target. Please correct target_type in database.", e.entryOrGuid, e.GetScriptType(), e.GetEventType(), e.GetActionType());
                break;
            }

            ObjectList* targets = GetTargets(e, unit);
            if (targets)
            {
                for (ObjectList::iterator itr = targets->begin(); itr != targets->end(); ++itr)
                {
                    if (Creature* target = (*itr)->ToCreature())
                    {
                        if (IsSmart(target))
                            CAST_AI(SmartAI, target->AI())->SetScript9(e, id, GetLastInvoker());
                    }
                    else if (GameObject* goTarget = (*itr)->ToGameObject())
                    {
                        if (IsSmartGO(goTarget))
                            CAST_AI(SmartGameObjectAI, goTarget->AI())->SetScript9(e, id, GetLastInvoker());
                    }
                }

                delete targets;
            }
            break;
        }
        case SMART_ACTION_ACTIVATE_TAXI:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsPlayer(*itr))
                    (*itr)->ToPlayer()->ActivateTaxiPathTo(e.action.taxi.id);

            delete targets;
            break;
        }
        case SMART_ACTION_RANDOM_MOVE:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsCreature((*itr)))
                {
                    if (e.action.moveRandom.distance)
                        (*itr)->ToCreature()->GetMotionMaster()->MoveRandom((float)e.action.moveRandom.distance);
                    else
                        (*itr)->ToCreature()->GetMotionMaster()->MoveIdle();
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_SET_UNIT_FIELD_BYTES_1:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;
            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsUnit(*itr))
                    (*itr)->ToUnit()->SetByteFlag(UNIT_FIELD_BYTES_1, 0, e.action.setunitByte.byte1);

            delete targets;
            break;
        }
        case SMART_ACTION_REMOVE_UNIT_FIELD_BYTES_1:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsUnit(*itr))
                    (*itr)->ToUnit()->RemoveByteFlag(UNIT_FIELD_BYTES_1, 0, e.action.delunitByte.byte1);

            delete targets;
            break;
        }
        case SMART_ACTION_INTERRUPT_SPELL:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsUnit(*itr))
                    (*itr)->ToUnit()->InterruptNonMeleeSpells(e.action.interruptSpellCasting.withDelayed, e.action.interruptSpellCasting.spell_id, e.action.interruptSpellCasting.withInstant);

            delete targets;
            break;
        }
        case SMART_ACTION_SEND_GO_CUSTOM_ANIM:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsGameObject(*itr))
                    (*itr)->ToGameObject()->SendCustomAnim(e.action.sendGoCustomAnim.anim);

            delete targets;
            break;
        }
        case SMART_ACTION_SET_DYNAMIC_FLAG:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsUnit(*itr))
                    (*itr)->ToUnit()->SetUInt32Value(UNIT_DYNAMIC_FLAGS, e.action.unitFlag.flag);

            delete targets;
            break;
        }
        case SMART_ACTION_ADD_DYNAMIC_FLAG:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsUnit(*itr))
                    (*itr)->ToUnit()->SetFlag(UNIT_DYNAMIC_FLAGS, e.action.unitFlag.flag);

            delete targets;
            break;
        }
        case SMART_ACTION_REMOVE_DYNAMIC_FLAG:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsUnit(*itr))
                    (*itr)->ToUnit()->RemoveFlag(UNIT_DYNAMIC_FLAGS, e.action.unitFlag.flag);

            delete targets;
            break;
        }
        case SMART_ACTION_JUMP_TO_POS:
        {
            if (!me)
                break;

            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveJump(e.target.x, e.target.y, e.target.z, (float)e.action.jump.speedxy, (float)e.action.jump.speedz);
            // TODO: Resume path when reached jump location
            break;
        }
        case SMART_ACTION_GO_SET_LOOT_STATE:
        {
            ObjectList* targets = GetTargets(e, unit);

            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (IsGameObject(*itr))
                    (*itr)->ToGameObject()->SetLootState((LootState)e.action.setGoLootState.state);

            delete targets;
            break;
        }
        case SMART_ACTION_SEND_TARGET_TO_TARGET:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
            {
                if (IsCreature(*itr))
                {
                    if (SmartAI* ai = CAST_AI(SmartAI, (*itr)->ToCreature()->AI()))
                        ai->GetScript()->StoreTargetList(GetTargetList(e.action.sendTargetToTarget.id), e.action.sendTargetToTarget.id);
                    else
                        sLog->outErrorDb("SmartScript: Action target for SMART_ACTION_SEND_TARGET_TO_TARGET is not using SmartAI, skipping");
                }
                else if (IsGameObject(*itr))
                {
                    if (SmartGameObjectAI* ai = CAST_AI(SmartGameObjectAI, (*itr)->ToGameObject()->AI()))
                        ai->GetScript()->StoreTargetList(GetTargetList(e.action.sendTargetToTarget.id), e.action.sendTargetToTarget.id);
                    else
                        sLog->outErrorDb("SmartScript: Action target for SMART_ACTION_SEND_TARGET_TO_TARGET is not using SmartGameObjectAI, skipping");
                }
            }

            delete targets;
            break;
        }
        case SMART_ACTION_SEND_GOSSIP_MENU:
        {
            if (!GetBaseObject())
                break;

            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::ProcessAction:: SMART_ACTION_SEND_GOSSIP_MENU: gossipMenuId %d, gossipNpcTextId %d",
                e.action.sendGossipMenu.gossipMenuId, e.action.sendGossipMenu.gossipNpcTextId);

            ObjectList* targets = GetTargets(e, unit);
            if (!targets)
                break;

            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); ++itr)
                if (Player* player = (*itr)->ToPlayer())
                {
                    if (e.action.sendGossipMenu.gossipMenuId)
                        player->PrepareGossipMenu(GetBaseObject(), e.action.sendGossipMenu.gossipMenuId, true);
                    else
                        player->PlayerTalkClass->ClearMenus();

                    player->SEND_GOSSIP_MENU(e.action.sendGossipMenu.gossipNpcTextId, GetBaseObject()->GetGUID());
                }

            delete targets;
            break;
        }
        default:
            sLog->outErrorDb("SmartScript::ProcessAction: Unhandled Action type %u", e.GetActionType());
            break;
    }

    if (e.link && e.link != e.event_id)
    {
        SmartScriptHolder linked = FindLinkedEvent(e.link);
        if (linked.GetActionType() && linked.GetEventType() == SMART_EVENT_LINK)
            ProcessEvent(linked, unit, var0, var1, bvar, spell, gob);
        else
            sLog->outErrorDb("SmartScript::ProcessAction: Entry %d SourceType %u, Event %u, Link Event %u not found or invalid, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.link);
    }
}

void SmartScript::InstallTemplate(SmartScriptHolder const& e)
{
    if (!GetBaseObject())
        return;
    if (mTemplate)
    {
        sLog->outErrorDb("SmartScript::InstallTemplate: Entry %d SourceType %u AI Template can not be set more then once, skipped.", e.entryOrGuid, e.GetScriptType());
        return;
    }
    mTemplate = (SMARTAI_TEMPLATE)e.action.installTtemplate.id;
    switch ((SMARTAI_TEMPLATE)e.action.installTtemplate.id)
    {
        case SMARTAI_TEMPLATE_CASTER:
            {
                AddEvent(SMART_EVENT_UPDATE_IC, 0, 0, 0, e.action.installTtemplate.param2, e.action.installTtemplate.param3, SMART_ACTION_CAST, e.action.installTtemplate.param1, e.target.raw.param1, 0, 0, 0, 0, SMART_TARGET_VICTIM, 0, 0, 0, 1);
                AddEvent(SMART_EVENT_RANGE, 0, e.action.installTtemplate.param4, 300, 0, 0, SMART_ACTION_ALLOW_COMBAT_MOVEMENT, 1, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 1);
                AddEvent(SMART_EVENT_RANGE, 0, 0, e.action.installTtemplate.param4>10?e.action.installTtemplate.param4-10:0, 0, 0, SMART_ACTION_ALLOW_COMBAT_MOVEMENT, 0, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 1);
                AddEvent(SMART_EVENT_MANA_PCT, 0, e.action.installTtemplate.param5-15>100?100:e.action.installTtemplate.param5+15, 100, 1000, 1000, SMART_ACTION_SET_EVENT_PHASE, 1, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 0);
                AddEvent(SMART_EVENT_MANA_PCT, 0, 0, e.action.installTtemplate.param5, 1000, 1000, SMART_ACTION_SET_EVENT_PHASE, 0, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 0);
                AddEvent(SMART_EVENT_MANA_PCT, 0, 0, e.action.installTtemplate.param5, 1000, 1000, SMART_ACTION_ALLOW_COMBAT_MOVEMENT, 1, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 0);
                break;
            }
        case SMARTAI_TEMPLATE_TURRET:
            {
                AddEvent(SMART_EVENT_UPDATE_IC, 0, 0, 0, e.action.installTtemplate.param2, e.action.installTtemplate.param3, SMART_ACTION_CAST, e.action.installTtemplate.param1, e.target.raw.param1, 0, 0, 0, 0, SMART_TARGET_VICTIM, 0, 0, 0, 0);
                AddEvent(SMART_EVENT_JUST_CREATED, 0, 0, 0, 0, 0, SMART_ACTION_ALLOW_COMBAT_MOVEMENT, 0, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 0);
                break;
            }
        case SMARTAI_TEMPLATE_CAGED_NPC_PART:
            {
                if (!me)
                    return;
                //store cage as id1
                AddEvent(SMART_EVENT_DATA_SET, 0, 0, 0, 0, 0, SMART_ACTION_STORE_TARGET_LIST, 1, 0, 0, 0, 0, 0, SMART_TARGET_CLOSEST_GAMEOBJECT, e.action.installTtemplate.param1, 10, 0, 0);

                 //reset(close) cage on hostage(me) respawn
                AddEvent(SMART_EVENT_UPDATE, SMART_EVENT_FLAG_NOT_REPEATABLE, 0, 0, 0, 0, SMART_ACTION_RESET_GOBJECT, 0, 0, 0, 0, 0, 0, SMART_TARGET_GAMEOBJECT_DISTANCE, e.action.installTtemplate.param1, 5, 0, 0);

                AddEvent(SMART_EVENT_DATA_SET, 0, 0, 0, 0, 0, SMART_ACTION_SET_RUN, e.action.installTtemplate.param3, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 0);
                AddEvent(SMART_EVENT_DATA_SET, 0, 0, 0, 0, 0, SMART_ACTION_SET_EVENT_PHASE, 1, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 0);

                AddEvent(SMART_EVENT_UPDATE, SMART_EVENT_FLAG_NOT_REPEATABLE, 1000, 1000, 0, 0, SMART_ACTION_MOVE_FORWARD, e.action.installTtemplate.param4, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 1);
                 //phase 1: give quest credit on movepoint reached
                AddEvent(SMART_EVENT_MOVEMENTINFORM, 0, POINT_MOTION_TYPE, SMART_RANDOM_POINT, 0, 0, SMART_ACTION_SET_DATA, 0, 0, 0, 0, 0, 0, SMART_TARGET_STORED, 1, 0, 0, 1);
                //phase 1: despawn after time on movepoint reached
                AddEvent(SMART_EVENT_MOVEMENTINFORM, 0, POINT_MOTION_TYPE, SMART_RANDOM_POINT, 0, 0, SMART_ACTION_FORCE_DESPAWN, e.action.installTtemplate.param2, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 1);

                if (sCreatureTextMgr->TextExist(me->GetEntry(), (uint8)e.action.installTtemplate.param5))
                    AddEvent(SMART_EVENT_MOVEMENTINFORM, 0, POINT_MOTION_TYPE, SMART_RANDOM_POINT, 0, 0, SMART_ACTION_TALK, e.action.installTtemplate.param5, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 1);
                break;
            }
        case SMARTAI_TEMPLATE_CAGED_GO_PART:
            {
                if (!go)
                    return;
                //store hostage as id1
                AddEvent(SMART_EVENT_GOSSIP_HELLO, 0, 0, 0, 0, 0, SMART_ACTION_STORE_TARGET_LIST, 1, 0, 0, 0, 0, 0, SMART_TARGET_CLOSEST_CREATURE, e.action.installTtemplate.param1, 10, 0, 0);
                //store invoker as id2
                AddEvent(SMART_EVENT_GOSSIP_HELLO, 0, 0, 0, 0, 0, SMART_ACTION_STORE_TARGET_LIST, 2, 0, 0, 0, 0, 0, SMART_TARGET_NONE, 0, 0, 0, 0);
                //signal hostage
                AddEvent(SMART_EVENT_GOSSIP_HELLO, 0, 0, 0, 0, 0, SMART_ACTION_SET_DATA, 0, 0, 0, 0, 0, 0, SMART_TARGET_STORED, 1, 0, 0, 0);
                //when hostage raeched end point, give credit to invoker
                if (e.action.installTtemplate.param2)
                    AddEvent(SMART_EVENT_DATA_SET, 0, 0, 0, 0, 0, SMART_ACTION_CALL_KILLEDMONSTER, e.action.installTtemplate.param1, 0, 0, 0, 0, 0, SMART_TARGET_STORED, 2, 0, 0, 0);
                else
                    AddEvent(SMART_EVENT_GOSSIP_HELLO, 0, 0, 0, 0, 0, SMART_ACTION_CALL_KILLEDMONSTER, e.action.installTtemplate.param1, 0, 0, 0, 0, 0, SMART_TARGET_STORED, 2, 0, 0, 0);
                break;
            }
        case SMARTAI_TEMPLATE_BASIC:
        default:
            return;
    }
}

void SmartScript::AddEvent(SMART_EVENT e, uint32 event_flags, uint32 event_param1, uint32 event_param2, uint32 event_param3, uint32 event_param4, SMART_ACTION action, uint32 action_param1, uint32 action_param2, uint32 action_param3, uint32 action_param4, uint32 action_param5, uint32 action_param6, SMARTAI_TARGETS t, uint32 target_param1, uint32 target_param2, uint32 target_param3, uint32 phaseMask)
{
    mInstallEvents.push_back(CreateEvent(e, event_flags, event_param1, event_param2, event_param3, event_param4, action, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, t, target_param1, target_param2, target_param3, phaseMask));
}

SmartScriptHolder SmartScript::CreateEvent(SMART_EVENT e, uint32 event_flags, uint32 event_param1, uint32 event_param2, uint32 event_param3, uint32 event_param4, SMART_ACTION action, uint32 action_param1, uint32 action_param2, uint32 action_param3, uint32 action_param4, uint32 action_param5, uint32 action_param6, SMARTAI_TARGETS t, uint32 target_param1, uint32 target_param2, uint32 target_param3, uint32 phaseMask)
{
    SmartScriptHolder script;
    script.event.type = e;
    script.event.raw.param1 = event_param1;
    script.event.raw.param2 = event_param2;
    script.event.raw.param3 = event_param3;
    script.event.raw.param4 = event_param4;
    script.event.event_phase_mask = phaseMask;
    script.event.event_flags = event_flags;

    script.action.type = action;
    script.action.raw.param1 = action_param1;
    script.action.raw.param2 = action_param2;
    script.action.raw.param3 = action_param3;
    script.action.raw.param4 = action_param4;
    script.action.raw.param5 = action_param5;
    script.action.raw.param6 = action_param6;

    script.target.type = t;
    script.target.raw.param1 = target_param1;
    script.target.raw.param2 = target_param2;
    script.target.raw.param3 = target_param3;

    script.source_type = SMART_SCRIPT_TYPE_CREATURE;
    InitTimer(script);
    return script;
}

ObjectList* SmartScript::GetTargets(SmartScriptHolder const& e, Unit* invoker /*= NULL*/)
{
    Unit* trigger = NULL;
    if (invoker)
        trigger = invoker;
    else if (Unit* tempLastInvoker = GetLastInvoker())
        trigger = tempLastInvoker;

    ObjectList* l = new ObjectList();
    switch (e.GetTargetType())
    {
        case SMART_TARGET_SELF:
            if (GetBaseObject())
                l->push_back(GetBaseObject());
            break;
        case SMART_TARGET_VICTIM:
            if (me && me->getVictim())
                l->push_back(me->getVictim());
            break;
        case SMART_TARGET_HOSTILE_SECOND_AGGRO:
            if (me)
                if (Unit* u = me->AI()->SelectTarget(SELECT_TARGET_TOPAGGRO, 1))
                    l->push_back(u);
            break;
        case SMART_TARGET_HOSTILE_LAST_AGGRO:
            if (me)
                if (Unit* u = me->AI()->SelectTarget(SELECT_TARGET_BOTTOMAGGRO, 0))
                    l->push_back(u);
            break;
        case SMART_TARGET_HOSTILE_RANDOM:
            if (me)
                if (Unit* u = me->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0))
                    l->push_back(u);
            break;
        case SMART_TARGET_HOSTILE_RANDOM_NOT_TOP:
            if (me)
                if (Unit* u = me->AI()->SelectTarget(SELECT_TARGET_RANDOM, 1))
                    l->push_back(u);
            break;
        case SMART_TARGET_NONE:
        case SMART_TARGET_ACTION_INVOKER:
            if (trigger)
                l->push_back(trigger);
            break;
        case SMART_TARGET_ACTION_INVOKER_VEHICLE:
            if (trigger && trigger->GetVehicle() && trigger->GetVehicle()->GetBase())
                l->push_back(trigger->GetVehicle()->GetBase());
            break;
        case SMART_TARGET_INVOKER_PARTY:
            if (trigger)
            {
                l->push_back(trigger);
                if (Player* player = trigger->ToPlayer())
                    if (Group* group = player->GetGroup())
                        for (GroupReference* groupRef = group->GetFirstMember(); groupRef != NULL; groupRef = groupRef->next())
                            if (Player* member = groupRef->getSource())
                                l->push_back(member);
            }
            break;
        case SMART_TARGET_CREATURE_RANGE:
        {
            // will always return a valid pointer, even if empty list
            ObjectList* units = GetWorldObjectsInDist((float)e.target.unitRange.maxDist);
            for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); ++itr)
            {
                if (!IsCreature(*itr))
                    continue;

                if (me && me == *itr)
                    continue;

                if (((e.target.unitRange.creature && (*itr)->ToCreature()->GetEntry() == e.target.unitRange.creature) || !e.target.unitRange.creature) && GetBaseObject()->IsInRange(*itr, (float)e.target.unitRange.minDist, (float)e.target.unitRange.maxDist))
                    l->push_back(*itr);
            }

            delete units;
            break;
        }
        case SMART_TARGET_CREATURE_DISTANCE:
        {
            // will always return a valid pointer, even if empty list
            ObjectList* units = GetWorldObjectsInDist((float)e.target.unitDistance.dist);
            for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); ++itr)
            {
                if (!IsCreature(*itr))
                    continue;

                if (me && me == *itr)
                    continue;

                if ((e.target.unitDistance.creature && (*itr)->ToCreature()->GetEntry() == e.target.unitDistance.creature) || !e.target.unitDistance.creature)
                    l->push_back(*itr);
            }

            delete units;
            break;
        }
        case SMART_TARGET_GAMEOBJECT_DISTANCE:
        {
            // will always return a valid pointer, even if empty list
            ObjectList* units = GetWorldObjectsInDist((float)e.target.goDistance.dist);
            for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); ++itr)
            {
                if (!IsGameObject(*itr))
                    continue;

                if (go && go == *itr)
                    continue;

                if ((e.target.goDistance.entry && (*itr)->ToGameObject()->GetEntry() == e.target.goDistance.entry) || !e.target.goDistance.entry)
                    l->push_back(*itr);
            }

            delete units;
            break;
        }
        case SMART_TARGET_GAMEOBJECT_RANGE:
        {
            // will always return a valid pointer, even if empty list
            ObjectList* units = GetWorldObjectsInDist((float)e.target.goRange.maxDist);
            for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); ++itr)
            {
                if (!IsGameObject(*itr))
                    continue;

                if (go && go == *itr)
                    continue;

                if (((e.target.goRange.entry && IsGameObject(*itr) && (*itr)->ToGameObject()->GetEntry() == e.target.goRange.entry) || !e.target.goRange.entry) && GetBaseObject()->IsInRange((*itr), (float)e.target.goRange.minDist, (float)e.target.goRange.maxDist))
                    l->push_back(*itr);
            }

            delete units;
            break;
        }
        case SMART_TARGET_CREATURE_GUID:
        {
            Creature* target = NULL;
            if (e.target.unitGUID.entry)
            {
                uint64 guid = MAKE_NEW_GUID(e.target.unitGUID.guid, e.target.unitGUID.entry, HIGHGUID_UNIT);
                target = HashMapHolder<Creature>::Find(guid);
            }
            else
            {
                if (!trigger && !GetBaseObject())
                {
                    sLog->outErrorDb("SMART_TARGET_CREATURE_GUID can not be used without invoker and without entry");
                    break;
                }

                target = FindCreatureNear(trigger ? trigger : GetBaseObject(), e.target.unitGUID.guid);
            }

            if (target)
                l->push_back(target);
            break;
        }
        case SMART_TARGET_GAMEOBJECT_GUID:
        {
            GameObject* target = NULL;
            if (e.target.unitGUID.entry)
            {
                uint64 guid = MAKE_NEW_GUID(e.target.goGUID.guid, e.target.goGUID.entry, HIGHGUID_GAMEOBJECT);
                target = HashMapHolder<GameObject>::Find(guid);
            }
            else
            {
                if (!trigger && !GetBaseObject())
                {
                    sLog->outErrorDb("SMART_TARGET_GAMEOBJECT_GUID can not be used without invoker and without entry");
                    break;
                }

                target = FindGameObjectNear(trigger ? trigger : GetBaseObject(), e.target.goGUID.guid);
            }

            if (target)
                l->push_back(target);
            break;
        }
        case SMART_TARGET_PLAYER_RANGE:
        {
            // will always return a valid pointer, even if empty list
            ObjectList* units = GetWorldObjectsInDist((float)e.target.playerRange.maxDist);
            if (!units->empty() && GetBaseObject())
                for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); ++itr)
                    if (IsPlayer(*itr) && GetBaseObject()->IsInRange(*itr, (float)e.target.playerRange.minDist, (float)e.target.playerRange.maxDist))
                        l->push_back(*itr);

            delete units;
            break;
        }
        case SMART_TARGET_PLAYER_DISTANCE:
        {
            // will always return a valid pointer, even if empty list
            ObjectList* units = GetWorldObjectsInDist((float)e.target.playerDistance.dist);
            for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); ++itr)
                if (IsPlayer(*itr))
                    l->push_back(*itr);

            delete units;
            break;
        }
        case SMART_TARGET_STORED:
        {
            ObjectListMap::iterator itr = mTargetStorage->find(e.target.stored.id);
            if (itr != mTargetStorage->end())
                l->assign(itr->second->begin(), itr->second->end());

            return l;
        }
        case SMART_TARGET_CLOSEST_CREATURE:
        {
            Creature* target = GetClosestCreatureWithEntry(GetBaseObject(), e.target.closest.entry, (float)(e.target.closest.dist ? e.target.closest.dist : 100), e.target.closest.dead ? false : true);
            if (target)
                l->push_back(target);
            break;
        }
        case SMART_TARGET_CLOSEST_GAMEOBJECT:
        {
            GameObject* target = GetClosestGameObjectWithEntry(GetBaseObject(), e.target.closest.entry, (float)(e.target.closest.dist ? e.target.closest.dist : 100));
            if (target)
                l->push_back(target);
            break;
        }
        case SMART_TARGET_CLOSEST_PLAYER:
        {
            if (me)
            {
                Player* target = me->SelectNearestPlayer((float)e.target.playerDistance.dist);
                if (target)
                    l->push_back(target);
            }
            break;
        }
        case SMART_TARGET_OWNER_OR_SUMMONER:
        {
            if (me)
                if (Unit* owner = ObjectAccessor::GetUnit(*me, me->GetCharmerOrOwnerGUID()))
                    l->push_back(owner);
            break;
        }
        case SMART_TARGET_THREAT_LIST:
        {
            if (me)
            {
                std::list<HostileReference*> const& threatList = me->getThreatManager().getThreatList();
                for (std::list<HostileReference*>::const_iterator i = threatList.begin(); i != threatList.end(); ++i)
                    if (Unit* temp = Unit::GetUnit(*me, (*i)->getUnitGuid()))
                        l->push_back(temp);
            }
            break;
        }
        case SMART_TARGET_POSITION:
        default:
            break;
    }

    if (l->empty())
    {
        delete l;
        l = NULL;
    }

    return l;
}

ObjectList* SmartScript::GetWorldObjectsInDist(float dist)
{
    ObjectList* targets = new ObjectList();
    WorldObject* obj = GetBaseObject();
    if (obj)
    {
        Trinity::AllWorldObjectsInRange u_check(obj, dist);
        Trinity::WorldObjectListSearcher<Trinity::AllWorldObjectsInRange> searcher(obj, *targets, u_check);
        obj->VisitNearbyObject(dist, searcher);
    }
    return targets;
}

void SmartScript::ProcessEvent(SmartScriptHolder& e, Unit* unit, uint32 var0, uint32 var1, bool bvar, const SpellInfo* spell, GameObject* gob)
{
    if (!e.active && e.GetEventType() != SMART_EVENT_LINK)
        return;

    if ((e.event.event_phase_mask && !IsInPhase(e.event.event_phase_mask)) || ((e.event.event_flags & SMART_EVENT_FLAG_NOT_REPEATABLE) && e.runOnce))
        return;

    switch (e.GetEventType())
    {
        case SMART_EVENT_LINK://special handling
            ProcessAction(e, unit, var0, var1, bvar, spell, gob);
            break;
        //called from Update tick
        case SMART_EVENT_UPDATE:
            RecalcTimer(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            ProcessAction(e);
            break;
        case SMART_EVENT_UPDATE_OOC:
            if (me && me->isInCombat())
                return;
            RecalcTimer(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            ProcessAction(e);
            break;
        case SMART_EVENT_UPDATE_IC:
            if (!me || !me->isInCombat())
                return;
            RecalcTimer(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            ProcessAction(e);
            break;
        case SMART_EVENT_HEALT_PCT:
        {
            if (!me || !me->isInCombat() || !me->GetMaxHealth())
                return;
            uint32 perc = (uint32)me->GetHealthPct();
            if (perc > e.event.minMaxRepeat.max || perc < e.event.minMaxRepeat.min)
                return;
            RecalcTimer(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            ProcessAction(e);
            break;
        }
        case SMART_EVENT_TARGET_HEALTH_PCT:
        {
            if (!me || !me->isInCombat() || !me->getVictim() || !me->getVictim()->GetMaxHealth())
                return;
            uint32 perc = (uint32)me->getVictim()->GetHealthPct();
            if (perc > e.event.minMaxRepeat.max || perc < e.event.minMaxRepeat.min)
                return;
            RecalcTimer(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            ProcessAction(e, me->getVictim());
            break;
        }
        case SMART_EVENT_MANA_PCT:
        {
            if (!me || !me->isInCombat() || !me->GetMaxPower(POWER_MANA))
                return;
            uint32 perc = uint32(100.0f * me->GetPower(POWER_MANA) / me->GetMaxPower(POWER_MANA));
            if (perc > e.event.minMaxRepeat.max || perc < e.event.minMaxRepeat.min)
                return;
            RecalcTimer(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            ProcessAction(e);
            break;
        }
        case SMART_EVENT_TARGET_MANA_PCT:
        {
            if (!me || !me->isInCombat() || !me->getVictim() || !me->getVictim()->GetMaxPower(POWER_MANA))
                return;
            uint32 perc = uint32(100.0f * me->getVictim()->GetPower(POWER_MANA) / me->getVictim()->GetMaxPower(POWER_MANA));
            if (perc > e.event.minMaxRepeat.max || perc < e.event.minMaxRepeat.min)
                return;
            RecalcTimer(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            ProcessAction(e, me->getVictim());
            break;
        }
        case SMART_EVENT_RANGE:
        {
            if (!me || !me->isInCombat() || !me->getVictim())
                return;

            if (me->IsInRange(me->getVictim(), (float)e.event.minMaxRepeat.min, (float)e.event.minMaxRepeat.max))
            {
                ProcessAction(e, me->getVictim());
                RecalcTimer(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            }
            break;
        }
        case SMART_EVENT_TARGET_CASTING:
        {
            if (!me || !me->isInCombat() || !me->getVictim() || !me->getVictim()->IsNonMeleeSpellCasted(false, false, true))
                return;
            ProcessAction(e, me->getVictim());
            RecalcTimer(e, e.event.minMax.repeatMin, e.event.minMax.repeatMax);
        }
        case SMART_EVENT_FRIENDLY_HEALTH:
        {
            if (!me || !me->isInCombat())
                return;

            Unit* target = DoSelectLowestHpFriendly((float)e.event.friendlyHealt.radius, e.event.friendlyHealt.hpDeficit);
            if (!target)
                return;
            ProcessAction(e, target);
            RecalcTimer(e, e.event.friendlyHealt.repeatMin, e.event.friendlyHealt.repeatMax);
            break;
        }
        case SMART_EVENT_FRIENDLY_IS_CC:
        {
            if (!me || !me->isInCombat())
                return;

            std::list<Creature*> pList;
            DoFindFriendlyCC(pList, (float)e.event.friendlyCC.radius);
            if (pList.empty())
                return;
            ProcessAction(e, *(pList.begin()));
            RecalcTimer(e, e.event.friendlyCC.repeatMin, e.event.friendlyCC.repeatMax);
            break;
        }
        case SMART_EVENT_FRIENDLY_MISSING_BUFF:
        {
            std::list<Creature*> pList;
            DoFindFriendlyMissingBuff(pList, (float)e.event.missingBuff.radius, e.event.missingBuff.spell);

            if (pList.empty())
                return;
            ProcessAction(e, *(pList.begin()));
            RecalcTimer(e, e.event.missingBuff.repeatMin, e.event.missingBuff.repeatMax);
            break;
        }
        case SMART_EVENT_HAS_AURA:
        {
            if (!me)
                return;
            uint32 count = me->GetAuraCount(e.event.aura.spell);
            if ((!e.event.aura.count && !count) || (e.event.aura.count && count >= e.event.aura.count))
            {
                ProcessAction(e);
                RecalcTimer(e, e.event.aura.repeatMin, e.event.aura.repeatMax);
            }
            break;
        }
        case SMART_EVENT_TARGET_BUFFED:
        {
            if (!me || !me->getVictim())
                return;
            uint32 count = me->getVictim()->GetAuraCount(e.event.aura.spell);
            if (count < e.event.aura.count)
                return;
            ProcessAction(e);
            RecalcTimer(e, e.event.aura.repeatMin, e.event.aura.repeatMax);
            break;
        }
        //no params
        case SMART_EVENT_AGGRO:
        case SMART_EVENT_DEATH:
        case SMART_EVENT_EVADE:
        case SMART_EVENT_REACHED_HOME:
        case SMART_EVENT_CHARMED:
        case SMART_EVENT_CHARMED_TARGET:
        case SMART_EVENT_CORPSE_REMOVED:
        case SMART_EVENT_AI_INIT:
        case SMART_EVENT_TRANSPORT_ADDPLAYER:
        case SMART_EVENT_TRANSPORT_REMOVE_PLAYER:
        case SMART_EVENT_QUEST_ACCEPTED:
        case SMART_EVENT_QUEST_OBJ_COPLETETION:
        case SMART_EVENT_QUEST_COMPLETION:
        case SMART_EVENT_QUEST_REWARDED:
        case SMART_EVENT_QUEST_FAIL:
        case SMART_EVENT_JUST_SUMMONED:
        case SMART_EVENT_RESET:
        case SMART_EVENT_JUST_CREATED:
        case SMART_EVENT_GOSSIP_HELLO:
        case SMART_EVENT_FOLLOW_COMPLETED:
            ProcessAction(e, unit, var0, var1, bvar, spell, gob);
            break;
        case SMART_EVENT_IS_BEHIND_TARGET:
            {
                if (!me)
                    return;

                if (Unit* victim = me->getVictim())
                {
                    if (!victim->HasInArc(static_cast<float>(M_PI), me))
                    {
                        ProcessAction(e, victim);
                        RecalcTimer(e, e.event.behindTarget.cooldownMin, e.event.behindTarget.cooldownMax);
                    }
                }
                break;
            }
        case SMART_EVENT_RECEIVE_EMOTE:
            if (e.event.emote.emote == var0)
            {
                ProcessAction(e, unit);
                RecalcTimer(e, e.event.emote.cooldownMin, e.event.emote.cooldownMax);
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
            ProcessAction(e, unit);
            RecalcTimer(e, e.event.kill.cooldownMin, e.event.kill.cooldownMax);
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
                    ProcessAction(e, unit, 0, 0, bvar, spell);
                    RecalcTimer(e, e.event.spellHit.cooldownMin, e.event.spellHit.cooldownMax);
                }
            break;
        }
        case SMART_EVENT_OOC_LOS:
        {
            if (!me || me->isInCombat())
                return;
            //can trigger if closer than fMaxAllowedRange
            float range = (float)e.event.los.maxDist;

            //if range is ok and we are actually in LOS
            if (me->IsWithinDistInMap(unit, range) && me->IsWithinLOSInMap(unit))
            {
                //if friendly event&&who is not hostile OR hostile event&&who is hostile
                if ((e.event.los.noHostile && !me->IsHostileTo(unit)) ||
                    (!e.event.los.noHostile && me->IsHostileTo(unit)))
                {
                    ProcessAction(e, unit);
                    RecalcTimer(e, e.event.los.cooldownMin, e.event.los.cooldownMax);
                }
            }
            break;
        }
        case SMART_EVENT_IC_LOS:
        {
            if (!me || !me->isInCombat())
                return;
            //can trigger if closer than fMaxAllowedRange
            float range = (float)e.event.los.maxDist;

            //if range is ok and we are actually in LOS
            if (me->IsWithinDistInMap(unit, range) && me->IsWithinLOSInMap(unit))
            {
                //if friendly event&&who is not hostile OR hostile event&&who is hostile
                if ((e.event.los.noHostile && !me->IsHostileTo(unit)) ||
                    (!e.event.los.noHostile && me->IsHostileTo(unit)))
                {
                    ProcessAction(e, unit);
                    RecalcTimer(e, e.event.los.cooldownMin, e.event.los.cooldownMax);
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
        {
            if (!IsCreature(unit))
                return;
            if (e.event.summoned.creature && unit->GetEntry() != e.event.summoned.creature)
                return;
            ProcessAction(e, unit);
            RecalcTimer(e, e.event.summoned.cooldownMin, e.event.summoned.cooldownMax);
            break;
        }
        case SMART_EVENT_RECEIVE_HEAL:
        case SMART_EVENT_DAMAGED:
        case SMART_EVENT_DAMAGED_TARGET:
        {
            if (var0 > e.event.minMaxRepeat.max || var0 < e.event.minMaxRepeat.min)
                return;
            ProcessAction(e, unit);
            RecalcTimer(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            break;
        }
        case SMART_EVENT_MOVEMENTINFORM:
        {
            if ((e.event.movementInform.type && var0 != e.event.movementInform.type) || (e.event.movementInform.id && var1 != e.event.movementInform.id))
                return;
            ProcessAction(e, unit, var0, var1);
            break;
        }
        case SMART_EVENT_TRANSPORT_RELOCATE:
        case SMART_EVENT_WAYPOINT_START:
        {
            if (e.event.waypoint.pathID && var0 != e.event.waypoint.pathID)
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
            if (!me || (e.event.waypoint.pointID && var0 != e.event.waypoint.pointID) || (e.event.waypoint.pathID && GetPathId() != e.event.waypoint.pathID))
                return;
            ProcessAction(e, unit);
            break;
        }
        case SMART_EVENT_SUMMON_DESPAWNED:
        case SMART_EVENT_INSTANCE_PLAYER_ENTER:
        {
            if (e.event.instancePlayerEnter.team && var0 != e.event.instancePlayerEnter.team)
                return;
            ProcessAction(e, unit, var0);
            RecalcTimer(e, e.event.instancePlayerEnter.cooldownMin, e.event.instancePlayerEnter.cooldownMax);
            break;
        }
        case SMART_EVENT_ACCEPTED_QUEST:
        case SMART_EVENT_REWARD_QUEST:
        {
            if (e.event.quest.quest && var0 != e.event.quest.quest)
                return;
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
            ProcessAction(e, unit, var0, var1);
            RecalcTimer(e, e.event.dataSet.cooldownMin, e.event.dataSet.cooldownMax);
            break;
        }
        case SMART_EVENT_PASSENGER_REMOVED:
        case SMART_EVENT_PASSENGER_BOARDED:
        {
            if (!unit)
                return;
            ProcessAction(e, unit);
            RecalcTimer(e, e.event.minMax.repeatMin, e.event.minMax.repeatMax);
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
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript: Gossip Select:  menu %u action %u", var0, var1);//little help for scripters
            if (e.event.gossip.sender != var0 || e.event.gossip.action != var1)
                return;
            ProcessAction(e, unit, var0, var1);
            break;
        }
        case SMART_EVENT_DUMMY_EFFECT:
        {
            if (e.event.dummy.spell != var0 || e.event.dummy.effIndex != var1)
                return;
            ProcessAction(e, unit, var0, var1);
            break;
        }
        case SMART_EVENT_GAME_EVENT_START:
        case SMART_EVENT_GAME_EVENT_END:
        {
            if (e.event.gameEvent.gameEventId != var0)
                return;
            ProcessAction(e, NULL, var0);
            break;
        }
        case SMART_EVENT_GO_STATE_CHANGED:
        {
            if (e.event.goStateChanged.state != var0)
                return;
            ProcessAction(e, unit, var0, var1);
            break;
        }
        default:
            sLog->outErrorDb("SmartScript::ProcessEvent: Unhandled Event type %u", e.GetEventType());
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
        case SMART_EVENT_OOC_LOS:
        case SMART_EVENT_IC_LOS:
            RecalcTimer(e, e.event.minMaxRepeat.min, e.event.minMaxRepeat.max);
            break;
        default:
            e.active = true;
            break;
    }
}
void SmartScript::RecalcTimer(SmartScriptHolder& e, uint32 min, uint32 max)
{
    // min/max was checked at loading!
    e.timer = urand(uint32(min), uint32(max));
    e.active = e.timer ? false : true;
}

void SmartScript::UpdateTimer(SmartScriptHolder& e, uint32 const diff)
{
    if (e.GetEventType() == SMART_EVENT_LINK)
        return;

    if (e.event.event_phase_mask && !IsInPhase(e.event.event_phase_mask))
        return;

    if (e.GetEventType() == SMART_EVENT_UPDATE_IC && (!me || !me->isInCombat()))
        return;

    if (e.GetEventType() == SMART_EVENT_UPDATE_OOC && (me && me->isInCombat()))//can be used with me=NULL (go script)
        return;

    if (e.timer < diff)
    {
        // delay spell cast event if another spell is being casted
        if (e.GetActionType() == SMART_ACTION_CAST)
        {
            if (!(e.action.cast.flags & SMARTCAST_INTERRUPT_PREVIOUS))
            {
                if (me && me->HasUnitState(UNIT_STATE_CASTING))
                {
                    e.timer = 1;
                    return;
                }
            }
        }

        e.active = true;//activate events with cooldown
        switch (e.GetEventType())//process ONLY timed events
        {
            case SMART_EVENT_UPDATE:
            case SMART_EVENT_UPDATE_OOC:
            case SMART_EVENT_UPDATE_IC:
            case SMART_EVENT_HEALT_PCT:
            case SMART_EVENT_TARGET_HEALTH_PCT:
            case SMART_EVENT_MANA_PCT:
            case SMART_EVENT_TARGET_MANA_PCT:
            case SMART_EVENT_RANGE:
            case SMART_EVENT_TARGET_CASTING:
            case SMART_EVENT_FRIENDLY_HEALTH:
            case SMART_EVENT_FRIENDLY_IS_CC:
            case SMART_EVENT_FRIENDLY_MISSING_BUFF:
            case SMART_EVENT_HAS_AURA:
            case SMART_EVENT_TARGET_BUFFED:
            case SMART_EVENT_IS_BEHIND_TARGET:
            {
                ProcessEvent(e);
                if (e.GetScriptType() == SMART_SCRIPT_TYPE_TIMED_ACTIONLIST)
                {
                    e.enableTimed = false;//disable event if it is in an ActionList and was processed once
                    for (SmartAIEventList::iterator i = mTimedActionList.begin(); i != mTimedActionList.end(); ++i)
                    {
                        //find the first event which is not the current one and enable it
                        if (i->event_id > e.event_id)
                        {
                            i->enableTimed = true;
                            break;
                        }
                    }
                }
                break;
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
        for (SmartAIEventList::iterator i = mInstallEvents.begin(); i != mInstallEvents.end(); ++i)
            mEvents.push_back(*i);//must be before UpdateTimers

        mInstallEvents.clear();
    }
}

bool SmartScript::ConditionValid(Unit* u, int32 c, int32 v1, int32 v2, int32 v3)
{
    if (c == 0)
        return true;

    if (!u || !u->ToPlayer())
        return false;

    Condition cond;
    cond.ConditionType = ConditionTypes(uint32(c));
    cond.ConditionValue1 = uint32(v1);
    cond.ConditionValue1 = uint32(v2);
    cond.ConditionValue1 = uint32(v3);
    ConditionSourceInfo srcInfo = ConditionSourceInfo(u->ToPlayer());
    return cond.Meets(srcInfo);
}

void SmartScript::OnUpdate(uint32 const diff)
{
    if ((mScriptType == SMART_SCRIPT_TYPE_CREATURE || mScriptType == SMART_SCRIPT_TYPE_GAMEOBJECT) && !GetBaseObject())
        return;

    InstallEvents();//before UpdateTimers

    for (SmartAIEventList::iterator i = mEvents.begin(); i != mEvents.end(); ++i)
        UpdateTimer(*i, diff);

    if (!mStoredEvents.empty())
        for (SmartAIEventList::iterator i = mStoredEvents.begin(); i != mStoredEvents.end(); ++i)
             UpdateTimer(*i, diff);

    bool needCleanup = true;
    if (!mTimedActionList.empty())
    {
        for (SmartAIEventList::iterator i = mTimedActionList.begin(); i != mTimedActionList.end(); ++i)
        {
            if ((*i).enableTimed)
            {
                UpdateTimer(*i, diff);
                needCleanup = false;
            }
        }
    }
    if (needCleanup)
        mTimedActionList.clear();

    if (!mRemIDs.empty())
    {
        for (std::list<uint32>::iterator i = mRemIDs.begin(); i != mRemIDs.end(); ++i)
        {
             RemoveStoredEvent((*i));
        }
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
            ProcessEventsFor(SMART_EVENT_TEXT_OVER, NULL, textID, entry);
        } else mTextTimer -= diff;
    }
}

void SmartScript::FillScript(SmartAIEventList e, WorldObject* obj, AreaTriggerEntry const* at)
{
    if (e.empty())
    {
        if (obj)
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript: EventMap for Entry %u is empty but is using SmartScript.", obj->GetEntry());
        if (at)
            sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript: EventMap for AreaTrigger %u is empty but is using SmartScript.", at->id);
        return;
    }
    for (SmartAIEventList::iterator i = e.begin(); i != e.end(); ++i)
    {
        #ifndef TRINITY_DEBUG
            if ((*i).event.event_flags & SMART_EVENT_FLAG_DEBUG_ONLY)
                continue;
        #endif

        if ((*i).event.event_flags & SMART_EVENT_FLAG_DIFFICULTY_ALL)//if has instance flag add only if in it
        {
            if (obj && obj->GetMap()->IsDungeon())
            {
                if ((1 << (obj->GetMap()->GetSpawnMode()+1)) & (*i).event.event_flags)
                {
                    mEvents.push_back((*i));
                }
            }
            continue;
        }
        mEvents.push_back((*i));//NOTE: 'world(0)' events still get processed in ANY instance mode
    }
    if (mEvents.empty() && obj)
        sLog->outErrorDb("SmartScript: Entry %u has events but no events added to list because of instance flags.", obj->GetEntry());
    if (mEvents.empty() && at)
        sLog->outErrorDb("SmartScript: AreaTrigger %u has events but no events added to list because of instance flags. NOTE: triggers can not handle any instance flags.", at->id);
}

void SmartScript::GetScript()
{
    SmartAIEventList e;
    if (me)
    {
        e = sSmartScriptMgr->GetScript(-((int32)me->GetDBTableGUIDLow()), mScriptType);
        if (e.empty())
            e = sSmartScriptMgr->GetScript((int32)me->GetEntry(), mScriptType);
        FillScript(e, me, NULL);
    }
    else if (go)
    {
        e = sSmartScriptMgr->GetScript(-((int32)go->GetDBTableGUIDLow()), mScriptType);
        if (e.empty())
            e = sSmartScriptMgr->GetScript((int32)go->GetEntry(), mScriptType);
        FillScript(e, go, NULL);
    }
    else if (trigger)
    {
        e = sSmartScriptMgr->GetScript((int32)trigger->id, mScriptType);
        FillScript(e, NULL, trigger);
    }
}

void SmartScript::OnInitialize(WorldObject* obj, AreaTriggerEntry const* at)
{
    if (obj)//handle object based scripts
    {
        switch (obj->GetTypeId())
        {
            case TYPEID_UNIT:
                mScriptType = SMART_SCRIPT_TYPE_CREATURE;
                me = obj->ToCreature();
                sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::OnInitialize: source is Creature %u", me->GetEntry());
                break;
            case TYPEID_GAMEOBJECT:
                mScriptType = SMART_SCRIPT_TYPE_GAMEOBJECT;
                go = obj->ToGameObject();
                sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::OnInitialize: source is GameObject %u", go->GetEntry());
                break;
            default:
                sLog->outError("SmartScript::OnInitialize: Unhandled TypeID !WARNING!");
                return;
        }
    } else if (at)
    {
        mScriptType = SMART_SCRIPT_TYPE_AREATRIGGER;
        trigger = at;
        sLog->outDebug(LOG_FILTER_DATABASE_AI, "SmartScript::OnInitialize: source is AreaTrigger %u", trigger->id);
    }
    else
    {
        sLog->outError("SmartScript::OnInitialize: !WARNING! Initialized objects are NULL.");
        return;
    }

    GetScript();//load copy of script

    for (SmartAIEventList::iterator i = mEvents.begin(); i != mEvents.end(); ++i)
        InitTimer((*i));//calculate timers for first time use

    ProcessEventsFor(SMART_EVENT_AI_INIT);
    InstallEvents();
    ProcessEventsFor(SMART_EVENT_JUST_CREATED);
}

void SmartScript::OnMoveInLineOfSight(Unit* who)
{
    ProcessEventsFor(SMART_EVENT_OOC_LOS, who);

    if (!me)
        return;

    if (me->getVictim())
        return;

    ProcessEventsFor(SMART_EVENT_IC_LOS, who);

}

/*
void SmartScript::UpdateAIWhileCharmed(const uint32 diff)
{
}

void SmartScript::DoAction(const int32 param)
{
}

uint32 SmartScript::GetData(uint32 id)
{
    return 0;
}

void SmartScript::SetData(uint32 id, uint32 value)
{
}

void SmartScript::SetGUID(uint64 guid, int32 id)
{
}

uint64 SmartScript::GetGUID(int32 id)
{
    return 0;
}

void SmartScript::MovepointStart(uint32 id)
{
}

void SmartScript::SetRun(bool run)
{
}

void SmartScript::SetMovePathEndAction(SMART_ACTION action)
{
}

uint32 SmartScript::DoChat(int8 id, uint64 whisperGuid)
{
    return 0;
}*/
// SmartScript end

Unit* SmartScript::DoSelectLowestHpFriendly(float range, uint32 MinHPDiff)
{
    if (!me)
        return NULL;

    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Unit* unit = NULL;

    Trinity::MostHPMissingInRange u_check(me, range, MinHPDiff);
    Trinity::UnitLastSearcher<Trinity::MostHPMissingInRange> searcher(me, unit, u_check);

    TypeContainerVisitor<Trinity::UnitLastSearcher<Trinity::MostHPMissingInRange>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, range);
    return unit;
}

void SmartScript::DoFindFriendlyCC(std::list<Creature*>& _list, float range)
{
    if (!me)
        return;

    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Trinity::FriendlyCCedInRange u_check(me, range);
    Trinity::CreatureListSearcher<Trinity::FriendlyCCedInRange> searcher(me, _list, u_check);

    TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::FriendlyCCedInRange>, GridTypeMapContainer >  grid_creature_searcher(searcher);

    cell.Visit(p, grid_creature_searcher, *me->GetMap(), *me, range);
}

void SmartScript::DoFindFriendlyMissingBuff(std::list<Creature*>& list, float range, uint32 spellid)
{
    if (!me)
        return;

    CellCoord p(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.SetNoCreate();

    Trinity::FriendlyMissingBuffInRange u_check(me, range, spellid);
    Trinity::CreatureListSearcher<Trinity::FriendlyMissingBuffInRange> searcher(me, list, u_check);

    TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::FriendlyMissingBuffInRange>, GridTypeMapContainer >  grid_creature_searcher(searcher);

    cell.Visit(p, grid_creature_searcher, *me->GetMap(), *me, range);
}

void SmartScript::SetScript9(SmartScriptHolder& e, uint32 entry)
{
    mTimedActionList.clear();
    mTimedActionList = sSmartScriptMgr->GetScript(entry, SMART_SCRIPT_TYPE_TIMED_ACTIONLIST);
    if (mTimedActionList.empty())
        return;
    for (SmartAIEventList::iterator i = mTimedActionList.begin(); i != mTimedActionList.end(); ++i)
    {
        if (i == mTimedActionList.begin())
        {
            i->enableTimed = true;//enable processing only for the first action
        }
        else i->enableTimed = false;

        if (e.action.timedActionList.timerType == 1)
            i->event.type = SMART_EVENT_UPDATE_IC;
        else if (e.action.timedActionList.timerType > 1)
            i->event.type = SMART_EVENT_UPDATE;
        InitTimer((*i));
    }
}

Unit* SmartScript::GetLastInvoker()
{
    return ObjectAccessor::FindUnit(mLastInvoker);
}
