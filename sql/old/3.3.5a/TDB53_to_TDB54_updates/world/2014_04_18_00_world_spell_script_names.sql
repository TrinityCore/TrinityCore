--
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_avenging_wrath';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(31884,'spell_pal_avenging_wrath'); 

--
DELETE FROM `spell_proc_event` WHERE `entry`=-53375;
