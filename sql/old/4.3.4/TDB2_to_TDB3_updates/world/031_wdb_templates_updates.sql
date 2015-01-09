UPDATE `npc_text` SET `em0_1`=0, `WDBVerified`=15595 WHERE `ID`=12130; -- 12130
UPDATE `npc_text` SET `text0_0`='I will never forget that day, $r. Never. Even though I had long since abandoned shamanism in favor of shadow magic, I felt the cut. A sense of loss so profound... I could not explain it to you with mere words.$B$BWhen the tie to the elements was severed, all orcs on Draenor changed. If there was ever any doubt in the power of the shadows, it was washed away with the cresting of the molten lava over the shattered earth.
', `em0_0`=274, `em0_1`=1, `em0_2`=1, `em0_3`=0, `em0_5`=0, `WDBVerified`=15595 WHERE `ID`=10316; -- 10316
UPDATE `npc_text` SET `text0_0`='Welcome to Theramore, $c. Looking for something?', `text0_1`='Welcome to Theramore, $c. Looking for something?', `em0_0`=396, `text1_0`='Welcome to Theramore Isle. Something I can help you find?', `text1_1`='Welcome to Theramore Isle. Something I can help you find?', `prob1`=1, `em1_0`=396, `WDBVerified`=15595 WHERE `ID`=11492; -- 11492
UPDATE `npc_text` SET `text0_1`='How may I help you?', `em0_0`=396, `WDBVerified`=15595 WHERE `ID`=13702; -- 13702


