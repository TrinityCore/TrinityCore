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

    PATH_FROM_NORTH_TO_SOUTH                = 447310,
    PATH_TROOPER_1                          = 447320,
    PATH_TROOPER_2                          = 447321,
    PATH_TROOPER_3                          = 447322,
    PATH_TROOPER_4                          = 447323,
    PATH_TROOPER_5                          = 447324,

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
    PrepareAuraScript(spell_silverpine_magical_chains_hauler);

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
    EVENT_AGATHA_RAISE_FORSAKEN             = 4, // Note: 4-8 are used
    EVENT_SCENE_TALK_COMETH                 = 9, // Note: 9-36 are used

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

    PATH_CROMUSH                            = 446402,
    PATH_GARROSH                            = 446290,

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

        DoMeleeAttackIfReady();
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
    PrepareAuraScript(spell_silverpine_raise_forsaken_83173);

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
    PrepareSpellScript(spell_silverpine_forsaken_trooper_masterscript_high_command);

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
    QUEST_LORDAERON                             = 27098,
    QUEST_TO_FORSAKEN_HIGH_COMMAND              = 27290,

    NPC_FORSAKEN_WARHORSE                       = 73595,

    SPELL_SUMMON_FORSAKEN_WARHORSE_SERVERSIDE   = 148164,
    SPELL_APPLY_INVIS_ZONE_1                    = 83231,
    SPELL_APPLY_INVIS_ZONE_4                    = 84183,
    SPELL_SUMMON_SYLVANAS_AND_HORSE             = 84128,
    SPELL_SUMMON_FORSAKEN_WARHORSE              = 84164,
    SPELL_LORDAERON_AURA                        = 84189, // Note: NYI, after researching thoroughly, nothing seems to point what this SPELL_AURA_DUMMY should do. Maybe it is what forces the player to cast the rest of the spells.
    SPELL_SUMMON_LORDAERON_ACTORS               = 84127,
    SPELL_FLIGHT_OF_THE_VALKYR_FORWARD          = 84695
};

// 44365 - Lady Sylvanas Windrunner (Forsaken High Command and Sepulcher)
struct npc_silverpine_sylvanas_windrunner_high_command_sepulcher : public ScriptedAI
{
    npc_silverpine_sylvanas_windrunner_high_command_sepulcher(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SUMMON_FORSAKEN_WARHORSE);

        // Note: the Forsaken Horse must be set in the same visibility mask that Sylvanas is in.
        if (Creature* forsakenWarhorse = me->FindNearestCreature(NPC_FORSAKEN_WARHORSE, 5.0f, true))
            forsakenWarhorse->CastSpell(forsakenWarhorse, me->HasAura(SPELL_APPLY_INVIS_ZONE_1) ? SPELL_APPLY_INVIS_ZONE_1 : SPELL_APPLY_INVIS_ZONE_4, true);
    }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        switch (quest->GetQuestId())
        {
            case QUEST_LORDAERON:
                player->CastSpell(player, SPELL_SUMMON_SYLVANAS_AND_HORSE, true);
                player->CastSpell(player, SPELL_SUMMON_FORSAKEN_WARHORSE, true);
                player->CastSpell(player, SPELL_LORDAERON_AURA, true);
                player->CastSpell(player, SPELL_SUMMON_LORDAERON_ACTORS, true);
                break;

            case QUEST_TO_FORSAKEN_HIGH_COMMAND:
                player->CastSpell(player, SPELL_FLIGHT_OF_THE_VALKYR_FORWARD, true);
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
        // @TODO: figure out some common thing why powertype energy is used here
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 100, true);
    }
};

enum WorgenRenegade
{
    SPELL_HEARTSTRIKE                           = 84182,
    SPELL_KILL_ME_AURA                          = 84181,
    SPELL_FLURRY_OF_CLAWS                       = 80365,

    EVENT_FLURRY_OF_CLAWS                       = 1
};

