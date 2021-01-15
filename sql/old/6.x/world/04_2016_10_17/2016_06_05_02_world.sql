-- Pile of Corpses
SET @ENTRY := 59722;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,6,0,0,0,0,11,114951,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pile of Corpses - Cast Pile of Corpses On Reset"),
(@ENTRY,0,1,0,0,0,100,6,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Pile of Corpses -  Set React Passive on Reset.");


-- Scarlet Centurion SAI
SET @ENTRY := 59746;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,15000,15000,35000,35000,11,115511,2,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Centurion - On IC Timer - Cast Retaliation."),
(@ENTRY,0,1,0,1,0,100,6,1000,1000,1000,1000,49,0,0,0,0,0,0,11,59771,20,0,0,0,0,0,"Scarlet Centurion - On OOC Timer - Attack Start on Zombified Corpse."),
(@ENTRY,0,2,0,0,0,100,6,7000,7000,16000,16000,11,115519,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Centurion - On IC Timer - Cast Cleave.");


-- Scarlet Flamethrower SAI
SET @ENTRY := 59705;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7000,7000,20000,20000,11,115506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Flamethrower - On IC Timer - Cast Flamethrower."),
(@ENTRY,0,1,0,1,0,100,6,1000,1000,1000,1000,49,0,0,0,0,0,0,11,59771,20,0,0,0,0,0,"Scarlet Flamethrower - On OOC Timer - Attack Start on Zombified Corpse.");
