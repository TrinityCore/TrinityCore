UPDATE `smart_scripts` SET `target_type`=23,`action_param3`=1 WHERE `entryorguid` IN (28948,2894800) AND `source_type` IN (0,9) AND `action_type`=1; 
UPDATE `smart_scripts` SET `comment`= 'Malmortis - On Waypoint 80 Reached - Say Line 6 (No Repeat)' WHERE `entryorguid`=28948 AND `source_type`=0 AND `id`=6; 
UPDATE `smart_scripts` SET `target_type`=23 WHERE  `entryorguid`=2894800 AND `source_type`=9 AND `id`=3 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=2894800 AND `source_type`=9 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28948 AND `source_type`=0 AND `id`>14;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28948,0,15,16,40,0,100,1,2,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Waypoint 2 Reached - Pause Waypoint (No Repeat)'),
(28948,0,16,17,61,0,100,1,0,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,'Malmortis - On Waypoint 2 Reached - Say Line 2 (No Repeat)'),
(28948,0,17,0,61,0,100,1,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,'Malmortis - On Waypoint 2 Reached - Set Orientation To Invoker'),
(28948,0,18,0,40,0,100,513,93,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,'Malmortis - On Waypoint 93 Reached - Set Orientation To Invoker'),
(28948,0,19,0,40,0,100,0,93,0,0,0,1,13,5000,1,0,0,0,23,0,0,0,0,0,0,0,'Malmortis - On Waypoint 93 Reached - Say text 13'),
(28948,0,20,0,52,0,100,0,13,28948,0,0,1,14,7000,1,0,0,0,23,0,0,0,0,0,0,0,'Malmortis - On Text 13 Over - Say text 14'),
(28948,0,21,22,52,0,100,0,14,28948,0,0,1,15,3000,1,0,0,0,23,0,0,0,0,0,0,0,'Malmortis - On Text 14 Over  - Say text 15'),
(28948,0,22,0,61,0,100,1,0,0,0,0,11,53101,2,0,0,0,0,23,0,0,0,0,0,0,0,'Malmortis - On Text 14 Over - Cast Kill Credit'),
(28948,0,23,24,52,0,100,512,15,28948,0,0,11,52676,2,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Text 15 Over - Cast Drakuramas Teleport Script 03'),
(28948,0,24,0,61,0,100,513,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Text 15 Over - Despawn');

DELETE FROM `creature_text` WHERE `CreatureID` = 28948 AND `GroupID`=15;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`, `BroadcastTextId`) VALUES 
(28948, 15, 0, "Farewell", 12, 0, 100, 2, 0, 0, "Malmortis say", 29440);
