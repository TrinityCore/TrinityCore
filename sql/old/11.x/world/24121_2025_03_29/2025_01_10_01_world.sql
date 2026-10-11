SET @CGUID := 6001072;
SET @OGUID := 6000630;

SET @ATID := 100;
SET @ATCP := 91;
SET @ATIDSPAWN := 104;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 130877, 530, 3433, 3495, '0', 10150, 0, 0, 0, 7830.33447265625, -7911.44287109375, 308.315216064453125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238); -- Rift to Telogrus (Area: Dawnstar Spire - Difficulty: 0) CreateObject1

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 279718, 0, 1519, 9171, '0', 10060, 0, -8149.23779296875, 812.22052001953125, 75.71726226806640625, 0.394130438566207885, 0, 0, 0.195792198181152343, 0.980645418167114257, 120, 255, 1, 58238), -- Rift to Ghostlands (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@OGUID+1, 278922, 530, 3433, 3494, '0', 0, 0, 7508.3603515625, -6393.01904296875, 15.42928028106689453, 0.981136858463287353, -0.02092409133911132, 0.053134918212890625, 0.470028877258300781, 0.880801737308502197, 120, 255, 1, 58238), -- Umbric's Notes - Sanctum of the Moon (Area: Sanctum of the Moon - Difficulty: 0) CreateObject1
(@OGUID+2, 278923, 530, 3433, 0, '0', 0, 0, 7057.40966796875, -6829.95849609375, 45.56482315063476562, 5.83130502700805664, 0, 0, -0.22402286529541015, 0.974583923816680908, 120, 255, 1, 58238), -- Umbric's Notes - Andilien Estate (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+3, 280641, 530, 3433, 3495, '0', 0, 0, 7833.65185546875, -7911.33349609375, 309.379150390625, 0.054047487676143646, 0, 0, 0.027020454406738281, 0.999634861946105957, 120, 255, 1, 58238), -- Umbric's Notes - Dawnstar Spire (Area: Dawnstar Spire - Difficulty: 0) CreateObject1
(@OGUID+4, 278905, 530, 3433, 3495, '0', 0, 0, 7859.0302734375, -7911.01220703125, 302.77655029296875, 5.486337661743164062, 0, 0, -0.38796615600585937, 0.92167365550994873, 120, 255, 1, 58238), -- Wide Hang Banner (Area: Dawnstar Spire - Difficulty: 0) CreateObject1
(@OGUID+5, 278906, 530, 3433, 3495, '0', 0, 0, 7830.22119140625, -7916.8125, 321.38629150390625, 3.148900747299194335, 0, 0, -0.99999332427978515, 0.003653962397947907, 120, 255, 1, 58238), -- Collector Tubes (Area: Dawnstar Spire - Difficulty: 0) CreateObject1
(@OGUID+6, 278910, 530, 3433, 3495, '0', 0, 0, 7804.5244140625, -7911.955078125, 314.375213623046875, 0, 0, 0, 0, 1, 120, 255, 1, 58238), -- Amethyst Crystal (Area: Dawnstar Spire - Difficulty: 0) CreateObject1
(@OGUID+7, 278904, 530, 3433, 3495, '0', 0, 0, 7830.74462890625, -7911.31787109375, 305.020904541015625, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 58238), -- DR Cable Wide (Area: Dawnstar Spire - Difficulty: 0) CreateObject1
(@OGUID+8, 278903, 530, 3433, 3495, '0', 0, 0, 7811.58935546875, -7911.61962890625, 315.26312255859375, 0.06784212589263916, -0.99942445755004882, -0.03391456604003906, 0, 0, 120, 255, 1, 58238), -- DR Cable Medium (Area: Dawnstar Spire - Difficulty: 0) CreateObject1
(@OGUID+9, 278908, 530, 3433, 3495, '0', 0, 0, 7822.99462890625, -7899.52783203125, 293.559478759765625, 0.618866205215454101, 0, 0, 0.304518699645996093, 0.95250636339187622, 120, 255, 1, 58238), -- Collector Tubes Short (Area: Dawnstar Spire - Difficulty: 0) CreateObject1
(@OGUID+10, 278903, 530, 3433, 3495, '0', 0, 0, 7873.8681640625, -7911.6005859375, 183.6184234619140625, 0.080261766910552978, -0.99919462203979492, -0.04012012481689453, 0, 0, 120, 255, 1, 58238), -- DR Cable Medium (Area: Dawnstar Spire - Difficulty: 0) CreateObject1
(@OGUID+11, 278908, 530, 3433, 3495, '0', 0, 0, 7831.77001953125, -7913.19091796875, 294.934906005859375, 0.533721089363098144, -0.68207740783691406, -0.18646717071533203, 0.186467170715332031, 0.682078003883361816, 120, 255, 1, 58238), -- Collector Tubes Short (Area: Dawnstar Spire - Difficulty: 0) CreateObject1
(@OGUID+12, 279040, 530, 3433, 3495, '0', 0, 0, 7864.43408203125, -7911.595703125, 291.763946533203125, 1.57537853717803955, 0, 0, 0.7087249755859375, 0.705484867095947265, 120, 255, 1, 58238), -- Teleportation Console (Area: Dawnstar Spire - Difficulty: 0) CreateObject1
(@OGUID+13, 278911, 530, 3433, 3495, '0', 0, 0, 7883.345703125, -7911.66845703125, 182.803192138671875, 1.57537853717803955, 0, 0, 0.7087249755859375, 0.705484867095947265, 120, 255, 1, 58238), -- Teleportation Console (Area: Dawnstar Spire - Difficulty: 0) CreateObject1
(@OGUID+14, 278905, 530, 3433, 3495, '0', 0, 0, 7860.31591796875, -7911.017578125, 302.466705322265625, 3.855569362640380859, 0, 0, -0.93695354461669921, 0.349453926086425781, 120, 255, 1, 58238); -- Wide Hang Banner (Area: Dawnstar Spire - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (279718, 278922, 278923, 280641, 278908, 278903, 278904, 278910, 278906, 278905);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(279718, 0, 0x20, 0, 0), -- Rift to Ghostlands
(278922, 0, 0x40000, 0, 0), -- Umbric's Notes - Sanctum of the Moon
(278923, 0, 0x40000, 0, 0), -- Umbric's Notes - Andilien Estate
(280641, 0, 0x40000, 0, 0), -- Umbric's Notes - Dawnstar Spire
(278908, 0, 0x2000, 0, 0), -- Collector Tubes Short
(278903, 0, 0x2000, 0, 0), -- DR Cable Medium
(278904, 0, 0x2000, 0, 0), -- DR Cable Wide
(278910, 0, 0x2000, 0, 0), -- Amethyst Crystal
(278906, 0, 0x2000, 0, 0), -- Collector Tubes
(278905, 0, 0x2000, 0, 0); -- Wide Hang Banner

DELETE FROM `creature_template_addon` WHERE `entry` = 130919; -- 130919 (High Elf Ranger)
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(130919, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, ''); -- 130919 (High Elf Ranger)

-- Template
UPDATE `creature_template` SET `faction`=1665, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=130919; -- High Elf Ranger
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x41000000 WHERE `entry`=130877; -- Rift to Telogrus

DELETE FROM `gameobject_template` WHERE `entry` IN (279718,278922,278923,280641,278906,279040,278910,278903,278904,278911,278905,278908);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(279718, 22, 42710, 'Rift to Ghostlands', '', '', '', 0.150000005960464477, 259553, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 58238), -- Rift to Ghostlands
(278922, 10, 15260, 'Umbric\'s Notes - Sanctum of the Moon', 'questinteract', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 7489, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 700, 58238), -- Umbric's Notes - Sanctum of the Moon
(278923, 10, 18306, 'Umbric\'s Notes - Andilien Estate', 'questinteract', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 7490, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 700, 58238), -- Umbric's Notes - Andilien Estate
(280641, 10, 22454, 'Umbric\'s Notes - Dawnstar Spire', 'questinteract', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 7512, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 700, 58238), -- Umbric's Notes - Dawnstar Spire
(278906, 5, 46622, 'Collector Tubes', '', '', '', 0.119999997317790985, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 58238), -- Collector Tubes
(279040, 22, 7076, 'Teleportation Console', '', '', '', 0.150000005960464477, 258928, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 58238), -- Teleportation Console
(278910, 5, 25334, 'Amethyst Crystal', '', '', '', 0.150000005960464477, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 58238), -- Amethyst Crystal
(278903, 5, 46619, 'DR Cable Medium', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 58238), -- DR Cable Medium
(278904, 5, 46620, 'DR Cable Wide', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 58238), -- DR Cable Wide
(278911, 22, 7076, 'Teleportation Console', '', '', '', 0.150000005960464477, 258927, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 58238), -- Teleportation Console
(278905, 5, 46621, 'Wide Hang Banner', '', '', '', 0.059999998658895492, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 58238), -- Wide Hang Banner
(278908, 5, 24812, 'Collector Tubes Short', '', '', '', 0.109999999403953552, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 58238); -- Collector Tubes Short

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=293, `StaticFlags1`=0x10000000, `StaticFlags3`=0x40000, `VerifiedBuild`=58238 WHERE (`Entry`=130919 AND `DifficultyID`=0); -- 130919 (High Elf Ranger) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=293, `StaticFlags1`=0x20000100, `VerifiedBuild`=58238 WHERE (`Entry`=130877 AND `DifficultyID`=0); -- 130877 (Rift to Telogrus) - Sessile, Floating

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1) OR (`Id` = @ATID+1 AND `IsCustom` = 1) OR (`Id` = @ATID+2 AND `IsCustom` = 1) OR (`Id` = @ATID+3 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0),
(@ATID+1, 1, 1, 0),
(@ATID+2, 1, 1, 0),
(@ATID+3, 1, 1, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1) OR (`Id`= @ATCP+1 AND `IsCustom`=1) OR (`Id`= @ATCP+2 AND `IsCustom`=1) OR (`Id`= @ATCP+3 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `Speed`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 14, 14, 0, 0, 0, 0, 0, 0, '', 0),
(@ATCP+1, 1, @ATID+1, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 13, 13, 0, 0, 0, 0, 0, 0, '', 0),
(@ATCP+2, 1, @ATID+2, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 28, 28, 0, 0, 0, 0, 0, 0, '', 0),
(@ATCP+3, 1, @ATID+3, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 12, 12, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+3;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 530, '0', 7517.829, -6384.978, 13.0925, 5.450139, 0, 0, 0, 'at_ghostlands_sanctum_of_the_moon_conversation', 'Ghostlands - Sanctum of the Moon - Trigger Conversation for Alleria (Quest: The Ghostlands)', 0),
(@ATIDSPAWN+1, @ATCP+1, 1, 530, '0', 7046.617, -6828.122, 44.6459, 2.817104, 0, 0, 0, 'at_ghostlands_andilien_estate_conversation', 'Ghostlands - Andilien Estate - Trigger Conversation for Alleria (Quest: The Ghostlands)', 0),
(@ATIDSPAWN+2, @ATCP+2, 1, 530, '0', 7830.174, -7911.672, 170.160, 1.551373, 0, 0, 0, 'at_ghostlands_dawnspair_spire_conversation', 'Ghostlands - Dawnspair Spire - Trigger Conversation for Alleria (Quest: The Ghostlands)', 0),
(@ATIDSPAWN+3, @ATCP+3, 1, 530, '0', 7860.084, -7911.698, 291.755, 3.145629, 0, 0, 0, 'at_ghostlands_dawnspair_spire_second_floor_conversation', 'Ghostlands - Dawnspair Spire second floor - Trigger Conversation for Alleria (Quest: The Ghostlands)', 0);

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=130919 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(130919, 1, 0, 0, 0, 0, 0, 0, 128828, 0, 0, 58238); -- High Elf Ranger

