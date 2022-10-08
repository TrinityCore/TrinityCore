
#include "GameEventMgr.h"
#include "GameObject.h"
enum eSay
{
    SAY_PANDA,
 
    SAY_TROLL,
    SAY_TAUREN,
    SAY_ORC,
    SAY_GOBLIN,
    SAY_UNDEAD,
    SAY_BLOOD_ELF,
    SAY_HIGHMOUNTAIN_TAUREN,
    SAY_NIGHTBORNE,
 
    SAY_HUMAN = 1,
    SAY_DRAENEI,
    SAY_GNOME,
    SAY_DWARF,
    SAY_NIGHTELF,
    SAY_WORGEN,
    SAY_LIGHTFORGED_DRAENEI,
    SAY_VOID_ELF
};

enum eEvent
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
    EVENT_9
};

enum eAction
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,
    ACTION_6,
    ACTION_7,
    ACTION_8,
    ACTION_9,
};
Position GameObjects_PandaHorde1[2] =
{
    { 1646.538f, -4446.736f, 18.34174f, 0.0f },
    { 1645.198f, -4448.274f, 18.37885f, 5.277842f }
};
 
Position GameObjects_PandaHorde2[2] =
{
    { 1639.217f, -4454.135f, 18.52924f, 1.444366f },
    { 1640.997f, -4453.488f, 18.52862f, 1.444366f }
};
 
Position GameObjects_Undead[2] =
{
    { 1634.129f, -4450.229f, 18.58235f, 1.692287f },
    { 1642.49f, -4441.861f, 18.56001f, 2.807821f }
};
 
Position Creatures_Undead[2] =
{
    { 1646.344f, -4447.566f, 18.61218f, 2.624754f },
    { 1639.727f, -4453.734f, 18.61253f, 1.908382f }
};
 
Position GameObjects_Troll[2] =
{
    { 1634.082f, -4450.311f, 18.61004f, 1.962201f },
    { 1642.389f, -4442.094f, 18.61934f, 2.762229f }
};
 
Position Creatures_Troll[2] =
{
    { 1639.168f, -4453.635f, 18.6129f, 1.44558f },
    { 1646.5f, -4448.054f, 18.61526f, 2.603914f }
};
 
Position GameObjects_Tauren[2] =
{
    { 1634.092f, -4450.299f, 18.62661f, 2.360492f },
    { 1642.392f, -4442.052f, 18.60526f, 2.393105f }
};
 
Position GameObjects_Goblin1[2] =
{
    { 1642.576f, -4441.997f, 18.53502f, 2.567097f },
    { 1634.156f, -4450.365f, 18.40569f, 2.272538f }
};
 
Position GameObjects_Goblin2[1] =
{
    { 1639.512f, -4454.743f, 18.5289f, 1.639161f }
};
 
Position GameObjects_BloodElf[2] =
{
    { 1634.028f, -4450.311f, 18.44618f, 2.341336f },
    { 1642.415f, -4441.995f, 18.54674f, 2.341336f }
};
 
Position Creatures_BloodElf[2] =
{
    { 1646.379f, -4447.776f, 18.61213f, 2.284842f },
    { 1639.392f, -4454.759f, 18.61214f, 2.284842f }
};
 
Position GameObjects_Orc[4] =
{
    { 1642.403f, -4442.122f, 18.52885f, 2.339575f },
    { 1634.132f, -4450.304f, 18.53629f, 2.339575f },
    { 1648.064f, -4448.8f, 18.52731f, 2.339575f },
    { 1640.708f, -4456.162f, 18.5273f, 2.339575f }
};
 
Position Creatures_Human[4] =
{
    { -8809.627f, 667.875f, 99.68798f, 3.573264f },
    { -8811.129f, 671.9097f, 99.62115f, 3.601025f },
    { -8803.71f, 655.5677f, 99.61188f, 3.601025f },
    { -8805.778f, 658.6632f, 99.72522f, 3.601025f }
};
 