// 44793 - Worgen Renegade
struct npc_silverpine_worgen_renegade : public ScriptedAI
{
    npc_silverpine_worgen_renegade(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();

        // Note: this is for a later usage during Lordaeron (questId 27098).
        if (me->IsSummon())
            DoCastSelf(SPELL_KILL_ME_AURA);

        me->SetReactState(REACT_AGGRESSIVE);
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // HACKFIX: sparring system is not implemented yet.
        if (!attacker->IsPlayer() && me->HealthBelowPctDamaged(80.0f, damage))
            damage = 0;
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

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

// 80365 - Flurry of Claws
class spell_silverpine_flurry_of_claws : public AuraScript
{
    PrepareAuraScript(spell_silverpine_flurry_of_claws);

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

        // Note: these texts are not sent by summoned creatures from Lordaeron (questId 27098).
        if (!me->IsSummon())
        {
            if (urand(0, 1))
                Talk(TALK_TROOPER_RESET);
        }
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // HACKFIX: sparring system is not implemented yet.
        if (!attacker->IsPlayer() && me->HealthBelowPctDamaged(80.0f, damage))
            damage = 0;
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

        DoMeleeAttackIfReady();
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

    PATH_BAT_TO_LAKE                            = 448210,
    PATH_BAT_AROUND_LAKE                        = 448211,
    PATH_BAT_TO_HOME                            = 448212,

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

                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);

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

Position const LordaeronCancelScenePos = { 498.54f, 1560.2840f, 128.2032f, 1.100281f };

enum ForsakenWarhorsePlayer
{
    SPELL_LORDAERON_COMPLETE                    = 84185,
    SPELL_DESPAWN_ALL_SUMMONS_LORDAERON         = 84173,
    SPELL_FADE_TO_BLACK                         = 89092,

    EVENT_ACTIVATE_SKIP                         = 1
};

// 45041 - Forsaken Warhorse (Player)
struct npc_silverpine_warhorse_player_lordaeron : public ScriptedAI
{
    npc_silverpine_warhorse_player_lordaeron(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
        {
            _playerGUID = player->GetGUID();

            player->EnterVehicle(me);

            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

            me->SetReactState(REACT_PASSIVE);
        }
    }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (passenger->GetTypeId() == TYPEID_PLAYER)
        {
            if (apply)
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_MOUNT_SPECIAL);

                me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
            else
            {
                if (passenger->ToPlayer()->GetQuestStatus(QUEST_LORDAERON) == QUEST_STATUS_INCOMPLETE)
                {
                    passenger->CastSpell(passenger, SPELL_FADE_TO_BLACK, true);
                    me->CastSpell(passenger, SPELL_LORDAERON_COMPLETE, true);

                    _events.ScheduleEvent(EVENT_ACTIVATE_SKIP, 100ms);
                }
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ACTIVATE_SKIP:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        player->NearTeleportTo(LordaeronCancelScenePos, false);
                        player->CastSpell(player, SPELL_DESPAWN_ALL_SUMMONS_LORDAERON, true);
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
    ObjectGuid _playerGUID;
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

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
        {
            _playerGUID = player->GetGUID();

            if (Creature* sylvanas = me->FindNearestCreature(NPC_SYLVANAS_LORDAERON, 10.0f))
                _sylvanasGUID = sylvanas->GetGUID();

            if (Creature* playerhorse = me->FindNearestCreature(NPC_FORSAKEN_WARHORSE_PLAYER, 10.0f))
                _playerHorseGUID = playerhorse->GetGUID();

            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

            me->SetReactState(REACT_PASSIVE);
        }
    }

    void PassengerBoarded(Unit* /*passenger*/, int8 seatId, bool apply) override
    {
        if (!apply)
            return;

        if (seatId == SEAT_WARHORSE_SYLVANAS)
            me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_WARHORSE_TO_SEPULCHER)
        {
            if (waypointId == WAYPOINT_ARRIVED_TO_SEPULCHER)
                me->GetMotionMaster()->MovePoint(POINT_CLOSE_TO_ZONE, LordaeronFinishPos, false, 3.5f);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;
    ObjectGuid _playerHorseGUID;
    ObjectGuid _sylvanasGUID;
};

enum SylvanasWindrunnerLordaeron
{
    NPC_FORSAKEN_WARHORSE_SYLVANAS              = 45057,

    SPELL_DREADGUARD_SALUTE_AURA                = 84200,
    SPELL_KILL_ME                               = 84180,

    EVENT_SYLVANAS_RIDE_WARHORSE_LORDAERON      = 1,
    EVENT_SYLVANAS_HEARTSTRIKE_COOLDOWN         = 3,
    EVENT_SYLVANAS_TALK                         = 4,
    EVENT_FINISH_SCENE_LORDAERON                = 26,

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
    TALK_SYLVANAS_LORDAERON_21                  = 21,

    SEAT_WARHORSE_PLAYER_BOARDED                = 1
};

// 45051 - Lady Sylvanas Windrunner (Lordaeron)
struct npc_silverpine_sylvanas_lordaeron : public ScriptedAI
{
    npc_silverpine_sylvanas_lordaeron(Creature* creature) : ScriptedAI(creature), _heartstrikeCD(false) { }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
            _playerGUID = player->GetGUID();

        if (Creature* sylvanashorse = me->FindNearestCreature(NPC_FORSAKEN_WARHORSE_SYLVANAS, 10.0f))
        {
            _sylvanasHorseGUID = sylvanashorse->GetGUID();

            me->EnterVehicle(sylvanashorse, SEAT_WARHORSE_SYLVANAS);

            if (sylvanashorse->IsAIEnabled())
                sylvanashorse->HandleEmoteCommand(EMOTE_ONESHOT_MOUNT_SPECIAL);

            _events.ScheduleEvent(EVENT_SYLVANAS_RIDE_WARHORSE_LORDAERON, 500ms);

            DoCastSelf(SPELL_DREADGUARD_SALUTE_AURA);
        }
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_KILL_ME:
            {
                if (_heartstrikeCD || me->HasUnitState(UNIT_STATE_CASTING))
                    me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                else
                {
                    me->HandleEmoteCommand(EMOTE_STATE_HOLD_BOW);

                    if (caster->ToUnit()->GetEntry() == NPC_WORGEN_RENEGADE)
                        me->CastSpell(caster, SPELL_HEARTSTRIKE, false);

                    _heartstrikeCD = true;

                    _events.ScheduleEvent(EVENT_SYLVANAS_HEARTSTRIKE_COOLDOWN, 2s);
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
                case EVENT_SYLVANAS_RIDE_WARHORSE_LORDAERON:
                {
                    if (Creature* playerhorse = me->FindNearestCreature(NPC_FORSAKEN_WARHORSE_PLAYER, 10.0f))
                    {
                        _playerHorseGUID = playerhorse->GetGUID();

                        if (Creature* sylvanashorse = me->FindNearestCreature(NPC_FORSAKEN_WARHORSE_SYLVANAS, 10.0f))
                            playerhorse->EnterVehicle(sylvanashorse, SEAT_WARHORSE_PLAYER_BOARDED);
                    }

                    _events.ScheduleEvent(EVENT_SYLVANAS_RIDE_WARHORSE_LORDAERON + 1, 1s);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK, 7s + 500ms);
                    break;
                }

                case EVENT_SYLVANAS_RIDE_WARHORSE_LORDAERON + 1:
                    if (Creature* sylvanashorse = me->FindNearestCreature(NPC_FORSAKEN_WARHORSE_SYLVANAS, 10.0f))
                        sylvanashorse->GetMotionMaster()->MovePath(PATH_WARHORSE_TO_SEPULCHER, false);
                    break;

                case EVENT_SYLVANAS_TALK:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_0, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 1, 5s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 1:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_1, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 2, 5s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 2:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_2, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 3, 9s + 100ms);
                    break;

                case EVENT_SYLVANAS_TALK + 3:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_3, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 4, 5s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 4:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_4, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 5, 8s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 5:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_5, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 6, 9s + 200ms);
                    break;

                case EVENT_SYLVANAS_TALK + 6:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_6, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 7, 9s + 900ms);
                    break;

                case EVENT_SYLVANAS_TALK + 7:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_7, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 8, 10s + 900ms);
                    break;

