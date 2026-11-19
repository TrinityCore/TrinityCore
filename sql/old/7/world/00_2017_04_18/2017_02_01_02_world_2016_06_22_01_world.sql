--
DELETE FROM `quest_template_addon` WHERE `ID` IN (9796, 10105);
INSERT INTO `quest_template_addon` (`ID`, `ExclusiveGroup`) VALUES
(9796, 9796),
(10105, 9796);
