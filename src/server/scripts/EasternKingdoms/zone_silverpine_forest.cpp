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

#include "CellImpl.h"
#include "CombatAI.h"
#include "CreatureAIImpl.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "Group.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Object.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SharedDefines.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "Unit.h"
#include "Vehicle.h"
#include "WorldSession.h"

enum HordeHauler
{
    NPC_HORDE_ENGINEER_HAULER               = 44734,
    NPC_SUBDUED_FOREST_ETTIN_HAULER         = 44737,
    NPC_FORSAKEN_TROOPER_F                  = 44732,
    NPC_FORSAKEN_TROOPER_M                  = 44733,

    SPELL_EJECT_PASSENGERS_3_8              = 83477,

    EVENT_START_PATH                        = 1,
    EVENT_YELL_ON_FORSAKEN_HIGH             = 2,
    EVENT_YELL_ON_SEPULCHER                 = 3,
    EVENT_YELL_ON_FORSAKEN_FRONT            = 4,
    EVENT_TROOPERS_RUN                      = 5,

    TALK_HAULER_BOARDED                     = 0,
    TALK_ON_FORSAKEN_HIGH                   = 1,
    TALK_ON_SEPULCHER                       = 2,
    TALK_ON_FORSAKEN_FRONT                  = 3,

    PATH_FROM_NORTH_TO_SOUTH                = 3578480,
    PATH_TROOPER_1                          = 3578560,
    PATH_TROOPER_2                          = 3578568,
    PATH_TROOPER_3                          = 3578576,
    PATH_TROOPER_4                          = 3578584,
    PATH_TROOPER_5                          = 3578592,

    WAYPOINT_ON_FORSAKEN_HIGH               = 11,
    WAYPOINT_ON_SEPULCHER                   = 35,
    WAYPOINT_ON_FORSAKEN_FRONT              = 60,
    WAYPOINT_ON_DESPAWN_POINT_SOUTH         = 63,
    WAYPOINT_ON_TROOPER_DESPAWN             = 1,

    SEAT_HAULER_PLAYER                      = 2,
    SEAT_HAULER_TROOPER_1                   = 3,
    SEAT_HAULER_TROOPER_2                   = 4,
    SEAT_HAULER_TROOPER_3                   = 5,
    SEAT_HAULER_TROOPER_4                   = 6,
    SEAT_HAULER_TROOPER_5                   = 7
};

// 44731 - Horde Hauler
struct npc_silverpine_horde_hauler : public ScriptedAI
{
    npc_silverpine_horde_hauler(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_START_PATH, 8s);
    }

    void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
    {
        if (apply && passenger->IsPlayer())
        {
            _playerGUID = passenger->GetGUID();

            if (seatId == SEAT_HAULER_PLAYER)
            {
                if (Creature* engineer = me->FindNearestCreature(NPC_HORDE_ENGINEER_HAULER, 15.0f, true))
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        if (engineer->IsAIEnabled())
                            engineer->AI()->Talk(TALK_HAULER_BOARDED, player);
                    }
                }
            }
        }

        if (!apply && !passenger->IsPlayer())
        {
            uint32 pathId = 0;

            switch (seatId)
            {
                case SEAT_HAULER_TROOPER_1:
                    pathId = PATH_TROOPER_1;
                    break;
                case SEAT_HAULER_TROOPER_2:
                    pathId = PATH_TROOPER_2;
                    break;
                case SEAT_HAULER_TROOPER_3:
                    pathId = PATH_TROOPER_3;
                    break;
                case SEAT_HAULER_TROOPER_4:
                    pathId = PATH_TROOPER_4;
                    break;
                case SEAT_HAULER_TROOPER_5:
                    pathId = PATH_TROOPER_5;
                    break;

                default:
                    break;
            }

            passenger->GetMotionMaster()->MovePath(pathId, false);
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_FROM_NORTH_TO_SOUTH)
        {
            if (waypointId == WAYPOINT_ON_FORSAKEN_HIGH)
                _events.ScheduleEvent(EVENT_YELL_ON_FORSAKEN_HIGH, 1s);
            else if (waypointId == WAYPOINT_ON_SEPULCHER)
                _events.ScheduleEvent(EVENT_YELL_ON_SEPULCHER, 1s);
            else if (waypointId == WAYPOINT_ON_FORSAKEN_FRONT)
                _events.ScheduleEvent(EVENT_YELL_ON_FORSAKEN_FRONT, 1s);
            else if (waypointId == WAYPOINT_ON_DESPAWN_POINT_SOUTH)
                me->DespawnOrUnsummon(1s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_PATH:
                    me->GetMotionMaster()->MovePath(PATH_FROM_NORTH_TO_SOUTH, false);
                    break;

                case EVENT_YELL_ON_FORSAKEN_HIGH:
                {
                    if (Creature* engineer = me->FindNearestCreature(NPC_HORDE_ENGINEER_HAULER, 15.0f, true))
                    {
                        if (engineer->IsAIEnabled())
                            engineer->AI()->Talk(TALK_ON_FORSAKEN_HIGH);
                    }
                    break;
                }

                case EVENT_YELL_ON_SEPULCHER:
                {
                    if (Creature* engineer = me->FindNearestCreature(NPC_HORDE_ENGINEER_HAULER, 15.0f, true))
                    {
                        if (engineer->IsAIEnabled())
                            engineer->AI()->Talk(TALK_ON_SEPULCHER);
                    }
                    break;
                }

                case EVENT_YELL_ON_FORSAKEN_FRONT:
                {
                    if (Creature* engineer = me->FindNearestCreature(NPC_HORDE_ENGINEER_HAULER, 15.0f, true))
                    {
                        if (engineer->IsAIEnabled())
                            engineer->AI()->Talk(TALK_ON_FORSAKEN_FRONT);
                    }

                    DoCastSelf(SPELL_EJECT_PASSENGERS_3_8);

                    me->SetUnitFlag3(UnitFlags3::UNIT_FLAG3_UNTARGETABLE_FROM_UI);
                    break;
                }

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;
};

enum MagicalChainsHauler
{
    SPELL_CHAIN_RIGHT_HAULER                = 83467,
    SPELL_CHAIN_LEFT_HAULER                 = 83464
};

// 84238 - Magical Chains (Hauler)
class spell_silverpine_magical_chains_hauler : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_CHAIN_RIGHT_HAULER,
            SPELL_CHAIN_LEFT_HAULER
        });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_CHAIN_RIGHT_HAULER, true);
        GetTarget()->CastSpell(nullptr, SPELL_CHAIN_LEFT_HAULER, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_silverpine_magical_chains_hauler::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

Position const OrgrimmarPortalPos[3] =
{
    { 1358.62f, 1054.72f, 53.1200f, 0.0f },
    { 1393.27f, 1021.20f, 53.2225f, 0.0f },
    { 1404.71f, 1063.73f, 60.5617f, 0.0f }
};

Position const HellscreamElitePos[16] =
{
    { 1387.90f, 1029.71f, 53.21853f, 2.827433f },
    { 1389.79f, 1024.51f, 53.20833f, 2.827433f },
    { 1388.05f, 1026.91f, 53.20833f, 2.827433f },
    { 1388.16f, 1020.88f, 53.25523f, 2.827433f },
    { 1385.79f, 1025.99f, 53.22593f, 2.827433f },
    { 1386.69f, 1023.26f, 53.24393f, 2.827433f },
    { 1384.33f, 1022.04f, 53.28123f, 2.827433f },
    { 1391.10f, 1027.73f, 53.20483f, 2.827433f },

    { 1359.10f, 1046.55f, 52.97053f, 5.253441f },
    { 1360.89f, 1051.81f, 53.19793f, 5.253441f },
    { 1360.75f, 1048.84f, 53.12893f, 5.253441f },
    { 1364.43f, 1053.62f, 53.29343f, 5.253441f },
    { 1363.08f, 1048.15f, 53.22223f, 5.253441f },
    { 1364.08f, 1050.84f, 53.29163f, 5.253441f },
    { 1366.69f, 1050.31f, 53.34203f, 5.253441f },
    { 1357.85f, 1050.12f, 52.99823f, 5.253441f }
};

Position const GarroshPos = { 1402.45f, 1061.62f, 60.56173f, 3.926991f };

Position const GarroshJumpPos = { 1378.65f, 1044.23f, 53.8389f, 5.51524f };

Position const CromushPos = { 1404.71f, 1063.73f, 60.5617f, 2.827433f };

Position const AgathaPreRisePos = { 1364.02f, 1028.54f, 66.99143f };

Position const AgathaRisePos = { 1368.65f, 1032.19f, 63.3033f };

Position const AgathaPreResetPos = { 1364.02f, 1028.54f, 55.9914f };

Position const AgathaResetPos = { 1364.02f, 1028.54f, 58.1319f };

enum QuestTheWarchiefCometh
{
    QUEST_THE_WARCHIEF_COMETH               = 26965,

    NPC_LADY_SYLVANAS_WINDRUNNER_COMETH     = 44365,
    NPC_AGATHA_COMETH                       = 44608,
    NPC_GRAND_EXECUTOR_MORTUUS              = 44615,
    NPC_MALE_FALLEN_HUMAN                   = 44592,
    NPC_FEMALE_FALLEN_HUMAN                 = 44593,
    NPC_PORTAL_FROM_ORGRIMMAR               = 44630,
    NPC_GARROSH_HELLSCREAM                  = 44629,
    NPC_HIGH_WARLORD_CROMUSH_COMETH         = 44640,
    NPC_HELLSCREAM_ELITE_COMETH             = 44636,
    NPC_QUEST_MONSTER_CREDIT                = 44629,
    NPC_FORSAKEN_WARHORSE_UNPHASED          = 73595,

    SPELL_RAISE_FORSAKEN_COMETH             = 83173,
    SPELL_AIR_REVENANT_ENTRANCE             = 55761,
    SPELL_SIMPLE_TELEPORT                   = 12980,
    SPELL_WELCOME_TO_SILVERPINE_CREDIT      = 83384,

    EVENT_START_SCENE_COMETH                = 1,
    EVENT_SUMMON_PORTAL_COMETH              = 2,
    EVENT_SUMMON_GARROSH_COMETH             = 3,
    EVENT_AGATHA_RAISE_FORSAKEN             = 4, // Note: 4-8 are used.
    EVENT_SCENE_TALK_COMETH                 = 9, // Note: 9-36 are used.

    ACTION_START_SCENE_COMETH               = 1,

    TALK_SYLVANAS_COMETH_0                  = 0,
    TALK_SYLVANAS_COMETH_1                  = 1,
    TALK_SYLVANAS_COMETH_2                  = 2,
    TALK_SYLVANAS_COMETH_3                  = 3,
    TALK_SYLVANAS_COMETH_4                  = 4,
    TALK_SYLVANAS_COMETH_5                  = 5,
    TALK_SYLVANAS_COMETH_6                  = 6,
    TALK_SYLVANAS_COMETH_7                  = 7,
    TALK_SYLVANAS_COMETH_8                  = 8,
    TALK_SYLVANAS_COMETH_9                  = 9,
    TALK_SYLVANAS_COMETH_10                 = 10,
    TALK_GARROSH_COMETH_0                   = 0,
    TALK_GARROSH_COMETH_1                   = 1,
    TALK_GARROSH_COMETH_2                   = 2,
    TALK_GARROSH_COMETH_3                   = 3,
    TALK_GARROSH_COMETH_4                   = 4,
    TALK_GARROSH_COMETH_5                   = 5,
    TALK_GARROSH_COMETH_6                   = 6,
    TALK_GARROSH_COMETH_7                   = 7,
    TALK_GARROSH_COMETH_8                   = 8,
    TALK_GARROSH_COMETH_9                   = 9,
    TALK_GARROSH_COMETH_10                  = 10,
    TALK_CROMUSH_COMETH_0                   = 0,
    TALK_CROMUSH_COMETH_1                   = 1,

    PATH_CROMUSH                            = 3571216,
    PATH_GARROSH                            = 3570320,

    POINT_AGATHA_PRE_RISE                   = 1,
    POINT_AGATHA_RISE                       = 2,
    POINT_AGATHA_PRE_RESET                  = 3,
    POINT_AGATHA_RESET                      = 4,

    ANIMKIT_GENERAL_1                       = 609,
    ANIMKIT_SYLV_1                          = 595,
    ANIMKIT_SYLV_2                          = 606,
    ANIMKIT_GARROSH_1                       = 662,
    ANIMKIT_GARROSH_2                       = 595
};

// 44615 - Grand Executor Mortuus
struct npc_silverpine_grand_executor_mortuus : public ScriptedAI
{
    npc_silverpine_grand_executor_mortuus(Creature* creature) : ScriptedAI(creature), _summons(me), _eventInProgress(false) {}

    void OnQuestAccept(Player* /*player*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_WARCHIEF_COMETH)
        {
            if (_eventInProgress)
                return;

            DoAction(ACTION_START_SCENE_COMETH);
        }
    }

    void Reset() override
    {
        _events.Reset();
        _garroshGUID.Clear();
        _cromushGUID.Clear();
        _sylvanasGUID.Clear();
        _agathaGUID.Clear();
        _summons.clear();
        _eventInProgress = false;
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_GARROSH_HELLSCREAM:
                summon->CastSpell(summon, SPELL_SIMPLE_TELEPORT);
                _garroshGUID = summon->GetGUID();
                break;

            case NPC_HELLSCREAM_ELITE_COMETH:
                summon->CastSpell(summon, SPELL_SIMPLE_TELEPORT);
                break;

            default:
                break;
        }
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case ACTION_START_SCENE_COMETH:
            {
                _eventInProgress = true;

                if (Creature* sylvanas = me->FindNearestCreature(NPC_LADY_SYLVANAS_WINDRUNNER_COMETH, 100.0f))
                {
                    _sylvanasGUID = sylvanas->GetGUID();

                    if (Creature* agatha = me->FindNearestCreature(NPC_AGATHA_COMETH, 100.0f))
                    {
                        _agathaGUID = agatha->GetGUID();

                        _events.ScheduleEvent(EVENT_START_SCENE_COMETH, 250ms);
                    }
                }

                break;
            }

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_SCENE_COMETH:
                    _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH, 1s);
                    _events.ScheduleEvent(EVENT_SUMMON_PORTAL_COMETH, 4s);
                    _events.ScheduleEvent(EVENT_SUMMON_GARROSH_COMETH, 7s + 500ms);
                    break;

                case EVENT_SUMMON_PORTAL_COMETH:
                    SummonPortalsFromOrgrimmar();
                    break;

                case EVENT_SUMMON_GARROSH_COMETH:
                    SummonGarroshAndHisEliteGuards();
                    break;

                case EVENT_SCENE_TALK_COMETH:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(TALK_SYLVANAS_COMETH_0);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 1, 4s + 500ms);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 1:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        sylvanas->SetFacingTo(0.808979f);

                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(TALK_SYLVANAS_COMETH_1);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 2, 3s + 500ms);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 2:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        garrosh->GetMotionMaster()->MoveJump(GarroshJumpPos, 15.595897f, 15.595897f);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 3, 2s + 500ms);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 3:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        sylvanas->SetFacingTo(3.924652f);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 4, 1s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 4:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                            garrosh->SetFacingToObject(sylvanas);

                        garrosh->PlayOneShotAnimKitId(ANIMKIT_GARROSH_1);

                        if (garrosh->IsAIEnabled())
                            garrosh->AI()->Talk(TALK_GARROSH_COMETH_0);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 5, 12s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 5:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        garrosh->SetFacingTo(3.9444442f);

                        if (garrosh->IsAIEnabled())
                            garrosh->AI()->Talk(TALK_GARROSH_COMETH_1);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 6, 7s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 6:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        sylvanas->SetFacingTo(2.4260077f);

                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(TALK_SYLVANAS_COMETH_2);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 7, 5s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 7:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        sylvanas->SetFacingTo(3.7350047f);
                        sylvanas->PlayOneShotAnimKitId(ANIMKIT_SYLV_1);

                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(TALK_SYLVANAS_COMETH_3);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 8, 16s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 8:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(TALK_SYLVANAS_COMETH_4);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 9, 4s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 9:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        if (garrosh->IsAIEnabled())
                            garrosh->AI()->Talk(TALK_GARROSH_COMETH_2);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 10, 3s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 10:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(TALK_SYLVANAS_COMETH_5);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 11, 6s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 11:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(TALK_SYLVANAS_COMETH_6);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 12, 6s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 12:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        sylvanas->PlayOneShotAnimKitId(ANIMKIT_SYLV_2);

                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(TALK_SYLVANAS_COMETH_7);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 13, 9s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 13:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(TALK_SYLVANAS_COMETH_8);

                        _events.ScheduleEvent(EVENT_AGATHA_RAISE_FORSAKEN, 3s);
                    }
                    break;
                }

                case EVENT_AGATHA_RAISE_FORSAKEN:
                {
                    if (Creature* agatha = ObjectAccessor::GetCreature(*me, _agathaGUID))
                    {
                        agatha->GetMotionMaster()->MovePoint(POINT_AGATHA_PRE_RISE, AgathaPreRisePos, false);

                        _events.ScheduleEvent(EVENT_AGATHA_RAISE_FORSAKEN + 1, 2s + 500ms);
                    }
                    break;
                }

                case EVENT_AGATHA_RAISE_FORSAKEN + 1:
                {
                    if (Creature* agatha = ObjectAccessor::GetCreature(*me, _agathaGUID))
                    {
                        agatha->SetWalk(true);
                        agatha->GetMotionMaster()->MovePoint(POINT_AGATHA_RISE, AgathaRisePos, false);

                        _events.ScheduleEvent(EVENT_AGATHA_RAISE_FORSAKEN + 2, 6s);
                    }
                    break;
                }

                case EVENT_AGATHA_RAISE_FORSAKEN + 2:
                {
                    if (Creature* agatha = ObjectAccessor::GetCreature(*me, _agathaGUID))
                    {
                        agatha->CastSpell(agatha, SPELL_RAISE_FORSAKEN_COMETH);

                        _events.ScheduleEvent(EVENT_AGATHA_RAISE_FORSAKEN + 3, 10s);
                    }
                    break;
                }

                case EVENT_AGATHA_RAISE_FORSAKEN + 3:
                {
                    if (Creature* agatha = ObjectAccessor::GetCreature(*me, _agathaGUID))
                    {
                        agatha->GetMotionMaster()->MovePoint(POINT_AGATHA_PRE_RESET, AgathaPreResetPos, false, 0.855211f);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 14, 750ms);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 14:
                {
                    if (Creature* cromush = ObjectAccessor::GetCreature(*me, _cromushGUID))
                    {
                        if (cromush->IsAIEnabled())
                            cromush->AI()->Talk(TALK_CROMUSH_COMETH_0);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 15, 3s + 500ms);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 15:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        garrosh->PlayOneShotAnimKitId(ANIMKIT_GENERAL_1);

                        if (garrosh->IsAIEnabled())
                            garrosh->AI()->Talk(TALK_GARROSH_COMETH_3);

                        if (Creature* agatha = ObjectAccessor::GetCreature(*me, _agathaGUID))
                            agatha->SetWalk(false);

                        _events.ScheduleEvent(EVENT_AGATHA_RAISE_FORSAKEN + 4, 12s);
                    }
                    break;
                }

                case EVENT_AGATHA_RAISE_FORSAKEN + 4:
                {
                    if (Creature* agatha = ObjectAccessor::GetCreature(*me, _agathaGUID))
                    {
                        agatha->GetMotionMaster()->MovePoint(POINT_AGATHA_RESET, AgathaResetPos, false, 0.7155f);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 16, 1s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 16:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        sylvanas->PlayOneShotAnimKitId(ANIMKIT_GENERAL_1);

                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(TALK_SYLVANAS_COMETH_9);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 17, 10s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 17:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        if (garrosh->IsAIEnabled())
                            garrosh->AI()->Talk(TALK_GARROSH_COMETH_4);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 18, 6s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 18:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        if (garrosh->IsAIEnabled())
                            garrosh->AI()->Talk(TALK_GARROSH_COMETH_5);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 19, 6s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 19:
                {
                    if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, _sylvanasGUID))
                    {
                        if (sylvanas->IsAIEnabled())
                            sylvanas->AI()->Talk(TALK_SYLVANAS_COMETH_10);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 20, 5s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 20:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        garrosh->SetFacingTo(5.51524f);

                        if (garrosh->IsAIEnabled())
                            garrosh->AI()->Talk(TALK_GARROSH_COMETH_6);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 21, 4s + 500ms);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 21:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        if (Creature* cromush = ObjectAccessor::GetCreature(*me, _cromushGUID))
                        {
                            garrosh->SetFacingToObject(cromush);

                            _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 22, 500ms);
                        }
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 22:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        garrosh->PlayOneShotAnimKitId(ANIMKIT_GARROSH_2);

                        if (garrosh->IsAIEnabled())
                            garrosh->AI()->Talk(TALK_GARROSH_COMETH_7);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 23, 14s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 23:
                {
                    if (Creature* cromush = ObjectAccessor::GetCreature(*me, _cromushGUID))
                    {
                        if (cromush->IsAIEnabled())
                            cromush->AI()->Talk(TALK_CROMUSH_COMETH_1);

                        if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                        {
                            cromush->SetFacingToObject(garrosh);

                            _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 24, 2s + 500ms);
                        }
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 24:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        garrosh->SetFacingTo(5.6199603f);
                        garrosh->PlayOneShotAnimKitId(ANIMKIT_GARROSH_2);

                        if (garrosh->IsAIEnabled())
                            garrosh->AI()->Talk(TALK_GARROSH_COMETH_8);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 25, 8s + 500ms);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 25:
                {
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, _garroshGUID))
                    {
                        garrosh->CastSpell(garrosh, SPELL_WELCOME_TO_SILVERPINE_CREDIT, true);

                        garrosh->GetMotionMaster()->MovePath(PATH_GARROSH, false);

                        _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 26, 9s);
                    }
                    break;
                }

                case EVENT_SCENE_TALK_COMETH + 26:
                    DespawnGarroshAndHisEliteGuards();
                    _events.ScheduleEvent(EVENT_SCENE_TALK_COMETH + 27, 500ms);
                    break;

                case EVENT_SCENE_TALK_COMETH + 27:
                    _summons.DespawnAll();
                    Reset();
                    break;

                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;
    }

    void SummonPortalsFromOrgrimmar()
    {
        for (Position const& pos : OrgrimmarPortalPos)
            me->SummonCreature(NPC_PORTAL_FROM_ORGRIMMAR, pos, TEMPSUMMON_TIMED_DESPAWN, 300s);

        std::list<Creature*> orgrimmarPortals;
        GetCreatureListWithEntryInGrid(orgrimmarPortals, me, NPC_PORTAL_FROM_ORGRIMMAR, 100.0f);

        for (Creature* portal : orgrimmarPortals)
            portal->CastSpell(portal, SPELL_AIR_REVENANT_ENTRANCE);
    }

    void SummonGarroshAndHisEliteGuards()
    {
        for (Position const& pos : HellscreamElitePos)
            me->SummonCreature(NPC_HELLSCREAM_ELITE_COMETH, pos, TEMPSUMMON_TIMED_DESPAWN, 300s);

        me->SummonCreature(NPC_GARROSH_HELLSCREAM, GarroshPos, TEMPSUMMON_TIMED_DESPAWN, 300s);

        if (Creature* cromush = me->SummonCreature(NPC_HIGH_WARLORD_CROMUSH_COMETH, CromushPos, TEMPSUMMON_TIMED_DESPAWN, 300s))
        {
            _cromushGUID = cromush->GetGUID();

            cromush->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
            cromush->GetMotionMaster()->MovePath(PATH_CROMUSH, false);
        }
    }

    void DespawnGarroshAndHisEliteGuards()
    {
        for (ObjectGuid const& summonedCreature : _summons)
        {
            if (Creature* summon = ObjectAccessor::GetCreature(*me, summonedCreature))
                summon->CastSpell(summon, SPELL_SIMPLE_TELEPORT);
        }
    }

private:
    EventMap _events;
    ObjectGuid _garroshGUID;
    ObjectGuid _cromushGUID;
    ObjectGuid _sylvanasGUID;
    ObjectGuid _agathaGUID;
    SummonList _summons;
    bool _eventInProgress;
};

enum RaiseForsakenCometh
{
    ACTION_RISE_DURING_RAISE                = 1,
    ACTION_DESCEND_AFTER_RAISE              = 2,

    POINT_BEING_RISEN                       = 1,

    ANIMKIT_RESET                           = 0,
    ANIMKIT_FALLEN_HUMAN                    = 721
};

// 83173 - Raise Forsaken
class spell_silverpine_raise_forsaken_83173 : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (Creature* fallenHuman = target->ToCreature())
        {
            if (fallenHuman->IsAIEnabled())
                fallenHuman->AI()->DoAction(ACTION_RISE_DURING_RAISE);
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (Creature* fallenHuman = target->ToCreature())
        {
            if (fallenHuman->IsAIEnabled())
                fallenHuman->AI()->DoAction(ACTION_DESCEND_AFTER_RAISE);
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_silverpine_raise_forsaken_83173::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_silverpine_raise_forsaken_83173::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum FallenHuman
{
    SPELL_FEIGNED                               = 80636,
    SPELL_FORSAKEN_TROOPER_MS_COMETH            = 83149,

    EVENT_ASCEND                                = 1,
    EVENT_TRANSFORM_INTO_FORSAKEN               = 2,
    EVENT_FACE_TOWARDS_SYLVANAS                 = 3,
    EVENT_EMOTE_TO_SYLVANAS                     = 4
};

// 44592, 44593 - Fallen Human
struct npc_silverpine_fallen_human : public ScriptedAI
{
    npc_silverpine_fallen_human(Creature* creature) : ScriptedAI(creature), _transformDone(false) {}

    void Reset() override
    {
        _transformDone = false;
        _events.Reset();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_RISE_DURING_RAISE:
                me->SetAIAnimKitId(ANIMKIT_FALLEN_HUMAN);
                _events.ScheduleEvent(EVENT_ASCEND, 1s);
                break;

            case ACTION_DESCEND_AFTER_RAISE:
                me->SetWalk(false);
                me->SetAIAnimKitId(ANIMKIT_RESET);
                me->GetMotionMaster()->MoveFall();
                _events.ScheduleEvent(EVENT_TRANSFORM_INTO_FORSAKEN, 1s);
                break;

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ASCEND:
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_BEING_RISEN, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 3.5f, false);
                    break;

                case EVENT_TRANSFORM_INTO_FORSAKEN:
                {
                    if (_transformDone)
                        return;

                    DoCastSelf(SPELL_FORSAKEN_TROOPER_MS_COMETH);

                    _transformDone = true;

                    _events.ScheduleEvent(EVENT_FACE_TOWARDS_SYLVANAS, 1s + 500ms);
                    break;
                }

                case EVENT_FACE_TOWARDS_SYLVANAS:
                    me->SetFacingTo(0.706837f);
                    _events.ScheduleEvent(EVENT_EMOTE_TO_SYLVANAS, 2s + 500ms);
                    break;

                case EVENT_EMOTE_TO_SYLVANAS:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                    me->DespawnOrUnsummon(80s);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _transformDone;
};

enum SpellForsakenTrooperMasterScriptCometh
{
    SPELL_FORSAKEN_TROOPER_MALE_01_HC       = 83150,
    SPELL_FORSAKEN_TROOPER_MALE_02_HC       = 83163,
    SPELL_FORSAKEN_TROOPER_MALE_03_HC       = 83164,
    SPELL_FORSAKEN_TROOPER_MALE_04_HC       = 83165,
    SPELL_FORSAKEN_TROOPER_FEMALE_01_HC     = 83152,
    SPELL_FORSAKEN_TROOPER_FEMALE_02_HC     = 83166,
    SPELL_FORSAKEN_TROOPER_FEMALE_03_HC     = 83167,
    SPELL_FORSAKEN_TROOPER_FEMALE_04_HC     = 83168,

    DISPLAY_MALE_01_HC                      = 33978,
    DISPLAY_MALE_02_HC                      = 33980,
    DISPLAY_MALE_03_HC                      = 33979,
    DISPLAY_MALE_04_HC                      = 33981,
    DISPLAY_FEMALE_01_HC                    = 33982,
    DISPLAY_FEMALE_02_HC                    = 33983,
    DISPLAY_FEMALE_03_HC                    = 33984,
    DISPLAY_FEMALE_04_HC                    = 33985
};

// 83149 - Forsaken Trooper Master Script (Forsaken High Command)
class spell_silverpine_forsaken_trooper_masterscript_high_command : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_FORSAKEN_TROOPER_MALE_01_HC,
            SPELL_FORSAKEN_TROOPER_MALE_02_HC,
            SPELL_FORSAKEN_TROOPER_MALE_03_HC,
            SPELL_FORSAKEN_TROOPER_MALE_04_HC,
            SPELL_FORSAKEN_TROOPER_FEMALE_01_HC,
            SPELL_FORSAKEN_TROOPER_FEMALE_02_HC,
            SPELL_FORSAKEN_TROOPER_FEMALE_03_HC,
            SPELL_FORSAKEN_TROOPER_FEMALE_04_HC
        });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            caster->RemoveAura(SPELL_FEIGNED);

            uint32 spellId = SPELL_FORSAKEN_TROOPER_MALE_01_HC;

            switch (caster->GetDisplayId())
            {
                case DISPLAY_MALE_01_HC:
                    spellId = SPELL_FORSAKEN_TROOPER_MALE_01_HC;
                    break;
                case DISPLAY_MALE_02_HC:
                    spellId = SPELL_FORSAKEN_TROOPER_MALE_02_HC;
                    break;
                case DISPLAY_MALE_03_HC:
                    spellId = SPELL_FORSAKEN_TROOPER_MALE_03_HC;
                    break;
                case DISPLAY_MALE_04_HC:
                    spellId = SPELL_FORSAKEN_TROOPER_MALE_04_HC;
                    break;
                case DISPLAY_FEMALE_01_HC:
                    spellId = SPELL_FORSAKEN_TROOPER_FEMALE_01_HC;
                    break;
                case DISPLAY_FEMALE_02_HC:
                    spellId = SPELL_FORSAKEN_TROOPER_FEMALE_02_HC;
                    break;
                case DISPLAY_FEMALE_03_HC:
                    spellId = SPELL_FORSAKEN_TROOPER_FEMALE_03_HC;
                    break;
                case DISPLAY_FEMALE_04_HC:
                    spellId = SPELL_FORSAKEN_TROOPER_FEMALE_04_HC;
                    break;
                default:
                    break;
            }

            caster->CastSpell(caster, spellId, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_forsaken_trooper_masterscript_high_command::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum SylvanasForsakenHighCommand
{
    QUEST_NO_ESCAPE                             = 27099,
    QUEST_LORDAERON                             = 27098,
    QUEST_TO_FORSAKEN_HIGH_COMMAND              = 27290,

    NPC_FORSAKEN_WARHORSE_SERVERSIDE            = 73595,

    SPELL_SUMMON_FORSAKEN_WARHORSE_SERVERSIDE   = 148164,
    SPELL_APPLY_INVIS_ZONE_1                    = 83231,
    SPELL_APPLY_INVIS_ZONE_4                    = 84183,
    SPELL_DESPAWN_ALL_SUMMONS_NO_ESCAPE         = 84011,
    SPELL_SUMMON_SYLVANAS_AND_HORSE             = 84128,
    SPELL_SUMMON_FORSAKEN_WARHORSE              = 84164,
    SPELL_SUMMON_LORDAERON_ACTORS               = 84127,
    SPELL_FLIGHT_OF_THE_VALKYR_FORWARD          = 84695
};

// 44365 - Lady Sylvanas Windrunner (Forsaken High Command and Sepulcher)
struct npc_silverpine_sylvanas_windrunner_high_command_sepulcher : public ScriptedAI
{
    npc_silverpine_sylvanas_windrunner_high_command_sepulcher(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SUMMON_FORSAKEN_WARHORSE_SERVERSIDE);
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_FORSAKEN_WARHORSE_SERVERSIDE:
                // Note: the Forsaken Horse must be set in the same visibility mask that Sylvanas is in.
                summon->CastSpell(summon, me->HasAura(SPELL_APPLY_INVIS_ZONE_1) ? SPELL_APPLY_INVIS_ZONE_1 : SPELL_APPLY_INVIS_ZONE_4, true);
                break;
            default:
                break;
        }
    }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        switch (quest->GetQuestId())
        {
            case QUEST_LORDAERON:
                player->CastSpell(player, SPELL_SUMMON_SYLVANAS_AND_HORSE, true);
                player->CastSpell(player, SPELL_SUMMON_FORSAKEN_WARHORSE, true);
                player->CastSpell(player, SPELL_SUMMON_LORDAERON_ACTORS, true);
                break;

            case QUEST_TO_FORSAKEN_HIGH_COMMAND:
                player->CastSpell(player, SPELL_FLIGHT_OF_THE_VALKYR_FORWARD, true);
                break;

            default:
                break;
        }
    }

    void OnQuestReward(Player* player, Quest const* quest, LootItemType /*type*/, uint32 /*opt*/) override
    {
        switch (quest->GetQuestId())
        {
            case QUEST_NO_ESCAPE:
                player->CastSpell(player, SPELL_DESPAWN_ALL_SUMMONS_NO_ESCAPE, true);
                break;
            case QUEST_LORDAERON:
                player->RemoveAura(SPELL_SUMMON_FORSAKEN_WARHORSE);
                break;
            default:
                break;
        }
    }
};

// 44789, 44790 - Deathstalker and Deathstalker Commander Belmont
struct npc_silverpine_deathstalker : public ScriptedAI
{
    npc_silverpine_deathstalker(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        // @TODO: figure out a common system to allow energy usage without scripts.
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 100, true);
    }
};

