--
DELETE FROM `areatrigger_tavern` WHERE `id` = 5309;
INSERT INTO `areatrigger_tavern` (`id`, `name`) VALUES (5309, 'Shadow Vault');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 30 AND `SourceEntry` = 5309;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(30, 0, 5309, 0, 0, 26, 0, 1, 0, 0, 0, 0, 0, '', 'Shadow Vault tavern requires phase 1.');
