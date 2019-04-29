#include "ScriptMgr.h"
#include "Map.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "theramore.h"

enum Misc
{
    // Events
    EVENT_START_WAR             = 1,
    EVENT_BATTLE_1,
    EVENT_BATTLE_2,
    EVENT_BATTLE_3,
    EVENT_BATTLE_4,
    EVENT_BATTLE_5,
    EVENT_BATTLE_6,
    EVENT_BATTLE_7,
    EVENT_BATTLE_8,

    // NPCs
    NPC_ROK_NAH_GRUNT           = 100034,
    NPC_ROK_NAH_SOLDIER         = 100029,
    NPC_ROK_NAH_HAG             = 100030,
    NPC_ROK_NAH_FELCASTER       = 100031,
    NPC_ROK_NAH_LOA_SINGER      = 100032,

    // Textes
    JAINA_SAY_01                = 32,
    JAINA_SAY_02                = 33,
    JAINA_SAY_03                = 34,
    JAINA_SAY_04                = 35,
    JAINA_SAY_WAVE_ALERT        = 36,
    JAINA_SAY_WAVE_CITADEL      = 37,
    JAINA_SAY_WAVE_DOORS        = 38,
    JAINA_SAY_WAVE_DOCKS        = 39
};

enum Waves
{
    WAVE_01                     = 100,
    WAVE_01_CHECK,
    WAVE_02,
    WAVE_02_CHECK,
    WAVE_03,
    WAVE_03_CHECK,
    WAVE_04,
    WAVE_04_CHECK,
    WAVE_05,
    WAVE_05_CHECK,
    WAVE_06,
    WAVE_06_CHECK,
    WAVE_07,
    WAVE_07_CHECK,
    WAVE_08,
    WAVE_08_CHECK,
    WAVE_EXIT
};

float HordeMembersLocation[4][5][5] =
{
    {
        { NPC_ROK_NAH_SOLDIER,      -3610.94f, -4334.58f, 9.29f, 3.817f },
        { NPC_ROK_NAH_GRUNT,        -3608.48f, -4331.07f, 9.35f, 3.817f },
        { NPC_ROK_NAH_GRUNT,        -3610.94f, -4332.61f, 9.29f, 3.817f },
        { NPC_ROK_NAH_GRUNT,        -3607.25f, -4334.16f, 9.36f, 3.817f },
        { NPC_ROK_NAH_GRUNT,        -3607.33f, -4330.34f, 9.32f, 3.817f }
    },

    {
        { NPC_ROK_NAH_SOLDIER,      -3669.06f, -4509.73f, 10.13f, 1.285f },
        { NPC_ROK_NAH_SOLDIER,      -3672.14f, -4508.86f, 10.33f, 1.285f },
        { NPC_ROK_NAH_GRUNT,        -3665.76f, -4510.66f, 10.07f, 1.285f },
        { NPC_ROK_NAH_LOA_SINGER,   -3669.96f, -4513.21f, 10.09f, 1.285f },
        { NPC_ROK_NAH_FELCASTER,    -3668.02f, -4506.34f, 10.21f, 1.295f }
    },

    {
        { NPC_ROK_NAH_SOLDIER,      -3827.43f, -4536.14f, 9.21f, 0.783f },
        { NPC_ROK_NAH_GRUNT,        -3826.47f, -4543.61f, 9.23f, 0.783f },
        { NPC_ROK_NAH_SOLDIER,      -3832.48f, -4544.31f, 9.21f, 0.783f },
        { NPC_ROK_NAH_LOA_SINGER,   -3828.94f, -4541.13f, 9.21f, 0.783f },
        { NPC_ROK_NAH_HAG,          -3831.80f, -4538.26f, 9.21f, 0.783f }
    },

    {
        { NPC_ROK_NAH_HAG,          -3669.06f, -4509.73f, 10.13f, 1.285f },
        { NPC_ROK_NAH_FELCASTER,    -3672.14f, -4508.86f, 10.33f, 1.285f },
        { NPC_ROK_NAH_FELCASTER,    -3665.76f, -4510.66f, 10.07f, 1.285f },
        { NPC_ROK_NAH_LOA_SINGER,   -3669.96f, -4513.21f, 10.09f, 1.285f },
        { NPC_ROK_NAH_GRUNT,        -3668.02f, -4506.34f, 10.21f, 1.295f }
    }
};

