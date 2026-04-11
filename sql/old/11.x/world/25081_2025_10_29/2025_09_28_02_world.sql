-- Quest
DELETE FROM `quest_greeting` WHERE (`ID`=42308 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(42308, 0, 396, 0, 'Watch your footing, rookie.', 63305); -- 42308

DELETE FROM `quest_details` WHERE `ID` IN (26257 /*It's Alive!*/, 26252 /*Heart of the Watcher*/, 26241 /*Westfall Stew*/, 26237 /*Times are Tough*/, 26236 /*Shakedown at the Saldean's*/, 26232 /*Lou's Parting Thoughts*/, 26230 /*Feast or Famine*/, 26229 /*"I TAKE Candle!"*/, 26228 /*Livin' the Life*/, 26215 /*Meet Two-Shoed Lou*/, 26214 /*Hot On the Trail: Murlocs*/, 26213 /*Hot On the Trail: The Riverpaw Clan*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26257, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- It's Alive!
(26252, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Heart of the Watcher
(26241, 1, 1, 1, 0, 0, 0, 0, 0, 63305), -- Westfall Stew
(26237, 1, 1, 5, 20, 0, 0, 0, 0, 63305), -- Times are Tough
(26236, 6, 1, 1, 0, 0, 0, 0, 0, 63305), -- Shakedown at the Saldean's
(26232, 1, 1, 1, 0, 0, 0, 0, 0, 63305), -- Lou's Parting Thoughts
(26230, 396, 396, 396, 0, 0, 0, 0, 0, 63305), -- Feast or Famine
(26229, 1, 1, 0, 0, 0, 0, 0, 0, 63305), -- "I TAKE Candle!"
(26228, 1, 1, 1, 0, 0, 0, 0, 0, 63305), -- Livin' the Life
(26215, 1, 1, 0, 0, 0, 0, 0, 0, 63305), -- Meet Two-Shoed Lou
(26214, 1, 1, 0, 0, 0, 0, 0, 0, 63305), -- Hot On the Trail: Murlocs
(26213, 1, 1, 1, 0, 0, 0, 0, 0, 63305); -- Hot On the Trail: The Riverpaw Clan

DELETE FROM `quest_request_items` WHERE `ID` IN (26229 /*"I TAKE Candle!"*/, 26228 /*Livin' the Life*/, 26257 /*It's Alive!*/, 26209 /*Murder Was The Case That They Gave Me*/, 26237 /*Times are Tough*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26229, 0, 5, 0, 0, 'I just want those kobolds dead. Dead!', 63305), -- "I TAKE Candle!"
(26228, 0, 0, 0, 0, 'Be careful with my old house. I plan to hand that off to my kids when they move out.', 63305), -- Livin' the Life
(26257, 0, 6, 0, 0, 'Did you find the golems?', 63305), -- It's Alive!
(26209, 0, 6, 0, 0, 'Anything yet?', 63305), -- Murder Was The Case That They Gave Me
(26237, 0, 0, 0, 0, 'Did you destroy the harvest watchers?', 63305); -- Times are Tough

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=396, `VerifiedBuild`=63305 WHERE `ID`=26230; -- Feast or Famine
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=63305 WHERE `ID`=26214; -- Hot On the Trail: Murlocs
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=63305 WHERE `ID`=26213; -- Hot On the Trail: The Riverpaw Clan
