-- Crank Fizzlebub
DELETE FROM `creature_text` WHERE `CreatureID`=2498 AND `GroupID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2498,2,0,"Hm... if you're looking to adle wits, $n, then the secret behind Zanzil's zombies might just do the trick!",12,0,100,0,0,0,1468,0,"Crank Fizzlebub");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2498 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2498,0,1,0,20,0,100,0,1118,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Crank Fizzlebub - On Quest 'Back to Booty Bay' Finished - Say Line 2");
