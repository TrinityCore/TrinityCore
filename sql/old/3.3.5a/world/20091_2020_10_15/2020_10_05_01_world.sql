--
UPDATE `smart_scripts` SET `link` = 1, `target_type` = 20, `target_param1` = 175610, `target_param2` = 0, `comment` = "Torch - On Gameobject State Changed - Activate Closest Gameobject 'Door'" WHERE `entryorguid` = 177385 AND `source_type` = 1 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 177385 AND `source_type` = 1 AND `id` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(177385,1,1,0,61,0,100,0,0,0,0,0,0,106,16,0,0,0,0,0,20,176944,0,0,0,0,0,0,0,"Torch - On Link - Remove Gameobject Flag Not Selectable (Old Treasure Chest)");
