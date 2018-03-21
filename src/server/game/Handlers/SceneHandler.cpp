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

#include "Common.h"
#include "Log.h"
#include "ScenePackets.h"
#include "WorldSession.h"
#include "Player.h"

void WorldSession::HandleSceneTriggerEvent(WorldPackets::Scenes::SceneTriggerEvent& sceneTriggerEvent)
{
    TC_LOG_DEBUG("scenes", "HandleSceneTriggerEvent: SceneInstanceID: %u Event: %s", sceneTriggerEvent.SceneInstanceID, sceneTriggerEvent.Event.c_str());

    GetPlayer()->GetSceneMgr().OnSceneTrigger(sceneTriggerEvent.SceneInstanceID, sceneTriggerEvent.Event);
}

void WorldSession::HandleScenePlaybackComplete(WorldPackets::Scenes::ScenePlaybackComplete& scenePlaybackComplete)
{
    TC_LOG_DEBUG("scenes", "HandleScenePlaybackComplete: SceneInstanceID: %u", scenePlaybackComplete.SceneInstanceID);

    GetPlayer()->GetSceneMgr().OnSceneComplete(scenePlaybackComplete.SceneInstanceID);
}

void WorldSession::HandleScenePlaybackCanceled(WorldPackets::Scenes::ScenePlaybackCanceled& scenePlaybackCanceled)
{
    TC_LOG_DEBUG("scenes", "HandleScenePlaybackCanceled: SceneInstanceID: %u", scenePlaybackCanceled.SceneInstanceID);

    GetPlayer()->GetSceneMgr().OnSceneCancel(scenePlaybackCanceled.SceneInstanceID);
}
