/*
Clawxl 2021
*/

#include "Player.h"
#include "Creature.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "WorldStatePackets.h"
#include "MiscPackets.h"
#include "WorldSession.h"

enum sv_events
{
    EVENT_START_TIMER = 1,
    EVENT_GAME_START,
};

enum sv_gos
{
    GATE_01 = 303140,
    GATE_02 = 303141,
    GATE_03 = 303199,
};

enum spells
{
    SPELL_AZERITE_RESIDUE = 282982,
    SPELL_ISLAND_COMPLETE ,

};
enum sv_conversations
{
    HORDE_ON_BEGIN = 6514,
    HORDE_ON_50 = 7498,
    HORDE_ON_80 = 7487,
    HORDE_ON_COMPLETE = 7504,
};

class scenario_snowblossom_village : public InstanceMapScript
{
public:
    scenario_snowblossom_village() : InstanceMapScript("scenario_snowblossom_village", 1907) { }

    struct scenario_snowblossom_village_InstanceMapScript : public InstanceScript
    {
        scenario_snowblossom_village_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
        }

        bool isIntr = false;
        bool isComplete = false;

        void InitWorldState(bool Enable = true)
        {
           // DoUpdateWorldState(WORLDSTATE_ALLIANCE_GAIN, 0);
           // DoUpdateWorldState(WORLDSTATE_HORDE_GAIN, 0);
            DoUpdateWorldState(16018, 1);
            DoUpdateWorldState(14253, 1);
            DoUpdateWorldState(13004, 1);
            DoUpdateWorldState(14065, 1);
            DoUpdateWorldState(14246, 1);
            DoUpdateWorldState(14063, 1);
            DoUpdateWorldState(13321, 9);
            DoUpdateWorldState(12889, 1);
            DoUpdateWorldState(12878, 1);
            DoUpdateWorldState(12877, 1);

            DoUpdateWorldState(3191, 20);
            DoUpdateWorldState(3901, 18);
            DoUpdateWorldState(14684, 6000);
            DoUpdateWorldState(15893, 17);
        }

        void OnPlayerEnter(Player* player) override
        {
            InitWorldState();
            SetCheckPointPos({ 2234.674f, -129.7475f, 6.3429f, 2.344061f });
            player->RemoveAurasDueToSpell(SPELL_AZERITE_RESIDUE);

            WorldPackets::Misc::StartTimer startTimer;
            startTimer.Type = WorldPackets::Misc::StartTimer::TIMER_TYPE_BATTLEGROUND;
          //  startTimer.TotalTime = 33;
           // startTimer.TimeLeft = 33;
            instance->SendToPlayers(startTimer.Write());

            events.ScheduleEvent(EVENT_START_TIMER, 33 * IN_MILLISECONDS);
        }

        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
        {
           // packet.Worldstates.emplace_back(uint32(WORLDSTATE_ALLIANCE_GAIN), int32(GetIslandCount()[0]));
           // packet.Worldstates.emplace_back(uint32(WORLDSTATE_HORDE_GAIN), int32(GetIslandCount()[1]));
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
            default:
                break;
            }
        }

        void OnPlayerExit(Player* player) override
        {
            player->RemoveAurasDueToSpell(SPELL_AZERITE_RESIDUE);
            player->RemoveAurasDueToSpell(SPELL_ISLAND_COMPLETE);
        }

        void Update(uint32 diff) override
        {
            events.Update(diff);
            switch (events.ExecuteEvent())
            {
            case EVENT_START_TIMER:
            
                isComplete = false;
               // CastIslandAzeriteAura();
                events.ScheduleEvent(EVENT_GAME_START, 1 * IN_MILLISECONDS);
                //
                break;
            case EVENT_GAME_START:
                if (!isIntr)
                {
                    isIntr = true;
                    DoPlayConversation(HORDE_ON_BEGIN);
                }
                if (!isComplete)
                {
                   // if (GetIslandCount()[0] >= 9000)
                    {
                        isComplete = true;
                       // IslandComplete(true);
                    }
                    //else if (GetIslandCount()[1] >= 9000)
                    {
                        isComplete = true;
                       // IslandComplete(false);
                    }
                }
                events.ScheduleEvent(EVENT_GAME_START, 1 * IN_MILLISECONDS);
                break;
            }
        }

    protected:
        EventMap events;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new scenario_snowblossom_village_InstanceMapScript(map);
    }
};

void AddSC_scenario_snowblossom_village()
{
    new scenario_snowblossom_village();
}
