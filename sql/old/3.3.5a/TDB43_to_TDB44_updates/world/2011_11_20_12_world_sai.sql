-- [Q] Rivenwood Captives

-- Riven Widow Cocoon SAI
SET @ENTRY := 24210;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature` SET `MovementType`=0,`spawndist`=0 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,6,0,25,0,0,0,0,0,12,24211,2,8000,0,0,0,1,0,0,0,0,0,0,0,"Riven Widow Cocoon - On Death - Summon Freed Winterhoof Longrunner (25%)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,24211,0,0,0,0,0,7,0,0,0,0,0,0,0,"Riven Widow Cocoon - On Death - Quest Credit");

-- Freed Winterhoof Longrunner SAI
SET @ENTRY := 24211;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Freed Winterhoof Longrunner - Just Summoned - Say Line 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Freed Winterhoof Longrunner - Just Summoned - Forced Desoawn");

-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Blessings of the spirits of the land and air upon you.",12,0,100,1,0,0,"Freed Winterhoof Longrunner"),
(@ENTRY,0,1,"I must return. Good hunting to you.",12,0,100,1,0,0,"Freed Winterhoof Longrunner"),
(@ENTRY,0,2,"I owe you a life debt, stranger.",12,0,100,1,0,0,"Freed Winterhoof Longrunner"),
(@ENTRY,0,3,"Strange ghosts walk the land. Be careful!",12,0,100,1,0,0,"Freed Winterhoof Longrunner"),
(@ENTRY,0,4,"Thank you, stranger.",12,0,100,1,0,0,"Freed Winterhoof Longrunner"),
(@ENTRY,0,5,"They took us one by one. I'm sure there are other survivors.",12,0,100,1,0,0,"Freed Winterhoof Longrunner"),
(@ENTRY,0,6,"We should never have traveled through the Rivenwood. Everyone knows this!",12,0,100,1,0,0,"Freed Winterhoof Longrunner"),
(@ENTRY,0,7,"You saved me from certain death. I owe you.",12,0,100,1,0,0,"Freed Winterhoof Longrunner");
