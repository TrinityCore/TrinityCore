-- Remove all entries which were tied to post Cata difficulties
DELETE FROM `creature_template_difficulty` WHERE `DifficultyID` NOT IN (0, 1, 2, 3, 4, 5, 6, 9, 148, 173, 174, 175, 176, 193, 194);

DELETE FROM `class_expansion_requirement` WHERE `ClassID` IN (10, 12, 13);
DELETE FROM `class_expansion_requirement` WHERE `RaceID` IN (24, 25, 26, 27, 28, 29, 30, 31, 32, 34, 35, 36, 37);
DELETE FROM `race_unlock_requirement` WHERE `RaceID` IN (24, 25, 26, 27, 28, 29, 30, 31, 32, 34, 35, 36, 37, 52, 70);

-- Note that we are aware that some spawns belong to 25m only but these spawns have been blended together in the master branch so we just convert data
-- Move black temple spawns back to difficulty 4
UPDATE `creature` SET `spawnDifficulties`= '4' WHERE `map`= 564;
UPDATE `gameobject` SET `spawnDifficulties`= '4' WHERE `map`= 564;
-- Move ulduar spawns back to difficulty 3 and 4
UPDATE `creature` SET `spawnDifficulties`= '3,4' WHERE `map`= 603;
UPDATE `gameobject` SET `spawnDifficulties`= '3,4' WHERE `map`= 603;
-- Move firelands spawns back to difficulty 3, 4, 5, 6
UPDATE `creature` SET `spawnDifficulties`= '3,4,5,6' WHERE `map`= 720;
UPDATE `gameobject` SET `spawnDifficulties`= '3,4,5,6' WHERE `map`= 720;

DELETE FROM `creature_questitem` WHERE `ItemId` IN (89052, 89053, 129912, 129913, 129915, 129916, 134806, 136616, 138951, 138952, 138953, 142345, 142349, 142352, 142353, 142354, 142355, 142385, 142386, 142387, 142388, 150774, 157030, 181354, 192493);
DELETE FROM `gameobject_questitem` WHERE `ItemId` IN (138953, 138952, 79039, 80227, 80229, 80230);
