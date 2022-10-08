/*
    http://uwow.biz
    army_training
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "army_training.h"
#include "Packets/WorldStatePackets.h"


// main loot 252452 (win) + 251953 (fail)
std::map<uint32, uint32> gosChestToLootChest
{
    { 252452 , 252452 },
    { 251953 , 251953 },

    { 251739, 251754 }, // bers
    { 251740, 251755 }, // bers
    { 251665, 251668 }, // bank
    { 251742, 251757 }, // manawanted 
    { 251741, 251756 }, // manawanted
    { 251744, 251759 }, // mage
    { 251743, 251758 }, // mage
    { 251730, 251751 }, // more brave
    { 251727 ,251748 }, ////////////// more efficient 
    { 251732, 251753 }, // +25 dmg (common)
    { 251731, 251752 }, ///////////// + 25 dmg
    { 251728, 251749 }, // +25 hp
    { 251729, 251750 }, // /////////// + 25 hp
    { 251726, 251747 }, // toy
    { 251666, 251669 }, // pet
    { 251724, 251746 }, // 1000 ap
    { 251725, 251745 }, // 1000 ap

    // 5 bloods ?????
};

class instance_army_training : public InstanceMapScript
{
public:
    instance_army_training() : InstanceMapScript("instance_army_training", 1626) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_army_training_InstanceMapScript(map);
    }

    struct instance_army_training_InstanceMapScript : public InstanceScript
    {
        //instance_army_training_InstanceMapScript(Map* map) : InstanceScript(map) {}

        std::map<uint32, ObjectGuid> chestsGuids{};
        std::vector<ObjectGuid> spectralChests{};
        std::map<uint32, ObjectGuid> lootChests{};

        std::vector<uint32> findChests{};
        uint32 points{};
        ObjectGuid gateGuid{};

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
            case NPC_WITHERED_SPELL_CLICK:
                if (urand(1, 4) == 4)
                    creature->SetVisible(false);
                break;
            case 110375:
                creature->SetReactState(REACT_PASSIVE);
                break;
            }
        }

        void OnPlayerLeave(Player* player)
        {
            player->RemoveAurasDueToSpell(SPELL_STARTED_OVERRIDE);
            player->RemoveAurasDueToSpell(SPELL_COUNT_MINIONS);
            player->RemoveAurasDueToSpell(SPELL_TELE_END);
        }

        void CreatureDies(Creature* creature, Unit* killer)
        {
            switch (creature->GetEntry())
            {
            case 110380:
            {
                if (GameObject* gate = instance->GetGameObject(gateGuid))
                    HandleGameObject(gate->GetGUID(), true, gate);
                // no break
            }
            case 110771:
            case 110954:
            case 110381:
                DoUpdateWorldState(static_cast<WorldStates>(12174), 10);
                points += 10;
                break;
            case 110028:
            case 110029:
            case 110369:
            case 110370:
            case 110374:
            case 110377:
            case 103385:
            case 110373: //
            case 110383:
            case 110386:
                DoUpdateWorldState(static_cast<WorldStates>(12174), 3);
                points += 3;
                break;
            case 110375:
            {
                Map::PlayerList const& players = instance->GetPlayers();
                if (players.isEmpty())
                    return;

                Player* pplayer = players.begin()->getSource();
                if (!pplayer)
                    return;

                creature->CastSpell(creature, (urand(1, 2) == 1 ? 223091 : 223744), true, nullptr, nullptr, pplayer->GetGUID());
                // no break
            }
            case 110371:
            case 110376:
            case 114267:
            case 112412:
                DoUpdateWorldState(static_cast<WorldStates>(12174), 1);
                points += 1;
                break;
            case NPC_MAGE:
            {
                Map::PlayerList const& players = instance->GetPlayers();
                if (players.isEmpty())
                    return;

                Player* pplayer = players.begin()->getSource();
                if (!pplayer)
                    return;

                if (!pplayer->armyTrainingInfo.currentUnits[ARMY_UNIT_MAGE].empty())
                    return;

                for (auto guid : spectralChests)
                    if (GameObject* go = instance->GetGameObject(guid))
                    {
                        go->SetRespawnTime(0);
                        go->Delete();
                    }
                break;
            }
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
                case 251785:
                    gateGuid = go->GetGUID();
                    break;
                case 251729:
                case 251731:
                case 251724:
                case 251744: // ???
                case 251730: // ???
                    spectralChests.push_back( go->GetGUID());
                    // no break
                case 251728:
                case 251665:
                case 251739:
                case 251742:
                case 251743:
                case 251725:
                case 251732:
                case 251666:
                case 251740:
                case 251741:
                case 251726:
                case 251727:
                    chestsGuids[go->GetEntry()] = go->GetGUID();
                    break;
                case 251748:
                case 251752:
                case 251750:
                case 251759:
                case 251755:
                case 252452:
                case 251753:
                case 251751:
                case 251747:
                case 251746:
                case 251745:
                case 251749:
                case 251756:
                case 251953:
                case 251669:
                case 251754:
                case 251668:
                case 251758:
                case 251757:
                    lootChests[go->GetEntry()] = go->GetGUID();
                    break;
                case 251954:
                    if (urand(1, 3) == 3)
                        go->SetPhaseMask(2, true);
                    break;
            }
        }

        void OnPlayerEnter(Player* player) override
        {
            AddDelayedEvent(5000, [&]() -> void
            {
                Map::PlayerList const& players = instance->GetPlayers();
                if (players.isEmpty())
                    return;

                Player* pplayer = players.begin()->getSource();
                if (!pplayer)
                    return;

                for (auto entry : pplayer->armyTrainingInfo.justFindedChest)
                    if (chestsGuids.find(entry) != chestsGuids.end())
                        if (GameObject* go = instance->GetGameObject(chestsGuids[entry]))
                            go->SetPhaseMask(2, true);

                if (!pplayer->armyTrainingInfo.justOpenedUnits[ARMY_UNIT_MAGE - 1])
                    for (auto guid : spectralChests)
                        if (GameObject* go = instance->GetGameObject(guid))
                            go->SetRespawnTime(-1);
            });
        }

        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
        {
            packet.Worldstates.emplace_back(static_cast<WorldStates>(12103), 0);
            packet.Worldstates.emplace_back(static_cast<WorldStates>(12104), 0);
            packet.Worldstates.emplace_back(static_cast<WorldStates>(12155), 0);
            packet.Worldstates.emplace_back(static_cast<WorldStates>(12174), 1);
            packet.Worldstates.emplace_back(static_cast<WorldStates>(12882), 1);
            packet.Worldstates.emplace_back(static_cast<WorldStates>(12884), 1);
        }

        void SetData(uint32 type, uint32 val) override
        {
            findChests.push_back(type);
        }

        void OnLootChestOpen(Player* player, Loot* loot, const GameObject* go) override
        {
            if (!go)
                return;

            if (go->GetEntry() == 251953 || go->GetEntry() == 252452)
            {
                if (points > 425)
                    points = 425;

                for (; points >= 100; points -= 100)
                    loot->AddItem(LootStoreItem((urand(1, 2) == 1 ? 141870 : 147416), LOOT_ITEM_TYPE_ITEM, 100, 1, 0, 1, 1));
                for (; points >= 25; points -= 25)
                    loot->AddItem(LootStoreItem((urand(1, 2) == 1 ? 147418 : 140260), LOOT_ITEM_TYPE_ITEM, 100, 1, 0, 1, 1));
            }
        }
        
        void onScenarionNextStep(uint32 newStep) override
        {
            if (newStep != 2)
                return;

            Map::PlayerList const& players = instance->GetPlayers();
            if (players.isEmpty())
                return;

            Player* pplayer = players.begin()->getSource();
            if (!pplayer)
                return;

            for (uint8 i = ARMY_UNIT_COMMON; i < ARMY_UNITS_MAX; ++i)
            {
                for (auto guid : pplayer->armyTrainingInfo.currentUnits[i])
                    if (Creature* summon = Unit::GetCreature(*pplayer, guid))
                        summon->DespawnOrUnsummon();

                pplayer->armyTrainingInfo.currentUnits[i].clear();
            }

            //pplayer->CastSpell(pplayer, SPELL_TELE_END, true);

            pplayer->CreateConversation(CONV_TELE);
            pplayer->AddDelayedEvent(4000, [pplayer]() -> void
            {
                pplayer->TeleportTo(1626, 2085.09f, 5399.86f, 47.33f, 6.04f, TELE_TO_SEAMLESS);
            });

            // 252452 (win) + 251953 (fail)
            if (points >= 425)
                findChests.push_back(252452);
            else
                findChests.push_back(251953);

            for (auto id : findChests)
            {
                if (id != 251953 && id != 252452)
                    pplayer->armyTrainingInfo.justFindedChest.insert(id);

                if (GameObject* go = instance->GetGameObject(lootChests[gosChestToLootChest[id]]))
                    go->SetRespawnTime(86400);
            }
            pplayer->armyTrainingInfo.needSave = true;
        }

        void Update(uint32 diff) override {}
    };
};

void AddSC_instance_army_training()
{
    new instance_army_training();
}
