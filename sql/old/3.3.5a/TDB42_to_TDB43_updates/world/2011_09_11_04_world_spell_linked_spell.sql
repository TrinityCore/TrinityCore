DELETE FROM `spell_linked_spell` WHERE `spell_trigger`IN (65686, 65684, 67222, 67176, 67223, 67177, 67224, 67178);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(65686, -65684, 2, 'Remove Dark Essence 10M'),
(65684, -65686, 2, 'Remove Light Essence 10M'),
(67222, -67176, 2, 'Remove Dark essence 10M H'),
(67176, -67222, 2, 'Remove Light essence 10M H'),
(67223, -67177, 2, 'Remove Dark essence 25M'),
(67177, -67223, 2, 'Remove Light essence 25M'),
(67224, -67178, 2, 'Remove Dark essence 25M H'),
(67178, -67224, 2, 'Remove Light essence 25M H');
