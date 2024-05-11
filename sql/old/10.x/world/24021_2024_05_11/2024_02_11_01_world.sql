-- Love is in the Air - The Gala of Gifts
DELETE FROM `phase_name` WHERE `ID` IN (22310, 22403);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(22310, 'Cosmetic - Love is in the Air - The Gala of Gifts - Elwynn Forest'),
(22403, 'Cosmetic - Love is in the Air - The Gala of Gifts - Durotar');

DELETE FROM `phase_area` WHERE `PhaseId` IN (22310, 22403);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(12, 22310, 'Elwynn Forest: Cosmetic - Love is in the Air - The Gala of Gifts - Elwynn Forest'),
(1519, 22310, 'Stormwind City: Cosmetic - Love is in the Air - The Gala of Gifts - Elwynn Forest'),
(14, 22403, 'Durotar: Cosmetic - Love is in the Air - The Gala of Gifts - Durotar');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (22310, 22403);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 22310, 0, 0, 0, 12, 0, 8, 0, 0, 0, 'Apply phase 22310 if event "Love is in the Air" is active'),
(26, 22403, 0, 0, 0, 12, 0, 8, 0, 0, 0, 'Apply phase 22403 if event "Love is in the Air" is active');
