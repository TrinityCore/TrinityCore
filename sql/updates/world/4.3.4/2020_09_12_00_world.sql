DELETE FROM `spell_script_names` WHERE `spell_id`= 77928;
UPDATE `spell_proc` SET `ProcFlags`= 0, `SpellTypeMask`= 1 WHERE `SpellId` IN (77786, 92971, 92972, 92973);