enum WorgenRenegade
{
    SPELL_KILL_ME_AURA                          = 84181,
    SPELL_FLURRY_OF_CLAWS                       = 80365,

    EVENT_FLURRY_OF_CLAWS                       = 1
};

// 44793 - Worgen Renegade
struct npc_silverpine_worgen_renegade : public ScriptedAI
{
    npc_silverpine_worgen_renegade(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (me->IsSummon())
            DoCastSelf(SPELL_KILL_ME_AURA);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_FLURRY_OF_CLAWS, 3s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FLURRY_OF_CLAWS:
                    DoCastVictim(SPELL_FLURRY_OF_CLAWS);
                    _events.Repeat(15s, 18s);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 80365 - Flurry of Claws
class spell_silverpine_flurry_of_claws : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(nullptr, GetSpellInfo()->GetEffect(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_silverpine_flurry_of_claws::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

enum ForsakenTrooper
{
    NPC_WORGEN_RENEGADE                         = 44793,

    SPELL_CLEAVE                                = 19983,

    EVENT_CLEAVE                                = 1,

    TALK_TROOPER_RESET                          = 0
};

// 44791, 44792 - Forsaken Trooper
struct npc_silverpine_forsaken_trooper : public ScriptedAI
{
    npc_silverpine_forsaken_trooper(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();

        // Note: these texts are sent aswell during Lordaeron (questId 27098).
        if (urand(0, 1))
            Talk(TALK_TROOPER_RESET);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_CLEAVE, 5s, 8s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    _events.Repeat(5s, 8s);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

enum BatHandlerMaggothbreath
{
    QUEST_ITERATING_UPON_SUCCESS                = 26998,

    SPELL_SUMMON_FORSAKEN_BAT                   = 83584,

    TALK_MAGGOTHBREATH_ITERATING_UPON_SUCCESS   = 0,

    DATA_GOSSIP_MENU_MAGGOT                     = 11892
};

// 44825 - Bat Handler Maggotbreath
struct npc_silverpine_bat_handler_maggotbreath : public ScriptedAI
{
    npc_silverpine_bat_handler_maggotbreath(Creature* creature) : ScriptedAI(creature) { }

    bool OnGossipHello(Player* player) override
    {
        if (player->GetQuestStatus(QUEST_ITERATING_UPON_SUCCESS) == QUEST_STATUS_INCOMPLETE)
            AddGossipItemFor(player, DATA_GOSSIP_MENU_MAGGOT, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        if (me->IsTaxi())
            AddGossipItemFor(player, DATA_GOSSIP_MENU_MAGGOT, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        switch (player->PlayerTalkClass->GetGossipOptionAction(gossipListId))
        {
            case GOSSIP_ACTION_INFO_DEF:
                Talk(TALK_MAGGOTHBREATH_ITERATING_UPON_SUCCESS, player);
                player->CastSpell(player, SPELL_SUMMON_FORSAKEN_BAT, true);
                break;

            // Note: Blizzard messed up this OptionNpc. It sends GossipOptionNpc::None rather than GossipOptionNpc::TaxiNode,
            // making it useless. To keep it blizzlike, we're just sending TaxiMenu forcefully as well.
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->GetSession()->SendTaxiMenu(me);
                break;

            default:
                break;
        }

        CloseGossipMenuFor(player);
        return true;
    }
};

enum ForsakenBat
{
    NPC_VILE_FIN_ORACLE                         = 1908,
    NPC_BAT_HANDLER_MAGGOTBREATH                = 44825,
    NPC_FORSAKEN_BAT                            = 44821,

    SPELL_BLIGHT_CONCOCTION                     = 83573,
    SPELL_GO_HOME                               = 83594,

    EVENT_CHECK_FINISH_ITERATING                = 1,
    EVENT_START_MOVEMENT_ITERATING              = 2,
    EVENT_GO_HOME_ITERATING                     = 3,

    ACTION_GO_HOME                              = 1,

    TALK_BAT_ARRIVED_TO_ISLE                    = 0,
    TALK_BAT_GOING_HOME                         = 1,

    PATH_BAT_TO_LAKE                            = 3585680,
    PATH_BAT_AROUND_LAKE                        = 3585688,
    PATH_BAT_TO_HOME                            = 3585696,

    WAYPOINT_LAST_POINT_TO_LAKE                 = 8,
    WAYPOINT_LAST_POINT_AROUND_LAKE             = 32,
    WAYPOINT_LAST_POINT_TO_HOME                 = 7,

    DATA_ITERATING_UPON_SUCCESS_QUEST_REQ       = 50
};

// 44821 - Forsaken Bat
struct npc_silverpine_forsaken_bat : public VehicleAI
{
    npc_silverpine_forsaken_bat(Creature* creature) : VehicleAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        SetInitialActionBar();
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
            _playerGUID = player->GetGUID();

        me->SetDisableGravity(true);
    }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (apply)
        {
            if (Player* player = passenger->ToPlayer())
            {
                if (player->GetQuestStatus(QUEST_ITERATING_UPON_SUCCESS) == QUEST_STATUS_INCOMPLETE)
                {
                    player->KilledMonsterCredit(NPC_BAT_HANDLER_MAGGOTBREATH);

                    me->SetUninteractible(true);

                    me->SetSpeed(UnitMoveType::MOVE_RUN, 17.794235f);
                    me->GetMotionMaster()->MovePath(PATH_BAT_TO_LAKE, false);

                    _events.ScheduleEvent(EVENT_CHECK_FINISH_ITERATING, 500ms);
                }
            }
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_BAT_TO_LAKE:
            {
                if (waypointId == WAYPOINT_LAST_POINT_TO_LAKE)
                {
                    me->SetSpeed(UnitMoveType::MOVE_RUN, 17.982668f);
                    me->GetMotionMaster()->MovePath(PATH_BAT_AROUND_LAKE, false);

                    SetCircularActionBar();

                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        Talk(TALK_BAT_ARRIVED_TO_ISLE, player);

                        player->VehicleSpellInitialize();
                    }
                }
                break;
            }

            case PATH_BAT_AROUND_LAKE:
            {
                if (waypointId == WAYPOINT_LAST_POINT_AROUND_LAKE)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        if (player->GetQuestStatus(QUEST_ITERATING_UPON_SUCCESS) == QUEST_STATUS_INCOMPLETE)
                            me->GetMotionMaster()->MovePath(PATH_BAT_AROUND_LAKE, false);
                    }
                }
                break;
            }

            case PATH_BAT_TO_HOME:
            {
                if (waypointId == WAYPOINT_LAST_POINT_TO_HOME)
                {
                    me->GetVehicleKit()->RemoveAllPassengers();
                    me->DespawnOrUnsummon();
                }
                break;
            }

            default:
                break;
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_GO_HOME)
            DoAction(ACTION_GO_HOME);
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case ACTION_GO_HOME:
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    me->PauseMovement();
                    me->GetMotionMaster()->Clear();
                    me->SetSpeed(UnitMoveType::MOVE_RUN, 35.78791f);
                    me->GetMotionMaster()->MovePath(PATH_BAT_TO_HOME, false);

                    SetFinishActionBar();

                    player->VehicleSpellInitialize();

                    Talk(TALK_BAT_GOING_HOME, player);
                }
                break;
            }

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHECK_FINISH_ITERATING:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        if (player->GetReqKillOrCastCurrentCount(QUEST_ITERATING_UPON_SUCCESS, NPC_VILE_FIN_ORACLE) == DATA_ITERATING_UPON_SUCCESS_QUEST_REQ)
                            player->CastSpell(me, SPELL_GO_HOME, true);
                        else
                            _events.ScheduleEvent(EVENT_CHECK_FINISH_ITERATING, 500ms);
                    }
                    break;
                }

                default:
                    break;
            }
        }
    }

    void SetInitialActionBar()
    {
        me->m_spells[0] = SPELL_BLIGHT_CONCOCTION;
        me->m_spells[1] = 0;
    }

    void SetCircularActionBar()
    {
        me->m_spells[0] = SPELL_BLIGHT_CONCOCTION;
        me->m_spells[1] = SPELL_GO_HOME;
    }

    void SetFinishActionBar()
    {
        me->m_spells[0] = 0;
        me->m_spells[1] = 0;
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;
};

enum AbandonedOuthouse
{
    QUEST_WAITING_TO_EXSANGUINATE           = 27045,

    SPELL_SUMMON_DEATHSTALKER_YORICK        = 83751
};

// 205143 - Abandoned Outhouse
struct go_silverpine_abandoned_outhouse : public GameObjectAI
{
    go_silverpine_abandoned_outhouse(GameObject* go) : GameObjectAI(go) { }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_WAITING_TO_EXSANGUINATE)
            player->CastSpell(player, SPELL_SUMMON_DEATHSTALKER_YORICK, true);
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        player->CastSpell(player, SPELL_SUMMON_DEATHSTALKER_YORICK, true);
        CloseGossipMenuFor(player);
        return false;
    }
};

Position const YorickReadyPosition = { 1313.7f, 1211.99f, 58.5f, 4.564474f };

Position const YorickDeathPosition = { 1295.52f, 1206.58f, 58.501f };

