DELETE FROM `quest_greeting` WHERE `ID` in (2993,2988);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(2993,0,0,0,"The land has been good to our people, $c. We must be thankful for our good fortune.",0), -- Baine Bloodhoof
(2988,0,0,0,"The Outrunners' duty is to ensure the safety of those who travel across the plains of Mulgore. Those that would threaten the safety of the tauren homeland risk punishment at our hands.",0); -- Morin Cloudstalker
