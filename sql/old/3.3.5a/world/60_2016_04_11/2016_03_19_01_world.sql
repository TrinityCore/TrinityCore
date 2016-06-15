UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', scriptname='' WHERE `entry` IN (177243, 177365, 177366, 177367, 177368, 177369, 177397, 177398, 177399, 177400);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (177243, 177365, 177366, 177367, 177368, 177369, 177397, 177398, 177399, 177400) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17724300, 17736500, 17736600, 17736700, 17736800, 17736900, 17739700, 17739800, 17739900, 17740000) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES

(177243,1,0,0,70,0,100,0,2,0,0,0,80,17724300,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(17724300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 11937, 3, 60000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - summon'),
(17724300, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17724300, 9, 2, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17724300, 9, 3, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 99, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - Reset'),

(177365,1,0,0,70,0,100,0,2,0,0,0,80,17736500,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(17736500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 11937, 3, 60000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - summon'),
(17736500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17736500, 9, 2, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17736500, 9, 3, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 99, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - Reset'),

(177366,1,0,0,70,0,100,0,2,0,0,0,80,17736600,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(17736600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 11937, 3, 60000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - summon'),
(17736600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17736600, 9, 2, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17736600, 9, 3, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 99, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - Reset'),

(177367,1,0,0,70,0,100,0,2,0,0,0,80,17736700,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(17736700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 11937, 3, 60000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - summon'),
(17736700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17736700, 9, 2, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17736700, 9, 3, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 99, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - Reset'),

(177368,1,0,0,70,0,100,0,2,0,0,0,80,17736800,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(17736800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 11937, 3, 60000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - summon'),
(17736800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17736800, 9, 2, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17736800, 9, 3, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 99, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - Reset'),

(177369,1,0,0,70,0,100,0,2,0,0,0,80,17736900,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(17736900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 11937, 3, 60000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - summon'),
(17736900, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17736900, 9, 2, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17736900, 9, 3, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 99, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - Reset'),

(177397,1,0,0,70,0,100,0,2,0,0,0,80,17739700,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(17739700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 11937, 3, 60000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - summon'),
(17739700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17739700, 9, 2, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17739700, 9, 3, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 99, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - Reset'),

(177398,1,0,0,70,0,100,0,2,0,0,0,80,17739800,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(17739800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 11937, 3, 60000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - summon'),
(17739800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17739800, 9, 2, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17739800, 9, 3, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 99, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - Reset'),

(177399,1,0,0,70,0,100,0,2,0,0,0,80,17739900,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(17739900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 11937, 3, 60000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - summon'),
(17739900, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17739900, 9, 2, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17739900, 9, 3, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 99, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - Reset'),

(177400,1,0,0,70,0,100,0,2,0,0,0,80,17740000,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(17740000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 11937, 3, 60000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - summon'),
(17740000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17740000, 9, 2, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - despawn'),
(17740000, 9, 3, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 99, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'demon portal - ActionList - Reset');
