-- These quests requires friendly reputation with Tranquillien (922) to be available
DELETE FROM `quest_template_addon` WHERE `ID` IN (9145,9150,9155,9160,9171,9192,9207);
INSERT INTO `quest_template_addon` (`ID`,`RequiredMinRepFaction`,`RequiredMinRepValue`,`SpecialFlags`) VALUES
(9145,922,3000,0),
(9150,922,3000,0),
(9155,922,3000,0),
(9160,922,3000,2),
(9171,922,3000,0),
(9207,922,3000,0),
(9192,922,3000,0);

-- Quest "Retaking Windrunner Spire" requires honored reputation with Tranquillien to be available
DELETE FROM `quest_template_addon` WHERE `ID`=9173;
INSERT INTO `quest_template_addon` (`ID`,`RequiredMinRepFaction`,`RequiredMinRepValue`) VALUES
(9173,922,9000);
