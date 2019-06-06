-- Brewmeister Bilger
DELETE FROM `smart_scripts` WHERE `entryorguid`=2705 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2705,0,1,0,1,0,100,0,10000,20000,60000,80000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brewmeister Bilger - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=2705;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2705,0,0,"Hiccup!",12,0,100,33,0,0,794,0,"Brewmeister Bilger");
