-- 7th Legion Rifleman SAI (replaces EAI)
SET @ENTRY   := 27791; -- NPC entry
SET @SPELL1  := 62312; -- Cast Net
SET @SPELL2  := 50092; -- Cast Shoot
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Rifleman - On Aggro - Cast Net"),
(@ENTRY,0,1,0,0,0,100,0,500,3500,5000,6000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0,"7th Legion Rifleman - In Combat - Cast Shoot"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"7th Legion Rifleman - At 15% HP - Flee");