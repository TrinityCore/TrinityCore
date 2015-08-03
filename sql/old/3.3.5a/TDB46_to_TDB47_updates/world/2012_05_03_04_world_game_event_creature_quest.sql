DELETE FROM `creature_questrelation` WHERE `id` IN (14305,14444,22817,22818,33532,33533,34365);
DELETE FROM `game_event_creature_quest` WHERE `eventEntry`=10;
INSERT INTO `game_event_creature_quest` (`eventEntry`,`id`,`quest`) VALUES
-- Alliance
(10,14450,1468), -- Orphan Matron Nightingale - Children's Week
(10,14305,1479), -- Human Orphan - The Bough of the Eternals
(10,14305,1558), -- Human Orphan - The Stonewrought Dam
(10,14305,1687), -- Human Orphan - Spooky Lighthouse
(10,14305,558), -- Human Orphan - Jaina's Autograph
(10,14305,4822), -- Human Orphan - You Scream, I Scream...
-- Horde
(10,14451,172), -- Orphan Matron Battlewail - Children's Week
(10,14444,910), -- Orcish Orphan - Down at the Docks
(10,14444,911), -- Orcish Orphan - Gateway to the Frontier
(10,14444,1800), -- Orcish Orphan - Lordaeron Throne Room
(10,14444,915), -- Orcish Orphan - You Scream, I Scream...
(10,14444,925), -- Orcish Orphan - Cairne's Hoofprint
(10,14444,5502), -- Orcish Orphan - A Warden of the Horde
-- Outlands: Blood Elfs
(10,22819,10942), -- Orphan Matron Mercy - Children's Week
(10,22817,10945), -- Blood Elf Orphan - Hch'uu and the Mushroom People
(10,22817,10951), -- Blood Elf Orphan - A Trip to the Dark Portal
(10,22817,10953), -- Blood Elf Orphan - Visit the Throne of the Elements
(10,22817,11975), -- Blood Elf Orphan - Now, When I Grow Up...
(10,22817,10963), -- Blood Elf Orphan - Time to Visit the Caverns
(10,22817,10967), -- Blood Elf Orphan - Back to the Orphanage
-- Outlands: Draenei
(10,22819,10943), -- Orphan Matron Mercy - Children's Week
(10,22818,10950), -- Draenei Orphan - Auchindoun and the Ring of Observance
(10,22818,10952), -- Draenei Orphan - A Trip to the Dark Portal
(10,22818,10954), -- Draenei Orphan - Jheel is at Aeris Landing!
(10,22818,10956), -- Draenei Orphan - The Seat of the Naaru
(10,22818,10962), -- Draenei Orphan - Time to Visit the Caverns
(10,22818,10966), -- Draenei Orphan - Back to the Orphanage
-- Northrend: Wolvar
(10,34365,13927), -- Orphan Matron Aria - Little Orphan Kekek Of The Wolvar
(10,33532,13930), -- Wolvar Orphan - Home Of The Bear-Men
(10,33532,13934), -- Wolvar Orphan - The Bronze Dragonshrine
(10,33532,13951), -- Wolvar Orphan - Playmates!
(10,33532,13955), -- Wolvar Orphan - The Dragon Queen
(10,33532,13957), -- Wolvar Orphan - The Mighty Hemet Nesingwary
(10,33532,13960), -- Wolvar Orphan - Back To The Orphanage
-- Northrend: Oracles
(10,34365,13926), -- Orphan Matron Aria - Little Orphan Roo Of The Oracles
(10,33533,13929), -- Oracle Orphan - The Biggest Tree Ever!
(10,33533,13933), -- Oracle Orphan - The Bronze Dragonshrine
(10,33533,13937), -- Oracle Orphan - A Trip To The Wonderworks
(10,33533,13950), -- Oracle Orphan - Playmates!
(10,33533,13954), -- Oracle Orphan - The Dragon Queen
(10,33533,13956), -- Oracle Orphan - Meeting a Great One
(10,33533,13959); -- Oracle Orphan - Back To The Orphanage

-- Removed "When I Grow Up..." and replace it with "Now, When I Grow Up..."
UPDATE `quest_template` SET `prevquestid`=10945,`exclusivegroup`=-11975 WHERE `id` IN (11975,10963);
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=10960;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,10960,0,'','','Deprecated quest: When I grow up...');
