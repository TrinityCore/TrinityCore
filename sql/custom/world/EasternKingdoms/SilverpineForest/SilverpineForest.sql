-- Silverpine Forest Fixes

-- NPC: 45711 Elemental Servitor
-- NPC: 199902 Scarlet Champion

-- Difficulty Fixes
UPDATE creature_template_difficulty SET ContentTuningID = 7 WHERE Entry IN (199902,204183,199888);

-- Template Fixes
UPDATE creature_template SET faction = 14 WHERE entry IN (199902,204183,199888);

-- Creature Random Movement
UPDATE creature
SET MovementType = 1,
    wander_distance = 8
WHERE id IN (
    45750,
    45711,
    199902,
    199890,
    199888,
    45254,
    44367,
    44549
);
