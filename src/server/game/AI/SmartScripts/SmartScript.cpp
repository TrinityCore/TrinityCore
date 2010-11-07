/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "SQLStorage.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
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

SmartScript::SmartScript()
{
    go = NULL;
    me = NULL;
    mEventPhase = 0;
    mInvinceabilityHpLevel = 0;
    mPathId = 0;
    mTargetStorage = new ObjectListMap();
    mStoredEvents.clear();
    mTextTimer = 0;
    mLastTextID = 0;
    mTextGUID = 0;
    mUseTextTimer = false;
    talker = NULL;
    mTemplate = SMARTAI_TEMPLATE_BASIC;
    meOrigGUID = 0;
    goOrigGUID = 0;
    mResumeActionList = true;
    mLastInvoker = NULL;
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
    mLastInvoker = NULL;
}

void SmartScript::ProcessEventsFor(SMART_EVENT e, Unit* unit, uint32 var0, uint32 var1, bool bvar, const SpellEntry* spell, GameObject* gob)
{
    if (e == SMART_EVENT_AGGRO)
    {
        if (!mResumeActionList)
            mTimedActionList.clear();//clear action list if it is not resumable
        else
        {
            for (SmartAIEventList::iterator itr = mTimedActionList.begin(); itr != mTimedActionList.end(); ++itr)
            {
                if (itr->enableTimed)
                {
                    InitTimer((*itr));//re-init the currently enabled timer, so it restarts the timer when resumed
                    break;
                }
            }
        }
    }
    for (SmartAIEventList::iterator i = mEvents.begin(); i != mEvents.end(); ++i)
    {
        if ((*i).GetEventType() == SMART_EVENT_LINK)//special handling
            continue;
        
        if ((*i).GetEventType() == e/* && (!(*i).event.event_phase_mask || IsInPhase((*i).event.event_phase_mask)) && !((*i).event.event_flags & SMART_EVENT_FLAG_NOT_REPEATABLE && (*i).runOnce)*/)
            ProcessEvent(*i, unit, var0, var1, bvar, spell, gob);
    }
}

