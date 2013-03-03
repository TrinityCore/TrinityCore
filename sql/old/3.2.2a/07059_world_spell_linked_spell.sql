-- add spell trigger for teleport to acherus (quest 12757)
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=53099;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(53099,53098,0, 'trigger teleport to acherus (for quest 12757)');
