SET @CGUID := 7002090;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 125385, 1643, 8721, 9130, '0', 9183, 0, 0, 1, -387.09722900390625, 1306.9305419921875, 20.7083740234375, 5.338231086730957031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Marshal Everit Reade (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@CGUID+1, 127714, 1643, 8721, 9130, '0', 9183, 0, 0, 0, -384.12847900390625, 1309.282958984375, 20.59227752685546875, 5.26045846939086914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Bella (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@CGUID+2, 125391, 1643, 8721, 9130, '0', 9183, 0, 0, 1, -386.890625, 1310.4132080078125, 20.34149932861328125, 5.303452491760253906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Waycrest Guard (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@CGUID+3, 125391, 1643, 8721, 9130, '0', 9183, 0, 0, 1, -392.416656494140625, 1307.126708984375, 21.0209808349609375, 5.303452491760253906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Waycrest Guard (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@CGUID+4, 125391, 1643, 8721, 9130, '0', 9183, 0, 0, 1, -389.8194580078125, 1308.6285400390625, 20.56307792663574218, 5.303452491760253906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Waycrest Guard (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@CGUID+5, 125391, 1643, 8721, 9130, '0', 9183, 0, 0, 1, -384.35589599609375, 1311.796875, 20.17281532287597656, 5.303452491760253906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257); -- Waycrest Guard (Area: Hangman's Point - Difficulty: 0) CreateObject1

UPDATE `creature` SET `PhaseId` = 9191 WHERE `guid` = 7002084;

UPDATE `creature` SET `StringId` = 'GuardOne' WHERE `guid` = @CGUID+3;
UPDATE `creature` SET `StringId` = 'GuardTwo' WHERE `guid` = @CGUID+4;
UPDATE `creature` SET `StringId` = 'GuardThree' WHERE `guid` = @CGUID+2;
UPDATE `creature` SET `StringId` = 'GuardFour' WHERE `guid` = @CGUID+5;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (127714,125385,125391);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(127714, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 127714 (Bella)
(125385, 0, 76864, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 125385 (Marshal Everit Reade)
(125391, 0, 76855, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 125391 (Waycrest Guard)

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` IN (144339,125394,125492,125385,125391,125380) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=144339 AND `DifficultyID`=0); -- 144339 (Fletcher's Hollow Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125394 AND `DifficultyID`=0); -- 125394 (Constable Henry Framer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125492 AND `DifficultyID`=0); -- 125492 (Executioner) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125385 AND `DifficultyID`=0); -- 125385 (Marshal Everit Reade) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125391 AND `DifficultyID`=0); -- 125391 (Waycrest Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125380 AND `DifficultyID`=0); -- 125380 (Lucille Waycrest) - CanSwim

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=5665;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(5665, 12676, 0, 60257);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_guards_intro_standing_accused' WHERE `Id` = 5665;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=5665 AND `Idx` IN (3,2,1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(5665, 59850, 7002084, 3, 0, 0, 0, 0, 60257), -- Full: 0x20313CCD607A7100004AC500007CED42 Creature/0 R3151/S19141 Map: 1643 (Kul Tiras) Entry: 125380 (Lucille Waycrest) Low: 8187202
(5665, 61576, 0, 2, 0, 0, 0, 0, 60257), -- Full: 0x20313CCD607A7240004AC500007CED42 Creature/0 R3151/S19141 Map: 1643 (Kul Tiras) Entry: 125385 (Marshal Everit Reade) Low: 8187202
(5665, 59853, 7002088, 1, 0, 0, 0, 0, 60257), -- Full: 0x20313CCD607A7480004AC500007CED43 Creature/0 R3151/S19141 Map: 1643 (Kul Tiras) Entry: 125394 (Constable Henry Framer) Low: 8187203
(5665, 60047, 7002087, 0, 0, 0, 0, 0, 60257); -- Full: 0x20313CCD608CF3C0004AC500007CED41 Creature/0 R3151/S19141 Map: 1643 (Kul Tiras) Entry: 144335 (Fletcher's Hollow Villager) Low: 8187201

DELETE FROM `conversation_line_template` WHERE `Id` IN (12681, 12680, 12679, 12678, 12677, 12676);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(12681, 0, 3, 0, 1, 60257),
(12680, 0, 2, 0, 1, 60257),
(12679, 0, 1, 0, 1, 60257),
(12678, 0, 2, 0, 1, 60257),
(12677, 0, 1, 0, 0, 60257),
(12676, 0, 0, 0, 0, 60257);

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (9183,9191);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(9183, 'Cosmetic - See Marshal Everit and Waycrest Guards at Hangmans Point'),
(9191, 'Cosmetic - See Lucille Waycrest tied up at Hangmans Point');

DELETE FROM `phase_area` WHERE `PhaseId` IN (9183,9191);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8721, 9183, 'See Marshal Everit and Waycrest Guards at Hangmans Point'),
(8721, 9191, 'See Lucille Waycrest tied up at Hangmans Point');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 9183 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 9183, 0, 0, 0, 47, 0, 48283, 2|8|64, 0, 0, 'Apply Phase 9183 if Quest 48283 is in progress | complete | rewarded');

-- Gossip
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (21395));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 21395, 0, 0, 0, 47, 0, 48283, 8, 0, '', 0, 'Player for which gossip text is shown has Standing Accused (48283) in state incomplete');

UPDATE `gossip_menu_option` SET `GossipOptionID`=47697, `OptionBroadcastTextID`=38986, `ActionMenuID`=21394, `VerifiedBuild`=60257 WHERE (`MenuID`=21395 AND `OptionID`=0); -- OptionBroadcastTextID: 38986 - 135341

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (48283, 48110, 48109);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48283, 604, 0, 0, 0, 0, 0, 0, 0, 60257), -- Standing Accused
(48110, 1, 0, 0, 0, 0, 0, 0, 0, 60257), -- In Case of Ambush
(48109, 1, 0, 0, 0, 0, 0, 0, 0, 60257); -- The Woods Have Eyes

DELETE FROM `creature_queststarter` WHERE (`id`=125385 AND `quest` IN (48110,48109));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(125385, 48110, 60257), -- In Case of Ambush offered by Marshal Everit Reade
(125385, 48109, 60257); -- The Woods Have Eyes offered by Marshal Everit Reade

DELETE FROM `creature_questender` WHERE (`id`=125385 AND `quest` IN (48109,48110));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(125385, 48109, 60257), -- The Woods Have Eyes ended by Marshal Everit Reade
(125385, 48110, 60257); -- In Case of Ambush ended by Marshal Everit Reade

DELETE FROM `quest_template_addon` WHERE `ID` IN (48109, 48110);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(48109, 0, 0, 0, 48283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Woods Have Eyes
(48110, 0, 0, 0, 48283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- In Case of Ambush

-- Lucille Waycrest smart ai
SET @ENTRY := 125380;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 21395, 0, 0, 0, 0, 85, 250087, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21395 selected - Gossip player: Cast spell 250087 on self', '');

-- Constable Henry Framer smart ai
SET @ENTRY := 125394;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 48283, 0, 0, 0, 0, 143, 5665, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Standing Accused (48283) - Player who accepted quest: Start conversation (5665) Actors<> (first line 12676)', '');

-- Bella smart ai
SET @ENTRY := 127714;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 58, 0, 100, 0, 0, 12771400, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On point 0 of path 12771400 ended - Self: Despawn instantly', '');

-- Waycrest Guard smart ai
SET @ENTRY := 125391;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 58, 0, 100, 0, 0, 12539100, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On point 0 of path 12539100 ended - Self: Despawn instantly', ''),
(@ENTRY, 0, 1, 0, 58, 0, 100, 0, 0, 12539101, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On point 0 of path 12539101 ended - Self: Despawn instantly', ''),
(@ENTRY, 0, 2, 0, 58, 0, 100, 0, 0, 12539102, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On point 0 of path 12539102 ended - Self: Despawn instantly', ''),
(@ENTRY, 0, 3, 0, 58, 0, 100, 0, 0, 12539103, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On point 0 of path 12539103 ended - Self: Despawn instantly', '');

-- Path for Marshal Everit Reade
SET @ENTRY := 125385;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Marshal Everit Reade - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -387.0918, 1306.9834, 20.69838, NULL, 0),
(@PATH, 1, -387.09723, 1306.9305, 20.669914, 5.33823, 0);

-- Path for Bella
SET @ENTRY := 127714;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Bella - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -384.12848, 1309.283, 20.508945, 5.26045, 0);

-- Path for Waycrest Guard
SET @ENTRY := 125391;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Waycrest Guard - Scripted Path - GuardThree');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -386.89062, 1310.4132, 20.258175, 5.30345, 0);

-- Path for Waycrest Guard
SET @ENTRY := 125391;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Waycrest Guard - Scripted Path - GuardFour');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -384.3559, 1311.7969, 20.089373, 5.30345, 0);

-- Path for Waycrest Guard
SET @ENTRY := 125391;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Waycrest Guard - Scripted Path - GuardTwo');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -389.81946, 1308.6285, 20.479637, 5.30345, 0);

-- Path for Waycrest Guard
SET @ENTRY := 125391;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Waycrest Guard - Scripted Path - GuardOne');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -392.41666, 1307.1267, 20.937431, 5.30345, 0);
