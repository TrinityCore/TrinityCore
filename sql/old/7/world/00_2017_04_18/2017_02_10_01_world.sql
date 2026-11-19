DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_victorious','spell_warr_victory_rush');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(34428,'spell_warr_victory_rush');

DELETE FROM `spell_proc_event` WHERE `entry`=32216;
