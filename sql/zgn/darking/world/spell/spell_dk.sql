-- 89832 Death Strike Enabler
DELETE FROM `serverside_spell` WHERE `Id` = 89832 AND `DifficultyID` = 0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `SpellName`, `Attributes`, `CastingTimeIndex`, `ProcFlags`, `ProcChance`, `DurationIndex`, `RangeIndex`, `SchoolMask`) VALUES
(89832, 0, 'Death Strike Enabler', 0x1d0, 1 /* CastingTimeIndex: 0/0/0 */, 0xAAAA8 /*ProcFlags: Damage Taken */, 100 /*Proc Chance*/, 21 /*Duration: -1/0/-1 */, 1 /*Range: Self Only*/, 0x1 /* Physical */);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 89832 AND `DifficultyID` = 0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAuraPeriod`, `EffectChainAmplitude`, `ImplicitTarget1`) VALUES
(89832, 0, 0, 6 /* APPLY_AURA */, 226 /* PERIODIC_DUMMY */, 1000, 1, 1 /* Target: Caster */);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dk_death_strike_enabler');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(89832, 'spell_dk_death_strike_enabler');

-- Link spells Death Knight (137005)
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 137005 AND `spell_effect` = 89832 AND `type` = 2;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(137005, 89832, 2, 'On Death Knight (passive) trigger Death Strike Enabler (Passive)');