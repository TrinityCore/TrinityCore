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

/*
 * Kalec for some reason lifts off after landing
 * Kalec seems to be spawned after cinematic is finished, not after specific time
 */

#include "ScriptMgr.h"
#include "magisters_terrace.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"

enum KalecgosMisc
{
    SAY_KALECGOS_SPAWN          = 0,

    SPELL_CAMERA_SHAKE          = 44762,
    SPELL_TRANSFORM_VISUAL      = 24085,
    SPELL_ORB_KILL_CREDIT       = 46307,

    PATH_KALECGOS_FLIGHT        = 248440,
    POINT_ID_PREPARE_LANDING    = 6,

    EVENT_KALECGOS_LANDING      = 1,
    EVENT_KALECGOS_TRANSFORM,
    EVENT_KALECGOS_SUMMON
};

Position const KalecgosHumanSpawnPos = { 197.86285f, -272.74414f, -8.651634f, 0.0f };

// 24844 - Kalecgos
struct npc_kalecgos : public ScriptedAI
{
    npc_kalecgos(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePath(PATH_KALECGOS_FLIGHT, false);
        Talk(SAY_KALECGOS_SPAWN);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != WAYPOINT_MOTION_TYPE)
            return;

        if (pointId == POINT_ID_PREPARE_LANDING)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
            me->SetDisableGravity(false);
            _events.ScheduleEvent(EVENT_KALECGOS_LANDING, 1s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_KALECGOS_LANDING:
                DoCastSelf(SPELL_CAMERA_SHAKE);
                me->SetFacingTo(0.0698132f);
                me->SetObjectScale(0.6f);
                _events.ScheduleEvent(EVENT_KALECGOS_TRANSFORM, 1s);
                break;
            case EVENT_KALECGOS_TRANSFORM:
                DoCastSelf(SPELL_TRANSFORM_VISUAL);
                // This doesn't appear in sniff and credit is rewarded when cinematic is finished
                DoCastSelf(SPELL_ORB_KILL_CREDIT);
                _events.ScheduleEvent(EVENT_KALECGOS_SUMMON, 1s);
                break;
            case EVENT_KALECGOS_SUMMON:
                me->SummonCreature(NPC_HUMAN_KALECGOS, KalecgosHumanSpawnPos, TEMPSUMMON_MANUAL_DESPAWN);
                me->DespawnOrUnsummon(1500ms);
                break;
            default:
                break;
        }
    }

private:
    EventMap _events;
};

void AddSC_magisters_terrace()
{
    RegisterMagistersTerraceCreatureAI(npc_kalecgos);
}
