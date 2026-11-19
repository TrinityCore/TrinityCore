DELETE FROM `conditions` WHERE `ConditionTypeOrReference`=19 AND `SourceEntry` IN (13604,13817,50452,50453);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(10,34379,50453,0,0,49,0,6,0,0,0,0,0,'','Ring of Rotting Sinew only 25 heroic'),
(10,34379,50452,0,0,49,0,6,0,0,0,0,0,'','Wodin\'s Lucky Necklace only 25 heroic');

ALTER TABLE `creature` ADD `spawnDifficulties` VARCHAR(100) NOT NULL DEFAULT '0' AFTER `spawnMask`;
UPDATE `creature` SET `spawnDifficulties`=MAKE_SET(`spawnMask`,"0","1","2","3","4","5","6","7","8","9",NULL,"11","12",NULL,"14","15","16","17","18","19","20",NULL,NULL,"23","24","25","26","27",NULL,"29","30",NULL,"32","33","34");
ALTER TABLE `creature` DROP `spawnMask`;

ALTER TABLE `gameobject` ADD `spawnDifficulties` VARCHAR(100) NOT NULL DEFAULT '0' AFTER `spawnMask`;
UPDATE `gameobject` SET `spawnDifficulties`=MAKE_SET(`spawnMask`,"0","1","2","3","4","5","6","7","8","9",NULL,"11","12",NULL,"14","15","16","17","18","19","20",NULL,NULL,"23","24","25","26","27",NULL,"29","30",NULL,"32","33","34");
ALTER TABLE `gameobject` DROP `spawnMask`;