void SmartScript::ProcessAction(SmartScriptHolder &e, Unit* unit, uint32 var0, uint32 var1, bool bvar, const SpellEntry* spell, GameObject* gob)
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
        mLastInvoker = unit;

    if (e.link && e.link != e.event_id)
    {
        SmartScriptHolder linked = FindLinkedEvent(e.link);
        if (linked.GetActionType() && linked.GetEventType() == SMART_EVENT_LINK)
        {
            ProcessEvent(linked, unit, var0, var1, bvar, spell, gob);
        }else{
            sLog.outErrorDb("SmartScript::ProcessAction: Entry %d SourceType %u, Event %u, Link Event %u not found or invalid, skipped.", e.entryOrGuid, e.GetScriptType(), e.event_id, e.link);
        }
    }

    switch (e.GetActionType())
    {
        case SMART_ACTION_TALK:
            {
                ObjectList* targets = GetTargets(e, unit);
                talker = me;
                if (targets)
                {
                    for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    {
                        if (IsCreature((*itr)))
                        {
                            talker = (*itr)->ToCreature();
                            break;
                        }
                    }
                }
                mLastTextID = e.action.talk.textGroupID;
                mTextTimer = e.action.talk.duration;
                mTextGUID = IsPlayer(unit)? unit->GetGUID() : NULL;//invoker, used for $vars in texts
                mUseTextTimer = true;
                sCreatureTextMgr.SendChat(talker, uint8(e.action.talk.textGroupID), mTextGUID);
                break;
            }
        case SMART_ACTION_SIMPLE_TALK:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (targets)
                {
                    for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    {
                        if (IsCreature((*itr)))
                        {
                            sCreatureTextMgr.SendChat((*itr)->ToCreature(), uint8(e.action.talk.textGroupID));
                        } else if (IsPlayer((*itr)))
                        {
                            sCreatureTextMgr.SendChat(me, uint8(e.action.talk.textGroupID),NULL,CHAT_TYPE_END,LANG_ADDON,TEXT_RANGE_NORMAL,NULL,TEAM_OTHER,false, (*itr)->ToPlayer());
                        }
                    }
                }
                break;
            }
        case SMART_ACTION_PLAY_EMOTE:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (targets)
                    for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                        if (IsUnit((*itr)))
                            (*itr)->ToUnit()->HandleEmoteCommand(e.action.emote.emote);
                break;
            }
        case SMART_ACTION_SOUND:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (targets)
                    for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                        if (IsCreature((*itr)))
                            sCreatureTextMgr.SendSound((*itr)->ToCreature(), e.action.sound.sound, CHAT_TYPE_SAY, 0, TextRange(e.action.sound.range), Team(NULL), false);
                break;
            }
        case SMART_ACTION_SET_FACTION:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (targets)
            {
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if (IsCreature((*itr)))
                    {
                        if (e.action.faction.factionID)
                            (*itr)->ToCreature()->setFaction(e.action.faction.factionID);
                        else
                        {
                            if (CreatureInfo const* ci = GetCreatureTemplateStore((*itr)->ToCreature()->GetEntry()))
                            {
                                if ((*itr)->ToCreature()->getFaction() != ci->faction_A)
                                    (*itr)->ToCreature()->setFaction(ci->faction_A);
                            }
                        }
                    }
                }
            }
            break;
        }
        case SMART_ACTION_MORPH_TO_ENTRY_OR_MODEL:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets) return;
            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
            {
                if (!IsCreature((*itr)))
                    continue;
            
                if (e.action.morphOrMount.creature || e.action.morphOrMount.model)
                {
                    //set model based on entry from creature_template
                    if (e.action.morphOrMount.creature)
                    {
                        if (CreatureInfo const* ci = GetCreatureTemplateStore(e.action.morphOrMount.creature))
                        {
                            uint32 display_id = sObjectMgr.ChooseDisplayId(0, ci);
                            (*itr)->ToCreature()->SetDisplayId(display_id);
                        }
                    }
                    //if no param1, then use value from param2 (modelId)
                    else
                        (*itr)->ToCreature()->SetDisplayId(e.action.morphOrMount.model);
                }
                else
                    (*itr)->ToCreature()->DeMorph();
            }
            break;
        }
        case SMART_ACTION_FAIL_QUEST:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets) return;
            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
            {
                if (IsPlayer((*itr)))
                    (*itr)->ToPlayer()->FailQuest(e.action.quest.quest);
            }
            break;
        }
        case SMART_ACTION_ADD_QUEST:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets) return;
            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
            {
                if (IsPlayer((*itr)))
                    if (const Quest* q = sObjectMgr.GetQuestTemplate(e.action.quest.quest))
                        (*itr)->ToPlayer()->AddQuest(q, NULL);
            }
            break;
        }
        case SMART_ACTION_SET_REACT_STATE:
        {
            if (!me) return;
            me->SetReactState(ReactStates(e.action.react.state));
            break;
        }
        case SMART_ACTION_RANDOM_EMOTE:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
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
                        count++;
                    }
                }
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsUnit((*itr)))
                        (*itr)->ToUnit()->HandleEmoteCommand(temp[urand(0, count)]);
                break;
            }
        case SMART_ACTION_THREAT_ALL_PCT:
        {
            if (!me) return;
            std::list<HostileReference*>& threatList = me->getThreatManager().getThreatList();
            for (std::list<HostileReference*>::iterator i = threatList.begin(); i != threatList.end(); ++i)
                if (Unit* Temp = Unit::GetUnit(*me,(*i)->getUnitGuid()))
                    me->getThreatManager().modifyThreatPercent(Temp, e.action.threatPCT.threatINC ? (int32)e.action.threatPCT.threatINC : -(int32)e.action.threatPCT.threatDEC);
            break;
        }
        case SMART_ACTION_THREAT_SINGLE_PCT:
        {
            if (!me) return;
            ObjectList* targets = GetTargets(e, unit);
            if (!targets) return;
            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                if (IsUnit((*itr)))
                    me->getThreatManager().modifyThreatPercent((*itr)->ToUnit(), e.action.threatPCT.threatINC ? (int32)e.action.threatPCT.threatINC : -(int32)e.action.threatPCT.threatDEC);
            break;
        }
        case SMART_ACTION_CALL_AREAEXPLOREDOREVENTHAPPENS:
            {
                //if (!me) return;
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsPlayer((*itr)))
                        (*itr)->ToPlayer()->AreaExploredOrEventHappens(e.action.quest.quest);
                break;
            }
        case SMART_ACTION_SEND_CASTCREATUREORGO:
            {
                if (!GetBaseObject()) return;
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsPlayer((*itr)))
                        (*itr)->ToPlayer()->CastedCreatureOrGO(e.action.castedCreatureOrGO.creature, GetBaseObject()->GetGUID(), e.action.castedCreatureOrGO.spell);
                break;
            }
        case SMART_ACTION_CAST:
            {
                if (!me) return;
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsUnit((*itr)))
                    {
                        if (e.action.cast.flags & SMARTCAST_INTERRUPT_PREVIOUS)
                            me->InterruptNonMeleeSpells(false);
                        me->CastSpell((*itr)->ToUnit(), e.action.cast.spell,(e.action.cast.flags & SMARTCAST_TRIGGERED) ? true : false);
                    }
                break;
            }
        case SMART_ACTION_INVOKER_CAST:
            {
                if (!mLastInvoker) return;
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsUnit((*itr)))
                    {
                        if (e.action.cast.flags & SMARTCAST_INTERRUPT_PREVIOUS)
                            mLastInvoker->InterruptNonMeleeSpells(false);
                        mLastInvoker->CastSpell((*itr)->ToUnit(), e.action.cast.spell,(e.action.cast.flags & SMARTCAST_TRIGGERED) ? true : false);
                    }
                break;
            }
        case SMART_ACTION_ADD_AURA:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsUnit((*itr)))
                    {
                        (*itr)->ToUnit()->AddAura(e.action.cast.spell, (*itr)->ToUnit());
                    }
                break;
            }
        case SMART_ACTION_ACTIVATE_GOBJECT:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsGameObject((*itr)))
                    {
                        // Activate
                        (*itr)->ToGameObject()->SetLootState(GO_READY);
                        (*itr)->ToGameObject()->UseDoorOrButton();
                    }
                break;
            }
        case SMART_ACTION_RESET_GOBJECT:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsGameObject((*itr)))
                        (*itr)->ToGameObject()->ResetDoorOrButton();
                break;
            }
        case SMART_ACTION_SET_EMOTE_STATE:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsUnit((*itr)))
                        (*itr)->ToUnit()->SetUInt32Value(UNIT_NPC_EMOTESTATE, e.action.emote.emote);
                break;
            }
        case SMART_ACTION_SET_UNIT_FLAG:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsUnit((*itr)))
                        (*itr)->ToUnit()->SetFlag(UNIT_FIELD_FLAGS, e.action.unitFlag.flag);
                break;
            }
        case SMART_ACTION_REMOVE_UNIT_FLAG:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsUnit((*itr)))
                        (*itr)->ToUnit()->RemoveFlag(UNIT_FIELD_FLAGS, e.action.unitFlag.flag);
                break;
            }
        case SMART_ACTION_AUTO_ATTACK:
            {
                if (!IsSmart()) return;
                CAST_AI(SmartAI, me->AI())->SetAutoAttack(e.action.autoAttack.attack ? true : false);
                break;
            }
        case SMART_ACTION_ALLOW_COMBAT_MOVEMENT:
            {
                if (!IsSmart()) return;
                bool move = e.action.combatMove.move ? true : false;
                CAST_AI(SmartAI, me->AI())->SetCombatMove(move);
                break;
            }
        case SMART_ACTION_SET_EVENT_PHASE:
            {
                SetPhase(e.action.setEventPhase.phase);
                break;
            }
        case SMART_ACTION_INC_EVENT_PHASE:
            {
                IncPhase(e.action.incEventPhase.inc);
                DecPhase(e.action.incEventPhase.dec);
                break;
            }
        case SMART_ACTION_EVADE:
            {
                if (me) me->AI()->EnterEvadeMode();
                return;
            }
        case SMART_ACTION_FLEE_FOR_ASSIST:
            {
                if (me) me->DoFleeToGetAssistance();
                break;
            }
        case SMART_ACTION_CALL_GROUPEVENTHAPPENS:
            {
                if (IsPlayer(unit) && GetBaseObject())
                    unit->ToPlayer()->GroupEventHappens(e.action.quest.quest, GetBaseObject());
                break;
            }
        case SMART_ACTION_CALL_CASTEDCREATUREORGO:
            {
                if (!me) return;
                std::list<HostileReference*>& threatList = me->getThreatManager().getThreatList();
                for (std::list<HostileReference*>::iterator i = threatList.begin(); i != threatList.end(); ++i)
                    if (Unit* Temp = Unit::GetUnit(*me,(*i)->getUnitGuid()))
                        if (IsPlayer(Temp))
                            Temp->ToPlayer()->CastedCreatureOrGO(e.action.castedCreatureOrGO.creature, me->GetGUID(), e.action.castedCreatureOrGO.spell);
                break;
            }
        case SMART_ACTION_REMOVEAURASFROMSPELL:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if(!IsUnit((*itr))) continue;
                    (*itr)->ToUnit()->RemoveAurasDueToSpell(e.action.removeAura.spell);
                }
                break;
            }
        case SMART_ACTION_FOLLOW:
            {
                if (!IsSmart()) return;
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if (IsUnit((*itr)))
                    {
                        CAST_AI(SmartAI, me->AI())->SetFollow((*itr)->ToUnit(), (float)e.action.follow.dist, (float)e.action.follow.angle, e.action.follow.credit, e.action.follow.entry, e.action.follow.creditType);
                        return;
                    }
                }
                break;
            }
        case SMART_ACTION_RANDOM_PHASE:
            {
                uint32 phases[SMART_ACTION_PARAM_COUNT];
                phases[0] = e.action.randomEmote.emote1;
                phases[1] = e.action.randomEmote.emote2;
                phases[2] = e.action.randomEmote.emote3;
                phases[3] = e.action.randomEmote.emote4;
                phases[4] = e.action.randomEmote.emote5;
                phases[5] = e.action.randomEmote.emote6;
                uint32 temp[SMART_ACTION_PARAM_COUNT];
                uint32 count = 0;
                for (uint8 i = 0; i < SMART_ACTION_PARAM_COUNT; i++)
                {
                    if (phases[i] > 0)
                    {
                        temp[count] = phases[i];
                        count++;
                    }
                }
                SetPhase(temp[urand(0, count)]);
                break;
            }
        case SMART_ACTION_RANDOM_PHASE_RANGE:
            {
                SetPhase(urand(e.action.randomPhaseRange.phaseMin, e.action.randomPhaseRange.phaseMax));
                break;
            }
        case SMART_ACTION_CALL_KILLEDMONSTER:
            {
                Player* pPlayer = NULL;
                if (me)
                    pPlayer = me->GetLootRecipient();
                if (me && pPlayer)
                    pPlayer->RewardPlayerAndGroupAtEvent(e.action.killedMonster.creature, pPlayer);
                else if (GetBaseObject()) 
                {
                    ObjectList* targets = GetTargets(e, unit);
                    if (!targets) return;
                    for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    {
                        if(!IsPlayer((*itr))) continue;
                        (*itr)->ToPlayer()->RewardPlayerAndGroupAtEvent(e.action.killedMonster.creature, (*itr)->ToPlayer());
                    }
                }else if (trigger && IsPlayer(unit))
                {
                    unit->ToPlayer()->RewardPlayerAndGroupAtEvent(e.action.killedMonster.creature, unit);
                }
                break;
            }
        case SMART_ACTION_SET_INST_DATA:
            {
                WorldObject* obj = GetBaseObject();
                if (!obj)
                    obj = unit;
                if (obj) return;
                InstanceScript* pInst = (InstanceScript*)obj->GetInstanceScript();
                if (!pInst)
                {
                    sLog.outErrorDb("SmartScript: Event %u attempt to set instance data without instance script. EntryOrGuid %d", e.GetEventType(), e.entryOrGuid);
                    return;
                }
                pInst->SetData(e.action.setInstanceData.field, e.action.setInstanceData.data);
                break;
            }
        case SMART_ACTION_SET_INST_DATA64:
            {
                WorldObject* obj = GetBaseObject();
                if (!obj)
                    obj = unit;
                if (obj) return;
                InstanceScript* pInst = (InstanceScript*)obj->GetInstanceScript();
                if (!pInst)
                {
                    sLog.outErrorDb("SmartScript: Event %u attempt to set instance data without instance script. EntryOrGuid %d", e.GetEventType(), e.entryOrGuid);
                    return;
                }
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    pInst->SetData64(e.action.setInstanceData64.field, (*itr)->GetGUID());
                    return;
                }
                
                break;
            }
        case SMART_ACTION_UPDATE_TEMPLATE:
            {
                if (!me || me->GetEntry() == e.action.updateTemplate.creature)
                    return;
                me->UpdateEntry(e.action.updateTemplate.creature, e.action.updateTemplate.team ? HORDE : ALLIANCE);
                break;
            }
        case SMART_ACTION_DIE:
            {
                if (me && !me->isDead())
                    me->Kill(me);
                break;
            }
        case SMART_ACTION_SET_IN_COMBAT_WITH_ZONE:
            {
                if (me)
                    me->SetInCombatWithZone();
                break;
            }
        case SMART_ACTION_CALL_FOR_HELP:
            {
                if (me)
                    me->CallForHelp((float)e.action.callHelp.range);
                break;
            }
        case SMART_ACTION_SET_SHEATH:
            {
                if (me)
                    me->SetSheath(SheathState(e.action.setSheath.sheath));
                break;
            }
        case SMART_ACTION_FORCE_DESPAWN:
            {
                if (!IsSmart()) return;
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
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if(!IsUnit((*itr))) continue;
                    if (e.action.morphOrMount.creature || e.action.morphOrMount.model)
                    {
                        if (e.action.morphOrMount.creature > 0)
                        {
                            if (CreatureInfo const* cInfo = GetCreatureTemplateStore(e.action.morphOrMount.creature))
                            {
                                uint32 display_id = sObjectMgr.ChooseDisplayId(0, cInfo);
                                (*itr)->ToUnit()->Mount(display_id);
                            }
                        }
                        else
                            (*itr)->ToUnit()->Mount(e.action.morphOrMount.model);
                    }
                    else
                        (*itr)->ToUnit()->Unmount();
                }
                break;
            }
        case SMART_ACTION_SET_INVINCIBILITY_HP_LEVEL:
            {
                if (!GetBaseObject()) return;
                if (e.action.invincHP.minHP)
                    mInvinceabilityHpLevel = me->CountPctFromMaxHealth(e.action.invincHP.minHP);
                else
                    mInvinceabilityHpLevel = e.action.invincHP.minHP;
                break;
            }
        case SMART_ACTION_SET_DATA:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if (IsCreature((*itr)))
                        (*itr)->ToCreature()->AI()->SetData(e.action.setData.field, e.action.setData.data);
                    if (IsGameObject((*itr)))
                        (*itr)->ToGameObject()->AI()->SetData(e.action.setData.field, e.action.setData.data);
                    return;
                }
                break;
            }
        case SMART_ACTION_MOVE_FORWARD:
            {
                if (!me) return;
                float x,y,z;
                me->GetClosePoint(x, y, z, me->GetObjectSize() / 3, (float)e.action.moveRandom.distance);
                me->GetMotionMaster()->MovePoint(SMART_RANDOM_POINT,x,y,z);
                break;
            }
        case SMART_ACTION_SET_VISIBILITY:
            {
                if (me)
                    me->SetVisibility(e.action.visibility.state ? VISIBILITY_ON : VISIBILITY_OFF);
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
                if (!me) return;
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if (IsUnit((*itr)))
                        me->AI()->AttackStart((*itr)->ToUnit());
                    return;
                }
                break;
            }
        case SMART_ACTION_SUMMON_CREATURE:
            {
                WorldObject* obj = GetBaseObject();
                if (!obj)
                    obj = unit;
                float x,y,z,o;;
                ObjectList* targets = GetTargets(e, unit);
                if (targets)
                {
                    for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    {
                        if(!IsUnit((*itr))) continue;
                        (*itr)->GetPosition(x,y,z,o);
                        if (Creature* summon = GetBaseObject()->SummonCreature(e.action.summonCreature.creature, x, y, z, o, (TempSummonType)e.action.summonCreature.type, e.action.summonCreature.duration))
                        {
                            if (unit && e.action.summonCreature.attackInvoker)
                            {
                                summon->AI()->AttackStart((*itr)->ToUnit());
                            }
                        }
                    }
                }
                if (e.GetTargetType() != SMART_TARGET_POSITION)
                    return;
                if (Creature* summon = GetBaseObject()->SummonCreature(e.action.summonCreature.creature, e.target.x, e.target.y, e.target.z, e.target.o, (TempSummonType)e.action.summonCreature.type, e.action.summonCreature.duration))
                {
                    if (unit && e.action.summonCreature.attackInvoker)
                        summon->AI()->AttackStart(unit);
                }
                break;
            }
        case SMART_ACTION_SUMMON_GO:
            {
                if (!GetBaseObject()) return;
                float x,y,z,o;
                ObjectList* targets = GetTargets(e, unit);
                if (targets)
                {
                    for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    {
                        if(!IsUnit((*itr))) continue;
                        (*itr)->GetPosition(x,y,z,o);
                        GetBaseObject()->SummonGameObject(e.action.summonGO.entry, x, y, z, o, 0, 0, 0, 0, e.action.summonGO.despawnTime);
                    }
                }
                if (e.GetTargetType() != SMART_TARGET_POSITION)
                    return;
                GetBaseObject()->SummonGameObject(e.action.summonGO.entry, e.target.x, e.target.y, e.target.z, e.target.o, 0, 0, 0, 0, e.action.summonGO.despawnTime);
                break;
            }
        case SMART_ACTION_KILL_UNIT:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if(!IsUnit((*itr))) continue;
                    (*itr)->ToUnit()->Kill((*itr)->ToUnit());
                }
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
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if(!IsPlayer((*itr))) continue;
                    (*itr)->ToPlayer()->AddItem(e.action.item.entry, e.action.item.count);
                }
                break;
            }
        case SMART_ACTION_REMOVE_ITEM:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if(!IsPlayer((*itr))) continue;
                    (*itr)->ToPlayer()->DestroyItemCount(e.action.item.entry, e.action.item.count, true);
                }
                break;
            }
        case SMART_ACTION_STORE_VARIABLE_DECIMAL:
            {
                if(mStoredDecimals.find(e.action.storeVar.id) != mStoredDecimals.end())
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
                if (!targets) return;
                uint32 map = e.action.teleport.mapID;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if(!IsPlayer((*itr))) continue;
                    (*itr)->ToPlayer()->TeleportTo(e.action.teleport.mapID, e.target.x, e.target.y, e.target.z, e.target.o);
                }
                break;
            }
        case SMART_ACTION_SET_FLY:
            {
                if (!IsSmart()) return;
                CAST_AI(SmartAI, me->AI())->SetFly(e.action.setFly.fly ? true : false);
                break;
            }
        case SMART_ACTION_SET_RUN:
            {
                if (!IsSmart()) return;
                CAST_AI(SmartAI, me->AI())->SetRun(e.action.setRun.run ? true : false);
                break;
            }
        
        case SMART_ACTION_SET_SWIMM:
            {
                if (!IsSmart()) return;
                CAST_AI(SmartAI, me->AI())->SetSwimm(e.action.setSwimm.swimm ? true : false);
                break;
            }
        case SMART_ACTION_WP_LOAD:
            {
                if (!me) return;
                uint32 entry = e.action.wpLoad.id;
                break;
            }
        case SMART_ACTION_WP_START:
            {
                if (!IsSmart()) return;
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
                if (!IsSmart()) return;
                uint32 delay = e.action.wpPause.delay;
                CAST_AI(SmartAI, me->AI())->PausePath(delay, e.GetEventType() == SMART_EVENT_WAYPOINT_REACHED ? false : true);
                break;
            }
        case SMART_ACTION_WP_STOP:
            {
                if (!IsSmart()) return;
                uint32 DespawnTime = e.action.wpStop.despawnTime;
                uint32 quest = e.action.wpStop.quest;
                bool fail = e.action.wpStop.fail ? true : false;
                CAST_AI(SmartAI, me->AI())->StopPath(DespawnTime, quest, fail);
                break;
            }
        case SMART_ACTION_WP_RESUME:
            {
                if (!IsSmart()) return;
                CAST_AI(SmartAI, me->AI())->ResumePath();
                break;
            }
        case SMART_ACTION_SET_ORIENTATION:
            {
                if (!me) return;
                ObjectList* targets = GetTargets(e, unit);
                if (e.GetTargetType() == SMART_TARGET_SELF)
                    me->SetFacing(me->GetCreatureData()->orientation, NULL);
                else if (e.GetTargetType() == SMART_TARGET_POSITION)
                    me->SetFacing(e.target.o, NULL);
                else if (targets && !targets->empty())
                    me->SetFacing(0, (*targets->begin()));
                break;
            }
        case SMART_ACTION_PLAYMOVIE:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if(!IsPlayer((*itr))) continue;
                    (*itr)->ToPlayer()->SendMovieStart(e.action.movie.entry);
                }

                break;
            }
        case SMART_ACTION_MOVE_TO_POS:
            {
                if (!IsSmart()) return;
                bool run = e.action.setRun.run ? true : false;
                CAST_AI(SmartAI, me->AI())->SetRun(run);
                me->GetMotionMaster()->MovePoint(0, e.target.x, e.target.y , e.target.z);
                break;
            }
        case SMART_ACTION_RESPAWN_TARGET:
        {
            ObjectList* targets = GetTargets(e, unit);
            if (!targets) return;
            for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
            {
                if(IsCreature((*itr)))
                    (*itr)->ToCreature()->Respawn();
                if(IsGameObject((*itr)))
                    (*itr)->ToGameObject()->Respawn();
            }
            break;
        }
        case SMART_ACTION_CLOSE_GOSSIP:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if(IsPlayer((*itr)))
                        (*itr)->ToPlayer()->PlayerTalkClass->CloseGossip();
                }
                break;
            }
        case SMART_ACTION_EQUIP:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if(Creature* npc = (*itr)->ToCreature())
                    {
                        uint32 slot[3];
                        if (e.action.equip.entry)
                        {
                            EquipmentInfo const *einfo = sObjectMgr.GetEquipmentInfo(e.action.equip.entry);
                            if (!einfo)
                            {
                                sLog.outErrorDb("SmartScript: SMART_ACTION_EQUIP uses non-existent equipment info entry %u", e.action.equip.entry);
                                return;
                            }
                            npc->SetCurrentEquipmentId(e.action.equip.entry);
                            slot[0] = einfo->equipentry[0];
                            slot[1] = einfo->equipentry[1];
                            slot[2] = einfo->equipentry[2];
                        }
                        else
                        {
                            slot[0] = e.action.equip.slot1;
                            slot[1] = e.action.equip.slot2;
                            slot[2] = e.action.equip.slot3;
                        }
                        if (!e.action.equip.mask || e.action.equip.mask & 1)
                            npc->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, e.action.equip.slot1);
                        if (!e.action.equip.mask || e.action.equip.mask & 2)
                            npc->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, e.action.equip.slot2);
                        if (!e.action.equip.mask || e.action.equip.mask & 4)
                            npc->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, e.action.equip.slot3);
                    }
                }
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
            {
                ProcessEventsFor((SMART_EVENT)SMART_EVENT_TIMED_EVENT_TRIGGERED, NULL, e.action.timeEvent.id);
                break;
            }
        case SMART_ACTION_REMOVE_TIMED_EVENT:
            {
                mRemIDs.push_back(e.action.timeEvent.id);
                break;
            }
        case SMART_ACTION_OVERRIDE_SCRIPT_BASE_OBJECT:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if (IsCreature(*itr))
                    {
                        if (!meOrigGUID)
                            meOrigGUID = me?me->GetGUID():0;
                        if (!goOrigGUID)
                            goOrigGUID = go?go->GetGUID():0;
                        go = NULL;
                        me = (*itr)->ToCreature();
                        return;
                    }else if (IsGameObject((*itr)))
                    {
                        if (!meOrigGUID)
                            meOrigGUID = me?me->GetGUID():0;
                        if (!goOrigGUID)
                            goOrigGUID = go?go->GetGUID():0;
                        go = (*itr)->ToGameObject();
                        me = NULL;
                        return;
                    }
                }
                break;
            }
        case SMART_ACTION_RESET_SCRIPT_BASE_OBJECT:
            ResetBaseObject();
            break;
        case SMART_ACTION_CALL_SCRIPT_RESET:
            OnReset();
            break;
        case SMART_ACTION_ENTER_VEHICLE:
            {
                if (!me) return;
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::iterator itr = targets->begin(); itr != targets->end(); itr++)
                {
                    if (IsUnit(*itr) && (*itr)->ToUnit()->GetVehicleKit())
                    {
                        me->EnterVehicle((*itr)->ToUnit()->GetVehicleKit(), e.action.enterVehicle.seat);
                        return;
                    }
                }
                break;
            }
        case SMART_ACTION_CALL_TIMED_ACTIONLIST:
            {
                mTimedActionList.clear();
                mTimedActionList = sSmartScriptMgr.GetScript(e.action.timedActionList.id, SMART_SCRIPT_TYPE_TIMED_ACTIONLIST);
                if (mTimedActionList.empty())
                    return;
                for (SmartAIEventList::iterator i = mTimedActionList.begin(); i != mTimedActionList.end(); ++i)
                {
                    if (i == mTimedActionList.begin())
                    {
                        i->enableTimed = true;//enable processing only for the first action
                    }
                    else i->enableTimed = false;
                    
                    //i->event.type = SMART_EVENT_UPDATE_IC;//default value
                    if (e.action.timedActionList.timerType == 1)
                        i->event.type = SMART_EVENT_UPDATE_IC;
                    else if (e.action.timedActionList.timerType > 1)
                        i->event.type = SMART_EVENT_UPDATE;
                    mResumeActionList = e.action.timedActionList.dontResume ? false : true;
                    InitTimer((*i));
                }
                break;
            }
        case SMART_ACTION_SET_NPC_FLAG:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsUnit((*itr)))
                        (*itr)->ToUnit()->SetUInt32Value(UNIT_NPC_FLAGS, e.action.unitFlag.flag);
                break;
            }
        case SMART_ACTION_ADD_NPC_FLAG:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsUnit((*itr)))
                        (*itr)->ToUnit()->SetFlag(UNIT_NPC_FLAGS, e.action.unitFlag.flag);
                break;
            }
        case SMART_ACTION_REMOVE_NPC_FLAG:
            {
                ObjectList* targets = GetTargets(e, unit);
                if (!targets) return;
                for (ObjectList::const_iterator itr = targets->begin(); itr != targets->end(); itr++)
                    if (IsUnit((*itr)))
                        (*itr)->ToUnit()->RemoveFlag(UNIT_NPC_FLAGS, e.action.unitFlag.flag);
                break;
            }
        default:
            sLog.outErrorDb("SmartScript::ProcessAction: Unhandled Action type %u", e.GetActionType());
            break;
    }
}

