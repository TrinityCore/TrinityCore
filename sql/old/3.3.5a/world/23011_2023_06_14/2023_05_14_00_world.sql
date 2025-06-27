-- Westwind Refugee Camp

-- Fix an issue when NPC were despawning when in combat with hostile player (tested, this won't affect any quest involved)
UPDATE `smart_scripts` SET `event_param1` =8 WHERE `entryorguid` IN (26184, 26179) AND `source_type` =0 AND `id` =8;

-- Add sniffed sleep aura
UPDATE `creature_addon` SET `auras` =16093 WHERE `guid` IN (102139, 102504, 102141, 102501, 102140, 102507, 102137);

-- Remove fishing pole/s (from the wrong specific ones)
UPDATE `creature` SET `equipment_id` =0 WHERE `guid` IN (102126, 102131, 102132, 102137, 102138, 102139, 102140, 102141, 102142, 102143, 102145, 102146, 102147, 102148, 102149, 102150, 102492, 102493, 102495, 102496, 102498, 102501, 102503, 102504, 102505, 102506, 102507, 102508, 102509, 102510, 102512, 102513, 102514);
