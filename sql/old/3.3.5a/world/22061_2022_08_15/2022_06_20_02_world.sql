--
DELETE FROM `spell_scripts` WHERE `id` = 57884;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 57889;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_icecrown_through_the_eye_the_eye_of_the_lk','spell_icecrown_through_the_eye_kill_credit_to_master');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(25732,'spell_icecrown_through_the_eye_the_eye_of_the_lk'),
(57884,'spell_icecrown_through_the_eye_kill_credit_to_master');

DELETE FROM `creature_text` WHERE `CreatureID` = 23837 AND `GroupID` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = -121192 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 192861 AND `source_type` = 1 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(192861,1,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Eye of the Lich King - On Gossip Option 0 Selected - Close Gossip");