-- Summoned data
DELETE FROM `creature_summoned_data` WHERE `CreatureID` = 130919;
INSERT INTO `creature_summoned_data` (`CreatureID`, `CreatureIDVisibleToSummoner`, `GroundMountDisplayID`, `FlyingMountDisplayID`, `DespawnOnQuestsRemoved`) VALUES
(130919, 126302, 81648, 81648, '49787');

-- Objective completion effect
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (295331, 295332, 295333, 295347);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(295331, NULL, NULL, 6468, 0, 0),
(295332, NULL, NULL, 6478, 0, 0),
(295333, NULL, NULL, 6635, 0, 0),
(295347, NULL, NULL, 6636, 0, 0);

-- SpellArea
DELETE FROM `spell_area` WHERE `spell` = 258930 AND `area` = 3433;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(258930, 3433, 49787, 48962, 0, 0, 2, 3, 74, 11); -- Summon Alleria

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 130877;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(130877, 250798, 1, 0);

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (6468, 6634, 6478, 6467, 6469, 6479, 6635, 6470, 6637, 6471, 6636);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(6468, 15107, 0, 58238),
(6634, 15111, 0, 58238),
(6478, 15115, 5126, 58238),
(6467, 14641, 0, 58238),
(6469, 14643, 0, 58238),
(6479, 15123, 0, 58238),
(6635, 15119, 5126, 58238),
(6470, 14644, 0, 58238),
(6637, 15130, 0, 58238),
(6471, 15129, 0, 58238),
(6636, 15124, 5126, 58238);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_high_elf_ranger_to_ghostlands' WHERE `Id` IN (6468, 6467, 6634, 6479, 6469, 6470, 6471, 6637);
UPDATE `conversation_template` SET `ScriptName` = 'conversation_sanctum_of_the_moon_to_ghostlands' WHERE `Id` = 6478;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_andilien_estate_to_ghostlands' WHERE `Id` = 6635;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_dawnspair_spire_to_ghostlands' WHERE `Id` = 6636;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_dawnspair_spire_followup_to_ghostlands' WHERE `Id` = 6471;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=6468 AND `Idx`=0) OR (`Idx`=0 AND `ConversationId` IN (6634,6467,6478)) OR (`Idx`=1 AND `ConversationId`=6478) OR (`ConversationId`=6469 AND `Idx`=0) OR (`ConversationId`=6479 AND `Idx`=0) OR (`ConversationId`=6635 AND `Idx` IN (1,0)) OR (`ConversationId`=6470 AND `Idx`=0) OR (`ConversationId`=6637 AND `Idx`=0) OR (`Idx`=0 AND `ConversationId` IN (6636,6471));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(6468, 61831, 0, 0, 0, 0, 0, 58238), -- Full: 0x203AE842407FD9C000004500007AA07F Creature/0 R3770/S69 Map: 530 (Outland) Entry: 130919 (High Elf Ranger) Low: 8036479
(6634, 61831, 0, 0, 0, 0, 0, 58238), -- Full: 0x203AE842407FD9C000000100007AAD1D Creature/0 R3770/S1 Map: 530 (Outland) Entry: 130919 (High Elf Ranger) Low: 8039709
(6467, 61831, 0, 0, 0, 0, 0, 58238), -- Full: 0x203AE842407FD9C000000100007AAD1D Creature/0 R3770/S1 Map: 530 (Outland) Entry: 130919 (High Elf Ranger) Low: 8039709
(6478, 0, 1, 0, 0, 0, 1, 58238), -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775
(6478, 0, 0, 129767, 79013, 0, 0, 58238),
(6469, 61831, 0, 0, 0, 0, 0, 58238), -- Full: 0x203AE842407FD9C000000100007AD1DF Creature/0 R3770/S1 Map: 530 (Outland) Entry: 130919 (High Elf Ranger) Low: 8049119
(6479, 61831, 0, 0, 0, 0, 0, 58238), -- Full: 0x203AE842407FD9C000000100007AD79B Creature/0 R3770/S1 Map: 530 (Outland) Entry: 130919 (High Elf Ranger) Low: 8050587
(6635, 0, 1, 0, 0, 0, 1, 58238), -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775
(6635, 0, 0, 129767, 79013, 0, 0, 58238),
(6470, 61831, 0, 0, 0, 0, 0, 58238), -- Full: 0x203AE842407FD9C000000100007AE062 Creature/0 R3770/S1 Map: 530 (Outland) Entry: 130919 (High Elf Ranger) Low: 8052834
(6637, 0, 0, 0, 0, 0, 0, 58238), -- Full: 0x203AE842407FD9C000004500007AEC31 Creature/0 R3770/S69 Map: 530 (Outland) Entry: 130919 (High Elf Ranger) Low: 8055857
(6636, 0, 0, 129767, 79013, 0, 0, 58238),
(6471, 61831, 0, 0, 0, 0, 0, 58238); -- Full: 0x203AE842407FD9C000004500007AF9D2 Creature/0 R3770/S69 Map: 530 (Outland) Entry: 130919 (High Elf Ranger) Low: 8059346

