UPDATE `creature_template` SET `ScriptName`= 'npc_tott_ozumat_vehicle_big' WHERE `entry`= 45030;
UPDATE `creature_template` SET `VehicleId`= 1074 WHERE `entry`= 49101;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (45030, 49101);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(45030, 46598, 1, 1),
(49101, 46598, 1, 1);

-- Naz'jar Sentinel
SET @ENTRY := 40577;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4000, 6000, 4000, 6000, 11, 77218, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4000 and 6000 ms (and later repeats every 4000 and 6000 ms) - Self: Cast spell 77218 on Random hostile // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 13000, 14000, 13000, 14000, 11, 76721, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 13000 and 14000 ms (and later repeats every 13000 and 14000 ms) - Self: Cast spell 76721 on Victim // ");
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry`= 40577;
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 49087;
UPDATE `creature_template` SET `mechanic_immune_mask`= 1 | 2 | 4 | 16 | 32 | 512 | 65536 | 131072, `flags_extra`= 0x40000000 WHERE `entry` IN (40577, 49087);

-- Noxius Mire
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 41201;
DELETE FROM `creature_template_addon` WHERE `entry`= 41201;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(41201, '77217');

-- Naz'jar Invader and Naz'jar Spiritmender
UPDATE `creature_template` SET `unit_flags`= `unit_flags` & ~256, `InhabitType`= 1, `flags_extra`= 0x00000200 WHERE `entry` IN (41096, 49090, 39616, 49085);
UPDATE `creature_template` SET `BaseVariance`= 0.5, `DamageModifier`= 15 WHERE `entry` IN (41096, 39616);
UPDATE `creature_template` SET `BaseVariance`= 0.5, `DamageModifier`= 30 WHERE `entry` IN (49090, 49085);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`= 74465 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 74465, 0, 0, 31, 0, 3, 22515, 0, 0, 0, '', 'Summon Falling Rocks - Target World Trigger');

-- Areatriggers
DELETE FROM `areatrigger_scripts` WHERE `entry`= 5806;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5806, 'at_tott_first_invader_event');

-- Creature Naz'jar Spiritmender 41096 SAI
SET @ENTRY := 41096;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1500, 1500, 2400, 2400, 11, 76815, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1500 and 1500 ms (and later repeats every 2400 and 2400 ms) - Self: Cast spell 76815 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 22000, 23000, 14000, 15000, 11, 76820, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 22000 and 23000 ms (and later repeats every 14000 and 15000 ms) - Self: Cast spell 76820 on Random hostile // "),
(@ENTRY, 0, 2, 0, 2, 0, 100, 0, 0, 50, 5000, 5000, 11, 76813, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 50% (check every 5000 - 5000 ms) - Self: Cast spell 76813 on Self // ");

-- Creature Naz'jar Invader 39616 SAI
SET @ENTRY := 39616;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 5000, 7000, 5000, 7000, 11, 76807, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 5000 and 7000 ms (for the first time, timer between 5000 and 7000 ms) - Self: Cast spell 76807 on Victim // "),
(@ENTRY, 0, 1, 0, 2, 0, 100, 0, 0, 50, 5000, 5000, 86, 76813, 0, 11, 41096, 20, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 50% (check every 5000 - 5000 ms) - SMART_TARGET_CREATURE_DISTANCE: Cast spell 76813 at Self // ");
