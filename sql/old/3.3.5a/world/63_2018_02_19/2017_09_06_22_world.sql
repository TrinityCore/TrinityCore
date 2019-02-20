-- Archmage Ansirem Runeweaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=2543 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2543,0,4,0,20,0,100,0,602,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - On Quest \Magical Analysis\ Finished - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=2543;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2543,0,0,"How interesting... the Stone possesses great magical potential, but in a purely raw form...",12,7,100,0,0,0,761,0,"Archmage Ansirem Runeweaver");
