UPDATE `conditions` SET `SourceGroup`=0 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=57402;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (43891,43789);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43892;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 43891, 0, 0, 29, 0, 24439, 1, 0, 0, 0, 0, '', 'Spell Drop-Off Periodic targets npc Sack of Relics'),
(17, 0, 43789, 0, 0, 31, 0, 3, 24439, 0, 0, 0, 0, '', 'Spell Grappling Beam targets npc Sack of Relics'),
(13, 1, 43892, 0, 0, 31, 0, 3, 24439, 0, 0, 0, 0, '', 'Spell Steel Gate Drop Off Check targets npc Sack of Relics');
