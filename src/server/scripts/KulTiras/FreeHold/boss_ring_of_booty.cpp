/*
 * Copyright 2023 AzgathCore
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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "freehold.h"

enum RingOfBootySpells
{
    ///Lightning
    Grabbing = 257831,
    Slippery = 257949,
    Greasy = 257829,
    GreasyDummy = 257950,
    ///Ludwig Von Tortollan 
    ShellBounce = 257904,
    ShellBounceDmg = 257902,
    ///Trothak
    RiderShark = 256410,
    RightSharkRiding = 256368,
    LeftSharkRiding = 256402,
    RipperPunch = 256363,
    SharkTornado = 256405,
    SharkTossJump = 256424,
    SharkTossDmg = 256477,
    FlailingShark = 256551,
    RearmCharge1 = 256489,
    RearmCharge2 = 256494,
    RearmDmg = 256706,
    HammerSharkAura = 256918,
    SawtoothSharkAura = 256923,

    ///Heroic Difficulty
    FlailingSharks = 256551,
    ThrowChumMissile = 272534,
    ThrowChum = 272548,
    BloodyMess = 272554
};

enum RingOfBootyEvents
{
    EventsMoveNextPosition = 1,
    EventsShellBounce,
    EventsRipperPunch,
    EventsSharkTornado,
    EventsSharkToss,
    EventsRearm,
    EventsThrowChum,
    EventsCheckPlayers,
    EventsCheckReset
};

enum RingOfBootyPoint
{
    MovementPointLightningCenter = 1,
    MovementPointLightningChange,
    MovementPointLightningDespawn,
    MovementPointTrothakFirstPoint,
    MovementPointFight,
};

enum RingOfBootyAction
{
    ActionFirstGukGuk = 0,
    ActionFirstGurgthock,
    ActionSecondGukGuk,
    ActionSecondGurgthock,
    ActionStartArena,
    ActionJumpPig,
    ActionSecondEvent,
    ActionThirdEvent,
    ActionStartMoveTrothak,
    ActionFinishFight
};

enum TalkGukguk
{
    TalkFirstGukGuk = 0,
    TalkSecondGukGuk
};

enum TalkGurgthock
{
    TalkFirstGurgthock = 0,
    TalkSecondGurgthock,
    TalkThirdGurgthock,
    TalkFourGurgthock,
    TalkCatchThePig,
    TalkEnterTortolan,
    TalkKillTortolan,
    TalkLastFight
};

enum TalkDavey
{
    TalkStartAnnouncer = 0,
};

Position midleArenaPos{ -1813.17f, -491.82f, 34.96f, 1.57f };
Position despawnPos{ -1811.06f, -439.22f, 35.92f };
Position const TrothakMovePos[3] =
{
    { -1830.87f, -432.38f, 40.13f, 5.94f },
    { -1811.71f, -438.00f, 36.05f, 4.66f },
    { -1812.53f, -473.63f, 35.35f, 4.72f }
};

void AddSC_boss_ring_of_booty()
{
   
}