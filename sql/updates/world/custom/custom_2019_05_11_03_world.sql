DELETE FROM `spell_proc` WHERE `SpellId` IN (-34293);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Chance`, `Cooldown`) VALUES
(-34293, 4, 3, 0, 0, 0x00000008, 0x00010000, 5, 2, 0, 2, 100, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_mage_pyromaniac';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-34293, 'spell_mage_pyromaniac');
