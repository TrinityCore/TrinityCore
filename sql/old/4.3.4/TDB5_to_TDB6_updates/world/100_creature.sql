DELETE FROM `creature` WHERE `guid` = 223809;
UPDATE `creature` SET `phaseMask`=1 WHERE `guid` = 25;
UPDATE `creature` SET `spawnMask`=1 WHERE `id` = 22515 AND `map`=628;
UPDATE `creature` SET `spawndist`=5 WHERE `guid`  IN (4224, 4245, 4269, 4288);
