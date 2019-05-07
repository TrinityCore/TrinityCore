#include "ScriptMgr.h"
#include "Map.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "theramore.h"

constexpr uint8 NUMBER_OF_WAVES = 10;

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
    NPC_THERAMORE_WAVES         = 100035,

    // Textes
    JAINA_SAY_01                = 32,
    JAINA_SAY_02                = 33,
    JAINA_SAY_03                = 34,
    JAINA_SAY_04                = 35,
    JAINA_SAY_WAVE_ALERT        = 36,
    JAINA_SAY_WAVE_CITADEL      = 37,
    JAINA_SAY_WAVE_DOORS        = 38,
    JAINA_SAY_WAVE_DOCKS        = 39,

    // Wave types
    WAVE_DOORS                  = 0,
    WAVE_CITADEL                = 1,
    WAVE_DOCKS                  = 2
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
    WAVE_09,
    WAVE_09_CHECK,
    WAVE_10,
    WAVE_10_CHECK,
    WAVE_EXIT
};

class KalecgosFlightEvent : public BasicEvent
{
    public:
    KalecgosFlightEvent(Creature* owner) : owner(owner)
    {
        spellArgs.AddSpellMod(SPELLVALUE_BASE_POINT0, 500000);

        spellArgs.SetTriggerFlags(TRIGGERED_CAST_DIRECTLY);
        spellArgs.SetTriggerFlags(TRIGGERED_IGNORE_SET_FACING);
        spellArgs.SetTriggerFlags(TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS);
    }

    bool Execute(uint64 eventTime, uint32 /*updateTime*/) override
    {
        owner->CastSpell(owner, SPELL_FROST_BREEZE, spellArgs);
        owner->SetReactState(REACT_PASSIVE);
        owner->GetThreatManager().RemoveMeFromThreatLists();
        owner->m_Events.AddEvent(this, eventTime + 2000);
        return false;
    }

    private:
    Creature* owner;
    CastSpellExtraArgs spellArgs;
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
                thalen = GetClosestCreatureWithEntry(me, NPC_THALEN_SONGWEAVER, 20.f);
                kalecgos = GetClosestCreatureWithEntry(me, NPC_KALECGOS_DRAGON, 2000.f);
                amara = GetClosestCreatureWithEntry(me, NPC_AMARA_LEESON, 20.f);

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
                        jaina->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                        events.ScheduleEvent(EVENT_BATTLE_2, 3s);
                        break;

