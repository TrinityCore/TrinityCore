-- Template Updates
-- Lady Naz'jar
UPDATE `creature_template` SET `ScriptName`= 'boss_lady_nazjar', `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry`= 40586;
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 49080;
UPDATE `creature_template` SET `mingold`= 19800, `maxgold`= 20000, `mechanic_immune_mask`= 80297855 WHERE `entry` IN (49080, 40586);
-- Geyser (Room Limitation)
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 1073743872, `flags_extra`= 128 WHERE `entry`= 48983;
-- Geyser
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 40597;
-- Naz'jar Honor Guard
UPDATE `creature_template` SET `ScriptName`= 'npc_nazjar_nazjar_honor_guard', `difficulty_entry_1`= 49084, `DamageModifier`= 30 WHERE `entry`= 40633;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `unit_flags`= 32832, `DamageModifier`= 60 WHERE `entry`= 49084;
-- Naz'jar Tempest Witch
UPDATE `creature_template` SET `ScriptName`= 'npc_nazjar_nazjar_tempest_witch', `difficulty_entry_1`= 49093, `speed_run`= 1.14286 WHERE `entry`= 44404;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `unit_flags`= 32832, `unit_class`= 2 WHERE `entry`= 49093;
-- Waterspout
UPDATE `creature_template` SET `speed_run`= 0.14285, `unit_flags`= 34112000, `unit_flags2`= 2099200, `flags_extra`= 128, `VehicleId`= 1338 WHERE `entry`= 48571;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 40586;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(40586, 0, 0, 'You have interfered with our plans for the last time, mortals!', 14, 0, 100, 0, 0, 18886, 50505, 'Lady Naz''jar - Aggro'),
(40586, 1, 0, 'Depths take you!', 14, 0, 100, 0, 0, 18887, 50506, 'Lady Naz''jar - Slay'),
(40586, 2, 0, 'Take arms, minions! Rise from the icy depths!', 14, 0, 100, 0, 0, 18892, 50513, 'Lady Naz''jar - Summon Adds 1'),
(40586, 2, 1, 'Destroy these intruders! Leave them for the great dark beyond!', 14, 0, 100, 0, 0, 18893, 50514, 'Lady Naz''jar - Summon Adds 2'),
(40586, 3, 0, 'Ulthok, stop them...', 14, 0, 100, 0, 0, 18889, 50509, 'Lady Naz''jar - Death');

-- Addons
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry` IN (48983, 40586);
UPDATE `creature_addon` SET `auras`= '' WHERE `guid` IN (254914, 254915, 254918, 254920, 254922, 255017);
DELETE FROM `creature_template_addon` WHERE `entry` IN (40633, 44404, 48571);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(48571, '90440');

-- Delete encounter spawned creatures
DELETE FROM `creature` WHERE `guid`IN (255060, 255061);
DELETE FROM `creature_addon` WHERE `guid`IN (255060, 255061);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (94046, 94047, 75690) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 3, 94046, 0, 0, 31, 0, 3, 40633, 0, 0, 0, '', 'Waterspout - Target Naz''jar Honor Guard'),
(13, 3, 94046, 0, 1, 31, 0, 3, 44404, 0, 0, 0, '', 'Waterspout - Target Naz''jar Tempest Witch'),
(13, 3, 94047, 0, 0, 31, 0, 3, 40633, 0, 0, 0, '', 'Waterspout - Target Naz''jar Honor Guard'),
(13, 3, 94047, 0, 1, 31, 0, 3, 44404, 0, 0, 0, '', 'Waterspout - Target Naz''jar Tempest Witch'),
(13, 2, 75690, 0, 0, 31, 0, 3, 40633, 0, 0, 0, '', 'Waterspout - Target Naz''jar Honor Guard'),
(13, 2, 75690, 0, 1, 31, 0, 3, 44404, 0, 0, 0, '', 'Waterspout - Target Naz''jar Tempest Witch');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_nazjar_waterspout';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(90484, 'spell_nazjar_waterspout');

-- Serverside spells
DELETE FROM `spell_dbc` WHERE `Id`= 94042;
INSERT INTO `spell_dbc`(`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellInterruptsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `Comment`) VALUES
(94042, 8388864, 268435592, 5, 268435712, 128, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 38, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Achievement - Old Faithful');
