UPDATE `creature_template` SET `DamageModifier`= 120, `BaseVariance`= 1 WHERE `entry` IN (42649, 49490);
UPDATE `creature_template` SET `DamageModifier`= 100, `BaseVariance`= 1 WHERE `entry` IN (42362, 49489);

UPDATE `creature_template` SET `DamageModifier`= 180, `BaseVariance`= 1 WHERE `entry` IN (51102, 51103, 49980, 49986, 51105, 51106, 51117, 51118, 47775, 47776);

-- Creature Laser Strike 43362 SAI
SET @ENTRY := 43362;
UPDATE `creature_template` SET `flags_extra`= 128, `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 11, 81066, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (OOC) 1000 min and 1000 max ms (repeat 0 min 0 max ms) - Self: Cast spell 81066 on Self // ");

UPDATE `creature_template_addon` SET `auras`= '81065' WHERE `entry`= 43362;

-- Creature Golem Sentry 42800 SAI
SET @ENTRY := 42800;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 9000, 10000, 18000, 19000, 11, 81063, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 9000 min and 10000 max ms (repeat 18000 min 19000 max ms) - Self: Cast spell 81063 on Random hostile // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 9000, 10000, 7000, 7000, 11, 81055, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 9000 min and 10000 max ms (repeat 7000 min 7000 max ms) - Self: Cast spell 81055 on Random hostile // ");

UPDATE `creature_template` SET `mechanic_immune_mask`= 1 | 2 | 8 | 16 | 32 | 64 | 256 | 512 | 2048 | 4096 | 8192 | 65536 | 131072 | 4194304 | 8388608 | 33554432 | 67108864 WHERE `entry` IN (42800, 49501);
UPDATE `creature_template` SET `DamageModifier`= 120, `BaseVariance`= 1 WHERE `entry` IN (42800, 49501);
UPDATE `creature_template` SET `difficulty_entry_1`= 49501 WHERE `entry`= @ENTRY;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_walk`= 1.2, `speed_run`= 1, `unit_flags`= 32832, `lootid`= 42800 WHERE `entry`= 49501;

DELETE FROM `spell_custom_attr` WHERE `entry` IN (81067, 91884);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(81067, 0x10),
(91884, 0x10);
