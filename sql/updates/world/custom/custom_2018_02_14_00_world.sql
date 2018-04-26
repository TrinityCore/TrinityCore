-- Template Updates
-- Glubtok
UPDATE `creature_template` SET `scriptname`= 'boss_glubtok' WHERE `entry`= 47162;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87 WHERE `entry`=48936;
-- General Purpose Bunny JMF Look 2
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 47242;
-- General Purpose Bunny JMF
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 45979;
-- Glubtok Firewall Platter
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 48974;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 47162;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
(47162, 0, 0, 'Glubtok show you da power of de arcane!', 14, 0, 100, 0, 0, 21151, 47256, 'Glubtok to Player'),
(47162, 1, 0, 'Fists of flame!', 14, 0, 100, 0, 0, 21153, 47239, 'Glubtok'),
(47162, 2, 0, 'Fists of frost!', 14, 0, 100, 0, 0, 21156, 47238, 'Glubtok'),
(47162, 3, 0, 'Glubtok ready?', 14, 0, 100, 1, 0, 21154, 47361, 'Glubtok'),
(47162, 4, 0, 'Let''s do it!', 14, 0, 100, 15, 0, 21157, 47362, 'Glubtok'),
(47162, 5, 0, 'ARCANE POWER!!!', 14, 0, 100, 15, 0, 21146, 47363, 'Glubtok'),
(47162, 6, 0, '|TInterface\\Icons\\spell_holy_innerfire.blp:20|t Glubtok creates a moving |cFFFF0000|Hspell:91398|h[Fire Wall]|h|r!', 41, 0, 100, 0, 0, 0, 49155, 'Glubtok'),
(47162, 7, 0, 'TOO...MUCH...POWER!!!', 14, 0, 100, 15, 0, 21145, 47422, 'Glubtok');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (88072, 88093) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 88072, 0, 0, 31, 0, 3, 47162, 0, 0, 0, '', 'Arcane Fire Beam - Target Glubtok'),
(13, 1, 88093, 0, 0, 31, 0, 3, 47162, 0, 0, 0, '', 'Arcane Frost Beam - Target Glubtok');

-- Spells
DELETE FROM `spell_proc` WHERE `SpellId` IN (87900, 87897);
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `Cooldown`) VALUES
(87900, 0x00000004, 1, 0, 4000),
(87897, 0x00000004, 1, 0, 4000);

-- Spellclick spells
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (48974, 48975, 49039, 49040);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(48974, 46598, 1, 1),
(48975, 47020, 1, 1),
(49039, 47020, 1, 1),
(49040, 47020, 1, 1);

