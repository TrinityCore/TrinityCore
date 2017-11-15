/*
-- Jorn Skyseer
DELETE FROM `creature_text` WHERE `CreatureID`=3387;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3387,0,0,"The rage of Ishamuhale runs through you, $n.",12,1,100,2,0,0,1297,0,"Jorn Skyseer"),
(3387,1,0,"Lakota'mani thunders within you, $n.",12,1,100,2,0,0,1298,0,"Jorn Skyseer"),
(3387,2,0,"The speed of Owatanka is with you, $n.",12,1,100,2,0,0,1299,0,"Jorn Skyseer"),
(3387,3,0,"Your path is steady, $n, for Washte Pawne's resolve is with you.",12,1,100,2,0,0,1300,0,"Jorn Skyseer");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3387;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3387 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3387,0,0,0,20,0,100,0,882,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jorn Skyseer - On Quest 'Ishamuhale' Finished - Say Line 0"),
(3387,0,1,0,20,0,100,0,883,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jorn Skyseer - On Quest 'Lakota'mani' Finished - Say Line 1"),
(3387,0,2,0,20,0,100,0,884,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jorn Skyseer - On Quest 'Owatanka' Finished - Say Line 2"),
(3387,0,3,0,20,0,100,0,885,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jorn Skyseer - On Quest 'Washte Pawne' Finished - Say Line 3");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3338 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `link`=0  WHERE `entryorguid`=3338 AND `source_type`=0 AND `id`=0; 
*/
