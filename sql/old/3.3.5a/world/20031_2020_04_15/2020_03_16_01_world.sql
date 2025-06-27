-- 
UPDATE `smart_scripts` SET `target_type`=23 WHERE `entryorguid`=1450000 AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts`  SET `action_param1`=10 WHERE `entryorguid`=14500 AND `source_type`=0 AND `id`=5;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 23180;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 23180, 0, 0, 29, 0, 14500, 40, 0, 1, 0, '', "Can cast spell Release Imp if NPC J'eevee is not near"),
(17, 0, 23180, 0, 0, 9, 0, 7629, 0, 0, 0, 0, '', "Can cast spell Release Imp if the quest Imp Delivery is taken");
