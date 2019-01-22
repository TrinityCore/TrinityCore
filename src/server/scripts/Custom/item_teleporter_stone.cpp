/*
* mond wow repack shit
* @Author - Artamedes
*/
#include "ScriptMgr.h"
#include "World.h"
#include "Player.h"
#include "Item.h"
#include "ScriptedGossip.h"
#include "WorldSession.h"
#include "Unit.h"
static const uint32 LOC_OFFSET = 1200;

enum TeleStone
{
	MAIN_MENU = 200000,

	WORLD_TELEPORT, //1
	KALIMDOR,//2
	EASTERN_KINGDOMS,//3
	NORTHREND,//4
	OUTLANDS,//5
	MAELSTROM,//6
	PANDARIA,//7
    DUNGEONS_AND_RAIDS, //8
	VANILLA_DUNGS_AND_RAIDS, //9
	TBC_DUNGS_AND_RAIDS,//10 
	LICH_KING_DUNGS_AND_RAIDS,//11
	CATACLYSM_DUNGS_AND_RAIDS,//12
	ARENAS,//14
	CUSTOM_INSTANCES,//15
	PLAYER_INFO,//16
	VIP_OPTIONS,//17
	VIP_FEATURES,//18
	DUNGEONS,//19
	RAIDS,//20
	WORLD_BOSSES,//21
	PLAYER_OPTIONS,
};

struct TeleportInfo
{
	uint32 mapid;
	float x, y, z, orientation;
};

