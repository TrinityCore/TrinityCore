
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_siamat_lightning_charge';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93959, 'spell_siamat_lightning_charge');

DELETE FROM `spell_dbc` WHERE `Id`= 93957;
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx3`, `AttributesEx6`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `Comment`) VALUES
(93957, 0x100, 0x10000000, 0x00100000, 0x00000400, 1, 36, 1, 1, '(Serverside/Non-DB2) Lightning Charge');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160111;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectAura`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `SpellID`, `EffectIndex`, `Comment`) VALUES
(160111, 6, 4, 1, 0, 93957, 0, '(Serverside/Non-DB2) Lightning Charge');
