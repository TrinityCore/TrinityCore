SET @CGUID := 11000792;

SET @NPCTEXTID := 610029;

SET @ATID := 187;
SET @ATIDSPAWN := 288;
SET @ATCP := 178;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+15;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 237480, 2694, 15355, 15922, '0', 26037, 0, 0, 1, -177.72222900390625, -2148.786376953125, 1176.921142578125, 3.802503108978271484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Orweyna (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
(@CGUID+1, 237341, 2694, 15355, 15922, '0', 26039, 0, 0, 1, -174.458328247070312, -2152.739501953125, 1177.080810546875, 1.108461976051330566, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Halduron Brightwing (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
(@CGUID+2, 253881, 2694, 15355, 15922, '0', 0, 0, 0, 0, -155.763885498046875, -2126.873291015625, 1184.8408203125, 0.901937007904052734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Glimmering Petalwing (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+3, 237201, 2694, 15355, 15922, '0', 0, 0, 0, 0, -107.319442749023437, -2157.84375, 1176.3629150390625, 3.034853219985961914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Agitated Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+4, 237204, 2694, 15355, 15922, '0', 0, 0, 0, 0, -119.512153625488281, -2170.916748046875, 1179.9871826171875, 0.94222259521484375, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Surly Potatoad (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+5, 253881, 2694, 15355, 15922, '0', 0, 0, 0, 0, -134.28472900390625, -2106.890625, 1180.8634033203125, 1.17809605598449707, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Glimmering Petalwing (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+6, 253881, 2694, 15355, 15922, '0', 0, 0, 0, 0, -153.375, -2121.9775390625, 1189.88037109375, 4.399270534515380859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Glimmering Petalwing (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+7, 253881, 2694, 15355, 15922, '0', 0, 0, 0, 0, -109.328132629394531, -2134.5625, 1182.59912109375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Glimmering Petalwing (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+8, 237201, 2694, 15355, 15922, '0', 0, 0, 0, 0, -117.163192749023437, -2073.91845703125, 1157.8670654296875, 1.026018142700195312, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Agitated Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+9, 237201, 2694, 15355, 15922, '0', 0, 0, 0, 0, -104.163192749023437, -2080.5869140625, 1161.4210205078125, 3.034853219985961914, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Agitated Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+10, 237201, 2694, 15355, 15922, '0', 0, 0, 0, 0, -139.59722900390625, -2096.232666015625, 1161.884033203125, 2.760121345520019531, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Agitated Thorntalon (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+11, 253881, 2694, 15355, 15922, '0', 0, 0, 0, 0, -114.772567749023437, -2063.661376953125, 1173.1083984375, 1.267651915550231933, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Glimmering Petalwing (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+12, 237204, 2694, 15355, 15922, '0', 0, 0, 0, 0, -174.090286254882812, -2091.911376953125, 1160.0732421875, 0.206134051084518432, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 67314), -- Surly Potatoad (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+13, 253881, 2694, 15355, 15922, '0', 0, 0, 0, 0, -118.251739501953125, -2063.2587890625, 1174.060791015625, 1.277216315269470214, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Glimmering Petalwing (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+14, 253881, 2694, 15355, 15922, '0', 0, 0, 0, 0, -122.279518127441406, -2062.4150390625, 1171.206787109375, 4.144488334655761718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Glimmering Petalwing (Area: Amirdrassil Roots - Difficulty: 0) CreateObject2
(@CGUID+15, 246467, 2694, 15355, 15922, '0', 0, 0, 0, 0, -111.338539123535156, -2157.3994140625, 1176.3831787109375, 4.677419662475585937, 120, 0, 0, 0, NULL, NULL, 0x4000800 | 0x00000001, 0xC1000000 | 0x00002000, 67314); -- Potatoad (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+15;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 713, 0, 0, 0, 0, ''), -- Glimmering Petalwing
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Agitated Thorntalon
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 713, 0, 0, 0, 0, ''), -- Glimmering Petalwing
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 713, 0, 0, 0, 0, ''), -- Glimmering Petalwing
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 713, 0, 0, 0, 0, ''), -- Glimmering Petalwing
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 713, 0, 0, 0, 0, ''), -- Glimmering Petalwing
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 713, 0, 0, 0, 0, ''), -- Glimmering Petalwing
(@CGUID+15, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''); -- Potatoad

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE `Id`=@ATID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 2694, '0', -177.563126, -2150.783691, 1176.984863, 0.398269, 0, 26037, 0, 'SmartAreaTriggerAI', 'Harandar - Trigger Conversation 28825 for Orweyna/Halduron', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, '', 0); 

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 237341;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(237341, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, ''); -- 237341 (Halduron Brightwing)

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=237341; -- Halduron Brightwing
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=237480; -- Orweyna
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=253252; -- Spore-Covered Firefly
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=253251; -- Lashroom Bud
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=245958; -- Underroot Hatchling
UPDATE `creature_template` SET `faction`=14, `speed_run`=1.269841432571411132, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=237204; -- Surly Potatoad
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=249690; -- Root-darting Firefly
UPDATE `creature_template` SET `faction`=190, `speed_walk`=1.60000002384185791, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=248649; -- Fungal Strider
UPDATE `creature_template` SET `faction`=14, `speed_run`=1.269841432571411132, `BaseAttackTime`=2000, `unit_flags`=0x2000340, `unit_flags2`=0x4000800, `unit_flags3`=0xC1000000 WHERE `entry`=246467; -- Potatoad
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=256534; -- Spore-dusted Moth
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=237201; -- Agitated Thorntalon
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=253254; -- Underbrush Crawler
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=253881; -- Glimmering Petalwing
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=251982; -- Plodding Potadling

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3321, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=237480 AND `DifficultyID`=0); -- 237480 (Orweyna) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3313, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=237341 AND `DifficultyID`=0); -- 237341 (Halduron Brightwing) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=253252 AND `DifficultyID`=0); -- 253252 (Spore-Covered Firefly) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=253251 AND `DifficultyID`=0); -- 253251 (Lashroom Bud) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=245958 AND `DifficultyID`=0); -- 245958 (Underroot Hatchling) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=237204 AND `DifficultyID`=0); -- 237204 (Surly Potatoad) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x30000000, `VerifiedBuild`=67314 WHERE (`Entry`=249690 AND `DifficultyID`=0); -- 249690 (Root-darting Firefly) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3313, `VerifiedBuild`=67314 WHERE (`Entry`=248649 AND `DifficultyID`=0); -- 248649 (Fungal Strider) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x30000000, `VerifiedBuild`=67314 WHERE (`Entry`=256534 AND `DifficultyID`=0); -- 256534 (Spore-dusted Moth) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=237201 AND `DifficultyID`=0); -- 237201 (Agitated Thorntalon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=253254 AND `DifficultyID`=0); -- 253254 (Underbrush Crawler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=253881 AND `DifficultyID`=0); -- 253881 (Glimmering Petalwing) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=251982 AND `DifficultyID`=0); -- 251982 (Plodding Potadling) - CanSwim

