-- Defias Messenger -- Add more lines
DELETE FROM `creature_text` WHERE `CreatureID`=550 AND `GroupID`=0 AND `ID`>2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(550,0,3,"Who dares interfere with the business of the Defias Brotherhood?  Die $C!",12,7,100,0,0,0,474,0,"Defias Messenger"),
(550,0,4,"Death to any $R that stands in my way!",12,7,100,0,0,0,475,0,"Defias Messenger"),
(550,0,5,"Who dares to provoke the messenger of Edwin Van Cleef?  Die $R!",12,7,100,0,0,0,476,0,"Defias Messenger"),
(550,0,6,"Am I carrying any letters addressed to $n? Why, no!  Looks like it's time for you to die!",12,7,100,0,0,0,477,0,"Defias Messenger"),
(550,0,7,"Here's a singing telegram for $n: Roses are red, violets are blue, I will kill any $R I see, including you!",12,7,100,0,0,0,480,0,"Defias Messenger");
