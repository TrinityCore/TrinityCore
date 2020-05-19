-- Template Updates
-- Ammunae
UPDATE `creature_template` SET `ScriptName`= 'boss_ammunae' WHERE `entry`= 39731;
UPDATE `creature_template` SET `DamageModifier`= 90, `flags_extra`= 1 WHERE `entry`= 48715;
-- Seedling Pod
UPDATE `creature_template` SET `unit_flags`= 64, `unit_flags2`= 33556480, `RegenHealth`= 0, `mechanic_immune_mask`= 650854271, `flags_extra`= 256 | 1073741824, `ScriptName`= 'npc_ammunae_seedling_pod' WHERE `entry` IN (40550, 51329);
-- Seedling Pod (Visual)
UPDATE `creature_template` SET `unit_flags2`= 2048, `unit_flags`= 33554496, `AIName`= 'NullCreatureAI' WHERE `entry`= 40592;
-- Bloodpetal Blossom
UPDATE `creature_template` SET `ScriptName`= 'npc_ammunae_bloodpetal_blossom' WHERE `entry`= 40620;
UPDATE `creature_template` SET `unit_flags2`= 2048, `unit_flags`= 33816576 WHERE `entry` IN (40620, 48716);
-- Bloodpetal Sprout
UPDATE `creature_template` SET `ScriptName`= 'npc_ammunae_bloodpetal_sprout' WHERE `entry`= 40630;
UPDATE `creature_template` SET `unit_flags2`= 2048, `unit_flags`= 33816576 WHERE `entry` IN (40630, 48717);
-- Bloodpetal Blossom (Visual)
UPDATE `creature_template` SET `unit_flags2`= 2048, `unit_flags`= 33554432, `AIName`= 'NullCreatureAI' WHERE `entry`= 40622;
-- Spore
UPDATE `creature_template` SET `speed_run`= 0.71428, `ScriptName` = 'npc_ammunae_spore' WHERE `entry`= 40585;

-- Addons
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`= 39731;

-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_gen_zero_energy_zero_regen',
'spell_ammunae_consume_life_energy',
'spell_ammunae_summon_bloodpetal_blossom',
'spell_ammunae_rampant_growth',
'spell_ammunae_fixate');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(72242, 'spell_gen_zero_energy_zero_regen'),
(75725, 'spell_ammunae_consume_life_energy'),
(75774, 'spell_ammunae_summon_bloodpetal_blossom'),
(75790, 'spell_ammunae_rampant_growth'),
(89888, 'spell_ammunae_rampant_growth'),
(73686, 'spell_ammunae_fixate');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (75657, 94970, 89124, 75774, 75790, 89888, 75702, 89889) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 3, 75657, 0, 0, 31, 0, 3, 39731, 0, 0, 0, '', 'Energize - Target Ammunae'),
(13, 3, 94970, 0, 0, 31, 0, 3, 39731, 0, 0, 0, '', 'Energize - Target Ammunae'),
(13, 1, 89124 , 0, 0, 31, 0, 3, 39731, 0, 0, 0, '', 'Energizing Growth - Target Ammunae'),
(13, 1, 75774 , 0, 0, 31, 0, 3, 40550, 0, 0, 0, '', 'Bloodpetal Blossom - Target Seedling Pod'),
(13, 1, 75774 , 0, 1, 31, 0, 3, 51329, 0, 0, 0, '', 'Bloodpetal Blossom - Target Seedling Pod'),
(13, 1, 75790 , 0, 0, 31, 0, 3, 40550, 0, 0, 0, '', 'Rampant Growth - Target Seedling Pod'),
(13, 1, 75790 , 0, 1, 31, 0, 3, 51329, 0, 0, 0, '', 'Rampant Growth - Target Seedling Pod'),
(13, 1, 89888 , 0, 0, 31, 0, 3, 40550, 0, 0, 0, '', 'Rampant Growth - Target Seedling Pod'),
(13, 1, 89888 , 0, 1, 31, 0, 3, 51329, 0, 0, 0, '', 'Rampant Growth - Target Seedling Pod'),
(13, 6, 75702 , 0, 0, 31, 0, 3, 40620, 0, 0, 0, '', 'Noxious Spores - Target Bloodpetal Blossom'),
(13, 6, 75702 , 0, 1, 31, 0, 3, 40630, 0, 0, 0, '', 'Noxious Spores - Target Bloodpetal Sprout'),
(13, 6, 89889 , 0, 0, 31, 0, 3, 40620, 0, 0, 0, '', 'Noxious Spores - Target Bloodpetal Blossom'),
(13, 6, 89889 , 0, 1, 31, 0, 3, 40630, 0, 0, 0, '', 'Noxious Spores - Target Bloodpetal Sprout');


-- Serverside Spells
DELETE FROM `spell_dbc` WHERE `Id` IN (75621, 94991, 75688, 75771, 75791, 75769, 75695);
INSERT INTO `spell_dbc` (`Id`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `AttributesEx`, `Comment`) VALUES
(75621, 1, 21, 1, 0x100, '(Serverside/Non-DB2) Summon Seedling Pod'),
(94991, 1, 21, 1, 0x100, '(Serverside/Non-DB2) Summon Seedling Pod'),
(75688, 1, 21, 1, 0x100, '(Serverside/Non-DB2) Summon Seedling Pod'),
(75771, 1, 21, 1, 0x100, '(Serverside/Non-DB2) Bloodpetal Blossom'),
(75791, 1, 21, 1, 0x100, '(Serverside/Non-DB2) Summon Bloodpetal Sprout'),
(75769, 1, 21, 1, 0x100, '(Serverside/Non-DB2) Summon Bloodpetal Blossom Visual'),
(75695, 1, 21, 1, 0x100, '(Serverside/Non-DB2) Summon Spore');

DELETE FROM `spelleffect_dbc` WHERE `Id` IN (160099, 160100, 160101, 160102, 160103, 160104, 160105);
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusMaxIndex`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `SpellID`, `EffectIndex`, `Comment`) VALUES
(160099, 28, 40592, 64, 0, 0, 18, 0, 75688, 0, ''),
(160100, 28, 40550, 64, 23, 23, 18, 86, 75621, 0, ''),
(160101, 28, 51329, 64, 23, 23, 18, 86, 94991, 0, ''),
(160102, 28, 40620, 64, 0, 0, 18, 0, 75771, 0, ''),
(160103, 28, 40630, 64, 0, 0, 18, 0, 75791, 0, ''),
(160104, 28, 40622, 64, 0, 0, 18, 0, 75769, 0, ''),
(160105, 28, 40585, 64, 0, 0, 18, 0, 75695, 0, '');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 39731;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(39731, 0, 0, 'This chamber will flourish with your life energy!', 14, 0, 100, 0, 0, 18571, 44767, 'Ammunae - Aggro'),
(39731, 1, 0, 'Your life, UNLEASHED!', 14, 0, 100, 0, 0, 18572, 44771, 'Ammunae - Rampant Growth'),
(39731, 2, 0, 'The cycle continues...', 14, 0, 100, 0, 0, 18569, 44770, 'Ammunae - Death'),
(39731, 3, 0, 'Wither away!', 14, 0, 100, 0, 0, 18573, 44768, 'Ammunae - Slay 1'),
(39731, 3, 1, 'Waste of energy.', 14, 0, 100, 0, 0, 18574, 44769, 'Ammunae - Slay 2');
