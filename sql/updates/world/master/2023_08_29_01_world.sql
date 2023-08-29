SET @CGUID := 5000015;

SET @ENTRY := 79316;
SET @PATH := @ENTRY * 100 + 0;

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 78558, 1265, 7025, 7037, '0', 3569, 0, 0, 1, 4066.50439453125, -2372.154541015625, 94.665191650390625, 1.596214056015014648, 120, 0, 0, 640000, 9573, 0, 0, 0, 50791), -- Archmage Khadgar (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@CGUID+1, 78553, 1265, 7025, 7041, '0', 3395, 0, 0, 1, 3956.76123046875, -2523.6806640625, 69.74970245361328125, 5.858800411224365234, 120, 0, 0, 4800000, 320750, 0, 0, 0, 50791), -- Thrall (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+2, 78569, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3931.802978515625, -2510.703125, 69.73077392578125, 4.66814422607421875, 120, 0, 0, 20000, 0, 0, 0, 0, 50791), -- Hansel Heavyhands (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+3, 78568, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3940.8994140625, -2510.875, 69.37921142578125, 5.61804819107055664, 120, 0, 0, 20000, 0, 0, 0, 0, 50791), -- Thaelin Darkanvil (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+4, 79315, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3943.55126953125, -2505.182373046875, 69.37921142578125, 5.88816070556640625, 120, 0, 0, 20000, 0, 0, 0, 0, 50791), -- Olin Umberhide (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+5, 78559, 1265, 7025, 7041, '0', 3394, 0, 0, 1, 3936.718017578125, -2505.223876953125, 69.73077392578125, 5.608281135559082031, 120, 0, 0, 640000, 9573, 0, 0, 0, 50791), -- Archmage Khadgar (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+6, 78556, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3936.046875, -2520.348876953125, 69.73077392578125, 3.980798721313476562, 120, 0, 0, 20000, 0, 0, 0, 0, 50791), -- Ariok (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+7, 79316, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3967.543, -2531.816, 66.32741, 0, 120, 0, 0, 20000, 1283, 2, 0, 0, 50791), -- Qiana Moonshadow (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 32356 - Cat Form, 132653 - Stealth)
(@CGUID+8, 79675, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3951.240478515625, -2501.229248046875, 69.73077392578125, 0.763182044029235839, 120, 0, 0, 400000, 0, 0, 0, 0, 50791), -- Lady Liadrin (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+9, 78430, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3936.319580078125, -2503.619873046875, 69.73077392578125, 5.626811981201171875, 120, 0, 0, 400000, 100, 0, 0, 0, 50791), -- Cordana Felsong (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+10, 78554, 1265, 7025, 7041, '0', 3396, 0, 0, 1, 3958.908935546875, -2520.145751953125, 69.7492828369140625, 5.844482421875, 120, 0, 0, 4800000, 128300, 0, 0, 0, 50791); -- Vindicator Maraad (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 165746 - Retribution Aura)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Archmage Khadgar
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Thrall
(@CGUID+3, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Thaelin Darkanvil
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 6411, 0, 0, 0, ''), -- Olin Umberhide
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 6413, 0, 0, 0, ''), -- Ariok
(@CGUID+7, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '32356 132653'), -- Qiana Moonshadow - 32356 - Cat Form, 132653 - Stealth
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Lady Liadrin
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, '165746'); -- Vindicator Maraad - 165746 - Retribution Aura

