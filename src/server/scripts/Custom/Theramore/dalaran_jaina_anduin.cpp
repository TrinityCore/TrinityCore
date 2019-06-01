#include "ScriptMgr.h"
#include "Map.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"

enum NPCs
{
    NPC_ANDUIN_WRYNN        = 100041,
    NPC_KALEC               = 100001,
    NPC_JAINA_PROUDMOORE    = 100038,
    NPC_INVISIBLE_STALKER   = 32780,
    NPC_KEL_THUZAD          = 20350,
    NPC_GHOUL               = 28405,
    NPC_WOUNDED_DALARAN     = 32493,
    NPC_KAEL_THAS           = 100043,
    NPC_BLOOD_ELF           = 100044,
    NPC_AETHAS_SUNREAVER    = 30116,
    NPC_SUNREAVER_MAGE      = 29255,
    NPC_SUNREAVER_GUARDIAN  = 33543,
    NPC_DRAGONHAWK          = 35148,
};

enum Spells
{
    SPELL_SIMPLE_TELEPORT   = 100032,
    SPELL_TELEPORT_EFFECT   = 70525,
    SPELL_TELEPORT_ANIM     = 70527,
    SPELL_REMEMBER_SHADOW   = 100042,
    SPELL_REMEMBER_SUMMON   = 23017,
    SPELL_ALPHA_75_PCT      = 44822,
    SPELL_SPOT_SCALED       = 50236
};

enum Misc
{
    SOUND_REUNION_MUSIC     = 28092,
    GOB_ANTONIDAS_STATUE    = 500011,

    QUEST_THE_FATE_OF_DALARAN = 80012,
};

enum Events
{
    ACTION_INTRO_TELEPORT   = 1,
    ACTION_START_REUNION    = 2,

    EVENT_TALK_SCENE,
    EVENT_SPAWN_SCENE,
    EVENT_DESPAWN_SCENE,

    // Events
    EVENT_TELEPORT,
    EVENT_INTRO_1,
    EVENT_INTRO_2,

    EVENT_REUNION_1,
    EVENT_REUNION_2,
    EVENT_REUNION_3,
    EVENT_REUNION_4,
    EVENT_REUNION_5,
    EVENT_REUNION_6,
    EVENT_REUNION_7,
    EVENT_REUNION_8,
    EVENT_REUNION_9,
    EVENT_REUNION_10,
    EVENT_REUNION_11,
    EVENT_REUNION_12
};

enum Phases
{
    PHASE_NONE              = 1,
    PHASE_NOT_STARTED,
    PHASE_STARTED
};

enum Texts
{
    SAY_ANDUIN_0            = 0,
    SAY_JAINA_1             = 0,

    SAY_JAINA_2             = 1,
    SAY_JAINA_3             = 2,
    SAY_JAINA_4             = 3,
    SAY_ANDUIN_5            = 1,
    SAY_JAINA_6             = 4,    // Auto
    SAY_JAINA_7             = 5,    // Auto
    SAY_JAINA_8             = 6,    // Auto
    SAY_JAINA_9             = 7,
    SAY_JAINA_10            = 8,
    SAY_JAINA_11            = 9,    // Auto
    SAY_JAINA_12            = 10,
    SAY_JAINA_13            = 11,   // Auto
    SAY_JAINA_14            = 12,
    SAY_ANDUIN_15           = 2,
    SAY_JAINA_16            = 13
};

#pragma region CONSTANTS

constexpr auto GOSSIP_ITEM_JAINA_START   = "Nous devons faire tout ce que nous pouvons pour garder la neutralité du Kirin Tor.";

constexpr uint8 INSIDE_PATH_SIZE         = 11;
constexpr uint8 SCENE_KALECGOS_COUNT     = 4;
constexpr uint8 SCENE_KEL_THUZAD_COUNT   = 3;
constexpr uint8 SCENE_KAEL_THAS_COUNT    = 6;
constexpr uint8 SCENE_AETHAS_COUNT       = 4;
constexpr uint8 SCENE_ANTONIDAS_COUNT    = 1;
constexpr uint8 TOTAL_SCENES_COUNT       = 5;

