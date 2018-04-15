-- GO missing spawn
-- Zone: Tanaris, Area: Land's End Beach or Finisterrae Beach
SET @GO_ENTRY := 142189; -- GO Inconspicuous Landmark entry
SET @GO_GUID := 329; -- Need one guid
SET @POOL := 355; -- Need one entry

DELETE FROM `gameobject` WHERE `id`=@GO_ENTRY;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(17499,@GO_ENTRY,1,1,1,-10249.2,-3981.8,1.66783,-0.750491,0,0,0.366501,-0.930418,900,100,1), -- Already in TDB
(17498,@GO_ENTRY,1,1,1,-10119.7,-4052.46,5.33005,-0.366519,0,0,0.182236,-0.983255,900,100,1), -- Already in TDB
(@GO_GUID,@GO_ENTRY,1,1,1,-10154.2,-3948.635,7.744733,2.652894,0,0,0.970295,0.241925,900,100,1);

DELETE FROM `pool_template` WHERE `entry`=@POOL;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@POOL,1 , 'GO Inconspicuous Landmark (142189)');

DELETE FROM `pool_gameobject` WHERE `guid` IN (17498,17499,@GO_GUID);
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(17498,@POOL,0, 'Inconspicuous Landmark'),
(17499,@POOL,0, 'Inconspicuous Landmark'),
(@GO_GUID,@POOL,0, 'Inconspicuous Landmark');
