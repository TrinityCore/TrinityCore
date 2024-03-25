-- Creature
UPDATE `creature` SET `equipment_id` = 1 WHERE `guid` = 9004157;

DELETE FROM `creature_template_addon` WHERE `entry` = 207353;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(207353, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '416876'); -- Arko'narin Starshade

DELETE FROM `creature_addon` WHERE `guid` = 9004158;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(9004158, 0, 0, 0, 0, 0, 0, 0, 743, 0, 0, 0, 0, '416876');

-- Template
UPDATE `creature_template` SET `ScriptName` = 'npc_arkonarin_starshade_ancient_curses' WHERE `entry` = 207353;
UPDATE `creature_template` SET `ScriptName` = 'npc_lysande_starshade_ancient_curses' WHERE `entry` = 202700;

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 21386 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 21386, 0, 0, 0, 47, 0, 75890, 2|8|64, 0, 0, 'Apply Phase 12881 if Quest 75890 is in Progress | complete | rewarded'),
(26, 21386, 0, 0, 0, 47, 0, 75891, 2|8|64, 0, 1, 'Apply Phase 12881 if Quest 75891 is not in Progress | complete | rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=22025;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(22025, 58792, 0, 53441);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_quest_ancient_curses_accept' WHERE `Id` = 22025;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=22025 AND `Idx` IN (1,0,2));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(22025, 92501, 1, 0, 0, 0, 0, 53441), -- Full: 0x203CD80000CA7E400046850000635334 Creature/0 R3894/S18053 Map: 0 (Eastern Kingdoms) Entry: 207353 (Arko'narin Starshade) Low: 6509364
(22025, 0, 0, 0, 0, 0, 1, 53441), -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775
(22025, 92502, 2, 0, 0, 0, 0, 53441); -- Full: 0x203CD80000C5F3000046850000635334 Creature/0 R3894/S18053 Map: 0 (Eastern Kingdoms) Entry: 202700 (Lysander Starshade) Low: 6509364

DELETE FROM `conversation_line_template` WHERE `Id` IN (58695, 59782, 58689, 60113, 58686, 58685, 58681, 58684, 58792);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(58695, 0, 1, 0, 0, 53441),
(59782, 0, 0, 0, 0, 53441),
(58689, 0, 1, 0, 0, 53441),
(60113, 0, 2, 0, 0, 53441),
(58686, 0, 1, 0, 0, 53441),
(58685, 0, 1, 0, 0, 53441),
(58681, 0, 2, 0, 0, 53441),
(58684, 0, 1, 0, 0, 53441),
(58792, 0, 0, 0, 0, 53441);

-- Path for Arko'narin Starshade
SET @ENTRY := 207353;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Arkonarin Starshade - Ancient Curses - Walk to Mount up');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8055.644, 811.8108, 67.04881, NULL, 0),
(@PATH, 1, -8059.302, 813.7813, 67.03999, NULL, 0),
(@PATH, 2, -8061.103, 816.2917, 67.12263, NULL, 0),
(@PATH, 3, -8063.181, 819.7986, 66.95995, NULL, 0),
(@PATH, 4, -8064.859, 822.7864, 67.23528, NULL, 0),
(@PATH, 5, -8067.783, 827.4531, 68.42369, NULL, 0);

SET @ENTRY := 207353;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Arkonarin Starshade - Ancient Curses - Fly with Mount');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8062.76, 837.1875, 90.90665, NULL, 0);

-- Path for Lysander Starshade
SET @ENTRY := 202700;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Lysander Starshade - Ancient Curses - Walk to Mount up');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8057.543, 816.6129, 67.32983, NULL, 0),
(@PATH, 1, -8059.802, 818.9965, 67.22331, NULL, 0),
(@PATH, 2, -8060.806, 821.8246, 67.04409, NULL, 0),
(@PATH, 3, -8061.877, 824.8906, 67.3605, NULL, 0),
(@PATH, 4, -8063.377, 828.0174, 68.87323, NULL, 0);

SET @ENTRY := 202700;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Lysander Starshade - Fly with Mount');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8093.516, 861.3646, 86.87444, NULL, 0);