Position GameObjects_Human[2] =
{
    { -8816.955f, 671.0573f, 99.50975f, 3.868148f },
    { -8808.649f, 652.0295f, 99.58704f, 3.295569f }
};
 
Position GameObjects_PandaAlliance1[2] =
{
    { -8803.479f, 653.4132f, 99.61394f, 5.176046f },
    { -8804.701f, 656.5955f, 99.60896f, 0.0f }
};
 
Position GameObjects_PandaAlliance2[2] =
{
    { -8811.194f, 670.1927f, 99.61343f, 0.3403957f },
    { -8812.531f, 672.3646f, 99.60198f, 1.278826f }
};
 
Position GameObjects_PandaAlliance3[2] =
{
    { -8816.583f, 670.9063f, 99.51109f, 3.827629f },
    { -8808.478f, 652.0417f, 99.50964f, 2.903347f }
};
 
Position Creatures_PandaAlliance[2] =
{
    { -8805.607f, 658.6823f, 99.77298f, 3.323271f },
    { -8809.594f, 667.4236f, 99.72505f, 3.538034f }
};
 
Position Creatures_PandaHorde[2] =
{
    { 1637.998f, -4453.658f, 19.51874f, 1.905331f },
    { 1646.026f, -4445.582f, 19.78983f, 2.588455f }
};
 
Position GameObjects_Draenei1[2] =
{
    { -8817.076f, 671.0625f, 99.50977f, 3.992838f },
    { -8808.42f, 652.1059f, 99.5117f, 3.229078f }
};
 
Position GameObjects_Draenei2[2] =
{
    { -8803.939f, 655.5174f, 99.90648f, 5.15875f },
    { -8806.221f, 660.6702f, 99.90648f, 5.15875f }
};
 
Position GameObjects_Worgen[2] =
{
    { -8816.759f, 670.9688f, 99.50755f, 4.076256f },
    { -8808.451f, 651.9861f, 99.50967f, 2.962185f }
};
 
struct npc_ashtar_121694 : ScriptedAI
{
    npc_ashtar_121694(Creature* creature) : ScriptedAI(creature) {}
 
    EventMap events;
 
    void Reset() override
    {
        events.Reset();
        CleanPlace();
        events.ScheduleEvent(EVENT_1, 60000);
        DoCast(243089);
    }
 
