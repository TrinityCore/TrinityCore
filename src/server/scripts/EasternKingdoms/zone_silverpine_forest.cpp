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
    NPC_FORSAKEN_WARHORSE                       = 73595,

    SPELL_SUMMON_FORSAKEN_WARHORSE              = 148164,
    SPELL_APPLY_INVIS_ZONE_1                    = 83231,
    SPELL_APPLY_INVIS_ZONE_4                    = 84183
};

// 44365 - Lady Sylvanas Windrunner (Forsaken High Command)
struct npc_silverpine_sylvanas_windrunner_high_command : public ScriptedAI
{
    npc_silverpine_sylvanas_windrunner_high_command(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SUMMON_FORSAKEN_WARHORSE);

        // Note: the Forsaken Horse must be set in the same visibility mask that Sylvanas is in.
        if (Creature* forsakenWarhorse = me->FindNearestCreature(NPC_FORSAKEN_WARHORSE, 5.0f, true))
            forsakenWarhorse->CastSpell(forsakenWarhorse, me->HasAura(SPELL_APPLY_INVIS_ZONE_1) ? SPELL_APPLY_INVIS_ZONE_1 : SPELL_APPLY_INVIS_ZONE_4, true);
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

enum BondoftheValkyr
{
    SPELL_SUMMON_AGATHA_FENRIS                  = 83982
};

// 83979 - Bond of the Val'kyr
class spell_silverpine_bond_of_the_valkyr : public AuraScript
{
    PrepareAuraScript(spell_silverpine_bond_of_the_valkyr);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_AGATHA_FENRIS });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_SUMMON_AGATHA_FENRIS, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAura(SPELL_SUMMON_AGATHA_FENRIS);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_silverpine_bond_of_the_valkyr::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_silverpine_bond_of_the_valkyr::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

Position const AgathaBackFrontyardPos = { 982.57f, 671.04f, 77.298f };

enum AgathaFenrisIsle
{
    NPC_AGATHA_FENRIS                           = 44951,

    SPELL_BOND_OF_THE_VALKYR                    = 83979,
    SPELL_DESPAWN_ALL_SUMMONS_AGATHA            = 84011,
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
    SPELL_RIDE_REVERSE_CAST_RIDE_VEHICLE        = 84109,

    EVENT_AGATHA_CHECK_PLAYER                   = 1,
    EVENT_UNHOLY_SMITE                          = 2,
    EVENT_DOOMHOWL                              = 3,
    EVENT_UNHOLY_DARKNESS_COOLDOWN              = 4,
    EVENT_FLEE_FROM_FENRIS                      = 5,

    TALK_AGATHA_BROADCAST                       = 0,
    TALK_AGATHA_RISE_FORSAKEN                   = 1,
    TALK_AGATHA_PRE_EVENT                       = 2,
    TALK_AGATHA_POST_EVENT1                     = 3,
    TALK_AGATHA_POST_EVENT2                     = 4,

    PATH_AGATHA_TO_FORSAKEN                     = 449510,

    WAYPOINT_SPEED_UP                           = 15,
    WAYPOINT_ARRIVED_TO_FORSAKEN                = 19,

    POINT_AGATHA_BACK_FRONTYARD                 = 1
};

