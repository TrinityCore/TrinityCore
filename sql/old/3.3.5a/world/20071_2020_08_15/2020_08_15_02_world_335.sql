-- Make Private Hendel act more correctly and fix script stuck
-- Source: https://www.youtube.com/watch?v=6XeuwJnqSd4 https://www.youtube.com/watch?v=mxRq_xKLn24
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4966 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 496600 AND 496602 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4966,0,0,0,19,0,100,0,1324,0,0,0,0,80,496600,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Quest 'The Missing Diplomat (Part 16)' Taken - Run Script"),

(496600,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Remove NPC Flag Questgiver"),
(496600,9,1,0,0,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Set Invincibility 1 HP"),
(496600,9,2,0,0,0,100,0,0,0,0,0,0,2,168,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Set Faction 168"),
(496600,9,3,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,11,5184,50,0,0,0,0,0,0,"Private Hendel - On Script - Set Data 1 1 (Theramore Sentry)"),
(496600,9,4,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Start Attacking"),
(496600,9,5,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Store Targetlist"),
(496600,9,6,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Set Event Phase 1"),

(4966,0,1,0,2,1,100,1,0,20,0,0,0,80,496601,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - Between 0-20% Health - Run Script (Phase 1) (No Repeat)"),

-- Not played in 2 videos for some reasons
(496601,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Say Line 0"),
(496601,9,1,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Set Event Phase 2"),
(496601,9,2,0,0,0,100,0,0,0,0,0,0,46,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Stop Attack"),
(496601,9,3,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Evade"),

(4966,0,2,0,21,2,100,0,0,0,0,0,0,80,496602,2,1,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Reached Home - Run Script (Phase 2)"),

-- He sets faction after reaching home only
(496602,9,0,0,0,0,100,0,0,0,0,0,0,2,1077,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Set Faction 1077"),
-- Probably he sets orientation to Archmage Tervosh
(496602,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.277231,"Private Hendel - On Script - Set Orientation"),
-- Default movement is random but probably is set by waypoint script
(496602,9,2,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Stop Random Movement"),
(496602,9,3,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Say Line 1"),
(496602,9,4,0,0,0,100,0,0,0,0,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Set Emote State 64"),
(496602,9,5,0,0,0,100,0,0,0,0,0,0,45,2,2,0,0,0,0,11,5184,50,0,0,0,0,0,0,"Private Hendel - On Script - Set Data 2 to Theramore Sentry"),
(496602,9,6,0,0,0,100,0,0,0,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Private Hendel - On Script - Summon Group 1"),
(496602,9,7,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,4967,0,0,0,0,0,0,0,"Private Hendel - On Script - Set Data 1 1 (Archmage Tervosh)"),
(496602,9,8,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,4967,0,0,0,0,0,0,0,"Private Hendel - On Script - Send Target (Archmage Tervosh)");
