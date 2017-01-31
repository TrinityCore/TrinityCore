SET @Fairmount = 3393; -- Captain Fairmount
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Fairmount; -- three scripts
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@Fairmount AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Fairmount,0,0,0,4,0,100,0,0,0,0,0,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captain Fairmount: On aggro cast Battle Shout self'),
(@Fairmount,0,1,0,2,0,100,1,0,30,0,0,11,19134,0,0,0,0,0,2,0,0,0,0,0,0,0,'Captain Fairmount: At 30% hp cast Frightening Shout'),
(@Fairmount,0,2,0,13,0,100,0,5000,5000,0,0,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,'Captain Fairmount: On enemy casting cast Pummel');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Fairmount;
UPDATE `creature_model_info` SET `modelid_other_gender`=0 WHERE `modelid`=1855; -- correct wrong model data, thanks Kaelima
