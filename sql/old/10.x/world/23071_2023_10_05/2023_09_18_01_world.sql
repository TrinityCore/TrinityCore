SET @CGUID := 5000076;

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 78573, 1265, 7025, 7041, '0', 3236, 0, 0, 0, 3990.776123046875, -2553.923583984375, 66.09201812744140625, 6.062974929809570312, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Korag (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+1, 78573, 1265, 7025, 7041, '0', 3237, 0, 0, 0, 3990.776123046875, -2553.923583984375, 66.09201812744140625, 6.062974929809570312, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Korag (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 122263 - Permanent Feign Death)
(@CGUID+2, 78507, 1265, 7025, 7041, '0', 0, 0, 0, 1, 3944.12939453125, -2506.163330078125, 69.37920379638671875, 6.10106658935546875, 120, 0, 0, 3200, 0, 0, NULL, NULL, 50791), -- Bleeding Hollow Savage (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 29266 - Permanent Feign Death)
(@CGUID+3, 78507, 1265, 7025, 7041, '0', 0, 0, 0, 1, 3933.8681640625, -2515.333251953125, 69.83924102783203125, 3.359530925750732421, 120, 0, 0, 3200, 0, 0, NULL, NULL, 50791), -- Bleeding Hollow Savage (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 29266 - Permanent Feign Death)
(@CGUID+4, 78507, 1265, 7025, 7041, '0', 0, 0, 0, 1, 3952.9619140625, -2499.98095703125, 69.73077392578125, 3.981081247329711914, 120, 0, 0, 3200, 0, 0, NULL, NULL, 50791), -- Bleeding Hollow Savage (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 29266 - Permanent Feign Death)
(@CGUID+5, 78507, 1265, 7025, 7041, '0', 0, 0, 0, 1, 3933.9619140625, -2521.460205078125, 69.73077392578125, 0.722415447235107421, 120, 0, 0, 3200, 0, 0, NULL, NULL, 50791), -- Bleeding Hollow Savage (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 29266 - Permanent Feign Death)
(@CGUID+6, 78507, 1265, 7025, 7041, '0', 0, 0, 0, 1, 3932.192626953125, -2511.2587890625, 69.83924102783203125, 4.906171321868896484, 120, 0, 0, 3200, 0, 0, NULL, NULL, 50791), -- Bleeding Hollow Savage (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 29266 - Permanent Feign Death)
(@CGUID+7, 78507, 1265, 7025, 7041, '0', 0, 0, 0, 1, 3941.690185546875, -2512.7275390625, 69.37921142578125, 1.244288563728332519, 120, 0, 0, 3200, 0, 0, NULL, NULL, 50791), -- Bleeding Hollow Savage (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 29266 - Permanent Feign Death)
(@CGUID+8, 78507, 1265, 7025, 7041, '0', 0, 0, 0, 1, 3928.200439453125, -2509.104248046875, 70.30466461181640625, 5.481092453002929687, 120, 0, 0, 3200, 0, 0, NULL, NULL, 50791), -- Bleeding Hollow Savage (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 29266 - Permanent Feign Death)
(@CGUID+9, 78507, 1265, 7025, 7041, '0', 0, 0, 0, 1, 3959.943603515625, -2523.475830078125, 69.75146484375, 6.165135860443115234, 120, 0, 0, 3200, 0, 0, NULL, NULL, 50791), -- Bleeding Hollow Savage (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 29266 - Permanent Feign Death)
(@CGUID+10, 81762, 1265, 7025, 7041, '0', 3623, 0, 0, 0, 3990.822998046875, -2553.802001953125, 66.079864501953125, 0.087815076112747192, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Taag (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+11, 81762, 1265, 7025, 7041, '0', 3624, 0, 0, 0, 3990.8212890625, -2553.802001953125, 66.079864501953125, 0.087815076112747192, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791); -- Taag (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 122263 - Permanent Feign Death)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Korag
(@CGUID+1, 0, 0, 0, 0, 4, 1, 0, 0, 7600, 0, 0, 0, '122263'), -- Korag - 122263 - Permanent Feign Death
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '29266'), -- Bleeding Hollow Savage - 29266 - Permanent Feign Death
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 6415, 0, 0, 0, '29266'), -- Bleeding Hollow Savage - 29266 - Permanent Feign Death
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 6412, 0, 0, 0, '29266'), -- Bleeding Hollow Savage - 29266 - Permanent Feign Death
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 6412, 0, 0, 0, '29266'), -- Bleeding Hollow Savage - 29266 - Permanent Feign Death
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '29266'), -- Bleeding Hollow Savage - 29266 - Permanent Feign Death
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '29266'), -- Bleeding Hollow Savage - 29266 - Permanent Feign Death
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 6414, 0, 0, 0, '29266'), -- Bleeding Hollow Savage - 29266 - Permanent Feign Death
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '29266'), -- Bleeding Hollow Savage - 29266 - Permanent Feign Death
(@CGUID+10, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Taag
(@CGUID+11, 0, 0, 0, 0, 4, 1, 0, 0, 7600, 0, 0, 0, '122263'); -- Taag - 122263 - Permanent Feign Death

-- Spell
DELETE FROM `spell_script_names` WHERE `spell_id`=122263 AND `ScriptName`='spell_gen_feign_death_all_flags';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(122263, 'spell_gen_feign_death_all_flags');

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (3623, 3624);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(3623, 'Cosmetic - Dying Slave is Alive (A)'),
(3624, 'Cosmetic - Dying Slave is Dead (A)');

DELETE FROM `phase_area` WHERE `AreaId` IN (7039, 7041) AND `PhaseId` IN (3236, 3237, 3623, 3624);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7041, 3236, 'See dying slave alive (H)'),
(7041, 3237, 'See dying slave dead (H)'),
(7041, 3623, 'See dying slave alive (A)'),
(7041, 3624, 'See dying slave dead (A)'),
(7039, 3236, 'See dying slave alive (H)'),
(7039, 3237, 'See dying slave dead (H)'),
(7039, 3623, 'See dying slave alive (A)'),
(7039, 3624, 'See dying slave dead (A)');

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3236 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3236, 0, 0, 0, 47, 0, 34421, 2 | 8 | 64, 0, 1, 'Apply Phase 3236 if Quest 34421 is not complete | in progress | rewarded'),
(26, 3236, 0, 0, 0, 6, 0, 67, 0, 0, 0, 'Apply phase 3236 if Team Horde');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3237 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3237, 0, 0, 0, 47, 0, 34421, 2 | 8 | 64, 0, 0, 'Apply Phase 3237 if Quest 34421 is complete | in progress | rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3623 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3623, 0, 0, 0, 47, 0, 35240, 2 | 8 | 64, 0, 1, 'Apply Phase 3623 if Quest 35240 is not complete | in progress | rewarded'),
(26, 3623, 0, 0, 0, 6, 0, 469, 0, 0, 0, 'Apply phase 3623 if Team Alliance');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3624 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3624, 0, 0, 0, 47, 0, 35240, 2 | 8 | 64, 0, 0, 'Apply Phase 3624 if Quest 35240 is complete | in progress | rewarded');

-- Quest
UPDATE `quest_poi` SET `VerifiedBuild`=50791 WHERE (`QuestID`=34421 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=34421 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=34421 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=34421 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=34421 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=34421 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=50791 WHERE (`QuestID`=34421 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=34421 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=34421 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=34421 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=34421 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=34421 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_poi` SET `VerifiedBuild`=50791 WHERE (`QuestID`=35240 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=35240 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=35240 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=35240 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=35240 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=35240 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=50791 WHERE (`QuestID`=35240 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=35240 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=35240 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=35240 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=35240 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=35240 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=50791 WHERE `ID`=35240;

DELETE FROM `quest_template_addon` WHERE `ID`=34421;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(34421, 0, 0, 0, 34420, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

UPDATE `creature_queststarter` SET `VerifiedBuild`=50791 WHERE (`id`=78573 AND `quest`=34421);
UPDATE `creature_queststarter` SET `VerifiedBuild`=50791 WHERE (`id`=81762 AND `quest`=35240);