// 44951 - Agatha
struct npc_silverpine_agatha_fenris_isle : public ScriptedAI
{
    npc_silverpine_agatha_fenris_isle(Creature* creature) : ScriptedAI(creature), _healCD(false), _sceneStarted(false) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_ASSIST);

        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);

        me->GetMotionMaster()->Clear();

        me->GetMotionMaster()->MoveFollow(me->GetOwner(), 3.0f, float(M_PI / 2.0f));

        _events.ScheduleEvent(EVENT_AGATHA_CHECK_PLAYER, 1s);
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        _playerGUID = summoner->GetGUID();
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_AGATHA_BROADCAST:
            {
                if (!_sceneStarted)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_AGATHA_BROADCAST, player);
                }
                break;
            }

            case SPELL_GENERAL_TRIGGER_84114:
                if (!_sceneStarted)
                    SetEventNoEscape();
                break;

            case SPELL_GENERAL_TRIGGER_84107:
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    me->CastSpell(player, SPELL_ARMORE_CAMERA_1, true);
                break;

            case SPELL_ARMORE_CAMERA_4:
                _events.ScheduleEvent(EVENT_FLEE_FROM_FENRIS + 1, 1s);
                break;

            case SPELL_GENERAL_TRIGGER_84079:
                _events.ScheduleEvent(EVENT_FLEE_FROM_FENRIS + 2, 1s);
                break;

            case SPELL_DESPAWN_ALL_SUMMONS_AGATHA:
                DoCastSelf(SPELL_MARK_MASTER_AS_DESUMMONED);
                break;

            case SPELL_MARK_MASTER_AS_DESUMMONED:
                me->DespawnOrUnsummon();
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
        if (!me->GetOwner())
        {
            if (Player* player = me->SelectNearestPlayer(5.0f))
            {
                if (player->HasAura(SPELL_BOND_OF_THE_VALKYR))
                    player->RemoveAura(SPELL_BOND_OF_THE_VALKYR);

                player->CastSpell(player, SPELL_BOND_OF_THE_VALKYR, true);

                me->DespawnOrUnsummon();
            }
        }

        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            if (!player->HasAura(SPELL_SUMMON_AGATHA_FENRIS) || !player->IsInWorld())
                me->DespawnOrUnsummon();
        }

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_AGATHA_CHECK_PLAYER:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        if (player->IsAlive() || player->IsInWorld())
                        {
                            if (!_healCD && player->GetHealthPct() < 75.0f)
                            {
                                me->CastSpell(player, SPELL_UNHOLY_DARKNESS, false);

                                _healCD = true;

                                _events.ScheduleEvent(EVENT_UNHOLY_DARKNESS_COOLDOWN, 8s);
                            }
                        }
                    }
                    _events.Repeat(1s);
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

                case EVENT_UNHOLY_DARKNESS_COOLDOWN:
                    _healCD = false;
                    break;

                case EVENT_FLEE_FROM_FENRIS + 1:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        me->SetFacingTo(3.159046f);

                        Talk(TALK_AGATHA_POST_EVENT1, player);
                    }
                    break;
                }

                case EVENT_FLEE_FROM_FENRIS + 2:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        me->CastSpell(player, SPELL_RIDE_REVERSE_CAST_RIDE_VEHICLE, true);

                        Talk(TALK_AGATHA_POST_EVENT2, player);

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
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        player->ExitVehicle();

                        _sceneStarted = false;

                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveFollow(player, 3.0f, float(M_PI / 2.0f));

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

        DoMeleeAttackIfReady();
    }

    void SetEventNoEscape()
    {
        _sceneStarted = true;

        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

        me->SetReactState(REACT_PASSIVE);

        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MovePoint(POINT_AGATHA_BACK_FRONTYARD, AgathaBackFrontyardPos);

        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
            Talk(TALK_AGATHA_PRE_EVENT, player);
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;
    bool _healCD;
    bool _sceneStarted;
};

enum NotifyAgatha
{
    SPELL_RISE_FORSAKEN_FENRIS                  = 83993
};

