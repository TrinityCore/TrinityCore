SET @CGUID := 6005166;
SET @OGUID := 6002805;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 97004, 1220, 7502, 7581, '0', 0, 0, 0, 0, -973.31427001953125, 4435.2021484375, 735.822021484375, 0.765724837779998779, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- "Red" Jack Findle (Area: Dalaran City - Difficulty: 0) CreateObject1 (Auras: 60913 - [DND] Dalaran - Shop Keeper Greeting)
(@CGUID+1, 96999, 1220, 7502, 7581, '0', 0, 0, 0, 0, -980.7742919921875, 4434.1318359375, 744.0382080078125, 4.6049957275390625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609); -- Susana Averoy (Area: Dalaran City - Difficulty: 0) CreateObject1

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 251033, 1220, 7502, 7581, '0', 0, 0, -967.25384521484375, 4435.98486328125, 735.7366943359375, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 61609), -- Facade (Area: Dalaran City - Difficulty: 0) CreateObject1
(@OGUID+1, 249362, 1220, 7502, 7581, '0', 0, 0, -965.22052001953125, 4435.8671875, 737.73712158203125, 1.042171835899353027, 0.612788200378417968, -0.35283088684082031, 0.612788200378417968, 0.35283362865447998, 120, 255, 1, 61609), -- Lever (Area: Dalaran City - Difficulty: 0) CreateObject1
(@OGUID+2, 242132, 1220, 7502, 7581, '0', 0, 0, -961.08526611328125, 4448.22705078125, 743.8145751953125, 0.628316879272460937, 0, 0, 0.309016227722167968, 0.95105677843093872, 120, 255, 1, 61609); -- Glorious Goods (Area: Dalaran City - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+1, 0, 0, -0.33380699157714843, 0.942641437053680419, 0, 0); -- Lever

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 97004;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(97004, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '60913'); -- 97004 ("Red" Jack Findle) - [DND] Dalaran - Shop Keeper Greeting

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=97004 AND `DifficultyID`=0); -- 97004 ("Red" Jack Findle) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=96999 AND `DifficultyID`=0); -- 96999 (Susana Averoy) - CanSwim

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 97004;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97004, 0, 0, 'Looking for something specific today?', 12, 0, 100, 6, 0, 0, 108823, 0, '\"Red\" Jack Findle to Player'),
(97004, 1, 0, 'And we will answer from the shadows.', 12, 0, 100, 1, 0, 0, 108811, 5, '\"Red\" Jack Findle to Player');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=97004 AND `MenuID`=19540);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(97004, 19540, 61609); -- "Red" Jack Findle

UPDATE `gossip_menu` SET `VerifiedBuild`=61609 WHERE (`MenuID`=19540 AND `TextID`=28878);
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=19540 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(19540, 45226, 0, 0, 'The raven calls.', 108809, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 61609);

UPDATE `gossip_menu_option` SET `GossipOptionID`=45228, `VerifiedBuild`=61609 WHERE (`MenuID`=19540 AND `OptionID`=2);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (19540));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 19540, 0, 0, 0, 47, 0, 40832, 74, 0, '', 0, 'Player for which gossip text is shown has Call of The Uncrowned (40832) in state complete, incomplete, rewarded');

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=96999 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=96999 AND `item`=60335 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=96999 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=96999 AND `item`=35954 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=96999 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(96999, 5, 4470, 0, 0, 1, 0, 0, 61609), -- Simple Wood
(96999, 4, 60335, 0, 0, 1, 0, 0, 61609), -- Thick Hide Pack
(96999, 3, 33449, 0, 0, 1, 0, 0, 61609), -- Crusty Flatbread
(96999, 2, 35954, 0, 0, 1, 0, 0, 61609), -- Sweetened Goat's Milk
(96999, 1, 159, 0, 0, 1, 0, 0, 61609); -- Refreshing Spring Water

