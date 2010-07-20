DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (54861,55004)AND `spell_effect` IN (-23335,-23333);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(54861,-23335,0, 'Drop Flag on Nitro Boost WSG'),
(54861,-23333,0, 'Drop Flag on Nitro Boost WSG'),
(55004,-23335,0, 'Drop Flag on Nitro Boost WSG'),
(55004,-23333,0, 'Drop Flag on Nitro Boost WSG');
