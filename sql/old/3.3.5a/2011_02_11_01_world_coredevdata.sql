DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=28239);
DELETE FROM `creature` WHERE `id`=28239;

UPDATE `creature` SET `position_x`=1357.86,`position_y`=1055.26,`position_z`=463.02 WHERE `guid`=101498;
UPDATE `creature` SET `position_x`=1210.38,`position_y`=1118.57,`position_z`=471.41 WHERE `guid`=100931;

UPDATE `creature_template` SET `flags_extra`=130 WHERE `entry`=28183;
UPDATE `creature_template` SET `scale`=1 WHERE `entry`=28183;

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=28183);
DELETE FROM `creature` WHERE `id`=28183;
-- this guids were used by the old spawns.
INSERT INTO `creature` (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, DeathState, MovementType) VALUES
(100227, 28183, 578, 3, 1, 0, 0, 1242.73267, 1079.592, 439.232849, 6.108652, 120, 0, 0, 1, 0, 0, 0),
(100228, 28183, 578, 3, 1, 0, 0, 1246.566, 1051.25171, 439.232849, 0.5061455, 120, 0, 0, 1, 0, 0, 0),
(100229, 28183, 578, 3, 1, 0, 0, 1265.30212, 1109.22742, 439.232849, 5.18362761, 120, 0, 0, 1, 0, 0, 0),
(100230, 28183, 578, 3, 1, 0, 0, 1277.07471, 1027.78992, 439.232849, 1.37881, 120, 0, 0, 1, 0, 0, 0),
(100231, 28183, 578, 3, 1, 0, 0, 1293.79858, 1113.18054, 439.232849, 4.485496, 120, 0, 0, 1, 0, 0, 0),
(100232, 28183, 578, 3, 1, 0, 0, 1305.63025, 1031.75171, 439.232849, 2.042035, 120, 0, 0, 1, 0, 0, 0),
(100233, 28183, 578, 3, 1, 0, 0, 1324.38538, 1089.79688, 439.232849, 3.59537816, 120, 0, 0, 1, 0, 0, 0),
(100234, 28183, 578, 3, 1, 0, 0, 1328.00171, 1061.15283, 439.232849, 2.8972466, 120, 0, 0, 1, 0, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (54069,56251);
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, ElseGroup, ConditionTypeOrReference, ConditionValue1, ConditionValue2, ConditionValue3, ErrorTextId, ScriptName, COMMENT) VALUES 
(13,0,54069,0,18,1,28183,0,0,'',NULL),
(13,0,56251,0,18,1,28183,0,0,'',NULL);

DELETE FROM `creature_template_addon` WHERE `entry`=28183;
INSERT INTO `creature_template_addon` (entry,auras) VALUE (28183,'50798 0');

DELETE FROM `creature_text` WHERE `entry`=27447;
INSERT INTO `creature_text` (entry,groupid,id,TEXT,TYPE,LANGUAGE,sound) VALUES 
(27447,0,0,'There will be no mercy!',1,0,13649),
(27447,1,1,'Blast them! Destroy them!',1,0,13650),
(27447,2,2,'%s calls an Azure Ring Captain!',3,0,0),
(27447,3,3,'They are... too strong! Underestimated their... fortitude.',1,0,13655);