DELETE FROM `npc_vendor` WHERE (`entry`=97004 AND `item`=183950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=183951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=183953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=183954 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=6219 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=183955 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=177062 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=228368 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=180060 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=180059 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=180058 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=180057 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=97004 AND `item`=180055 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(97004, 45, 183950, 0, 0, 1, 0, 0, 61609), -- Distilled Death Extract
(97004, 44, 183951, 0, 0, 1, 0, 0, 61609), -- Immortal Shard
(97004, 43, 183952, 0, 0, 1, 0, 0, 61609), -- Machinist's Oil
(97004, 42, 183953, 0, 0, 1, 0, 0, 61609), -- Sealing Wax
(97004, 41, 183954, 0, 0, 1, 0, 0, 61609), -- Malleable Wire
(97004, 40, 6219, 0, 0, 1, 0, 0, 61609), -- Arclight Spanner
(97004, 39, 39354, 0, 0, 1, 0, 0, 61609), -- Light Parchment
(97004, 38, 38426, 0, 0, 1, 0, 0, 61609), -- Eternium Thread
(97004, 37, 39505, 0, 0, 1, 0, 0, 61609), -- Virtuoso Inking Set
(97004, 36, 20815, 0, 0, 1, 0, 0, 61609), -- Jeweler's Toolset
(97004, 35, 6532, 0, 0, 1, 0, 0, 61609), -- Bright Baubles
(97004, 34, 6530, 0, 0, 1, 0, 0, 61609), -- Nightcrawlers
(97004, 33, 4400, 0, 0, 1, 0, 0, 61609), -- Heavy Stock
(97004, 32, 4399, 0, 0, 1, 0, 0, 61609), -- Wooden Stock
(97004, 31, 4289, 0, 0, 1, 0, 0, 61609), -- Salt
(97004, 30, 3371, 0, 0, 1, 0, 0, 61609), -- Crystal Vial
(97004, 29, 4340, 0, 0, 1, 0, 0, 61609), -- Gray Dye
(97004, 28, 4342, 0, 0, 1, 0, 0, 61609), -- Purple Dye
(97004, 27, 4341, 0, 0, 1, 0, 0, 61609), -- Yellow Dye
(97004, 26, 2325, 0, 0, 1, 0, 0, 61609), -- Black Dye
(97004, 25, 2604, 0, 0, 1, 0, 0, 61609), -- Red Dye
(97004, 24, 3857, 0, 0, 1, 0, 0, 61609), -- Coal
(97004, 23, 3466, 0, 0, 1, 0, 0, 61609), -- Strong Flux
(97004, 22, 2880, 0, 0, 1, 0, 0, 61609), -- Weak Flux
(97004, 21, 2678, 0, 0, 1, 0, 0, 61609), -- Mild Spices
(97004, 20, 14341, 0, 0, 1, 0, 0, 61609), -- Rune Thread
(97004, 19, 8343, 0, 0, 1, 0, 0, 61609), -- Heavy Silken Thread
(97004, 18, 4291, 0, 0, 1, 0, 0, 61609), -- Silken Thread
(97004, 17, 2321, 0, 0, 1, 0, 0, 61609), -- Fine Thread
(97004, 16, 2320, 0, 0, 1, 0, 0, 61609), -- Coarse Thread
(97004, 15, 180733, 0, 0, 1, 0, 0, 61609), -- Luminous Flux
(97004, 14, 183955, 0, 0, 1, 0, 0, 61609), -- Curing Salt
(97004, 13, 177062, 0, 0, 1, 0, 0, 61609), -- Penumbra Thread
(97004, 12, 5956, 0, 0, 1, 0, 0, 61609), -- Blacksmith Hammer
(97004, 11, 6217, 0, 0, 1, 0, 0, 61609), -- Copper Rod
(97004, 10, 6256, 0, 0, 1, 0, 0, 61609), -- Fishing Pole
(97004, 9, 85663, 0, 0, 1, 0, 0, 61609), -- Herbalist's Spade
(97004, 8, 7005, 0, 0, 1, 0, 0, 61609), -- Skinning Knife
(97004, 7, 2901, 0, 0, 1, 0, 0, 61609), -- Mining Pick
(97004, 6, 228368, 0, 0, 1, 0, 0, 61609), -- Relic of the Past VI
(97004, 5, 180060, 0, 0, 1, 0, 0, 61609), -- Relic of the Past V
(97004, 4, 180059, 0, 0, 1, 0, 0, 61609), -- Relic of the Past IV
(97004, 3, 180058, 0, 0, 1, 0, 0, 61609), -- Relic of the Past III
(97004, 2, 180057, 0, 0, 1, 0, 0, 61609), -- Relic of the Past II
(97004, 1, 180055, 0, 0, 1, 0, 0, 61609); -- Relic of the Past I
