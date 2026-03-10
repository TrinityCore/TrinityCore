SET @CGUID := 10006786;

SET @NPCTEXTID := 600115;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 238212, 2738, 15781, 15781, '0', 25628, 0, 0, 0, -805.576416015625, -79.5104141235351562, 545.0430908203125, 4.155874252319335937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Om'talad (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1
(@CGUID+1, 238209, 2738, 15336, 15792, '0', 0, 0, 0, 0, 1323.99658203125, -1040.07470703125, -97.0501251220703125, 3.866137981414794921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493); -- Cartel Om Custodian (Area: The Oasis - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=238209; -- Cartel Om Custodian
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=238212; -- Om'talad

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (238209,238212));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(238209, 0, 10, 1, 1, 317182, 0x0, 0, 0), -- Cartel Om Custodian
(238212, 0, 10, 1, 1, 317186, 0x0, 0, 0); -- Om'talad

UPDATE `creature_template_difficulty` SET `ContentTuningID`=3008, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=238209 AND `DifficultyID`=0); -- 238209 (Cartel Om Custodian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3008, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=238212 AND `DifficultyID`=0); -- 238212 (Om'talad) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 25628;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(25628, 'Cosmetic - See Om''talad in Tazavesh');

DELETE FROM `phase_area` WHERE `PhaseId` = 25628;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15781, 25628, 'See Om''talad in Tazavesh');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 25628 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 25628, 0, 0, 0, 47, 0, 87290, 64, 0, 1, 'Apply Phase 25628 if Quest 87290 is not rewarded');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`MenuID`=38091 AND `CreatureID`=238209);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(238209, 38091, 62493); -- Cartel Om Custodian

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 281558, 0, 0, 0, 0, 0, 0, 0, 62493); -- 238209 (Cartel Om Custodian)

DELETE FROM `gossip_menu` WHERE (`MenuID`=38091 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38091, @NPCTEXTID+0, 62493); -- 238209 (Cartel Om Custodian)

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=238209 AND `quest`=87337) OR (`id`=238212 AND `quest`=87290);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(238209, 87337, 62493), -- Custodian Duties offered by Cartel Om Custodian
(238212, 87290, 62493); -- The Oasis offered by Om'talad

DELETE FROM `creature_questender` WHERE (`id`=238209 AND `quest`=87290);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(238209, 87290, 62493); -- The Oasis ended by Cartel Om Custodian

DELETE FROM `quest_template_addon` WHERE `ID` = 87337;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(87337, 0, 0, 0, 87290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
