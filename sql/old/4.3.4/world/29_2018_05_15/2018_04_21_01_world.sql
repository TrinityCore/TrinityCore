-- 
UPDATE `gameobject` SET `spawnMask`=15  WHERE `map` IN (669,967) AND `id` NOT IN (207342, 209062, 207340,209060, 209061, 207341, 209063, 207339);
UPDATE `creature` SET `spawnMask`=15  WHERE `map` IN (669,967);
