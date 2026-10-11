UPDATE `world_state` SET `Comment`='11.1.5 Midseason - Turbo-Boost Quest Turn-In Tracker (Currency) - Max quantity' WHERE `ID`=29245;
UPDATE `world_state` SET `DefaultValue`=10 WHERE `ID`=29713;
UPDATE `world_state` SET `DefaultValue`=2250000 WHERE `ID`=28715;
UPDATE `world_state` SET `DefaultValue`=575000 WHERE `ID`=28441;
UPDATE `world_state` SET `DefaultValue`=810 WHERE `ID`=28390;
UPDATE `world_state` SET `DefaultValue`=900 WHERE `ID`=28388;
UPDATE `world_state` SET `DefaultValue`=0 WHERE `ID`=28182;
UPDATE `world_state` SET `DefaultValue`=9 WHERE `ID`=28158;
UPDATE `world_state` SET `DefaultValue`=3276 WHERE `ID`=27793;
UPDATE `world_state` SET `DefaultValue`=252 WHERE `ID`=27335;
UPDATE `world_state` SET `DefaultValue`=11 WHERE `ID`=27326;
UPDATE `world_state` SET `DefaultValue`=640000 WHERE `ID`=27170;

DELETE FROM `world_state` WHERE `ID`=29600;
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(29600, 0, NULL, NULL, '', '11.2.5 Midseason - Turbo-Boost Quest Turn-In Tracker (Currency) - Max quantity');
