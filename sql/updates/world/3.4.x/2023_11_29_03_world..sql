DELETE FROM `creature` WHERE `map` IN (566, 643, 644, 645, 646, 648, 654, 657, 671, 720, 725, 726, 730, 732, 754, 755, 757, 860, 861, 870, 939, 940, 967, 974, 1004, 1007, 1064, 1116, 1220, 1464, 1481, 1544, 1642, 1643, 2106, 2107, 2175, 2444);
DELETE FROM `creature_addon` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `creature_movement_override` WHERE `SpawnId` NOT IN (SELECT `guid` FROM `creature`);

DELETE FROM `gameobject` WHERE `map` IN (566, 643, 644, 645, 646, 648, 654, 657, 671, 720, 725, 726, 730, 732, 754, 755, 757, 860, 861, 870, 939, 940, 967, 974, 1004, 1007, 1064, 1116, 1220, 1464, 1481, 1544, 1642, 1643, 2106, 2107, 2175, 2444);
DELETE FROM `gameobject_addon` WHERE `guid` NOT IN (SELECT `guid` FROM `gameobject`);

DELETE FROM `spawn_group` WHERE `spawnType`= 0 AND `spawnId` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `spawn_group` WHERE `spawnType`= 1 AND `spawnId` NOT IN (SELECT `guid` FROM `gameobject`);

DELETE FROM `battle_pet_breeds`;
DELETE FROM `battle_pet_quality`;
DELETE FROM `scene_template`;
DELETE FROM `scenarios`;
DELETE FROM `terrain_worldmap`;
DELETE FROM `terrain_swap_defaults`;
DELETE FROM `race_unlock_requirement` WHERE `raceID` IN (9, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 34, 35, 36, 37, 52, 70);
DELETE FROM `class_expansion_requirement` WHERE `RaceID` IN (9, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 34, 35, 36, 37, 52, 70) OR ActiveExpansionLevel > 2;