void SmartScript::InstallTemplate(SmartScriptHolder e)
{
    if (!GetBaseObject())
        return;
    if (mTemplate)
    {
        sLog.outErrorDb("SmartScript::InstallTemplate: Entry %d SourceType %u AI Template can not be set more then once, skipped.", e.entryOrGuid, e.GetScriptType());
        return;
    }
    mTemplate = (SMARTAI_TEMPLATE)e.action.installTtemplate.id;
    switch ((SMARTAI_TEMPLATE)e.action.installTtemplate.id)
    {
        case SMARTAI_TEMPLATE_CASTER:
            {
                AddEvent(SMART_EVENT_UPDATE_IC,0, 0,0,e.action.installTtemplate.param2,e.action.installTtemplate.param3,SMART_ACTION_CAST,e.action.installTtemplate.param1,e.target.raw.param1,0,0,0,0,SMART_TARGET_VICTIM,0,0,0,1);
                AddEvent(SMART_EVENT_RANGE,0, e.action.installTtemplate.param4,300,0,0,SMART_ACTION_ALLOW_COMBAT_MOVEMENT,1,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,1);
                AddEvent(SMART_EVENT_RANGE,0, 0,e.action.installTtemplate.param4>10?e.action.installTtemplate.param4-10:0,0,0,SMART_ACTION_ALLOW_COMBAT_MOVEMENT,0,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,1);
                AddEvent(SMART_EVENT_MANA_PCT,0,e.action.installTtemplate.param5-15>100?100:e.action.installTtemplate.param5+15,100,1000,1000,SMART_ACTION_SET_EVENT_PHASE,1,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,0);
                AddEvent(SMART_EVENT_MANA_PCT,0,0,e.action.installTtemplate.param5,1000,1000,SMART_ACTION_SET_EVENT_PHASE,0,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,0);
                AddEvent(SMART_EVENT_MANA_PCT,0,0,e.action.installTtemplate.param5,1000,1000,SMART_ACTION_ALLOW_COMBAT_MOVEMENT,1,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,0);
                break;
            }
        case SMARTAI_TEMPLATE_TURRET:
            {
                AddEvent(SMART_EVENT_UPDATE_IC,0, 0,0,e.action.installTtemplate.param2,e.action.installTtemplate.param3,SMART_ACTION_CAST,e.action.installTtemplate.param1,e.target.raw.param1,0,0,0,0,SMART_TARGET_VICTIM,0,0,0,0);
                AddEvent(SMART_EVENT_JUST_CREATED,0, 0,0,0,0,SMART_ACTION_ALLOW_COMBAT_MOVEMENT,0,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,0);
                break;
            }
        case SMARTAI_TEMPLATE_CAGED_NPC_PART:
            {
                if (!me) return;
                //store cage as id1
                AddEvent(SMART_EVENT_DATA_SET,0,0,0,0,0,SMART_ACTION_STORE_TARGET_LIST,1,0,0,0,0,0,SMART_TARGET_CLOSEST_GAMEOBJECT,e.action.installTtemplate.param1,10,0,0);

                 //reset(close) cage on hostage(me) respawn
                AddEvent(SMART_EVENT_UPDATE,SMART_EVENT_FLAG_NOT_REPEATABLE,0,0,0,0,SMART_ACTION_RESET_GOBJECT,0,0,0,0,0,0,SMART_TARGET_GAMEOBJECT_DISTANCE,e.action.installTtemplate.param1,5,0,0);
                
                AddEvent(SMART_EVENT_DATA_SET,0,0,0,0,0,SMART_ACTION_SET_RUN,e.action.installTtemplate.param3,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,0);
                AddEvent(SMART_EVENT_DATA_SET,0,0,0,0,0,SMART_ACTION_SET_EVENT_PHASE,1,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,0);

                AddEvent(SMART_EVENT_UPDATE,SMART_EVENT_FLAG_NOT_REPEATABLE,1000,1000,0,0,SMART_ACTION_MOVE_FORWARD,e.action.installTtemplate.param4,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,1);
                 //phase 1: give quest credit on movepoint reached
                AddEvent(SMART_EVENT_MOVEMENTINFORM,0, POINT_MOTION_TYPE,SMART_RANDOM_POINT,0,0,SMART_ACTION_SET_DATA,0,0,0,0,0,0,SMART_TARGET_STORED,1,0,0,1);
                //phase 1: despawn after time on movepoint reached
                AddEvent(SMART_EVENT_MOVEMENTINFORM,0, POINT_MOTION_TYPE,SMART_RANDOM_POINT,0,0,SMART_ACTION_FORCE_DESPAWN,e.action.installTtemplate.param2,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,1);

                if (sCreatureTextMgr.TextExist(me->GetEntry(), (uint8)e.action.installTtemplate.param5))
                    AddEvent(SMART_EVENT_MOVEMENTINFORM,0, POINT_MOTION_TYPE,SMART_RANDOM_POINT,0,0,SMART_ACTION_TALK,e.action.installTtemplate.param5,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,1);
                break;
            }
        case SMARTAI_TEMPLATE_CAGED_GO_PART:
            {
                if (!go) return;
                //store hostage as id1
                AddEvent(SMART_EVENT_GOSSIP_HELLO,0,0,0,0,0,SMART_ACTION_STORE_TARGET_LIST,1,0,0,0,0,0,SMART_TARGET_CLOSEST_CREATURE,e.action.installTtemplate.param1,10,0,0);
                //store invoker as id2
                AddEvent(SMART_EVENT_GOSSIP_HELLO,0,0,0,0,0,SMART_ACTION_STORE_TARGET_LIST,2,0,0,0,0,0,SMART_TARGET_NONE,0,0,0,0);
                //signal hostage
                AddEvent(SMART_EVENT_GOSSIP_HELLO,0,0,0,0,0,SMART_ACTION_SET_DATA,0,0,0,0,0,0,SMART_TARGET_STORED,1,0,0,0);
                //when hostage raeched end point, give credit to invoker
                if (e.action.installTtemplate.param2)
                    AddEvent(SMART_EVENT_DATA_SET,0,0,0,0,0,SMART_ACTION_CALL_KILLEDMONSTER,e.action.installTtemplate.param1,0,0,0,0,0,SMART_TARGET_STORED,2,0,0,0);
                else
                    AddEvent(SMART_EVENT_GOSSIP_HELLO,0,0,0,0,0,SMART_ACTION_CALL_KILLEDMONSTER,e.action.installTtemplate.param1,0,0,0,0,0,SMART_TARGET_STORED,2,0,0,0);
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

ObjectList* SmartScript::GetTargets(SmartScriptHolder e, Unit* invoker)
{
    Unit* trigger = NULL;
    if (invoker)
        trigger = invoker;
    else if (mLastInvoker)
        trigger = mLastInvoker;
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
            if (!me) return NULL;
            if(Unit* u = me->AI()->SelectTarget(SELECT_TARGET_TOPAGGRO, 1))
                l->push_back(u);
            break;
        case SMART_TARGET_HOSTILE_LAST_AGGRO:
            if (!me) return NULL;
            if(Unit* u = me->AI()->SelectTarget(SELECT_TARGET_BOTTOMAGGRO, 0))
                l->push_back(u);
            break;
        case SMART_TARGET_HOSTILE_RANDOM:
            if (!me) return NULL;
            if(Unit* u = me->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0))
                l->push_back(u);
            break;
        case SMART_TARGET_HOSTILE_RANDOM_NOT_TOP:
            if (!me) return NULL;
            if(Unit* u = me->AI()->SelectTarget(SELECT_TARGET_RANDOM, 1))
                l->push_back(u);
            break;
        case SMART_TARGET_NONE:
        case SMART_TARGET_ACTION_INVOKER:
            if (trigger)
                l->push_back(trigger);
            break;
        case SMART_TARGET_ACTION_INVOKER_VEHICLE:
            if (trigger && trigger->GetVehicle() && trigger->GetVehicle()->GetBase())
            {
                l->push_back(trigger->GetVehicle()->GetBase());
            }
            break;
        case SMART_TARGET_INVOKER_PARTY:
            if (trigger)
            {
                l->push_back(trigger);
                if (Player* plr = trigger->ToPlayer())
                {
                    if (Group *pGroup = plr->GetGroup())
                    {
                        for (GroupReference *gr = pGroup->GetFirstMember(); gr != NULL; gr = gr->next())
                        {
                            if (Player *pGroupGuy = gr->getSource())
                                l->push_back(pGroupGuy);
                        }
                    }                
                }
            }
            break;
        case SMART_TARGET_CREATURE_RANGE:
            {
                ObjectList* units = GetWorldObjectsInDist((float)e.target.unitRange.maxDist);
                if (!units) return NULL;
                for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); itr++)
                {
                    if(!IsCreature((*itr)))
                        continue;
                    if (me && me == (*itr))
                        continue;
                    if (((e.target.unitRange.creature && (*itr)->ToCreature()->GetEntry() == e.target.unitRange.creature) || !e.target.unitRange.creature) && GetBaseObject()->IsInRange((*itr), (float)e.target.unitRange.minDist, (float)e.target.unitRange.maxDist))
                        l->push_back((*itr));
                }
                break;
            }
        case SMART_TARGET_CREATURE_DISTANCE:
            {
                ObjectList* units = GetWorldObjectsInDist((float)e.target.unitDistance.dist);
                if (!units) return NULL;
                for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); itr++)
                {
                    if(!IsCreature((*itr)))
                        continue;
                    if (me && me == (*itr))
                        continue;
                    if ((e.target.unitDistance.creature && (*itr)->ToCreature()->GetEntry() == e.target.unitDistance.creature) || !e.target.unitDistance.creature)
                    {
                        l->push_back((*itr));
                    }
                }
                break;
            }
        case SMART_TARGET_GAMEOBJECT_DISTANCE:
            {
                ObjectList* units = GetWorldObjectsInDist((float)e.target.goDistance.dist);
                if (!units) return NULL;
                for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); itr++)
                {
                    if(!IsGameObject((*itr)))
                        continue;
                    if (go && go == (*itr))
                        continue;
                    if ((e.target.goDistance.entry && (*itr)->ToGameObject()->GetEntry() == e.target.goDistance.entry) || !e.target.goDistance.entry)
                        l->push_back((*itr));
                }
                break;
            }
        case SMART_TARGET_GAMEOBJECT_RANGE:
            {
                ObjectList* units = GetWorldObjectsInDist((float)e.target.goRange.maxDist);
                if (!units) return NULL;
                for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); itr++)
                {
                    if(!IsGameObject((*itr)))
                        continue;
                    if (go && go == (*itr))
                        continue;
                    if (((e.target.goRange.entry && IsGameObject((*itr)) && (*itr)->ToGameObject()->GetEntry() == e.target.goRange.entry) || !e.target.goRange.entry) && GetBaseObject()->IsInRange((*itr), (float)e.target.goRange.minDist, (float)e.target.goRange.maxDist))
                        l->push_back((*itr));
                }
                break;
            }
        case SMART_TARGET_CREATURE_GUID:
            {
                Creature* target = NULL;
                if (e.target.unitGUID.entry)
                {
                    uint64 guid = MAKE_NEW_GUID(e.target.unitGUID.guid, e.target.unitGUID.entry, HIGHGUID_UNIT);
                    target = HashMapHolder<Creature>::Find(guid);
                } else 
                {
                    if (!trigger && !GetBaseObject())
                    {
                        sLog.outErrorDb("SMART_TARGET_CREATURE_GUID can not be used without invoker and without entry");
                        return NULL;
                    }
                    target = FindCreatureNear(trigger?trigger:GetBaseObject(), e.target.unitGUID.guid);
                }
                if (target)
                {
                    l->push_back(target);
                }
                break;
            }
        case SMART_TARGET_GAMEOBJECT_GUID:
            {
                GameObject* target = NULL;
                if (e.target.unitGUID.entry)
                {
                    uint64 guid = MAKE_NEW_GUID(e.target.goGUID.guid, e.target.goGUID.entry, HIGHGUID_GAMEOBJECT);
                    target = HashMapHolder<GameObject>::Find(guid);
                } else 
                {
                    if (!trigger && !GetBaseObject())
                    {
                        sLog.outErrorDb("SMART_TARGET_GAMEOBJECT_GUID can not be used without invoker and without entry");
                        return NULL;
                    }
                    target = FindGameObjectNear(trigger?trigger:GetBaseObject(), e.target.goGUID.guid);
                }
                if (target)
                {
                    l->push_back(target);
                }
                break;
            }
        case SMART_TARGET_PLAYER_RANGE:
            {
                ObjectList* units = GetWorldObjectsInDist((float)e.target.playerRange.maxDist);
                if (!units || !GetBaseObject()) return NULL;
                for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); itr++)
                {
                    if(IsPlayer((*itr)) && GetBaseObject()->IsInRange((*itr), (float)e.target.playerRange.minDist, (float)e.target.playerRange.maxDist))
                        l->push_back((*itr));
                }
                break;
            }
        case SMART_TARGET_PLAYER_DISTANCE:
            {
                ObjectList* units = GetWorldObjectsInDist((float)e.target.playerDistance.dist);
                if (!units) return NULL;
                for (ObjectList::const_iterator itr = units->begin(); itr != units->end(); itr++)
                {
                    if(IsPlayer((*itr)))
                        l->push_back((*itr));
                }
                break;
            }
        case SMART_TARGET_STORED:
            {
                ObjectListMap::iterator itr = mTargetStorage->find(e.target.stored.id);
                if (itr != mTargetStorage->end())
                    return itr->second;
                return l;
            }
        case SMART_TARGET_CLOSEST_CREATURE:
            {
                Creature* target = GetClosestCreatureWithEntry(GetBaseObject(),e.target.closest.entry, (float)(e.target.closest.dist ? e.target.closest.dist : 100), e.target.closest.dead ? false : true);
                if (target)
                    l->push_back(target);
                break;
            }
        case SMART_TARGET_CLOSEST_GAMEOBJECT:
            {
                GameObject* target = GetClosestGameObjectWithEntry(GetBaseObject(),e.target.closest.entry, (float)(e.target.closest.dist ? e.target.closest.dist : 100));
                if (target)
                    l->push_back(target);
                break;
            }
        case SMART_TARGET_OWNER_OR_SUMMONER:
            {
                if (!me) return NULL;
                uint64 guid = me->GetCharmerOrOwnerGUID();
                if (Unit* owner = ObjectAccessor::GetUnit(*me, guid))
                    l->push_back(owner);
                break;
            }
        case SMART_TARGET_POSITION:
        default:
            return NULL;
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

