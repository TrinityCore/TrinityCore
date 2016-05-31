-- Mists of Pandaria: Dungeons.
DELETE FROM `instance_template` WHERE `map` IN (959, 960, 961, 962, 994, 1011);
INSERT INTO `instance_template` (`map`, `parent`, `allowMount`) VALUES
(959, 870, 1), -- Shado-Pan Monastery, AllowMount=True
(960, 870, 0), -- Temple of the Jade Serpent, AllowMount=False
(961, 870, 0), -- Stormstout Brewery, AllowMount=False
(962, 870, 0), -- Gate of the Setting Sun, AllowMount=False
(994, 870, 0), -- Mogushan Palace, AllowMount=False
(1011, 870, 1); -- Siege of Niuzao Temple, AllowMount=True

-- Warlords of Draenor: Dungeons.
DELETE FROM `instance_template` WHERE `map` IN (1175, 1176, 1182, 1195, 1208, 1209, 1279, 1358);
INSERT INTO `instance_template` (`map`, `parent`, `allowMount`) VALUES
(1175, 0, 0), -- Bloodmaul Slag Mines, AllowMount=False
(1176, 0, 0), -- Shadowmoon Burial Grounds, AllowMount=False
(1182, 0, 0), -- Auchindoun, AllowMount=False
(1195, 0, 1), -- Iron Docks, AllowMount=True
(1208, 0, 0), -- Grimrail Depot, AllowMount=False
(1209, 0, 0), -- Skyreach, AllowMount=False
(1279, 0, 1), -- The Everbloom, AllowMount=True
(1358, 0, 0); -- Upper Blackrock Spire, AllowMount=False

-- Warlords of Draenor: Raids.
DELETE FROM `instance_template` WHERE `map`IN (1228, 1205);
INSERT INTO `instance_template` (`map`, `parent`, `allowMount`) VALUES
(1228, 0, 1), -- Highmaul, AllowMount=True
(1205, 0, 0); -- Blackrock Foundry, AllowMount=False
