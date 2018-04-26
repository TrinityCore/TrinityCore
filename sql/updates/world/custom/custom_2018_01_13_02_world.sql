UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 2 WHERE `entry` IN (35870, 35233, 35230);
UPDATE `creature_template` SET `VehicleID`= 463 WHERE `entry`= 35231;
UPDATE `creature_template` SET `VehicleID`= 470 WHERE `entry`= 35317;

UPDATE `creature` SET `spawntimesecs`= 5 WHERE `id`= 35229;

UPDATE `creature_template` SET `npcflag`= 16777216 WHERE `entry` IN (44427, 35231, 44428, 35317, 44429);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (44427, 35231, 44428, 35317, 44429);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(44427, 67001, 3, 0),
(44428, 46598, 3, 0),
(35231, 46598, 1, 0),
(44429, 82992, 3, 0),
(35317, 43671, 1, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`= 35231;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `summontype`, `summontimer`, `description`) VALUES
(35231, 35230, 1, 1, 5, 0, 'Crowley''s Horse - Lord Darius Crowley');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 18 AND `SourceGroup` IN (44427, 35317, 44428, 44429);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `Comment`) VALUES
(18, 44427, 67001, 9, 14212, 'Required quest active for spellclick'),
(18, 44429, 82992, 9, 14212, 'Required quest active for spellclick'),
(18, 35317, 43671, 9, 14218, 'Required quest active for spellclick');

UPDATE `creature_template` SET `speed_run`= 1.28571, `ScriptName`= 'npc_crowleys_horse' WHERE `entry`= 35231;

SET @ID := 352310;
DELETE FROM `waypoint_data` WHERE `id`= @ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `move_type`) VALUES
(@ID, 1, -1686.12, 1655.639, 20.61058, 1),
(@ID, 2, -1668.156, 1639.432, 20.61058, 1),
(@ID, 3, -1666.63, 1628.859, 20.53271, 1),
(@ID, 4, -1670.76, 1617.431, 20.61058, 1),
(@ID, 5, -1693.648, 1592.639, 20.61058, 1),
(@ID, 6, -1708.017, 1590.55, 20.61042, 1),
(@ID, 7, -1719.366, 1595.649, 20.61042, 1),
(@ID, 8, -1720.566, 1610.141, 20.6074, 1),
(@ID, 9, -1711.898, 1629.703, 20.6074, 1),
(@ID, 10, -1698.149, 1656.483, 20.61058, 1),
(@ID, 11, -1696.424, 1682.012, 20.52616, 1),
(@ID, 12, -1684.675, 1700.12, 20.46484, 1),
(@ID, 13, -1658.309, 1710.313, 20.58983, 1),
(@ID, 14, -1625.477, 1712.299, 21.80511, 1),
(@ID, 15, -1592.095, 1710.71, 20.58986, 1);

SET @ID := 352311;
DELETE FROM `waypoint_data` WHERE `id`= @ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `move_type`) VALUES
(@ID, 1, -1545.082, 1684.233, 20.60992, 1),
(@ID, 2, -1542.793, 1656.083, 20.60992, 1),
(@ID, 3, -1542.998, 1640.535, 20.60992, 1),
(@ID, 4, -1520.733, 1618.097, 20.61054, 1),
(@ID, 5, -1498.792, 1621.738, 20.61054, 1),
(@ID, 6, -1468.356, 1630.78, 20.61054, 1),
(@ID, 7, -1441.646, 1627.67, 20.61054, 1),
(@ID, 8, -1429.844, 1616.627, 20.58984, 1),
(@ID, 9, -1417.991, 1586.554, 20.58984, 1),
(@ID, 10, -1429.177, 1548.783, 20.84849, 1),
(@ID, 11, -1447.417, 1532.79, 20.60095, 1),
(@ID, 12, -1463.104, 1535.031, 20.61054, 1),
(@ID, 13, -1483.035, 1544.151, 20.61054, 1),
(@ID, 14, -1505.156, 1568.611, 20.61053, 1),
(@ID, 15, -1531.599, 1581.872, 26.53872, 1),
(@ID, 16, -1540.594, 1574.429, 29.20671, 1);

SET @ID := 444280;
DELETE FROM `waypoint_data` WHERE `id`= @ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `move_type`) VALUES
(@ID, 1, -1512.36, 1570.78, 24.06706, 1),
(@ID, 2, -1498.715, 1565.426, 20.87811, 1),
(@ID, 3, -1487.863, 1557.163, 20.85, 1),
(@ID, 4, -1474.18, 1542.68, 20.61054, 1),
(@ID, 5, -1457.6, 1532.64, 20.60095, 1),
(@ID, 6, -1438.01, 1525.31, 20.87622, 1),
(@ID, 7, -1424.2, 1545.7, 20.46568, 1),
(@ID, 8, -1411.29, 1556.16, 20.55698, 1),
(@ID, 9, -1414.19, 1577.65, 20.58984, 1),
(@ID, 10, -1427.47, 1617.3, 20.58984, 1),
(@ID, 11, -1445.54, 1633.9, 20.61054, 1),
(@ID, 12, -1470.71, 1658.21, 20.61054, 1),
(@ID, 13, -1491.05, 1658.74, 20.61054, 1),
(@ID, 14, -1515.33, 1641.18, 20.60992, 1),
(@ID, 15, -1526.75, 1630.37, 20.61054, 1),
(@ID, 16, -1528.42, 1610.71, 20.61054, 1),
(@ID, 17, -1532.39, 1585.36, 26.53804, 1);


DELETE FROM `conditions` WHERE `SourceEntry`= 67063 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO conditions (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 7, 67063, 0, 0, 31, 0, 3, 35229, 0, 0, 0, '', 'Throw Torch - Target Bloodfang Stalker');

DELETE FROM `creature_text` WHERE `CreatureID`= 35230;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(35230, 0, 0, 'Let''s round up as many of them as we can.  Every worgen chasing us is one less worgen chasing the survivors!', 12, 0, 100, 0, 0, 19696, 35498, 'Lord Darius Crowley to Player'),
(35230, 1, 0, 'You''ll never catch us, you blasted mongrels!', 14, 0, 100, 0, 0, 19696, 35497, 'Lord Darius Crowley to Player');

-- Creature Lord Darius Crowley 35230 SAI
SET @ENTRY := 35230;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 7000 and 7000 ms) - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 39000, 39000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 39000 and 39000 ms) - Self: Talk 1 // ");

UPDATE `creature_template` SET `InhabitType`= 1 WHERE `entry`= 36057;
DELETE FROM `creature_sparring_template` WHERE `AttackerEntry` IN (36057, 35229, 41015, 35627);
INSERT INTO `creature_sparring_template` (`AttackerEntry`, `VictimEntry`, `HealthLimitPct`) VALUES
(36057, 35229, 90.0),
(35229, 36057, 90.0),
(35229, 35317, 100.0),
(41015, 35627, 90.0),
(35627, 41015, 90.0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_gen_throw_torch');
 
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(67063, 'spell_gen_throw_torch');

UPDATE `creature_addon` SET `emote`= 385 WHERE `guid`= 377296;
UPDATE `creature_addon` SET `emote`= 214 WHERE `guid`= 377414;

DELETE FROM `creature` WHERE `guid` IN (377447, 377448);
DELETE FROM `creature_addon` WHERE `guid` IN (377447, 377448);

-- Creature Northgate Rebel 41015 SAI
SET @ENTRY := 41015;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 2000, 49, 0, 0, 0, 0, 0, 0, 11, 35627, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 0 ms (and later repeats every 2000 and 2000 ms) - Self: Attack Creature Frenzied Stalker (35627) in 0 yd // ");

UPDATE `creature_template` SET `VehicleID`= 1025, `speed_run`= 1.28571, `spell1`= 67063, `ScriptName`= 'npc_crowleys_horse' WHERE `entry`= 44428;

-- Creature Lord Darius Crowley 35566 SAI
SET @ENTRY := 35566;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 20, 0, 100, 0, 14222, 0, 0, 0, 85, 98274, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player rewards quest 14222 - Invoker: Cast spell 98274 to Action invoker // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, 68630, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell 68630 to Action invoker // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 72788, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Invoker: Cast spell 72788 to Action invoker // ");
