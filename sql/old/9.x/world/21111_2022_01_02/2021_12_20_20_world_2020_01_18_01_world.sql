-- 
DELETE FROM `creature` WHERE `guid` IN(200010,200008) AND `id` IN (29057,29069);
DELETE FROM `spawn_group` WHERE `spawnId` IN (200010,200008) AND `spawnType`=0;
UPDATE `creature` SET `position_x`=6232.26, `position_y`=4944.96, `position_z`=-98.8431, `orientation`=3.43397, `spawndist`=0, `MovementType`=0 WHERE `guid`=115122;
UPDATE `creature` SET `position_x`=6241.88, `position_y`=4953.22, `position_z`=-98.7876, `orientation`=3.57534, `spawndist`=0, `MovementType`=0 WHERE `guid`=115126;
UPDATE `creature` SET `position_x`=6222.05, `position_y`=4943.04, `position_z`=-98.8662, `orientation`=3.62246, `spawndist`=0, `MovementType`=0 WHERE `guid`=115196;
UPDATE `creature` SET `position_x`=6203.99, `position_y`=4966.64, `position_z`=-98.9068, `orientation`=4.27041, `spawndist`=0, `MovementType`=0 WHERE `guid`=115136;
UPDATE `creature` SET `position_x`=6212.96, `position_y`=4974.03, `position_z`=-98.8272, `orientation`=4.08192, `spawndist`=0, `MovementType`=0 WHERE `guid`=115192;
