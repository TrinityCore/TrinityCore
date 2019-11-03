#include "ScriptMgr.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "Weather.h"
#include "GameObject.h"

#define PLAYER_TELEPORT_PATH_SIZE   15
#define JAINA_PATH_01_SIZE          13
#define JAINA_PATH_02_SIZE          14
#define KLANNOC_PATH_01_SIZE         5
#define SPECTATORS_MAX_NUMBER        8
#define FIRES_MAX_NUMBER            12

enum Events
{
    // Events
    START_AFFRAY_ISLE           = 1,

    // Affray Isle
    EVENT_AFFRAY_ISLE_1,
    EVENT_AFFRAY_ISLE_2,
    EVENT_AFFRAY_ISLE_3,
    EVENT_AFFRAY_ISLE_4,
    EVENT_AFFRAY_ISLE_5,
    EVENT_AFFRAY_ISLE_6,
    EVENT_AFFRAY_ISLE_7,
    EVENT_AFFRAY_ISLE_8,
    EVENT_AFFRAY_ISLE_9,
    EVENT_AFFRAY_ISLE_10,
    EVENT_AFFRAY_ISLE_11,
    EVENT_AFFRAY_ISLE_12,
    EVENT_AFFRAY_ISLE_13,
    EVENT_AFFRAY_ISLE_14,
    EVENT_AFFRAY_ISLE_15,
    EVENT_AFFRAY_ISLE_16,
    EVENT_AFFRAY_ISLE_17,
    EVENT_AFFRAY_ISLE_18,
    EVENT_AFFRAY_ISLE_19,
    EVENT_AFFRAY_ISLE_20,
};

enum Talks
{
    TALK_SPECTATOR_FLEE         = 0,

    TALK_JAINA_01               = 0,
    TALK_JAINA_02               = 1,
    TALK_KLANNOC_03             = 0,
    TALK_JAINA_04               = 2,
    TALK_JAINA_05               = 3,
    TALK_JAINA_06               = 4,
};

enum Misc
{
    // Map ID
    MAPID_KALIMDOR              = 1,

    // Phasemask
    PHASEMASK_AFFRAY            = 16,

    // NPCs
    NPC_JAINA_PROUDMOORE        = 100066,
    NPC_KALECGOS                = 100001,
    NPC_THRALL                  = 100068,
    NPC_PURPLE_GRYPHON          = 18362,
    NPC_KLANNOC_MACLEOD         = 100067,
    NPC_AFFRAY_SPECTATOR        = 100068,
    NPC_INVISIBLE_STALKER       = 32780,

    // Morph
    MORPH_INVISIBLE_PLAYER      = 15880,

    // Game objects
    GOB_FIRE                    = 182592,
    GOB_FOCUSING_IRIS           = 500017,
    GOB_ANTONIDAS_BOOK          = 500018,
};

enum Spells
{
    SPELL_ARCANE_BARRAGE        = 100009,
    SPELL_WAVE_VISUAL           = 100060,
    SPELL_TELEPORT_PATH         = 100061,
    SPELL_SIMPLE_TELEPORT       = 100032,
    SPELL_VISUAL_TELEPORT       = 51347,
    SPELL_SMOKE_REVEAL          = 10389,
    SPELL_PYROBLAST             = 100005,
    SPELL_IMMOLATE              = 48150,
    SPELL_ICE_NOVA              = 56935,
    SPELL_ARCANE_CANALISATION   = 54219,
    SPELL_CANALISATION          = 58012,
    SPELL_ARCANE_CLOUD          = 39952
};

const Position FocusingIrisPos      = { -1643.60f, -4244.23f, 10.42f, 6.25f };
const Position FocusingIrisFxPos    = { -1644.40f, -4244.29f,  8.48f, 6.25f };

const Position PlayerTeleportPath[PLAYER_TELEPORT_PATH_SIZE] =
{
    { -1634.20f, -3967.94f,  0.41f, 4.66f },
    { -1624.72f, -4020.75f,  4.56f, 4.90f },
    { -1617.92f, -4046.26f,  5.97f, 4.94f },
    { -1608.27f, -4087.12f,  6.96f, 4.94f },
    { -1600.31f, -4131.10f,  7.71f, 4.72f },
    { -1602.98f, -4182.66f,  8.36f, 4.50f },
    { -1611.30f, -4244.69f, 12.43f, 4.81f },
    { -1602.44f, -4285.64f, 13.83f, 5.02f },
    { -1582.44f, -4355.22f, 13.10f, 4.81f },
    { -1590.16f, -4410.66f, 12.66f, 3.97f },
    { -1628.92f, -4422.50f, 13.46f, 2.97f },
    { -1648.09f, -4423.28f, 10.99f, 3.20f },
    { -1710.89f, -4422.42f,  6.85f, 2.79f },
    { -1719.90f, -4408.28f,  3.39f, 1.20f },
    { -1710.83f, -4390.23f,  4.37f, 1.28f }
};

