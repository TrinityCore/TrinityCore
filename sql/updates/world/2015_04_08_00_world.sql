-- Kill some database errors
DELETE FROM `creature_addon` WHERE `guid` IN (52306, 52317, 52312, 52303, 52296, 127436, 127437);
UPDATE `creature` SET `spawndist`=0 WHERE `guid`=52331;
UPDATE `creature` SET `spawndist`=0 WHERE `guid`=52330;
UPDATE `creature` SET `spawndist`=0 WHERE `guid`=120692;
DELETE FROM `linked_respawn` WHERE  `guid`=127436 AND `linkType`=0;
DELETE FROM `linked_respawn` WHERE  `guid`=127437 AND `linkType`=0;
