UPDATE `creature` SET `spawnMask` = 1 << 1 WHERE `map` = 109;
UPDATE `gameobject` SET `spawnMask` = 1 << 1 WHERE `map` = 109;

UPDATE `creature` SET `spawnMask` = (1 << 14) | (1 << 33) WHERE `map` = 564;
UPDATE `gameobject` SET `spawnMask` = (1 << 14) | (1 << 33) WHERE `map` = 564;

UPDATE `creature` SET `spawnMask` = 1 << 25 WHERE `map` = 1191;
UPDATE `gameobject` SET `spawnMask` = 1 << 25 WHERE `map` = 1191;

UPDATE `creature` SET `PhaseGroup` = 0 WHERE `PhaseGroup` IN (1, 169);
UPDATE `gameobject` SET `PhaseGroup` = 0 WHERE `PhaseGroup` IN (1, 169);

UPDATE `creature` SET `PhaseId` = 0 WHERE `PhaseId` = 1;
UPDATE `gameobject` SET `PhaseId` = 0 WHERE `PhaseId` = 1;

UPDATE `creature` SET `PhaseId` = 0 WHERE `PhaseId` = 169 AND `PhaseGroup` = 396;
UPDATE `gameobject` SET `PhaseId` = 0 WHERE `PhaseId` = 169 AND `PhaseGroup` = 396;
