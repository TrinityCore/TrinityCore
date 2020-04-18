-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (19257,19258);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19257,19258) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19257, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Arcanist Torseldori - On aggro - say text"),
(19257, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 3000, 4000, 11, 15530, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Arcanist Torseldori - IC - Cast spell Frostbolt"),
(19257, 0, 2, 0, 0, 0, 100, 0, 4000, 10000, 10000, 14000, 11, 12674, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Arcanist Torseldori - IC - Cast spell Frost Nova"),
(19257, 0, 3, 0, 0, 0, 100, 0, 10000, 15000, 13000, 24000, 11, 33634, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Arcanist Torseldori - IC - Cast spell Frost Blizzard"),
(19258, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 3000, 4000, 11, 15530, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bloodmage - IC - Cast spell Frostbolt"),
(19258, 0, 1, 0, 0, 0, 100, 0, 4000, 10000, 10000, 14000, 11, 12674, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bloodmage - IC - Cast spell Frost Nova"),
(19258, 0, 2, 0, 0, 0, 100, 0, 10000, 15000, 13000, 24000, 11, 33634, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bloodmage - IC - Cast spell Frost Blizzard");

DELETE FROM `creature_text` WHERE `CreatureID` = 19257;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`, `BroadcastTextId`) VALUES 
(19257, 0, 0, "INCOMING! Do not let them through! Focus fire! NOW, NOW, NOW!", 14, 1, 100, 0, 0, 0, 'Arcanist Torseldori', 16395);
