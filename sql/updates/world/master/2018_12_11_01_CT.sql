DELETE FROM `phase_area` WHERE `AreaID` IN (7705, 7741, 7740, 7742, 7712, 7754, 7713, 7749, 7912);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceEntry` IN (7705, 7741, 7740, 7742, 7712, 7754, 7713, 7749, 7912);

INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 4899, 'Start Demon Hunter');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7741, 5310, 'Complete Scene Start Demon Hunter');


INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(26, 4899, 7705, 0, 1, 8, 0, 40076, 0, 0, 0, 0, 0, '', ''), 
(26, 4899, 7705, 0, 1, 1, 0, 193525, 0, 0, 1, 0, 0, '', ''),
(26, 4899, 7705, 0, 1, 14, 0, 40077, 0, 0, 0, 0, 0, '', ''),
(26, 5310, 7741, 0, 1, 8, 0, 40077, 0, 0, 1, 0, 0, '', 'If quest 40077 not complete rewarded'), 
(26, 5310, 7741, 0, 1, 28, 0, 40077, 0, 0, 1, 0, 0, '', 'If quest 40077 not complete rewarded');

