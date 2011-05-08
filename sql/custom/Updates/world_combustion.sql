DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = '-11129';
INSERT INTO `spell_linked_spell` VALUES ('-11129', '-28682', '0', 'Combustion');

UPDATE `spell_proc_event` SET `SpellFamilyMask1` = `SpellFamilyMask1` &~ 0x8 WHERE `entry` = '11129';
