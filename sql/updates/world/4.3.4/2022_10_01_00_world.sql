DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dru_natures_bounty';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-17074, 'spell_dru_natures_bounty');

DELETE FROM `spell_proc` WHERE `SpellId`= -17074;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `Chance`) VALUES
(-17074, 7, 0x10, 0x4000, 0x4, 0x2, 100);
