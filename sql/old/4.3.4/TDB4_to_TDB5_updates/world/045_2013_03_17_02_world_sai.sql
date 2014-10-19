SET @MULE := 23977;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@MULE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MULE AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MULE*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MULE,0,0,0,22,0,100,0,125,0,0,0,11,43572,0,0,0,0,0,7,0,0,0,0,0,0,0,'Abandoned Pack Mule - On emote receive - Spellcast Send Them Packing: On /Raise Emote Dummy to Player'),
(@MULE,0,1,2,31,0,100,0,43572,0,0,0,11,42721,0,0,0,0,0,7,0,0,0,0,0,0,0,'Abandoned Pack Mule - On target spellhit Send Them Packing: On /Raise Emote Dummy to Player - Spellcast Send Them Packing: On Successful Dummy Spell Kill Credit'),
(@MULE,0,2,0,61,0,100,0,0,0,0,0,80,@MULE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Abandoned Pack Mule - On target spellhit Send Them Packing: On /Raise Emote Dummy to Player - Run script'),

(@MULE*100,9,0,0,0,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Abandoned Pack Mule script - Stop movement'),
(@MULE*100,9,1,0,0,0,100,0,500,500,0,0,5,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Abandoned Pack Mule script - Play emote'),
(@MULE*100,9,2,0,0,0,100,0,0,0,0,0,4,727,0,0,0,0,0,1,0,0,0,0,0,0,0,'Abandoned Pack Mule script - Play sound'),
(@MULE*100,9,3,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Abandoned Pack Mule script - Set run'),
(@MULE*100,9,4,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,1561.824,-3709.441,147.7268,0,'Abandoned Pack Mule script - Move to position'),
(@MULE*100,9,5,0,0,0,100,0,15000,15000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Abandoned Pack Mule script - Despawn');
