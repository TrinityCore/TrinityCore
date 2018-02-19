-- 
UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE `event_type`=52 AND `source_type`=0 AND `action_type`=11 AND `action_param1`=63010 AND `target_type`=7;
UPDATE smart_scripts SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid` IN (3328500, 3374500) AND `source_type`=9 AND `id`=10;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4488 AND `source_type` = 0 AND id IN (20,21,22,23);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4488,0, 20, 0, 62,0,100,0, 4764, 0,0,0, 64, 1, 0,0,0,0,0, 7, 0, 0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 0 Selected - Store target'),
(4488,0, 21, 0, 62,0,100,0, 4764, 1,0,0, 64, 1, 0,0,0,0,0, 7, 0, 0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 1 Selected - Store target'),
(4488,0, 22, 0, 62,0,100,0, 4764, 2,0,0, 64, 1, 0,0,0,0,0, 7, 0, 0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 2 Selected - Store target'),
(4488,0, 23, 0, 62,0,100,0, 4764, 3,0,0, 64, 1, 0,0,0,0,0, 7, 0, 0,0,0,0,0,0,'Parqual Fintallas - On Gossip Option 3 Selected - Store target');
UPDATE smart_scripts SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid` IN (4488) AND `source_type`=0 AND `id`IN (3,4,9,13);
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid` IN (18417) AND `source_type`=0 AND `id`IN (6);
