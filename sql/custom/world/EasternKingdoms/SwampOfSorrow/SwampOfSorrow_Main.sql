-- Fixes for Swamp Of Sorrow

-- NPC: 986 Haromm
-- NPC: 51983 Deadwind Widow
-- NPC: 46487 Marshtide Peasant

-- Difficulty fixes
-- Missing Content Tuning
UPDATE creature_template_difficulty SET ContentTuningID = 31 WHERE Entry = 986 AND DifficultyID = 0;

-- Template Addons
UPDATE creature_template_addon SET emote = 1008 WHERE Entry = 46487;

-- Wrong spawns
DELETE FROM creature WHERE id = 51983 AND guid = 293089;
DELETE FROM creature WHERE id = 51983 AND guid = 293088;

-- Creature Spawn fixes
UPDATE creature
SET MovementType = 1,
    wander_distance = 8
WHERE id IN (
    46950,858,48249,759,761,
    858,1088,45967,45701,922,45809
);
