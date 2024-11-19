-- https://www.wowhead.com/wotlk/quest=467/stonegears-search
-- 2nd Questgiver for "Stonegear's Search" (Pilot Longbeard)
DELETE FROM `creature_queststarter` WHERE `id` = 2092 AND `quest` = 467;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (2092, 467);

-- https://www.wowhead.com/wotlk/quest=1698/yorus-barleybrew
-- 2nd Questgiver for "Yorus Barleybrew" (Darnath Bladesinger)
DELETE FROM `creature_queststarter` WHERE `id` = 7315 AND `quest` = 1698;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (7315, 1698);

-- https://www.wowhead.com/wotlk/quest=1684/elanaria
-- 3rd Questgiver for "Elanaria" (Sentinel Elissa Starbreeze)
DELETE FROM `creature_queststarter` WHERE `id` = 3657 AND `quest` = 1684;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (3657, 1684);
