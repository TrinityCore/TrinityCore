DELETE FROM `conditions` WHERE `SourceEntry` IN (80340, 80196) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 80340, 0, 0, 31, 0, 3, 39978, 0, 0, 0, '', 'Furious Swipe - Target Twilight Torturer'),
(13, 1, 80340, 0, 1, 31, 0, 3, 39980, 0, 0, 0, '', 'Furious Swipe - Target Twilight Sadist'),
(13, 1, 80340, 0, 2, 31, 0, 3, 39982, 0, 0, 0, '', 'Furious Swipe - Target Crazed Mage'),
(13, 1, 80340, 0, 3, 31, 0, 3, 39987, 0, 0, 0, '', 'Furious Swipe - Target Evolved Twilight Zealot'),
(13, 1, 80340, 0, 4, 31, 0, 3, 39708, 0, 0, 0, '', 'Furious Swipe - Target Twilight Flame Caller'),
(13, 1, 80340, 0, 5, 31, 0, 3, 39990, 0, 0, 0, '', 'Furious Swipe - Target Twilight Zealot'),
(13, 1, 80340, 0, 6, 31, 0, 3, 40017, 0, 0, 0, '', 'Furious Swipe - Target Twilight Element Warden'),
(13, 1, 80340, 0, 7, 31, 0, 3, 39985, 0, 0, 0, '', 'Furious Swipe - Target Mad Prisoner'),
(13, 1, 80196, 0, 0, 31, 0, 3, 39978, 0, 0, 0, '', 'Aggro Nearby Targets - Target Twilight Torturer'),
(13, 1, 80196, 0, 1, 31, 0, 3, 39980, 0, 0, 0, '', 'Aggro Nearby Targets - Target Twilight Sadist'),
(13, 1, 80196, 0, 2, 31, 0, 3, 39982, 0, 0, 0, '', 'Aggro Nearby Targets - Target Crazed Mage'),
(13, 1, 80196, 0, 3, 31, 0, 3, 39987, 0, 0, 0, '', 'Aggro Nearby Targets - Target Evolved Twilight Zealot'),
(13, 1, 80196, 0, 4, 31, 0, 3, 39708, 0, 0, 0, '', 'Aggro Nearby Targets - Target Twilight Flame Caller'),
(13, 1, 80196, 0, 5, 31, 0, 3, 39990, 0, 0, 0, '', 'Aggro Nearby Targets - Target Twilight Zealot'),
(13, 1, 80196, 0, 6, 31, 0, 3, 40017, 0, 0, 0, '', 'Aggro Nearby Targets - Target Twilight Element Warden'),
(13, 1, 80196, 0, 7, 31, 0, 3, 39985, 0, 0, 0, '', 'Aggro Nearby Targets - Target Mad Prisoner');

-- Areatriggers
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (6014);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6014, 'at_raz_corla_event');
