DELETE FROM `gameobject_scripts` WHERE `id` IN (43177,44809,44811,45625,45428,61664);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (193020,175432,176767,101852,101853,177385);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (193020,175432,176767,101852,101853,177385) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(193020,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,61606,193019,0,0,0,0,0, 'Lever - On activate - Activate The Violet Hold'),
(175432,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,45626,175369,0,0,0,0,0, ' - On activate - Activate Elders Square Service Entrance'),
(176767,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,45427,174626,0,0,0,0,0, 'Torch - On activate - Activate Scholomance Door'),
(101852,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,15013,101851,0,0,0,0,0, 'Lever - On activate - Activate Armory Door'),
(101853,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,15012,101850,0,0,0,0,0, 'Lever - On activate - Activate Cathedral Door'),
(177385,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,43178,175610,0,0,0,0,0, 'Torch - On activate - Activate Door');
