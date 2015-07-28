DELETE FROM `gameobject_scripts` WHERE `id`=47301;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=185512;
DELETE FROM `smart_scripts` WHERE `entryorguid`=185512 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18551200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(185512,1,0,0,70,0,100,0,2,0,0,0,80,18551200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stasis Chamber Alpha - On Activate - Start Script'),
(18551200,9,0,0,0,0,100,0,10000,10000,0,0,12,22920,1,300000,0,1,0,8,0,0,0,3989.02,6071.37,266.41,3.72,'Script - After 10s - Summon Thuk the Defiant');
