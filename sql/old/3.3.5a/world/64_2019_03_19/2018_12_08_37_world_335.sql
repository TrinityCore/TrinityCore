-- Quest "The Grateful Dead"
DELETE FROM `quest_details` WHERE `ID` IN (13952,14166,14167,14168,14169,14170,14171,14172,14173,14174,14175,14176,14177);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(13952,1,0,0,0,0,0,0,0,0),
(14166,1,0,0,0,0,0,0,0,0),
(14167,1,0,0,0,0,0,0,0,0),
(14168,1,0,0,0,0,0,0,0,0),
(14169,1,0,0,0,0,0,0,0,0),
(14170,1,0,0,0,0,0,0,0,0),
(14171,1,0,0,0,0,0,0,0,0),
(14172,1,0,0,0,0,0,0,0,0),
(14173,1,0,0,0,0,0,0,0,0),
(14174,1,0,0,0,0,0,0,0,0),
(14175,1,0,0,0,0,0,0,0,0),
(14176,1,0,0,0,0,0,0,0,0),
(14177,1,0,0,0,0,0,0,0,0);

DELETE FROM `quest_request_items` WHERE `ID` IN (13952,14166,14167,14168,14169,14170,14171,14172,14173,14174,14175,14176,14177);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(13952,6,6,"You don't have any Bread of the Dead, do you?",0),
(14166,6,6,"You don't have any Bread of the Dead, do you?",0),
(14167,6,6,"You don't have any Bread of the Dead, do you?",0),
(14168,6,6,"You don't have any Bread of the Dead, do you?",0),
(14169,6,6,"You don't have any Bread of the Dead, do you?",0),
(14170,6,6,"You don't have any Bread of the Dead, do you?",0),
(14171,6,6,"You don't have any Bread of the Dead, do you?",0),
(14172,6,6,"You don't have any Bread of the Dead, do you?",0),
(14173,6,6,"You don't have any Bread of the Dead, do you?",0),
(14174,6,6,"You don't have any Bread of the Dead, do you?",0),
(14175,6,6,"You don't have any Bread of the Dead, do you?",0),
(14176,6,6,"You don't have any Bread of the Dead, do you?",0),
(14177,6,6,"You don't have any Bread of the Dead, do you?",0);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (13952,14166,14167,14168,14169,14170,14171,14172,14173,14174,14175,14176,14177);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(13952,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14166,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14167,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14168,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14169,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14170,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14171,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14172,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14173,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14174,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14175,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14176,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0),
(14177,2,0,0,0,0,0,0,0,"Ah, more delicious Bread of the Dead, thank you!$B$BPlease, take this in return... a little something fun for the holiday.",0);
