UPDATE creature SET MovementType = 0, spawndist = 0 WHERE id  IN (7939, 39314, 40360, 40362);
UPDATE creature_template SET MovementType = 0 WHERE entry IN (7939, 39314, 40360, 40362);
DELETE FROM creature WHERE guid IN (257434, 371329);
DELETE FROM gameobject WHERE guid = 88836;
DELETE FROM creature WHERE id = 1794;
