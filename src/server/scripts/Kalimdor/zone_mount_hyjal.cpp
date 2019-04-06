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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "GameObjectData.h"
#include "GameObject.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"
#include "Spell.h"
#include "Vehicle.h"

enum CommonDefines
{
    // Move Points
    POINT_NONE = 0
};

enum AsHyjalBurns
{
    // Texts
    SAY_BURNT_PLAIN                 = 0,
    SAY_APPROACH_FIRELANDS          = 1,
    SAY_RAGNAROS_SUMMONED           = 2,

    // Events
    EVENT_ARONUS_FLY_TO_PORTAL      = 1,
    EVENT_ARONUS_INTRO_TELEPORT,
    EVENT_ARONUS_FLY_AFTER_TELEPORT,
    EVENT_ARONUS_FLY_OVER_PLAIN,
    EVENT_ARONUS_FLY_TO_FIRELANDS,
    EVENT_ARONUS_SUMMON_RAGNAROS,
    EVENT_ARONUS_FLY_TO_NORDRASSIL,
    EVENT_ARONUS_EJECT_PASSENGERS,

    // Spells
    SPELL_HYJAL_INTRO_PORT          = 73519,
    SPELL_PLAY_HYJAL_INTRO_FLIGHT_A = 94508,
    SPELL_PLAY_HYJAL_INTRO_FLIGHT_B = 94509,
    SPELL_PLAY_HYJAL_INTRO_FLIGHT_C = 94510,
    SPELL_PLAY_HYJAL_INTRO_FLIGHT_D = 94511,
    SPELL_FLAME_BREATH              = 92815,
    SPELL_FORCECAST_SUMMON_RAGNAROS = 74437,
    SPELL_DANS_EJECT_ALL_PASSENGERS = 51254,

    // Creature
    NPC_DEATHWING                   = 39867
};

Position const AronusPath1[] =
{
    { 7791.06f,  -2445.54f,  489.6467f },
    { 7772.387f, -2466.134f, 500.5336f },
    { 7747.4f,   -2509.035f, 500.9175f }
};

Position const AronusPath2[] =
{
    { 4692.0f,   -3190.0f,   1100.0f   },
    { 4631.768f, -3206.595f, 1066.634f },
    { 4608.449f, -3278.08f,  1066.634f }
};

Position const AronusPath3[] =
{
    { 4608.449f, -3278.08f,  1066.634f },
    { 4674.389f, -3213.078f, 1105.225f },
    { 4595.177f, -3160.993f, 1105.225f },
    { 4444.997f, -3120.368f, 1105.225f }
};

Position const AronusPath4[] =
{
    { 4444.997f, -3120.368f, 1105.225f },
    { 4356.268f, -3140.339f, 1079.978f },
    { 4210.395f, -3086.316f, 1075.616f },
    { 4159.675f, -3025.274f, 1042.256f },
    { 4112.436f, -3039.601f, 1015.922f },
    { 4065.911f, -3053.733f, 997.0886f }
};

Position const AronusPath5[] =
{
    { 4065.911f, -3053.733f, 997.0886f },
    { 4212.104f, -3126.182f, 1087.835f },
    { 4482.061f, -3015.623f, 1187.483f },
    { 4882.237f, -3406.547f, 1771.693f },
    { 5114.466f, -3483.545f, 1755.137f },
    { 5211.074f, -3609.153f, 1755.137f },
    { 5512.352f, -3793.356f, 1689.859f },
    { 5546.801f, -3691.3f,   1626.61f  },
    { 5536.043f, -3629.82f,  1570.572f }
};

Position const AronusPath6[] =
{
    { 5536.043f, -3629.82f,  1570.572f },
    { 5534.813f, -3629.128f, 1611.423f },
    { 5520.546f, -3606.208f, 1634.757f }
};

struct npc_mh_aronus : public PassiveAI
{
    npc_mh_aronus(Creature* creature) : PassiveAI(creature) { }

    void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
            return;