const Position JainaPath01[JAINA_PATH_01_SIZE] =
{
    { -1710.29f, -4377.18f, 4.55f, 5.02f },
    { -1710.29f, -4377.18f, 4.55f, 5.01f },
    { -1708.13f, -4382.60f, 4.60f, 5.44f },
    { -1704.00f, -4383.90f, 4.69f, 0.24f },
    { -1699.90f, -4381.63f, 4.91f, 0.79f },
    { -1697.59f, -4378.65f, 4.90f, 1.00f },
    { -1693.75f, -4372.47f, 4.88f, 0.93f },
    { -1691.10f, -4369.22f, 4.90f, 0.84f },
    { -1686.12f, -4364.10f, 4.95f, 0.87f },
    { -1681.42f, -4357.16f, 5.02f, 1.06f },
    { -1679.39f, -4353.49f, 4.90f, 1.09f },
    { -1676.57f, -4346.48f, 4.23f, 1.22f },
    { -1674.08f, -4341.96f, 3.67f, 0.91f }
};

const Position JainaPath02[JAINA_PATH_02_SIZE] =
{
    { -1674.14f, -4342.04f, 3.67f, 0.34f },
    { -1666.01f, -4337.26f, 3.80f, 1.00f },
    { -1664.60f, -4330.80f, 3.63f, 1.64f },
    { -1665.77f, -4324.19f, 3.43f, 1.84f },
    { -1670.08f, -4313.56f, 3.68f, 1.98f },
    { -1673.96f, -4306.12f, 3.75f, 2.13f },
    { -1677.87f, -4299.82f, 3.61f, 2.03f },
    { -1680.33f, -4291.97f, 3.30f, 1.72f },
    { -1680.23f, -4283.77f, 2.88f, 1.31f },
    { -1675.98f, -4275.16f, 2.74f, 0.89f },
    { -1670.29f, -4269.01f, 2.90f, 0.75f },
    { -1667.21f, -4266.14f, 2.99f, 0.75f },
    { -1660.96f, -4257.84f, 3.08f, 1.15f },
    { -1658.20f, -4249.91f, 2.01f, 1.30f }
};

const Position KlannocPath01[KLANNOC_PATH_01_SIZE] =
{
    { -1642.59f, -4347.65f, 6.50f, 2.42f },
    { -1644.83f, -4345.66f, 6.52f, 2.41f },
    { -1648.16f, -4342.63f, 4.88f, 2.40f },
    { -1652.18f, -4339.98f, 4.88f, 2.73f },
    { -1657.90f, -4338.15f, 4.45f, 2.85f }
};

const Position BuildingMeteorPos[FIRES_MAX_NUMBER] =
{
    { -1666.98f, -4368.48f, 15.09f, 0.09f },
    { -1654.66f, -4356.94f, 15.66f, 2.67f },
    { -1649.54f, -4363.14f, 18.56f, 5.10f },
    { -1645.32f, -4342.68f,  4.88f, 4.94f },
    { -1646.60f, -4353.18f, 16.78f, 0.91f },
    { -1656.34f, -4372.14f, 18.35f, 6.24f },
    { -1653.69f, -4363.88f, 17.80f, 0.02f },
    { -1632.16f, -4348.17f, 17.78f, 4.12f },
    { -1638.41f, -4354.31f, 28.32f, 4.35f },
    { -1642.21f, -4360.63f, 28.96f, 4.21f },
    { -1661.48f, -4360.98f,  4.88f, 5.34f },
    { -1667.19f, -4367.37f,  4.88f, 5.63f }
};

class PurpleGryphonFlyAway : public BasicEvent
{
    public:
        PurpleGryphonFlyAway(Creature* owner) : owner(owner), stage(0)
        {
            posToLift = owner->GetPosition();
            posToLift.m_positionZ += 20.f;
        }

