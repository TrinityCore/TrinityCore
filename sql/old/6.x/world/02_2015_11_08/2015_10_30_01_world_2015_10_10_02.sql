--
DELETE FROM `smart_scripts` WHERE `entryorguid`=16286 AND `source_type`=0;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=16286;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (29865,55053);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(29865,"spell_loatheb_deathbloom"),
(55053,"spell_loatheb_deathbloom");
