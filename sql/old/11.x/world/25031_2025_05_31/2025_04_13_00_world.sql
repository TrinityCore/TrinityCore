SET @CGUID := 7001827;
SET @OGUID := 7000456;

SET @ATID := 106;
SET @ATCP := 101;
SET @ATIDSPAWN := 200;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 128345, 1643, 8721, 9032, '0', 9567, 0, 0, 0, -76.8940963745117187, 2097.38720703125, 46.79547882080078125, 4.594814300537109375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Deathcursed Terror (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 263591 - Empowered)
(@CGUID+1, 124417, 1643, 8721, 9032, '0', 9114, 0, 0, 0, -79.1944427490234375, 2098.677001953125, 46.80597686767578125, 5.175147056579589843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037); -- Cyril White (Area: Fallhaven - Difficulty: 0) CreateObject1

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 272567, 1643, 8721, 9032, '0', 9098, 0, -76.8368072509765625, 2100.619873046875, 46.76551055908203125, 4.695298671722412109, 0, 0, -0.71312332153320312, 0.701038599014282226, 120, 255, 0, 60037), -- Cursed Effigy (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+1, 272620, 1643, 8721, 9032, '0', 9086, 0, -77.0972213745117187, 2100.375, 46.649688720703125, 2.602100372314453125, 0, 0, 0.963838577270507812, 0.266486734151840209, 120, 255, 1, 60037), -- Rubble (Area: Fallhaven - Difficulty: 0) CreateObject2
(@OGUID+2, 277378, 1643, 8721, 9032, '0', 9086, 0, -77.0277786254882812, 2100.173583984375, 47.18392562866210937, 4.155613899230957031, 0.112113475799560546, 0.056863784790039062, -0.86755561828613281, 0.481190532445907592, 120, 255, 1, 60037), -- Skull (Area: Fallhaven - Difficulty: 0) CreateObject2
(@OGUID+3, 277378, 1643, 8721, 9032, '0', 9567, 0, -77.0277786254882812, 2100.173583984375, 47.18392562866210937, 4.155613899230957031, 0.112113475799560546, 0.056863784790039062, -0.86755561828613281, 0.481190532445907592, 120, 255, 1, 60189), -- Skull (Area: Fallhaven - Difficulty: 0) CreateObject2
(@OGUID+4, 272620, 1643, 8721, 9032, '0', 9567, 0, -77.0972213745117187, 2100.375, 46.649688720703125, 2.602100372314453125, 0, 0, 0.963838577270507812, 0.266486734151840209, 120, 255, 1, 60189); -- Rubble (Area: Fallhaven - Difficulty: 0) CreateObject2

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (128345 /*128345 (Deathcursed Terror) - Empowered*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(128345, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '263591'); -- 128345 (Deathcursed Terror) - Empowered

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (272567 /*Cursed Effigy*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(272567, 0, 0x40000, 0, 0); -- Cursed Effigy

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 1643, '0', -76.8238, 2096.960, 46.716511, 1.555236, 0, 9846, 0, 'SmartAreaTriggerAI', 'Drustvar - Fallhaven Deathcurse Areatrigger (Quest: "The Final Effigy")', 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 40, 40, 0, 0, 0, 0, 0, 0, '', 0);

-- Template
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=60037 WHERE `entry` IN (272567, 278675); -- Cursed Effigy

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60037 WHERE (`Entry`=128345 AND `DifficultyID`=0); -- 128345 (Deathcursed Terror) - CanSwim

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=2131;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(2131, 27, 2186, 0);

UPDATE `scene_template` SET `ScriptName` = 'scene_drustvar_cleanse_fallhaven' WHERE `SceneId` = 2131;

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (9098,9567,9846,9086,9114);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(9098, 'Cosmetic - See cursed Effigy after protection gets destroyed'),
(9846, 'Cosmetic - Deathcursed Terror Areatrigger'),
(9567, 'Personal - Deathcursed Terror'),
(9086, 'Cosmetic - See destroyed Effigy'),
(9114, 'Cosmetic - See Cyril White in Fallhaven');

DELETE FROM `phase_area` WHERE `PhaseId` IN (9098,9086,9114,9567,9846);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8721, 9098, 'See cursed Effigy after protection gets destroyed'),
(8721, 9086, 'See destroyed Effigy'),
(8721, 9114, 'See Cyril White in Fallhaven'),
(8721, 9567, 'Deathcursed Terror'),
(8721, 9846, 'Deathcursed Terror Areatrigger');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (9115,9870,9098,9086,9114,9567,9846) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 9115, 0, 0, 0, 47, 0, 47982, 2|8|64, 0, 1, 'Apply Phase 9115 if Quest 48622 is not in progress | complete | rewarded'),
(26, 9870, 0, 0, 0, 47, 0, 48622, 2|64, 0, 0, 'Apply Phase 9870 if Quest 48622 is complete | rewarded'),
(26, 9870, 0, 0, 0, 47, 0, 47982, 2|8|64, 0, 1, 'Apply Phase 9870 if Quest 47982 is not in progress | complete | rewarded'),
(26, 9086, 0, 0, 0, 47, 0, 47982, 2|64, 0, 0, 'Apply Phase 9086 if Quest 47982 is complete | rewarded'),
(26, 9114, 0, 0, 0, 47, 0, 47982, 2|64, 0, 0, 'Apply Phase 9114 if Quest 47982 is complete | rewarded'),
(26, 9567, 0, 0, 0, 47, 0, 47982, 8, 0, 0, 'Apply Phase 9567 if Quest 47982 is in progress'),
(26, 9567, 0, 0, 0, 1, 0, 248476, 1, 0, 0, 'Apply Phase 9567 if player has Aura 248476 effect 1'),
(26, 9846, 0, 0, 0, 47, 0, 47982, 8, 0, 0, 'Apply Phase 9846 if Quest 47982 is in progress'),
(26, 9846, 0, 0, 0, 1, 0, 248476, 1, 0, 0, 'Apply Phase 9846 if player has Aura 248476 effect 1'),
(26, 9098, 0, 0, 0, 47, 0, 47982, 8, 0, 0, 'Apply Phase 9098 if Quest 47982 is in progress'),
(26, 9098, 0, 0, 0, 47, 0, 47982, 2|64, 0, 1, 'Apply Phase 9098 if Quest 47982 is not complete | rewarded'),
(26, 9098, 0, 0, 0, 1, 0, 248476, 1, 0, 1, 'Apply Phase 9098 if player has not Aura 248476 effect 1');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (128345, 130419);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(128345, 0, 0, 'Fool! You will die screaming!', 14, 0, 100, 0, 0, 104620, 154748, 0, 'Deathcursed Terror'),
(128345, 1, 0, 'All of Kul Tiras will suffer. You are only the first!', 14, 0, 100, 0, 0, 104621, 154749, 0, 'Deathcursed Terror'),
(128345, 2, 0, 'Gorak Tul... comes...', 12, 0, 100, 0, 0, 104622, 154750, 0, 'Deathcursed Terror to Player'),
(130419, 0, 0, 'What... what is going on?', 12, 0, 100, 6, 0, 97676, 133721, 0, 'Cyril White to Player');

-- ScriptName
DELETE FROM `spell_script_names` WHERE `spell_id` IN (248476, 254558);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(248476, 'spell_gen_force_phase_update'),
(254558, 'spell_drustvar_cancel_deathcurse');

-- Quest AI
DELETE FROM `smart_scripts` WHERE `entryorguid` = 47982 AND `source_type` = 5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(47982, 5, 0, 0, '', 47, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 82238, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On quest accepted - Self: Cast spell 82238 on self');

-- Areatrigger AI
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ATID+0 AND `source_type` = 12;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ATID+0, 12, 0, 0, '', 88, 0, 100, 0, 0, 0, 0, 0, 0, '', 28, 248476, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On areatrigger exit - remove Aura 248476 on Invoker');

-- Quest
DELETE FROM `quest_details` WHERE `ID`=47982;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(47982, 1, 0, 0, 0, 0, 0, 0, 0, 60037); -- The Final Effigy

DELETE FROM `creature_questender` WHERE (`id`=124417 AND `quest`=47982);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(124417, 47982, 60037); -- The Final Effigy ended by Cyril White

DELETE FROM `gameobject_queststarter` WHERE (`id`=278585 AND `quest`=47982);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(278585, 47982, 60037); -- The Final Effigy offered by Cursed Effigy

DELETE FROM `gameobject_questender` WHERE (`id`=278585 AND `quest`=47981);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(278585, 47981, 59888); -- Cracking the Curse ended by Cursed Effigy

DELETE FROM `quest_template_addon` WHERE `ID` IN (47980, 47981, 47982);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(47980, 0, 0, 0, 47978, 47982, -47979, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Furious Familiars
(47981, 0, 0, 0, 47978, 47982, -47979, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Cracking the Curse
(47982, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartQuest'); -- The Final Effigy

UPDATE `quest_template_addon` SET `NextQuestId` = 47982, `ExclusiveGroup` = -47979 WHERE `ID` = 47979;

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 291386;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(291386, NULL, 271509, NULL, 0, 0);

-- Deathcursed Terror smart ai
SET @ENTRY := 128345;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On aggro - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 1000, 3000, 5000, 7000, 0, 11, 263604, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 7 seconds (1 - 3s initially) (IC) - Self: Cast spell  263604 on Victim', ''),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 16000, 18000, 16000, 18000, 0, 11, 281007, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 16 - 18 seconds (IC) - Self: Cast spell  281007 on Self', ''),
(@ENTRY, 0, 3, 0, 2, 0, 100, 1, 0, 50, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-50%% (once) - Self: Talk 1 to invoker', ''),
(@ENTRY, 0, 4, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On death - Self: Talk 2 to invoker', '');

-- Cyril White smart ai
SET @ENTRY := 130419;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 21873, 0, 0, 0, 0, 85, 258198, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21873 selected - Gossip player: Cast spell 258198 on self', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 271850, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21873 selected - Gossip player: Cast spell 271850 on self', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21873 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 13041900, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Cyril White #0 (13041900) (update out of combat)', '');

-- Timed list 13041900 smart ai
SET @ENTRY := 13041900;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 44, 9114, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Remove phase id 9114', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set npc flags NONE', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Take off all equipped items', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -79.1858, 2098.65, 46.723, 0.73303, 'After 1 seconds - Self: Move to position (-79.1858, 2098.65, 46.723, 0.73303) (point id 1)', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.044, 'After 2 seconds - Self: Set orientation to 5.044', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 44, 9114, 1, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Owner/Summoner: Add phase id to 9114', ''),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Despawn in 1 s', '');
