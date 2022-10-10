-- DB update 2021_02_04_03 -> 2021_02_05_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_04_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_04_03 2021_02_05_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612095806740149900'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612095806740149900');

DELETE FROM `creature_loot_template` WHERE `entry` IN (
202, -- Skeletal Horror - Tangy Clam Meat
203, -- Skeletal Mage - Tangy Clam Meat
205, -- Nightbane Dark Runner - Clam Meat
205, -- Nightbane Dark Runner - Tangy Clam Meat
210, -- Bone Chewer - Tangy Clam Meat
212, -- Splinter Fist Warrior - Clam Meat
212, -- Splinter Fist Warrior - Tangy Clam Meat
217, -- Venom Web Spider - Tangy Clam Meat
240, -- Marshal Dughan - Clam Meat
246, -- "Auntie" Bernice Stonefield - Clam Meat
313, -- Theocritus - Clam Meat
345, -- Bellygrub - Clam Meat
397, -- Morganth - Clam Meat
423, -- Redridge Mongrel - Clam Meat
423, -- Redridge Mongrel - Tangy Clam Meat
424, -- Redridge Poacher - Clam Meat
426, -- Redridge Brute - Clam Meat
428, -- Dire Condor - Clam Meat
428, -- Dire Condor - Tangy Clam Meat
429, -- Shadowhide Darkweaver - Clam Meat
430, -- Redridge Mystic - Clam Meat
432, -- Shadowhide Brute - Clam Meat
433, -- Shadowhide Gnoll - Clam Meat
436, -- Blackrock Shadowcaster - Clam Meat
437, -- Blackrock Renegade - Clam Meat
440, -- Blackrock Grunt - Clam Meat
441, -- Black Dragon Whelp - Clam Meat
441, -- Black Dragon Whelp - Tangy Clam Meat
442, -- Tarantula - Clam Meat
445, -- Redridge Alpha - Clam Meat
446, -- Redridge Basher - Clam Meat
448, -- Hogger - Clam Meat
449, -- Defias Knuckleduster - Clam Meat
452, -- Riverpaw Bandit - Clam Meat
454, -- Young Goretusk - Clam Meat
454, -- Young Goretusk - Tangy Clam Meat
475, -- Kobold Tunneler - Clam Meat
478, -- Riverpaw Outrunner - Clam Meat
480, -- Rusty Harvest Golem - Clam Meat
481, -- Defias Footpad - Clam Meat
485, -- Blackrock Outrunner - Clam Meat
486, -- Tharil'zun - Clam Meat
500, -- Riverpaw Scout - Clam Meat
501, -- Riverpaw Herbalist - Clam Meat
504, -- Defias Trapper - Clam Meat
505, -- Greater Tarantula - Clam Meat
518, -- Yowler - Clam Meat
531, -- Skeletal Fiend - Tangy Clam Meat
547, -- Great Goretusk - Clam Meat
565, -- Rabid Dire Wolf - Tangy Clam Meat
568, -- Shadowhide Warrior - Clam Meat
569, -- Green Recluse - Clam Meat
580, -- Redridge Drudger - Clam Meat
589, -- Defias Pillager - Clam Meat
590, -- Defias Looter - Clam Meat
590, -- Defias Looter - Tangy Clam Meat
598, -- Defias Miner - Clam Meat
604, -- Plague Spreader - Tangy Clam Meat
615, -- Blackrock Tracker - Clam Meat
624, -- Undead Excavator - Clam Meat
634, -- Defias Overseer - Clam Meat
636, -- Defias Blackguard - Clam Meat
657, -- Defias Pirate - Clam Meat
685, -- Stranglethorn Raptor - Tangy Clam Meat
686, -- Lashtail Raptor - Tangy Clam Meat
703, -- Lieutenant Fangore - Clam Meat
712, -- Redridge Thrasher - Clam Meat
819, -- Servant of Ilgalar - Tangy Clam Meat
824, -- Defias Digger - Clam Meat
832, -- Dust Devil - Clam Meat
833, -- Coyote Packleader - Clam Meat
834, -- Coyote - Clam Meat
892, -- Splinter Fist Taskmaster - Tangy Clam Meat
930, -- Black Widow Hatchling - Tangy Clam Meat
940, -- Kurzen Medicine Man - Tangy Clam Meat
949, -- Carrion Recluse - Clam Meat
949, -- Carrion Recluse - Tangy Clam Meat
1707, -- Defias Captive - Tangy Clam Meat
1708, -- Defias Inmate - Clam Meat
1716, -- Bazil Thredd - Tangy Clam Meat
1725, -- Defias Watchman - Clam Meat
1726, -- Defias Magician - Clam Meat
1727, -- Defias Worker - Clam Meat
1732, -- Defias Squallshaper - Clam Meat
1732, -- Defias Squallshaper - Tangy Clam Meat
1733, -- Zggi - Clam Meat
1765, -- Worg - Clam Meat
1766, -- Mottled Worg - Clam Meat
1769, -- Moonrage Whitescalp - Clam Meat
1770, -- Moonrage Darkrunner - Clam Meat
1772, -- Rot Hide Gladerunner - Clam Meat
1778, -- Ferocious Grizzled Bear - Clam Meat
1779, -- Moonrage Glutton - Clam Meat
1780, -- Moss Stalker - Clam Meat
1781, -- Mist Creeper - Clam Meat
1782, -- Moonrage Darksoul - Clam Meat
1797, -- Giant Grizzled Bear - Clam Meat
1866, -- Ravenclaw Slave - Clam Meat
1867, -- Dalaran Apprentice - Clam Meat
1870, -- Hand of Ravenclaw - Clam Meat
1888, -- Dalaran Watcher - Clam Meat
1891, -- Pyrewood Watcher - Clam Meat
1939, -- Rot Hide Brute - Clam Meat
1940, -- Rot Hide Plague Weaver - Clam Meat
1942, -- Rot Hide Savage - Clam Meat
1943, -- Raging Rot Hide - Clam Meat
1953, -- Lake Skulker - Clam Meat
1954, -- Elder Lake Skulker - Clam Meat
1955, -- Lake Creeper - Clam Meat
1956, -- Elder Lake Creeper - Clam Meat
1961, -- Mangeclaw - Clam Meat
1983, -- Nightlash - Clam Meat
2043, -- Nightsaber Stalker - Clam Meat
2054, -- Sickly Refugee - Clam Meat
2054, -- Sickly Refugee - Tangy Clam Meat
2069, -- Moonstalker - Clam Meat
2070, -- Moonstalker Runt - Clam Meat
2071, -- Moonstalker Matriarch - Clam Meat
2089, -- Giant Wetlands Crocolisk - Tangy Clam Meat
2152, -- Gnarlpine Ambusher - Clam Meat
2156, -- Cracked Golem - Clam Meat
2157, -- Stone Behemoth - Clam Meat
2158, -- Gravelflint Scout - Clam Meat
2158, -- Gravelflint Scout - Tangy Clam Meat
2160, -- Gravelflint Geomancer - Clam Meat
2163, -- Thistle Bear - Clam Meat
2163, -- Thistle Bear - Tangy Clam Meat
2164, -- Rabid Thistle Bear - Clam Meat
2165, -- Grizzled Thistle Bear - Clam Meat
2165, -- Grizzled Thistle Bear - Tangy Clam Meat
2168, -- Blackwood Warrior - Clam Meat
2169, -- Blackwood Totemic - Clam Meat
2170, -- Blackwood Ursa - Clam Meat
2171, -- Blackwood Shaman - Clam Meat
2172, -- Strider Clutchmother - Clam Meat
2174, -- Coastal Frenzy - Clam Meat
2175, -- Shadowclaw - Clam Meat
2176, -- Cursed Highborne - Clam Meat
2177, -- Writhing Highborne - Clam Meat
2178, -- Wailing Highborne - Clam Meat
2179, -- Stormscale Wave Rider - Clam Meat
2179, -- Stormscale Wave Rider - Tangy Clam Meat
2180, -- Stormscale Siren - Clam Meat
2181, -- Stormscale Myrmidon - Clam Meat
2181, -- Stormscale Myrmidon - Tangy Clam Meat
2182, -- Stormscale Sorceress - Clam Meat
2183, -- Stormscale Warrior - Clam Meat
2184, -- Lady Moongazer - Clam Meat
2185, -- Darkshore Thresher - Clam Meat
2187, -- Elder Darkshore Thresher - Clam Meat
2189, -- Vile Sprite - Clam Meat
2190, -- Wild Grell - Clam Meat
2191, -- Licillin - Clam Meat
2192, -- Firecaller Radison - Clam Meat
2212, -- Deth'ryll Satyr - Clam Meat
2237, -- Moonstalker Sire - Clam Meat
2240, -- Syndicate Footpad - Tangy Clam Meat
2241, -- Syndicate Thief - Tangy Clam Meat
2242, -- Syndicate Spy - Tangy Clam Meat
2244, -- Syndicate Shadow Mage - Clam Meat
2246, -- Syndicate Assassin - Clam Meat
2246, -- Syndicate Assassin - Tangy Clam Meat
2247, -- Syndicate Enforcer - Tangy Clam Meat
2248, -- Cave Yeti - Tangy Clam Meat
2249, -- Ferocious Yeti - Tangy Clam Meat
2250, -- Mountain Yeti - Tangy Clam Meat
2251, -- Giant Yeti - Tangy Clam Meat
2252, -- Crushridge Ogre - Tangy Clam Meat
2253, -- Crushridge Brute - Clam Meat
2253, -- Crushridge Brute - Tangy Clam Meat
2260, -- Syndicate Rogue - Tangy Clam Meat
2261, -- Syndicate Watchman - Tangy Clam Meat
2266, -- Hillsbrad Farmer - Tangy Clam Meat
2268, -- Hillsbrad Footman - Tangy Clam Meat
2269, -- Hillsbrad Miner - Tangy Clam Meat
2270, -- Hillsbrad Sentry - Tangy Clam Meat
2271, -- Dalaran Shield Guard - Tangy Clam Meat
2272, -- Dalaran Theurgist - Tangy Clam Meat
2318, -- Argus Shadow Mage - Tangy Clam Meat
2321, -- Foreststrider Fledgling - Clam Meat
2322, -- Foreststrider - Clam Meat
2323, -- Giant Foreststrider - Clam Meat
2323, -- Giant Foreststrider - Tangy Clam Meat
2324, -- Blackwood Windtalker - Clam Meat
2333, -- Henchman Valik - Tangy Clam Meat
2335, -- Magistrate Burnside - Tangy Clam Meat
2336, -- Dark Strand Fanatic - Clam Meat
2337, -- Dark Strand Voidcaller - Clam Meat
2338, -- Twilight Disciple - Clam Meat
2339, -- Twilight Thug - Clam Meat
2344, -- Dun Garok Mountaineer - Tangy Clam Meat
2345, -- Dun Garok Rifleman - Tangy Clam Meat
2348, -- Elder Moss Creeper - Tangy Clam Meat
2349, -- Giant Moss Creeper - Tangy Clam Meat
2350, -- Forest Moss Creeper - Clam Meat
2350, -- Forest Moss Creeper - Tangy Clam Meat
2351, -- Gray Bear - Tangy Clam Meat
2354, -- Vicious Gray Bear - Tangy Clam Meat
2356, -- Elder Gray Bear - Tangy Clam Meat
2358, -- Dalaran Summoner - Tangy Clam Meat
2359, -- Elemental Slave - Tangy Clam Meat
2360, -- Hillsbrad Farmhand - Tangy Clam Meat
2372, -- Mudsnout Gnoll - Tangy Clam Meat
2373, -- Mudsnout Shaman - Tangy Clam Meat
2384, -- Starving Mountain Lion - Clam Meat
2384, -- Starving Mountain Lion - Tangy Clam Meat
2385, -- Feral Mountain Lion - Tangy Clam Meat
2406, -- Mountain Lion - Clam Meat
2406, -- Mountain Lion - Tangy Clam Meat
2407, -- Hulking Mountain Lion - Tangy Clam Meat
2421, -- Muckrake - Tangy Clam Meat
2434, -- Shadowy Assassin - Tangy Clam Meat
2440, -- Drunken Footpad - Tangy Clam Meat
2503, -- Hillsbrad Foreman - Tangy Clam Meat
2529, -- Son of Arugal - Clam Meat
2559, -- Highland Strider - Tangy Clam Meat
2560, -- Highland Thrasher - Tangy Clam Meat
2561, -- Highland Fleshstalker - Tangy Clam Meat
2562, -- Boulderfist Ogre - Tangy Clam Meat
2563, -- Plains Creeper - Clam Meat
2563, -- Plains Creeper - Tangy Clam Meat
2565, -- Giant Plains Creeper - Tangy Clam Meat
2572, -- Drywhisker Kobold - Tangy Clam Meat
2578, -- Young Mesa Buzzard - Tangy Clam Meat
2586, -- Syndicate Highwayman - Tangy Clam Meat
2650, -- Witherbark Zealot - Tangy Clam Meat
2655, -- Green Sludge - Clam Meat
2706, -- Tor'gan - Tangy Clam Meat
2712, -- Quae - Tangy Clam Meat
2721, -- Forsaken Bodyguard - Tangy Clam Meat
2744, -- Shadowforge Commander - Clam Meat
2744, -- Shadowforge Commander - Tangy Clam Meat
2787, -- Zaruk - Tangy Clam Meat
2850, -- Broken Tooth - Tangy Clam Meat
2852, -- Enslaved Druid of the Talon - Tangy Clam Meat
2930, -- Sentinel Glynda Nal'Shea - Clam Meat
3058, -- Arra'chea - Clam Meat
3100, -- Elder Mottled Boar - Clam Meat
3197, -- Burning Blade Fanatic - Clam Meat
3234, -- Lost Barrens Kodo - Clam Meat
3236, -- Barrens Kodo - Clam Meat
3238, -- Stormhide - Clam Meat
3238, -- Stormhide - Tangy Clam Meat
3239, -- Thunderhead - Clam Meat
3240, -- Stormsnout - Clam Meat
3242, -- Zhevra Runner - Clam Meat
3243, -- Savannah Highmane - Clam Meat
3244, -- Greater Plainstrider - Clam Meat
3245, -- Ornery Plainstrider - Clam Meat
3246, -- Fleeting Plainstrider - Clam Meat
3247, -- Thunderhawk Hatchling - Clam Meat
3248, -- Barrens Giraffe - Clam Meat
3250, -- Silithid Creeper - Tangy Clam Meat
3251, -- Silithid Grub - Tangy Clam Meat
3254, -- Sunscale Lashtail - Clam Meat
3255, -- Sunscale Screecher - Clam Meat
3256, -- Sunscale Scytheclaw - Clam Meat
3257, -- Ishamuhale - Clam Meat
3258, -- Bristleback Hunter - Clam Meat
3260, -- Bristleback Water Seeker - Clam Meat
3261, -- Bristleback Thornweaver - Clam Meat
3263, -- Bristleback Geomancer - Clam Meat
3263, -- Bristleback Geomancer - Tangy Clam Meat
3265, -- Razormane Hunter - Clam Meat
3266, -- Razormane Defender - Clam Meat
3267, -- Razormane Water Seeker - Clam Meat
3272, -- Kolkar Wrangler - Clam Meat
3273, -- Kolkar Stormer - Clam Meat
3274, -- Kolkar Pack Runner - Clam Meat
3275, -- Kolkar Marauder - Clam Meat
3276, -- Witchwing Harpy - Clam Meat
3279, -- Witchwing Ambusher - Clam Meat
3280, -- Witchwing Windcaller - Clam Meat
3284, -- Venture Co. Drudger - Clam Meat
3379, -- Burning Blade Bruiser - Clam Meat
3380, -- Burning Blade Acolyte - Clam Meat
3385, -- Theramore Marine - Clam Meat
3386, -- Theramore Preserver - Clam Meat
3388, -- Mahren Skyseer - Clam Meat
3394, -- Barak Kodobane - Clam Meat
3395, -- Verog the Dervish - Clam Meat
3397, -- Kolkar Bloodcharger - Clam Meat
3398, -- Gesharahan - Clam Meat
3415, -- Savannah Huntress - Clam Meat
3425, -- Savannah Prowler - Clam Meat
3425, -- Savannah Prowler - Tangy Clam Meat
3426, -- Zhevra Charger - Clam Meat
3448, -- Tonga Runetotem - Clam Meat
3457, -- Razormane Stalker - Clam Meat
3459, -- Razormane Warfrenzy - Clam Meat
3464, -- Gazrog - Clam Meat
3465, -- Gilthares Firebough - Tangy Clam Meat
3466, -- Zhevra Courser - Clam Meat
3474, -- Lakota'mani - Clam Meat
3475, -- Echeyakee - Clam Meat
3476, -- Isha Awak - Clam Meat
3476, -- Isha Awak - Tangy Clam Meat
3535, -- Blackmoss the Fetid - Clam Meat
3566, -- Flatland Prowler - Clam Meat
3619, -- Ghost Saber - Clam Meat
3630, -- Deviate Coiler - Clam Meat
3631, -- Deviate Stinglash - Clam Meat
3632, -- Deviate Creeper - Clam Meat
3633, -- Deviate Slayer - Clam Meat
3633, -- Deviate Slayer - Tangy Clam Meat
3634, -- Deviate Stalker - Clam Meat
3636, -- Deviate Ravager - Clam Meat
3637, -- Deviate Guardian - Clam Meat
3638, -- Devouring Ectoplasm - Clam Meat
3640, -- Evolving Ectoplasm - Clam Meat
3641, -- Deviate Lurker - Clam Meat
3641, -- Deviate Lurker - Tangy Clam Meat
3652, -- Trigore the Lasher - Clam Meat
3655, -- Mad Magglish - Clam Meat
3659, -- Jorb - Tangy Clam Meat
3660, -- Athrikus Narassin - Clam Meat
3660, -- Athrikus Narassin - Tangy Clam Meat
3661, -- Balthule Shadowstrike - Clam Meat
3661, -- Balthule Shadowstrike - Tangy Clam Meat
3662, -- Delmanis the Hated - Clam Meat
3662, -- Delmanis the Hated - Tangy Clam Meat
3664, -- Ilkrud Magthrull - Clam Meat
3667, -- Anaya Dawnrunner - Clam Meat
3691, -- Raene Wolfrunner - Clam Meat
3691, -- Raene Wolfrunner - Tangy Clam Meat
3692, -- Volcor - Clam Meat
3692, -- Volcor - Tangy Clam Meat
3693, -- Terenthis - Clam Meat
3693, -- Terenthis - Tangy Clam Meat
3694, -- Sentinel Selarin - Clam Meat
3694, -- Sentinel Selarin - Tangy Clam Meat
3695, -- Grimclaw - Clam Meat
3695, -- Grimclaw - Tangy Clam Meat
3702, -- Alanndarian Nightsong - Clam Meat
3702, -- Alanndarian Nightsong - Tangy Clam Meat
3711, -- Wrathtail Myrmidon - Clam Meat
3711, -- Wrathtail Myrmidon - Tangy Clam Meat
3712, -- Wrathtail Razortail - Clam Meat
3712, -- Wrathtail Razortail - Tangy Clam Meat
3713, -- Wrathtail Wave Rider - Clam Meat
3713, -- Wrathtail Wave Rider - Tangy Clam Meat
3717, -- Wrathtail Sorceress - Clam Meat
3717, -- Wrathtail Sorceress - Tangy Clam Meat
3721, -- Mystlash Hydra - Clam Meat
3721, -- Mystlash Hydra - Tangy Clam Meat
3722, -- Mystlash Flayer - Clam Meat
3725, -- Dark Strand Cultist - Clam Meat
3727, -- Dark Strand Enforcer - Clam Meat
3727, -- Dark Strand Enforcer - Tangy Clam Meat
3728, -- Dark Strand Adept - Clam Meat
3730, -- Dark Strand Excavator - Clam Meat
3730, -- Dark Strand Excavator - Tangy Clam Meat
3732, -- Forsaken Seeker - Clam Meat
3733, -- Forsaken Herbalist - Clam Meat
3733, -- Forsaken Herbalist - Tangy Clam Meat
3737, -- Saltspittle Puddlejumper - Clam Meat
3737, -- Saltspittle Puddlejumper - Tangy Clam Meat
3739, -- Saltspittle Warrior - Clam Meat
3740, -- Saltspittle Muckdweller - Clam Meat
3742, -- Saltspittle Oracle - Clam Meat
3743, -- Foulweald Warrior - Clam Meat
3767, -- Bleakheart Trickster - Clam Meat
3767, -- Bleakheart Trickster - Tangy Clam Meat
3770, -- Bleakheart Shadowstalker - Clam Meat
3772, -- Lesser Felguard - Clam Meat
3783, -- Shadethicket Raincaller - Clam Meat
3791, -- Terrowulf Shadow Weaver - Clam Meat
3801, -- Severed Sleeper - Clam Meat
3809, -- Ashenvale Bear - Clam Meat
3809, -- Ashenvale Bear - Tangy Clam Meat
3811, -- Giant Ashenvale Bear - Clam Meat
3816, -- Wild Buck - Clam Meat
3817, -- Shadowhorn Stag - Clam Meat
3818, -- Elder Shadowhorn Stag - Clam Meat
3819, -- Wildthorn Stalker - Clam Meat
3819, -- Wildthorn Stalker - Tangy Clam Meat
3823, -- Ghostpaw Runner - Clam Meat
3824, -- Ghostpaw Howler - Clam Meat
3824, -- Ghostpaw Howler - Tangy Clam Meat
3834, -- Crazed Ancient - Clam Meat
3840, -- Druid of the Fang - Clam Meat
3844, -- Healing Ward IV - Tangy Clam Meat
3846, -- Talen - Clam Meat
3853, -- Shadowfang Moonwalker - Tangy Clam Meat
3859, -- Shadowfang Ragetooth - Clam Meat
3862, -- Slavering Worg - Tangy Clam Meat
3877, -- Wailing Guardsman - Clam Meat
3916, -- Shael'dryn - Clam Meat
3917, -- Befouled Water Elemental - Clam Meat
3917, -- Befouled Water Elemental - Tangy Clam Meat
3919, -- Withered Ancient - Clam Meat
3921, -- Thistlefur Ursa - Clam Meat
3921, -- Thistlefur Ursa - Tangy Clam Meat
3922, -- Thistlefur Totemic - Clam Meat
3924, -- Thistlefur Shaman - Clam Meat
3925, -- Thistlefur Avenger - Clam Meat
3928, -- Rotting Slime - Clam Meat
3943, -- Ruuzel - Clam Meat
3944, -- Wrathtail Priestess - Clam Meat
3947, -- Goblin Shipbuilder - Clam Meat
3984, -- Nancy Vishas - Tangy Clam Meat
3987, -- Dal Bloodclaw - Clam Meat
3987, -- Dal Bloodclaw - Tangy Clam Meat
3988, -- Venture Co. Operator - Clam Meat
3989, -- Venture Co. Logger - Clam Meat
3991, -- Venture Co. Deforester - Clam Meat
4007, -- Deepmoss Venomspitter - Clam Meat
4012, -- Pridewing Wyvern - Clam Meat
4012, -- Pridewing Wyvern - Tangy Clam Meat
4015, -- Pridewing Patriarch - Tangy Clam Meat
4027, -- Bloodfury Storm Witch - Tangy Clam Meat
4037, -- Burning Ravager - Clam Meat
4041, -- Scorched Basilisk - Clam Meat
4044, -- Blackened Basilisk - Tangy Clam Meat
4054, -- Laughing Sister - Clam Meat
4064, -- Blackrock Scout - Clam Meat
4065, -- Blackrock Sentry - Clam Meat
4065, -- Blackrock Sentry - Tangy Clam Meat
4101, -- Screeching Roguefeather - Tangy Clam Meat
4107, -- Highperch Wyvern - Tangy Clam Meat
4109, -- Highperch Consort - Clam Meat
4109, -- Highperch Consort - Tangy Clam Meat
4117, -- Cloud Serpent - Clam Meat
4119, -- Elder Cloud Serpent - Clam Meat
4127, -- Hecklefang Hyena - Clam Meat
4129, -- Hecklefang Snarler - Clam Meat
4263, -- Deepmoss Hatchling - Clam Meat
4281, -- Scarlet Scout - Clam Meat
4287, -- Scarlet Gallant - Tangy Clam Meat
4293, -- Scarlet Scryer - Clam Meat
4294, -- Scarlet Sorcerer - Clam Meat
4297, -- Scarlet Conjuror - Tangy Clam Meat
4298, -- Scarlet Defender - Tangy Clam Meat
4304, -- Scarlet Tracking Hound - Clam Meat
4316, -- Kolkar Packhound - Clam Meat
4416, -- Defias Strip Miner - Clam Meat
4463, -- Blackrock Summoner - Clam Meat
4464, -- Blackrock Gladiator - Clam Meat
4540, -- Scarlet Monk - Tangy Clam Meat
4686, -- Deepstrider Giant - Soft-shelled Clam Meat
4692, -- Dread Swoop - Tangy Clam Meat
4696, -- Scorpashi Snapper - Tangy Clam Meat
4711, -- Slitherblade Naga - Soft-shelled Clam Meat
4712, -- Slitherblade Sorceress - Soft-shelled Clam Meat
4713, -- Slitherblade Warrior - Soft-shelled Clam Meat
4714, -- Slitherblade Myrmidon - Soft-shelled Clam Meat
4718, -- Slitherblade Oracle - Soft-shelled Clam Meat
4788, -- Fallenroot Satyr - Clam Meat
4788, -- Fallenroot Satyr - Tangy Clam Meat
4789, -- Fallenroot Rogue - Clam Meat
4789, -- Fallenroot Rogue - Tangy Clam Meat
4798, -- Fallenroot Shadowstalker - Tangy Clam Meat
4799, -- Fallenroot Hellcaller - Clam Meat
4799, -- Fallenroot Hellcaller - Tangy Clam Meat
4809, -- Twilight Acolyte - Tangy Clam Meat
4810, -- Twilight Reaver - Tangy Clam Meat
4811, -- Twilight Aquamancer - Tangy Clam Meat
4812, -- Twilight Loreseeker - Tangy Clam Meat
4813, -- Twilight Shadowmage - Tangy Clam Meat
4814, -- Twilight Elementalist - Tangy Clam Meat
4852, -- Stonevault Oracle - Tangy Clam Meat
4979, -- Theramore Guard - Tangy Clam Meat
5048, -- Deviate Adder - Clam Meat
5053, -- Deviate Crocolisk - Clam Meat
5055, -- Deviate Lasher - Clam Meat
5185, -- Hammerhead Shark - Tangy Clam Meat
5237, -- Gordunni Ogre Mage - Tangy Clam Meat
5331, -- Hatecrest Warrior - Clam Meat
5755, -- Deviate Viper - Clam Meat
5756, -- Deviate Venomwing - Clam Meat
5761, -- Deviate Shambler - Clam Meat
5762, -- Deviate Moccasin - Tangy Clam Meat
5780, -- Cloned Ectoplasm - Clam Meat
5829, -- Snort the Heckler - Clam Meat
5838, -- Brokespear - Clam Meat
5996, -- Nethergarde Miner - Clam Meat
6020, -- Slimeshell Makrura - Clam Meat
6020, -- Slimeshell Makrura - Tangy Clam Meat
6033, -- Lake Frenzy - Clam Meat
6133, -- Shade of Elura - Clam Meat
6180, -- Defias Raider - Clam Meat
6194, -- Spitelash Serpent Guard - Clam Meat
6195, -- Spitelash Siren - Clam Meat
6210, -- Caverndeep Pillager - Tangy Clam Meat
6213, -- Irradiated Invader - Tangy Clam Meat
6221, -- Addled Leper - Tangy Clam Meat
6329, -- Irradiated Pillager - Tangy Clam Meat
6426, -- Anguished Dead - Tangy Clam Meat
6518, -- Tar Lurker - Tangy Clam Meat
6552, -- Gorishi Worker - Tangy Clam Meat
6788, -- Den Mother - Clam Meat
6789, -- Thistle Cub - Clam Meat
7016, -- Lady Vespira - Clam Meat
7017, -- Lord Sinslayer - Clam Meat
7075, -- Writhing Mage - Tangy Clam Meat
7318, -- Rageclaw - Clam Meat
8598, -- Frenzied Plaguehound - Tangy Clam Meat
8886, -- Deviate Python - Clam Meat
8959, -- Felpaw Wolf - Clam Meat
8959, -- Felpaw Wolf - Tangy Clam Meat
9316, -- Wenikee Boltbucket - Clam Meat
9524, -- Kolkar Invader - Clam Meat
10157, -- Moonkin Oracle - Clam Meat
10158, -- Moonkin - Clam Meat
10158, -- Moonkin - Tangy Clam Meat
10159, -- Young Moonkin - Clam Meat
10160, -- Raging Moonkin - Clam Meat
10358, -- Fellicent's Shade - Clam Meat
10373, -- Xabraxxis - Clam Meat
10559, -- Lady Vespia - Clam Meat
10638, -- Kanati Greycloud - Clam Meat
11318, -- Ragefire Trogg - Clam Meat
11563, -- Drysnap Pincer - Soft-shelled Clam Meat
11713, -- Blackwood Tracker - Clam Meat
11714, -- Marosh the Devious - Clam Meat
11738, -- Sand Skitterer - Clam Meat
11820, -- Locke Okarr - Clam Meat
11820, -- Locke Okarr - Tangy Clam Meat
11912, -- Grimtotem Brute - Clam Meat
12321, -- Stormscale Toxicologist - Clam Meat
12369, -- Lord Kragaru - Soft-shelled Clam Meat
12432, -- Old Vicejaw - Clam Meat
12736, -- Je'neu Sancrea - Clam Meat
12736, -- Je'neu Sancrea - Tangy Clam Meat
12862, -- Warsong Scout - Clam Meat
12863, -- Warsong Runner - Clam Meat
12863, -- Warsong Runner - Tangy Clam Meat
12876, -- Baron Aquanis - Tangy Clam Meat
12902, -- Lorgus Jett - Tangy Clam Meat
12940, -- Vorsha the Lasher - Clam Meat
13196, -- Phase Lasher - Clam Meat
13359, -- Frostwolf Bowman - Clam Meat
13440, -- Frostwolf Wolf Rider - Clam Meat
14223, -- Cranky Benj - Tangy Clam Meat
14269, -- Seeker Aqualon - Clam Meat
14270, -- Squiddic - Clam Meat
14271, -- Ribchaser - Clam Meat
14273, -- Boulderheart - Clam Meat
14276, -- Scargil - Tangy Clam Meat
14277, -- Lady Zephris - Tangy Clam Meat
14357, -- Lake Thresher - Clam Meat
14357, -- Lake Thresher - Tangy Clam Meat
14983, -- Field Marshal Oslight - Tangy Clam Meat
17917, -- Coilfang Water Elemental - Jaggal Clam Meat
19762, -- Coilskar Defender - Jaggal Clam Meat
21044, -- Coilskar Assassin - Jaggal Clam Meat
21126, -- Coilfang Scale-Healer - Jaggal Clam Meat
21127 -- Coilfang Tempest - Jaggal Clam Meat
) AND `Item` IN (24477,5504,5503,15924) AND `Reference` = 0;

UPDATE `creature_template` SET `lootid` = 0 WHERE `entry` IN (3388,240,246);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
