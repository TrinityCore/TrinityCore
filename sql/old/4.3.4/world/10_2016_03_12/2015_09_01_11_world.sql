--
DELETE FROM `creature` WHERE `guid` IN (109404,109385, 113, 114);
INSERT INTO `creature` (`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`curhealth`,`curmana`,`MovementType`) VALUES
(109404,27024,571,4676.16,-5575.82,53.61,0.85,120,6,9940,0,2),
(109385,26935,571,4550.15,-5493.45,2.19,0.85,120,6,9940,0,2);