                case EVENT_SYLVANAS_TALK + 8:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_8, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 9, 9s + 800ms);
                    break;

                case EVENT_SYLVANAS_TALK + 9:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_9, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 10, 6s + 100ms);
                    break;

                case EVENT_SYLVANAS_TALK + 10:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_10, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 11, 5s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 11:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_11, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 12, 9s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 12:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_12, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 13, 7s + 100ms);
                    break;

                case EVENT_SYLVANAS_TALK + 13:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_13, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 14, 11s + 300ms);
                    break;

                case EVENT_SYLVANAS_TALK + 14:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_14, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 15, 11s + 300ms);
                    break;

                case EVENT_SYLVANAS_TALK + 15:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_15, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 16, 9s + 600ms);
                    break;

                case EVENT_SYLVANAS_TALK + 16:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_16, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 17, 9s + 800ms);
                    break;

                case EVENT_SYLVANAS_TALK + 17:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_17, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 18, 5s + 800ms);
                    break;

                case EVENT_SYLVANAS_TALK + 18:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_18, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 19, 9s + 300ms);
                    break;

                case EVENT_SYLVANAS_TALK + 19:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_19, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 20, 12s + 500ms);
                    break;

                case EVENT_SYLVANAS_TALK + 20:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_20, player);
                    _events.ScheduleEvent(EVENT_SYLVANAS_TALK + 21, 7s);
                    break;

                case EVENT_SYLVANAS_TALK + 21:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_SYLVANAS_LORDAERON_21, player);
                    _events.ScheduleEvent(EVENT_FINISH_SCENE_LORDAERON, 10s);
                    break;

                case EVENT_FINISH_SCENE_LORDAERON:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        player->CastSpell(player, SPELL_FADE_TO_BLACK, true);
                        me->CastSpell(player, SPELL_LORDAERON_COMPLETE, true);
                    }

                    _events.ScheduleEvent(EVENT_FINISH_SCENE_LORDAERON + 1, 100ms);
                    break;
                }

                case EVENT_FINISH_SCENE_LORDAERON + 1:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        player->NearTeleportTo(LordaeronCancelScenePos, false);
                        player->CastSpell(player, SPELL_DESPAWN_ALL_SUMMONS_LORDAERON, true);
                    }
                    break;
                }

                case EVENT_SYLVANAS_HEARTSTRIKE_COOLDOWN:
                    _heartstrikeCD = false;
                    break;

                default:
                    break;
            }
        }

        UpdateVictim();
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;
    ObjectGuid _playerHorseGUID;
    ObjectGuid _sylvanasHorseGUID;
    bool _heartstrikeCD;
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
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_DREADGUARD_SALUTE:
            {
                if (_done)
                    return;

                me->SetAIAnimKitId(ANIMKIT_DREADGUARD);

                _done = true;

                _events.ScheduleEvent(EVENT_RESET_ANIMKIT, 2s + 500ms);
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
    { 1308.89f, 1059.138f, 54.598f, 3.16124f },
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
    { 1308.89f, 1059.138f, 54.598f, 3.16124f },
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

    { 971.74f, 1354.18f, 46.846f, 3.46365f },
    { 964.22f, 1366.20f, 46.887f, 5.15618f },
    { 969.18f, 1368.70f, 47.393f, 5.03445f },
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
        if (Unit* caster = GetCaster())
        {
            _playerGUID = caster->GetGUID();

            for (Position const& pos : ForsakenTrooperMPos)
                caster->SummonCreature(NPC_FORSAKEN_TROOPER_F_LORDAERON, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, SPELL_SUMMON_LORDAERON_ACTORS, _playerGUID);

            for (Position const& pos : ForsakenTrooperFPos)
                caster->SummonCreature(NPC_FORSAKEN_TROOPER_M_LORDAERON, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, SPELL_SUMMON_LORDAERON_ACTORS, _playerGUID);

            for (Position const& pos : WorgenRenegadePos)
                caster->SummonCreature(NPC_WORGEN_RENEGADE, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, SPELL_SUMMON_LORDAERON_ACTORS, _playerGUID);

            for (Position const& pos : OrcDemolisherPos)
                caster->SummonCreature(NPC_ORC_DEMOLISHER_LORDAERON, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, SPELL_SUMMON_LORDAERON_ACTORS, _playerGUID);

            for (Position const& pos : SeaOrcPos)
                caster->SummonCreature(NPC_ORC_MOVER_LORDAERON, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, SPELL_SUMMON_LORDAERON_ACTORS, _playerGUID);

            if (Creature* leaderOrc = caster->SummonCreature(NPC_ORC_MOVER_LORDAERON, SeaOrcLeaderPos1, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, SPELL_SUMMON_LORDAERON_ACTORS, _playerGUID))
            {
                leaderOrc->GetMotionMaster()->MovePath(PATH_ORC_LEADER1, true);

                for (uint8 i = 0; 0 < 4; i++)
                    if (Creature* orc = caster->SummonCreature(NPC_ORC_MOVER_LORDAERON, SeaOrcLeaderPos1, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, SPELL_SUMMON_LORDAERON_ACTORS, _playerGUID))
                        orc->GetMotionMaster()->MoveFollow(leaderOrc, float(3 * i), 0.0f);
            }

            if (Creature* leaderOrc = caster->SummonCreature(NPC_ORC_MOVER_LORDAERON, SeaOrcLeaderPos2, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, SPELL_SUMMON_LORDAERON_ACTORS, _playerGUID))
            {
                leaderOrc->GetMotionMaster()->MovePath(PATH_ORC_LEADER2, true);

                for (uint8 i = 0; 0 < 4; i++)
                    if (Creature* orc = caster->SummonCreature(NPC_ORC_MOVER_LORDAERON, SeaOrcLeaderPos2, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, SPELL_SUMMON_LORDAERON_ACTORS, _playerGUID))
                        orc->GetMotionMaster()->MoveFollow(leaderOrc, float(3 * i), 0.0f);
            }

            for (Position const& pos : DreadguardPos)
                caster->SummonCreature(NPC_DREADGUARD_LORDAERON, pos, TEMPSUMMON_TIMED_DESPAWN, 300s, 0, SPELL_SUMMON_LORDAERON_ACTORS, _playerGUID);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_summon_lordaeron_actors::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }

private:
    ObjectGuid _playerGUID;
};

// 84173 - Despawn All Summons
class spell_silverpine_despawn_all_summons_lordaeron : public SpellScript
{
    PrepareSpellScript(spell_silverpine_despawn_all_summons_lordaeron);

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();

        if (target->GetOwner() == GetCaster())
            target->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_despawn_all_summons_lordaeron::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
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
    RegisterCreatureAI(npc_silverpine_warhorse_player_lordaeron);
    RegisterCreatureAI(npc_silverpine_warhorse_sylvanas_lordaeron);
    RegisterCreatureAI(npc_silverpine_sylvanas_lordaeron);
    RegisterCreatureAI(npc_silverpine_dreadguard_lordaeron);
    RegisterSpellScript(spell_silverpine_summon_lordaeron_actors);
    RegisterSpellScript(spell_silverpine_despawn_all_summons_lordaeron);
}
