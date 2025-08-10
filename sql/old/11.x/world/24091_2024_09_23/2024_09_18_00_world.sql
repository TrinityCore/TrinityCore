SET @CGUID := 10002061;

SET @NPCTEXTID := 600031;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 219126, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2753.782958984375, -2579.807373046875, 219.50665283203125, 3.119388341903686523, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+1, 226270, 2552, 14771, 14771, '0', '0', 0, 0, 1, 2739.1494140625, -2557.848876953125, 219.8755645751953125, 0.968167781829833984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Watchful Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+2, 219126, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2720.15625, -2572.17529296875, 219.8852996826171875, 1.771259903907775878, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 436791 - Holding Mead Mug [DNT])
(@CGUID+3, 219126, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2725.53125, -2568.49658203125, 219.54400634765625, 0.033491913229227066, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+4, 219126, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2740.29345703125, -2579.413330078125, 218.950836181640625, 6.262483119964599609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 436791 - Holding Mead Mug [DNT])
(@CGUID+5, 219126, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2740.39501953125, -2577.9619140625, 218.950836181640625, 0.05699058249592781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+6, 219126, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2720.216064453125, -2569.0556640625, 219.8852996826171875, 4.274806022644042968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 436791 - Holding Mead Mug [DNT])
(@CGUID+7, 219126, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2725.97216796875, -2566.614501953125, 219.7487030029296875, 6.069196224212646484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+8, 219126, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2731.283935546875, -2589.989501953125, 219.7810516357421875, 1.52925574779510498, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+9, 219225, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2712.225830078125, -2626.4619140625, 220.040557861328125, 2.745888471603393554, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Cuzolth (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+10, 219226, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2708.911376953125, -2626.8056640625, 220.0397491455078125, 0.715072572231292724, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Vaskarn (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+11, 229927, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2723.37353515625, -2602.924560546875, 219.6511077880859375, 1.998453259468078613, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Unbound Crafter (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+12, 219014, 2552, 14771, 14771, '0', '0', 0, 0, 1, 2762.561767578125, -2562.890625, 219.73443603515625, 3.877671718597412109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+13, 219014, 2552, 14771, 14771, '0', '0', 0, 0, 3, 2752.15283203125, -2552.579833984375, 219.7344207763671875, 3.981329202651977539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+14, 219014, 2552, 14771, 14771, '0', '0', 0, 0, 1, 2792.3369140625, -2663.604248046875, 224.3729095458984375, 1.27729201316833496, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+15, 219014, 2552, 14771, 14771, '0', '0', 0, 0, 1, 2790.538330078125, -2513.232666015625, 239.209625244140625, 0.100807569921016693, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+16, 219014, 2552, 14771, 14771, '0', '0', 0, 0, 1, 2802.4072265625, -2524.520751953125, 239.20941162109375, 1.633610129356384277, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+17, 219014, 2552, 14771, 14771, '0', '0', 0, 0, 3, 2661.087646484375, -2568.407958984375, 219.7292327880859375, 4.758181095123291015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+18, 219014, 2552, 14771, 14771, '0', '0', 0, 0, 3, 2647.4619140625, -2554.552001953125, 219.6681365966796875, 3.167210102081298828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+19, 219014, 2552, 14771, 14771, '0', '0', 0, 0, 1, 2784.09375, -2655.111083984375, 224.3729095458984375, 0.634117841720581054, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+20, 219014, 2552, 14771, 14771, '0', '0', 0, 0, 3, 2709.182373046875, -2553.96533203125, 219.7689056396484375, 0.02004028670489788, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+21, 219014, 2552, 14771, 14771, '0', '0', 0, 0, 2, 2695.091064453125, -2567.9150390625, 219.734466552734375, 4.669504642486572265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+22, 229927, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2793.00341796875, -2661.444580078125, 224.3729095458984375, 3.839724302291870117, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Unbound Crafter (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+23, 229927, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2790.973876953125, -2661.704833984375, 224.3729095458984375, 0.628318548202514648, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513); -- Unbound Crafter (Area: Dornogal - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Oathsworn Citizen
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 717, 0, 0, 0, 0, ''), -- Watchful Peacekeeper
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436791'), -- Oathsworn Citizen - 436791 - Holding Mead Mug [DNT]
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Oathsworn Citizen
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 743, 0, 0, 0, 0, '436791'), -- Oathsworn Citizen - 436791 - Holding Mead Mug [DNT]
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 1023, 0, 0, 0, 0, ''), -- Oathsworn Citizen
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436791'), -- Oathsworn Citizen - 436791 - Holding Mead Mug [DNT]
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Oathsworn Citizen
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''); -- Oathsworn Citizen

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=219226 AND `MenuID` IN (35076,35079,35077));
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(219226, 35076, 56513); -- Vaskarn

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 265441, 0, 0, 0, 0, 0, 0, 0, 56513), -- 219226 (Vaskarn)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 265445, 0, 0, 0, 0, 0, 0, 0, 56513), -- 219226 (Vaskarn)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 265451, 0, 0, 0, 0, 0, 0, 0, 56513); -- 219226 (Vaskarn)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35076 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=35077 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=35079 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35076, @NPCTEXTID+0, 56513), -- 219226 (Vaskarn)
(35077, @NPCTEXTID+1, 56513), -- 219226 (Vaskarn)
(35079, @NPCTEXTID+2, 56513); -- 219226 (Vaskarn)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=35076 AND `OptionID` IN (2,1,0)) OR (`MenuID`=35077 AND `OptionID`=0) OR (`MenuID`=35079 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(35076, 122627, 2, 1, 'Show me your Crest transmutation options.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56513),
(35076, 122628, 1, 0, 'Tell me about upgrading gear using Valorstones and Harbinger Crests.', 0, 0, 0, 35079, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56513),
(35076, 122629, 0, 0, 'How do I acquire Valorstones and Harbinger Crests?', 0, 0, 0, 35077, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56513),
(35077, 122630, 0, 0, 'I want to talk about something else.', 0, 0, 0, 35076, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56513),
(35079, 122634, 0, 0, 'I want to talk about something else.', 0, 0, 0, 35076, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56513);

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=219226 AND `item`=221375 AND `ExtendedCost`=8586 AND `type`=1) OR (`entry`=219226 AND `item`=221373 AND `ExtendedCost`=8587 AND `type`=1) OR (`entry`=219226 AND `item`=221268 AND `ExtendedCost`=8583 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(219226, 3, 221375, 0, 8586, 1, 0, 0, 56513), -- Pack of Runed Harbinger Crests
(219226, 2, 221373, 0, 8587, 1, 0, 0, 56513), -- Satchel of Carved Harbinger Crests
(219226, 1, 221268, 0, 8583, 1, 0, 0, 56513); -- Pouch of Weathered Harbinger Crests

-- Unbound Crafter smart ai
SET @ENTRY := 229927;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+11);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(-(@CGUID+11), 0, 0, 0, 34, 0, 100, 0, 2, 3, 0, 0, 0, 80, 22992700, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #Unbound Crafter #0 (22992700) (update out of combat)', ''),
(-(@CGUID+11), 0, 1, 0, 34, 0, 100, 0, 2, 9, 0, 0, 0, 80, 22992700, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 9 - Self: Start timed action list id #Unbound Crafter #1 (22992700) (update out of combat)', '');

-- Timed list 22992700 smart ai
SET @ENTRY := 22992700;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 11 seconds - Self: Remove stand state KNEEL', '');

-- Path for Unbound Crafter
SET @MOVERGUID := @CGUID+11;
SET @ENTRY := 229927;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Unbound Crafter - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2711.0676, -2594.4236, 219.6511, NULL, 0),
(@PATH, 1, 2700.4783, -2599.8923, 219.6511, NULL, 0),
(@PATH, 2, 2698.6458, -2607.4966, 219.6511, NULL, 0),
(@PATH, 3, 2698.822, -2609.2344, 219.6511, 4.7630, 13841),
(@PATH, 4, 2700.7551, -2600.7102, 219.6511, NULL, 0),
(@PATH, 5, 2705.9714, -2596.7449, 219.6511, NULL, 0),
(@PATH, 6, 2715.2952, -2597.0486, 219.6511, NULL, 0),
(@PATH, 7, 2722.6729, -2600.7952, 219.65112, NULL, 0),
(@PATH, 8, 2725.8064, -2606.9688, 219.65115, NULL, 0),
(@PATH, 9, 2726.3098, -2609.3665, 219.65115, 4.0289, 15843),
(@PATH, 10, 2721.8247, -2599.5261, 219.6511, NULL, 0);

UPDATE `creature` SET `position_x`=2711.0676, `position_y`=-2594.4236, `position_z`=219.6511, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
