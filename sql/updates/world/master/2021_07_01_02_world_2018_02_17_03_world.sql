-- 
UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid` IN (31135,3113500,3113501,3113502,3113503,3113504,3113505,3113506) AND `source_type` IN (0,9) AND `target_type`=7;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31135) AND `source_type`=0 AND `id`=42;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(31135, 0, 42, 0, 19, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Geirrvif - On quest taken - Store target");
