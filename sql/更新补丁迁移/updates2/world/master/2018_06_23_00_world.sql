--
UPDATE `creature` SET `spawnMask` = (1 << 14) | (1 << 33) WHERE `map` = 603;
UPDATE `gameobject` SET `spawnMask` = (1 << 14) | (1 << 33) WHERE `map` = 603;
