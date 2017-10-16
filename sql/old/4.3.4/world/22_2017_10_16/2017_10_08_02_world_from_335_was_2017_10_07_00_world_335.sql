/*
-- 
DELETE FROM `creature_text` WHERE `CreatureID`=6790;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6790,0,0,"Welcome to the Scarlet Raven.  It's best to stay indoors these days.",12,7,100,3,0,0,83,0,"Innkeeper Trelayne");
DELETE FROM `smart_scripts` WHERE `entryorguid`=6790 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6790,0,2,0,10,0,100,0,1,20,40000,40000,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Innkeeper Trelayne - OOC LOS - Say Line 0");
*/