        bool Execute(uint64 eventTime, uint32 /*updateTime*/) override
        {
            switch (stage)
            {
                case 0:
                    owner->GetMotionMaster()->MoveTakeoff(0, posToLift);
                    return NextEvent(eventTime, 3000);
                case 1:
                    owner->GetMotionMaster()->MovePoint(0, -1528.06f, -3962.72f, 44.08f, false, 0.f);
                    return true;
                default:
                    break;
            }
            return true;
        }

    private:
        Creature* owner;
        uint8 stage;
        Position posToLift;

        bool NextEvent(uint64 eventTime, uint64 time)
        {
            stage++;
            owner->m_Events.AddEvent(this, eventTime + time);
            return false;
        }
};

class KlannocBurning : public BasicEvent
{
    public:
        KlannocBurning(Creature* owner, Creature* jaina) : owner(owner), jaina(jaina), stage(0) { }

        bool Execute(uint64 eventTime, uint32 /*updateTime*/) override
        {
            switch (stage)
            {
                case 0:
                    owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    return NextEvent(eventTime, 500);
                case 1:
                    jaina->CastSpell(owner, SPELL_PYROBLAST);
                    return NextEvent(eventTime, 1000);
                case 2:
                    owner->RemoveAllAuras();
                    owner->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    owner->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                    owner->AddAura(SPELL_IMMOLATE, owner);
                    owner->GetMotionMaster()->MoveConfused();
                    return NextEvent(eventTime, 6000);
                case 3:
                    owner->KillSelf();
                    return true;
                default:
                    break;
            }
            return true;
        }

    private:
        Creature* owner;
        Creature* jaina;
        uint8 stage;
        Position posToLift;

        bool NextEvent(uint64 eventTime, uint64 time)
        {
            stage++;
            owner->m_Events.AddEvent(this, eventTime + time);
            return false;
        }
};

class SpectatorDeath : public BasicEvent
{
    public:
        SpectatorDeath(Creature* owner) : owner(owner) { }

        bool Execute(uint64 eventTime, uint32 /*updateTime*/) override
        {
            owner->KillSelf();
            return true;
        }

    private:
        Creature* owner;
};

class jaina_affray_isle : public CreatureScript
{
    public:
    jaina_affray_isle() : CreatureScript("jaina_affray_isle") {}

    struct jaina_affray_isleAI : public ScriptedAI
    {
        jaina_affray_isleAI(Creature* creature) : ScriptedAI(creature), debug(false)
        {
            Initialize();
        }

        void Initialize()
        {
            player = nullptr;
        }

        void SetData(uint32 id, uint32 value) override
        {
            switch (id)
            {
                case START_AFFRAY_ISLE:
                {
                    player = me->SelectNearestPlayer(25.f);

                    me->GetMap()->SetZoneWeather(17, WEATHER_STATE_FOG, 1.f);

                    debug = value == 2 ? true : false;
                    if (debug)
                    {
                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_3, 2s);
                    }
                    else
                    {
                        gryphon = GetClosestCreatureWithEntry(me, NPC_PURPLE_GRYPHON, 25.f);
                        me->SetFacingToObject(gryphon);
                        gryphon->m_Events.AddEvent(new PurpleGryphonFlyAway(gryphon), gryphon->m_Events.CalculateTime(3000));

                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_1, 3s);
                    }

                    break;
                }

