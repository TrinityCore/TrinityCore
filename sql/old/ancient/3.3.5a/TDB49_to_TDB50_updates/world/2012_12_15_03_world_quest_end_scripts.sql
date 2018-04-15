DELETE FROM `quest_end_scripts` WHERE `id` IN (254,619,652,779,795,2946,2966,3364,5058,5059);
UPDATE `quest_template` SET `CompleteScript`=0 WHERE `Id`IN (254,619,652,779,795,2946,2966,3364,5058,5059);
DELETE FROM `db_script_string` WHERE `entry` IN (2000000045,2000000046);
DELETE FROM `smart_scripts` WHERE `entryorguid`=836 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Durnan Furcuttor for Scalding Mornbrew Delivery
(836,0,0,0,20,0,100,0,3364,0,0,0,80,83600,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Durnan Furcutter - On quest "Scalding Mornbrew Delivery" Rewarded - call script');
-- corrected quest
