--
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=13665; -- The Grand Melee
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=13847; -- At The Enemy's Gates
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1 WHERE `ID`=13592; -- A Valiant's Field Training
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=13836; -- Disarmed!
UPDATE `quest_offer_reward` SET `Emote1`=396 WHERE `ID`=13127; -- Mage-Lord Urom
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396 WHERE `ID`=13126; -- A Unified Front
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396 WHERE `ID`=13124; -- The Struggle Persists
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6604; -- Enraged Wildkin
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=5085; -- [DEPRECATED]Mystery Goo
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5082; -- [DEPRECATED]Threat of the Winterfall
UPDATE `quest_offer_reward` SET `Emote1`=11 WHERE `ID`=4041; -- The Videre Elixir
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11, `Emote3`=5, `EmoteDelay2`=200 WHERE `ID`=4144; -- Bloodpetal Sprouts
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4143; -- Haze of Evil
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=9562; -- Murlocs... Why Here? Why Now?
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=9513; -- Reclaiming the Ruins
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=9512; -- Cookie's Jumbo Gumbo
UPDATE `quest_offer_reward` SET `Emote3`=15 WHERE `ID`=9544; -- The Prophecy of Akida

UPDATE `quest_request_items` SET `EmoteOnComplete`=11 WHERE `ID`=24431; -- Waterlogged Recipe
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=13836; -- Disarmed!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5085; -- [DEPRECATED]Mystery Goo
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=8467; -- [DEPRECATED]Feathers for Nafien
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3909; -- The Videre Elixir
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=8467; -- [DEPRECATED]Feathers for Nafien
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4041; -- The Videre Elixir
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4041; -- The Videre Elixir
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4041; -- The Videre Elixir
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=4144; -- Bloodpetal Sprouts
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=4144; -- Bloodpetal Sprouts
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4143; -- Haze of Evil
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3373; -- The Essence of Eranikus
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9564; -- Gurf's Dignity
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9562; -- Murlocs... Why Here? Why Now?
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9560; -- Beasts of the Apocalypse!

DELETE FROM `quest_poi` WHERE (`QuestID`=13836 AND `id`=1);
INSERT INTO `quest_poi` (`QuestID`, `id`, `ObjectiveIndex`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `VerifiedBuild`) VALUES
(13836, 1, 4, 571, 504, 1, 0, 7, 12340); -- Disarmed!
DELETE FROM `quest_poi` WHERE (`id`=1 AND `QuestID` IN (2928,1050));
INSERT INTO `quest_poi` (`QuestID`, `id`, `ObjectiveIndex`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `VerifiedBuild`) VALUES
(2928, 1, 4, 0, 27, 0, 0, 7, 12340), -- Gyrodrillmatic Excavationators
(1050, 1, 4, 0, 20, 0, 0, 7, 12340); -- Mythology of the Titans

UPDATE `quest_poi` SET `WorldMapAreaId`=504, `Floor`=1, `Flags`=3, `VerifiedBuild`=12340 WHERE (`QuestID`=13836 AND `id`=0); -- Disarmed!
UPDATE `quest_poi` SET `WorldMapAreaId`=301, `Flags`=3, `VerifiedBuild`=12340 WHERE (`QuestID`=2928 AND `id`=0); -- Gyrodrillmatic Excavationators
UPDATE `quest_poi` SET `WorldMapAreaId`=341, `Flags`=7, `VerifiedBuild`=12340 WHERE (`QuestID`=2922 AND `id`=1); -- Save Techbot's Brain!
UPDATE `quest_poi` SET `Flags`=7, `VerifiedBuild`=12340 WHERE (`QuestID`=1050 AND `id`=0); -- Mythology of the Titans
UPDATE `quest_poi` SET `Priority`=1, `VerifiedBuild`=12340 WHERE (`QuestID`=3909 AND `id`=3); -- The Videre Elixir
UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE (`QuestID`=3909 AND `id`=1); -- The Videre Elixir
UPDATE `quest_poi` SET `Priority`=1, `VerifiedBuild`=12340 WHERE (`QuestID`=9544 AND `id`=1); -- The Prophecy of Akida
UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE (`QuestID`=9544 AND `id`=0); -- The Prophecy of Akida

DELETE FROM `quest_poi_points` WHERE (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=13836 AND `Idx1`=1 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(13836, 1, 11, 5716, 475, 12340), -- Disarmed!
(13836, 1, 10, 5665, 513, 12340), -- Disarmed!
(13836, 1, 9, 5660, 525, 12340), -- Disarmed!
(13836, 1, 8, 5660, 546, 12340), -- Disarmed!
(13836, 1, 7, 5683, 575, 12340), -- Disarmed!
(13836, 1, 6, 5700, 566, 12340), -- Disarmed!
(13836, 1, 5, 5722, 551, 12340), -- Disarmed!
(13836, 1, 4, 5744, 534, 12340), -- Disarmed!
(13836, 1, 3, 5762, 513, 12340), -- Disarmed!
(13836, 1, 2, 5765, 493, 12340), -- Disarmed!
(13836, 1, 1, 5745, 473, 12340), -- Disarmed!
(13836, 1, 0, 5727, 473, 12340); -- Disarmed!
DELETE FROM `quest_poi_points` WHERE (`QuestID`=2928 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=1050 AND `Idx1`=1 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(2928, 1, 0, -5164, 576, 12340), -- Gyrodrillmatic Excavationators
(1050, 1, 0, 2816, -784, 12340); -- Mythology of the Titans
