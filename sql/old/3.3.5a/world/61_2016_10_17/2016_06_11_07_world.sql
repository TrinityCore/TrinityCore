--
UPDATE `quest_template_addon` SET `SpecialFlags`=0 WHERE `ID` IN (8552, 3785);

DELETE FROM `quest_template_addon` WHERE `ID`=2882;
INSERT INTO `quest_template_addon` (`ID`, `SpecialFlags`) VALUES
(2882, 1);
