-- Q29400 spawn quest giver
DELETE FROM game_event_creature WHERE eventEntry = 12 AND guid in (select guid from creature where id in (19169, 19175, 19176, 19177, 19178, 20102));
INSERT INTO game_event_creature SELECT 12, guid FROM creature WHERE id in (19169, 19175, 19176, 19177, 19178, 20102);

-- Q29400
DELETE FROM game_event_creature WHERE eventEntry = 12 AND guid in (select guid from creature where id in (18927, 19148, 19171, 19172, 19173, 20102));
INSERT INTO game_event_creature SELECT 12, guid FROM creature WHERE id in (18927, 19148, 19171, 19172, 19173, 20102);