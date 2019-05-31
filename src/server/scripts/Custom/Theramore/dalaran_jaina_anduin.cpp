#include "ScriptMgr.h"
#include "Map.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"

enum NPCs
{
    NPC_ANDUIN_WRYNN        = 100041,
    NPC_KALEC               = 100001,
    NPC_JAINA_PROUDMOORE    = 100038,
    NPC_AETHAS_SUNSTRIDER   = 26471,
    NPC_INVISIBLE_STALKER   = 32780,
};

enum Spells
{
    SPELL_SIMPLE_TELEPORT   = 100032,
    SPELL_TELEPORT_EFFECT   = 70525,
    SPELL_TELEPORT_ANIM     = 70527,
    SPELL_REMEMBER_SHADOW   = 100042,
    SPELL_REMEMBER_SUMMON   = 23017,
    SPELL_ALPHA_75_PCT      = 44822,
};

enum Events
{
    ACTION_INTRO_TELEPORT   = 1,
    ACTION_START_REUNION    = 2,

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
};

enum Phases
{
    PHASE_NONE              = 1,
    PHASE_NOT_STARTED,
    PHASE_STARTED
};

enum Texts
{
    SAY_JAINA_1             = 0,

    SAY_JAINA_2             = 1,
    SAY_JAINA_3             = 2,
    SAY_JAINA_4             = 3,
    SAY_ANDUIN_5            = 0,
    SAY_JAINA_6             = 4,
    SAY_JAINA_7             = 5,
};

#pragma region CONSTANTS

constexpr auto INSIDE_PATH_SIZE = 11;

const Position centerPos = { 5848.36f, 853.19f, 843.21f, 4.10f };

const Position pathInsideJaina[INSIDE_PATH_SIZE] =
{
    { 5848.97f, 830.92f, 846.33f, 1.41f },
    { 5849.40f, 832.92f, 846.33f, 1.36f },
    { 5849.40f, 832.92f, 846.33f, 1.41f },
    { 5849.78f, 835.01f, 846.33f, 1.47f },
    { 5849.75f, 836.97f, 846.34f, 1.65f },
    { 5849.64f, 838.21f, 845.98f, 1.65f },
    { 5849.43f, 840.70f, 844.24f, 1.65f },
    { 5849.07f, 842.78f, 843.75f, 2.09f },
    { 5847.38f, 843.96f, 843.68f, 2.96f },
    { 5845.43f, 843.87f, 843.70f, 3.27f },
    { 5844.08f, 844.17f, 843.71f, 0.95f }
};

const Position pathInsideAnduin[INSIDE_PATH_SIZE] =
{
    { 5850.91f, 831.14f, 846.33f, 1.81f },
    { 5849.40f, 832.92f, 846.33f, 1.36f },
    { 5849.40f, 832.92f, 846.33f, 1.41f },
    { 5849.78f, 835.01f, 846.33f, 1.47f },
    { 5849.75f, 836.97f, 846.34f, 1.65f },
    { 5849.64f, 838.21f, 845.98f, 1.65f },
    { 5849.43f, 840.70f, 844.24f, 1.65f },
    { 5849.07f, 842.78f, 843.75f, 2.09f },
    { 5847.38f, 843.96f, 843.68f, 2.96f },
    { 5845.43f, 843.87f, 843.70f, 3.27f },
    { 5845.20f, 843.20f, 843.75f, 2.39f }
};

struct Scene
{
    public:
    uint8 Type;
    uint32 Entry;
    Emote Emote;
    uint32 Aura;
    const Position Position;
    const QuaternionData Rotation;
};

