DELETE FROM `conditions` WHERE `SourceEntry`= 11513 AND (`SourceTypeOrReferenceId`=17 OR `SourceTypeOrReferenceId`=13);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 11513, 0, 0, 29, 0, 6213, 5, 0, 0, 0, 0, '', 'Must be near NPC to cast'),
(17, 0, 11513, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0, '', 'Must be near NPC to cast'),
(17, 0, 11513, 0, 1, 29, 0, 6329, 5, 0, 0, 0, 0, '', 'Must be near NPC to cast'),
(17, 0, 11513, 0, 1, 36, 0, 0, 0, 0, 0, 0, 0, '', 'Must be near NPC to cast');

DELETE FROM `conditions` WHERE `SourceEntry`= 12709 AND (`SourceTypeOrReferenceId`=17 OR `SourceTypeOrReferenceId`=13);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 12709, 0, 0, 29, 0, 6218, 5, 0, 0, 0, 0, '', 'Must be near NPC to cast'),
(17, 0, 12709, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0, '', 'Must be near NPC to cast'),
(17, 0, 12709, 0, 1, 29, 0, 6220, 5, 0, 0, 0, 0, '', 'Must be near NPC to cast'),
(17, 0, 12709, 0, 1, 36, 0, 0, 0, 0, 0, 0, 0, '', 'Must be near NPC to cast'),
(17, 0, 12709, 0, 2, 29, 0, 6219, 5, 0, 0, 0, 0, '', 'Must be near NPC to cast'),
(17, 0, 12709, 0, 2, 36, 0, 0, 0, 0, 0, 0, 0, '', 'Must be near NPC to cast');

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_collecting_fallout';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(12709, 'spell_collecting_fallout');
