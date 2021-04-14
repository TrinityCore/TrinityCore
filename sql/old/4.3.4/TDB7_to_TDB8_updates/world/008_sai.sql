-- Nature's Reprisal (13946) quest script
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 65455;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 65455, 0, 0, 31, 0, 3, 2002, 0, 0, 0, 0, '', 'Nature''s Fury can hit only Rascal Sprite'),
(13, 1, 65455, 0, 1, 31, 0, 3, 2003, 0, 0, 0, 0, '', 'Nature''s Fury can hit only Shadow Sprite'),
(13, 1, 65455, 0, 2, 31, 0, 3, 2004, 0, 0, 0, 0, '', 'Nature''s Fury can hit only Dark Sprite');
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (2002, 2003, 2004);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2002, 2003, 2004);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2002, 0, 0, 0, 8, 0, 100, 1, 65455, 0, 0, 0, 33, 34440, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Rascal Sprite - on spell hit (65455) - give quest credit (34440)'),
(2003, 0, 0, 0, 8, 0, 100, 1, 65455, 0, 0, 0, 33, 34440, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shadow Sprite - on spell hit (65455) - give quest credit (34440)'),
(2004, 0, 0, 0, 8, 0, 100, 1, 65455, 0, 0, 0, 33, 34440, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dark Sprite - on spell hit (65455) - give quest credit (34440)');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (65455, -65462);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(65455, 65462, 1, 'Nature''s Fury - root and shrink effect'),
(-65462, 65456, 0, 'Nature''s Fury - explode effect');
