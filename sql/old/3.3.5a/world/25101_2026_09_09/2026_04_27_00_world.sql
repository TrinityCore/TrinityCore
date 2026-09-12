DELETE FROM `spell_dbc` WHERE `Id` IN (34147,34148,58892,58899);
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `CastingTimeIndex`, `ProcChance`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Effect1`, `EffectDieSides1`, `EffectImplicitTargetA1`, `EffectRadiusIndex1`, `EffectMiscValue1`, `SpellName`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `SchoolMask`) VALUES
(34147, 256, 268435456, 16, 101, 60, 60, 25, 7, 50, 1, 47, 8, 183510, 'Create Soulwell R1 (Improved Healthstone R1)', 1, 1, 1, 1),
(34148, 256, 268435456, 16, 101, 60, 60, 25, 7, 50, 1, 47, 8, 183511, 'Create Soulwell R1 (Improved Healthstone R2)', 1, 1, 1, 1),
(58892, 256, 268435456, 16, 101, 60, 60, 25, 7, 50, 1, 47, 8, 193170, 'Create Soulwell R2 (Improved Healthstone R1)', 1, 1, 1, 1),
(58899, 256, 268435456, 16, 101, 60, 60, 25, 7, 50, 1, 47, 8, 193171, 'Create Soulwell R2 (Improved Healthstone R2)', 1, 1, 1, 1);

UPDATE `spell_dbc` SET `Effect1`=77 WHERE `Id` IN (34145,58888);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warl_ritual_of_souls_r1','spell_warl_ritual_of_souls_r2');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(34145,'spell_warl_ritual_of_souls_r1'),
(58888,'spell_warl_ritual_of_souls_r2');

UPDATE `gameobject_template` SET `ScriptName`='' WHERE `entry` IN (181621,183510,183511,193169,193170,193171);
