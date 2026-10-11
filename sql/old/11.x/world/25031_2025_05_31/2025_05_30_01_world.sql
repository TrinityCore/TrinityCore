# fix respawn times for bridge workers, foreman oslow, and huge boulder
UPDATE `creature` SET `spawntimesecs` = 30 WHERE `guid` IN (334925, 334930, 334929, 334928, 334931, 334927, 334926, 334924);

# move script from alex to boulder
UPDATE `creature_template` SET `ScriptName`='npc_redridge_huge_boulder' WHERE `entry` = 43196; -- Huge Boulder
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` = 653; -- Bridge Worker Alex

UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=43094; -- Canyon Ettin
UPDATE `creature_template` SET `faction`=35, `unit_flags`=0x40, `VehicleId`=938, `ScriptName`='npc_redridge_subdued_canyon_ettin' WHERE `entry`=43197; -- Subdued Canyon Ettin
UPDATE `creature_template` SET `unit_flags3`=0x1000000 WHERE `entry`=43196; -- Huge Boulder

DELETE FROM `creature_template_addon` WHERE `entry` IN (43197 /*43197 (Subdued Canyon Ettin) - Detect: Quest Invis Zone 1*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(43197, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '81299'); -- 43197 (Subdued Canyon Ettin) - Detect: Quest Invis Zone 1

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=341 AND `DifficultyID`=0); -- 341 (Foreman Oslow) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=648 AND `DifficultyID`=0); -- 648 (Bridge Worker Trent) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=649 AND `DifficultyID`=0); -- 649 (Bridge Worker Dmitri) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=650 AND `DifficultyID`=0); -- 650 (Bridge Worker Jess) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=651 AND `DifficultyID`=0); -- 651 (Bridge Worker Daniel) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=652 AND `DifficultyID`=0); -- 652 (Bridge Worker Matthew) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=653 AND `DifficultyID`=0); -- 653 (Bridge Worker Alex) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=43094 AND `DifficultyID`=0); -- 43094 (Canyon Ettin) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=43197 AND `DifficultyID`=0); -- 43197 (Subdued Canyon Ettin) -

DELETE FROM `spell_script_names` WHERE `spell_id` IN (80704, 80702, 80739, 80707);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(80704, 'spell_redridge_control_ettin'),
(80702, 'spell_redridge_control_ettin_2'),
(80739, 'spell_gen_reverse_cast_target_to_caster_triggered'),
(80707, 'spell_gen_despawn_target');

# exit location for thrown boulder
DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry` = 8161;
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES
(8161, 0, -9310.855, -2366.367, 67.17842, 0, 2);

