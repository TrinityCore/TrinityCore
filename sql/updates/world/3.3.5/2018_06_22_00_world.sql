DELETE FROM `creature` WHERE `guid` IN(73427,73428);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(73427,26121,547,0,0,1,1,0,0,-69.8121,-162.4954,-2.30451,1.710423,300,0,0,1,1,0,0,0,0,'',0),
(73428,26120,547,0,0,1,1,0,0,-98.1029,-230.7864,-10.8085,1.448623,300,0,0,1,1,0,0,0,0,'',0);

DELETE FROM `game_event_creature` WHERE `eventEntry`=1 AND `guid` IN(73427,73428);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(1,73427),
(1,73428);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=26120;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(26120,0,0,1,0);
