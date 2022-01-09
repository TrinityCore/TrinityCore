DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_enable_worgen_altered_form';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(94293, 'spell_gen_enable_worgen_altered_form');

DELETE FROM `spell_dbc` WHERE `Id`= 97681;
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellName`) VALUES
(97681, 0x000000C0, 1, 0, 1, 1, '(Serverside/Non-DB2) Altered Form');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160112;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectAura`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectTriggerSpell`, `SpellID`, `EffectIndex`, `Comment`) VALUES
(160112, 6, 42, 1, 0, 97709, 97681, 0, '(Serverside/Non-DB2) Altered Form');

DELETE FROM `spell_proc` WHERE `SpellId`= 97681;
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `Chance`) VALUES
(97681, 0x8000000, 100);
