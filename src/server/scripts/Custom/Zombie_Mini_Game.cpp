//#include "Chat.h"
//#include "ScriptPCH.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "ScriptedGossip.h"
//#include "ObjectMgr.h"
//#include "Group.h"
//#include "Item.h"
//#include "Unit.h"
//#include "Player.h"
//
//enum ZOMBIE_DATA
//{
//    NPC_START_GAME = 125,
//    NPC_START_NEXT_WAVE = 126,
//    NPC_START_NEXT_ROUND = 127,
//    NPC_WAIT_FOR_END_ROUND = 128,
//    NPC_WAIT_FOR_CHEST_LOOT = 151,
//    NPC_END_GAME = 152,
//    NPC_END_GAME_INUSE = 154,
//    NPC_END_GAME_GOSSIP = 157,
//
//    TIME_BTW_EACH_WAVE = -1000350,
//    TIME_TO = -1000350,
//    ZOMBIE_NPC_3_SPELL = -1000350,
//    ZOMBIE_NPC_4_SPELL = -1000350,
//    ZOMBIE_NPC_5_SPELL = -1000350,
//};
//
//uint32 ZOMBIE_NPCS[7] = { 0, 434,435,436,437,440,441 };
//uint32 TREASURE_CHEST[7] = { 0, 510000,520000,530000,540000,550000,560000 };
//
//const Position Spawn_C1 = { -10953.3662f, -1997.1374f, 79.9735f, 3.0059f };
//const Position Spawn_C2 = { -10974.728516f, -1972.700073f, 79.973518f, 5.158750f };
//const Position Spawn_C3 = { -10957.954102f, -1973.366821f, 79.973518f, 3.991647f };
//const Position Spawn_C4 = { -10985.388672f, -1992.934814f, 79.973984f, 6.138140f };
//const Position Spawn_C5 = { -10980.184570f, -2016.144897f, 79.973984f, 0.798218f };
//const Position Spawn_C6 = { -10962.931641f, -2019.476074f, 79.974602f, 2.163240f };
//
//bool zombie_inUse = false;
//
//bool closeGossipNotify(Player* player, std::string message)
//{
//    // player->PlayerTalkClass->SendCloseGossip();
//    player->GetSession()->SendNotification(message.c_str());
//    return true;
//}
//
//class zombie_bg_master : public CreatureScript
//{
//public:
//    zombie_bg_master() : CreatureScript("zombie_bg_master") { }
//
//    bool OnGossipHello(Player* player, Creature* creature)
//    {
//        if (player->IsInCombat())
//        {
//            return closeGossipNotify(player, "You can't start the zombie event while being in combat.");
//        }
//
//        if (!player->GetGroup() || player->GetGroup() == NULL)
//        {
//            return closeGossipNotify(player, "You must be the group leader in a party/raid with 5-10 players.");
//        }
//
//        Group* grp = player->GetGroup();
//
//        if (grp->GetMembersCount() > 10 || grp->GetMembersCount() < 5)
//        {
//            return closeGossipNotify(player, "You must be the group leader in a party/raid with 5-10 players.");
//        }
//
//        if (grp->GetLeaderGUID() != player->GetGUID())
//        {
//            return closeGossipNotify(player, "Only the party leader can activate the Zombie Event!");
//        }
//
//        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Teleport me to the Zombie Attack event!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
//        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "No thanks.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
//        player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
//    {
//        player->PlayerTalkClass->ClearMenus();
//        Group* grp = player->GetGroup();
//        switch (uiAction)
//        {
//        case GOSSIP_ACTION_INFO_DEF + 1:
//            grp->ConvertToRaid();
//            player->TeleportTo(532, -10966.888f, -2011.3127f, 79.98f, 1.37f);
//            zombie_inUse = true;
//            break;
//
//        case GOSSIP_ACTION_INFO_DEF + 2:
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        }
//        return true;
//    }
//
//
//};
//
//
//class zombie_bg_master_endgame : public CreatureScript
//{
//public:
//    zombie_bg_master_endgame() : CreatureScript("zombie_bg_master_endgame") { }
//
//    bool OnGossipHello(Player* player, Creature* creature)
//    {
//        if (player->IsInCombat())
//            return false;
//        if (player->GetGroup()->GetLeaderGUID() == player->GetGUID()) {
//            AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "End the Zombie Event!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
//            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Nevermind.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
//            player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
//        }
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
//    {
//        player->PlayerTalkClass->ClearMenus();
//        Group* grp = player->GetGroup();
//        switch (uiAction)
//        {
//        case GOSSIP_ACTION_INFO_DEF + 1:
//            //creature->MonsterYell("The group leader ended the zombie event!", 0, 0);
//            creature->SummonCreature(NPC_END_GAME, -10989.9003f, -1940.1300f, 93.9107f, 4.8345f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1 * 1000);
//            creature->DespawnOrUnsummon();
//            break;
//
//        case GOSSIP_ACTION_INFO_DEF + 2:
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        }
//        return true;
//    }
//
//
//};
//
//class zombie_bg_master_final : public CreatureScript
//{
//public:
//    zombie_bg_master_final() : CreatureScript("zombie_bg_master_final") { }
//
//    bool OnGossipHello(Player* player, Creature* creature)
//    {
//        if (!player->GetGroup())
//            return false;
//        if (player->GetGroup() == NULL)
//            return false;
//        if ((player->GetGroup()->GetMembersCount() <= 10 && player->GetGroup()->GetMembersCount() >= 5) && player->GetGroup()->GetLeaderGUID() == player->GetGUID())
//        {
//            AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "Summon group to the Zombie Attack event!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
//            if (player->GetGroup()->GetLeaderGUID() == player->GetGUID())
//                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Start the event!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
//            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Nevermind", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
//            player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
//        }
//        else
//        {
//            ChatHandler(player->GetSession()).PSendSysMessage("You must be the group leader in a party/raid with 5-10 players");
//            while (creature->SelectNearestPlayer(280.0f) != NULL)
//            {
//                Player* plr = creature->SelectNearestPlayer(280.0f);
//                if (plr)
//                {
//                    plr->ResurrectPlayer(60, false);
//                    plr->TeleportTo(534, 5541.770020f, -3783.469971f, 1594.910034f, 2.883010f);
//                }
//            }
//        }
//
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
//    {
//
//        player->PlayerTalkClass->ClearMenus();
//        Group* grp = player->GetGroup();
//        zombie_inUse = true;
//        if (grp) {
//            GroupReference* grpRef = grp->GetFirstMember();
//            if (grp->GetLeaderGUID() == player->GetGUID())
//                // GroupReference grpRef = player->GetGroupRef();
//
//                switch (uiAction)
//                {
//                case GOSSIP_ACTION_INFO_DEF + 1:
//
//                    for (grpRef; grpRef != NULL; grpRef = grpRef->next())
//                    {
//                        Player* groupMember = grpRef->GetSource();
//                        ChatHandler(player->GetSession()).PSendSysMessage("Sending summon request to...");
//                        if (!groupMember)
//                            continue;
//                        if (groupMember->GetGUID() == player->GetGUID())
//                            break;
//                        player->SetSelection(groupMember->GetGUID());
//                        player->CastSpell(groupMember, 7720, true);
//                        ChatHandler(player->GetSession()).PSendSysMessage("%s", groupMember->GetName());
//                    }
//                    break;
//
//                case GOSSIP_ACTION_INFO_DEF + 2:
//                    // creature->MonsterYell("Round 1 starts in 30 seconds!", 0, 0);
//
//                     /* spawn NPC_START_GAME to despawn after 30 seconds and start the game */
//                    creature->SummonCreature(NPC_START_GAME, -10989.9003f, -1940.1300f, 93.9107f, 4.8345f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30 * 1000);
//                    /* the main NPC will not be seen again by the group so teleport him away */
//                    creature->UpdatePosition(-10989.9003f, -1940.1300f, 93.9107f, 4.8345f, true);
//                    break;
//
//                case GOSSIP_ACTION_INFO_DEF + 3:
//                    //creature->MonsterYell("The group leader ended the zombie event!", 0, 0);
//                    creature->SummonCreature(NPC_END_GAME, -10989.9003f, -1940.1300f, 93.9107f, 4.8345f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 500);
//                    break;
//
//                case GOSSIP_ACTION_INFO_DEF + 4:
//                    //NPC_END_GAME
//
//                    break;
//                }
//        }
//        player->PlayerTalkClass->SendCloseGossip();
//        return true;
//    }
//
//    struct zombie_bg_master_finalAI : public ScriptedAI
//    {
//        zombie_bg_master_finalAI(Creature* c) : ScriptedAI(c), Summons(me) {}
//
//        SummonList Summons;
//        //total number of zombies to spawn
//        uint8 zombieCount;
//        //current number of zombies spawned so far
//        uint8 zombiesSpawned;
//        //how many zombies have died in this round
//        uint8 zombieDeathCount;
//        //what round in the game you are on
//        uint8 zombieRound;
//        //how many waves of zombies per round
//        uint8 zombieWaves;
//        //the number of waves already spawned
//        uint8 zombieWavesCount;
//        //the number of zombies to be spawned per wave
//        uint32 zombieSpawnPerWave;
//        //stores how many players are in the group
//        uint32 zombieGroupMembers;
//        //stores number of zombies spawn per each person
//        uint8 ZOMBIES_PER_PERSON;
//
//        bool inZombieGame;
//
//        Player* zombieLeader;
//        Group* playerGroup;
//        GameObject* zombie_chest_loot;
//
//        void JustSummoned(Creature* summon)
//        {
//            if (summon) {
//                uint32 entry = summon->GetEntry();
//                Summons.Summon(summon);
//                if (entry >= 125 && entry <= 128 || entry == 151 || entry == 152)
//                {
//
//                }
//                else {
//                    Player* selPlr = summon->SelectNearestPlayer(200);
//                    if (selPlr)
//                        summon->Attack(selPlr, false);
//                    else
//                    {
//                        /* cant find a player to select */
//                    }
//                }
//            }
//        }
//
//        void SummonedCreatureDespawn(Creature* summon)
//        {
//            uint32 summonID = summon->GetEntry();
//
//            if (summonID == NPC_START_GAME)
//            {
//                /* called at the beg of the game */
//                /* reset all vars because this is new instance of game */
//                resetZombieEvent();
//
//                Player* selPlr = me->SelectNearestPlayer(280.0f);
//                if (!selPlr)
//                {
//                    reviveAndTeleportOut(); resetZombieEvent(); ("!selPlr return", 0, 0); return;
//                }
//                if (selPlr == NULL)
//                {
//                    reviveAndTeleportOut(); resetZombieEvent(); ("selPlr == NULL return", 0, 0); return;
//                }
//                if (!selPlr->GetGroup())
//                {
//                    reviveAndTeleportOut(); resetZombieEvent(); ("!Group return", 0, 0); return;
//                }
//                if (selPlr->GetGroup() == NULL)
//                {
//                    reviveAndTeleportOut(); resetZombieEvent(); ("Group == NULL return", 0, 0); return;
//                }
//                if (playerGroup = selPlr->GetGroup())
//                {
//                    zombieGroupMembers = playerGroup->GetMembersCount();
//                    // if (zombieLeader = sObjectAccessor->FindPlayer(playerGroup->GetLeaderGUID()))
//                    {
//                        //  }
//                         // else {
//                        reviveAndTeleportOut(); resetZombieEvent(); ("LeaderGUID == NULL return", 0, 0); return;
//                    }
//                }
//                else
//                {
//                    reviveAndTeleportOut(); resetZombieEvent(); ("playerGroup == NULL return", 0, 0); return;
//                }
//
//                /* Set the ZombieGame to true so they cant keep starting the game */
//                inZombieGame = true;
//
//                ("Round 1 is starting now!", 0, 0);
//                sendMessageToGroup("Round 1 is starting now!");
//                ("If you die anytime during the event you will respawned at the end of the round!", 0, 0);
//                me->SetVisible(false);
//
//                /* calc how many waves of zombies to send */
//                zombieWaves = getNumberOfWaves();
//                /* calc how many zombies per wave */
//                zombieSpawnPerWave = getZombieSpawnCountPerWave();
//                /* spawn */
//                spawnZombies(me, zombieSpawnPerWave);
//
//                /* NPC_START_NEXT_WAVE is despanwed when the next wave of zombies is to be sent */
//                me->SummonCreature(NPC_START_NEXT_WAVE, -10989.9003f, -1940.1300f, 93.9107f, 4.8345f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30 * 1000);
//            }
//
//            if (inZombieGame == false) { return; }
//            char buffer[150];
//            switch (summonID)
//            {
//            case NPC_START_GAME:
//                /* called at the beg of the game */
//                break;
//
//                /* called when a wave of zombies needs to be spawned */
//            case NPC_START_NEXT_WAVE:
//                if (zombieWavesCount == zombieWaves) {					/* spawned all waves */
//                    if (isRoundOver()) {									/* check if all zombies are dead */
//                        /* reset wave count to 1 for next round */
//                        zombieWavesCount = 1;
//                        /* add addtional zombies for next round */
//                        ZOMBIES_PER_PERSON = ZOMBIES_PER_PERSON + 2;
//
//                        /* spawn treasure loot */
//                        spawnGoDrop(me);
//
//                        /* remove all add. zombies that are somehow left */
//                        Summons.RemoveNotExisting();
//
//                        /* revive the group for the next round */
//                        reviveGroup();
//                        me->SetVisible(true);
//
//                        sprintf(buffer, "You have finished round %u, you now have 1 minute to loot the chest in the middle before it dissapears and next round begins!", zombieRound);
//                        //me->MonsterYell(buffer, 0, 0);
//                        sendMessageToGroup(buffer);
//                        sprintf(buffer, "If you want to stop the event and exit, disband your group and you will be teleported out in 30 seconds.");
//                        //  me->MonsterYell(buffer, 0, 0);
//                        sendMessageToGroup(buffer);
//
//                        /* NPC_START_NEXT_ROUND is spawned when all waves of zombies have been killed */
//                        me->SummonCreature(NPC_START_NEXT_ROUND, -10989.9003f, -1940.1300f, 93.9107f, 4.8345f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60 * 1000);
//                        /* NPC_END_GAME_GOSSIP is spawned after every round incase players want to exit the game */
//                        me->SummonCreature(NPC_END_GAME_GOSSIP, -10969.819336f, -1995.319580f, 79.973022f, 1.467133f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60 * 1000);
//                        zombieRound++;
//
//                    }
//                    else {											/* not all zombies are dead wait for * sec and check again */
//                        if (isGroupDead())
//                        {
//                            reviveAndTeleportOut();
//                            me->SetVisible(true);
//                            Summons.DespawnAll();
//                            Summons.RemoveNotExisting();
//                            resetZombieEvent();
//                        }
//                        else {
//                            /* not all members are dead but there is still zombies left, respawn and check again in * sec */
//                            me->SummonCreature(NPC_WAIT_FOR_END_ROUND, -10989.9003f, -1940.1300f, 93.9107f, 4.8345f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30 * 1000);
//                        }
//                    }
//                }
//                else {													/* not all waves spawned continue spawning zombies */
//                    if (!isGroupDead()) {
//                        spawnZombies(me, zombieSpawnPerWave);
//                        me->SummonCreature(NPC_START_NEXT_WAVE, -10989.9003f, -1940.1300f, 93.9107f, 4.8345f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30 * 1000);
//                        zombieWavesCount++;
//                    }
//                    else {
//                        reviveAndTeleportOut();
//                        me->SetVisible(true);
//                        Summons.DespawnAll();
//                        resetZombieEvent();
//                        //  sLog->outError("Everyone is dead. Stopping....2");
//                    }
//                }
//                break;
//
//            case NPC_START_NEXT_ROUND:									/* called when the all waves are spawned and next round needs to begin */
//                if (zombieRound != 15) {
//                    sprintf(buffer, "Round %u is starting now!", zombieRound);
//                    // me->MonsterYell(buffer, 0, 0);
//                    sendMessageToGroup(buffer);
//                    me->SetVisible(false);
//                    zombieWaves = getNumberOfWaves();						/* calc how many waves of zombies to send */
//                    zombieSpawnPerWave = getZombieSpawnCountPerWave();		/* calc how many zombies per wave */
//                    spawnZombies(me, zombieSpawnPerWave);
//                    me->SummonCreature(NPC_START_NEXT_WAVE, -10989.9003f, -1940.1300f, 93.9107f, 4.8345f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30 * 1000);
//                }
//                else
//                {
//                    //    me->MonsterYell("You have completed all 15 rounds!", 0, 0);
//                    sendMessageToGroup("You have completed all 15 rounds!");
//                    resetZombieEvent();
//                    Summons.RemoveNotExisting();
//                }
//                break;
//
//            case NPC_WAIT_FOR_END_ROUND:								/* called when the all waves are spawned but zombies are still left */
//                if (isGroupDead())										/* check if the zombies killed all the players */
//                {
//                    reviveAndTeleportOut();
//                    me->SetVisible(true);
//                    Summons.DespawnAll();
//                    resetZombieEvent();
//                    //   sLog->outError("Everyone is dead. Stopping....3");
//                }
//                else {
//                    if (isRoundOver()) {									/* check if all zombies have been killed if not, wait another * secs*/
//                        sprintf(buffer, "You have finished round %u, you now have 1 minute to loot the chest in the middle before it dissapears and next round begins!", zombieRound);
//                        me->SetVisible(true);
//                        //   me->MonsterYell(buffer, 0, 0);
//                        sendMessageToGroup(buffer);
//                        sprintf(buffer, "If you want to stop the event and exit, disband your group and you will be teleported out in 30 seconds.");
//                        //   me->MonsterYell(buffer, 0, 0);
//                        sendMessageToGroup(buffer);
//
//                        zombieWavesCount = 1;
//                        ZOMBIES_PER_PERSON = ZOMBIES_PER_PERSON + 2;
//
//                        reviveGroup();
//                        Summons.RemoveNotExisting();
//                        spawnGoDrop(me);
//
//                        me->SummonCreature(NPC_START_NEXT_ROUND, -10989.9003f, -1940.1300f, 93.9107f, 4.8345f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60 * 1000);
//                        me->SummonCreature(NPC_END_GAME_GOSSIP, -10969.819336f, -1995.319580f, 79.973022f, 1.467133f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60 * 1000);
//                        zombieRound++;
//                    }
//                    else {
//                        me->SummonCreature(NPC_WAIT_FOR_END_ROUND, -10989.9003f, -1940.1300f, 93.9107f, 4.8345f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30 * 1000);
//                    }
//                }
//                break;
//
//            case NPC_WAIT_FOR_CHEST_LOOT:
//                if (zombie_chest_loot)
//                {
//                    //    zombie_chest_loot->SetRespawnTime(0);
//                     //   zombie_chest_loot->Delete();
//                     //   zombie_chest_loot->DeleteFromDB();
//                }
//                break;
//
//            case NPC_END_GAME:
//                reviveAndTeleportOut();
//                resetZombieEvent();
//                me->UpdatePosition(-10989.9003f, -1940.1300f, 93.9107f, 4.8345f, true);
//                break;
//            case NPC_END_GAME_INUSE:
//                zombie_inUse = false;
//                break;
//            case NPC_END_GAME_GOSSIP:
//
//                break;
//            default:
//                if (summonID == 434 || summonID == 435 || summonID == 436 || summonID == 437 || summonID == 440 || summonID == 441)
//                    zombieDeathCount++;
//                break;
//            }
//        }
//
//        bool isGroupDead()
//        {
//            if (!zombieLeader->GetGroup())
//                return true;
//            if (zombieLeader->GetGroup() == NULL)
//                return true;
//            if (!playerGroup)
//                return true;
//            if (playerGroup == NULL)
//                return true;
//            if (playerGroup->GetMembersCount() > 10 || playerGroup->GetMembersCount() < 5)
//                return true;
//
//            uint32 playersDead = 0;
//            const Group::MemberSlotList members = playerGroup->GetMemberSlots();
//            for (Group::member_citerator itr = members.begin(); itr != members.end(); ++itr)
//            {
//                Player* GroupMember = (ObjectAccessor::GetPlayer(*me, itr->guid));
//                if (!GroupMember || !GroupMember->GetSession()) { playersDead++; continue; }
//                if (!GroupMember->IsWithinDistInMap(me, 100)) { playersDead++; continue; }
//                if (GroupMember->isDead()) { playersDead++; continue; }
//
//            }
//
//            if (playersDead >= playerGroup->GetMembersCount())
//                return true;
//
//            if (zombieRound == 15)
//                return true;
//            return false;
//        }
//
//        bool sendMessageToGroup(const char* message)
//        {
//            if (!zombieLeader->GetGroup())
//                return true;
//            if (zombieLeader->GetGroup() == NULL)
//                return true;
//            if (!playerGroup)
//                return true;
//
//            const Group::MemberSlotList members = playerGroup->GetMemberSlots();
//            for (Group::member_citerator itr = members.begin(); itr != members.end(); ++itr)
//            {
//                Player* GroupMember = (ObjectAccessor::GetPlayer(*me, itr->guid));
//                if (GroupMember && GroupMember->GetSession())
//                {
//                    if (!GroupMember)
//                        continue;
//                    //    GroupMember->GetSession()->SendAreaTriggerMessage(message);
//                }
//            }
//            return true;
//        }
//
//        void reviveAndTeleportOut()
//        {
//            if (!zombieLeader || zombieLeader == NULL)
//            {
//                teleportPlayersOut();
//                return;
//            }
//
//            if (!zombieLeader->GetGroup())
//            {
//                teleportPlayersOut();
//                return;
//            }
//            if (zombieLeader->GetGroup() == NULL)
//            {
//                teleportPlayersOut();
//                return;
//            }
//            if (!playerGroup)
//            {
//                teleportPlayersOut();
//                return;
//            }
//
//            if (playerGroup) {
//                const Group::MemberSlotList members = playerGroup->GetMemberSlots();
//                for (Group::member_citerator itr = members.begin(); itr != members.end(); ++itr)
//                {
//                    Player* GroupMember = (ObjectAccessor::GetPlayer(*me, itr->guid));
//                    if (GroupMember && GroupMember->GetSession())
//                    {
//                        if (!GroupMember->IsWithinDistInMap(me, 100))
//                        {
//                            if (GroupMember->isDead())
//                                GroupMember->ResurrectPlayer(60, false);
//                            GroupMember->TeleportTo(534, 5541.770020f, -3783.469971f, 1594.910034f, 2.883010f);
//                        }
//                    }
//                }
//            }
//        }
//
//        bool teleportPlayersOut()
//        {
//            // sLog->outError("teleportPlrsOut");
//            while (me->SelectNearestPlayer(280.0f) != NULL)
//            {
//                Player* plr = me->SelectNearestPlayer(280.0f);
//                if (plr)
//                {
//                    plr->ResurrectPlayer(60, false);
//                    plr->TeleportTo(534, 5541.770020f, -3783.469971f, 1594.910034f, 2.883010f);
//                }
//            }
//            return true;
//        }
//
//        void spawnZombies(Creature* creature, uint32 count)
//        {
//            zombiesSpawned = zombiesSpawned + count;
//            for (uint32 i = 1; i <= count; i++) {
//                // ACE_Based::Thread::Sleep(10);
//                uint32 NPC_ID = rand() % 6 + 1;
//                switch ((rand() % 6 + 1))
//                {
//                case 1:
//                    creature->SummonCreature(ZOMBIE_NPCS[NPC_ID], Spawn_C1);
//                    break;
//                case 2:
//                    creature->SummonCreature(ZOMBIE_NPCS[NPC_ID], Spawn_C2);
//                    break;
//                case 3:
//                    creature->SummonCreature(ZOMBIE_NPCS[NPC_ID], Spawn_C3);
//                    break;
//                case 4:
//                    creature->SummonCreature(ZOMBIE_NPCS[NPC_ID], Spawn_C4);
//                    break;
//                case 5:
//                    creature->SummonCreature(ZOMBIE_NPCS[NPC_ID], Spawn_C5);
//                    break;
//                case 6:
//                    creature->SummonCreature(ZOMBIE_NPCS[NPC_ID], Spawn_C6);
//                    break;
//                    //   default: sLog->outError("spawn default");break;
//                }
//            }
//        }
//
//        int getZombieSpawnCountPerWave()
//        {
//            return ((zombieGroupMembers * ZOMBIES_PER_PERSON) - 1) / zombieWaves + 1;
//        }
//
//        int getNumberOfWaves()
//        {
//            if (zombieRound <= 3)
//                return 3;
//            if (zombieRound > 4 && zombieRound <= 8)
//                return 4;
//            if (zombieRound > 8 && zombieRound <= 12)
//                return 5;
//            if (zombieRound > 12 && zombieRound <= 18)
//                return 6;
//            if (zombieRound > 18 && zombieRound < 50)
//                return 7;
//            return 3;
//        }
//
//        int getZombieSpawnCount(Creature* creature)
//        {
//            return ((zombieGroupMembers * ZOMBIES_PER_PERSON) - 1) / 3 + 1;
//
//        }
//
//        bool spawnGoDrop(Creature* creature)
//        {
//            switch (zombieRound)
//            {
//            case 1: creature->SummonCreature(510000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 2: creature->SummonCreature(510000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 3: creature->SummonCreature(520000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 4: creature->SummonCreature(520000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 5: creature->SummonCreature(530000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 6: creature->SummonCreature(530000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 7: creature->SummonCreature(540000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 8: creature->SummonCreature(540000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 9: creature->SummonCreature(550000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 10: creature->SummonCreature(550000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 11: creature->SummonCreature(560000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 12: creature->SummonCreature(560000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 13: creature->SummonCreature(560000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 14: creature->SummonCreature(560000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            case 15: creature->SummonCreature(560000, -10970.494141f, -2001.188354f, 79.973495f, 1.433620f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90 * 1000); break;
//            }
//
//            creature->SummonCreature(NPC_WAIT_FOR_CHEST_LOOT, -10989.9003f, -1940.1300f, 93.9107f, 4.8345f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 100 * 1000);
//            return true;
//        }
//
//        bool isRoundOver()
//        {
//            if ((zombiesSpawned - zombieDeathCount) <= 0) {
//                zombiesSpawned = 0;
//                zombieDeathCount = 0;
//                return true;
//            }
//
//            return false;
//        }
//
//        bool resetZombieEvent()
//        {
//            zombieCount = 0;
//            zombiesSpawned = 0;
//            zombieDeathCount = 0;
//            zombieRound = 1;
//            zombieWaves = 3;
//            zombieWavesCount = 1;
//            zombieSpawnPerWave = 0;
//            zombieGroupMembers = 0;
//            ZOMBIES_PER_PERSON = 3;
//
//            playerGroup = NULL;
//            zombieLeader = NULL;
//
//            inZombieGame = false;
//            me->UpdatePosition(-10989.9003f, -1940.1300f, 93.9107f, 4.8345f, true);
//            return true;
//        }
//
//        void reviveGroup()
//        {
//            GroupReference* grpRef = playerGroup->GetFirstMember();
//            for (grpRef; grpRef != NULL; grpRef = grpRef->next())
//            {
//                Player* groupMember = grpRef->GetSource();
//                if (!groupMember)
//                    continue;
//
//                if (!groupMember->IsInFlight() && !groupMember->IsFlying())
//                {
//                    if (!groupMember->IsAlive() && groupMember->IsInWorld())
//                    {
//                        if (!groupMember->InBattleground() && !groupMember->InArena())
//                        {
//                            groupMember->ResurrectPlayer(60, false);
//                        }
//                    }
//                    groupMember->TeleportTo(532, -10966.888f, -2011.3127f, 79.98f, 1.37f);
//                }
//            }
//        }
//
//
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new zombie_bg_master_finalAI(creature);
//    }
//};
//
///*
//---------------
//Zombie Creatures AI
//---------------
//*/
//
//class mobs_normal_zombie : public CreatureScript
//{
//public:
//    mobs_normal_zombie() : CreatureScript("mobs_normal_zombie") { }
//
//    struct mobs_normal_zombieAI : public ScriptedAI
//    {
//        mobs_normal_zombieAI(Creature* c) : ScriptedAI(c) {}
//
//        void JustDied(Unit* killer)
//        {
//            //zombieDeathCount++;
//            if (me)
//                me->DespawnOrUnsummon();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new mobs_normal_zombieAI(creature);
//    }
//};
//
//class go_zombie_treasure : public GameObjectScript
//{
//public:
//    go_zombie_treasure() : GameObjectScript("go_zombie_treasure") { }
//
//    bool OnGossipHello(Player* player, GameObject* go)
//    {
//        // sLog->outError("OnGossipHello");
//        // player->SendLoot(go->GetGUID(), LOOT_CORPSE);
//        return true;
//    }
//};
//
//void AddSC_zombie_event()
//{
//    new zombie_bg_master();
//    new zombie_bg_master_endgame();
//    new zombie_bg_master_final();
//    new mobs_normal_zombie();
//    new go_zombie_treasure();
//}
