DELETE FROM `creature_text` WHERE `CreatureID`=20926 AND `GroupID` IN (0,1);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(20926,0,0,'You hear a faint echo....',16,0,100,0,0,0,18599,3,'When Access Panel is used'),
(20926,1,0,'You hear a loud rumble of metal grinding on stone...',16,0,100,0,0,0,18600,3,'When main door open');
