/*
-- Smiling Jim
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4895;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4895 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=489500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4895,0,0,0,1,0,100,0,45000,60000,150000,180000,80,489500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smiling Jim - Out of Combat - Run Script"),
(489500,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smiling Jim - On Script - Say Line 0"),
(489500,9,1,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smiling Jim - On Script - Say Line 1"),
(489500,9,2,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smiling Jim - On Script - Say Line 2"),
(489500,9,3,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smiling Jim - On Script - Say Line 3");

DELETE FROM `creature_text` WHERE `CreatureID`=4895;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4895,0,0,"He'll bring you mead, he'll bring you beer...",12,7,100,0,0,0,1632,0,"Smiling Jim"),
(4895,1,0,"A grinning face from ear to ear...",12,7,100,0,0,0,1633,0,"Smiling Jim"),
(4895,2,0,"He's served us all from year to year...",12,7,100,0,0,0,1634,0,"Smiling Jim"),
(4895,3,0,"We call him Smiling Jim...",12,7,100,11,0,0,1635,0,"Smiling Jim");
*/
