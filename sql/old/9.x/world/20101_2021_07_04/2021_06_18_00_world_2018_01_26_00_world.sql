-- 
DELETE FROM `event_scripts` WHERE `id` = 19714;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(19714,0,9,5272,60,0,0,0,0,0),
(19714,0,9,5273,60,0,0,0,0,0),
(19714,0,9,5274,60,0,0,0,0,0),
(19714,0,9,5271,60,0,0,0,0,0),
(19714,0,9,5275,60,0,0,0,0,0),
(19714,0,10,30461,600000,0,6947.48,-859.518,1147.6,5.67487);
UPDATE `gameobject` SET `position_z`=1066.73991 WHERE `guid`=5275;
UPDATE `gameobject` SET `position_z`=1067.04003 WHERE `guid`=5274;

