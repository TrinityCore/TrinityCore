DELETE FROM `world_state` WHERE `ID` IN (2259,2260,2261,2262,2263,2264);
INSERT INTO `world_state` (`ID`,`DefaultValue`,`MapIDs`,`AreaIDs`,`ScriptName`,`Comment`) VALUES
(2259,0,NULL,NULL,'','Scourge Invasion - Winterspring Under Attack'),
(2260,0,NULL,NULL,'','Scourge Invasion - Azshara Under Attack'),
(2261,0,NULL,NULL,'','Scourge Invasion - Blasted Lands Under Attack'),
(2262,0,NULL,NULL,'','Scourge Invasion - Burning Steppes Under Attack'),
(2263,0,NULL,NULL,'','Scourge Invasion - Tanaris Under Attack'),
(2264,0,NULL,NULL,'','Scourge Invasion - Eastern Plaguelands Under Attack');