                    case EVENT_BATTLE_2:
                    {
                        if (Creature * barrier = GetClosestCreatureWithEntry(me, NPC_INVISIBLE_STALKER, 20.f))
                        {
                            barrier->CastSpell(barrier, 70444);
                            barrier->RemoveAllAuras();
                            barrier->DespawnOrUnsummon(2s);
                        }

                        if (GameObject * gate = GetClosestGameObjectWithEntry(me, GOB_THERAMORE_GATE, 35.f))
                        {
                            gate->SetLootState(GO_READY);
                            gate->UseDoorOrButton();
                        }

                        amara->RemoveAllAuras();
                        thalen->SetWalk(false);
                        thalen->RemoveAllAuras();
                        thalen->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_LAUGH);
                        events.ScheduleEvent(EVENT_BATTLE_3, 3s);
                        break;
                    }

                    case EVENT_BATTLE_3:
                        jaina->AI()->Talk(JAINA_SAY_03);
                        jaina->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        thalen->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        thalen->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        thalen->SetReactState(REACT_PASSIVE);
                        thalen->SetFaction(85);
                        thalen->GetMotionMaster()->MovePoint(0, -3609.83f, -4333.48f, 9.29f, false, 3.82f);
                        events.ScheduleEvent(EVENT_BATTLE_4, 6s);
                        break;

                    case EVENT_BATTLE_4:
                        if (Creature * fx = DoSummon(NPC_INVISIBLE_STALKER, jaina->GetPosition(), 5000, TEMPSUMMON_TIMED_DESPAWN))
                            fx->CastSpell(fx, SPELL_TELEPORT, true);
                        jaina->NearTeleportTo(-3612.43f, -4335.63f, 9.29f, 0.72f);
                        events.ScheduleEvent(EVENT_BATTLE_5, 1s);
                        break;

                    case EVENT_BATTLE_5:
                    {
                        CastSpellExtraArgs args;
                        args.SetTriggerFlags(TRIGGERED_CAST_DIRECTLY);
                        jaina->CastSpell(thalen, SPELL_ICE_NOVA, args);
                        thalen->AddAura(SPELL_ICE_BLOCK, thalen);
                        events.ScheduleEvent(EVENT_BATTLE_6, 2s);
                        break;
                    }

                    case EVENT_BATTLE_6:
                        jaina->CastSpell(jaina, SPELL_SIMPLE_TELEPORT);
                        events.ScheduleEvent(EVENT_BATTLE_7, 2s);
                        break;

                    case EVENT_BATTLE_7:
                        thalen->CastSpell(thalen, SPELL_POWER_BALL_VISUAL);
                        thalen->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STRANGULATE);
                        events.ScheduleEvent(EVENT_BATTLE_8, 1s);
                        break;

                    case EVENT_BATTLE_8:
                        if (Creature * medic = DoSummon(NPC_THERAMORE_MEDIC, { -3736.40f, -4553.58f, 4.74f, 5.99f }, 0, TEMPSUMMON_MANUAL_DESPAWN))
                            medic->CastSpell(thalen, SPELL_CHAINS);
                        thalen->NearTeleportTo(-3727.50f, -4555.78f, 4.74f, 2.82f);
                        jaina->CastSpell(jaina, SPELL_TELEPORT, true);
                        jaina->NearTeleportTo(-3658.39f, -4372.87f, 9.35f, 0.69f);
                        kalecgos->m_Events.AddEvent(new KalecgosFlightEvent(kalecgos), kalecgos->m_Events.CalculateTime(3000));
                        events.ScheduleEvent(WAVE_01, 5s);
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
                    case WAVE_09:
                    case WAVE_10:
                        HordeMembersInvoker(waves, horderMembers);
                        waves = RAND(WAVE_CITADEL, WAVE_DOCKS);
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
                    case WAVE_09_CHECK:
                    case WAVE_10_CHECK:
                    {
                        uint32 membersCounter = 0;
                        uint32 deadCounter = 0;
                        for (uint8 i = 0; i < NUMBER_OF_WAVES; ++i)
                        {
                            ++membersCounter;
                            Creature* temp = ObjectAccessor::GetCreature(*me, horderMembers[i]);
                            if (!temp || temp->isDead())
                                ++deadCounter;
                        }

                        // Quand le nombre de membres vivants est inférieur ou égal au nom de membres morts
                        if (membersCounter <= deadCounter)
                        {
                            for (Player* player : players)
                                player->KilledMonsterCredit(NPC_THERAMORE_WAVES);

                            events.ScheduleEvent(++wavesInvoker, 2s);
                        }
                        else
                            events.ScheduleEvent(wavesInvoker, 1s);
                        break;
                    }

                    case WAVE_EXIT:
                        for (Player* player : players)
                            player->CompleteQuest(QUEST_PREPARE_FOR_WAR);
                        jaina->AI()->SetData(EVENT_STOP_KALECGOS, 1);
                        jaina->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        kalecgos->DespawnOrUnsummon();
                        break;

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
        Creature* kalecgos;
        ObjectGuid horderMembers[NUMBER_OF_WAVES];
        uint32 waves;
        uint32 wavesInvoker;
        std::vector<Player*> players;

        void HordeMembersInvoker(uint32 waveId, ObjectGuid * hordes)
        {
            for (uint32 i = 0; i < NUMBER_OF_WAVES; ++i)
            {
                uint32 entry = RAND(NPC_ROK_NAH_GRUNT, NPC_ROK_NAH_SOLDIER, NPC_ROK_NAH_FELCASTER, NPC_ROK_NAH_HAG, NPC_ROK_NAH_LOA_SINGER);
                Position pos;

                switch (waveId)
                {
                    case WAVE_DOORS:
                        pos = GetRandomPosition({ -3608.66f, -4332.66f, 11.62f, 3.83f }, 3.f);
                        break;

                    case WAVE_CITADEL:
                        pos = GetRandomPosition({ -3669.10f, -4507.06f, 11.62f, 0.f }, 20.f);
                        break;

                    case WAVE_DOCKS:
                        pos = GetRandomPosition({ -3823.47f, -4536.42f, 11.62f, 0.f }, 25.f);
                        break;
                }

                if (Creature * temp = DoSummon(entry, pos, 900000, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN))
                {
                    if (waveId == WAVE_DOORS)
                    {
                        Position dest = GetRandomPosition(jaina->GetPosition(), 5.f);
                        temp->GetMotionMaster()->MovePoint(0, dest, false);
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
                // Portes
                case WAVE_DOORS:
                    groupId = JAINA_SAY_WAVE_DOORS;
                    break;

                // Citadelle
                case WAVE_CITADEL:
                    groupId = JAINA_SAY_WAVE_CITADEL;
                    break;

                // Docks
                case WAVE_DOCKS:
                    groupId = JAINA_SAY_WAVE_DOCKS;
                    break;
            }

            jaina->AI()->Talk(JAINA_SAY_WAVE_ALERT);
            jaina->AI()->Talk(groupId);
        }

        Position GetRandomPosition(Position center, float dist)
        {
            float alpha = 2 * float(M_PI) * float(rand_norm());
            float r = dist * sqrtf(float(rand_norm()));
            float x = r * cosf(alpha) + center.GetPositionX();
            float y = r * sinf(alpha) + center.GetPositionY();
            return { x, y, center.GetPositionZ(), 0.f };
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
