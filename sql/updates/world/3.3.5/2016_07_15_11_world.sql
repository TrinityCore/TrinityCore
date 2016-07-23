--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (65200, 65258, 65265);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 65200, 0, 0, 29, 0, 34320, 5, 0, 0, 0, 0, "", "Spell 'Feed Venomhide Hatchling' (used for quest 'Hungry, Hungry Hatchling') requires NPC 'Venomhide Hatchling' to be within 5 yards"),
(17, 0, 65258, 0, 0, 29, 0, 34320, 5, 0, 0, 0, 0, "", "Spell 'Feed Venomhide Hatchling' (used for quest 'Gorishi Grub') requires NPC 'Venomhide Hatchling' to be within 5 yards"),
(17, 0, 65265, 0, 0, 29, 0, 34320, 5, 0, 0, 0, 0, "", "Spell 'Feed Venomhide Hatchling' (used for quest 'Poached, Scrambled, Or Raw?') requires NPC 'Venomhide Hatchling' to be within 5 yards");
