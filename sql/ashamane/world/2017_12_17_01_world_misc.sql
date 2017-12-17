UPDATE creature SET PhaseId = 50 WHERE id = 52173;

UPDATE creature_template SET faction = 2111 WHERE entry IN (95013,
96124,
94687);
DELETE FROM creature WHERE guid IN (20509615, 20545508);

DELETE FROM gameobject WHERE id IN (176213);
