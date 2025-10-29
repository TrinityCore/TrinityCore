-- delete data from wrong guid range
SET @CGUID := 10006842;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23;
DELETE FROM `spawn_tracking` WHERE (`SpawnType`=0 AND `SpawnId` IN (@CGUID+0,@CGUID+1,@CGUID+2,@CGUID+3,@CGUID+4,@CGUID+5,@CGUID+6,@CGUID+7,@CGUID+8,@CGUID+9,@CGUID+10));
DELETE FROM `spawn_tracking_state` WHERE `SpawnId` BETWEEN @CGUID+0 AND @CGUID+10;

-- use bfa guid range
SET @CGUID := 7003643;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 126159, 1643, 8721, 9170, '0', 0, 0, 0, 0, -966.16839599609375, 1280.8853759765625, 1.349034309387207031, 3.408623218536376953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Frightened Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+1, 126159, 1643, 8721, 9170, '0', 0, 0, 0, 0, -990.6163330078125, 1218.373291015625, 4.844318389892578125, 5.732672691345214843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Frightened Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+2, 126159, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1053.7274169921875, 1248.498291015625, 3.664930582046508789, 5.491601943969726562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Frightened Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+3, 126159, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1037.1441650390625, 1198.703125, 5.243381500244140625, 3.64534926414489746, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Frightened Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+4, 126159, 1643, 8721, 9170, '0', 0, 0, 0, 0, -944.873291015625, 1253.8316650390625, 2.395283937454223632, 4.26699686050415039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Frightened Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+5, 126159, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1060.2100830078125, 1191.701416015625, 6.38011789321899414, 0.094857007265090942, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Frightened Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+6, 126159, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1000.1995849609375, 1249.2396240234375, 4.803758621215820312, 1.41468822956085205, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Frightened Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+7, 126159, 1643, 8721, 9170, '0', 0, 0, 0, 0, -939.09027099609375, 1219.0399169921875, 7.38536691665649414, 2.319292545318603515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Frightened Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+8, 126159, 1643, 8721, 9170, '0', 0, 0, 0, 0, -985.55035400390625, 1175.5260009765625, 8.042690277099609375, 1.363971471786499023, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Frightened Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+9, 126159, 1643, 8721, 9170, '0', 0, 0, 0, 0, -946.05902099609375, 1181.8211669921875, 10.21261119842529296, 2.297159671783447265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Frightened Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+10, 126159, 1643, 8721, 9170, '0', 0, 0, 0, 0, -945.61285400390625, 1180.6319580078125, 10.38770771026611328, 5.817588329315185546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Frightened Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+11, 126730, 1643, 8721, 9170, '0', 9325, 0, 0, 0, -1051.8975830078125, 1281.810791015625, 7.295806884765625, 0.067046679556369781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+12, 126730, 1643, 8721, 9170, '0', 9325, 0, 0, 0, -1045.7760009765625, 1285.361083984375, 7.109745025634765625, 3.874427556991577148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+13, 126730, 1643, 8721, 9170, '0', 9325, 0, 0, 0, -1042.9114990234375, 1302.7239990234375, 4.824723243713378906, 0.290113806724548339, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+14, 126730, 1643, 8721, 9170, '0', 9325, 0, 0, 0, -1053.3385009765625, 1275.4930419921875, 7.418804645538330078, 1.093313932418823242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+15, 126730, 1643, 8721, 9170, '0', 9325, 0, 0, 0, -1045.625, 1279.5816650390625, 7.31776285171508789, 2.396680831909179687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+16, 126730, 1643, 8721, 9170, '0', 9325, 0, 0, 0, -1051.015625, 1287.21875, 6.89956521987915039, 3.971215486526489257, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+17, 126730, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1014.026123046875, 1236.4757080078125, 6.732679367065429687, 1.079315781593322753, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+18, 126730, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1015.81427001953125, 1236.953125, 6.471057891845703125, 3.619761228561401367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+19, 126730, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1072.5225830078125, 1296.9444580078125, 2.533166408538818359, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+20, 126730, 1643, 8721, 9170, '0', 0, 0, 0, 0, -967.75177001953125, 1237.7535400390625, 4.40622711181640625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+21, 126730, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1052.8177490234375, 1207.5694580078125, 5.523822784423828125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+22, 126730, 1643, 8721, 9170, '0', 0, 0, 0, 0, -992.23089599609375, 1190.9947509765625, 6.974688529968261718, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+23, 126730, 1643, 8721, 9170, '0', 0, 0, 0, 0, -956.41839599609375, 1214.8333740234375, 6.010541915893554687, 3.814818859100341796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163); -- Fletcher's Hollow Woodsman (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Woodsman
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Woodsman
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Woodsman
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Woodsman
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Woodsman
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Woodsman
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Woodsman
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Woodsman
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Woodsman
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Woodsman
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Woodsman
(@CGUID+11, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fletcher's Hollow Woodsman
(@CGUID+14, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fletcher's Hollow Woodsman
(@CGUID+15, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fletcher's Hollow Woodsman
(@CGUID+17, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fletcher's Hollow Woodsman - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+18, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fletcher's Hollow Woodsman - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+19, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fletcher's Hollow Woodsman - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+20, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fletcher's Hollow Woodsman - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+21, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fletcher's Hollow Woodsman - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+22, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fletcher's Hollow Woodsman - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+23, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'); -- Fletcher's Hollow Woodsman - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)

-- Template
UPDATE `creature_template` SET `ScriptName` = 'npc_drustvar_frightend_woodsman_private' WHERE `entry` = 126159;

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` = 126159 AND `DifficultyID` = 1);
UPDATE `creature_template_difficulty` SET `StaticFlags1` = 0x12000000 WHERE `Entry` = 126159;

-- Update Strings
UPDATE `creature` SET `StringId` = 'CosmeticWoodmansPath0' WHERE `guid` = @CGUID+0;
UPDATE `creature` SET `StringId` = 'CosmeticWoodmansPath1' WHERE `guid` = @CGUID+1;
UPDATE `creature` SET `StringId` = 'CosmeticWoodmansPath2' WHERE `guid` = @CGUID+2;
UPDATE `creature` SET `StringId` = 'CosmeticWoodmansPath3' WHERE `guid` = @CGUID+3;
UPDATE `creature` SET `StringId` = 'CosmeticWoodmansPath4' WHERE `guid` = @CGUID+4;
UPDATE `creature` SET `StringId` = 'CosmeticWoodmansPath5' WHERE `guid` = @CGUID+5;
UPDATE `creature` SET `StringId` = 'CosmeticWoodmansPath6' WHERE `guid` = @CGUID+6;
UPDATE `creature` SET `StringId` = 'CosmeticWoodmansPath7' WHERE `guid` = @CGUID+7;
UPDATE `creature` SET `StringId` = 'CosmeticWoodmansPath8' WHERE `guid` = @CGUID+8;
UPDATE `creature` SET `StringId` = 'CosmeticWoodmansPath9' WHERE `guid` = @CGUID+9;
UPDATE `creature` SET `StringId` = 'CosmeticWoodmansPath10' WHERE `guid` = @CGUID+10;

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 9325;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(9325, 'Cosmetic - See Fletchers Hollow Woodsman at Timbered Strand camp');

DELETE FROM `phase_area` WHERE `PhaseId` = 9325;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8721, 9325, 'Fletchers Hollow Woodsman at Timbered Strand camp');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 9325 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 9325, 0, 0, 0, 47, 0, 48518, 2|64, 0, 0, 'Apply Phase 9325 if Quest 48518 is complete|rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=5863;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(5863, 13139, 0, 63163);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=5863 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(5863, 60393, 7003584, 0, 0, 0, 0, 0, 63163); -- Full: 0x2016FCCD607B59800020FB000044EC67 Creature/0 R1471/S8443 Map: 1643 (Kul Tiras) Entry: 126310 (Evelyn Pare) Low: 4516967

UPDATE `conversation_actors` SET `VerifiedBuild`=63163 WHERE (`ConversationId`=6209 AND `Idx`=0);

DELETE FROM `conversation_line_template` WHERE `Id` IN (13140, 13139);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(13140, 0, 0, 0, 0, 63163),
(13139, 0, 0, 0, 0, 63163);

UPDATE `conversation_line_template` SET `VerifiedBuild`=63163 WHERE `Id` IN (13866, 13865);

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (49295 /*Clear-Cutting*/, 48518 /*Save Who We Can*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(49295, 1, 1, 0, 0, 0, 0, 0, 0, 63163), -- Clear-Cutting
(48518, 1, 1, 0, 0, 0, 0, 0, 0, 63163); -- Save Who We Can

DELETE FROM `creature_queststarter` WHERE (`id`=126310 AND `quest` IN (49295,48518));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(126310, 49295, 63163), -- Clear-Cutting offered by Evelyn Pare
(126310, 48518, 63163); -- Save Who We Can offered by Evelyn Pare

DELETE FROM `creature_questender` WHERE (`id`=126310 AND `quest` IN (49295,48518));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(126310, 49295, 63163), -- Clear-Cutting ended by Evelyn Pare
(126310, 48518, 63163); -- Save Who We Can ended by Evelyn Pare

DELETE FROM `quest_template_addon` WHERE `ID` IN (49295,48518);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(49295, 0, 0, 0, 48171, 48519, -49295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Clear-Cutting
(48518, 0, 0, 0, 48171, 48519, -49295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Save Who We Can

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 292396;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(292396, NULL, NULL, NULL, 1, 0);

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 126159;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(126159, 251542, 1, 0);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 126159;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(126159, 0, 0, 'What are these things!? I\'m getting out of here!', 12, 0, 100, 5, 0, 0, 154071, 0, 'Frightened Woodsman to Player'),
(126159, 0, 1, 'Thank you! I was nearly a goner.', 12, 0, 100, 5, 0, 0, 154072, 0, 'Frightened Woodsman to Player'),
(126159, 0, 2, 'They nearly had me there. Thank you, $c.', 12, 0, 100, 5, 0, 0, 154056, 0, 'Frightened Woodsman to Player'),
(126159, 0, 3, 'I\'m saved! I was about a moment away from being monster food!', 12, 0, 100, 4, 0, 0, 154070, 0, 'Frightened Woodsman to Player');

-- Spawntracking
DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (1363899 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1619983 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1363901 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1363912 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1362549 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1363904 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1619984 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1363908 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1619982 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1363902 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 1619981 /*Map: 1643 (Kul Tiras) - Phase: 0*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(1363899, 1643, 0, 0, 0, 63163), -- Map: 1643 (Kul Tiras) - Phase: 0
(1619983, 1643, 0, 0, 0, 63163), -- Map: 1643 (Kul Tiras) - Phase: 0
(1363901, 1643, 0, 0, 0, 63163), -- Map: 1643 (Kul Tiras) - Phase: 0
(1363912, 1643, 0, 0, 0, 63163), -- Map: 1643 (Kul Tiras) - Phase: 0
(1362549, 1643, 0, 0, 0, 63163), -- Map: 1643 (Kul Tiras) - Phase: 0
(1363904, 1643, 0, 0, 0, 63163), -- Map: 1643 (Kul Tiras) - Phase: 0
(1619984, 1643, 0, 0, 0, 63163), -- Map: 1643 (Kul Tiras) - Phase: 0
(1363908, 1643, 0, 0, 0, 63163), -- Map: 1643 (Kul Tiras) - Phase: 0
(1619982, 1643, 0, 0, 0, 63163), -- Map: 1643 (Kul Tiras) - Phase: 0
(1363902, 1643, 0, 0, 0, 63163), -- Map: 1643 (Kul Tiras) - Phase: 0
(1619981, 1643, 0, 0, 0, 63163); -- Map: 1643 (Kul Tiras) - Phase: 0

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId` IN (1363899,1619983,1363901,1363912,1362549,1363904,1619984,1363908,1619982,1363902,1619981) AND `QuestObjectiveId`=292396);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(1363899, 292396, 63163),
(1619983, 292396, 63163),
(1363901, 292396, 63163),
(1363912, 292396, 63163),
(1362549, 292396, 63163),
(1363904, 292396, 63163),
(1619984, 292396, 63163),
(1363908, 292396, 63163),
(1619982, 292396, 63163),
(1363902, 292396, 63163),
(1619981, 292396, 63163);

DELETE FROM `spawn_tracking` WHERE (`SpawnType`=0 AND `SpawnId` IN (@CGUID+0,@CGUID+1,@CGUID+2,@CGUID+3,@CGUID+4,@CGUID+5,@CGUID+6,@CGUID+7,@CGUID+8,@CGUID+9,@CGUID+10));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveIds`) VALUES
(1363899, 0, @CGUID+0, 292396), -- Frightened Woodsman
(1619983, 0, @CGUID+1, 292396), -- Frightened Woodsman
(1363901, 0, @CGUID+2, 292396), -- Frightened Woodsman
(1363912, 0, @CGUID+3, 292396), -- Frightened Woodsman
(1362549, 0, @CGUID+4, 292396), -- Frightened Woodsman
(1363904, 0, @CGUID+5, 292396), -- Frightened Woodsman
(1619984, 0, @CGUID+6, 292396), -- Frightened Woodsman
(1363908, 0, @CGUID+7, 292396), -- Frightened Woodsman
(1619982, 0, @CGUID+8, 292396), -- Frightened Woodsman
(1363902, 0, @CGUID+9, 292396), -- Frightened Woodsman
(1619981, 0, @CGUID+10, 292396); -- Frightened Woodsman

DELETE FROM `spawn_tracking_state` WHERE `SpawnId` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(0, @CGUID+0, 0, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+0, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+0, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+1, 0, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+1, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+1, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+2, 0, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+2, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+2, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+3, 0, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+3, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+3, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+4, 0, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+4, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+4, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+5, 0, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+5, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+5, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+6, 0, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+6, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+6, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+7, 0, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+7, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+7, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+8, 0, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+8, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+8, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+9, 0, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+9, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+9, 2, 0, NULL, NULL, NULL, NULL),
(0, @CGUID+10, 0, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+10, 1, 1, NULL, NULL, NULL, NULL),
(0, @CGUID+10, 2, 0, NULL, NULL, NULL, NULL);

-- Evelyn Pare smart ai
SET @ENTRY := 126310;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 48518, 0, 0, 0, 0, 143, 5863, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Save Who We Can (48518) - Player who accepted quest: Start conversation 5863', '');

-- Path for Frightened Woodsman
SET @ENTRY := 126159;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Frightened Woodsman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -969.791, 1278.125, 1.3469634, NULL, 0),
(@PATH, 1, -972.8301, 1275.5273, 1.1665344, NULL, 0),
(@PATH, 2, -976.6289, 1272.2803, 1.4329594, NULL, 0),
(@PATH, 3, -977.3887, 1271.6309, 1.6070671, NULL, 0),
(@PATH, 4, -979.66797, 1269.6826, 1.8994806, NULL, 0),
(@PATH, 5, -980.6876, 1268.8074, 2.0000606, NULL, 0),
(@PATH, 6, -986.21094, 1273.1006, 1.5898918, NULL, 0),
(@PATH, 7, -987.78906, 1274.3271, 1.3433032, NULL, 0),
(@PATH, 8, -994.8906, 1279.8467, 1.6060011, NULL, 0),
(@PATH, 9, -998.0469, 1282.2998, 1.7906227, NULL, 0),
(@PATH, 10, -1000.1879, 1283.9546, 1.9120281, NULL, 0),
(@PATH, 11, -1013.5414, 1289.6835, 3.4760714, NULL, 0),
(@PATH, 12, -1040.5806, 1284.9609, 6.7520065, NULL, 0),
(@PATH, 13, -1044.57, 1284.83, 6.95331, NULL, 0);

-- Path for Frightened Woodsman
SET @ENTRY := 126159;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Frightened Woodsman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -964.63824, 1245.8508, 3.738105, NULL, 0),
(@PATH, 1, -980.1768, 1269.9199, 1.8758667, NULL, 0),
(@PATH, 2, -999.74457, 1284.7217, 1.8891238, NULL, 0),
(@PATH, 3, -1013.4349, 1290.5631, 3.3870773, NULL, 0),
(@PATH, 4, -1040.7367, 1285.9338, 6.6907015, NULL, 0),
(@PATH, 5, -1044.57, 1284.83, 6.95331, NULL, 0);

-- Path for Frightened Woodsman
SET @ENTRY := 126159;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Frightened Woodsman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1049.3052, 1206.8124, 5.3364353, NULL, 0),
(@PATH, 1, -1044.4297, 1232.3555, 4.790239, NULL, 0),
(@PATH, 2, -1027.6222, 1254.0756, 2.3303928, NULL, 0),
(@PATH, 3, -1037.4901, 1271.7511, 5.382873, NULL, 0),
(@PATH, 4, -1042.162, 1279.1566, 6.9152584, NULL, 0),
(@PATH, 5, -1027.9238, 1253.7129, 2.3645225, NULL, 0),
(@PATH, 6, -1027.6222, 1254.0756, 2.3303928, NULL, 0),
(@PATH, 7, -1029.0879, 1256.6943, 2.1073968, NULL, 0),
(@PATH, 8, -1030.0645, 1258.4404, 1.9199958, NULL, 0),
(@PATH, 9, -1032.9941, 1263.6787, 2.207642, NULL, 0),
(@PATH, 10, -1033.4824, 1264.5518, 2.5975335, NULL, 0),
(@PATH, 11, -1034.459, 1266.2979, 3.1771655, NULL, 0),
(@PATH, 12, -1034.9473, 1267.1709, 3.4289753, NULL, 0),
(@PATH, 13, -1035.4355, 1268.044, 4.0329213, NULL, 0),
(@PATH, 14, -1036.9004, 1270.6631, 4.9303966, NULL, 0),
(@PATH, 15, -1037.3887, 1271.5361, 5.1832595, NULL, 0),
(@PATH, 16, -1037.4901, 1271.7511, 5.382873, NULL, 0),
(@PATH, 17, -1038.4707, 1272.1182, 5.6318088, NULL, 0),
(@PATH, 18, -1039.4414, 1272.3613, 5.9032006, NULL, 0),
(@PATH, 19, -1039.584, 1272.3965, 6.1437073, NULL, 0),
(@PATH, 20, -1040.625, 1272.917, 6.258568, NULL, 0),
(@PATH, 21, -1042.6211, 1273.1455, 7.579245, NULL, 0),
(@PATH, 22, -1042.796, 1273.3705, 7.6373496, NULL, 0),
(@PATH, 23, -1043.0153, 1273.6525, 7.6283073, NULL, 0),
(@PATH, 24, -1043.2285, 1274.4785, 6.695917, NULL, 0),
(@PATH, 25, -1042.7832, 1276.4277, 6.875457, NULL, 0),
(@PATH, 26, -1042.162, 1279.1566, 6.9152584, NULL, 0),
(@PATH, 27, -1039.9999, 1282.9305, 6.7596445, NULL, 0),
(@PATH, 28, -1041.8477, 1283.6982, 6.9723234, NULL, 0),
(@PATH, 29, -1044.57, 1284.83, 6.95331, NULL, 0);

-- Path for Frightened Woodsman
SET @ENTRY := 126159;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Frightened Woodsman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1048.6033, 1208.0197, 5.3196874, NULL, 0),
(@PATH, 1, -1045.2667, 1232.832, 4.7974887, NULL, 0),
(@PATH, 2, -1028.538, 1254.1411, 2.3448055, NULL, 0),
(@PATH, 3, -1038.2815, 1271.2854, 5.4993534, NULL, 0),
(@PATH, 4, -1043.0779, 1279.0919, 7.004792, NULL, 0),
(@PATH, 5, -1040.9592, 1283.3276, 6.897245, NULL, 0),
(@PATH, 6, -1044.57, 1284.83, 6.95331, NULL, 0);

-- Path for Frightened Woodsman
SET @ENTRY := 126159;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Frightened Woodsman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -977.3529, 1272.5326, 1.4482864, NULL, 0),
(@PATH, 1, -997.8193, 1288.0524, 1.7287827, NULL, 0),
(@PATH, 2, -1012.97235, 1294.3823, 2.998228, NULL, 0),
(@PATH, 3, -1041.4216, 1290.2023, 6.4584484, NULL, 0),
(@PATH, 4, -1044.57, 1284.83, 6.95331, NULL, 0);

-- Path for Frightened Woodsman
SET @ENTRY := 126159;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Frightened Woodsman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1048.7517, 1234.2654, 4.781578, NULL, 0),
(@PATH, 1, -1032.2965, 1254.4102, 2.4188404, NULL, 0),
(@PATH, 2, -1044.9551, 1238.9121, 4.3776727, NULL, 0),
(@PATH, 3, -1043.6895, 1240.4609, 4.1836085, NULL, 0),
(@PATH, 4, -1042.4238, 1242.0098, 3.9224558, NULL, 0),
(@PATH, 5, -1041.1582, 1243.5586, 3.7537775, NULL, 0),
(@PATH, 6, -1039.8926, 1245.1074, 3.4807348, NULL, 0),
(@PATH, 7, -1037.9941, 1247.4307, 3.1914978, NULL, 0),
(@PATH, 8, -1036.7285, 1248.9795, 2.9467397, NULL, 0),
(@PATH, 9, -1034.8301, 1251.3027, 2.7184575, NULL, 0),
(@PATH, 10, -1032.9316, 1253.626, 2.4942486, NULL, 0),
(@PATH, 11, -1032.2965, 1254.4102, 2.4188404, NULL, 0),
(@PATH, 12, -1033.7266, 1257.0469, 2.203743, NULL, 0),
(@PATH, 13, -1035.6328, 1260.5625, 2.538701, NULL, 0),
(@PATH, 14, -1036.5859, 1262.3203, 2.8818967, NULL, 0),
(@PATH, 15, -1037.5391, 1264.0781, 3.5358105, NULL, 0),
(@PATH, 16, -1038.4922, 1265.8359, 4.0190353, NULL, 0),
(@PATH, 17, -1038.9688, 1266.7148, 4.5478325, NULL, 0),
(@PATH, 18, -1039.9219, 1268.4727, 5.09605, NULL, 0),
(@PATH, 19, -1040.3984, 1269.3516, 5.3848205, NULL, 0),
(@PATH, 20, -1040.625, 1269.792, 5.65326, NULL, 0),
(@PATH, 21, -1040.1035, 1269.792, 5.3848205, NULL, 0),
(@PATH, 22, -1040.4316, 1271.7646, 5.9341555, NULL, 0),
(@PATH, 23, -1040.625, 1272.917, 6.258568, NULL, 0),
(@PATH, 24, -1042.6211, 1273.1455, 7.579245, NULL, 0),
(@PATH, 25, -1042.8125, 1273.2467, 7.649857, NULL, 0),
(@PATH, 26, -1043.3792, 1273.5461, 7.6655216, NULL, 0),
(@PATH, 27, -1044.2715, 1274.4785, 6.888114, NULL, 0),
(@PATH, 28, -1045.2871, 1276.2012, 7.2165403, NULL, 0),
(@PATH, 29, -1046.8367, 1278.8262, 7.2945046, NULL, 0);

-- Path for Frightened Woodsman
SET @ENTRY := 126159;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Frightened Woodsman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1038.0818, 1271.403, 5.4770575, NULL, 0),
(@PATH, 1, -1042.8467, 1279.1083, 6.982142, NULL, 0),
(@PATH, 2, -1040.7126, 1283.2256, 6.861896, NULL, 0),
(@PATH, 3, -1044.57, 1284.83, 6.95331, NULL, 0);

-- Path for Frightened Woodsman
SET @ENTRY := 126159;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Frightened Woodsman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -962.11285, 1248.0154, 3.3333268, NULL, 0),
(@PATH, 1, -977.49506, 1272.4011, 1.4705961, NULL, 0),
(@PATH, 2, -997.9162, 1287.8848, 1.7415571, NULL, 0),
(@PATH, 3, -1012.9956, 1294.1901, 3.0172763, NULL, 0),
(@PATH, 4, -1041.3871, 1289.9874, 6.471616, NULL, 0),
(@PATH, 5, -1044.57, 1284.83, 6.95331, NULL, 0);

-- Path for Frightened Woodsman
SET @ENTRY := 126159;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Frightened Woodsman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -984.75977, 1206.4805, 5.1149945, NULL, 0),
(@PATH, 1, -964.5982, 1226.8022, 4.9384475, NULL, 0),
(@PATH, 2, -961.0319, 1246.561, 3.4785063, NULL, 0),
(@PATH, 3, -977.4789, 1272.416, 1.468004, NULL, 0),
(@PATH, 4, -997.90515, 1287.9039, 1.7400118, NULL, 0),
(@PATH, 5, -1012.993, 1294.212, 3.0148344, NULL, 0),
(@PATH, 6, -1041.3895, 1290.0027, 6.4705744, NULL, 0),
(@PATH, 7, -1044.57, 1284.83, 6.95331, NULL, 0);

-- Path for Frightened Woodsman
SET @ENTRY := 126159;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Frightened Woodsman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -984.2826, 1206.4985, 5.167493, NULL, 0),
(@PATH, 1, -964.1338, 1226.564, 4.992367, NULL, 0),
(@PATH, 2, -960.5198, 1246.6619, 3.442301, NULL, 0),
(@PATH, 3, -977.0957, 1272.7705, 1.4076643, NULL, 0),
(@PATH, 4, -997.6439, 1288.3558, 1.7058196, NULL, 0),
(@PATH, 5, -1012.93024, 1294.7302, 2.9641085, NULL, 0),
(@PATH, 6, -1041.484, 1290.5911, 6.434307, NULL, 0),
(@PATH, 7, -1044.57, 1284.83, 6.95331, NULL, 0);

-- Path for Frightened Woodsman
SET @ENTRY := 126159;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Frightened Woodsman - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -986.8489, 1206.5679, 5.1028304, NULL, 0),
(@PATH, 1, -966.4178, 1227.7361, 4.7504907, NULL, 0),
(@PATH, 2, -963.0386, 1246.1659, 3.6307645, NULL, 0),
(@PATH, 3, -978.9801, 1271.0271, 1.7044792, NULL, 0),
(@PATH, 4, -998.92865, 1286.1332, 1.8381066, NULL, 0),
(@PATH, 5, -1013.23883, 1292.1816, 3.2135684, NULL, 0),
(@PATH, 6, -1040.9102, 1287.752, 6.597714, NULL, 0),
(@PATH, 7, -1044.57, 1284.83, 6.95331, NULL, 0);
