-- Arcanist Ithanas
UPDATE `creature_template` SET `gossip_menu_id`= 15296 WHERE `entry`= 15296;

DELETE FROM `gossip_menu` WHERE `MenuId`= 15296;
INSERT INTO `gossip_menu` (`MenuId`,`textid`,`VerifiedBuild`) VALUES (15296, 7787, 0);

-- Arcanist Helion
UPDATE `creature_template` SET `gossip_menu_id`= 15297 WHERE `entry`= 15297;

DELETE FROM `gossip_menu` WHERE `MenuId`= 15297;
INSERT INTO `gossip_menu` (`MenuId`,`textid`,`VerifiedBuild`) VALUES (15297, 7786, 0);

-- Lanthan Perilon
DELETE FROM `gossip_menu` WHERE `MenuId`= 6570 AND `textid`= 7785;
INSERT INTO `gossip_menu` (`MenuId`,`textid`,`VerifiedBuild`) VALUES (6570, 7785, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 6570;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`comment`) VALUES
(14, 6570, 7785, 0, 0, 8, 0, 8335, 0, 0, 1, 0, 0, '', "Gossip text requires quest 'Felendren the Banished' NOT rewarded"),
(14, 6570, 7869, 0, 0, 8, 0, 8335, 0, 0, 0, 0, 0, '', "Gossip text requires quest 'Felendren the Banished' rewarded");

-- Outrunner Alarion
DELETE FROM `gossip_menu` WHERE `MenuId`= 6573 AND `textid`= 7788;
INSERT INTO `gossip_menu` (`MenuId`,`textid`,`VerifiedBuild`) VALUES (6573, 7788, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 6573;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`comment`) VALUES
(14, 6573, 7788, 0, 0, 8, 0, 9705, 0, 0, 1, 0, 0, '', "Gossip text requires quest 'Package Recovery' NOT rewarded"),
(14, 6573, 7821, 0, 0, 8, 0, 9705, 0, 0, 0, 0, 0, '', "Gossip text requires quest 'Package Recovery' rewarded");
