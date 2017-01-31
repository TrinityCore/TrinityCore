-- East Porticullis(195648): close and corrections
UPDATE `gameobject` SET `phaseMask`=1,`rotation2`=0.7071065,`rotation3`=0.707107,`spawntimesecs`=7200,`animprogress`=255,`state`=0 WHERE `guid`=151176;

-- North Portcullis(195650): delete extra spawn and corrections
DELETE FROM `gameobject` WHERE `guid`=150080;
UPDATE `gameobject` SET `phaseMask`=1,`rotation2`=0.7071065,`rotation3`=0.707107,`spawntimesecs`=7200,`animprogress`=255,`state`=1 WHERE `guid`=151178;

-- Web Door(195485): corrections
UPDATE `gameobject` SET `spawnMask`=15,`rotation2`=0.7071067,`rotation3`=0.7071068,`spawntimesecs`=7200,`animprogress`=255 WHERE `guid`=151192;