        _events.ScheduleEvent(EVENT_ARONUS_FLY_TO_PORTAL, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ARONUS_FLY_TO_PORTAL:
                    // Preload grid to avoid waypoint issues after teleport
                    me->GetMap()->LoadGrid(AronusPath2[0].GetPositionX(), AronusPath2[0].GetPositionY());

                    DoCastSelf(SPELL_PLAY_HYJAL_INTRO_FLIGHT_A);
                    _events.ScheduleEvent(EVENT_ARONUS_INTRO_TELEPORT, MoveByPathAndGetTravelTime(AronusPath1, 3, 7.0f));
                    break;
                case EVENT_ARONUS_INTRO_TELEPORT:
                    DoCastSelf(SPELL_HYJAL_INTRO_PORT);
                    _events.ScheduleEvent(EVENT_ARONUS_FLY_AFTER_TELEPORT, 1s + 500ms);
                    break;
                case EVENT_ARONUS_FLY_AFTER_TELEPORT:
                    _events.ScheduleEvent(EVENT_ARONUS_FLY_OVER_PLAIN, MoveByPathAndGetTravelTime(AronusPath2, 3, 14.0f));
                    break;
                case EVENT_ARONUS_FLY_OVER_PLAIN:
                    Talk(SAY_BURNT_PLAIN);
                    DoCastSelf(SPELL_PLAY_HYJAL_INTRO_FLIGHT_B);
                    _events.ScheduleEvent(EVENT_ARONUS_FLY_TO_FIRELANDS, MoveByPathAndGetTravelTime(AronusPath3, 4, 14.0f));
                    break;
                case EVENT_ARONUS_FLY_TO_FIRELANDS:
                    Talk(SAY_APPROACH_FIRELANDS);
                    DoCastSelf(SPELL_PLAY_HYJAL_INTRO_FLIGHT_C);
                    _events.ScheduleEvent(EVENT_ARONUS_SUMMON_RAGNAROS, MoveByPathAndGetTravelTime(AronusPath4, 6, 21.0f));
                    break;
                case EVENT_ARONUS_SUMMON_RAGNAROS:
                    if (Creature* deathwing = me->FindNearestCreature(NPC_DEATHWING, 200.0f, true))
                        deathwing->CastSpell(deathwing, SPELL_FLAME_BREATH);

                    DoCastSelf(SPELL_FORCECAST_SUMMON_RAGNAROS);
                    _events.ScheduleEvent(EVENT_ARONUS_FLY_TO_NORDRASSIL, 7s);
                    break;
                case EVENT_ARONUS_FLY_TO_NORDRASSIL:
                    Talk(SAY_RAGNAROS_SUMMONED);
                    _events.ScheduleEvent(EVENT_ARONUS_EJECT_PASSENGERS, MoveByPathAndGetTravelTime(AronusPath5, 9, 42.0f));
                    break;
                case EVENT_ARONUS_EJECT_PASSENGERS:
                    DoCastSelf(SPELL_PLAY_HYJAL_INTRO_FLIGHT_D);
                    DoCastSelf(SPELL_DANS_EJECT_ALL_PASSENGERS, true);
                    me->DespawnOrUnsummon(MoveByPathAndGetTravelTime(AronusPath6, 3, 21.0f));
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;

    int32 MoveByPathAndGetTravelTime(Position const* pathPoints, size_t pathSize, float velocity)
    {
        Movement::MoveSplineInit init(me);
        Movement::PointsArray path;
        path.reserve(pathSize);
        std::transform(pathPoints, pathPoints + pathSize, std::back_inserter(path), [](Position const& point)
        {
            return G3D::Vector3(point.GetPositionX(), point.GetPositionY(), point.GetPositionZ());
        });

        init.SetFly();
        init.SetUncompressed();
        init.MovebyPath(path);
        init.SetSmooth();
        init.SetWalk(false);
        init.SetVelocity(velocity);
        return init.Launch();
    }
};

enum IncitingTheElements
{
    // Texts
    SAY_FEED_BERRIES                    = 0,
    SAY_FIGHT_INFILTRATOR               = 1,
    SAY_INFILTRATOR_SPOTTED             = 0,

