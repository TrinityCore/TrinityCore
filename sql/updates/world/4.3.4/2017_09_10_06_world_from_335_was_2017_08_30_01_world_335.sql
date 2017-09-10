/*
-- Farmer Furlbrow
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=237;
DELETE FROM `smart_scripts` WHERE `entryorguid`=237;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(237,0,0,0,1,0,100,0,75000,90000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farmer Furlbrow - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=237;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(237,0,0,"Can't believe the forsaken wagon broke down.  Ain't no luck to be had in this land....",12,7,100,0,0,0,56,0,"Farmer Furlbrow"),
(237,0,1,"We'll be out of here just as soon as I get this wagon fixed....",12,7,100,0,0,0,57,0,"Farmer Furlbrow");
*/
