--
UPDATE `smart_scripts` SET `target_type` = 1, `target_param1` = 0 WHERE `entryorguid` = 1807500 AND `source_type` = 9 AND `id` = 7;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 34389;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,34389,0,0,31,1,3,18075,0,0,0,0,"","Group 0: Spell 'Throw Doomhammer' targets creature 'Mannoroth'");