const Position centerPos = { 5848.36f, 853.19f, 843.21f, 4.10f };

const Position pathInsideJaina[INSIDE_PATH_SIZE] =
{
    { 5848.97f, 830.92f, 846.33f, 1.41f },
    { 5849.97f, 832.90f, 846.33f, 1.67f },
    { 5849.71f, 835.38f, 846.34f, 1.62f },
    { 5849.54f, 837.88f, 846.20f, 1.64f },
    { 5849.27f, 841.62f, 843.84f, 1.64f },
    { 5849.03f, 844.95f, 843.45f, 1.75f },
    { 5848.12f, 847.74f, 843.21f, 2.06f },
    { 5845.63f, 850.74f, 843.21f, 2.48f },
    { 5843.53f, 852.08f, 843.21f, 2.68f },
    { 5840.31f, 853.33f, 843.29f, 2.88f },
    { 5836.37f, 853.11f, 843.72f, 5.02f }
};

const Position pathInsideAnduin[INSIDE_PATH_SIZE] =
{
    { 5850.91f, 831.14f, 846.33f, 1.81f },
    { 5849.97f, 832.90f, 846.33f, 1.67f },
    { 5849.71f, 835.38f, 846.34f, 1.62f },
    { 5849.54f, 837.88f, 846.20f, 1.64f },
    { 5849.27f, 841.62f, 843.84f, 1.64f },
    { 5849.03f, 844.95f, 843.45f, 1.75f },
    { 5848.12f, 847.74f, 843.21f, 2.06f },
    { 5845.63f, 850.74f, 843.21f, 2.48f },
    { 5843.53f, 852.08f, 843.21f, 2.68f },
    { 5840.31f, 853.33f, 843.29f, 2.88f },
    { 5836.55f, 851.01f, 843.72f, 1.55f }
};

struct Scene
{
    public:
    uint8 Type;
    uint32 Entry;
    Emote Emote;
    uint32 Spell;
    const Position Spawn;
    const QuaternionData Rotation;
};

const Scene Kalecgos[SCENE_KALECGOS_COUNT] =
{
    { 1, NPC_JAINA_PROUDMOORE,  EMOTE_STATE_TALK,     0,       { 5849.48f, 855.61f, 843.21f, 4.63f }, QuaternionData::QuaternionData() },
    { 1, NPC_KALEC,             EMOTE_STATE_TALK,     0,       { 5849.49f, 852.97f, 843.21f, 1.50f }, QuaternionData::QuaternionData() },
    { 2, 500007,                EMOTE_ONESHOT_NONE,   0,       { 5852.70f, 853.97f, 843.21f, 3.23f }, { 0.f, 0.f, -0.99f, 0.04f } },
    { 2, 500001,                EMOTE_ONESHOT_NONE,   0,       { 5851.70f, 857.49f, 843.21f, 3.83f }, { 0.f, 0.f, -0.94f, 0.33f } }
};

const Scene Kelthuzad[SCENE_KEL_THUZAD_COUNT] =
{
    { 1, NPC_KEL_THUZAD,        EMOTE_ONESHOT_NONE,   100043,  { 5848.40f, 853.14f, 843.21f, 2.63f }, QuaternionData::QuaternionData() },
    { 1, NPC_WOUNDED_DALARAN,   EMOTE_ONESHOT_NONE,   27965,   { 5846.39f, 852.60f, 843.21f, 4.53f }, QuaternionData::QuaternionData() },
    { 2, 181756,                EMOTE_ONESHOT_NONE,   0,       { 5849.65f, 857.74f, 843.21f, 2.24f }, { 0.f, 0.f, -0.90f, -0.43f } }
};

