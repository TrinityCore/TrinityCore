-- 
-- Tome of Mel'Thandris SAI
SET @ENTRY := 19027;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,12,3946,2,40000,0,0,0,8,0,0,0,3169.15,-1211.71,216.95,4.59,"Tome of Mel'Thandris - On Gameobject State Changed - Summon Creature 'Velinde Starsong'");

UPDATE `creature_template` SET `AIName`='' WHERE  `entry`=11789;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-56500;
