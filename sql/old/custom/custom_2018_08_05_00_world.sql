-- Template Updates
-- Shadow of Obsidius
UPDATE `creature_template` SET `modelid1`= 35979, `BaseVariance`= 0.5, `DamageModifier`= 8 WHERE `entry`= 40818;
UPDATE `creature_template` SET `BaseVariance`= 0.5, `DamageModifier`= 4 WHERE `entry`= 40817;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (40817, 40818);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(40817, '76190 76164 76167 75054'),
(40818, '76190 76164 76167 75054');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_obsidius_twitchy',
'spell_obsidius_transformation',
'spell_obsidius_transformation_not_selectable',
'spell_obsidius_transformation_scale',
'spell_obsidius_crepuscular_veil');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76167, 'spell_obsidius_twitchy'),
(76196, 'spell_obsidius_transformation'),
(76242, 'spell_obsidius_transformation_not_selectable'),
(76200, 'spell_obsidius_transformation_scale'),
(76189, 'spell_obsidius_crepuscular_veil');

-- Procs
DELETE FROM `spell_proc` WHERE `SpellId`= 76167;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(76167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (76196, 82393) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 76196, 0, 0, 31, 0, 3, 40817, 0, 0, 0, '', 'Transformation - Target Shadow of Obsidius'),
(13, 1, 82393, 0, 0, 31, 0, 3, 39670, 0, 0, 0, '', 'Stop Heart - Target Raz the Crazed');

-- Areatriggers
DELETE FROM `areatrigger_scripts` WHERE `entry`= 6016;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6016, 'at_raz_obsidius_event');

-- Creature Twilight Element Warden SAI
SET @ENTRY := -361820;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 200, 300, 4000, 5000, 11, 75205, 0, 0, 0, 0, 0, 19, 40343, 200, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 200 and 300 ms (and later repeats every 4000 and 5000 ms) - Self: Cast spell 75205 on Closest alive creature Channel Target (40343) in 200 yards // Twilight Element Warden - Out of Combat - Cast 'Bore'"),
(@ENTRY, 0, 1, 2, 25, 0, 100, 0, 0, 0, 0, 0, 11, 74919, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 74919 on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 2111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set faction to 2111 // "),
(@ENTRY, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 10, 361667, 0, 0, 0, 0, 0, 0, "On death - Creature Ascendant Lord Obsidius 39705 (361667): Set creature data #0 to 0 // ");

SET @ENTRY := -361822;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 200, 300, 4000, 5000, 11, 75205, 0, 0, 0, 0, 0, 19, 40343, 200, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 200 and 300 ms (and later repeats every 4000 and 5000 ms) - Self: Cast spell 75205 on Closest alive creature Channel Target (40343) in 200 yards // Twilight Element Warden - Out of Combat - Cast 'Bore'"),
(@ENTRY, 0, 1, 2, 25, 0, 100, 0, 0, 0, 0, 0, 11, 74919, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 74919 on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 2111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set faction to 2111 // "),
(@ENTRY, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 10, 361667, 0, 0, 0, 0, 0, 0, "On death - Creature Ascendant Lord Obsidius 39705 (361667): Set creature data #0 to 0 // ");

SET @ENTRY := -361824;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 200, 300, 4000, 5000, 11, 75205, 0, 0, 0, 0, 0, 19, 40343, 200, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 200 and 300 ms (and later repeats every 4000 and 5000 ms) - Self: Cast spell 75205 on Closest alive creature Channel Target (40343) in 200 yards // Twilight Element Warden - Out of Combat - Cast 'Bore'"),
(@ENTRY, 0, 1, 2, 25, 0, 100, 0, 0, 0, 0, 0, 11, 74919, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 74919 on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 2111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set faction to 2111 // "),
(@ENTRY, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 10, 361667, 0, 0, 0, 0, 0, 0, "On death - Creature Ascendant Lord Obsidius 39705 (361667): Set creature data #0 to 0 // ");

SET @ENTRY := -361825;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 200, 300, 4000, 5000, 11, 75205, 0, 0, 0, 0, 0, 19, 40343, 200, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 200 and 300 ms (and later repeats every 4000 and 5000 ms) - Self: Cast spell 75205 on Closest alive creature Channel Target (40343) in 200 yards // Twilight Element Warden - Out of Combat - Cast 'Bore'"),
(@ENTRY, 0, 1, 2, 25, 0, 100, 0, 0, 0, 0, 0, 11, 74919, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 74919 on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 2111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set faction to 2111 // "),
(@ENTRY, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 10, 361667, 0, 0, 0, 0, 0, 0, "On death - Creature Ascendant Lord Obsidius 39705 (361667): Set creature data #0 to 0 // ");

SET @ENTRY := -361823;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 200, 300, 4000, 5000, 11, 75205, 0, 0, 0, 0, 0, 19, 40343, 200, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 200 and 300 ms (and later repeats every 4000 and 5000 ms) - Self: Cast spell 75205 on Closest alive creature Channel Target (40343) in 200 yards // Twilight Element Warden - Out of Combat - Cast 'Bore'"),
(@ENTRY, 0, 1, 2, 25, 0, 100, 0, 0, 0, 0, 0, 11, 74919, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 74919 on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 2111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set faction to 2111 // "),
(@ENTRY, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 10, 361667, 0, 0, 0, 0, 0, 0, "On death - Creature Ascendant Lord Obsidius 39705 (361667): Set creature data #0 to 0 // ");

SET @ENTRY := -361819;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 200, 300, 4000, 5000, 11, 75205, 0, 0, 0, 0, 0, 19, 40343, 200, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 200 and 300 ms (and later repeats every 4000 and 5000 ms) - Self: Cast spell 75205 on Closest alive creature Channel Target (40343) in 200 yards // Twilight Element Warden - Out of Combat - Cast 'Bore'"),
(@ENTRY, 0, 1, 2, 25, 0, 100, 0, 0, 0, 0, 0, 11, 74919, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 74919 on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 2111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set faction to 2111 // "),
(@ENTRY, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 10, 361667, 0, 0, 0, 0, 0, 0, "On death - Creature Ascendant Lord Obsidius 39705 (361667): Set creature data #0 to 0 // ");

SET @ENTRY := -361821;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 200, 300, 4000, 5000, 11, 75205, 0, 0, 0, 0, 0, 19, 40343, 200, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 200 and 300 ms (and later repeats every 4000 and 5000 ms) - Self: Cast spell 75205 on Closest alive creature Channel Target (40343) in 200 yards // Twilight Element Warden - Out of Combat - Cast 'Bore'"),
(@ENTRY, 0, 1, 2, 25, 0, 100, 0, 0, 0, 0, 0, 11, 74919, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 74919 on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 2111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set faction to 2111 // "),
(@ENTRY, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 10, 361667, 0, 0, 0, 0, 0, 0, "On death - Creature Ascendant Lord Obsidius 39705 (361667): Set creature data #0 to 0 // ");

DELETE FROM `creature_formations` WHERE `leaderGUID`= 361820;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `groupAI`, `dist`, `angle`) VALUES
(361820, 361820, 3, 0, 0),
(361820, 361822, 3, 0, 0),
(361820, 361823, 3, 0, 0),
(361820, 361824, 3, 0, 0),
(361820, 361825, 3, 0, 0),
(361820, 361819, 3, 0, 0),
(361820, 361821, 3, 0, 0);

-- Achievement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15961;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15961, 11, 0, 0, 'achievement_ascendant_descending');
