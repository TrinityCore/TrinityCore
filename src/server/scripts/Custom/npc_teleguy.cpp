#include "ScriptPCH.h"
#include "Config.h"

class npc_teleguy : public CreatureScript
{
public:
    npc_teleguy() : CreatureScript("npc_teleguy") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        pCreature->MonsterWhisper("Добро пожаловать в систему 'улучшенный телепортер v1.02'", pPlayer->GetGUID(), false);

        if (pPlayer->GetTeam() == ALLIANCE ) {
            pPlayer->ADD_GOSSIP_ITEM(9, "Исцели меня!"                     , GOSSIP_SENDER_MAIN, 1202);
            pPlayer->ADD_GOSSIP_ITEM(5, "Пиратская Бухта."                 , GOSSIP_SENDER_MAIN, 4035);
            pPlayer->ADD_GOSSIP_ITEM(5, "Дарнасс."                         , GOSSIP_SENDER_MAIN, 1203);
            pPlayer->ADD_GOSSIP_ITEM(5, "Экзодар."                         , GOSSIP_SENDER_MAIN, 1216);
            pPlayer->ADD_GOSSIP_ITEM(5, "Штормград."                       , GOSSIP_SENDER_MAIN, 1206);
            pPlayer->ADD_GOSSIP_ITEM(5, "Стальгорн."                       , GOSSIP_SENDER_MAIN, 1224);
            pPlayer->ADD_GOSSIP_ITEM(5, "Гномреган."                       , GOSSIP_SENDER_MAIN, 1222);
            pPlayer->ADD_GOSSIP_ITEM(5, "Шаттрат."                         , GOSSIP_SENDER_MAIN, 1287);
            pPlayer->ADD_GOSSIP_ITEM(5, "Даларан."                         , GOSSIP_SENDER_MAIN, 1205);
            pPlayer->ADD_GOSSIP_ITEM(5, "Остров Кель'Данас."               , GOSSIP_SENDER_MAIN, 1288);
            if (sConfig->GetIntDefault("RealmID", 0) == 5)
            {
                pPlayer->ADD_GOSSIP_ITEM(5, "Стартовая локация."           , GOSSIP_SENDER_MAIN, 4039);
                pPlayer->ADD_GOSSIP_ITEM(5, "Арена награнда."              , GOSSIP_SENDER_MAIN, 4040);
            }
            pPlayer->ADD_GOSSIP_ITEM(7, "[Инстансы] ->"                    , GOSSIP_SENDER_MAIN, 5550);
            pPlayer->ADD_GOSSIP_ITEM(7, "[Инстансы WotLK] ->"              , GOSSIP_SENDER_MAIN, 5554);

        }  else {

            pPlayer->ADD_GOSSIP_ITEM(9, "Исцели меня!"                     , GOSSIP_SENDER_MAIN, 1202);
            pPlayer->ADD_GOSSIP_ITEM(5, "Пиратская Бухта."                 , GOSSIP_SENDER_MAIN, 4035);
            pPlayer->ADD_GOSSIP_ITEM(5, "Оргриммар."                       , GOSSIP_SENDER_MAIN, 1215);
            pPlayer->ADD_GOSSIP_ITEM(5, "Луносвет."                        , GOSSIP_SENDER_MAIN, 1217);
            pPlayer->ADD_GOSSIP_ITEM(5, "Подгород."                        , GOSSIP_SENDER_MAIN, 1213);
            pPlayer->ADD_GOSSIP_ITEM(5, "Громовой утёс."                   , GOSSIP_SENDER_MAIN, 1225);
            pPlayer->ADD_GOSSIP_ITEM(5, "Гномреган."                       , GOSSIP_SENDER_MAIN, 1222);
            pPlayer->ADD_GOSSIP_ITEM(5, "Шаттрат."                         , GOSSIP_SENDER_MAIN, 1287);
            pPlayer->ADD_GOSSIP_ITEM(5, "Даларан."                         , GOSSIP_SENDER_MAIN, 1205);
            pPlayer->ADD_GOSSIP_ITEM(5, "Остров Кель'Данас."               , GOSSIP_SENDER_MAIN, 1288);
            if (sConfig->GetIntDefault("RealmID", 0) == 5)
            {
                pPlayer->ADD_GOSSIP_ITEM(5, "Стартовая локация."           , GOSSIP_SENDER_MAIN, 4039);
                pPlayer->ADD_GOSSIP_ITEM(5, "Арена награнда."              , GOSSIP_SENDER_MAIN, 4040);
            }
            pPlayer->ADD_GOSSIP_ITEM(7, "[Инстансы] ->"                    , GOSSIP_SENDER_MAIN, 5550);
            pPlayer->ADD_GOSSIP_ITEM(7, "[Инстансы WotLK] ->"              , GOSSIP_SENDER_MAIN, 5554);
        }

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
            case 5550: //Instances
                pPlayer->ADD_GOSSIP_ITEM(5, "Огненная пропасть."            , GOSSIP_SENDER_MAIN, 1248);
                pPlayer->ADD_GOSSIP_ITEM(5, "Пещеры стенаний."              , GOSSIP_SENDER_MAIN, 1249);
                pPlayer->ADD_GOSSIP_ITEM(5, "Тюрьма."                       , GOSSIP_SENDER_MAIN, 1253);
                pPlayer->ADD_GOSSIP_ITEM(5, "Мертвые копи."                 , GOSSIP_SENDER_MAIN, 1250);
                pPlayer->ADD_GOSSIP_ITEM(5, "Крепость Темного Клыка."       , GOSSIP_SENDER_MAIN, 1251);
                pPlayer->ADD_GOSSIP_ITEM(5, "Непроглядная Пучина."          , GOSSIP_SENDER_MAIN, 1252);
                pPlayer->ADD_GOSSIP_ITEM(5, "Лабиринты Иглошкурых."         , GOSSIP_SENDER_MAIN, 1254);
                pPlayer->ADD_GOSSIP_ITEM(5, "Курганы Иглошкурых."           , GOSSIP_SENDER_MAIN, 1256);
                pPlayer->ADD_GOSSIP_ITEM(5, "Монастырь Алого Ордена."       , GOSSIP_SENDER_MAIN, 1257);
                pPlayer->ADD_GOSSIP_ITEM(5, "Аукиндон."                     , GOSSIP_SENDER_MAIN, 4038);
                pPlayer->ADD_GOSSIP_ITEM(7, "[Ещё] ->"                      , GOSSIP_SENDER_MAIN, 5551);
                pPlayer->ADD_GOSSIP_ITEM(7, "<- [Главное меню]"             , GOSSIP_SENDER_MAIN, 5552);

                pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());

                break;

            case 5551: //More Instances
                pPlayer->ADD_GOSSIP_ITEM(5, "Ульдаман."                  , GOSSIP_SENDER_MAIN, 1258);
                pPlayer->ADD_GOSSIP_ITEM(5, "Зул'Фаррак."                , GOSSIP_SENDER_MAIN, 1259);
                pPlayer->ADD_GOSSIP_ITEM(5, "Мародон."                   , GOSSIP_SENDER_MAIN, 1260);
                pPlayer->ADD_GOSSIP_ITEM(5, "Затонувший храм."           , GOSSIP_SENDER_MAIN, 1261);
                pPlayer->ADD_GOSSIP_ITEM(5, "Глубины Чёрной Горы."       , GOSSIP_SENDER_MAIN, 1262);
                pPlayer->ADD_GOSSIP_ITEM(5, "Забытый Город."             , GOSSIP_SENDER_MAIN, 1263);
                pPlayer->ADD_GOSSIP_ITEM(5, "Пик Чёрной горы."           , GOSSIP_SENDER_MAIN, 1264);
                pPlayer->ADD_GOSSIP_ITEM(5, "Стратхольм."                , GOSSIP_SENDER_MAIN, 1265);
                pPlayer->ADD_GOSSIP_ITEM(5, "Некроситет."                , GOSSIP_SENDER_MAIN, 1266);
                pPlayer->ADD_GOSSIP_ITEM(5, "Ан'кираж."                  , GOSSIP_SENDER_MAIN, 4037);
                pPlayer->ADD_GOSSIP_ITEM(7, "[Ещё] ->"                   , GOSSIP_SENDER_MAIN, 5553);
                pPlayer->ADD_GOSSIP_ITEM(7, "<- [Назад]"                 , GOSSIP_SENDER_MAIN, 5550);
                pPlayer->ADD_GOSSIP_ITEM(7, "<- [Главное меню]"          , GOSSIP_SENDER_MAIN, 5552);

                pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());

                break;

            case 5553: //Instances 60-70
                pPlayer->ADD_GOSSIP_ITEM(5, "Каражан."                   , GOSSIP_SENDER_MAIN, 4007);
                pPlayer->ADD_GOSSIP_ITEM(5, "Логово Груула."             , GOSSIP_SENDER_MAIN, 4008);
                pPlayer->ADD_GOSSIP_ITEM(5, "Цитадель Адского Пламени."  , GOSSIP_SENDER_MAIN, 4009);
                pPlayer->ADD_GOSSIP_ITEM(5, "Резервуар Кривого Клыка."   , GOSSIP_SENDER_MAIN, 4010);
                pPlayer->ADD_GOSSIP_ITEM(5, "Крепость Бурь."             , GOSSIP_SENDER_MAIN, 4011);
                pPlayer->ADD_GOSSIP_ITEM(5, "Пещеры Времени."            , GOSSIP_SENDER_MAIN, 4012);
                pPlayer->ADD_GOSSIP_ITEM(5, "Зул'Аман."                  , GOSSIP_SENDER_MAIN, 4016);
                pPlayer->ADD_GOSSIP_ITEM(5, "Зул'Гуруб."                 , GOSSIP_SENDER_MAIN, 4034);
                pPlayer->ADD_GOSSIP_ITEM(5, "Чёрный Храм."               , GOSSIP_SENDER_MAIN, 4013);
                pPlayer->ADD_GOSSIP_ITEM(5, "Террасса Магистров."        , GOSSIP_SENDER_MAIN, 4017);
                pPlayer->ADD_GOSSIP_ITEM(5, "Плато Солнечного Колодца."  , GOSSIP_SENDER_MAIN, 4018);
                pPlayer->ADD_GOSSIP_ITEM(7, "<- [Назад]"                 , GOSSIP_SENDER_MAIN, 5550);
                pPlayer->ADD_GOSSIP_ITEM(7, "<- [Главное меню]"          , GOSSIP_SENDER_MAIN, 5552);


                pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());

                break;

            case 5554: //Instances 75-80 NORTHREND
                pPlayer->ADD_GOSSIP_ITEM(5, "Крепость Утгард."                        , GOSSIP_SENDER_MAIN, 4019);
                pPlayer->ADD_GOSSIP_ITEM(5, "Нексус."                                 , GOSSIP_SENDER_MAIN, 4020);
                pPlayer->ADD_GOSSIP_ITEM(5, "Азжол-Неруб."                            , GOSSIP_SENDER_MAIN, 4021);
                pPlayer->ADD_GOSSIP_ITEM(5, "Ан'кахет: Старое Королевство."           , GOSSIP_SENDER_MAIN, 4022);
                pPlayer->ADD_GOSSIP_ITEM(5, "Крепость Драк'Тарон."                    , GOSSIP_SENDER_MAIN, 4023);
                pPlayer->ADD_GOSSIP_ITEM(5, "Аметистовая Цитадель."                   , GOSSIP_SENDER_MAIN, 4024);
                pPlayer->ADD_GOSSIP_ITEM(5, "Гун'Драк."                               , GOSSIP_SENDER_MAIN, 4025);
                pPlayer->ADD_GOSSIP_ITEM(5, "Вершина Утгард."                         , GOSSIP_SENDER_MAIN, 4026);
                pPlayer->ADD_GOSSIP_ITEM(5, "Ульдуар."                                , GOSSIP_SENDER_MAIN, 4027);
                pPlayer->ADD_GOSSIP_ITEM(7, "[Ещё] ->"                                , GOSSIP_SENDER_MAIN, 5555);
                pPlayer->ADD_GOSSIP_ITEM(7, "<- [Назад]"                              , GOSSIP_SENDER_MAIN, 5550);
                pPlayer->ADD_GOSSIP_ITEM(7, "<- [Главное меню]"                       , GOSSIP_SENDER_MAIN, 5552);


                pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());

                break;

            case 5555: //Instances 75-80 NORTHREND more
                pPlayer->ADD_GOSSIP_ITEM(5, "Обсидиановое святилище."                , GOSSIP_SENDER_MAIN, 4028);
                pPlayer->ADD_GOSSIP_ITEM(5, "Наксрамас."                             , GOSSIP_SENDER_MAIN, 4029);
                pPlayer->ADD_GOSSIP_ITEM(5, "Колизей Серебрянного Авангарда."        , GOSSIP_SENDER_MAIN, 4032);
                pPlayer->ADD_GOSSIP_ITEM(5, "Склеп Аркавона."                        , GOSSIP_SENDER_MAIN, 4030);
                pPlayer->ADD_GOSSIP_ITEM(5, "Ледяная Корона: Рейд."                  , GOSSIP_SENDER_MAIN, 4031);
                pPlayer->ADD_GOSSIP_ITEM(5, "Ледяная Корона: Ледяные Залы."          , GOSSIP_SENDER_MAIN, 4033);
                pPlayer->ADD_GOSSIP_ITEM(5, "Логово Ониксии."                        , GOSSIP_SENDER_MAIN, 4036);
                pPlayer->ADD_GOSSIP_ITEM(7, "<- [Назад]"                             , GOSSIP_SENDER_MAIN, 5554);
                pPlayer->ADD_GOSSIP_ITEM(7, "<- [Главное меню]"                      , GOSSIP_SENDER_MAIN, 5552);


                pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());

                break;

            case 5552: //Back To Main Menu
                if (pPlayer->GetTeam() == ALLIANCE ) {
                    pPlayer->ADD_GOSSIP_ITEM(9, "Исцели меня!"                           , GOSSIP_SENDER_MAIN, 1202);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Пиратская Бухта."                       , GOSSIP_SENDER_MAIN, 4035);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Дарнасс."                               , GOSSIP_SENDER_MAIN, 1203);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Экзодар."                               , GOSSIP_SENDER_MAIN, 1216);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Штормград."                             , GOSSIP_SENDER_MAIN, 1206);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Стальгорн."                             , GOSSIP_SENDER_MAIN, 1224);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Гномреган."                             , GOSSIP_SENDER_MAIN, 1222);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Шаттрат."                               , GOSSIP_SENDER_MAIN, 1287);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Даларан."                               , GOSSIP_SENDER_MAIN, 1205);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Остров Кель'Данас."                     , GOSSIP_SENDER_MAIN, 1288);
                    if (sConfig->GetIntDefault("RealmID", 0) == 5)
                    {
                        pPlayer->ADD_GOSSIP_ITEM(5, "Стартовая локация."                 , GOSSIP_SENDER_MAIN, 4039);
                        pPlayer->ADD_GOSSIP_ITEM(5, "Арена награнда."                    , GOSSIP_SENDER_MAIN, 4040);
                    }
                    pPlayer->ADD_GOSSIP_ITEM(7, "[Инстансы] ->"                          , GOSSIP_SENDER_MAIN, 5550);
                    pPlayer->ADD_GOSSIP_ITEM(7, "[Инстансы WotLK] ->"                    , GOSSIP_SENDER_MAIN, 5554);

                }  else {

                    pPlayer->ADD_GOSSIP_ITEM(9, "Исцели меня!"                           , GOSSIP_SENDER_MAIN, 1202);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Пиратская Бухта."                       , GOSSIP_SENDER_MAIN, 4035);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Оргриммар."                             , GOSSIP_SENDER_MAIN, 1215);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Луносвет."                              , GOSSIP_SENDER_MAIN, 1217);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Подгород."                              , GOSSIP_SENDER_MAIN, 1213);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Громовой утёс."                         , GOSSIP_SENDER_MAIN, 1225);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Гномреган."                             , GOSSIP_SENDER_MAIN, 1222);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Шаттрат.."                              , GOSSIP_SENDER_MAIN, 1287);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Даларан."                               , GOSSIP_SENDER_MAIN, 1205);
                    pPlayer->ADD_GOSSIP_ITEM(5, "Остров Кель'Данас."                     , GOSSIP_SENDER_MAIN, 1288);
                    if (sConfig->GetIntDefault("RealmID", 0) == 5)
                    {
                        pPlayer->ADD_GOSSIP_ITEM(5, "Стартовая локация."                 , GOSSIP_SENDER_MAIN, 4039);
                        pPlayer->ADD_GOSSIP_ITEM(5, "Арена награнда."                    , GOSSIP_SENDER_MAIN, 4040);
                    }
                    pPlayer->ADD_GOSSIP_ITEM(7, "[Инстансы] ->"                          , GOSSIP_SENDER_MAIN, 5550);
                    pPlayer->ADD_GOSSIP_ITEM(7, "[Инстансы WotLK] ->"                    , GOSSIP_SENDER_MAIN, 5554);
                }

                    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());

                break;

            case 1203: // Teleport to Darnassus
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(1, 9947.52f, 2482.73f, 1316.21f, 0.0f);
                break;

            case 1206: // Teleport to Stormwind
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(0, -8960.14f, 516.266f, 96.3568f, 0.0f);
                break;

            case 1205: // Teleport to Dalaran
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(571, 5804.14f, 624.770f, 647.7670f, 1.64f);
                break;

            case 1213: // Teleport to Undercity
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(0, 1819.71f, 238.79f, 60.5321f, 0.0f);
                break;

            case 1215: // Teleport to Orgrimmar
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(1, 1552.5f, -4420.66f, 8.94802f, 0.0f);
                break;

            case 1216: // Teleport to Exodar
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(530, -4073.03f, -12020.4f, -1.47f, 0.0f);
                break;

            case 1217: // Teleport to Silvermoon
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(530, 9338.74f, -7277.27f, 13.7895f, 0.0f);
                break;

            case 1222: // Teleport to Gnomeregan
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(0, -5163.43f,660.40f,348.28f,4.65f);
                    break;

            case 1224: // Teleport to Ironforge
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(0, -4924.07f, -951.95f, 501.55f, 5.40f);
                break;

            case 1225: // Teleport to Thunder Bluff
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(1, -1280.19f,127.21f,131.35f,5.16f); 
                break;

            case 1248: // Teleport Player to Ragefire Chasm
                if( pPlayer->getLevel() >= 8)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(1, 1800.53f,-4394.68f,-17.93f,5.49f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 8!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1249: // Teleport to the Wailing Caverns
                if (pPlayer->getLevel() >= 10)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(1, -722.53f,-2226.30f,16.94f,2.71f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 10!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1250: // Teleport to the Deadmines
                if (pPlayer->getLevel() >= 10)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, -11212.04f,1658.58f,25.67f,1.45f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 10!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1251: // Teleport to Shadowfang Keep
                if (pPlayer->getLevel() >= 15)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, -254.47f,1524.68f,76.89f,1.56f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 15!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1252: // Teleport to Blackfathom Deeps
                if (pPlayer->getLevel() >= 15)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(1, 4254.58f,664.74f,-29.04f,1.97f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 15!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1253: // Teleport to the Stockade
                if (pPlayer->getLevel() >= 20)  
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, -8769.76f,813.08f,97.63f,2.26f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 20!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1254: // Teleport to Razorfen Kraul
                if (pPlayer->getLevel() >= 24)    
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(1, -4484.04f,-1739.40f,86.47f,1.23f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 24!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1255: // Teleport to Gnomeregan
                if (pPlayer->getLevel() >= 20)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, -5162.62f,667.81f,248.05f,1.48f);   
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 20!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1256: // Teleport to Razorfen Downs
                if (pPlayer->getLevel() >= 25)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(1, -4645.08f,-2470.85f,85.53f,4.39f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 25!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1257: // Teleport to the Scarlet Monastery
                if (pPlayer->getLevel() >= 25)   
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, 2843.89f,-693.74f,139.32f,5.11f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 25!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1258://Teleport to Uldaman
                if (pPlayer->getLevel() >= 35)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, -6119.70f,-2957.30f,204.11f,0.03f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 35!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1259: // Teleport to Zul'Farrak
                if (pPlayer->getLevel() >= 35)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(1, -6839.39f,-2911.03f,8.87f,0.41f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 35!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1260: // Teleport to Maraudon
                if (pPlayer->getLevel() >= 40)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(1, -1433.33f,2955.34f,96.21f,4.82f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 40!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1261: // Teleport to the Sunken Temple
                if (pPlayer->getLevel() >= 45)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, -10346.92f,-3851.90f,-43.41f,6.09f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 45!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1262: // Teleport to Blackrock Depths
                if (pPlayer->getLevel() >= 45)     
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, -7301.03f,-913.19f,165.37f,0.08f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 45!", LANG_UNIVERSAL, NULL);
                }
                    break;

            case 1263: // Teleport to Dire Maul
                if (pPlayer->getLevel() >= 50)       
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(1, -3982.47f,1127.79f,161.02f,0.05f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 50!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1264: // Teleport to Blackrock Spire
                if (pPlayer->getLevel() >= 50)    
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(0, -7535.43f,-1212.04f,285.45f,5.29f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 50!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1265: // Teleport to Stratholme
                if (pPlayer->getLevel() >= 50)     
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, 3263.54f,-3379.46f,143.59f,0.00f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 50!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1266: // Teleport to Scholomance
                if (pPlayer->getLevel() >= 50)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, 1219.01f,-2604.66f,85.61f,0.50f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 50!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1287:// Shattrath City
                if( pPlayer->getLevel() >= 58)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, -1850.209961f, 5435.821777f, -10.961435f, 3.403913f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 58!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 1288: // Teleport to Isle Of Quel'Danas
                if (pPlayer->getLevel() >= 65)    
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, 12947.4f,-6893.31f,5.68398f,3.09154f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 65!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4007: // Karazhan
                if (pPlayer->getLevel() >= 70)   
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, -11118.8f, -2010.84f, 47.0807f, 0.0f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4008: // Gruul's Lair
                if (pPlayer->getLevel() >= 65)    
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, 3539.007568f, 5082.357910f, 1.691071f, 0.0f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 65!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4009: // Hellfire Citadel
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(530, -305.816223f, 3056.401611f, -2.473183f, 2.01f);
                break;

            case 4010: // Coilfang Reservoir
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(530, 517.288025f, 6976.279785f, 32.007198f, 0.0f);
                break;

            case 4011: // Tempest Keep
                if (pPlayer->getLevel() >= 70)   
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, 3089.579346f, 1399.046509f, 187.653458f, 4.794070f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4012: // Caverns of Time
                if (pPlayer->getLevel() >= 66)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(1, -8173.66f, -4746.36f, 33.8423f, 4.93989f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 66!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4016: // Zul'Aman
                if (pPlayer->getLevel() >= 70)  
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, 6846.95f, -7954.5f, 170.028f, 4.61501f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4013: // Black Temple
                if (pPlayer->getLevel() >= 70)   
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, -3610.719482f, 324.987579f, 37.400028f, 3.282981f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4017: // magistrate
                if (pPlayer->getLevel() >= 70)   
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, 12884.6f, -7317.69f, 65.5023f, 4.799f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4018: // Sunwell
                if (pPlayer->getLevel() >= 70)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, 12574.1f, -6774.81f, 15.0904f, 3.13788f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4019:// Utgarde Keep
                if (pPlayer->getLevel() >= 70)    
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 1219.720f, -4865.28f, 41.25f, 0.31f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4020: // The Nexus
                if (pPlayer->getLevel() >= 70)  
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 3776.950f, 6953.80f, 105.05f, 0.345f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4021: // Azjol-Nerub
                if (pPlayer->getLevel() >= 70)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 3675.430f, 2169.00f, 35.90f, 2.29f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4022: // Ahn'kahet: The Old Kingdom
                if (pPlayer->getLevel() >= 70)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 3646.760f, 2045.17f, 1.79f, 4.37f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4023: // Drak'Tharon Keep
                if (pPlayer->getLevel() >= 70)   
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 4450.860f, -2045.25f, 162.83f, 0.00f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4024: // The Violet Hold
                if (pPlayer->getLevel() >= 70)    
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 5679.820f, 486.80f, 652.40f, 4.08f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4025: // Gun' Drak
                if (pPlayer->getLevel() >= 70)    
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 6937.540f, -4455.98f, 450.68f, 1.00f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4026: // Utgarde Pinnacle
                if (pPlayer->getLevel() >= 70) 
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 1245.690f, -4856.59f, 216.86f, 3.45f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4027: // Ulduar
                if (pPlayer->getLevel() >= 70) 
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 8976.240f, -1281.33f, 1059.01f, 0.58f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4028: // The Obsidian Sanctum
                if (pPlayer->getLevel() >= 70)   
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 3625.780f, 280.40f, -120.14f, 3.25f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4029: // Naxxramas
                if (pPlayer->getLevel() >= 70)       
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 3668.719f, -1262.460f, 243.63f, 5.03f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4030: // Archavon's Valut
                if (pPlayer->getLevel() >= 70)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 5475.506f, 2840.60f, 418.67f, 6.25f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень не должен быть ниже бы уровня 70!", LANG_UNIVERSAL, NULL);
                } 
                break;

            case 1202: // Heal me!
                if (pPlayer->HasAura(45523) )
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Извини, но сейчас я не могу этого сделать, попробуй позже.", LANG_UNIVERSAL, NULL);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->CastSpell(pPlayer, 39321, true);
                    pPlayer->CastSpell(pPlayer, 45523, true);
                }
                break;

            case 4031: // Icecrown Raid
                if (pPlayer->getLevel() >= 70)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 5796.494f, 2075.29f, 636.06f, 3.59f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень не должен быть ниже бы уровня 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4032: // Argent Coliseum
                if (pPlayer->getLevel() >= 70)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 8516.204f, 641.40f, 547.32f, 1.61f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень не должен быть ниже бы уровня 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4033: // Icecrown Daily
                if (pPlayer->getLevel() >= 70)     
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(571, 5631.911f, 2011.72f, 798.26f, 4.59f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 70!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4034: // Zul'Gurub
                if (pPlayer->getLevel() >= 50)     
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, -11916.153f, -1211.612f, 92.28f, 4.68f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 50!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4035: // Booty Bay
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(0, -14290.535f, 548.290f, 8.85f, 4.29f);
                break;

            case 4036: // Onyxia
                if (pPlayer->getLevel() >= 60)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(1, -4712.451f, -3729.173f, 54.21f, 0.56f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 60!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4037: // AQ
                if (pPlayer->getLevel() >= 50)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, -8254.271f, 1536.794f, -4.80f, 5.67f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 50!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4038:
                if (pPlayer->getLevel() >= 50)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(0, -3354.630f, 4930.559f, -99.97f, 0.33f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pCreature->MonsterSay("Ваш уровень должен превышать 50!", LANG_UNIVERSAL, NULL);
                }
                break;

            case 4039: // Start locations
                if (pPlayer->GetTeam() == ALLIANCE)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, -2750.668f, 7313.711f, 43.485f, 2.69f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, -1236.92f, 7144.97f, 57.26f, 4.78f);
                }
                break;

            case 4040: // Nagrand Arena
                if (pPlayer->GetTeam() == ALLIANCE)
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, -2106.58f, 6749.17f, -3.65f, 5.27f);
                }
                else
                {
                    pPlayer->CLOSE_GOSSIP_MENU();
                    pPlayer->TeleportTo(530, -1971.01f, 6541.43f, 12.75f, 2.48f);
                }
                break;
        }

        return true;
    }
};

void AddSC_npc_teleguy()
{
    new npc_teleguy;
}