static const TeleportInfo locations[] =
{
	//      x          y         z      o   map
	{ 530, -2278.14f, 5568.74f, 66.9998f, 5.9990100f }, // Mall
																//Kalimdor 1 - 22
	{ 1, 1928.4f, -2166.0f, 94.0f, 0.2f }, //ashenvale 1
	{ 1, 2897.182f, -4833.0f, 128.5f, 1.7f }, //azshara 2
	{ 530, -3139.08f, -12548.6f, 38.029f, 4.2f }, //azurement isle 3
	{ 530, -1945.0f, -11873.70f, 49.4f, 6.04f }, //Bloodmyst Isle 4
	{ 1, 5767.250f, 298.50f, 20.60f, 6.0f }, //Darkshore 5 
	{ 1, 4102.25f, -1006.789978f, 272.717010f, 0.790048f }, //Felwood 6
	{ 1, 5534.0f, -3622.0f, 1567.0f, 2.0f }, //Mount Hyjal 7
	{ 1, 7654.3f, -2232.870f, 462.10f, 5.960f }, //Moonglade 8
	{ 1, 10111.3f, 1557.729980f, 1324.325806f, 4.042390f }, //Teldrassil  9
	{ 1, 6759.180f, -4419.630f, 763.2139890f, 4.434750f }, //Winterspring 10
	{ 1, 65.558f, -2713.2211f, 91.667f, 0.158f }, //The Barrens  11
	{ 1, -606.395f, 2211.750f, 92.981f, 0.809f }, //Desolace 12
	{ 1, 1007.780029f, -4446.220215f, 11.2022f, 0.20f }, //Durotar 13
	{ 1, -3646.879f, -3847.610f, 4.727f, 6.0868f }, //Dustwallow Marsh 14 
	{ 1, -2184.730f, -732.133484f, -13.645f, 0.487f }, //Mulgore 15 
	{ 1, 1570.920f, 1031.520f, 137.9590f, 3.330f }, //Stonetalon Mountains 16
	{ 1, -4840.42f, 1318.4f, 81.5f, 1.5f }, //Feralas 17
	{ 1, -7426.870f, 1005.309f, 1.135f, 2.960f }, //Silithus 18
	{ 1, -7931.200f, -3414.280029f, 80.736f, 0.665f }, //Tanaris 19
	{ 1, -5126.258f, -1982.943f, 87.866f, 4.168f }, //Thousand Needles 20
	{ 1, -10073.239f, -2697.993f, 9.767f, 2.90f }, //Uldum 21
	{ 1, -7943.20f, -2119.0900f, -218.3450f, 6.072f }, //Un'Goro Crater 22
													   //Eastern Kingdoms 23 - 40
	{ 0, -11182.50f, -3016.669922f, 7.424809f, 4.0004f },  //Blasted Lands 23 
	{ 0, -10438.79980f, -1932.750f, 104.616997f, 4.7740f },  //Deadwind Pass 24
	{ 0, -10904.0f, -364.240f, 39.5f, 3.04f },  //Duskwood 25
	{ 0, -9616.558f, -300.0f, 57.31f, 5.0f },  //Elwynn Forest 26
	{ 0, -8956.39f, -2304.44f, 132.460f, 1.588f },  //Redridge Mts 27 
	{ 0, -12634.480f, -378.139f, 18.886629f, 6.229370f },  //Stranglethorn Vale 28
	{ 0, -10132.4560f, -2471.5668f, 27.5627f, 3.9186f },  //Swamp of Sorrows 29
	{ 0, -10235.200f, 1222.469971f, 43.625f, 0.53f },  //Westfall 30
	{ 0, -6570.355957f, -3235.079102f, 244.407547f, 3.400f },  //Badlands 31
	{ 0, -7622.440f, -1222.197f, 247.272f, 5.169f },  //BlockRock Mountains 32
	{ 0, -8118.540f, -1633.83f, 132.9960f, 0.0890f },  //Burning Steppes 33
	{ 0, -5444.419f, -656.504f, 394.24f, 6.24f },  //Dun Morogh 34 
	{ 0, -5202.939941f, -2855.179932f, 335.901489f, 0.37f },  //Loch Modan 35
	{ 0, -7007.812988f, -1068.956421f, 241.932938f, 5.39600f },  //Searing Gorge 36 
	{ 0, -3242.810059f, -2469.0400f, 15.922f, 6.039f },  //wetlands 37
	{ 530, 9080.0f, -7193.2299f, 55.60f, 5.95f },  //Eversong Woods 38
	{ 530, 7360.9f, -6803.3f, 44.294201f, 5.836f },  //Ghostlands 39
	{ 530, 12947.40f, -6893.310f, 5.68f, 3.09f },  //Isle of Quel'Danas 40
												   //Outland 41 - 47
	{ 530, 3037.669922f, 5962.859863f, 130.774002f, 1.27530f }, //Blade's Edge Mountains 41
	{ 530, 417.249f, 3159.980f, -87.628f, 0.43f }, //Hellfire 42
	{ 530, -1145.949f, 8182.350f, 3.60f, 6.134f }, //Nagrand 43
	{ 530, 3830.229980f, 3426.50f, 88.614502f, 5.166770f }, //Netherstorm 44
	{ 530, -1955.109f, 4563.6088f, 12.54f, 4.45f }, //Tekkorar 45
	{ 530, -54.8620f, 5813.4399f, 20.60f, 0.08f }, //Zangarmarsh 46
	{ 530, -2746.632568f, 1556.131104f, 36.950989f, 3.7086f }, //Shadowmoon 47
															   //Northrend 48 - 56

	{ 571, 3256.570f, 5278.229980f, 40.80460f, 0.246f }, //borean 48
	{ 571, 4103.3599f, 263.477997f, 50.501900f, 3.093490f }, //dragonblight 49
	{ 571, 7253.640f, 1644.7800f, 433.67993f, 4.834f }, //icecrown 50
	{ 571, 5323.0f, 4942.0f, -133.558517f, 2.1700f }, //sholazar bsasin 51
	{ 571, 5614.674316f, -325.961578f, 154.875900f, 4.212954f }, //crystalsong 52
	{ 571, 5804.998535f, -3453.326172f, 372.397156f, 5.629090f }, // zuldrak 53
	{ 571, 4391.729980f, -3587.919922f, 238.531006f, 3.575260f }, //grizzly hills 54
	{ 571, 1902.1500f, -4883.910f, 171.3630f, 3.115370f }, // howling fjord 55
	{ 571, 7527.140f, -1260.890f, 919.0490f, 2.069600f }, // storm peaks 56

														  //cata 57-59

	{ 646, 915.004f, 503.842f, -49.230f, 0.196f }, //deepholm 57
	{ 0, -4336.856934f, -4162.810547f, 329.128f, 3.06f }, //twilgiht highalnds 58
	{ 861, 1037.712f, 335.423f, 40.963f, 1.2f }, //molten front
	{ 0, -13261.224f, 163.995f, 35.862f, 1.163f }, // GURUBASHI
};

class item_teleporter : public ItemScript
{
public:
	item_teleporter() : ItemScript("item_teleporter") { }

