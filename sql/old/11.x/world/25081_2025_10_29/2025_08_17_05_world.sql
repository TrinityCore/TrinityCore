DELETE FROM `quest_offer_reward` WHERE `ID`=90779;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(90779, 1, 0, 0, 0, 0, 0, 0, 0, 'Tales of your own accomplishments mingle into the chorus of echoes emanating from the now repaired stone.', 62493); -- 90779

DELETE FROM `achievement_reward` WHERE `ID`=41886;
INSERT INTO `achievement_reward` (`ID`,`TitleA`,`TitleH`,`ItemID`,`Sender`,`Subject`,`Body`,`MailTemplateID`) VALUES
(41886,0,0,219226,219226,'Ethereal Crest Analysis','My friend!\r\n\r\nCuzolth and I have cracked the mystery of the Ethereal Crests! It took time, effort, and no small amount of arcane tinkering, but we''ve finally done it!\r\n\r\nI should be able to transmute your Weathered Ethereal Crests into Carved Ethereal Crests now. Make haste and meet me in Dornogal at once!\r\n\r\nYour friend,\r\nVaskarn',0);
