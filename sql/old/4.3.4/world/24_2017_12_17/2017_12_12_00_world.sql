-- Oathsworn Captain
UPDATE `creature` SET `position_x`= -10784, `position_y`= -1397.36, `position_z`= 15.47772, `orientation`= 3.854353, `MovementType`= 2 WHERE `guid`= 295192;
UPDATE `creature` SET `position_x`= -10837.9, `position_y`= -1299.11, `position_z`= 15.44543, `orientation`= 3.379167, `MovementType`= 2 WHERE `guid`= 313314;
UPDATE `creature_template` SET `difficulty_entry_1`= 49334, `DamageModifier`= 15 WHERE `entry`= 45122;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `DamageModifier`= 20 WHERE `entry`= 49334;

DELETE FROM `waypoint_data` WHERE `id` IN (2951920, 3133140);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
-- Left Captain
(2951920, 1, -10792.2, -1403.64, 15.39894),
(2951920, 2, -10800.6, -1410.26, 15.47772),
(2951920, 3, -10806.6, -1412.06, 15.47772),
(2951920, 4, -10813.8, -1413.42, 15.47772),
(2951920, 5, -10821.1, -1414.79, 15.47772),
(2951920, 6, -10827.6, -1414.14, 15.47772),
(2951920, 7, -10821.1, -1414.79, 15.47772),
(2951920, 8, -10813.8, -1413.42, 15.47772),
(2951920, 9, -10806.6, -1412.06, 15.47772),
(2951920, 10, -10800.6, -1410.26, 15.47772),
(2951920, 11, -10792.2, -1403.64, 15.39894),
(2951920, 12, -10784, -1397.36, 15.47772),
-- Right Captain
(3133140, 1, -10847, -1303.65, 15.47772),
(3133140, 2, -10860.1, -1313.22, 15.47772),
(3133140, 3, -10855.1, -1309.42, 15.47772),
(3133140, 4, -10847, -1303.65, 15.47772),
(3133140, 5, -10837.9, -1299.11, 15.44543),
(3133140, 6, -10829.6, -1297.1, 15.41835),
(3133140, 7, -10822.9, -1296.66, 15.41835),
(3133140, 8, -10822.9, -1296.66, 15.41835),
(3133140, 9, -10829.6, -1297.1, 15.41835),
(3133140, 10, -10837.9, -1299.11, 15.44543);

DELETE FROM `creature_addon` WHERE `guid` IN (295192, 313314);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(295192, 2951920, 1),
(313314, 3133140, 1);

-- Earthquake
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 14, `unit_flags`= 33554432, `flags_extra`= 131 WHERE `entry`= 45126;
DELETE FROM `creature_template_addon` WHERE `entry`= 45126;
INSERT INTO `creature_template_addon` (`entry`, `Auras`) VALUES
(45126, '84249');

-- Creature Oathsworn Captain 45122 SAI
SET @ENTRY := 45122;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 10000, 13000, 17000, 11, 84248, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 10000 ms (and later repeats every 13000 and 17000 ms) - Self: Cast spell 84248 on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 6000, 10000, 13000, 17000, 11, 82670, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 10000 ms (and later repeats every 13000 and 17000 ms) - Self: Cast spell 82670 on Victim // ");

-- Enslaved Bandit visual
UPDATE `creature` SET `unit_flags`= 33587200 WHERE `guid` IN (339628, 339639);
DELETE FROM `creature_addon` WHERE `guid` IN (339628, 339639);
INSERT INTO `creature_addon` (`guid`, `emote`, `Auras`) VALUES
(339628, 420, '16245'),
(339639, 420, '16245');

-- Creature Enslaved Bandit 45007 SAI
SET @ENTRY := 45007;
UPDATE `creature_template` SET `InhabitType`= 1, `AIName`="SmartAI" WHERE `entry`= @ENTRY;

SET @ENTRY := -339628;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 60, 0, 100, 1, 100, 100, 0, 0, 18, 33556480, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 100 and 100 ms) - Self: Set UNIT_FLAGS_2 to 33556480 // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 84172, 2, 0, 0, 0, 0, 10, 339626, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 84172 on Creature Rope Beam Stalker 37231 (339626) // "),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 84168, 2, 0, 0, 0, 0, 10, 339623, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 84168 on Creature Rope Beam Stalker 37231 (339623) // "),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 11, 84167, 2, 0, 0, 0, 0, 10, 339624, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 84167 on Creature Rope Beam Stalker 37231 (339624) // "),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 84171, 2, 0, 0, 0, 0, 10, 339625, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 84171 on Creature Rope Beam Stalker 37231 (339625) // ");


