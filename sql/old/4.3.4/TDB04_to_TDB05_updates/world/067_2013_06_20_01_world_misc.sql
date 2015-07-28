DELETE FROM `spell_script_names` WHERE `spell_id`=55945;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(55945,"spell_gen_spectator_cheer_trigger");

DELETE FROM `creature_template_addon` WHERE `entry` IN (30102,30193);
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES
(30102,1, '55944 56060'),(30193,1, '55944 56060');
