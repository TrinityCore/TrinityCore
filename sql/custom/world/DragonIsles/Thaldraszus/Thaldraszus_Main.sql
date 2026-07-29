-- Thaldraszus Fixes

-- NPC: 196498 Skittering Boneborer

-- Incorrect factions
UPDATE creature_template SET faction = 14 WHERE entry = 196498;