    void CleanPlace()
    {
        if (sGameEventMgr->IsActiveEvent(300))
        {
            /*
            if (auto auctionist1 = me->FindNearestCreature(44865, 100.0f))
                auctionist1->SetVisible(false);
            if (auto auctionist2 = me->FindNearestCreature(44867, 100.0f))
                auctionist2->SetVisible(false);
            if (auto auctionist3 = me->FindNearestCreature(44866, 100.0f))
                auctionist3->SetVisible(false);
            if (auto auctionist4 = me->FindNearestCreature(44868, 100.0f))
                auctionist4->SetVisible(false);
            if (auto guard1 = me->FindNearestCreature(44871, 100.0f))
                guard1->SetVisible(false);
            if (auto guard2 = me->FindNearestCreature(44872, 100.0f))
                guard2->SetVisible(false);
            if (auto guard3 = me->FindNearestCreature(14376, 100.0f))
                guard3->SetVisible(false);
            */
        }
        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, me, 12.0f);
        for (auto& player : playerList)
        {
            if (!player->HasAura(243089) || !player->HasAura(248207))
            {
                player->CastSpell(player, 243089, true);
                player->AddAura(248207, player);
            }
        }
    }
 
    void EnterEvadeMode(EvadeReason reason) override
    {
        CreatureAI::EnterEvadeMode();
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
 
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
            {
                events.ScheduleEvent(EVENT_1, 60000);
                std::list<Position> listPosMale;
                std::list<Position> listPosFemale;
                std::list<Player*> players;
                std::map<uint8, std::list<Player*>> playerRace[TEAM_MAX];
                GetPlayerListInGrid(players, me, 12.0f);
                if (players.empty())
                    return;

                for (auto& player : players)
                    playerRace[player->GetTeamId()][player->getRace()].push_back(player);
 
                if (playerRace[TEAM_HORDE].empty())
                    return;

                auto& selectList = Trinity::Containers::SelectRandomContainerElement(playerRace[TEAM_HORDE]);
                std::list<Player*> listPl = selectList.second;
                if (listPl.size() > 14)
                    Trinity::Containers::RandomResize(listPl, 14);
                uint8 selectRace = selectList.first;
 
                listPosMale.push_back(Position{ 1642.28f, -4447.57f, 18.5314f });
                listPosMale.push_back(Position{ 1640.95f, -4448.94f, 18.5311f });
                listPosMale.push_back(Position{ 1639.59f, -4450.35f, 18.5311f });
                listPosMale.push_back(Position{ 1644.83f, -4444.93f, 18.5316f });
                listPosMale.push_back(Position{ 1643.49f, -4446.32f, 18.5323f });
                listPosMale.push_back(Position{ 1638.45f, -4451.52f, 18.5311f });
                listPosMale.push_back(Position{ 1637.23f, -4452.8f, 18.5311f });
                listPosFemale.push_back(Position{ 1638.0f, -4449.1f, 18.5325f });
                listPosFemale.push_back(Position{ 1643.06f, -4443.95f, 18.5325f });
                listPosFemale.push_back(Position{ 1641.63f, -4445.28f, 18.5325f });
                listPosFemale.push_back(Position{ 1635.85f, -4451.29f, 18.5325f });
                listPosFemale.push_back(Position{ 1636.86f, -4450.27f, 18.5325f });
                listPosFemale.push_back(Position{ 1640.55f, -4446.4f, 18.5325f });
                listPosFemale.push_back(Position{ 1639.28f, -4447.73f, 18.5325f });
 
                for (auto& player : listPl)
                {
                    if (listPosMale.size() > 0)
                    {
                        if (player->getGender() == GENDER_MALE)
                        {
                            player->CastSpell(listPosMale.front(), 230496, false);
                            listPosMale.pop_front();
                           // player->AddDelayedEvent(500, [=]() -> void { player->SetFacingTo(2.053105f); });
                          //  player->AddDelayedEvent(700, [=]() -> void { player->CastSpell(player, 243100, false); });
                        }
                    }
                    if (listPosFemale.size() > 0)
                    {
                        if (player->getGender() == GENDER_FEMALE)
                        {
                            player->CastSpell(listPosFemale.front(), 230496, false);
                            listPosFemale.pop_front();
                          //  player->AddDelayedEvent(500, [=]() -> void { player->SetFacingTo(2.053105f); });
                          //  player->AddDelayedEvent(700, [=]() -> void { player->CastSpell(player, 243100, false); });
                        }
                    }
                }
 
                switch (selectRace)
                {
                case RACE_PANDAREN_HORDE:
                    me->AI()->DoAction(ACTION_1);
                    break;
                case RACE_TROLL:
                    me->AI()->DoAction(ACTION_2);
                    break;
                case RACE_TAUREN:
                    me->AI()->DoAction(ACTION_3);
                    break;
                case RACE_ORC:
                    me->AI()->DoAction(ACTION_4);
                    break;
                case RACE_GOBLIN:
                    me->AI()->DoAction(ACTION_5);
                    break;
                case RACE_UNDEAD_PLAYER:
                    me->AI()->DoAction(ACTION_6);
                    break;
                case RACE_BLOODELF:
                    me->AI()->DoAction(ACTION_7);
                    break;
                case RACE_HIGHMOUNTAIN_TAUREN:
                    me->AI()->DoAction(ACTION_8);
                    break;
                case RACE_NIGHTBORNE:
                    me->AI()->DoAction(ACTION_9);
                    break;
                }
                break;
            }
            }
        }
    }
 
    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case ACTION_1:
            Talk(SAY_PANDA);
            for (uint8 i = 0; i < 2; ++i)
            {
                me->SummonGameObject(247599, GameObjects_PandaHorde1[i], QuaternionData(), 15);
                me->SummonGameObject(247599, GameObjects_PandaHorde1[i], QuaternionData(), 15);
                me->SummonGameObject(247600, GameObjects_PandaHorde2[i], QuaternionData(), 15);
                me->SummonCreature(124969, Creatures_PandaHorde[i], TEMPSUMMON_TIMED_DESPAWN, 15000);
            }
            break;
        case ACTION_2:
            Talk(SAY_TROLL);
            for (uint8 i = 0; i < 2; ++i)
            {
                me->SummonGameObject(269856, GameObjects_Troll[i], QuaternionData(), 15);
                me->SummonCreature(121724, Creatures_Troll[i], TEMPSUMMON_TIMED_DESPAWN, 15000);
            }
            break;
        case ACTION_3:
            Talk(SAY_TAUREN);
            for (uint8 i = 0; i < 2; ++i)
                me->SummonGameObject(269857, GameObjects_Tauren[i], QuaternionData(), 15);
            break;
        case ACTION_4:
            Talk(SAY_ORC);
            for (uint8 i = 0; i < 4; ++i)
                me->SummonGameObject(269861, GameObjects_Orc[i], QuaternionData(), 15);
            break;
        case ACTION_5:
            Talk(SAY_GOBLIN);
            for (uint8 i = 0; i < 2; ++i)
            {
                me->SummonGameObject(269858, GameObjects_Goblin1[i], QuaternionData(), 15);
                me->SummonGameObject(269869, GameObjects_Goblin2[i], QuaternionData(), 15);
            }
            me->SummonCreature(121727, 1645.549f, -4447.509f, 19.08538f, 3.405418f, TEMPSUMMON_TIMED_DESPAWN, 15000);
            break;
        case ACTION_6:
            Talk(SAY_UNDEAD);
            for (uint8 i = 0; i < 2; ++i)
            {
                me->SummonGameObject(269855, GameObjects_Undead[i], QuaternionData(), 15);
                me->SummonCreature(121722, Creatures_Undead[i], TEMPSUMMON_TIMED_DESPAWN, 15000);
            }
            break;
        case ACTION_7:
            Talk(SAY_BLOOD_ELF);
            for (uint8 i = 0; i < 2; ++i)
            {
                me->SummonGameObject(269859, GameObjects_BloodElf[i], QuaternionData(), 15);
                me->SummonCreature(121730, Creatures_BloodElf[i], TEMPSUMMON_TIMED_DESPAWN, 15000);
            }
        case ACTION_8:
            Talk(SAY_HIGHMOUNTAIN_TAUREN);
            break;
        case ACTION_9:
            Talk(SAY_NIGHTBORNE);
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 45.0f, false))
            {
                if (sGameEventMgr->IsActiveEvent(300))
                {
                    if (!player->HasAura(243089) || !player->HasAura(248207))
                    {
                        player->CastSpell(player, 243089, true);
                        player->AddAura(248207, player);
                    }
                }
            }
            else
            {
                player->RemoveAura(243089);
                player->RemoveAura(248207);
            }
        }
    }
};
 
