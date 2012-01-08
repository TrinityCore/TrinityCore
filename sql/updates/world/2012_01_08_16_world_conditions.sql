-- Spell script target for flying sword
DELETE FROM `conditions` WHERE `SourceEntry` = 48331 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 48331, 0, 18, 1, 27327, 0, 0, '', NULL);

-- Spell script target for Flame Brazier's (on players only)
DELETE FROM `conditions` WHERE `SourceEntry` = 48246 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 48246, 0, 18, 1, 0, 0, 0, '', NULL);

-- Spell script target for Ritual Strike DMG -- Players and Ritual Target
DELETE FROM `conditions` WHERE `SourceEntry` = 48277 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 48277, 0, 18, 1, 26555, 0, 0, '', NULL),
(13, 0, 48277, 0, 18, 1, 27327, 0, 0, '', NULL);
