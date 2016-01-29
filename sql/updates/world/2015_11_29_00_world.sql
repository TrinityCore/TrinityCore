-- Talbuk Doe SAI
SET @ENTRY := 20610; -- Talbuk Doe
SET @SPELL_GORE := 32019; -- Gore
SET @SPELL_TAG := 35771; -- Tag Subbued Talbuk
SET @SPELL_TAG_CREDIT := 40347; -- Talbuk Tagging Credit
SET @SPELL_SLEEPING := 14915; -- Sleeping Sleep
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Doe - On Aggro - Say text 0"),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,8000,11000,11,@SPELL_GORE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talbuk Doe - In Combat - Cast Gore"),
(@ENTRY,0,2,0,2,0,100,1,0,20,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Doe - At 20% HP - Say Text 1"),
(@ENTRY,0,5,0,4,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,20777,30,0,0,0,0,0,"Talbuk Doe - On Aggro - Set data"),
(@ENTRY,0,3,0,8,0,100,0,@SPELL_TAG,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Doe - On Spellhit - Run Script"),
(@ENTRY,0,4,0,11,0,100,0,0,0,0,0,19,386,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Doe - On Respawn - Remove Unit Flag"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,85,@SPELL_TAG_CREDIT ,0,0,0,0,0,7,0,0,0,0,0,0,0,"Talbuk Doe - Script - Give Quest Credit"),
(@ENTRY*100,9,1,0,0,0,100,1,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Doe - Script - Stop combat"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,18,386,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Doe - Script - Set Unit Flag"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,11,@SPELL_SLEEPING,1,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Doe - Script - Cast Sleeping Sleep"),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,11,55795,1,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Doe - Script - Cast visual death state"),
(@ENTRY*100, 9, 5, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Talbuk Doe - On Script - Despawn');

-- Talbuk Sire SAI
SET @ENTRY := 20777; -- Talbuk Sire
SET @SPELL_STOMP := 32023; -- Hoof Stomp
SET @SPELL_TAG := 35771; -- Tag Subbued Talbuk
SET @SPELL_SLEEPING := 14915; -- Sleeping Sleep
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,8000,11000,11,@SPELL_STOMP,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talbuk Sire - In Combat - Cast Hoof Stomp"),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Sire - At 20% HP - Say Text 0"),
(@ENTRY,0,4,0,38,0,100,0,0,1,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,"Talbuk Sire - On data set - Start attack"),
(@ENTRY,0,2,0,8,0,100,0,@SPELL_TAG,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Sire - On Spellhit - Run Script"),
(@ENTRY,0,3,0,11,0,100,0,0,0,0,0,19,386,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Sire - On Respawn - Remove Unit Flag"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,85,@SPELL_TAG_CREDIT ,0,0,0,0,0,7,0,0,0,0,0,0,0,"Talbuk Sire - Script - Give Quest Credit"),
(@ENTRY*100,9,1,0,0,0,100,1,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Sire - Script - Stop combat"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,18,386,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Sire - Script - Set Unit Flag"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,11,@SPELL_SLEEPING,1,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Sire - Script - Cast Sleeping Sleep"),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,11,55795,1,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Sire - Script - Cast visual death state"),
(@ENTRY*100, 9, 5, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Talbuk Sire - On Script - Despawn');