enum DeathstalkerRaneYorick
{
    PHASE_WAITING_TO_EXSANGUINATE           = 265,

    NPC_ARMOIRE_SUMMONED                    = 44893,
    NPC_PACKLEADER_IVAR_BLOODFANG           = 44884,

    SPELL_STEALTH                           = 34189,
    SPELL_PERMANENT_FEIGN_DEATH             = 29266,
    SPELL_HIDDEN_IN_ARMOIRE                 = 83788,
    SPELL_SUMMON_YORICK                     = 83751,
    SPELL_CANCEL_SUMMON_YORICK              = 83755,

    EVENT_START_QUEST_EXSANGUINATE          = 1,
    EVENT_WAIT_FOR_PLAYER_EXSANGUINATE      = 3,
    EVENT_RANE_HIDE                         = 4,
    EVENT_SET_GUID_FOR_ARMOIRE              = 5,
    EVENT_RANE_TALK_TO_PLAYER               = 6,
    EVENT_RANE_LAST_MOVE                    = 7,
    EVENT_RANE_SKIPS_PATH                   = 9,

    ACTION_RANE_JUMP_DEATH                  = 1,
    ACTION_RANE_SKIP_PATH                   = 2,

    TALK_YORICK_EXSANGUINATE_SUMMON         = 0,
    TALK_YORICK_EXSANGUINATE_HIDE           = 1,

    PATH_YORICK_UP                          = 3590560,
    PATH_YORICK_HIDE                        = 3590568,

    WAYPOINT_CLOSE_TO_ARMOIRE               = 15,
    WAYPOINT_HIDDEN_NEXT_TO_ARMOIRE         = 2
};

// 44882 - Deathstalker Rane Yorick
struct npc_silverpine_deathstalker_rane_yorick : public ScriptedAI
{
    npc_silverpine_deathstalker_rane_yorick(Creature* creature) : ScriptedAI(creature), _playerArrived(false), _playerSkipped(false) { }

    void JustAppeared() override
    {
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 100, true);
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        me->SetFacingToObject(summoner);

        _events.ScheduleEvent(EVENT_START_QUEST_EXSANGUINATE, 1s);
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_YORICK_UP && waypointId == WAYPOINT_CLOSE_TO_ARMOIRE)
            _events.ScheduleEvent(EVENT_WAIT_FOR_PLAYER_EXSANGUINATE, 1s);

        if (pathId == PATH_YORICK_HIDE && waypointId == WAYPOINT_HIDDEN_NEXT_TO_ARMOIRE)
        {
            me->SetFacingTo(4.6425757f);

            DoCastSelf(SPELL_STEALTH);

            me->SetUninteractible(true);

            _playerSkipped = true;
        }
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case ACTION_RANE_JUMP_DEATH:
                me->SetDisableGravity(true);
                _events.ScheduleEvent(EVENT_RANE_LAST_MOVE, 10ms);
                break;

            case ACTION_RANE_SKIP_PATH:
                me->PauseMovement();
                me->GetMotionMaster()->Clear();
                _events.Reset();
                _events.ScheduleEvent(EVENT_RANE_SKIPS_PATH, 250ms);
                break;

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        _events.Update(diff);

        if (Unit* summoner = tempSummon->GetSummonerUnit())
        {
            // Note: SummonPropertiesFlags::DespawnWhenExpired is NYI.
            if (!summoner->HasAura(SPELL_SUMMON_YORICK))
                me->DespawnOrUnsummon();
        }

        if (!_playerSkipped)
        {
            if (Unit* summoner = tempSummon->GetSummonerUnit())
            {
                if (summoner->HasAura(SPELL_HIDDEN_IN_ARMOIRE))
                {
                    _playerSkipped = true;

                    DoAction(ACTION_RANE_SKIP_PATH);
                }
            }
        }

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_QUEST_EXSANGUINATE:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        Talk(TALK_YORICK_EXSANGUINATE_SUMMON, summoner);

                        _events.ScheduleEvent(EVENT_START_QUEST_EXSANGUINATE + 1, 1s + 500ms);
                    }
                    break;
                }

                case EVENT_START_QUEST_EXSANGUINATE + 1:
                    me->GetMotionMaster()->MovePath(PATH_YORICK_UP, false);
                    break;

                case EVENT_WAIT_FOR_PLAYER_EXSANGUINATE:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (summoner->GetDistance2d(me) <= 5.0f && !_playerArrived)
                        {
                            _events.ScheduleEvent(EVENT_RANE_TALK_TO_PLAYER, 1s);
                            _playerArrived = true;
                        }
                        else
                            _events.ScheduleEvent(EVENT_WAIT_FOR_PLAYER_EXSANGUINATE, 1s);
                    }
                    break;
                }

                case EVENT_RANE_TALK_TO_PLAYER:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        Talk(TALK_YORICK_EXSANGUINATE_HIDE, summoner);

                        _events.ScheduleEvent(EVENT_RANE_HIDE, 3s);
                        _events.ScheduleEvent(EVENT_SET_GUID_FOR_ARMOIRE, 1s);
                    }
                    break;
                }

                case EVENT_RANE_HIDE:
                    me->GetMotionMaster()->MovePath(PATH_YORICK_HIDE, false);
                    break;

                case EVENT_SET_GUID_FOR_ARMOIRE:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (!_bloodfangGUID)
                        {
                            if (Creature* bloodfang = me->FindNearestCreature(NPC_PACKLEADER_IVAR_BLOODFANG, 30.0f))
                            {
                                if (bloodfang->GetOwnerGUID() == summoner->GetGUID())
                                    _bloodfangGUID = bloodfang->GetGUID();
                            }
                        }

                        if (!_armoireGUID)
                        {
                            if (Creature* armoire = me->FindNearestCreature(NPC_ARMOIRE_SUMMONED, 30.0f))
                            {
                                if (armoire->GetOwnerGUID() == summoner->GetGUID())
                                {
                                    _armoireGUID = armoire->GetGUID();

                                    if (armoire->IsAIEnabled())
                                        armoire->GetAI()->SetGUID(me->GetGUID(), me->GetEntry());
                                }
                            }
                        }
                    }

                    if (!_bloodfangGUID || !_armoireGUID)
                        _events.ScheduleEvent(EVENT_SET_GUID_FOR_ARMOIRE, 1s);
                    break;
                }

                case EVENT_RANE_LAST_MOVE:
                    me->GetMotionMaster()->MoveJump(YorickDeathPosition, 10.0f, 10.0f);
                    DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH);
                    _events.ScheduleEvent(EVENT_RANE_LAST_MOVE + 1, 2s);
                    break;

                case EVENT_RANE_LAST_MOVE + 1:
                    me->SetDisableGravity(false);
                    break;

                case EVENT_RANE_SKIPS_PATH:
                    me->NearTeleportTo(YorickReadyPosition, false);
                    _events.ScheduleEvent(EVENT_RANE_SKIPS_PATH + 1, 250ms);
                    break;

                case EVENT_RANE_SKIPS_PATH + 1:
                    DoCastSelf(SPELL_STEALTH);
                    me->SetUninteractible(true);
                    _events.ScheduleEvent(EVENT_SET_GUID_FOR_ARMOIRE, 500ms);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    ObjectGuid _armoireGUID;
    ObjectGuid _bloodfangGUID;
    bool _playerArrived;
    bool _playerSkipped;
};

enum WaitingToExsanguinate
{
    NPC_DEATHSTALKER_RANE_YORICK            = 44882,
    NPC_LORD_DARIUS_CROWLEY                 = 44883,

    SPELL_SUMMON_CROWLEY_BLOODFANG_MASTER   = 83762,
    SPELL_ARMOIRE_CAMERA_ON_CROWLEY         = 83763,
    SPELL_ARMOIRE_CAMERA_ON_BLOODFANG       = 83764,
    SPELL_RIDE_REVERSE_CAST_EXSANGUINATE    = 83781,
    SPELL_EJECT_PASSENGER_01                = 80743,
    SPELL_KILL_CREDIT_YORICK                = 83786,
    SPELL_HIDE_IN_ARMOIRE                   = 83788,

    EVENT_START_SCENE_EXSANGUINATE          = 1,
    EVENT_TALK_SCENE_EXSANGUINATE           = 4,
    EVENT_ACTION_SCENE_EXSANGUINATE         = 27,
    EVENT_SWITCH_SCENE_CAMERA               = 33,
    EVENT_FINISH_SCENE_EXSANGUINATE         = 40,

    TALK_YORICK_EXSANGUINATE_DEATH           = 2,
    TALK_CROWLEY_EXSANGUINATE_0              = 0,
    TALK_CROWLEY_EXSANGUINATE_1              = 1,
    TALK_CROWLEY_EXSANGUINATE_2              = 2,
    TALK_CROWLEY_EXSANGUINATE_3              = 3,
    TALK_CROWLEY_EXSANGUINATE_4              = 4,
    TALK_CROWLEY_EXSANGUINATE_5              = 5,
    TALK_CROWLEY_EXSANGUINATE_6              = 6,
    TALK_BLOODFANG_EXSANGUINATE_0            = 0,
    TALK_BLOODFANG_EXSANGUINATE_1            = 1,
    TALK_BLOODFANG_EXSANGUINATE_2            = 2,
    TALK_BLOODFANG_EXSANGUINATE_3            = 3,
    TALK_BLOODFANG_EXSANGUINATE_4            = 4,
    TALK_BLOODFANG_EXSANGUINATE_5            = 5,
    TALK_BLOODFANG_EXSANGUINATE_6            = 6,
    TALK_BLOODFANG_EXSANGUINATE_7            = 7,
    TALK_BLOODFANG_EXSANGUINATE_8            = 8,
    TALK_BLOODFANG_EXSANGUINATE_9            = 9,
    TALK_BLOODFANG_EXSANGUINATE_10           = 10,

    PATH_CROWLEY_ENTER                       = 3590640,
    PATH_BLOODFANG_ENTER                     = 3590720,
    PATH_BLOODFANG_NEAR_YORICK               = 3590728,
    PATH_BLOODFANG_WITH_YORICK               = 3590736,
    PATH_BLOODFANG_EXIT                      = 3590744,
    PATH_CROWLEY_EXIT                        = 3590648
};

// 44893 - Armoire
struct npc_silverpine_armoire : public VehicleAI
{
    npc_silverpine_armoire(Creature* creature) : VehicleAI(creature) { }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (apply)
        {
            if (Player* player = passenger->ToPlayer())
            {
                if (player->GetQuestStatus(QUEST_WAITING_TO_EXSANGUINATE) == QUEST_STATUS_INCOMPLETE)
                    _events.ScheduleEvent(EVENT_START_SCENE_EXSANGUINATE, 400ms);
            }
        }
        else
        {
            if (Creature* crowley = ObjectAccessor::GetCreature(*me, _crowleyGUID))
                crowley->DespawnOrUnsummon();

            if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                bloodfang->DespawnOrUnsummon();

            if (Creature* yorick = ObjectAccessor::GetCreature(*me, _yorickGUID))
                yorick->CastSpell(nullptr, SPELL_CANCEL_SUMMON_YORICK, true);

            me->DespawnOrUnsummon(1s);
        }
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        switch (id)
        {
            case NPC_DEATHSTALKER_RANE_YORICK:
                _yorickGUID = guid;
                break;

            case NPC_LORD_DARIUS_CROWLEY:
                _crowleyGUID = guid;
                break;

            case NPC_PACKLEADER_IVAR_BLOODFANG:
                _bloodfangGUID = guid;
                break;

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_SCENE_EXSANGUINATE:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        summoner->CastSpell(summoner, SPELL_SUMMON_CROWLEY_BLOODFANG_MASTER, true);

                        _events.ScheduleEvent(EVENT_START_SCENE_EXSANGUINATE + 1, 100ms);
                    }
                    break;
                }

                case EVENT_START_SCENE_EXSANGUINATE + 1:
                {
                    if (Creature* crowley = ObjectAccessor::GetCreature(*me, _crowleyGUID))
                    {
                        crowley->GetMotionMaster()->MovePath(PATH_CROWLEY_ENTER, false);

                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            bloodfang->GetMotionMaster()->MovePath(PATH_BLOODFANG_ENTER, false);

                            _events.ScheduleEvent(EVENT_START_SCENE_EXSANGUINATE + 2, 7s);
                        }
                    }
                    break;
                }

                case EVENT_START_SCENE_EXSANGUINATE + 2:
                {
                    if (Creature* crowley = ObjectAccessor::GetCreature(*me, _crowleyGUID))
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            crowley->SetFacingToObject(bloodfang);

                            bloodfang->SetFacingToObject(crowley);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE, 2s);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* crowley = ObjectAccessor::GetCreature(*me, _crowleyGUID))
                        {
                            if (crowley->IsAIEnabled())
                                crowley->AI()->Talk(TALK_CROWLEY_EXSANGUINATE_0, summoner);

                            _events.ScheduleEvent(EVENT_SWITCH_SCENE_CAMERA, 3s + 900ms);
                        }
                    }
                    break;
                }

                case EVENT_SWITCH_SCENE_CAMERA:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        summoner->CastSpell(nullptr, SPELL_ARMOIRE_CAMERA_ON_BLOODFANG, true);

                        _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 1, 2s + 500ms);
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 1:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            if (bloodfang->IsAIEnabled())
                                bloodfang->AI()->Talk(TALK_BLOODFANG_EXSANGUINATE_0, summoner);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 2, 3s + 100ms);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 2:
                {
                    if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                    {
                        bloodfang->HandleEmoteCommand(EMOTE_ONESHOT_POINT);

                        _events.ScheduleEvent(EVENT_SWITCH_SCENE_CAMERA + 1, 4s + 800ms);
                    }
                    break;
                }

                case EVENT_SWITCH_SCENE_CAMERA + 1:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        summoner->CastSpell(nullptr, SPELL_ARMOIRE_CAMERA_ON_CROWLEY, true);

                        _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 3, 2s + 500ms);
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 3:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* crowley = ObjectAccessor::GetCreature(*me, _crowleyGUID))
                        {
                            if (crowley->IsAIEnabled())
                                crowley->AI()->Talk(TALK_CROWLEY_EXSANGUINATE_1, summoner);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 4, 3s + 500ms);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 4:
                {
                    if (Creature* crowley = ObjectAccessor::GetCreature(*me, _crowleyGUID))
                    {
                        crowley->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);

                        _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 5, 5s + 400ms);
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 5:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* crowley = ObjectAccessor::GetCreature(*me, _crowleyGUID))
                        {
                            if (crowley->IsAIEnabled())
                                crowley->AI()->Talk(TALK_CROWLEY_EXSANGUINATE_2, summoner);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 6, 3s + 100ms);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 6:
                {
                    if (Creature* crowley = ObjectAccessor::GetCreature(*me, _crowleyGUID))
                    {
                        crowley->HandleEmoteCommand(EMOTE_ONESHOT_TALK);

                        _events.ScheduleEvent(EVENT_SWITCH_SCENE_CAMERA + 2, 3s + 550ms);
                    }
                    break;
                }

                case EVENT_SWITCH_SCENE_CAMERA + 2:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        summoner->CastSpell(nullptr, SPELL_ARMOIRE_CAMERA_ON_BLOODFANG, true);

                        _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 7, 2s + 500ms);
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 7:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            if (bloodfang->IsAIEnabled())
                                bloodfang->AI()->Talk(TALK_BLOODFANG_EXSANGUINATE_1, summoner);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 8, 3s + 800ms);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 8:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            if (bloodfang->IsAIEnabled())
                                bloodfang->AI()->Talk(TALK_BLOODFANG_EXSANGUINATE_2, summoner);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 9, 2s + 400ms);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 9:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            if (bloodfang->IsAIEnabled())
                                bloodfang->AI()->Talk(TALK_BLOODFANG_EXSANGUINATE_3, summoner);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 10, 3s + 900ms);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 10:
                {
                    if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                    {
                        bloodfang->HandleEmoteCommand(EMOTE_ONESHOT_TALK);

                        _events.ScheduleEvent(EVENT_SWITCH_SCENE_CAMERA + 3, 4s + 450ms);
                    }
                    break;
                }

                case EVENT_SWITCH_SCENE_CAMERA + 3:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        summoner->CastSpell(nullptr, SPELL_ARMOIRE_CAMERA_ON_CROWLEY, true);

                        _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 11, 3s);
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 11:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* crowley = ObjectAccessor::GetCreature(*me, _crowleyGUID))
                        {
                            if (crowley->IsAIEnabled())
                                crowley->AI()->Talk(TALK_CROWLEY_EXSANGUINATE_3, summoner);

                            _events.ScheduleEvent(EVENT_SWITCH_SCENE_CAMERA + 4, 1s + 900ms);
                        }
                    }
                    break;
                }

                case EVENT_SWITCH_SCENE_CAMERA + 4:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        summoner->CastSpell(nullptr, SPELL_ARMOIRE_CAMERA_ON_BLOODFANG, true);

                        _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 12, 2s + 500ms);
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 12:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            if (bloodfang->IsAIEnabled())
                                bloodfang->AI()->Talk(TALK_BLOODFANG_EXSANGUINATE_4, summoner);

                            _events.ScheduleEvent(EVENT_ACTION_SCENE_EXSANGUINATE, 2s + 300ms);
                        }
                    }
                    break;
                }

                case EVENT_ACTION_SCENE_EXSANGUINATE:
                {
                    if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                    {
                        bloodfang->SetFacingTo(0.6457718f);

                        _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 13, 1s + 300ms);
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 13:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            if (bloodfang->IsAIEnabled())
                                bloodfang->AI()->Talk(TALK_BLOODFANG_EXSANGUINATE_5, summoner);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 14, 4s);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 14:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            if (bloodfang->IsAIEnabled())
                                bloodfang->AI()->Talk(TALK_BLOODFANG_EXSANGUINATE_6, summoner);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 15, 3s + 500ms);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 15:
                {
                    if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                    {
                        bloodfang->HandleEmoteCommand(EMOTE_ONESHOT_YES);

                        _events.ScheduleEvent(EVENT_ACTION_SCENE_EXSANGUINATE + 1, 2s + 800ms);
                    }
                    break;
                }

                case EVENT_ACTION_SCENE_EXSANGUINATE + 1:
                {
                    if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                    {
                        bloodfang->GetMotionMaster()->MovePath(PATH_BLOODFANG_NEAR_YORICK, false);

                        _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 16, 3s);
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 16:
                {
                    if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                    {
                        bloodfang->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);

                        _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 17, 200ms);
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 17:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            if (bloodfang->IsAIEnabled())
                                bloodfang->AI()->Talk(TALK_BLOODFANG_EXSANGUINATE_7, summoner);

                            _events.ScheduleEvent(EVENT_ACTION_SCENE_EXSANGUINATE + 2, 2s + 300ms);
                        }
                    }
                    break;
                }

                case EVENT_ACTION_SCENE_EXSANGUINATE + 2:
                {
                    if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                    {
                        if (Creature* yorick = ObjectAccessor::GetCreature(*me, _yorickGUID))
                        {
                            yorick->RemoveAura(SPELL_STEALTH);

                            yorick->SetUninteractible(false);

                            bloodfang->CastSpell(yorick, SPELL_RIDE_REVERSE_CAST_EXSANGUINATE, true);

                            _events.ScheduleEvent(EVENT_ACTION_SCENE_EXSANGUINATE + 3, 1s + 100ms);
                        }
                    }
                    break;
                }

                case EVENT_ACTION_SCENE_EXSANGUINATE + 3:
                {
                    if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                    {
                        bloodfang->GetMotionMaster()->MovePath(PATH_BLOODFANG_WITH_YORICK, false);

                        _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 18, 3s);
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 18:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            bloodfang->SetFacingTo(3.054326f);

                            if (bloodfang->IsAIEnabled())
                                bloodfang->AI()->Talk(TALK_BLOODFANG_EXSANGUINATE_8, summoner);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 19, 3s + 600ms);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 19:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* yorick = ObjectAccessor::GetCreature(*me, _yorickGUID))
                        {
                            if (yorick->IsAIEnabled())
                                yorick->AI()->Talk(TALK_YORICK_EXSANGUINATE_DEATH, summoner);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 20, 4s + 850ms);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 20:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            if (Creature* yorick = ObjectAccessor::GetCreature(*me, _yorickGUID))
                            {
                                bloodfang->CastSpell(yorick, SPELL_EJECT_PASSENGER_01, false);

                                if (yorick->IsAIEnabled())
                                    yorick->AI()->DoAction(ACTION_RANE_JUMP_DEATH);

                                if (bloodfang->IsAIEnabled())
                                    bloodfang->AI()->Talk(TALK_BLOODFANG_EXSANGUINATE_9, summoner);

                                _events.ScheduleEvent(EVENT_ACTION_SCENE_EXSANGUINATE + 4, 3s + 600ms);
                            }
                        }
                    }
                    break;
                }

                case EVENT_ACTION_SCENE_EXSANGUINATE + 4:
                {
                    if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                    {
                        bloodfang->SetFacingTo(0.0f);

                        _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 21, 1s + 100ms);
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 21:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            if (bloodfang->IsAIEnabled())
                                bloodfang->AI()->Talk(TALK_BLOODFANG_EXSANGUINATE_10, summoner);

                            _events.ScheduleEvent(EVENT_TALK_SCENE_EXSANGUINATE + 22, 4s + 100ms);
                        }
                    }
                    break;
                }

                case EVENT_TALK_SCENE_EXSANGUINATE + 22:
                {
                    if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                    {
                        bloodfang->HandleEmoteCommand(EMOTE_ONESHOT_TALK);

                        _events.ScheduleEvent(EVENT_SWITCH_SCENE_CAMERA + 5, 3s + 250ms);
                    }
                    break;
                }

                case EVENT_SWITCH_SCENE_CAMERA + 5:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        summoner->CastSpell(nullptr, SPELL_ARMOIRE_CAMERA_ON_CROWLEY, true);

                        if (Creature* bloodfang = ObjectAccessor::GetCreature(*me, _bloodfangGUID))
                        {
                            bloodfang->SetWalk(false);
                            bloodfang->GetMotionMaster()->MovePath(PATH_BLOODFANG_EXIT, false);

                            _events.ScheduleEvent(EVENT_ACTION_SCENE_EXSANGUINATE + 5, 3s);
                        }
                    }
                    break;
                }

                case EVENT_ACTION_SCENE_EXSANGUINATE + 5:
                {
                    if (Creature* crowley = ObjectAccessor::GetCreature(*me, _crowleyGUID))
                    {
                        crowley->GetMotionMaster()->MovePath(PATH_CROWLEY_EXIT, false);

                        _events.ScheduleEvent(EVENT_FINISH_SCENE_EXSANGUINATE, 4s);
                    }
                    break;
                }

                case EVENT_FINISH_SCENE_EXSANGUINATE:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (Creature* crowley = ObjectAccessor::GetCreature(*me, _crowleyGUID))
                            crowley->CastSpell(summoner, SPELL_KILL_CREDIT_YORICK, false);

                        if (Creature* yorick = ObjectAccessor::GetCreature(*me, _yorickGUID))
                            yorick->CastSpell(summoner, SPELL_CANCEL_SUMMON_YORICK, true);

                        summoner->GetMotionMaster()->Clear();

                        summoner->RemoveAura(SPELL_HIDE_IN_ARMOIRE);

                        summoner->ExitVehicle();
                    }
                    break;
                }

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    ObjectGuid _yorickGUID;
    ObjectGuid _crowleyGUID;
    ObjectGuid _bloodfangGUID;
};