const Scene Kaelthas[SCENE_KAEL_THAS_COUNT] =
{
    { 1, NPC_KAEL_THAS,         EMOTE_STATE_SPELL_CHANNEL_DIRECTED, 0,      { 5851.68f, 859.24f, 843.22f, 4.18f }, QuaternionData::QuaternionData() },
    { 1, NPC_BLOOD_ELF,         EMOTE_STATE_KNEEL,                  0,      { 5851.73f, 849.30f, 843.21f, 1.71f }, QuaternionData::QuaternionData() },
    { 1, NPC_BLOOD_ELF,         EMOTE_STATE_KNEEL,                  0,      { 5848.67f, 848.25f, 843.21f, 1.35f }, QuaternionData::QuaternionData() },
    { 1, NPC_BLOOD_ELF,         EMOTE_STATE_KNEEL,                  0,      { 5842.58f, 853.39f, 843.21f, 0.70f }, QuaternionData::QuaternionData() },
    { 1, NPC_BLOOD_ELF,         EMOTE_STATE_KNEEL,                  0,      { 5844.27f, 850.18f, 843.21f, 0.70f }, QuaternionData::QuaternionData() },
    { 1, NPC_INVISIBLE_STALKER, EMOTE_STATE_KNEEL,                  71183,  { 5848.36f, 853.19f, 843.21f, 4.10f }, QuaternionData::QuaternionData() }
};

const Scene Aethas[SCENE_AETHAS_COUNT] =
{
    { 1, NPC_AETHAS_SUNREAVER,      EMOTE_ONESHOT_NONE, 0, { 5847.70f, 855.39f, 843.21f, 3.17f }, QuaternionData::QuaternionData() },
    { 1, NPC_SUNREAVER_MAGE,        EMOTE_ONESHOT_NONE, 0, { 5850.47f, 849.40f, 843.21f, 2.76f }, QuaternionData::QuaternionData() },
    { 1, NPC_SUNREAVER_GUARDIAN,    EMOTE_ONESHOT_NONE, 0, { 5848.48f, 848.52f, 843.21f, 2.33f }, QuaternionData::QuaternionData() },
    { 1, NPC_DRAGONHAWK,            EMOTE_ONESHOT_NONE, 0, { 5850.83f, 856.70f, 843.21f, 3.14f }, QuaternionData::QuaternionData() }
};

const Scene Antonidas[SCENE_ANTONIDAS_COUNT]
{
    { 2, GOB_ANTONIDAS_STATUE,      EMOTE_ONESHOT_NONE, 0, { 5848.40f, 853.14f, 843.21f, 2.63f  }, { 0.f, 0.f, -0.99f, 0.f } }
};

const uint8  Sizes[TOTAL_SCENES_COUNT]  = { SCENE_KALECGOS_COUNT, SCENE_KEL_THUZAD_COUNT, SCENE_KAEL_THAS_COUNT, SCENE_AETHAS_COUNT, SCENE_ANTONIDAS_COUNT };
const Scene* Scenes[TOTAL_SCENES_COUNT] = { Kalecgos, Kelthuzad, Kaelthas, Aethas, Antonidas };

#pragma endregion

class dalaran_jaina_anduin : public CreatureScript
{
    public:
    dalaran_jaina_anduin() : CreatureScript("dalaran_jaina_anduin") {}

    struct dalaran_jaina_anduinAI : public ScriptedAI
    {
        dalaran_jaina_anduinAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            sceneIndex = 0;
            talkIndex = SAY_JAINA_6;
            player = nullptr;
            anduin = nullptr;
            phase = PHASE_NONE;
        }

