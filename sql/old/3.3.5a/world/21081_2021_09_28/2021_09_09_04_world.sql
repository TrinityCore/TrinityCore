--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24362 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2436200,2436201) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24362,0,0,0,19,0,100,0,11351,0,0,0,0,80,2436200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Longrunner Pembe - On Quest 'Mastering the Runes' Taken - Run Script"),
(24362,0,1,0,20,0,100,0,11351,0,0,0,0,80,2436201,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Longrunner Pembe - On Quest 'Mastering the Runes' Finished - Run Script"),

(2436200,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.286381244659423828,"Longrunner Pembe - On Script - Set Orientation"),
(2436200,9,1,0,0,0,100,0,1500,1500,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Longrunner Pembe - On Script - Say Line 0"),
(2436200,9,2,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,1.082104086875915527,"Longrunner Pembe - On Script - Set Orientation"),

(2436201,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Longrunner Pembe - On Script - Say Line 1"),
(2436201,9,1,0,0,0,100,0,4000,4000,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Longrunner Pembe - On Script - Set Emote State 173"),
(2436201,9,2,0,0,0,100,0,3000,3000,0,0,0,1,2,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Longrunner Pembe - On Script - Say Line 2"),
(2436201,9,3,0,0,0,100,0,5000,5000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Longrunner Pembe - On Script - Set Emote State 0"),
(2436201,9,4,0,0,0,100,0,1000,1000,0,0,0,1,3,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Longrunner Pembe - On Script - Say Line 3");

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24328 AND `source_type` = 0 AND `id` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2432800,2432801) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24328,0,1,0,20,0,100,0,11349,0,0,0,0,80,2432801,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prospector Belvar - On Quest 'Mastering the Runes' Finished - Run Script"),

(2432800,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.530727386474609375,"Prospector Belvar - On Script - Set Orientation"),
(2432800,9,1,0,0,0,100,0,1500,1500,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Prospector Belvar - On Script - Say Line 0"),
(2432800,9,2,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,1.117010712623596191,"Prospector Belvar - On Script - Set Orientation"),

(2432801,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Prospector Belvar - On Script - Say Line 1"),
(2432801,9,1,0,0,0,100,0,4000,4000,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prospector Belvar - On Script - Set Emote State 69"),
(2432801,9,2,0,0,0,100,0,3000,3000,0,0,0,1,2,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Prospector Belvar - On Script - Say Line 2"),
(2432801,9,3,0,0,0,100,0,5000,5000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prospector Belvar - On Script - Set Emote State 0"),
(2432801,9,4,0,0,0,100,0,1000,1000,0,0,0,1,3,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Prospector Belvar - On Script - Say Line 3");

DELETE FROM `creature_text` WHERE `CreatureID` = 24328 AND `GroupID` IN (1,2,3);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24328,1,0,"I'm only going to carve the runes I think will give you command over a giant.",12,0,100,1,0,0,23246,0,"Prospector Belvar"),
(24328,2,0,"I'm omitting the runes for \"north\" and \"west\" because I'm not sure how they impact the giant. I'm also including a rune to limit how long you can control it.",12,0,100,0,0,0,23247,0,"Prospector Belvar"),
(24328,3,0,"There we go, the Rune of Command... hopefully. Not nearly as vicious as its Iron Dwarf cousin, but functional.",12,0,100,1,0,0,23248,0,"Prospector Belvar");