const Scene JainaKalecgos[] =
{
    { 1, NPC_JAINA_PROUDMOORE, EMOTE_STATE_TALK,   0, { 5849.46f, 852.71f, 843.21f, 2.65f }, QuaternionData::QuaternionData() },
    { 1, NPC_KALEC,            EMOTE_STATE_TALK,   0, { 5848.23f, 854.48f, 843.21f, 4.88f }, QuaternionData::QuaternionData() },
    { 2, 500007,               EMOTE_ONESHOT_NONE, 0, { 5845.58f, 856.36f, 843.21f, 4.81f }, { 0.f, 0.f, -0.58f, 0.80f } },
    { 2, 500001,               EMOTE_ONESHOT_NONE, 0, { 5849.18f, 856.40f, 843.21f, 4.18f }, { 0.f, 0.f,  0.00f, 0.00f } },
    { 2, 500006,               EMOTE_ONESHOT_NONE, 0, { 5851.37f, 854.17f, 843.21f, 3.69f }, { 0.f, 0.f, -0.98f, 0.19f } },
    { 2, 1571,                 EMOTE_ONESHOT_NONE, 0, { 5851.33f, 854.15f, 844.26f, 2.03f }, { 0.f, 0.f, -0.60f, 0.79f } },
};

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
            player = nullptr;
            anduin = nullptr;
            phase = PHASE_NONE;
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            switch (id)
            {
                case ACTION_INTRO_TELEPORT:
                    anduin = GetClosestCreatureWithEntry(me, NPC_ANDUIN_WRYNN, 10.f);
                    events.ScheduleEvent(EVENT_INTRO_1,  2s);
                    events.ScheduleEvent(EVENT_TELEPORT, 1s);
                    break;

                case ACTION_START_REUNION:
                    phase = PHASE_STARTED;
                    events.CancelEvent(EVENT_TELEPORT);
                    events.ScheduleEvent(EVENT_REUNION_1, 2s);
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (phase == PHASE_NONE && me->IsFriendlyTo(who) && me->IsWithinDistInMap(who, 6.0f))
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
                        me->SetTarget(anduin->GetGUID());
                        anduin->SetTarget(me->GetGUID());
                        me->Say("Every day I ask myself: \"What's the right thing to do?\"", LANG_UNIVERSAL);
                        events.ScheduleEvent(EVENT_REUNION_2, 4s);
                        break;

                    case EVENT_REUNION_2:
                        me->Say("Come with me - look around you a moment.", LANG_UNIVERSAL);
                        me->GetMotionMaster()->MoveSmoothPath(0, pathInsideJaina, INSIDE_PATH_SIZE, true);
                        events.ScheduleEvent(EVENT_REUNION_3, 2s);
                        break;

                    case EVENT_REUNION_3:
                        anduin->GetMotionMaster()->MoveSmoothPath(0, pathInsideAnduin, INSIDE_PATH_SIZE, true);
                        events.ScheduleEvent(EVENT_REUNION_4, 3s);
                        break;

                    case EVENT_REUNION_4:
                        me->Say("In the aftermath of Theramore, my first instinct was to decimate Orgrimmar - to kill every man woman and child in the city.", LANG_UNIVERSAL);
                        events.ScheduleEvent(EVENT_REUNION_5, 5s);
                        break;

                    case EVENT_REUNION_5:
                        anduin->Say("...Jaina!", LANG_UNIVERSAL);
                        me->SetTarget(ObjectGuid::Empty);
                        anduin->SetTarget(ObjectGuid::Empty);
                        me->SetFacingToObject(anduin);
                        anduin->SetFacingToObject(me);
                        events.ScheduleEvent(EVENT_REUNION_6, 2s);
                        break;

                    case EVENT_REUNION_6:
                        me->Say("I'm not proud. Since then, Kalecgos and I have talked at length about power, and how it should be used.", LANG_UNIVERSAL);
                        me->SetFacingToObject(center);
                        anduin->SetFacingToObject(center);
                        events.ScheduleEvent(EVENT_REUNION_7, 2s);
                        break;

                    case EVENT_REUNION_7:
                        DoCast(SPELL_REMEMBER_SUMMON);
                        SummonScene(JainaKalecgos, 6);
                        player->AddAura(SPELL_REMEMBER_SHADOW, player);
                        events.ScheduleEvent(EVENT_REUNION_8, 8s);
                        break;

                    case EVENT_REUNION_8:
                        DespawnScene();
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

        void SummonScene(const Scene* scene, uint8 size)
        {
            ObjectGuid guid = ObjectGuid::Empty;
            for (int i = 0; i < size; ++i)
            {
                switch (scene[i].Type)
                {
                    case 1:
                    {
                        Unit* c = me->SummonCreature(scene[i].Entry, scene[i].Position, TEMPSUMMON_MANUAL_DESPAWN);
                        c->AddAura(SPELL_ALPHA_75_PCT, c);
                        c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        c->SetSheath(SHEATH_STATE_UNARMED);

                        if (scene[i].Aura != 0)
                            c->AddAura(scene[i].Aura, c);

                        if (scene[i].Emote != EMOTE_ONESHOT_NONE)
                            c->SetUInt32Value(UNIT_NPC_EMOTESTATE, scene[i].Emote);

                        guid = c->GetGUID();
                        break;
                    }

                    case 2:
                    {
                        GameObject* o = me->SummonGameObject(scene[i].Entry, scene[i].Position, scene[i].Rotation, 0);
                        guid = o->GetGUID();
                        break;
                    }
                }

                guids.push_back(guid);
            }
        }

        Creature* GetInScene(uint32 entry)
        {
            for (ObjectGuid guid : guids)
            {
                WorldObject* o = ObjectAccessor::GetWorldObject(*me, guid);
                switch (o->GetTypeId())
                {
                    case TYPEID_UNIT:
                    {
                        Creature* temp = o->ToCreature();
                        if (temp && temp->GetEntry() == entry)
                            return temp;
                    }
                }
            }
        }

        void DespawnScene()
        {
            me->RemoveAurasDueToSpell(SPELL_REMEMBER_SUMMON);
            for (ObjectGuid guid : guids)
            {
                WorldObject* o = ObjectAccessor::GetWorldObject(*me, guid);
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
