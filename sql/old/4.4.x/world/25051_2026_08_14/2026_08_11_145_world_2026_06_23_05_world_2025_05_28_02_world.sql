--
DELETE FROM `creature_text` WHERE `CreatureID` = 17798 AND `GroupID` = 3 AND `ID` = 1;
DELETE FROM `creature_text` WHERE `CreatureID` = 17798 AND `GroupID` = 5;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(17798,5,0,"%s begins to channel from the nearby distiller...",16,0,100,0,0,0,19166,0,"kalithresh EMOTE_CHANNEL");
