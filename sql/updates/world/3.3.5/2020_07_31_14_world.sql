-- http://web.archive.org/web/20120706221554/www.wowhead.com/npc=25396
DELETE FROM `creature_text` WHERE `CreatureID` = 25396;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25396,0,0,"You should not have come here!",12,0,100,0,0,0,13923,0,"Naxxanar Skeletal Mage"),
(25396,0,1,"You'll be joining the other guests now....",12,0,100,0,0,0,13924,0,"Naxxanar Skeletal Mage"),
(25396,0,2,"You cannot stop us all!",12,0,100,0,0,0,13925,0,"Naxxanar Skeletal Mage"),
(25396,0,3,"Your death will soon follow....",12,0,100,0,0,0,13926,0,"Naxxanar Skeletal Mage");
