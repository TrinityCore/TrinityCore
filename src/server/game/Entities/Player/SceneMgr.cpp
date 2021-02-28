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

#include "SceneMgr.h"
#include "Chat.h"
#include "DB2Stores.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScenePackets.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"

SceneMgr::SceneMgr(Player* player) : _player(player)
{
    _standaloneSceneInstanceID = 0;
    _isDebuggingScenes = false;
}

uint32 SceneMgr::PlayScene(uint32 sceneId, Position const* position /*= nullptr*/)
{
    SceneTemplate const* sceneTemplate = sObjectMgr->GetSceneTemplate(sceneId);
    return PlaySceneByTemplate(sceneTemplate, position);
}

uint32 SceneMgr::PlaySceneByTemplate(SceneTemplate const* sceneTemplate, Position const* position /*= nullptr*/)
{
    if (!sceneTemplate)
        return 0;

    SceneScriptPackageEntry const* entry = sSceneScriptPackageStore.LookupEntry(sceneTemplate->ScenePackageId);
    if (!entry)
        return 0;

    // By default, take player position
    if (!position)
        position = GetPlayer();

    uint32 sceneInstanceID = GetNewStandaloneSceneInstanceID();

    if (_isDebuggingScenes)
        ChatHandler(GetPlayer()->GetSession()).PSendSysMessage(LANG_COMMAND_SCENE_DEBUG_PLAY, sceneInstanceID, sceneTemplate->ScenePackageId, sceneTemplate->PlaybackFlags);

    WorldPackets::Scenes::PlayScene playScene;
    playScene.SceneID              = sceneTemplate->SceneId;
    playScene.PlaybackFlags        = sceneTemplate->PlaybackFlags;
    playScene.SceneInstanceID      = sceneInstanceID;
    playScene.SceneScriptPackageID = sceneTemplate->ScenePackageId;
    playScene.Location             = *position;
    playScene.TransportGUID        = GetPlayer()->GetTransGUID();
    playScene.Encrypted            = sceneTemplate->Encrypted;

    GetPlayer()->SendDirectMessage(playScene.Write());

    AddInstanceIdToSceneMap(sceneInstanceID, sceneTemplate);

    sScriptMgr->OnSceneStart(GetPlayer(), sceneInstanceID, sceneTemplate);

    return sceneInstanceID;
}

uint32 SceneMgr::PlaySceneByPackageId(uint32 sceneScriptPackageId, uint32 playbackflags /*= SCENEFLAG_UNK16*/, Position const* position /*= nullptr*/)
{
    SceneTemplate sceneTemplate;
    sceneTemplate.SceneId           = 0;
    sceneTemplate.ScenePackageId    = sceneScriptPackageId;
    sceneTemplate.PlaybackFlags     = playbackflags;
    sceneTemplate.Encrypted         = false;
    sceneTemplate.ScriptId          = 0;

    return PlaySceneByTemplate(&sceneTemplate, position);
}

void SceneMgr::CancelScene(uint32 sceneInstanceID, bool removeFromMap /*= true*/)
{
    if (removeFromMap)
        RemoveSceneInstanceId(sceneInstanceID);

    WorldPackets::Scenes::CancelScene cancelScene;
    cancelScene.SceneInstanceID = sceneInstanceID;
    GetPlayer()->SendDirectMessage(cancelScene.Write());
}

void SceneMgr::OnSceneTrigger(uint32 sceneInstanceID, std::string const& triggerName)
{
    if (!HasScene(sceneInstanceID))
        return;

    if (_isDebuggingScenes)
        ChatHandler(GetPlayer()->GetSession()).PSendSysMessage(LANG_COMMAND_SCENE_DEBUG_TRIGGER, sceneInstanceID, triggerName.c_str());

    SceneTemplate const* sceneTemplate = GetSceneTemplateFromInstanceId(sceneInstanceID);
    sScriptMgr->OnSceneTrigger(GetPlayer(), sceneInstanceID, sceneTemplate, triggerName);
}