                default:
                    break;
            }
        }

        void Reset() override
        {
            events.Reset();
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_AFFRAY_ISLE_1:
                        me->SetFacingTo(4.57f);
                        me->AI()->Talk(TALK_JAINA_01);
                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_2, 3s);
                        break;

                    case EVENT_AFFRAY_ISLE_2:
                        DoCast(SPELL_SIMPLE_TELEPORT);
                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_3, 1s);
                        break;

                    case EVENT_AFFRAY_ISLE_3:
                        me->NearTeleportTo(-1710.29f, -4377.18f, 4.56f, 4.83f);
                        me->SetVisible(false);
                        if (!debug)
                        {
                            SetPlayerTeleportMode(player, true);
                            player->GetMotionMaster()->MoveSmoothPath(0, PlayerTeleportPath, PLAYER_TELEPORT_PATH_SIZE, false);
                            events.ScheduleEvent(EVENT_AFFRAY_ISLE_4, 11s);
                        }
                        else
                        {
                            player->NearTeleportTo(PlayerTeleportPath[PLAYER_TELEPORT_PATH_SIZE - 1]);
                            events.ScheduleEvent(EVENT_AFFRAY_ISLE_4, 2s);
                        }
                        break;

                    case EVENT_AFFRAY_ISLE_4:
                        if (!debug)
                        {
                            SetPlayerTeleportMode(player, false);
                            player->GetMotionMaster()->Clear();
                        }
                        me->SetVisible(true);
                        DoCast(SPELL_VISUAL_TELEPORT);
                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_5, 2s);
                        break;

                    case EVENT_AFFRAY_ISLE_5:
                        me->AI()->Talk(TALK_JAINA_02);
                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_6, 3s);
                        break;

                    case EVENT_AFFRAY_ISLE_6:
                        me->GetMotionMaster()->MoveSmoothPath(0, JainaPath01, JAINA_PATH_01_SIZE, false);
                        if (!debug)
                            events.ScheduleEvent(EVENT_AFFRAY_ISLE_7, 9s);
                        else
                            events.ScheduleEvent(EVENT_AFFRAY_ISLE_13, 9s);
                        break;

                    case EVENT_AFFRAY_ISLE_7:
                    {
                        if (klannoc = me->SummonCreature(NPC_KLANNOC_MACLEOD, KlannocPath01[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10min))
                        {
                            me->SetFacingTo(0.32f);

                            klannoc->GetMotionMaster()->MoveSmoothPath(0, KlannocPath01, KLANNOC_PATH_01_SIZE, true);
                            klannoc->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            klannoc->SetReactState(REACT_PASSIVE);
                            klannoc->SetFaction(14);
                        }

                        float angle = 45.f;
                        for (uint8 i = 0; i < SPECTATORS_MAX_NUMBER; i++)
                        {
                            Position pos = GetPositionAroundMe(angle, 6.5f);
                            if (Creature* spectator = me->SummonCreature(NPC_AFFRAY_SPECTATOR, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10min))
                            {
                                spectator->UpdateGroundPositionZ(pos.GetPositionX(), pos.GetPositionY(), pos.m_positionZ);
                                spectator->NearTeleportTo(pos);

                                spectator->SetFacingToObject(me);
                                spectator->CastSpell(spectator, SPELL_SMOKE_REVEAL);
                                spectator->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                spectator->SetReactState(REACT_PASSIVE);
                                spectator->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY_UNARMED);
                                spectator->SetFaction(14);

                                spectators.push_back(spectator);
                            }

                            angle += 45.f;
                        }

                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_8, 8s);
                        break;
                    }

                    case EVENT_AFFRAY_ISLE_8:
                        me->SetFacingToObject(klannoc);
                        klannoc->SetFacingToObject(me);
                        klannoc->AI()->Talk(TALK_KLANNOC_03);
                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_9, 3s);
                        break;

                    case EVENT_AFFRAY_ISLE_9:
                        me->AI()->Talk(TALK_JAINA_04);
                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_10, 3s);
                        break;

                    case EVENT_AFFRAY_ISLE_10:
                        klannoc->m_Events.AddEvent(new KlannocBurning(klannoc, me), klannoc->m_Events.CalculateTime(100));
                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_11, 2s);
                        break;

                    case EVENT_AFFRAY_ISLE_11:
                    {
                        for (Creature* spectator : spectators)
                        {
                            if (roll_chance_i(30))
                                spectator->AI()->Talk(TALK_SPECTATOR_FLEE);

                            spectator->GetMotionMaster()->MoveFleeing(me);
                            spectator->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                        }

                        uint8 randomSpectator = urand(0, SPECTATORS_MAX_NUMBER - 1);
                        if (Creature* victim = spectators[randomSpectator])
                        {
                            victim->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                            CastSpellExtraArgs args;
                            args.SetTriggerFlags(TRIGGERED_CAST_DIRECTLY);

                            DoCast(victim, SPELL_ARCANE_BARRAGE, args);
                        }

                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_12, 5s);
                        break;
                    }

                    case EVENT_AFFRAY_ISLE_12:
                    {
                        me->AI()->Talk(TALK_JAINA_05);
                        for (Creature* spectator : spectators)
                        {
                            spectator->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            spectator->m_Events.AddEvent(new SpectatorDeath(spectator), spectator->m_Events.CalculateTime(2000));
                        }

                        CastSpellExtraArgs args;
                        args.SetTriggerFlags(TRIGGERED_CAST_DIRECTLY);

                        DoCastAOE(SPELL_ICE_NOVA, args);

                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_13, 2s);
                        break;
                    }

                    case EVENT_AFFRAY_ISLE_13:
                        me->AI()->Talk(TALK_JAINA_06);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveSmoothPath(0, JainaPath02, JAINA_PATH_02_SIZE, false);
                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_14, 13s);
                        break;

                    case EVENT_AFFRAY_ISLE_14:
                        me->GetMotionMaster()->MovePoint(0, -1655.44f, -4246.56f, 1.77f, true, 6.13f);
                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_15, 3s);
                        break;

                    case EVENT_AFFRAY_ISLE_15:
                    {
                        me->SummonGameObject(GOB_ANTONIDAS_BOOK, -1651.47f, -4241.25f, 3.02f, 3.82f, QuaternionData(0.f, 0.f, -0.9200f, 0.3917f), 0);

                        //arcaneCloud = me->SummonCreature(NPC_INVISIBLE_STALKER, -1652.58f, -4242.50f, 87.16f, 0.04f, TEMPSUMMON_MANUAL_DESPAWN);
                        //arcaneCloud->AddAura(SPELL_ARCANE_CLOUD, arcaneCloud);
                        //arcaneCloud->SetObjectScale(5.f);

                        me->SummonGameObject(GOB_FOCUSING_IRIS, -1649.19f, -4247.15f, 3.32f, 3.09f, QuaternionData(), 0);
                        iris = me->SummonCreature(NPC_INVISIBLE_STALKER, FocusingIrisFxPos, TEMPSUMMON_MANUAL_DESPAWN);

                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_16, 3s);
                        break;
                    }

                    case EVENT_AFFRAY_ISLE_16:
                        DoCast(SPELL_ARCANE_CANALISATION);
                        wave = me->SummonCreature(NPC_INVISIBLE_STALKER, -1579.89f, -4245.80f, -2.19f, 6.20f, TEMPSUMMON_MANUAL_DESPAWN);
                        events.ScheduleEvent(EVENT_AFFRAY_ISLE_17, 4s);
                        break;

                    case EVENT_AFFRAY_ISLE_17:
                        iris->CastSpell(wave, SPELL_CANALISATION);
                        wave->AddAura(SPELL_WAVE_VISUAL, wave);
                        break;

                    default:
                        break;
                }
            }
        }

        private:
            EventMap events;
            Player* player;
            Creature* klannoc;
            Creature* kalecgos;
            Creature* thrall;
            Creature* gryphon;
            Creature* arcaneCloud;
            Creature* iris;
            Creature* wave;
            std::vector<Creature*> spectators;

            bool debug;

            void SetPlayerTeleportMode(Player* player, bool value)
            {
                player->SetControlled(value, UNIT_STATE_CONTROLLED);

                float speed = value ? 20.f : 1.f;
                player->SetSpeedRate(MOVE_WALK, speed);
                player->SetSpeedRate(MOVE_RUN, speed);
                player->SetSpeedRate(MOVE_SWIM, speed);
                player->SetSpeedRate(MOVE_FLIGHT, speed);

                if (value)
                {
                    player->SetDisplayId(MORPH_INVISIBLE_PLAYER);
                    player->AddAura(SPELL_TELEPORT_PATH, player);
                }
                else
                {
                    player->SetDisplayId(player->GetNativeDisplayId());
                    player->RemoveAurasDueToSpell(SPELL_TELEPORT_PATH);
                }

                SetPlayerCanFly(player, value);
            }

            void SetPlayerCanFly(Player* player, bool value)
            {
                WorldPacket data(12);
                if (value)
                    data.SetOpcode(SMSG_MOVE_SET_CAN_FLY);
                else
                    data.SetOpcode(SMSG_MOVE_UNSET_CAN_FLY);

                data << player->GetPackGUID();
                data << uint32(0);
                player->SendMessageToSet(&data, true);
            }

            const Position GetPositionAroundMe(float angle, float radius)
            {
                double ang = angle * (M_PI / 180);
                Position pos;
                pos.m_positionX = me->GetPositionX() + radius * sin(ang);
                pos.m_positionY = me->GetPositionY() + radius * cos(ang);
                pos.m_positionZ = 4.38f;
                return pos;
            }
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new jaina_affray_isleAI(creature);
    }
};

void AddSC_jaina_affray_isle()
{
    new jaina_affray_isle();
}
