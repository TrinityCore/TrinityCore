DELETE FROM `spell_proc` WHERE `SpellID`= -53234;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(-53234, 9, 0, 0, 1, 2, 2);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_hun_piercing_shots';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-53234, 'spell_hun_piercing_shots');

DELETE FROM `spell_proc` WHERE `SpellID` IN (-34485, 82926);
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(-34485, 9, 0, 0, 1, 1, 0),
(82926, 9, 0, 0, 1, 1, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_hun_master_marksman';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-34485, 'spell_hun_master_marksman');

DELETE FROM `spell_proc` WHERE `SpellID`= -35104;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(-35104, 9, 0, 0, 1, 2, 2);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_hun_bombardment';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-35104, 'spell_hun_bombardment');
