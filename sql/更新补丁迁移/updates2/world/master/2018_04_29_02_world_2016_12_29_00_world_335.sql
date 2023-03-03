DELETE FROM `spell_custom_attr` WHERE `entry` IN (57723, 57724);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(57723, 0x40), -- Exhaustion
(57724, 0x40); -- Sated