DELETE FROM `conversation_line_template` WHERE `Id` IN (14642, 15107, 15111, 14641, 15118, 15117, 15116, 15115, 14643, 14655, 15123, 15122, 15121, 15120, 15119, 14644, 15130, 15126, 15125, 15124, 15129);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(14642, 0, 0, 0, 0, 58238),
(15107, 0, 0, 0, 0, 58238),
(15111, 0, 0, 0, 0, 58238),
(14641, 0, 0, 0, 0, 58238),
(15118, 0, 1, 1, 0, 58238),
(15117, 119, 0, 0, 0, 58238),
(15116, 119, 0, 0, 0, 58238),
(15115, 119, 0, 0, 0, 58238),
(14643, 0, 0, 0, 0, 58238),
(14655, 0, 0, 0, 0, 58238),
(15123, 0, 0, 0, 0, 58238),
(15122, 0, 1, 1, 0, 58238),
(15121, 119, 0, 0, 0, 58238),
(15120, 119, 0, 0, 0, 58238),
(15119, 119, 0, 0, 0, 58238),
(14644, 0, 0, 0, 0, 58238),
(15130, 0, 0, 0, 0, 58238),
(15126, 119, 0, 0, 0, 58238),
(15125, 119, 0, 0, 0, 58238),
(15124, 119, 0, 0, 0, 58238),
(15129, 0, 0, 0, 0, 58238);

