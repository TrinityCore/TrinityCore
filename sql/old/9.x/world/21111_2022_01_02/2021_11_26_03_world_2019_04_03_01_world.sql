-- 
DELETE FROM `quest_template_addon` WHERE `ID`=9697;
INSERT INTO `quest_template_addon` (`ID`, `RequiredMinRepFaction`,`RequiredMinRepValue`) VALUES
(9697,942,3000);
UPDATE `quest_template_addon` SET `RequiredMinRepFaction` = 942, `RequiredMinRepValue` = 3000 WHERE `ID`=9957;
