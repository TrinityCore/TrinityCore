UPDATE `creature_template` SET `unit_flags`=768,`AIName`='SmartAI' WHERE  `entry`=29775;

DELETE FROM `smart_scripts` WHERE `entryorguid` =2977500 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29775 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29775,0,0,0,54,0,100,0,0,0,0,0,80,2977500,2,0,0,0,0,1,0,0,0,0,0,0,0,"Archivist Mechaton - On Just Summoned - Run Script"),
(29775,0,1,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archivist Mechaton - On Evade - Despawn"),
(2977500,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archivist Mechaton - Script - Say Line 1"),
(2977500,9,1,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archivist Mechaton - Script - Say Line 2"),
(2977500,9,2,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archivist Mechaton - Script - Say Line 3"),
(2977500,9,3,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archivist Mechaton - Script - Say Line 4"),
(2977500,9,4,0,0,0,100,0,6000,6000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archivist Mechaton - Script - Say Line 5"),
(2977500,9,5,0,0,0,100,0,6000,6000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archivist Mechaton - Script - Say Line 6"),
(2977500,9,6,0,0,0,100,0,6000,6000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archivist Mechaton - Script - Say Line 7"),
(2977500,9,7,0,0,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archivist Mechaton - Script - Remove Unit Flags"),
(2977500,9,8,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Archivist Mechaton - Script - Remove Unit Flags");

DELETE FROM `creature_text` WHERE `entry`=29775;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(29775, 0, 0, 'Use of the Inventor''s Disk detected. Emergency protocol gamma activated.', 12, 0, 100, 0, 0, 0, 'Archivist Mechaton',30402),
(29775, 1, 0, 'Verifying status of Norgannon''s shell.', 12, 0, 100, 0, 0, 0, 'Archivist Mechaton',30403),
(29775, 2, 0, 'Norgannon''s shell accounted for and secure. It will be available for transfer once user''s identity has been verified.', 12, 0, 100, 1, 0, 0, 'Archivist Mechaton',30404),
(29775, 3, 0, 'Standby to verify identity as Keeper Mimir.', 12, 0, 100, 1, 0, 0, 'Archivist Mechaton',30405),
(29775, 4, 0, 'Identity verification failed. User is not Keeper Mimir.', 12, 0, 100, 25, 0, 0, 'Archivist Mechaton',30406),
(29775, 5, 0, 'The Inventor''s Disk has fallen into the hands of an unauthorized user.  Activating defense protocol.', 12, 0, 100, 0, 0, 0, 'Archivist Mechaton',30407),
(29775, 6, 0, 'Impostor must be dealt with. The Inventor''s Disk must be recovered.', 12, 0, 100, 5, 0, 0, 'Archivist Mechaton',30408);
