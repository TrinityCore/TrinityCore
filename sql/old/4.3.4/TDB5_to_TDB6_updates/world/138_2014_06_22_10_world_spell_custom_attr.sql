-- Fixes these two spells avoiding crit reduction
DELETE FROM `spell_custom_attr` WHERE `entry` IN (7268, 47666);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES 
(7268, 4096), -- Arcane Missiles
(47666, 4096); -- penance damage
