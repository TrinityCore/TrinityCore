-- Phase
DELETE FROM `phase_name` WHERE `ID` = 15330;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(15330, 'Cosmetic - 9.0 NPE - Horde Populated Camp');

-- Phase for Clientside GameObjects
DELETE FROM `phase_area` WHERE (`AreaId` IN (10529, 10588, 10527) AND `PhaseId` = 15330);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(10529, 15330, 'Cosmetic - 9.0 NPE - Horde Populated Camp'), -- Ogre Ruins
(10588, 15330, 'Cosmetic - 9.0 NPE - Horde Populated Camp'), -- Darkmaul Plains
(10527, 15330, 'Cosmetic - 9.0 NPE - Horde Populated Camp'); -- Hruns Barrows

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 15330 AND `SourceEntry` IN (10529, 10588, 10527));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 15330, 10529, 0, 0, 47, 0, 59942, 64, 0, 0, 'Apply Phase 15330 if Quest 59942 is rewarded'), -- Ogre Ruins
(26, 15330, 10588, 0, 0, 47, 0, 59942, 64, 0, 0, 'Apply Phase 15330 if Quest 59942 is rewarded'), -- Darkmaul Plains
(26, 15330, 10527, 0, 0, 47, 0, 59942, 64, 0, 0, 'Apply Phase 15330 if Quest 59942 is rewarded'); -- Hruns Barrows