void SmartScript::ProcessEvent(SmartScriptHolder &e, Unit* unit, uint32 var0, uint32 var1, bool bvar, const SpellEntry* spell, GameObject* gob)
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
            if(me && me->isInCombat())
                return;
            RecalcTimer(e, e.event.minMaxRepeat.repeatMin, e.event.minMaxRepeat.repeatMax);
            ProcessAction(e);
            break;
        case SMART_EVENT_UPDATE_IC:
            if(!me || !me->isInCombat())
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

                if (me->IsInRange(me->getVictim(),(float)e.event.minMaxRepeat.min,(float)e.event.minMaxRepeat.max))
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

            Unit* pUnit = DoSelectLowestHpFriendly((float)e.event.friendlyHealt.radius, e.event.friendlyHealt.hpDeficit);
            if (!pUnit)
                return;
            ProcessAction(e, pUnit);
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
            if (!me) return;
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
            if (!me || !me->getVictim()) return;
            if (!me) return;
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
        case SMART_EVENT_FOLLOW_COPMLETE:
            ProcessAction(e, unit, var0, var1, bvar, spell, gob);
            break;
        case SMART_EVENT_RECEIVE_EMOTE:
            if (e.event.emote.emote == var0)
            {
                ProcessAction(e, unit);
                RecalcTimer(e, e.event.emote.cooldownMin, e.event.emote.cooldownMax);
            }
            break;
        case SMART_EVENT_KILL:
        {
            if (!me || !unit) return;
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
            if (!spell) return;
            if (!e.event.spellHit.spell || spell->Id == e.event.spellHit.spell)
                if (!e.event.spellHit.school || (spell->SchoolMask & e.event.spellHit.school))
                {
                    ProcessAction(e, unit, 0, 0, bvar, spell);
                    RecalcTimer(e, e.event.spellHit.cooldownMin, e.event.spellHit.cooldownMax);
                }
            break;
        }
        case SMART_EVENT_OOC_LOS:
        {
            if (!me || me->isInCombat()) return;
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
            if (!me || !me->isInCombat()) return;
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
            if (!GetBaseObject()) return;
            if (e.event.respawn.type == SMART_SCRIPT_RESPAWN_CONDITION_MAP && GetBaseObject()->GetMapId() != e.event.respawn.map)
                return;
            if (e.event.respawn.type == SMART_SCRIPT_RESPAWN_CONDITION_AREA && GetBaseObject()->GetZoneId() != e.event.respawn.area)
                return;
            ProcessAction(e);
            break;
        }
        case SMART_EVENT_SUMMONED_UNIT:
        {
            if (!IsCreature(unit)) return;
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
            RecalcTimer(e, e.event.minMaxRepeat.repeatMin,e.event.minMaxRepeat.repeatMax);
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
            if (!unit) return;
            ProcessAction(e, unit);
            RecalcTimer(e, e.event.minMax.repeatMin, e.event.minMax.repeatMax);
            break;
        }
        case SMART_EVENT_TIMED_EVENT_TRIGGERED:
            {
                if (e.event.timedEvent.id == var0)
                    ProcessAction(e,unit);
                break;
            }
        case SMART_EVENT_GOSSIP_SELECT:
            {
                sLog.outString("SmartScript: Gossip Select:  menu %u action %u", var0, var1);//little help for scripters
                if (e.event.gossip.sender != var0 || e.event.gossip.action != var1)
                    return;
                ProcessAction(e, unit, var0, var1);
                break;
            }
        default:
            sLog.outErrorDb("SmartScript::ProcessEvent: Unhandled Event type %u", e.GetEventType());
            break;
    }
}