enum DariusCrowleyExsanguinate
{
    WAYPOINT_ON_CROWLEY_DESPAWN              = 2
};

// 44883 - Lord Darius Crowley
struct npc_silverpine_lord_darius_crowley_exsanguinate : public ScriptedAI
{
    npc_silverpine_lord_darius_crowley_exsanguinate(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        if (Creature* armoire = me->FindNearestCreature(NPC_ARMOIRE_SUMMONED, 100.0f))
        {
            if (armoire->IsAIEnabled())
                armoire->GetAI()->SetGUID(me->GetGUID(), me->GetEntry());
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_CROWLEY_EXIT && waypointId == WAYPOINT_ON_CROWLEY_DESPAWN)
            me->DespawnOrUnsummon();
    }
};

enum IvarBloodfangExsanguinate
{
    WAYPOINT_ON_BLOODFANG_DESPAWN            = 3
};

// 44884 - Packleader Ivar Bloodfang
struct npc_silverpine_packleader_ivar_bloodfang_exsanguinate : public ScriptedAI
{
    npc_silverpine_packleader_ivar_bloodfang_exsanguinate(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        if (Creature* armoire = me->FindNearestCreature(NPC_ARMOIRE_SUMMONED, 30.0f))
        {
            if (armoire->IsAIEnabled())
                armoire->GetAI()->SetGUID(me->GetGUID(), me->GetEntry());
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_BLOODFANG_EXIT && waypointId == WAYPOINT_ON_BLOODFANG_DESPAWN)
            me->DespawnOrUnsummon();
    }
};

enum SaltyRocka
{
    NPC_SALTY_GORGAR                            = 45497,

    EVENT_ROCKA_CHECK_CONVERSATION              = 1,
    EVENT_ROCKA_CHOOSE_CONVERSATION             = 2,
    EVENT_ROCKA_CONVERSATION_COOLDOWN           = 3,
    EVENT_ROCKA_TALK                            = 10,

    TALK_ROCKA_0                                = 0,
    TALK_ROCKA_1                                = 1,
    TALK_ROCKA_2                                = 2,
    TALK_ROCKA_3                                = 3,
    TALK_ROCKA_4                                = 4,
    TALK_ROCKA_5                                = 5,
    TALK_ROCKA_6                                = 6,
    TALK_ROCKA_7                                = 7,
    TALK_ROCKA_8                                = 8,
    TALK_ROCKA_9                                = 9,
    TALK_GORGAR_0                               = 0,
    TALK_GORGAR_1                               = 1,
    TALK_GORGAR_2                               = 2,
    TALK_GORGAR_3                               = 3,
    TALK_GORGAR_4                               = 4,
    TALK_GORGAR_5                               = 5
};

// 45498 - "Salty" Rocka
struct npc_silverpine_salty_rocka : public ScriptedAI
{
    npc_silverpine_salty_rocka(Creature* creature) : ScriptedAI(creature), _isConversationOnCooldown(false) { }

    void JustAppeared() override
    {
        CheckForGorgor();
    }

    void Reset() override
    {
        _isConversationOnCooldown = false;
        _events.Reset();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER && who->GetDistance2d(me) < 20.0f)
            _events.ScheduleEvent(EVENT_ROCKA_CHECK_CONVERSATION, 250ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ROCKA_CHECK_CONVERSATION:
                    if (_isConversationOnCooldown)
                        return;
                    _isConversationOnCooldown = true;
                    _events.ScheduleEvent(EVENT_ROCKA_CHOOSE_CONVERSATION, 250ms);
                    _events.ScheduleEvent(EVENT_ROCKA_CONVERSATION_COOLDOWN, 180s);
                    break;

                case EVENT_ROCKA_CHOOSE_CONVERSATION:
                    _events.ScheduleEvent(EVENT_ROCKA_TALK + (urand(0, 4) * 10), 750ms);
                    break;

                case EVENT_ROCKA_TALK:
                    Talk(TALK_ROCKA_0);
                    _events.ScheduleEvent(EVENT_ROCKA_TALK + 1, 20s);
                    break;

                case EVENT_ROCKA_TALK + 1:
                {
                    if (Creature* gorgar = ObjectAccessor::GetCreature(*me, _gorgarGUID))
                    {
                        if (gorgar->IsAIEnabled())
                            gorgar->AI()->Talk(TALK_GORGAR_0);
                    }
                    _events.ScheduleEvent(EVENT_ROCKA_TALK + 2, 20s);
                    break;
                }

                case EVENT_ROCKA_TALK + 2:
                    Talk(TALK_ROCKA_1);
                    break;

                case EVENT_ROCKA_TALK + 10:
                    Talk(TALK_ROCKA_2);
                    _events.ScheduleEvent(EVENT_ROCKA_TALK + 11, 20s);
                    break;

                case EVENT_ROCKA_TALK + 11:
                {
                    if (Creature* gorgar = ObjectAccessor::GetCreature(*me, _gorgarGUID))
                    {
                        if (gorgar->IsAIEnabled())
                            gorgar->AI()->Talk(TALK_GORGAR_1);
                    }
                    _events.ScheduleEvent(EVENT_ROCKA_TALK + 12, 20s);
                    break;
                }

                case EVENT_ROCKA_TALK + 12:
                    Talk(TALK_ROCKA_3);
                    break;

                case EVENT_ROCKA_TALK + 20:
                    Talk(TALK_ROCKA_4);
                    _events.ScheduleEvent(EVENT_ROCKA_TALK + 21, 20s);
                    break;

                case EVENT_ROCKA_TALK + 21:
                {
                    if (Creature* gorgar = ObjectAccessor::GetCreature(*me, _gorgarGUID))
                    {
                        if (gorgar->IsAIEnabled())
                            gorgar->AI()->Talk(TALK_GORGAR_2);
                    }
                    _events.ScheduleEvent(EVENT_ROCKA_TALK + 22, 20s);
                    break;
                }

                case EVENT_ROCKA_TALK + 22:
                    Talk(TALK_ROCKA_5);
                    break;

                case EVENT_ROCKA_TALK + 30:
                    Talk(TALK_ROCKA_6);
                    _events.ScheduleEvent(EVENT_ROCKA_TALK + 31, 20s);
                    break;

                case EVENT_ROCKA_TALK + 31:
                {
                    if (Creature* gorgar = ObjectAccessor::GetCreature(*me, _gorgarGUID))
                    {
                        if (gorgar->IsAIEnabled())
                            gorgar->AI()->Talk(TALK_GORGAR_3);
                    }
                    _events.ScheduleEvent(EVENT_ROCKA_TALK + 32, 20s);
                    break;
                }

                case EVENT_ROCKA_TALK + 32:
                    Talk(TALK_ROCKA_7);
                    break;

                case EVENT_ROCKA_TALK + 40:
                    Talk(TALK_ROCKA_8);
                    _events.ScheduleEvent(EVENT_ROCKA_TALK + 1, 20s);
                    break;

                case EVENT_ROCKA_TALK + 41:
                {
                    if (Creature* gorgar = ObjectAccessor::GetCreature(*me, _gorgarGUID))
                    {
                        if (gorgar->IsAIEnabled())
                            gorgar->AI()->Talk(TALK_GORGAR_4);
                    }
                    _events.ScheduleEvent(EVENT_ROCKA_TALK + 2, 20s);
                    break;
                }

                case EVENT_ROCKA_TALK + 42:
                    Talk(TALK_ROCKA_9);
                    break;

                case EVENT_ROCKA_CONVERSATION_COOLDOWN:
                    Reset();
                    break;

                default:
                    break;
            }
        }
    }

    void CheckForGorgor()
    {
        if (!_gorgarGUID)
        {
            if (Creature* gorgar = me->FindNearestCreature(NPC_SALTY_GORGAR, 50.0f))
                _gorgarGUID = gorgar->GetGUID();
        }
    }

private:
    EventMap _events;
    ObjectGuid _gorgarGUID;
    bool _isConversationOnCooldown;
};

enum AtForsakenRearGuard
{
    QUEST_LOST_IN_THE_DARKNESS                  = 27093,
    QUEST_DEEPER_INTO_DARKNESS                  = 27094,
    QUEST_ITS_ONLY_POISONOUS_IF_YOU_INGEST_IT   = 27088,

    NPC_ADMIRAL_HATCHET                         = 44916,
    NPC_APOTHECARY_WORMCRUD                     = 44912,

    ACTION_HATCHET_START_CONVERSATION           = 1,
    ACTION_WORMCRUD_START_CONVERSATION          = 2
};

// 6222 - Forsaken Rear Guard
class at_silverpine_forsaken_rear_guard : public AreaTriggerScript
{
public:
    at_silverpine_forsaken_rear_guard() : AreaTriggerScript("at_silverpine_forsaken_rear_guard") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        if (player->IsAlive())
        {
            if ((player->GetQuestStatus(QUEST_LOST_IN_THE_DARKNESS) != QUEST_STATUS_COMPLETE && player->GetQuestStatus(QUEST_LOST_IN_THE_DARKNESS) != QUEST_STATUS_REWARDED) &&
                (player->GetQuestStatus(QUEST_DEEPER_INTO_DARKNESS) != QUEST_STATUS_COMPLETE && player->GetQuestStatus(QUEST_DEEPER_INTO_DARKNESS) != QUEST_STATUS_REWARDED))
            {
                if (Creature* hatchet = player->FindNearestCreature(NPC_ADMIRAL_HATCHET, 50.0f))
                {
                    if (hatchet->IsAIEnabled())
                        hatchet->AI()->DoAction(ACTION_HATCHET_START_CONVERSATION);
                }
            }
            else if (player->GetQuestStatus(QUEST_ITS_ONLY_POISONOUS_IF_YOU_INGEST_IT) != QUEST_STATUS_COMPLETE && player->GetQuestStatus(QUEST_ITS_ONLY_POISONOUS_IF_YOU_INGEST_IT) != QUEST_STATUS_REWARDED)
            {
                if (Creature* wormcrud = player->FindNearestCreature(NPC_APOTHECARY_WORMCRUD, 50.0f))
                {
                    if (wormcrud->IsAIEnabled())
                        wormcrud->AI()->DoAction(ACTION_WORMCRUD_START_CONVERSATION);
                }
            }
        }

        return true;
    }
};

enum ApothecaryWormcrud
{
    NPC_DRUNKEN_ORC_SEA_DOG                     = 44913,

    EVENT_WORMCRUD_CHECK_CONVERSATION           = 1,
    EVENT_WORMCRUD_CHOOSE_CONVERSATION          = 2,
    EVENT_WORMCRUD_CONVERSATION_COOLDOWN        = 3,
    EVENT_WORMCRUD_TALK                         = 4,

    TALK_ORCSEA_0                               = 0,
    TALK_ORCSEA_1                               = 1,
    TALK_ORCSEA_2                               = 2,
    TALK_WORMCRUD_0                             = 0
};

// 44912 - Apothecary Wormcrud
struct npc_silverpine_apothecary_wormcrud : public ScriptedAI
{
    npc_silverpine_apothecary_wormcrud(Creature* creature) : ScriptedAI(creature), _isConversationOnCooldown(false) { }

    void JustAppeared() override
    {
        CheckForSeaOrcs();
    }

    void Reset() override
    {
        _events.Reset();

        _isConversationOnCooldown = false;
    }

    void DoAction(int32 param) override
    {
        if (param == ACTION_WORMCRUD_START_CONVERSATION)
        {
            if (_isConversationOnCooldown)
                return;

            _isConversationOnCooldown = true;

            _events.ScheduleEvent(EVENT_WORMCRUD_TALK, 15s);
            _events.ScheduleEvent(EVENT_WORMCRUD_CONVERSATION_COOLDOWN, 215s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WORMCRUD_TALK:
                {
                    if (Creature* orcsea1 = ObjectAccessor::GetCreature(*me, _drunkenOrcSeaDog[0]))
                    {
                        if (orcsea1->IsAIEnabled())
                            orcsea1->AI()->Talk(TALK_ORCSEA_0);
                    }
                    _events.ScheduleEvent(EVENT_WORMCRUD_TALK + 1, 12s);
                    break;
                }

                case EVENT_WORMCRUD_TALK + 1:
                {
                    if (Creature* orcsea2 = ObjectAccessor::GetCreature(*me, _drunkenOrcSeaDog[1]))
                    {
                        if (orcsea2->IsAIEnabled())
                            orcsea2->AI()->Talk(TALK_ORCSEA_1);
                    }
                    _events.ScheduleEvent(EVENT_WORMCRUD_TALK + 2, 12s);
                    break;
                }

                case EVENT_WORMCRUD_TALK + 2:
                {
                    if (Creature* orcsea3 = ObjectAccessor::GetCreature(*me, _drunkenOrcSeaDog[2]))
                    {
                        if (orcsea3->IsAIEnabled())
                            orcsea3->AI()->Talk(TALK_ORCSEA_2);
                    }
                    _events.ScheduleEvent(EVENT_WORMCRUD_TALK + 3, 12s);
                    break;
                }

                case EVENT_WORMCRUD_TALK + 3:
                    Talk(TALK_WORMCRUD_0);
                    break;

                case EVENT_WORMCRUD_CONVERSATION_COOLDOWN:
                    Reset();
                    break;

                default:
                    break;
            }
        }
    }

    void CheckForSeaOrcs()
    {
        std::vector<Creature*> orcSeaDogList;
        me->GetCreatureListWithEntryInGrid(orcSeaDogList, NPC_DRUNKEN_ORC_SEA_DOG, 5.0f);

        if (orcSeaDogList.size() < 3)
            return;

        for (uint32 i = 0; i < orcSeaDogList.size(); i++)
            _drunkenOrcSeaDog[i] = orcSeaDogList[i]->GetGUID();
    }

private:
    EventMap _events;
    std::array<ObjectGuid, 3> _drunkenOrcSeaDog;
    bool _isConversationOnCooldown;
};

enum HatchetRearGuard
{
    QUEST_STEEL_THUNDER                         = 27069,

    NPC_WARLORD_TOROK                           = 44917,

    SPELL_SUMMON_ORC_SEA_PUP                    = 83839,
    SPELL_SEA_PUP_TRIGGER                       = 83865,
    SPELL_DESPAWN_ALL_SUMMONS_LOST_IN_DARKNESS  = 83935,

    EVENT_HATCHET_CHECK_CONVERSATION            = 1,
    EVENT_HATCHET_CONVERSATION_COOLDOWN         = 2,
    EVENT_HATCHET_TALK                          = 3,

    TALK_HATCHET_0                              = 0,
    TALK_HATCHET_1                              = 1,
    TALK_TOROK_0                                = 0,
    TALK_TOROK_1                                = 1,
    TALK_TOROK_2                                = 2,

    ANIMKIT_TOROK                               = 594
};

// 44916 - Admiral Hatchet
struct npc_silverpine_admiral_hatchet : public ScriptedAI
{
    npc_silverpine_admiral_hatchet(Creature* creature) : ScriptedAI(creature), _isConversationOnCooldown(false) { }

    void JustAppeared() override
    {
        CheckForTorok();
    }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_STEEL_THUNDER)
            player->CastSpell(player, SPELL_SUMMON_ORC_SEA_PUP);
    }

    void OnQuestReward(Player* player, Quest const* quest, LootItemType /*type*/, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == QUEST_STEEL_THUNDER)
            player->CastSpell(player, SPELL_SEA_PUP_TRIGGER, true);
        else if (quest->GetQuestId() == QUEST_LOST_IN_THE_DARKNESS)
            player->CastSpell(nullptr, SPELL_DESPAWN_ALL_SUMMONS_LOST_IN_DARKNESS, true);
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        if (player->GetQuestStatus(QUEST_STEEL_THUNDER) == QUEST_STATUS_INCOMPLETE)
            player->CastSpell(player, SPELL_SUMMON_ORC_SEA_PUP);

        CloseGossipMenuFor(player);
        return false;
    }

    void Reset() override
    {
        _events.Reset();
        _isConversationOnCooldown = false;
    }

    void DoAction(int32 param) override
    {
        if (param == ACTION_HATCHET_START_CONVERSATION)
        {
            if (_isConversationOnCooldown)
                return;

            _isConversationOnCooldown = true;

            _events.ScheduleEvent(EVENT_HATCHET_TALK, 1s);
            _events.ScheduleEvent(EVENT_HATCHET_CONVERSATION_COOLDOWN, 230s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HATCHET_TALK:
                    Talk(TALK_HATCHET_0);
                    _events.ScheduleEvent(EVENT_HATCHET_TALK + 1, 8s);
                    break;

                case EVENT_HATCHET_TALK + 1:
                {
                    if (Creature* torok = ObjectAccessor::GetCreature(*me, _torokGUID))
                    {
                        if (torok->IsAIEnabled())
                            torok->AI()->Talk(TALK_TOROK_0);
                    }
                    _events.ScheduleEvent(EVENT_HATCHET_TALK + 2, 6s);
                    break;
                }

                case EVENT_HATCHET_TALK + 2:
                    Talk(TALK_HATCHET_1);
                    _events.ScheduleEvent(EVENT_HATCHET_TALK + 3, 6s);
                    break;

                case EVENT_HATCHET_TALK + 3:
                {
                    if (Creature* torok = ObjectAccessor::GetCreature(*me, _torokGUID))
                    {
                        torok->PlayOneShotAnimKitId(ANIMKIT_TOROK);

                        if (torok->IsAIEnabled())
                            torok->AI()->Talk(TALK_TOROK_1);
                    }
                    break;
                }

                case EVENT_HATCHET_CONVERSATION_COOLDOWN:
                    Reset();
                    break;

                default:
                    break;
            }
        }
    }

    void CheckForTorok()
    {
        if (!_torokGUID)
        {
            if (Creature* torok = me->FindNearestCreature(NPC_WARLORD_TOROK, 30.0f))
                _torokGUID = torok->GetGUID();
        }
    }

private:
    EventMap _events;
    ObjectGuid _torokGUID;
    bool _isConversationOnCooldown;
};

enum OrcSeaDog
{
    SPELL_DRINK_TANKARD                         = 42871,
    SPELL_COSMETIC_SLEEP                        = 84186,
    SPELL_COSMETIC_FEELING_SICK                 = 83832,
    SPELL_COSMETIC_NOT_FEELING_SICK             = 83829,
    SPELL_SICK                                  = 83885,

    EVENT_SEA_DOG_DRINK                         = 1,
    EVENT_SEA_DOG_ROAM                          = 2,
    EVENT_SEA_DOG_VOMIT                         = 3,

    COSMETIC_SIT_ON_THE_FLOOR                   = 1,
    COSMETIC_SIT_ON_THE_FLOOR_TWICE             = 2,
    COSMETIC_GO_TO_SLEEP                        = 3,
    COSMETIC_START_TO_FEEL_UNEASY               = 4
};

// 44913 - Orc Sea Dog
struct npc_silverpine_orc_sea_dog_not_sick : public ScriptedAI
{
    npc_silverpine_orc_sea_dog_not_sick(Creature* creature) : ScriptedAI(creature) {}

