-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11936;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11936 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11936, 0, 0, 0, 1, 0, 100, 0, 6000, 15000, 60000, 65000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artist Renfray - OOC - Say text'),
(11936, 0, 1, 0, 20, 0, 100, 0, 5846, 0, 0, 0, 85, 18347, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Artist Renfray - On quest rewarded - Cast Haunted');

DELETE FROM `creature_text` WHERE `CreatureID`=11936;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11936,0,0,"Are they all...dead?",12,0,100,0,0,0,7274,0,"Artist Renfray"),
(11936,0,1,"Is someone there? Tirion my old friend, is that you? have you come to save us?",12,0,100,0,0,0,7273,0,"Artist Renfray"),
(11936,0,2,"So dark...",12,0,100,0,0,0,7272,0,"Artist Renfray"),
(11936,0,3,"The Sarkhoff's... sometimes the Sarkhoff's visit. They are good people.",12,0,100,0,0,0,7275,0,"Artist Renfray");
