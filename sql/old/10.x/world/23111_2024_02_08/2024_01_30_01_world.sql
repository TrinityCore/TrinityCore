SET @CGUID := 7000312;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 124725, 1643, 8717, 9802, '0', 0, 0, 0, 0, 1153.8646240234375, -467.994781494140625, 31.37536048889160156, 4.406496047973632812, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53040), -- Joan Weber (Area: Harbormaster's Office - Difficulty: 0) CreateObject1
(@CGUID+1, 124727, 1643, 8717, 9802, '0', 0, 0, 0, 0, 1151.8367919921875, -465.692718505859375, 31.37541770935058593, 4.617561817169189453, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 53040), -- Galeheart (Area: Harbormaster's Office - Difficulty: 0) CreateObject1
(@CGUID+2, 135446, 1643, 8717, 9802, '0', 0, 0, 0, 0, 1037.859375, -503.703125, 14.79341316223144531, 2.927463769912719726, 120, 0, 0, 23685, 0, 0, NULL, NULL, NULL, NULL, 53040), -- Vindicator Jaelaana (Area: Harbormaster's Office - Difficulty: 0) CreateObject1
(@CGUID+3, 135808, 1643, 8717, 9802, '0', 0, 0, 0, 0, 1075.5989990234375, -477.736114501953125, 9.783464431762695312, 4.444948673248291015, 120, 0, 0, 264315, 0, 0, NULL, NULL, NULL, NULL, 53040), -- Provisioner Fray (Area: Harbormaster's Office - Difficulty: 0) CreateObject1 (Auras: 227301 - Read Scroll)
(@CGUID+4, 139522, 1643, 8717, 9802, '0', 0, 0, 0, 0, 1069.2083740234375, -493.76910400390625, 13.25523281097412109, 1.347262859344482421, 120, 0, 0, 23788, 0, 0, NULL, NULL, NULL, NULL, 53040); -- Scouting Map (Area: Harbormaster's Office - Difficulty: 0) CreateObject1 (Auras: 274053 - Quest Bang - Zone Choice Map)

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 135808;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(135808, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '227301'); -- 135808 (Provisioner Fray) - Read Scroll

-- Creature Template Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 139522;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(139522, 0, 0, 1, 1, 0, 0, NULL);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=135446 AND `MenuID`=10182) OR (`CreatureID`=135808 AND `MenuID`=22600);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(135446, 10182, 53040), -- Vindicator Jaelaana
(135808, 22600, 53040); -- Provisioner Fray

UPDATE `creature_template_gossip` SET `VerifiedBuild`=53040 WHERE (`CreatureID`=124725 AND `MenuID`=22339);

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=135446 AND `item`=162378 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162346 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162345 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162344 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162324 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162323 AND `ExtendedCost`=6418 AND `type`=1) OR (`entry`=135446 AND `item`=162306 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162302 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162276 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162275 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162670 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162261 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162138 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162139 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162132 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=163320 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=162128 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135446 AND `item`=166278 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135446 AND `item`=165880 AND `ExtendedCost`=6453 AND `type`=1) OR (`entry`=135446 AND `item`=165873 AND `ExtendedCost`=6453 AND `type`=1) OR (`entry`=135446 AND `item`=165836 AND `ExtendedCost`=6453 AND `type`=1) OR (`entry`=135446 AND `item`=160539 AND `ExtendedCost`=6306 AND `type`=1) OR (`entry`=135446 AND `item`=163778 AND `ExtendedCost`=6424 AND `type`=1) OR (`entry`=135446 AND `item`=161590 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135446 AND `item`=161588 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135446 AND `item`=161585 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135446 AND `item`=161584 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135446 AND `item`=165720 AND `ExtendedCost`=6447 AND `type`=1) OR (`entry`=135446 AND `item`=161589 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135446 AND `item`=161587 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135446 AND `item`=161586 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135446 AND `item`=161583 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135446 AND `item`=160536 AND `ExtendedCost`=6305 AND `type`=1) OR (`entry`=135446 AND `item`=166445 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135446 AND `item`=168124 AND `ExtendedCost`=6545 AND `type`=1) OR (`entry`=135808 AND `item`=162414 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135808 AND `item`=162413 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135808 AND `item`=162380 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135808 AND `item`=162359 AND `ExtendedCost`=6418 AND `type`=1) OR (`entry`=135808 AND `item`=162328 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135808 AND `item`=162327 AND `ExtendedCost`=6418 AND `type`=1) OR (`entry`=135808 AND `item`=162304 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135808 AND `item`=162317 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135808 AND `item`=162316 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135808 AND `item`=162254 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135808 AND `item`=162134 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135808 AND `item`=163316 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135808 AND `item`=162130 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135808 AND `item`=166277 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135808 AND `item`=161879 AND `ExtendedCost`=6570 AND `type`=1) OR (`entry`=135808 AND `item`=161911 AND `ExtendedCost`=6308 AND `type`=1) OR (`entry`=135808 AND `item`=160540 AND `ExtendedCost`=6306 AND `type`=1) OR (`entry`=135808 AND `item`=161574 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135808 AND `item`=161571 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135808 AND `item`=161570 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135808 AND `item`=161568 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135808 AND `item`=163200 AND `ExtendedCost`=6421 AND `type`=1) OR (`entry`=135808 AND `item`=161976 AND `ExtendedCost`=6314 AND `type`=1) OR (`entry`=135808 AND `item`=161573 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135808 AND `item`=161572 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135808 AND `item`=161569 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135808 AND `item`=161567 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135808 AND `item`=163201 AND `ExtendedCost`=6422 AND `type`=1) OR (`entry`=135808 AND `item`=160534 AND `ExtendedCost`=6305 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(135446, 47, 162378, 0, 6419, 1, 0, 0, 53040), -- Design: Amberblaze Loop
(135446, 46, 162346, 0, 6419, 1, 0, 0, 53040), -- Schematic: Finely-Tuned Stormsteel Destroyer
(135446, 45, 162345, 0, 6419, 1, 0, 0, 53040), -- Schematic: Precision Attitude Adjuster
(135446, 44, 162344, 0, 6419, 1, 0, 0, 53040), -- Schematic: Monelite Scope of Alacrity
(135446, 43, 162324, 0, 6419, 1, 0, 0, 53040), -- Schematic: AZ3-R1-T3 Synthetic Specs
(135446, 42, 162323, 0, 6418, 1, 0, 0, 53040), -- Schematic: AZ3-R1-T3 Synthetic Specs
(135446, 41, 162306, 0, 6419, 1, 0, 0, 53040), -- Formula: Enchanter's Sorcerous Scepter
(135446, 40, 162302, 0, 6419, 1, 0, 0, 53040), -- Formula: Enchant Ring - Pact of Critical Strike
(135446, 39, 162276, 0, 6419, 1, 0, 0, 53040), -- Plans: Stormsteel Spear
(135446, 38, 162275, 0, 6419, 1, 0, 0, 53040), -- Plans: Stormsteel Dagger
(135446, 37, 162670, 0, 6419, 1, 0, 0, 53040), -- Plans: Stormsteel Saber
(135446, 36, 162261, 0, 6419, 1, 0, 0, 53040), -- Plans: Stormsteel Shield
(135446, 35, 162138, 0, 6419, 1, 0, 0, 53040), -- Recipe: Endless Tincture of Fractional Power
(135446, 34, 162139, 0, 6419, 1, 0, 0, 53040), -- Recipe: Surging Alchemist Stone
(135446, 33, 162132, 0, 6419, 1, 0, 0, 53040), -- Recipe: Flask of the Currents
(135446, 32, 163320, 0, 6419, 1, 0, 0, 53040), -- Recipe: Battle Potion of Strength
(135446, 31, 162128, 0, 6419, 1, 0, 0, 53040), -- Recipe: Steelskin Potion
(135446, 30, 166278, 0, 6310, 1, 0, 0, 53040), -- Technique: Contract: 7th Legion
(135446, 29, 165880, 0, 6453, 1, 0, 0, 53040), -- Outpost Upgrade: Arom's Stand
(135446, 28, 165873, 0, 6453, 1, 0, 0, 53040), -- Outpost Upgrade: Castaway Point
(135446, 27, 165836, 0, 6453, 1, 0, 0, 53040), -- Outpost Upgrade: Brennadam
(135446, 20, 160539, 0, 6306, 1, 0, 0, 53040), -- Tabard of the 7th Legion
(135446, 19, 163778, 0, 6424, 1, 0, 0, 53040), -- Lil' Siege Tower
(135446, 14, 161590, 0, 6310, 1, 0, 0, 53040), -- Elite Footman's Legplates
(135446, 13, 161588, 0, 6310, 1, 0, 0, 53040), -- Bracers of the Allied Earthbinders
(135446, 12, 161585, 0, 6310, 1, 0, 0, 53040), -- Gloves of the Forward Skirmisher
(135446, 11, 161584, 0, 6310, 1, 0, 0, 53040), -- Medical Corps Slippers
(135446, 10, 165720, 0, 6447, 1, 0, 0, 53040), -- Monelite Whetstone
(135446, 9, 161589, 0, 6309, 1, 0, 0, 53040), -- Royal Knight's Sabatons
(135446, 8, 161587, 0, 6309, 1, 0, 0, 53040), -- Legguards of the Storm Battalion
(135446, 7, 161586, 0, 6309, 1, 0, 0, 53040), -- Belt of the Grove Auxiliary
(135446, 6, 161583, 0, 6309, 1, 0, 0, 53040), -- Warmage's Flame-Brimming Wristcords
(135446, 3, 160536, 0, 6305, 1, 0, 0, 53040), -- 7th Legionnaire's Cloak
(135446, 2, 166445, 0, 0, 1, 0, 0, 53040), -- 7th Legion Scouting Map
(135446, 1, 168124, 0, 6545, 1, 0, 0, 53040), -- Cache of War Resources
(135808, 29, 162414, 0, 6419, 1, 0, 0, 53040), -- Pattern: Hardened Tempest Knuckles
(135808, 28, 162413, 0, 6419, 1, 0, 0, 53040), -- Pattern: Mistscale Knuckles
(135808, 27, 162380, 0, 6419, 1, 0, 0, 53040), -- Design: Tidal Amethyst Loop
(135808, 26, 162359, 0, 6418, 1, 0, 0, 53040), -- Technique: Contract: Proudmoore Admiralty
(135808, 25, 162328, 0, 6419, 1, 0, 0, 53040), -- Schematic: AZ3-R1-T3 Bionic Bifocals
(135808, 24, 162327, 0, 6418, 1, 0, 0, 53040), -- Schematic: AZ3-R1-T3 Bionic Bifocals
(135808, 23, 162304, 0, 6419, 1, 0, 0, 53040), -- Formula: Enchant Ring - Pact of Mastery
(135808, 22, 162317, 0, 6419, 1, 0, 0, 53040), -- Formula: Enchant Weapon - Masterful Navigation
(135808, 21, 162316, 0, 6419, 1, 0, 0, 53040), -- Formula: Enchant Weapon - Siphoning
(135808, 20, 162254, 0, 6419, 1, 0, 0, 53040), -- Recipe: Coastal Mana Potion
(135808, 19, 162134, 0, 6419, 1, 0, 0, 53040), -- Recipe: Flask of the Vast Horizon
(135808, 18, 163316, 0, 6419, 1, 0, 0, 53040), -- Recipe: Battle Potion of Intellect
(135808, 17, 162130, 0, 6419, 1, 0, 0, 53040), -- Recipe: Potion of Bursting Blood
(135808, 16, 166277, 0, 6310, 1, 0, 0, 53040), -- Schematic: Unstable Temporal Time Shifter
(135808, 15, 161879, 0, 6570, 1, 0, 0, 53040), -- Reins of the Proudmoore Sea Scout
(135808, 14, 161911, 0, 6308, 1, 0, 0, 53040), -- Reins of the Admiralty Stallion
(135808, 13, 160540, 0, 6306, 1, 0, 0, 53040), -- Proudmoore Admiralty Tabard
(135808, 12, 161574, 0, 6310, 1, 0, 0, 53040), -- Boarding Action Vambraces
(135808, 11, 161571, 0, 6310, 1, 0, 0, 53040), -- Cordage Sliding Grips
(135808, 10, 161570, 0, 6310, 1, 0, 0, 53040), -- First Lieutenant's Ceremonial Belt
(135808, 9, 161568, 0, 6310, 1, 0, 0, 53040), -- Maritime Spellweaver's Leggings
(135808, 8, 163200, 0, 6421, 1, 0, 0, 53040), -- Cursed Spyglass
(135808, 7, 161976, 0, 6314, 1, 0, 0, 53040), -- Admiralty Marine's Duffel
(135808, 6, 161573, 0, 6309, 1, 0, 0, 53040), -- Proudmoore Marine's Legplates
(135808, 5, 161572, 0, 6309, 1, 0, 0, 53040), -- Yardarm Sharpshooter's Boots
(135808, 4, 161569, 0, 6309, 1, 0, 0, 53040), -- Master-At-Arms Wristguards
(135808, 3, 161567, 0, 6309, 1, 0, 0, 53040), -- Sailing Master's Sash
(135808, 2, 163201, 0, 6422, 1, 0, 0, 53040), -- Gnoll Targeting Barrel
(135808, 1, 160534, 0, 6305, 1, 0, 0, 53040); -- Navy Blue Boat Cloak
