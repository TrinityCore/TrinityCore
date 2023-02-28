///*
//    http://uwow.biz
//    army_training
//*/
//
//#include "scriptmgr.h"
//#include "scriptedcreature.h"
//#include "army_training.h"
//#include "packets/worldstatepackets.h"
//
//
//// main loot 252452 (win) + 251953 (fail)
//std::map<uint32, uint32> goschesttolootchest
//{
//    { 252452 , 252452 },
//    { 251953 , 251953 },
//
//    { 251739, 251754 }, // bers
//    { 251740, 251755 }, // bers
//    { 251665, 251668 }, // bank
//    { 251742, 251757 }, // manawanted 
//    { 251741, 251756 }, // manawanted
//    { 251744, 251759 }, // mage
//    { 251743, 251758 }, // mage
//    { 251730, 251751 }, // more brave
//    { 251727 ,251748 }, ////////////// more efficient 
//    { 251732, 251753 }, // +25 dmg (common)
//    { 251731, 251752 }, ///////////// + 25 dmg
//    { 251728, 251749 }, // +25 hp
//    { 251729, 251750 }, // /////////// + 25 hp
//    { 251726, 251747 }, // toy
//    { 251666, 251669 }, // pet
//    { 251724, 251746 }, // 1000 ap
//    { 251725, 251745 }, // 1000 ap
//
//    // 5 bloods ?????
//};
//
//class instance_army_training : public instancemapscript
//{
//public:
//    instance_army_training() : instancemapscript("instance_army_training", 1626) { }
//
//    instancescript* getinstancescript(instancemap* map) const override
//    {
//        return new instance_army_training_instancemapscript(map);
//    }
//
//    struct instance_army_training_instancemapscript : public instancescript
//    {
//        //instance_army_training_instancemapscript(map* map) : instancescript(map) {}
//
//        std::map<uint32, objectguid> chestsguids{};
//        std::vector<objectguid> spectralchests{};
//        std::map<uint32, objectguid> lootchests{};
//
//        std::vector<uint32> findchests{};
//        uint32 points{};
//        objectguid gateguid{};
//
//        void oncreaturecreate(creature* creature) override
//        {
//            instancescript::oncreaturecreate(creature);
//
//            switch (creature->getentry())
//            {
//            case npc_withered_spell_click:
//                if (urand(1, 4) == 4)
//                    creature->setvisible(false);
//                break;
//            case 110375:
//                creature->setreactstate(react_passive);
//                break;
//            }
//        }
//
//        void onplayerleave(player* player)
//        {
//            player->removeaurasduetospell(spell_started_override);
//            player->removeaurasduetospell(spell_count_minions);
//            player->removeaurasduetospell(spell_tele_end);
//        }
//
//        void creaturedies(creature* creature, unit* killer)
//        {
//            switch (creature->getentry())
//            {
//            case 110380:
//            {
//                if (gameobject* gate = instance->getgameobject(gateguid))
//                    handlegameobject(gate->getguid(), true, gate);
//                // no break
//            }
//            case 110771:
//            case 110954:
//            case 110381:
//                doupdateworldstate(static_cast<worldstates>(12174), 10);
//                points += 10;
//                break;
//            case 110028:
//            case 110029:
//            case 110369:
//            case 110370:
//            case 110374:
//            case 110377:
//            case 103385:
//            case 110373: //
//            case 110383:
//            case 110386:
//                doupdateworldstate(static_cast<worldstates>(12174), 3);
//                points += 3;
//                break;
//            case 110375:
//            {
//                map::playerlist const& players = instance->getplayers();
//                if (players.isempty())
//                    return;
//
//                player* pplayer = players.begin()->getsource();
//                if (!pplayer)
//                    return;
//
//                creature->castspell(creature, (urand(1, 2) == 1 ? 223091 : 223744), true, nullptr, nullptr, pplayer->getguid());
//                // no break
//            }
//            case 110371:
//            case 110376:
//            case 114267:
//            case 112412:
//                doupdateworldstate(static_cast<worldstates>(12174), 1);
//                points += 1;
//                break;
//            case npc_mage:
//            {
//                map::playerlist const& players = instance->getplayers();
//                if (players.isempty())
//                    return;
//
//                player* pplayer = players.begin()->getsource();
//                if (!pplayer)
//                    return;
//
//                if (!pplayer->armytraininginfo.currentunits[army_unit_mage].empty())
//                    return;
//
//                for (auto guid : spectralchests)
//                    if (gameobject* go = instance->getgameobject(guid))
//                    {
//                        go->setrespawntime(0);
//                        go->delete();
//                    }
//                break;
//            }
//            }
//        }
//
//        void ongameobjectcreate(gameobject* go) override
//        {
//            instancescript::ongameobjectcreate(go);
//
//            switch (go->getentry())
//            {
//                case 251785:
//                    gateguid = go->getguid();
//                    break;
//                case 251729:
//                case 251731:
//                case 251724:
//                case 251744: // ???
//                case 251730: // ???
//                    spectralchests.push_back( go->getguid());
//                    // no break
//                case 251728:
//                case 251665:
//                case 251739:
//                case 251742:
//                case 251743:
//                case 251725:
//                case 251732:
//                case 251666:
//                case 251740:
//                case 251741:
//                case 251726:
//                case 251727:
//                    chestsguids[go->getentry()] = go->getguid();
//                    break;
//                case 251748:
//                case 251752:
//                case 251750:
//                case 251759:
//                case 251755:
//                case 252452:
//                case 251753:
//                case 251751:
//                case 251747:
//                case 251746:
//                case 251745:
//                case 251749:
//                case 251756:
//                case 251953:
//                case 251669:
//                case 251754:
//                case 251668:
//                case 251758:
//                case 251757:
//                    lootchests[go->getentry()] = go->getguid();
//                    break;
//                case 251954:
//                    if (urand(1, 3) == 3)
//                        go->setphasemask(2, true);
//                    break;
//            }
//        }
//
//        void onplayerenter(player* player) override
//        {
//            adddelayedevent(5000, [&]() -> void
//            {
//                map::playerlist const& players = instance->getplayers();
//                if (players.isempty())
//                    return;
//
//                player* pplayer = players.begin()->getsource();
//                if (!pplayer)
//                    return;
//
//                for (auto entry : pplayer->armytraininginfo.justfindedchest)
//                    if (chestsguids.find(entry) != chestsguids.end())
//                        if (gameobject* go = instance->getgameobject(chestsguids[entry]))
//                            go->setphasemask(2, true);
//
//                if (!pplayer->armytraininginfo.justopenedunits[army_unit_mage - 1])
//                    for (auto guid : spectralchests)
//                        if (gameobject* go = instance->getgameobject(guid))
//                            go->setrespawntime(-1);
//            });
//        }
//
//        void fillinitialworldstates(worldpackets::worldstate::initworldstates& packet) override
//        {
//            packet.worldstates.emplace_back(static_cast<worldstates>(12103), 0);
//            packet.worldstates.emplace_back(static_cast<worldstates>(12104), 0);
//            packet.worldstates.emplace_back(static_cast<worldstates>(12155), 0);
//            packet.worldstates.emplace_back(static_cast<worldstates>(12174), 1);
//            packet.worldstates.emplace_back(static_cast<worldstates>(12882), 1);
//            packet.worldstates.emplace_back(static_cast<worldstates>(12884), 1);
//        }
//
//        void setdata(uint32 type, uint32 val) override
//        {
//            findchests.push_back(type);
//        }
//
//        void onlootchestopen(player* player, loot* loot, const gameobject* go) override
//        {
//            if (!go)
//                return;
//
//            if (go->getentry() == 251953 || go->getentry() == 252452)
//            {
//                if (points > 425)
//                    points = 425;
//
//                for (; points >= 100; points -= 100)
//                    loot->additem(lootstoreitem((urand(1, 2) == 1 ? 141870 : 147416), loot_item_type_item, 100, 1, 0, 1, 1));
//                for (; points >= 25; points -= 25)
//                    loot->additem(lootstoreitem((urand(1, 2) == 1 ? 147418 : 140260), loot_item_type_item, 100, 1, 0, 1, 1));
//            }
//        }
//        
//        void onscenarionnextstep(uint32 newstep) override
//        {
//            if (newstep != 2)
//                return;
//
//            map::playerlist const& players = instance->getplayers();
//            if (players.isempty())
//                return;
//
//            player* pplayer = players.begin()->getsource();
//            if (!pplayer)
//                return;
//
//            for (uint8 i = army_unit_common; i < army_units_max; ++i)
//            {
//                for (auto guid : pplayer->armytraininginfo.currentunits[i])
//                    if (creature* summon = unit::getcreature(*pplayer, guid))
//                        summon->despawnorunsummon();
//
//                pplayer->armytraininginfo.currentunits[i].clear();
//            }
//
//            //pplayer->castspell(pplayer, spell_tele_end, true);
//
//            pplayer->createconversation(conv_tele);
//            pplayer->adddelayedevent(4000, [pplayer]() -> void
//            {
//                pplayer->teleportto(1626, 2085.09f, 5399.86f, 47.33f, 6.04f, tele_to_seamless);
//            });
//
//            // 252452 (win) + 251953 (fail)
//            if (points >= 425)
//                findchests.push_back(252452);
//            else
//                findchests.push_back(251953);
//
//            for (auto id : findchests)
//            {
//                if (id != 251953 && id != 252452)
//                    pplayer->armytraininginfo.justfindedchest.insert(id);
//
//                if (gameobject* go = instance->getgameobject(lootchests[goschesttolootchest[id]]))
//                    go->setrespawntime(86400);
//            }
//            pplayer->armytraininginfo.needsave = true;
//        }
//
//        void update(uint32 diff) override {}
//    };
//};
//
//void addsc_instance_army_training()
//{
//    new instance_army_training();
//}
