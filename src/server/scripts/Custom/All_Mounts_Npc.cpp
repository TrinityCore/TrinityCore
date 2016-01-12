#include "ScriptMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GameEventMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Unit.h"
#include "GameObject.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "Chat.h"
#include "DBCStructure.h"
#include "DBCStores.h"
#include "ObjectMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

class All_Mounts_Npc : public CreatureScript
{
public:
	All_Mounts_Npc() : CreatureScript("All_Mounts_Npc") {}

	bool OnGossipHello(Player* player, Creature* creature) override
	{
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teach me Mounts", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Goodbye", GOSSIP_SENDER_MAIN, 2);
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
	{
		if (action == 2)
		{
			player->PlayerTalkClass->SendCloseGossip();
			return false;
		}

		player->LearnSpell(48778, false);     //Acherus Deathcharger
		player->LearnSpell(60025, false);     //Albino Drake
		player->LearnSpell(127180, false);     //Albino Riding Crane
		player->LearnSpell(98204, false);     //Amani Battle Bear
		player->LearnSpell(96503, false);     //Amani Dragonhawk
		player->LearnSpell(43688, false);     //Amani War Bear
		player->LearnSpell(138424, false);     //Amber Primordial Direhorn
		player->LearnSpell(123886, false);     //Amber Scorpion
		player->LearnSpell(16056, false);     //Ancient Frostsaber
		player->LearnSpell(171618, false);     //Ancient Leatherhide
		player->LearnSpell(16081, false);     //Arctic Wolf
		player->LearnSpell(66906, false);     //Argent Charger
		player->LearnSpell(63844, false);     //Argent Hippogryph
		player->LearnSpell(66907, false);     //Argent Warhorse
		player->LearnSpell(67466, false);     //Argent Warhorse
		player->LearnSpell(139595, false);     //Armored Bloodwing
		player->LearnSpell(142478, false);     //Armored Blue Dragonhawk
		player->LearnSpell(61230, false);     //Armored Blue Wind Rider
		player->LearnSpell(60114, false);     //Armored Brown Bear
		player->LearnSpell(60116, false);     //Armored Brown Bear
		player->LearnSpell(171629, false);     //Armored Frostboar
		player->LearnSpell(171838, false);     //Armored Frostwolf
		player->LearnSpell(171626, false);     //Armored Irontusk
		player->LearnSpell(171630, false);     //Armored Razorback
		player->LearnSpell(96491, false);     //Armored Razzashi Raptor
		player->LearnSpell(142266, false);     //Armored Red Dragonhawk
		player->LearnSpell(136400, false);     //Armored Skyscreamer
		player->LearnSpell(61229, false);     //Armored Snowy Gryphon
		player->LearnSpell(132117, false);     //Ashen Pandaren Phoenix
		player->LearnSpell(40192, false);     //Ashes of Al'ar
		player->LearnSpell(148428, false);     //Ashhide Mushan Beast
		player->LearnSpell(127170, false);     //Astral Cloud Serpent
		player->LearnSpell(123992, false);     //Azure Cloud Serpent
		player->LearnSpell(59567, false);     //Azure Drake
		player->LearnSpell(41514, false);     //Azure Netherwing Drake
		player->LearnSpell(127174, false);     //Azure Riding Crane
		player->LearnSpell(118089, false);     //Azure Water Strider
		player->LearnSpell(51412, false);     //Big Battle Bear
		player->LearnSpell(58983, false);     //Big Blizzard Bear
		player->LearnSpell(71342, false);     //Big Love Rocket
		player->LearnSpell(22719, false);     //Black Battlestrider
		player->LearnSpell(127286, false);     //Black Dragon Turtle
		player->LearnSpell(59650, false);     //Black Drake
		player->LearnSpell(35022, false);     //Black Hawkstrider
		player->LearnSpell(16055, false);     //Black Nightsaber
		player->LearnSpell(138642, false);     //Black Primal Raptor
		player->LearnSpell(59976, false);     //Black Proto-Drake
		player->LearnSpell(25863, false);     //Black Qiraji Battle Tank
		player->LearnSpell(26655, false);     //Black Qiraji Battle Tank
		player->LearnSpell(26656, false);     //Black Qiraji Battle Tank
		player->LearnSpell(17461, false);     //Black Ram
		player->LearnSpell(130138, false);     //Black Riding Goat
		player->LearnSpell(127209, false);     //Black Riding Yak
		player->LearnSpell(64977, false);     //Black Skeletal Horse
		player->LearnSpell(470, false);     //Black Stallion
		player->LearnSpell(60118, false);     //Black War Bear
		player->LearnSpell(60119, false);     //Black War Bear
		player->LearnSpell(48027, false);     //Black War Elekk
		player->LearnSpell(22718, false);     //Black War Kodo
		player->LearnSpell(59785, false);     //Black War Mammoth
		player->LearnSpell(59788, false);     //Black War Mammoth
		player->LearnSpell(22720, false);     //Black War Ram
		player->LearnSpell(22721, false);     //Black War Raptor
		player->LearnSpell(22717, false);     //Black War Steed
		player->LearnSpell(22723, false);     //Black War Tiger
		player->LearnSpell(22724, false);     //Black War Wolf
		player->LearnSpell(64658, false);     //Black Wolf
		player->LearnSpell(171627, false);     //Blacksteel Battleboar
		player->LearnSpell(107842, false);     //Blazing Drake
		player->LearnSpell(74856, false);     //Blazing Hippogryph
		player->LearnSpell(127220, false);     //Blonde Riding Yak
		player->LearnSpell(72808, false);     //Bloodbathed Frostbrood Vanquisher
		player->LearnSpell(171620, false);     //Bloodhoof Bull
		player->LearnSpell(127287, false);     //Blue Dragon Turtle
		player->LearnSpell(61996, false);     //Blue Dragonhawk
		player->LearnSpell(59568, false);     //Blue Drake
		player->LearnSpell(35020, false);     //Blue Hawkstrider
		player->LearnSpell(10969, false);     //Blue Mechanostrider
		player->LearnSpell(59996, false);     //Blue Proto-Drake
		player->LearnSpell(25953, false);     //Blue Qiraji Battle Tank
		player->LearnSpell(39803, false);     //Blue Riding Nether Ray
		player->LearnSpell(129934, false);     //Blue Shado-Pan Riding Tiger
		player->LearnSpell(17463, false);     //Blue Skeletal Horse
		player->LearnSpell(64656, false);     //Blue Skeletal Warhorse
		player->LearnSpell(32244, false);     //Blue Wind Rider
		player->LearnSpell(138640, false);     //Bone-White Primal Raptor
		player->LearnSpell(142641, false);     //Brawler's Burly Mushan Beast
		player->LearnSpell(171832, false);     //Breezestrider Stallion
		player->LearnSpell(50869, false);     //Brewfest Kodo
		player->LearnSpell(43899, false);     //Brewfest Ram
		player->LearnSpell(190690, false);     //Bristling Hellboar
		player->LearnSpell(59569, false);     //Bronze Drake
		player->LearnSpell(127288, false);     //Brown Dragon Turtle
		player->LearnSpell(34406, false);     //Brown Elekk
		player->LearnSpell(458, false);     //Brown Horse
		player->LearnSpell(18990, false);     //Brown Kodo
		player->LearnSpell(6899, false);     //Brown Ram
		player->LearnSpell(88748, false);     //Brown Riding Camel
		player->LearnSpell(130086, false);     //Brown Riding Goat
		player->LearnSpell(127213, false);     //Brown Riding Yak
		player->LearnSpell(17464, false);     //Brown Skeletal Horse
		player->LearnSpell(6654, false);     //Brown Wolf
		player->LearnSpell(58615, false);     //Brutal Nether Drake
		player->LearnSpell(124550, false);     //Cataclysmic Gladiator's Twilight Drake
		player->LearnSpell(75614, false);     //Celestial Steed
		player->LearnSpell(43927, false);     //Cenarion War Hippogryph
		player->LearnSpell(171848, false);     //Challenger's War Yeti
		player->LearnSpell(171846, false);     //Champion's Treadblade
		player->LearnSpell(6648, false);     //Chestnut Mare
		player->LearnSpell(171847, false);     //Cindermane Charger
		player->LearnSpell(139448, false);     //Clutch of Ji-Kun
		player->LearnSpell(189364, false);     //Coalfist Gronnling
		player->LearnSpell(41515, false);     //Cobalt Netherwing Drake
		player->LearnSpell(138423, false);     //Cobalt Primordial Direhorn
		player->LearnSpell(39315, false);     //Cobalt Riding Talbuk
		player->LearnSpell(34896, false);     //Cobalt War Talbuk
		player->LearnSpell(170347, false);     //Core Hound
		player->LearnSpell(183117, false);     //Corrupted Dreadwing
		player->LearnSpell(97560, false);     //Corrupted Fire Hawk
		player->LearnSpell(102514, false);     //Corrupted Hippogryph
		player->LearnSpell(169952, false);     //Creeping Carpet
		player->LearnSpell(127156, false);     //Crimson Cloud Serpent
		player->LearnSpell(73313, false);     //Crimson Deathcharger
		player->LearnSpell(129552, false);     //Crimson Pandaren Phoenix
		player->LearnSpell(140250, false);     //Crimson Primal Direhorn
		player->LearnSpell(123160, false);     //Crimson Riding Crane
		player->LearnSpell(127271, false);     //Crimson Water Strider
		player->LearnSpell(68188, false);     //Crusader's Black Warhorse
		player->LearnSpell(68187, false);     //Crusader's White Warhorse
		player->LearnSpell(88990, false);     //Dark Phoenix
		player->LearnSpell(39316, false);     //Dark Riding Talbuk
		player->LearnSpell(34790, false);     //Dark War Talbuk
		player->LearnSpell(103081, false);     //Darkmoon Dancing Bear
		player->LearnSpell(63635, false);     //Darkspear Raptor
		player->LearnSpell(63637, false);     //Darnassian Nightsaber
		player->LearnSpell(64927, false);     //Deadly Gladiator's Frost Wyrm
		player->LearnSpell(190977, false);     //Deathtusk Felboar
		player->LearnSpell(193007, false);     //Demonsaber
		player->LearnSpell(126507, false);     //Depleted-Kyparium Rocket
		player->LearnSpell(6653, false);     //Dire Wolf
		player->LearnSpell(171634, false);     //Domesticated Razorback
		player->LearnSpell(88335, false);     //Drake of the East Wind
		player->LearnSpell(88742, false);     //Drake of the North Wind
		player->LearnSpell(88744, false);     //Drake of the South Wind
		player->LearnSpell(88741, false);     //Drake of the West Wind
		player->LearnSpell(155741, false);     //Dread Raven
		player->LearnSpell(148972, false);     //Dreadsteed
		player->LearnSpell(171844, false);     //Dustmane Direwolf
		player->LearnSpell(171625, false);     //Dusty Rockhide
		player->LearnSpell(32239, false);     //Ebon Gryphon
		player->LearnSpell(194464, false);     //Eclipse Dragonhawk
		player->LearnSpell(175700, false);     //Emerald Drake
		player->LearnSpell(149801, false);     //Emerald Hippogryph
		player->LearnSpell(132118, false);     //Emerald Pandaren Phoenix
		player->LearnSpell(8395, false);     //Emerald Raptor
		player->LearnSpell(142878, false);     //Enchanted Fey Dragon
		player->LearnSpell(63639, false);     //Exodar Elekk
		player->LearnSpell(110039, false);     //Experiment 12-B
		player->LearnSpell(113120, false);     //Feldrake
		player->LearnSpell(97501, false);     //Felfire Hawk
		player->LearnSpell(200175, false);     //Felsaber
		player->LearnSpell(148970, false);     //Felsteed
		player->LearnSpell(182912, false);     //Felsteel Annihilator
		player->LearnSpell(36702, false);     //Fiery Warhorse
		player->LearnSpell(101542, false);     //Flametalon of Alysrazor
		player->LearnSpell(97359, false);     //Flameward Hippogryph
		player->LearnSpell(61451, false);     //Flying Carpet
		player->LearnSpell(44153, false);     //Flying Machine
		player->LearnSpell(63643, false);     //Forsaken Warhorse
		player->LearnSpell(84751, false);     //Fossilized Raptor
		player->LearnSpell(17460, false);     //Frost Ram
		player->LearnSpell(171632, false);     //Frostplains Battleboar
		player->LearnSpell(23509, false);     //Frostwolf Howler
		player->LearnSpell(75596, false);     //Frosty Flying Carpet
		player->LearnSpell(65439, false);     //Furious Gladiator's Frost Wyrm
		player->LearnSpell(171851, false);     //Garn Nighthowl
		player->LearnSpell(171836, false);     //Garn Steelmaw
		player->LearnSpell(126508, false);     //Geosynchronous World Spinner
		player->LearnSpell(136505, false);     //Ghastly Charger
		player->LearnSpell(171635, false);     //Giant Coldsnout
		player->LearnSpell(63638, false);     //Gnomeregan Mechanostrider
		player->LearnSpell(89520, false);     //Goblin Mini Hotrod
		player->LearnSpell(87090, false);     //Goblin Trike
		player->LearnSpell(87091, false);     //Goblin Turbo-Trike
		player->LearnSpell(123993, false);     //Golden Cloud Serpent
		player->LearnSpell(32235, false);     //Golden Gryphon
		player->LearnSpell(90621, false);     //Golden King
		player->LearnSpell(140249, false);     //Golden Primal Direhorn
		player->LearnSpell(127176, false);     //Golden Riding Crane
		player->LearnSpell(127278, false);     //Golden Water Strider
		player->LearnSpell(171436, false);     //Gorestrider Gronnling
		player->LearnSpell(135416, false);     //Grand Armored Gryphon
		player->LearnSpell(135418, false);     //Grand Armored Wyvern
		player->LearnSpell(61465, false);     //Grand Black War Mammoth
		player->LearnSpell(61467, false);     //Grand Black War Mammoth
		player->LearnSpell(122708, false);     //Grand Expedition Yak
		player->LearnSpell(136163, false);     //Grand Gryphon
		player->LearnSpell(61470, false);     //Grand Ice Mammoth
		player->LearnSpell(61469, false);     //Grand Ice Mammoth
		player->LearnSpell(136164, false);     //Grand Wyvern
		player->LearnSpell(35710, false);     //Gray Elekk
		player->LearnSpell(18989, false);     //Gray Kodo
		player->LearnSpell(6777, false);     //Gray Ram
		player->LearnSpell(127295, false);     //Great Black Dragon Turtle
		player->LearnSpell(127302, false);     //Great Blue Dragon Turtle
		player->LearnSpell(35713, false);     //Great Blue Elekk
		player->LearnSpell(49379, false);     //Great Brewfest Kodo
		player->LearnSpell(127308, false);     //Great Brown Dragon Turtle
		player->LearnSpell(23249, false);     //Great Brown Kodo
		player->LearnSpell(65641, false);     //Great Golden Kodo
		player->LearnSpell(23248, false);     //Great Gray Kodo
		player->LearnSpell(127293, false);     //Great Green Dragon Turtle
		player->LearnSpell(35712, false);     //Great Green Elekk
		player->LearnSpell(171636, false);     //Great Greytusk
		player->LearnSpell(127310, false);     //Great Purple Dragon Turtle
		player->LearnSpell(35714, false);     //Great Purple Elekk
		player->LearnSpell(120822, false);     //Great Red Dragon Turtle
		player->LearnSpell(65637, false);     //Great Red Elekk
		player->LearnSpell(23247, false);     //Great White Kodo
		player->LearnSpell(120395, false);     //Green Dragon Turtle
		player->LearnSpell(18991, false);     //Green Kodo
		player->LearnSpell(17453, false);     //Green Mechanostrider
		player->LearnSpell(138643, false);     //Green Primal Raptor
		player->LearnSpell(61294, false);     //Green Proto-Drake
		player->LearnSpell(26056, false);     //Green Qiraji Battle Tank
		player->LearnSpell(39798, false);     //Green Riding Nether Ray
		player->LearnSpell(129932, false);     //Green Shado-Pan Riding Tiger
		player->LearnSpell(17465, false);     //Green Skeletal Warhorse
		player->LearnSpell(32245, false);     //Green Wind Rider
		player->LearnSpell(88750, false);     //Grey Riding Camel
		player->LearnSpell(127216, false);     //Grey Riding Yak
		player->LearnSpell(148619, false);     //Grievous Gladiator's Cloud Serpent
		player->LearnSpell(163025, false);     //Grinning Reaver
		player->LearnSpell(189999, false);     //Grove Warden
		player->LearnSpell(48025, false);     //Headless Horseman's Mount
		player->LearnSpell(110051, false);     //Heart of the Aspects
		player->LearnSpell(142073, false);     //Hearthsteed
		player->LearnSpell(127169, false);     //Heavenly Azure Cloud Serpent
		player->LearnSpell(127161, false);     //Heavenly Crimson Cloud Serpent
		player->LearnSpell(127164, false);     //Heavenly Golden Cloud Serpent
		player->LearnSpell(127165, false);     //Heavenly Jade Cloud Serpent
		player->LearnSpell(127158, false);     //Heavenly Onyx Cloud Serpent
		player->LearnSpell(59799, false);     //Ice Mammoth
		player->LearnSpell(59797, false);     //Ice Mammoth
		player->LearnSpell(72807, false);     //Icebound Frostbrood Vanquisher
		player->LearnSpell(17459, false);     //Icy Blue Mechanostrider Mod A
		player->LearnSpell(189998, false);     //Illidari Felstalker
		player->LearnSpell(124659, false);     //Imperial Quilen
		player->LearnSpell(186305, false);     //Infernal Direwolf
		player->LearnSpell(201098, false);     //Infinite Timereaver
		player->LearnSpell(72286, false);     //Invincible
		player->LearnSpell(153489, false);     //Iron Skyreaver
		player->LearnSpell(63956, false);     //Ironbound Proto-Drake
		player->LearnSpell(142910, false);     //Ironbound Wraithcharger
		player->LearnSpell(63636, false);     //Ironforge Ram
		player->LearnSpell(171621, false);     //Ironhoof Destroyer
		player->LearnSpell(171839, false);     //Ironside Warwolf
		player->LearnSpell(17450, false);     //Ivory Raptor
		player->LearnSpell(113199, false);     //Jade Cloud Serpent
		player->LearnSpell(133023, false);     //Jade Pandaren Kite
		player->LearnSpell(121837, false);     //Jade Panther
		player->LearnSpell(138426, false);     //Jade Primordial Direhorn
		player->LearnSpell(127274, false);     //Jade Water Strider
		player->LearnSpell(120043, false);     //Jeweled Onyx Panther
		player->LearnSpell(127178, false);     //Jungle Riding Crane
		player->LearnSpell(93644, false);     //Kor'kron Annihilator
		player->LearnSpell(148417, false);     //Kor'kron Juggernaut
		player->LearnSpell(148396, false);     //Kor'kron War Wolf
		player->LearnSpell(107845, false);     //Life-Binder's Handmaiden
		player->LearnSpell(65917, false);     //Magic Rooster
		player->LearnSpell(61309, false);     //Magnificent Flying Carpet
		player->LearnSpell(139407, false);     //Malevolent Gladiator's Cloud Serpent
		player->LearnSpell(55531, false);     //Mechano-Hog
		player->LearnSpell(60424, false);     //Mekgineer's Chopper
		player->LearnSpell(44744, false);     //Merciless Nether Drake
		player->LearnSpell(63796, false);     //Mimiron's Head
		player->LearnSpell(191314, false);     //Minion of Grumpus
		player->LearnSpell(171825, false);     //Mosshide Riverwallow
		player->LearnSpell(93623, false);     //Mottled Drake
		player->LearnSpell(171622, false);     //Mottled Meadowstomper
		player->LearnSpell(16084, false);     //Mottled Red Raptor
		player->LearnSpell(171850, false);     //Mount Template 49
		player->LearnSpell(171827, false);     //Mount Template 50
		player->LearnSpell(171840, false);     //Mount Template 51
		player->LearnSpell(103195, false);     //Mountain Horse
		player->LearnSpell(171826, false);     //Mudback Riverbeast
		player->LearnSpell(180545, false);     //Mystic Runesaber
		player->LearnSpell(121820, false);     //Obsidian Nightwing
		player->LearnSpell(66846, false);     //Ochre Skeletal Warhorse
		player->LearnSpell(127154, false);     //Onyx Cloud Serpent
		player->LearnSpell(41513, false);     //Onyx Netherwing Drake
		player->LearnSpell(69395, false);     //Onyxian Drake
		player->LearnSpell(127272, false);     //Orange Water Strider
		player->LearnSpell(63640, false);     //Orgrimmar Wolf
		player->LearnSpell(171833, false);     //Pale Thorngrazer
		player->LearnSpell(16082, false);     //Palomino
		player->LearnSpell(118737, false);     //Pandaren Kite
		player->LearnSpell(130985, false);     //Pandaren Kite
		player->LearnSpell(32345, false);     //Peep the Phoenix Mount
		player->LearnSpell(88718, false);     //Phosphorescent Stone Drake
		player->LearnSpell(472, false);     //Pinto
		player->LearnSpell(60021, false);     //Plagued Proto-Drake
		player->LearnSpell(193695, false);     //Prestigious War Steed
		player->LearnSpell(204166, false);     //Prestigious War Wolf
		player->LearnSpell(148620, false);     //Prideful Gladiator's Cloud Serpent
		player->LearnSpell(186828, false);     //Primal Gladiator's Felblood Gronnling
		player->LearnSpell(97493, false);     //Pureblood Fire Hawk
		player->LearnSpell(127289, false);     //Purple Dragon Turtle
		player->LearnSpell(35711, false);     //Purple Elekk
		player->LearnSpell(35018, false);     //Purple Hawkstrider
		player->LearnSpell(41516, false);     //Purple Netherwing Drake
		player->LearnSpell(39801, false);     //Purple Riding Nether Ray
		player->LearnSpell(23246, false);     //Purple Skeletal Warhorse
		player->LearnSpell(66090, false);     //Quel'dorei Steed
		player->LearnSpell(41252, false);     //Raven Lord
		player->LearnSpell(127290, false);     //Red Dragon Turtle
		player->LearnSpell(61997, false);     //Red Dragonhawk
		player->LearnSpell(59570, false);     //Red Drake
		player->LearnSpell(130092, false);     //Red Flying Cloud
		player->LearnSpell(34795, false);     //Red Hawkstrider
		player->LearnSpell(10873, false);     //Red Mechanostrider
		player->LearnSpell(138641, false);     //Red Primal Raptor
		player->LearnSpell(59961, false);     //Red Proto-Drake
		player->LearnSpell(26054, false);     //Red Qiraji Battle Tank
		player->LearnSpell(39800, false);     //Red Riding Nether Ray
		player->LearnSpell(129935, false);     //Red Shado-Pan Riding Tiger
		player->LearnSpell(17462, false);     //Red Skeletal Horse
		player->LearnSpell(22722, false);     //Red Skeletal Warhorse
		player->LearnSpell(16080, false);     //Red Wolf
		player->LearnSpell(127177, false);     //Regal Riding Crane
		player->LearnSpell(67336, false);     //Relentless Gladiator's Frost Wyrm
		player->LearnSpell(30174, false);     //Riding Turtle
		player->LearnSpell(17481, false);     //Rivendare's Deathcharger
		player->LearnSpell(171628, false);     //Rocktusk Battleboar
		player->LearnSpell(121838, false);     //Ruby Panther
		player->LearnSpell(63963, false);     //Rusted Proto-Drake
		player->LearnSpell(101821, false);     //Ruthless Gladiator's Twilight Drake
		player->LearnSpell(93326, false);     //Sandstone Drake
		player->LearnSpell(121836, false);     //Sapphire Panther
		player->LearnSpell(171824, false);     //Sapphire Riverbeast
		player->LearnSpell(97581, false);     //Savage Raptor
		player->LearnSpell(64731, false);     //Sea Turtle
		player->LearnSpell(171624, false);     //Shadowhide Pearltusk
		player->LearnSpell(171829, false);     //Shadowmane Charger
		player->LearnSpell(66087, false);     //Silver Covenant Hippogryph
		player->LearnSpell(39802, false);     //Silver Riding Nether Ray
		player->LearnSpell(39317, false);     //Silver Riding Talbuk
		player->LearnSpell(34898, false);     //Silver War Talbuk
		player->LearnSpell(63642, false);     //Silvermoon Hawkstrider
		player->LearnSpell(134359, false);     //Sky Golem
		player->LearnSpell(138425, false);     //Slate Primordial Direhorn
		player->LearnSpell(171843, false);     //Smoky Direwolf
		player->LearnSpell(32240, false);     //Snowy Gryphon
		player->LearnSpell(191633, false);     //Soaring Skyterror
		player->LearnSpell(171828, false);     //Solar Spirehawk
		player->LearnSpell(130965, false);     //Son of Galleon
		player->LearnSpell(148392, false);     //Spawn of Galakras
		player->LearnSpell(136471, false);     //Spawn of Horridon
		player->LearnSpell(107516, false);     //Spectral Gryphon
		player->LearnSpell(92231, false);     //Spectral Steed
		player->LearnSpell(42776, false);     //Spectral Tiger
		player->LearnSpell(107517, false);     //Spectral Wind Rider
		player->LearnSpell(92232, false);     //Spectral Wolf
		player->LearnSpell(196681, false);     //Spirit of Eche'ro
		player->LearnSpell(10789, false);     //Spotted Frostsaber
		player->LearnSpell(147595, false);     //Stormcrow
		player->LearnSpell(23510, false);     //Stormpike Battle Charger
		player->LearnSpell(63232, false);     //Stormwind Steed
		player->LearnSpell(66847, false);     //Striped Dawnsaber
		player->LearnSpell(8394, false);     //Striped Frostsaber
		player->LearnSpell(10793, false);     //Striped Nightsaber
		player->LearnSpell(98718, false);     //Subdued Seahorse
		player->LearnSpell(179245, false);     //Summon Chauffeur
		player->LearnSpell(179244, false);     //Summon Chauffeur
		player->LearnSpell(171849, false);     //Sunhide Gronnling
		player->LearnSpell(66088, false);     //Sunreaver Dragonhawk
		player->LearnSpell(66091, false);     //Sunreaver Hawkstrider
		player->LearnSpell(121839, false);     //Sunstone Panther
		player->LearnSpell(68057, false);     //Swift Alliance Steed
		player->LearnSpell(32242, false);     //Swift Blue Gryphon
		player->LearnSpell(23241, false);     //Swift Blue Raptor
		player->LearnSpell(171830, false);     //Swift Breezestrider
		player->LearnSpell(43900, false);     //Swift Brewfest Ram
		player->LearnSpell(23238, false);     //Swift Brown Ram
		player->LearnSpell(23229, false);     //Swift Brown Steed
		player->LearnSpell(23250, false);     //Swift Brown Wolf
		player->LearnSpell(65646, false);     //Swift Burgundy Wolf
		player->LearnSpell(102346, false);     //Swift Forest Strider
		player->LearnSpell(23221, false);     //Swift Frostsaber
		player->LearnSpell(171842, false);     //Swift Frostwolf
		player->LearnSpell(23239, false);     //Swift Gray Ram
		player->LearnSpell(65640, false);     //Swift Gray Steed
		player->LearnSpell(23252, false);     //Swift Gray Wolf
		player->LearnSpell(32290, false);     //Swift Green Gryphon
		player->LearnSpell(35025, false);     //Swift Green Hawkstrider
		player->LearnSpell(23225, false);     //Swift Green Mechanostrider
		player->LearnSpell(32295, false);     //Swift Green Wind Rider
		player->LearnSpell(68056, false);     //Swift Horde Wolf
		player->LearnSpell(102350, false);     //Swift Lovebird
		player->LearnSpell(23219, false);     //Swift Mistsaber
		player->LearnSpell(65638, false);     //Swift Moonsaber
		player->LearnSpell(103196, false);     //Swift Mountain Horse
		player->LearnSpell(37015, false);     //Swift Nether Drake
		player->LearnSpell(23242, false);     //Swift Olive Raptor
		player->LearnSpell(23243, false);     //Swift Orange Raptor
		player->LearnSpell(23227, false);     //Swift Palomino
		player->LearnSpell(33660, false);     //Swift Pink Hawkstrider
		player->LearnSpell(32292, false);     //Swift Purple Gryphon
		player->LearnSpell(35027, false);     //Swift Purple Hawkstrider
		player->LearnSpell(65644, false);     //Swift Purple Raptor
		player->LearnSpell(32297, false);     //Swift Purple Wind Rider
		player->LearnSpell(24242, false);     //Swift Razzashi Raptor
		player->LearnSpell(32289, false);     //Swift Red Gryphon
		player->LearnSpell(65639, false);     //Swift Red Hawkstrider
		player->LearnSpell(32246, false);     //Swift Red Wind Rider
		player->LearnSpell(101573, false);     //Swift Shorestrider
		player->LearnSpell(55164, false);     //Swift Spectral Gryphon
		player->LearnSpell(194046, false);     //Swift Spectral Rylak
		player->LearnSpell(42777, false);     //Swift Spectral Tiger
		player->LearnSpell(102349, false);     //Swift Springstrider
		player->LearnSpell(23338, false);     //Swift Stormsaber
		player->LearnSpell(23251, false);     //Swift Timber Wolf
		player->LearnSpell(65643, false);     //Swift Violet Ram
		player->LearnSpell(35028, false);     //Swift Warstrider
		player->LearnSpell(46628, false);     //Swift White Hawkstrider
		player->LearnSpell(23223, false);     //Swift White Mechanostrider
		player->LearnSpell(23240, false);     //Swift White Ram
		player->LearnSpell(23228, false);     //Swift White Steed
		player->LearnSpell(134573, false);     //Swift Windsteed
		player->LearnSpell(23222, false);     //Swift Yellow Mechanostrider
		player->LearnSpell(32296, false);     //Swift Yellow Wind Rider
		player->LearnSpell(49322, false);     //Swift Zhevra
		player->LearnSpell(96499, false);     //Swift Zulian Panther
		player->LearnSpell(24252, false);     //Swift Zulian Tiger
		player->LearnSpell(88749, false);     //Tan Riding Camel
		player->LearnSpell(39318, false);     //Tan Riding Talbuk
		player->LearnSpell(34899, false);     //Tan War Talbuk
		player->LearnSpell(32243, false);     //Tawny Wind Rider
		player->LearnSpell(18992, false);     //Teal Kodo
		player->LearnSpell(63641, false);     //Thunder Bluff Kodo
		player->LearnSpell(129918, false);     //Thundering August Cloud Serpent
		player->LearnSpell(139442, false);     //Thundering Cobalt Cloud Serpent
		player->LearnSpell(124408, false);     //Thundering Jade Cloud Serpent
		player->LearnSpell(148476, false);     //Thundering Onyx Cloud Serpent
		player->LearnSpell(132036, false);     //Thundering Ruby Cloud Serpent
		player->LearnSpell(580, false);     //Timber Wolf
		player->LearnSpell(60002, false);     //Time-Lost Proto-Drake
		player->LearnSpell(171617, false);     //Trained Icehoof
		player->LearnSpell(171623, false);     //Trained Meadowstomper
		player->LearnSpell(171638, false);     //Trained Riverwallow
		player->LearnSpell(171637, false);     //Trained Rocktusk
		player->LearnSpell(171831, false);     //Trained Silverpelt
		player->LearnSpell(171841, false);     //Trained Snarler
		player->LearnSpell(61425, false);     //Traveler's Tundra Mammoth
		player->LearnSpell(61447, false);     //Traveler's Tundra Mammoth
		player->LearnSpell(171619, false);     //Tundra Icehoof
		player->LearnSpell(44151, false);     //Turbo-Charged Flying Machine
		player->LearnSpell(65642, false);     //Turbostrider
		player->LearnSpell(10796, false);     //Turquoise Raptor
		player->LearnSpell(59571, false);     //Twilight Drake
		player->LearnSpell(107844, false);     //Twilight Harbinger
		player->LearnSpell(107203, false);     //Tyrael's Charger
		player->LearnSpell(148618, false);     //Tyrannical Gladiator's Cloud Serpent
		player->LearnSpell(92155, false);     //Ultramarine Qiraji Battle Tank
		player->LearnSpell(17454, false);     //Unpainted Mechanostrider
		player->LearnSpell(75207, false);     //Vashj'ir Seahorse
		player->LearnSpell(49193, false);     //Vengeful Nether Drake
		player->LearnSpell(64659, false);     //Venomhide Ravasaur
		player->LearnSpell(41517, false);     //Veridian Netherwing Drake
		player->LearnSpell(101282, false);     //Vicious Gladiator's Twilight Drake
		player->LearnSpell(146622, false);     //Vicious Skeletal Warhorse
		player->LearnSpell(185052, false);     //Vicious War Kodo
		player->LearnSpell(183889, false);     //Vicious War Mechanostrider
		player->LearnSpell(171834, false);     //Vicious War Ram
		player->LearnSpell(171835, false);     //Vicious War Raptor
		player->LearnSpell(100332, false);     //Vicious War Steed
		player->LearnSpell(100333, false);     //Vicious War Wolf
		player->LearnSpell(146615, false);     //Vicious Warsaber
		player->LearnSpell(41518, false);     //Violet Netherwing Drake
		player->LearnSpell(132119, false);     //Violet Pandaren Phoenix
		player->LearnSpell(60024, false);     //Violet Proto-Drake
		player->LearnSpell(10799, false);     //Violet Raptor
		player->LearnSpell(88746, false);     //Vitreous Stone Drake
		player->LearnSpell(179478, false);     //Voidtalon of the Dark Star
		player->LearnSpell(88331, false);     //Volcanic Stone Drake
		player->LearnSpell(163024, false);     //Warforged Nightmare
		player->LearnSpell(171845, false);     //Warlord's Deathwheel
		player->LearnSpell(189044, false);     //Warmongering Gladiator's Felblood Gronnling
		player->LearnSpell(171837, false);     //Warsong Direfang
		player->LearnSpell(64657, false);     //White Kodo
		player->LearnSpell(15779, false);     //White Mechanostrider Mod B
		player->LearnSpell(54753, false);     //White Polar Bear
		player->LearnSpell(6898, false);     //White Ram
		player->LearnSpell(102488, false);     //White Riding Camel
		player->LearnSpell(130137, false);     //White Riding Goat
		player->LearnSpell(39319, false);     //White Riding Talbuk
		player->LearnSpell(123182, false);     //White Riding Yak
		player->LearnSpell(65645, false);     //White Skeletal Warhorse
		player->LearnSpell(16083, false);     //White Stallion
		player->LearnSpell(34897, false);     //White War Talbuk
		player->LearnSpell(189043, false);     //Wild Gladiator's Felblood Gronnling
		player->LearnSpell(171633, false);     //Wild Goretusk
		player->LearnSpell(98727, false);     //Winged Guardian
		player->LearnSpell(54729, false);     //Winged Steed of the Ebon Blade
		player->LearnSpell(17229, false);     //Winterspring Frostsaber
		player->LearnSpell(171616, false);     //Witherhide Cliffstomper
		player->LearnSpell(59791, false);     //Wooly Mammoth
		player->LearnSpell(59793, false);     //Wooly Mammoth
		player->LearnSpell(74918, false);     //Wooly White Rhino
		player->LearnSpell(71810, false);     //Wrathful Gladiator's Frost Wyrm
		player->LearnSpell(46197, false);     //X-51 Nether-Rocket
		player->LearnSpell(46199, false);     //X-51 Nether-Rocket X-TREME
		player->LearnSpell(75973, false);     //X-53 Touring Rocket
		player->LearnSpell(26055, false);     //Yellow Qiraji Battle Tank
		return true;
	}
};

void AddSC_All_Mounts_Npc()
{
	new All_Mounts_Npc;
}