	void TeleportTo(Player* player, uint32 action)
	{
		uint32 idx = action - LOC_OFFSET;
		CloseGossipMenuFor(player);
		player->TeleportTo(locations[idx].mapid, locations[idx].x, locations[idx].y, locations[idx].z, locations[idx].orientation);
	}

	void AddMainMenuGossipItem(Player* _player)
	{
		AddGossipItemFor(_player, 0, "|TInterface\\icons\\inv_qiraj_jewelglyphed:20|tMain Menu", GOSSIP_SENDER_MAIN, 0);
	}

	void OnGossipHello(Player* player, Item* item)
	{

		if (player->isDead())
			player->ResurrectPlayer(1.0f, false);

		AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_zone_hellfirepeninsula_01:20|tMall", GOSSIP_SENDER_MAIN, LOC_OFFSET + 0); //start at 0
		//AddGossipItemFor(player, 0, "|TInterface\\icons\\Inv_misc_map02:20|tWorld Teleport", GOSSIP_SENDER_MAIN, 2); //coded
		AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_zone_silverpine_01:20|tCustom Dungeon", GOSSIP_SENDER_MAIN, 310000);
		//AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_reputation_argentcrusader:20|tSpecial Dungeon", GOSSIP_SENDER_MAIN, 320000);
		//AddGossipItemFor(player, 0, "|TInterface\\icons\\spell_shadow_creepingplague:20|tSuper Instance", GOSSIP_SENDER_MAIN, 330000);
		AddGossipItemFor(player, 0, "|TInterface\\icons\\inv_datacrystal01:20|tWorld Bosses", GOSSIP_SENDER_MAIN, 8);
		AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_bg_getxflags_no_die:20|tArenas", GOSSIP_SENDER_MAIN, 5);
		AddGossipItemFor(player, 0, "|TInterface\\icons\\inv_misc_bag_07_green:20|tBank", GOSSIP_SENDER_MAIN, 6);
		//AddGossipItemFor(player, 0, "|TInterface\\icons\\inv_misc_rune_07:20|tPlayer Info", GOSSIP_SENDER_MAIN, 7);
		AddGossipItemFor(player, 0, "|TInterface\\icons\\ability_druid_forceofnature:20|tOptions", GOSSIP_SENDER_MAIN, 10); 
		
		player->PlayerTalkClass->SendGossipMenu(MAIN_MENU, item->GetGUID());
	}

	bool OnUse(Player* player, Item* item, SpellCastTargets const & /*targets*/) override
	{
		player->PlayerTalkClass->ClearMenus();
		if (!player->IsInCombat())
			OnGossipHello(player, item);
		else
			player->CombatStop(true);
		return true;
	}

	void OnGossipSelect(Player* player, Item* item, uint32 /*sender*/, uint32 action)
	{
		player->PlayerTalkClass->ClearMenus();

		if (action >= LOC_OFFSET && action < LOC_OFFSET + sizeof(locations))
		{
			TeleportTo(player, action);
			return;
		}

		switch (action)
		{
		case 0:
			OnGossipHello(player, item);
			break;

		case 7://player info
		{
			std::ostringstream ss;
			ss << "[|cFFFF0000" << player->GetName() << "|R]" << " Account ID: " << player->GetSession()->GetAccountId() << " VIP Level: ";// << int(player->GetSession()->getVipLevel()); this too
			AddGossipItemFor(player, 0, ss.str().c_str(), GOSSIP_SENDER_MAIN, 7);
			ss.str("");
			ss.clear();
			//ss << "MG: |cFFFF0000" << player->GetCCurrency(MG) << "|R"; 
			AddGossipItemFor(player, 10, ss.str().c_str(), GOSSIP_SENDER_MAIN, 7);
			ss.str("");
			ss.clear();
			//ss << "VP: |cFFFF0000" << player->GetCCurrency(VP) << "|R";
			AddGossipItemFor(player, 10, ss.str().c_str(), GOSSIP_SENDER_MAIN, 7);
			ss.str("");
			ss.clear();
			//ss << "DP: |cFFFF0000" << player->GetCCurrency(DP) << "|R";
			AddGossipItemFor(player, 10, ss.str().c_str(), GOSSIP_SENDER_MAIN, 7);
			ss.str("");
			ss.clear();
			ss << "Latency: |cFFFF0000" << player->GetSession()->GetLatency() << "|R ms";
			AddGossipItemFor(player, 10, ss.str().c_str(), GOSSIP_SENDER_MAIN, 7);
			ss.str("");
			ss.clear();

			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(PLAYER_INFO, item->GetGUID());
		}
		break;
		case 2: //World Teleport
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_zone_kalimdor_01:20|tKalimdor", GOSSIP_SENDER_MAIN, 21);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\Achievement_Zone_EasternKingdoms_01:20|tEastern Kingdoms", GOSSIP_SENDER_MAIN, 22);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_zone_outland_01:20|tOutland", GOSSIP_SENDER_MAIN, 23);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_zone_northrend_01:20|tNorthrend", GOSSIP_SENDER_MAIN, 24);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(WORLD_TELEPORT, item->GetGUID());
			break;
			