UPDATE `creature_template` SET `unit_flags2`=4196352 WHERE `entry`=78558; -- Archmage Khadgar
UPDATE `creature_template` SET `unit_flags3`=1048576 WHERE `entry`=78430; -- Cordana Felsong
UPDATE `creature_template` SET `unit_flags3`=1048576 WHERE `entry`=78553; -- Thrall
UPDATE `creature_template` SET `unit_flags3`=1048576 WHERE `entry`=78569; -- Hansel Heavyhands
UPDATE `creature_template` SET `unit_flags3`=1048576 WHERE `entry`=78568; -- Thaelin Darkanvil
UPDATE `creature_template` SET `unit_flags2`=51200 WHERE `entry`=78556; -- Ariok
UPDATE `creature_template` SET `unit_flags2`=51200 WHERE `entry`=79315; -- Olin Umberhide
UPDATE `creature_template` SET `unit_flags3`=9437184 WHERE `entry`=78554; -- Vindicator Maraad

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=79675 AND `MenuID`=16433) OR (`CreatureID`=79315 AND `MenuID`=16432) OR (`CreatureID`=78556 AND `MenuID`=16641) OR (`CreatureID`=78568 AND `MenuID`=16518) OR (`CreatureID`=79316 AND `MenuID`=16428);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(79675, 16433, 50791), -- Lady Liadrin
(79315, 16432, 50791), -- Olin Umberhide
(78556, 16641, 50791), -- Ariok
(78568, 16518, 50791), -- Thaelin Darkanvil
(79316, 16428, 50791); -- Qiana Moonshadow

DELETE FROM `npc_vendor` WHERE (`entry`=78568 AND `item`=120959 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=119324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=119022 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=117439 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=117442 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=117440 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=117568 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=117453 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=117437 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=117441 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=78568 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(78568, 17, 120959, 0, 0, 1, 0, 0, 50791), -- Pinchwhistle "Nitro Fuel"
(78568, 16, 119324, 0, 0, 1, 0, 0, 50791), -- Savage Remedy
(78568, 15, 119022, 0, 0, 1, 0, 0, 50791), -- Shadowmoon Sugar Pear Cider
(78568, 14, 117439, 0, 0, 1, 0, 0, 50791), -- "Da Bruisery" Hot & Wroth
(78568, 13, 117442, 0, 0, 1, 0, 0, 50791), -- Thunderbelly Mead
(78568, 12, 117440, 0, 0, 1, 0, 0, 50791), -- Peglegger's Porter
(78568, 11, 117568, 0, 0, 1, 0, 0, 50791), -- Jug of Ironwine
(78568, 10, 117453, 0, 0, 1, 0, 0, 50791), -- "Da Bruisery" OPA
(78568, 9, 117437, 0, 0, 1, 0, 0, 50791), -- Skyreach Sunrise
(78568, 8, 117441, 0, 0, 1, 0, 0, 50791), -- Elekk's Neck
(78568, 7, 3857, 0, 0, 1, 0, 0, 50791), -- Coal
(78568, 6, 18567, 0, 0, 1, 0, 0, 50791), -- Elemental Flux
(78568, 5, 3466, 0, 0, 1, 0, 0, 50791), -- Strong Flux
(78568, 4, 2880, 0, 0, 1, 0, 0, 50791), -- Weak Flux
(78568, 3, 180733, 0, 0, 1, 0, 0, 50791), -- Luminous Flux
(78568, 2, 5956, 0, 0, 1, 0, 0, 50791), -- Blacksmith Hammer
(78568, 1, 2901, 0, 0, 1, 0, 0, 50791); -- Mining Pick

DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 3967.543, -2531.816, 66.32741, NULL, 0),
(@PATH, 1, 3965.543, -2534.443, 66.56498, NULL, 0),
(@PATH, 2, 3962.482, -2536.5, 66.72681, NULL, 3669),
(@PATH, 3, 3967.543, -2531.816, 66.32741, NULL, 0),
(@PATH, 4, 3970.99, -2527.691, 66.0947, NULL, 0),
(@PATH, 5, 3972.09, -2524.106, 65.69862, NULL, 3605);

UPDATE `gossip_menu` SET `VerifiedBuild`=50791 WHERE (`MenuID`=16433 AND `TextID`=23824) OR (`MenuID`=16432 AND `TextID`=23823) OR (`MenuID`=16641 AND `TextID`=24170) OR (`MenuID`=16518 AND `TextID`=23994) OR (`MenuID`=16428 AND `TextID`=23808);
UPDATE `gossip_menu_option` SET `GossipOptionID`=42453, `VerifiedBuild`=50791 WHERE (`MenuID`=16518 AND `OptionID`=1);

