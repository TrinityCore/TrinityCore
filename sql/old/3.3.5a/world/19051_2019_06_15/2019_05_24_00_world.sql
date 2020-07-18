DELETE FROM spell_script_names WHERE spell_id = 24083;
INSERT INTO spell_script_names VALUES (24083, 'spell_hatch_spiders');

UPDATE gameobject_template SET ScriptName = "gob_spider_egg" WHERE entry = 179985;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (24082,24083);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 24082, 0, 0, 31, 0, 5, 179985, 0, 0, 0, 0, '', 'Hatch Spider Egg targets Spider Egg'),
(13, 1, 24083, 0, 0, 31, 0, 5, 179985, 0, 0, 0, 0, '', 'Hatch Eggs targets Spider Egg');