struct npc_marla_121739 : ScriptedAI
{
    npc_marla_121739(Creature* creature) : ScriptedAI(creature) {  }
 
    EventMap events;
 
    void Reset() override
    {
        events.Reset();
        CleanPlace();
        events.ScheduleEvent(EVENT_1, 60000);
        DoCast(243089);
    }
 
    void EnterEvadeMode(EvadeReason reason) override
    {
        CreatureAI::EnterEvadeMode();
    }

    void CleanPlace()
    {
        if (sGameEventMgr->IsActiveEvent(300))
        {
            /*
            if (auto auctionist1 = me->FindNearestCreature(8670, 100.0f))
                auctionist1->SetVisible(false);
            if (auto auctionist2 = me->FindNearestCreature(8719, 100.0f))
                auctionist2->SetVisible(false);
            if (auto auctionist3 = me->FindNearestCreature(15659, 100.0f))
                auctionist3->SetVisible(false);
            if (auto citizen = me->FindNearestCreature(83678, 100.0f))
                citizen->SetVisible(false);
            */
        }
        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, me, 12.0f);
        for (auto& player : playerList)
        {
            if (!player->HasAura(243089) || !player->HasAura(248203))
            {
                player->CastSpell(player, 243089, true);
                player->AddAura(248203, player);
            }
        }
    }
 
    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
 
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
            {
                events.ScheduleEvent(EVENT_1, 60000);
                std::list<Position> listPosMale;
                std::list<Position> listPosFemale;
                std::list<Player*> players;
                std::map<uint8, std::list<Player*>> playerRace[TEAM_MAX];
                GetPlayerListInGrid(players, me, 12.0f);
                if (players.empty())
                    return;

                for (auto& player : players)
                    playerRace[player->GetTeamId()][player->getRace()].push_back(player);

                if (playerRace[TEAM_ALLIANCE].empty())
                    return;

                auto& selectList = Trinity::Containers::SelectRandomContainerElement(playerRace[TEAM_ALLIANCE]);
                std::list<Player*> listPl = selectList.second;
                if (listPl.size() > 26)
                    Trinity::Containers::RandomResize(listPl, 26);

                uint8 selectRace = selectList.first;

                listPosMale.push_back(Position{ -8808.11f, 660.28f, 99.6042f });
                listPosMale.push_back(Position{ -8808.86f, 661.719f, 99.6008f });
                listPosMale.push_back(Position{ -8809.39f, 663.006f, 99.6008f });
                listPosMale.push_back(Position{ -8809.98f, 664.495f, 99.6018f });
                listPosMale.push_back(Position{ -8810.63f, 666.116f, 99.6031f });
                listPosMale.push_back(Position{ -8811.26f, 667.522f, 99.6031f });
                listPosMale.push_back(Position{ -8804.83f, 653.528f, 99.6113f });
                listPosMale.push_back(Position{ -8805.68f, 655.29f, 99.6099f });
                listPosMale.push_back(Position{ -8806.46f, 656.882f, 99.6078f });
                listPosMale.push_back(Position{ -8807.32f, 658.644f, 99.6059f });
                listPosMale.push_back(Position{ -8812.0f, 669.199f, 99.6033f });
                listPosMale.push_back(Position{ -8812.67f, 670.805f, 99.6034f });
                listPosMale.push_back(Position{ -8813.31f, 672.358f, 99.6036f });
                listPosFemale.push_back(Position{ -8809.76f, 657.611f, 99.5365f });
                listPosFemale.push_back(Position{ -8810.3f, 659.373f, 99.5422f });
                listPosFemale.push_back(Position{ -8810.87f, 660.808f, 99.5442f });
                listPosFemale.push_back(Position{ -8811.47f, 662.226f, 99.5442f });
                listPosFemale.push_back(Position{ -8812.09f, 663.71f, 99.5442f });
                listPosFemale.push_back(Position{ -8812.79f, 665.264f, 99.5442f });
                listPosFemale.push_back(Position{ -8808.27f, 654.133f, 99.5365f });
                listPosFemale.push_back(Position{ -8807.48f, 652.376f, 99.5365f });
                listPosFemale.push_back(Position{ -8809.02f, 655.806f, 99.5365f });
                listPosFemale.push_back(Position{ -8813.44f, 666.742f, 99.5442f });
                listPosFemale.push_back(Position{ -8814.12f, 668.277f, 99.5442f });
                listPosFemale.push_back(Position{ -8814.7f, 669.905f, 99.5455f });
                listPosFemale.push_back(Position{ -8815.38f, 671.599f, 99.5457f });
 
                for (auto& player : listPl)
                {
                    if (listPosMale.size() > 0)
                    {
                        if (player->getGender() == GENDER_MALE)
                        {
                            player->CastSpell(listPosMale.front(), 230496, false);
                            listPosMale.pop_front();
                          // player->AddDelayedEvent(500, [=]() -> void { player->SetFacingTo(2.938065f); });
                          //  player->AddDelayedEvent(700, [=]() -> void { player->CastSpell(player, 243530, false); });
                        }
                    }
                    if (listPosFemale.size() > 0)
                    {
                        if (player->getGender() == GENDER_FEMALE)
                        {
                            player->CastSpell(listPosFemale.front(), 230496, false);
                            listPosFemale.pop_front();
                           // player->AddDelayedEvent(500, [=]() -> void { player->SetFacingTo(2.938065f); });
                           // player->AddDelayedEvent(700, [=]() -> void { player->CastSpell(player, 243530, false); });
                        }
                    }
                }
 
                switch (selectRace)
                {
                case RACE_PANDAREN_ALLIANCE:
                    me->AI()->DoAction(ACTION_1);
                    break;
                case RACE_HUMAN:
                    me->AI()->DoAction(ACTION_2);
                    break;
                case RACE_DRAENEI:
                    me->AI()->DoAction(ACTION_3);
                    break;
                case RACE_GNOME:
                    me->AI()->DoAction(ACTION_4);
                    break;
                case RACE_DWARF:
                    me->AI()->DoAction(ACTION_5);
                    break;
                case RACE_NIGHTELF:
                    me->AI()->DoAction(ACTION_6);
                    break;
                case RACE_WORGEN:
                    me->AI()->DoAction(ACTION_7);
                    break;
                case RACE_LIGHTFORGED_DRAENEI:
                    me->AI()->DoAction(ACTION_8);
                    break;
                case RACE_VOID_ELF:
                    me->AI()->DoAction(ACTION_9);
                    break;
                }
                break;
            }
            }
        }
    }
 
    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case ACTION_1:
            Talk(SAY_PANDA);
            for (uint8 i = 0; i < 2; ++i)
            {
                me->SummonGameObject(245084, GameObjects_PandaAlliance1[i], QuaternionData(), 15);
                me->SummonGameObject(245085, GameObjects_PandaAlliance2[i], QuaternionData(), 15);
                me->SummonGameObject(269880, GameObjects_PandaAlliance3[i], QuaternionData(), 15);
                me->SummonCreature(124969, Creatures_PandaAlliance[i], TEMPSUMMON_TIMED_DESPAWN, 15000);
            }
            me->SummonGameObject(245083, Position(-8804.591f, 656.5555f, 99.61126f), QuaternionData(), 15);
            break;
        case ACTION_2:
            Talk(SAY_HUMAN);
            for (uint8 i = 0; i < 4; ++i)
                me->SummonCreature(122068, Creatures_Human[i], TEMPSUMMON_TIMED_DESPAWN, 15000);
            for (uint8 i = 0; i < 2; ++i)
                me->SummonGameObject(269872, GameObjects_Human[i], QuaternionData(), 15);
            break;
        case ACTION_3:
            Talk(SAY_DRAENEI);
            me->SummonCreature(124973, -8804.389f, 656.9688f, 99.63331f, 2.070419f, TEMPSUMMON_TIMED_DESPAWN, 15000);
            me->SummonCreature(124973, -8810.299f, 670.8351f, 99.67626f, 5.159013f, TEMPSUMMON_TIMED_DESPAWN, 15000);
            for (uint8 i = 0; i < 2; ++i)
            {
                me->SummonGameObject(269878, GameObjects_Draenei1[i], QuaternionData(), 15);
                me->SummonGameObject(269878, GameObjects_Draenei2[i], QuaternionData(), 15);
            }
            break;
        case ACTION_4:
            Talk(SAY_GNOME);
            break;
        case ACTION_5:
            Talk(SAY_DWARF);
            break;
        case ACTION_6:
            Talk(SAY_NIGHTELF);
            break;
        case ACTION_7:
            Talk(SAY_WORGEN);
            for (uint8 i = 0; i < 2; ++i)
                me->SummonGameObject(269879, GameObjects_Worgen[i], QuaternionData(), 15);
            break;
        case ACTION_8:
            Talk(SAY_LIGHTFORGED_DRAENEI);
            break;
        case ACTION_9:
            Talk(SAY_VOID_ELF);
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 45.0f, false))
            {
                if (sGameEventMgr->IsActiveEvent(300))
                {
                    if (!player->HasAura(243089) || !player->HasAura(248203))
                    {
                        player->CastSpell(player, 243089, true);
                        player->AddAura(248203, player);
                    }
                }
            }
            else
            {
                player->RemoveAura(243089);
                player->RemoveAura(248203);
            }
        }
    }
};