SET @ENTRY := -339639;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 60, 0, 100, 1, 100, 100, 0, 0, 18, 33556480, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 100 and 100 ms) - Self: Set UNIT_FLAGS_2 to 33556480 // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 84168, 2, 0, 0, 0, 0, 10, 339620, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 84168 on Creature Rope Beam Stalker 37231 (339620) // "),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 84167, 2, 0, 0, 0, 0, 10, 339621, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 84167 on Creature Rope Beam Stalker 37231 (339621) // "),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 11, 84171, 2, 0, 0, 0, 0, 10, 339636, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 84171 on Creature Rope Beam Stalker 37231 (339636) // "),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 84172, 2, 0, 0, 0, 0, 10, 339637, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 84172 on Creature Rope Beam Stalker 37231 (339637) // ");

-- Creature Pygmy Brute 44896 SAI
SET @ENTRY := 44896;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 1, 0, 0, 0, 0, 12, 44897, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Summon creature Pygmy Scout (44897) at Self, moved by offset (0, 0, 0, 0) // ");

-- Creature Pygmy Scout 44897 SAI
SET @ENTRY := 44897;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 1, 0, 0, 0, 0, 67, 0, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Trigger timed event #0 in 100 - 100 ms // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 44898, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Summon creature Pygmy Firebreather (44898) at Self, moved by offset (0, 0, 0, 0) // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 46598, 0, 0, 0, 0, 0, 11, 44896, 5, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 46598 on Creature Pygmy Brute (44896) in 5 yd // ");

-- Creature Pygmy Firebreather 44898 SAI
SET @ENTRY := 44898;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 67, 0, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Trigger timed event #0 in 100 - 100 ms // "),
(@ENTRY, 0, 1, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 47020 , 0, 0, 0, 0, 0, 11, 44897, 5, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 47020  on Creature Pygmy Scout (44897) in 5 yd // ");

-- Wind Tunnels
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 755 AND `summonerType`= 2;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`) VALUES
(755, 2, 0, 48092, -10891.5, -1379.72, 15.436, 5.34071, 8),
(755, 2, 0, 48092, -10964.9, -1481.17, 6.75973, 5.34071, 8),
(755, 2, 0, 48092, -10930.6, -1302.74, 2.202043, 5.35816, 8),
(755, 2, 0, 48092, -10998.4, -1356.15, 10.8898, 5.34071, 8),
(755, 2, 0, 48092, -11027.7, -1427.97, 5.69384, 5.34071, 8),
(755, 2, 0, 48092, -10887.7, -1447.7, 2.24816, 4.74729, 8);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 48092;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(48092, 93970, 1, 0);

DELETE FROM `creature` WHERE `guid` IN (339650, 339653, 339654, 339656, 339659, 339661);
DELETE FROM `creature_addon` WHERE `guid` IN (339650, 339653, 339654, 339656, 339659, 339661);
DELETE FROM `creature_template_addon` WHERE `entry`= 48092;
INSERT INTO `creature_template_addon` (`entry`, `Auras`) VALUES
(48092, '89698');

-- Creature Wind Tunnel 48092 SAI
SET @ENTRY := 48092;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 93970, 0, 0, 0, 67, 0, 500, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell 93970 hit  - Trigger timed event #0 in 500 - 500 ms // "),
(@ENTRY, 0, 1, 0, 59, 0, 100, 0, 0, 0, 0, 0, 11, 85016, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 85016 on Action invoker // ");

DELETE FROM `conditions` WHERE `SourceEntry`= 85017;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 85017, 0, 0, 31, 0, 3, 48097, 0, 0, 0, '', 'Slipstream - Target Wind Tunnel Landing Zone');

-- Creature Wind Tunnel Landing Zone 48097 SAI
SET @ENTRY := 48097;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 27, 0, 100, 0, 0, 0, 0, 0, 67, 0, 1500, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On passenger boarded (vehicle) - Trigger timed event #0 in 1500 - 1500 ms // "),
(@ENTRY, 0, 1, 0, 59, 0, 100, 1, 0, 0, 0, 0, 28, 85017, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Remove aura due to spell 85017 // ");

