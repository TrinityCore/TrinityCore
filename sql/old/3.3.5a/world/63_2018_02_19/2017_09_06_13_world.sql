-- A Lost Master (Part 2)
DELETE FROM `creature_text` WHERE `CreatureID`=3693 AND `GroupID` IN (10, 11);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3693,10,0,"%s begins to cast a spell as you take the cloak from him.",16,7,100,0,0,0,1249,0,"Terenthis"),
(3693,11,0,"Go now, $n. Find Volcor... and remember, the magics protecting you will fail if you interact with anyone, save for talking.",12,7,100,1,0,0,1289,0,"Terenthis");
DELETE FROM `smart_scripts` WHERE `entryorguid`=3693 AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3693,0,6,0,19,0,100,0,993,0,0,0,80,369303,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Quest \A Lost Master (Part 2)\ Taken - Run Script");
DELETE FROM `smart_scripts` WHERE `entryorguid`=369303 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(369303,9,0,0,0,0,100,0,0,0,0,0,1,10,0,0,0,0,0,7,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 10"),
(369303,9,1,0,0,0,100,0,2000,2000,0,0,1,11,0,0,0,0,0,7,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 11");
