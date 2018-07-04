UPDATE `smart_scripts` SET `event_flags`=1 WHERE `entryorguid`=19440 AND `id`=0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=38530 AND `ElseGroup`>0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 38530, 0, 1, 31, 0, 3, 16873, 0, 0, 0, 0, '', NULL),
(13, 1, 38530, 0, 2, 31, 0, 3, 16907, 0, 0, 0, 0, '', NULL),
(13, 1, 38530, 0, 3, 31, 0, 3, 19422, 0, 0, 0, 0, '', NULL),
(13, 1, 38530, 0, 3, 31, 0, 3, 19424, 0, 0, 0, 0, '', NULL);

DELETE FROM `smart_scripts` WHERE `entryorguid`=16873 AND `source_type`=0 AND `id`=17;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16907 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19422 AND `source_type`=0 AND `id`=15;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19424 AND `source_type`=0 AND `id`=4;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16873, 0, 17, 0, 8, 0, 100, 1, 38530, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bleeding Hollow Dark Shaman - On Spellhit - Start Attack'),
(16907, 0, 1, 0, 8, 0, 100, 1, 38530, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bleeding Hollow Peon - On Spellhit - Start Attack'),
(19422, 0, 15, 0, 8, 0, 100, 1, 38530, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bleeding Hollow Necrolyte - On Spellhit - Start Attack'),
(19424, 0, 4, 0, 8, 0, 100, 1, 38530, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bleeding Hollow Tormentor - On Spellhit - Start Attack');