DELETE FROM `gossip_menu_option` WHERE (`menu_id`=11135 AND `id`=0) OR (`menu_id`=9492 AND `id`=0) OR (`menu_id`=12927 AND `id`=0) OR (`menu_id`=12927 AND `id`=1) OR (`menu_id`=13045 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(11135, 0, 0, 'I''m here to rescue you.', 0, 0, ''), -- Lilian Voss
(9492, 0, 0, 'Use the outhouse.', 0, 0, ''), -- Amberpine Outhouse
(12927, 0, 3, 'I seek further druidic training to have a closer understanding of the Earth Mother''s will.', 0, 0, ''), -- Muha
(12927, 1, 0, 'I wish to unlearn my talents.', 0, 0, ''), -- Muha
(13045, 0, 2, 'I''d like to travel by air.', 0, 0, ''); -- Pricilla Winterwind

UPDATE `gossip_menu_option` SET `option_text`='Is there something I can do at the Sanctuary of Malorne?' WHERE `menu_id`=11493 AND `id`=2; -- Ysera
UPDATE `gossip_menu_option` SET `option_text`='Is there something I can do at the Sanctuary of Malorne?' WHERE `menu_id`=11494 AND `id`=2; -- Ysera
UPDATE `gossip_menu_option` SET `option_text`='I am ready to hear your story, Oronok.' WHERE `menu_id`=8259 AND `id`=1; -- Oronok Torn-heart
UPDATE `gossip_menu_option` SET `option_text`='I want to fly on the wings of the bronze flight.' WHERE `menu_id`=9574 AND `id`=1; -- Eternos
UPDATE `gossip_menu_option` SET `option_text`='What abilities do amber drakes have?' WHERE `menu_id`=9574 AND `id`=4; -- Eternos
UPDATE `gossip_menu_option` SET `option_text`='\"Stash?\"' WHERE `menu_id`=9041 AND `id`=2; -- Captain "Stash" Torgoley
UPDATE `gossip_menu_option` SET `option_text`='\"Stash?\"' WHERE `menu_id`=9042 AND `id`=2; -- Captain "Stash" Torgoley
UPDATE `gossip_menu_option` SET `option_text`='\"Stash?\"' WHERE `menu_id`=9040 AND `id`=2; -- Captain "Stash" Torgoley
UPDATE `gossip_menu_option` SET `option_text`='We''ve killed your captors. You''re free to go.' WHERE `menu_id`=12805 AND `id`=0; -- Norkani
UPDATE `gossip_menu_option` SET `option_text`='Chromie, you and I both know what''s going to happen in this time stream. We''ve seen this all before.$B$BCan you just skip us ahead to all the real action?' WHERE `menu_id`=9586 AND `id`=2; -- Chromie
UPDATE `gossip_menu_option` SET `option_text`='I want to fly on the wings of the bronze flight.' WHERE `menu_id`=9574 AND `id`=1; -- Eternos
UPDATE `gossip_menu_option` SET `option_text`='What abilities do amber drakes have?' WHERE `menu_id`=9574 AND `id`=4; -- Eternos
UPDATE `gossip_menu_option` SET `option_text`='Then repeat after me: \"Lok''tar ogar! Victory or death - it is these words that bind me to the Horde. For they are the most sacred and fundamental of truths to any warrior of the Horde.

I give my flesh and blood freely to the Warchief. I am the instrument of my Warchief''s desire. I am a weapon of my Warchief''s command.

From this moment until the end of days I live and die - For the Horde!\"' WHERE `menu_id`=9304 AND `id`=0; -- Taunka'le Refugee

UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=208263; -- -Unknown-

DELETE FROM `creature_equip_template` WHERE `entry` IN (39002, 44636, 44640, 44629, 44790, 44789, 51128, 44899, 45228, 45225, 45280, 45292, 45479, 45376, 45484, 45315, 45313, 45312, 45374, 44375, 12736, 27260, 54214, 18488, 27160, 27566, 26344, 25975, 53405, 32702, 27500, 17326, 30189, 30657, 28179, 30377, 30443, 30188, 30595, 30685, 30596, 30989, 39445, 39756, 40845, 39974, 24240);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(39002, 38723, 0, 0), -- Scarlet Lieutenant Gebler
(44636, 21580, 0, 0), -- Hellscream's Elite
(44640, 47031, 0, 0), -- High Warlord Cromush
(44629, 30414, 0, 0), -- Garrosh Hellscream
(44790, 2184, 2184, 0), -- Deathstalker
(44789, 57195, 57195, 0), -- Deathstalker Commander Belmont
(51128, 14533, 0, 0), -- Wildhammer Guard
(44899, 5282, 5282, 0), -- Deathstalker Rane Yorick
(45228, 36790, 0, 0), -- Master Forteski
(45225, 18167, 18166, 0), -- Veteran Forsaken Trooper
(45280, 30439, 0, 52052), -- Forsaken Vanguard
(45292, 40967, 40968, 0), -- Worgen Rebel
(45479, 0, 0, 11021), -- Bat Handler Doomair
(45376, 0, 0, 11021), -- Forsaken Sharpshooter
(45484, 1903, 0, 11021), -- Provisioner Angelus
(45315, 49020, 32885, 0), -- Forward Commander Onslaught
(45313, 2184, 2184, 0), -- Deathstalker
(45312, 57195, 57195, 0), -- Deathstalker Commander Belmont
(45374, 0, 0, 49711), -- Forsaken Blightspreader
(44375, 44236, 0, 0), -- Zeya
(12736, 13336, 0, 0), -- Je'neu Sancrea
(27260, 34820, 0, 0), -- Dragonflayer Huscarl
(54214, 2703, 0, 0), -- Scott Keenan
(18488, 27852, 0, 0), -- Telaari Watcher
(27160, 37120, 143, 2551), -- 7th Legion Infantryman
(27566, 2827, 0, 0), -- Unu'pe Villager
(26344, 6680, 0, 0), -- Indu'le Warrior
(25975, 2200, 0, 0), -- Master Fire Eater
(53405, 62032, 0, 0), -- Raedra Windhammer
(32702, 44654, 0, 0), -- Drog Skullbreaker
(27500, 34640, 21549, 0), -- Conquest Hold Berserker
(17326, 6227, 0, 0), -- Blacksilt Scout
(30189, 42544, 42543, 0), -- Crusader of Virtue
(30657, 1911, 1903, 0), -- Siegemaster Fezzik
(28179, 13262, 0, 0), -- Highlord Tirion Fordring
(30377, 40276, 40276, 0), -- The Ebon Watcher
(30443, 36942, 0, 0), -- The Lich King
(30188, 37917, 0, 0), -- Argent Champion
(30595, 13262, 0, 0), -- Highlord Tirion Fordring
(30685, 1902, 0, 0), -- Argent Mason
(30596, 40276, 40276, 0), -- The Ebon Watcher
(30989, 33169, 33169, 0), -- Halof the Deathbringer
(39445, 15903, 15907, 0), -- Lycanthoth Vandal
(39756, 52517, 0, 0), -- The Manipulator
(40845, 52063, 52063, 0), -- Forgemaster Pyrendius
(39974, 40606, 0, 0), -- Twilight Inferno Lord
(24240, 32856, 0, 0); -- Alyson Antille


UPDATE `creature_equip_template` SET `itemEntry1`=0 WHERE `entry`=27573; -- Taunka Huntsman
UPDATE `creature_equip_template` SET `itemEntry1`=0 WHERE `entry`=29505; -- Imindril Spearsong
UPDATE `creature_equip_template` SET `itemEntry1`=0 WHERE `entry`=39006; -- Siege Tank Engineer
UPDATE `creature_equip_template` SET `itemEntry1`=0, `itemEntry2`=0 WHERE `entry`=16582; -- Thrallmar Marksman
UPDATE `creature_equip_template` SET `itemEntry1`=0, `itemEntry3`=2550 WHERE `entry`=987; -- Ogromm
UPDATE `creature_equip_template` SET `itemEntry1`=10612, `itemEntry2`=12452, `itemEntry3`=5260 WHERE `entry`=866; -- Stonard Grunt
UPDATE `creature_equip_template` SET `itemEntry1`=10898, `itemEntry2`=12456 WHERE `entry`=18489; -- Garadar Defender
UPDATE `creature_equip_template` SET `itemEntry1`=10898, `itemEntry2`=12456 WHERE `entry`=42937; -- Blackrock Invader
UPDATE `creature_equip_template` SET `itemEntry1`=11019 WHERE `entry`=981; -- Hartash
UPDATE `creature_equip_template` SET `itemEntry1`=11087, `itemEntry2`=0 WHERE `entry`=985; -- Malosh
UPDATE `creature_equip_template` SET `itemEntry1`=12742, `itemEntry2`=3757 WHERE `entry`=24642; -- Drunken Northsea Pirate
UPDATE `creature_equip_template` SET `itemEntry1`=12744, `itemEntry2`=0, `itemEntry3`=0 WHERE `entry`=2084; -- Natheril Raincaller
UPDATE `creature_equip_template` SET `itemEntry1`=12801 WHERE `entry`=19147; -- Allerian Peasant
UPDATE `creature_equip_template` SET `itemEntry1`=12850, `itemEntry3`=0 WHERE `entry`=989; -- Banalash
UPDATE `creature_equip_template` SET `itemEntry1`=12944, `itemEntry2`=143 WHERE `entry`=16842; -- Honor Hold Defender
UPDATE `creature_equip_template` SET `itemEntry1`=13612 WHERE `entry`=48125; -- Advisor Sarophas
UPDATE `creature_equip_template` SET `itemEntry1`=13622 WHERE `entry`=1853; -- Darkmaster Gandling
UPDATE `creature_equip_template` SET `itemEntry1`=14475 WHERE `entry`=17138; -- Warmaul Reaver
UPDATE `creature_equip_template` SET `itemEntry1`=14877 WHERE `entry`=44791; -- Forsaken Trooper
UPDATE `creature_equip_template` SET `itemEntry1`=1493 WHERE `entry`=30380; -- Skybreaker Cannoneer
UPDATE `creature_equip_template` SET `itemEntry1`=17383 WHERE `entry`=18489; -- Garadar Defender
UPDATE `creature_equip_template` SET `itemEntry1`=17383 WHERE `entry`=19068; -- Garadar Wolf Rider
UPDATE `creature_equip_template` SET `itemEntry1`=17383 WHERE `entry`=41431; -- Grimtotem Invader
UPDATE `creature_equip_template` SET `itemEntry1`=18062 WHERE `entry`=44791; -- Forsaken Trooper
UPDATE `creature_equip_template` SET `itemEntry1`=1901, `itemEntry2`=0 WHERE `entry`=760; -- Lost One Muckdweller
UPDATE `creature_equip_template` SET `itemEntry1`=19014 WHERE `entry`=45334; -- Twilight Bonebreaker
UPDATE `creature_equip_template` SET `itemEntry1`=19015 WHERE `entry`=15062; -- Arathi Lumberjack
UPDATE `creature_equip_template` SET `itemEntry1`=1902 WHERE `entry`=22407; -- Caravan Defender
UPDATE `creature_equip_template` SET `itemEntry1`=1902 WHERE `entry`=26112; -- Bor'gorok Peon
UPDATE `creature_equip_template` SET `itemEntry1`=1902 WHERE `entry`=44158; -- Orgrimmar Skyway Peon
UPDATE `creature_equip_template` SET `itemEntry1`=1903 WHERE `entry`=16831; -- Nethergarde Infantry
UPDATE `creature_equip_template` SET `itemEntry1`=1903 WHERE `entry`=21405; -- Ethereal Arcanist
UPDATE `creature_equip_template` SET `itemEntry1`=1903, `itemEntry2`=0 WHERE `entry`=16864; -- Stormwind Infantry
UPDATE `creature_equip_template` SET `itemEntry1`=1903, `itemEntry2`=0 WHERE `entry`=980; -- Grimnal
UPDATE `creature_equip_template` SET `itemEntry1`=1903, `itemEntry3`=0 WHERE `entry`=1322; -- Maxton Strang
UPDATE `creature_equip_template` SET `itemEntry1`=1904 WHERE `entry`=1161; -- Stonesplinter Trogg
UPDATE `creature_equip_template` SET `itemEntry1`=1904 WHERE `entry`=41122; -- Frostmane Snowstrider
UPDATE `creature_equip_template` SET `itemEntry1`=1904, `itemEntry2`=2081 WHERE `entry`=864; -- Stonard Orc
UPDATE `creature_equip_template` SET `itemEntry1`=1904, `itemEntry3`=5260 WHERE `entry`=759; -- Lost One Hunter
UPDATE `creature_equip_template` SET `itemEntry1`=1905 WHERE `entry`=543; -- Nalesette Wildbringer
UPDATE `creature_equip_template` SET `itemEntry1`=1905, `itemEntry2`=0 WHERE `entry`=2267; -- Hillsbrad Peasant
UPDATE `creature_equip_template` SET `itemEntry1`=1906 WHERE `entry`=1162; -- Stonesplinter Scout
UPDATE `creature_equip_template` SET `itemEntry1`=1906 WHERE `entry`=39870; -- Twilight Firecatcher
UPDATE `creature_equip_template` SET `itemEntry1`=1906 WHERE `entry`=39890; -- Twilight Earthshaper
UPDATE `creature_equip_template` SET `itemEntry1`=1907, `itemEntry2`=0 WHERE `entry`=1174; -- Tunnel Rat Geomancer
UPDATE `creature_equip_template` SET `itemEntry1`=1908 WHERE `entry`=761; -- Lost One Seer
UPDATE `creature_equip_template` SET `itemEntry1`=1908, `itemEntry2`=0 WHERE `entry`=1165; -- Stonesplinter Geomancer
UPDATE `creature_equip_template` SET `itemEntry1`=1908, `itemEntry2`=0 WHERE `entry`=1197; -- Stonesplinter Shaman
UPDATE `creature_equip_template` SET `itemEntry1`=1910 WHERE `entry`=15075; -- Forsaken Miner
UPDATE `creature_equip_template` SET `itemEntry1`=1910 WHERE `entry`=19610; -- Irradiated Worker
UPDATE `creature_equip_template` SET `itemEntry1`=1910 WHERE `entry`=38409; -- Goblin Survivor
UPDATE `creature_equip_template` SET `itemEntry1`=1910 WHERE `entry`=38745; -- Kezan Citizen
UPDATE `creature_equip_template` SET `itemEntry1`=1910 WHERE `entry`=40776; -- Speedbarge Crewmember
UPDATE `creature_equip_template` SET `itemEntry1`=1910 WHERE `entry`=40779; -- Speedbarge Crewmember
UPDATE `creature_equip_template` SET `itemEntry1`=1911 WHERE `entry`=20203; -- Nether Technician
UPDATE `creature_equip_template` SET `itemEntry1`=1911 WHERE `entry`=29016; -- Steam Tank Engineer
UPDATE `creature_equip_template` SET `itemEntry1`=1911 WHERE `entry`=46082; -- Engineer Niff
UPDATE `creature_equip_template` SET `itemEntry1`=1925 WHERE `entry`=28126; -- Don Carlos
UPDATE `creature_equip_template` SET `itemEntry1`=1983 WHERE `entry`=763; -- Lost One Chieftain
UPDATE `creature_equip_template` SET `itemEntry1`=19980, `itemEntry2`=19980 WHERE `entry`=18794; -- Cabal Ritualist
UPDATE `creature_equip_template` SET `itemEntry1`=2023, `itemEntry2`=0, `itemEntry3`=2552 WHERE `entry`=853; -- Coldridge Mountaineer
UPDATE `creature_equip_template` SET `itemEntry1`=21465 WHERE `entry`=16580; -- Thrallmar Grunt
UPDATE `creature_equip_template` SET `itemEntry1`=21573 WHERE `entry`=42218; -- Stormwind Royal Guard
UPDATE `creature_equip_template` SET `itemEntry1`=2180, `itemEntry2`=1984 WHERE `entry`=1090; -- Mountaineer Wallbang
UPDATE `creature_equip_template` SET `itemEntry1`=2180, `itemEntry2`=1984, `itemEntry3`=0 WHERE `entry`=1089; -- Mountaineer Cobbleflint
UPDATE `creature_equip_template` SET `itemEntry1`=2180, `itemEntry2`=1984, `itemEntry3`=2552 WHERE `entry`=1276; -- Mountaineer Brokk
UPDATE `creature_equip_template` SET `itemEntry1`=2180, `itemEntry2`=1984, `itemEntry3`=2552 WHERE `entry`=1338; -- Mountaineer Dalk
UPDATE `creature_equip_template` SET `itemEntry1`=2182, `itemEntry2`=1984, `itemEntry3`=2552 WHERE `entry`=1277; -- Mountaineer Ganin
UPDATE `creature_equip_template` SET `itemEntry1`=2182, `itemEntry2`=1984, `itemEntry3`=2552 WHERE `entry`=1281; -- Mountaineer Zaren
UPDATE `creature_equip_template` SET `itemEntry1`=2182, `itemEntry2`=1984, `itemEntry3`=2552 WHERE `entry`=2105; -- Mountaineer Dokkin
UPDATE `creature_equip_template` SET `itemEntry1`=2183, `itemEntry2`=1984 WHERE `entry`=1342; -- Mountaineer Rockgar
UPDATE `creature_equip_template` SET `itemEntry1`=2183, `itemEntry2`=1984, `itemEntry3`=2552 WHERE `entry`=1283; -- Mountaineer Kalmir
UPDATE `creature_equip_template` SET `itemEntry1`=2183, `itemEntry2`=1984, `itemEntry3`=2552 WHERE `entry`=1330; -- Mountaineer Tyraw
UPDATE `creature_equip_template` SET `itemEntry1`=2184 WHERE `entry`=590; -- Defias Looter
UPDATE `creature_equip_template` SET `itemEntry1`=2196 WHERE `entry`=1699; -- Gremlock Pilsnor
UPDATE `creature_equip_template` SET `itemEntry1`=2196 WHERE `entry`=46709; -- Arugi
UPDATE `creature_equip_template` SET `itemEntry1`=2196, `itemEntry2`=13854 WHERE `entry`=982; -- Thultash
UPDATE `creature_equip_template` SET `itemEntry1`=2198, `itemEntry2`=3698 WHERE `entry`=1386; -- Rogvar
UPDATE `creature_equip_template` SET `itemEntry1`=2200, `itemEntry2`=0 WHERE `entry`=25962; -- Fire Eater
UPDATE `creature_equip_template` SET `itemEntry1`=2202 WHERE `entry`=34830; -- Defiant Troll
UPDATE `creature_equip_template` SET `itemEntry1`=2202, `itemEntry2`=19485 WHERE `entry`=1425; -- Grizlak
UPDATE `creature_equip_template` SET `itemEntry1`=2202, `itemEntry2`=3350, `itemEntry3`=0 WHERE `entry`=1398; -- Boss Galgosh
UPDATE `creature_equip_template` SET `itemEntry1`=23906 WHERE `entry`=17659; -- Blade of Argus
UPDATE `creature_equip_template` SET `itemEntry1`=23906, `itemEntry2`=23907 WHERE `entry`=16733; -- Exodar Peacekeeper
UPDATE `creature_equip_template` SET `itemEntry1`=2559, `itemEntry2`=0 WHERE `entry`=988; -- Kartosh
UPDATE `creature_equip_template` SET `itemEntry1`=25758 WHERE `entry`=22018; -- Eclipsion Cavalier
UPDATE `creature_equip_template` SET `itemEntry1`=2695 WHERE `entry`=1718; -- Rockjaw Raider
UPDATE `creature_equip_template` SET `itemEntry1`=2695 WHERE `entry`=22407; -- Caravan Defender
UPDATE `creature_equip_template` SET `itemEntry1`=2704 WHERE `entry`=35063; -- Kezan Citizen
UPDATE `creature_equip_template` SET `itemEntry1`=2704 WHERE `entry`=35075; -- Kezan Citizen
UPDATE `creature_equip_template` SET `itemEntry1`=2704, `itemEntry2`=13407 WHERE `entry`=16831; -- Nethergarde Infantry
UPDATE `creature_equip_template` SET `itemEntry1`=2717 WHERE `entry`=40529; -- Gnome Bar Patron
UPDATE `creature_equip_template` SET `itemEntry1`=2717, `itemEntry2`=3757 WHERE `entry`=16864; -- Stormwind Infantry
UPDATE `creature_equip_template` SET `itemEntry1`=2717, `itemEntry2`=53108 WHERE `entry`=40092; -- Southsea Sailor
UPDATE `creature_equip_template` SET `itemEntry1`=27850, `itemEntry2`=27851 WHERE `entry`=19071; -- Telaari Elekk Rider
UPDATE `creature_equip_template` SET `itemEntry1`=2809, `itemEntry2`=1984, `itemEntry3`=2552 WHERE `entry`=1282; -- Mountaineer Veek
UPDATE `creature_equip_template` SET `itemEntry1`=2809, `itemEntry2`=1984, `itemEntry3`=2552 WHERE `entry`=1329; -- Mountaineer Naarh
UPDATE `creature_equip_template` SET `itemEntry1`=2809, `itemEntry2`=2081 WHERE `entry`=986; -- Haromm
UPDATE `creature_equip_template` SET `itemEntry1`=2884, `itemEntry2`=0 WHERE `entry`=1073; -- Ashlan Stonesmirk
UPDATE `creature_equip_template` SET `itemEntry1`=28914 WHERE `entry`=38217; -- Darkspear Watcher
UPDATE `creature_equip_template` SET `itemEntry1`=2901 WHERE `entry`=41911; -- Forsaken Invader
UPDATE `creature_equip_template` SET `itemEntry1`=30180, `itemEntry2`=30180 WHERE `entry`=19362; -- Kor'kron Defender
UPDATE `creature_equip_template` SET `itemEntry1`=30636, `itemEntry2`=0 WHERE `entry`=19792; -- Eclipsion Centurion
UPDATE `creature_equip_template` SET `itemEntry1`=31273 WHERE `entry`=27953; -- Wyrmrest Protector
UPDATE `creature_equip_template` SET `itemEntry1`=31311 WHERE `entry`=42296; -- Shadowsworn Spellblade
UPDATE `creature_equip_template` SET `itemEntry1`=31551 WHERE `entry`=45798; -- Crushblow Warrior
UPDATE `creature_equip_template` SET `itemEntry1`=31551, `itemEntry2`=0 WHERE `entry`=22253; -- Dragonmaw Ascendant
UPDATE `creature_equip_template` SET `itemEntry1`=31604, `itemEntry2`=0 WHERE `entry`=23146; -- Dragonmaw Enforcer
UPDATE `creature_equip_template` SET `itemEntry1`=32322, `itemEntry2`=32322 WHERE `entry`=22982; -- Skyguard Navigator
UPDATE `creature_equip_template` SET `itemEntry1`=32371 WHERE `entry`=23257; -- Skyguard Windcharger
UPDATE `creature_equip_template` SET `itemEntry1`=32499 WHERE `entry`=23115; -- Ogri'la Peacekeeper
UPDATE `creature_equip_template` SET `itemEntry1`=3326 WHERE `entry`=23676; -- Iron Rune Destroyer
UPDATE `creature_equip_template` SET `itemEntry1`=33276 WHERE `entry`=24015; -- Winterskorn Defender
UPDATE `creature_equip_template` SET `itemEntry1`=3346, `itemEntry3`=0 WHERE `entry`=1167; -- Stonesplinter Digger
UPDATE `creature_equip_template` SET `itemEntry1`=3350, `itemEntry2`=0 WHERE `entry`=1164; -- Stonesplinter Bonesnapper
UPDATE `creature_equip_template` SET `itemEntry1`=3362 WHERE `entry`=47657; -- Suspicious Villager
UPDATE `creature_equip_template` SET `itemEntry1`=3367 WHERE `entry`=37067; -- Crash Survivor
UPDATE `creature_equip_template` SET `itemEntry1`=34596, `itemEntry2`=34590 WHERE `entry`=25115; -- Shattered Sun Warrior
UPDATE `creature_equip_template` SET `itemEntry1`=34820, `itemEntry2`=0 WHERE `entry`=25521; -- Skadir Longboatsman
UPDATE `creature_equip_template` SET `itemEntry1`=3699, `itemEntry2`=3695, `itemEntry3`=0 WHERE `entry`=983; -- Thultazor
UPDATE `creature_equip_template` SET `itemEntry1`=37 WHERE `entry`=41913; -- Gilneas Citizen
UPDATE `creature_equip_template` SET `itemEntry1`=3774 WHERE `entry`=1344; -- Prospector Ironband
UPDATE `creature_equip_template` SET `itemEntry1`=38491 WHERE `entry`=27953; -- Wyrmrest Protector
UPDATE `creature_equip_template` SET `itemEntry1`=40595 WHERE `entry`=38493; -- Argent Crusader
UPDATE `creature_equip_template` SET `itemEntry1`=40609, `itemEntry2`=40609 WHERE `entry`=29451; -- Vargul Slayer
UPDATE `creature_equip_template` SET `itemEntry1`=43625, `itemEntry2`=39384 WHERE `entry`=28586; -- General Bjarngrim
UPDATE `creature_equip_template` SET `itemEntry1`=44654 WHERE `entry`=32706; -- Saedelin Whitedawn
UPDATE `creature_equip_template` SET `itemEntry1`=49198 WHERE `entry`=43232; -- Earthen Champion
UPDATE `creature_equip_template` SET `itemEntry1`=50139 WHERE `entry`=38432; -- Megs Dreadshredder
UPDATE `creature_equip_template` SET `itemEntry1`=5278, `itemEntry3`=2550 WHERE `entry`=1442; -- Helgrum the Swift
UPDATE `creature_equip_template` SET `itemEntry1`=5285, `itemEntry2`=0 WHERE `entry`=2303; -- Lyranne Feathersong
UPDATE `creature_equip_template` SET `itemEntry1`=5287 WHERE `entry`=2483; -- Jaquilina Dramet
UPDATE `creature_equip_template` SET `itemEntry1`=5289 WHERE `entry`=17138; -- Warmaul Reaver
UPDATE `creature_equip_template` SET `itemEntry1`=5289 WHERE `entry`=7027; -- Blackrock Slayer
UPDATE `creature_equip_template` SET `itemEntry1`=5292 WHERE `entry`=17134; -- Boulderfist Crusher
UPDATE `creature_equip_template` SET `itemEntry1`=5598, `itemEntry3`=0 WHERE `entry`=2302; -- Aethalas
UPDATE `creature_equip_template` SET `itemEntry1`=57125 WHERE `entry`=43229; -- Injured Earthen
UPDATE `creature_equip_template` SET `itemEntry1`=59141 WHERE `entry`=1399; -- Magosh
UPDATE `creature_equip_template` SET `itemEntry1`=6225 WHERE `entry`=17190; -- Siltfin Murloc
UPDATE `creature_equip_template` SET `itemEntry1`=6225 WHERE `entry`=17191; -- Siltfin Oracle
UPDATE `creature_equip_template` SET `itemEntry1`=6227 WHERE `entry`=17191; -- Siltfin Oracle
UPDATE `creature_equip_template` SET `itemEntry1`=6228 WHERE `entry`=17190; -- Siltfin Murloc
UPDATE `creature_equip_template` SET `itemEntry1`=6229 WHERE `entry`=17192; -- Siltfin Hunter
UPDATE `creature_equip_template` SET `itemEntry1`=6233 WHERE `entry`=18240; -- Sunspring Villager
UPDATE `creature_equip_template` SET `itemEntry1`=77365, `itemEntry3`=77364 WHERE `entry`=48737; -- Tyrande Whisperwind
UPDATE `creature_equip_template` SET `itemEntry1`=77365, `itemEntry3`=77364 WHERE `entry`=54179; -- Tyrande Whisperwind
UPDATE `creature_equip_template` SET `itemEntry1`=77365, `itemEntry3`=77364 WHERE `entry`=7999; -- Tyrande Whisperwind
UPDATE `creature_equip_template` SET `itemEntry1`=851 WHERE `entry`=24911; -- Cursed Sea Dog
UPDATE `creature_equip_template` SET `itemEntry1`=9701 WHERE `entry`=35186; -- Kezan Partygoer
UPDATE `creature_equip_template` SET `itemEntry2`=0 WHERE `entry`=23146; -- Dragonmaw Enforcer
UPDATE `creature_equip_template` SET `itemEntry2`=0 WHERE `entry`=984; -- Thralosh
UPDATE `creature_equip_template` SET `itemEntry3`=0 WHERE `entry`=41509; -- Irontree Warden
UPDATE `creature_equip_template` SET `itemEntry3`=12523 WHERE `entry`=1686; -- Irene Sureshot
UPDATE `creature_equip_template` SET `itemEntry3`=44635 WHERE `entry`=32710; -- Garl Grimgrizzle
UPDATE `creature_equip_template` SET `itemEntry3`=44635 WHERE `entry`=32711; -- Warp-Huntress Kula


UPDATE `creature_template` SET `HoverHeight`=15 WHERE `entry`=26276; -- Nexus Guardian
UPDATE `creature_template` SET `HoverHeight`=15 WHERE `entry`=27608; -- Azure Dragon
UPDATE `creature_template` SET `HoverHeight`=4.95 WHERE `entry`=56249; -- Twilight Assaulter
UPDATE `creature_template` SET `HoverHeight`=5.4 WHERE `entry`=56250; -- Twilight Assaulter
UPDATE `creature_template` SET `HoverHeight`=5.4 WHERE `entry`=56251; -- Twilight Assaulter
UPDATE `creature_template` SET `HoverHeight`=6.75 WHERE `entry`=57795; -- Twilight Assaulter
UPDATE `creature_template` SET `baseattacktime`=1000, `unit_flags`=32768, `unit_flags2`=33556480, `dynamicflags`=0 WHERE `entry`=43228; -- Stone Trogg Berserker
UPDATE `creature_template` SET `baseattacktime`=1250 WHERE `entry`=18970; -- Darkspear Axe Thrower
UPDATE `creature_template` SET `baseattacktime`=1250 WHERE `entry`=18972; -- Orgrimmar Shaman
UPDATE `creature_template` SET `baseattacktime`=1333 WHERE `entry`=29844; -- Icebound Revenant
UPDATE `creature_template` SET `baseattacktime`=1333 WHERE `entry`=40291; -- Azureborne Seer
UPDATE `creature_template` SET `baseattacktime`=1500 WHERE `entry`=40320; -- Valiona
UPDATE `creature_template` SET `baseattacktime`=1500 WHERE `entry`=40484; -- Erudax
UPDATE `creature_template` SET `baseattacktime`=1500 WHERE `entry`=41095; -- Twilight Drake
UPDATE `creature_template` SET `baseattacktime`=1818 WHERE `entry`=28034; -- Drakkari Snake Handler
UPDATE `creature_template` SET `baseattacktime`=1818 WHERE `entry`=28036; -- Champion of Sseratus
UPDATE `creature_template` SET `baseattacktime`=2000 WHERE `entry`=15952; -- Maexxna
UPDATE `creature_template` SET `baseattacktime`=2000 WHERE `entry`=31812; -- Decomposed Ghoul
UPDATE `creature_template` SET `baseattacktime`=2000 WHERE `entry`=40998; -- King Moltron
UPDATE `creature_template` SET `baseattacktime`=2000 WHERE `entry`=42453; -- Azsh'ir Abyss Priestess
UPDATE `creature_template` SET `baseattacktime`=2400 WHERE `entry`=23374; -- Ashtongue Stalker
UPDATE `creature_template` SET `baseattacktime`=4000 WHERE `entry`=18966; -- Justinius the Harbinger
UPDATE `creature_template` SET `faction_A`=10, `faction_H`=10, `unit_flags`=32768 WHERE `entry`=25589; -- Bonker Togglevolt
UPDATE `creature_template` SET `faction_A`=113, `faction_H`=113, `unit_flags`=32768 WHERE `entry`=19589; -- Maxx A. Million Mk. V
UPDATE `creature_template` SET `faction_A`=1334, `faction_H`=1334 WHERE `entry`=14848; -- Herald
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE `entry`=49424; -- Marshal Redpath
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14, `dynamicflags`=0 WHERE `entry`=52795; -- Brimstone Hound
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14, `unit_flags`=536903936, `unit_flags2`=2049, `dynamicflags`=32 WHERE `entry`=26943; -- Battered Drakkari Berserker
UPDATE `creature_template` SET `faction_A`=16, `faction_H`=16, `speed_run`=1.142857, `unit_class`=2 WHERE `entry`=24411; -- Shattered Hand Centurion Image
UPDATE `creature_template` SET `faction_A`=1692, `faction_H`=1692, `unit_flags`=0, `unit_flags2`=2052, `dynamicflags`=0 WHERE `entry`=24576; -- Riplash Myrmidon
UPDATE `creature_template` SET `faction_A`=1754, `faction_H`=1754, `unit_flags`=33280 WHERE `entry`=18944; -- Fel Soldier
UPDATE `creature_template` SET `faction_A`=1771, `faction_H`=1771 WHERE `entry`=39390; -- Twilight Drake
UPDATE `creature_template` SET `faction_A`=1843, `faction_H`=1843 WHERE `entry`=22082; -- Shadowmoon Slayer
UPDATE `creature_template` SET `faction_A`=1892, `faction_H`=1892, `npcflag`=3, `unit_flags`=256 WHERE `entry`=26170; -- Thassarian
UPDATE `creature_template` SET `faction_A`=1973, `faction_H`=1973, `unit_flags`=33280 WHERE `entry`=25253; -- Valiance Keep Footman
UPDATE `creature_template` SET `faction_A`=1981, `faction_H`=1981 WHERE `entry`=26488; -- Taunka Pack Kodo
UPDATE `creature_template` SET `faction_A`=2030, `faction_H`=2030 WHERE `entry`=2385; -- Feral Mountain Lion
UPDATE `creature_template` SET `faction_A`=2056, `faction_H`=2056, `speed_run`=1.142857, `unit_flags2`=2052 WHERE `entry`=27553; -- Kor'kron Vanguard
UPDATE `creature_template` SET `faction_A`=2069, `faction_H`=2069 WHERE `entry`=29236; -- Gundrak Brute
UPDATE `creature_template` SET `faction_A`=21, `faction_H`=21 WHERE `entry`=24460; -- Chillmere Tidehunter
UPDATE `creature_template` SET `faction_A`=2156, `faction_H`=2156 WHERE `entry`=47720; -- Camel
UPDATE `creature_template` SET `faction_A`=2209, `faction_H`=2209 WHERE `entry`=37011; -- The Damned
UPDATE `creature_template` SET `faction_A`=2227, `faction_H`=2227, `unit_flags`=32768 WHERE `entry`=38746; -- Gobber
UPDATE `creature_template` SET `faction_A`=2231, `faction_H`=2231 WHERE `entry`=36471; -- Foreman Dampwick
UPDATE `creature_template` SET `faction_A`=2231, `faction_H`=2231 WHERE `entry`=38124; -- Assistant Greely
UPDATE `creature_template` SET `faction_A`=2231, `faction_H`=2231 WHERE `entry`=38511; -- Sally "Salvager" Sandscrew
UPDATE `creature_template` SET `faction_A`=2231, `faction_H`=2231 WHERE `entry`=38738; -- Coach Crosscheck
UPDATE `creature_template` SET `faction_A`=2231, `faction_H`=2231 WHERE `entry`=38120; -- Hobart Grapplehammer
UPDATE `creature_template` SET `faction_A`=2231, `faction_H`=2231, `unit_flags`=32768 WHERE `entry`=36600; -- Geargrinder Gizmo
UPDATE `creature_template` SET `faction_A`=2231, `faction_H`=2231, `unit_flags`=32768 WHERE `entry`=38387; -- Sassy Hardwrench
UPDATE `creature_template` SET `faction_A`=2231, `faction_H`=2231, `unit_flags`=33024 WHERE `entry`=36615; -- Doc Zapnozzle
UPDATE `creature_template` SET `faction_A`=2233, `faction_H`=2233, `unit_flags`=32768 WHERE `entry`=52935; -- Marin Bladewing
UPDATE `creature_template` SET `faction_A`=2233, `faction_H`=2233, `unit_flags`=32768 WHERE `entry`=52964; -- Turak Runetotem
UPDATE `creature_template` SET `faction_A`=232, `faction_H`=232 WHERE `entry`=1741; -- Deathguard Bartrand
UPDATE `creature_template` SET `faction_A`=250, `faction_H`=250 WHERE `entry`=18294; -- Kristen Dipswitch
UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35 WHERE `entry`=24418; -- Steel Gate Flying Machine
UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35, `unit_flags`=537165824, `unit_flags2`=2049, `dynamicflags`=32 WHERE `entry`=26816; -- Focus Wizard
UPDATE `creature_template` SET `faction_A`=778, `faction_H`=778, `unit_flags`=0 WHERE `entry`=23725; -- Stone Giant
UPDATE `creature_template` SET `faction_H`=35 WHERE `entry`=32629; -- Wintergrasp Siege Turret
UPDATE `creature_template` SET `gossip_menu_id`=10206 WHERE `entry`=28070; -- Brann Bronzebeard
UPDATE `creature_template` SET `gossip_menu_id`=10988 WHERE `entry`=38247; -- Ortezza
UPDATE `creature_template` SET `gossip_menu_id`=11067 WHERE `entry`=38647; -- Izzy
UPDATE `creature_template` SET `gossip_menu_id`=11126 WHERE `entry`=38966; -- Vol'jin
UPDATE `creature_template` SET `gossip_menu_id`=11133 WHERE `entry`=38910; -- Lilian Voss
UPDATE `creature_template` SET `gossip_menu_id`=11136 WHERE `entry`=38999; -- Lilian Voss
UPDATE `creature_template` SET `gossip_menu_id`=12356 WHERE `entry`=46603; -- Nomarch Teneth
UPDATE `creature_template` SET `gossip_menu_id`=12976 WHERE `entry`=52134; -- Commander Jarod Shadowsong
UPDATE `creature_template` SET `gossip_menu_id`=12980 WHERE `entry`=53259; -- Arthorn Windsong
UPDATE `creature_template` SET `gossip_menu_id`=13183 WHERE `entry`=55779; -- Thrall
UPDATE `creature_template` SET `gossip_menu_id`=4654 WHERE `entry`=2124; -- Isabella
UPDATE `creature_template` SET `gossip_menu_id`=5729 WHERE `entry`=14358; -- Shen'dralar Ancient
UPDATE `creature_template` SET `gossip_menu_id`=6202 WHERE `entry`=14847; -- Professor Thaddeus Paleo
UPDATE `creature_template` SET `gossip_menu_id`=7552 WHERE `entry`=17772; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `gossip_menu_id`=8383 WHERE `entry`=21772; -- Chief Apothecary Hildagard
UPDATE `creature_template` SET `gossip_menu_id`=9653 WHERE `entry`=26499; -- Arthas
UPDATE `creature_template` SET `maxlevel`=13, `faction_A`=1630, `faction_H`=1630 WHERE `entry`=16301; -- Risen Hungerer
UPDATE `creature_template` SET `maxlevel`=33, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=37924; -- Barrens Operative
UPDATE `creature_template` SET `maxlevel`=55, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=11730; -- Hive'Regal Ambusher
UPDATE `creature_template` SET `maxlevel`=61, `speed_run`=1.142857 WHERE `entry`=19149; -- Telaari Citizen
UPDATE `creature_template` SET `minlevel`=13, `maxlevel`=13, `faction_A`=1630, `faction_H`=1630 WHERE `entry`=16323; -- Phantasmal Seeker
UPDATE `creature_template` SET `minlevel`=15 WHERE `entry`=3274; -- Kolkar Pack Runner
UPDATE `creature_template` SET `minlevel`=15 WHERE `entry`=3461; -- Oasis Snapjaw
UPDATE `creature_template` SET `minlevel`=15 WHERE `entry`=34706; -- Theramore Sharpshooter
UPDATE `creature_template` SET `minlevel`=15, `maxlevel`=15 WHERE `entry`=43103; -- Bluetip Thresher
UPDATE `creature_template` SET `minlevel`=15, `maxlevel`=15, `baseattacktime`=3500 WHERE `entry`=48445; -- Oaf Lackey
UPDATE `creature_template` SET `minlevel`=15, `maxlevel`=15, `faction_A`=67, `faction_H`=67, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=256, `VehicleId`=665 WHERE `entry`=39002; -- Scarlet Lieutenant Gebler
UPDATE `creature_template` SET `minlevel`=7, `maxlevel`=7, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=39080; -- Sparky
UPDATE `creature_template` SET `minlevel`=70, `faction_A`=14, `faction_H`=14, `unit_flags2`=2048 WHERE `entry`=24901; -- Maddened Frosthorn
UPDATE `creature_template` SET `speed_run`=1.428571 WHERE `entry`=17306; -- Watchkeeper Gargolmar
UPDATE `creature_template` SET `minlevel`=74, `speed_walk`=1, `speed_run`=0.9920629 WHERE `entry`=31755; -- Stabled Hunter Pet
UPDATE `creature_template` SET `speed_run`=0.8571429 WHERE `entry`=28961; -- Titanium Siegebreaker
UPDATE `creature_template` SET `speed_run`=0.8571429 WHERE `entry`=28965; -- Titanium Thunderer
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=44790; -- Deathstalker
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=14363; -- Thief Catcher Shadowdelve
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=14365; -- Thief Catcher Farmountain
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=14367; -- Thief Catcher Thunderbrew
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=40728; -- Whale Shark
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=46180; -- Ithurian Whitespire
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=47581; -- Archmage Aranhir Starsinger
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=47582; -- Erdunor Whitespire
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=34976; -- Ruk Warstomper
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=34978; -- Mosha Starhorn
UPDATE `creature_template` SET `speed_run`=0.4285714, `dynamicflags`=0 WHERE `entry`=54322; -- Deth'tilac
UPDATE `creature_template` SET `speed_run`=0.9920629 WHERE `entry`=25880; -- Minion of Kaw
UPDATE `creature_template` SET `speed_run`=0.9920629 WHERE `entry`=40482; -- Earthen Ring Wavebinder
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=18490; -- Fallen Druid
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=25242; -- Warsong Battleguard
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=26725; -- Wind Tamer Oril
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=27768; -- Image of Razuvious
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=27973; -- Crystalline Shardling
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=32601; -- Dalaran Visitor
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=25439; -- Warsong Scout
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=53840; -- Gart Mistrunner
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=53841; -- Zen'tabra
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=53844; -- Celestine of the Harvest
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=33587200 WHERE `entry`=28221; -- Trapdoor Crawler
UPDATE `creature_template` SET `speed_run`=1.289683 WHERE `entry`=23739; -- Valgarde Defender
UPDATE `creature_template` SET `speed_run`=1.385714 WHERE `entry`=12996; -- Mounted Ironforge Mountaineer
UPDATE `creature_template` SET `speed_run`=1.385714 WHERE `entry`=32597; -- Dalaran Visitor
UPDATE `creature_template` SET `speed_run`=1.385714 WHERE `entry`=32598; -- Dalaran Visitor
UPDATE `creature_template` SET `speed_run`=1.385714 WHERE `entry`=34864; -- Gilneas City Guard
UPDATE `creature_template` SET `speed_run`=1.385714 WHERE `entry`=36642; -- Myralion Sunblaze
UPDATE `creature_template` SET `speed_run`=1.385714 WHERE `entry`=47428; -- Hellscream's Sentry
UPDATE `creature_template` SET `speed_walk`=0.5, `speed_run`=0.4960314, `unit_flags`=541065216 WHERE `entry`=43170; -- Earthen Geomancer
UPDATE `creature_template` SET `speed_walk`=0.5, `speed_run`=0.5714286 WHERE `entry`=24213; -- Firjus the Soul Crusher
UPDATE `creature_template` SET `speed_walk`=0.5, `speed_run`=0.5714286 WHERE `entry`=32325; -- Gold Priest
UPDATE `creature_template` SET `speed_walk`=0.5, `speed_run`=0.5714286, `dynamicflags`=4 WHERE `entry`=47462; -- Archduke Calcinder
UPDATE `creature_template` SET `speed_walk`=0.5, `speed_run`=0.5714286, `unit_flags`=536903680, `unit_flags2`=0, `dynamicflags`=4 WHERE `entry`=46493; -- Warlord Halthar
UPDATE `creature_template` SET `speed_walk`=0.5, `speed_run`=1.071429 WHERE `entry`=20998; -- Ridgespine Horror
UPDATE `creature_template` SET `speed_walk`=0.6, `speed_run`=0.6857143, `baseattacktime`=1995 WHERE `entry`=46825; -- Restless Soldier
UPDATE `creature_template` SET `speed_walk`=0.6, `speed_run`=1.142857 WHERE `entry`=45314; -- Arthura
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=29019; -- Dockhand
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=29917; -- Field Corpse (Type B)
UPDATE `creature_template` SET `speed_walk`=0.666668, `baseattacktime`=2000 WHERE `entry`=25843; -- Northsea Thug
UPDATE `creature_template` SET `speed_walk`=0.666668, `speed_run`=1.142857 WHERE `entry`=5761; -- Deviate Shambler
UPDATE `creature_template` SET `speed_walk`=0.8, `speed_run`=0.9920629, `unit_flags`=32768 WHERE `entry`=26461; -- Scourge Corpserender
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=17878; -- Scourge Siege Engineer
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=27537; -- Fordragon Lumberjack
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=27779; -- Image of Noth
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=50701; -- Trained Pygmy
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=12736; -- Je'neu Sancrea
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=24196; -- Trapped Animal
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=27290; -- Hungering Dead
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=32343; -- Green Priest
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=3653; -- Kresh
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=3654; -- Mutanus the Devourer
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=3669; -- Lord Cobrahn
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=3670; -- Lord Pythas
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=3679; -- Naralex
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=44375; -- Zeya
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=44636; -- Hellscream's Elite
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=44640; -- High Warlord Cromush
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=44789; -- Deathstalker Commander Belmont
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=44987; -- Worgen Sentry
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45032; -- Fenris Keep Stalker
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45225; -- Veteran Forsaken Trooper
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45228; -- Master Forteski
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45236; -- Packleader Ivar Bloodfang
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45270; -- Hillsbrad Worgen
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45280; -- Forsaken Vanguard
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45292; -- Worgen Rebel
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45312; -- Deathstalker Commander Belmont
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45313; -- Deathstalker
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45315; -- Forward Commander Onslaught
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45374; -- Forsaken Blightspreader
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45375; -- Worgen Rusher
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45376; -- Forsaken Sharpshooter
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45479; -- Bat Handler Doomair
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=45484; -- Provisioner Angelus
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=46889; -- Kagtha
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=46890; -- Shattered Hand Assassin
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=46902; -- Miss Mayhem
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=46903; -- Mayhem Reaper Prototype
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=46906; -- Slinky Sharpshiv
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=5048; -- Deviate Adder
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=5755; -- Deviate Viper
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=5762; -- Deviate Moccasin
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=5763; -- Nightmare Ectoplasm
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=8886; -- Deviate Python
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857, `dynamicflags`=4 WHERE `entry`=42594; -- Orgrimmar Thief
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857, `unit_flags2`=2049 WHERE `entry`=44899; -- Deathstalker Rane Yorick
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857, `unit_flags2`=33556480 WHERE `entry`=46598; -- General Purpose Bunny JMF x2 size
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857, `unit_flags`=262400 WHERE `entry`=32321; -- Green Warrior
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857, `unit_flags`=768 WHERE `entry`=27766; -- Image of Kel'Thuzad
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.285714 WHERE `entry`=5914; -- Deviate Nightmare
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.289683 WHERE `entry`=12876; -- Baron Aquanis
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.428571 WHERE `entry`=54634; -- Thrall
UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=1.142857 WHERE `entry`=45120; -- Orc Demolisher
UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=3 WHERE `entry`=25765; -- Fizzcrank Bomber
UPDATE `creature_template` SET `speed_walk`=1.6, `speed_run`=0.5714286 WHERE `entry`=45704; -- Lurking Tempest
UPDATE `creature_template` SET `speed_walk`=1.6, `speed_run`=1.571429 WHERE `entry`=45301; -- Korok the Colossus
UPDATE `creature_template` SET `speed_walk`=1.6, `unit_class`=1 WHERE `entry`=24410; -- Vazruden the Herald Image
UPDATE `creature_template` SET `speed_walk`=2.8, `speed_run`=2 WHERE `entry`=45282; -- Forsaken Catapult
UPDATE `creature_template` SET `unit_class`=2 WHERE `entry`=26858; -- Sarathstra
UPDATE `creature_template` SET `unit_flags2`=33622016 WHERE `entry`=38745; -- Kezan Citizen
UPDATE `creature_template` SET `unit_flags2`=34816 WHERE `entry`=56027; -- Stormherald Eljrrin
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=18351; -- Lump
UPDATE `creature_template` SET `unit_flags`=16640 WHERE `entry`=40639; -- Engineer Hexascrub
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=15103; -- Stormpike Emissary
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=15106; -- Frostwolf Emissary
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=22013; -- Eye of the Storm Emissary
UPDATE `creature_template` SET `unit_flags`=295680 WHERE `entry`=28401; -- Har'koa
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=52495; -- Shalis Darkhunter
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=20102; -- Goblin Commoner