        bool GossipHello(Player* player) override
        {
            if (player->GetQuestStatus(QUEST_THE_FATE_OF_DALARAN) == QUEST_STATUS_INCOMPLETE)
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_JAINA_START, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, 100001, me->GetGUID());
                return true;
            }

            SendGossipMenuFor(player, 100000, me->GetGUID());
            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    SetData(ACTION_START_REUNION, 1U);
                    break;
            }

            CloseGossipMenuFor(player);
            return true;
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            switch (id)
            {
                case ACTION_INTRO_TELEPORT:
                    anduin = GetClosestCreatureWithEntry(me, NPC_ANDUIN_WRYNN, 10.f);
                    player = me->SelectNearestPlayer(50.f);
                    anduin->AI()->Talk(SAY_ANDUIN_0);
                    events.ScheduleEvent(EVENT_INTRO_1,  4s);
                    events.ScheduleEvent(EVENT_TELEPORT, 1s);
                    break;

                case ACTION_START_REUNION:
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    anduin->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    phase = PHASE_STARTED;
                    events.CancelEvent(EVENT_TELEPORT);
                    events.ScheduleEvent(EVENT_REUNION_1, 2s);
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetMapId() != 727 || phase != PHASE_NONE)
                return;

            if (me->IsFriendlyTo(who) && me->IsWithinDistInMap(who, 6.0f))
            {
                player = who->ToPlayer();
                phase = PHASE_NOT_STARTED;
                SetData(ACTION_INTRO_TELEPORT, 1U);
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
                    // Event : TELEPORT
                    #pragma region TELEPORT

                    case EVENT_INTRO_1:
                        Talk(SAY_JAINA_1);
                        events.ScheduleEvent(EVENT_INTRO_2, 4s);
                        break;

                    case EVENT_INTRO_2:
                        anduin->SetFacingToObject(player);
                        anduin->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        me->SetFacingToObject(player);
                        break;

                    case EVENT_TELEPORT:
                        if (player->GetPositionZ() < 840.f)
                        {
                            me->CastSpell(me, SPELL_TELEPORT_ANIM, true);
                            me->CastSpell(player, SPELL_TELEPORT_EFFECT);
                        }
                        events.RescheduleEvent(EVENT_TELEPORT, 5ms);
                        break;

                    #pragma endregion

                    // Event : REUNION
                    #pragma region REUNION

                    case EVENT_REUNION_1:
                        center = me->SummonCreature(NPC_INVISIBLE_STALKER, centerPos, TEMPSUMMON_MANUAL_DESPAWN);
                        center->SetObjectScale(5.6f);
                        me->SetTarget(anduin->GetGUID());
                        anduin->SetTarget(me->GetGUID());
                        Talk(SAY_JAINA_2);
                        events.ScheduleEvent(EVENT_REUNION_2, 6s);
                        break;

                    case EVENT_REUNION_2:
                        Talk(SAY_JAINA_3);
                        anduin->SetTarget(ObjectGuid::Empty);
                        me->GetMotionMaster()->MoveSmoothPath(0, pathInsideJaina, INSIDE_PATH_SIZE, true);
                        events.ScheduleEvent(EVENT_REUNION_3, 3s);
                        break;

                    case EVENT_REUNION_3:
                        anduin->GetMotionMaster()->MoveSmoothPath(0, pathInsideAnduin, INSIDE_PATH_SIZE, true);
                        events.ScheduleEvent(EVENT_REUNION_4, 3s);
                        break;

                    case EVENT_REUNION_4:
                        Talk(SAY_JAINA_4);
                        events.ScheduleEvent(EVENT_REUNION_5, 10s);
                        break;

                    case EVENT_REUNION_5:
                        anduin->AI()->Talk(SAY_ANDUIN_5);
                        me->SetTarget(ObjectGuid::Empty);
                        me->SetFacingToObject(anduin);
                        anduin->SetFacingToObject(me);
                        events.ScheduleEvent(EVENT_REUNION_6, 1s);
                        break;

                    case EVENT_REUNION_6:
                        me->PlayDirectMusic(SOUND_REUNION_MUSIC);
                        center->AddAura(SPELL_SPOT_SCALED, center);
                        player->AddAura(SPELL_REMEMBER_SHADOW, player);
                        me->SetFacingToObject(center);
                        anduin->SetFacingToObject(center);
                        events.ScheduleEvent(EVENT_TALK_SCENE, 60ms);
                        break;

                    case EVENT_REUNION_7:
                        Talk(SAY_JAINA_9);
                        player->RemoveAurasDueToSpell(SPELL_REMEMBER_SHADOW);
                        events.ScheduleEvent(EVENT_REUNION_8, 5s);
                        break;

                    case EVENT_REUNION_8:
                        Talk(SAY_JAINA_10);
                        talkIndex = SAY_JAINA_11;
                        events.ScheduleEvent(EVENT_TALK_SCENE, 6s);
                        break;

                    case EVENT_REUNION_9:
                        Talk(SAY_JAINA_12);
                        talkIndex = SAY_JAINA_13;
                        events.ScheduleEvent(EVENT_TALK_SCENE, 6s);
                        break;

                    case EVENT_REUNION_10:
                        Talk(SAY_JAINA_14);
                        events.ScheduleEvent(EVENT_REUNION_11, 6s);
                        break;

                    case EVENT_REUNION_11:
                        anduin->AI()->Talk(SAY_ANDUIN_15);
                        events.ScheduleEvent(EVENT_REUNION_12, 3s);
                        break;

                    case EVENT_REUNION_12:
                        Talk(SAY_JAINA_16);
                        player->CompleteQuest(QUEST_THE_FATE_OF_DALARAN);
                        anduin->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        break;

                    // Events : SCENES

                    case EVENT_TALK_SCENE:
                        Talk(talkIndex++);
                        events.ScheduleEvent(EVENT_SPAWN_SCENE, 2s);
                        break;

                    case EVENT_SPAWN_SCENE:
                        SummonScene();
                        SummonSceneAddon();
                        events.ScheduleEvent(EVENT_DESPAWN_SCENE, 8s);
                        break;

                    case EVENT_DESPAWN_SCENE:
                        DespawnScene();
                        sceneIndex++;
                        switch (sceneIndex)
                        {
                            // Kalecgos, Kel'thuzad, Kael'thas
                            case 3:
                                events.ScheduleEvent(EVENT_REUNION_7, 3s);
                                break;

                            // Sunreavers
                            case 4:
                                events.ScheduleEvent(EVENT_REUNION_9, 3s);
                                break;

                            // Antonidas
                            case 5:
                                center->DespawnOrUnsummon();
                                events.ScheduleEvent(EVENT_REUNION_10, 3s);
                                break;

                            default:
                                events.ScheduleEvent(EVENT_TALK_SCENE, 2s);
                                break;
                        }
                        break;

                    #pragma endregion

                    default:
                        break;
                }
            }
        }

        private:
        EventMap events;
        Creature* anduin;
        Creature* center;
        GuidList guids;
        Phases phase;
        Player* player;
        float startOrientation;
        uint8 sceneIndex;
        uint8 talkIndex;

        void SummonScene()
        {
            DoCast(SPELL_REMEMBER_SUMMON);

            guids.clear();

            ObjectGuid guid = ObjectGuid::Empty;

            for (int i = 0; i < Sizes[sceneIndex]; ++i)
            {
                switch (Scenes[sceneIndex][i].Type)
                {
                    case 1:
                    {
                        Unit* c = me->SummonCreature(Scenes[sceneIndex][i].Entry, Scenes[sceneIndex][i].Spawn, TEMPSUMMON_MANUAL_DESPAWN);
                        c->AddAura(SPELL_ALPHA_75_PCT, c);
                        c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        c->SetSheath(SHEATH_STATE_UNARMED);
                        c->SetFaction(35);

                        if (Scenes[sceneIndex][i].Spell)
                            c->CastSpell(c, Scenes[sceneIndex][i].Spell);

                        switch (Scenes[sceneIndex][i].Emote)
                        {
                            case EMOTE_ONESHOT_NONE:
                                break;

                            case EMOTE_STATE_KNEEL:
                                c->SetStandState(UNIT_STAND_STATE_KNEEL);
                                break;

                            default:
                                c->SetUInt32Value(UNIT_NPC_EMOTESTATE, Scenes[sceneIndex][i].Emote);
                                break;
                        }

                        guid = c->GetGUID();
                        break;
                    }

                    case 2:
                    {
                        GameObject* o = me->SummonGameObject(Scenes[sceneIndex][i].Entry, Scenes[sceneIndex][i].Spawn, Scenes[sceneIndex][i].Rotation, 0);
                        guid = o->GetGUID();
                        break;
                    }
                }

                guids.push_back(guid);
            }
        }

        void SummonSceneAddon()
        {
            if (Creature * temp = GetCreatureInScene(NPC_KAEL_THAS))
            {
                temp->SetWalk(true);
                temp->GetMotionMaster()->MovePoint(0, 5849.86f, 856.02f, 843.21f);
            }

            if (Creature * temp = GetCreatureInScene(NPC_KEL_THUZAD))
            {
                for (int i = 0; i < 8; ++i)
                {
                    float angle = float(rand_norm() * 2 * M_PI);
                    float dist = frand(1, 5);
                    const Position pos = { temp->GetPositionX() + cos(angle) * dist, temp->GetPositionY() + sin(angle) * dist, temp->GetPositionZ(), angle };
                    if (Creature * ghoul = temp->SummonCreature(NPC_GHOUL, pos, TEMPSUMMON_TIMED_DESPAWN, 8s))
                    {
                        ghoul->AddAura(SPELL_ALPHA_75_PCT, ghoul);
                        ghoul->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        ghoul->SetSheath(SHEATH_STATE_UNARMED);
                        ghoul->SetFaction(35);
                    }
                }
            }

            if (GameObject * temp = GetGameObjectInScene(GOB_ANTONIDAS_STATUE))
                center->SetObjectScale(2);
        }

        Creature* GetCreatureInScene(uint32 entry)
        {
            for (ObjectGuid guid : guids)
            {
                if (WorldObject * o = ObjectAccessor::GetWorldObject(*me, guid))
                {
                    switch (o->GetTypeId())
                    {
                        case TYPEID_UNIT:
                        {
                            if (Creature * temp = o->ToCreature())
                            {
                                if (temp->GetEntry() == entry)
                                {
                                    return temp;
                                }
                            }
                        }
                    }
                }
            }

            return nullptr;
        }
        GameObject* GetGameObjectInScene(uint32 entry)
        {
            for (ObjectGuid guid : guids)
            {
                if (WorldObject * o = ObjectAccessor::GetWorldObject(*me, guid))
                {
                    switch (o->GetTypeId())
                    {
                        case TYPEID_GAMEOBJECT:
                        {
                            if (GameObject * temp = o->ToGameObject())
                            {
                                if (temp->GetEntry() == entry)
                                {
                                    return temp;
                                }
                            }
                        }
                    }
                }
            }

            return nullptr;
        }

        void DespawnScene()
        {
            me->RemoveAurasDueToSpell(SPELL_REMEMBER_SUMMON);
            for (ObjectGuid guid : guids)
            {
                WorldObject* o = ObjectAccessor::GetWorldObject(*me, guid);
                if (!o)
                    continue;

                switch (o->GetTypeId())
                {
                    case TYPEID_UNIT:
                        o->ToCreature()->DespawnOrUnsummon();
                        break;

                    case TYPEID_GAMEOBJECT:
                        o->ToGameObject()->Delete();
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new dalaran_jaina_anduinAI(creature);
    }
};

void AddSC_dalaran_jaina_anduin()
{
    new dalaran_jaina_anduin();
}
