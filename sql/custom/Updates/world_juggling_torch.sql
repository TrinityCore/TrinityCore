INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES
('13', '45644', '18', '1');
UPDATE `item_template` SET `ScriptName` = 'item_juggling_torch' WHERE `entry` = 34599;
INSERT INTO `spell_scripts` (`id`, `command`, `datalong`, `datalong2`) VALUES ('45644', '15', '45280', '2');
UPDATE `spell_scripts` SET `datalong2`='2' WHERE `datalong` IN (29132, 29099, 46689, 29130, 29133, 29102, 29101, 46690);