DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_hun_master_marksman',
'spell_hun_bombardment');

UPDATE `spell_proc` SET `SpellFamilyMask0`= 0x20000 WHERE `SpellId`= 82926;
UPDATE `spell_proc` SET `SpellFamilyMask1`= 0x1 WHERE `SpellId`= -34485;
UPDATE `spell_proc` SET `SpellFamilyMask0`= 0x1000 WHERE `SpellId`= -35104;
UPDATE `spell_proc` SET `SpellFamilyMask0`= 0x8 | 0x10, `SpellFamilyMask1`= 0, `SpellFamilyMask2`= 0, `SpellPhaseMask`= 4 | 1, `SpellTypeMask`= 4, `Cooldown`= 10000 WHERE `SpellId`= -56342;
UPDATE `spell_proc` SET `SpellFamilyMask0`= 0x20000, `SpellFamilyMask1`= 0x1, `SpellFamilyMask2`= 0x1 WHERE `SpellId`= -53234;
