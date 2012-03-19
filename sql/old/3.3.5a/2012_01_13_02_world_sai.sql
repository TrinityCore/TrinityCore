-- Quest 12180 "The Captive Prospectors" 37013
-- Creature updates
UPDATE `creature` SET `spawntimesecs`=120 WHERE `id` IN (27113,27114,27115);
UPDATE `creature_template` SET `InhabitType`=1 WHERE `entry` IN (27113,27114,27115);
-- SAI for Prospector Gann
SET @ENTRY := 27113; -- NPC entry
SET @SPELL := 47978; -- Open Dun Argol Cage
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,8,0,100,0,@SPELL,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Gann - On Spellhit - Run script'),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,1000,1000,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Gann - Script - set run'),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,1000,1000,69,0,0,0,0,0,0,1,0,0,0,3579.263,-5125.724,167.1185,0,'Prospector Gann - Script - Moveto'),
(@ENTRY*100,9,2,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Gann - Script - Say 0'),
(@ENTRY*100,9,3,0,0,0,100,0,5000,5000,5000,5000,69,0,0,0,0,0,0,1,0,0,0,3600.135,-5119.964,166.4886,0,'Prospector Gann - Script - Moveto'),
(@ENTRY*100,9,4,0,0,0,100,0,2000,2000,2000,2000,32,0,0,0,0,0,0,14,59407,188554,0,0,0,0,0,'Prospector Gann - Script - reset go'),
(@ENTRY*100,9,5,0,0,0,100,0,1000,1000,1000,1000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Gann - Script - despawn');
-- SAI for Prospector Torgan
SET @ENTRY := 27114; -- NPC entry
SET @SPELL := 47978; -- Open Dun Argol Cage
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,8,0,100,0,@SPELL,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Torgan - On Spellhit - Run script'),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,1000,1000,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Torgan - Script - set run'),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,1000,1000,69,0,0,0,0,0,0,1,0,0,0,3467.921,-5114.096,236.9127,0,'Prospector Torgan - Script - Moveto'),
(@ENTRY*100,9,2,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Torgan - Script - Say 0'),
(@ENTRY*100,9,3,0,0,0,100,0,5000,5000,5000,5000,69,0,0,0,0,0,0,1,0,0,0,3489.064,-5102.472,236.8901,0,'Prospector Torgan - Script - Moveto'),
(@ENTRY*100,9,4,0,0,0,100,0,2000,2000,2000,2000,32,0,0,0,0,0,0,14,59409,188554,0,0,0,0,0,'Prospector Torgan - Script - reset go'),
(@ENTRY*100,9,5,0,0,0,100,0,1000,1000,1000,1000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Torgan - Script - despawn');
-- SAI for Prospector Varana
SET @ENTRY := 27115; -- NPC entry
SET @SPELL := 47978; -- Open Dun Argol Cage
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,8,0,100,0,@SPELL,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Varana - On Spellhit - Run script'),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,1000,1000,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Varana - Script - set run'),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,1000,1000,69,0,0,0,0,0,0,1,0,0,0,3379.451,-5100.344,326.5531,0,'Prospector Varana - Script - Moveto'),
(@ENTRY*100,9,2,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Varana - Script - Say 0'),
(@ENTRY*100,9,3,0,0,0,100,0,5000,5000,5000,5000,69,0,0,0,0,0,0,1,0,0,0,3375.131,-5065.586,326.4890,0,'Prospector Varana - Script - Moveto'),
(@ENTRY*100,9,4,0,0,0,100,0,2000,2000,2000,2000,32,0,0,0,0,0,0,14,59408,188554,0,0,0,0,0,'Prospector Varana - Script - reset go'),
(@ENTRY*100,9,5,0,0,0,100,0,1000,1000,1000,1000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Varana - Script - despawn');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (27113,27114,27115) AND `groupid` IN (0);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(27113,0,0, 'Thank you for rescuing me, but the others are still held on the tiers above!',12,0,100,1,0,0, 'Prospector Gann'),
(27114,0,0, 'Thank goodness! I was worried they were going to press me into service in their war against the stone giants!',12,0,100,1,0,0, 'Prospector Torgan'),
(27115,0,0, 'These irons are crazy! They keep talking about serving their ''master Loken'' but from what I can tell, only a few receive orders from him.',12,0,100,1,0,0, 'Prospector Varana');
-- Made in Canada. Export to EU forbidden.
