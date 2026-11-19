-- Gurgthock SAI
SET @ENTRY := 18471;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,9962,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: Brokentoe' Taken - Say Line 0"),
(@ENTRY,0,1,20,61,0,100,0,9962,0,0,0,80,1847100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: Brokentoe' Taken - Run Script"),
(@ENTRY,0,2,3,19,0,100,0,9967,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: The Blue Brothers' Taken - Say Line 0"),
(@ENTRY,0,3,20,61,0,100,0,9967,0,0,0,80,1847101,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: The Blue Brothers' Taken - Run Script"),
(@ENTRY,0,4,5,19,0,100,0,9970,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: Rokdar the Sundered Lord' Taken - Say Line 0"),
(@ENTRY,0,5,20,61,0,100,0,9970,0,0,0,80,1847102,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: Rokdar the Sundered Lord' Taken - Run Script"),
(@ENTRY,0,6,7,19,0,100,0,9972,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: Skra'gath' Taken - Say Line 0"),
(@ENTRY,0,7,20,61,0,100,0,9972,0,0,0,80,1847103,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: Skra'gath' Taken - Run Script"),
(@ENTRY,0,8,9,19,0,100,0,9973,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: The Warmaul Champion' Taken - Say Line 0"),
(@ENTRY,0,9,20,61,0,100,0,9973,0,0,0,80,1847104,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: The Warmaul Champion' Taken - Run Script"),
(@ENTRY,0,10,11,19,0,100,0,9977,0,0,0,1,11,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: The Final Challenge' Taken - Say Line 11"),
(@ENTRY,0,11,20,61,0,100,0,9977,0,0,0,45,1,1,0,0,0,0,19,18069,0,0,0,0,0,0,"Gurgthock - On Quest 'The Ring of Blood: The Final Challenge' Taken - Set Data 1 1"),
(@ENTRY,0,12,22,38,0,100,0,10,10,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Data Set 10 10 - Say Line 2"),
(@ENTRY,0,13,22,38,0,100,0,11,11,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Data Set 11 11 - Say Line 4"),
(@ENTRY,0,14,15,38,0,100,0,12,12,0,0,1,6,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Data Set 12 12 - Say Line 6"),
(@ENTRY,0,15,22,61,0,100,0,0,0,0,0,45,12,12,0,0,0,0,19,18069,0,0,0,0,0,0,"Gurgthock - On Data Set 12 12 - Set Data 12 12"),
(@ENTRY,0,16,17,38,0,100,0,13,13,0,0,1,8,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Data Set 13 13 - Say Line 8"),
(@ENTRY,0,17,22,61,0,100,0,0,0,0,0,45,13,13,0,0,0,0,19,18069,0,0,0,0,0,0,"Gurgthock - On Data Set 13 13 - Set Data 13 13"),
(@ENTRY,0,18,19,38,0,100,0,14,14,0,0,1,10,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Data Set 14 14 - Say Line 10"),
(@ENTRY,0,19,22,61,0,100,0,0,0,0,0,45,14,14,0,0,0,0,19,18069,0,0,0,0,0,0,"Gurgthock - On Data Set 14 14 - Set Data 14 14"),
(@ENTRY,0,20,21,61,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurgthock - On Data Set 14 14 - Set Npc Flag Gossip"),
(@ENTRY,0,21,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurgthock - Link - Set Event Phase 2"),
(@ENTRY,0,22,23,61,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurgthock - Link - Set Npc Flags Gossip & Questgiver"),
(@ENTRY,0,23,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurgthock - Link - Set Event Phase 0"),
(@ENTRY,0,24,25,1,2,100,0,300000,300000,300000,300000,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurgthock - Out of Combat - Set Npc Flags Gossip & Questgiver (Phase 2)"),
(@ENTRY,0,25,0,61,2,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gurgthock - Out of Combat - Set Event Phase 0 (Phase 2)"),
(@ENTRY,0,26,22,38,0,100,0,15,15,0,0,70,0,0,0,0,0,0,19,18471,0,0,0,0,0,0,"Gurgthock - On Data Set 15 15 - Respawn Mogor");

UPDATE `smart_scripts` SET `link`=15 WHERE  `entryorguid`=18069 AND `source_type`=0 AND `id`=14 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=18069 AND `id`=15 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18069, 0, 15, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 15, 15, 0, 0, 0, 0, 19, 18471, 0, 0, 0, 0, 0, 0, 'Mogor - Linked with Previous Event - Say Data');
