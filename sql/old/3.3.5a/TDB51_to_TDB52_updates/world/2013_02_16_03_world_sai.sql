-- quest fix cuergo's gold (q2882)
SET @ENTRY :=7898;
UPDATE `creature_template` SET `AIName`= 'SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND`entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND`entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Trigger - on respawn - run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,300000,300000,11,11463,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - spawn pirate1'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,300000,300000,11,11463,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - spawn pirate2'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,300000,300000,11,11485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - spawn buccaneer1'),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,300000,300000,11,11485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - spawn buccaneer2'),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,300000,300000,11,11487,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - spawn swashbuckler'),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Actionscript - despawn trigger');
