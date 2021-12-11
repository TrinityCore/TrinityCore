SET @CGUID :=810000;

-- Queststarter & ender
DELETE FROM `creature_queststarter` WHERE `id` = 143845 AND `quest` = 51485;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES
(143845, 51485);

DELETE FROM `creature_questender` WHERE `id` = 133407 AND `quest` = 51485;
INSERT INTO `creature_questender`(`id`, `quest`) VALUES
(133407, 51485);

-- Conversation Stuff for Overlord Geya'rah
DELETE FROM `conversation_actors` WHERE (`ConversationId`=12748 AND `Idx`=0);
INSERT INTO `conversation_actors`(`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `VerifiedBuild`) VALUES
(12748, 66065, @CGUID+1, 0, 0, 0, 40593);

DELETE FROM `conversation_line_template` WHERE `Id` IN (31271, 31270, 31269, 31268);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(31271, 0, 0, 0, 40906),
(31270, 0, 0, 0, 40906),
(31269, 0, 0, 0, 40906),
(31268, 0, 0, 0, 40906);

DELETE FROM `conversation_template` WHERE `Id`=12748;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(12748, 31268, 0, 40906);

-- Phasing
DELETE FROM `phase_area` WHERE `AreaId` = 5168 AND `PhaseId` =11908;
INSERT INTO `phase_area`(`AreaId`, `PhaseId`, `Comment`) VALUES
(5168, 11908, 'Cosmetik: Maghar Orcs visible for everyone with unlock Archievemt');

-- Condition
DELETE FROM `Conditions` WHERE `SourceEntry` = 5168 AND `SourceTypeOrReferenceId` = 26;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 11908, 5168, 0, 0, 17, 0, 12518, 0, 0, 0, 0, 0, '', 'Allow Phase 11908 if Achievemt \"Allied Race: Maghar Orc\" is rewarded');

-- Gossips
DELETE FROM `gossip_menu` WHERE (`MenuId`=24056 AND `TextId`=37697);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(24056, 37697, 40906); -- 144316 (Mag'har Impaler)

-- SAI Conversation Script for Moira GUID: @CGUID+56
-- SET SAI in Template
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` = 143845;
DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+1) AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+1), 0, 0, 0, 19, 0, 100, 0, 51485, 0, 0, 0, 0, '', 143, 12748, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Overlord Geyarah - On Quest accept 51485 - Start Conversation 12748 - To Invoker');

-- Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 144315, 1, 1637, 5168, '0', '11908', 0, 0, 0, 1936.906005859375, -4809.79931640625, 57.81399917602539062, 1.893602490425109863, 120, 0, 0, 12970, 0, 0, 0, 0, 0, 40906), -- Mag'har Warder (Area: Valley of Honor - Difficulty: 0)
(@CGUID+1, 143845, 1, 1637, 5168, '0', '11908', 0, 0, 0, 1970.4322509765625, -4731.76025390625, 37.48699951171875, 1.225260734558105468, 120, 0, 0, 353730, 0, 0, 0, 0, 0, 40906), -- Overlord Geya'rah (Area: Valley of Honor - Difficulty: 0)
(@CGUID+2, 144318, 1, 1637, 5168, '0', '11908', 0, 0, 0, 1966.8199462890625, -4802.97998046875, 39.090301513671875, 1.593159914016723632, 120, 10, 0, 12381, 0, 1, 0, 0, 0, 40906), -- Mag'har Warrior (Area: Valley of Honor - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+3, 144321, 1, 1637, 5168, '0', '11908', 0, 0, 0, 1952.3021240234375, -4738.4306640625, 37.25665283203125, 1.468596458435058593, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 40906), -- Mag'har Ripper (Area: Valley of Honor - Difficulty: 0)
(@CGUID+4, 144323, 1, 1637, 5168, '0', '11908', 0, 0, 0, 1950.1492919921875, -4709.38916015625, 37.19626998901367187, 2.306943655014038085, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 40906); -- Mag'har Outrider (Area: Valley of Honor - Difficulty: 0) (Auras: 138441 - Wearing Quiver, 166740 - Howling Blade)

-- _template_addon and _addon Data
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mag'har Warder
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Overlord Geya'rah
(@CGUID+2, (@CGUID+2 * 10), 0, 0, 0, 0, 0, 0, 0, ''), -- Mag'har Warrior
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mag'har Ripper
(@CGUID+4, 0, 0, 0, 2, 0, 0, 0, 0, '138441 166740'); -- Mag'har Outrider - 138441 - Wearing Quiver, 166740 - Howling Blade

DELETE FROM `creature_template_addon` WHERE `entry` IN (144323, 144321, 144318, 144316, 143845, 144315);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(144323, 0, 0, 0, 2, 0, 0, 0, 0, '138441 166740'), -- 144323 (Mag'har Outrider) - Wearing Quiver, Howling Blade
(144321, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144321 (Mag'har Ripper)
(144318, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 144318 (Mag'har Warrior)
(144316, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144316 (Mag'har Impaler)
(143845, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 143845 (Overlord Geya'rah)
(144315, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 144315 (Mag'har Warder)

-- Scaling and Model_info
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (144323, 144321, 144318, 144316, 143845, 144315));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(144323, 0, 0, 0, 517, 40906),
(144321, 0, 0, 0, 517, 40906),
(144318, 0, 0, 0, 517, 40906),
(144316, 0, 0, 0, 517, 40906),
(143845, 0, 0, 0, 517, 40906),
(144315, 0, 0, 0, 517, 40906);

-- Creature_template
UPDATE `creature_template` SET `gossip_menu_id`=24056, `minlevel`=60 WHERE `entry`=144323; -- Mag'har Outrider
UPDATE `creature_template` SET `gossip_menu_id`=24056, `minlevel`=60 WHERE `entry`=144321; -- Mag'har Ripper
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=144318; -- Mag'har Warrior
UPDATE `creature_template` SET `gossip_menu_id`=24056, `minlevel`=60 WHERE `entry`=144316; -- Mag'har Impaler
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=143845; -- Overlord Geya'rah
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=144315; -- Mag'har Warder
UPDATE `npc_text` SET `VerifiedBuild`=40906 WHERE `ID`=37697; -- 37697

DELETE FROM `creature_model_info` WHERE `DisplayID`=101799;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(101799, 0.22152663767337799, 0, 0, 40906);

-- Equipment Data
UPDATE `creature_equip_template` SET `ItemID1`=4568, `ItemID2`=1906 WHERE (`CreatureID`=144318 AND `ID`=1); -- Mag'har Warrior
UPDATE `creature_equip_template` SET `ItemID1`=4568, `ItemID2`=1906 WHERE (`CreatureID`=144316 AND `ID`=1); -- Mag'har Impaler
UPDATE `creature_equip_template` SET `ItemID1`=4568, `ItemID2`=1906 WHERE (`CreatureID`=144315 AND `ID`=1); -- Mag'har Warder

-- Waypoint Data for GUID+2 // Need spline looks weird without
SET @PATH := @CGUID+2 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 1923.73, -4637.28, 33.2019, 5.3337, 19358, 0, 0, 100, 0),
(@PATH, 1, 1973.23, -4742.89, 37.3362, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1975.06, -4744.09, 37.4013, 2.2471, 12109, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 1923.73, `position_y`= -4637.28, `position_z`= 33.2019, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+2;
