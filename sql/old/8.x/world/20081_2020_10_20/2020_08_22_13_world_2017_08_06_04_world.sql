-- DB/Quest: You, Robot (quest ID 10248): missing Progress text + end of RewardText
DELETE FROM `quest_request_items` WHERE `ID`=10248;
INSERT INTO `quest_request_items` (`ID`,`EmoteOnComplete`,`EmoteOnIncomplete`,`CompletionText`,`VerifiedBuild`) VALUES
(10248, 1, 0, 'What did you think?  Still needs some tweaking, eh?', 12340);

UPDATE `quest_offer_reward`
 SET `RewardText`="Well, my boy that certainly was exciting! And for my money, I'd say that the Scrap Reaver X6000 performed admirably, despite its rookie pilot.$B$BHehe, no, don't take offense, I was just kidding.  After all, you just saved Area 52 and the X-52 Nether-Rocket from certain doom!"
 WHERE `Id`=10248;
