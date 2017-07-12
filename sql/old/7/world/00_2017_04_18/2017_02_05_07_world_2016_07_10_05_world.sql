--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=3397 AND `SourceGroup`=3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 3, 3397, 0, 0, 29, 0, 3395, 200, 0, 1, 0, 0, "", "Prevent summoning creature Verog the Dervish if already summoned");

UPDATE `smart_scripts` SET `action_param2`=6, `action_param3`=20000 WHERE `source_type`=0 AND `entryorguid`=3397 AND `id`=3;
UPDATE `smart_scripts` SET `event_chance`=20 WHERE `source_type`=0 AND `entryorguid`=3397 AND `id`=2;
