-- Acidic Swamp Ooze SAI
SET @ENTRY := 4393;
SET @SPELL_END_CHANNEL := 42485;
SET @SPELL_BUBBLING_OOZE := 43135;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,@SPELL_END_CHANNEL,0,0,0,33,23797,0,0,0,0,0,7,0,0,0,0,0,0,0,"Acidic Swamp Ooze - On Spellhit - Quest Credit"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,11,@SPELL_BUBBLING_OOZE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Acidic Swamp Ooze - At 15% HP - Cast Bubbling Ooze");

-- Bubbling Swamp Ooze SAI
SET @ENTRY := 4394;
SET @SPELL_END_CHANNEL := 42485;
SET @SPELL_BUBBLING_OOZE := 43135;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,@SPELL_END_CHANNEL,0,0,0,33,23797,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bubbling Swamp Ooze - On Spellhit - Quest Credit"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,11,@SPELL_BUBBLING_OOZE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bubbling Swamp Ooze - At 15% HP - Cast Bubbling Ooze");