			break;
		case 310000: //Custom Dungeon
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_chiefukorzsandscalp:20|tZul'Farrak", GOSSIP_SENDER_MAIN, 310003);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(DUNGEONS_AND_RAIDS, item->GetGUID());
			break;
			break;
		case 320000: //Special Dungeon
					 //	AddGossipItemFor(player, 0, "|TInterface\\icons\\creatureportrait_be_scryingorb_epic:20|t)
				AddMainMenuGossipItem(player);
				player->PlayerTalkClass->SendGossipMenu(DUNGEONS_AND_RAIDS, item->GetGUID());
				break;
				break;
		case 330000: // super instances
					 //	AddGossipItemFor(player, 0 "|TInterface\\icons\\creatureportrait_be_scryingorb_epic:20|t)
					AddMainMenuGossipItem(player);
					player->PlayerTalkClass->SendGossipMenu(DUNGEONS_AND_RAIDS, item->GetGUID());
					break;
		case 3://Dungeons and Raids
			AddGossipItemFor(player, 0, "|TInterface\\icons\\spell_holy_revivechampion:20|tDungeons", GOSSIP_SENDER_MAIN, 31);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\inv_helmet_74:20|tRaids", GOSSIP_SENDER_MAIN, 32);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(DUNGEONS_AND_RAIDS, item->GetGUID());
			break;

		case 310003://Zul'Farrak
			player->TeleportTo(1, -6806.85f, -2890.600f, 8.8868f, 6.257260f);
			break;

		case 881:
			player->TeleportTo(1, 4031.05f, -3054.48999f, 569.973999f, 1.938210f);
			break;

		case 882:
			player->TeleportTo(571, 2871.265381f, 66.218613f, 1.337f, 3.372304f);
			break;

		case 10:
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(PLAYER_OPTIONS, item->GetGUID());
			break;

