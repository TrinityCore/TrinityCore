-- 
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE entry IN (29364,29365);
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554560 WHERE `entry`=29365;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|2 WHERE `entry`=29364;

-- Void Sentry SAI
SET @ENTRY := 29365;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,2,25,0,100,2,0,0,0,0,11,54342,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Sentry - On Reset - Cast 'Zuramat Add 2' (Normal Dungeon)"),
(@ENTRY,0,1,2,25,0,100,4,0,0,0,0,11,59747,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Sentry - On Reset - Cast 'Zuramat Add 2' (Heroic Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,54351,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Sentry - On Reset - Cast 'Zuramat Add' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Sentry - In Combat - Disable Combat Movement"),
(@ENTRY,0,4,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Sentry - On Data Set 1 1 - Despawn Instant");

-- Void Sentry SAI
SET @ENTRY := 29364;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Sentry - In Combat - Disable Combat Movement"),
(@ENTRY,0,1,2,25,0,100,0,0,0,0,0,11,54341,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Sentry - On Reset - Cast 'Zuramat Add'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,54351,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Sentry - On Reset - Cast 'Zuramat Add'"),
(@ENTRY,0,3,0,11,0,100,0,0,0,0,0,11,58650,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Sentry - On Respawn - Cast 'Summon Void Sentry Ball'"),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,29365,10,0,0,0,0,0,"Void Sentry - On Just Died - Set Data 1 1");
