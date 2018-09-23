-- Template Updates
-- High Priestes Kilnara
UPDATE `creature_template` SET `DamageModifier`= 120, `BaseVariance`= 0.5, `mingold`= 20000, `maxgold`= 21000, `mechanic_immune_mask`= 80297855,`ScriptName`= 'boss_high_priestess_kilnara' WHERE `entry`= 52059;
-- Avatar of Bethekk
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5, `exp`= 3,  `minlevel`= 87, `maxlevel`= 87, `mechanic_immune_mask`= 617299839 WHERE `entry`= 52602;
-- Pride of Bethekk
UPDATE `creature_template` SET `DamageModifier`= 10, `BaseVariance`= 0.5, `unit_flags`= 0x8000, `ScriptName`= 'npc_kilnara_pride_of_bethekk' WHERE `entry`= 52061;
-- Pride of Bethekk (Transform)
UPDATE `creature_template` SET `unit_flags`= 0x8000 WHERE `entry`= 52061;
-- Wave of Agony
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 52160;
-- Wave of Agony (Visual wave)
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 2 WHERE `entry`= 52147;

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_kilnara_tears_of_blood',
'spell_kilnara_wave_of_agony',
'spell_kilnara_wave_of_agony_dummy',
'spell_kilnara_primal_awakening',
'spell_kilnara_gaping_wound');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(96435, 'spell_kilnara_tears_of_blood'),
(98270, 'spell_kilnara_wave_of_agony'),
(96457, 'spell_kilnara_wave_of_agony_dummy'),
(96530, 'spell_kilnara_primal_awakening'),
(97355, 'spell_kilnara_gaping_wound');

DELETE FROM `creature_template_addon` WHERE `entry`= 52147;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(52147, '96532');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (96465, 96530) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 96465, 0, 0, 31, 0, 3, 52160, 0, 0, 0, '', 'Wave of Agony - Target Wave of Agony'),
(13, 1, 96530, 0, 0, 31, 0, 3, 52061, 0, 0, 0, '', 'Primale Awakening - Target Pride of Bethekk');

-- Summon Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 52059;
INSERT INTO `creature_summon_groups` (`groupId`, `summonerId`, `summonerType`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(0, 52059, 0, 52061, -11517.2, -1646.82, 44.4849, 3.87463, 6, 4000),
(0, 52059, 0, 52061, -11518.1, -1651.48, 44.4849, 2.26893, 6, 4000),
(0, 52059, 0, 52061, -11520.6, -1646,    44.4849, 4.95674, 6, 4000),
(0, 52059, 0, 52061, -11521.8, -1651.58, 44.4849, 0.977384, 6, 4000),
(0, 52059, 0, 52061, -11504.1, -1650.26, 44.4849, 2.26893, 6, 4000),
(0, 52059, 0, 52061, -11508.7, -1603.38, 44.4849, 5.41052, 6, 4000),
(0, 52059, 0, 52061, -11508.3, -1607.37, 44.4849, 0.977384, 6, 4000),
(0, 52059, 0, 52061, -11523.2, -1609.31, 44.4849, 0.977384, 6, 4000),
(0, 52059, 0, 52061, -11523.2, -1605.96, 44.4849, 5.41052, 6, 4000),
(0, 52059, 0, 52061, -11519.7, -1609,    44.4849, 2.26893, 6, 4000),
(0, 52059, 0, 52061, -11519.2, -1605.37, 44.4849, 3.56047, 6, 4000),
(0, 52059, 0, 52061, -11504.6, -1603.33, 44.4849, 3.87463, 6, 4000),
(0, 52059, 0, 52061, -11504.3, -1645.56, 44.4849, 4.66003, 6, 4000),
(0, 52059, 0, 52061, -11507,   -1644.55, 44.4849, 4.7822, 6, 4000),
(0, 52059, 0, 52061, -11506.6, -1651.04, 44.4849, 1.6057, 6, 4000),
(0, 52059, 0, 52061, -11505.6, -1607.56, 44.4849, 2.26893, 6, 4000);

DELETE FROM `creature` WHERE `guid` IN (262602, 271426, 271427, 276829, 289056, 295339, 295353, 318887, 318907, 319126, 319682, 334853, 334863, 334932, 334957, 335469);
DELETE FROM `creature_addon` WHERE `guid` IN (262602, 271426, 271427, 276829, 289056, 295339, 295353, 318887, 318907, 319126, 319682, 334853, 334863, 334932, 334957, 335469);

-- Loot
-- Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id`= 52059;
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(52059, 395, 7000);

DELETE FROM `creature_loot_template` WHERE `Entry`= 52059;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
(52059, 520590, 100, 1, 520590, 1);

DELETE FROM `reference_loot_template` WHERE `Entry`= 520590;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(520590, 69614, 0, 1, 1, 1, 1),
(520590, 69612, 0, 1, 1, 1, 1),
(520590, 69611, 0, 1, 1, 1, 1),
(520590, 69613, 0, 1, 1, 1, 1),
(520590, 69610, 0, 1, 1, 1, 1);
