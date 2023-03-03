INSERT INTO `command` (`name`, `security`, `help`) VALUES ('list neauras', '3', 'Syntax: .list neauras');

DELETE FROM `spell_script_names` WHERE (`spell_id`='108212') AND (`ScriptName`='spell_rog_burst_of_speed');

DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='33395') AND (`spell_effect`='44544') AND (`type`='0') AND (`hastalent`='0');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('33395', 'spell_mage_pet_freeze');

UPDATE `pet_stats` SET `haste`='0' WHERE (`entry`='59190');

UPDATE `creature_template` SET `speed_run`='1.14286' WHERE (`entry`='417');