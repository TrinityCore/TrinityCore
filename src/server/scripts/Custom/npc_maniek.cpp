#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "WorldPacket.h"

class npc_maniek : public CreatureScript
{
public:
    npc_maniek() : CreatureScript("npc_maniek") { }

    bool OnGossipHello(Player *pPlayer, Creature *pCreature)
    {
        uint8 PlayerTeam = (pPlayer->GetTeam() == ALLIANCE) ? 0 : 1;
        uint32 NPCLevel = pCreature->getLevel(); //80 = horde & allianz, 81 = horde, 82 = allianz
        if ((NPCLevel == 81 && PlayerTeam != 1) || (NPCLevel == 82 && PlayerTeam != 0))
        {
            pCreature->MonsterWhisper("Get out! I offer my services to enemy!", pPlayer->GetGUID());
            return true;
        }

        uint32 PlayerLevel = pPlayer->getLevel();
        uint8 PlayerKlasse = pPlayer->getClass();
        std::string kosten = (PlayerLevel <= 70) ? (PlayerLevel) + " Silver" : (PlayerLevel*10) + " Silver";

        pPlayer->ADD_GOSSIP_ITEM( 10, "Teleports:", GOSSIP_SENDER_MAIN, 6111);
        //pPlayer->ADD_GOSSIP_ITEM( 10, " ", GOSSIP_SENDER_MAIN, 6111);

        if (ALLIANCE == pPlayer->GetTeam())
        {
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Stormwind", GOSSIP_SENDER_MAIN, 6201);
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Ironforge", GOSSIP_SENDER_MAIN, 6202);
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Darnassus", GOSSIP_SENDER_MAIN, 6203);
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Exodar", GOSSIP_SENDER_MAIN, 6204);
        if (PlayerLevel>=68)
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Northrend", GOSSIP_SENDER_MAIN, 6267);
        } else
        {
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Orgrimmar", GOSSIP_SENDER_MAIN, 6211);
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Thunder Bluff", GOSSIP_SENDER_MAIN, 6212);
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Undercity", GOSSIP_SENDER_MAIN, 6213);
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Silvermoon City", GOSSIP_SENDER_MAIN, 6214);
        if (PlayerLevel>=68)
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Northrend", GOSSIP_SENDER_MAIN, 6268);
        }
        if (pPlayer->getClass()==6)
        {
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Acherus The Ebon Hold", GOSSIP_SENDER_MAIN, 6207);
        }
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Astranaar", GOSSIP_SENDER_MAIN, 6266);
        if (PlayerLevel>=30)
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Gurubashi Arena", GOSSIP_SENDER_MAIN, 6200);
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Gadgetzan", GOSSIP_SENDER_MAIN, 6269);
        if (PlayerLevel>=58)
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Shattrath", GOSSIP_SENDER_MAIN, 6208);
        if (PlayerLevel>=65)
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Isle of Quel'Danas", GOSSIP_SENDER_MAIN, 6209);
        if (PlayerLevel>=70)
            pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport to Dalaran", GOSSIP_SENDER_MAIN, 6210);

        //if (ALLIANCE == pPlayer->GetTeam())
        //    pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport zum Azshara Krater (Allianz)", GOSSIP_SENDER_MAIN, 6402);
        //else
        //    pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport zum Azshara Krater (Horde)", GOSSIP_SENDER_MAIN, 6401);

        //pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport zum Playertreff", GOSSIP_SENDER_MAIN, 6403);
        //pPlayer->ADD_GOSSIP_ITEM( 5, "Teleport zur Rennbahn", GOSSIP_SENDER_MAIN, 6550);

        pPlayer->PlayerTalkClass->SendGossipMenu(2713,pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player *pPlayer, Creature *pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        switch (uiAction) {
            case 6200: custom_porter_port(0, -13234.1f, 217.387f, 31.6759f, 1.06815f, pPlayer, pCreature); break; //guru
            case 6201: custom_porter_port(0, -8908.96f, 556.3f, 93.5345f, 0.73f, pPlayer, pCreature); break; //stormwind
            case 6202: custom_porter_port(0, -4821.6f, -1155.58f, 502.2345f, 3.33532f, pPlayer, pCreature); break; //eisenschmiede
            case 6203: custom_porter_port(1, 9947.53f, 2604.15f, 1316.19f, 4.223f, pPlayer, pCreature); break; //darnassus
            case 6204: custom_porter_port(530, -4054.75f, -11793.4f, 11.1139f, 1.51503f, pPlayer, pCreature); break; //exodar
            case 6205: custom_porter_port(1, 45.951f, 1218.27f, 146.713f, 0.063138f, pPlayer, pCreature); break; //pt ally
            case 6206: custom_porter_port(609, 2362.29f, -5693.76f, 153.922f, 3.77816f, pPlayer, pCreature); break; //todesbresche
            case 6207: custom_porter_port(609, 2348.74f, -5694.94f, 384.088f, 3.90954f, pPlayer, pCreature); break; //acherus
            case 6208: custom_porter_port(530, -1879.5f, 5409.46f, -12.4277f, 1.0332f, pPlayer, pCreature); break; //shattrath
            case 6209: custom_porter_port(530, 13000.2f, -6907.51f, 12.0f, 1.06815f, pPlayer, pCreature); break; //queldanas
            case 6210: custom_porter_port(571, 5814.2f, 446.337f, 659.201f, 1.41145f, pPlayer, pCreature); break; //dalaran
            case 6211: custom_porter_port(1, 1677.91f, -4314.79f, 62.35f, 2.66969f, pPlayer, pCreature); break; //orgrimmar
            case 6212: custom_porter_port(1, -1197.18f, 29.2706f, 179.755f, 2.9666f, pPlayer, pCreature); break; //donnerfels
            case 6213: custom_porter_port(0, 1568.48f, 268.52f, -42.1384f, 1.69719f, pPlayer, pCreature); break; //unterstadt
            case 6214: custom_porter_port(530, 9373.08f, -7166.07f, 11.4763f, 5.38653f, pPlayer, pCreature); break; //silbermond
            case 6215: custom_porter_port(1, -1790.17f, 3055.44f, 9.35831f, 1.06815f, pPlayer, pCreature); break; //pt horde
            case 6216: custom_porter_port(1, -11846.4f, -4756.91f, 6.25831f, 0.305114f, pPlayer, pCreature); break; //pt highrate
            case 6401: custom_porter_port(37, -30.2515f, 952.13f, 348.4f, 5.49992f, pPlayer, pCreature); break; //krater horde
            case 6402: custom_porter_port(37, 1100.61f, 298.099f, 338.7f, 3.11388f, pPlayer, pCreature); break; //krater ally
            case 6403: custom_porter_port(0, -3964.02f, -1343.13f, 152.9f, 3.14183f, pPlayer, pCreature); break; //new pt
            case 6550: custom_porter_port(0, -7823.80f, -477.402f, 170.8f, 3.031973f, pPlayer, pCreature); break; //dt-renngebiet
            case 6266: custom_porter_port(1, 2730.27f, -368.802f, 108.886f, 4.07746f, pPlayer, pCreature); break; //astranar
            case 6267: custom_porter_port(571, 2213.94f, 5273.14f, 12.1967f, 5.89294f, pPlayer, pCreature); break; //Northrend ALLIANCE
            case 6268: custom_porter_port(571, 2649.82f, -4362.68f, 277.585f, 5.15979f, pPlayer, pCreature); break; //Northrend Horde
            case 6269: custom_porter_port(1, -7155.7f, -3822.1f, 8.43f, 1.06815f, pPlayer, pCreature); break; //dadgetzan
        }

        pPlayer->CLOSE_GOSSIP_MENU();
        return true;
    }

    void custom_porter_port(uint32 a, float b, float c, float d, float e, Player* pPlayer, Creature* pCreature)
    {
        char* temp = "";
        switch (urand(1,7)) {
            case 1: temp = "Have a pleasant journey!"; break;
            case 2: temp = "And again... happy customer..."; break;
            case 3: temp = "An excellent choice!"; break;
            case 4: temp = "Faster than the speed of light!"; break;
            case 5: temp = "Would You recommend us?"; break;
            case 6: temp = "Player? WHAT ARE YOU DOIN'?! STHAP!"; break;
            case 7: temp = "Connection lost......."; break;
        }
        char const* text = temp;

        pCreature->MonsterWhisper(text, pPlayer->GetGUID());

        pPlayer->TeleportTo(a,b,c,d,e);
        return;
    }
};

void AddSC_npc_maniek()
{
    new npc_maniek;
}
