-- 
SET @ENTRY := 3584;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`>=5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,5,7,61,0,100,0,945,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Therylune - On Quest 'Therylune's Escape' Taken - Set Faction 250"),
(@ENTRY,0,6,8,11,0,100,0,0,0,0,0,2,124,0,0,0,0,0,1,0,0,0,0,0,0,0,"Therylune - On Respawn - Set Faction 124"),
(@ENTRY,0,7,9,61,0,100,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Therylune - On Quest 'Therylune's Escape' Taken - Remove Flags Immune To NPC's"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Therylune - On Respawn - Set Flags Immune To NPC's"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Therylune - On Quest 'Therylune's Escape' Taken - Remove npc flag");
UPDATE `smart_scripts` SET `link`=5 WHERE  `entryorguid`=3584 AND `source_type`=0 AND `id`=1 AND `link`=0;
