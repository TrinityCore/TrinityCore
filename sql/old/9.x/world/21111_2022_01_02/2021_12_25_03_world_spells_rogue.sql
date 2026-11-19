-- Spell Proc
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_rog_backstab',
'spell_rog_grand_melee',
'spell_rog_mastery_main_gauche',
'spell_rog_roll_the_bones',
'spell_rog_ruthlessness',
'spell_rog_sinister_strike',
'spell_rog_restless_blades',
'spell_rog_venomous_wounds',
'spell_rog_symbols_of_death',
'spell_rog_shadowstrike');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(53, 'spell_rog_backstab'),
(193358, 'spell_rog_grand_melee'),
(76806, 'spell_rog_mastery_main_gauche'),
(315508, 'spell_rog_roll_the_bones'),
(14161, 'spell_rog_ruthlessness'),
(193315, 'spell_rog_sinister_strike'),
(79096, 'spell_rog_restless_blades'),
(79134, 'spell_rog_venomous_wounds'),
(212283, 'spell_rog_symbols_of_death'),
(185438, 'spell_rog_shadowstrike');

-- Spell Procs
DELETE FROM `spell_proc` WHERE `SpellId` IN (79134,227151);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(79134, 0, 8, 0x100100, 0x0, 0x0, 0x0, 0, 1, 2, 0x403, 0x0, 0, 0, 0, 0, 0), -- Venomous Wounds
(227151, 0, 8, 0x0, 0x0, 0x0, 0x0, 0, 7, 2, 0x403, 0x8, 0, 0, 0, 0, 0); -- Symbols of Death (Crit Aura)
