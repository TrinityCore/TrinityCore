-- Halls of Origination - Creatures spawned in heroic and normal version
UPDATE `creature` SET `spawnMask`=3 WHERE `map`=644;
UPDATE `gameobject` SET `spawnMask`=3 WHERE `map`=644;


-- Firelands - Creatures spawned on all versions
UPDATE `creature` SET `spawnMask`=15 WHERE `map`=720;
UPDATE `gameobject` SET `spawnMask`=15 WHERE `map`=720;
