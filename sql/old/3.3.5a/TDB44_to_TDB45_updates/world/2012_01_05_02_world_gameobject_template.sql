-- Fixing quest 12234 "Need to Know"
UPDATE `gameobject_template` SET `flags`=`flags`|4 WHERE `entry`=188675; -- Scarlet Onslaught Daily Orders: Barracks by sniff
UPDATE `gameobject_template` SET `flags`=`flags`|4 WHERE `entry`=188676; -- Scarlet Onslaught Daily Orders: Abbey by sniff
UPDATE `gameobject_template` SET `flags`=`flags`|4 WHERE `entry`=188677; -- Scarlet Onslaught Daily Orders: Beach by sniff
DELETE FROM `gameobject` WHERE `id`=188677;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(219,188677,571,1,1,2567.449,-388.7118,3.573463,-2.879789,0,0,-0.9914446,0.1305283,300,100,1);
