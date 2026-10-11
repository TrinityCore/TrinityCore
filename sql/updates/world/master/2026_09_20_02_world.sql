DELETE FROM `world_state` WHERE `ID` IN (30744, 30731, 32183, 31270, 31815, 30933, 30934, 32248, 32659, 31826);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(30744, 44, NULL, NULL, '', 'Nebulous Voidcore - Midnight Season 1 (Currency) - Max quantity'),
(30731, 4, NULL, NULL, '', '12.0.5 Midseason - Voidforge Upgrade - Turn-In Tracker (Currency) - Max quantity'),
(32183, 0, NULL, NULL, '', 'Nebulous Voidcore - Midnight Season 2 (Currency) - Max quantity'),
(31270, 480000, NULL, NULL, '', 'Conquest - Midnight Season 2 (Currency) - Max quantity'),
(31815, 480000, NULL, NULL, '', 'Bloody Tokens - Midnight Season 2 (Currency) - Max quantity'),
(30933, 600, NULL, NULL, '', 'Veteran/Champion/Adventurer Mistcrest (Currency) - Max quantity'),
(30934, 500, NULL, NULL, '', 'Hero/Myth Mistcrest (Currency) - Max quantity'),
(32248, 20, NULL, NULL, '', 'Renown - Zul''jarra''s Forces (Currency) - Max quantity'),
(32659, 8, NULL, NULL, '', 'Tidal Spark Dust (Currency) - Max quantity'),
(31826, 5, NULL, NULL, '', '12.1 Delves - Personal Tracker - S2 Weekly Turn-In (Hidden) (Currency) - Max quantity');

UPDATE `world_state` SET `DefaultValue`=140 WHERE `ID`=27335;
UPDATE `world_state` SET `DefaultValue`=29 WHERE `ID` IN (27488,27500,27501,27502,27503,27504,27505,27506,27507,27508,27509,27510);
UPDATE `world_state` SET `DefaultValue`=420 WHERE `ID`=27489;
UPDATE `world_state` SET `DefaultValue`=270 WHERE `ID`=27490;
UPDATE `world_state` SET `DefaultValue`=300 WHERE `ID`=27491;
UPDATE `world_state` SET `DefaultValue`=540 WHERE `ID`=27492;
UPDATE `world_state` SET `DefaultValue`=570 WHERE `ID`=27493;
UPDATE `world_state` SET `DefaultValue`=600 WHERE `ID`=27494;
UPDATE `world_state` SET `DefaultValue`=360 WHERE `ID`=27495;
UPDATE `world_state` SET `DefaultValue`=330 WHERE `ID`=27496;
UPDATE `world_state` SET `DefaultValue`=450 WHERE `ID`=27497;
UPDATE `world_state` SET `DefaultValue`=540 WHERE `ID`=27498;
UPDATE `world_state` SET `DefaultValue`=330 WHERE `ID`=27499;
UPDATE `world_state` SET `DefaultValue`=9828 WHERE `ID`=27793;
UPDATE `world_state` SET `DefaultValue`=0 WHERE `ID` IN (29184,29185);
UPDATE `world_state` SET `DefaultValue`=15 WHERE `ID`=29713;
UPDATE `world_state` SET `DefaultValue`=27 WHERE `ID`=30221;
UPDATE `world_state` SET `DefaultValue`=6 WHERE `ID`=30474;
UPDATE `world_state` SET `DefaultValue`=20 WHERE `ID` IN (31021,31023,31024,31025);