// 83990 - Notify Agatha
class spell_silverpine_notify_agatha : public SpellScript
{
    PrepareSpellScript(spell_silverpine_notify_agatha);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RISE_FORSAKEN_FENRIS });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetExplTargetUnit();

        if (caster && target)
        {
            _ownerGUID = target->ToPlayer()->GetGUID();

            if (Creature* agatha = target->FindNearestCreature(NPC_AGATHA_FENRIS, 50.0f, true))
            {
                if (agatha->GetOwner() == target)
                {
                    agatha->CastSpell(caster, SPELL_RISE_FORSAKEN_FENRIS, true);

                    if (Player* player = ObjectAccessor::GetPlayer(*target, _ownerGUID))
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

private:
    ObjectGuid _ownerGUID;
};

/*
 * HACKFIX: The next spell is a masterscript which is cast by the creature once it dies, which uses 8 different spells that summon 8 different npcs (4 male, 4 female).
 * However, according to sniffs, each 4 of them share the same displayIds on their creature_template. This means that, for example, no matter what spell the male npc uses,
 * the summoned npc will have a random displayId, which may or may not match its displayId. I could modify their creature_templates so that each of them
 * has a unique displayId, which would fix the problem, but Funjoker would kill me. Basically, the only way to fix this for now is making a hackfix to ignore the spells,
 * and simply change their displayIds on summon until proper support for disabling displayId probabilities gets implemented into TrinityCore.
 */

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
    PrepareSpellScript(spell_silverpine_forsaken_trooper_masterscript_fenris_isle);

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
            uint32 spellId = SPELL_FORSAKEN_TROOPER_MALE_01_HC;

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

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

enum ForsakenTrooperFenris
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
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

        me->SetReactState(REACT_PASSIVE);

        uint32 displayId = DISPLAY_MALE_01_F;

        switch (summoner->ToCreature()->GetDisplayId())
        {
            case DISPLAY_MALE_01_D_F:
                displayId = DISPLAY_MALE_01_F;
                break;
            case DISPLAY_MALE_02_D_F:
                displayId = DISPLAY_MALE_02_F;
                break;
            case DISPLAY_MALE_03_D_F:
                displayId = DISPLAY_MALE_03_F;
                break;
            case DISPLAY_MALE_04_D_F:
                displayId = DISPLAY_MALE_04_F;
                break;
            case DISPLAY_FEMALE_01_D_F:
                displayId = DISPLAY_FEMALE_01_F;
                break;
            case DISPLAY_FEMALE_02_D_F:
                displayId = DISPLAY_FEMALE_02_F;
                break;
            case DISPLAY_FEMALE_03_D_F:
                displayId = DISPLAY_FEMALE_03_F;
                break;
            case DISPLAY_FEMALE_04_D_F:
                displayId = DISPLAY_FEMALE_04_F;
                break;
            default:
                break;
        }

        me->SetDisplayId(displayId);

        if (roll_chance_i(50))
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

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

// 80515 - Undying Frenzy
class spell_silverpine_undying_frenzy : public AuraScript
{
    PrepareAuraScript(spell_silverpine_undying_frenzy);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        GetCaster()->CastSpell(nullptr, GetSpellInfo()->GetEffect(EFFECT_1).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_silverpine_undying_frenzy::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

enum AtNoEscape
{
    QUEST_NO_ESCAPE                             = 27099,

    NPC_FENRIS_KEEP_STALKER                     = 45032
};

// 6230 - No Escape
class at_silverpine_no_escape : public AreaTriggerScript
{
public:
    at_silverpine_no_escape() : AreaTriggerScript("at_silverpine_no_escape") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        if (player->IsAlive())
        {
            if (player->GetQuestStatus(QUEST_NO_ESCAPE) == QUEST_STATUS_INCOMPLETE)
            {
                if (Creature* agatha = player->FindNearestCreature(NPC_AGATHA_FENRIS, 10.0f, true))
                {
                    if (agatha->GetOwner() == player)
                    {
                        if (Creature* fenrisStalker = player->FindNearestCreature(NPC_FENRIS_KEEP_STALKER, 50.0f, true))
                        {
                            if (fenrisStalker->IsAIEnabled())
                                fenrisStalker->AI()->SetGUID(player->GetGUID());
                        }
                    }
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
    PrepareSpellScript(spell_silverpine_summon_fenris_keep_actors);

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

enum DespawnAllSummonsFenris
{
    NPC_BLOODFANG_FENRIS                        = 44990,
    NPC_CROWLEY_FENRIS                          = 44989,
    NPC_PHIN_ODELIC                             = 44993,
    NPC_BARTOLO_GINSETTI                        = 44994,
    NPC_LOREMASTER_DIBBS                        = 44995,
    NPC_MAGISTRATE_HENRY_MALEB                  = 44996,
    NPC_CARETAKER_SMITHERS                      = 44997,
    NPC_SOPHIA_ZWOSKI                           = 45002,
    NPC_FENRIS_KEEP_CAMERA                      = 45003
};

// 84065 - Despawn All Summons
class spell_silverpine_despawn_all_summons_fenris_keep : public SpellScript
{
    PrepareSpellScript(spell_silverpine_despawn_all_summons_fenris_keep);

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();

        if (target->GetOwner() == GetCaster())
            target->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silverpine_despawn_all_summons_fenris_keep::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

Position const NoEscapeStartPos = { 981.782f, 670.953f, 74.898f, 3.1887f };

enum FenrisKeepStalker
{
    SPELL_FORCE_CAST_FENRIS_CAMERA              = 84113,

    EVENT_RESET_SCENE_FENRIS                    = 1,

    ACTION_START_SCENE_FENRIS                   = 1
};

// 45032 - Fenris Keep Stalker
struct npc_silverpine_fenris_keep_stalker : public ScriptedAI
{
    npc_silverpine_fenris_keep_stalker(Creature* creature) : ScriptedAI(creature) { }

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        if (!_playerGUID.IsEmpty())
            return;

        _playerGUID = guid;

        DoAction(ACTION_START_SCENE_FENRIS);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_GENERAL_TRIGGER_84107:
                _events.RescheduleEvent(EVENT_RESET_SCENE_FENRIS, 30s);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case ACTION_START_SCENE_FENRIS:
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    me->CastSpell(player, SPELL_FORCE_CAST_FENRIS_CAMERA, true);
                    player->NearTeleportTo(NoEscapeStartPos, true);
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
                case EVENT_RESET_SCENE_FENRIS:
                    Reset();
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;
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
        if (Player* player = summoner->ToPlayer())
        {
            _playerGUID = player->GetGUID();

            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                player->EnterVehicle(me, SEAT_FENRIS_CAMERA);
        }

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
        if (apply && seatId == SEAT_FENRIS_CAMERA)
        {
            _events.ScheduleEvent(EVENT_MOVE_TO_START_POINT, 10ms);

            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                me->CastSpell(player, SPELL_SUMMON_FENRIS_ACTORS, true);
        }

        if (apply && seatId == SEAT_FENRIS_CAMERA_FORCE)
            passenger->SetFacingTo(0.0f);

        if (!apply && seatId == SEAT_FENRIS_CAMERA_FORCE)
            _events.ScheduleEvent(EVENT_SCENE_FINISH_FENRIS, 1s);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_CAMERA_FRONTYARD)
            _events.ScheduleEvent(EVENT_CHANGE_TO_SEAT_2, 500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TO_START_POINT:
                    me->GetMotionMaster()->MovePoint(POINT_CAMERA_FRONTYARD, CameraFrontyardPos);
                    break;

                case EVENT_CHANGE_TO_SEAT_2:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        me->CastSpell(player, SPELL_FORCE_SEAT_2, true);
                    _events.ScheduleEvent(EVENT_TRIGGER_84102, 2s);
                    break;

                case EVENT_TRIGGER_84102:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        if (Creature* crowley = player->FindNearestCreature(NPC_CROWLEY_FENRIS, 50.0f))
                            player->CastSpell(player, SPELL_GENERAL_TRIGGER_84102, true);
                    }
                    break;
                }

                case EVENT_SCENE_FINISH_FENRIS:
                    if (Creature* agatha = me->FindNearestCreature(NPC_AGATHA_FENRIS, 60.0f))
                        me->CastSpell(agatha, SPELL_GENERAL_TRIGGER_84079, true);
                    me->SetFacingTo(0.08278348f);
                    _events.ScheduleEvent(EVENT_SCENE_FINISH_FENRIS + 1, 4s);
                    break;

                case EVENT_SCENE_FINISH_FENRIS + 1:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        me->CastSpell(player, SPELL_DESPAWN_ALL_SUMMONS_FENRIS, true);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;
};

enum DariusCrowleyFenris
{
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

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
            _playerGUID = player->GetGUID();

        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

        me->SetReactState(REACT_PASSIVE);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (me->GetEntry() != NPC_CROWLEY_FENRIS)
            return;

        switch (spellInfo->Id)
        {
            case SPELL_GENERAL_TRIGGER_84102:
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    me->CastSpell(player, SPELL_ARMORE_CAMERA_FENRIS, true);

                    Talk(TALK_CROWLEY_NO_ESCAPE_6, player);

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
        _events.Update(diff);

        if (me->GetEntry() != NPC_CROWLEY_FENRIS)
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CROWLEY_ANIMATION_FENRIS:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_CROWLEY_NO_ESCAPE_0, player);
                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS + 1, 4s + 700ms);
                    break;

                case EVENT_CROWLEY_ANIMATION_FENRIS + 1:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_CROWLEY_NO_ESCAPE_1, player);
                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS + 2, 4s + 700ms);
                    break;

                case EVENT_CROWLEY_ANIMATION_FENRIS + 2:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_CROWLEY_NO_ESCAPE_2, player);
                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS + 3, 4s + 700ms);
                    break;

                case EVENT_CROWLEY_ANIMATION_FENRIS + 3:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_CROWLEY_NO_ESCAPE_3, player);
                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS + 4, 4s + 700ms);
                    break;

                case EVENT_CROWLEY_ANIMATION_FENRIS + 4:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_CROWLEY_NO_ESCAPE_4, player);
                    _events.ScheduleEvent(EVENT_CROWLEY_ANIMATION_FENRIS + 5, 6s + 100ms);
                    break;

                case EVENT_CROWLEY_ANIMATION_FENRIS + 5:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_CROWLEY_NO_ESCAPE_5, player);
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
    ObjectGuid _playerGUID;
};

