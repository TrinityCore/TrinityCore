DELETE FROM `spell_proc` WHERE `SpellId`= -85099;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `Chance`) VALUES
(-85099, 5, 0x4000, 0x40000, 0x1, 0x2, 100);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_warl_pandemic',
'spell_warl_pandemic_script');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-85099, 'spell_warl_pandemic'),
(92931 , 'spell_warl_pandemic_script');
