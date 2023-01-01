--
UPDATE `creature_template_addon` SET `bytes1` = 5, `bytes2` = 1, `emote` = 0, `auras` = '45631 45842' WHERE `entry` = 25478;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 25478;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_borean_tundra_neural_needle','spell_borean_tundra_prototype_neural_needle');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45634,'spell_borean_tundra_neural_needle'),
(48252,'spell_borean_tundra_prototype_neural_needle');
