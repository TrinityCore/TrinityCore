DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gormok_ride_player','spell_gormok_jump_to_hand');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(66245,'spell_gormok_ride_player'), -- Ride Vehicle
(66342,'spell_gormok_jump_to_hand'); -- Jump to Hand