    void JustAppeared() override
    {
        switch (urand(COSMETIC_SIT_ON_THE_FLOOR, COSMETIC_START_TO_FEEL_UNEASY))
        {
            case COSMETIC_SIT_ON_THE_FLOOR:
            case COSMETIC_SIT_ON_THE_FLOOR_TWICE:
                DoCastSelf(SPELL_COSMETIC_NOT_FEELING_SICK, false);
                _events.ScheduleEvent(EVENT_SEA_DOG_DRINK, 1s, 2s);
                break;
            case COSMETIC_GO_TO_SLEEP:
                DoCastSelf(SPELL_COSMETIC_SLEEP, false);
                break;
            case COSMETIC_START_TO_FEEL_UNEASY:
                DoCastSelf(SPELL_COSMETIC_FEELING_SICK, false);
                _events.ScheduleEvent(EVENT_SEA_DOG_ROAM, 1s, 5s);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SEA_DOG_DRINK:
                    DoCastSelf(SPELL_DRINK_TANKARD, false);
                    _events.Repeat(6s, 20s);
                    break;
                case EVENT_SEA_DOG_ROAM:
                    me->GetMotionMaster()->MoveCirclePath(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 1.5f, true, 4);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

struct npc_silverpine_orc_sea_dog_sick : public ScriptedAI
{
    npc_silverpine_orc_sea_dog_sick(Creature* creature) : ScriptedAI(creature) {}

    void JustAppeared() override
    {
        DoCastSelf(SPELL_COSMETIC_FEELING_SICK, false);

        _events.ScheduleEvent(EVENT_SEA_DOG_VOMIT, 5s, 20s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SEA_DOG_VOMIT:
                    DoCastSelf(SPELL_SICK, false);
                    _events.Repeat(25s, 50s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// Note: we're not using the generic spell for this one because Orc Sea Pup is unsummoned 3s later.
// 83840 - Despawn All Summons
class spell_silverpine_despawn_all_summons_steel_thunder : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            Creature* target = GetHitCreature();

            if (target->GetOwner() == caster)
                target->DespawnOrUnsummon(3s);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_despawn_all_summons_steel_thunder::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum OrcSeaPup
{
    NPC_ORC_CRATE                               = 44915,

    SPELL_SUMMON_ORC_CRATE                      = 83835,
    SPELL_EJECT_ALL_PASSENGERS                  = 68576,
    SPELL_ANIM_DEAD                             = 98190,
    SPELL_DESPAWN_ALL_SUMMONS_STEEL_THUNDER     = 83840,

    EVENT_ORC_PUP_JUST_SUMMONED                 = 1,
    EVENT_ORC_PUP_REMOVE_PROTECTION             = 2,
    EVENT_ORC_PUP_TALK                          = 3,
    EVENT_ORC_PUP_DELIVER_CRATES                = 4,

    TALK_ORC_PUP_SUMMONED                       = 0,
    TALK_ORC_PUP_DELIVER_CRATES                 = 6,
    TALK_ORC_PUP_WORN_OFF                       = 7
};

// 44914 - Orc Sea Pup
struct npc_silverpine_orc_sea_pup : public VehicleAI
{
    npc_silverpine_orc_sea_pup(Creature* creature) : VehicleAI(creature), _isJustSummoned(true) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
        {
            me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);

            // Note: SummonPropertiesFlags::JoinSummonerSpawnGroup is NYI.
            me->GetMotionMaster()->MoveFollow(player, 2.0f, float(M_PI / 2.0f));

            if (player->GetQuestStatus(QUEST_STEEL_THUNDER) == QUEST_STATUS_INCOMPLETE)
            {
                _events.ScheduleEvent(EVENT_ORC_PUP_JUST_SUMMONED, 1s);
                _events.ScheduleEvent(EVENT_ORC_PUP_REMOVE_PROTECTION, 1s + 500ms);
                _events.ScheduleEvent(EVENT_ORC_PUP_TALK, 5s);

                int c = player->GetReqKillOrCastCurrentCount(QUEST_STEEL_THUNDER, NPC_ORC_CRATE);

                for (int i = 0; i < c; i++)
                    DoCastSelf(SPELL_SUMMON_ORC_CRATE);
            }
        }
    }

    void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        Creature* passengerCreature = passenger->ToCreature();
        if (!passengerCreature)
            return;

        if (passenger->GetEntry() != NPC_ORC_CRATE)
            return;

        if (apply)
        {
            if (_isJustSummoned)
                return;

            if (Unit* summoner = tempSummon->GetSummonerUnit())
                Talk(seatId + 1, summoner);
        }
        else
            passengerCreature->DespawnOrUnsummon(3s);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        switch (spellInfo->Id)
        {
            case SPELL_SEA_PUP_TRIGGER:
            {
                if (Unit* summoner = tempSummon->GetSummonerUnit())
                {
                    Talk(TALK_ORC_PUP_DELIVER_CRATES, summoner);

                    summoner->CastSpell(nullptr, SPELL_DESPAWN_ALL_SUMMONS_STEEL_THUNDER, true);

                    _events.CancelEvent(EVENT_ORC_PUP_TALK);
                }
                break;
            }

            case SPELL_DESPAWN_ALL_SUMMONS_STEEL_THUNDER:
                _events.ScheduleEvent(EVENT_ORC_PUP_DELIVER_CRATES, 1s + 250ms);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ORC_PUP_JUST_SUMMONED:
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                        Talk(TALK_ORC_PUP_SUMMONED, summoner);
                    break;

                case EVENT_ORC_PUP_TALK:
                {
                    if (Vehicle* vehicle = me->GetVehicleKit())
                    {
                        if (vehicle->IsVehicleInUse())
                        {
                            if (Unit* summoner = tempSummon->GetSummonerUnit())
                                Talk(TALK_ORC_PUP_WORN_OFF, summoner);
                        }
                    }
                    _events.ScheduleEvent(EVENT_ORC_PUP_TALK, 30s, 75s);
                    break;
                }

                case EVENT_ORC_PUP_REMOVE_PROTECTION:
                    _isJustSummoned = false;
                    break;

                case EVENT_ORC_PUP_DELIVER_CRATES:
                    DoCastSelf(SPELL_EJECT_ALL_PASSENGERS);
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _isJustSummoned;
};

enum OrcCrate
{
    NPC_ORC_SEA_PUP                             = 44914
};

// 44915 - Orc Crate
struct npc_silverpine_orc_crate : public ScriptedAI
{
    npc_silverpine_orc_crate(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (summoner->GetEntry() == NPC_ORC_SEA_PUP)
        {
            me->SetUninteractible(true);

            me->EnterVehicle(summoner->ToUnit());
        }
    }
};

enum PickUpOrcCrate
{
    SPELL_KILL_CREDIT_SEA_DOG_CRATE             = 83843
};

// 83838 - Pick Up Orc Crate
class spell_silverpine_pick_up_orc_crate : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfi*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_SUMMON_ORC_CRATE,
            SPELL_KILL_CREDIT_SEA_DOG_CRATE
        });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(nullptr, SPELL_SUMMON_ORC_CRATE);
        GetHitUnit()->CastSpell(nullptr, SPELL_KILL_CREDIT_SEA_DOG_CRATE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_pick_up_orc_crate::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum ForestEttin
{
    NPC_MUTANT_BUSH_CHICKEN                     = 44935,

    SPELL_HAULING_TIMBER                        = 88361,
    SPELL_BONK                                  = 80146,
    SPELL_LOG_SMASH                             = 88421,
    SPELL_RIDE_REVERSE_CAST_ITS_POISONOUS       = 83904,
    SPELL_ETTIN_MOUTH                           = 83907,
    SPELL_BUSH_EXPLOSION                        = 83903,
    SPELL_RELEASE_BUSH_CHICKEN                  = 83902,

    EVENT_LOG_SMASH                             = 1,
    EVENT_BONK                                  = 2,
    EVENT_GRAB_BUSH_CHICKEN                     = 3,
    EVENT_AFTER_GRABBING_BUSH_CHICKEN           = 4,
    EVENT_BUSH_CHICKEN_CHANGE_SITS              = 5,
    EVENT_BUSH_CHICKEN_BLASTS                   = 6,
    EVENT_RESET                                 = 7,

    ACTION_NOTICE_CHICKEN                       = 1,

    SEAT_ETTIN_ARM                              = 0,
    SEAT_ETTIN_MOUTH                            = 1,

    SOUND_CHICKEN_MOUNT_WOUND                   = 15936
};

// 44367 - Forest Ettin
struct npc_silverpine_forest_ettin : public ScriptedAI
{
    npc_silverpine_forest_ettin(Creature* creature) : ScriptedAI(creature), _isGrabbingBushChicken(false) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_HAULING_TIMBER, false);
    }

    void Reset() override
    {
        _events.Reset();

        _isGrabbingBushChicken = false;

        me->ResumeMovement();

        _chickenGUID.Clear();
        _playerGUID.Clear();
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_RELEASE_BUSH_CHICKEN)
            _playerGUID = caster->GetGUID();
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        switch (id)
        {
            case NPC_MUTANT_BUSH_CHICKEN:
                _chickenGUID = guid;
                break;
            default:
                break;
        }
    }

    void PassengerBoarded(Unit* /*passenger*/, int8 seatId, bool apply) override
    {
        if (!_isGrabbingBushChicken)
            return;

        if (apply)
        {
            if (seatId == SEAT_ETTIN_ARM)
                _events.ScheduleEvent(EVENT_AFTER_GRABBING_BUSH_CHICKEN, 2s);
            else if (seatId == SEAT_ETTIN_MOUTH)
                _events.ScheduleEvent(EVENT_BUSH_CHICKEN_BLASTS, 2s);
        }
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case ACTION_NOTICE_CHICKEN:
            {
                if (Creature* mutantBushChicken = ObjectAccessor::GetCreature(*me, _chickenGUID))
                {
                    me->PauseMovement();

                    me->SetFacingToObject(mutantBushChicken);

                    _events.ScheduleEvent(EVENT_GRAB_BUSH_CHICKEN, 1s + 250ms);
                }
                break;
            }

            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* spellInfo /*= nullptr*/) override
    {
        if (!spellInfo)
            return;

        // HACKFIX: according to BasePoints damage is around 90k, which is wrong. On retail, it deals 80% of its health points only.
        // Also, Mutant Bush Chicken is summoned as not player-controlled (not blue-taped), though it uses the same summonProperties's
        // Control and Slot as some other summoning spells from this zone.
        if (spellInfo->Id == SPELL_BUSH_EXPLOSION)
            damage = 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_BONK, 2s);
        _events.ScheduleEvent(EVENT_LOG_SMASH, 8s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BONK:
                    DoCastVictim(SPELL_BONK);
                    _events.Repeat(9s, 11s);
                    break;

                case EVENT_LOG_SMASH:
                    DoCastVictim(SPELL_LOG_SMASH);
                    _events.Repeat(15s, 16s);
                    break;

                case EVENT_GRAB_BUSH_CHICKEN:
                {
                    if (Creature* mutantBushChicken = ObjectAccessor::GetCreature(*me, _chickenGUID))
                    {
                        _isGrabbingBushChicken = true;

                        me->CastSpell(mutantBushChicken, SPELL_RIDE_REVERSE_CAST_ITS_POISONOUS, true);

                        _events.ScheduleEvent(EVENT_RESET, 25s);
                    }
                    break;
                }

                case EVENT_AFTER_GRABBING_BUSH_CHICKEN:
                    me->ResumeMovement();
                    _events.ScheduleEvent(EVENT_BUSH_CHICKEN_CHANGE_SITS, 2s);
                    break;

                case EVENT_BUSH_CHICKEN_CHANGE_SITS:
                {
                    if (Creature* mutantBushChicken = ObjectAccessor::GetCreature(*me, _chickenGUID))
                    {
                        mutantBushChicken->CastSpell(me, SPELL_ETTIN_MOUTH, true);

                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        {
                            if (player->GetQuestStatus(QUEST_ITS_ONLY_POISONOUS_IF_YOU_INGEST_IT) == QUEST_STATUS_INCOMPLETE)
                                mutantBushChicken->PlayDirectSound(SOUND_CHICKEN_MOUNT_WOUND, player);
                        }
                    }
                    break;
                }

                case EVENT_BUSH_CHICKEN_BLASTS:
                {
                    if (Creature* mutantBushChicken = ObjectAccessor::GetCreature(*me, _chickenGUID))
                    {
                        mutantBushChicken->CastSpell(me, SPELL_BUSH_EXPLOSION, true);

                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            AttackStart(player);
                    }
                    break;
                }

                case EVENT_RESET:
                    Reset();
                    break;

                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;
    }

private:
    EventMap _events;
    ObjectGuid _chickenGUID;
    ObjectGuid _playerGUID;
    bool _isGrabbingBushChicken;
};

enum MutantBushChicken
{
    NPC_FOREST_ETTIN                            = 44367,

    EVENT_MOVE_TO_FOREST_ETTIN                  = 1,

    POINT_NEAR_FOREST_ETTIN                     = 1
};

// 44935 - Mutant Bush Chicken
struct npc_silverpine_mutant_bush_chicken : public ScriptedAI
{
    npc_silverpine_mutant_bush_chicken(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_ITS_ONLY_POISONOUS_IF_YOU_INGEST_IT) == QUEST_STATUS_INCOMPLETE)
                me->PlayDirectSound(SOUND_CHICKEN_MOUNT_WOUND, player);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_NEAR_FOREST_ETTIN)
        {
            if (Creature* forestEttin = ObjectAccessor::GetCreature(*me, _forestEttinGUID))
            {
                if (forestEttin->IsAIEnabled())
                    forestEttin->AI()->DoAction(ACTION_NOTICE_CHICKEN);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        if (Unit* summoner = tempSummon->GetSummonerUnit())
        {
            // Note: SummonPropertiesFlags::DespawnOnSummonerLogout is NYI.
            if (!summoner->IsInWorld())
                me->DespawnOrUnsummon();
        }

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TO_FOREST_ETTIN:
                    if (Creature* forestEttin = ObjectAccessor::GetCreature(*me, _forestEttinGUID))
                        me->GetMotionMaster()->MovePoint(POINT_NEAR_FOREST_ETTIN, forestEttin->GetPosition(), false);
                    break;
                default:
                    break;
            }
        }
    }

    void CheckForForestEttin(Unit* forestEttin)
    {
        _forestEttinGUID = forestEttin->GetGUID();

        me->SetFacingToObject(forestEttin);

        _events.ScheduleEvent(EVENT_MOVE_TO_FOREST_ETTIN, 1s);
    }

private:
    EventMap _events;
    ObjectGuid _forestEttinGUID;
};

// 83902 - Release Diseased Mutant Bush Chicken
class spell_silverpine_release_diseased_mutant_bush_chicken : public SpellScript
{
    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (Unit* caster = GetCaster())
        {
            std::vector<Creature*> chickens;
            caster->GetCreatureListWithEntryInGrid(chickens, NPC_MUTANT_BUSH_CHICKEN, 5.0f);
            for (Creature* mutantBushChicken : chickens)
            {
                if (mutantBushChicken->GetOwner() != caster)
                    continue;

                if (target->IsAIEnabled())
                    target->GetAI()->SetGUID(mutantBushChicken->GetGUID(), NPC_MUTANT_BUSH_CHICKEN);

                if (npc_silverpine_mutant_bush_chicken* mutantBushChickenAI = CAST_AI(npc_silverpine_mutant_bush_chicken, mutantBushChicken->AI()))
                    mutantBushChickenAI->CheckForForestEttin(target);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_release_diseased_mutant_bush_chicken::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

enum WebbedVictim
{
    SPELL_FREE_WEBBED_VICTIM                    = 83927,
    SPELL_FREE_WEBBED_VICTIM_RANDOM             = 83919
};

// 44941 - Webbed Victim
struct npc_silverpine_webbed_victim : public ScriptedAI
{
    npc_silverpine_webbed_victim(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_LOST_IN_THE_DARKNESS) == QUEST_STATUS_INCOMPLETE)
                player->CastSpell(me, roll_chance_i(50) ? SPELL_FREE_WEBBED_VICTIM : SPELL_FREE_WEBBED_VICTIM_RANDOM, true);
        }
    }
};

enum FreeWebbedVictim
{
    NPC_BLOODFANG_SCAVENGER                     = 44547,
    NPC_RABID_DOG                               = 1766,
    NPC_GIANT_RABBID_BEAR                       = 1797,

    DATA_RANDOM_0                               = 0,
    DATA_RANDOM_1                               = 1,
    DATA_RANDOM_2                               = 2,
    DATA_RANDOM_3                               = 3
};

// 83919 - Free Webbed Victim
class spell_silverpine_free_webbed_victim_random : public SpellScript
{
    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            uint32 randomCreature = 0;

            /*
             * Note: this spell is always cast when there's nothing in the web or there's a foe. Also,
             * there are 4 serverside spells for this, but we're unable to know which one does what exactly:
             * 83922 - (Serverside/Non-DB2) Free Webbed Victim, 83923 - (Serverside/Non-DB2) Free Webbed Victim,
             * 83924 - (Serverside/Non-DB2) Free Webbed Victim, 83925 - (Serverside/Non-DB2) Free Webbed Victim.
             * It is safe to assume that each summons one of the three foes, and the other summons nothing.
             * 83927 - Free Webbed Victim summons orcs. We could try finding summonProperties, but it is hard.
             */

            switch (urand(DATA_RANDOM_0, DATA_RANDOM_3))
            {
                case DATA_RANDOM_0:
                    randomCreature = NPC_BLOODFANG_SCAVENGER;
                    break;
                case DATA_RANDOM_1:
                    randomCreature = NPC_RABID_DOG;
                    break;
                case DATA_RANDOM_2:
                    randomCreature = NPC_GIANT_RABBID_BEAR;
                    break;
                case DATA_RANDOM_3:
                    randomCreature = 0;
                    break;
                default:
                    break;
            }

            if (randomCreature != 0)
            {
                if (Creature* randomAggresiveCreature = caster->SummonCreature(randomCreature, GetHitUnit()->GetPosition()))
                    randomAggresiveCreature->Attack(caster, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_free_webbed_victim_random::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum WebbedOrcSeaDog
{
    NPC_ORC_SEA_DOG                             = 44942,

    SPELL_SINISTER_STRIKE                       = 60195,

    EVENT_WEBBEB_ORC_CHECK_PLAYER               = 1,
    EVENT_WEBBEB_ORC_TALK                       = 2,
    EVENT_SINISTER_STRIKE                       = 3,

    TALK_WEBBEB_ORC_FREED                       = 0
};

// 44942 - Orc Sea Dog
struct npc_silverpine_orc_sea_dog : public ScriptedAI
{
    npc_silverpine_orc_sea_dog(Creature* creature) : ScriptedAI(creature) {}

    void JustAppeared() override
    {
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 100, true);

        // Note: SummonPropertiesFlags::HelpWhenSummonedInCombat is NYI.
        me->SetReactState(REACT_ASSIST);
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
        {
            player->KilledMonsterCredit(NPC_ORC_SEA_DOG);

            // Note: SummonPropertiesFlags::JoinSummonerSpawnGroup is NYI. They should be faned around the back of the player depending on how many summons they have (Pets and Guardians included).
            me->GetMotionMaster()->MoveFollow(player, 5.0f, frand(1.57f, 4.71f));

            _events.ScheduleEvent(EVENT_WEBBEB_ORC_CHECK_PLAYER, 1s);
            _events.ScheduleEvent(EVENT_WEBBEB_ORC_TALK, 1s + 500ms);
        }
    }

    void Reset() override
    {
        _events.CancelEvent(EVENT_SINISTER_STRIKE);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SINISTER_STRIKE, 2s, 4s);
    }

    void UpdateAI(uint32 diff) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        if (Unit* summoner = tempSummon->GetSummonerUnit())
        {
            // Note: SummonPropertiesFlags::DespawnOnSummonerDeath and SummonPropertiesFlags::DespawnOnSummonerLogout are NYI.
            if (!summoner->IsAlive() || !summoner->IsInWorld())
                me->DespawnOrUnsummon();
        }

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WEBBEB_ORC_TALK:
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                        Talk(TALK_WEBBEB_ORC_FREED, summoner);
                    break;

                case EVENT_SINISTER_STRIKE:
                    DoCastVictim(SPELL_SINISTER_STRIKE);
                    _events.Repeat(6s, 8s);
                    break;

                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;
    }

private:
    EventMap _events;
};

enum SkitterwebMatriarch
{
    NPC_SKITTERWEB_STALKER                      = 44908,

    SPELL_SKITTERWEB                            = 83827,
    SPELL_SUMMNON_SPIDERLINGS                   = 87084,
    SPELL_VENOM_SPLASH                          = 79607,

    EVENT_MATRIARCH_AGGRO                       = 1,
    EVENT_RESET_POSITION                        = 4,
    EVENT_SUMMON_SPIDERLINGS                    = 5,
    EVENT_VENOM_SPLASH                          = 6,

    ANIMKIT_MATRIARCH_INTERACT                  = 1,
    ANIMKIT_MATRIARCH_LURKING_ON_CEILING        = 865,
    ANIMKIT_MATRIARCH_HANGING_BY_WEB            = 866
};

// 44906 - Skitterweb Matriarch
struct npc_silverpine_skitterweb_matriarch : public ScriptedAI
{
    npc_silverpine_skitterweb_matriarch(Creature* creature) : ScriptedAI(creature) {}