Position const tpPosHorde[17] =
{
    { 1635.934f, -4440.566f, 17.24011f },
    { 1632.809f, -4447.231f, 17.2437f },
    { 1631.582f, -4438.109f, 17.26118f },
    { 1630.111f, -4447.62f, 17.26399f },
    { 1639.507f, -4437.439f, 17.27032f },
    { 1630.715f, -4441.179f, 17.25966f },
    { 1634.566f, -4436.788f, 17.25977f },
    { 1629.259f, -4441.999f, 17.25993f },
    { 1633.288f, -4437.134f, 17.25956f },
    { 1639.83f, -4440.377f, 17.24771f },
    { 1637.222f, -4436.253f, 17.26024f },
    { 1629.97f, -4444.608f, 17.26015f },
    { 1636.604f, -4438.896f, 17.2589f },
    { 1632.905f, -4443.604f, 17.23834f },
    { 1633.684f, -4438.853f, 17.25886f },
    { 1632.349f, -4439.787f, 17.24818f },
    { 1627.868f, -4444.772f, 17.26042f }
};

//248241
class spell_teleport_off_stage_horde : public SpellScript
{
    PrepareSpellScript(spell_teleport_off_stage_horde);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        Unit* caster = GetCaster();
        if (!caster && !caster->IsPlayer())
            return;

