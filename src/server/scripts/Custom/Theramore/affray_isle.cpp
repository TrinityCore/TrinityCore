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

enum Talks
{
    TALK_SPECTATOR_FLEE         =  0,

    TALK_JAINA_01               =  8,
    TALK_JAINA_02               =  9,
    TALK_KLANNOC_03             =  0,
    TALK_JAINA_04               = 10,
    TALK_JAINA_05               = 11,
    TALK_JAINA_06               = 12,
};

enum Misc
{
    // Event
    START_AFFRAY_ISLE           = 1,

    // Map ID
    MAPID_KALIMDOR              = 1,

    // Phasemask
    PHASEMASK_AFFRAY            = 16,

    // NPCs
    NPC_JAINA_PROUDMOORE        = 100066,
    NPC_KALECGOS                = 100001,
    NPC_THRALL                  = 100068,
    NPC_KLANNOC_MACLEOD         = 100067,
    NPC_AFFRAY_SPECTATOR        = 100068,
    NPC_INVISIBLE_STALKER       = 32780,
    NPC_FOCUSING_IRIS           = 100069,

    // Morph
    MORPH_INVISIBLE_PLAYER      = 15880,

    // Game objects
    GOB_FIRE                    = 182592,
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
    SPELL_ARCANE_CANALISATION   = 100064,
    SPELL_CANALISATION          = 100062,
    SPELL_ARCANE_CLOUD          = 39952,
    SPELL_STUNNED               = 100066,
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

class KlannocBurning : public BasicEvent
{
    public:
    KlannocBurning(Creature* owner, Creature* jaina) : owner(owner), jaina(jaina), stage(0) { }