    void JustAppeared() override
    {
        me->SetDisableGravity(true);
        me->SetHover(true);

        _lurkingOnCeilingPos = me->GetPosition();

        me->SetAIAnimKitId(ANIMKIT_MATRIARCH_LURKING_ON_CEILING);

        me->CastSpell(nullptr, SPELL_SKITTERWEB, true);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustReachedHome() override
    {
        me->SetDisableGravity(true);
        me->SetHover(true);

        me->CastSpell(nullptr, SPELL_SKITTERWEB, true);

        me->SetAIAnimKitId(ANIMKIT_MATRIARCH_HANGING_BY_WEB);

        me->GetMotionMaster()->MoveJump(_lurkingOnCeilingPos, 8.0f, 8.0f);

        _events.ScheduleEvent(EVENT_RESET_POSITION, 1s + 500ms);
    }

    void JustSummoned(Creature* summon) override
    {
        if (Unit* victim = me->GetVictim())
            summon->Attack(victim, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        _attackerGUID = who->GetGUID();

        me->AttackStop();

        me->SetAIAnimKitId(ANIMKIT_RESET);
        me->PlayOneShotAnimKitId(ANIMKIT_MATRIARCH_HANGING_BY_WEB);

        _events.ScheduleEvent(EVENT_MATRIARCH_AGGRO, 3s + 500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MATRIARCH_AGGRO:
                    me->SetDisableGravity(false);
                    me->SetHover(false);
                    me->GetMotionMaster()->MoveFall();
                    _events.ScheduleEvent(EVENT_MATRIARCH_AGGRO + 1, 1s);
                    break;

                case EVENT_MATRIARCH_AGGRO + 1:
                    me->PlayOneShotAnimKitId(ANIMKIT_MATRIARCH_INTERACT);
                    me->CastStop();
                    me->SetHomePosition(me->GetPosition());
                    _events.ScheduleEvent(EVENT_MATRIARCH_AGGRO + 2, 1s + 500ms);
                    break;

                case EVENT_MATRIARCH_AGGRO + 2:
                    if (Unit* attacker = ObjectAccessor::GetUnit(*me, _attackerGUID))
                        ScheduleCombatEvents(attacker);
                    break;

                case EVENT_RESET_POSITION:
                    me->SetFacingTo(0.820305f);
                    me->SetHomePosition(me->GetPosition());
                    me->SetAIAnimKitId(ANIMKIT_MATRIARCH_LURKING_ON_CEILING);
                    break;

                case EVENT_SUMMON_SPIDERLINGS:
                    DoCastSelf(SPELL_SUMMNON_SPIDERLINGS);
                    break;

                case EVENT_VENOM_SPLASH:
                    DoCastVictim(SPELL_VENOM_SPLASH);
                    _events.Repeat(15s, 18s);
                    break;

                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;
    }

    void ScheduleCombatEvents(Unit* who)
    {
        me->Attack(who, true);

        _events.ScheduleEvent(EVENT_SUMMON_SPIDERLINGS, 5s);
        _events.ScheduleEvent(EVENT_VENOM_SPLASH, 9s, 14s);
    }

private:
    EventMap _events;
    Position _lurkingOnCeilingPos;
    ObjectGuid _attackerGUID;
};

enum BondoftheValkyr
{
    SPELL_SUMMON_AGATHA_FENRIS                  = 83982
};

// 83979 - Bond of the Val'kyr
class spell_silverpine_bond_of_the_valkyr : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_AGATHA_FENRIS });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_SUMMON_AGATHA_FENRIS, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAura(SPELL_SUMMON_AGATHA_FENRIS);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_silverpine_bond_of_the_valkyr::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_silverpine_bond_of_the_valkyr::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

Position const AgathaBackFrontyardPos = { 982.57f, 671.04f, 77.298f };

enum AgathaFenrisIsle
{
    NPC_AGATHA_FENRIS                           = 44951,

    SPELL_BOND_OF_THE_VALKYR                    = 83979,
    SPELL_MARK_MASTER_AS_DESUMMONED             = 80929,
    SPELL_AGATHA_BROADCAST                      = 83978,
    SPELL_DOOMHOWL                              = 84012,
    SPELL_UNHOLY_DARKNESS                       = 84013,
    SPELL_UNHOLY_SMITE                          = 84014,
    SPELL_GENERAL_TRIGGER_84114                 = 84114,
    SPELL_GENERAL_TRIGGER_84107                 = 84107,
    SPELL_ARMORE_CAMERA_1                       = 84112,
    SPELL_ARMORE_CAMERA_4                       = 84111,
    SPELL_GENERAL_TRIGGER_84079                 = 84079,

    SPELL_RIDE_REVERSE_CAST_NO_ESCAPE           = 84109,

    EVENT_AGATHA_CHECK_PLAYER_HEALTH            = 1,
    EVENT_UNHOLY_SMITE                          = 2,
    EVENT_DOOMHOWL                              = 3,
    EVENT_FLEE_FROM_FENRIS                      = 4,

    TALK_AGATHA_BROADCAST                       = 0,
    TALK_AGATHA_RISE_FORSAKEN                   = 1,
    TALK_AGATHA_PRE_EVENT                       = 2,
    TALK_AGATHA_POST_EVENT1                     = 3,
    TALK_AGATHA_POST_EVENT2                     = 4,

    PATH_AGATHA_TO_FORSAKEN                     = 3596080,

    WAYPOINT_SPEED_UP                           = 14,
    WAYPOINT_ARRIVED_TO_FORSAKEN                = 19,

    POINT_AGATHA_BACK_FRONTYARD                 = 1
};

// 44951 - Agatha
struct npc_silverpine_agatha_fenris_isle : public ScriptedAI
{
    npc_silverpine_agatha_fenris_isle(Creature* creature) : ScriptedAI(creature), _isSceneStarted(false) { }

    void JustAppeared() override
    {
        // Note: SummonPropertiesFlags::HelpWhenSummonedInCombat is NYI.
        me->SetReactState(REACT_ASSIST);

        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);

        // Note: SummonPropertiesFlags::JoinSummonerSpawnGroup is NYI.
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveFollow(me->GetOwner(), 3.0f, float(M_PI / 2.0f));

        _events.ScheduleEvent(EVENT_AGATHA_CHECK_PLAYER_HEALTH, 1s);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        switch (spellInfo->Id)
        {
            case SPELL_AGATHA_BROADCAST:
            {
                if (_isSceneStarted)
                    return;

                if (Unit* summoner = tempSummon->GetSummonerUnit())
                    Talk(TALK_AGATHA_BROADCAST, summoner);
                break;
            }

            case SPELL_GENERAL_TRIGGER_84114:
            {
                if (!_isSceneStarted)
                    SetEventNoEscape();
                break;
            }

            case SPELL_GENERAL_TRIGGER_84107:
                if (Unit* summoner = tempSummon->GetSummonerUnit())
                    me->CastSpell(summoner, SPELL_ARMORE_CAMERA_1, true);
                break;

            case SPELL_ARMORE_CAMERA_4:
                _events.ScheduleEvent(EVENT_FLEE_FROM_FENRIS + 1, 1s);
                break;

            case SPELL_GENERAL_TRIGGER_84079:
                _events.ScheduleEvent(EVENT_FLEE_FROM_FENRIS + 2, 1s);
                break;

            case SPELL_DESPAWN_ALL_SUMMONS_NO_ESCAPE:
                DoCastSelf(SPELL_MARK_MASTER_AS_DESUMMONED);
                break;

            default:
                break;
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_AGATHA_TO_FORSAKEN)
        {
            if (waypointId == WAYPOINT_SPEED_UP)
                me->SetSpeed(MOVE_RUN, 15.880999f);
            else if (waypointId == WAYPOINT_ARRIVED_TO_FORSAKEN)
                _events.ScheduleEvent(EVENT_FLEE_FROM_FENRIS + 3, 100ms);
        }
    }

    void Reset() override
    {
        _events.CancelEvent(EVENT_UNHOLY_SMITE);
        _events.CancelEvent(EVENT_DOOMHOWL);

        // Note: SummonPropertiesFlags::JoinSummonerSpawnGroup is NYI.
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveFollow(me->GetOwner(), 3.0f, float(M_PI / 2.0f));
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_UNHOLY_SMITE, 500ms);
        _events.ScheduleEvent(EVENT_DOOMHOWL, 2s, 3s);
    }

    void UpdateAI(uint32 diff) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        // Note: SummonPropertiesFlags::DespawnOnSummonerDeath, SummonPropertiesFlags::DespawnOnSummonerLogout and SummonPropertiesFlags::DespawnWhenExpired are NYI.
        if (Unit* summoner = tempSummon->GetSummonerUnit())
        {
            if (!summoner->IsAlive() || !summoner->IsInWorld() || !summoner->HasAura(SPELL_SUMMON_AGATHA_FENRIS))
                me->DespawnOrUnsummon();
        }

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_AGATHA_CHECK_PLAYER_HEALTH:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        if (!me->HasUnitState(UNIT_STATE_CASTING) && summoner->GetHealthPct() < 75.0f)
                            me->CastSpell(summoner, SPELL_UNHOLY_DARKNESS, false);

                        _events.Repeat(1s);
                    }
                    break;
                }

                case EVENT_DOOMHOWL:
                    DoCastVictim(SPELL_DOOMHOWL);
                    _events.Repeat(14s, 18s);
                    break;

                case EVENT_UNHOLY_SMITE:
                    DoCastVictim(SPELL_UNHOLY_SMITE);
                    _events.Repeat(4s, 6s);
                    break;

                case EVENT_FLEE_FROM_FENRIS + 1:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        me->SetFacingTo(3.159046f);

                        Talk(TALK_AGATHA_POST_EVENT1, summoner);
                    }
                    break;
                }

                case EVENT_FLEE_FROM_FENRIS + 2:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        me->CastSpell(summoner, SPELL_RIDE_REVERSE_CAST_NO_ESCAPE, true);

                        Talk(TALK_AGATHA_POST_EVENT2, summoner);

                        if (Player* player = summoner->ToPlayer())
                            player->KilledMonsterCredit(NPC_AGATHA_FENRIS);

                        me->SetDisableGravity(true);
                        me->SetCanFly(true);

                        me->SetSpeed(MOVE_RUN, 7.7937083f);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePath(PATH_AGATHA_TO_FORSAKEN, false);
                    }
                    break;
                }

                case EVENT_FLEE_FROM_FENRIS + 3:
                {
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                    {
                        summoner->ExitVehicle();

                        _isSceneStarted = false;

                        me->SetSpeed(MOVE_RUN, 1.14286f);

                        // Note: SummonPropertiesFlags::JoinSummonerSpawnGroup is NYI.
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveFollow(summoner, 3.0f, float(M_PI / 2.0f));

                        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

                        me->SetReactState(REACT_ASSIST);
                    }
                    break;
                }

                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;
    }

    void SetEventNoEscape()
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        if (_isSceneStarted)
            return;

        _isSceneStarted = true;

        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

        me->SetReactState(REACT_PASSIVE);

        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MovePoint(POINT_AGATHA_BACK_FRONTYARD, AgathaBackFrontyardPos);

        if (Unit* summoner = tempSummon->GetSummonerUnit())
            Talk(TALK_AGATHA_PRE_EVENT, summoner);
    }

private:
    EventMap _events;
    bool _isSceneStarted;
};

enum NotifyAgatha
{
    SPELL_RISE_FORSAKEN_FENRIS                  = 83993
};

