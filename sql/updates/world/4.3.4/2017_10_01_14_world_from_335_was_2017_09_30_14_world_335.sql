/*
-- Gubber Blump
DELETE FROM `creature_text` WHERE `CreatureID`=10216;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10216,0,0,"Fishing is real easy.  Just take a pole with a line on it, maybe put some bait on it, and cast it out in the water.  Sure enough, them fish will start biting.",12,0,100,1,0,0,5531,0,"Gubber Blump"),
(10216,1,0,"I got some extras with me; if you pay me back what I paid for them, you can have one.  I got some bait too.",12,0,100,0,0,0,5532,0,"Gubber Blump");

DELETE FROM `smart_scripts` WHERE `entryorguid`=10216 AND `source_type`=0 AND `id` IN (2, 3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10216,0,2,0,62,0,100,0,2562,1,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gubber Blump - On Gossip Option 1 Selected - Say Line 0"),
(10216,0,3,0,62,0,100,0,2562,2,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gubber Blump - On Gossip Option 2 Selected - Say Line 1");
*/
