-- [Q] Laying Waste to the Unwanted

-- Invis Horde Siege Engine - West SAI
SET @ENTRY := 19009;
SET @SPELL_IGNITE_SIEGE := 32979;
SET @SPELL_HELLFIRE_FIRE := 34386;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature` SET `position_x`=-183.947998,`position_y`=2773.389893,`position_z`=49.198399 WHERE `guid`=68321 AND `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,@SPELL_IGNITE_SIEGE,0,60000,60000,11,@SPELL_HELLFIRE_FIRE,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invis Horde Siege Engine - West - On Spellhit - Cast Create Hellfire Fire"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,@ENTRY,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invis Horde Siege Engine - West - On Spellhit - Quest Credit");

-- Invis Horde Siege Engine - West 02 SAI
SET @ENTRY := 21236;
SET @SPELL_IGNITE_SIEGE := 32979;
SET @SPELL_HELLFIRE_FIRE := 34386;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature` SET `position_z`=43.094120 WHERE `guid`=74454 AND `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,@SPELL_IGNITE_SIEGE,0,60000,60000,11,@SPELL_HELLFIRE_FIRE,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invis Horde Siege Engine - West 02 - On Spellhit - Cast Create Hellfire Fire"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,@ENTRY,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invis Horde Siege Engine - West 02 - On Spellhit - Quest Credit");

-- Invis Horde Siege Engine - East SAI
SET @ENTRY := 21237;
SET @SPELL_IGNITE_SIEGE := 32979;
SET @SPELL_HELLFIRE_FIRE := 34386;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature` SET `position_x`=-157.329712,`position_y`=2518.655273,`position_z`=58.221237 WHERE `guid`=67186 AND `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,@SPELL_IGNITE_SIEGE,0,60000,60000,11,@SPELL_HELLFIRE_FIRE,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invis Horde Siege Engine - East - On Spellhit - Cast Create Hellfire Fire"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,@ENTRY,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invis Horde Siege Engine - East - On Spellhit - Quest Credit");

-- Invis Horde Siege Engine - East 02 SAI
SET @ENTRY := 18818;
SET @SPELL_IGNITE_SIEGE := 32979;
SET @SPELL_HELLFIRE_FIRE := 34386;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature` SET `position_x`=-152.163116,`position_y`=2662.497314,`position_z`=60.728378 WHERE `guid`=74455 AND `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,@SPELL_IGNITE_SIEGE,0,60000,60000,11,@SPELL_HELLFIRE_FIRE,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invis Horde Siege Engine - East 02 - On Spellhit - Cast Create Hellfire Fire"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,@ENTRY,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invis Horde Siege Engine - East 02 - On Spellhit - Quest Credit");
