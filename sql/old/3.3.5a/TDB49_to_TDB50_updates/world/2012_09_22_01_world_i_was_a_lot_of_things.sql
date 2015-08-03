-- Quest: I was a lot of things
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_shadowmoon_tuber_node',`flags_extra`=`flags_extra`|128 WHERE `entry`=21347;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=36652;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,1,36652,31,3,21347,'Tuber Whistle targets Shadowmoon Valley Tuber Node');

UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=21195;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=21195;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21195 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_param2`,`action_type`,`action_param1`,`action_param2`,`target_type`,`target_param1`,`target_param2`,`comment`) VALUES
(21195,1,0,34,1,24,0,0, 1,    0,0, 'Domesticated Felboar - Movementinform - Evade (Required for core script npc_shadowmoon_tuber_node)'),
(21195,2,0,34,1,45,1,1,11,21347,5, 'Domesticated Felboar - Movementinform - Set data (Required for core script npc_shadowmoon_tuber_node)');

SET @TRIGGER_GUID = 77821; -- 10
SET @BOAR_GUID    = 77832; -- 8

DELETE FROM `creature` WHERE `id`=21347 OR `guid` BETWEEN @TRIGGER_GUID AND @TRIGGER_GUID + 9;
SET @TRIGGER_GUID = @TRIGGER_GUID - 1;
INSERT INTO `creature`(`guid`,`id`,`map`,`phaseMask`,`position_x`,`position_y`,`position_z`)
SELECT (SELECT @TRIGGER_GUID:=@TRIGGER_GUID+1),21347,`map`,3,`position_x`,`position_y`,`position_z` FROM `gameobject` WHERE `id`=184701 LIMIT 10;

DELETE FROM `creature` WHERE (`id`=21195 AND `map`=530) OR `guid` BETWEEN @BOAR_GUID AND @BOAR_GUID + 7;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`curhealth`,`MovementType`) VALUES
(@BOAR_GUID  ,21195,530,-2506.78,1190.22,55.9496,4.15084,300,5,6116,1),
(@BOAR_GUID+1,21195,530,-2486.92,1326.49,64.4239,5.31872,300,5,6116,1),
(@BOAR_GUID+2,21195,530,-2476.05,1284.68,48.0809,1.20087,300,5,5914,1),
(@BOAR_GUID+3,21195,530,-2476.74,1228.44,40.4087,3.72907,300,5,5914,1),
(@BOAR_GUID+4,21195,530,-2549.03,1162.94,78.8947,1.48754,300,5,6116,1),
(@BOAR_GUID+5,21195,530,-2553.91,1186.80,78.5604,1.17575,300,5,6116,1),
(@BOAR_GUID+6,21195,530,-2694.88,1495.00,19.2922,2.33106,300,5,5914,1),
(@BOAR_GUID+7,21195,530,-2706.26,1538.41,16.6343,1.96146,300,5,5914,1);
