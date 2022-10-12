DELETE FROM `skill_tiers` WHERE `ID` IN (333,335,336,338);
INSERT INTO `skill_tiers` (`ID`,`Value1`,`Value2`,`Value3`,`Value4`,`Value5`,`Value6`,`Value7`,`Value8`,`Value9`,`Value10`,`Value11`,`Value12`,`Value13`,`Value14`,`Value15`,`Value16`) VALUES
(333,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
(335,75,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
(336,300,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
(338,150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

UPDATE `skill_tiers` SET `Value10`=800,`Value11`=950 WHERE `ID`=224;
