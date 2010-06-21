DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (54861,55004)AND `spell_effect` IN (-34976);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
( 54861,-34976, 0, 'Drop Flag on Nitro Boost EOS'),
( 55004,-34976, 0, 'Drop Flag on Nitro Boost EOS');
