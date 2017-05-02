-- Cuergo's Gold quest spawns by nelegalno
-- TODO: Rewrite once it is possible to summon NPC's in positions relative to the summoner's location
-- Closes #1677

SET @ENTRY := 7898;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,12,7901,6,300000,0,1,0,18,40,0,0,0,0,0,0,'Pirate treasure trigger mob - Summon Treasure Hunting Swashbuckler'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,12,7902,6,300000,0,1,0,18,40,0,0,0,0,0,0,'Pirate treasure trigger mob - Summon Treasure Hunting Buccaneer 1'),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,12,7902,6,300000,0,1,0,18,40,0,0,0,0,0,0,'Pirate treasure trigger mob - Summon Treasure Hunting Buccaneer 2'),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,12,7902,6,300000,0,1,0,18,40,0,0,0,0,0,0,'Pirate treasure trigger mob - Summon Treasure Hunting Buccaneer 3'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,12,7899,6,300000,0,1,0,18,40,0,0,0,0,0,0,'Pirate treasure trigger mob - Summon Treasure Hunting Pirate');
