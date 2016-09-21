/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "SceneMgr.h"
#include "Player.h"
#include "Chat.h"
#include "SpellAuraEffects.h"

class ChatHandler;

SceneMgr::SceneMgr(Player* player) : _player(player)
{
    m_StandaloneSceneInstanceID = 0;
    m_isDebugScenes = false;
}

uint32 SceneMgr::PlayScene(uint32 sceneId, Position const* position /*= nullptr*/)
{
    SceneTemplate const* sceneTemplate = sObjectMgr->GetSceneTemplate(sceneId);
    return PlaySceneByTemplate(sceneTemplate, position);
}

uint32 SceneMgr::PlaySceneByTemplate(SceneTemplate const* sceneTemplate, Position const* position /*= nullptr*/)
{
    if (sceneTemplate == nullptr)
        return 0;

    SceneScriptPackageEntry const* entry = sSceneScriptPackageStore.LookupEntry(sceneTemplate->ScenePackageId);

    if (entry == nullptr)
        return 0;

    // By default, take player position
    if (position == nullptr)
        position = GetPlayer();;

    uint64 transportGUID = 0;
    uint32 sceneInstanceID = GetNewStandaloneSceneInstanceID();

    if (m_isDebugScenes)
        ChatHandler(GetPlayer()->GetSession()).PSendSysMessage(LANG_COMMAND_SCENE_DEBUG_PLAY, sceneInstanceID, sceneTemplate->ScenePackageId, sceneTemplate->Playbackflags);

    WorldPackets::Scenes::PlayScene packet;
    packet.SceneID              = sceneTemplate->SceneId;
    packet.PlaybackFlags        = sceneTemplate->Playbackflags;
    packet.SceneInstanceID      = sceneInstanceID;
    packet.SceneScriptPackageID = sceneTemplate->ScenePackageId;
    packet.Location             = *position;
    packet.TransportGUID        = GetPlayer()->GetTransGUID();

    GetPlayer()->GetSession()->SendPacket(packet.Write(), true);

    AddInstanceIdToSceneMap(sceneInstanceID, sceneTemplate);

    sScriptMgr->OnSceneStart(GetPlayer(), sceneInstanceID, sceneTemplate);

    return sceneInstanceID;
}

uint32 SceneMgr::PlaySceneByPackageId(uint32 sceneScriptPackageId, uint32 playbackflags /*= SCENEFLAG_UNK16*/, Position const* position /*= nullptr*/)
{
    SceneTemplate sceneTemplate;
    sceneTemplate.SceneId           = 0;
    sceneTemplate.ScenePackageId    = sceneScriptPackageId;
    sceneTemplate.Playbackflags     = playbackflags;
    sceneTemplate.ScriptId          = 0;

    return PlaySceneByTemplate(&sceneTemplate, position);
}

void SceneMgr::CancelScene(uint32 sceneInstanceID, bool removeFromMap /*= true*/)
{
    if (removeFromMap)
        RemoveSceneInstanceId(sceneInstanceID);

    WorldPackets::Scenes::CancelScene packet;
    packet.SceneInstanceID = sceneInstanceID;
    GetPlayer()->GetSession()->SendPacket(packet.Write(), true);
}

void SceneMgr::OnSceneTrigger(uint32 sceneInstanceID, std::string triggerName)
{
    if (!HasScene(sceneInstanceID))
        return;

    if (m_isDebugScenes)
        ChatHandler(GetPlayer()->GetSession()).PSendSysMessage(LANG_COMMAND_SCENE_DEBUG_TRIGGER, sceneInstanceID, triggerName.c_str());

    SceneTemplate const* sceneTemplate = GetSceneTemplateFromInstanceId(sceneInstanceID);
    sScriptMgr->OnSceneTrigger(GetPlayer(), sceneInstanceID, sceneTemplate, triggerName);
}