-- Scene
UPDATE `scene_template` SET `ScriptName` = 'scene_dark_portal_run_away' WHERE `SceneId`=621; -- Archmage Khadgar

-- Quest
DELETE FROM `quest_template_addon` WHERE `ID`=34420;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(34420, 0, 0, 0, 34393, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 'quest_the_cost_of_war');

UPDATE `quest_poi` SET `VerifiedBuild`=50791 WHERE (`QuestID`=34420 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=34420 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42567 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=42567 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=39954 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=39954 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=39944 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=39944 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=39935 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=39935 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=39935 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=39931 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=39931 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=26131 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=26131 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=1453 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=1453 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=50791 WHERE (`QuestID`=34420 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=34420 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42567 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=42567 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=39954 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=39954 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=39944 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=39944 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=39935 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=39935 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=39935 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=39935 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=39935 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=39935 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=39935 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=39935 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=39935 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=39935 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=39931 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=39931 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=26131 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26131 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=1453 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=1453 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_details` SET `VerifiedBuild`=50791 WHERE `ID`=34420;
UPDATE `quest_template_locale` SET `QuestDescription`='Hay quien dice que es una misión suicida, pero no entra en mis planes desperdiciar ninguna vida.$b$b¡Todos conmigo!', `VerifiedBuild`=50791 WHERE (`ID`=34420 AND `locale`='esES');
UPDATE `creature_queststarter` SET `VerifiedBuild`=50791 WHERE (`id`=78558 AND `quest`=34420);

-- Phase
DELETE FROM `phase_area` WHERE `AreaId` = 7025 AND `PhaseId` IN (3569, 3264, 3394, 3395, 3396);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7025, 3569, 'See Named Characters on Dark Portal, Post-Guldan'),
(7025, 3264, 'See Questgivers at Bleeding Hollow Building'),
(7025, 3394, 'See Khadgar at Bleeding Hollow Building'),
(7025, 3395, 'See Thrall at Bleeding Hollow Building'),
(7025, 3396, 'See Maraad at Bleeding Hollow Building');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3569 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3569, 0, 0, 0, 47, 0, 34393, 66, 0, 0, 0, 0, '', 'Apply Phase 3569 if Quest 34393 is complete | rewarded'),
(26, 3569, 0, 0, 0, 47, 0, 34420, 66, 0, 1, 0, 0, '', 'Apply Phase 3569 if Quest 34420 is not complete | rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3264 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3264, 0, 0, 0, 1, 0, 158985, 0, 0, 1, 0, 0, '', 'Apply Phase 3264 if has no aura 158985'),
(26, 3264, 0, 0, 0, 47, 0, 34420, 66, 0, 0, 0, 0, '', 'Apply Phase 3264 if Quest 34420 is complete | rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3394 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3394, 0, 0, 0, 1, 0, 158985, 0, 0, 1, 0, 0, '', 'Apply Phase 3394 if has no aura 158985'),
(26, 3394, 0, 0, 0, 47, 0, 34420, 66, 0, 0, 0, 0, '', 'Apply Phase 3394 if Quest 34420 is complete | rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3395 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3395, 0, 0, 0, 1, 0, 158985, 0, 0, 1, 0, 0, '', 'Apply Phase 3395 if has no aura 158985'),
(26, 3395, 0, 0, 0, 47, 0, 34420, 66, 0, 0, 0, 0, '', 'Apply Phase 3395 if Quest 34420 is complete | rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3396 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3396, 0, 0, 0, 1, 0, 158985, 0, 0, 1, 0, 0, '', 'Apply Phase 3396 if has no aura 158985'),
(26, 3396, 0, 0, 0, 47, 0, 34420, 66, 0, 0, 0, 0, '', 'Apply Phase 3396 if Quest 34420 is complete | rewarded');
