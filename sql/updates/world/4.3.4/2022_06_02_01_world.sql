DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_dru_t12_restoration_4p_bonus',
'spell_dru_firebloom');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(99015, 'spell_dru_t12_restoration_4p_bonus'),
(99017, 'spell_dru_firebloom');

DELETE FROM `spell_proc` WHERE `SpellId`= 99015;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask1`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(99015, 7, 0x2, 2, 2);
