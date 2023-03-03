-- Bramblefist the Maddened
SET @ENTRY := 129847;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,277599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Quaking Stomp');

-- Briarback Thornmatron
SET @ENTRY := 135155;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,270453,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,265501,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Thornshape');

-- Wagga Snarltusk <Briarback Mystic>
SET @ENTRY := 130079;
SET @ENTRYTOTEM := 137585;
SET @TOTEMSPELL := 8377;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,25000,37000,11,270474,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earthgrab Totem'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,3500,11,270453,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Bolt'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,270494,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rumbling Earth');