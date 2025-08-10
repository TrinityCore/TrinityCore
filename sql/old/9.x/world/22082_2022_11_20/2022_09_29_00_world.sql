-- Update PhaseID
UPDATE `creature` SET `PhaseId` = 16826 WHERE `guid` IN (850207, 850208);
UPDATE `gameobject` SET `PhaseId` = 16826 WHERE `guid` = 500400;

-- Phase
DELETE FROM `phase_area` WHERE `AreaId` = 10523 AND `PhaseId` = 16826;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(10523, 16826, 'See Portal to Oribos in Wizards Sanctum');

DELETE FROM `phase_name` WHERE `ID` = 16826;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(16826, 'See Portal to Oribos in Wizards Sanctum');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 16826 AND `SourceEntry` = 10523);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 16826, 10523, 0, 0, 47, 0, 60151, 2 | 8 | 64, 0, 0, 'Apply Phase 16826 If Quest 60151 IS in Progress | complete | rewarded');
