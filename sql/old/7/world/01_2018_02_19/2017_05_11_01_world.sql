--
UPDATE `creature` SET `spawnMask` = 1 WHERE `guid` IN (250022,250025);
UPDATE `creature` SET `spawnMask` = 2 WHERE `map` =109;
UPDATE `creature` SET `spawnMask` = 16 WHERE `guid` IN (86283,86284,86285,86286,86287,86288,86289,86290,86291);
UPDATE `creature` SET `PhaseId` = 169 WHERE `guid` IN (250025,351326,452536,452537,452538,452539,452540);
UPDATE `gameobject` SET `PhaseId` = 169 WHERE `id` = 181371 AND `PhaseId` = 1;