    // Events
    EVENT_FIND_INFILTRATOR              = 1,
    EVENT_SUMMON_INFILTRATOR,
    EVENT_INFILTRATOR_ATTACK,
    EVENT_INFILTRATOR_TALK_SPOTTED,
    EVENT_INFILTRATOR_SHADOWSTEP,
    EVENT_INFILTRATOR_BACKSTAB,

    // Move Points
    POINT_SUMMON_INFILTRATOR            = 1,

    // Spells
    SPELL_FEED_BERRIES                  = 74513,
    SPELL_FORCECAST_SPOT_INFILTRATOR    = 74515,
    SPELL_STEALTH                       = 30991,
    SPELL_SHADOWSTEP                    = 80576,
    SPELL_BACKSTAB                      = 37685
};

struct npc_mh_faerie_dragon : public ScriptedAI
{
    npc_mh_faerie_dragon(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _eventInProgress = false;
        me->GetMotionMaster()->MoveRandom(7.0f);
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (!caster)
            return;

        if (spell->Id == SPELL_FEED_BERRIES && !_eventInProgress)
        {
            me->GetMotionMaster()->InitDefault();
            me->StopMoving();
            Talk(SAY_FEED_BERRIES, caster);
            _events.ScheduleEvent(EVENT_FIND_INFILTRATOR, 2s + 500ms);
            _actorGUID = caster->GetGUID();
            _eventInProgress = true;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FIND_INFILTRATOR:
                {
                    Position pos = me->GetPosition();
                    me->SetWalk(true);
                    me->MovePosition(pos, 30.0f, frand(0.0f, float(M_PI * 2)));
                    me->GetMotionMaster()->MovePoint(POINT_SUMMON_INFILTRATOR, pos);
                    break;
                }
                default:
                    break;
            }
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        if (id == POINT_SUMMON_INFILTRATOR)
        {
            if (Player* player = ObjectAccessor::FindPlayer(_actorGUID))
            {
                Talk(SAY_FIGHT_INFILTRATOR, player);
                DoCast(player, SPELL_FORCECAST_SPOT_INFILTRATOR);
            }
            me->DespawnOrUnsummon(3s);
        }
    }
private:
    EventMap _events;
    ObjectGuid _actorGUID;
    bool _eventInProgress;
};

struct npc_mh_twilight_inciter : public ScriptedAI
{
    npc_mh_twilight_inciter(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _spotted = false;
        me->SetReactState(REACT_PASSIVE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_INFILTRATOR_SHADOWSTEP, 25s);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        DoCastSelf(SPELL_STEALTH);
        me->SetFacingToObject(summoner);
        _events.ScheduleEvent(EVENT_INFILTRATOR_TALK_SPOTTED, 1s + 500ms);
        _events.ScheduleEvent(EVENT_INFILTRATOR_ATTACK, 5s + 500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && _spotted)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INFILTRATOR_ATTACK:
                    _spotted = true;
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    if (TempSummon* summon = me->ToTempSummon())
                        if (Unit* target = summon->GetSummoner())
                            AttackStart(target);
                    break;
                case EVENT_INFILTRATOR_TALK_SPOTTED:
                    if (TempSummon* summon = me->ToTempSummon())
                        if (Unit* target = summon->GetSummoner())
                            Talk(SAY_INFILTRATOR_SPOTTED, target);
                    break;
                case EVENT_INFILTRATOR_SHADOWSTEP:
                    DoCastVictim(SPELL_SHADOWSTEP);
                    _events.ScheduleEvent(EVENT_INFILTRATOR_BACKSTAB, 1s);
                    _events.Repeat(30s);
                    break;
                case EVENT_INFILTRATOR_BACKSTAB:
                    DoCastVictim(SPELL_BACKSTAB);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
    bool _spotted;
};

enum FlamesFromAbove
{
    // Events
    EVENT_SUMMON_EMERALD_FLAMES             = 1,

