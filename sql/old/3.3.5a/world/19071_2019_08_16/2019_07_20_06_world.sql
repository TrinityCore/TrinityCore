--
DELETE FROM `spell_custom_attr` WHERE `entry` IN (19659, 24690, 51121, 59376);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(19659, 4096),
(24690, 4096|8192|16384),
(51121, 4096|8192),
(59376, 4096|8192);
