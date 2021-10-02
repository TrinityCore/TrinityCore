ALTER TABLE `playercreateinfo`
  ADD `npe_map` int(10) unsigned DEFAULT NULL AFTER `orientation`,
  ADD `npe_position_x` float DEFAULT NULL AFTER `npe_map`,
  ADD `npe_position_y` float DEFAULT NULL AFTER `npe_position_x`,
  ADD `npe_position_z` float DEFAULT NULL AFTER `npe_position_y`,
  ADD `npe_orientation` float DEFAULT NULL AFTER `npe_position_z`,
  ADD `npe_transport_guid` bigint(20) unsigned DEFAULT NULL AFTER `npe_orientation`,
  DROP `zone`;

DELETE FROM `gameobject_template` WHERE `entry` IN (333479,349879);
INSERT INTO `gameobject_template` (`entry`,`type`,`displayId`,`name`,`IconName`,`castBarCaption`,`unk1`,`size`,`Data0`,`Data1`,`Data2`,`Data3`,`Data4`,`Data5`,`Data6`,`Data7`,`Data8`,`Data9`,`Data10`,`Data11`,`Data12`,`Data13`,`Data14`,`Data15`,`Data16`,`Data17`,`Data18`,`Data19`,`Data20`,`Data21`,`Data22`,`Data23`,`Data24`,`Data25`,`Data26`,`Data27`,`Data28`,`Data29`,`Data30`,`Data31`,`Data32`,`Data33`,`ContentTuningId`,`VerifiedBuild`) VALUES
(333479,15,61205,'Alliance Ship','','','',1,7748,10,2,0,0,81,2261,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,40120), -- Alliance Ship
(349879,15,61835,'Horde Transport','','','',1,8099,10,2,0,0,81,2369,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,40120); -- Horde Transport

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (333479,349879);
INSERT INTO `gameobject_template_addon` (`entry`,`faction`,`flags`,`mingold`,`maxgold`,`WorldEffectID`,`AIAnimKitID`) VALUES
(333479,0,0x28,0,0,0,0),
(349879,0,0x28,0,0,0,0);

SET @ALLIANCE_SHIP := 29;
SET @HORDE_SHIP := 30;
DELETE FROM `transports` WHERE `guid` IN (@ALLIANCE_SHIP,@HORDE_SHIP);
INSERT INTO `transports` (`guid`, `entry`, `name`, `phaseUseFlags`, `phaseid`, `phasegroup`, `ScriptName`) VALUES
(29,333479,'NPE - Alliance Ship',0,0,0,''),
(30,349879,'NPE - Horde Transport',0,0,0,'');

UPDATE `playercreateinfo` SET `npe_map`=2175,`npe_position_x`=11.1301,`npe_position_y`=-0.417182,`npe_position_z`=5.18741,`npe_orientation`=3.1484344,`npe_transport_guid`=@ALLIANCE_SHIP WHERE `race` IN (1,3,4,7,11,22,25) AND `class` NOT IN (6,12);
UPDATE `playercreateinfo` SET `npe_map`=2175,`npe_position_x`=-10.7291,`npe_position_y`=-7.14635,`npe_position_z`=8.73113,`npe_orientation`=1.563206,`npe_transport_guid`=@HORDE_SHIP WHERE `race` IN (2,5,6,8,9,10,26) AND `class` NOT IN (6,12);
