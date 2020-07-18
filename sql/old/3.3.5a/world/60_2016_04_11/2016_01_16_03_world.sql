--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29333;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=29333;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (29329, 29330, 29338) AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29329,0,2,0,8,0,100,0,52741,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Paladin - On spell hit "Darkmender''s Tincture" - Despawn'),
(29330,0,2,0,8,0,100,0,52741,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Harbor Guard - On spell hit "Darkmender''s Tincture" - Despawn'),
(29338,0,2,0,8,0,100,0,52741,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Raven Bishop - On spell hit "Darkmender''s Tincture" - Despawn'),
(29333,0,0,0,8,0,100,0,52741,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Gryphon Rider - On spell hit "Darkmender''s Tincture" - Despawn');

UPDATE `spell_scripts` SET `datalong2`=2, `dataint`=0 WHERE `id`=52741 AND `command`=15;