    // Spells
    SPELL_EMERALD_FRAMEWEAVER_DRAKE_BREATH  = 76205,

    // Gameobjects
    GO_EMERALD_FLAME                        = 203065
};

Position const EmeraldFlameweaverSummonPos = { 5725.01f, -3305.924f, 1625.791f, 6.019073f };

Position const EmeraldFlameweaverPath1[] =
{
    { 5708.011f, -3301.326f, 1620.673f },
    { 5725.01f,  -3305.924f, 1625.791f },
    { 5742.01f,  -3310.521f, 1630.909f },
    { 5753.374f, -3295.726f, 1614.876f },
    { 5753.374f, -3295.726f, 1614.876f }
};

Position const EmeraldFlameweaverPath2[] =
{
    { 5753.374f, -3295.726f, 1614.876f },
    { 5761.196f, -3287.415f, 1611.663f },
    { 5766.298f, -3290.731f, 1616.272f },
    { 5768.874f, -3298.884f, 1620.067f },
    { 5772.097f, -3310.894f, 1623.15f  },
    { 5758.483f, -3328.623f, 1639.484f }
};

Position const EmeraldFlamesPositions[] =
{
    { 5767.491f, -3286.856f, 1604.598f },
    { 5772.15f,  -3282.38f,  1604.77f  },
    { 5785.219f, -3292.889f, 1605.573f },
    { 5779.661f, -3303.783f, 1604.636f },
    { 5751.01f,  -3293.18f,  1604.63f  },
    { 5772.796f, -3307.984f, 1604.598f },
    { 5762.307f, -3285.71f,  1607.487f },
    { 5781.79f,  -3303.74f,  1607.733f },
    { 5772.169f, -3288.177f, 1610.019f },
    { 5759.41f,  -3285.17f,  1604.83f  },
    { 5763.712f, -3281.502f, 1605.107f }
};

QuaternionData const emeraldFlameRotation = QuaternionData();

struct npc_mh_emerald_flameweaver : public PassiveAI
{
    npc_mh_emerald_flameweaver(Creature* creature) : PassiveAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        me->GetMotionMaster()->MoveSmoothPath(POINT_NONE, EmeraldFlameweaverPath1, 5, false, true);
        _events.ScheduleEvent(EVENT_SUMMON_EMERALD_FLAMES, 5s + 500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SUMMON_EMERALD_FLAMES:
                    for (uint8 i = 0; i < 10; i++)
                        if (GameObject* flame = me->SummonGameObject(GO_EMERALD_FLAME, EmeraldFlamesPositions[i], emeraldFlameRotation, 0, GO_SUMMON_TIMED_DESPAWN))
                            flame->DespawnOrUnsummon(20s);

                    DoCastAOE(SPELL_EMERALD_FRAMEWEAVER_DRAKE_BREATH);

                    if (TempSummon* summon = me->ToTempSummon())
                        if (Unit* target = summon->GetSummoner())
                            if (Player* player = target->ToPlayer())
                                player->KilledMonsterCredit(me->GetEntry());

                    me->GetMotionMaster()->MoveSmoothPath(POINT_NONE, EmeraldFlameweaverPath2, 6, false, true);
                    me->DespawnOrUnsummon(9s);
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


enum RagingFirestorm
{
    NPC_GROVE_WARDEN    = 39941,
    NPC_LAINA_NIGHTSKY  = 39927,
    SPELL_SUMMON_TREES  = 74565,
    SPELL_GOUT_OF_FLAME = 80549,

    EVENT_GOUT_OF_FLAME = 1
};

Position const GroveWardenSummonPositions[] =
{
    { 5041.51f, -1730.29f, 1323.29f, 1.6057f },
    { 5031.45f, -1734.11f, 1322.15f, 1.6057f },
    { 5033.78f, -1732.86f, 1322.35f, 1.6057f },
    { 5034.65f, -1729.32f, 1322.3f,  1.6057f },
    { 5042.12f, -1734.71f, 1323.35f, 1.6057f },
    { 5033.48f, -1737.55f, 1322.51f, 1.6057f }
};

Position const GroveWardenWaypointPosition1 = { 5026.774f, -1657.001f, 1326.92f };
Position const GroveWardenWaypointPosition2 = { 5028.423f, -1645.738f, 1327.722f };

struct npc_mh_raging_firestorm : public ScriptedAI
{
    npc_mh_raging_firestorm(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _allowWardenCombat = me->GetExactDist2d(GroveWardenWaypointPosition1) < 140.0f;
    }

    void AttackStart(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_UNIT && victim->GetEntry() == NPC_GROVE_WARDEN && victim->GetExactDist2d(me) > me->GetCombatReach())
            return;

        ScriptedAI::AttackStart(victim);
    }

    void Reset() override
    {
        _events.Reset();
        if (_allowWardenCombat)
            SummonGroveWarden();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_GOUT_OF_FLAME, 8s, 10s);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GOUT_OF_FLAME:
                    DoCastVictim(SPELL_GOUT_OF_FLAME);
                    _events.Repeat(21s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
    bool _allowWardenCombat;

    void SummonGroveWarden()
    {
        uint8 spawnIndex = urand(0, 5);
        if (Creature* warden = DoSummon(NPC_GROVE_WARDEN, GroveWardenSummonPositions[spawnIndex], 20000))
        {
            warden->SetDisplayId(warden->GetCreatureTemplate()->Modelid1);
            Position waypointPos = GroveWardenWaypointPosition1;
            Position homePos = me->GetHomePosition();
            if (me->GetExactDist2d(GroveWardenWaypointPosition1) < me->GetExactDist2d(GroveWardenWaypointPosition2))
                waypointPos = GroveWardenWaypointPosition2;

            if (Creature* laina = warden->FindNearestCreature(NPC_LAINA_NIGHTSKY, 20.0f, true))
                warden->CastSpell(laina, SPELL_SUMMON_TREES);

            warden->m_Events.AddEventAtOffset([warden, waypointPos, homePos]()
            {
                Movement::MoveSplineInit init(warden);
                init.MoveTo(waypointPos.GetPositionX(), waypointPos.GetPositionY(), waypointPos.GetPositionZ());
                if (int32 travelTime = init.Launch())
                    warden->m_Events.AddEventAtOffset([warden, homePos]()
                {
                    warden->GetMotionMaster()->MovePoint(POINT_NONE, homePos);
                }, Milliseconds(travelTime));
            }, 2s + 500ms);
        }
    }
};

class spell_mh_summon_emerald_flameweaver : public SpellScript
{
    PrepareSpellScript(spell_mh_summon_emerald_flameweaver);

    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(EmeraldFlameweaverSummonPos);
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_mh_summon_emerald_flameweaver::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

Position const RagnarosSummonPos = { 4039.558f, -3061.701f, 972.6672f, 0.104719f };

class spell_mh_ragnaros : public SpellScript
{
    PrepareSpellScript(spell_mh_ragnaros);

    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(RagnarosSummonPos);
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_mh_ragnaros::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

class spell_mh_flamebreaker : public AuraScript
{
    PrepareAuraScript(spell_mh_flamebreaker);

    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        Unit* caster = GetTarget();
        if (Unit* target = ObjectAccessor::GetCreature(*caster, caster->GetChannelObjectGuid()))
            caster->CastSpell(target, GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mh_flamebreaker::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_mount_hyjal()
{
    RegisterCreatureAI(npc_mh_aronus);
    RegisterCreatureAI(npc_mh_faerie_dragon);
    RegisterCreatureAI(npc_mh_twilight_inciter);
    RegisterCreatureAI(npc_mh_emerald_flameweaver);
    RegisterCreatureAI(npc_mh_raging_firestorm);
    RegisterSpellScript(spell_mh_summon_emerald_flameweaver);
    RegisterSpellScript(spell_mh_ragnaros);
    RegisterAuraScript(spell_mh_flamebreaker);
}