void SceneMgr::OnSceneCancel(uint32 sceneInstanceID)
{
    if (!HasScene(sceneInstanceID))
        return;

    if (_isDebuggingScenes)
        ChatHandler(GetPlayer()->GetSession()).PSendSysMessage(LANG_COMMAND_SCENE_DEBUG_CANCEL, sceneInstanceID);

    SceneTemplate const* sceneTemplate = GetSceneTemplateFromInstanceId(sceneInstanceID);

    // Must be done before removing aura
    RemoveSceneInstanceId(sceneInstanceID);

    if (sceneTemplate->SceneId != 0)
        RemoveAurasDueToSceneId(sceneTemplate->SceneId);

    sScriptMgr->OnSceneCancel(GetPlayer(), sceneInstanceID, sceneTemplate);

    if (sceneTemplate->PlaybackFlags & SCENEFLAG_CANCEL_AT_END)
        CancelScene(sceneInstanceID, false);
}

void SceneMgr::OnSceneComplete(uint32 sceneInstanceID)
{
    if (!HasScene(sceneInstanceID))
        return;

    if (_isDebuggingScenes)
        ChatHandler(GetPlayer()->GetSession()).PSendSysMessage(LANG_COMMAND_SCENE_DEBUG_COMPLETE, sceneInstanceID);

    SceneTemplate const* sceneTemplate = GetSceneTemplateFromInstanceId(sceneInstanceID);

    // Must be done before removing aura
    RemoveSceneInstanceId(sceneInstanceID);

    if (sceneTemplate->SceneId != 0)
        RemoveAurasDueToSceneId(sceneTemplate->SceneId);

    sScriptMgr->OnSceneComplete(GetPlayer(), sceneInstanceID, sceneTemplate);

    if (sceneTemplate->PlaybackFlags & SCENEFLAG_CANCEL_AT_END)
        CancelScene(sceneInstanceID, false);
}

bool SceneMgr::HasScene(uint32 sceneInstanceID, uint32 sceneScriptPackageId /*= 0*/) const
{
    auto itr = _scenesByInstance.find(sceneInstanceID);

    if (itr != _scenesByInstance.end())
        return !sceneScriptPackageId || sceneScriptPackageId == itr->second->ScenePackageId;

    return false;
}

void SceneMgr::AddInstanceIdToSceneMap(uint32 sceneInstanceID, SceneTemplate const* sceneTemplate)
{
    _scenesByInstance[sceneInstanceID] = sceneTemplate;
}

void SceneMgr::CancelSceneBySceneId(uint32 sceneId)
{
    std::vector<uint32> instancesIds;

    for (auto const& itr : _scenesByInstance)
        if (itr.second->SceneId == sceneId)
            instancesIds.push_back(itr.first);

    for (uint32 sceneInstanceID : instancesIds)
        CancelScene(sceneInstanceID);
}

void SceneMgr::CancelSceneByPackageId(uint32 sceneScriptPackageId)
{
    std::vector<uint32> instancesIds;

    for (auto itr : _scenesByInstance)
        if (itr.second->ScenePackageId == sceneScriptPackageId)
            instancesIds.push_back(itr.first);

    for (uint32 sceneInstanceID : instancesIds)
        CancelScene(sceneInstanceID);
}

void SceneMgr::RemoveSceneInstanceId(uint32 sceneInstanceID)
{
    _scenesByInstance.erase(sceneInstanceID);
}

void SceneMgr::RemoveAurasDueToSceneId(uint32 sceneId)
{
    Player::AuraEffectList const& scenePlayAuras = GetPlayer()->GetAuraEffectsByType(SPELL_AURA_PLAY_SCENE);
    for (AuraEffect* scenePlayAura : scenePlayAuras)
    {
        if (uint32(scenePlayAura->GetMiscValue()) == sceneId)
        {
            GetPlayer()->RemoveAura(scenePlayAura->GetBase());
            break;
        }
    }
}

SceneTemplate const* SceneMgr::GetSceneTemplateFromInstanceId(uint32 sceneInstanceID)
{
    auto itr = _scenesByInstance.find(sceneInstanceID);

    if (itr != _scenesByInstance.end())
        return itr->second;

    return nullptr;
}

uint32 SceneMgr::GetActiveSceneCount(uint32 sceneScriptPackageId /*= 0*/)
{
    uint32 activeSceneCount = 0;

    for (auto itr : _scenesByInstance)
        if (!sceneScriptPackageId || itr.second->ScenePackageId == sceneScriptPackageId)
            ++activeSceneCount;

    return activeSceneCount;
}