-- Spell target
DELETE FROM `spell_target_position` WHERE (`ID`=259553 AND `EffectIndex`=0) OR (`ID`=258927 AND `EffectIndex`=0) OR (`ID`=258928 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(259553, 0, 530, 7929.7001953125, -6481.52001953125, 47.4199981689453125, 58238), -- Spell: 259553 (Teleport: Ghostlands) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(258927, 0, 530, 7856.580078125, -7911.47998046875, 291.709991455078125, 58238), -- Spell: 258927 (Teleport) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(258928, 0, 530, 7875.77001953125, -7911.6298828125, 182.8000030517578125, 58238); -- Spell: 258928 (Teleport) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (10060, 10061, 10150);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(10060, 'Cosmetic - See Rift to Ghostlands in Stormwind Embassy'),
(10061, 'Deprecated - See Alleria Windrunner in Stormwind Embassy'),
(10150, 'Cosmetic - See Rift to Telogrus at Dawnspair Spire');

DELETE FROM `phase_area` WHERE `PhaseId` IN (10060, 10061, 10150);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 10060, 'See Rift to Ghostlands in Stormwind Embassy'),
(1519, 10061, 'Deprecated - See Alleria Windrunner in Stormwind Embassy'),
(3433, 10150, 'See Rift to Telogrus at Dawnspair Spire');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (10060,10061,10150) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 10060, 0, 0, 0, 47, 0, 49787, 8, 0, 0, 'Apply Phase 10060 if Quest 49787 is taken'),
(26, 10061, 0, 0, 0, 47, 0, 49787, 2|8|64, 0, 1, 'Apply Phase 10061 if Quest 49787 is not taken | complete | rewarded'),
(26, 10150, 0, 0, 0, 47, 0, 49787, 2, 0, 0, 'Apply Phase 10060 if Quest 49787 is complete');

