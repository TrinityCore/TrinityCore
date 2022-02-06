-- Source: Sniffs
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25321,25322) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2532100,2532200) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25321,0,0,0,8,0,100,1,45504,0,0,0,0,80,2532100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaskala Craftsman - On Spellhit 'Free Kaskala Spirit' - Run Script (No Repeat)"),
(25322,0,0,0,8,0,100,1,45504,0,0,0,0,80,2532200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaskala Shaman - On Spellhit 'Free Kaskala Spirit' - Run Script (No Repeat)"),

(2532100,9,0,0,0,0,100,0,2000,2000,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaskala Craftsman - On Script - Play Emote 2"),
(2532100,9,1,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kaskala Craftsman - On Script - Say Line 0"),
(2532100,9,2,0,0,0,100,0,4000,4000,0,0,0,33,25321,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kaskala Craftsman - On Script - Quest Credit 'The Lost Spirits'"),
(2532100,9,3,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaskala Craftsman - On Script - Despawn Instant"),

(2532200,9,0,0,0,0,100,0,2000,2000,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaskala Shaman - On Script - Play Emote 2"),
(2532200,9,1,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kaskala Shaman - On Script - Say Line 0"),
(2532200,9,2,0,0,0,100,0,4000,4000,0,0,0,33,25322,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kaskala Shaman - On Script - Quest Credit 'The Lost Spirits'"),
(2532200,9,3,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaskala Shaman - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `CreatureID` IN (25321,25322);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25321,0,0,"Thank you for freeing me! May the tides always favor you.",12,0,100,1,0,0,24596,0,"Kaskala Craftsman"),
(25321,0,1,"You have my gratitude, $c. I thought I'd never be free.",12,0,100,1,0,0,24597,0,"Kaskala Craftsman"),
(25321,0,2,"Do not allow Kaskala to forget what has happened here.",12,0,100,1,0,0,24598,0,"Kaskala Craftsman"),
(25322,0,0,"Thank you, $c. May the winds and seas always deliver you safely.",12,0,100,1,0,0,24599,0,"Kaskala Shaman"),
(25322,0,1,"The people of Kaskala are in your debt, $c.",12,0,100,1,0,0,24600,0,"Kaskala Shaman"),
(25322,0,2,"May the ancestors always aid you, $c, as you have aided me.",12,0,100,1,0,0,24601,0,"Kaskala Shaman");