        uint8 rand = urand(0, 16);
        caster->ToPlayer()->TeleportTo(1, tpPosHorde[rand].GetPositionX(), tpPosHorde[rand].GetPositionY(), tpPosHorde[rand].GetPositionZ(), 5.340707f);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_teleport_off_stage_horde::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);       
    }
};

Position const tpPosAlliance[17] =
{
    { -8816.149f, 652.4827f, 98.01012f },
    { -8819.726f, 650.8871f, 98.22498f },
    { -8821.26f, 658.302f, 98.225f },
    { -8826.988f, 657.3768f, 98.22498f },
    { -8822.592f, 656.2656f, 98.22498f },
    { -8821.116f, 652.9566f, 98.22497f },
    { -8824.771f, 658.6736f, 98.22497f },
    { -8817.701f, 658.2448f, 98.21861f },
    { -8819.569f, 654.7205f, 98.22497f },
    { -8820.241f, 664.809f, 98.21796f },
    { -8822.377f, 649.4323f, 98.22497f },
    { -8824.422f, 663.3038f, 98.22498f },
    { -8822.839f, 654.1823f, 98.22498f },
    { -8817.708f, 656.7292f, 98.22001f },
    { -8823.467f, 651.257f, 98.22497f },
    { -8826.035f, 660.4097f, 98.22498f },
    { -8822.67f, 661.4063f, 98.22497f }
};

//248242
class spell_teleport_off_stage_alliance : public SpellScript
{
    PrepareSpellScript(spell_teleport_off_stage_alliance);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        Unit* caster = GetCaster();
        if (!caster && !caster->IsPlayer())
            return;

        uint8 rand = urand(0, 16);
        caster->ToPlayer()->TeleportTo(0, tpPosAlliance[rand].GetPositionX(), tpPosAlliance[rand].GetPositionY(), tpPosAlliance[rand].GetPositionZ(), 0.06981317f);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_teleport_off_stage_alliance::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

void AddSC_AuctionHouseDanceParty()
{
    RegisterCreatureAI(npc_ashtar_121694);
    RegisterCreatureAI(npc_marla_121739);
    RegisterSpellScript(spell_teleport_off_stage_horde);
    RegisterSpellScript(spell_teleport_off_stage_alliance);
}
