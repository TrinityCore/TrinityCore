SET @Grey := 1001; -- reference starting value TDB Field
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @Grey AND @Grey+53;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- level 52 Grey Items ilvl 57
(@Grey+51,3951,0,1,1,1,1), -- Twill Vest
(@Grey+51,3976,0,1,1,1,1), -- Smooth Leather Armor
(@Grey+51,3995,0,1,1,1,1), -- Laminated Scale Cloak
(@Grey+51,8081,0,1,1,1,1), -- Light Plate Belt
(@Grey+51,8753,0,1,1,1,1), -- Smooth Leather Helmet
(@Grey+51,9186,0,1,1,1,1), -- Mind-numbing Poison III
(@Grey+51,13821,0,1,1,1,1), -- Bulky Maul
(@Grey+51,13825,0,1,1,1,1), -- Primed Musket
-- level 53 Grey Items ilvl 58
(@Grey+52,3948,0,1,1,1,1), -- Twill Gloves
(@Grey+52,3973,0,1,1,1,1), -- Smooth Leather Gloves
(@Grey+52,3994,0,1,1,1,1), -- Laminated Scale Bracers
(@Grey+52,8080,0,1,1,1,1), -- Light Plate Chestpiece
(@Grey+52,13817,0,1,1,1,1); -- Tapered Greatsword
-- --------------------------------------------------------
-- TBC_Greys_References
-- --------------------------------------------------------
SET @GreyTBC  := 4000; -- reference starting value TDB Field
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @GreyTBC AND @GreyTBC+2;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- level 61 Greys, ilvl 66 (32 items)
(@GreyTBC,24576,0,1,1,1,1), -- Loosely Threaded Belt
(@GreyTBC,24577,0,1,1,1,1), -- Loosely Threaded Boots
(@GreyTBC,24578,0,1,1,1,1), -- Loosely Threaded Bracers
(@GreyTBC,24580,0,1,1,1,1), -- Loosely Threaded Hat
(@GreyTBC,24782,0,1,1,1,1), -- Loosely Threaded Gloves
(@GreyTBC,25338,0,1,1,1,1), -- Loosely Threaded Pants
(@GreyTBC,25339,0,1,1,1,1), -- Loosely Threaded Shoulderpads
(@GreyTBC,25340,0,1,1,1,1), -- Loosely Threaded Vest
(@GreyTBC,25349,0,1,1,1,1), -- Moldy Leather Armor
(@GreyTBC,25350,0,1,1,1,1), -- Moldy Leather Belt
(@GreyTBC,25351,0,1,1,1,1), -- Moldy Leather Boots
(@GreyTBC,25352,0,1,1,1,1), -- Moldy Leather Bracers
(@GreyTBC,25353,0,1,1,1,1), -- Moldy Leather Gloves
(@GreyTBC,25354,0,1,1,1,1), -- Moldy Leather Helmet
(@GreyTBC,25355,0,1,1,1,1), -- Moldy Leather Pants
(@GreyTBC,25356,0,1,1,1,1), -- Moldy Leather Shoulderpads
(@GreyTBC,25365,0,1,1,1,1), -- Eroded Mail Armor
(@GreyTBC,25366,0,1,1,1,1), -- Eroded Mail Belt
(@GreyTBC,25367,0,1,1,1,1), -- Eroded Mail Boots
(@GreyTBC,25368,0,1,1,1,1), -- Eroded Mail Bracers
(@GreyTBC,25369,0,1,1,1,1), -- Eroded Mail Circlet
(@GreyTBC,25370,0,1,1,1,1), -- Eroded Mail Gloves
(@GreyTBC,25371,0,1,1,1,1), -- Eroded Mail Pants
(@GreyTBC,25372,0,1,1,1,1), -- Eroded Mail Shoulderpads
(@GreyTBC,25381,0,1,1,1,1), -- Tarnished Plate Belt
(@GreyTBC,25382,0,1,1,1,1), -- Tarnished Plate Boots
(@GreyTBC,25383,0,1,1,1,1), -- Tarnished Plate Bracers
(@GreyTBC,25384,0,1,1,1,1), -- Tarnished Plate Chestpiece
(@GreyTBC,25385,0,1,1,1,1), -- Tarnished Plate Gloves
(@GreyTBC,25386,0,1,1,1,1), -- Tarnished Plate Helmet
(@GreyTBC,25387,0,1,1,1,1), -- Tarnished Plate Pants
(@GreyTBC,25388,0,1,1,1,1), -- Tarnished Plate Shoulderpads
-- level 64 Greys, ilvl 69 (10 items)
(@GreyTBC+1,25397,0,1,1,1,1), -- Eroded Axe
(@GreyTBC+1,25398,0,1,1,1,1), -- Stone Reaper
(@GreyTBC+1,25399,0,1,1,1,1), -- Deteriorating Blade
(@GreyTBC+1,25400,0,1,1,1,1), -- Tarnished Claymore
(@GreyTBC+1,25401,0,1,1,1,1), -- Corroded Mace
(@GreyTBC+1,25402,0,1,1,1,1), -- The Stoppable Force
(@GreyTBC+1,25403,0,1,1,1,1), -- Sharpened Stilleto
(@GreyTBC+1,25404,0,1,1,1,1), -- Dense War Staff
(@GreyTBC+1,25405,0,1,1,1,1), -- Rusted Musket
(@GreyTBC+1,25406,0,1,1,1,1), -- Broken Longbow
-- lvl 67 Greys, ilvl 72 (32 items)
(@GreyTBC+2,25341,0,1,1,1,1), -- Dilapidated Cloth Belt
(@GreyTBC+2,25342,0,1,1,1,1), -- Dilapidated Cloth Boots
(@GreyTBC+2,25343,0,1,1,1,1), -- Dilapidated Cloth Bracers
(@GreyTBC+2,25344,0,1,1,1,1), -- Dilapidated Cloth Gloves
(@GreyTBC+2,25345,0,1,1,1,1), -- Dilapidated Cloth Hat
(@GreyTBC+2,25346,0,1,1,1,1), -- Dilapidated Cloth Pants
(@GreyTBC+2,25347,0,1,1,1,1), -- Dilapidated Cloth Shoulderpads
(@GreyTBC+2,25348,0,1,1,1,1), -- Dilapidated Cloth Vest
(@GreyTBC+2,25357,0,1,1,1,1), -- Decaying Leather Armor
(@GreyTBC+2,25358,0,1,1,1,1), -- Decaying Leather Belt
(@GreyTBC+2,25359,0,1,1,1,1), -- Decaying Leather Boots
(@GreyTBC+2,25360,0,1,1,1,1), -- Decaying Leather Bracers
(@GreyTBC+2,25361,0,1,1,1,1), -- Decaying Leather Gloves
(@GreyTBC+2,25362,0,1,1,1,1), -- Decaying Leather Helmet
(@GreyTBC+2,25363,0,1,1,1,1), -- Decaying Leather Pants
(@GreyTBC+2,25364,0,1,1,1,1), -- Decaying Leather Shoulderpads
(@GreyTBC+2,25373,0,1,1,1,1), -- Corroded Mail Armor
(@GreyTBC+2,25374,0,1,1,1,1), -- Corroded Mail Belt
(@GreyTBC+2,25375,0,1,1,1,1), -- Corroded Mail Boots
(@GreyTBC+2,25376,0,1,1,1,1), -- Corroded Mail Bracers
(@GreyTBC+2,25377,0,1,1,1,1), -- Corroded Mail Circlet
(@GreyTBC+2,25378,0,1,1,1,1), -- Corroded Mail Gloves
(@GreyTBC+2,25379,0,1,1,1,1), -- Corroded Mail Pants
(@GreyTBC+2,25380,0,1,1,1,1), -- Corroded Mail Shoulderpads
(@GreyTBC+2,25389,0,1,1,1,1), -- Deteriorating Plate Belt
(@GreyTBC+2,25390,0,1,1,1,1), -- Deteriorating Plate Boots
(@GreyTBC+2,25391,0,1,1,1,1), -- Deteriorating Plate Bracers
(@GreyTBC+2,25392,0,1,1,1,1), -- Deteriorating Plate Chestpiece
(@GreyTBC+2,25393,0,1,1,1,1), -- Deteriorating Plate Gloves
(@GreyTBC+2,25394,0,1,1,1,1), -- Deteriorating Plate Helmet
(@GreyTBC+2,25395,0,1,1,1,1), -- Deteriorating Plate Pants
(@GreyTBC+2,25396,0,1,1,1,1); -- Deteriorating Plate Shoulderpads
-- --------------------------------------------------------
-- TBC_Greens_References
-- --------------------------------------------------------
SET @GreenTBC := 4100; -- reference starting value TDB Field
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @GreenTBC AND @GreenTBC+13;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- lvl 57 ilvl 81 greens (55 items) TBC
(@GreenTBC,25296,0,1,1,1,1), -- Absorption Dagger
(@GreenTBC,25324,0,1,1,1,1), -- Angerstaff
(@GreenTBC,25058,0,1,1,1,1), -- Anglesite Choker
(@GreenTBC,25240,0,1,1,1,1), -- Azerothian Longbow
(@GreenTBC,28531,0,1,1,1,1), -- Barbed Shrike
(@GreenTBC,24700,0,1,1,1,1), -- Bonechewer Bands
(@GreenTBC,24695,0,1,1,1,1), -- Bonechewer Chestpiece
(@GreenTBC,24693,0,1,1,1,1), -- Bonechewer Pelt-Girdle
(@GreenTBC,24698,0,1,1,1,1), -- Bonechewer Ripleggings
(@GreenTBC,24699,0,1,1,1,1), -- Bonechewer Shoulderguards
(@GreenTBC,24694,0,1,1,1,1), -- Bonechewer Shredboots
(@GreenTBC,24697,0,1,1,1,1), -- Bonechewer Skincloak
(@GreenTBC,24696,0,1,1,1,1), -- Bonechewer Spikegloves
(@GreenTBC,25114,0,1,1,1,1), -- Doomsayer's Mace
(@GreenTBC,25086,0,1,1,1,1), -- Dreamseeker Dandelion
(@GreenTBC,24920,0,1,1,1,1), -- Grimscale Armor
(@GreenTBC,24918,0,1,1,1,1), -- Grimscale Belt
(@GreenTBC,24921,0,1,1,1,1), -- Grimscale Gauntlets
(@GreenTBC,24922,0,1,1,1,1), -- Grimscale Helm
(@GreenTBC,24923,0,1,1,1,1), -- Grimscale Legguards
(@GreenTBC,24924,0,1,1,1,1), -- Grimscale Pauldrons
(@GreenTBC,24919,0,1,1,1,1), -- Grimscale Sabatons
(@GreenTBC,24925,0,1,1,1,1), -- Grimscale Vambraces
(@GreenTBC,25198,0,1,1,1,1), -- Karaborian Battle Axe
(@GreenTBC,25268,0,1,1,1,1), -- Lead-Slug Shotgun
(@GreenTBC,25100,0,1,1,1,1), -- Liege Blade
(@GreenTBC,25212,0,1,1,1,1), -- Lucky Strike Axe
(@GreenTBC,25282,0,1,1,1,1), -- Mahogany Wand
(@GreenTBC,25310,0,1,1,1,1), -- Naaru Lightmace
(@GreenTBC,25072,0,1,1,1,1), -- Northman's Shield
(@GreenTBC,24582,0,1,1,1,1), -- Outlander's Boots
(@GreenTBC,24588,0,1,1,1,1), -- Outlander's Bracers
(@GreenTBC,24585,0,1,1,1,1), -- Outlander's Facewrap
(@GreenTBC,24575,0,1,1,1,1), -- Outlander's Girdle
(@GreenTBC,24584,0,1,1,1,1), -- Outlander's Gloves
(@GreenTBC,24586,0,1,1,1,1), -- Outlander's Leggings
(@GreenTBC,24587,0,1,1,1,1), -- Outlander's Pauldrons
(@GreenTBC,24583,0,1,1,1,1), -- Outlander's Tunic
(@GreenTBC,25170,0,1,1,1,1), -- Rattan Bo Staff
(@GreenTBC,25184,0,1,1,1,1), -- Ravager Claws
(@GreenTBC,25156,0,1,1,1,1), -- Royal Crusader Sword
(@GreenTBC,25044,0,1,1,1,1), -- Rubellite Ring
(@GreenTBC,25128,0,1,1,1,1), -- Shining Mace
(@GreenTBC,25030,0,1,1,1,1), -- Silky Velvet Cloak
(@GreenTBC,25142,0,1,1,1,1), -- Telaari Longblade
(@GreenTBC,25254,0,1,1,1,1), -- Tower Crossbow
(@GreenTBC,24813,0,1,1,1,1), -- Unyielding Bindings
(@GreenTBC,24808,0,1,1,1,1), -- Unyielding Chain Vest
(@GreenTBC,24809,0,1,1,1,1), -- Unyielding Fists
(@GreenTBC,24807,0,1,1,1,1), -- Unyielding Footwraps
(@GreenTBC,24810,0,1,1,1,1), -- Unyielding Helm
(@GreenTBC,24811,0,1,1,1,1), -- Unyielding Leggings
(@GreenTBC,24812,0,1,1,1,1), -- Unyielding Spaulders
(@GreenTBC,24806,0,1,1,1,1), -- Unyielding Waistband
(@GreenTBC,25226,0,1,1,1,1), -- War Scythe
-- lvl 58 ilvl 84 greens (55 items) TBC
(@GreenTBC+1,24926,0,1,1,1,1), -- Ango'rosh Belt
(@GreenTBC+1,24928,0,1,1,1,1), -- Ango'rosh Breastplate
(@GreenTBC+1,24929,0,1,1,1,1), -- Ango'rosh Gauntlets
(@GreenTBC+1,24930,0,1,1,1,1), -- Ango'rosh Helm
(@GreenTBC+1,24931,0,1,1,1,1), -- Ango'rosh Legguards
(@GreenTBC+1,24932,0,1,1,1,1), -- Ango'rosh Pauldrons
(@GreenTBC+1,24927,0,1,1,1,1), -- Ango'rosh Sabatons
(@GreenTBC+1,24933,0,1,1,1,1), -- Ango'rosh Vambraces
(@GreenTBC+1,25241,0,1,1,1,1), -- Ashenvale Longbow
(@GreenTBC+1,25045,0,1,1,1,1), -- Azurite Ring
(@GreenTBC+1,25087,0,1,1,1,1), -- Bleeding Eye
(@GreenTBC+1,25325,0,1,1,1,1), -- Brutal Scar-Limb
(@GreenTBC+1,25101,0,1,1,1,1), -- Cross Pommel Dagger
(@GreenTBC+1,25283,0,1,1,1,1), -- Crystallized Ebony Wand
(@GreenTBC+1,25073,0,1,1,1,1), -- Emperor Shield
(@GreenTBC+1,24821,0,1,1,1,1), -- Felstone Bindings
(@GreenTBC+1,24816,0,1,1,1,1), -- Felstone Chain Vest
(@GreenTBC+1,24817,0,1,1,1,1), -- Felstone Gauntlets
(@GreenTBC+1,24815,0,1,1,1,1), -- Felstone Greaves
(@GreenTBC+1,24818,0,1,1,1,1), -- Felstone Helm
(@GreenTBC+1,24819,0,1,1,1,1), -- Felstone Leggings
(@GreenTBC+1,24820,0,1,1,1,1), -- Felstone Spaulders
(@GreenTBC+1,24814,0,1,1,1,1), -- Felstone Waistband
(@GreenTBC+1,25213,0,1,1,1,1), -- Fel-Touched Axe
(@GreenTBC+1,25059,0,1,1,1,1), -- Fire Opal Collar
(@GreenTBC+1,24590,0,1,1,1,1), -- Fireheart Boots
(@GreenTBC+1,24596,0,1,1,1,1), -- Fireheart Bracers
(@GreenTBC+1,24591,0,1,1,1,1), -- Fireheart Chestpiece
(@GreenTBC+1,24589,0,1,1,1,1), -- Fireheart Girdle
(@GreenTBC+1,24592,0,1,1,1,1), -- Fireheart Gloves
(@GreenTBC+1,24594,0,1,1,1,1), -- Fireheart Leggings
(@GreenTBC+1,24595,0,1,1,1,1), -- Fireheart Shoulderpads
(@GreenTBC+1,24593,0,1,1,1,1), -- Fireheart Skullcap
(@GreenTBC+1,25129,0,1,1,1,1), -- Giant's Leg Bone
(@GreenTBC+1,24708,0,1,1,1,1), -- Haal'eshi Bindings
(@GreenTBC+1,24702,0,1,1,1,1), -- Haal'eshi Boots
(@GreenTBC+1,24701,0,1,1,1,1), -- Haal'eshi Cord
(@GreenTBC+1,24704,0,1,1,1,1), -- Haal'eshi Gloves
(@GreenTBC+1,24705,0,1,1,1,1), -- Haal'eshi Hat
(@GreenTBC+1,24703,0,1,1,1,1), -- Haal'eshi Jerkin
(@GreenTBC+1,24706,0,1,1,1,1), -- Haal'eshi Leggings
(@GreenTBC+1,24707,0,1,1,1,1), -- Haal'eshi Pauldrons
(@GreenTBC+1,25199,0,1,1,1,1), -- Knight's War Axe
(@GreenTBC+1,25269,0,1,1,1,1), -- Longbeard Rifle
(@GreenTBC+1,25255,0,1,1,1,1), -- Ram's Head Crossbow
(@GreenTBC+1,25311,0,1,1,1,1), -- Revitalizing Hammer
(@GreenTBC+1,25115,0,1,1,1,1), -- Riversong Mace
(@GreenTBC+1,25157,0,1,1,1,1), -- Serpentlord Claymore
(@GreenTBC+1,25227,0,1,1,1,1), -- Sha'tari Longspear
(@GreenTBC+1,25143,0,1,1,1,1), -- Silver Hand Blade
(@GreenTBC+1,28532,0,1,1,1,1), -- Silver Throwing Knives
(@GreenTBC+1,25031,0,1,1,1,1), -- Silvermoon Royal Cloak
(@GreenTBC+1,25171,0,1,1,1,1), -- Straight Hardwood Staff
(@GreenTBC+1,25185,0,1,1,1,1), -- Thrasher Blades
(@GreenTBC+1,25297,0,1,1,1,1), -- Tuning Knife
-- lvl 59 ilvl 87 greens (55 items) TBC
(@GreenTBC+2,25298,0,1,1,1,1), -- Combustion Dagger
(@GreenTBC+2,24934,0,1,1,1,1), -- Darkcrest Belt
(@GreenTBC+2,24941,0,1,1,1,1), -- Darkcrest Bracers
(@GreenTBC+2,24936,0,1,1,1,1), -- Darkcrest Breastplate
(@GreenTBC+2,24937,0,1,1,1,1), -- Darkcrest Gauntlets
(@GreenTBC+2,24938,0,1,1,1,1), -- Darkcrest Helm
(@GreenTBC+2,24939,0,1,1,1,1), -- Darkcrest Legguards
(@GreenTBC+2,24940,0,1,1,1,1), -- Darkcrest Pauldrons
(@GreenTBC+2,24935,0,1,1,1,1), -- Darkcrest Sabatons
(@GreenTBC+2,25312,0,1,1,1,1), -- Glorious Scepter
(@GreenTBC+2,25270,0,1,1,1,1), -- Gnomish Assault Rifle
(@GreenTBC+2,25130,0,1,1,1,1), -- Gronn-Bone Club
(@GreenTBC+2,25228,0,1,1,1,1), -- Halberd Polearm
(@GreenTBC+2,25032,0,1,1,1,1), -- Hellfire Cloak
(@GreenTBC+2,25102,0,1,1,1,1), -- Jaedenis Dagger
(@GreenTBC+2,25200,0,1,1,1,1), -- Jagged Broadaxe
(@GreenTBC+2,25172,0,1,1,1,1), -- Jinbali Warp-Staff
(@GreenTBC+2,25088,0,1,1,1,1), -- Laughing Skull Orb
(@GreenTBC+2,25214,0,1,1,1,1), -- Mok'Nathal Battleaxe
(@GreenTBC+2,24824,0,1,1,1,1), -- Netherstalker Armor
(@GreenTBC+2,24822,0,1,1,1,1), -- Netherstalker Belt
(@GreenTBC+2,24829,0,1,1,1,1), -- Netherstalker Bracer
(@GreenTBC+2,24825,0,1,1,1,1), -- Netherstalker Gloves
(@GreenTBC+2,24823,0,1,1,1,1), -- Netherstalker Greaves
(@GreenTBC+2,24826,0,1,1,1,1), -- Netherstalker Helmet
(@GreenTBC+2,24827,0,1,1,1,1), -- Netherstalker Legguards
(@GreenTBC+2,24828,0,1,1,1,1), -- Netherstalker Mantle
(@GreenTBC+2,25116,0,1,1,1,1), -- Pneumatic War Hammer
(@GreenTBC+2,25326,0,1,1,1,1), -- Primal Lore-Staff
(@GreenTBC+2,25284,0,1,1,1,1), -- Purpleheart Wand
(@GreenTBC+2,25158,0,1,1,1,1), -- Skeletal Broadsword
(@GreenTBC+2,25144,0,1,1,1,1), -- Skettis Curved Blade
(@GreenTBC+2,25046,0,1,1,1,1), -- Spined Ring
(@GreenTBC+2,24601,0,1,1,1,1), -- Starfire Circlet
(@GreenTBC+2,24600,0,1,1,1,1), -- Starfire Gloves
(@GreenTBC+2,24603,0,1,1,1,1), -- Starfire Mantle
(@GreenTBC+2,24598,0,1,1,1,1), -- Starfire Sandals
(@GreenTBC+2,24597,0,1,1,1,1), -- Starfire Sash
(@GreenTBC+2,24602,0,1,1,1,1), -- Starfire Trousers
(@GreenTBC+2,24599,0,1,1,1,1), -- Starfire Vest
(@GreenTBC+2,24604,0,1,1,1,1), -- Starfire Wristwraps
(@GreenTBC+2,25256,0,1,1,1,1), -- Stronghold Crossbow
(@GreenTBC+2,25060,0,1,1,1,1), -- Sunstone Necklace
(@GreenTBC+2,25242,0,1,1,1,1), -- Telaari Longbow
(@GreenTBC+2,25074,0,1,1,1,1), -- Telaari Shield
(@GreenTBC+2,25186,0,1,1,1,1), -- Vampiric Handscythes
(@GreenTBC+2,24716,0,1,1,1,1), -- Vengeance Bands
(@GreenTBC+2,24709,0,1,1,1,1), -- Vengeance Belt
(@GreenTBC+2,24710,0,1,1,1,1), -- Vengeance Boots
(@GreenTBC+2,24711,0,1,1,1,1), -- Vengeance Chestpiece
(@GreenTBC+2,24712,0,1,1,1,1), -- Vengeance Gloves
(@GreenTBC+2,24713,0,1,1,1,1), -- Vengeance Helm
(@GreenTBC+2,24714,0,1,1,1,1), -- Vengeance Legguards
(@GreenTBC+2,24715,0,1,1,1,1), -- Vengeance Pauldrons
(@GreenTBC+2,28533,0,1,1,1,1), -- Wooden Boomerang
-- lvl 60 ilvl 90 greens (51 items) TBC
(@GreenTBC+3,24605,0,1,1,1,1), -- Laughing Skull Waistguard
(@GreenTBC+3,24606,0,1,1,1,1), -- Laughing Skull Boot
(@GreenTBC+3,24607,0,1,1,1,1), -- Laughing Skull Tunic
(@GreenTBC+3,24608,0,1,1,1,1), -- Laughing Skull Gloves
(@GreenTBC+3,24609,0,1,1,1,1), -- Laughing Skull Cap
(@GreenTBC+3,24610,0,1,1,1,1), -- Laughing Skull Pants
(@GreenTBC+3,24611,0,1,1,1,1), -- Laughing Skull Shoulderpads
(@GreenTBC+3,24612,0,1,1,1,1), -- Laughing Skull Bracelets
(@GreenTBC+3,24717,0,1,1,1,1), -- Dreghood Belt
(@GreenTBC+3,24718,0,1,1,1,1), -- Dreghood Boots
(@GreenTBC+3,24719,0,1,1,1,1), -- Dreghood Chestpiece
(@GreenTBC+3,24720,0,1,1,1,1), -- Dreghood Gloves
(@GreenTBC+3,24721,0,1,1,1,1), -- Dreghood Cowl
(@GreenTBC+3,24722,0,1,1,1,1), -- Dreghood Trousers
(@GreenTBC+3,24723,0,1,1,1,1), -- Dreghood Pauldrons
(@GreenTBC+3,24724,0,1,1,1,1), -- Dreghood Bands
(@GreenTBC+3,24830,0,1,1,1,1), -- Nexus-Strider Belt
(@GreenTBC+3,24831,0,1,1,1,1), -- Nexus-Strider Greaves
(@GreenTBC+3,24832,0,1,1,1,1), -- Nexus-Strider Breastplate
(@GreenTBC+3,24833,0,1,1,1,1), -- Nexus-Strider Gloves
(@GreenTBC+3,24834,0,1,1,1,1), -- Nexus-Strider Helmet
(@GreenTBC+3,24835,0,1,1,1,1), -- Nexus-Strider Legwraps
(@GreenTBC+3,24836,0,1,1,1,1), -- Nexus-Strider Mantle
(@GreenTBC+3,24837,0,1,1,1,1), -- Nexus-Strider Bracer
(@GreenTBC+3,24942,0,1,1,1,1), -- Bloodscale Belt
(@GreenTBC+3,24943,0,1,1,1,1), -- Bloodscale Sabatons
(@GreenTBC+3,24944,0,1,1,1,1), -- Bloodscale Breastplate
(@GreenTBC+3,24945,0,1,1,1,1), -- Bloodscale Gauntlets
(@GreenTBC+3,24946,0,1,1,1,1), -- Bloodscale Helm
(@GreenTBC+3,24947,0,1,1,1,1), -- Bloodscale Legguards
(@GreenTBC+3,24948,0,1,1,1,1), -- Bloodscale Pauldrons
(@GreenTBC+3,24949,0,1,1,1,1), -- Bloodscale Bracers
(@GreenTBC+3,25033,0,1,1,1,1), -- Scavenger's Cloak
(@GreenTBC+3,25047,0,1,1,1,1), -- Tourmaline Loop
(@GreenTBC+3,25061,0,1,1,1,1), -- Hiddenite Necklace
(@GreenTBC+3,25075,0,1,1,1,1), -- Hardened Steel Shield
(@GreenTBC+3,25089,0,1,1,1,1), -- Supplicant's Rod
(@GreenTBC+3,25103,0,1,1,1,1), -- Nightstalker Dagger
(@GreenTBC+3,25117,0,1,1,1,1), -- Flanged Battle Mace
(@GreenTBC+3,25131,0,1,1,1,1), -- Hateful Bludgeon
(@GreenTBC+3,25187,0,1,1,1,1), -- Shekketh Talons
(@GreenTBC+3,25201,0,1,1,1,1), -- Reaver's Sickle
(@GreenTBC+3,25215,0,1,1,1,1), -- Spiked Battle Axe
(@GreenTBC+3,25229,0,1,1,1,1), -- Partisan Polearm
(@GreenTBC+3,25243,0,1,1,1,1), -- Windtalker Bow
(@GreenTBC+3,25257,0,1,1,1,1), -- Citadel Crossbow
(@GreenTBC+3,25271,0,1,1,1,1), -- Croc-Hunter's Rifle
(@GreenTBC+3,25299,0,1,1,1,1), -- Siphoning Dagger
(@GreenTBC+3,25313,0,1,1,1,1), -- Cold-Iron Scepter
(@GreenTBC+3,25327,0,1,1,1,1), -- Frenzied Staff
(@GreenTBC+3,28534,0,1,1,1,1), -- Fel Tipped Dart
-- lvl 61 ilvl 93 greens (55 items) TBC
(@GreenTBC+4,24613,0,1,1,1,1), -- Vindicator Belt
(@GreenTBC+4,24614,0,1,1,1,1), -- Vindicator Boots
(@GreenTBC+4,24615,0,1,1,1,1), -- Vindicator Tunic
(@GreenTBC+4,24616,0,1,1,1,1), -- Vindicator Gloves
(@GreenTBC+4,24617,0,1,1,1,1), -- Vindicator Cap
(@GreenTBC+4,24618,0,1,1,1,1), -- Vindicator Pants
(@GreenTBC+4,24619,0,1,1,1,1), -- Vindicator Shoulderpads
(@GreenTBC+4,24620,0,1,1,1,1), -- Vindicator Bracers
(@GreenTBC+4,24725,0,1,1,1,1), -- Dementia Cord
(@GreenTBC+4,24726,0,1,1,1,1), -- Dementia Boots
(@GreenTBC+4,24727,0,1,1,1,1), -- Dementia Vest
(@GreenTBC+4,24728,0,1,1,1,1), -- Dementia Gloves
(@GreenTBC+4,24729,0,1,1,1,1), -- Dementia Hood
(@GreenTBC+4,24730,0,1,1,1,1), -- Dementia Trousers
(@GreenTBC+4,24731,0,1,1,1,1), -- Dementia Shoulderguards
(@GreenTBC+4,24732,0,1,1,1,1), -- Dementia Armguards
(@GreenTBC+4,24838,0,1,1,1,1), -- Wrathfin Waistband
(@GreenTBC+4,24839,0,1,1,1,1), -- Wrathfin Greaves
(@GreenTBC+4,24840,0,1,1,1,1), -- Wrathfin Armor
(@GreenTBC+4,24841,0,1,1,1,1), -- Wrathfin Gloves
(@GreenTBC+4,24842,0,1,1,1,1), -- Wrathfin Helmet
(@GreenTBC+4,24843,0,1,1,1,1), -- Wrathfin Legguards
(@GreenTBC+4,24844,0,1,1,1,1), -- Wrathfin Mantle
(@GreenTBC+4,24845,0,1,1,1,1), -- Wrathfin Bindings
(@GreenTBC+4,24950,0,1,1,1,1), -- Bogslayer Belt
(@GreenTBC+4,24951,0,1,1,1,1), -- Bogslayer Sabatons
(@GreenTBC+4,24952,0,1,1,1,1), -- Bogslayer Breastplate
(@GreenTBC+4,24953,0,1,1,1,1), -- Bogslayer Gauntlets
(@GreenTBC+4,24954,0,1,1,1,1), -- Bogslayer Helm
(@GreenTBC+4,24955,0,1,1,1,1), -- Bogslayer Legplates
(@GreenTBC+4,24956,0,1,1,1,1), -- Bogslayer Pauldrons
(@GreenTBC+4,24957,0,1,1,1,1), -- Bogslayer Bracers
(@GreenTBC+4,25034,0,1,1,1,1), -- Elementalist Cloak
(@GreenTBC+4,25048,0,1,1,1,1), -- Smoky Quartz Ring
(@GreenTBC+4,25062,0,1,1,1,1), -- Zircon Amulet
(@GreenTBC+4,25076,0,1,1,1,1), -- Screaming Shield
(@GreenTBC+4,25090,0,1,1,1,1), -- Slavehandler Rod
(@GreenTBC+4,25104,0,1,1,1,1), -- Anzac Dagger
(@GreenTBC+4,25118,0,1,1,1,1), -- Battle Star
(@GreenTBC+4,25132,0,1,1,1,1), -- Thrallmar War Hammer
(@GreenTBC+4,25146,0,1,1,1,1), -- Light-Etched Longsword
(@GreenTBC+4,25160,0,1,1,1,1), -- Vengeance Blade
(@GreenTBC+4,25174,0,1,1,1,1), -- Hanbo Staff
(@GreenTBC+4,25188,0,1,1,1,1), -- Spleenripper Claws
(@GreenTBC+4,25202,0,1,1,1,1), -- Kingly Axe
(@GreenTBC+4,25216,0,1,1,1,1), -- Ogre Splitting Axe
(@GreenTBC+4,25230,0,1,1,1,1), -- Voulge Blade
(@GreenTBC+4,25244,0,1,1,1,1), -- Viper Bow
(@GreenTBC+4,25258,0,1,1,1,1), -- Repeater Crossbow
(@GreenTBC+4,25272,0,1,1,1,1), -- PC-54 Shotgun
(@GreenTBC+4,25286,0,1,1,1,1), -- Yew Wand
(@GreenTBC+4,25300,0,1,1,1,1), -- Lightning Dagger
(@GreenTBC+4,25314,0,1,1,1,1), -- Ceremonial Hammer
(@GreenTBC+4,25328,0,1,1,1,1), -- Faerie-Kind Staff
(@GreenTBC+4,28535,0,1,1,1,1), -- Amani Throwing Axe
-- lvl 62 ilvl 96 greens (55 items) TBC
(@GreenTBC+5,24621,0,1,1,1,1), -- Slavehandler Belt
(@GreenTBC+5,24622,0,1,1,1,1), -- Slavehandler Footpads
(@GreenTBC+5,24623,0,1,1,1,1), -- Slavehandler Jerkin
(@GreenTBC+5,24624,0,1,1,1,1), -- Slavehandler Handwraps
(@GreenTBC+5,24625,0,1,1,1,1), -- Slavehandler Cap
(@GreenTBC+5,24626,0,1,1,1,1), -- Slavehandler Pants
(@GreenTBC+5,24627,0,1,1,1,1), -- Slavehandler Amice
(@GreenTBC+5,24628,0,1,1,1,1), -- Slavehandler Wristguards
(@GreenTBC+5,24733,0,1,1,1,1), -- Sunroc Waistband
(@GreenTBC+5,24734,0,1,1,1,1), -- Sunroc Boots
(@GreenTBC+5,24735,0,1,1,1,1), -- Sunroc Chestpiece
(@GreenTBC+5,24736,0,1,1,1,1), -- Sunroc Gloves
(@GreenTBC+5,24737,0,1,1,1,1), -- Sunroc Mask
(@GreenTBC+5,24738,0,1,1,1,1), -- Sunroc Pants
(@GreenTBC+5,24739,0,1,1,1,1), -- Sunroc Shoulderguards
(@GreenTBC+5,24740,0,1,1,1,1), -- Sunroc Armguards
(@GreenTBC+5,24846,0,1,1,1,1), -- Fenclaw Waistband
(@GreenTBC+5,24847,0,1,1,1,1), -- Fenclaw Footwraps
(@GreenTBC+5,24848,0,1,1,1,1), -- Fenclaw Armor
(@GreenTBC+5,24849,0,1,1,1,1), -- Fenclaw Fists
(@GreenTBC+5,24850,0,1,1,1,1), -- Fenclaw Helm
(@GreenTBC+5,24851,0,1,1,1,1), -- Fenclaw Legguards
(@GreenTBC+5,24852,0,1,1,1,1), -- Fenclaw Mantle
(@GreenTBC+5,24853,0,1,1,1,1), -- Fenclaw Bindings
(@GreenTBC+5,24958,0,1,1,1,1), -- Khan'aish Girdle
(@GreenTBC+5,24959,0,1,1,1,1), -- Khan'aish Greaves
(@GreenTBC+5,24960,0,1,1,1,1), -- Khan'aish Breastplate
(@GreenTBC+5,24961,0,1,1,1,1), -- Khan'aish Gloves
(@GreenTBC+5,24962,0,1,1,1,1), -- Khan'aish Helmet
(@GreenTBC+5,24963,0,1,1,1,1), -- Khan'aish Legplates
(@GreenTBC+5,24964,0,1,1,1,1), -- Khan'aish Epaulets
(@GreenTBC+5,24965,0,1,1,1,1), -- Khan'aish Bracers
(@GreenTBC+5,25035,0,1,1,1,1), -- Silver-Lined Cloak
(@GreenTBC+5,25049,0,1,1,1,1), -- Scheelite Ring
(@GreenTBC+5,25063,0,1,1,1,1), -- Multi-Colored Beads
(@GreenTBC+5,25077,0,1,1,1,1), -- Modani War-Shield
(@GreenTBC+5,25091,0,1,1,1,1), -- Mistyreed Torch
(@GreenTBC+5,25105,0,1,1,1,1), -- Arachnid Dagger
(@GreenTBC+5,25119,0,1,1,1,1), -- Silvermoon War-Mace
(@GreenTBC+5,25133,0,1,1,1,1), -- Stormwind Maul
(@GreenTBC+5,25147,0,1,1,1,1), -- Skystrider Katana
(@GreenTBC+5,25161,0,1,1,1,1), -- Dragon Wing Blade
(@GreenTBC+5,25175,0,1,1,1,1), -- Demoniac Longstaff
(@GreenTBC+5,25189,0,1,1,1,1), -- Ironspine Point
(@GreenTBC+5,25203,0,1,1,1,1), -- Chipped Woodchopper
(@GreenTBC+5,25217,0,1,1,1,1), -- Sundering Axe
(@GreenTBC+5,25231,0,1,1,1,1), -- Fel-Wrought Halberd
(@GreenTBC+5,25245,0,1,1,1,1), -- Razorsong Bow
(@GreenTBC+5,25259,0,1,1,1,1), -- Collapsible Crossbow
(@GreenTBC+5,25273,0,1,1,1,1), -- Sawed-Off Shotgun
(@GreenTBC+5,25287,0,1,1,1,1), -- Magician's Wand
(@GreenTBC+5,25301,0,1,1,1,1), -- Shattering Dagger
(@GreenTBC+5,25315,0,1,1,1,1), -- Restorative Mace
(@GreenTBC+5,25329,0,1,1,1,1), -- Tranquility Staff
(@GreenTBC+5,28536,0,1,1,1,1), -- Jagged Guillotine
-- lvl 63 ilvl 99 greens (55 items) TBC
(@GreenTBC+6,24629,0,1,1,1,1), -- Feralfen Sash
(@GreenTBC+6,24630,0,1,1,1,1), -- Feralfen Sandals
(@GreenTBC+6,24631,0,1,1,1,1), -- Feralfen Jerkin
(@GreenTBC+6,24632,0,1,1,1,1), -- Feralfen Hand
(@GreenTBC+6,24633,0,1,1,1,1), -- Feralfen Hood
(@GreenTBC+6,24634,0,1,1,1,1), -- Feralfen Pants
(@GreenTBC+6,24635,0,1,1,1,1), -- Feralfen Amice
(@GreenTBC+6,24636,0,1,1,1,1), -- Feralfen Cuffs
(@GreenTBC+6,24741,0,1,1,1,1), -- Ranger Belt
(@GreenTBC+6,24742,0,1,1,1,1), -- Ranger Boots
(@GreenTBC+6,24743,0,1,1,1,1), -- Ranger Jerkin
(@GreenTBC+6,24744,0,1,1,1,1), -- Ranger Gloves
(@GreenTBC+6,24745,0,1,1,1,1), -- Ranger Hat
(@GreenTBC+6,24746,0,1,1,1,1), -- Ranger Pants
(@GreenTBC+6,24747,0,1,1,1,1), -- Ranger Pauldrons
(@GreenTBC+6,24748,0,1,1,1,1), -- Ranger Armguards
(@GreenTBC+6,24854,0,1,1,1,1), -- Marshcreeper Belt
(@GreenTBC+6,24855,0,1,1,1,1), -- Marshcreeper Sludgeboots
(@GreenTBC+6,24856,0,1,1,1,1), -- Marshcreeper Fen-Vest
(@GreenTBC+6,24857,0,1,1,1,1), -- Marshcreeper Gloves
(@GreenTBC+6,24858,0,1,1,1,1), -- Marshcreeper Helm
(@GreenTBC+6,24859,0,1,1,1,1), -- Marshcreeper Leggings
(@GreenTBC+6,24860,0,1,1,1,1), -- Marshcreeper Mantle
(@GreenTBC+6,24861,0,1,1,1,1), -- Marshcreeper Bracelets
(@GreenTBC+6,24966,0,1,1,1,1), -- Talonguard Girdle
(@GreenTBC+6,24967,0,1,1,1,1), -- Talonguard Greaves
(@GreenTBC+6,24968,0,1,1,1,1), -- Talonguard Armor
(@GreenTBC+6,24969,0,1,1,1,1), -- Talonguard Gloves
(@GreenTBC+6,24970,0,1,1,1,1), -- Talonguard Helmet
(@GreenTBC+6,24971,0,1,1,1,1), -- Talonguard Legplates
(@GreenTBC+6,24972,0,1,1,1,1), -- Talonguard Epaulets
(@GreenTBC+6,24973,0,1,1,1,1), -- Talonguard Bracers
(@GreenTBC+6,25036,0,1,1,1,1), -- Boulderfist Cloak
(@GreenTBC+6,25050,0,1,1,1,1), -- Moldavite Ring
(@GreenTBC+6,25064,0,1,1,1,1), -- Amethyst Pendant
(@GreenTBC+6,25078,0,1,1,1,1), -- Zangari Shield
(@GreenTBC+6,25092,0,1,1,1,1), -- Consortium Crystal
(@GreenTBC+6,25106,0,1,1,1,1), -- Cobra Shortblade
(@GreenTBC+6,25120,0,1,1,1,1), -- Rockshard Club
(@GreenTBC+6,25134,0,1,1,1,1), -- Highmountain Hammer
(@GreenTBC+6,25148,0,1,1,1,1), -- Bone Collector Sword
(@GreenTBC+6,25162,0,1,1,1,1), -- Darkened Broadsword
(@GreenTBC+6,25176,0,1,1,1,1), -- Taiji Quarterstaff
(@GreenTBC+6,25190,0,1,1,1,1), -- Wight's Claws
(@GreenTBC+6,25204,0,1,1,1,1), -- Colossal War Axe
(@GreenTBC+6,25218,0,1,1,1,1), -- Silver-Edged Axe
(@GreenTBC+6,25232,0,1,1,1,1), -- War Glaive
(@GreenTBC+6,25246,0,1,1,1,1), -- Thalassian Compound Bow
(@GreenTBC+6,25260,0,1,1,1,1), -- Archer's Crossbow
(@GreenTBC+6,25274,0,1,1,1,1), -- Cliffjumper Shotgun
(@GreenTBC+6,25288,0,1,1,1,1), -- Conjurer's Wand
(@GreenTBC+6,25302,0,1,1,1,1), -- Soul-Drain Dagger
(@GreenTBC+6,25316,0,1,1,1,1), -- Spirit-Clad Mace
(@GreenTBC+6,25330,0,1,1,1,1), -- Starshine Staff
(@GreenTBC+6,28537,0,1,1,1,1), -- Wildhammer Throwing Axe
-- lvl 67 ilvl 111 greens (55 items) TBC
(@GreenTBC+10,24661,0,1,1,1,1), -- Shadow Council Chain
(@GreenTBC+10,24662,0,1,1,1,1), -- Shadow Council Boots
(@GreenTBC+10,24663,0,1,1,1,1), -- Shadow Council Tunic
(@GreenTBC+10,24664,0,1,1,1,1), -- Shadow Council Gloves
(@GreenTBC+10,24665,0,1,1,1,1), -- Shadow Council Cowl
(@GreenTBC+10,24666,0,1,1,1,1), -- Shadow Council Pants
(@GreenTBC+10,24667,0,1,1,1,1), -- Shadow Council Mantle
(@GreenTBC+10,24668,0,1,1,1,1), -- Shadow Council Bracer
(@GreenTBC+10,24773,0,1,1,1,1), -- Boneshredder Belt
(@GreenTBC+10,24774,0,1,1,1,1), -- Boneshredder Boots
(@GreenTBC+10,24775,0,1,1,1,1), -- Boneshredder Jerkin
(@GreenTBC+10,24776,0,1,1,1,1), -- Boneshredder Gloves
(@GreenTBC+10,24777,0,1,1,1,1), -- Boneshredder Skullcap
(@GreenTBC+10,24778,0,1,1,1,1), -- Boneshredder Britches
(@GreenTBC+10,24779,0,1,1,1,1), -- Boneshredder Shoulderguards
(@GreenTBC+10,24780,0,1,1,1,1), -- Boneshredder Wristguards
(@GreenTBC+10,24886,0,1,1,1,1), -- Skettis Belt
(@GreenTBC+10,24887,0,1,1,1,1), -- Skettis Footwraps
(@GreenTBC+10,24888,0,1,1,1,1), -- Skettis Chestpiece
(@GreenTBC+10,24889,0,1,1,1,1), -- Skettis Gauntlets
(@GreenTBC+10,24890,0,1,1,1,1), -- Skettis Helmet
(@GreenTBC+10,24891,0,1,1,1,1), -- Skettis Legguards
(@GreenTBC+10,24892,0,1,1,1,1), -- Skettis Spaulders
(@GreenTBC+10,24893,0,1,1,1,1), -- Skettis Bracer
(@GreenTBC+10,24998,0,1,1,1,1), -- Bloodfist Girdle
(@GreenTBC+10,24999,0,1,1,1,1), -- Bloodfist Greaves
(@GreenTBC+10,25000,0,1,1,1,1), -- Bloodfist Breastplate
(@GreenTBC+10,25001,0,1,1,1,1), -- Bloodfist Gloves
(@GreenTBC+10,25002,0,1,1,1,1), -- Bloodfist Helmet
(@GreenTBC+10,25003,0,1,1,1,1), -- Bloodfist Legplates
(@GreenTBC+10,25004,0,1,1,1,1), -- Bloodfist Epaulets
(@GreenTBC+10,25005,0,1,1,1,1), -- Bloodfist Vambraces
(@GreenTBC+10,25040,0,1,1,1,1), -- Murkblood Cape
(@GreenTBC+10,25054,0,1,1,1,1), -- Sodalite Band
(@GreenTBC+10,25068,0,1,1,1,1), -- Kunzite Necklace
(@GreenTBC+10,25082,0,1,1,1,1), -- Fel-Iron Shield
(@GreenTBC+10,25096,0,1,1,1,1), -- Elementalist Star
(@GreenTBC+10,25110,0,1,1,1,1), -- Sharp Bowie Knife
(@GreenTBC+10,25124,0,1,1,1,1), -- Footman Mace
(@GreenTBC+10,25138,0,1,1,1,1), -- Blood Knight Maul
(@GreenTBC+10,25152,0,1,1,1,1), -- Howling Sword
(@GreenTBC+10,25166,0,1,1,1,1), -- Mok'Nathal Warblade
(@GreenTBC+10,25180,0,1,1,1,1), -- Calenda Fighting Stick
(@GreenTBC+10,25194,0,1,1,1,1), -- Serpent's Fangs
(@GreenTBC+10,25208,0,1,1,1,1), -- Bladespire Broadaxe
(@GreenTBC+10,25222,0,1,1,1,1), -- Ceremonial Slayer's Axe
(@GreenTBC+10,25236,0,1,1,1,1), -- Grim Scythe
(@GreenTBC+10,25250,0,1,1,1,1), -- Rocslayer Longbow
(@GreenTBC+10,25264,0,1,1,1,1), -- Pocket Ballista
(@GreenTBC+10,25278,0,1,1,1,1), -- Nesingwary Longrifle
(@GreenTBC+10,25292,0,1,1,1,1), -- Mechano-Wand
(@GreenTBC+10,25306,0,1,1,1,1), -- Permafrost Dagger
(@GreenTBC+10,25320,0,1,1,1,1), -- Queen's Insignia
(@GreenTBC+10,25334,0,1,1,1,1), -- Intimidating Greatstaff
(@GreenTBC+10,28541,0,1,1,1,1), -- Sawshrike
(@GreenTBC+10,30520,0,1,1,1,1), -- Gold-Trimmed Cuffs
(@GreenTBC+10,30986,0,1,1,1,1), -- Bloodforged Guard
-- lvl 68 ilvl 114 greens (55 items) TBC
(@GreenTBC+11,25055,0,1,1,1,1), -- Alexandrite Ring
(@GreenTBC+11,25139,0,1,1,1,1), -- Algaz Battle Hammer
(@GreenTBC+11,25209,0,1,1,1,1), -- Amani Tomahawk
(@GreenTBC+11,25041,0,1,1,1,1), -- Ambusher's Cloak
(@GreenTBC+11,25097,0,1,1,1,1), -- Astralaan Orb
(@GreenTBC+11,25265,0,1,1,1,1), -- Barreled Crossbow
(@GreenTBC+11,25008,0,1,1,1,1), -- Conqueror's Breastplate
(@GreenTBC+11,25012,0,1,1,1,1), -- Conqueror's Epaulets
(@GreenTBC+11,25009,0,1,1,1,1), -- Conqueror's Gauntlets
(@GreenTBC+11,25006,0,1,1,1,1), -- Conqueror's Girdle
(@GreenTBC+11,25007,0,1,1,1,1), -- Conqueror's Greaves
(@GreenTBC+11,25010,0,1,1,1,1), -- Conqueror's Helmet
(@GreenTBC+11,25011,0,1,1,1,1), -- Conqueror's Legplates
(@GreenTBC+11,25013,0,1,1,1,1), -- Conqueror's Vambraces
(@GreenTBC+11,25195,0,1,1,1,1), -- Diamond Tipped Claws
(@GreenTBC+11,25321,0,1,1,1,1), -- Divine Hammer
(@GreenTBC+11,25293,0,1,1,1,1), -- Draenethyst Wand
(@GreenTBC+11,24669,0,1,1,1,1), -- Eldr'naan Belt
(@GreenTBC+11,24670,0,1,1,1,1), -- Eldr'naan Boots
(@GreenTBC+11,24676,0,1,1,1,1), -- Eldr'naan Bracelets
(@GreenTBC+11,24672,0,1,1,1,1), -- Eldr'naan Gloves
(@GreenTBC+11,24673,0,1,1,1,1), -- Eldr'naan Hood
(@GreenTBC+11,24671,0,1,1,1,1), -- Eldr'naan Jerkin
(@GreenTBC+11,24674,0,1,1,1,1), -- Eldr'naan Pants
(@GreenTBC+11,24675,0,1,1,1,1), -- Eldr'naan Shoulderpads
(@GreenTBC+11,25069,0,1,1,1,1), -- Epidote Stone Necklace
(@GreenTBC+11,25335,0,1,1,1,1), -- Feral Warp-Staff
(@GreenTBC+11,25153,0,1,1,1,1), -- Gladiator Greatblade
(@GreenTBC+11,28542,0,1,1,1,1), -- Heartseeker Knives
(@GreenTBC+11,25111,0,1,1,1,1), -- Lionhead Dagger
(@GreenTBC+11,24781,0,1,1,1,1), -- Murkblood Belt
(@GreenTBC+11,24783,0,1,1,1,1), -- Murkblood Boots
(@GreenTBC+11,24789,0,1,1,1,1), -- Murkblood Bracers
(@GreenTBC+11,24784,0,1,1,1,1), -- Murkblood Chestpiece
(@GreenTBC+11,24786,0,1,1,1,1), -- Murkblood Cover
(@GreenTBC+11,24785,0,1,1,1,1), -- Murkblood Gloves
(@GreenTBC+11,24787,0,1,1,1,1), -- Murkblood Pants
(@GreenTBC+11,24788,0,1,1,1,1), -- Murkblood Shoulderguards
(@GreenTBC+11,25237,0,1,1,1,1), -- Nether Trident
(@GreenTBC+11,25167,0,1,1,1,1), -- Nethersteel Claymore
(@GreenTBC+11,25251,0,1,1,1,1), -- Orc Flatbow
(@GreenTBC+11,25125,0,1,1,1,1), -- Retro-Spike Club
(@GreenTBC+11,25279,0,1,1,1,1), -- Sen'jin Longrifle
(@GreenTBC+11,25307,0,1,1,1,1), -- Shadow Dagger
(@GreenTBC+11,25083,0,1,1,1,1), -- Smouldering Shield
(@GreenTBC+11,24896,0,1,1,1,1), -- Sundered Chestpiece
(@GreenTBC+11,24895,0,1,1,1,1), -- Sundered Footwraps
(@GreenTBC+11,24897,0,1,1,1,1), -- Sundered Gauntlets
(@GreenTBC+11,24898,0,1,1,1,1), -- Sundered Helmet
(@GreenTBC+11,24899,0,1,1,1,1), -- Sundered Legguards
(@GreenTBC+11,24900,0,1,1,1,1), -- Sundered Spaulders
(@GreenTBC+11,24894,0,1,1,1,1), -- Sundered Waistband
(@GreenTBC+11,25181,0,1,1,1,1), -- Tapered Staff
(@GreenTBC+11,24901,0,1,1,1,1), -- Tortured Bracer
(@GreenTBC+11,25223,0,1,1,1,1), -- Windcaller Hatchet
-- lvl 69 ilvl 117 greens (55 items) TBC
(@GreenTBC+12,25056,0,1,1,1,1), -- Almandine Ring
(@GreenTBC+12,25126,0,1,1,1,1), -- Anvilmar Hammer
(@GreenTBC+12,24677,0,1,1,1,1), -- Archmage Belt
(@GreenTBC+12,24684,0,1,1,1,1), -- Archmage Bracelets
(@GreenTBC+12,24680,0,1,1,1,1), -- Archmage Gloves
(@GreenTBC+12,24681,0,1,1,1,1), -- Archmage Headpiece
(@GreenTBC+12,24683,0,1,1,1,1), -- Archmage Mantle
(@GreenTBC+12,24682,0,1,1,1,1), -- Archmage Pants
(@GreenTBC+12,24679,0,1,1,1,1), -- Archmage Robe
(@GreenTBC+12,24678,0,1,1,1,1), -- Archmage Slippers
(@GreenTBC+12,25154,0,1,1,1,1), -- Blood Groove Blade
(@GreenTBC+12,25196,0,1,1,1,1), -- Boneshredder Claws
(@GreenTBC+12,25140,0,1,1,1,1), -- Commanding Mallet
(@GreenTBC+12,25070,0,1,1,1,1), -- Coral Beads
(@GreenTBC+12,25182,0,1,1,1,1), -- Crystal-Etched Warstaff
(@GreenTBC+12,25210,0,1,1,1,1), -- Double-Bladed Axe
(@GreenTBC+12,25294,0,1,1,1,1), -- Dragonscale Wand
(@GreenTBC+12,25252,0,1,1,1,1), -- Dream Catcher Bow
(@GreenTBC+12,28543,0,1,1,1,1), -- Dreghood Throwing Axe
(@GreenTBC+12,24791,0,1,1,1,1), -- Expedition Boots
(@GreenTBC+12,24797,0,1,1,1,1), -- Expedition Bracers
(@GreenTBC+12,24790,0,1,1,1,1), -- Expedition Girdle
(@GreenTBC+12,24793,0,1,1,1,1), -- Expedition Gloves
(@GreenTBC+12,24794,0,1,1,1,1), -- Expedition Hood
(@GreenTBC+12,24795,0,1,1,1,1), -- Expedition Pants
(@GreenTBC+12,24796,0,1,1,1,1), -- Expedition Shoulderguards
(@GreenTBC+12,24792,0,1,1,1,1), -- Expedition Tunic
(@GreenTBC+12,25112,0,1,1,1,1), -- Fel Ripper
(@GreenTBC+12,25280,0,1,1,1,1), -- Game Hunter Musket
(@GreenTBC+12,25238,0,1,1,1,1), -- Hellfire War Spear
(@GreenTBC+12,25322,0,1,1,1,1), -- Lordly Scepter
(@GreenTBC+12,25042,0,1,1,1,1), -- Nether Cloak
(@GreenTBC+12,25168,0,1,1,1,1), -- Sha'tari Longsword
(@GreenTBC+12,25014,0,1,1,1,1), -- Shattered Hand Belt
(@GreenTBC+12,25016,0,1,1,1,1), -- Shattered Hand Breastplate
(@GreenTBC+12,25020,0,1,1,1,1), -- Shattered Hand Epaulets
(@GreenTBC+12,25017,0,1,1,1,1), -- Shattered Hand Gauntlets
(@GreenTBC+12,25018,0,1,1,1,1), -- Shattered Hand Helmet
(@GreenTBC+12,25019,0,1,1,1,1), -- Shattered Hand Legplates
(@GreenTBC+12,25015,0,1,1,1,1), -- Shattered Hand Sabatons
(@GreenTBC+12,25021,0,1,1,1,1), -- Shattered Hand Vambraces
(@GreenTBC+12,25224,0,1,1,1,1), -- Slavemaster Axe
(@GreenTBC+12,25336,0,1,1,1,1), -- Splintering Greatstaff
(@GreenTBC+12,24904,0,1,1,1,1), -- Talhide Chestpiece
(@GreenTBC+12,24906,0,1,1,1,1), -- Talhide Helmet
(@GreenTBC+12,24903,0,1,1,1,1), -- Talhide Lined-Boots
(@GreenTBC+12,24909,0,1,1,1,1), -- Talhide Lined-Bracers
(@GreenTBC+12,24905,0,1,1,1,1), -- Talhide Lined-Gloves
(@GreenTBC+12,24907,0,1,1,1,1), -- Talhide Lined-Leggings
(@GreenTBC+12,24908,0,1,1,1,1), -- Talhide Shoulderguards
(@GreenTBC+12,24902,0,1,1,1,1), -- Talhide Stitched-Belt
(@GreenTBC+12,25308,0,1,1,1,1), -- Thunder Spike
(@GreenTBC+12,25098,0,1,1,1,1), -- Tuurik Torch
(@GreenTBC+12,25266,0,1,1,1,1), -- Well-Balanced Crossbow
(@GreenTBC+12,25084,0,1,1,1,1), -- Zeth'Gor Shield
-- lvl 70 ilvl 120 greens (55 items) TBC
(@GreenTBC+13,25057,0,1,1,1,1), -- Amber Band
(@GreenTBC+13,25043,0,1,1,1,1), -- Amber Cape
(@GreenTBC+13,25323,0,1,1,1,1), -- Ascendant's Scepter
(@GreenTBC+13,28544,0,1,1,1,1), -- Assassin's Shuriken
(@GreenTBC+13,25281,0,1,1,1,1), -- Big-Boar Battle Rifle
(@GreenTBC+13,25225,0,1,1,1,1), -- Deepforge Broadaxe
(@GreenTBC+13,25099,0,1,1,1,1), -- Draenei Crystal Rod
(@GreenTBC+13,24805,0,1,1,1,1), -- Dragonhawk Bands
(@GreenTBC+13,24798,0,1,1,1,1), -- Dragonhawk Belt
(@GreenTBC+13,24799,0,1,1,1,1), -- Dragonhawk Boots
(@GreenTBC+13,24801,0,1,1,1,1), -- Dragonhawk Gloves
(@GreenTBC+13,24802,0,1,1,1,1), -- Dragonhawk Hat
(@GreenTBC+13,24803,0,1,1,1,1), -- Dragonhawk Pants
(@GreenTBC+13,24804,0,1,1,1,1), -- Dragonhawk Shoulderguards
(@GreenTBC+13,24800,0,1,1,1,1), -- Dragonhawk Tunic
(@GreenTBC+13,25085,0,1,1,1,1), -- Dragonscale Shield
(@GreenTBC+13,24685,0,1,1,1,1), -- Elementalist Belt
(@GreenTBC+13,24686,0,1,1,1,1), -- Elementalist Boots
(@GreenTBC+13,24692,0,1,1,1,1), -- Elementalist Bracelets
(@GreenTBC+13,24688,0,1,1,1,1), -- Elementalist Gloves
(@GreenTBC+13,24690,0,1,1,1,1), -- Elementalist Leggings
(@GreenTBC+13,24691,0,1,1,1,1), -- Elementalist Mantle
(@GreenTBC+13,24689,0,1,1,1,1), -- Elementalist Skullcap
(@GreenTBC+13,24687,0,1,1,1,1), -- Elementalist Tunic
(@GreenTBC+13,25169,0,1,1,1,1), -- Fel Orc Brute Sword
(@GreenTBC+13,25295,0,1,1,1,1), -- Flawless Wand
(@GreenTBC+13,25141,0,1,1,1,1), -- Halaani Hammer
(@GreenTBC+13,25155,0,1,1,1,1), -- Iron Skull Sword
(@GreenTBC+13,25127,0,1,1,1,1), -- Knight's War Hammer
(@GreenTBC+13,25239,0,1,1,1,1), -- Legend's Glaive
(@GreenTBC+13,24910,0,1,1,1,1), -- Netherstorm Belt
(@GreenTBC+13,24917,0,1,1,1,1), -- Netherstorm Bracer
(@GreenTBC+13,24912,0,1,1,1,1), -- Netherstorm Chestpiece
(@GreenTBC+13,24913,0,1,1,1,1), -- Netherstorm Gauntlets
(@GreenTBC+13,24911,0,1,1,1,1), -- Netherstorm Greaves
(@GreenTBC+13,24914,0,1,1,1,1), -- Netherstorm Helm
(@GreenTBC+13,24915,0,1,1,1,1), -- Netherstorm Legguards
(@GreenTBC+13,24916,0,1,1,1,1), -- Netherstorm Shoulderguards
(@GreenTBC+13,25113,0,1,1,1,1), -- Phantom Dagger
(@GreenTBC+13,25267,0,1,1,1,1), -- Rampant Crossbow
(@GreenTBC+13,25197,0,1,1,1,1), -- Razor Scythes
(@GreenTBC+13,25211,0,1,1,1,1), -- Rockbiter Cutter
(@GreenTBC+13,25337,0,1,1,1,1), -- Swarming Sting-Staff
(@GreenTBC+13,25071,0,1,1,1,1), -- Tanzanite Pendant
(@GreenTBC+13,25183,0,1,1,1,1), -- Voodoo Hex-Staff
(@GreenTBC+13,25024,0,1,1,1,1), -- Warlord's Iron-Breastplate
(@GreenTBC+13,25028,0,1,1,1,1), -- Warlord's Iron-Epaulets
(@GreenTBC+13,25025,0,1,1,1,1), -- Warlord's Iron-Gauntlets
(@GreenTBC+13,25022,0,1,1,1,1), -- Warlord's Iron-Girdle
(@GreenTBC+13,25026,0,1,1,1,1), -- Warlord's Iron-Helm
(@GreenTBC+13,25027,0,1,1,1,1), -- Warlord's Iron-Legplates
(@GreenTBC+13,25029,0,1,1,1,1), -- Warlord's Iron-Vambraces
(@GreenTBC+13,25023,0,1,1,1,1), -- Warlord's Sabatons
(@GreenTBC+13,25309,0,1,1,1,1), -- Warpdagger
(@GreenTBC+13,25253,0,1,1,1,1); -- Windspear Longbow
-- --------------------------------------------------------
-- TBC_Blues_References
-- --------------------------------------------------------
SET @BlueTBC := 4200; -- reference starting value TDB Field
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @BlueTBC AND @BlueTBC+10;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- lvl 60 blues ilvl 85((6 items)
(@BlueTBC,31125,0,1,1,1,1), -- Boots of the Decimator
(@BlueTBC,31126,0,1,1,1,1), -- Gloves of Ferocity
(@BlueTBC,31127,0,1,1,1,1), -- Hauberk of Totemic Rage
(@BlueTBC,31131,0,1,1,1,1), -- Sash of Silent Blades
(@BlueTBC,31133,0,1,1,1,1), -- Leggings of Concentrated Darkness
(@BlueTBC,31134,0,1,1,1,1), -- Blade of Misfortune
-- lvl 61 blues ilvl 88 (6 items)
(@BlueTBC+1,31136,0,1,1,1,1), -- Breastplate of Blade Turning
(@BlueTBC+1,31137,0,1,1,1,1), -- Gauntlets of Purification
(@BlueTBC+1,31138,0,1,1,1,1), -- Storm Lord's Girdle
(@BlueTBC+1,31139,0,1,1,1,1), -- Fist of Reckoning
(@BlueTBC+1,31140,0,1,1,1,1), -- Cloak of Entropy
(@BlueTBC+1,31142,0,1,1,1,1), -- Blade of Trapped Knowledge
-- lvl 62 blues ilvl 91 (6 items)
(@BlueTBC+2,31143,0,1,1,1,1), -- Shroud of Frenzy
(@BlueTBC+2,31145,0,1,1,1,1), -- Headdress of the Sleeper
(@BlueTBC+2,31147,0,1,1,1,1), -- Pendant of Cunning
(@BlueTBC+2,31148,0,1,1,1,1), -- Demon Hide Spaulders
(@BlueTBC+2,31149,0,1,1,1,1), -- Gloves of Pandemonium
(@BlueTBC+2,31150,0,1,1,1,1), -- Gloves of Piety
-- lvl 63 blues ilvl 94 (6 items)
(@BlueTBC+3,31151,0,1,1,1,1), -- Girdle of Siege
(@BlueTBC+3,31152,0,1,1,1,1), -- Girdle of SiegeChestguard of Illumination
(@BlueTBC+3,31153,0,1,1,1,1), -- Girdle of SiegeAxe of the Legion
(@BlueTBC+3,31173,0,1,1,1,1), -- Girdle of SiegeBoots of Savagery
(@BlueTBC+3,31175,0,1,1,1,1), -- Girdle of SiegeBlade Dancer's Wristguards
(@BlueTBC+3,31178,0,1,1,1,1), -- Girdle of SiegeAmulet of Unstable Power
-- lvl 64 blues ilvl 97 (6 items)
(@BlueTBC+4,31180,0,1,1,1,1), -- Gauntlets of the Skullsplitter
(@BlueTBC+4,31186,0,1,1,1,1), -- Braxxis' Staff of Slumber
(@BlueTBC+4,31187,0,1,1,1,1), -- Boots of the Pathfinder
(@BlueTBC+4,31190,0,1,1,1,1), -- The Dreamer's Shoulderpads
(@BlueTBC+4,31193,0,1,1,1,1), -- Blade of Unquenched Thirst
(@BlueTBC+4,31196,0,1,1,1,1), -- Amulet of Sanctification
-- lvl 65 blues ilvl 100 (6 items)
(@BlueTBC+5,31200,0,1,1,1,1), -- Shield of the Wayward Footman
(@BlueTBC+5,31202,0,1,1,1,1), -- Girdle of Divine Blessing
(@BlueTBC+5,31204,0,1,1,1,1), -- The Gunblade
(@BlueTBC+5,31222,0,1,1,1,1), -- Headdress of Inner Rage
(@BlueTBC+5,31226,0,1,1,1,1), -- Leggings of the Sly
(@BlueTBC+5,31230,0,1,1,1,1), -- Abyss Walker's Boots
-- lvl 68 blues ilvl 109 (6 items)
(@BlueTBC+8,31284,0,1,1,1,1), -- Bracers of Recklessness
(@BlueTBC+8,31285,0,1,1,1,1), -- Chestguard of the Talon
(@BlueTBC+8,31286,0,1,1,1,1), -- Breastplate of Rapid Striking
(@BlueTBC+8,31287,0,1,1,1,1), -- Draenei Honor Guard Shield
(@BlueTBC+8,31288,0,1,1,1,1), -- The Master's Treads
(@BlueTBC+8,31289,0,1,1,1,1), -- Staff of Divine Infusion
-- lvl 69 blues ilvl 112 (6 items)
(@BlueTBC+9,31291,0,1,1,1,1), -- Crystalforged War Axe
(@BlueTBC+9,31292,0,1,1,1,1), -- Crystal Pulse Shield
(@BlueTBC+9,31293,0,1,1,1,1), -- Girdle of Gale Force
(@BlueTBC+9,31294,0,1,1,1,1), -- Pauldrons of Surging Mana
(@BlueTBC+9,31295,0,1,1,1,1), -- Chestguard of the Dark Stalker
(@BlueTBC+9,31297,0,1,1,1,1), -- Robe of the Crimson Order
-- lvl 70 blues ilvl 115 (7 items)
(@BlueTBC+10,31298,0,1,1,1,1), -- Legguards of the Shattered Hand
(@BlueTBC+10,31299,0,1,1,1,1), -- The Oathkeeper
(@BlueTBC+10,31303,0,1,1,1,1), -- Valanos' Longbow
(@BlueTBC+10,31304,0,1,1,1,1), -- The Essence Focuser
(@BlueTBC+10,31305,0,1,1,1,1), -- Ced's Carver
(@BlueTBC+10,31306,0,1,1,1,1), -- Leggings of the Sacred Crest
(@BlueTBC+10,31308,0,1,1,1,1); -- The Bringer of Death
