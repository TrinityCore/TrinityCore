-- Hordes's Honor the Flame
-- Add missing creature_quesrelation and involvedrealation that were blocking quests
DELETE FROM `game_event_creature_quest` WHERE `quest` IN (11846,11845,11852,11839,11859,11841,11851,11855,11835,11858,11863,13500,13493,13494,13495,13496,13497,13498,13499,11850,11848,11853,11857,11837,11844,11860,11584,11862,11842,11840);
INSERT INTO `game_event_creature_quest` (`eventEntry`,`id`, `quest`) VALUES
-- Flame Keeper of Eastern Kingdom? {Achievement=1025}
(1,25933, 11850), -- Ghostland
(1,25931, 11848), -- Eversong woods
(1,25935, 11853), -- Hillsbrad Foothills
(1,25941, 11857), -- Swamp of sorrows
(1,25920, 11837), -- Cape of Stranglethorn
(1,25927, 11844), -- Burning Steppes
(1,25944, 11860), -- The Hinterlands
(1,25939, 11584), -- Silverpine Forest
(1,25946, 11862), -- Tirisfal Glades
(1,25925, 11842), -- Badlands
(1,25923, 11840), -- Arathi Highlands
-- The Flame Keeper of Kalimdore - {Achievement=1026}
(1,25929, 11846), -- Durotar
(1,25928, 11845), -- Desolace
(1,25936, 11852), -- Mulgore
(1,25922, 11839), -- Winterspring
(1,25943, 11859), -- Barrens
(1,25884, 11841), -- Ashenvale
-- The Flame Keeper of Outland - {Achievement=1027}
(1,25934, 11851), -- Hellfire Peninsula
(1,25938, 11855), -- Shadowmoon Valley
(1,25918, 11835), -- Netherstorm
(1,25942, 11858), -- Terokkar
(1,25947, 11863), -- Terokkar
-- Flame Keeper of Northrend - {Achievement=6009}
(1,32816, 13500), -- Zul'Drak
(1,32809, 13493), -- Borean Tundra
(1,32810, 13494), -- Sholazar Basin
(1,32811, 13495), -- Dragonblight
(1,32815, 13499), -- Crystalsong Forest
(1,32814, 13498), -- Storm Peaks
(1,32813, 13497), -- Grizzly Hills
(1,32812, 13496); -- Howling Fjords
-- add missing quest-involved relations
DELETE FROM `creature_involvedrelation` WHERE `quest` IN (11846,11845,11852,11839,11859,11841,11851,11855,11835,11858,11863,13500,13493,13494,13495,13496,13497,13498,13499,11850,11848,11853,11857,11837,11844,11860,11584,11862,11842,11840);
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES
(25929, 11846), -- Durotar
(25928, 11845), -- Desolace
(25936, 11852), -- Mulgore
(25922, 11839), -- Winterspring
(25943, 11859), -- Barrens
(25884, 11841), -- Ashenvale
(25934, 11851), -- Hellfire Peninsula
(25938, 11855), -- Shadowmoon Valley
(25918, 11835), -- Netherstorm
(25942, 11858), -- Terokkar
(25947, 11863), -- Terokkar
(32816, 13500), -- Zul'Drak
(32809, 13493), -- Borean Tundra
(32810, 13494), -- Sholazar Basin
(32811, 13495), -- Dragonblight
(32815, 13499), -- Crystalsong Forest
(32814, 13498), -- Storm Peaks
(32813, 13497), -- Grizzly Hills
(32812, 13496), -- Howling Fjords
(25933, 11850), -- Ghostland
(25931, 11848), -- Eversong woods
(25935, 11853), -- Hillsbrad Foothills
(25941, 11857), -- Swamp of sorrows
(25920, 11837), -- Cape of Stranglethorn
(25927, 11844), -- Burning Steppes
(25944, 11860), -- The Hinterlands
(25939, 11584), -- Silverpine Forest
(25946, 11862), -- Tirisfal Glades
(25925, 11842), -- Badlands
(25923, 11840); -- Arathi Highlands
-- update quest texts and rewardcash
UPDATE `quest_template` SET `RewardOrRequiredMoney`=37000,`RewardMoneyMaxLevel`=66300, `OfferRewardText`='Honor the Durotar flame!' WHERE `Id`=11846;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Mulgore flame!' WHERE `Id`=11852;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Barrens flame!',`RewardOrRequiredMoney`=37000, `RewardMoneyMaxLevel`=66300 WHERE `Id`=11859; -- Barrens
UPDATE `quest_template` SET `OfferRewardText`='Honor the Tanaris flame!',`RequestItemsText`='' WHERE `Id`=11838 LIMIT 1;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Ashenvale flame!' WHERE `Id`=11841;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Winterspring flame!' WHERE `Id`=11839;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Desolace flame!' WHERE `Id`=11845;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Thousand Needles flame!' WHERE `Id`=11861;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Feralas flame!' WHERE `Id`=11849;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Dustwallow Marsh flame!' WHERE `Id`=11847;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Silithus flame!' WHERE `Id`=11836;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Stonetalon Mountains flame!' WHERE `Id`=11856;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Hellfire Peninsula flame!' WHERE `Id`=11851;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Shadowmoon Valley flame!' WHERE `Id`=11855;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Nagrand flame!', `RequestItemsText`='' WHERE `Id`=11821;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Netherstorm flame!' WHERE `Id`=11835;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Blades Edge Mountains flame! ', `RequestItemsText`='' WHERE `Id`=11843;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Terokkar flame!' WHERE `Id`=11858;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Zangarmarsh flame!' WHERE `Id`=11863;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Zul''Drak flame!' WHERE `Id`=13500;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Borean Tundra flame!' WHERE `Id`=13493;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Sholazar Basin flame!' WHERE `Id`=13494;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Dragonblight flame!' WHERE `Id`=13495;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Crystalsong Forest flame!' WHERE `Id`=13499;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Storm Peaks flame!' WHERE `Id`=13498;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Grizzly Hills flame!' WHERE `Id`=13497;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Howling Fjords flame!' WHERE `Id`=13496;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Ghostland flame!' WHERE `Id`=11850;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Eversong woods flame!' WHERE `Id`=11848;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Hillsbrad Foothills flame!' WHERE `Id`=11853;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Swamp of sorrows flame!' WHERE `Id`=11857;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Cape of Stranglethorn flame!' WHERE `Id`=11837;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Burning Steppes flame!' WHERE `Id`=11844;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Hinterlands flame!' WHERE `Id`=11860;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Silverpine Forest flame!' WHERE `Id`=11584;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Tirisfal Glades flame!' WHERE `Id`=11862;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Badlands flame!' WHERE `Id`=11842;
UPDATE `quest_template` SET `OfferRewardText`='Honor the Arathi Highlands flame!' WHERE `Id`=11840;
