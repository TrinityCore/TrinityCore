DELETE FROM `creature_text` WHERE CreatureID=22984;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(22984, 0, 0, 'You hear a loud rumble of metal grinding on stone...', 16, 0, 100, 0, 0, 0, 18600, 2, "Black Temple Trigger - when High Warlord Naj'entus dies - Emote"),
(22984, 1, 0, 'The door to The Den of Mortal Delights has opened.', 16, 0, 100, 0, 0, 0, 21494, 2, 'Black Temple Trigger - when Lower Temple Defeated - Emote');
