//From:https://uiwow.com/thread-3869-1-2.html?_dsign=392e0202
//此套源码来自devcore的 javscore开服玩家驻地系统,非同与一般的残缺版，这是完整的玩家驻地系统(只是作者介绍,本文中更是残缺中残缺)
//基本实现游戏中全UI，可视化编辑驻地的项目，包含安装gameobject, 创建NPC管理等等

{
    GAMEOBJECT_SPAWN_LIMIT = 20,
    NPC_SPAWN_LIMIT = 10,

    SAY_NOT_INTERESTED = -1999922,
    SAY_WRONG = -1999923,
    SAY_ CORRECT = -1999924,

    ITEM_1 = 183779,
    ITEM_2 = 26990,
    ITEM_3 = 184140,
    ITEM_4 = 181087，
    ITEM_5 = 1594,
    ITEM_6 = 153584,
    ITEM_7 = 176210,
    ITEM_8 = 85004,
    ITEM_9 = 184284,
    ITEM_10 = 182070,
    ITEM_11 = 170592，
    ITEM_12 = 180376,
    ITEM_13 = 180379，
    ITEM_14 = 180377，

    NPC_1 = 481851，
    NPC_2 = 18885,
    NPC_3 = 18886,
    NPC_4 = 50071,
    NPC_5 = 50070,
    NPC_6 = 50170,
    NPC_7 = 50027,
    NPC_8 = 26303,
    NPC_9 = 50040，
    NPC_10 = 985000,
    NPC_11 = 32666,
    NPC_12 = 50000,

        //PACKAGE 1 GOBJS and NPCs
        P1_ITEM 1 = 179481,
        P1_ITEM 2 = 179483,
        P1_ITEM 3 = 183036,
        P1_ITEM 4 = 183516,
        P1_ITEM 5 = 184998,

        P1_NPC_1 = 50073,
        P1_NPC_2 = 1459,
        P1_NPC_3 = 24181,
        P1_NPC_4 = 985001,
        P1_NPC_5 = 70015,

        //PACKAGE 2 GOBJS and NPCs
        P2_ITEM_1 = 182774,
        P2_ITEM_2 = 186729,
        P2_ITEM_3 = 187294,
        P2_ITEM_4 = 164882,
        P2_ITEM_5 = 180876,

        P2_NPC_1 = 13,
        P2_NPC_2 = 50014,
        P2_NPC_3 = 66667,
        P2_NPC_4 = 500256,



        //图片2,以下未校对
        //BUY PACKAGE
case GOSSIP_ ACTION INFO_ DEF + 1:
    player->PlayerTalkClass->ClearMenu9();
    if (!hasPackage(AccID, 1))
        player->ADD_ GOSSIP_ ITEM(GOSSIP_ ICON_ VENDOR，PACKAGE_ 1，GOSSIP_ SENDER_ MAIN， GOSSIP_ ACTION_ INFO DEF + 10) :
        if (!hasPackage(AccID, 2))
            player->ADD_ GOSSIP_ ITEM(GOSSIP_ ICON VENDOR，PACKAGE_ _2, GOSSIP_ SENDER_ MAIN, GOSSIP_ ACTION_ INFO_ _DEF + 11);
    if (!hasPackage(AccID，3))
        player->ADD_ GOSSIP_ ITEM(GOSSIP_ ICON_ _VENDOR，PACKAGE_ 3, GOSSIP_ SENDER_ MAIN, GOSSIP_ ACTION_ INFO_ DEF + 12);
    if (!hasPackage(AccID，41)
        player->ADD_ GOSSIP_ ITEM(GOSSIP_ ICON_ VENDOR，PACKAGE_ 4, GOSSIP_ SENDER_ MAIN, GOSSIP_ ACTION_ INFO_ _DEF + 130);
        player->SaveReca1lPosit1on();
        player->P1ayerTalkC1a33->SendGossipMenu11111，creature->GetGUID());
    break;
    //BUY NPC PACKAGE
case GOSSIP_ ACTION_ _INFO_ DEE + 2: .
    ChatHandler(player->GetSession()).PSendSysMessage("Th1s teature 13 not avallable yet!");
    player->PlayerTalkClass->SendCloseGogsip() :
        break;
    //+10 NeC SPANN
case GOSSIP_ ACTION INFO_ DEE + 3:
    if (player->HaaItemCount(HOUSE_ TOKEN, npcb, true)) {
        player->DestroyItemCount(HOUSE_ TOKEN, npcb， true);
        CharacterDatabase.PExecute("UPDATE player_ house sET npcs_ bonus - npcs_ _bonus + 10 WHERE player_ guid-tu", player->GetGUID());
        ChatHandler(player->GetSession()).PSendSyaMessage("You can now add 10 more NPC'g!");
        ; else
            ChatHandler(player->GetSession()).PSendSysMessage("You do not have enough House Tokeng to purchase this package!");
        player->PlayerTa1kC1a9s->SendCloseGosgip();
        break;
        //+10 GO SPAWN
case GOSSIP_ ACTION INFO DEE + 4: .
    if (player->HasItemCount(HOUSE_ IOKEN，gob,
        true)) {
        player->DestroyItemCount(HOUSE_ TOKEN，gob, true);
        CharacterDatabase.PExecute("UPDATE player_ house SET items_ bonus = items_ bonus + 10 WHERE player_ guid=号u", player->GetGUID());
        ChatHandler(player->GetSession()).PSendSysMessage("You can now add 10 more GameObjects! !");
    }
    else.
        ChatHandler(player->GetSession()).PSendSysMessage("You do not have enough House Tokens to purchase this package!");
    player->PlayerTalkClass->SendCloseGossip();
    break;
case GOSSIP_ ACIION_ INFO_ DEF + 10:
    player->PlayerIalkClasg->ClearMenus();
    player - > ADD_ GOSSIP_ ITEM(GOSSIP_ ICON_ VENDOR，"Buy Package #1 (15 Tokens)", GOSSIP_ SENDER_ MAIN，GOSSIP_ ACTION_ INFO_ DEF + 13);
    player->ADD GOSSIP_ ITEM(GOSSIP_ ICON_ VENDOR，"Preview Package #1"， GOSSIP_ SENDER_ MAIN, GOSSIP_ ACTION_ INEO_ DEE + 16);
    player->P1ayerTa1kClas3->SendGossipMenu11111, creature->GetGUID();
    break.;
case GOSSIP_ ACTION_ INFO_ DEF + 11:
    player->Playerta1kclass->ClarMenus()
        player->ADD_ GOSSIP_ ITEM(GOSSIP_ ICON VENDOR，"Buy Package #2 (15 Tokens)", GOSSIP_ SENDER_ MAIN, GOSSIP_ ACTION INEO_ DEF + 14);
    player->ADD_ _GOSSIP_ ITEM(GOSSIP_ ICON_ VENDOR, "Preview Package *2", GOSSIP_ SENDER_ MAIN，GOSSIP_ ACTION_ INFO_ _DEF + 17) :
        player->PlayerTalkClass->SendGossipMenu(11111, creature->GetGUID());
    break;
case GOSSIP_ ACTION_ INFO_ _DEF + 12:
    player->PlayerTalkClass->ClearMenus();

    //图片3

    PM MOUNT_ ITEM 1 - 65128.
        PM MOUNT_ ITEM 2 = 65129,
        PM_ MOUNT_ ITEM 3 = 65130,
        PM MOUNT_ ITEM 4 = 65131,
        PM MOUNT ITEM 5 - 65132
        PM MOUNT_ ITEM 6 = 93025,
        PM_ MOUNT_ ITEM 7 = 93026,
        PM_ MOUNT ITEM
        = 93027，
        PM MOUNT_ ITEM 9 = 93054,
        PM_ MOUNT_ ITEM_ 10 = 93061,
        M_ MOUNT_ ITEM_ 11 - 93065,
        PVP_ TICKET_ ID = 19182，
        PVP_ TICKET COST = 50,
        ARENA TEAM COST - 1500,
        BROREN SOUL_ ID - 29438,
        BROKEN_ SOUL_ COST = 1500
        enum PMGossipMenuOptions
        OPTION_ BUY_ 1 = GOSSIP_ ACTION_ INFO_ DEF + 22,
        OPTION_ BUY_ 2_ HK = GOSSIP_ ACTION_ INFO_ DEF + 23,
        OPTION_ BUY_ 2 DP = GOSSIP_ ACTION_ INFO DEF + 24,
        OPTION_ BUY_ 2_ VP - GOSSIP_ ACTION INFO_ DEF + 25,
        OPTION_ BUY_ 3_ PVP = GOSIP_ ACTION_ INFO_ DEF + 26,
        OPIION BUY_ 3_ DP = GOSSIP_ ACTION INFO DEF + 27,
        OPTION_ BUY_ 3 VP = GOSSIP_ ACTION_ INFO_ DEF + 28,
        OPTION BUY_ 4 HK - GOSSIP_ ACTION_ INFO DEE + 29，
        OPTION_ BUY_ 4_ _DP = GOSSIP_ ACTION_ INFO_ DEF + 30,
        OPTION_ BUY_ 4 VE = GOSSIP_ ACTION_ INFO_ DEE + 31,
        OPTION_ BUY_ _5_ ARENA = GOSSIP_ ACTION INFO_ DEE + 32,
        OPTION_ BUY 5 DP - GOSSIP_ ACTION_ INEO DEF + 33,
        OPTION_ BUY_ 5_ VP - GOSSIP_ ACTION INFO_ DEF + 34,
        OPIION_ BUY_ 6 = GOSSIP_ ACTION_ INFO DEF + 35,
        OPTION_ BUY_ 6_ DP = GOSSIP_ ACTION_ INFO DEF + 36,
        OPTION_ BUY_ 6 VP - GOSSIP_ ACTION INFO_ DEF + 37,
        OPTION_ BUY_ 7 = GOSSIP_ ACTION_ INFO_ DEF + 38,
        OPTION_ BUY_ 7_ _DP = GOSSIP_ ACTION_ INFO_ DEF + 39,
        OPTION BUY_ 7 VP = GOSSIP_ ACTION INFO DEF + 40,
        OPTION_ BUY_ 8 - GOSSIP_ ACTION_ INFO_ DEF + 41,
        OPTION_ BUY_ 8_ DP - GOSSIP_ ACTION INFO_ DEF + 42,
        OPTION_ BUY_ 8 VE = GOSSIP_ ACTION_ INFO_ DEE + 43,

        OPTION_ BUY_ 9 = GOSSIP_ ACTION_ INFO DEF + 44.
        OPTION BUY_ 9_ DP - GOSSIP_ ACTION INEO DEF + 45,
        OPTION BUY 9 VP = GOSSIP ACTION_ INFO DEF + 46,
