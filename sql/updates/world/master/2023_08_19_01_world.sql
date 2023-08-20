SET @OGUID := 5000005;

-- Gameobjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 233614, 1265, 7025, 7037, '0', 3880, 0, 3964.389892578125, -2311.460205078125, 63.83720016479492187, 4.711029052734375, -0.24200916290283203, -0.24167919158935546, -0.66491508483886718, 0.664011061191558837, 120, 255, 1, 50791), -- Chamber Door (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+1, 233614, 1265, 7025, 7037, '0', 3880, 0, 4167.580078125, -2309.510498046875, 63.83720016479492187, 4.671691417694091796, -0.24671554565429687, -0.23687267303466796, -0.67784595489501953, 0.650805354118347167, 120, 255, 1, 50791); -- Chamber Door (Area: The Dark Portal - Difficulty: 0) CreateObject1

UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=233614; -- Chamber Door

-- Quest
UPDATE `quest_template_locale` SET `QuestDescription`='Has luchado teniendo todo en contra y has hecho frente a males indescriptibles en innumerables ocasiones, pero siempre te has alzado con la victoria. Ahora, por enésima vez, has acudido a la llamada del deber, $gdispuesto:dispuesta; a arriesgar la vida para salvar tu amado mundo, nuestro mundo.$B$BEres la última esperanza de Azeroth, $n.$B$BNo confiaría en nadie más para enfrentarse a los abrumadores desafíos que nos aguardan.$B$BEl enemigo al que nos enfrentamos podría tener la información que necesitamos para ganar esta guerra. ¡Busca y destruye!$B$B¡Adelante, $n! ¡Por Azeroth!', `VerifiedBuild`=50791 WHERE (`ID`=35933 AND `locale`='esES');
UPDATE `quest_poi` SET `VerifiedBuild`=50791 WHERE (`QuestID`=35933 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=35933 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=50791 WHERE (`QuestID`=35933 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=11) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=10) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=9) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=8) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=7) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=6) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=35933 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_details` SET `VerifiedBuild`=50791 WHERE `ID` = 35933;

DELETE FROM `quest_request_items_locale` WHERE (`ID`=35933 AND `locale`='esES');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(35933, 'esES', 'Esta misiva tiene la marca del clan Grito de Guerra.', 50791);

-- Phases
DELETE FROM `phase_name` WHERE `ID`= 3880;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(3880, 'Cosmetic - Dark Portal chambers closed');

DELETE FROM `phase_area` WHERE `AreaId` = 7037 AND `PhaseId`= 3880;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7037, 3880, 'See doors at chambers on the Dark Portal (Assault on the Dark Portal)');

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3880 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3880, 0, 0, 0, 47, 0, 35933, 64, 0, 1, 'Apply Phase 3880 if Quest 35933 is not rewarded');
