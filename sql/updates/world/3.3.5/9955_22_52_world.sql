DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gormok_ride_player','spell_gormok_jump_to_hand','spell_gormok_snobolled');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(66245,'spell_gormok_ride_player'), 
(66342,'spell_gormok_jump_to_hand'),
(66406,'spell_gormok_snobolled');
