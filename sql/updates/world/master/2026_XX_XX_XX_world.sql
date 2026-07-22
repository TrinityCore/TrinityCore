SET @ATID		:= SET_VALUE_MANUALLY_HERE;
SET @ATIDSPAWN	:= SET_VALUE_MANUALLY_HERE;
SET @ATCP 		:= SET_VALUE_MANUALLY_HERE;
SET @CGUID 		:= SET_VALUE_MANUALLY_HERE; -- Need 11
SET @NPCTEXTID	:= SET_VALUE_MANUALLY_HERE; -- Need 2

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (12777, 13070);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES 
(12777, 'Cosmetic - See Princess Tess Greymane at Stormwind Keep'),
(13070, 'Cosmetic - See Genn Greymane, Mia Greymane and Greyguards at Stormwind Keep');

DELETE FROM `phase_area` WHERE `AreaId`=6292 AND `PhaseId` IN (12777, 13070);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(6292, 12777, 'Princess Tess Greymane - Stormwind Keep'),
(6292, 13070, 'Genn Greymane, Mia Greymane and Greyguards - Stormwind Keep');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (12777, 13070) AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 12777, 0, 0, 0, 47, 0, 54976, 2|64, 0, 0, 'Apply Phase 12777 if Quest 54976 is complete|rewarded'),
(26, 13070, 0, 0, 0, 47, 0, 54976, 2|64, 0, 0, 'Apply Phase 13070 if Quest 54976 is complete|rewarded');

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 155313, 0, 1519, 6292, '0', '12777', 0, 92167, 0, -8320.9267578125, 289.470489501953125, 156.915863037109375, 0.360383212566375732, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Princess Tess Greymane (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+1, 120599, 0, 1519, 6292, '0', '13070', 0, 0, 1, -8301.6494140625, 269.763885498046875, 155.43048095703125, 5.390641689300537109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Greyguard (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+2, 120599, 0, 1519, 6292, '0', '13070', 0, 0, 1, -8342.984375, 274.513885498046875, 155.43048095703125, 3.837550640106201171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Greyguard (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+3, 120599, 0, 1519, 6292, '0', '13070', 0, 0, 1, -8334.8955078125, 311.588531494140625, 155.4304962158203125, 2.190695047378540039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Greyguard (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+4, 120599, 0, 1519, 6292, '0', '13070', 0, 0, 1, -8297.626953125, 303.416656494140625, 155.43048095703125, 0.624896347522735595, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Greyguard (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+5, 151783, 0, 1519, 6292, '0', '13070', 0, 0, 0, -8316.9345703125, 289.4757080078125, 156.915863037109375, 3.29029083251953125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Genn Greymane (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+6, 151784, 0, 1519, 6292, '0', '13070', 0, 0, 0, -8317.3818359375, 292.11285400390625, 156.915863037109375, 3.623901128768920898, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Mia Greymane (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+7, 120599, 0, 1519, 6292, '0', '13070', 0, 0, 1, -8306.1650390625, 266.328125, 155.4304962158203125, 5.486443042755126953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Greyguard (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+8, 120599, 0, 1519, 6292, '0', '13070', 0, 0, 1, -8339.234375, 308.1319580078125, 155.4304962158203125, 2.190695047378540039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Greyguard (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+9, 120599, 0, 1519, 6292, '0', '13070', 0, 0, 1, -8339.5625, 270.079864501953125, 155.43048095703125, 3.837550640106201171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Greyguard (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+10, 120599, 0, 1519, 6292, '0', '13070', 0, 0, 1, -8301.138671875, 307.6944580078125, 155.43048095703125, 0.624896347522735595, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453); -- Greyguard (Area: Stormwind Keep - Difficulty: 0) CreateObject1

-- Creature template
UPDATE `creature_template` SET `faction`=2163, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=151784; -- Mia Greymane
UPDATE `creature_template` SET `faction`=2767, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=151783; -- Genn Greymane
UPDATE `creature_template` SET `faction`=2163, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=155313; -- Princess Tess Greymane

-- Creature template difficulty
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1281, `StaticFlags1`=0x10000000, `VerifiedBuild`=68453 WHERE `Entry`=151784 AND `DifficultyID`=0; -- 151784 (Mia Greymane) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1281, `StaticFlags1`=0x10000000, `VerifiedBuild`=68453 WHERE `Entry`=151783 AND `DifficultyID`=0; -- 151783 (Genn Greymane) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1281, `StaticFlags1`=0x10000000, `VerifiedBuild`=68453 WHERE `Entry`=155313 AND `DifficultyID`=0; -- 155313 (Princess Tess Greymane) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=68453 WHERE `Entry`=120599 AND `DifficultyID`=0; -- 120599 (Greyguard) - CanSwim

-- Quest
DELETE FROM `quest_template_addon` WHERE `ID`=54976;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(54976, 0, 0, 0, 0, 54977, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `quest_details` WHERE `ID`=54976;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(54976, 2, 0, 0, 0, 0, 0, 0, 0, 68453); -- The Shadow of Gilneas

DELETE FROM `quest_offer_reward` WHERE `ID`=54976;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(54976, 1, 0, 0, 0, 0, 0, 0, 0, 'You have arrived just in time, $n.', 68453); -- The Shadow of Gilneas

DELETE FROM `creature_queststarter` WHERE `id`=126332 AND `quest`=54976;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(126332, 54976, 68453); -- The Shadow of Gilneas offered by Aysa Cloudsinger

DELETE FROM `creature_questender` WHERE `id`=155313 AND `quest`=54976;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(155313, 54976, 68453); -- The Shadow of Gilneas ended by Princess Tess Greymane

-- The Shadow of Gilneas SAI
SET @ENTRY := 54976;
UPDATE `quest_template_addon` SET `ScriptName`='SmartQuest' WHERE `ID`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=5 AND `entryOrGuid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 0, 143, 10939, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Start conversation 10939', ''),
(@ENTRY, 5, 1, 0, 50, 0, 100, 0, 0, 0, 0, 0, 0, 143, 10974, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest rewarded - Player who rewarded: Start conversation 10974', '');

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE `Id`=@ATID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId`=@ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 0, '0', -8321.211914, 288.127350, 156.833771, 0.663997, 0, 13070, 0, 'SmartAreaTriggerAI', 'Stormwind City - Conversation trigger 10963 for quest 54976', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 1, 27, 27, 40, 27, 27, 40, 0, 0, '', 0);

-- Serverside Areatrigger SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ATID+0 AND `source_type`=12 AND `id`=0 AND `link`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ATID+0, 12, 0, 1, '', 46, 0, 100, 1, 0, 0, 0, 0, 0, '', 143, 10963, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On AreaTrigger enter - play Conversation 10963 to Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=@ATID+0 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @ATID+0, 1, 0, 0, 47, 0, 54976, 2, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when quest 54976 is completed');

-- Conversation
DELETE FROM `conversation_actors` WHERE `ConversationId`=10939 AND `Idx`=0 OR `ConversationId`=10963 AND `Idx` IN (0,1) OR `ConversationId`=10974 AND `Idx` IN (2,1,0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES 
(10939, 68683, 0, 0, 150115, 30304, 0, 0, 68453),
(10963, 69346, @CGUID+5, 0, 151783, 0, 0, 0, 68453), -- Full: 0x203AE800009439C0006D57000050A7C7 Creature/0 R3770/S27991 Map: 0 (Eastern Kingdoms) Entry: 151783 (Genn Greymane) Low: 5285831
(10963, 68683, @CGUID+0, 1, 155313, 0, 0, 0, 68453), -- Full: 0x203AE8000097AC40006D57000050A7C7 Creature/0 R3770/S27991 Map: 0 (Eastern Kingdoms) Entry: 155313 (Princess Tess Greymane) Low: 5285831
(10974, 69347, @CGUID+6, 2, 151784, 0, 0, 0, 68453), -- Full: 0x203AE80000943A00006D57000050A7C7 Creature/0 R3770/S27991 Map: 0 (Eastern Kingdoms) Entry: 151784 (Mia Greymane) Low: 5285831
(10974, 69346, @CGUID+5, 1, 151783, 0, 0, 0, 68453), -- Full: 0x203AE800009439C0006D57000050A7C7 Creature/0 R3770/S27991 Map: 0 (Eastern Kingdoms) Entry: 151783 (Genn Greymane) Low: 5285831
(10974, 68683, @CGUID+0, 0, 155313, 0, 0, 0, 68453); -- Full: 0x203AE8000097AC40006D57000050A7C7 Creature/0 R3770/S27991 Map: 0 (Eastern Kingdoms) Entry: 155313 (Princess Tess Greymane) Low: 5285831

DELETE FROM `conversation_line_template` WHERE `Id` IN (26645, 26644, 26649, 26648, 26654, 26653, 26652, 26651, 26650);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(26645, 84, 0, 0, 0, 68453),
(26644, 84, 0, 0, 0, 68453),
(26649, 0, 1, 0, 0, 68453),
(26648, 0, 0, 0, 1, 68453),
(26654, 0, 2, 0, 0, 68453),
(26653, 0, 1, 0, 0, 68453),
(26652, 0, 0, 0, 0, 68453),
(26651, 0, 0, 0, 0, 68453),
(26650, 0, 0, 0, 0, 68453);

DELETE FROM `conversation_template` WHERE `Id` IN (10939, 10963, 10974);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(10939, 26644, 0, 68453),
(10963, 26648, 0, 68453),
(10974, 26650, 0, 68453);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=151783 AND `MenuID`=24341) OR (`CreatureID`=155313 AND `MenuID`=23910);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(151783, 24341, 68453), -- Genn Greymane
(155313, 23910, 68453); -- Princess Tess Greymane

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 169742, 0, 0, 0, 0, 0, 0, 0, 68453), -- 155313 (Princess Tess Greymane)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 176736, 0, 0, 0, 0, 0, 0, 0, 68453); -- 151783 (Genn Greymane)

DELETE FROM `gossip_menu` WHERE (`MenuID`=23910 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=24341 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(23910, @NPCTEXTID+0, 68453), -- 155313 (Princess Tess Greymane)
(24341, @NPCTEXTID+1, 68453); -- 151783 (Genn Greymane)
