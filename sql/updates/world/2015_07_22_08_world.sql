-- 4.x + 6.x
-- Update Eversong Woods

-- Mana Wyrm SAI
SET @ENTRY := 15274;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,28730,0,0,0,11,61314,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mana Wyrm - On Spellhit 'Arcane Torrent' - Cast 'Quest Credit 8346' (No Repeat)"),
(@ENTRY,0,1,0,8,0,100,1,25046,0,0,0,11,61314,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mana Wyrm - On Spellhit 'Arcane Torrent' - Cast 'Quest Credit 8346' (No Repeat)"),
(@ENTRY,0,2,0,8,0,100,1,50613,0,0,0,11,61314,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mana Wyrm - On Spellhit 'Arcane Torrent' - Cast 'Quest Credit 8346' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,12000,12000,11,25602,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Wyrm - In Combat - Cast 'Faerie Fire'");

-- Felendren the Banished SAI
SET @ENTRY := 15367;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felendren the Banished - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,9100,10600,20500,28600,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felendren the Banished - In Combat - Cast 'Mind Flay'");

-- NPC talk text insert
DELETE FROM `creature_text` WHERE `entry` IN (15367);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`BroadcastTextId`,`comment`) VALUES
(15367,0,0, 'Take heart! Your friends will not long mourn your passing!',12,0,100,0,0,10986, 'text say');

-- Grimscale Murloc SAI
SET @ENTRY := 15668;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimscale Murloc - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Ranger Jaela SAI
SET @ENTRY := 15416;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,9,0,0,0,100,0,0,0,3400,4700,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger Jaela - In Combat - Cast 'Fireball'");

-- Wretched Hooligan SAI
SET @ENTRY := 16162;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8800,13700,9900,19500,11,29098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Hooligan - In Combat - Cast 'Bitter Withdrawal'"),
(@ENTRY,0,1,0,0,0,100,0,9900,12900,11900,17500,11,14873,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Hooligan - In Combat - Cast 'Sinister Strike'");

-- Wretched Thug SAI
SET @ENTRY := 15645;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Thug - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,1500,7900,5700,16100,11,29098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Thug - In Combat - Cast 'Bitter Withdrawal'");

-- NPC talk text insert
DELETE FROM `creature_text` WHERE `entry` IN (15645);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`BroadcastTextId`,`comment`) VALUES
(15645,0,0,'The pain...the need...I hunger for more...',12,10,100,0,0,12149,'Wretched Thug'),
(15645,0,1,'I cannot stand the pain.  I must find a new source.',12,10,100,0,0,12151,'Wretched Thug'),
(15645,0,2,'More, more, more!  I must feed soon.',12,10,100,0,0,12150,'Wretched Thug');
