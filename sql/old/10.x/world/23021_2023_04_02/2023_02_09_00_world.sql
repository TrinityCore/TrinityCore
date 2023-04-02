-- (Swift Spectral Drake)
DELETE FROM `spell_area` WHERE `spell` = 372995 AND `area` IN (13644, 13645, 13646, 13647) AND `racemask` = 0xFFA1FFF7;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(372995, 13644, 0, 0, 8326, 0xFFA1FFF7, 2, 3, 64, 11), -- Waking Shores
(372995, 13645, 0, 0, 8326, 0xFFA1FFF7, 2, 3, 64, 11), -- Ohn'ahran Plains
(372995, 13646, 0, 0, 8326, 0xFFA1FFF7, 2, 3, 64, 11), -- Azure Span
(372995, 13647, 0, 0, 8326, 0xFFA1FFF7, 2, 3, 64, 11); -- Thaldraszus

-- Nightelf (Swift Flying Wisp)
DELETE FROM `spell_area` WHERE `spell` = 55173 AND `area` IN (13644, 13645, 13646, 13647) AND `racemask` = 8;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(55173, 13644, 0, 0, 8326, 8, 2, 3, 64, 11), -- Waking Shores
(55173, 13645, 0, 0, 8326, 8, 2, 3, 64, 11), -- Ohn'ahran Plains
(55173, 13646, 0, 0, 8326, 8, 2, 3, 64, 11), -- Azure Span
(55173, 13647, 0, 0, 8326, 8, 2, 3, 64, 11); -- Thaldraszus
