--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND (`SourceEntry`=11586 OR `SourceEntry`=11585);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES 
(19, 11585, 14, 10172, "Accept quest 11585 - Quest 10172 needs to be incomplete"),
(19, 11586, 8, 10172, "Accept quest 11586 - Quest 10172 needs to be rewarded");

UPDATE `quest_template_addon` SET `ExclusiveGroup`=11585 WHERE  `ID`IN(11585,11586);
