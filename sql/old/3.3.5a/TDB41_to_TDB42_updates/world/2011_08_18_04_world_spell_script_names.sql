DELETE FROM `spell_script_names` WHERE `spell_id`=64414;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(64414,'spell_load_into_catapult');

-- Update a wrongly entered spell
UPDATE `creature_template` SET `spell6`=64414 WHERE `entry`=33167;