-- Difficulty override
DELETE FROM `creature_static_flags_override` WHERE `SpawnId` = (@CGUID+5);
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
((@CGUID+5), 0, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (26037,26039);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(26037, 'Cosmetic - See Orweyna near the Cave at Amirdrassil Roots'),
(26039, 'Cosmetic - See Halduron near the Cave at Amirdrassil Roots');

DELETE FROM `phase_area` WHERE `PhaseId` IN (26037,26039);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15355, 26037, 'See Orweyna near the cave at Amirdrassil Roots'),
(15355, 26039, 'See Halduron near the cave at Amirdrassil Roots');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (26037,26039) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 26037, 0, 0, 0, 47, 0, 86899, 2|64, 0, 0, 'Apply Phase 26037 if Quest 86899 is complete|rewarded'),
(26, 26037, 0, 0, 0, 47, 0, 86900, 2|8|64, 0, 1, 'Apply Phase 26037 if Quest 86900 is not complete|in progress|rewarded'),
(26, 26039, 0, 0, 0, 47, 0, 86899, 2|64, 0, 0, 'Apply Phase 26039 if Quest 86899 is complete|rewarded'),
(26, 26039, 0, 0, 0, 47, 0, 86900, 2|8|64, 0, 1, 'Apply Phase 26039 if Quest 86900 is not complete|in progress|rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=28825;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(28825, 81685, 0, 67314);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=28825 AND `Idx` IN (0,1));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(28825, 105998, (@CGUID+0), 0, 0, 0, 0, 0, 67314), -- Full: 0x20423150C0E7EA00002B560000767BFE Creature/0 R4236/S11094 Map: 2694 (Harandar) Entry: 237480 (Orweyna) Low: 7764990
(28825, 106178, (@CGUID+1), 1, 0, 0, 0, 0, 67314); -- Full: 0x20423150C0E7C740002B560000767C04 Creature/0 R4236/S11094 Map: 2694 (Harandar) Entry: 237341 (Halduron Brightwing) Low: 7764996

DELETE FROM `conversation_line_template` WHERE `Id` IN (79613, 81660, 81685);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(79613, 0, 0, 0, 0, 67314),
(81660, 0, 1, 0, 0, 67314),
(81685, 0, 0, 0, 0, 67314);

-- Quest
DELETE FROM `quest_details` WHERE `ID`=86900;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(86900, 1, 0, 0, 0, 0, 0, 0, 0, 67314); -- To Har'athir

DELETE FROM `creature_queststarter` WHERE (`id`=237480 AND `quest`=86900);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(237480, 86900, 67314); -- To Har'athir offered by Orweyna

DELETE FROM `quest_template_addon` WHERE `ID` = 86900;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(86900, 0, 0, 0, 86899, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=237480 AND `MenuID`=39211) OR (`CreatureID`=237341 AND `MenuID`=38720);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(237480, 39211, 67314), -- Orweyna
(237341, 38720, 67314); -- Halduron Brightwing

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 286956, 0, 0, 0, 0, 0, 0, 0, 67314), -- 237341 (Halduron Brightwing)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 289846, 0, 0, 0, 0, 0, 0, 0, 67314), -- 237480 (Orweyna)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 289845, 0, 0, 0, 0, 0, 0, 0, 67314); -- 237480 (Orweyna)

