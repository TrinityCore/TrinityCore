--
UPDATE `smart_scripts` SET `event_flags`= 1 WHERE `entryorguid` = 27003 AND `source_type` = 0 AND `id` = 2;
UPDATE `smart_scripts` SET `event_param1`= 5000, `event_param2` = 5000 WHERE `entryorguid` = 2700300 AND `source_type` = 9 AND `id` IN (7, 6);
UPDATE `smart_scripts` SET `action_type`= 20, `Comment`="Dregmar Runebrand - Stop Attack" WHERE `entryorguid`=2700300 AND `source_type` = 9 AND `id` = 1;
UPDATE `smart_scripts` SET `action_type`= 20, `action_param1`= 1, `Comment`='Dregmar Runebrand - Start Attack' WHERE `entryorguid`= 2700300 AND `source_type` = 9 AND `id` = 8;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2700300 AND `source_type` = 9 AND `id` IN (9, 10);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2700300,9,9,0,0,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - enable movement'),
(2700300,9,10,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - force despawn');
