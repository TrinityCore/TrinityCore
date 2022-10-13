DELETE FROM `gossip_menu` WHERE (`MenuID`=10637 AND `TextID`=14735) OR (`MenuID`=27404 AND `TextID`=41815) OR (`MenuID`=26132 AND `TextID`=41814) OR (`MenuID`=16820 AND `TextID`=24454) OR (`MenuID`=24215 AND `TextID`=37924) OR (`MenuID`=25652 AND `TextID`=40491) OR (`MenuID`=25591 AND `TextID`=7778) OR (`MenuID`=25955 AND `TextID`=41160) OR (`MenuID`=26145 AND `TextID`=41506) OR (`MenuID`=26091 AND `TextID`=41439) OR (`MenuID`=26122 AND `TextID`=41481) OR (`MenuID`=25654 AND `TextID`=40493) OR (`MenuID`=26924 AND `TextID`=42877) OR (`MenuID`=26775 AND `TextID`=42569);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(10637, 14735, 45745), -- 35315 (Narimar)
(27404, 41815, 45745), -- 171795 (Lady Moonberry)
(26132, 41814, 45745), -- 171795 (Lady Moonberry)
(16820, 24454, 45745), -- 81674 (Nisha)
(24215, 37924, 45745), -- 153757 (Kelya Moonfall)
(25652, 40491, 45745), -- 156295 (Courier Rokalai)
(25591, 7778, 45745), -- 159421 (Cassius)
(25955, 41160, 45745), -- 168427 (Artemede)
(26145, 41506, 45745), -- 168485 (Apolon)
(26091, 41439, 45745), -- 171816 (Paolone)
(26122, 41481, 45745), -- 168430 (Dactylis)
(25654, 40493, 45745), -- 167745 (Haephus)
(26924, 42877, 45745), -- 168517 (Kalisthene)
(26775, 42569, 45745); -- 176100 (Iona Skyblade)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=5 AND `MenuID` IN (26091,26145)) OR (`OptionID`=0 AND `MenuID` IN (10434,25654,26091,27404,25591,26122,26145,26775,24215,25652)) OR (`OptionID`=3 AND `MenuID` IN (26091,26145)) OR (`OptionID`=9 AND `MenuID`=26145) OR (`OptionID`=8 AND `MenuID` IN (26132,26145)) OR (`OptionID`=1 AND `MenuID` IN (25955,10637,26145,26091,16820)) OR (`OptionID`=2 AND `MenuID` IN (27404,26091,26145)) OR (`OptionID`=4 AND `MenuID` IN (26091,26145)) OR (`OptionID`=6 AND `MenuID`=26145);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(26091, 5, 0, 'Ring of Warding', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(10434, 0, 2, 'Show me where I can fly.', 12271, 8192, 0, 0, 0, 0, 0, NULL, 0, 45745), -- OptionBroadcastTextID: 12271 - 140511 - 158191
(25654, 0, 32, 'Show me the Sanctum.', 0, 2199023255552, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26091, 0, 0, 'Herald\'s Footpads', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26091, 3, 0, 'Vial of Lichfrost', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26145, 9, 0, 'What should I do next?', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26145, 5, 0, 'What is equipment?', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(27404, 0, 0, 'The cycle led me down a different path, but yes, please allow me to commit to your covenant once again.', 0, 1, 0, 0, 0, 0, 0, 'This path will lead to you leaving your current covenant. \n\nAre you sure?', 0, 45745),
(26132, 8, 0, 'I wish to rejoin the Night Fae.', 0, 1, 0, 27404, 0, 0, 0, NULL, 0, 45745),
(25955, 1, 0, 'We are ready to challenge the Path of Ascension.', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25591, 0, 2, 'Show me where I can fly.', 12271, 8192, 0, 0, 0, 0, 0, NULL, 0, 45745), -- OptionBroadcastTextID: 12271 - 140511 - 158191
(26122, 0, 29, 'I\'d like to do some crafting.', 0, 274877906944, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26145, 8, 0, 'What do I do if I\'m struggling against a memory?', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26145, 0, 0, 'How do I capture new memories?', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26775, 0, 45, 'What is my Renown with the Kyrian?', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(10637, 1, 2, 'Show me where I can fly.', 12271, 8192, 0, 0, 0, 0, 0, NULL, 0, 45745), -- OptionBroadcastTextID: 12271 - 140511 - 158191
(27404, 2, 41, 'Remind me of the Night Fae', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26145, 1, 0, 'How do I fight higher difficulty memories?', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26145, 3, 0, 'I am having trouble finding materials.', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(24215, 0, 2, 'Show me where I can fly.', 12271, 8192, 0, 0, 0, 0, 0, NULL, 0, 45745), -- OptionBroadcastTextID: 12271 - 140511 - 158191
(26091, 2, 0, 'Spiritforged Aegis', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26091, 4, 0, 'Phial of Serenity', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26145, 6, 0, 'What are charms?', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26091, 1, 0, 'Deep Echo Trident', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26145, 4, 0, 'Where can I find new blueprints?', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25652, 0, 2, 'Show me where I can fly.', 12271, 8192, 0, 0, 0, 0, 0, NULL, 0, 45745), -- OptionBroadcastTextID: 12271 - 140511 - 158191
(26145, 2, 0, 'What are Medallions of Service, and where can I get them?', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(16820, 1, 2, 'Show me where I can fly.', 12271, 8192, 0, 0, 0, 0, 0, NULL, 0, 45745); -- OptionBroadcastTextID: 12271 - 140511 - 158191

UPDATE `gossip_menu_option` SET `OptionNpcFlag`=128, `VerifiedBuild`=45745 WHERE (`MenuID`=9868 AND `OptionID`=1); -- OptionBroadcastTextID: 2823 - 7509 - 8097

UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=45745 WHERE `entry`=131123; -- Enchanted Tiki Mask
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=45745 WHERE `entry`=122968; -- Yazma
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=45745 WHERE `entry`=111290; -- Braxas the Fleshcarver

DELETE FROM `gameobject_template` WHERE `entry` IN (334231 /*Wrathion's Recorded Journal*/, 238827 /*Stool*/, 238821 /*Stool*/, 238822 /*Stool*/, 238819 /*Stool*/, 238823 /*Stool*/, 238820 /*Stool*/, 238828 /*Stool*/, 235325 /*Hooked Dagger*/, 236722 /*Statue Base*/, 230479 /*Garrison Building Horde Sparring Arena V3*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(334231, 9, 9806, 'Wrathion\'s Recorded Journal', '', '', '', 1, 8032, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Wrathion's Recorded Journal
(238827, 7, 16151, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Stool
(238821, 7, 16151, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Stool
(238822, 7, 16151, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Stool
(238819, 7, 16151, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Stool
(238823, 7, 16151, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Stool
(238820, 7, 16151, 'Stool', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Stool
(238828, 7, 16151, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Stool
(235325, 10, 20413, 'Hooked Dagger', 'questinteract', 'Placing', '', 0.660000026226043701, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 816, 45745), -- Hooked Dagger
(236722, 5, 19151, 'Statue Base', '', '', '', 0.5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Statue Base
(230479, 38, 18579, 'Garrison Building Horde Sparring Arena V3', '', '', '', 1, 1410, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745); -- Garrison Building Horde Sparring Arena V3

UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=45745 WHERE `entry`=247615; -- Crown of Mavrana Mooncrest
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=45745 WHERE `entry`=247614; -- Crown Pillar
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry` IN (260268, 260263); -- Portal to Shal'Aran
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=253393; -- Telemancy Beacon
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=253134; -- Teleporter
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=45745 WHERE `entry`=246492; -- Runescale Koi School
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=257974; -- Wine Bottle
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=257973; -- Fruit Basket
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=257972; -- Lantern
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=257971; -- Dusk Lily
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=257970; -- Nightborne Planter
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry`=253144; -- Teleportation Nexus
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=247023; -- Shadowbloom
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=246731; -- Elven Waypost
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45745 WHERE `entry`=246568; -- Felsoul Cage
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=45745 WHERE `entry`=242411; -- Lyrelle's Summoning Stone
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=266106; -- Legion Portal
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=252107; -- Unpowered Telemancy Beacon
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=45745 WHERE `entry`=280900; -- All
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=45745 WHERE `entry`=280899; -- Yellow
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=45745 WHERE `entry`=280898; -- Green
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=45745 WHERE `entry`=280897; -- Blue
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=45745 WHERE `entry`=280896; -- Red
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=45745 WHERE `entry`=280902; -- All (Always Curtain)
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=45745 WHERE `entry`=280901; -- All (Always Collision)
UPDATE `gameobject_template` SET `ContentTuningId`=54, `VerifiedBuild`=45745 WHERE `entry`=205360; -- Portal to Temple of Earth
UPDATE `gameobject_template` SET `Data0`=2858, `Data4`=50, `Data5`=75, `Data6`=30, `Data12`=679, `ContentTuningId`=679, `VerifiedBuild`=45745 WHERE `entry`=202750; -- Heartblossom
UPDATE `gameobject_template` SET `ContentTuningId`=54, `VerifiedBuild`=45745 WHERE `entry`=205272; -- Portal to Stormwind
UPDATE `gameobject_template` SET `ContentTuningId`=54, `VerifiedBuild`=45745 WHERE `entry`=204407; -- Incense Burner
UPDATE `gameobject_template` SET `ContentTuningId`=54, `VerifiedBuild`=45745 WHERE `entry`=205359; -- Portal to Therazane's Throne
UPDATE `gameobject_template` SET `ContentTuningId`=54, `VerifiedBuild`=45745 WHERE `entry`=205273; -- Portal to Orgrimmar
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=21870, `ContentTuningId`=39, `VerifiedBuild`=45745 WHERE `entry`=185224; -- Cabal Chest
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45745 WHERE `entry`=252783; -- Arcway Outlet
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45745 WHERE `entry`=266301; -- Shal'dorei Foodstuff
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45745 WHERE `entry`=266298; -- Magically Purified Water
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=251493; -- Shadefruit
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=251494; -- Silver Jasmine
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=251492; -- Purified Water
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=251475; -- Manafruit Extractor
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=252880; -- Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=45745 WHERE `entry`=242412; -- Ondri's Summoning Stone
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=266171; -- Fel Rune
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=266779; -- Bookshelf
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry` IN (266774, 266793); -- Table
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=266784; -- Crate
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=252774; -- Ancient Mana Crystal
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45745 WHERE `entry`=267065; -- Nightborne Cage
UPDATE `gameobject_template` SET `ContentTuningId`=344, `VerifiedBuild`=45745 WHERE `entry`=267261; -- Spell Focus
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=251507; -- Unctuous Draught
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=251506; -- Supple Nectar
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=251499; -- Honeyed Infusion
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=254069; -- Spilled Arcwine
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45745 WHERE `entry`=251626; -- Thousand-Year Arcwine
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=254067; -- Arcwine Barrel
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=257291; -- Nightborne Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry` IN (257547, 257548, 252474, 252473, 252476, 252477, 252475, 252512, 252511, 252510, 252490, 252489); -- Window
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=266585; -- Shattered Teleporter Pad
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=265509; -- Broken Telemancy Beacon
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45745 WHERE `entry`=260492; -- Glowing Tome
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=45745 WHERE `entry`=271111; -- Drum
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=45745 WHERE `entry`=280526; -- Goblin Drum
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=45745 WHERE `entry`=288596; -- Cache of Secrets
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=45745 WHERE `entry`=233617; -- Portal to Gorgrond
UPDATE `gameobject_template` SET `ContentTuningId`=816, `VerifiedBuild`=45745 WHERE `entry`=235332; -- Gronn-Tooth Necklace
UPDATE `gameobject_template` SET `Data19`=0, `VerifiedBuild`=45745 WHERE `entry`=235390; -- Nagrand Arrowbloom
UPDATE `gameobject_template` SET `ContentTuningId`=302, `VerifiedBuild`=45745 WHERE `entry`=242958; -- Jewelcrafting Hut Focus
UPDATE `gameobject_template` SET `ContentTuningId`=302, `VerifiedBuild`=45745 WHERE `entry`=237069; -- Jewelcrafting Work Order
UPDATE `gameobject_template` SET `ContentTuningId`=46, `VerifiedBuild`=45745 WHERE `entry`=188424; -- Letter from Saurfang
UPDATE `gameobject_template` SET `ContentTuningId`=46, `VerifiedBuild`=45745 WHERE `entry`=188423; -- Burning Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=46, `VerifiedBuild`=45745 WHERE `entry`=188418; -- Wanted!
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=45745 WHERE `entry`=184999; -- Auchenai Coffin
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=45745 WHERE `entry`=184807; -- Ethereal Particles
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=45745 WHERE `entry`=182585; -- Restless Bones
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=19413, `ContentTuningId`=39, `VerifiedBuild`=45745 WHERE `entry`=182584; -- Restless Bones
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=45745 WHERE `entry`=184743; -- Consuming Flames
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=45745 WHERE `entry`=266104; -- Lunelli's Earth Totem
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=45745 WHERE `entry`=280814; -- Pyramid
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=45745 WHERE `entry`=280813; -- Fish
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=45745 WHERE `entry`=280812; -- Feather
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=45745 WHERE `entry`=266105; -- Lunelli's Air Totem
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=45745 WHERE `entry`=280815; -- Letter from Ms. Graham
UPDATE `gameobject_template` SET `ContentTuningId`=203, `VerifiedBuild`=45745 WHERE `entry`=179512; -- Fixed Trap
UPDATE `gameobject_template` SET `Data0`=1634, `Data1`=0, `Data15`=0, `Data20`=44, `Data25`=368, `Data30`=96902, `ContentTuningId`=278, `VerifiedBuild`=45745 WHERE `entry`=179564; -- Gordok Tribute
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45745 WHERE `entry`=248958; -- Compendium of Ancient Weapons Volume VII
UPDATE `gameobject_template` SET `ContentTuningId`=203, `VerifiedBuild`=45745 WHERE `entry`=179517; -- Treasure of the Shen'dralar
UPDATE `gameobject_template` SET `ContentTuningId`=203, `VerifiedBuild`=45745 WHERE `entry`=153464; -- Large Solid Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=16518, `ContentTuningId`=203, `VerifiedBuild`=45745 WHERE `entry`=179499; -- Ogre Tannin Basket
UPDATE `gameobject_template` SET `name`='Skeletal Remains of Telmius Dreamseeker', `ContentTuningId`=203, `VerifiedBuild`=45745 WHERE `entry`=179544; -- Skeletal Remains of Kariel Winthalus
UPDATE `gameobject_template` SET `ContentTuningId`=203, `VerifiedBuild`=45745 WHERE `entry`=179485; -- Broken Trap
UPDATE `gameobject_template` SET `ContentTuningId`=203, `VerifiedBuild`=45745 WHERE `entry` IN (179532, 179533, 179526); -- Warpwood Pod
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=203, `VerifiedBuild`=45745 WHERE `entry`=179516; -- Fengus's Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=16548, `ContentTuningId`=203, `VerifiedBuild`=45745 WHERE `entry`=179528; -- Warpwood Pod
UPDATE `gameobject_template` SET `Data1`=0, `Data18`=683, `Data30`=39337, `ContentTuningId`=22, `VerifiedBuild`=45745 WHERE `entry`=207535; -- Runestone Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28573, `ContentTuningId`=22, `VerifiedBuild`=45745 WHERE `entry`=202793; -- Loose Soil
UPDATE `gameobject_template` SET `ContentTuningId`=467, `VerifiedBuild`=45745 WHERE `entry`=297826; -- Wicker Totem
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45745 WHERE `entry`=276255; -- Is it a Rock? How to Identify Relics
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45745 WHERE `entry`=276254; -- Beginner's Guide to Archaeology
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45745 WHERE `entry`=276258; -- "Genuine Titan Disc"
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45745 WHERE `entry`=276257; -- "Ancient Potsherds"
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45745 WHERE `entry`=276253; -- Half-eaten Journal
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45745 WHERE `entry`=277273; -- Suspiciously Protruding Book
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=187, `VerifiedBuild`=45745 WHERE `entry`=297892; -- Runebound Chest
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45745 WHERE `entry`=276874; -- Bucket of Grain
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45745 WHERE `entry`=276873; -- Hardened Lockbox
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45745 WHERE `entry`=284422; -- Crate of Azerite
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45745 WHERE `entry`=288214; -- Wanted Poster
UPDATE `gameobject_template` SET `ContentTuningId`=708, `VerifiedBuild`=45745 WHERE `entry`=279647; -- Tome of Sacrifice
UPDATE `gameobject_template` SET `ContentTuningId`=292, `VerifiedBuild`=45745 WHERE `entry`=278401; -- Sand Shifter School
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=45745 WHERE `entry`=326133; -- Cook Pot
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=45745 WHERE `entry`=324028; -- Elven Cookpot
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=1743, `ContentTuningId`=20, `VerifiedBuild`=45745 WHERE `entry`=2068; -- Pupellyverbos Port
UPDATE `gameobject_template` SET `ContentTuningId`=20, `VerifiedBuild`=45745 WHERE `entry`=179908; -- Slagtree's Lost Tools
UPDATE `gameobject_template` SET `Data1`=0, `Data15`=0, `Data30`=17532, `ContentTuningId`=1006, `VerifiedBuild`=45745 WHERE `entry`=180691; -- Scarab Coffer
UPDATE `gameobject_template` SET `ContentTuningId`=183, `VerifiedBuild`=45745 WHERE `entry`=268414; -- Alliance Banner
UPDATE `gameobject_template` SET `ContentTuningId`=36, `VerifiedBuild`=45745 WHERE `entry`=179565; -- Dusty Reliquary
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=15521, `ContentTuningId`=36, `VerifiedBuild`=45745 WHERE `entry`=178553; -- Hive'Ashi Pod
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39339, `ContentTuningId`=32, `VerifiedBuild`=45745 WHERE `entry`=207513; -- Silken Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=71, `VerifiedBuild`=45745 WHERE `entry`=2909; -- Wildmane Water Pump


DELETE FROM `gameobject_template` WHERE `entry` IN (364437 /*Chair*/, 364435 /*Chair*/, 364434 /*Chair*/, 364433 /*Chair*/, 364432 /*Chair*/, 364431 /*Chair*/, 364430 /*Chair*/, 364428 /*Chair*/, 364426 /*Chair*/, 364429 /*Chair*/, 251048 /*Matrix Punchograph 3005-E*/, 251015 /*Encrypted Door*/, 311580 /*Gnomish Mayhem Detector*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(364437, 7, 62460, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(364435, 7, 15617, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(364434, 7, 15618, 'Chair', '', '', '', 1.509765505790710449, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(364433, 7, 15617, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(364432, 7, 15617, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(364431, 7, 15617, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(364430, 7, 15617, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(364428, 7, 15617, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(364426, 7, 15617, 'Chair', '', '', '', 0.999999821186065673, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(364429, 7, 32290, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(251048, 2, 2091, 'Matrix Punchograph 3005-E', '', '', '', 1, 93, 0, 0, 19818, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1372, 45745), -- Matrix Punchograph 3005-E
(251015, 0, 10398, 'Encrypted Door', '', '', '', 1.85000002384185791, 0, 0, 0, 0, 0, 0, 0, 21439, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1372, 45745), -- Encrypted Door
(311580, 5, 52061, 'Gnomish Mayhem Detector', '', '', '', 0.200000002980232238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745); -- Gnomish Mayhem Detector

UPDATE `gameobject_template` SET `ContentTuningId`=60, `VerifiedBuild`=45745 WHERE `entry`=211171; -- Anvil
UPDATE `gameobject_template` SET `ContentTuningId`=60, `VerifiedBuild`=45745 WHERE `entry`=211170; -- Forge
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=40379, `ContentTuningId`=80, `VerifiedBuild`=45745 WHERE `entry`=209507; -- Hard Tearwood Reed
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=40266, `ContentTuningId`=80, `VerifiedBuild`=45745 WHERE `entry`=209326; -- Loose Dogwood Root
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=40266, `ContentTuningId`=80, `VerifiedBuild`=45745 WHERE `entry`=209327; -- Loose Dogwood Root
UPDATE `gameobject_template` SET `ContentTuningId`=80, `VerifiedBuild`=45745 WHERE `entry`=210986; -- Edict of Temperance
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=45745 WHERE `entry`=210005; -- Weapon Rack
UPDATE `gameobject_template` SET `Data5`=0, `ContentTuningId`=482, `VerifiedBuild`=45745 WHERE `entry`=183384; -- Portal to Shattrath
UPDATE `gameobject_template` SET `ContentTuningId`=196, `VerifiedBuild`=45745 WHERE `entry`=192886; -- In Time, the Arcane Corrupts All!
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25391, `ContentTuningId`=48, `VerifiedBuild`=45745 WHERE `entry`=191781; -- Scourge Scrap Metal
UPDATE `gameobject_template` SET `ContentTuningId`=48, `VerifiedBuild`=45745 WHERE `entry`=190535; -- Zim'Abwa
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=24369, `ContentTuningId`=48, `VerifiedBuild`=45745 WHERE `entry`=190534; -- Mature Water-Poppy
UPDATE `gameobject_template` SET `ContentTuningId`=48, `VerifiedBuild`=45745 WHERE `entry`=190550; -- Ancient Dirt Mound
UPDATE `gameobject_template` SET `ContentTuningId`=48, `VerifiedBuild`=45745 WHERE `entry`=190522; -- Drakkari Pedestal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=23388, `ContentTuningId`=47, `VerifiedBuild`=45745 WHERE `entry`=188263; -- Missing Journal Page
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=23388, `ContentTuningId`=47, `VerifiedBuild`=45745 WHERE `entry`=188262; -- Missing Journal Page
UPDATE `gameobject_template` SET `ContentTuningId`=47, `VerifiedBuild`=45745 WHERE `entry`=188261; -- Battered Journal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=24160, `ContentTuningId`=47, `VerifiedBuild`=45745 WHERE `entry`=189983; -- Wild Carrot
UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=45745 WHERE `entry`=248057; -- Bear Totem
UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=45745 WHERE `entry`=248779; -- PLACEHOLDER Tree
UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=45745 WHERE `entry`=248778; -- Dreamway Portal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39342, `ContentTuningId`=47, `VerifiedBuild`=45745 WHERE `entry`=207540; -- Runestone Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=48, `VerifiedBuild`=45745 WHERE `entry`=191766; -- Orders From Drakuru
UPDATE `gameobject_template` SET `ContentTuningId`=48, `VerifiedBuild`=45745 WHERE `entry`=191728; -- Wanted!
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25912, `ContentTuningId`=163, `VerifiedBuild`=45745 WHERE `entry`=192909; -- Ancient Elven Masonry
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25912, `ContentTuningId`=163, `VerifiedBuild`=45745 WHERE `entry`=192910; -- Ancient Elven Masonry
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25912, `ContentTuningId`=163, `VerifiedBuild`=45745 WHERE `entry`=192912; -- Ancient Elven Masonry
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25912, `ContentTuningId`=163, `VerifiedBuild`=45745 WHERE `entry`=192911; -- Ancient Elven Masonry
UPDATE `gameobject_template` SET `ContentTuningId`=676, `VerifiedBuild`=45745 WHERE `entry`=181570; -- Rich Adamantite Deposit
UPDATE `gameobject_template` SET `ContentTuningId`=10, `VerifiedBuild`=45745 WHERE `entry`=60; -- Wanted: Gath'Ilzogg
UPDATE `gameobject_template` SET `ContentTuningId`=691, `VerifiedBuild`=45745 WHERE `entry`=312345; -- Official-Looking Note
UPDATE `gameobject_template` SET `ContentTuningId`=10, `VerifiedBuild`=45745 WHERE `entry`=1726; -- Missing!
UPDATE `gameobject_template` SET `ContentTuningId`=10, `VerifiedBuild`=45745 WHERE `entry`=47; -- Wanted!
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=9999, `ContentTuningId`=10, `VerifiedBuild`=45745 WHERE `entry`=154357; -- Glinting Mud
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=14105, `ContentTuningId`=73, `VerifiedBuild`=45745 WHERE `entry`=176793; -- Bundle of Wood
UPDATE `gameobject_template` SET `ContentTuningId`=73, `VerifiedBuild`=45745 WHERE `entry`=56; -- Rolf's corpse
UPDATE `gameobject_template` SET `ContentTuningId`=73, `VerifiedBuild`=45745 WHERE `entry`=20923; -- Stone of Remembrance
UPDATE `gameobject_template` SET `ContentTuningId`=204, `VerifiedBuild`=45745 WHERE `entry`=142476; -- Matrix Punchograph 3005-C
UPDATE `gameobject_template` SET `ContentTuningId`=204, `VerifiedBuild`=45745 WHERE `entry` IN (175084, 175085, 142487); -- The Sparklematic 5200
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=45745 WHERE `entry`=142207; -- The Final Chamber
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=45745 WHERE `entry`=146086; -- Cave In
UPDATE `gameobject_template` SET `ContentTuningId`=204, `VerifiedBuild`=45745 WHERE `entry`=142475; -- Matrix Punchograph 3005-B
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=6799, `ContentTuningId`=204, `VerifiedBuild`=45745 WHERE `entry`=142344; -- Artificial Extrapolator
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=2955, `ContentTuningId`=683, `VerifiedBuild`=45745 WHERE `entry`=19020; -- Box of Assorted Parts
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=45745 WHERE `entry`=146085; -- Cave In
UPDATE `gameobject_template` SET `ContentTuningId`=204, `VerifiedBuild`=45745 WHERE `entry`=208325; -- Extra Parachutes
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=45745 WHERE `entry`=90858; -- Workshop Door
UPDATE `gameobject_template` SET `ContentTuningId`=204, `VerifiedBuild`=45745 WHERE `entry`=179555; -- Meeting Stone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30020, `ContentTuningId`=74, `VerifiedBuild`=45745 WHERE `entry`=203968; -- Spare Part
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30020, `ContentTuningId`=74, `VerifiedBuild`=45745 WHERE `entry`=203966; -- Spare Part
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30020, `ContentTuningId`=74, `VerifiedBuild`=45745 WHERE `entry`=203965; -- Spare Part 
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30020, `ContentTuningId`=74, `VerifiedBuild`=45745 WHERE `entry`=203964; -- Spare Part
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=30020, `ContentTuningId`=74, `VerifiedBuild`=45745 WHERE `entry`=203967; -- Spare Part
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=797, `ContentTuningId`=74, `VerifiedBuild`=45745 WHERE `entry`=276; -- Shimmerweed Basket
UPDATE `gameobject_template` SET `ContentTuningId`=868, `VerifiedBuild`=45745 WHERE `entry`=207320; -- Hero's Call Board
UPDATE `gameobject_template` SET `ContentTuningId`=868, `VerifiedBuild`=45745 WHERE `entry`=139852; -- Memorial to Sully Balloo

DELETE FROM `gameobject_template` WHERE `entry` IN (239923 /*Gronnsbane's Haft*/, 230580 /*Bone Pile*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(239923, 3, 25214, 'Gronnsbane\'s Haft', 'questinteract', 'Collecting', '', 0.400000005960464477, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 81040, 0, 0, 0, 59766, 0, 0, 0, 0, 64, 45745), -- Gronnsbane's Haft
(230580, 9, 7418, 'Bone Pile', 'inspect', '', '', 1, 4915, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 45745); -- Bone Pile

UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39336, `ContentTuningId`=13, `VerifiedBuild`=45745 WHERE `entry`=207474; -- Silverbound Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=45745 WHERE `entry`=203431; -- Northwatch Tent
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29681, `ContentTuningId`=14, `VerifiedBuild`=45745 WHERE `entry`=203443; -- Spare Part
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=45745 WHERE `entry`=203239; -- Support Beam Marker
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39336, `ContentTuningId`=14, `VerifiedBuild`=45745 WHERE `entry`=207522; -- Maplewood Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=683, `VerifiedBuild`=45745 WHERE `entry`=3730; -- Bruiseweed
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=3092, `ContentTuningId`=14, `VerifiedBuild`=45745 WHERE `entry`=19603; -- Venture Co. Documents
UPDATE `gameobject_template` SET `ContentTuningId`=64, `VerifiedBuild`=45745 WHERE `entry` IN (237298, 237299); -- Pillaged Caravan Goods
UPDATE `gameobject_template` SET `ContentTuningId`=64, `VerifiedBuild`=45745 WHERE `entry` IN (230582, 230581); -- Goren Tracks
UPDATE `gameobject_template` SET `ContentTuningId`=64, `VerifiedBuild`=45745 WHERE `entry`=229050; -- Goren Egg
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=45745 WHERE `entry`=326737; -- Arcane Device
UPDATE `gameobject_template` SET `ContentTuningId`=708, `VerifiedBuild`=45745 WHERE `entry`=328391; -- Spell Focus - Empowered Abyssal Focus
UPDATE `gameobject_template` SET `ContentTuningId`=708, `VerifiedBuild`=45745 WHERE `entry`=327595; -- Radiating Abyssal Focus
UPDATE `gameobject_template` SET `ContentTuningId`=708, `VerifiedBuild`=45745 WHERE `entry`=327593; -- Spell Focus - Restored Abyssal Focus
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=45745 WHERE `entry`=356823; -- Cloudwalker's Coffer

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=239923 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(239923, 0, 122098, 45745); -- Gronnsbane's Haft
