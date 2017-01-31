DELETE FROM `spell_custom_attr` WHERE `entry` IN (1130,1725,3600,32375,32592,35009,39897,43263,58838);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(1130, 64), -- Hunter spell 1130, Hunter's Mark Rank 1
(1725, 64),  -- Rogue spell 1725, Distract
(3600, 64),  -- Greater Earthbind Totem spell 3600, Earthbind
(32375, 64), -- Priest Discipline spell 32375, Mass Dispel
(32592, 64), -- Priest Discipline spell 32592, Mass Dispel
-- Spell ID 35009 - Server-side - Invisibility - Reducing threat
(35009, 64), -- Triggered by Mage Invisibility (Level 68), spells 66 & 67765
(39897, 64), -- Priest Discipline spell 39897, Mass Dispel
(43263, 64), -- Ghoul level 66 spell 43263, Ghoul Taunt
(58838, 64); -- Inherit Master's Threat List
