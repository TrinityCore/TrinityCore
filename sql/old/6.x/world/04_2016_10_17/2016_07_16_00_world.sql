-- Restore deleted gameobject 181260 (Scorched Grove Runestone)
DELETE FROM `gameobject_template` WHERE `entry`= 181260;
INSERT INTO `gameobject_template` (`entry`,`type`,`displayId`,`name`,`IconName`,`castBarCaption`,`unk1`,`faction`,`flags`,`size`,`Data0`,`Data1`,`Data2`,`Data3`,`Data4`,`Data5`,`Data6`,`Data7`,`Data8`,`Data9`,`Data10`,`Data11`,`Data12`,`Data13`,`Data14`,`Data15`,`Data16`,`Data17`,`Data18`,`Data19`,`Data20`,`Data21`,`Data22`,`Data23`,`Data24`,`Data25`,`Data26`,`Data27`,`Data28`,`Data29`,`Data30`,`Data31`,`Data32`,`unkInt32`,`AIName`,`ScriptName`,`VerifiedBuild`) VALUES
(181260,8,0,'Scorched Grove Runestone','','','',0,0,1,1401,35,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'','',0);

DELETE FROM `gameobject` WHERE `id`= 181260;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`PhaseId`,`PhaseGroup`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`VerifiedBuild`) VALUES
(99935, 181260, 530, 0, 0, 1, 0, 0, 8206.85, -6335.76, 64.5, 0, 0, 0, 0, 0, 180, 0, 1, 0);
