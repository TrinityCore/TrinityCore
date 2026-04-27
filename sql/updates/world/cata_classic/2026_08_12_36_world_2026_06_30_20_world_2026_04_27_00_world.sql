DELETE FROM `serverside_spell` WHERE `Id` IN (34147,34148,58892,58899);
INSERT INTO `serverside_spell` (`Id`, `Attributes`, `AttributesEx`, `CastingTimeIndex`, `ProcChance`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `SpellName`, `SchoolMask`) VALUES
(34147, 256, 268435456, 16, 101, 60, 60, 25, 7, 'Create Soulwell R1 (Improved Healthstone R1)', 1),
(34148, 256, 268435456, 16, 101, 60, 60, 25, 7, 'Create Soulwell R1 (Improved Healthstone R2)', 1),
(58892, 256, 268435456, 16, 101, 60, 60, 25, 7, 'Create Soulwell R2 (Improved Healthstone R1)', 1),
(58899, 256, 268435456, 16, 101, 60, 60, 25, 7, 'Create Soulwell R2 (Improved Healthstone R2)', 1);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (34147,34148,58892,58899);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `Effect`, `ImplicitTarget1`, `EffectRadiusIndex1`, `EffectMiscValue1`) VALUES
(34147, 0, 50, 47, 8, 183510),
(34148, 0, 50, 47, 8, 183511),
(58892, 0, 50, 47, 8, 193170),
(58899, 0, 50, 47, 8, 193171);

UPDATE `serverside_spell_effect` SET `Effect`=77 WHERE `SpellID` IN (34145,58888) AND `EffectIndex`=0;

UPDATE `gameobject_template` SET `ScriptName`='' WHERE `entry` IN (181621,183510,183511,193169,193170,193171);
