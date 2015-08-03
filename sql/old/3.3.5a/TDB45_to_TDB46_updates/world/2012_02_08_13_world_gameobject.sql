-- Lunar festival: Rocket Clusters placed near Omen's summon place (Moonglade)
SET @CLUSTER := 180874;
SET @LUNARFESTIVAL := 7;

DELETE FROM `gameobject` WHERE `id`=@CLUSTER AND `guid` IN (230,231);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`) VALUES
(230,@CLUSTER,1,1,1,7531.662,-2851.228,458.9172),
(231,@CLUSTER,1,1,1,7561.145,-2872.45,461.0998);

DELETE FROM `game_event_gameobject` WHERE `guid` IN (230,231) AND `eventEntry`=@LUNARFESTIVAL;
INSERT INTO `game_event_gameobject` (`eventEntry`,`guid`) VALUES
(@LUNARFESTIVAL,230),
(@LUNARFESTIVAL,231);
