DELETE FROM `gameobject_scripts` WHERE `id` IN (24397,24398,25980,26188,26192);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (101831,101832,101833,101834,183517,183518,185123);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (101831,101832,101833,101834,183517,183518,185123) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(101831,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,30533,13965,0,0,0,0,0, 'Door Lever - On activate - Activate Factory Door'),
(101832,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,26185,17153,0,0,0,0,0, 'Door Lever - On activate - Activate Heavy Door'),
(101833,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,30534,16397,0,0,0,0,0, 'Door Lever - On activate - Activate Iron Clad Door'),
(101834,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,26182,17153,0,0,0,0,0, 'Door Lever - On activate - Activate Heavy Door'),
(183517,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,25826,184912,0,0,0,0,0, 'Lever - On activate - Activate The Shattered Halls'),
(183518,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,24141,183294,0,0,0,0,0, 'Lever - On activate - Activate The Shadow Labyrinth'),
(185123,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,25083,184246,0,0,0,0,0, 'Lever - On activate - Activate Heavy Iron Portcullis');
