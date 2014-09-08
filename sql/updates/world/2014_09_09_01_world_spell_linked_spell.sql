DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (853, 5588, 5589, 10308, 22570, 49802, 5211, 6798, 8983) AND `spell_effect` = 32747;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(853, 32747, 0, 'Hammer of Justice - Interrupt - Rank 1 '),
(5588, 32747, 0, 'Hammer of Justice - Interrupt - Rank 2'),
(5589, 32747, 0, 'Hammer of Justice - Interrupt - Rank 3'),
(10308, 32747, 0, 'Hammer of Justice - Interrupt - Rank 4'),
(22570, 32747, 0, 'Maim - Interrupt - Rank 1'),
(49802, 32747, 0, 'Maim - Interrupt - Rank 2'),
(5211, 32747, 0, 'Bash - Interrupt - Rank 1'),
(6798, 32747, 0, 'Bash - Interrupt - Rank 2'),
(8983, 32747, 0, 'Bash - Interrupt - Rank 3');