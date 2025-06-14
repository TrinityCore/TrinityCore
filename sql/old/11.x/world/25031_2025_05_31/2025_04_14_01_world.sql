SET @CGUID := 7002074;

SET @NPCTEXTID := 570050;

SET @ATID := 107;
SET @ATCP := 102;
SET @ATIDSPAWN := 201;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+15;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 127743, 1643, 8721, 9131, '0', 0, 0, 0, 0, -408.3663330078125, 1317.8333740234375, 22.62582969665527343, 5.392325878143310546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Auntie Amanda Hale (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+1, 130097, 1643, 8721, 9131, '0', 0, 0, 0, 0, -384.25347900390625, 1284.454833984375, 18.01809883117675781, 6.131077766418457031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+2, 130096, 1643, 8721, 9131, '0', 0, 0, 0, 0, -380.80035400390625, 1287.5711669921875, 18.01809883117675781, 5.400705814361572265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+3, 130096, 1643, 8721, 9131, '0', 0, 0, 0, 0, -380.970489501953125, 1294.138916015625, 18.02124404907226562, 5.374122142791748046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+4, 130097, 1643, 8721, 9131, '0', 0, 0, 0, 0, -375.899322509765625, 1295.796875, 18.01809883117675781, 4.757123470306396484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+5, 130097, 1643, 8721, 9131, '0', 0, 0, 0, 0, -374.020843505859375, 1291.673583984375, 18.03081703186035156, 4.902576923370361328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+6, 144335, 1643, 8721, 9131, '0', 0, 0, 0, 0, -385.682281494140625, 1285.4097900390625, 18.01809883117675781, 5.987240791320800781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+7, 144339, 1643, 8721, 9131, '0', 0, 0, 0, 0, -373.572906494140625, 1293.892333984375, 18.03289604187011718, 4.485391139984130859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+8, 144338, 1643, 8721, 9131, '0', 0, 0, 0, 0, -376.670135498046875, 1293.876708984375, 18.01809883117675781, 4.880229949951171875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+9, 144337, 1643, 8721, 9131, '0', 0, 0, 0, 0, -379.64410400390625, 1289.1353759765625, 18.01809883117675781, 5.793770790100097656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+10, 125380, 1643, 8721, 9131, '0', 0, 0, 0, 0, -373.48785400390625, 1283.6492919921875, 22.8849029541015625, 2.311525821685791015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Lucille Waycrest (Area: Watcher's Wood - Difficulty: 0) CreateObject1 (Auras: 248932 - Tied Up)
(@CGUID+11, 125492, 1643, 8721, 9131, '0', 0, 0, 0, 1, -371.85589599609375, 1282.5677490234375, 22.77555465698242187, 2.272112607955932617, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Executioner (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+12, 130097, 1643, 8721, 9131, '0', 0, 0, 0, 0, -384.260406494140625, 1288.6285400390625, 18.01809883117675781, 5.771496295928955078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+13, 130096, 1643, 8721, 9131, '0', 0, 0, 0, 0, -387.916656494140625, 1282.685791015625, 18.10347938537597656, 0.244347155094146728, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1
(@CGUID+14, 125394, 1643, 8721, 9131, '0', 0, 0, 0, 0, -377.7725830078125, 1282.982666015625, 22.77555465698242187, 2.238608360290527343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Constable Henry Framer (Area: Watcher's Wood - Difficulty: 0) CreateObject1 (Auras: 243679 - Hold Torch)
(@CGUID+15, 130097, 1643, 8721, 9131, '0', 0, 0, 0, 0, -378.94964599609375, 1291.857666015625, 18.01809883117675781, 5.25482940673828125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257); -- Fletcher's Hollow Villager (Area: Watcher's Wood - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (125394 /*125394 (Constable Henry Framer) - Hold Torch*/, 125492 /*125492 (Executioner)*/, 125380 /*125380 (Lucille Waycrest) - Tied Up*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(125394, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '243679'), -- 125394 (Constable Henry Framer) - Hold Torch
(125492, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 125492 (Executioner)
(125380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248932'); -- 125380 (Lucille Waycrest) - Tied Up

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 1643, '0', -384.274, 1294.129, 17.978, 5.382452, 0, 0, 0, 'SmartAreaTriggerAI', 'Drustvar - Hangmans Point intro conversation (Quest: "The Waycrest Daughter")', 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 35, 35, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=22 AND `SourceGroup` = 1 AND `SourceEntry` = @ATID+0 AND `SourceId` = 12);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(22, 1, @ATID+0, 12, 0, 47, 0, 48108, 2, 0, 0, 'AreaTrigger execute SAI only if Quest 48108 is in state complete');

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` IN (125394,144336,125492,125380,144337,144338,144339,144335,130096,130097) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125394 AND `DifficultyID`=0); -- 125394 (Constable Henry Framer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=144336 AND `DifficultyID`=0); -- 144336 (Fletcher's Hollow Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125492 AND `DifficultyID`=0); -- 125492 (Executioner) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125380 AND `DifficultyID`=0); -- 125380 (Lucille Waycrest) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=144337 AND `DifficultyID`=0); -- 144337 (Fletcher's Hollow Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=144338 AND `DifficultyID`=0); -- 144338 (Fletcher's Hollow Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=144339 AND `DifficultyID`=0); -- 144339 (Fletcher's Hollow Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=144335 AND `DifficultyID`=0); -- 144335 (Fletcher's Hollow Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=130096 AND `DifficultyID`=0); -- 130096 (Fletcher's Hollow Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=130097 AND `DifficultyID`=0); -- 130097 (Fletcher's Hollow Villager) - CanSwim

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=5664;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(5664, 12672, 0, 60257);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=5664 AND `Idx` IN (0,1));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(5664, 59853, @CGUID+14, 0, 0, 0, 0, 0, 60257), -- Full: 0x2016ECCD607A7480001F2A00007B6258 Creature/0 R1467/S7978 Map: 1643 (Kul Tiras) Entry: 125394 (Constable Henry Framer) Low: 8086104
(5664, 60045, @CGUID+7, 1, 0, 0, 0, 0, 60257); -- Full: 0x2016ECCD608CF4C0001F2A00007B6258 Creature/0 R1467/S7978 Map: 1643 (Kul Tiras) Entry: 144339 (Fletcher's Hollow Villager) Low: 8086104

DELETE FROM `conversation_line_template` WHERE `Id` IN (12675, 12674, 12673, 12672);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(12675, 0, 0, 1, 0, 60257),
(12674, 0, 1, 0, 0, 60257),
(12673, 0, 0, 0, 0, 60257),
(12672, 0, 0, 1, 0, 60257);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=127743 AND `MenuID`=21549) OR (`CreatureID`=125394 AND `MenuID`=21407);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(127743, 21549, 60257), -- Auntie Amanda Hale
(125394, 21407, 60257); -- Constable Henry Framer

UPDATE `creature_template_gossip` SET `VerifiedBuild`=60257 WHERE (`CreatureID`=125380 AND `MenuID`=21395);

UPDATE `gossip_menu` SET `VerifiedBuild`=60257 WHERE (`MenuID`=21549 AND `TextID`=32861) OR (`MenuID`=21395 AND `TextID`=32590) OR (`MenuID`=21407 AND `TextID`=32606);

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (48283 /*Standing Accused*/, 53701 /*A Drust Cause*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48283, 604, 0, 0, 0, 0, 0, 0, 0, 60257), -- Standing Accused
(53701, 0, 0, 0, 0, 0, 0, 0, 0, 60257); -- A Drust Cause

DELETE FROM `creature_queststarter` WHERE (`id`=125394 AND `quest`=48283);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(125394, 48283, 60257); -- Standing Accused offered by Constable Henry Framer

DELETE FROM `creature_questender` WHERE (`id`=125385 AND `quest`=48283) OR (`id`=125394 AND `quest`=48108);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(125385, 48283, 60257), -- Standing Accused ended by Marshal Everit Reade
(125394, 48108, 60257); -- The Waycrest Daughter ended by Constable Henry Framer

DELETE FROM `quest_template_addon` WHERE `ID` = 48283;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(48283, 0, 0, 0, 48108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Standing Accused

-- Areatrigger AI
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ATID+0 AND `source_type` = 12;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ATID+0, 12, 0, 0, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 143, 5664, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On AreaTrigger enter - play Conversation 5664 on Invoker');

-- Fletcher's Hollow Villager smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (144336,144337,144338,144339,144335,130096,130097);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (144336,144337,144338,144339,144335,130096,130097);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(144336, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', ''),
(144337, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', ''),
(144338, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', ''),
(144339, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', ''),
(144335, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', ''),
(130096, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', ''),
(130097, 0, 0, 0, 60, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 10, 22, 15, 5, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds - Self: Play random emote: 22, 15, 5, 25,', '');
