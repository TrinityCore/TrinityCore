--
-- DELETE FROM `gameobject` WHERE `id`=64922 AND `guid`=189980;
-- DELETE FROM `gameobject_addon` WHERE `guid`=189980;
DELETE FROM `pool_gameobject` WHERE `pool_entry`=5217 ;
-- DELETE FROM `pool_creature` WHERE `guid`=134515 AND `pool_entry`=1047;
DELETE FROM `pool_template` WHERE `entry` IN (5217,5450,5506,5517,5608);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(5450,1,"Icecrown node 3"),
(5506,1,"Icecrown node 59"),
(5517,1,"Icecrown node 70"),
(5608,1,"Icecrown node 161");
