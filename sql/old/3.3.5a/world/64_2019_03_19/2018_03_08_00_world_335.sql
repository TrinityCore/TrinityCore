-- 
DELETE FROM `conditions` WHERE `SourceEntry` IN (28806) AND `SourceTypeOrReferenceId`=13 AND `ConditionValue1`=5;
UPDATE `conditions` SET `ConditionValue1`=3, `ConditionValue2`=17066  WHERE `SourceEntry` IN (29172) AND `SourceTypeOrReferenceId`=13;
UPDATE `conditions` SET `ConditionValue1`=3, `ConditionValue2`=17066  WHERE `SourceEntry` IN (29531) AND `SourceTypeOrReferenceId`=13;
UPDATE `conditions` SET `ConditionValue1`=3, `ConditionValue2`=17066  WHERE `SourceEntry` IN (29831) AND `SourceTypeOrReferenceId`=13;

DELETE FROM `conditions` WHERE `SourceEntry` IN (30098) AND `SourceTypeOrReferenceId`=17;
DELETE FROM `conditions` WHERE `SourceEntry` IN (30098) AND `SourceTypeOrReferenceId`=13;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, COMMENT) VALUES 
(13, 2, 30098, 0, 0, 31, 0, 3, 17253, 0, 0, 0, 0, "", ""),
(13, 2, 30098, 0, 0, 29, 0, 17233, 20, 0, 1, 0, 0, "", ""),
(13, 1, 30098, 0, 0, 31, 0, 5, 182483, 0, 0, 0, 0, "", ""),
(13, 4, 30098, 0, 0, 31, 0, 5, 181653, 0, 0, 0, 0, "", "");

DELETE FROM `conditions` WHERE `SourceEntry` IN (17233) AND `SourceTypeOrReferenceId`=22;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, COMMENT) VALUES 
(22, 1, 17233, 0, 0, 6, 0, 67, 0, 0, 1, 0, 0, "", "");

UPDATE `event_scripts` SET `datalong2`=55000 WHERE `id`=10561;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17253 AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17253, 0, 6, 0, 52, 0, 100, 0, 7, 17233, 0, 0, 32, 0, 0, 0, 0, 0, 0, 20, 182483, 20, 0, 0, 0, 0, 0, "Defile Uther's Tomb Trigger - On Text 7 Over - reset gob");
UPDATE smart_scripts SET `target_o`=0.2935 WHERE `entryorguid`=17238 AND `source_type`=0 AND `id`=16;
UPDATE smart_scripts SET `target_type`=21, `target_param1`=50 WHERE `entryorguid`=1723801 AND `source_type`=9 AND `id`=1;