void SceneMgr::OnSceneCancel(uint32 sceneInstanceID)
{
    if (!HasScene(sceneInstanceID))
        return;

    if (m_isDebugScenes)
        ChatHandler(GetPlayer()->GetSession()).PSendSysMessage(LANG_COMMAND_SCENE_DEBUG_CANCEL, sceneInstanceID);

    SceneTemplate const* sceneTemplate = GetSceneTemplateFromInstanceId(sceneInstanceID);

    // Must be done before removing aura
    RemoveSceneInstanceId(sceneInstanceID);

    if (sceneTemplate->SceneId != 0)
        RemoveAurasDueToSceneId(sceneTemplate->SceneId);

    sScriptMgr->OnSceneCancel(GetPlayer(), sceneInstanceID, sceneTemplate);
}

void SceneMgr::OnSceneComplete(uint32 sceneInstanceID)
{
    if (!HasScene(sceneInstanceID))
        return;

    if (m_isDebugScenes)
        ChatHandler(GetPlayer()->GetSession()).PSendSysMessage(LANG_COMMAND_SCENE_DEBUG_COMPLETE, sceneInstanceID);

    SceneTemplate const* sceneTemplate = GetSceneTemplateFromInstanceId(sceneInstanceID);

    // Must be done before removing aura
    RemoveSceneInstanceId(sceneInstanceID);

    if (sceneTemplate->SceneId != 0)
        RemoveAurasDueToSceneId(sceneTemplate->SceneId);

    sScriptMgr->OnSceneComplete(GetPlayer(), sceneInstanceID, sceneTemplate);
}

bool SceneMgr::HasScene(uint32 sceneInstanceID, uint32 sceneScriptPackageId /*= 0*/) const
{
    auto itr = m_scenesByInstance.find(sceneInstanceID);
    
    if (itr == m_scenesByInstance.end())
        return false;

    return !sceneScriptPackageId || sceneScriptPackageId == itr->second->ScenePackageId;
}

void SceneMgr::AddInstanceIdToSceneMap(uint32 sceneInstanceID, SceneTemplate const* sceneTemplate)
{
    m_scenesByInstance[sceneInstanceID] = sceneTemplate;
}

void SceneMgr::CancelSceneByPackageId(uint32 sceneScriptPackageId)
{
    std::vector<uint32> instancesIds;

    for (auto itr : m_scenesByInstance)
        if (itr.second->ScenePackageId == sceneScriptPackageId)
            instancesIds.push_back(itr.first);

    for (uint32 sceneInstanceID : instancesIds)
        CancelScene(sceneInstanceID);
}

void SceneMgr::RemoveSceneInstanceId(uint32 sceneInstanceID)
{
    m_scenesByInstance.erase(sceneInstanceID);
}

void SceneMgr::RemoveAurasDueToSceneId(uint32 sceneId)
{
    Player::AuraEffectList const& scenePlayAuras = GetPlayer()->GetAuraEffectsByType(SPELL_AURA_SCENE_PLAY);
    for (AuraEffect* scenePlayAura : scenePlayAuras)
    {
        if (scenePlayAura->GetMiscValue() == sceneId)
        {
            GetPlayer()->RemoveAura(scenePlayAura->GetBase());
            break;
        }
    }
}

SceneTemplate const* SceneMgr::GetSceneTemplateFromInstanceId(uint32 sceneInstanceID)
{
    auto itr = m_scenesByInstance.find(sceneInstanceID);

    if (itr == m_scenesByInstance.end())
        return nullptr;

    return itr->second;
}

uint32 SceneMgr::GetActiveSceneCount(uint32 sceneScriptPackageId /*= 0*/)
{
    uint32 activeSceneCount = 0;

    for (auto itr : m_scenesByInstance)
        if (!sceneScriptPackageId || itr.second->ScenePackageId == sceneScriptPackageId)
            ++activeSceneCount;

    return activeSceneCount;
}
