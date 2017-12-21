 /*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ScriptedEscortAI.h"
#include "shadowfang_keep.h"
#include "Player.h"

enum Events
{
    // Deathstalker Commander Belmont
    EVENT_WALK_STAIRS_1 = 1,
    EVENT_WALK_STAIRS_2,
    EVENT_FACE_DIRECTION,
    EVENT_TALK_ASHBURY_DEAD_1,
    EVENT_TALK_ASHBURY_DEAD_2,
    EVENT_TALK_MOVE_DOOR,
    EVENT_MOVE_TO_DOOR,
    EVENT_TALK_OPEN,
    EVENT_OPEN_DOOR,
    EVENT_ATTACK_DOOR,
    EVENT_WALK_AWAY,
    EVENT_FACE_DIRECTION_2,
    EVENT_TALK_TO_CROMUSH_1,
    EVENT_TALK_TO_CROMUSH_2,
    EVENT_TALK_TO_CROMUSH_3,
    EVENT_BOW,
    EVENT_SUMMON_CROMUSH_1,
    EVENT_SUMMON_CROMUSH_2,
    EVENT_MOVE_TO_ARUGAL_GATE,
    EVENT_RESUME_PATH,

    // High Warlord Cromush
    EVENT_TALK_TO_BELMONT_1,
    EVENT_TALK_TO_BELMONT_2,
    EVENT_TALK_EMOTE,
    EVENT_POINT_EMOTE,
    EVENT_TALK_POISONED,
    EVENT_KNEEL,

    // Packleader Ivar Bloodfang
    EVENT_MOVE_TO_BALCONY_1,
    EVENT_MOVE_TO_BALCONY_2,
    EVENT_JUMP_TO_ASHUBRY,
    EVENT_FACE_DIRECTION_3,
    EVENT_MASTIFF_EMOTE,
    EVENT_RANDOM_INTERACTION,
    EVENT_BERSERKER_EMOTE,
    EVENT_TALK_SILVERLAINE_DEAD,
    EVENT_FACE_DIRECTION_4,
    EVENT_TALK_WALDEN_INTRO,
    EVENT_TALK_WALDEN_DEAD,
    EVENT_TALK_ATTACK_WORGEN,
    EVENT_MOVE_TO_GATE,
    EVENT_TALK_OPEN_GATE,
    EVENT_FACE_DIRECTION_5,
    EVENT_OPEN_GATE,
    EVENT_MOVE_TO_ARUGAL_DOOR,
    EVENT_TALK_DOOR_CLOSED_1,
    EVENT_TALK_DOOR_CLOSED_2,
    EVENT_FACE_DIRECTION_6,
    EVENT_OPEN_ROOM,
    EVENT_TALK_FINAL,


    // Bloodfang Berserker
    EVENT_MOVE_ARROUND,
    EVENT_JUMP_FROM_BALCONY,
    EVENT_REMOVE_STEALTH,
    EVENT_EAT_EMOTE,
    EVENT_MOVE_RANDOM,
    EVENT_MOVE_TO_JUMP_POSITION,
    EVENT_JUMP_UP,
    EVENT_MOVE_FURTHER_1,
    EVENT_MOVE_FURTHER_2,

    // Undead Troups
    EVENT_CHEER,
};

enum Points
{
    POINT_WALK_STAIRS_1 = 1,
    POINT_MOVE_BALCONY_1,
    POINT_MOVE_BALCONY_2,
    POINT_JUMP_UP,
    POINT_MOVE_FURTHER_1,
    POINT_MOVE_FURTHER_2,
};

enum Texts
{
    // Deathstalker Commander Belmont
    SAY_BELMONT_ASHBURY_DEAD    = 0,
    SAY_BELMONT_MOVE_TO_DOOR    = 1,
    SAY_BELMONT_UNLOCK_DOOR     = 2,
    SAY_BELMONT_OPEN_DOOR       = 3,
    SAY_BELMONT_SILVERLAINE_DEAD = 4,
    SAY_BELMONT_TO_CROMUSH_1    = 5,
    SAY_BELMONT_TO_CROMUSH_2    = 6,
    SAY_BELMONT_TO_CROMUSH_3    = 7,
    SAY_BELMONT_WALDEN_DEAD     = 8,
    SAY_BELMONT_WALDEN_OUTRO    = 9,
    SAY_BELMONT_DOOR_CLOSED     = 10,
    SAY_BELMONT_DOOR_OPENED     = 11,
    SAY_BELMONT_GODFREY         = 12,

    // High Warlord Cromush
    SAY_CROMUSH_TO_BELMONT_1    = 0,
    SAY_CROMUSH_TO_BELMONT_2    = 1,
    SAY_CROMUSH_FOR_THE_HORDE   = 2,
    SAY_CROMUSH_TO_BELMONT_3    = 3,

    // Packleader Ivar Bloodfang
    SAY_IVAR_ASHBURY_DEAD_1     = 0,
    SAY_IVAR_ASHBURY_DEAD_2     = 1,
    SAY_IVAR_TALK_TO_PACK_1     = 2,
    SAY_IVAR_MOVE_TO_COURTYARD  = 3,
    SAY_IVAR_UNLOCK_DOOR        = 4,
    SAY_IVAR_EMOTE_BERSERKER    = 5,
    SAY_IVAR_SILVERLAINE_DEAD   = 6,
    SAY_IVAR_WALDEN_INTRO       = 7,
    SAY_IVAR_WALDEN_DEAD        = 8,
    SAY_IVAR_ATTACK_WORGEN      = 9,
    SAY_IVAR_OPEN_GATE          = 10,
    SAY_IVAR_DOOR_CLOSED_1      = 11,
    SAY_IVAR_DOOR_CLOSED_2      = 12,
    SAY_IVAR_ROOM_OPEN          = 13,

    // Bloodfang Berserker
    SAY_BONES                   = 0,

    // Rabid Mastiff
    SAY_EMOTE_MASTIFF           = 0,

    // Magistrate Henry Maleb
    SAY_EMPRISONED              = 0,
};

Position const SKBelmontPath1[] =
{
    { -244.814f, 2127.15f, 87.0129f },
    { -256.849f, 2117.16f, 81.1796f },
};

const G3D::Vector3 SKBelmontPath2[] =
{
    {-253.795f, 2129.375f, 81.6518f },
    {-251.545f, 2136.625f, 84.4018f },
    { -248.795f, 2143.875f, 87.1518f },
    { -242.295f, 2141.375f, 87.4018f },
    { -237.545f, 2139.875f, 87.1518f },
    { -236.295f, 2144.625f, 88.4018f },
    { -235.545f, 2149.125f, 90.6518f },
    { -234.295f, 2152.125f, 90.9018f },
    { -242.545f, 2155.125f, 90.9018f },
    { -241.741f, 2157.09f, 90.624f },
};

const G3D::Vector3 SKBelmontPath3[] =
{
    { -232.822f, 2150.74f, 90.874f },
    { -227.572f, 2148.99f, 90.874f },
    { -222.822f, 2144.99f, 90.874f },
    { -219.403f, 2143.39f, 90.624f },
};


Position const SKCromushMovePose1 = { -130.894f, 2166.81f, 138.697f };

const G3D::Vector3 SKCromushFinalPath[] =
{
    { -130.894f, 2166.81f, 138.697f },
    { -122.2125f, 2164.165f, 139.025f },
    { -119.031f, 2172.02f, 139.853f },
};

// ---

const G3D::Vector3 SKBelmontPath4[] =
{
    { -268.0123f, 2271.203f, 95.94984f },
    { -267.106f, 2270.78f, 95.94984f },
    { -261.689f, 2268.78f, 98.724f },
    { -254.925f, 2266.13f, 100.889f },
    { -250.826f, 2264.28f, 100.889f },
    { -248.769f, 2260.63f, 100.892f },
    { -245.891f, 2256.9f, 100.893f },
    { -241.253f, 2256.01f, 100.893f },
    { -235.432f, 2255.13f, 100.892f },
    { -227.415f, 2257.64f, 102.753f },
    { -227.415f, 2257.64f, 102.753f },
};

// ---

const G3D::Vector3 SKBelmontPath5[] =
{
    { -173.513f, 2177.429f, 129.3383f },
    { -173.059f, 2178.32f, 129.3383f },
    { -170.795f, 2182.45f, 129.255f },
    { -164.78f, 2180.16f, 129.26f },
    { -153.594f, 2175.79f, 128.448f },
    {-142.101f, 2171.24f, 128.201f },
    { -142.101f, 2171.24f, 128.201f },
};

const G3D::Vector3 SKBelmontPath6[] =
{
    { -137.9335f, 2166.785f, 128.8225f },
    { -135.6835f, 2165.535f, 129.0725f },
    { -133.266f, 2164.33f, 128.944f },
};

// ---

const G3D::Vector3 SKBelmontFinalPath[] =
{
    { -168.6964f, 2187.787f, 151.9893f },
    { -169.071f, 2186.86f, 151.9893f },
    { -168.637f, 2181.88f, 151.906f },
    { -162.78f, 2179.32f, 151.906f },
    { -154.911f, 2176.01f, 155.038f },
    { -141.832f, 2170.99f, 155.678f },
    { -131.832f, 2166.28f, 155.678f },
    { -131.832f, 2166.28f, 155.678f },
};

Position const SKBelmonFinalPos = { -119.658f, 2162.35f, 155.678f };

enum IvarPaths
{
    PATH_IVAR_ASHBURY_BALCONY = 4700600,
};

const G3D::Vector3 SKIvarPath2[] =
{
    { -253.9495f, 2124.95f, 81.65175f },
    { -253.6995f, 2131.45f, 81.65175f },
    { -252.1995f, 2135.7f, 83.65175f },
    { -250.4495f, 2140.7f, 86.15175f },
    { -248.9495f, 2143.95f, 87.15175f },
    { -242.4495f, 2141.7f, 87.15175f },
    { -237.9495f, 2140.45f, 87.15175f },
    { -236.9495f, 2144.7f, 88.40175f },
    { -235.4495f, 2150.95f, 90.90175f },
    { -242.9495f, 2153.95f, 90.90175f },
    { -241.84f, 2156.7f, 90.624f },
};

const G3D::Vector3 SKIvarPath3[] =
{
    { -241.2605f, 2154.06f, 90.874f },
    { -237.2605f, 2151.81f, 90.874f },
    { -233.2605f, 2149.31f, 90.874f },
    { -228.681f, 2146.92f, 90.624f },
};

Position const IvarJumpPos1 = { -254.559f, 2121.7f, 81.1795f };

const G3D::Vector3 SKBerserkerPath1[] =
{
    { -235.5815f, 2138.77f, 87.24785f },
    { -238.0815f, 2141.02f, 87.24785f },
    { -244.3315f, 2142.77f, 87.24785f },
    { -248.8315f, 2144.02f, 87.24785f },
    { -250.8315f, 2139.27f, 85.49785f },
    { -252.5815f, 2134.77f, 83.24785f },
};

Position const SKBerserkerJumpPositions1[] =
{
    { -258.332f, 2119.02f, 81.1795f },
    { -256.205f, 2118.07f, 81.1795f },
    { -253.896f, 2116.94f, 81.1795f },
};

// -----

Position const IvarJumpPos2 = { -268.177f, 2294.44f, 77.4874f };

Position const SKBerserkerJumpPositions2[] =
{
    { -234.196f, 2281.85f, 76.2979f },
    { -240.969f, 2283.85f, 76.3204f },
    { -255.816f, 2289.09f, 76.3441f },
};

// --
const G3D::Vector3 SKBerserkerPath2[] =
{
    { -254.862f, 2266.08f, 101.0079f },
    { -251.362f, 2264.58f, 101.0079f },
    { -249.112f, 2261.83f, 101.0079f },
    { -250.318f, 2249.56f, 100.892f },
};

const G3D::Vector3 SKBerserkerPath3[] =
{
    { -252.7115f, 2265.245f, 101.0332f },
    { -249.7115f, 2262.495f, 101.0332f },
    { -246.7115f, 2254.995f, 101.0332f },
    { -251.4615f, 2246.995f, 101.0332f },
    { -257.411f, 2244.82f, 100.891f },
};

const G3D::Vector3 SKBerserkerPath4[] =
{
    { -252.2485f, 2265.13f, 101.0929f },
    { -249.7485f, 2262.63f, 101.0929f },
    { -247.068f, 2253.4f, 100.893f },
};

// ---

Position const IvarJumpPos3 = { -246.66f, 2163.02f, 96.6991f };

// ---

Position const IvarWalkPos1 = { -149.165f, 2174.34f, 127.953f };

const G3D::Vector3 SKIvarPath4[] =
{
    { -139.9845f, 2170.305f, 128.6985f },
    { -135.2345f, 2165.305f, 129.1985f },
    { -133.304f, 2164.27f, 128.944f },
};

Position const BerserkerMoveJumpPositions[] =
{
    { -141.41f, 2172.98f, 128.201f },
    { -140.714f, 2170.52f, 128.201f },
    { -148.229f, 2166.35f, 128.448f },
    { -147.859f, 2168.45f, 128.201f },
    { -142.191f, 2171.89f, 128.201f },
    { -146.189f, 2164.87f, 128.448f },
    { -141.179f, 2172.86f, 128.201f },
};

Position const BerserkerJumpPositions2[] =
{
    { -136.769f, 2171.22f, 136.578f },
    { -138.573f, 2169.05f, 136.578f },
    { -138.858f, 2166.37f, 136.578f },
    { -138.807f, 2166.77f, 136.578f },
    { -137.516f, 2169.59f, 136.578f },
    { -138.97f, 2166.46f, 136.578f },
    { -137.408f, 2170.33f, 136.578f },
};

Position const BerserkerJumpMovePositions1[] =
{
    { -132.109f, 2168.61f, 138.697f },
    { -132.535f, 2167.76f, 138.697f },
    { -134.12f, 2167.11f, 138.697f },
    { -130.965f, 2166.47f, 138.697f },
    { -132.753f, 2167.57f, 138.697f },
    { -133.672f, 2164.91f, 138.697f },
    { -132.797f, 2166.66f, 138.697f },
};

const G3D::Vector3 BerserkerFinalPath0[] =
{
    { -127.849f, 2166.03f, 139.0555f },
    {-123.599f, 2165.53f, 139.0555f },
    {-120.089f, 2168.95f, 139.414f },
};

const G3D::Vector3 BerserkerFinalPath1[] =
{
    { -126.677f, 2165.465f, 139.0325f },
    { -121.427f, 2165.215f, 139.0325f },
    { -119.319f, 2168.17f, 139.368f },
};

const G3D::Vector3 BerserkerFinalPath2[] =
{
    { -134.12f, 2167.11f, 138.697f },
    { -123.1685f, 2165.135f, 139.0035f },
    { -118.717f, 2171.66f, 139.81f },
};

const G3D::Vector3 BerserkerFinalPath3[] =
{
    { -130.965f, 2166.47f, 138.697f },
    { -124.0485f, 2164.915f, 139.026f },
    { -120.132f, 2168.36f, 139.355f },
};

const G3D::Vector3 BerserkerFinalPath4[] =
{
    { -132.753f, 2167.57f, 138.697f },
    { -122.675f, 2164.24f, 139.0525f },
    { -119.097f, 2172.41f, 139.908f },
};

const G3D::Vector3 BerserkerFinalPath5[] =
{
    { -127.396f, 2165.925f, 139.088f },
    { -122.396f, 2164.925f, 139.088f },
    { -119.62f, 2169.44f, 139.479f },
};

const G3D::Vector3 BerserkerFinalPath6[] =
{
    { -132.753f, 2167.57f, 138.697f },
    { -124.541f, 2165.705f, 139.0565f },
    { -120.785f, 2169.25f, 139.416f },
};

// ---

Position const IvarArugalDoorPos = { -120.818f, 2162.85f, 155.678f };

class npc_sfk_packleader_ivar_bloodfang : public CreatureScript
{
public:
    npc_sfk_packleader_ivar_bloodfang() : CreatureScript("npc_sfk_packleader_ivar_bloodfang") { }

    struct npc_sfk_packleader_ivar_bloodfangAI : public npc_escortAI
    {
        npc_sfk_packleader_ivar_bloodfangAI(Creature* creature) : npc_escortAI(creature), instance(creature->GetInstanceScript()), summons(me) { }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }


        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_DESPAWN:
                    summons.DespawnAll();
                    me->DespawnOrUnsummon(Milliseconds(1));
                    break;
                case ACTION_DESPAWN_BERSERKERS:
                    summons.DespawnAll();
                    break;
                case ACTION_ASHBURY_DEAD:
                    events.ScheduleEvent(EVENT_MOVE_TO_BALCONY_1, Seconds(2));
                    break;
                case ACTION_SILVERLAINE_DEAD:
                    me->GetMotionMaster()->MoveJump(IvarJumpPos2, 15.0f, 6.0f);
                    events.ScheduleEvent(EVENT_TALK_SILVERLAINE_DEAD, Seconds(7));
                    break;
                case ACTION_WALDEN_INTRO:
                    me->GetMotionMaster()->MoveJump(IvarJumpPos3, 20.0f, 10.0f);
                    events.ScheduleEvent(EVENT_FACE_DIRECTION_4, Seconds(4) + Milliseconds(500));
                    break;
                case ACTION_WALDEN_DEAD:
                    me->GetMotionMaster()->MovePoint(0, IvarWalkPos1, false);
                    events.ScheduleEvent(EVENT_TALK_WALDEN_DEAD, Seconds(7));
                    break;
                case ACTION_GODFREY_INTRO:
                    events.ScheduleEvent(EVENT_MOVE_TO_ARUGAL_DOOR, Seconds(5));
                    break;
                default:
                    break;
            }
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

        }

        bool WasWhisperedBefore(ObjectGuid guid) const
        {
            return _whisperedPlayers.count(guid) != 0;
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MOVE_TO_BALCONY_1:
                        me->GetMotionMaster()->MovePath(PATH_IVAR_ASHBURY_BALCONY, false);
                        events.ScheduleEvent(EVENT_JUMP_TO_ASHUBRY, Seconds(3) + Milliseconds(500));
                        break;
                    case EVENT_JUMP_TO_ASHUBRY:
                        me->GetMotionMaster()->MoveJump(IvarJumpPos1, 5.0f, 15.0f, 0);
                        events.ScheduleEvent(EVENT_FACE_DIRECTION, Seconds(2) + Milliseconds(500));
                        break;
                    case EVENT_FACE_DIRECTION:
                        me->SetFacingTo(7.497746f);
                        events.ScheduleEvent(EVENT_TALK_ASHBURY_DEAD_1, Seconds(2) + Milliseconds(700));
                        break;
                    case EVENT_TALK_ASHBURY_DEAD_1:
                        Talk(SAY_IVAR_ASHBURY_DEAD_1);
                        events.ScheduleEvent(EVENT_TALK_ASHBURY_DEAD_2, Seconds(5));
                        events.ScheduleEvent(EVENT_RANDOM_INTERACTION, Seconds(2));
                        break;
                    case EVENT_TALK_ASHBURY_DEAD_2:
                        Talk(SAY_IVAR_ASHBURY_DEAD_2);
                        events.ScheduleEvent(EVENT_BERSERKER_EMOTE, Seconds(6));
                        events.ScheduleEvent(EVENT_FACE_DIRECTION_2, Seconds(11));
                        break;
                    case EVENT_RANDOM_INTERACTION:
                        switch (urand(0, 1))
                        {
                            case 0:
                                if (Creature* berserker = me->FindNearestCreature(NPC_BLOODFANG_BERSERKER, 20.0f, true))
                                    berserker->AI()->Talk(SAY_BONES);
                                break;
                            case 1:
                                if (Creature* henry = me->FindNearestCreature(NPC_HIGH_MAGISTRATE_HENRY, 20.0f, true))
                                    henry->AI()->Talk(SAY_EMPRISONED);
                                break;
                            default:
                                break;
                        }
                        break;
                    case EVENT_BERSERKER_EMOTE:
                        Talk(SAY_IVAR_EMOTE_BERSERKER);
                        break;
                    case EVENT_FACE_DIRECTION_2:
                        me->SetFacingTo(4.356153f);
                        Talk(SAY_IVAR_TALK_TO_PACK_1);
                        events.ScheduleEvent(EVENT_TALK_MOVE_DOOR, Seconds(6));
                        break;
                    case EVENT_TALK_MOVE_DOOR:
                        Talk(SAY_IVAR_MOVE_TO_COURTYARD);
                        events.ScheduleEvent(EVENT_MOVE_TO_DOOR, Seconds(8));
                        break;
                    case EVENT_MOVE_TO_DOOR:
                        me->GetMotionMaster()->MoveSmoothPath(0, SKIvarPath2, 11);
                        events.ScheduleEvent(EVENT_TALK_OPEN, Seconds(10));
                        break;
                    case EVENT_TALK_OPEN:
                        Talk(SAY_IVAR_UNLOCK_DOOR);
                        events.ScheduleEvent(EVENT_ATTACK_DOOR, Seconds(4) + Milliseconds(500));
                        break;
                    case EVENT_ATTACK_DOOR:
                        DoCast(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_OPEN_DOOR, Seconds(1) + Milliseconds(500));
                        break;
                    case EVENT_OPEN_DOOR:
                        instance->SetData(DATA_ASHBURY_OUTRO, DONE);
                        events.ScheduleEvent(EVENT_WALK_AWAY, Seconds(2));
                        break;
                    case EVENT_WALK_AWAY:
                        me->GetMotionMaster()->MoveSmoothPath(0, SKIvarPath3, 4, true);
                        events.ScheduleEvent(EVENT_FACE_DIRECTION_3, Seconds(7));
                        break;
                    case EVENT_FACE_DIRECTION_3:
                        me->SetFacingTo(9.010136f);
                        break;
                    case EVENT_TALK_SILVERLAINE_DEAD:
                        Talk(SAY_IVAR_SILVERLAINE_DEAD);
                        break;
                    case EVENT_FACE_DIRECTION_4:
                        me->SetFacingTo(8.723662f);
                        events.ScheduleEvent(EVENT_TALK_WALDEN_INTRO, Seconds(1));
                        break;
                    case EVENT_TALK_WALDEN_INTRO:
                    {
                        std::list<Player*> players;
                        Trinity::AnyPlayerInObjectRangeCheck checker(me, 10.0f);
                        Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, players, checker);
                        Cell::VisitWorldObjects(me, searcher, 10.0f);
                        for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            if (!WasWhisperedBefore((*itr)->GetGUID()))
                            {
                                _whisperedPlayers.insert((*itr)->GetGUID());
                                Talk(SAY_IVAR_WALDEN_INTRO, (*itr));
                            }
                        }
                        events.Repeat(Seconds(1));
                        break;
                    }
                    case EVENT_TALK_WALDEN_DEAD:
                        Talk(SAY_IVAR_WALDEN_DEAD);
                        events.ScheduleEvent(EVENT_TALK_ATTACK_WORGEN, Seconds(6));
                        break;
                    case EVENT_TALK_ATTACK_WORGEN:
                        Talk(SAY_IVAR_ATTACK_WORGEN);
                        events.ScheduleEvent(EVENT_MOVE_TO_GATE, Seconds(16));
                        break;
                    case EVENT_MOVE_TO_GATE:
                        Talk(SAY_IVAR_OPEN_GATE);
                        me->GetMotionMaster()->MoveSmoothPath(0, SKIvarPath4, 3, true);
                        events.ScheduleEvent(EVENT_FACE_DIRECTION_5, Seconds(11));
                        break;
                    case EVENT_FACE_DIRECTION_5:
                        me->SetFacingTo(9.053417f);
                        events.ScheduleEvent(EVENT_OPEN_GATE, Seconds(3));
                        break;
                    case EVENT_OPEN_GATE:
                        instance->SetData(DATA_WALDEN_OUTRO, DONE);
                        break;
                    case EVENT_MOVE_TO_ARUGAL_DOOR:
                        me->GetMotionMaster()->MovePoint(0, IvarArugalDoorPos);
                        events.ScheduleEvent(EVENT_TALK_DOOR_CLOSED_1, Seconds(6));
                        break;
                    case EVENT_TALK_DOOR_CLOSED_1:
                        Talk(SAY_IVAR_DOOR_CLOSED_1);
                        me->SetFacingTo(9.029113f);
                        events.ScheduleEvent(EVENT_TALK_DOOR_CLOSED_2, Seconds(6));
                        break;
                    case EVENT_TALK_DOOR_CLOSED_2:
                        Talk(SAY_IVAR_DOOR_CLOSED_2);
                        events.ScheduleEvent(EVENT_FACE_DIRECTION_6, Seconds(2) + Milliseconds(400));
                        break;
                    case EVENT_FACE_DIRECTION_6:
                        me->SetFacingTo(5.88752f);
                        events.ScheduleEvent(EVENT_OPEN_ROOM, Seconds(3));
                        break;
                    case EVENT_OPEN_ROOM:
                        instance->SetData(DATA_GODFREY_INTRO, DONE);
                        events.ScheduleEvent(EVENT_TALK_FINAL, Seconds(2));
                        break;
                    case EVENT_TALK_FINAL:
                        me->SetFacingTo(9.029113f);
                        Talk(SAY_IVAR_ROOM_OPEN);
                        break;
                    default:
                        break;
                }
            }
        }
        private:
            GuidSet _whisperedPlayers;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_sfk_packleader_ivar_bloodfangAI>(creature);
    }
};

class npc_sfk_bloodfang_berserker : public CreatureScript
{
public:
    npc_sfk_bloodfang_berserker() : CreatureScript("npc_sfk_bloodfang_berserker") { }

    struct npc_sfk_bloodfang_berserkerAI : public ScriptedAI
    {
        npc_sfk_bloodfang_berserkerAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript())
        {
            actionID = 0;

        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_WORGEN_1:
                    actionID = 0;
                    events.ScheduleEvent(EVENT_JUMP_FROM_BALCONY, Seconds(2) + Milliseconds(500));
                    break;
                case ACTION_WORGEN_2:
                    actionID = 1;
                    events.ScheduleEvent(EVENT_JUMP_FROM_BALCONY, Seconds(2) + Milliseconds(500));
                    break;
                case ACTION_WORGEN_3:
                    actionID = 2;
                    events.ScheduleEvent(EVENT_JUMP_FROM_BALCONY, Seconds(2) + Milliseconds(500));
                    break;
                case ACTION_WORGEN_6:
                    events.ScheduleEvent(EVENT_MOVE_ARROUND, Seconds(31));
                    break;
                case ACTION_WORGEN_7:
                    DoCast(me, SPELL_STEALTH, true);
                    me->GetMotionMaster()->MoveJump(SKBerserkerJumpPositions2[0], 15.0f, 6.0f);
                    events.ScheduleEvent(EVENT_REMOVE_STEALTH, Milliseconds(100));
                    events.ScheduleEvent(EVENT_EAT_EMOTE, Seconds(3) + Milliseconds(300));
                    break;
                case ACTION_WORGEN_8:
                    DoCast(me, SPELL_STEALTH, true);
                    me->GetMotionMaster()->MoveJump(SKBerserkerJumpPositions2[1], 15.0f, 6.0f);
                    events.ScheduleEvent(EVENT_REMOVE_STEALTH, Milliseconds(100));
                    events.ScheduleEvent(EVENT_EAT_EMOTE, Seconds(3) + Milliseconds(300));
                    break;
                case ACTION_WORGEN_9:
                    DoCast(me, SPELL_STEALTH, true);
                    me->GetMotionMaster()->MoveJump(SKBerserkerJumpPositions2[2], 15.0f, 6.0f);
                    events.ScheduleEvent(EVENT_REMOVE_STEALTH, Milliseconds(100));
                    events.ScheduleEvent(EVENT_EAT_EMOTE, Seconds(3) + Milliseconds(300));
                    break;
                case ACTION_WORGEN_10:
                    me->GetMotionMaster()->MoveSmoothPath(0, SKBerserkerPath2, 4, true);
                    events.ScheduleEvent(EVENT_MOVE_RANDOM, Seconds(12));
                    break;
                case ACTION_WORGEN_11:
                    me->GetMotionMaster()->MoveSmoothPath(0, SKBerserkerPath3, 5, true);
                    events.ScheduleEvent(EVENT_MOVE_RANDOM, Seconds(16));
                    break;
                case ACTION_WORGEN_12:
                    me->GetMotionMaster()->MoveSmoothPath(0, SKBerserkerPath4, 3, true);
                    events.ScheduleEvent(EVENT_MOVE_RANDOM, Seconds(10));
                    break;
                case ACTION_WORGEN_13:
                    berserkerNumber = 0;
                    DoCast(me, SPELL_STEALTH, true);
                    events.ScheduleEvent(EVENT_MOVE_TO_JUMP_POSITION, Seconds(15) + Milliseconds(700));
                    break;
                case ACTION_WORGEN_14:
                    berserkerNumber = 1;
                    DoCast(me, SPELL_STEALTH, true);
                    events.ScheduleEvent(EVENT_MOVE_TO_JUMP_POSITION, Seconds(15) + Milliseconds(700));
                    break;
                case ACTION_WORGEN_15:
                    berserkerNumber = 2;
                    DoCast(me, SPELL_STEALTH, true);
                    events.ScheduleEvent(EVENT_MOVE_TO_JUMP_POSITION, Seconds(17) + Milliseconds(700));
                    break;
                case ACTION_WORGEN_16:
                    berserkerNumber = 3;
                    DoCast(me, SPELL_STEALTH, true);
                    events.ScheduleEvent(EVENT_MOVE_TO_JUMP_POSITION, Seconds(15) + Milliseconds(700));
                    break;
                case ACTION_WORGEN_17:
                    berserkerNumber = 4;
                    DoCast(me, SPELL_STEALTH, true);
                    events.ScheduleEvent(EVENT_MOVE_TO_JUMP_POSITION, Seconds(17) + Milliseconds(700));
                    break;
                case ACTION_WORGEN_18:
                    berserkerNumber = 5;
                    DoCast(me, SPELL_STEALTH, true);
                    events.ScheduleEvent(EVENT_MOVE_TO_JUMP_POSITION, Seconds(15) + Milliseconds(700));
                    break;
                case ACTION_WORGEN_19:
                    berserkerNumber = 6;
                    DoCast(me, SPELL_STEALTH, true);
                    events.ScheduleEvent(EVENT_MOVE_TO_JUMP_POSITION, Seconds(17) + Milliseconds(700));
                    break;
                default:
                    break;
            }
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (pointId)
            {
                case POINT_JUMP_UP:
                    events.ScheduleEvent(EVENT_JUMP_UP, Milliseconds(1));
                    break;
                case POINT_MOVE_FURTHER_1:
                    events.ScheduleEvent(EVENT_MOVE_FURTHER_2, Milliseconds(1));
                    break;
                case POINT_MOVE_FURTHER_2:
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MOVE_ARROUND:
                        me->GetMotionMaster()->MoveSmoothPath(0, SKBerserkerPath1, 6, true);
                        break;
                    case EVENT_JUMP_FROM_BALCONY:
                        me->GetMotionMaster()->MoveJump(SKBerserkerJumpPositions1[actionID], 7.0f, 15.0f, 0);
                        events.ScheduleEvent(EVENT_FACE_DIRECTION, Seconds(2) + Milliseconds(500));
                        break;
                    case EVENT_FACE_DIRECTION:
                        me->SetFacingTo(7.323833f);
                        break;
                    case EVENT_REMOVE_STEALTH:
                        me->RemoveAurasDueToSpell(SPELL_STEALTH);
                        break;
                    case EVENT_EAT_EMOTE:
                        me->HandleEmoteCommand(EMOTE_STATE_EAT);
                        break;
                    case EVENT_MOVE_RANDOM:
                        me->SetHomePosition(me->GetPosition());
                        me->GetMotionMaster()->MoveRandom(5.0f);
                        break;
                    case EVENT_MOVE_TO_JUMP_POSITION:
                        me->GetMotionMaster()->MovePoint(POINT_JUMP_UP, BerserkerMoveJumpPositions[berserkerNumber], false);
                        break;
                    case EVENT_JUMP_UP:
                        me->GetMotionMaster()->MoveJump(BerserkerJumpPositions2[berserkerNumber], 16.0f, 21.0f);
                        events.ScheduleEvent(EVENT_MOVE_FURTHER_1, Seconds(5) + Milliseconds(500));
                        break;
                    case EVENT_MOVE_FURTHER_1:
                        me->GetMotionMaster()->MovePoint(POINT_MOVE_FURTHER_1, BerserkerJumpMovePositions1[berserkerNumber], false);
                        break;
                    case EVENT_MOVE_FURTHER_2:
                        switch (berserkerNumber)
                        {
                            case 0:
                                me->GetMotionMaster()->MoveSmoothPath(0, BerserkerFinalPath0, 3, false);
                                break;
                            case 1:
                                me->GetMotionMaster()->MoveSmoothPath(0, BerserkerFinalPath1, 3, false);
                                break;
                            case 2:
                                me->GetMotionMaster()->MoveSmoothPath(0, BerserkerFinalPath2, 3, false);
                                break;
                            case 3:
                                me->GetMotionMaster()->MoveSmoothPath(0, BerserkerFinalPath3, 3, false);
                                break;
                            case 4:
                                me->GetMotionMaster()->MoveSmoothPath(0, BerserkerFinalPath4, 3, false);
                                break;
                            case 5:
                                me->GetMotionMaster()->MoveSmoothPath(0, BerserkerFinalPath5, 3, false);
                                break;
                            case 6:
                                me->GetMotionMaster()->MoveSmoothPath(0, BerserkerFinalPath6, 3, false);
                                break;
                            default:
                                break;
                        }
                        me->DespawnOrUnsummon(2500);
                        break;
                    default:
                        break;
                }
            }
        }
        private:
            uint8 berserkerNumber;
            InstanceScript* instance;
            EventMap events;
            uint8 actionID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_sfk_bloodfang_berserkerAI>(creature);
    }
};

class npc_sfk_deathstalker_commander_belmont : public CreatureScript
{
public:
    npc_sfk_deathstalker_commander_belmont() : CreatureScript("npc_sfk_deathstalker_commander_belmont") { }

    struct npc_sfk_deathstalker_commander_belmontAI : public ScriptedAI
    {
        npc_sfk_deathstalker_commander_belmontAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()), summons(me)
        {
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;

        void JustSummoned(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                case NPC_DISEASE_BUNNY:
                case NPC_HIGH_WARLORD_CROMUSH:
                    break;
                default:
                    summons.Summon(summon);
                    break;
            }
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_DESPAWN:
                    summons.DespawnAll();
                    me->DespawnOrUnsummon(Milliseconds(1));
                    break;
                case ACTION_ASHBURY_DEAD:
                    events.ScheduleEvent(EVENT_WALK_STAIRS_1, Milliseconds(800));
                    break;
                case ACTION_SILVERLAINE_DEAD:
                    DoCast(me, SPELL_STEALTH, true);
                    events.ScheduleEvent(EVENT_REMOVE_STEALTH, Seconds(3) + Milliseconds(500));
                    break;
                case ACTION_SPRINGVALE_DEAD:
                    me->GetMotionMaster()->MoveSmoothPath(0, SKBelmontPath4, 11);
                    events.ScheduleEvent(EVENT_FACE_DIRECTION_3, Seconds(6));
                    break;
                case ACTION_WALDEN_DEAD:
                    me->GetMotionMaster()->MoveSmoothPath(0, SKBelmontPath5, 7);
                    events.ScheduleEvent(EVENT_TALK_WALDEN_DEAD, Seconds(7) + Milliseconds(300));
                    break;
                case ACTION_GODFREY_INTRO:
                    me->GetMotionMaster()->MoveSmoothPath(0, SKBelmontFinalPath, 8);
                    events.ScheduleEvent(EVENT_TALK_DOOR_CLOSED_1, Seconds(11));
                    events.ScheduleEvent(EVENT_MOVE_TO_ARUGAL_DOOR, Seconds(6));
                    break;
                default:
                    break;
            }
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (pointId)
            {
                case POINT_WALK_STAIRS_1:
                    events.ScheduleEvent(EVENT_WALK_STAIRS_2, Milliseconds(1));
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    // Event chain after Baron Ashbury's death
                    case EVENT_WALK_STAIRS_1:
                        me->GetMotionMaster()->MovePoint(POINT_WALK_STAIRS_1, SKBelmontPath1[0]);
                        break;
                    case EVENT_WALK_STAIRS_2:
                        events.ScheduleEvent(EVENT_FACE_DIRECTION, Seconds(2) + Milliseconds(500));
                        me->GetMotionMaster()->MoveJump(SKBelmontPath1[1], 10.0f, 10.0f);
                        break;
                    case EVENT_FACE_DIRECTION:
                        me->SetFacingTo(1.308997f);
                        events.ScheduleEvent(EVENT_TALK_ASHBURY_DEAD_1, Seconds(2) + Milliseconds(400));
                        break;
                    case EVENT_TALK_ASHBURY_DEAD_1:
                        Talk(SAY_BELMONT_ASHBURY_DEAD);
                        events.ScheduleEvent(EVENT_TALK_MOVE_DOOR, Seconds(12));
                        break;
                    case EVENT_TALK_MOVE_DOOR:
                        Talk(SAY_BELMONT_MOVE_TO_DOOR);
                        events.ScheduleEvent(EVENT_MOVE_TO_DOOR, Seconds(2));
                        break;
                    case EVENT_MOVE_TO_DOOR:
                        me->GetMotionMaster()->MoveSmoothPath(0, SKBelmontPath2, 10);
                        events.ScheduleEvent(EVENT_TALK_OPEN, Seconds(10));
                        break;
                    case EVENT_TALK_OPEN:
                        Talk(SAY_BELMONT_UNLOCK_DOOR);
                        events.ScheduleEvent(EVENT_OPEN_DOOR, Seconds(5));
                        break;
                    case EVENT_OPEN_DOOR:
                        instance->SetData(DATA_ASHBURY_OUTRO, DONE);
                        Talk(SAY_BELMONT_OPEN_DOOR);
                        events.ScheduleEvent(EVENT_WALK_AWAY, Seconds(3) + Milliseconds(400));
                        break;
                    case EVENT_WALK_AWAY:
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        me->GetMotionMaster()->MoveSmoothPath(0, SKBelmontPath3, 4, true);
                        events.ScheduleEvent(EVENT_FACE_DIRECTION_2, Seconds(11));
                        break;
                    case EVENT_FACE_DIRECTION_2:
                        me->SetFacingTo(9.077573f);
                        break;
                    // Event chain after Baron Silverlaine's death
                    case EVENT_REMOVE_STEALTH:
                        me->RemoveAurasDueToSpell(SPELL_STEALTH);
                        Talk(SAY_BELMONT_SILVERLAINE_DEAD);
                        events.ScheduleEvent(EVENT_SUMMON_CROMUSH_1, Seconds(4));
                        events.ScheduleEvent(EVENT_TALK_TO_CROMUSH_1, Seconds(7));
                        break;
                    case EVENT_SUMMON_CROMUSH_1:
                        if (Creature* cromush = me->SummonCreature(NPC_HIGH_WARLORD_CROMUSH, SKCromushSpawnPos1))
                            cromush->AI()->DoAction(ACTION_CROMUSH_SUMMONED_1);
                        break;
                    case EVENT_TALK_TO_CROMUSH_1:
                        Talk(SAY_BELMONT_TO_CROMUSH_1);
                        events.ScheduleEvent(EVENT_TALK_TO_CROMUSH_2, Seconds(8) + Milliseconds(500));
                        break;
                    case EVENT_TALK_TO_CROMUSH_2:
                        Talk(SAY_BELMONT_TO_CROMUSH_2);
                        events.ScheduleEvent(EVENT_TALK_TO_CROMUSH_3, Seconds(6));
                        break;
                    case EVENT_TALK_TO_CROMUSH_3:
                        Talk(SAY_BELMONT_TO_CROMUSH_3);
                        events.ScheduleEvent(EVENT_BOW, Seconds(20));
                        break;
                    case EVENT_BOW:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
                        break;
                    case EVENT_FACE_DIRECTION_3:
                        me->SetFacingTo(3.445011f);
                        break;
                    case EVENT_TALK_WALDEN_DEAD:
                        Talk(SAY_BELMONT_WALDEN_DEAD);
                        events.ScheduleEvent(EVENT_SUMMON_CROMUSH_2, Seconds(7));
                        events.ScheduleEvent(EVENT_MOVE_TO_GATE, Seconds(17));
                        break;
                    case EVENT_SUMMON_CROMUSH_2:
                        if (Creature* cromush = me->SummonCreature(NPC_HIGH_WARLORD_CROMUSH, SKCromushSpawnPos2))
                        {
                            cromush->SetDisableGravity(true);
                            cromush->AI()->DoAction(ACTION_CROMUSH_SUMMONED_2);
                        }
                        break;
                    case EVENT_MOVE_TO_GATE:
                        Talk(SAY_BELMONT_WALDEN_OUTRO);
                        me->GetMotionMaster()->MoveSmoothPath(0, SKBelmontPath6, 3);
                        events.ScheduleEvent(EVENT_FACE_DIRECTION_4, Seconds(6));
                        break;
                    case EVENT_FACE_DIRECTION_4:
                        me->SetFacingTo(9.055001f);
                        events.ScheduleEvent(EVENT_OPEN_GATE, Seconds(1));
                        break;
                    case EVENT_OPEN_GATE:
                        instance->SetData(DATA_WALDEN_OUTRO, DONE);
                        break;
                    case EVENT_TALK_DOOR_CLOSED_1:
                        Talk(SAY_BELMONT_DOOR_CLOSED);
                        events.ScheduleEvent(EVENT_OPEN_ROOM, Seconds(7));
                        break;
                    case EVENT_MOVE_TO_ARUGAL_DOOR:
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(0, SKBelmonFinalPos);
                        break;
                    case EVENT_OPEN_ROOM:
                        instance->SetData(DATA_GODFREY_INTRO, DONE);
                        Talk(SAY_BELMONT_DOOR_OPENED);
                        if (Creature* cromush = me->FindNearestCreature(NPC_HIGH_WARLORD_CROMUSH, 10.0f, true))
                            cromush->AI()->DoAction(ACTION_CROMUSH_POISONED);
                        events.ScheduleEvent(EVENT_TALK_FINAL, Seconds(12));
                        break;
                    case EVENT_TALK_FINAL:
                        Talk(SAY_BELMONT_GODFREY);
                        events.ScheduleEvent(EVENT_FACE_DIRECTION_5, Seconds(4));
                        break;
                    case EVENT_FACE_DIRECTION_5:
                        me->SetFacingTo(9.074822f);
                        me->HandleEmoteCommand(EMOTE_STATE_READY1H);
                        break;
                    default:
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_sfk_deathstalker_commander_belmontAI>(creature);
    }
};

class npc_sfk_veteran_forsaken_trooper : public CreatureScript
{
public:
    npc_sfk_veteran_forsaken_trooper() : CreatureScript("npc_sfk_veteran_forsaken_trooper") { }

    struct npc_sfk_veteran_forsaken_trooperAI : public ScriptedAI
    {
        npc_sfk_veteran_forsaken_trooperAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript())
        {
        }

        InstanceScript* instance;
        EventMap events;

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_CHEER:
                    events.ScheduleEvent(EVENT_CHEER, Seconds(22) + Milliseconds(500));
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHEER:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER_NO_SHEATHE);
                    break;
                default:
                    break;
                }
            }
        }
    private:
        uint8 undeadNumber;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_sfk_veteran_forsaken_trooperAI>(creature);
    }
};

class npc_sfk_high_warlord_cromush : public CreatureScript
{
public:
    npc_sfk_high_warlord_cromush() : CreatureScript("npc_sfk_high_warlord_cromush") { }

    struct npc_sfk_high_warlord_cromushAI : public ScriptedAI
    {
        npc_sfk_high_warlord_cromushAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript())
        {
        }

        InstanceScript* instance;
        EventMap events;

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_CROMUSH_SUMMONED_1:
                    DoCast(me, SPELL_TELEPORT_VISUAL, true);
                    events.ScheduleEvent(EVENT_TALK_TO_BELMONT_1, Seconds(6));
                    break;
                case ACTION_CROMUSH_SUMMONED_2:
                    DoCast(me, SPELL_TELEPORT_VISUAL, true);
                    Talk(SAY_CROMUSH_FOR_THE_HORDE);
                    events.ScheduleEvent(EVENT_FACE_DIRECTION, Seconds(6));
                    break;
                case ACTION_CROMUSH_SUMMONED_3:
                    me->SetUInt32Value(UNIT_FIELD_BYTES_1, 8);
                    break;
                case ACTION_CROMUSH_POISONED:
                    events.ScheduleEvent(EVENT_TALK_POISONED, Seconds(6));
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TALK_TO_BELMONT_1:
                        Talk(SAY_CROMUSH_TO_BELMONT_1);
                        events.ScheduleEvent(EVENT_TALK_TO_BELMONT_2, Seconds(17));
                        break;
                    case EVENT_TALK_TO_BELMONT_2:
                        Talk(SAY_CROMUSH_TO_BELMONT_2);
                        events.ScheduleEvent(EVENT_TALK_EMOTE, Seconds(6));
                        break;
                    case EVENT_TALK_EMOTE:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_TALK_NO_SHEATHE);
                        events.ScheduleEvent(EVENT_POINT_EMOTE, Seconds(5));
                        break;
                    case EVENT_POINT_EMOTE:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_POINT_NO_SHEATHE);
                        break;
                    case EVENT_FACE_DIRECTION:
                        me->SetFacingTo(5.916666f);
                        events.ScheduleEvent(EVENT_MOVE_FURTHER_1, Seconds(1));
                        break;
                    case EVENT_MOVE_FURTHER_1:
                        me->SetDisableGravity(false);
                        me->GetMotionMaster()->MoveJump(SKCromushMovePose1, 16.0f, 6.0f);
                        events.ScheduleEvent(EVENT_MOVE_FURTHER_2, Seconds(1));
                        break;
                    case EVENT_MOVE_FURTHER_2:
                        me->GetMotionMaster()->MoveSmoothPath(0, SKCromushFinalPath, 3, false);
                        me->DespawnOrUnsummon(2000);
                        break;
                    case EVENT_TALK_POISONED:
                        Talk(SAY_CROMUSH_TO_BELMONT_3);
                        break;
                    default:
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_sfk_high_warlord_cromushAI>(creature);
    }
};

enum SKShieldOfBones
{
    SPELL_SHIELD_OF_BONES_TRIGGERED = 91631,
};

class spell_sfk_shield_of_bones: public SpellScriptLoader
{
    public:
        spell_sfk_shield_of_bones() : SpellScriptLoader("spell_sfk_shield_of_bones") { }

        class spell_sfk_shield_of_bones_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sfk_shield_of_bones_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHIELD_OF_BONES_TRIGGERED });
            }

            void OnAuraRemoveHandler(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
                    if (Unit* caster = GetCaster())
                        caster->CastSpell(caster, SPELL_SHIELD_OF_BONES_TRIGGERED, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_sfk_shield_of_bones_AuraScript::OnAuraRemoveHandler, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sfk_shield_of_bones_AuraScript();
        }
};

class at_sfk_pre_walden : public AreaTriggerScript
{
public:
    at_sfk_pre_walden() : AreaTriggerScript("at_sfk_pre_walden") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (instance->GetData(DATA_WALDEN_INTRO) != DONE)
                instance->SetData(DATA_WALDEN_INTRO, DONE);
        return true;
    }
};

class at_sfk_godfrey_intro : public AreaTriggerScript
{
public:
    at_sfk_godfrey_intro() : AreaTriggerScript("at_sfk_godfrey_intro") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (instance->GetData(DATA_GODFREY_INTRO) != IN_PROGRESS && instance->GetData(DATA_GODFREY_INTRO) != DONE)
                instance->SetData(DATA_GODFREY_INTRO, IN_PROGRESS);
        return true;
    }
};

void AddSC_shadowfang_keep()
{
    new npc_sfk_packleader_ivar_bloodfang();
    new npc_sfk_bloodfang_berserker();
    new npc_sfk_deathstalker_commander_belmont();
    new npc_sfk_veteran_forsaken_trooper();
    new npc_sfk_high_warlord_cromush();
    new spell_sfk_shield_of_bones();
    new at_sfk_pre_walden();
    new at_sfk_godfrey_intro();
}
