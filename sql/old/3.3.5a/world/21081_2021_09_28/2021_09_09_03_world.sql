--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19720,19725,19726) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1972000,1972001) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19720,0,0,0,11,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Respawn - Set Invincibility"),
(19720,0,1,2,25,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Reset - Set Flag Immune To Players"),
(19720,0,2,0,61,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Reset - Add NPC Flags Gossip & Questgiver"),
(19720,0,3,0,62,0,100,0,8033,0,0,0,0,80,1972000,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Gossip Option 0 Selected - Run Script"),
(19720,0,4,0,2,0,100,1,0,1,0,0,0,80,1972001,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - Between 0-1% Health - Run Script (No Repeat)"),

(1972000,9,0,0,0,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Close Gossip"),
(1972000,9,1,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Store Targetlist"),
(1972000,9,2,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Remove NPC Flags Gossip & Questgiver"),
(1972000,9,3,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Set Orientation Invoker"),
(1972000,9,4,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Say Line 0"),
(1972000,9,5,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,19725,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Send Target 1 (\"Epic\" Malone)"),
(1972000,9,6,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,19726,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Send Target 1 (\"Creepjack\")"),
(1972000,9,7,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,19725,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Set Data 1 1 (\"Epic\" Malone)"),
(1972000,9,8,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,19726,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Set Data 1 1 (\"Creepjack\")"),
(1972000,9,9,0,0,0,100,0,0,0,0,0,0,91,3,0,0,0,0,0,19,19725,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Remove Flag Standstate Sleep (\"Epic\" Malone)"),
(1972000,9,10,0,0,0,100,0,0,0,0,0,0,91,3,0,0,0,0,0,19,19726,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Remove Flag Standstate Sleep (\"Creepjack\")"),
(1972000,9,11,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,19,19725,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Say Line 0 (\"Epic\" Malone)"),
(1972000,9,12,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,19,19726,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Say Line 0 (\"Creepjack\")"),
(1972000,9,13,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Say Line 1"),
(1972000,9,14,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Say Line 2"),
(1972000,9,15,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Say Line 3"),
(1972000,9,16,0,0,0,100,0,1000,1000,0,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Say Line 4"),
(1972000,9,17,0,0,0,100,0,1000,1000,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Remove Flag Immune To Players"),
(1972000,9,18,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,19,19725,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Remove Flag Immune To Players (\"Epic\" Malone)"),
(1972000,9,19,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,19,19726,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Remove Flag Immune To Players (\"Creepjack\")"),
(1972000,9,20,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Start Attack Stored Target 1"),
(1972000,9,21,0,0,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,19,19725,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Set Data 1 2 (\"Epic\" Malone)"),
(1972000,9,22,0,0,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,19,19726,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Set Data 1 2 (\"Creepjack\")"),
-- As usually, should be more complex
(1972001,9,0,0,0,0,100,0,0,0,0,0,0,11,34549,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Cast 'Dirty Larry Submits'"),
(1972001,9,1,0,0,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Say Line 5"),
(1972001,9,2,0,0,0,100,0,0,0,0,0,0,45,1,3,0,0,0,0,19,19725,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Set Data 1 3 (\"Epic\" Malone)"),
(1972001,9,3,0,0,0,100,0,0,0,0,0,0,45,1,3,0,0,0,0,19,19726,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Set Data 1 3 (\"Creepjack\")"),
(1972001,9,4,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Dirty\" Larry - On Script - Evade"),

-- Both casts 16093 on spawn (CreateObject2), it makes creature sit for some reason and has anim I don't see in movie
(19725,0,0,0,37,0,100,0,0,0,0,0,0,116,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Epic\" Malone - On AI Initialize - Set Corpse Delay"),
(19725,0,1,0,25,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Epic\" Malone - On Reset - Set Flag Immune To Players"),
(19725,0,2,0,38,0,100,0,1,1,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"\"Epic\" Malone - On Data Set 1 1 - Set Orientation Stored Target 1"),
(19725,0,3,0,38,0,100,0,1,2,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"\"Epic\" Malone - On Data Set 1 2 - Start Attack Stored Target 1"),
(19725,0,4,0,38,0,100,0,1,3,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Epic\" Malone - On Data Set 1 3 - Evade"),

(19726,0,0,0,37,0,100,0,0,0,0,0,0,116,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Creepjack\" - On AI Initialize - Set Corpse Delay"),
(19726,0,1,0,25,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Creepjack\" - On Reset - Set Flag Immune To Players"),
(19726,0,2,0,38,0,100,0,1,1,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"\"Creepjack\" - On Data Set 1 1 - Set Orientation Stored Target 1"),
(19726,0,3,0,38,0,100,0,1,2,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"\"Creepjack\" - On Data Set 1 2 - Start Attack Stored Target 1"),
(19726,0,4,0,38,0,100,0,1,3,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"\"Creepjack\" - On Data Set 1 3 - Evade");

UPDATE `creature_text` SET `Emote` = 5 WHERE `CreatureID` = 19720 AND `GroupID` = 0;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 19720 AND `GroupID` = 1;
UPDATE `creature_text` SET `Emote` = 20 WHERE `CreatureID` = 19720 AND `GroupID` = 5;
DELETE FROM `creature_text` WHERE `CreatureID` IN (19725,19726);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(19725,0,0,"%s cracks his knuckles.",16,0,100,23,0,0,17358,0,'\"Creepjack\"'),
(19726,0,0,"%s cracks his knuckles.",16,0,100,23,0,0,17358,0,'\"Epic\" Malone');

UPDATE `creature` SET `spawntimesecs` = 2 WHERE `id` IN (19725,19726);