DELETE FROM `gossip_menu` WHERE (`MenuID`=38720 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=39210 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=39211 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38720, @NPCTEXTID+0, 67314), -- 237341 (Halduron Brightwing)
(39210, @NPCTEXTID+1, 67314), -- 237480 (Orweyna)
(39211, @NPCTEXTID+2, 67314); -- 237480 (Orweyna)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (39211,39210));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(39211, 133757, 0, 0, 'Will your people welcome you?', 0, 0, 0, 39210, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 67314),
(39210, 138580, 0, 0, 'I would like to ask something else.', 0, 0, 0, 39211, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 67314);

-- Serverside Areatrigger SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ATID+0 AND `source_type`=12 AND `id`=0 AND `link`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ATID+0, 12, 0, 1, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 143, 28825, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On AreaTrigger enter - play Conversation to Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=@ATID+0 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @ATID+0, 1, 0, 0, 47, 0, 86899, 2|64, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when quest 86899 is complete|rewarded'),
(28, @ATID+0, 1, 0, 0, 47, 0, 86900, 2|8|64, 0, '', 1, 0, 0, '', 'Only trigger areatrigger when quest 86900 is not complete|in progress|rewarded');

-- Path for Glimmering Petalwing
SET @MOVERGUID := @CGUID+5;
SET @ENTRY := 253881;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1776, 'Glimmering Petalwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -128.42686, -2092.7485, 1180.8634, NULL, 0),
(@PATH, 1, -114.28473, -2086.8906, 1180.8634, NULL, 0),
(@PATH, 2, -100.14259, -2092.7485, 1180.8634, NULL, 0),
(@PATH, 3, -94.28473, -2106.8906, 1180.8634, NULL, 0),
(@PATH, 4, -100.14259, -2121.0327, 1180.8634, NULL, 0),
(@PATH, 5, -114.28473, -2126.8906, 1180.8634, NULL, 0),
(@PATH, 6, -128.42686, -2121.0327, 1180.8634, NULL, 0),
(@PATH, 7, -134.28473, -2106.8906, 1180.8634, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Glimmering Petalwing
