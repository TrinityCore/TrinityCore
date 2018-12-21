DROP TABLE IF EXISTS `world_map_template`;
CREATE TABLE `world_map_template`(
    `mapID` INT(11) UNSIGNED NOT NULL DEFAULT '0' ,
    `ScriptName` TEXT,
    PRIMARY KEY (`mapID`));

DELETE FROM `world_map_template` WHERE `mapId`= 369;
INSERT INTO `world_map_template` (`mapID`, `ScriptName`) VALUES
(369, 'world_map_deeprun_tram');

DELETE FROM `gameobject` WHERE `guid` IN (18802, 18803, 18804, 18805, 18806, 18807);
DELETE FROM `gameobject_addon` WHERE `guid` IN (18802, 18803, 18804, 18805, 18806, 18807);

UPDATE `gameobject_template` SET `data6`= 0, `data8`= 0, `data10`= 0 WHERE `entry`= 176084;
