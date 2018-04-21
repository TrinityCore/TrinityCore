DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (57294,57399);
INSERT INTO `spell_linked_spell` VALUES
(57294,59690,2,'Well Fed - Well Fed (DND)'),
(57399,59699,2,'Well Fed - Well Fed (DND)');

DELETE FROM `spell_group` WHERE `spell_id` IN (59690,59699);