void SmartScript::InitTimer(SmartScriptHolder &e)
{
    switch (e.GetEventType())
    {//set only events which have initial timers
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
void SmartScript::RecalcTimer(SmartScriptHolder &e, uint32 min, uint32 max)
{
    // min/max was checked at loading!
    e.timer = urand(uint32(min), uint32(max));
    e.active = e.timer ? false : true;
}

void SmartScript::UpdateTimer(SmartScriptHolder &e, const uint32 diff)
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
    } else e.timer -= diff;
}

bool SmartScript::CheckTimer(SmartScriptHolder &e)
{
    return e.active;
}

void SmartScript::InstallEvents()
{
    if (!mInstallEvents.empty())
    {
        for (SmartAIEventList::iterator i = mInstallEvents.begin(); i != mInstallEvents.end(); ++i)
        {
            mEvents.push_back((*i));//must be before UpdateTimers
        }
        mInstallEvents.clear();
    }
}

void SmartScript::OnUpdate(const uint32 diff)
{
    if ((mScriptType == SMART_SCRIPT_TYPE_CREATURE || mScriptType == SMART_SCRIPT_TYPE_GAMEOBJECT) && !GetBaseObject())
        return;
    InstallEvents();//before UpdateTimers

    for (SmartAIEventList::iterator i = mEvents.begin(); i != mEvents.end(); ++i)
        UpdateTimer((*i), diff);

    if (!mStoredEvents.empty())
    {
        for (SmartAIEventList::iterator i = mStoredEvents.begin(); i != mStoredEvents.end(); ++i)
        {
             UpdateTimer((*i), diff);
        }
    }
    bool needCleanup = true;
    if (!mTimedActionList.empty())
    {
        for (SmartAIEventList::iterator i = mTimedActionList.begin(); i != mTimedActionList.end(); ++i)
        {
            if ((*i).enableTimed)
            {
                UpdateTimer((*i), diff);
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
            uint32 temp = mLastTextID;
            mLastTextID = 0;
            mTextTimer = 0;
            mUseTextTimer = false;
            uint32 tempEntry = talker?talker->GetEntry():0;
            talker = NULL;
            ProcessEventsFor(SMART_EVENT_TEXT_OVER, NULL, temp, tempEntry);
        } else mTextTimer -= diff;
    }
}

void SmartScript::FillScript(SmartAIEventList e, WorldObject* obj, AreaTriggerEntry const* at)
{
    if (e.empty())
    {
        if (obj)
            sLog.outDebug("SmartScript: EventMap for Entry %u is empty but is using SmartScript.", obj->GetEntry());
        if (at)
            sLog.outDebug("SmartScript: EventMap for AreaTrigger %u is empty but is using SmartScript.", at->id);
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
        sLog.outErrorDb("SmartScript: Entry %u has events but no events added to list because of instance flags.", obj->GetEntry());
    if (mEvents.empty() && at)
        sLog.outErrorDb("SmartScript: AreaTrigger %u has events but no events added to list because of instance flags. NOTE: triggers can not handle any instance flags.", at->id);
}

void SmartScript::GetScript()
{
    SmartAIEventList e;
    if (me)
    {
        e = sSmartScriptMgr.GetScript(-((int32)me->GetDBTableGUIDLow()), mScriptType);
        if (e.empty())
            e = sSmartScriptMgr.GetScript((int32)me->GetEntry(), mScriptType);
        FillScript(e, me, NULL);
    }
    else if (go)
    {
        e = sSmartScriptMgr.GetScript(-((int32)go->GetDBTableGUIDLow()), mScriptType);
        if (e.empty())
            e = sSmartScriptMgr.GetScript((int32)go->GetEntry(), mScriptType);
        FillScript(e, go, NULL);
    }
    else if (trigger)
    {
        e = sSmartScriptMgr.GetScript((int32)trigger->id, mScriptType);
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
                sLog.outDebug("SmartScript::OnInitialize: source is Creature %u", me->GetEntry());
                break;
            case TYPEID_GAMEOBJECT:
                mScriptType = SMART_SCRIPT_TYPE_GAMEOBJECT;
                go = obj->ToGameObject();
                sLog.outDebug("SmartScript::OnInitialize: source is GameObject %u", go->GetEntry());
                break;
            default:
                sLog.outError("SmartScript::OnInitialize: Unhandled TypeID !WARNING!");
                return;
        }
    } else if (at)
    {
        mScriptType = SMART_SCRIPT_TYPE_AREATRIGGER;
        trigger = at;
        sLog.outDebug("SmartScript::OnInitialize: source is AreaTrigger %u", trigger->id);
    }
    else
    {
        sLog.outError("SmartScript::OnInitialize: !WARNING! Initialized objects are NULL.");
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

    if(!me) return;
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

void SmartScript::SetGUID(const uint64& guid, int32 id)
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
    if (!me) return NULL;
    CellPair p(Trinity::ComputeCellPair(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Unit* pUnit = NULL;

    Trinity::MostHPMissingInRange u_check(me, range, MinHPDiff);
    Trinity::UnitLastSearcher<Trinity::MostHPMissingInRange> searcher(me, pUnit, u_check);

    TypeContainerVisitor<Trinity::UnitLastSearcher<Trinity::MostHPMissingInRange>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    cell.Visit(p, grid_unit_searcher, *me->GetMap(), *me, range);
    return pUnit;
}

void SmartScript::DoFindFriendlyCC(std::list<Creature*>& _list, float range)
{
    if (!me) return;
    CellPair p(Trinity::ComputeCellPair(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Trinity::FriendlyCCedInRange u_check(me, range);
    Trinity::CreatureListSearcher<Trinity::FriendlyCCedInRange> searcher(me, _list, u_check);

    TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::FriendlyCCedInRange>, GridTypeMapContainer >  grid_creature_searcher(searcher);

    cell.Visit(p, grid_creature_searcher, *me->GetMap());
}

void SmartScript::DoFindFriendlyMissingBuff(std::list<Creature*>& _list, float range, uint32 spellid)
{
    if (!me) return;
    CellPair p(Trinity::ComputeCellPair(me->GetPositionX(), me->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Trinity::FriendlyMissingBuffInRange u_check(me, range, spellid);
    Trinity::CreatureListSearcher<Trinity::FriendlyMissingBuffInRange> searcher(me, _list, u_check);

    TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::FriendlyMissingBuffInRange>, GridTypeMapContainer >  grid_creature_searcher(searcher);

    cell.Visit(p, grid_creature_searcher, *me->GetMap());
}