SET @CGUID := 7000317;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 136059, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1161.93408203125, -659.0850830078125, 29.09493446350097656, 4.966357707977294921, 120, 0, 0, 176210, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Layla Evenkeel (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+1, 136061, 1643, 8717, 8718, '0', 0, 0, 0, 1, 1173.1910400390625, -623.763916015625, 29.32428741455078125, 5.615747928619384765, 120, 0, 0, 176210, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Camilla Darksky (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+2, 136063, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1182.6492919921875, -620.37847900390625, 29.516571044921875, 4.470850944519042968, 120, 0, 0, 176210, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Cassandra Brennor (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+3, 148228, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1195.6771240234375, -646.23089599609375, 29.14507102966308593, 1.498639583587646484, 120, 0, 0, 176210, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Marvin Sipsquall (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+4, 136071, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1199.8472900390625, -646.623291015625, 29.25776290893554687, 5.050883293151855468, 120, 0, 0, 176210, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Daniel Brineweaver (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+5, 142346, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1206.584716796875, -645.4351806640625, 29.34119033813476562, 1.085464954376220703, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Tradewinds Tailor (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 136102, 1643, 8717, 8718, '0', 0, 0, 0, 1, 1266.595458984375, -596.904541015625, 40.42242050170898437, 6.143213748931884765, 120, 0, 0, 176210, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Alan Goyle (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+7, 130368, 1643, 8717, 8718, '0', 0, 0, 0, 1, 1215.1754150390625, -615.5850830078125, 29.81883811950683593, 2.290356397628784179, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Samuel D. Colton III (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+8, 136091, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1242.9600830078125, -616.02081298828125, 30.2190093994140625, 2.222506999969482421, 120, 0, 0, 176210, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Myra Cabot (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+9, 132228, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1255.1129150390625, -597.7569580078125, 30.44710350036621093, 6.278410911560058593, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Elric Whalgrene (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (Auras: 260736 - Cosmetic Effects - Elric Whalgrene, 260739 - Cosmetic Effects - Elric Whalgrene)
(@CGUID+10, 130399, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1257.63720703125, -583.1475830078125, 31.15656280517578125, 6.122046470642089843, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Zooey Inksprocket (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (Auras: 258161 - Pencil In Ear - Gnome - Cosmetic)
(@CGUID+11, 133536, 1643, 8717, 8718, '0', 0, 0, 0, 1, 1232.2623291015625, -583.18487548828125, 25.43334770202636718, 1.183392286300659179, 120, 0, 0, 176210, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Grix "Ironfists" Barlow (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (Auras: 281608 - Grix Working At Anvil)
(@CGUID+12, 136041, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1195.1927490234375, -594.560791015625, 29.79686164855957031, 5.263544559478759765, 120, 0, 0, 176210, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Emily Fairweather (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+13, 143261, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1193.029541015625, -589.81427001953125, 29.6735076904296875, 0.60609602928161621, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 53162), -- Chase Hall (Area: Tradewinds Market - Difficulty: 0) CreateObject1
(@CGUID+14, 142095, 1643, 8717, 8718, '0', 0, 0, 0, 0, 1197.5816650390625, -580.01910400390625, 29.76234054565429687, 3.937714099884033203, 120, 0, 0, 88105, 2434, 0, NULL, NULL, NULL, NULL, 53162); -- Henrick Wyther (Area: Tradewinds Market - Difficulty: 0) CreateObject1 (Auras: 250840 - Read Scroll)

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (136059, 136061, 136071, 143261, 130368, 130399);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(136059, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Layla Evenkeel
(136061, 0, 0, 0, 0, 0, 1, 0, 0, 14931, 0, 0, 0, ''), -- 136061 (Camilla Darksky)
(136071, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Daniel Brineweaver
(143261, 0, 0, 0, 0, 0, 1, 0, 10, 0, 0, 0, 0, ''), -- Chase Hall
(130368, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''), -- Samuel D. Colton III
(130399, 0, 0, 0, 0, 0, 1, 0, 483, 0, 0, 0, 0, '258161'); -- 130399 (Zooey Inksprocket) - Pencil In Ear - Gnome - Cosmetic

-- Alan Goyle smart ai
SET @ENTRY := 136102;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 1000, 4000, 17000, 21000, 85, 215172, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 17 - 21 seconds (1 - 4s initially) (OOC) - Self: Cast spell 215172 on self');

-- Emily Fairweather smart ai
SET @ENTRY := 136041;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 18000, 20000, 28000, 31000, 85, 87066, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 28 - 31 seconds (18 - 20s initially) (OOC) - Self: Cast spell 87066 on self');

-- Tradewinds Tailor smart ai
SET @ENTRY := 142346;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+5);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+5), 0, 0, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 80, 14234600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform - Self: Start timed action list id #Tradewinds Tailor #0 (14234600) (update out of combat)'),
(-(@CGUID+5), 0, 1, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 80, 14234600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #Tradewinds Tailor #0 (14234600) (update out of combat)'),
(-(@CGUID+5), 0, 2, 0, '', 34, 0, 100, 0, 2, 2, 0, 0, 80, 14234600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #Tradewinds Tailor #0 (14234600) (update out of combat)');

-- Timed list 14234600 smart ai
SET @ENTRY := 14234600;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 0');

 -- Grix "Ironfists" Barlow smart ai
SET @ENTRY := 133536;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 80, 13353600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform - Self: Start timed action list id #Grix "Ironfists" Barlow #0 (13353600) (update out of combat)'),
(@ENTRY, 0, 1, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 80, 13353601, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #Grix "Ironfists" Barlow #1 (13353601) (update out of combat)');

-- Timed list 13353600 smart ai
SET @ENTRY := 13353600;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 85, 281608, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 281608 on self'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 10000, 10000, 0, 0, 92, 0, 281608, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Interrupt casted spell  281608');

-- Timed list 13353601 smart ai
SET @ENTRY := 13353601;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 85, 267653, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 267653 on self'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 15000, 15000, 0, 0, 92, 0, 267653, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 15 seconds - Self: Interrupt casted spell  267653');

-- delete duplicate Gossip
DELETE FROM `gossip_menu_option` WHERE `MenuID` = 22007 AND `OptionID` IN (14, 15);
DELETE FROM `gossip_menu_option` WHERE `MenuID` = 22204 AND `OptionID` = 1;

-- Path
SET @ENTRY := 142346;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tradewinds Tailor - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1208.349, -642.0903, 29.27368, NULL, 6256),
(@PATH, 1, 1205.833, -644.8299, 29.34067, 2.12739, 6741),
(@PATH, 2, 1205.663, -647.1823, 29.2909, NULL, 6095);

UPDATE `creature` SET `position_x`= 1208.349, `position_y`= -642.0903, `position_z`= 29.27368, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+5;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+5, @PATH, 1);

-- Path
SET @ENTRY := 133536;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Grix Barlow - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1231.848, -584.2012, 25.43335, NULL, 11602),
(@PATH, 1, 1232.262, -583.1849, 25.43335, NULL, 16555);

UPDATE `creature` SET `position_x`= 1231.848, `position_y`= -584.2012, `position_z`= 25.43335, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+11;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+11;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+11, @PATH, 1);

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=133536 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133536 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133536 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133536 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133536 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133536 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133536 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133536 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=130399 AND `item`=158205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=130399 AND `item`=158186 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=130399 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=130399 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=130399 AND `item`=39489 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=130399 AND `item`=183953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=130399 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132228 AND `item`=183950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132228 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136091 AND `item`=163836 AND `ExtendedCost`=6048 AND `type`=1) OR (`entry`=136091 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136091 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136091 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136091 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136091 AND `item`=30746 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136091 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=130368 AND `item`=183954 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=130368 AND `item`=52188 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=130368 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=163203 AND `ExtendedCost`=6426 AND `type`=1) OR (`entry`=142095 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=159959 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=160059 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=158205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=158186 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=163569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=160502 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=160712 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=160710 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=160709 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=160400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=160399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=160398 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142095 AND `item`=160705 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136041 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136041 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136041 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136041 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136041 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136041 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136041 AND `item`=183951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=159959 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136071 AND `item`=177062 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42376 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42378 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42377 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42375 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42374 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42372 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42373 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42369 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42370 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42368 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42363 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42360 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42361 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=42365 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=148228 AND `item`=53852 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=159959 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=160059 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=183955 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=177062 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136063 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136061 AND `item`=163838 AND `ExtendedCost`=6048 AND `type`=1) OR (`entry`=136061 AND `item`=160059 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136061 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136061 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=163203 AND `ExtendedCost`=6426 AND `type`=1) OR (`entry`=136059 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=6219 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=160502 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=163569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136059 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(133536, 9, 3857, 0, 0, 1, 0, 0, 53162), -- Coal
(133536, 8, 18567, 0, 0, 1, 0, 0, 53162), -- Elemental Flux
(133536, 7, 160298, 0, 0, 1, 0, 0, 53162), -- Durable Flux
(133536, 6, 3466, 0, 0, 1, 0, 0, 53162), -- Strong Flux
(133536, 5, 2880, 0, 0, 1, 0, 0, 53162), -- Weak Flux
(133536, 4, 180733, 0, 0, 1, 0, 0, 53162), -- Luminous Flux
(133536, 3, 5956, 0, 0, 1, 0, 0, 53162), -- Blacksmith Hammer
(133536, 2, 2901, 0, 0, 1, 0, 0, 53162), -- Mining Pick
(130399, 8, 158205, 0, 0, 1, 0, 0, 53162), -- Acacia Powder
(130399, 7, 158186, 0, 0, 1, 0, 0, 53162), -- Distilled Water
(130399, 6, 64670, 0, 0, 1, 0, 0, 53162), -- Vanishing Powder
(130399, 5, 39354, 0, 0, 1, 0, 0, 53162), -- Light Parchment
(130399, 4, 39489, 0, 0, 1, 0, 0, 53162), -- Scribe's Satchel
(130399, 3, 183953, 0, 0, 1, 0, 0, 53162), -- Sealing Wax
(130399, 2, 39505, 0, 0, 1, 0, 0, 53162), -- Virtuoso Inking Set
(132228, 3, 183950, 0, 0, 1, 0, 0, 53162), -- Distilled Death Extract
(132228, 2, 3371, 0, 0, 1, 0, 0, 53162), -- Crystal Vial
(136091, 7, 163836, 0, 6048, 1, 0, 0, 53162), -- Forgotten Techniques of Kul Tiras
(136091, 6, 20815, 0, 0, 1, 0, 0, 53162), -- Jeweler's Toolset
(136091, 5, 3857, 0, 0, 1, 0, 0, 53162), -- Coal
(136091, 4, 3466, 0, 0, 1, 0, 0, 53162), -- Strong Flux
(136091, 3, 2880, 0, 0, 1, 0, 0, 53162), -- Weak Flux
(136091, 2, 30746, 0, 0, 1, 0, 0, 53162), -- Mining Sack
(136091, 1, 2901, 0, 0, 1, 0, 0, 53162), -- Mining Pick
(130368, 4, 183954, 0, 0, 1, 0, 0, 53162), -- Malleable Wire
(130368, 3, 52188, 0, 0, 1, 0, 0, 53162), -- Jeweler's Setting
(130368, 2, 20815, 0, 0, 1, 0, 0, 53162), -- Jeweler's Toolset
(142095, 15, 163203, 0, 6426, 1, 0, 0, 53162), -- Hypersensitive Azeritometer Sensor
(142095, 14, 160298, 0, 0, 1, 0, 0, 53162), -- Durable Flux
(142095, 13, 159959, 0, 0, 1, 0, 0, 53162), -- Nylon Thread
(142095, 12, 160059, 0, 0, 1, 0, 0, 53162), -- Amber Tanning Oil
(142095, 11, 158205, 0, 0, 1, 0, 0, 53162), -- Acacia Powder
(142095, 10, 158186, 0, 0, 1, 0, 0, 53162), -- Distilled Water
(142095, 9, 163569, 0, 0, 1, 0, 0, 53162), -- Insulated Wiring
(142095, 8, 160502, 0, 0, 1, 0, 0, 53162), -- Chemical Blasting Cap
(142095, 7, 160712, 0, 0, 1, 0, 0, 53162), -- Powdered Sugar
(142095, 6, 160710, 0, 0, 1, 0, 0, 53162), -- Wild Berries
(142095, 5, 160709, 0, 0, 1, 0, 0, 53162), -- Fresh Potato
(142095, 4, 160400, 0, 0, 1, 0, 0, 53162), -- Foosaka
(142095, 3, 160399, 0, 0, 1, 0, 0, 53162), -- Wild Flour
(142095, 2, 160398, 0, 0, 1, 0, 0, 53162), -- Choral Honey
(142095, 1, 160705, 0, 0, 1, 0, 0, 53162), -- Major's Frothy Coffee
(136041, 1254, 11291, 0, 0, 1, 0, 0, 53162), -- Star Wood
(136041, 1253, 4470, 0, 0, 1, 0, 0, 53162), -- Simple Wood
(136041, 1252, 10938, 1, 0, 1, 0, 0, 53162), -- Lesser Magic Essence
(136041, 1251, 10940, 4, 0, 1, 0, 0, 53162), -- Strange Dust
(136041, 1250, 6217, 0, 0, 1, 0, 0, 53162), -- Copper Rod
(136041, 1249, 38682, 0, 0, 1, 0, 0, 53162), -- Enchanting Vellum
(136041, 1248, 183951, 0, 0, 1, 0, 0, 53162), -- Immortal Shard
(136071, 21, 2324, 0, 0, 1, 0, 0, 53162), -- Bleach
(136071, 20, 6260, 0, 0, 1, 0, 0, 53162), -- Blue Dye
(136071, 19, 2604, 0, 0, 1, 0, 0, 53162), -- Red Dye
(136071, 18, 2605, 0, 0, 1, 0, 0, 53162), -- Green Dye
(136071, 17, 4340, 0, 0, 1, 0, 0, 53162), -- Gray Dye
(136071, 16, 4341, 0, 0, 1, 0, 0, 53162), -- Yellow Dye
(136071, 15, 6261, 0, 0, 1, 0, 0, 53162), -- Orange Dye
(136071, 14, 2325, 0, 0, 1, 0, 0, 53162), -- Black Dye
(136071, 13, 10290, 0, 0, 1, 0, 0, 53162), -- Pink Dye
(136071, 12, 4342, 0, 0, 1, 0, 0, 53162), -- Purple Dye
(136071, 11, 2320, 0, 0, 1, 0, 0, 53162), -- Coarse Thread
(136071, 10, 2321, 0, 0, 1, 0, 0, 53162), -- Fine Thread
(136071, 9, 4291, 0, 0, 1, 0, 0, 53162), -- Silken Thread
(136071, 8, 8343, 0, 0, 1, 0, 0, 53162), -- Heavy Silken Thread
(136071, 7, 14341, 0, 0, 1, 0, 0, 53162), -- Rune Thread
(136071, 6, 38426, 0, 0, 1, 0, 0, 53162), -- Eternium Thread
(136071, 3, 159959, 0, 0, 1, 0, 0, 53162), -- Nylon Thread
(136071, 2, 177062, 0, 0, 1, 0, 0, 53162), -- Penumbra Thread
(148228, 16, 42376, 0, 0, 1, 0, 0, 53162), -- Yellow Martial Shirt
(148228, 15, 42378, 0, 0, 1, 0, 0, 53162), -- Red Martial Shirt
(148228, 14, 42377, 0, 0, 1, 0, 0, 53162), -- Purple Martial Shirt
(148228, 13, 42375, 0, 0, 1, 0, 0, 53162), -- Green Martial Shirt
(148228, 12, 42374, 0, 0, 1, 0, 0, 53162), -- Blue Martial Shirt
(148228, 11, 42372, 0, 0, 1, 0, 0, 53162), -- Scarlet Filigreed Shirt
(148228, 10, 42373, 0, 0, 1, 0, 0, 53162), -- Golden Filigreed Shirt
(148228, 9, 42369, 0, 0, 1, 0, 0, 53162), -- Ebon Filigreed Shirt
(148228, 8, 42370, 0, 0, 1, 0, 0, 53162), -- Cerulean Filigreed Shirt
(148228, 7, 42371, 0, 0, 1, 0, 0, 53162), -- Amber Filigreed Shirt
(148228, 6, 42368, 0, 0, 1, 0, 0, 53162), -- Scarlet Filigreed Doublet
(148228, 5, 42363, 0, 0, 1, 0, 0, 53162), -- Golden Filigreed Doublet
(148228, 4, 42360, 0, 0, 1, 0, 0, 53162), -- Ebon Filigreed Doublet
(148228, 3, 42361, 0, 0, 1, 0, 0, 53162), -- Cerulean Filigreed Doublet
(148228, 2, 42365, 0, 0, 1, 0, 0, 53162), -- Amber Filigreed Doublet
(148228, 1, 53852, 0, 0, 1, 0, 0, 53162), -- Embroidered Shirt
(136063, 22, 2325, 0, 0, 1, 0, 0, 53162), -- Black Dye
(136063, 21, 2604, 0, 0, 1, 0, 0, 53162), -- Red Dye
(136063, 20, 2605, 0, 0, 1, 0, 0, 53162), -- Green Dye
(136063, 19, 4340, 0, 0, 1, 0, 0, 53162), -- Gray Dye
(136063, 18, 4341, 0, 0, 1, 0, 0, 53162), -- Yellow Dye
(136063, 17, 4342, 0, 0, 1, 0, 0, 53162), -- Purple Dye
(136063, 16, 6260, 0, 0, 1, 0, 0, 53162), -- Blue Dye
(136063, 15, 6261, 0, 0, 1, 0, 0, 53162), -- Orange Dye
(136063, 14, 10290, 0, 0, 1, 0, 0, 53162), -- Pink Dye
(136063, 13, 2324, 0, 0, 1, 0, 0, 53162), -- Bleach
(136063, 12, 159959, 0, 0, 1, 0, 0, 53162), -- Nylon Thread
(136063, 11, 14341, 0, 0, 1, 0, 0, 53162), -- Rune Thread
(136063, 10, 38426, 0, 0, 1, 0, 0, 53162), -- Eternium Thread
(136063, 9, 8343, 0, 0, 1, 0, 0, 53162), -- Heavy Silken Thread
(136063, 8, 4291, 0, 0, 1, 0, 0, 53162), -- Silken Thread
(136063, 7, 2321, 0, 0, 1, 0, 0, 53162), -- Fine Thread
(136063, 6, 2320, 0, 0, 1, 0, 0, 53162), -- Coarse Thread
(136063, 5, 160059, 0, 0, 1, 0, 0, 53162), -- Amber Tanning Oil
(136063, 4, 183955, 0, 0, 1, 0, 0, 53162), -- Curing Salt
(136063, 3, 177062, 0, 0, 1, 0, 0, 53162), -- Penumbra Thread
(136063, 2, 7005, 0, 0, 1, 0, 0, 53162), -- Skinning Knife
(136061, 4, 163838, 0, 6048, 1, 0, 0, 53162), -- Forgotten Techniques of Kul Tiras
(136061, 3, 160059, 0, 0, 1, 0, 0, 53162), -- Amber Tanning Oil
(136061, 2, 4289, 0, 0, 1, 0, 0, 53162), -- Salt
(136061, 1, 7005, 0, 0, 1, 0, 0, 53162), -- Skinning Knife
(136059, 14, 163203, 0, 6426, 1, 0, 0, 53162), -- Hypersensitive Azeritometer Sensor
(136059, 13, 3857, 0, 0, 1, 0, 0, 53162), -- Coal
(136059, 12, 18567, 0, 0, 1, 0, 0, 53162), -- Elemental Flux
(136059, 11, 160298, 0, 0, 1, 0, 0, 53162), -- Durable Flux
(136059, 10, 3466, 0, 0, 1, 0, 0, 53162), -- Strong Flux
(136059, 9, 2880, 0, 0, 1, 0, 0, 53162), -- Weak Flux
(136059, 8, 5956, 0, 0, 1, 0, 0, 53162), -- Blacksmith Hammer
(136059, 7, 2901, 0, 0, 1, 0, 0, 53162), -- Mining Pick
(136059, 6, 6219, 0, 0, 1, 0, 0, 53162), -- Arclight Spanner
(136059, 5, 160502, 0, 0, 1, 0, 0, 53162), -- Chemical Blasting Cap
(136059, 4, 163569, 0, 0, 1, 0, 0, 53162), -- Insulated Wiring
(136059, 3, 183952, 0, 0, 1, 0, 0, 53162), -- Machinist's Oil
(136059, 2, 180733, 0, 0, 1, 0, 0, 53162); -- Luminous Flux
