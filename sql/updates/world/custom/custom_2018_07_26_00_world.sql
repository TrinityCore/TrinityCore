-- Template Updates
-- Bound Flames
UPDATE `creature_template` SET `DamageModifier`= 15, `BaseVariance`= 0.5 WHERE `entry`= 50417;

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_karsh_quicksilver_armor',
'spell_karsh_superheated_quicksilver_armor',
'spell_karsh_superheated_quicksilver_armor_proc');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75854, 'spell_karsh_quicksilver_armor'),
(75846, 'spell_karsh_superheated_quicksilver_armor'),
(93567, 'spell_karsh_superheated_quicksilver_armor'),
(76015, 'spell_karsh_superheated_quicksilver_armor_proc');

-- Serverside spells
DELETE FROM `spell_dbc` WHERE `Id`= 88538;
INSERT INTO `spell_dbc`(`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellInterruptsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `Comment`) VALUES
(88538, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Forcecast Lava Spout');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160091;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectBasePoints`, `EffectTriggerSpell`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`, `Comment`) VALUES
(160091, 140, 0, 76007, 0, 0, 12, 12, 22, 7, 88538, 0, 'Forcecast Lava Spout');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (88538, 93499) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 88538, 0, 0, 31, 0, 3, 39842, 0, 0, 0, '', 'Forcecast Lava Spout - Target Invisible Stalker'),
(13, 1, 93499, 0, 0, 31, 0, 3, 39842, 0, 0, 0, '', 'Bound Flames- Target Invisible Stalker');

-- Achievement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15947;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15947, 11, 0, 0, 'achievement_too_hot_to_handle');
