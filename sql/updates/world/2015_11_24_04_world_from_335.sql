--
DELETE FROM `spell_custom_attr` WHERE `entry` IN (1130,1725,3600,14323,14324,14325,32375,32592,35009,39897,42650,43263,43264,53338,58831,58832,58833,58834,58838);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(1130, 64), -- Hunter spell 1130, Hunter's Mark Rank 1
(1725, 64),  -- Rogue spell 1725, Distract
(3600, 64),  -- Greater Earthbind Totem spell 3600, Earthbind
(14323, 64), -- Hunter spell 14323, Hunter's Mark Rank 2
(14324, 64), -- Hunter spell 14324, Hunter's Mark Rank 3
(14325, 64), -- Hunter spell 14325, Hunter's Mark Rank 4
(32375, 64), -- Priest Discipline spell 32375, Mass Dispel
(32592, 64), -- Priest Discipline spell 32592, Mass Dispel
-- Spell ID 35009 - Server-side - Invisibility - Reducing threat
(35009, 64), -- Triggered by Mage Invisibility (Level 68), spells 66 & 67765
(39897, 64), -- Priest Discipline spell 39897, Mass Dispel
(42650, 64), -- Death Knight Unholy spell 42650, Army of the Dead
(43263, 64), -- Ghoul level 66 spell 43263, Ghoul Taunt
(43264, 64), -- Periodic Taunt, Trigger for Ghoul Taunt
(53338, 64), -- Hunter spell 53338, Hunter's Mark Rank 5 
(58831, 64), -- Mirror Image, spawns left Mirror Image NPC
(58832, 64), -- Mirror Image, Triggers 58831,58833,58834
(58833, 64), -- Mirror Image, spawns center Mirror Image NPC
(58834, 64), -- Mirror Image, spawns right Mirror Image NPC
(58838, 64); -- Inherit Master's Threat List
