UPDATE `spell_proc` SET `HitMask`= 64 | 2048, `ProcFlags`= 0x000002A8 | 0x00020000 WHERE `SpellId`= -12298;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_warr_shield_specialization';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-12298, 'spell_warr_shield_specialization');
