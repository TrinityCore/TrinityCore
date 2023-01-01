-- 
UPDATE `gameobject` SET `spawntimesecs`=43200 WHERE `id` IN (176325,176327,173232,173234);
UPDATE `gameobject_template` SET `AIName`="" WHERE `entry` IN (176325,176327);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (176325,176327) AND `source_type`=1;
DELETE FROM `event_scripts` WHERE `id` IN (5300,5301);
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(5300,0,10,11120,900000,0,3581.71, -2984.3996, 125.001, 4.991206),
(5301,0,10,11121,900000,0,3823.34, -3708.2463, 143.355, 1.963489);
