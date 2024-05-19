SET @CGUID := 5000387;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 75494, 1116, 6719, 6873, '0', 0, 0, 0, 0, 764.6024169921875, 459.888885498046875, 102.4560089111328125, 5.719715595245361328, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Ironhide Boar (Area: Anguish Fortress - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%, 145362 - Permanent Feign Death (Stun, Untrackable, Uninteractible, Immune))
(@CGUID+1, 76382, 1116, 6719, 6873, '0', 0, 0, 0, 0, 728.00177001953125, 441.26910400390625, 101.70697021484375, 4.71952676773071289, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Pale Crawler (Area: Anguish Fortress - Difficulty: 0) CreateObject1
(@CGUID+2, 75494, 1116, 6719, 6873, '0', 0, 0, 0, 0, 749.41668701171875, 418.164947509765625, 102.2681961059570312, 2.341953039169311523, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Ironhide Boar (Area: Anguish Fortress - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%, 145362 - Permanent Feign Death (Stun, Untrackable, Uninteractible, Immune))
(@CGUID+3, 75494, 1116, 6719, 6873, '0', 0, 0, 0, 0, 708.50177001953125, 408.453125, 102.4711990356445312, 5.945296764373779296, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Ironhide Boar (Area: Anguish Fortress - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%, 145362 - Permanent Feign Death (Stun, Untrackable, Uninteractible, Immune))
(@CGUID+4, 76382, 1116, 6719, 6873, '0', 0, 0, 0, 0, 750.44268798828125, 420.67535400390625, 102.12835693359375, 4.33853006362915039, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Pale Crawler (Area: Anguish Fortress - Difficulty: 0) CreateObject1
(@CGUID+5, 72602, 1116, 6719, 6873, '0', 0, 0, 0, 0, 706.22222900390625, 427.421875, 102.8582229614257812, 0.930994212627410888, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Boar-Keeper Kaz'ar (Area: Anguish Fortress - Difficulty: 0) CreateObject1 (Auras: 145362 - Permanent Feign Death (Stun, Untrackable, Uninteractible, Immune))
(@CGUID+6, 76382, 1116, 6719, 6873, '0', 0, 0, 0, 0, 786.6649169921875, 404.633697509765625, 101.0994415283203125, 6.182679653167724609, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Pale Crawler (Area: Anguish Fortress - Difficulty: 0) CreateObject1
(@CGUID+7, 75494, 1116, 6719, 6873, '0', 0, 0, 0, 0, 728.4444580078125, 438.66839599609375, 101.8671340942382812, 1.677148103713989257, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Ironhide Boar (Area: Anguish Fortress - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%, 145362 - Permanent Feign Death (Stun, Untrackable, Uninteractible, Immune))
(@CGUID+8, 76382, 1116, 6719, 6873, '0', 0, 0, 0, 0, 707.842041015625, 405.326385498046875, 102.5169296264648437, 1.244415760040283203, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Pale Crawler (Area: Anguish Fortress - Difficulty: 0) CreateObject1
(@CGUID+9, 76382, 1116, 6719, 6873, '0', 0, 0, 0, 0, 708.20660400390625, 408.28125, 102.4687423706054687, 4.836190700531005859, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Pale Crawler (Area: Anguish Fortress - Difficulty: 0) CreateObject1
(@CGUID+10, 86689, 1116, 6719, 6873, '0', 0, 0, 0, 0, 708.404541015625, 426.96875, 103.1837081909179687, 2.643360376358032226, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Sneevel (Area: Anguish Fortress - Difficulty: 0) CreateObject1
(@CGUID+11, 76382, 1116, 6719, 6873, '0', 0, 0, 0, 0, 727.86285400390625, 438.91839599609375, 101.88525390625, 6.239078044891357421, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Pale Crawler (Area: Anguish Fortress - Difficulty: 0) CreateObject1
(@CGUID+12, 76382, 1116, 6719, 6873, '0', 0, 0, 0, 0, 766.78302001953125, 460.244781494140625, 102.4927520751953125, 3.103133440017700195, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989); -- Pale Crawler (Area: Anguish Fortress - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '123978 145362'), -- Ironhide Boar - 123978 - Mod Scale 95-120%, 145362 - Permanent Feign Death (Stun, Untrackable, Uninteractible, Immune)
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Pale Crawler
(@CGUID+2, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '123978 145362'), -- Ironhide Boar - 123978 - Mod Scale 95-120%, 145362 - Permanent Feign Death (Stun, Untrackable, Uninteractible, Immune)
(@CGUID+3, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '123978 145362'), -- Ironhide Boar - 123978 - Mod Scale 95-120%, 145362 - Permanent Feign Death (Stun, Untrackable, Uninteractible, Immune)
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Pale Crawler
(@CGUID+5, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '145362'), -- Boar-Keeper Kaz'ar - 145362 - Permanent Feign Death (Stun, Untrackable, Uninteractible, Immune)
(@CGUID+7, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '123978 145362'), -- Ironhide Boar - 123978 - Mod Scale 95-120%, 145362 - Permanent Feign Death (Stun, Untrackable, Uninteractible, Immune)
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Pale Crawler
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Pale Crawler
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Sneevel
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''); -- Pale Crawler

-- Template
UPDATE `creature_template` SET `faction`=2696, `BaseAttackTime`=1500, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=86689; -- Sneevel
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=72602; -- Boar-Keeper Kaz'ar
UPDATE `creature_template` SET `faction`=2358, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=75494; -- Ironhide Boar

-- SpellScript name
DELETE FROM `spell_script_names` WHERE `spell_id` = 145362;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(145362, 'spell_gen_feign_death_all_flags');

-- Difficulty & Model
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53989 WHERE (`Entry`=86689 AND `DifficultyID`=0); -- Sneevel
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435712, `VerifiedBuild`=53989 WHERE (`Entry`=72602 AND `DifficultyID`=0); -- Boar-Keeper Kaz'ar
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=53989 WHERE (`Entry`=75494 AND `DifficultyID`=0); -- Ironhide Boar

 -- Pale Crawler smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 76382;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+1), 0, 0, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 80, 7638200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #Pale Crawler #0 (7638200) (update out of combat)'),
(-(@CGUID+1), 0, 1, 0, '', 34, 0, 100, 0, 2, 2, 0, 0, 80, 7638200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #Pale Crawler #0 (7638200) (update out of combat)');

 -- Timed list 7638200 smart ai
SET @ENTRY := 7638200;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 418, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 418'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 28000, 28000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 28 seconds - Self: Set emote state to 0');

-- Path for CGUID+1
SET @ENTRY := 76382;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Pale Crawler - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 760.0417, 461.25, 102.3215, NULL, 0),
(@PATH, 1, 764.9097, 461.6111, 102.3975, 4.476, 31154),
(@PATH, 2, 728.0018, 441.2691, 101.707, NULL, 30785);

UPDATE `creature` SET `position_x`= 760.0417, `position_y`= 461.25, `position_z`= 102.3215, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+1;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+1, @PATH, 1);
