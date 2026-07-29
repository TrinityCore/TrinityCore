-- Uldum Fixes

-- NPC: 50063 Akma'hat <Dirge of the Eternal Sands> - phase 367
-- NPC: 51402 Madexx - phase 0 (green)
-- NPC: 51404 Madexx - phase 0 (blue)
-- NPC: 51403 Madexx - phase 367 (red)
-- NPC: 50154 Madexx - phase 0 (black)
-- NPC: 162370 Armagedillo - phase 0
-- NPC: 50064 Cyrus the Black - phase 367
-- NPC: 48548 Immortal Colossus

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE Entry IN (48548) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (48548) AND `DifficultyID` = 1;

UPDATE creature_template_difficulty SET ContentTuningID = 55 WHERE Entry IN (50063,51404,51403,51402,50154,162370,50064);
