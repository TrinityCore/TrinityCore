-- Arcane Wraith SAI
SET @ENTRY := 15273;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,28730,0,0,0,27,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Arcane Wraith - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,1,0,8,0,100,1,25046,0,0,0,27,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Arcane Wraith - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,2,0,0,0,100,0,10100,16500,12700,24800,11,37361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Wraith - In Combat - Cast Arcane Bolt");

-- Mana Wyrm SAI
SET @ENTRY := 15274;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,28730,0,0,0,27,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Mana Wyrm - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,1,0,8,0,100,1,25046,0,0,0,27,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Mana Wyrm - On Spellhit Arcane Torrent - Quest Credit");

-- Feral Tender SAI
SET @ENTRY := 15294;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,28730,0,0,0,27,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Feral Tender - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,1,0,8,0,100,1,25046,0,0,0,27,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Feral Tender - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,2,0,2,0,100,0,0,50,15300,22900,11,31325,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feral Tender - At 50% HP - Cast Renew");

-- Tainted Arcane Wraith SAI
SET @ENTRY := 15298;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,28730,0,0,0,27,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Tainted Arcane Wraith - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,1,0,8,0,100,1,25046,0,0,0,27,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Tainted Arcane Wraith - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,2,0,0,0,100,0,9000,18800,21100,32200,11,25603,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tainted Arcane Wraith - In Combat - Cast Slow");
