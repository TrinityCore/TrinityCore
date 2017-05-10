--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (58203);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,58203,0,0,31,1,3,31075,0,0,0,'','Iron Chain');

UPDATE `smart_scripts` SET `event_param1`=500, `event_param2`=500, `action_type`=51 WHERE `entryorguid` IN (3092000) AND `source_type`=9 AND `id`=5;
UPDATE `smart_scripts` SET `event_param1`=2000, `event_param2`=2000, `action_param1`=52520 WHERE `entryorguid` IN (3092000) AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=2000, `event_param2`=2000, `action_param1`=58231, `target_type`=1, `target_param1`=0 WHERE `entryorguid` IN (3107500) AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=38, `event_param1`=1, `event_param2`=1, `event_param3`=0, `event_param4`=0, `action_type`=103, `action_param1`=1, `comment`="Scourge Bomb - On Data Set 1 1 - Root" WHERE `entryorguid` IN (31075) AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `event_param1`=1000, `event_param2`=1000, `action_param1`=0 WHERE `entryorguid` IN (3107500) AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `event_param3`=3 WHERE `entryorguid` IN (30920) AND `source_type`=0 AND `id`=1;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (58231);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,2,58231,0,0,31,0,3,31075,0,1,0,'','Exploding Abomination');
