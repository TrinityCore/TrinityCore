UPDATE `creature_template` SET `unit_flags`=33587200, `unit_flags2`=2080 WHERE `entry`=29791; -- Fixed flags of Rhino Spirit

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gal_darah_stampede_charge';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (59823, 'spell_gal_darah_stampede_charge');
