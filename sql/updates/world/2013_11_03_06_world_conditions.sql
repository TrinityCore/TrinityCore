-- Skill requirements for Flying Carpets and Flying Machines
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (75596,61309,61451,44153,44151);

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 75596, 0, 0, 7, 0, 197, 425, 0, 0, 0, 0, '', 'Player has must have Tailoring with skill level 425 to Ride Frosty Flying Carpet'),
(17, 0, 61309, 0, 0, 7, 0, 197, 425, 0, 0, 0, 0, '', 'Player has must have Tailoring with skill level 425 to Ride Magnificent Flying Carpet'),
(17, 0, 61451, 0, 0, 7, 0, 197, 300, 0, 0, 0, 0, '', 'Player has must have Tailoring with skill level 300 to Ride Flying Carpet'),
(17, 0, 44153, 0, 0, 7, 0, 202, 300, 0, 0, 0, 0, '', 'Player has must have Engineering with skill level 300 to Ride Flying Machine'),
(17, 0, 44151, 0, 0, 7, 0, 202, 375, 0, 0, 0, 0, '', 'Player has must have Engineering with skill level 375 to Ride Turbo-Charged Flying Machine');
