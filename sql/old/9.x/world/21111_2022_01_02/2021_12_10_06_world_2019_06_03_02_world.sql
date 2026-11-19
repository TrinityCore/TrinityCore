DELETE FROM `creature_text` WHERE `CreatureID`=25478;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25478, 0, 0, "Pathetic fool! A servant of Malygos would sooner die than aid an enemy....", 15, 0, 100, 0, 0, 0, 24735, 0, "Imprisoned Beryl Sorcerer"),
(25478, 1, 0, "Aargh! Do your worst, $c! I'll tell you NOTHING!", 15, 0, 100, 0, 0, 0, 24736, 0, "Imprisoned Beryl Sorcerer"),
(25478, 2, 0, "Aahhhh! Release me! I am of no use to you. I swear it!", 15, 0, 100, 0, 0, 0, 24737, 0, "Imprisoned Beryl Sorcerer"),
(25478, 3, 0, "Stop! I beg you, please stop. Please....", 15, 0, 100, 0, 0, 0, 24738, 0, "Imprisoned Beryl Sorcerer"),
(25478, 4, 0, "Alright! I am beaten. Your precious archmage is held in a prison, elevated and sealed. Even if you manage to reach her, Salrand herself holds the key. Your mission is folly!", 15, 0, 100, 0, 0, 0, 24739, 0, "Imprisoned Beryl Sorcerer"),
(25478, 5, 0, "Enough! I've told you all that I know. Your continued abuse is senseless!", 15, 0, 100, 0, 0, 0, 24740, 0, "Imprisoned Beryl Sorcerer"),
(25478, 6, 0, "Noooo! This torture is inhumane! You have what you want... why don't you just kill me?", 15, 0, 100, 0, 0, 0, 24755, 0, "Imprisoned Beryl Sorcerer"),
(25478, 7, 0, "I've given you the information, $r! You're wasting your time....", 15, 0, 100, 0, 0, 0, 24756, 0, "Imprisoned Beryl Sorcerer"),
(25478, 8, 0, "What more can you possibly want, $r?", 15, 0, 100, 0, 0, 0, 26307, 0, "Imprisoned Beryl Sorcerer"),
(25478, 9, 0, "Aargh!!", 15, 0, 100, 0, 0, 0, 26308, 0, "Imprisoned Beryl Sorcerer"),
(25478, 10, 0, "Stop!  Please...", 15, 0, 100, 0, 0, 0, 26309, 0, "Imprisoned Beryl Sorcerer"),
(25478, 11, 0, "Why are you here?", 15, 0, 100, 0, 0, 0, 26310, 0, "Imprisoned Beryl Sorcerer"),
(25478, 12, 0, "How can you possibly bring me lower?", 15, 0, 100, 0, 0, 0, 26311, 0, "Imprisoned Beryl Sorcerer"),
(25478, 13, 0, "What more can you take away from me?", 15, 0, 100, 0, 0, 0, 26312, 0, "Imprisoned Beryl Sorcerer"),
(25478, 14, 0, "You've got a darkness in you, $r.", 15, 0, 100, 0, 0, 0, 26313, 0, "Imprisoned Beryl Sorcerer"),
(25478, 15, 0, "You aren't even asking me questions...", 15, 0, 100, 0, 0, 0, 26314, 0, "Imprisoned Beryl Sorcerer"),
(25478, 16, 0, "Are you trying to meet the real me?", 15, 0, 100, 0, 0, 0, 26315, 0, "Imprisoned Beryl Sorcerer"),
(25478, 17, 0, "You have shown me the face of true evil, $n.", 15, 0, 100, 0, 0, 0, 26316, 0, "Imprisoned Beryl Sorcerer");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9488 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 9488, 0, 0, 0, 8, 0, 11648, 0, 0, 0, 0, 0, "", "Gossip option 0 is only available if quest 'The Art of Persuasion' is rewarded");
