--
UPDATE `smart_scripts` SET `action_param1`=1 WHERE `entryorguid`=4484 AND `id`=26;
UPDATE `smart_scripts` SET `event_type`=61, `event_param1`=0, `event_param2`=0, `action_type`=1, `action_param1`=5 WHERE entryorguid=4484 AND id=24;
UPDATE `smart_scripts` SET `link`=24 WHERE `entryorguid`=4484 AND `id`=23;

DELETE FROM `smart_scripts` WHERE `entryorguid`=4484 AND `id`=28;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4484, 0, 28, 0, 61, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 3893, 50, 0, 0, 0, 0, 0, "Feero Ironhand - On Link - Say Line 0 (Forsaken Scout)");

DELETE FROM `creature_text` WHERE `entry`=3893;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3893, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1309), 12, 0, 100, 0, 0, 0, 1309, 0, "Forsaken Scout");
