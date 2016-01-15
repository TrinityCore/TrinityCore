-- 
-- Defias Conjurer SAI "Comments and event_flags fix"
SET @ENTRY := 619;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Conjurer - Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - On Health - Flee for assist (No Repeat)");

-- Crushridge Warmonger SAI "Comments and event_flags fix"
SET @ENTRY := 2287;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Warmonger - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,39,15,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Warmonger - Between 0-50% Health - Call For Help (No Repeat)"),
(@ENTRY,0,2,3,74,0,100,1,0,15,0,0,11,8269,1,0,0,0,0,9,0,0,0,0,0,0,0,"Crushridge Warmonger - On Friendly Between 0-15% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Warmonger - On Friendly Between 0-15% Health - Say Line 1 (No Repeat)");

-- Dustbelcher Lord SAI "Line numbering and event_flags fix"
SET @ENTRY := 2719;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7800,12100,11200,30000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Lord - In Combat - Cast 'Battle Shout'"),
(@ENTRY,0,1,0,0,0,100,0,6600,18700,30800,32400,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Lord - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,39,15,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Lord - Between 0-50% Health - Call For Help (No Repeat)");

-- Duggan Wildhammer & Sentinel Leader & Dal Bloodclaw SAI "event_flags fix"
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `entryorguid` IN (10817,17210) AND `source_type`=0 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `entryorguid` IN (3987) AND `source_type`=0 AND `id`=1;
