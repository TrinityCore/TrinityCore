DELETE FROM `spell_script_names` WHERE `spell_id` IN (78740,95016);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(78740, 'spell_activate'),
(95016, 'spell_activate'),
(79501, 'spell_fire'),
(92035, 'spell_fire');
UPDATE `gameobject_template` SET `flags`='20' WHERE `entry`='203625';
UPDATE `creature_template` SET `unit_flags`='0',`speed_run`='0.7' WHERE `entry`='42897';