		case 31://Dungeons
			AddGossipItemFor(player, 0, "|TInterface\\icons\\Achievement_Zone_EasternKingdoms_01:20|tVanilla", GOSSIP_SENDER_MAIN, 311);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_zone_outland_01:20|tThe Burning Crusade", GOSSIP_SENDER_MAIN, 312);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_zone_northrend_01:20|tWrath of the Lich King", GOSSIP_SENDER_MAIN, 313);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:20|tBack", GOSSIP_SENDER_MAIN, 3);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(DUNGEONS, item->GetGUID());
			break;

		case 8://Worldboss
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_svalasorrowgrave:20|tBattle Angel", GOSSIP_SENDER_MAIN, 100000);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_lichking:20|tLich King", GOSSIP_SENDER_MAIN, 100001);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_illidan:20|tIllidan", GOSSIP_SENDER_MAIN, 100002);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(DUNGEONS, item->GetGUID());
			break;

		case 10000://Battle angel
			CloseGossipMenuFor(player);
			player->TeleportTo(0, 745.286f, -4016.07f, 93.4931f, 0.334191f);
			break;


        case 311:
			AddGossipItemFor(player, 0, "|TInterface\\icons\\racial_orc_berserkerstrength:20 |tRagefire Chasm", 1, 99900);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\inv_misc_head_murloc_01:20 |tDeadmines", 1, 99901);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_mutanus_the_devourer:20 |tWailing Caverns", 1, 99902);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\inv_helm_robe_dungeonrobe_c_04:20 |tShadowfang Keep", 1, 99903);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_bazil_akumai:20 |tBlackfathom Deeps", 1, 99904);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_mekgineer thermaplugg:20 |tGnomeregan", 1, 99906);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_charlgarazorflank:20 |tRazorfen Kraul", 1, 99907);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_princesstheradras:20 |tMaraudon", 1, 99908);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\spell_holy_resurrection:20 |tScarlet Monastery", 1, 99912);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_archaedas:20 |tUldaman", 1, 99913);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\ability_warrior_decisivestrike:20 |tDire Maul", 1, 99914);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\spell_holy_senseundead:20 |tScholomance", 1, 99915);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_amnennar_the_coldbringer:20 |tRazorfen Downs", 1, 99917);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\spell_deathknight_armyofthedead:20 |tStratholme", 1, 99919);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_chiefukorzsandscalp:20 |tZul'Farrak", 1, 99920);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_emperordagranthaurissan:20 |tBlackrock Depths", 1, 99921);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_overlord_wyrmthalak:20 |tTemple of Atal'Hakkar", 1, 99922);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_shadeoferanikus:20 |tBlackrock Spire", 1, 99924);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:20|tBack", GOSSIP_SENDER_MAIN, 31);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(DUNGEONS, item->GetGUID());
			break;

		case  99900:
			CloseGossipMenuFor(player);
			player->TeleportTo(389, 0.876914f, -23.6f, -20.458948f, 4.39f);
			break;
		case  99901:
			CloseGossipMenuFor(player);
			player->TeleportTo(36, -16.4f, -383.070f, 61.779999f, 2.526370f);
			break;

		case  99902:
			CloseGossipMenuFor(player);
			player->TeleportTo(43, -158.440994f, 131.600998f, -74.255203f, 5.846850f);
			break;

		case  99903:
			CloseGossipMenuFor(player);
			player->TeleportTo(33, -228.190994f, 2111.409912f, 76.890404f, 1.381951f);
			break;

		case  99904:
			CloseGossipMenuFor(player);
			player->TeleportTo(48, -150.233994f, 106.594002f, -39.77899f, 4.450590f);
			break;


		case  99906:
			CloseGossipMenuFor(player);
			player->TeleportTo(90, -340, 6.68f, -152.850f, 2.625f);
			break;

		case  99907:
			CloseGossipMenuFor(player);
			player->TeleportTo(47, 1943.0f, 1544.630f, 81.996666f, 1.38f);
			break;

		case  99908:
			CloseGossipMenuFor(player);
			player->TeleportTo(349, 752.909973f, -616.5300f, -33.110f, 1.370f);
			break;
		case  99912:
			CloseGossipMenuFor(player);
			player->TeleportTo(0, 2880.742f, -808.762f, 160.332993f, 5.323298f);
			break;
		case  99913:
			CloseGossipMenuFor(player);
			player->TeleportTo(70, -221.603928f, 63.427294f, -46.038364f, 3.117877f);
			break;
		case  99914:
			CloseGossipMenuFor(player);
			player->TeleportTo(429, -201.110f, -328.660f, -2.723914f, 5.22f);
			break;
		case  99915:
			CloseGossipMenuFor(player);
			player->TeleportTo(289, 200.4320f, 92.276497f, 128.442001f, 1.497f);
			break;

		case  99917:
			CloseGossipMenuFor(player);
			player->TeleportTo(129, 2593.680f, 1111.22998f, 50.951801f, 4.712390f);
			break;
		case  99919:
			CloseGossipMenuFor(player);
			player->TeleportTo(329, 3393.175293f, -3380.268066f, 142.717148f, 0.053661f);
			break;
		case  99920:
			CloseGossipMenuFor(player);
			player->TeleportTo(209, 1213.520f, 841.590f, 9.298f, 7.090f);
			break;
		case  99921:
			CloseGossipMenuFor(player);
			player->TeleportTo(230, 458.320f, 26.520f, -70.673f, 4.950f);
			break;
		case  99922:
			CloseGossipMenuFor(player);
			player->TeleportTo(109, -319.239990f, 99.90f, -131.850f, 3.711505f);
			break;
		case  99924:
			CloseGossipMenuFor(player);
			player->TeleportTo(0, -7524.189941f, -1230.130f, 285.7330f, 2.095f);
			break;

		case  312:
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_omartheunscarred_01:20 |tHellfire Citadel", 1, 99925);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_ladyvashj:20 |tCoilfang Reservoir", 1, 99926);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_exarch_maladaar:20 |tAuchindoun", 1, 99927);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_aeonus_01:20 |tCaverns of Time", 1, 99928);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_character_bloodelf_male:20 |tTempest Keep", 1, 99929);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\ability_mount_cockatricemountelite_green:20 |tMagisters' Terrace", 1, 99930);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:20|tBack", GOSSIP_SENDER_MAIN, 31);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(DUNGEONS, item->GetGUID());
			break;
			//Teleports of outland instances.
		case  99925:
			player->TeleportTo(530, -335.308990f, 3126.635742f, -102.765564f, 2.194442f);
			break;
		case  99926:
			player->TeleportTo(530, 735.065979f, 6883.450195f, -66.291298f, 5.891720f);
			break;
		case  99927:
			player->TeleportTo(530, -3323.294922f, 4934.059570f, -100.308395f, 2.184640f);
			break;
		case  99928:
			player->TeleportTo(1, -8488.0f, -4212.0f, -215.0f, 3.978554f);
			break;
		case  99929:
			player->TeleportTo(530, 3098.744629f, 1507.355469f, 190.3f, 4.568055f);
			break;
		case  99930:
			player->TeleportTo(530, 12884.6f, -7317.7f, 65.502296f, 4.7990f);
			break;
			//Northrend
		case  313:
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_utgardekeep:20 |tUtgarde Keep", 1, 99931);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_nexus70_heroic:20 |tThe Nexus", 1, 99932);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_azjollowercity_normal:20 |tAhn'kahet The Old Kingdom", 1, 99933);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_azjoluppercity_normal:20 |tAzjol-Nerub", 1, 99934);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\ability_hunter_pet_devilsaur:20 |tDrak'Tharon Keep", 1, 99935);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_theviolethold_heroic:20 |tThe Violet Hold", 1, 99936);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_gundrak_normal:20 |tGundrak", 1, 99937);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_ulduar77_normal:20 |tHalls of Stone", 1, 99938);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_ulduar80_normal:20 |tHalls of Lightning", 1, 99939);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_nexus80_heroic:20 |tThe Oculus", 1, 99940);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_cotstratholme_heroic:20 |tCulling of Stratholme", 1, 99941);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_utgardepinnacle_normal:20 |tUtgarde Pinnacle", 1, 99942);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\inv_spear_05:20 |tTrial of the Champion", 1, 99943);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_icecrown_forgeofsouls:20 |tForge of Souls", 1, 99944);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_icecrown_pitofsaron:20 |tPit of Saron", 1, 99945);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_icecrown_hallsofreflection:20 |tHalls of Reflection", 1, 99946);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:20|tBack", GOSSIP_SENDER_MAIN, 31);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(DUNGEONS, item->GetGUID());
			break;
		case  99931:
			player->TeleportTo(574, 153.789f, -86.547997f, 12.551f, 0.304f);
			break;
		case  99932:
			player->TeleportTo(571, 3814.865967f, 6968.145508f, 99.356407f, 0.311923f);
			break;
		case  99933:
			player->TeleportTo(619, 342.075043f, -1104.613159f, 61.916801f, 0.572631f);
			break;
		case  99934:
			player->TeleportTo(601, 412.028564f, 786.141357f, 829.196777f, 5.978966f);
			break;
		case  99935:
			player->TeleportTo(600, -517.343018f, -487.976013f, 11.01f, 4.8310f);
			break;
		case  99936:
			player->TeleportTo(608, 1809.214355f, 803.929504f, 44.363998f, 6.282f);
			break;
		case  99937:
			player->TeleportTo(604, 1866.653198f, 628.712952f, 176.668945f, 3.097039f);
			break;
		case  99938:
			player->TeleportTo(599, 1153.239990f, 806.164001f, 195.936996f, 4.715f);
			break;
		case  99939:
			player->TeleportTo(602, 1331.469971f, 259.618988f, 53.397999f, 4.772000f);
			break;
		case  99940:
			player->TeleportTo(578, 1055.930054f, 986.849976f, 361.070007f, 5.745f);
			break;
		case  99941:
			player->TeleportTo(595, 1431.099976f, 556.919983f, 36.689999f, 5.1600f);
			break;
		case  99942:
			player->TeleportTo(574, 164.788025f, -83.097336f, 12.551000f, 0.304000f);
			break;
		case  99943:
			player->TeleportTo(650, 805.226990f, 618.038025f, 412.393005f, 3.1456f);
			break;
		case  99944:
			player->TeleportTo(632, 4922.859f, 2175.629883f, 638.734009f, 2.003550f);
			break;
		case  99945:
			player->TeleportTo(658, 437.883545f, 212.355774f, 528.708862f, 6.256460f);
			break;
		case  99946:
			player->TeleportTo(602, 1331.781738f, 254.395782f, 53.4f, 4.772f);
			break;

		
		case 32://Raids
			AddGossipItemFor(player, 0, "|TInterface\\icons\\Achievement_Zone_EasternKingdoms_01:20|tVanilla", GOSSIP_SENDER_MAIN, 321);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_zone_outland_01:20|tThe Burning Crusade", GOSSIP_SENDER_MAIN, 322);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_zone_northrend_01:20|tWrath of the Lich King", GOSSIP_SENDER_MAIN, 323);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:20|tBack", GOSSIP_SENDER_MAIN, 3);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(RAIDS, item->GetGUID());
			break;
		case 321:
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_hakkar:20 |tZul'Gurub", 1, 99954);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_onyxia:20 |tOnyxia's Lair", 1, 99955);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_ragnaros:20 |tMolten Core", 1, 99956);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_nefarion:20 |tBlackwing Lair", 1, 99957);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_ossiriantheunscarred:20 |tRuins of Ahn'Qiraj", 1, 99958);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_cthun:20 |tTemple of Ahn'Qiraj", 1, 99959);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:20|tBack", GOSSIP_SENDER_MAIN, 32);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(RAIDS, item->GetGUID());
			break;
		case 322:
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_princemalchezaar_02:20 |tKarazhan", 1, 99961);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_gruulthedragonkiller:20 |tGruul's Lair", 1, 99962);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_magtheridon:20 |tMagtheridon's Lair", 1, 99963);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_ladyvashj:20 |tSerpentshrine Cavern", 1, 99964);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_character_bloodelf_male:20 |tTempest Keep: The Eye", 1, 99965);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_archimonde-:20 |tBattle for Mount Hyjal", 1, 99966);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_illidan:20 |tBlack Temple", 1, 99967);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_kiljaedan:20 |tSunwell Plateau", 1, 99968);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:20|tBack", GOSSIP_SENDER_MAIN, 32);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(RAIDS, item->GetGUID());
			break;
		case 323:
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_dungeon_coablackdragonflight_10man:20 |tObsidian Sanctum", 1, 99969);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\inv_misc_statue_07:20 |tVault of Archavon", 1, 99970);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_freya_01:20 |tUlduar", 1, 99972);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\inv_crown_15:20 |tTrial of the Crusader", 1, 99973);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_halloween_spider_01:20 |tNaxxramas", 1, 99960);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\spell_shadow_twilight:20 |tRuby Sanctum", 1, 99975);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\achievement_boss_lichking:20 |tIcecrown Citadel", 1, 99976);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:20|tBack", GOSSIP_SENDER_MAIN, 32);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(RAIDS, item->GetGUID());
			break;


		case 5:
			AddGossipItemFor(player, 0, "|TInterface\\icons\\inv_helmet_25:20|tGurubashi Arena", GOSSIP_SENDER_MAIN, 51);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(ARENAS, item->GetGUID());
			break;

		case 51:
			player->TeleportTo(0, -13261.1f, 164.344f, 35.7824f, 1.09914f);
			break;

		case 6://Bank
			player->GetSession()->SendShowBank(player->GetSession()->GetPlayer()->GetGUID());
			break;

		case 21://kalimdor
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_ashenvale_01:15:15:-18 |tAshenvale|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 1);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_azshara_01:15:15:-18 |tAzshara|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 2);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_azuremystisle_01:15:15:-18 |tAzuremyst Isle|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 3);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_bloodmystisle_01:15:15:-18 |tBloodmyst Isle|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 4);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_darkshore_01:15:15:-18 |tDarkshore|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 5);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_felwood:15:15:-18 |tFelwood|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 6);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_mount hyjal:15:15:-18|t Hyjal|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 7);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\spell_arcane_teleportmoonglade:15:15:-18 |tMoonglade|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 8);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_darnassus:15:15:-18 |tTeldrassil|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 9);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_winterspring:15:15:-18 |tWinterspring|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 10);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_barrens_01:15:15:-18 |tThe Barrens|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 11);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_desolace:15:15:-18 |tDesolace|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 12);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_durotar:15:15:-18 |tDurotar|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 13);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_dustwallowmarsh:15:15:-18 |tDustwallow Marsh|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 14);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_mulgore_01:15:15:-18 |tMulgore|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 15);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_stonetalon_01:15:15:-18 |tStonetalon Mountains|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 16);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_feralas:15:15:-18 |tFeralas|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 17);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_silithus_01:15:15:-18 |tSilithus|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 18);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_tanaris_01:15:15:-18 |tTanaris|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 19);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_thousandneedles_01:15:15:-18 |tThousand Needles|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 20);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_uldum:15:15:-18 |tUldum|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 21);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_ungorocrater_01:15:15:-18 |tUn'Goro Crater|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 22);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:15:15:-18|t<------", GOSSIP_SENDER_MAIN, 2);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(KALIMDOR, item->GetGUID());
			break;
		case 22://Eastern Kingdoms
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_blastedlands_01:15:15:-18 |tBlasted Lands|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 23);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_deadwindpass:15:15:-18 |tDeadwind Pass|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 24);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_duskwood:15:15:-18 |tDuskwood|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 25);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_elwynnforest:15:15:-18 |tElwynn Forest|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 26);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_redridgemountains:15:15:-18 |tRedridge Mountains|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 27);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\ability_mount_whitetiger:15:15:-18 |tStranglethorn Vale|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 28);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_swampsorrows_01:15:15:-18 |tSwamp of Sorrows|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 29);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_westfall_01:15:15:-18 |tWestfall|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 30);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_badlands_01:15:15:-18 |tBadlands|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 31);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\spell_fire_volcano:15:15:-18 |tBlackrock Mountains|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 32);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_burningsteppes_01:15:15:-18 |tBurning Steppes|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 33);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_dunmorogh:15:15:-18 |tDun Morogh|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 34);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_lochmodan:15:15:-18 |tLoch Modan|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 35);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_searinggorge_01:15:15:-18 |tSearing Gorge|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 36);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_wetlands_01:15:15:-18 |tWetlands|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 37);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_eversongwoods:15:15:-18 |tEversong Woods|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 38);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_ghostlands:15:15:-18 |tGhostlands|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 39);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_isleofqueldanas:15:15:-18 |tIsle of Quel'Danas|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 40);

			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:15:15:-18|t<------", GOSSIP_SENDER_MAIN, 2);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(EASTERN_KINGDOMS, item->GetGUID());
			break;
		case 23://outlands

			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_bladesedgemtns_01:20 |tBlade's Edge Mountains|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 41);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_hellfirepeninsula_01:20 |tHellfire Peninsula|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 42);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_nagrand_01:20 |tNagrand|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 43);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_netherstorm_01:20 |tNetherstorm|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 44);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_shadowmoon:20 |tShadowmoon Valley|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 47);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_terrokar:20 |tTerokkar Forest|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 45);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_zangarmarsh:20 |tZangarmarsh|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 46);

			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:15:15:-18|t<------", GOSSIP_SENDER_MAIN, 2);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(OUTLANDS, item->GetGUID());
			break;
		case 24://Northrend 48 - 56
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_boreantundra_01:20 |tBorean Tundra|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 48);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_dragonblight_01:20 |tDragonblight|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 49);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_icecrown_01:20 |tIcecrown|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 50);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_sholazar_01:20 |tSholazar Basin|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 51);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_crystalsong_01:20 |tCrystalsong|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 52);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_zuldrak_01:20 |tZul'Drak|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 53);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_grizzlyhills_01:20 |tGrizzly Hills|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 54);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_howlingfjord_01:20 |tHowling Fjord|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 55);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_stormpeaks_01:20 |tStorm Peaks|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 56);

			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:15:15:-18|t<------", GOSSIP_SENDER_MAIN, 2);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(NORTHREND, item->GetGUID());
			break;
		case 25://Maelstrom

			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_dungeon_deepholm:20 |tDeepholm|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 57);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_twilighthighlands:20 |tTwilight Highlands|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 58);
			AddGossipItemFor(player, 0, "|cffFF0000|TInterface\\icons\\achievement_zone_firelands:20 |tMolten Front|r", GOSSIP_SENDER_MAIN, LOC_OFFSET + 59);
			AddGossipItemFor(player, 0, "|TInterface\\icons\\misc_arrowleft:15:15:-18|t<------", GOSSIP_SENDER_MAIN, 2);
			AddMainMenuGossipItem(player);
			player->PlayerTalkClass->SendGossipMenu(MAELSTROM, item->GetGUID());
			break;
		default:
			CloseGossipMenuFor(player);
			break;
		}
	}
};

void AddSC_item_teleporter()
{
	new item_teleporter();
}
