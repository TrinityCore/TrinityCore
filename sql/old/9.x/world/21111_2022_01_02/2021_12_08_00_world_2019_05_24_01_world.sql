-- Demon Portal SAI
UPDATE `gameobject` SET `spawntimesecs`=120 WHERE `id` IN (177243, 177365, 177366, 177367, 177368, 177369, 177397, 177398, 177399, 177400);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (177243, 177365, 177366, 177367, 177368, 177369, 177397, 177398, 177399, 177400) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17724300, 17736500, 17736600, 17736700, 17736800, 17736900, 17739700, 17739800, 17739900, 17740000) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(177243,1,0,0,70,0,100,0,2,0,0,0,80,17724300,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(177243,1,1,0,35,0,100,0,11937,5000,5000,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on Summon despawned - Remove flag'),
(177365,1,0,0,70,0,100,0,2,0,0,0,80,17724300,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(177365,1,1,0,35,0,100,0,11937,5000,5000,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on Summon despawned - Remove flag'),
(177366,1,0,0,70,0,100,0,2,0,0,0,80,17724300,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(177366,1,1,0,35,0,100,0,11937,5000,5000,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on Summon despawned - Remove flag'),
(177367,1,0,0,70,0,100,0,2,0,0,0,80,17724300,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(177367,1,1,0,35,0,100,0,11937,5000,5000,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on Summon despawned - Remove flag'),
(177368,1,0,0,70,0,100,0,2,0,0,0,80,17724300,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(177368,1,1,0,35,0,100,0,11937,5000,5000,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on Summon despawned - Remove flag'),
(177369,1,0,0,70,0,100,0,2,0,0,0,80,17724300,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(177369,1,1,0,35,0,100,0,11937,5000,5000,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on Summon despawned - Remove flag'),
(177397,1,0,0,70,0,100,0,2,0,0,0,80,17724300,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(177397,1,1,0,35,0,100,0,11937,5000,5000,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on Summon despawned - Remove flag'),
(177398,1,0,0,70,0,100,0,2,0,0,0,80,17724300,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(177398,1,1,0,35,0,100,0,11937,5000,5000,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on Summon despawned - Remove flag'),
(177399,1,0,0,70,0,100,0,2,0,0,0,80,17724300,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(177399,1,1,0,35,0,100,0,11937,5000,5000,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on Summon despawned - Remove flag'),
(177400,1,0,0,70,0,100,0,2,0,0,0,80,17724300,2,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on state change - Call Timed ActionList'),
(177400,1,1,0,35,0,100,0,11937,5000,5000,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'demon portal - on Summon despawned - Remove flag'),
(17724300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 11937, 4, 30000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Demon portal - ActionList - summon Demon Portal Guardian'),
(17724300, 9, 1, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 105, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Demon portal - ActionList - Set gob flag'),
(17724300, 9, 2, 0, 0, 0, 100, 0, 120000, 120000, 0, 0, 106, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Demon portal - ActionList - Remove gob flag');
-- Demon Portal Guardian
DELETE FROM `smart_scripts` WHERE `entryorguid`=11937 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(11937, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 30, 0, 0, 0, 0, 0, 0, 'Demon Portal Guardian - On Just summoned - Attack'),
(11937, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Demon Portal Guardian - On death - Despawn summoner'),
(11937, 0, 2, 0, 21, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Demon Portal Guardian - On homepos - remove flag'),
(11937, 0, 3, 0, 21, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demon Portal Guardian - On homepos - Despawn');
