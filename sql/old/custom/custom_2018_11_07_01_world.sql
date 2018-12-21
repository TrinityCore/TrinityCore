-- Add Venomtip visual aura to Venomtip Needler
DELETE FROM `creature_template_addon` WHERE `entry` IN (52379);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(52379, '96912');

-- Remove Poison Cloud aura from toxic plants to handle them via instance script and turn them passive
UPDATE `creature_template` SET `flags_extra`= 2 WHERE `entry` IN (52332, 52331);
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry` IN (52332, 52331);

-- Update Venomtip Needler and Florawing Needler random movement
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `id` IN (52379, 52377);

-- Set ready 1h emote for entrance Siame-Quashi
DELETE FROM `creature_addon` WHERE `guid` IN (295169, 295167, 295172, 295174);
INSERT INTO `creature_addon` (`guid`, `bytes2`, `emote`) VALUES
(295169, 1, 333),
(295167, 1, 333),
(295172, 1, 333),
(295174, 1, 333);

-- Zanzil's Cauldron of Toxic Torment
UPDATE `creature_template` SET `unit_flags`= 0x200 WHERE `entry`= 52529;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`= 52529;

DELETE FROM `creature_text` WHERE `CreatureID`= 52380;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(52380, 0, 0, 'Mauri\'s death removes the protections from a nearby cauldron!', 41, 0, 100, 0, 0, 0, 51367, 'Venomancer Mauri - Death');

-- Creature Venomancer Mauri 52380
SET @ENTRY := 52380;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 65, `mechanic_immune_mask`= 16	| 65536 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 86, 96937, 0, 10, 295158, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - SMART_TARGET_CREATURE_GUID: Cast spell 96937 at Self // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 86, 96936, 0, 10, 295157, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - SMART_TARGET_CREATURE_GUID: Cast spell 96936 at Self // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 0, 0, 10, 295156, 0, 0, 0, 0, 0, 0, " Linked - Creature Zanzil's Cauldron of Toxic Torment 52529 (295156): Set UNIT_FLAGS to UNIT_FLAG_NOT_SELECTABLE // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 86, 97122, 0, 10, 295156, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - SMART_TARGET_CREATURE_GUID: Cast spell 97122 at Self // "),
(@ENTRY, 0, 4, 5, 6, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Talk 0 // "),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 10, 295156, 0, 0, 0, 0, 0, 0, " Linked - Creature Zanzil's Cauldron of Toxic Torment 52529 (295156): Remove UNIT_FLAGS to UNIT_FLAG_NOT_SELECTABLE // "),
(@ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 97122, 0, 0, 0, 0, 0, 10, 295156, 0, 0, 0, 0, 0, 0, " Linked - Creature Zanzil's Cauldron of Toxic Torment 52529 (295156): Remove aura due to spell 97122 // "),
(@ENTRY, 0, 7, 8, 4, 0, 100, 0, 0, 0, 0, 0, 28, 96936, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Remove aura due to spell 96936 // "),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 96937, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Remove aura due to spell 96937 // "),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 4000, 4000, 7000, 7000, 11, 96918, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4000 and 4000 ms (and later repeats every 7000 and 7000 ms) - Self: Cast spell 96918 on Victim // "),
(@ENTRY, 0, 10, 0, 0, 0, 100, 0, 7000, 7000, 9000, 9000, 11, 96466, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 9000 and 9000 ms) - Self: Cast spell 96466 on Random hostile // ");

DELETE FROM `creature_text` WHERE `CreatureID`= 52381;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(52381, 0, 0, 'I\'m gonna turn ya\' blood ta venom!', 12, 0, 100, 0, 0, 0, 51221, 'Venomancer T\'Kulu - Aggro'),
(52381, 1, 0, 'T\'kulu\'s death removes the protections from a nearby cauldron!', 41, 0, 100, 0, 0, 0, 51368, 'Venomancer T\'Kulu - Death');

-- Creature Venomancer T'Kulu 52381
SET @ENTRY := 52381;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 65, `mechanic_immune_mask`= 16	| 65536 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 86, 96937, 0, 10, 295004, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - SMART_TARGET_CREATURE_GUID: Cast spell 96937 at Self // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 86, 96936, 0, 10, 295002, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - SMART_TARGET_CREATURE_GUID: Cast spell 96936 at Self // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 0, 0, 10, 295003, 0, 0, 0, 0, 0, 0, " Linked - Creature Zanzil's Cauldron of Toxic Torment 52529 (295003): Set UNIT_FLAGS to UNIT_FLAG_NOT_SELECTABLE // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 86, 97122, 0, 10, 295003, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - SMART_TARGET_CREATURE_GUID: Cast spell 97122 at Self // "),
(@ENTRY, 0, 4, 5, 6, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Talk 1 // "),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 10, 295003, 0, 0, 0, 0, 0, 0, " Linked - Creature Zanzil's Cauldron of Toxic Torment 52529 (295003): Remove UNIT_FLAGS to UNIT_FLAG_NOT_SELECTABLE // "),
(@ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 97122, 0, 0, 0, 0, 0, 10, 295003, 0, 0, 0, 0, 0, 0, " Linked - Creature Zanzil's Cauldron of Toxic Torment 52529 (295003): Remove aura due to spell 97122 // "),
(@ENTRY, 0, 7, 8, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Talk 0 // "),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 28, 96936, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Remove aura due to spell 96936 // "),
(@ENTRY, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 96937, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Remove aura due to spell 96937 // "),
(@ENTRY, 0, 10, 0, 0, 0, 100, 0, 4000, 4000, 6000, 6000, 11, 96918, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4000 and 4000 ms (and later repeats every 6000 and 6000 ms) - Self: Cast spell 96918 on Victim // "),
(@ENTRY, 0, 11, 0, 0, 0, 100, 0, 7000, 7000, 14000, 14000, 11, 96475, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 14000 and 14000 ms) - Self: Cast spell 96475 on Self // ");