    bool Execute(uint64 eventTime, uint32 /*updateTime*/) override
    {
        switch (stage)
        {
            case 0:
                owner->SetWalk(false);
                owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                return NextEvent(Milliseconds(eventTime), 500ms);
            case 1:
                jaina->CastSpell(owner, SPELL_PYROBLAST);
                return NextEvent(Milliseconds(eventTime), 1890ms);
            case 2:
                owner->RemoveAllAuras();
                owner->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                owner->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                owner->AddAura(SPELL_IMMOLATE, owner);
                owner->GetMotionMaster()->MoveConfused();
                return NextEvent(Milliseconds(eventTime), 6s);
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

    bool NextEvent(Milliseconds eventTime, Milliseconds time)
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

class WaveGrowing : public BasicEvent
{
    public:
    WaveGrowing(Creature* owner) : owner(owner) { }

    bool Execute(uint64 eventTime, uint32 /*updateTime*/) override
    {
        if (!owner->HasAura(SPELL_WAVE_VISUAL))
            owner->AddAura(SPELL_WAVE_VISUAL, owner);

        float currentScale = owner->GetObjectScale();
        if (currentScale >= 4.f)
            return true;

        owner->SetObjectScale(currentScale + 0.3f);
        owner->m_Events.AddEvent(this, Milliseconds(eventTime) + 2s);
        return false;
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
                    DoAction(START_AFFRAY_ISLE);
                    break;
                }

                default:
                    break;
            }
        }

        void DoAction(int32 param) override
        {
            if (param != START_AFFRAY_ISLE)
                return;

            Talk(TALK_JAINA_01);
            scheduler.Schedule(3s, [this](TaskContext context)
            {
                switch (context.GetRepeatCounter())
                {
                    case 0:
                        DoCast(SPELL_SIMPLE_TELEPORT);
                        context.Repeat(1s);
                        break;

                    case 1:
                        me->NearTeleportTo(-1710.29f, -4377.18f, 4.56f, 4.83f);
                        me->SetVisible(false);
                        SetPlayerTeleportMode(player, true);
                        player->GetMotionMaster()->MoveSmoothPath(0, PlayerTeleportPath, PLAYER_TELEPORT_PATH_SIZE, false);
                        context.Repeat(11s);
                        break;

                    case 2:
                        player->GetMotionMaster()->Clear();
                        SetPlayerTeleportMode(player, false);
                        me->SetVisible(true);
                        DoCast(SPELL_VISUAL_TELEPORT);
                        context.Repeat(2s);
                        break;

                    case 3:
                        Talk(TALK_JAINA_02);
                        context.Repeat(3s);
                        break;

                    case 4:
                        me->GetMotionMaster()->MoveSmoothPath(0, JainaPath01, JAINA_PATH_01_SIZE, false);
                        context.Repeat(9s);
                        break;

                    case 5:
                    {
                        if (klannoc = me->SummonCreature(NPC_KLANNOC_MACLEOD, KlannocPath01[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10min))
                        {
                            me->SetFacingTo(0.32f);

                            klannoc->GetMotionMaster()->MoveSmoothPath(0, KlannocPath01, KLANNOC_PATH_01_SIZE, true);
                            klannoc->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            klannoc->SetReactState(REACT_PASSIVE);
                            klannoc->SetFaction(14);
                        }

                        if (playerSpectator = me->SummonCreature(NPC_AFFRAY_SPECTATOR, player->GetRandomNearPosition(1.f), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10min))
                        {
                            playerSpectator->CastSpell(player, SPELL_STUNNED);
                            player->Lock(true);

                            playerSpectator->SetFacingToObject(player);
                            playerSpectator->CastSpell(playerSpectator, SPELL_SMOKE_REVEAL);
                            playerSpectator->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            playerSpectator->SetReactState(REACT_PASSIVE);
                            playerSpectator->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY_THROWN);
                            playerSpectator->SetFaction(14);
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

                        context.Repeat(8s);
                        break;
                    }

                    case 6:
                        me->SetFacingToObject(klannoc);
                        klannoc->SetFacingToObject(me);
                        klannoc->AI()->Talk(TALK_KLANNOC_03);
                        context.Repeat(3s);
                        break;

                    case 7:
                        Talk(TALK_JAINA_04);
                        context.Repeat(3s);
                        break;

                    case 8:
                        klannoc->m_Events.AddEvent(new KlannocBurning(klannoc, me), klannoc->m_Events.CalculateTime(1ms));
                        context.Repeat(3s);
                        break;

                    case 9:
                    {
                        for (Creature* spectator : spectators)
                        {
                            if (roll_chance_i(30))
                                spectator->AI()->Talk(TALK_SPECTATOR_FLEE);

                            spectator->GetMotionMaster()->MoveFleeing(me);
                            spectator->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                        }

                        playerSpectator->GetMotionMaster()->MoveFleeing(me);
                        playerSpectator->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);

                        uint8 randomSpectator = urand(0, SPECTATORS_MAX_NUMBER - 1);
                        if (Creature* victim = spectators[randomSpectator])
                        {
                            victim->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                            CastSpellExtraArgs args;
                            args.AddSpellBP0(99999999);
                            args.SetTriggerFlags(TRIGGERED_CAST_DIRECTLY);

                            DoCast(victim, SPELL_ARCANE_BARRAGE, args);
                        }

                        context.Repeat(5s);
                        break;
                    }

                    case 10:
                    {
                        Talk(TALK_JAINA_05);
                        for (Creature* spectator : spectators)
                        {
                            spectator->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            spectator->m_Events.AddEvent(new SpectatorDeath(spectator), spectator->m_Events.CalculateTime(2s));
                        }

                        playerSpectator->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        playerSpectator->m_Events.AddEvent(new SpectatorDeath(playerSpectator), playerSpectator->m_Events.CalculateTime(2s));

                        player->Lock(false);

                        CastSpellExtraArgs args;
                        args.SetTriggerFlags(TRIGGERED_CAST_DIRECTLY);

                        DoCastAOE(SPELL_ICE_NOVA, args);

                        context.Repeat(5s);
                        break;
                    }

                    case 11:
                        Talk(TALK_JAINA_06);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveSmoothPath(0, JainaPath02, JAINA_PATH_02_SIZE, false);
                        context.Repeat(13s);
                        break;

                    case 12:
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(0, -1655.44f, -4246.56f, 1.77f, true, 6.13f);
                        context.Repeat(Milliseconds((int)me->GetMotionMaster()->GetTime()));
                        break;

                    case 13:
                    {
                        if (focusingIrisFx = me->SummonCreature(NPC_FOCUSING_IRIS, -1654.17f, -4246.51f, 3.51f, 3.08f, TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            waveFx = me->SummonCreature(NPC_INVISIBLE_STALKER, -1553.19f, -4251.73f, -1.91f, 6.27f);
                            waveFx->m_Events.AddEvent(new WaveGrowing(waveFx), waveFx->m_Events.CalculateTime(3s));

                            DoCast(SPELL_ARCANE_CANALISATION);

                            me->SetFacingToObject(focusingIrisFx);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_SPELL_CHANNEL_DIRECTED);
                            me->SummonGameObject(GOB_ANTONIDAS_BOOK, -1653.03f, -4243.82f, 3.11f, 3.99f, QuaternionData(0.f, 0.f, -0.9101f, 0.4143f), 0s);
                        }
                        break;
                    }
                }
            });
        }

        void Reset() override
        {
            scheduler.CancelAll();
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            scheduler.Update(diff);
        }

        private:
        TaskScheduler scheduler;
        Player* player;
        Creature* klannoc;
        Creature* playerSpectator;
        Creature* kalecgos;
        Creature* thrall;
        Creature* arcaneCloud;
        Creature* focusingIrisFx;
        Creature* waveFx;
        std::vector<Creature*> spectators;

        bool debug;

        void SetPlayerTeleportMode(Player* player, bool value)
        {
            player->Lock(value);
            player->SetSheath(SHEATH_STATE_UNARMED);

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
            float ang = float(angle * (M_PI / 180.f));
            Position pos;
            pos.m_positionX = me->GetPositionX() + radius * sinf(ang);
            pos.m_positionY = me->GetPositionY() + radius * cosf(ang);
            pos.m_positionZ = 4.38f;
            return pos;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new jaina_affray_isleAI(creature);
    }
};

void AddSC_jaina_affray_isle()
{
    new jaina_affray_isle();
}
