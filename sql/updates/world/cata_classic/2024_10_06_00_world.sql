-- wotlk classic titan rune protocol spawns and data
SET @NPCTEXTID := 520000; -- wotlk npc text range
SET @OGUID := 2990000; -- wotlk event gameobject range
SET @CGUID := 2990000; -- wotlk event creature range

-- Dalaran Vendors
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 207128, 571, 4395, 4395, '0', 169, 0, 0, 0, 5749.73095703125, 736.67364501953125, 655.68878173828125, 0.789474904537200927, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Animated Constellation (Area: Dalaran - Difficulty: 0) CreateObject1
(@CGUID+1, 207128, 571, 4395, 4564, '0', 169, 0, 0, 0, 5932.2099609375, 500.923614501953125, 651.8404541015625, 1.684129834175109863, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Animated Constellation (Area: Krasus' Landing - Difficulty: 0) CreateObject1
(@CGUID+2, 211340, 571, 4395, 4564, '0', 169, 0, 0, 0, 5926.26123046875, 508.26910400390625, 650.26641845703125, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Kolara Dreamsmasher (Area: Krasus' Landing - Difficulty: 0) CreateObject1
(@CGUID+3, 211332, 571, 4395, 4395, '0', 169, 0, 0, 0, 5756.11474609375, 745.40625, 653.747802734375, 4.595656871795654296, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713); -- Korralin Hoperender (Area: Dalaran - Difficulty: 0) CreateObject1

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+13;
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+13;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 382526, 601, 4277, 4405, '2', 169, 0, 444.0538330078125, 791.0711669921875, 830.73992919921875, 4.176662445068359375, 0, 0, -0.86904144287109375, 0.494739264249801635, 7200, 255, 1, 56713), -- Mysterious Device (Area: Passage of Lost Fiends - Difficulty: 2) CreateObject2
(@OGUID+1, 382526, 619, 4494, 4623, '2', 169, 0, 377.935760498046875, -1081.21875, 48.67596817016601562, 3.692834377288818359, 0, 0, -0.96225643157958984, 0.272144407033920288, 7200, 255, 1, 56713), -- Mysterious Device (Area: Hall of the Conquered Kings - Difficulty: 2) CreateObject2
(@OGUID+2, 382526, 599, 4264, 4264, '2', 169, 0, 1159.017333984375, 802.71527099609375, 197.4412078857421875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56713), -- Mysterious Device (Area: Halls of Stone - Difficulty: 2) CreateObject2
(@OGUID+3, 382526, 602, 4272, 4272, '2', 169, 0, 1341.486083984375, 238.0885467529296875, 53.994049072265625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56713), -- Mysterious Device (Area: Halls of Lightning - Difficulty: 2) CreateObject2
(@OGUID+4, 382526, 604, 4416, 4416, '2', 169, 0, 1861.578125, 631.0625, 177.8182830810546875, 0, 0, 0, 0, 1, 7200, 255, 1, 56713), -- Mysterious Device (Area: Gundrak - Difficulty: 2) CreateObject2
(@OGUID+5, 382526, 604, 4416, 4416, '2', 169, 0, 1859.03125, 853.451416015625, 178.0142364501953125, 0, 0, 0, 0, 1, 7200, 255, 1, 56713), -- Mysterious Device (Area: Gundrak - Difficulty: 2) CreateObject1
(@OGUID+6, 382526, 600, 4196, 4196, '2', 169, 0, -503.046875, -513.01043701171875, 11.8472909927368164, 2.507583379745483398, 0, 0, 0.950173377990722656, 0.311721891164779663, 7200, 255, 1, 56713), -- Mysterious Device (Area: Drak'Tharon Keep - Difficulty: 2) CreateObject2
(@OGUID+7, 382526, 575, 1196, 1196, '2', 169, 0, 572.2117919921875, -336.211822509765625, 110.1451187133789062, 1.507198929786682128, 0, 0, 0.684267997741699218, 0.72923058271408081, 7200, 255, 1, 56713), -- Mysterious Device (Area: Utgarde Pinnacle - Difficulty: 2) CreateObject2
(@OGUID+8, 382526, 574, 206, 206, '2', 169, 0, 166.3402862548828125, -96.984375, 14.26257705688476562, 1.842780113220214843, 0, 0, 0.796442985534667968, 0.604713618755340576, 7200, 255, 1, 56713), -- Mysterious Device (Area: Utgarde Keep - Difficulty: 2) CreateObject2
(@OGUID+9, 382526, 650, 4723, 4723, '2', 169, 0, 798.81597900390625, 605.951416015625, 412.371002197265625, 2.92466282844543457, 0, 0, 0.994123458862304687, 0.108252346515655517, 7200, 255, 1, 56713), -- Mysterious Device (Area: Trial of the Champion - Difficulty: 2) CreateObject2
(@OGUID+10, 382526, 578, 4228, 4228, '2', 169, 0, 1058.7222900390625, 989.71527099609375, 362.743988037109375, 3.799419164657592773, 0, 0, -0.94639396667480468, 0.323014646768569946, 7200, 255, 1, 56713), -- Mysterious Device (Area: The Oculus - Difficulty: 2) CreateObject2
(@OGUID+11, 382526, 576, 4265, 4265, '2', 169, 0, 144.303985595703125, -3.4262251853942871, -15.7468805313110351, 5.597727298736572265, 0, 0, -0.33605861663818359, 0.941841065883636474, 7200, 255, 1, 56713), -- Mysterious Device (Area: The Nexus - Difficulty: 2) CreateObject2
(@OGUID+12, 382526, 608, 4415, 4415, '2', 169, 0, 1838.2586669921875, 813.09893798828125, 45.20830154418945312, 4.74647378921508789, 0, 0, -0.69495391845703125, 0.719054281711578369, 7200, 255, 1, 56713), -- Mysterious Device (Area: The Violet Hold - Difficulty: 2) CreateObject2
(@OGUID+13, 382526, 595, 4100, 4100, '2', 169, 0, 2089.98779296875, 1303.6336669921875, 141.19140625, 4.544805526733398437, 0, 0, -0.76380634307861328, 0.645445466041564941, 7200, 255, 1, 56713); -- Mysterious Device (Area: The Culling of Stratholme - Difficulty: 2) CreateObject1

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 233139, 0, 0, 0, 0, 0, 0, 0, 56713), -- 382526 (Mysterious Device)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 249450, 0, 0, 0, 0, 0, 0, 0, 56713); -- 211297 (Silver Covenant Warden)

DELETE FROM `gossip_menu` WHERE `MenuID` IN (30239, 32742);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(30239, @NPCTEXTID+0, 56713), -- 382526 (Mysterious Device)
(32742, @NPCTEXTID+1, 56713); -- 211297 (Silver Covenant Warden)

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (30239, 32742);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(30239, 109827, 1, 0, 'Activate Defense Protocol Beta.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 412399, NULL, 56713),
(30239, 113944, 2, 0, 'Activate Defense Protocol Gamma.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 424186, NULL, 56713),
(30239, 107730, 0, 0, 'Activate Defense Protocol Alpha.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 396441, NULL, 56713),
(32742, 113969, 0, 0, 'Shatter your opponents\' armor with your melee attacks', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 424400, NULL, 56713),
(32742, 113967, 2, 0, 'Accumulate wrath from your healing actions and turn it against your foes', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 424405, NULL, 56713),
(32742, 113968, 1, 0, 'Rally your allies to quicken their actions from your ranged and spell critical strikes', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 424403, NULL, 56713),
(32742, 113966, 3, 0, 'Shield yourself in thorns that injure enemies when you block, dodge, or parry', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 424407, NULL, 56713);

DELETE FROM `creature_equip_template` WHERE `CreatureID`= 211297;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(211297, 1, 34877, 0, 0, 0, 0, 0, 34281, 0, 0, 56713); -- Silver Covenant Warden

DELETE FROM `creature_template` WHERE `entry` IN (196957 /*-Unknown-*/, 198016 /*-Unknown-*/);
INSERT INTO `creature_template` (`entry`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `BaseAttackTime`, `RangeAttackTime`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VehicleId`) VALUES
(196957, 35, 0, 1, 1.142857193946838378, 2000, 2000, 33554944, 2048, 0, 0), -- -Unknown-
(198016, 94, 0, 1, 1.142857193946838378, 2000, 2000, 33554432, 2048, 0, 0); -- -Unknown-

-- 'leaked' name based on chat message packets
UPDATE `creature_template` SET `name`= '[DNT] Heroic+ Dungeon Difficulty Bunny' WHERE `entry`= 198016;
UPDATE `creature_template` SET `faction`=2123, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=211340; -- Kolara Dreamsmasher
UPDATE `creature_template` SET `faction`=2027, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=211332; -- Korralin Hoperender
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=207128; -- Animated Constellation

DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (198016, 196957);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `MinLevel`, `MaxLevel`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(198016, 0, 60, 60, 536871168, 0, 0, 0, 0, 0, 0, 0, 56713), -- 198016 - Sessile, Floating
(196957, 0, 60, 60, 536871168, 0, 0, 0, 0, 0, 0, 0, 56713); -- 196957 - Sessile, Floating

UPDATE `creature_template_difficulty` SET `MinLevel`=80, `MaxLevel`=80, `VerifiedBuild`=56713 WHERE `Entry`=211340; -- 211340 (Kolara Dreamsmasher) - 
UPDATE `creature_template_difficulty` SET `MinLevel`=80, `MaxLevel`=80, `VerifiedBuild`=56713 WHERE `Entry`=211332; -- 211332 (Korralin Hoperender) - 
UPDATE `creature_template_difficulty` SET `MinLevel`=83, `MaxLevel`=83, `StaticFlags1`=536870912, `VerifiedBuild`=56713 WHERE `Entry`=207128; -- 207128 (Animated Constellation) - Floating

DELETE FROM `creature_template_addon` WHERE `entry` IN (211340, 211332, 207128);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(211340, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 211340 (Kolara Dreamsmasher)
(211332, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 211332 (Korralin Hoperender)
(207128, 0, 0, 0, 2, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- 207128 (Animated Constellation)

DELETE FROM `npc_vendor` WHERE `entry` IN (207128, 211332, 211340);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(207128, 61, 46067, 0, 8163, 1, 0, 0, 56713), -- Hammer of Crushing Whispers
(207128, 60, 45886, 0, 8163, 1, 0, 0, 56713), -- Icecore Staff
(207128, 59, 46033, 0, 8163, 1, 0, 0, 56713), -- Tortured Earth
(207128, 58, 45868, 0, 8163, 1, 0, 0, 56713), -- Aesir's Edge
(207128, 57, 45990, 0, 8163, 1, 0, 0, 56713), -- Fusion Blade
(207128, 56, 46035, 0, 8163, 1, 0, 0, 56713), -- Aesuga, Hand of the Ardent Champion
(207128, 55, 45870, 0, 8163, 1, 0, 0, 56713), -- Magnetized Projectile Emitter
(207128, 54, 46049, 0, 8179, 1, 0, 0, 56713), -- Zodiac Leggings
(207128, 53, 46039, 0, 8179, 1, 0, 0, 56713), -- Breastplate of the Timeless
(207128, 52, 45877, 0, 8162, 1, 0, 0, 56713), -- The Boreal Guard
(207128, 51, 45887, 0, 8162, 1, 0, 0, 56713), -- Ice Layered Barrier
(207128, 50, 45449, 0, 8162, 1, 0, 0, 56713), -- The Masticator
(207128, 49, 46097, 0, 8162, 1, 0, 0, 56713), -- Caress of Insanity
(207128, 48, 45930, 0, 8162, 1, 0, 0, 56713), -- Combatant's Bootblade
(207128, 47, 45448, 0, 8162, 1, 0, 0, 56713), -- Perilous Bite
(207128, 46, 45876, 0, 8162, 1, 0, 0, 56713), -- Shiver
(207128, 45, 46036, 0, 8162, 1, 0, 0, 56713), -- Void Sabre
(207128, 44, 45947, 0, 8162, 1, 0, 0, 56713), -- Serilas, Blood Blade of Invar One-Arm
(207128, 43, 45993, 0, 8162, 1, 0, 0, 56713), -- Mimiron's Flight Goggles
(207128, 42, 45982, 0, 8162, 1, 0, 0, 56713), -- Fused Alloy Legplates
(207128, 41, 46034, 0, 8162, 1, 0, 0, 56713), -- Leggings of Profound Darkness
(207128, 40, 45295, 0, 8162, 1, 0, 0, 56713), -- Gilded Steel Legplates
(207128, 39, 45867, 0, 8162, 1, 0, 0, 56713), -- Breastplate of the Stoneshaper
(207128, 38, 46041, 0, 8178, 1, 0, 0, 56713), -- Starfall Girdle
(207128, 37, 46051, 0, 8178, 1, 0, 0, 56713), -- Meteorite Crystal
(207128, 36, 46038, 0, 8178, 1, 0, 0, 56713), -- Dark Matter
(207128, 35, 46044, 0, 8178, 1, 0, 0, 56713), -- Observer's Mantle
(207128, 34, 46037, 0, 8178, 1, 0, 0, 56713), -- Shoulderplates of the Celestial Watch
(207128, 33, 46045, 0, 8178, 1, 0, 0, 56713), -- Pulsar Gloves
(207128, 32, 46043, 0, 8178, 1, 0, 0, 56713), -- Gloves of the Endless Dark
(207128, 31, 46050, 0, 8178, 1, 0, 0, 56713), -- Starlight Treads
(207128, 30, 46048, 0, 8177, 1, 0, 0, 56713), -- Band of Lights
(207128, 29, 46046, 0, 8177, 1, 0, 0, 56713), -- Nebula Band
(207128, 28, 46047, 0, 8177, 1, 0, 0, 56713), -- Pendant of the Somber Witness
(207128, 27, 46040, 0, 8177, 1, 0, 0, 56713), -- Strength of the Heavens
(207128, 26, 46042, 0, 8177, 1, 0, 0, 56713), -- Drape of the Messenger
(207128, 25, 45931, 0, 8160, 1, 0, 0, 56713), -- Mjolnir Runestone
(207128, 24, 45929, 0, 8160, 1, 0, 0, 56713), -- Sif's Remembrance
(207128, 23, 46068, 0, 8160, 1, 0, 0, 56713), -- Amice of Inconceivable Horror
(207128, 22, 45300, 0, 8160, 1, 0, 0, 56713), -- Mantle of Fiery Vengeance
(207128, 21, 45988, 0, 8160, 1, 0, 0, 56713), -- Greaves of the Iron Army
(207128, 20, 45989, 0, 8160, 1, 0, 0, 56713), -- Tempered Mercury Greaves
(207128, 19, 46095, 0, 8160, 1, 0, 0, 56713), -- Soul-Devouring Cinch
(207128, 18, 45455, 0, 8160, 1, 0, 0, 56713), -- Belt of the Crystal Tree
(207128, 17, 45928, 0, 8160, 1, 0, 0, 56713), -- Gauntlets of the Thunder God
(207128, 16, 45943, 0, 8160, 1, 0, 0, 56713), -- Gloves of Whispering Winds
(207128, 15, 45293, 0, 8160, 1, 0, 0, 56713), -- Handguards of Potent Cures
(207128, 14, 45294, 0, 8161, 1, 0, 0, 56713), -- Petrified Ivy Sprig
(207128, 13, 45296, 0, 8161, 1, 0, 0, 56713), -- Twirling Blades
(207128, 12, 45888, 0, 8161, 1, 0, 0, 56713), -- Bitter Cold Armguards
(207128, 11, 45869, 0, 8161, 1, 0, 0, 56713), -- Fluxing Energy Coils
(207128, 10, 46096, 0, 8161, 1, 0, 0, 56713), -- Signet of Soft Lament
(207128, 9, 45456, 0, 8161, 1, 0, 0, 56713), -- Loop of the Agile
(207128, 8, 45946, 0, 8161, 1, 0, 0, 56713), -- Fire Orchid Signet
(207128, 7, 45297, 0, 8161, 1, 0, 0, 56713), -- Shimmering Seal
(207128, 6, 45871, 0, 8161, 1, 0, 0, 56713), -- Seal of Ulduar
(207128, 5, 45933, 0, 8161, 1, 0, 0, 56713), -- Pendant of the Shallow Grave
(207128, 4, 45447, 0, 8161, 1, 0, 0, 56713), -- Watchful Eye of Fate
(207128, 3, 45945, 0, 8161, 1, 0, 0, 56713), -- Seed of Budding Carnage
(207128, 2, 46032, 0, 8161, 1, 0, 0, 56713), -- Drape of the Faceless General
(207128, 1, 47556, 0, 8165, 1, 0, 0, 56713), -- Crusader Orb
(211332, 79, 45486, 0, 8315, 1, 0, 0, 56713), -- Drape of the Sullen Goddess
(211332, 78, 45242, 0, 8315, 1, 0, 0, 56713), -- Drape of Mortal Downfall
(211332, 77, 45461, 0, 8315, 1, 0, 0, 56713), -- Drape of Icy Intent
(211332, 76, 45496, 0, 8315, 1, 0, 0, 56713), -- Titanskin Cloak
(211332, 75, 45535, 0, 8315, 1, 0, 0, 56713), -- Show of Faith
(211332, 74, 45609, 0, 8315, 1, 0, 0, 56713), -- Comet's Trail
(211332, 73, 45518, 0, 8315, 1, 0, 0, 56713), -- Flare of the Heavens
(211332, 72, 45534, 0, 8315, 1, 0, 0, 56713), -- Seal of the Betrayed King
(211332, 71, 45495, 0, 8315, 1, 0, 0, 56713), -- Conductive Seal
(211332, 70, 45471, 0, 8315, 1, 0, 0, 56713), -- Fate's Clutch
(211332, 69, 45133, 0, 8315, 1, 0, 0, 56713), -- Pendant of Fiery Havoc
(211332, 68, 45443, 0, 8315, 1, 0, 0, 56713), -- Charm of Meticulous Timing
(211332, 67, 45459, 0, 8315, 1, 0, 0, 56713), -- Frigid Strength of Hodir
(211332, 66, 45243, 0, 8315, 1, 0, 0, 56713), -- Sapphire Amulet of Renewal
(211332, 65, 45517, 0, 8315, 1, 0, 0, 56713), -- Pendulum of Infinity
(211332, 64, 45485, 0, 8315, 1, 0, 0, 56713), -- Bronze Pendant of the Vanir
(211332, 63, 47115, 0, 8276, 1, 0, 0, 56713), -- Death's Verdict
(211332, 62, 47182, 0, 8276, 1, 0, 0, 56713), -- Reign of the Unliving
(211332, 61, 47069, 0, 8279, 1, 0, 0, 56713), -- Justicebringer
(211332, 60, 47041, 0, 8276, 1, 0, 0, 56713), -- Solace of the Defeated
(211332, 59, 46979, 0, 8278, 1, 0, 0, 56713), -- Blade of Tarasque
(211332, 58, 47148, 0, 8277, 1, 0, 0, 56713), -- Stormpike Cleaver
(211332, 57, 47139, 0, 8275, 1, 0, 0, 56713), -- Wail of the Val'kyr
(211332, 56, 46959, 0, 8275, 1, 0, 0, 56713), -- Band of the Violent Temperment
(211332, 55, 47071, 0, 8276, 1, 0, 0, 56713), -- Treads of the Icewalker
(211332, 54, 47092, 0, 8276, 1, 0, 0, 56713), -- Boots of the Mourning Widow
(211332, 53, 46970, 0, 8275, 1, 0, 0, 56713), -- Drape of the Untamed Predator
(211332, 52, 47080, 0, 8276, 1, 0, 0, 56713), -- Satrina's Impeding Scarab
(211332, 51, 47089, 0, 8275, 1, 0, 0, 56713), -- Cloak of Displacement
(211332, 50, 47223, 0, 8275, 1, 0, 0, 56713), -- Ring of the Darkmender
(211332, 49, 47070, 0, 8275, 1, 0, 0, 56713), -- Ring of Callous Aggression
(211332, 48, 47105, 0, 8275, 1, 0, 0, 56713), -- The Executioner's Malice
(211332, 47, 47043, 0, 8275, 1, 0, 0, 56713), -- Charge of the Demon Lord
(211332, 46, 47053, 0, 8275, 1, 0, 0, 56713), -- Symbol of Transgression
(211332, 45, 46976, 0, 8275, 1, 0, 0, 56713), -- Shawl of the Refreshing Winds
(211332, 44, 47193, 0, 8278, 1, 0, 0, 56713), -- Misery's End
(211332, 43, 47079, 0, 8277, 1, 0, 0, 56713), -- Bastion of Purity
(211332, 42, 47233, 0, 8279, 1, 0, 0, 56713), -- Archon Glaive
(211332, 41, 47150, 0, 8276, 1, 0, 0, 56713), -- Greaves of the 7th Legion
(211332, 40, 46999, 0, 8276, 1, 0, 0, 56713), -- Bloodbath Belt
(211332, 39, 46994, 0, 8279, 1, 0, 0, 56713), -- Talonstrike
(211332, 38, 47042, 0, 8275, 1, 0, 0, 56713), -- Pride of the Eredar
(211332, 37, 47138, 0, 8275, 1, 0, 0, 56713), -- Chalice of Searing Light
(211332, 36, 46958, 0, 8277, 1, 0, 0, 56713), -- Steel Bladebreaker
(211332, 35, 46961, 0, 8275, 1, 0, 0, 56713), -- Boneshatter Armplates
(211332, 34, 47081, 0, 8276, 1, 0, 0, 56713), -- Cord of Biting Cold
(211332, 33, 47104, 0, 8277, 1, 0, 0, 56713), -- Twin Spike
(211332, 32, 47107, 0, 8276, 1, 0, 0, 56713), -- Belt of the Merciless Killer
(211332, 31, 47225, 0, 8275, 1, 0, 0, 56713), -- Maiden's Favor
(211332, 30, 47054, 0, 8275, 1, 0, 0, 56713), -- Band of Deplorable Violence
(211332, 29, 46972, 0, 8276, 1, 0, 0, 56713), -- Cord of the Tenebrous Mist
(211332, 28, 47151, 0, 8275, 1, 0, 0, 56713), -- Bracers of Dark Determination
(211332, 27, 47114, 0, 8279, 1, 0, 0, 56713), -- Lupine Longstaff
(211332, 26, 46997, 0, 8276, 1, 0, 0, 56713), -- Dawnbreaker Greaves
(211332, 25, 47149, 0, 8275, 1, 0, 0, 56713), -- Signet of the Traitor King
(211332, 24, 47116, 0, 8275, 1, 0, 0, 56713), -- The Arbiter's Muse
(211332, 23, 46963, 0, 8277, 1, 0, 0, 56713), -- Crystal Plated Vanguard
(211332, 22, 47072, 0, 8276, 1, 0, 0, 56713), -- Girdle of Bloodied Scars
(211332, 21, 46996, 0, 8277, 1, 0, 0, 56713), -- Lionhead Slasher
(211332, 20, 47152, 0, 8276, 1, 0, 0, 56713), -- Belt of Deathly Dominion
(211332, 19, 47106, 0, 8276, 1, 0, 0, 56713), -- Sabatons of Ruthless Judgment
(211332, 18, 47203, 0, 8275, 1, 0, 0, 56713), -- Armbands of the Ashen Saint
(211332, 17, 47140, 0, 8276, 1, 0, 0, 56713), -- Cord of Pale Thorns
(211332, 16, 47183, 0, 8275, 1, 0, 0, 56713), -- Strength of the Nerub
(211332, 15, 47073, 0, 8275, 1, 0, 0, 56713), -- Bracers of the Untold Massacre
(211332, 14, 47141, 0, 8275, 1, 0, 0, 56713), -- Bindings of Dark Essence
(211332, 13, 47194, 0, 8276, 1, 0, 0, 56713), -- Footpads of the Icy Floe
(211332, 12, 46988, 0, 8276, 1, 0, 0, 56713), -- Boots of the Unrelenting Storm
(211332, 11, 47055, 0, 8275, 1, 0, 0, 56713), -- Bracers of the Autumn Willow
(211332, 10, 46985, 0, 8276, 1, 0, 0, 56713), -- Boots of the Courageous
(211332, 9, 46990, 0, 8276, 1, 0, 0, 56713), -- Belt of the Ice Burrower
(211332, 8, 47056, 0, 8275, 1, 0, 0, 56713), -- Bracers of Cloudy Omen
(211332, 7, 47090, 0, 8276, 1, 0, 0, 56713), -- Boots of Tremoring Earth
(211332, 6, 47108, 0, 8275, 1, 0, 0, 56713), -- Bracers of the Shieldmaiden
(211332, 5, 47093, 0, 8275, 1, 0, 0, 56713), -- Vambraces of the Broken Bond
(211332, 4, 47195, 0, 8276, 1, 0, 0, 56713), -- Belt of the Forgotten Martyr
(211332, 3, 47242, 0, 8280, 1, 0, 0, 56713), -- Trophy of the Crusade
(211332, 2, 49908, 0, 8274, 1, 0, 0, 56713), -- Primordial Saronite
(211332, 1, 2589, 1, 8284, 2, 0, 0, 56713), -- 2589
(211340, 79, 45486, 0, 8315, 1, 0, 0, 56713), -- Drape of the Sullen Goddess
(211340, 78, 45242, 0, 8315, 1, 0, 0, 56713), -- Drape of Mortal Downfall
(211340, 77, 45461, 0, 8315, 1, 0, 0, 56713), -- Drape of Icy Intent
(211340, 76, 45496, 0, 8315, 1, 0, 0, 56713), -- Titanskin Cloak
(211340, 75, 45535, 0, 8315, 1, 0, 0, 56713), -- Show of Faith
(211340, 74, 45609, 0, 8315, 1, 0, 0, 56713), -- Comet's Trail
(211340, 73, 45518, 0, 8315, 1, 0, 0, 56713), -- Flare of the Heavens
(211340, 72, 45534, 0, 8315, 1, 0, 0, 56713), -- Seal of the Betrayed King
(211340, 71, 45495, 0, 8315, 1, 0, 0, 56713), -- Conductive Seal
(211340, 70, 45471, 0, 8315, 1, 0, 0, 56713), -- Fate's Clutch
(211340, 69, 45133, 0, 8315, 1, 0, 0, 56713), -- Pendant of Fiery Havoc
(211340, 68, 45443, 0, 8315, 1, 0, 0, 56713), -- Charm of Meticulous Timing
(211340, 67, 45459, 0, 8315, 1, 0, 0, 56713), -- Frigid Strength of Hodir
(211340, 66, 45243, 0, 8315, 1, 0, 0, 56713), -- Sapphire Amulet of Renewal
(211340, 65, 45517, 0, 8315, 1, 0, 0, 56713), -- Pendulum of Infinity
(211340, 64, 45485, 0, 8315, 1, 0, 0, 56713), -- Bronze Pendant of the Vanir
(211340, 63, 47115, 0, 8276, 1, 0, 0, 56713), -- Death's Verdict
(211340, 62, 47182, 0, 8276, 1, 0, 0, 56713), -- Reign of the Unliving
(211340, 61, 47069, 0, 8279, 1, 0, 0, 56713), -- Justicebringer
(211340, 60, 47041, 0, 8276, 1, 0, 0, 56713), -- Solace of the Defeated
(211340, 59, 46979, 0, 8278, 1, 0, 0, 56713), -- Blade of Tarasque
(211340, 58, 47148, 0, 8277, 1, 0, 0, 56713), -- Stormpike Cleaver
(211340, 57, 47139, 0, 8275, 1, 0, 0, 56713), -- Wail of the Val'kyr
(211340, 56, 46959, 0, 8275, 1, 0, 0, 56713), -- Band of the Violent Temperment
(211340, 55, 47071, 0, 8276, 1, 0, 0, 56713), -- Treads of the Icewalker
(211340, 54, 47092, 0, 8276, 1, 0, 0, 56713), -- Boots of the Mourning Widow
(211340, 53, 46970, 0, 8275, 1, 0, 0, 56713), -- Drape of the Untamed Predator
(211340, 52, 47080, 0, 8276, 1, 0, 0, 56713), -- Satrina's Impeding Scarab
(211340, 51, 47089, 0, 8275, 1, 0, 0, 56713), -- Cloak of Displacement
(211340, 50, 47223, 0, 8275, 1, 0, 0, 56713), -- Ring of the Darkmender
(211340, 49, 47070, 0, 8275, 1, 0, 0, 56713), -- Ring of Callous Aggression
(211340, 48, 47105, 0, 8275, 1, 0, 0, 56713), -- The Executioner's Malice
(211340, 47, 47043, 0, 8275, 1, 0, 0, 56713), -- Charge of the Demon Lord
(211340, 46, 47053, 0, 8275, 1, 0, 0, 56713), -- Symbol of Transgression
(211340, 45, 46976, 0, 8275, 1, 0, 0, 56713), -- Shawl of the Refreshing Winds
(211340, 44, 47193, 0, 8278, 1, 0, 0, 56713), -- Misery's End
(211340, 43, 47079, 0, 8277, 1, 0, 0, 56713), -- Bastion of Purity
(211340, 42, 47233, 0, 8279, 1, 0, 0, 56713), -- Archon Glaive
(211340, 41, 47150, 0, 8276, 1, 0, 0, 56713), -- Greaves of the 7th Legion
(211340, 40, 46999, 0, 8276, 1, 0, 0, 56713), -- Bloodbath Belt
(211340, 39, 46994, 0, 8279, 1, 0, 0, 56713), -- Talonstrike
(211340, 38, 47042, 0, 8275, 1, 0, 0, 56713), -- Pride of the Eredar
(211340, 37, 47138, 0, 8275, 1, 0, 0, 56713), -- Chalice of Searing Light
(211340, 36, 46958, 0, 8277, 1, 0, 0, 56713), -- Steel Bladebreaker
(211340, 35, 46961, 0, 8275, 1, 0, 0, 56713), -- Boneshatter Armplates
(211340, 34, 47081, 0, 8276, 1, 0, 0, 56713), -- Cord of Biting Cold
(211340, 33, 47104, 0, 8277, 1, 0, 0, 56713), -- Twin Spike
(211340, 32, 47107, 0, 8276, 1, 0, 0, 56713), -- Belt of the Merciless Killer
(211340, 31, 47225, 0, 8275, 1, 0, 0, 56713), -- Maiden's Favor
(211340, 30, 47054, 0, 8275, 1, 0, 0, 56713), -- Band of Deplorable Violence
(211340, 29, 46972, 0, 8276, 1, 0, 0, 56713), -- Cord of the Tenebrous Mist
(211340, 28, 47151, 0, 8275, 1, 0, 0, 56713), -- Bracers of Dark Determination
(211340, 27, 47114, 0, 8279, 1, 0, 0, 56713), -- Lupine Longstaff
(211340, 26, 46997, 0, 8276, 1, 0, 0, 56713), -- Dawnbreaker Greaves
(211340, 25, 47149, 0, 8275, 1, 0, 0, 56713), -- Signet of the Traitor King
(211340, 24, 47116, 0, 8275, 1, 0, 0, 56713), -- The Arbiter's Muse
(211340, 23, 46963, 0, 8277, 1, 0, 0, 56713), -- Crystal Plated Vanguard
(211340, 22, 47072, 0, 8276, 1, 0, 0, 56713), -- Girdle of Bloodied Scars
(211340, 21, 46996, 0, 8277, 1, 0, 0, 56713), -- Lionhead Slasher
(211340, 20, 47152, 0, 8276, 1, 0, 0, 56713), -- Belt of Deathly Dominion
(211340, 19, 47106, 0, 8276, 1, 0, 0, 56713), -- Sabatons of Ruthless Judgment
(211340, 18, 47203, 0, 8275, 1, 0, 0, 56713), -- Armbands of the Ashen Saint
(211340, 17, 47140, 0, 8276, 1, 0, 0, 56713), -- Cord of Pale Thorns
(211340, 16, 47183, 0, 8275, 1, 0, 0, 56713), -- Strength of the Nerub
(211340, 15, 47073, 0, 8275, 1, 0, 0, 56713), -- Bracers of the Untold Massacre
(211340, 14, 47141, 0, 8275, 1, 0, 0, 56713), -- Bindings of Dark Essence
(211340, 13, 47194, 0, 8276, 1, 0, 0, 56713), -- Footpads of the Icy Floe
(211340, 12, 46988, 0, 8276, 1, 0, 0, 56713), -- Boots of the Unrelenting Storm
(211340, 11, 47055, 0, 8275, 1, 0, 0, 56713), -- Bracers of the Autumn Willow
(211340, 10, 46985, 0, 8276, 1, 0, 0, 56713), -- Boots of the Courageous
(211340, 9, 46990, 0, 8276, 1, 0, 0, 56713), -- Belt of the Ice Burrower
(211340, 8, 47056, 0, 8275, 1, 0, 0, 56713), -- Bracers of Cloudy Omen
(211340, 7, 47090, 0, 8276, 1, 0, 0, 56713), -- Boots of Tremoring Earth
(211340, 6, 47108, 0, 8275, 1, 0, 0, 56713), -- Bracers of the Shieldmaiden
(211340, 5, 47093, 0, 8275, 1, 0, 0, 56713), -- Vambraces of the Broken Bond
(211340, 4, 47195, 0, 8276, 1, 0, 0, 56713), -- Belt of the Forgotten Martyr
(211340, 3, 47242, 0, 8280, 1, 0, 0, 56713), -- Trophy of the Crusade
(211340, 2, 49908, 0, 8274, 1, 0, 0, 56713), -- Primordial Saronite
(211340, 1, 2589, 1, 8284, 2, 0, 0, 56713); -- 2589

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (106231, 114392, 102499, 114393);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(106231, 0.324999988079071044, 0.324999988079071044, 0, 56713),
(114392, 0.382999986410140991, 1.5, 0, 56713),
(102499, 0.261313140392303466, 0, 0, 56713),
(114393, 0.382999986410140991, 1.5, 0, 56713);

DELETE FROM `creature_template_movement` WHERE `CreatureID`= 207128;
INSERT INTO `creature_template_movement` (`CreatureID`, `HoverInitiallyEnabled`) VALUES
(207128, 1);
