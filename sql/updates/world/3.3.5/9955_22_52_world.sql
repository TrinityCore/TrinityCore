DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gormok_ride_player','spell_gormok_jump_to_hand','spell_gormok_snobolled');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66245,'spell_gormok_ride_player'),
(66342,'spell_gormok_jump_to_hand'),
(66406,'spell_gormok_snobolled');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=66636;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 66636, 64, 0, 0, 'Disable LoS for Spell Rising Anger');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=34796;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(34796, 46598, 0, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=34796 AND `accessory_entry`=34800;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(34796,34800,0,0,'Snobold Vassal', 5,0),
(34796,34800,1,0,'Snobold Vassal', 5,0),
(34796,34800,2,0,'Snobold Vassal', 5,0),
(34796,34800,3,0,'Snobold Vassal', 5,0);
