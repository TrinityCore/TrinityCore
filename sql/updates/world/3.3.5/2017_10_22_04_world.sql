-- 
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (117664, 117670, 117671, 117672, 117677);
DELETE FROM `creature_addon` WHERE `guid` IN (117664, 117670, 117671, 117672, 117677);
INSERT INTO `creature_addon` (`guid`, `emote`) VALUES
(117664, 383),
(117670, 383),
(117671, 383),
(117672, 383),
(117677, 383);

UPDATE `smart_scripts` SET `comment`="Gjalerbron Prisoner - On Data Set - Run Script" WHERE `entryorguid`=24035 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2403500, -117691, -117692, -117693, -117694, -117695, -117696, -117697, -117698, -117699, -117700, -117701, -117702, -117703, -117704, -117705, -117708, -117710, -117713, -117714);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2403500, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 33, 24035, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Script - Kill Credit"),
(2403500, 9, 1, 0, 0, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Script - Say Line 1"),
(2403500, 9, 2, 0, 0, 0, 100, 1, 3000, 3000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Script - Despawn Instant"),
(-117691, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117691, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117692, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117692, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117693, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117693, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117694, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117694, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117695, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117695, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117696, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117696, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117697, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117697, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117698, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117698, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117699, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117699, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117700, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117700, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117701, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117701, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117702, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117702, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117703, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117703, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117704, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117704, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117705, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117705, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117708, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117708, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117710, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117710, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117713, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117713, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0"),
(-117714, 0, 0, 0, 38, 0, 100, 513, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - On Data Set - Run Script"),
(-117714, 0, 1, 0, 1, 0, 25, 0, 20000, 50000, 60000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gjalerbron Prisoner - OOC - Say Line 0");

UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry`=24035;
DELETE FROM `creature_text` WHERE `CreatureID`=24035;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24035, 0, 0, "Please, let me out of here!", 12, 0, 100, 0, 0, 0, 22637, 0, "Gjalerbron Prisoner"),
(24035, 0, 1, "The key... you have to find the key!", 12, 0, 100, 0, 0, 0, 22638, 0, "Gjalerbron Prisoner"),
(24035, 0, 2, "I think I saw a key on one of those vrykul.", 12, 0, 100, 0, 0, 0, 22639, 0, "Gjalerbron Prisoner"),
(24035, 0, 3, "I don't want to be taken down into the catacombs!", 12, 0, 100, 0, 0, 0, 22640, 0, "Gjalerbron Prisoner"),
(24035, 0, 4, "I don't want to be sacrificed!", 12, 0, 100, 0, 0, 0, 22641, 0, "Gjalerbron Prisoner"),
(24035, 0, 5, "They're performing unholy rites down in the catacombs, and I'm about to be the sacrifice!", 12, 0, 100, 0, 0, 0, 22642, 0, "Gjalerbron Prisoner"),
(24035, 0, 6, "Is there no hero to rescue me?", 12, 0, 100, 0, 0, 0, 22643, 0, "Gjalerbron Prisoner"),
(24035, 0, 7, "This is the end.", 12, 0, 100, 0, 0, 0, 22644, 0, "Gjalerbron Prisoner"),
(24035, 0, 8, "I think I saw a key on one of those Gjalerbron vrykul up top.", 12, 0, 100, 0, 0, 0, 23649, 0, "Gjalerbron Prisoner"),
(24035, 1, 0, "Oh, thank you, thank you!", 12, 0, 100, 0, 0, 0, 22645, 0, "Gjalerbron Prisoner"),
(24035, 1, 1, "Thank you.  I will not forget this!", 12, 0, 100, 0, 0, 0, 22646, 0, "Gjalerbron Prisoner"),
(24035, 1, 2, "Avenge my friends who have already been sacrificed!", 12, 0, 100, 0, 0, 0, 22647, 0, "Gjalerbron Prisoner"),
(24035, 1, 3, "You have to put a stop to this madness before it's too late!", 12, 0, 100, 0, 0, 0, 22648, 0, "Gjalerbron Prisoner"),
(24035, 1, 4, "My thanks to you, hero!", 12, 0, 100, 0, 0, 0, 22649, 0, "Gjalerbron Prisoner"),
(24035, 1, 5, "The vrykul are evil and must be destroyed!", 12, 0, 100, 0, 0, 0, 22650, 0, "Gjalerbron Prisoner"),
(24035, 1, 6, "You saved my life!", 12, 0, 100, 0, 0, 0, 22651, 0, "Gjalerbron Prisoner"),
(24035, 1, 7, "Thank goodness for you!", 12, 0, 100, 0, 0, 0, 22652, 0, "Gjalerbron Prisoner");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-115239,-115235,-115236,-115238,-48198);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-115239, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On aggro - Say text 0"),
(-115239, 0, 1, 0, 0, 0, 100, 0, 2000, 3000, 3000, 3500, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Cast Shadow Bolt"),
(-115239, 0, 2, 0, 0, 0, 100, 0, 3000, 7000, 10000, 20000, 11, 17173, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Drain Life"),
(-115239, 0, 3, 0, 0, 0, 100, 0, 5000, 8000, 25000, 30000, 11, 18267, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Curse of Weakness"),
(-115239, 0, 4, 0, 1, 0, 100, 1, 2000, 2000, 0, 0, 11, 43151, 0, 0, 0, 0, 0, 10, 117664, 24035, 0, 0, 0, 0, 0, "Necrolord - OOC - cast Necrolord: Purple Beam"),
(-115235, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On aggro - Say text 0"),
(-115235, 0, 1, 0, 0, 0, 100, 0, 2000, 3000, 3000, 3500, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Cast Shadow Bolt"),
(-115235, 0, 2, 0, 0, 0, 100, 0, 3000, 7000, 10000, 20000, 11, 17173, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Drain Life"),
(-115235, 0, 3, 0, 0, 0, 100, 0, 5000, 8000, 25000, 30000, 11, 18267, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Curse of Weakness"),
(-115235, 0, 4, 0, 1, 0, 100, 1, 2000, 2000, 0, 0, 11, 43151, 0, 0, 0, 0, 0, 10, 117671, 24035, 0, 0, 0, 0, 0, "Necrolord - OOC - cast Necrolord: Purple Beam"),
(-115236, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On aggro - Say text 0"),
(-115236, 0, 1, 0, 0, 0, 100, 0, 2000, 3000, 3000, 3500, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Cast Shadow Bolt"),
(-115236, 0, 2, 0, 0, 0, 100, 0, 3000, 7000, 10000, 20000, 11, 17173, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Drain Life"),
(-115236, 0, 3, 0, 0, 0, 100, 0, 5000, 8000, 25000, 30000, 11, 18267, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Curse of Weakness"),
(-115236, 0, 4, 0, 1, 0, 100, 1, 2000, 2000, 0, 0, 11, 43151, 0, 0, 0, 0, 0, 10, 117672, 24035, 0, 0, 0, 0, 0, "Necrolord - OOC - cast Necrolord: Purple Beam"),
(-115238, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On aggro - Say text 0"),
(-115238, 0, 1, 0, 0, 0, 100, 0, 2000, 3000, 3000, 3500, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Cast Shadow Bolt"),
(-115238, 0, 2, 0, 0, 0, 100, 0, 3000, 7000, 10000, 20000, 11, 17173, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Drain Life"),
(-115238, 0, 3, 0, 0, 0, 100, 0, 5000, 8000, 25000, 30000, 11, 18267, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Curse of Weakness"),
(-115238, 0, 4, 0, 1, 0, 100, 1, 2000, 2000, 0, 0, 11, 43151, 0, 0, 0, 0, 0, 10, 117677, 24035, 0, 0, 0, 0, 0, "Necrolord - OOC - cast Necrolord: Purple Beam"),
(-48198, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On aggro - Say text 0"),
(-48198, 0, 1, 0, 0, 0, 100, 0, 2000, 3000, 3000, 3500, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Cast Shadow Bolt"),
(-48198, 0, 2, 0, 0, 0, 100, 0, 3000, 7000, 10000, 20000, 11, 17173, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Drain Life"),
(-48198, 0, 3, 0, 0, 0, 100, 0, 5000, 8000, 25000, 30000, 11, 18267, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Curse of Weakness"),
(-48198, 0, 4, 0, 1, 0, 100, 1, 2000, 2000, 0, 0, 11, 43151, 0, 0, 0, 0, 0, 10, 117670, 24035, 0, 0, 0, 0, 0, "Necrolord - OOC - cast Necrolord: Purple Beam");

DELETE FROM `creature` WHERE `guid`=48198;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(48198, 24014, 571, 0, 0, 1, 1, 0, 1,2598.214, -3574.1608, 161.379, 4.197266, 300, 0, 0, 7185, 0, 0, 0, 0, 0, 0);
