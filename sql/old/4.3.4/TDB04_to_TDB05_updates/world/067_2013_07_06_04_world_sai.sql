SET @AXTROZ := 12899;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` = @AXTROZ; 4.x
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @AXTROZ;
-- SAI for Axtroz
DELETE FROM `smart_scripts` WHERE `entryorguid`=@AXTROZ AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@AXTROZ,0,0,0,0,0,100,0,6100,7100,16200,16200,11,20712,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Axtroz - In Combat - Cast Flame Breath'),
(@AXTROZ,0,1,0,0,0,100,0,8300,13300,7700,11400,11,16095,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Axtroz - In Combat - Cast Vicious Rend'),
(@AXTROZ,0,2,0,0,0,90,0,4600,5200,6400,11800,11,20714,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Axtroz - In Combat - Cast Fireball');
