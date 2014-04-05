--
UPDATE `smart_scripts` SET `event_type`=11 WHERE  `entryorguid`=9546 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=954600 AND `source_type`=9 AND `id`=2;

DELETE FROM `smart_scripts` WHERE `entryorguid`=164954 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16495400 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(164954,1,0,1,19,0,100,0,4265,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Zukk'ash Pod - On Quest Accept - Store Target List"),
(164954,1,1,2,61,0,100,0,0,0,0,0,12,9546,1,25000,0,0,0,8,0,0,0,-5314.81,430.89,11.79,3.46,"Zukk'ash Pod - On Quest Accept - Summon Raschal the Courier"),
(164954,1,2,0,61,0,100,0,0,0,0,0,80,16495400,2,0,0,0,0,1,0,0,0,0,0,0,0,"Zukk'ash Pod - On Quest Accept - Run Script"),
(16495400,9,0,0,0,0,100,0,100,100,0,0,100,1,0,0,0,0,0,19,9546,0,0,0,0,0,0,"Zukk'ash Pod - Script - Send Target List to Raschal the Courier");
