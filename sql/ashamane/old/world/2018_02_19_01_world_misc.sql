UPDATE `creature_template` SET `InhabitType` = 4 WHERE (entry = 44475);
-- Correction Conflit Guid Game_event (mob invisible)
DELETE FROM game_event_creature WHERE guid IN (SELECT guid FROM creature WHERE id = 2556);
