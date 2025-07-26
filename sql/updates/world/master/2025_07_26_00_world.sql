SET @CGUID := 6005878;
SET @SPAWNGROUP := 1268;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 116804, 1651, 8443, 8443, '23,2,8', '0', 0, 0, 0, -11140.375, -1886.9410400390625, 165.8487396240234375, 3.765622377395629882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Scene Actor (Area: Karazhan - Difficulty: Mythic) CreateObject2
(@CGUID+1, 115491, 1651, 8443, 8443, '23,2,8', '0', 0, 0, 0, -11168.97265625, -1911.078125, 165.8487548828125, 6.273388862609863281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Medivh (Area: Karazhan - Difficulty: Mythic) CreateObject2 (Auras: 229485 - Vision)
(@CGUID+2, 114462, 1651, 8443, 8443, '23,2,8', '0', 0, 0, 0, -11164.689453125, -1912.8975830078125, 165.8487396240234375, 1.612735271453857421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609); -- The Curator (Area: Karazhan - Difficulty: Mythic) CreateObject2 (Auras: 229609 - Vision)

UPDATE `creature_template` SET `ScriptName`='boss_the_curator_rtk' WHERE `entry`=114247;
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x80000, `AIName`='SmartAI' WHERE `entry`=114249; -- Volatile Energy
UPDATE `creature_template` SET `unit_flags3`=0x1000001 WHERE `entry`=116804; -- Scene Actor
UPDATE `creature_template` SET `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=114462; -- The Curator
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry` IN (116124, 115491); -- Medivh

DELETE FROM `creature_template_addon` WHERE `entry` IN (114462, 115491, 114249);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(114249, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '227268'), -- 114249 (Volatile Energy) - Volatile Energy Passive
(114462, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '229609'), -- 114462 (The Curator) - Vision
(115491, 0, 0, 0, 0, 0, 1, 0, 0, 4817, 0, 0, 4, '229485'); -- 115491 (Medivh) - Vision

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (114462,115491));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(114462, 23, 0, 0, 629, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 114462 (The Curator) - 
(115491, 23, 0, 0, 629, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609); -- 115491 (Medivh) - 

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=13.75, `CreatureDifficultyID`=119052, `TypeFlags`=0x4 WHERE (`Entry`=115491 AND `DifficultyID`=23); -- Medivh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=44, `ManaModifier`=20, `CreatureDifficultyID`=117838, `TypeFlags`=0x24 WHERE (`Entry`=114462 AND `DifficultyID`=23); -- The Curator
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `VerifiedBuild`=61609 WHERE (`Entry`=114249 AND `DifficultyID`=23); -- 114249 (Volatile Energy) - 

DELETE FROM `creature_summon_groups` WHERE `summonerId`=114247;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES
(114247, 0, 0, 116804, -11140.375, -1886.9410400390625, 165.8487396240234375, 3.765622377395629882, 8, 0, 'The Curator - Summon group on death'),
(114247, 0, 0, 114462, -11164.689453125, -1912.8975830078125, 165.8487396240234375, 1.612735271453857421, 8, 0, 'The Curator - Summon group on death'),
(114247, 0, 0, 115491, -11168.97265625, -1911.078125, 165.8487548828125, 6.273388862609863281, 8, 0, 'The Curator - Summon group on death');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_the_curator_rtk_summon_volatile_energy_selector', 'spell_the_curator_rtk_power_discharge_selector', 'spell_the_curator_rtk_arc_lightning_selector', 'spell_the_curator_rtk_static_charge_selector', 'spell_the_curator_rtk_overload');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(234416, 'spell_the_curator_rtk_summon_volatile_energy_selector'),
(227278, 'spell_the_curator_rtk_power_discharge_selector'),
(227269, 'spell_the_curator_rtk_arc_lightning_selector'),
(228735, 'spell_the_curator_rtk_static_charge_selector'),
(227256, 'spell_the_curator_rtk_overload');

-- Areatriggers
DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 8780);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(8780, 0, 12848, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 'at_the_curator_rtk_power_discharge', 61609); -- Spell: 227289 (Power Discharge)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` = 12848);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(12848, 0, 0, 61609);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (115491, 114462, 114247);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(115491, 0, 0, 'Now you\'re ready to oversee the tower\'s protection in my absence.', 12, 0, 100, 1, 0, 78197, 124000, 0, 'Medivh'),
(115491, 1, 0, 'Hmm, I must remember to shut you down from time to time. Overuse might cause you to become... erratic.', 12, 0, 100, 25, 0, 78198, 124002, 0, 'Medivh'),
(114462, 0, 0, 'Defense protocols activated.', 14, 0, 100, 0, 0, 78201, 124001, 0, 'Curator to Medivh'),
(114247, 0, 0, 'Welcome to the-- TERMINATE INTRUDERS!', 14, 0, 100, 0, 0, 77229, 123421, 0, 'The Curator'),
(114247, 0, 1, 'The Menagerie is for-- ERADICATE! ERADICATE!', 14, 0, 100, 0, 0, 77181, 123138, 0, 'The Curator'),
(114247, 1, 0, 'Countermeasures deployed.', 12, 0, 100, 0, 0, 77224, 123423, 0, 'The Curator'),
(114247, 1, 1, 'DETERRENT ACTIVATED!', 12, 0, 100, 0, 0, 77227, 123424, 0, 'The Curator'),
(114247, 2, 0, 'Overload in progress. Prepare for-- PURGE! PURGE! PURGE!', 12, 0, 100, 0, 0, 77183, 123140, 0, 'The Curator'),
(114247, 3, 0, 'EXTERMINATED!', 12, 0, 100, 0, 0, 77184, 123141, 0, 'The Curator'),
(114247, 3, 1, 'Attention guests: DIE! DIE! DIE!', 12, 0, 100, 0, 0, 77185, 123142, 0, 'The Curator'),
(114247, 4, 0, 'Curator is no longer op... er... ation... al.', 14, 0, 100, 0, 0, 77182, 123139, 0, 'The Curator'),
(114247, 4, 1, 'System... failure... im... mi... nent...', 14, 0, 100, 0, 0, 77228, 123422, 0, 'The Curator');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=114249 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(114249, 0, 0, 0, '', 0, 0, 100, 0, 0, 1000, 6000, 6000, 0, '', 85, 228735, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Volatile Energy - In combat (6 seconds) - Cast "Static Charge"');

-- Spawngroup
DELETE FROM `spawn_group` WHERE `groupId`=@SPAWNGROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP, 0, @CGUID+0),
(@SPAWNGROUP, 0, @CGUID+1),
(@SPAWNGROUP, 0, @CGUID+2);

DELETE FROM `spawn_group_template` WHERE `groupId`=@SPAWNGROUP;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP, 'Karazhan - The Curator outro', 4);