-- Spawntracking
DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (1426902, 1426903, 1437211);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(1426902, 530, 0, 0, 0, 58238),
(1426903, 530, 0, 0, 0, 58238),
(1437211, 530, 0, 0, 0, 58238);

DELETE FROM `spawn_tracking_quest_objective` WHERE `SpawnTrackingId` IN (1426902, 1426903, 1437211);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(1426902, 295332, 58238),
(1426903, 295333, 58238),
(1437211, 295347, 58238);

DELETE FROM `spawn_tracking` WHERE `SpawnTrackingId` IN (1426902, 1426903, 1437211);
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveId`) VALUES
(1426902, 1, @OGUID+1, 295332),
(1426903, 1, @OGUID+2, 295333),
(1437211, 1, @OGUID+3, 295347);

DELETE FROM `spawn_tracking_state` WHERE `SpawnId` IN (@OGUID+1, @OGUID+2, @OGUID+3);
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(1, @OGUID+1, 0, 0, NULL, NULL, NULL, ''),
(1, @OGUID+1, 1, 1, NULL, NULL, NULL, ''),
(1, @OGUID+2, 0, 0, NULL, NULL, NULL, ''),
(1, @OGUID+2, 1, 1, NULL, NULL, NULL, ''),
(1, @OGUID+3, 0, 0, NULL, NULL, NULL, ''),
(1, @OGUID+3, 1, 1, NULL, NULL, NULL, '');

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=124520;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(124520, 0.231532931327819824, 1, 0, 58238);

-- Page Text
DELETE FROM `page_text` WHERE `ID` IN (7489, 7490, 7512);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(7489, 'Our void experiments are proceeding well. I am certain we are on the cusp of a breakthrough... despite Rommath\'s small-minded protests.\n\nThe grand magister must understand that this power is crucial to the defense of Silvermoon. Never again shall the sin\'dorei fall prey to our enemies!\n\nUnfortunately, it seems our research has reached an impasse. I believe there is knowledge at the Andilien Estate that will springboard us forward.', 0, 0, 0, 58238), -- 7489
(7490, 'It seems we are not the first of our people seeking to harness the void. I have found notebooks belonging to one whose very name is a curse... Dar\'Khan Drathir.\n\nIt was Drathir\'s betrayal that allowed Arthas to corrupt the Sunwell... and left our kingdom in ruins. For the first time, I see why Rommath opposes our course of study.\n\nNevertheless, I believe this knowledge can be used for good. The bulk of Drathir\'s research was conducted at Dawnstar Spire. That is where we must go.', 0, 0, 0, 58238), -- 7490
(7512, 'Drathir\'s quest for power led him to seek the fragments of an ancient world, one teetering on the brink of the Void itself.\n\nHis notes said it existed within a rift in the very fabric of reality. He never found this place... but I have succeeded where he failed. The way will soon be open to us!\n\nDrathir believed this site held an ancient object of unspeakable might. Perhaps this will be the key that allows us to gain control over the shadows.', 0, 0, 0, 58238); -- 7512

-- Quest
DELETE FROM `creature_questender` WHERE (`id`=130919 AND `quest` = 49787);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(130919, 49787, 58238); -- The Ghostlands ended by High Elf Ranger

-- High Elf Ranger smart ai
SET @ENTRY := 130919;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 8, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.22216, 'On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Set orientation to 2.22216', ''),
(@ENTRY, 0, 1, 2, 34, 0, 100, 0, 8, 2, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.073804, 'On movement of type POINT_MOTION_TYPE inform, point 2 - Self: Set orientation to 2.073804', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 262272, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type POINT_MOTION_TYPE inform, point 2 - Self: Cast spell 262272 on self', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 82238, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On movement of type POINT_MOTION_TYPE inform, point 2 - Owner/Summoner: Cast spell 82238 on self', '');
