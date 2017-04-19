UPDATE `spell_proc` SET `AttributesMask`=(`AttributesMask` & ~0x10) WHERE `SpellId` IN (32216, 56817);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_proc_charge_drop_only';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32216, 'spell_gen_proc_charge_drop_only'),
(56817, 'spell_gen_proc_charge_drop_only');
