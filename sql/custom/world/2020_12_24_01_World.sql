-- fix argus spawndifficulties

UPDATE `creature` SET `spawndifficulties` = 0 WHERE `map` = 1669;
UPDATE `gameobject` SET `spawndifficulties` = 0 WHERE `map` = 1669;