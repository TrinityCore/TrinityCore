--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16943,20928) AND `source_type` = 0 AND `id` IN (3,4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22348,22350,22351) AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (22348,22350,22351);

DELETE FROM `spell_script_names` WHERE `spell_id` = 38920 AND `ScriptName` = 'spell_detonate_teleporter';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38920,'spell_detonate_teleporter');
