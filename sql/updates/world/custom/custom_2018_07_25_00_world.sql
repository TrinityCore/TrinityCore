-- Template Updates
-- Corla, Herald of Twilight
UPDATE `creature_template` SET `ScriptName`= 'boss_corla_herald_of_twilight' WHERE `entry`= 39679;
-- Twilight Zealot
UPDATE `creature_template` SET `ScriptName`= 'npc_corla_twilight_zealot' WHERE `entry`= 50284;
UPDATE `creature_template` SET `mechanic_immune_mask`= 1 | 2 | 4 | 8 | 16 | 32 | 256 | 512 | 2048 | 4096 | 8192 | 65536	| 131072 | 8388608, `flags_extra`= 0x40000000 WHERE `entry` IN (50284, 50285, 39987, 39988);
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry`= 39987;
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 39988;

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_corla_nether_dragon_essence',
'spell_nether_dragon_essence_1',
'spell_nether_dragon_essence_2',
'spell_corla_nether_dragon_essence_visual',
'spell_corla_nether_beam',
'spell_corla_evolution',
'spell_corla_grievous_whirl');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75649, 'spell_corla_nether_dragon_essence'),
(75650, 'spell_corla_nether_dragon_essence_visual'),
(75653, 'spell_corla_nether_dragon_essence_visual'),
(75654, 'spell_corla_nether_dragon_essence_visual'),
(75676, 'spell_corla_nether_beam'),
(75697, 'spell_corla_evolution'),
(87378, 'spell_corla_evolution'),
(76524, 'spell_corla_grievous_whirl'),
(93658, 'spell_corla_grievous_whirl');

DELETE FROM `conditions` WHERE `SourceEntry`= 75677 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 75677, 0, 0, 31, 0, 3, 39842, 0, 0, 0, '', 'Nether Beam - Target Invisible Stalker');

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry`= 39842;
DELETE FROM `creature_addon` WHERE `guid`= 361693;
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(361693, '75649');

-- Delete encounter related creatures
DELETE FROM `creature` WHERE `guid` IN (361875, 361876);
DELETE FROM `creature_addon` WHERE `guid` IN (361875, 361876);

DELETE FROM `spell_proc` WHERE `SpellId` IN (76524, 93658);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(76524, 0, 0, 0, 0, 0x00008000| 0x00080000, 7, 0, 0, 0, 0, 0, 100),
(93658, 0, 0, 0, 0, 0x00008000| 0x00080000, 7, 0, 0, 0, 0, 0, 100);

-- Achievement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15944;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15944, 11, 0, 0, 'achievement_arrested_development');