class theramore_waves_invoker : public CreatureScript
{
public:
    theramore_waves_invoker() : CreatureScript("theramore_waves_invoker") {}

    struct theramore_waves_invokerAI : public ScriptedAI
    {
        theramore_waves_invokerAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            waves = 0;
            wavesInvoker = WAVE_01;
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            if (id == EVENT_START_WAR)
            {
                jaina = GetClosestCreatureWithEntry(me, NPC_JAINA_PROUDMOORE, 20.f);
                amara = GetClosestCreatureWithEntry(me, NPC_AMARA_LEESON, 20.f);
                thalen = GetClosestCreatureWithEntry(me, NPC_THALEN_SONGWEAVER, 20.f);

                jaina->AI()->Talk(JAINA_SAY_01);

                Map::PlayerList const& allPlayers = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = allPlayers.begin(); itr != allPlayers.end(); ++itr)
                {
                    if (Player * player = itr->GetSource()->ToPlayer())
                        players.push_back(player);
                }

                events.ScheduleEvent(EVENT_BATTLE_1, 2s);
            }
        }


        // Plus de vague
        // Vague de la porte doivent courir depuis l'extérieur
        // Faire les IA de la horde en c++
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
                    // Event - Battle
                    case EVENT_BATTLE_1:
                        jaina->AI()->Talk(JAINA_SAY_02);
                        jaina->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                        events.ScheduleEvent(EVENT_BATTLE_2, 3s);
                        break;

                    case EVENT_BATTLE_2:
                    {
                        if (Creature* barrier = GetClosestCreatureWithEntry(me, NPC_INVISIBLE_STALKER, 20.f))
                        {
                            barrier->CastSpell(barrier, 70444);
                            barrier->RemoveAllAuras();
                            barrier->DespawnOrUnsummon(2s);
                        }

                        if (GameObject* gate = GetClosestGameObjectWithEntry(me, GOB_THERAMORE_GATE, 35.f))
                        {
                            gate->SetLootState(LootState::GO_READY);
                            gate->UseDoorOrButton();
                        }

                        amara->RemoveAllAuras();
                        thalen->RemoveAllAuras();
                        events.ScheduleEvent(EVENT_BATTLE_3, 3s);
                        break;
                    }

                    case EVENT_BATTLE_3:
                        jaina->AI()->Talk(JAINA_SAY_03);
                        jaina->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        thalen->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        thalen->SetReactState(REACT_PASSIVE);
                        thalen->SetFaction(85);
                        thalen->GetMotionMaster()->MovePoint(0, -3609.83f, -4333.48f, 9.29f, false, 3.82f);
                        events.ScheduleEvent(EVENT_BATTLE_4, 6s);
                        break;

                    case EVENT_BATTLE_4:
                        jaina->CastSpell(jaina, SPELL_TELEPORT, true);
                        jaina->NearTeleportTo(-3612.43f, -4335.63f, 9.29f, 0.72f);
                        events.ScheduleEvent(EVENT_BATTLE_5, 1s);
                        break;

                    case EVENT_BATTLE_5:
                    {
                        CastSpellExtraArgs args;
                        args.SetTriggerFlags(TRIGGERED_CAST_DIRECTLY);
                        jaina->CastSpell(thalen, 56935, args);
                        thalen->AddAura(45776, thalen);
                        events.ScheduleEvent(EVENT_BATTLE_6, 2s);
                        break;
                    }

                    case EVENT_BATTLE_6:
                        jaina->CastSpell(jaina, 7077);
                        events.ScheduleEvent(EVENT_BATTLE_7, 2s);
                        break;

                    case EVENT_BATTLE_7:
                        thalen->CastSpell(thalen, 54139);
                        thalen->DespawnOrUnsummon(2s);
                        events.ScheduleEvent(EVENT_BATTLE_8, 3s);
                        break;

                    case EVENT_BATTLE_8:
                        jaina->CastSpell(jaina, SPELL_TELEPORT, true);
                        jaina->NearTeleportTo(-3658.39f, -4372.87f, 9.35f, 0.69f);
                        break;

                    // Event - Invoker
                    case WAVE_01:
                    case WAVE_02:
                    case WAVE_03:
                    case WAVE_04:
                    case WAVE_05:
                    case WAVE_06:
                    case WAVE_07:
                    case WAVE_08:
                        HordeMembersInvoker(waves, horderMembers);
                        waves = RAND(1, 2);
                        events.ScheduleEvent(++wavesInvoker, 1s);
                        break;

                    case WAVE_01_CHECK:
                    case WAVE_02_CHECK:
                    case WAVE_03_CHECK:
                    case WAVE_04_CHECK:
                    case WAVE_05_CHECK:
                    case WAVE_06_CHECK:
                    case WAVE_07_CHECK:
                    case WAVE_08_CHECK:
                    {
                        uint32 membersCounter = 0;
                        uint32 deadCounter = 0;
                        for (uint8 i = 0; i < 5; ++i)
                        {
                            ++membersCounter;
                            Creature* temp = ObjectAccessor::GetCreature(*me, horderMembers[i]);
                            if (!temp || temp->isDead())
                                ++deadCounter;
                        }

                        // Quand le nombre de membres vivants est inférieur ou égal au nom de membres morts
                        if (membersCounter <= deadCounter)
                            events.ScheduleEvent(++wavesInvoker, 2s);
                        else
                            events.ScheduleEvent(wavesInvoker, 1s);
                        break;
                    }

                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
        Creature* jaina;
        Creature* thalen;
        Creature* amara;
        ObjectGuid horderMembers[5];
        uint32 waves;
        uint32 wavesInvoker;
        std::vector<Player*> players;

        void HordeMembersInvoker(uint32 waveId, ObjectGuid * hordes)
        {
            for (uint32 i = 0; i < 5; ++i)
            {
                Position pos = { HordeMembersLocation[waveId][i][1], HordeMembersLocation[waveId][i][2], HordeMembersLocation[waveId][i][3], HordeMembersLocation[waveId][i][4] };
                if (Creature * temp = DoSummon((uint32)HordeMembersLocation[waveId][i][0], pos, 900000, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN))
                {
                    switch (waveId)
                    {
                        case 0:
                        {
                            float alpha = 2 * float(M_PI) * rand_norm();
                            float r = 5 * sqrtf(rand_norm());
                            float x = r * cosf(alpha) + jaina->GetPositionX();
                            float y = r * sinf(alpha) + jaina->GetPositionY();
                            Position pos = { x, y, jaina->GetPositionZ(), 0.f };
                            temp->GetMotionMaster()->MovePoint(0, pos, false);
                            break;
                        }
                    }

                    hordes[i] = temp->GetGUID();
                }
            }

            SendJainaWarning(waveId);
        }

        void SendJainaWarning(uint8 spawnNumber)
        {
            uint8 groupId = -1;
            switch (spawnNumber)
            {
                // Citadelle
                case 1:
                case 3:
                    groupId = JAINA_SAY_WAVE_CITADEL;
                    break;

                // Portes
                case 0:
                    groupId = JAINA_SAY_WAVE_DOORS;
                    break;

                // Docks
                case 2:
                    groupId = JAINA_SAY_WAVE_DOCKS;
                    break;
            }

            jaina->AI()->Talk(JAINA_SAY_WAVE_ALERT);
            jaina->AI()->Talk(groupId);
        }
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new theramore_waves_invokerAI(creature);
    }
};

void AddSC_theramore_waves_invoker()
{
    new theramore_waves_invoker();
}
