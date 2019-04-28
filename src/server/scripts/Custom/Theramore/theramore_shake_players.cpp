#include "ScriptMgr.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"

enum Misc
{
    // Events
    EVENT_START_WAR         = 1,

    // NPCs
    NPC_ROK_NAH_GRUNT       = 100028,
    NPC_ROK_NAH_SOLDIER     = 100029,
    NPC_ROK_NAH_HAG         = 100030,
    NPC_ROK_NAH_FELCASTER   = 100031,
    NPC_ROK_NAH_LOA_SINGER  = 100032,

    // Textes
    JAINA_SAY_WAVE_ALERT       = 32,
    JAINA_SAY_WAVE_CITADEL     = 33,
    JAINA_SAY_WAVE_DOORS       = 34,
    JAINA_SAY_WAVE_DOCKS       = 35,
};

enum Waves
{
    WAVE_01             = 1,
    WAVE_01_CHECK,
    WAVE_02,
    WAVE_02_CHECK,
    WAVE_03,
    WAVE_03_CHECK,
    WAVE_04,
    WAVE_04_CHECK,
    WAVE_EXIT
};

float HordeMembersLocation[4][5][5] =
{
    {
        { NPC_ROK_NAH_SOLDIER,       -3658.71f, -4376.15f, 9.53f, 3.822f },
        { NPC_ROK_NAH_SOLDIER,       -3661.62f, -4372.74f, 9.35f, 3.822f },
        { NPC_ROK_NAH_SOLDIER,       -3663.10f, -4379.90f, 9.43f, 3.822f },
        { NPC_ROK_NAH_HAG,           -3666.05f, -4376.46f, 9.35f, 3.822f },
        { NPC_ROK_NAH_FELCASTER,     -3655.41f, -4370.57f, 9.35f, 3.822f }
    },

    {
        { NPC_ROK_NAH_SOLDIER,       -3669.06f, -4509.73f, 10.13f, 1.285f },
        { NPC_ROK_NAH_SOLDIER,       -3672.14f, -4508.86f, 10.33f, 1.285f },
        { NPC_ROK_NAH_GRUNT,         -3665.76f, -4510.66f, 10.07f, 1.285f },
        { NPC_ROK_NAH_LOA_SINGER,    -3669.96f, -4513.21f, 10.09f, 1.285f },
        { NPC_ROK_NAH_FELCASTER,     -3668.02f, -4506.34f, 10.21f, 1.295f }
    },

    {
        { NPC_ROK_NAH_SOLDIER,       -3827.43f, -4536.14f, 9.21f, 0.783f },
        { NPC_ROK_NAH_SOLDIER,       -3826.47f, -4543.61f, 9.23f, 0.783f },
        { NPC_ROK_NAH_SOLDIER,       -3832.48f, -4544.31f, 9.21f, 0.783f },
        { NPC_ROK_NAH_SOLDIER,       -3828.94f, -4541.13f, 9.21f, 0.783f },
        { NPC_ROK_NAH_HAG,           -3831.80f, -4538.26f, 9.21f, 0.783f }
    },

    {
        { NPC_ROK_NAH_HAG,          -3669.06f, -4509.73f, 10.13f, 1.285f },
        { NPC_ROK_NAH_FELCASTER,    -3672.14f, -4508.86f, 10.33f, 1.285f },
        { NPC_ROK_NAH_FELCASTER,    -3665.76f, -4510.66f, 10.07f, 1.285f },
        { NPC_ROK_NAH_LOA_SINGER,   -3669.96f, -4513.21f, 10.09f, 1.285f },
        { NPC_ROK_NAH_GRUNT,        -3668.02f, -4506.34f, 10.21f, 1.295f }
    }
};

class theramore_shake_players : public CreatureScript
{
    public:
    theramore_shake_players() : CreatureScript("theramore_shake_players") {}

    struct theramore_shake_playersAI : public ScriptedAI
    {
        theramore_shake_playersAI(Creature* creature) : ScriptedAI(creature)
        {
            waves = 0;
            wavesInvoker = WAVE_01;
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            if (id == EVENT_START_WAR)
            {
                jaina = GetClosestCreatureWithEntry(me, 100000, 2000.f);

                Map::PlayerList const& allPlayers = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = allPlayers.begin(); itr != allPlayers.end(); ++itr)
                {
                    if (Player * player = itr->GetSource()->ToPlayer())
                        players.push_back(player);
                }

                events.ScheduleEvent(WAVE_01, 1s);
            }
        }


        // TODO : Jaina doit crier
        // Plus de vague
        // Vague de la porte doivent courir depuis l'extérieur
        // Faire les IA de la horde en c++
        void Reset() override
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case WAVE_01:
                    case WAVE_02:
                    case WAVE_03:
                    case WAVE_04:
                        InvocationSoldatsHordeux(waves, horderMembers);
                        waves++;
                        events.ScheduleEvent(++wavesInvoker, 1s);
                        break;

                    case WAVE_01_CHECK:
                    case WAVE_02_CHECK:
                    case WAVE_03_CHECK:
                    case WAVE_04_CHECK:
                    {
                        uint32 uiHordeCompteur = 0;
                        uint32 uiDeadCompteur = 0;
                        for (uint8 i = 0; i < 5; ++i)
                        {
                            ++uiHordeCompteur;
                            Creature* temp = ObjectAccessor::GetCreature(*me, horderMembers[i]);
                            if (!temp || temp->isDead())
                                ++uiDeadCompteur;
                        }

                        if (uiHordeCompteur <= uiDeadCompteur)
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
        ObjectGuid horderMembers[5];
        uint32 waves;
        uint32 wavesInvoker;
        std::vector<Player*> players;

        void InvocationSoldatsHordeux(uint32 waveId, ObjectGuid* hordes)
        {
            for (uint32 i = 0; i < 5; ++i)
            {
                Position pos = { HordeMembersLocation[waveId][i][1], HordeMembersLocation[waveId][i][2], HordeMembersLocation[waveId][i][3], HordeMembersLocation[waveId][i][4] };
                if (Creature * temp = DoSummon((uint32)HordeMembersLocation[waveId][i][0], pos, 900000, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN))
                    hordes[i] = temp->GetGUID();
            }

            SendJainaWarning(waveId);
        }

        void SendJainaWarning(uint8 SpawnNumber)
        {
            jaina->AI()->Talk(JAINA_SAY_WAVE_ALERT);
            for (Player* player : players)
                player->PlayDirectSound(11757);

            uint8 groupId = -1;
            switch (SpawnNumber)
            {
                // Fort
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

            jaina->AI()->Talk(groupId);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new theramore_shake_playersAI(creature);
    }
};

void AddSC_theramore_shake()
{
    new theramore_shake_players();
}
