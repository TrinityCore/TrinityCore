-- Strengthen the Ancients (12092)
-- Woodlands Walker
SET @ENTRY := 26421;
UPDATE `creature_template` SET `npcflag`=1,`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100+0,@ENTRY*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,50994,0,0,0,0,0,1,0,0,0,0,0,0,0,'Woodlands Walker - Cast Toughen Hide - at 50% HP'),
(@ENTRY,0,1,2,64,0,100,1,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip hello - Close gossip - Invoker'),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,88,@ENTRY*100+0,@ENTRY*100+1,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Run random script - Self'),
--
(@ENTRY*100+0,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Woodlands Walker - Emote text - Self'),
(@ENTRY*100+0,9,1,0,0,0,100,0,1000,1000,0,0,2,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'Woodlands Walker - Set faction monster - Self'),
--
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Woodlands Walker - Emote text - Self'),
(@ENTRY*100+1,9,1,0,0,0,100,0,1000,1000,0,0,11,47550,0,0,0,0,0,7,0,0,0,0,0,0,0,'Woodlands Walker - Cast Create Bark of the Walkers - Invoker'),
(@ENTRY*100+1,9,2,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Woodlands Walker - Despawn - Self');

DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The %s is angered by your request and attacks!",16,0,100,0,0,0,"emote text"),
(@ENTRY,1,0,"Breaking off a piece of its bark, the %s hands it to you before departing.",16,0,100,0,0,0,"emote text");
