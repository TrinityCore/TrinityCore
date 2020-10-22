-- Eclipse rework
UPDATE `spell_proc` SET `SpellFamilyName`= 7, `SpellFamilyMask0`= 0x1 | 0x2 | 0x4, `SpellFamilyMask2`= 0x2000000, `ProcFlags`= 0, `SpellTypeMask`= 1, `SpellPhaseMask`= 1 WHERE `SpellId`= 79577;
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dru_eclipse_energize';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dru_eclipse' AND `spell_id`= 48518;
