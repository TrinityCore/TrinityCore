-- Chief Engineer Hinderweir VII
DELETE FROM `creature_text` WHERE `CreatureID`=1093;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1093,0,0,"The Stonewrought Dam has been saved!  Three cheers for $n!",14,7,100,22,0,0,546,0,"Chief Engineer Hinderweir VII");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1093;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1093 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1093,0,0,0,20,0,100,0,283,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Engineer Hinderweir VII - On Quest 'A Dark Threat Looms (Part 7)' Finished - Say Line 0");
