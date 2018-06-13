-- Barithras Moonshade
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3583;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3583 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3583,0,0,0,19,0,100,0,947,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Barithras Moonshade - On Quest Cave Mushrooms Taken - Say Line 0"),
(3583,0,1,0,19,0,100,0,948,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Barithras Moonshade - On Quest Onu Taken - Say Line 1");
DELETE FROM `creature_text` WHERE `CreatureID`=3583;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3583,0,0,"Cliffspring Falls lies along the mountains to the east and north.",12,2,100,1,0,0,1210,0,"Barithras Moonshade"),
(3583,1,0,"Thank you, $n.  And luck to you.",12,2,100,2,0,0,1211,0,"Barithras Moonshade");