// 83990 - Notify Agatha
class spell_silverpine_notify_agatha : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RISE_FORSAKEN_FENRIS });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetExplTargetUnit();

        if (caster)
        {
            if (Creature* agatha = target->FindNearestCreature(NPC_AGATHA_FENRIS, 50.0f, true))
            {
                if (agatha->GetOwner() == target)
                {
                    agatha->CastSpell(caster, SPELL_RISE_FORSAKEN_FENRIS, true);

                    if (Player* player = target->ToPlayer())
                    {
                        if (roll_chance_i(50))
                        {
                            if (agatha->IsAIEnabled())
                                agatha->AI()->Talk(TALK_AGATHA_RISE_FORSAKEN, player);
                        }
                    }
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_notify_agatha::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum SpellForsakenTrooperMasterScriptFenrisIsle
{
    SPELL_FORSAKEN_TROOPER_MALE_01_F            = 83998,
    SPELL_FORSAKEN_TROOPER_MALE_02_F            = 83999,
    SPELL_FORSAKEN_TROOPER_MALE_03_F            = 84000,
    SPELL_FORSAKEN_TROOPER_MALE_04_F            = 84001,
    SPELL_FORSAKEN_TROOPER_FEMALE_01_F          = 84002,
    SPELL_FORSAKEN_TROOPER_FEMALE_02_F          = 84003,
    SPELL_FORSAKEN_TROOPER_FEMALE_03_F          = 84004,
    SPELL_FORSAKEN_TROOPER_FEMALE_04_F          = 84005,

    DISPLAY_MALE_01_F                           = 33978,
    DISPLAY_MALE_02_F                           = 33979,
    DISPLAY_MALE_03_F                           = 33980,
    DISPLAY_MALE_04_F                           = 33981,
    DISPLAY_FEMALE_01_F                         = 33982,
    DISPLAY_FEMALE_02_F                         = 33983,
    DISPLAY_FEMALE_03_F                         = 33984,
    DISPLAY_FEMALE_04_F                         = 33985
};

// 83997 - Forsaken Trooper Master Script (Fenris Isle)
class spell_silverpine_forsaken_trooper_masterscript_fenris_isle : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_FORSAKEN_TROOPER_MALE_01_F,
            SPELL_FORSAKEN_TROOPER_MALE_02_F,
            SPELL_FORSAKEN_TROOPER_MALE_03_F,
            SPELL_FORSAKEN_TROOPER_MALE_04_F,
            SPELL_FORSAKEN_TROOPER_FEMALE_01_F,
            SPELL_FORSAKEN_TROOPER_FEMALE_02_F,
            SPELL_FORSAKEN_TROOPER_FEMALE_03_F,
            SPELL_FORSAKEN_TROOPER_FEMALE_04_F
        });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* unit = GetCaster();

        if (Creature* hillsbradRefugee = unit->ToCreature())
        {
            uint32 spellId = unit->GetGender() == GENDER_MALE ? SPELL_FORSAKEN_TROOPER_MALE_01_F : SPELL_FORSAKEN_TROOPER_FEMALE_01_F;

            switch (hillsbradRefugee->GetDisplayId())
            {
                case DISPLAY_MALE_01_F:
                    spellId = SPELL_FORSAKEN_TROOPER_MALE_01_F;
                    break;
                case DISPLAY_MALE_02_F:
                    spellId = SPELL_FORSAKEN_TROOPER_MALE_02_F;
                    break;
                case DISPLAY_MALE_03_F:
                    spellId = SPELL_FORSAKEN_TROOPER_MALE_03_F;
                    break;
                case DISPLAY_MALE_04_F:
                    spellId = SPELL_FORSAKEN_TROOPER_MALE_04_F;
                    break;
                case DISPLAY_FEMALE_01_F:
                    spellId = SPELL_FORSAKEN_TROOPER_FEMALE_01_F;
                    break;
                case DISPLAY_FEMALE_02_F:
                    spellId = SPELL_FORSAKEN_TROOPER_FEMALE_02_F;
                    break;
                case DISPLAY_FEMALE_03_F:
                    spellId = SPELL_FORSAKEN_TROOPER_FEMALE_03_F;
                    break;
                case DISPLAY_FEMALE_04_F:
                    spellId = SPELL_FORSAKEN_TROOPER_FEMALE_04_F;
                    break;
                default:
                    break;
            }

            hillsbradRefugee->CastSpell(hillsbradRefugee, spellId, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_forsaken_trooper_masterscript_fenris_isle::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum HillsbradRefugee
{
    QUEST_RISE_FORSAKEN                         = 27097,

    SPELL_TROOPER_MASTERSCRIPT_FENRIS           = 83997,
    SPELL_NOTIFY_AGATHA_FENRIS                  = 83990,
    SPELL_LORDAERON_MIGHT                       = 87104,

    EVENT_LORDAERON_MIGHT                       = 1
};

// 44954, 44966 - Hillsbrad Refugee
struct npc_silverpine_hillsbrad_refugee : public ScriptedAI
{
    npc_silverpine_hillsbrad_refugee(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        _events.Reset();
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_RISE_FORSAKEN_FENRIS:
                DoCastSelf(SPELL_TROOPER_MASTERSCRIPT_FENRIS);
                me->DespawnOrUnsummon(2s);
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_RISE_FORSAKEN) == QUEST_STATUS_INCOMPLETE)
                me->CastSpell(player, SPELL_NOTIFY_AGATHA_FENRIS, true);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_LORDAERON_MIGHT, 3s, 8s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (!UpdateVictim())
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LORDAERON_MIGHT:
                    DoCastSelf(SPELL_LORDAERON_MIGHT);
                    _events.Repeat(15s, 18s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

enum ForsakenTrooperFenrisIsle
{
    EVENT_REFUGEE_JUST_RISEN                    = 1,

    TALK_REFUGEE_JUST_RISEN                     = 0,

    DISPLAY_MALE_01_D_F                         = 33986,
    DISPLAY_MALE_02_D_F                         = 33987,
    DISPLAY_MALE_03_D_F                         = 33988,
    DISPLAY_MALE_04_D_F                         = 33989,
    DISPLAY_FEMALE_01_D_F                       = 33991,
    DISPLAY_FEMALE_02_D_F                       = 33992,
    DISPLAY_FEMALE_03_D_F                       = 33993,
    DISPLAY_FEMALE_04_D_F                       = 33994
};

// 44958, 44959, 44960, 44961 - Forsaken Trooper (Male)
// 44962, 44963, 44964, 44965 - Forsaken Trooper (Female)
struct npc_silverpine_forsaken_trooper_fenris_isle : public ScriptedAI
{
    npc_silverpine_forsaken_trooper_fenris_isle(Creature* creature) : ScriptedAI(creature) {}

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (!summoner->IsCreature())
            return;

        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

        me->SetReactState(REACT_PASSIVE);

        uint32 displayId = me->GetGender() == GENDER_MALE ? DISPLAY_MALE_01_D_F : DISPLAY_FEMALE_01_D_F;

        switch (summoner->ToCreature()->GetDisplayId())
        {
            case DISPLAY_MALE_01_F:
                displayId = DISPLAY_MALE_01_D_F;
                break;
            case DISPLAY_MALE_02_F:
                displayId = DISPLAY_MALE_02_D_F;
                break;
            case DISPLAY_MALE_03_F:
                displayId = DISPLAY_MALE_03_D_F;
                break;
            case DISPLAY_MALE_04_F:
                displayId = DISPLAY_MALE_04_D_F;
                break;
            case DISPLAY_FEMALE_01_F:
                displayId = DISPLAY_FEMALE_01_D_F;
                break;
            case DISPLAY_FEMALE_02_F:
                displayId = DISPLAY_FEMALE_02_D_F;
                break;
            case DISPLAY_FEMALE_03_F:
                displayId = DISPLAY_FEMALE_03_D_F;
                break;
            case DISPLAY_FEMALE_04_F:
                displayId = DISPLAY_FEMALE_04_D_F;
                break;
            default:
                break;
        }

        me->SetDisplayId(displayId);

        _events.ScheduleEvent(EVENT_REFUGEE_JUST_RISEN, 1s);

        me->DespawnOrUnsummon(4s);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_REFUGEE_JUST_RISEN:
                    Talk(TALK_REFUGEE_JUST_RISEN);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

enum WorgenSentry
{
    SPELL_BATTLE_ROAR                           = 6507,
    SPELL_UNDYING_FRENZY                        = 80515,

    EVENT_UNDYING_FRENZY                        = 1,

    TALK_SENTRY_WARNING                         = 0
};

// 44987 - Worgen Sentry
struct npc_silverpine_worgen_sentry : public ScriptedAI
{
    npc_silverpine_worgen_sentry(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        _events.Reset();
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(TALK_SENTRY_WARNING);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_BATTLE_ROAR);

        _events.ScheduleEvent(EVENT_UNDYING_FRENZY, 3s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (!UpdateVictim())
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_UNDYING_FRENZY:
                    DoCastVictim(SPELL_UNDYING_FRENZY);
                    _events.Repeat(10s, 12s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

Position const NoEscapeStartPos = { 981.782f, 670.953f, 74.898f, 3.1887f };

enum FenrisKeepStalker
{
    SPELL_FORCE_CAST_FENRIS_CAMERA              = 84113
};

// 45032 - Fenris Keep Stalker
struct npc_silverpine_fenris_keep_stalker : public ScriptedAI
{
    npc_silverpine_fenris_keep_stalker(Creature* creature) : ScriptedAI(creature), eventIsTriggered(false) { }

    void Reset() override
    {
        eventIsTriggered = false;
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_GENERAL_TRIGGER_84107:
                Reset();
                break;
            default:
                break;
        }
    }

    void OnTriggerNoEscape(ObjectGuid playerGuid)
    {
        if (eventIsTriggered)
            return;

        if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
        {
            eventIsTriggered = true;

            me->CastSpell(player, SPELL_FORCE_CAST_FENRIS_CAMERA, true);

            player->NearTeleportTo(NoEscapeStartPos, true);
        }
    }

private:
    bool eventIsTriggered;
};

enum AtNoEscape
{
    NPC_FENRIS_KEEP_STALKER                     = 45032
};

// 6230 - No Escape
class at_silverpine_no_escape : public AreaTriggerScript
{
public:
    at_silverpine_no_escape() : AreaTriggerScript("at_silverpine_no_escape") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        if (!player->IsAlive() || player->GetQuestStatus(QUEST_NO_ESCAPE) != QUEST_STATUS_INCOMPLETE)
            return true;

        if (Creature* agatha = player->FindNearestCreature(NPC_AGATHA_FENRIS, 10.0f, true))
        {
            if (agatha->GetOwner() == player)
            {
                if (Creature* fenrisStalker = player->FindNearestCreature(NPC_FENRIS_KEEP_STALKER, 50.0f, true))
                {
                    if (npc_silverpine_fenris_keep_stalker* fenrisKeepStalkerAI = CAST_AI(npc_silverpine_fenris_keep_stalker, fenrisStalker->AI()))
                        fenrisKeepStalkerAI->OnTriggerNoEscape(player->GetGUID());
                }
            }
        }

        return true;
    }
};

enum SummonFenrisActors
{
    SPELL_SUMMON_BLOODFANG_FENRIS               = 84054,
    SPELL_SUMMON_CROWLEY_FENRIS                 = 84055,
    SPELL_SUMMON_PHIN_ODELIC                    = 84056,
    SPELL_SUMMON_BARTOLO_GINSETTI               = 84057,
    SPELL_SUMMON_LOREMASTER_DIBBS               = 84058,
    SPELL_SUMMON_MAGISTRATE_HENRY               = 84059,
    SPELL_SUMMON_CARETAKER_SMITHERS             = 84060,
    SPELL_SUMMON_SOPHIA                         = 84061
};

// 84053 - Summon Fenris Actors
class spell_silverpine_summon_fenris_keep_actors : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_SUMMON_BLOODFANG_FENRIS,
            SPELL_SUMMON_CROWLEY_FENRIS,
            SPELL_SUMMON_PHIN_ODELIC,
            SPELL_SUMMON_BARTOLO_GINSETTI,
            SPELL_SUMMON_LOREMASTER_DIBBS,
            SPELL_SUMMON_MAGISTRATE_HENRY,
            SPELL_SUMMON_CARETAKER_SMITHERS,
            SPELL_SUMMON_SOPHIA
        });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        target->CastSpell(target, SPELL_SUMMON_BLOODFANG_FENRIS, true);
        target->CastSpell(target, SPELL_SUMMON_CROWLEY_FENRIS, true);
        target->CastSpell(target, SPELL_SUMMON_PHIN_ODELIC, true);
        target->CastSpell(target, SPELL_SUMMON_BARTOLO_GINSETTI, true);
        target->CastSpell(target, SPELL_SUMMON_LOREMASTER_DIBBS, true);
        target->CastSpell(target, SPELL_SUMMON_MAGISTRATE_HENRY, true);
        target->CastSpell(target, SPELL_SUMMON_CARETAKER_SMITHERS, true);
        target->CastSpell(target, SPELL_SUMMON_SOPHIA, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_summon_fenris_keep_actors::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

Position const CameraFrontyardPos = { 980.7f, 689.14f, 76.9f };

enum FenrisKeepCamera
{
    SPELL_SUMMON_FENRIS_ACTORS                  = 84053,
    SPELL_GENERAL_TRIGGER_84102                 = 84102,
    SPELL_FORCE_SEAT_2                          = 84091,
    SPELL_DESPAWN_ALL_SUMMONS_FENRIS            = 84066,

    EVENT_MOVE_TO_START_POINT                   = 1,
    EVENT_CHANGE_TO_SEAT_2                      = 2,
    EVENT_TRIGGER_84102                         = 3,
    EVENT_SCENE_FINISH_FENRIS                   = 4,

    POINT_CAMERA_FRONTYARD                      = 1,

    SEAT_FENRIS_CAMERA                          = 0,
    SEAT_FENRIS_CAMERA_FORCE                    = 1
};

// 45003 - Fenris Keep Camera
struct npc_silverpine_fenris_keep_camera : public ScriptedAI
{
    npc_silverpine_fenris_keep_camera(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Unit* unit = summoner->ToUnit())
            unit->EnterVehicle(me, SEAT_FENRIS_CAMERA);

        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

        me->SetReactState(REACT_PASSIVE);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_GENERAL_TRIGGER_84107:
                _events.ScheduleEvent(EVENT_SCENE_FINISH_FENRIS, 2s + 500ms);
                break;
            default:
                break;
        }
    }

    void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
    {
        if (apply)
        {
            if (seatId == SEAT_FENRIS_CAMERA)
            {
                _events.ScheduleEvent(EVENT_MOVE_TO_START_POINT, 10ms);

                me->CastSpell(passenger, SPELL_SUMMON_FENRIS_ACTORS, true);
            }
            else if (seatId == SEAT_FENRIS_CAMERA_FORCE)
                passenger->SetFacingTo(0.0f);
        }
        else
        {
            if (seatId == SEAT_FENRIS_CAMERA_FORCE)
                _events.ScheduleEvent(EVENT_SCENE_FINISH_FENRIS, 1s);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_CAMERA_FRONTYARD)
            _events.ScheduleEvent(EVENT_CHANGE_TO_SEAT_2, 500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        TempSummon* summon = me->ToTempSummon();
        if (!summon)
            return;

        Unit* summoner = summon->GetSummonerUnit();
        if (!summoner)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TO_START_POINT:
                    me->GetMotionMaster()->MovePoint(POINT_CAMERA_FRONTYARD, CameraFrontyardPos);
                    break;

                case EVENT_CHANGE_TO_SEAT_2:
                    me->CastSpell(summoner, SPELL_FORCE_SEAT_2, true);
                    _events.ScheduleEvent(EVENT_TRIGGER_84102, 2s);
                    break;

                case EVENT_TRIGGER_84102:
                    summoner->CastSpell(summoner, SPELL_GENERAL_TRIGGER_84102, true);
                    break;

                case EVENT_SCENE_FINISH_FENRIS:
                    if (Creature* agatha = me->FindNearestCreature(NPC_AGATHA_FENRIS, 60.0f))
                        me->CastSpell(agatha, SPELL_GENERAL_TRIGGER_84079, true);
                    me->SetFacingTo(0.08278348f);
                    _events.ScheduleEvent(EVENT_SCENE_FINISH_FENRIS + 1, 4s);
                    break;

                case EVENT_SCENE_FINISH_FENRIS + 1:
                    me->CastSpell(summoner, SPELL_DESPAWN_ALL_SUMMONS_FENRIS, true);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

enum DariusCrowleyFenris
{
    NPC_CROWLEY_FENRIS                          = 44989,
    NPC_MAGISTRATE_HENRY_MALEB                  = 44996,

    SPELL_ARMORE_CAMERA_FENRIS                  = 83768,
    SPELL_CONVERSATION_TRIGGER_84076            = 84076,

    EVENT_CROWLEY_ANIMATION_FENRIS              = 1,

    TALK_CROWLEY_NO_ESCAPE_0                    = 0,
    TALK_CROWLEY_NO_ESCAPE_1                    = 1,
    TALK_CROWLEY_NO_ESCAPE_2                    = 2,
    TALK_CROWLEY_NO_ESCAPE_3                    = 3,
    TALK_CROWLEY_NO_ESCAPE_4                    = 4,
    TALK_CROWLEY_NO_ESCAPE_5                    = 5,
    TALK_CROWLEY_NO_ESCAPE_6                    = 6
};

// 44989 - Lord Darius Crowley, 44990 - Packleader Ivar Bloodfang
struct npc_silverpine_crowley_bloodfang_fenris_keep : public ScriptedAI
{
    npc_silverpine_crowley_bloodfang_fenris_keep(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

        me->SetReactState(REACT_PASSIVE);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        if (me->GetEntry() != NPC_CROWLEY_FENRIS)
            return;

        switch (spellInfo->Id)
        {
            case SPELL_GENERAL_TRIGGER_84102:
            {
                if (Unit* summoner = tempSummon->GetSummonerUnit())
                {
                    me->CastSpell(summoner, SPELL_ARMORE_CAMERA_FENRIS, true);

                    Talk(TALK_CROWLEY_NO_ESCAPE_6, summoner);

                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS, 2s + 500ms);
                }
                break;
            }

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        Unit* summoner = tempSummon->GetSummonerUnit();
        if (!summoner)
            return;

        _events.Update(diff);

        if (me->GetEntry() != NPC_CROWLEY_FENRIS)
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CROWLEY_ANIMATION_FENRIS:
                    Talk(TALK_CROWLEY_NO_ESCAPE_0, summoner);
                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS + 1, 4s + 700ms);
                    break;

                case EVENT_CROWLEY_ANIMATION_FENRIS + 1:
                    Talk(TALK_CROWLEY_NO_ESCAPE_1, summoner);
                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS + 2, 4s + 700ms);
                    break;

                case EVENT_CROWLEY_ANIMATION_FENRIS + 2:
                    Talk(TALK_CROWLEY_NO_ESCAPE_2, summoner);
                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS + 3, 4s + 700ms);
                    break;

                case EVENT_CROWLEY_ANIMATION_FENRIS + 3:
                    Talk(TALK_CROWLEY_NO_ESCAPE_3, summoner);
                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS + 4, 4s + 700ms);
                    break;

                case EVENT_CROWLEY_ANIMATION_FENRIS + 4:
                    Talk(TALK_CROWLEY_NO_ESCAPE_4, summoner);
                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS + 5, 6s + 100ms);
                    break;

                case EVENT_CROWLEY_ANIMATION_FENRIS + 5:
                    Talk(TALK_CROWLEY_NO_ESCAPE_5, summoner);
                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS + 6, 9s + 500ms);
                    break;

                case EVENT_CROWLEY_ANIMATION_FENRIS + 6:
                    if (Creature* henry = me->FindNearestCreature(NPC_MAGISTRATE_HENRY_MALEB, 30.0f))
                        me->CastSpell(henry, SPELL_CONVERSATION_TRIGGER_84076, true);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

enum GeneralActorFenris
{
    NPC_BLOODFANG_FENRIS                        = 44990,
    NPC_PHIN_ODELIC                             = 44993,
    NPC_BARTOLO_GINSETTI                        = 44994,
    NPC_LOREMASTER_DIBBS                        = 44995,
    NPC_CARETAKER_SMITHERS                      = 44997,
    NPC_SOPHIA_ZWOSKI                           = 45002,
    NPC_FENRIS_KEEP_CAMERA                      = 45003,

    SPELL_CONVERSATION_TRIGGER_84077            = 84077,
    SPELL_ARMORE_CAMERA_2                       = 84104,
    SPELL_ARMORE_CAMERA_3                       = 84103,
    SPELL_BLOOD_ODELIC                          = 84094,
    SPELL_BLOOD_BARTOLO                         = 84095,
    SPELL_BLOOD_DIBBS                           = 84096,
    SPELL_BLOOD_HENRY                           = 84097,
    SPELL_BLOOD_SMITHERS                        = 84098,
    SPELL_BLOOD_ZWOSKI                          = 84099,

    EVENT_MAGISTRATE_ANIMATION                  = 1,
    EVENT_ACTOR_FENRIS_DRINK                    = 4,
    EVENT_ACTOR_FENRIS_MORPH                    = 5,

    TALK_HENRY_NO_ESCAPE_0                      = 0,
    TALK_HENRY_NO_ESCAPE_1                      = 1,

    SOUND_HOWLING                               = 17671
};

// 44993 - Phin Odelic, 44994 - Bartolo Ginsetti, 44995 - Loremaster Dibbs, 44996 - Magistrate Henry Maleb, 44997 - Caretaker Smithers, 45002 - Sophia Zwoski
struct npc_silverpine_generic_actor_fenris_keep : public ScriptedAI
{
    npc_silverpine_generic_actor_fenris_keep(Creature* creature) : ScriptedAI(creature), _isWorgen(false) { }

    void JustAppeared() override
    {
        if (Creature* fenrisStalker = me->FindNearestCreature(NPC_FENRIS_KEEP_STALKER, 50.0f, true))
            me->SetFacingToObject(fenrisStalker);

        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

        me->SetReactState(REACT_PASSIVE);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        switch (spellInfo->Id)
        {
            case SPELL_CONVERSATION_TRIGGER_84076:
                if (Unit* summoner = tempSummon->GetSummonerUnit())
                    me->CastSpell(summoner, SPELL_ARMORE_CAMERA_2, true);
                break;

            case SPELL_ARMORE_CAMERA_3:
                _events.ScheduleEvent(EVENT_MAGISTRATE_ANIMATION, 1s + 300ms);
                break;

            case SPELL_CONVERSATION_TRIGGER_84077:
                _events.ScheduleEvent(EVENT_ACTOR_FENRIS_DRINK, 1s);
                break;

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MAGISTRATE_ANIMATION:
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                        Talk(TALK_HENRY_NO_ESCAPE_0, summoner);
                    _events.ScheduleEvent(EVENT_MAGISTRATE_ANIMATION + 1, 10s + 800ms);
                    break;

                case EVENT_MAGISTRATE_ANIMATION + 1:
                    if (Unit* summoner = tempSummon->GetSummonerUnit())
                        Talk(TALK_HENRY_NO_ESCAPE_1, summoner);
                    _events.ScheduleEvent(EVENT_MAGISTRATE_ANIMATION + 2, 2s);
                    break;

                case EVENT_MAGISTRATE_ANIMATION + 2:
                    DoCastSelf(SPELL_CONVERSATION_TRIGGER_84077, true);
                    break;

                case EVENT_ACTOR_FENRIS_DRINK:
                    _events.ScheduleEvent(EVENT_ACTOR_FENRIS_MORPH, 1s + 500ms);
                    break;

                case EVENT_ACTOR_FENRIS_MORPH:
                {
                    _isWorgen = true;

                    uint32 spellId = 0;

                    switch (me->GetEntry())
                    {
                        case NPC_PHIN_ODELIC:
                            spellId = SPELL_BLOOD_ODELIC;
                            break;
                        case NPC_BARTOLO_GINSETTI:
                            spellId = SPELL_BLOOD_BARTOLO;
                            break;
                        case NPC_LOREMASTER_DIBBS:
                            spellId = SPELL_BLOOD_DIBBS;
                            break;
                        case NPC_MAGISTRATE_HENRY_MALEB:
                            spellId = SPELL_BLOOD_HENRY;
                            break;
                        case NPC_CARETAKER_SMITHERS:
                            spellId = SPELL_BLOOD_SMITHERS;
                            break;
                        case NPC_SOPHIA_ZWOSKI:
                            spellId = SPELL_BLOOD_ZWOSKI;
                            me->PlayDirectSound(SOUND_HOWLING);
                            break;
                        default:
                            break;
                    }

                    DoCastSelf(spellId);

                    _events.ScheduleEvent(EVENT_ACTOR_FENRIS_MORPH + 1, 1s);
                    break;
                }

                case EVENT_ACTOR_FENRIS_MORPH + 1:
                    me->HandleEmoteCommand(EMOTE_STATE_READY_UNARMED);
                    if (me->GetEntry() == NPC_MAGISTRATE_HENRY_MALEB)
                        _events.ScheduleEvent(EVENT_ACTOR_FENRIS_MORPH + 2, 2s);
                    break;

                case EVENT_ACTOR_FENRIS_MORPH + 2:
                    if (Creature* agatha = me->FindNearestCreature(NPC_AGATHA_FENRIS, 60.0f))
                        me->CastSpell(agatha, SPELL_GENERAL_TRIGGER_84107, true);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _isWorgen;
};

Position const LordaeronFinishScenePos = { 498.54f, 1560.2840f, 128.2032f, 1.100281f };

enum ForsakenWarhorsePlayer
{
    NPC_FORSAKEN_WARHORSE_SYLVANAS              = 45057,

    SPELL_RIDE_SYLVANAS_HORSE                   = 84166,
    SPELL_LORDAERON_COMPLETE                    = 84185,
    SPELL_DESPAWN_ALL_SUMMONS_LORDAERON         = 84173,
    SPELL_FADE_TO_BLACK                         = 89092,

    EVENT_ACTIVATE_SKIP                         = 1,

    SEAT_WARHORSE_SYLVANAS_PLAYER               = 1
};

// 45041 - Forsaken Warhorse (Player)
struct npc_silverpine_warhorse_player_lordaeron : public ScriptedAI
{
    npc_silverpine_warhorse_player_lordaeron(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->HandleEmoteCommand(EMOTE_ONESHOT_MOUNT_SPECIAL);

        me->CastSpell(nullptr, SPELL_RIDE_SYLVANAS_HORSE, true);

        me->SetReactState(REACT_PASSIVE);
    }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        Player* player = passenger->ToPlayer();
        if (!player)
            return;

        if (apply)
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        else
        {
            if (player->GetQuestStatus(QUEST_LORDAERON) == QUEST_STATUS_INCOMPLETE)
                player->CastSpell(player, SPELL_FADE_TO_BLACK, true);

            _events.ScheduleEvent(EVENT_ACTIVATE_SKIP, 250ms);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        Unit* summoner = tempSummon->GetSummonerUnit();
        if (!summoner)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ACTIVATE_SKIP:
                    me->CastSpell(summoner, SPELL_LORDAERON_COMPLETE, true);
                    summoner->NearTeleportTo(LordaeronFinishScenePos, false);
                    summoner->CastSpell(summoner, SPELL_DESPAWN_ALL_SUMMONS_LORDAERON, true);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

Position const LordaeronFinishPos = { 499.185f, 1549.9855f, 129.094f };

enum ForsakenWarhorseSylvanas
{
    NPC_SYLVANAS_LORDAERON                      = 45051,
    NPC_FORSAKEN_WARHORSE_PLAYER                = 45041,

    PATH_WARHORSE_TO_SEPULCHER                  = 450570,

    WAYPOINT_ARRIVED_TO_SEPULCHER               = 44,

    POINT_CLOSE_TO_ZONE                         = 1,

    SEAT_WARHORSE_SYLVANAS                      = 0
};

// 45057 - Forsaken Warhorse (Sylvanas)
struct npc_silverpine_warhorse_sylvanas_lordaeron : public ScriptedAI
{
    npc_silverpine_warhorse_sylvanas_lordaeron(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->HandleEmoteCommand(EMOTE_ONESHOT_MOUNT_SPECIAL);

        me->SetSpeed(MOVE_RUN, 6.3564f);

        me->SetReactState(REACT_PASSIVE);
    }

    void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
            return;

        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_WARHORSE_TO_SEPULCHER)
        {
            if (waypointId == WAYPOINT_ARRIVED_TO_SEPULCHER)
                me->GetMotionMaster()->MovePoint(POINT_CLOSE_TO_ZONE, LordaeronFinishPos, false, 3.5f);
        }
    }
};

enum SylvanasWindrunnerLordaeron
{
    SPELL_DREADGUARD_SALUTE_AURA                = 84200,
    SPELL_KILL_ME                               = 84180,
    SPELL_HEARTSTRIKE                           = 84182,

    EVENT_SYLVANAS_RIDE_WARHORSE_LORDAERON      = 1,
    EVENT_SYLVANAS_TALK                         = 3,
    EVENT_FINISH_SCENE_LORDAERON                = 25,
    EVENT_REMOVE_HEARTSTRIKE_COOLDOWN           = 27,

    TALK_SYLVANAS_LORDAERON_0                   = 0,
    TALK_SYLVANAS_LORDAERON_1                   = 1,
    TALK_SYLVANAS_LORDAERON_2                   = 2,
    TALK_SYLVANAS_LORDAERON_3                   = 3,
    TALK_SYLVANAS_LORDAERON_4                   = 4,
    TALK_SYLVANAS_LORDAERON_5                   = 5,
    TALK_SYLVANAS_LORDAERON_6                   = 6,
    TALK_SYLVANAS_LORDAERON_7                   = 7,
    TALK_SYLVANAS_LORDAERON_8                   = 8,
    TALK_SYLVANAS_LORDAERON_9                   = 9,
    TALK_SYLVANAS_LORDAERON_10                  = 10,
    TALK_SYLVANAS_LORDAERON_11                  = 11,
    TALK_SYLVANAS_LORDAERON_12                  = 12,
    TALK_SYLVANAS_LORDAERON_13                  = 13,
    TALK_SYLVANAS_LORDAERON_14                  = 14,
    TALK_SYLVANAS_LORDAERON_15                  = 15,
    TALK_SYLVANAS_LORDAERON_16                  = 16,
    TALK_SYLVANAS_LORDAERON_17                  = 17,
    TALK_SYLVANAS_LORDAERON_18                  = 18,
    TALK_SYLVANAS_LORDAERON_19                  = 19,
    TALK_SYLVANAS_LORDAERON_20                  = 20,
    TALK_SYLVANAS_LORDAERON_21                  = 21
};

// 45051 - Lady Sylvanas Windrunner (Lordaeron)
struct npc_silverpine_sylvanas_lordaeron : public ScriptedAI
{
    npc_silverpine_sylvanas_lordaeron(Creature* creature) : ScriptedAI(creature), _isHeartstrikeOnCooldown(false) { }

    void JustAppeared() override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        if (Unit* summoner = tempSummon->GetSummonerUnit())
        {
            std::vector<Creature*> sylvanasHorse;
            me->GetCreatureListWithEntryInGrid(sylvanasHorse, NPC_FORSAKEN_WARHORSE_SYLVANAS, 5.0f);
            for (Creature* forsakenWarhorse : sylvanasHorse)
            {
                if (forsakenWarhorse->GetOwner() != summoner)
                    continue;

                _sylvanasHorseGUID = forsakenWarhorse->GetGUID();

                me->EnterVehicle(forsakenWarhorse, SEAT_WARHORSE_SYLVANAS);

                _events.ScheduleEvent(EVENT_SYLVANAS_RIDE_WARHORSE_LORDAERON, 500ms);
            }
        }

        me->SetUnitFlag(UNIT_FLAG_UNK_6);
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetUnitFlag3(UNIT_FLAG3_UNK0);

        DoCastSelf(SPELL_DREADGUARD_SALUTE_AURA);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_KILL_ME || _isHeartstrikeOnCooldown)
            return;

        _isHeartstrikeOnCooldown = true;

        me->CastSpell(caster, SPELL_HEARTSTRIKE, false);

        _events.ScheduleEvent(EVENT_REMOVE_HEARTSTRIKE_COOLDOWN, 3s);
    }

    void UpdateAI(uint32 diff) override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        // Note: SummonPropertiesFlags::DespawnOnSummonerLogout and SummonPropertiesFlags::DespawnOnSummonerDeath are NYI.
        Unit* summoner = tempSummon->GetSummonerUnit();
        if (!summoner || !summoner->IsAlive())
        {
            me->DespawnOrUnsummon();
            return;
        }

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SYLVANAS_RIDE_WARHORSE_LORDAERON:
                    _events.ScheduleEvent(EVENT_SYLVANAS_RIDE_WARHORSE_LORDAERON + 1, 1s);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK, 7s + 500ms);
                    break;

                case EVENT_SYLVANAS_RIDE_WARHORSE_LORDAERON + 1:
                    if (Creature* sylvanasHorse = ObjectAccessor::GetCreature(*me, _sylvanasHorseGUID))
                        sylvanasHorse->GetMotionMaster()->MovePath(PATH_WARHORSE_TO_SEPULCHER, false);
                    break;

                case EVENT_SYLVANAS_TALK:
                    Talk(TALK_SYLVANAS_LORDAERON_0, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 1, 5s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 1:
                    Talk(TALK_SYLVANAS_LORDAERON_1, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 2, 5s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 2:
                    Talk(TALK_SYLVANAS_LORDAERON_2, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 3, 9s + 100ms);
                    break;

                case EVENT_SYLVANAS_TALK + 3:
                    Talk(TALK_SYLVANAS_LORDAERON_3, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 4, 5s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 4:
                    Talk(TALK_SYLVANAS_LORDAERON_4, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 5, 8s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 5:
                    Talk(TALK_SYLVANAS_LORDAERON_5, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 6, 9s + 200ms);
                    break;

                case EVENT_SYLVANAS_TALK + 6:
                    Talk(TALK_SYLVANAS_LORDAERON_6, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 7, 9s + 900ms);
                    break;

                case EVENT_SYLVANAS_TALK + 7:
                    Talk(TALK_SYLVANAS_LORDAERON_7, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 8, 10s + 900ms);
                    break;

                case EVENT_SYLVANAS_TALK + 8:
                    Talk(TALK_SYLVANAS_LORDAERON_8, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 9, 9s + 800ms);
                    break;

                case EVENT_SYLVANAS_TALK + 9:
                    Talk(TALK_SYLVANAS_LORDAERON_9, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 10, 6s + 100ms);
                    break;

                case EVENT_SYLVANAS_TALK + 10:
                    Talk(TALK_SYLVANAS_LORDAERON_10, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 11, 5s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 11:
                    Talk(TALK_SYLVANAS_LORDAERON_11, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 12, 9s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 12:
                    Talk(TALK_SYLVANAS_LORDAERON_12, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 13, 7s + 100ms);
                    break;

                case EVENT_SYLVANAS_TALK + 13:
                    Talk(TALK_SYLVANAS_LORDAERON_13, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 14, 11s + 300ms);
                    break;

                case EVENT_SYLVANAS_TALK + 14:
                    Talk(TALK_SYLVANAS_LORDAERON_14, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 15, 11s + 300ms);
                    break;

                case EVENT_SYLVANAS_TALK + 15:
                    Talk(TALK_SYLVANAS_LORDAERON_15, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 16, 9s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 16:
                    Talk(TALK_SYLVANAS_LORDAERON_16, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 17, 9s + 800ms);
                    break;

                case EVENT_SYLVANAS_TALK + 17:
                    Talk(TALK_SYLVANAS_LORDAERON_17, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 18, 5s + 800ms);
                    break;

                case EVENT_SYLVANAS_TALK + 18:
                    Talk(TALK_SYLVANAS_LORDAERON_18, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 19, 9s + 300ms);
                    break;

                case EVENT_SYLVANAS_TALK + 19:
                    Talk(TALK_SYLVANAS_LORDAERON_19, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 20, 12s + 500ms);
                    break;

                case EVENT_SYLVANAS_TALK + 20:
                    Talk(TALK_SYLVANAS_LORDAERON_20, summoner);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 21, 7s);
                    break;

                case EVENT_SYLVANAS_TALK + 21:
                    Talk(TALK_SYLVANAS_LORDAERON_21, summoner);
                    _events.ScheduleEvent(EVENT_FINISH_SCENE_LORDAERON, 10s);
                    break;

                case EVENT_FINISH_SCENE_LORDAERON:
                    summoner->CastSpell(summoner, SPELL_FADE_TO_BLACK, true);
                    me->CastSpell(summoner, SPELL_LORDAERON_COMPLETE, true);
                    _events.ScheduleEvent(EVENT_FINISH_SCENE_LORDAERON + 1, 100ms);
                    break;

                case EVENT_FINISH_SCENE_LORDAERON + 1:
                    summoner->NearTeleportTo(LordaeronFinishScenePos, false);
                    summoner->CastSpell(summoner, SPELL_DESPAWN_ALL_SUMMONS_LORDAERON, true);
                    break;

                case EVENT_REMOVE_HEARTSTRIKE_COOLDOWN:
                    _isHeartstrikeOnCooldown = false;
                    break;

                default:
                    break;
            }
        }

        UpdateVictim();
    }

private:
    EventMap _events;
    ObjectGuid _sylvanasHorseGUID;
    bool _isHeartstrikeOnCooldown;
};

enum DreadguardLordaeron
{
    SPELL_DREADGUARD_SALUTE                     = 84199,

    EVENT_RESET_ANIMKIT                         = 1,

    ANIMKIT_DREADGUARD                          = 898
};

// 44911 - Dreadguard
struct npc_silverpine_dreadguard_lordaeron : public ScriptedAI
{
    npc_silverpine_dreadguard_lordaeron(Creature* creature) : ScriptedAI(creature), _done(false) { }

    void Reset() override
    {
        _events.Reset();

        _done = false;
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_DREADGUARD_SALUTE:
                if (_done)
                    return;
                _done = true;
                me->SetAIAnimKitId(ANIMKIT_DREADGUARD);
                _events.ScheduleEvent(EVENT_RESET_ANIMKIT, 2s + 500ms);
                break;

        default:
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RESET_ANIMKIT:
                    _done = false;
                    me->SetAIAnimKitId(ANIMKIT_RESET);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _done;
};

Position const ForsakenTrooperMPos[8] =
{
    { 1278.29f, 1053.83f, 54.284f, 3.16124f },
    { 1258.23f, 1078.28f, 52.430f, 3.30653f },
    { 1251.07f, 1161.13f, 51.974f, 3.53822f },
    { 1204.23f, 1174.21f, 46.824f, 3.53822f },
    { 1180.46f, 1227.42f, 54.059f, 3.53822f },
    { 1244.08f, 1137.64f, 50.124f, 1.24199f },
    { 1219.74f, 1207.46f, 52.489f, 3.94696f },
    { 1278.76f, 1144.46f, 51.269f, 5.58114f }
};

Position const ForsakenTrooperFPos[8] =
{
    { 1308.89f, 1059.13f, 54.598f, 3.16124f },
    { 1227.65f, 1107.85f, 50.456f, 3.30653f },
    { 1252.97f, 1148.88f, 49.575f, 3.53822f },
    { 1178.60f, 1200.06f, 48.753f, 3.53822f },
    { 1144.25f, 1153.30f, 48.406f, 3.53822f },
    { 1308.06f, 1107.48f, 48.315f, 2.19707f },
    { 1163.96f, 1198.18f, 47.255f, 2.64785f },
    { 1301.43f, 1153.10f, 52.386f, 0.43350f }
};

Position const WorgenRenegadePos[16] =
{
    { 1278.29f, 1053.83f, 54.284f, 3.16124f },
    { 1258.23f, 1078.28f, 52.430f, 3.30653f },
    { 1251.07f, 1161.13f, 51.974f, 3.53822f },
    { 1204.23f, 1174.21f, 46.824f, 3.53822f },
    { 1180.46f, 1227.42f, 54.059f, 3.53822f },
    { 1244.08f, 1137.64f, 50.124f, 1.24199f },
    { 1219.74f, 1207.46f, 52.489f, 3.94696f },
    { 1278.76f, 1144.46f, 51.269f, 5.58114f },
    { 1308.89f, 1059.13f, 54.598f, 3.16124f },
    { 1227.65f, 1107.85f, 50.456f, 3.30653f },
    { 1252.97f, 1148.88f, 49.575f, 3.53822f },
    { 1178.60f, 1200.06f, 48.753f, 3.53822f },
    { 1144.25f, 1153.30f, 48.406f, 3.53822f },
    { 1308.06f, 1107.48f, 48.315f, 2.19707f },
    { 1163.96f, 1198.18f, 47.255f, 2.64785f },
    { 1301.43f, 1153.10f, 52.386f, 0.43350f }
};

Position const OrcDemolisherPos[3] =
{
    { 1072.83f, 1270.05f, 43.02f, 3.16124f },
    { 1013.34f, 1313.89f, 42.85f, 3.30653f },
    { 969.38f, 1361.34f, 47.302f, 3.53822f }
};

Position const SeaOrcPos[9] =
{
    { 1076.48f, 1253.85f, 45.929f, 2.43872f },
    { 1077.14f, 1263.65f, 43.694f, 1.59048f },
    { 1070.36f, 1263.61f, 45.013f, 1.56299f },

    { 1014.53f, 1307.78f, 43.935f, 1.54728f },
    { 1003.97f, 1315.32f, 44.549f, 4.10375f },
    { 1002.05f, 1338.77f, 44.450f, 3.85635f },

    { 971.74f, 1354.18f, 46.846f, 3.46365f  },
    { 964.22f, 1366.20f, 46.887f, 5.15618f  },
    { 969.18f, 1368.70f, 47.393f, 5.03445f  }
};

Position const SeaOrcLeaderPos1 = { 1010.04f, 1301.17f, 45.891f, 2.53684f };

Position const SeaOrcLeaderPos2 = { 1042.26f, 1337.02f, 37.903f, 3.68637f };

Position const DreadguardPos[33] =
{
    { 634.12701416015625f, 1320.52001953125f, 83.78723907470703125f, 3.630284786224365234f   },
    { 622.53802490234375f, 1340.219970703125f, 85.43963623046875f, 3.525565147399902343f     },
    { 629.906005859375f, 1326.52001953125f, 84.15843963623046875f, 3.665191411972045898f     },
    { 626.1669921875f, 1332.780029296875f, 84.69873809814453125f, 3.560471534729003906f      },
    { 618.56097412109375f, 1347.0999755859375f, 86.084136962890625f, 3.560471534729003906f   },
    { 614.75897216796875f, 1336.969970703125f, 86.1674346923828125f, 0.645771801471710205f   },
    { 625.81298828125f, 1317.010009765625f, 84.4972381591796875f, 0.645771801471710205f      },
    { 622.22601318359375f, 1322.6300048828125f, 85.16963958740234375f, 0.645771801471710205f },
    { 614.85400390625f, 1355.6300048828125f, 86.87713623046875f, 3.473205089569091796f       },
    { 618.52398681640625f, 1329.4599609375f, 85.74703216552734375f, 0.645771801471710205f    },
    { 610.7239990234375f, 1344.530029296875f, 86.6329345703125f, 0.645771801471710205f       },
    { 606.46002197265625f, 1352.8499755859375f, 87.35283660888671875f, 0.645771801471710205f },
    { 610.56298828125f, 1365.0999755859375f, 87.761932373046875f, 3.50811171531677246f       },
    { 602.11102294921875f, 1362.239990234375f, 88.252532958984375f, 0.645771801471710205f    },
    { 606.41302490234375f, 1376.47998046875f, 88.97403717041015625f, 3.438298702239990234f   },
    { 596.18597412109375f, 1372.81005859375f, 89.34323883056640625f, 0.645771801471710205f   },
    { 602.12701416015625f, 1384.3499755859375f, 90.04973602294921875f, 3.543018341064453125f },
    { 591.97601318359375f, 1380.77001953125f, 90.32863616943359375f, 0.645771801471710205f   },
    { 597.49102783203125f, 1395.3499755859375f, 91.6871337890625f, 3.647738218307495117f     },
    { 587.97601318359375f, 1390.5899658203125f, 91.8007354736328125f, 0.645771801471710205f  },
    { 592.40802001953125f, 1406.1600341796875f, 93.38373565673828125f, 3.525565147399902343f },
    { 583.12298583984375f, 1401.469970703125f, 93.7557373046875f, 0.645771801471710205f      },
    { 574.67401123046875f, 1412.9000244140625f, 96.23223876953125f, 5.480333805084228515f    },
    { 589.6409912109375f, 1422.1099853515625f, 96.60943603515625f, 5.16617441177368164f      },
    { 558.7659912109375f, 1426.969970703125f, 99.60413360595703125f, 0.48869219422340393f    },
    { 573.9439697265625f, 1436.8800048828125f, 100.802337646484375f, 4.729842185974121093f   },
    { 556.385009765625f, 1430.22998046875f, 100.3133392333984375f, 0.48869219422340393f      },
    { 573.3060302734375f, 1440.5400390625f, 101.784332275390625f, 3.96189737319946289f       },
    { 485.446014404296875f, 1509.739990234375f, 135.3153228759765625f, 1.221730470657348632f },
    { 464.031005859375f, 1486.9300537109375f, 146.788330078125f, 1.151917338371276855f       },
    { 472.25201416015625f, 1540.760009765625f, 131.2733306884765625f, 0.0f                   },
    { 554.0989990234375f, 1579.75f, 131.211334228515625f, 3.31612563133239746f               },
    { 511.608001708984375f, 1626.579956054687f, 125.6103363037109375f, 4.555309295654296875f }
};

enum SummonLordaeronActors
{
    NPC_FORSAKEN_TROOPER_M_LORDAERON            = 44791,
    NPC_FORSAKEN_TROOPER_F_LORDAERON            = 44792,
    NPC_ORC_MOVER_LORDAERON                     = 45589,
    NPC_ORC_DEMOLISHER_LORDAERON                = 45635,
    NPC_DREADGUARD_LORDAERON                    = 44911,

    PATH_ORC_LEADER1                            = 4494200,
    PATH_ORC_LEADER2                            = 4494201
};

// 84127 - Summon Lordaeron Actors
class spell_silverpine_summon_lordaeron_actors : public SpellScript
{
    PrepareSpellScript(spell_silverpine_summon_lordaeron_actors);

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        for (Position const& pos : ForsakenTrooperMPos)
            caster->SummonCreature(NPC_FORSAKEN_TROOPER_F_LORDAERON, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, GetSpellInfo()->Id, caster->GetGUID());

        for (Position const& pos : ForsakenTrooperFPos)
            caster->SummonCreature(NPC_FORSAKEN_TROOPER_M_LORDAERON, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, GetSpellInfo()->Id, caster->GetGUID());

        for (Position const& pos : WorgenRenegadePos)
            caster->SummonCreature(NPC_WORGEN_RENEGADE, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, GetSpellInfo()->Id, caster->GetGUID());

        for (Position const& pos : OrcDemolisherPos)
            caster->SummonCreature(NPC_ORC_DEMOLISHER_LORDAERON, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, GetSpellInfo()->Id, caster->GetGUID());

        for (Position const& pos : SeaOrcPos)
            caster->SummonCreature(NPC_ORC_MOVER_LORDAERON, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, GetSpellInfo()->Id, caster->GetGUID());

        if (Creature* leaderOrc = caster->SummonCreature(NPC_ORC_MOVER_LORDAERON, SeaOrcLeaderPos1, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, GetSpellInfo()->Id, caster->GetGUID()))
        {
            leaderOrc->GetMotionMaster()->MovePath(PATH_ORC_LEADER1, true);

            for (uint8 i = 0; i < 4; i++)
                if (Creature* orc = caster->SummonCreature(NPC_ORC_MOVER_LORDAERON, SeaOrcLeaderPos1, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, GetSpellInfo()->Id, caster->GetGUID()))
                    orc->GetMotionMaster()->MoveChase(leaderOrc, float(3.0f * i));
        }

        if (Creature* leaderOrc = caster->SummonCreature(NPC_ORC_MOVER_LORDAERON, SeaOrcLeaderPos2, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, GetSpellInfo()->Id, caster->GetGUID()))
        {
            leaderOrc->GetMotionMaster()->MovePath(PATH_ORC_LEADER2, true);

            for (uint8 i = 0; i < 4; i++)
                if (Creature* orc = caster->SummonCreature(NPC_ORC_MOVER_LORDAERON, SeaOrcLeaderPos2, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, GetSpellInfo()->Id, caster->GetGUID()))
                    orc->GetMotionMaster()->MoveChase(leaderOrc, float(3.0f * i));
        }

        for (Position const& pos : DreadguardPos)
            caster->SummonCreature(NPC_DREADGUARD_LORDAERON, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, GetSpellInfo()->Id, caster->GetGUID());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_summon_lordaeron_actors::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_silverpine_forest()
{
    /* Vehicles */

    RegisterCreatureAI(npc_silverpine_horde_hauler);
    RegisterSpellScript(spell_silverpine_magical_chains_hauler);

    /* Forsaken High Command */

    RegisterCreatureAI(npc_silverpine_grand_executor_mortuus);
    RegisterSpellScript(spell_silverpine_raise_forsaken_83173);
    RegisterCreatureAI(npc_silverpine_fallen_human);
    RegisterSpellScript(spell_silverpine_forsaken_trooper_masterscript_high_command);
    RegisterCreatureAI(npc_silverpine_sylvanas_windrunner_high_command_sepulcher);
    RegisterCreatureAI(npc_silverpine_deathstalker);
    RegisterCreatureAI(npc_silverpine_worgen_renegade);
    RegisterSpellScript(spell_silverpine_flurry_of_claws);
    RegisterCreatureAI(npc_silverpine_forsaken_trooper);
    RegisterCreatureAI(npc_silverpine_bat_handler_maggotbreath);
    RegisterCreatureAI(npc_silverpine_forsaken_bat);

    /* Ivar Patch */

    RegisterGameObjectAI(go_silverpine_abandoned_outhouse);
    RegisterCreatureAI(npc_silverpine_deathstalker_rane_yorick);
    RegisterCreatureAI(npc_silverpine_armoire);
    RegisterCreatureAI(npc_silverpine_lord_darius_crowley_exsanguinate);
    RegisterCreatureAI(npc_silverpine_packleader_ivar_bloodfang_exsanguinate);

    /* Forsaken Rear Guard */

    new at_silverpine_forsaken_rear_guard();
    RegisterCreatureAI(npc_silverpine_salty_rocka);
    RegisterCreatureAI(npc_silverpine_apothecary_wormcrud);
    RegisterCreatureAI(npc_silverpine_admiral_hatchet);
    RegisterCreatureAI(npc_silverpine_orc_sea_dog_sick);
    RegisterCreatureAI(npc_silverpine_orc_sea_dog_not_sick);

    /* North Tide's Beachhead */

    RegisterSpellScript(spell_silverpine_despawn_all_summons_steel_thunder);
    RegisterCreatureAI(npc_silverpine_orc_sea_pup);
    RegisterCreatureAI(npc_silverpine_orc_crate);
    RegisterSpellScript(spell_silverpine_pick_up_orc_crate);
    RegisterCreatureAI(npc_silverpine_forest_ettin);
    RegisterCreatureAI(npc_silverpine_mutant_bush_chicken);
    RegisterSpellScript(spell_silverpine_release_diseased_mutant_bush_chicken);

    /* The Skittering Dark */

    RegisterCreatureAI(npc_silverpine_webbed_victim);
    RegisterSpellScript(spell_silverpine_free_webbed_victim_random);
    RegisterCreatureAI(npc_silverpine_orc_sea_dog);
    RegisterCreatureAI(npc_silverpine_skitterweb_matriarch);

    /* Fenris Isle */

    RegisterSpellScript(spell_silverpine_bond_of_the_valkyr);
    RegisterCreatureAI(npc_silverpine_agatha_fenris_isle);
    RegisterSpellScript(spell_silverpine_notify_agatha);
    RegisterSpellScript(spell_silverpine_forsaken_trooper_masterscript_fenris_isle);
    RegisterCreatureAI(npc_silverpine_hillsbrad_refugee);
    RegisterCreatureAI(npc_silverpine_forsaken_trooper_fenris_isle);
    RegisterCreatureAI(npc_silverpine_worgen_sentry);
    new at_silverpine_no_escape();
    RegisterSpellScript(spell_silverpine_summon_fenris_keep_actors);
    RegisterCreatureAI(npc_silverpine_fenris_keep_stalker);
    RegisterCreatureAI(npc_silverpine_fenris_keep_camera);
    RegisterCreatureAI(npc_silverpine_crowley_bloodfang_fenris_keep);
    RegisterCreatureAI(npc_silverpine_generic_actor_fenris_keep);

    /* Lordaeron */

    RegisterCreatureAI(npc_silverpine_warhorse_player_lordaeron);
    RegisterCreatureAI(npc_silverpine_warhorse_sylvanas_lordaeron);
    RegisterCreatureAI(npc_silverpine_sylvanas_lordaeron);
    RegisterCreatureAI(npc_silverpine_dreadguard_lordaeron);
    RegisterSpellScript(spell_silverpine_summon_lordaeron_actors);
}
