DELETE FROM `spell_proc` WHERE `SpellId`= 84617;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(84617, 0, 0, 0, 0, 0, 1, 4, 0, 64, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_rog_envenom';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32645, 'spell_rog_envenom');
