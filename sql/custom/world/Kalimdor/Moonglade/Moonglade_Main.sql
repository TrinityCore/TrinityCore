-- Moonglade Fixes

-- NPC: 122580 Jadefire Illusionist
-- NPC: 122597 Jadefire Shadowmaster
-- NPC: 122609 Xavinox

-- Creature Difficulty
UPDATE creature_template_difficulty SET ContentTuningID = 2151 WHERE Entry IN (122580,122597,122609);
