-- 
DELETE FROM `creature_text` WHERE `CreatureID`=8284 AND `GroupID`=7;
DELETE FROM `creature_text` WHERE `CreatureID`=8338 AND `GroupID`=1;
DELETE FROM `creature_text` WHERE `CreatureID`=8337 AND `GroupID`=0 AND `ID`=1;
DELETE FROM `creature_text` WHERE `CreatureID`=8284 AND `GroupID`=8 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8337,0,1,"Ragnaros sees all, mortal.",14,0,100,0,0,0,4347,0,"Dark Iron Steelshifter"),
(8284,8,2,"I'm about to open a can on this $n.",12,0,100,0,0,0,4351,0,"Dorius Stonetender"),
(8338,1,0,"%s disappears in a cloud of dust.",16,0,100,0,0,0,4362,0,"Dark Iron Marksman");

-- Dark Iron Marksman
DELETE FROM `smart_scripts` WHERE `entryorguid`=833800 AND `source_type`=9 AND `id` IN (3,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(833800,9,3,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Marksman - On Script - Say Line 1"),
(833800,9,4,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Marksman - On Script - Despawn");

-- Dorius Stonetender
DELETE FROM `smart_scripts` WHERE `entryorguid`=828405 AND `source_type`=9 AND `id` IN (6,7);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(828405,9,6,0,0,0,100,0,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Kill Self");
