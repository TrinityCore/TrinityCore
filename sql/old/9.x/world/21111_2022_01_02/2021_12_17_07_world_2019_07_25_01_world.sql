--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=30547;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30547 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30547, 0, 0, 0, 1, 0, 100, 0, 30000, 60000, 180000, 300000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Postmaster Malown - OOC - Say Line 0");

DELETE FROM `creature_text` WHERE `creatureid`=30547;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(30547, 0, 0, "...zzz... ..snrk... c'mere... gonna... gonna be Malowned... zzz..", 12, 0, 100, 0, 0, 0, 31230, 0, "Postmaster Malown"),
(30547, 0, 1, "...mrf... kids messin'.. with th' boxes... zzzz... teach 'em... lesson...", 12, 0, 100, 0, 0, 0, 31231, 0, "Postmaster Malown");