DELETE FROM `creature_text` WHERE `CreatureID` = 43197 AND `GroupID` IN (0, 1, 2, 3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(43197, 0, 0, 'ROCK NOT SO HEAVY! PUNY HUMIES!', 12, 0, 100, 0, 0, 0, 43218, 0, 'Subdued Canyon Ettin to Huge Boulder'),
(43197, 1, 0, 'Where trow? TROW ON BRIDGE??', 12, 0, 100, 0, 0, 0, 43220, 0, 'Subdued Canyon Ettin to Huge Boulder'),
(43197, 2, 0, 'OK! Me trow in water!', 12, 0, 100, 0, 0, 0, 43222, 0, 'Subdued Canyon Ettin to Huge Boulder'),
(43197, 3, 0, 'BYE, BYE, DADDY!', 14, 0, 100, 0, 0, 0, 43226, 0, 'Subdued Canyon Ettin to Huge Boulder');

DELETE FROM `creature_text` WHERE `CreatureID` = 648 AND `GroupID` = 1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(648, 1, 0, 'NO, NO, NO! Please!', 12, 0, 100, 0, 0, 0, 43230, 0, 'Bridge Worker Trent - Scared'),
(648, 1, 1, 'NOOOOOO!!!', 12, 0, 100, 0, 0, 0, 43231, 0, 'Bridge Worker Trent - Scared'),
(648, 1, 2, 'ANYWHERE BUT THE BRIDGE!', 12, 0, 100, 0, 0, 0, 43232, 0, 'Bridge Worker Trent - Scared');

DELETE FROM `creature_text` WHERE `CreatureID` = 649 AND `GroupID` = 1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(649, 1, 0, 'NO, NO, NO! Please!', 12, 0, 100, 0, 0, 0, 43230, 0, 'Bridge Worker Dmitri - Scared'),
(649, 1, 1, 'NOOOOOO!!!', 12, 0, 100, 0, 0, 0, 43231, 0, 'Bridge Worker Dmitri - Scared'),
(649, 1, 2, 'ANYWHERE BUT THE BRIDGE!', 12, 0, 100, 0, 0, 0, 43232, 0, 'Bridge Worker Dmitri - Scared');

DELETE FROM `creature_text` WHERE `CreatureID` = 650 AND `GroupID` = 1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(650, 1, 0, 'NO, NO, NO! Please!', 12, 0, 100, 0, 0, 0, 43230, 0, 'Bridge Worker Jess - Scared'),
(650, 1, 1, 'NOOOOOO!!!', 12, 0, 100, 0, 0, 0, 43231, 0, 'Bridge Worker Jess - Scared'),
(650, 1, 2, 'ANYWHERE BUT THE BRIDGE!', 12, 0, 100, 0, 0, 0, 43232, 0, 'Bridge Worker Jess - Scared');

DELETE FROM `creature_text` WHERE `CreatureID` = 651 AND `GroupID` = 1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(651, 1, 0, 'NO, NO, NO! Please!', 12, 0, 100, 0, 0, 0, 43230, 0, 'Bridge Worker Daniel - Scared'),
(651, 1, 1, 'NOOOOOO!!!', 12, 0, 100, 0, 0, 0, 43231, 0, 'Bridge Worker Daniel - Scared'),
(651, 1, 2, 'ANYWHERE BUT THE BRIDGE!', 12, 0, 100, 0, 0, 0, 43232, 0, 'Bridge Worker Daniel - Scared');

DELETE FROM `creature_text` WHERE `CreatureID` = 652 AND `GroupID` = 2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(652, 2, 0, 'NO, NO, NO! Please!', 12, 0, 100, 0, 0, 0, 43230, 0, 'Bridge Worker Matthew - Scared'),
(652, 2, 1, 'NOOOOOO!!!', 12, 0, 100, 0, 0, 0, 43231, 0, 'Bridge Worker Matthew - Scared'),
(652, 2, 2, 'ANYWHERE BUT THE BRIDGE!', 12, 0, 100, 0, 0, 0, 43232, 0, 'Bridge Worker Matthew - Scared');

DELETE FROM `creature_text` WHERE `CreatureID` = 653 AND `GroupID` = 5;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(653, 5, 0, 'NO, NO, NO! Please!', 12, 0, 100, 0, 0, 0, 43230, 0, 'Bridge Worker Alex - Scared'),
(653, 5, 1, 'NOOOOOO!!!', 12, 0, 100, 0, 0, 0, 43231, 0, 'Bridge Worker Alex - Scared'),
(653, 5, 2, 'ANYWHERE BUT THE BRIDGE!', 12, 0, 100, 0, 0, 0, 43232, 0, 'Bridge Worker Alex - Scared');

-- Path 1 for Subdued Canyon Ettin
SET @ENTRY := 43197;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Subdued Canyon Ettin - Scripted Path - Path To Water');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -9270.707, -2299.5933, 69.642654, NULL, 0),
(@PATH, 1, -9271.457, -2309.5933, 69.892654, NULL, 0),
(@PATH, 2, -9279.707, -2319.0933, 66.892654, NULL, 0),
(@PATH, 3, -9303.957, -2330.5933, 61.642654, NULL, 0),
(@PATH, 4, -9324.86,  -2338.94,   61.2445, 5.0614, 0);

-- Path 2 for Subdued Canyon Ettin
SET @ENTRY := 43197;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Subdued Canyon Ettin - Scripted Path - Path Up Hill');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -9308.439, -2330.975, 61.716003, NULL, 0),
(@PATH, 1, -9292.939, -2325.475, 62.716003, NULL, 0),
(@PATH, 2, -9276.939, -2316.725, 68.966, NULL, 0),
(@PATH, 3, -9260.689, -2312.725, 75.216, NULL, 0),
(@PATH, 4, -9237.689, -2313.225, 78.716, NULL, 0),
(@PATH, 5, -9214.52,  -2334.01,  83.6875, NULL, 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (80739));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 80739, 0, 0, 51, 0, 5, 43196, 0, '', 0, 'Potential target of the spell is TYPEID_UNIT, entry is 43196');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (80704));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES
(13, 2, 80704, 0, 0, 51, 0, 5, 43197, 0, '', 0, 'Potential target of the spell is TYPEID_UNIT, entry is 43197'),
(13, 2, 80704, 0, 0, 33, 0, 1, 3, 0, '', 0, 'Potential target of the spell is TYPEID_UNIT, entry is 43197, if owned by spell caster'),
(13, 2, 80704, 0, 1, 51, 0, 5, 43094, 0, '', 0, 'Otherwise, potential target of the spell is TYPEID_UNIT, entry is 43094');
