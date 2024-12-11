SET @CGUID := 10004741;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 222259, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2960.036376953125, -2676.60107421875, 244.5857086181640625, 5.513881683349609375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Concerned Dornogal Citizen (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1 (Auras: 458815 - Interviewee Name Change [DNT])
(@CGUID+1, 222260, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2907.3828125, -2725.9775390625, 238.853729248046875, 0.748263061046600341, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Concerned Dornogal Citizen (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1 (Auras: 458815 - Interviewee Name Change [DNT])
(@CGUID+2, 222263, 2552, 14771, 15184, '0', 0, 0, 0, 0, 3138.82861328125, -2619.779541015625, 296.464111328125, 2.347834348678588867, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Concerned Dornogal Citizen (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1 (Auras: 458815 - Interviewee Name Change [DNT], 449464 - Cosmetic - Reading Book [DNT])
(@CGUID+3, 222268, 2552, 14771, 15182, '0', 23642, 0, 0, 1, 3037.936767578125, -2944.079833984375, 359.7869873046875, 5.595143318176269531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Peacekeeper Leif (Area: Stoneward's Rise - Difficulty: 0) CreateObject1
(@CGUID+4, 222266, 2552, 14771, 15182, '0', 23642, 0, 0, 0, 3039.440185546875, -2948.0625, 359.786895751953125, 1.832460999488830566, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Lamplighter Kaerter (Area: Stoneward's Rise - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (222263 /*222263 (Concerned Dornogal Citizen) - Interviewee Name Change [DNT], Cosmetic - Reading Book [DNT]*/, 222260 /*222260 (Concerned Dornogal Citizen) - Interviewee Name Change [DNT]*/, 222259 /*222259 (Concerned Dornogal Citizen) - Interviewee Name Change [DNT]*/, 222266, 222268);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(222263, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '458815 449464'), -- 222263 (Concerned Dornogal Citizen) - Interviewee Name Change [DNT], Cosmetic - Reading Book [DNT]
(222260, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '458815'), -- 222260 (Concerned Dornogal Citizen) - Interviewee Name Change [DNT]
(222259, 0, 0, 4, 0, 0, 1, 0, 0, 0, 0, 0, 0, '458815'), -- 222259 (Concerned Dornogal Citizen) - Interviewee Name Change [DNT]
(222266, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 222266 (Lamplighter Kaerter)
(222268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 222268 (Peacekeeper Leif)

-- Template
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=222259; -- Concerned Dornogal Citizen
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry` IN (222263, 222260); -- Concerned Dornogal Citizen
UPDATE `creature_template` SET `faction`=3364, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=222266; -- Lamplighter Kaerter
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=222268; -- Peacekeeper Leif

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222263 AND `DifficultyID`=0); -- 222263 (Concerned Dornogal Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222260 AND `DifficultyID`=0); -- 222260 (Concerned Dornogal Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x30000100, `VerifiedBuild`=57689 WHERE (`Entry`=222259 AND `DifficultyID`=0); -- 222259 (Concerned Dornogal Citizen) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222266 AND `DifficultyID`=0); -- 222266 (Lamplighter Kaerter) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222268 AND `DifficultyID`=0); -- 222268 (Peacekeeper Leif) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 23642;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(23642, 'Cosmetic - See Peacekeeper Leif and Lamplighter Kaerter in Dornogal');

DELETE FROM `phase_area` WHERE `PhaseId` = 23642;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14717, 23642, 'See Peacekeeper Leif and Lamplighter Kaerter');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23642 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23642, 0, 0, 0, 47, 0, 80209, 2|64, 0, 0, 'Apply Phase 23642 if Quest 80456 is complete | rewarded'),
(26, 23642, 0, 0, 0, 47, 0, 80210, 2|8|64, 0, 1, 'Apply Phase 23642 if Quest 80456 is not taken | complete | rewarded');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=222263 AND `MenuID`=34999) OR (`CreatureID`=222260 AND `MenuID`=34997) OR (`CreatureID`=222259 AND `MenuID`=35621);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(222263, 34999, 57689), -- Concerned Dornogal Citizen
(222260, 34997, 57689), -- Concerned Dornogal Citizen
(222259, 35621, 57689); -- Concerned Dornogal Citizen

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+5;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 264369, 0, 0, 0, 0, 0, 0, 0, 57689), -- 222259 (Concerned Dornogal Citizen)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 264367, 0, 0, 0, 0, 0, 0, 0, 57689), -- 222259 (Concerned Dornogal Citizen)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 264371, 0, 0, 0, 0, 0, 0, 0, 57689), -- 222260 (Concerned Dornogal Citizen)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 264370, 0, 0, 0, 0, 0, 0, 0, 57689), -- 222260 (Concerned Dornogal Citizen)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 264373, 0, 0, 0, 0, 0, 0, 0, 57689), -- 222263 (Concerned Dornogal Citizen)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 264372, 0, 0, 0, 0, 0, 0, 0, 57689); -- 222263 (Concerned Dornogal Citizen)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35620 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=35621 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=34996 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=34997 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=34998 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=34999 AND `TextID`=@NPCTEXTID+5);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35620, @NPCTEXTID+0, 57689), -- 222259 (Concerned Dornogal Citizen)
(35621, @NPCTEXTID+1, 57689), -- 222259 (Concerned Dornogal Citizen)
(34996, @NPCTEXTID+2, 57689), -- 222260 (Concerned Dornogal Citizen)
(34997, @NPCTEXTID+3, 57689), -- 222260 (Concerned Dornogal Citizen)
(34998, @NPCTEXTID+4, 57689), -- 222263 (Concerned Dornogal Citizen)
(34999, @NPCTEXTID+5, 57689); -- 222263 (Concerned Dornogal Citizen)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (34997,34999,35621));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(34997, 122511, 0, 0, 'What can you tell me about the Arathi Lamplighter?', 0, 0, 1, 34996, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(34999, 122512, 0, 0, 'What can you tell me about the Arathi Lamplighter?', 0, 0, 1, 34998, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(35621, 123322, 0, 0, 'What can you tell me about the Arathi Lamplighter?', 0, 0, 1, 35620, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (34999,34997,35621));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 35621, 0, 0, 0, 47, 0, 80209, 8, 0, '', 0, 'Player for which gossip text is shown has quest An Oddball in Dornogal (80209) active'),
(15, 35621, 0, 0, 0, 48, 0, 450047, 0, 1, '', 1, 'Player for which gossip text is shown has quest objective 450047 == 1 (but hasn\'t rewarded quest yet)'),
(15, 34997, 0, 0, 0, 47, 0, 80209, 8, 0, '', 0, 'Player for which gossip text is shown has quest An Oddball in Dornogal (80209) active'),
(15, 34997, 0, 0, 0, 48, 0, 450048, 0, 1, '', 1, 'Player for which gossip text is shown has quest objective 450048 == 1 (but hasn\'t rewarded quest yet)'),
(15, 34999, 0, 0, 0, 47, 0, 80209, 8, 0, '', 0, 'Player for which gossip text is shown has quest An Oddball in Dornogal (80209) active'),
(15, 34999, 0, 0, 0, 48, 0, 450049, 0, 1, '', 1, 'Player for which gossip text is shown has quest objective 450049 == 1 (but hasn\'t rewarded quest yet)');

-- Quest
DELETE FROM `creature_questender` WHERE (`id`=222268 AND `quest`=80209);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(222268, 80209, 57689); -- An Oddball in Dornogal ended by Peacekeeper Leif

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (117038, 121228);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(117038, 0.347000002861022949, 1.5, 0, 57689),
(121228, 0.347000002861022949, 1.5, 0, 57689);

-- Concerned Dornogal Citizen smart ai
SET @ENTRY := 222259;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 35621, 0, 0, 0, 0, 85, 450695, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 35621 selected - Gossip player: Cast spell 450695 on self', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 33, 224117, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 35621 selected - Gossip player: Give kill credit KC: Citizen 1 Interviewed  (224117)', '');

-- Concerned Dornogal Citizen smart ai
SET @ENTRY := 222260;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 34997, 0, 0, 0, 0, 85, 450695, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 34997 selected - Gossip player: Cast spell 450695 on self', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 33, 224118, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 34997 selected - Gossip player: Give kill credit KC: Citizen 2 Interviewed  (224118)', '');

-- Concerned Dornogal Citizen smart ai
SET @ENTRY := 222263;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 34999, 0, 0, 0, 0, 85, 450695, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 34999 selected - Gossip player: Cast spell 450695 on self', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 33, 224119, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 34999 selected - Gossip player: Give kill credit KC: Citizen 3 Interviewed  (224119)', '');

-- Path for Concerned Dornogal Citizen
SET @MOVERGUID := @CGUID+2;
SET @ENTRY := 222263;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Concerned Dornogal Citizen - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3140.5547, -2608.4705, 296.52078, NULL, 0),
(@PATH, 1, 3147.3376, -2615.6199, 296.34583, NULL, 0),
(@PATH, 2, 3140.9749, -2621.962, 296.40466, NULL, 0),
(@PATH, 3, 3134.3213, -2615.1963, 296.4018, NULL, 0);

UPDATE `creature` SET `position_x`=3140.5547, `position_y`=-2608.4705, `position_z`=296.52078, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '458815 449464');
