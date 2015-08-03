-- Invis BE Ballista SAI
SET @ENTRY := 19723;
SET @SPELL_BURN_BLOOD_ELF := 34526;
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=`flags_extra`|130 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_BURN_BLOOD_ELF,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Invis BE Ballista - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,50,181915,20000,0,0,0,0,1,0,0,0,0,0,0,0,"Invis BE Ballista - Script - Summon Blaze (fire)"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,8,0,0,0,0,0,0,0,"Invis BE Ballista - Script - Despawn");

-- Invis BE Tent SAI
SET @ENTRY := 19724;
SET @SPELL_BURN_BLOOD_ELF := 34526;
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=`flags_extra`|130 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_BURN_BLOOD_ELF,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Invis BE Tent - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,50,181915,20000,0,0,0,0,1,0,0,0,0,0,0,0,"Invis BE Tent - Script - Summon Blaze (fire)"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,8,0,0,0,0,0,0,0,"Invis BE Tent - Script - Despawn");
