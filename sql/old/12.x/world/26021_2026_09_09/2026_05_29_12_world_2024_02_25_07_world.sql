-- Outro for quest "Where Kings Walk" (13188)
-- Text
DELETE FROM `creature_text` WHERE `CreatureID`=29611 AND `GroupID` IN (0,1,2,3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(29611,0,0,"People of Stormwind! Citizens of the Alliance! Your king speaks!",14,7,100,22,0,0,31675,0,"King Varian Wrynn"),
(29611,1,0,"Today marks the first of many defeats for the Scourge! Death knights, once in service of the Lich King, have broken free of his grasp and formed a new alliance against his tyranny!",14,7,100,22,0,0,31676,0,"King Varian Wrynn"),
(29611,2,0,"You will welcome these former heroes of the Alliance and treat them with the respect that you would give to any ally of Stormwind!",14,7,100,22,0,0,31677,0,"King Varian Wrynn"),
(29611,3,0,"Glory to the Alliance!",14,7,100,4,0,0,31678,0,"King Varian Wrynn");

-- Script
DELETE FROM `smart_scripts` WHERE `entryorguid`=29611 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2961100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29611,0,2,0,20,0,100,0,13188,0,0,0,0,80,2961100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"King Varian Wrynn - On Quest 'Where Kings Walk' Rewarded - Run Script"),

(2961100,9,0,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"King Varian Wrynn - On Script - Say Line 0"),
(2961100,9,1,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"King Varian Wrynn - On Script - Say Line 1"),
(2961100,9,2,0,0,0,100,0,8000,8000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"King Varian Wrynn - On Script - Say Line 2"),
(2961100,9,3,0,0,0,100,0,9000,9000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"King Varian Wrynn - On Script - Say Line 3");