-- Vehicle Accessory
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (48974, 48975, 49039, 49040);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(48974, 48975, 0, 1, 'Glubtok Firewall Platter', 5, 0),
(48974, 49039, 1, 1, 'Glubtok Firewall Platter', 5, 0),
(48974, 49040, 2, 1, 'Glubtok Firewall Platter', 5, 0),
(48974, 49040, 3, 1, 'Glubtok Firewall Platter', 5, 0),
(48974, 48975, 4, 1, 'Glubtok Firewall Platter', 5, 0),
(48974, 49039, 5, 1, 'Glubtok Firewall Platter', 5, 0),
(48974, 49040, 6, 1, 'Glubtok Firewall Platter', 5, 0),
(48974, 49040, 7, 1, 'Glubtok Firewall Platter', 5, 0),
(49040, 49042, 5, 1, 'Glubtok Firewall Platter Creature Level 1c - Glubtok Firewall Platter Creature Level 2c', 5, 0), -- Glubtok Firewall Platter Creature Level 1c - Glubtok Firewall Platter Creature Level 2c
(49040, 49042, 4, 1, 'Glubtok Firewall Platter Creature Level 1c - Glubtok Firewall Platter Creature Level 2c', 5, 0), -- Glubtok Firewall Platter Creature Level 1c - Glubtok Firewall Platter Creature Level 2c
(49040, 49042, 1, 1, 'Glubtok Firewall Platter Creature Level 1c - Glubtok Firewall Platter Creature Level 2c', 5, 0), -- Glubtok Firewall Platter Creature Level 1c - Glubtok Firewall Platter Creature Level 2c
(49040, 49042, 0, 1, 'Glubtok Firewall Platter Creature Level 1c - Glubtok Firewall Platter Creature Level 2c', 5, 0), -- Glubtok Firewall Platter Creature Level 1c - Glubtok Firewall Platter Creature Level 2c
(49039, 49041, 5, 1, 'Glubtok Firewall Platter Creature Level 1b - Glubtok Firewall Platter Creature Level 2b', 5, 0), -- Glubtok Firewall Platter Creature Level 1b - Glubtok Firewall Platter Creature Level 2b
(49039, 49041, 4, 1, 'Glubtok Firewall Platter Creature Level 1b - Glubtok Firewall Platter Creature Level 2b', 5, 0), -- Glubtok Firewall Platter Creature Level 1b - Glubtok Firewall Platter Creature Level 2b
(49039, 49041, 1, 1, 'Glubtok Firewall Platter Creature Level 1b - Glubtok Firewall Platter Creature Level 2b', 5, 0), -- Glubtok Firewall Platter Creature Level 1b - Glubtok Firewall Platter Creature Level 2b
(49039, 49041, 0, 1, 'Glubtok Firewall Platter Creature Level 1b - Glubtok Firewall Platter Creature Level 2b', 5, 0), -- Glubtok Firewall Platter Creature Level 1b - Glubtok Firewall Platter Creature Level 2b
(48975, 48976, 5, 1, 'Glubtok Firewall Platter Creature Level 1a - Glubtok Firewall Platter Creature Level 2a', 5, 0), -- Glubtok Firewall Platter Creature Level 1a - Glubtok Firewall Platter Creature Level 2a
(48975, 48976, 4, 1, 'Glubtok Firewall Platter Creature Level 1a - Glubtok Firewall Platter Creature Level 2a', 5, 0), -- Glubtok Firewall Platter Creature Level 1a - Glubtok Firewall Platter Creature Level 2a
(48975, 48976, 1, 1, 'Glubtok Firewall Platter Creature Level 1a - Glubtok Firewall Platter Creature Level 2a', 5, 0), -- Glubtok Firewall Platter Creature Level 1a - Glubtok Firewall Platter Creature Level 2a
(48975, 48976, 0, 1, 'Glubtok Firewall Platter Creature Level 1a - Glubtok Firewall Platter Creature Level 2a', 5, 0); -- Glubtok Firewall Platter Creature Level 1a - Glubtok Firewall Platter Creature Level 2a

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_glubtok_blossom_targeting';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88140, 'spell_glubtok_blossom_targeting');

-- Creature Fire Blossom 48957 SAI
SET @ENTRY := 48957;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Attack Players in 30 yards // ");

-- Creature Frost Blossom 48957 SAI
SET @ENTRY := 48958;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Attack Players in 30 yards // ");

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id`= 48936;
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(48936, 395, 7000);

-- Loot
UPDATE creature_template SET `lootid`= 47162 WHERE `entry`= 47162;
DELETE FROM `creature_loot_template` WHERE `entry` IN (47162, 48936);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(47162, 5195, 0, 1, 1, 1, 1),
(47162, 2169, 0, 1, 1, 1, 1),
(47162, 5194, 0, 1, 1, 1, 1);

UPDATE creature_template SET `lootid`= 48936 WHERE `entry`= 48936;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(48936, 63467, 0, 1, 1, 1, 1),
(48936, 63468, 0, 1, 1, 1, 1),
(48936, 63471, 0, 1, 1, 1, 1),
(48936, 63470, 0, 1, 1, 1, 1),
(48936, 65163, 0, 1, 1, 1, 1);
