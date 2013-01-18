UPDATE `spell_proc_event` SET `cooldown`=0 WHERE `entry`=64440;

DELETE FROM `spell_script_names` WHERE `spell_id`=64442;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(64442,'spell_gen_blade_warding');
