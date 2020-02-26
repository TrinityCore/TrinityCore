-- 
UPDATE `smart_scripts` SET `event_param1`=44611, `action_param1` = 0 WHERE `entryorguid` = 24824 AND `source_type`=0 AND `id`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN(44611);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 44611, 0, 31, 3, 24824, 0, 0, '', 'Collect Data Credit');
