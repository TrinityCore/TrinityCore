-- 
UPDATE `quest_template_addon` SET `ExclusiveGroup`=8747 WHERE `Id` IN (8747, 8752, 8757);

UPDATE `quest_template_addon` SET `PrevQuestId`=0, `SpecialFlags`=1 WHERE `Id` IN (8764, 8765, 8766);

DELETE FROM `conditions` WHERE `SourceEntry` IN (8764, 8765, 8766);
INSERT INTO `conditions` VALUES
(19, 0, 8764, 0, 0, 2, 0, 21200, 1, 1, 0, 0, 0, "", "Quest 8764 is available only if player has item 21200 in bags or bank"),
(20, 0, 8764, 0, 0, 2, 0, 21200, 1, 1, 0, 0, 0, "", "Show question mark for quest 8764 only if player has item 21200 in bags or bank"),

(19, 0, 8765, 0, 0, 2, 0, 21210, 1, 1, 0, 0, 0, "", "Quest 8765 is available only if player has item 21210 in bags or bank"),
(20, 0, 8765, 0, 0, 2, 0, 21210, 1, 1, 0, 0, 0, "", "Show question mark for quest 8765 only if player has item 21210 in bags or bank"),

(19, 0, 8766, 0, 0, 2, 0, 21205, 1, 1, 0, 0, 0, "", "Quest 8766 is available only if player has item 21205 in bags or bank"),
(20, 0, 8766, 0, 0, 2, 0, 21205, 1, 1, 0, 0, 0, "", "Show question mark for quest 8766 only if player has item 21205 in bags or bank");

DELETE FROM `quest_offer_reward` WHERE `ID` IN (8747, 8752, 8757);
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
(8747,1,0,0,0,0,0,0,0,(SELECT `CompletionText` FROM `quest_request_items` WHERE `ID`=8747),12340),
(8752,1,0,0,0,0,0,0,0,(SELECT `CompletionText` FROM `quest_request_items` WHERE `ID`=8752),12340),
(8757,1,0,0,0,0,0,0,0,(SELECT `CompletionText` FROM `quest_request_items` WHERE `ID`=8757),12340);

UPDATE `quest_request_items` SET `CompletionText` = "Never have I seen such tenacity! The Bronze Flight grants you one final enchantment. The Timeless One himself has requested it so!$B$BHand me your signet ring so that I may make the necessary adjustments." WHERE `ID` IN (8751, 8756, 8761);
