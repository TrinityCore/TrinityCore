-- Bloodfen Raptor SAI
SET @ENTRY := 4351;
SET @SPELL_ROPE := 42325;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,@SPELL_ROPE,0,0,0,33,23727,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodfen Raptor - On Spellhit - Quest Credit"),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfen Raptor - At 20% HP - Say Line 0");

-- Bloodfen Screecher SAI
SET @ENTRY := 4352;
SET @SPELL_ROPE := 42325;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,@SPELL_ROPE,0,0,0,33,23727,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodfen Screecher - On Spellhit - Quest Credit"),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfen Screecher - At 20% HP - Say Line 0");

-- Texts
DELETE FROM `creature_text` WHERE `entry` IN (4351,4352);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(4351,0,0,"%s looks weak enough to capture.",16,0,100,0,0,0,"Bloodfen Raptor"),
(4352,0,0,"%s looks weak enough to capture.",16,0,100,0,0,0,"Bloodfen Screecher");
