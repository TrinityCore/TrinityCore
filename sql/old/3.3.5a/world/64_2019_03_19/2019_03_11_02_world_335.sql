-- 
DELETE FROM `gameobject` WHERE `guid` IN (14999) AND `id`=202083;
DELETE FROM `gameobject_addon` WHERE `guid` IN (14999);
DELETE FROM `pool_gameobject` WHERE `guid` IN (14999,6248) AND `pool_entry`=202482;
INSERT INTO `pool_gameobject` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(6248, 202482, 25, "Razormaw Matriarch's Nest (202083) P1");
