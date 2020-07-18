-- 
UPDATE `smart_scripts` SET `target_type`=23 WHERE `source_type`=9 AND `entryorguid`=2878000 AND `id` IN (6); 
DELETE FROM `smart_scripts` WHERE `entryorguid`=2878000 AND `source_type`=9 AND `id` IN (7,8);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2878000, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 20, 190731, 15, 0, 0, 0, 0, 0, "Explosive Charges Bunny - On Script - despawn gob"),
(2878000, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 20, 190732, 15, 0, 0, 0, 0, 0, "Explosive Charges Bunny - On Script - despawn gob");
