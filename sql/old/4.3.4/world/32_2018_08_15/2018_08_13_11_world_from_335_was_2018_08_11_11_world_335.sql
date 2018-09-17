/*
-- Acolyte Dellis
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5386;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5386 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5386,0,0,0,1,0,100,0,1000,15000,100000,150000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acolyte Dellis - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5386;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5386,0,0,"It wasn't my fault, Master Mazen!",12,7,100,0,0,0,1828,0,"Acolyte Dellis"),
(5386,0,1,"It was a simple mistake. A wrong turn I tell you!",12,7,100,0,0,0,1829,0,"Acolyte Dellis"),
(5386,0,2,"The swamp was horrible! I was so... so... scared!",12,7,100,0,0,0,1830,0,"Acolyte Dellis"),
(5386,0,3,"I'm lucky to be alive!",12,7,100,0,0,0,1831,0,"Acolyte Dellis");
*/