enum GeneralActorFenris
{
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

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
            _playerGUID = player->GetGUID();

        if (Creature* fenrisStalker = me->FindNearestCreature(NPC_FENRIS_KEEP_STALKER, 50.0f, true))
            me->SetFacingToObject(fenrisStalker);

        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

        me->SetReactState(REACT_PASSIVE);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_CONVERSATION_TRIGGER_84076:
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    me->CastSpell(player, SPELL_ARMORE_CAMERA_2, true);
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
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MAGISTRATE_ANIMATION:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_HENRY_NO_ESCAPE_0, player);
                    _events.ScheduleEvent(EVENT_MAGISTRATE_ANIMATION + 1, 10s + 800ms);
                    break;

                case EVENT_MAGISTRATE_ANIMATION + 1:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(TALK_HENRY_NO_ESCAPE_1, player);
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
    ObjectGuid _playerGUID;
    bool _isWorgen;
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
    RegisterCreatureAI(npc_silverpine_sylvanas_windrunner_high_command);
    RegisterCreatureAI(npc_silverpine_deathstalker);
    RegisterCreatureAI(npc_silverpine_worgen_renegade);
    RegisterSpellScript(spell_silverpine_flurry_of_claws);
    RegisterCreatureAI(npc_silverpine_forsaken_trooper);
    RegisterCreatureAI(npc_silverpine_bat_handler_maggotbreath);
    RegisterCreatureAI(npc_silverpine_forsaken_bat);

    /* Fenris Isle */

    RegisterSpellScript(spell_silverpine_bond_of_the_valkyr);
    RegisterCreatureAI(npc_silverpine_agatha_fenris_isle);
    RegisterSpellScript(spell_silverpine_notify_agatha);
    RegisterSpellScript(spell_silverpine_forsaken_trooper_masterscript_fenris_isle);
    RegisterCreatureAI(npc_silverpine_hillsbrad_refugee);
    RegisterCreatureAI(npc_silverpine_forsaken_trooper_fenris_isle);
    RegisterCreatureAI(npc_silverpine_worgen_sentry);
    RegisterSpellScript(spell_silverpine_undying_frenzy);
    new at_silverpine_no_escape();
    RegisterSpellScript(spell_silverpine_summon_fenris_keep_actors);
    RegisterSpellScript(spell_silverpine_despawn_all_summons_fenris_keep);
    RegisterCreatureAI(npc_silverpine_fenris_keep_stalker);
    RegisterCreatureAI(npc_silverpine_fenris_keep_camera);
    RegisterCreatureAI(npc_silverpine_crowley_bloodfang_fenris_keep);
    RegisterCreatureAI(npc_silverpine_generic_actor_fenris_keep);
}
