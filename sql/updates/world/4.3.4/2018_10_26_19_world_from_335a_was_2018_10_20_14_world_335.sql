/*
-- Crimson Courier
DELETE FROM `smart_scripts` WHERE `entryorguid`=12337 AND `source_type`=0 AND `ID` IN (8,9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12337,0,8,0,11,0,100,0,0,0,0,0,0,3,0,10502,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Courier - On Respawn - Morph to Model 10502"),
(12337,0,9,0,4,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Courier - On Aggro - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=12337 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12337,1,0,"Assassins! Guards! Guards!",14,0,100,0,0,0,7595,0,"Crimson Courier");
*/
