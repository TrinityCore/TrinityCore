DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_warr_heroic_fury';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(60970, 'spell_warr_heroic_fury');

UPDATE `spell_proc` SET `SpellFamilyMask0`= 0x8 WHERE `SpellId`= -12311;
