-- Creature Garrosh Hellscream 39605 SAI
SET @ENTRY := 39605;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 65, `BaseVariance`= 0.5, `mechanic_immune_mask`= 617299839, `flags_extra`= 0x40000000 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 7000, 7000, 20000, 20000, 11, 84715, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 20000 and 20000 ms) - Self: Cast spell 84715 on Victim // "),
(@ENTRY, 0, 1, 2, 0, 0, 100, 0, 10000, 10000, 20000, 20000, 11, 50230, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 10000 ms (and later repeats every 20000 and 20000 ms) - Self: Cast spell 50230 on Random hostile // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 84724, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 84724 on Self // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 23000, 23000, 20000, 20000, 11, 61044, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 23000 and 23000 ms (and later repeats every 20000 and 20000 ms) - Self: Cast spell 61044 on Self // "),
(@ENTRY, 0, 4, 0, 0, 0, 100, 0, 33500, 33500, 20000, 20000, 11, 84742, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 33500 and 33500 ms (and later repeats every 20000 and 20000 ms) - Self: Cast spell 84742 on Random hostile // ");
