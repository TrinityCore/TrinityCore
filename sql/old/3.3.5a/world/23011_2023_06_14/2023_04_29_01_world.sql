-- 
DELETE FROM `spell_area` WHERE `spell` = 57940 AND `area` IN (495,4277);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(57940, 495, 0, 0, 0, 0, 2, 1, 0, 0),  -- Howling Fjord
(57940, 4277, 0, 0, 0, 0, 2, 1, 0, 0); -- Azjol-Nerub (Dungeon)

-- Remove Essence of Wintergrasp in Instances (must be obtained only in only Northrend map and Dungeons)
DELETE FROM `spell_area` WHERE `spell` = 57940 AND `area` IN (
3456, -- Naxxramas
4493, -- The Obsidian Sanctum
4603, -- Vault of Archavon
4273  -- Ulduar
);
