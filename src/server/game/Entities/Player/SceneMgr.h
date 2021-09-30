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

#ifndef SceneMgr_h__
#define SceneMgr_h__

#include "Common.h"
#include <map>

enum SceneFlags
{
    SCENEFLAG_PLAYER_NOT_INTERACTABLE_PHASED    = 0x01, // Player Is Non-Interactable and Phased
    SCENEFLAG_FADE_TO_BLACKSCREEN_ON_COMPLETE   = 0x02,
    SCENEFLAG_NOT_CANCELABLE                    = 0x04,
    SCENEFLAG_GIGANTIC_AOI                      = 0x08,
    SCENEFLAG_INFINITE_AOI                      = 0x10, // 16, most common value
    SCENEFLAG_FADE_TO_BLACKSCREEN_ON_CANCEL     = 0x20,
    SCENEFLAG_IGNORE_TRANSPORT                  = 0x40,
    SCENEFLAG_PLAY_AS_LOGIN_CINEMATIC           = 0x80,
};

class Player;
struct Position;
struct SceneTemplate;

using SceneTemplateByInstance = std::map<uint32, std::unique_ptr<SceneTemplate>>;

class TC_GAME_API SceneMgr
{
public:
    SceneMgr(Player* player);

    SceneMgr(SceneMgr const&) = delete;
    SceneMgr(SceneMgr&&) = delete;

    Player* GetPlayer() const { return _player; }

    uint32 PlayScene(uint32 sceneId, Position const* position = nullptr);
    uint32 PlaySceneByTemplate(SceneTemplate const* sceneTemplate, Position const* position = nullptr);
    uint32 PlaySceneByPackageId(uint32 sceneScriptPackageId, uint32 playbackflags = SCENEFLAG_INFINITE_AOI, Position const* position = nullptr);
    void CancelScene(uint32 sceneInstanceID, bool removeFromMap = true);

    void OnSceneTrigger(uint32 sceneInstanceID, std::string const& triggerName);
    void OnSceneCancel(uint32 sceneInstanceID);
    void OnSceneComplete(uint32 sceneInstanceID);

    void RecreateScene(uint32 sceneScriptPackageId, uint32 playbackflags = SCENEFLAG_INFINITE_AOI, Position const* position = nullptr)
    {
        CancelSceneByPackageId(sceneScriptPackageId);
        PlaySceneByPackageId(sceneScriptPackageId, playbackflags, position);
    }

    bool HasScene(uint32 sceneInstanceID, uint32 sceneScriptPackageId = 0) const;

    void AddInstanceIdToSceneMap(uint32 sceneInstanceID, SceneTemplate const* sceneTemplate);
    void CancelSceneBySceneId(uint32 sceneId);
    void CancelSceneByPackageId(uint32 sceneScriptPackageId);
    void RemoveSceneInstanceId(uint32 sceneInstanceID);
    void RemoveAurasDueToSceneId(uint32 sceneId);

    SceneTemplate const* GetSceneTemplateFromInstanceId(uint32 sceneInstanceID);
    uint32 GetActiveSceneCount(uint32 sceneScriptPackageId = 0);
    SceneTemplateByInstance const& GetSceneTemplateByInstanceMap() const { return _scenesByInstance; }

    uint32 GetNewStandaloneSceneInstanceID() { return ++_standaloneSceneInstanceID; }

    void ToggleDebugSceneMode() { _isDebuggingScenes = !_isDebuggingScenes; }
    bool IsInDebugSceneMode() const { return _isDebuggingScenes; }

private:
    Player* _player;
    SceneTemplateByInstance _scenesByInstance;
    uint32 _standaloneSceneInstanceID;
    bool _isDebuggingScenes;
};

#endif // SceneMgr_h__
