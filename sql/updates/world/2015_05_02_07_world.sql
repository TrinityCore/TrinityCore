UPDATE `game_tele` SET `name`='PlainOfThieves' WHERE `id`=1574;

UPDATE `areatrigger_teleport` SET `Name`='Temple of the Jade Serpent - Exit Target' WHERE `ID`=7687;
UPDATE `areatrigger_teleport` SET `Name`='Temple of the Jade Serpent - Entrance Target' WHERE `ID`=7854;
UPDATE `areatrigger_teleport` SET `Name`='Shado-Pan Monestary - Exit Target' WHERE `ID`=7699;
UPDATE `areatrigger_teleport` SET `Name`='Shado-Pan Monestary - Entrance Target' WHERE `ID`=7694;
UPDATE `areatrigger_teleport` SET `PortLocID`=4353, `Name`='Siege of Niuzao Temple - Entrance Target' WHERE `ID`=8315;
UPDATE `areatrigger_teleport` SET `Name`='Siege of Niuzao Temple - Exit Target' WHERE `ID`=8312;


DELETE FROM `areatrigger_teleport` WHERE `ID` IN (1468, 1470, 4352, 5530, 7838, 7999, 8001, 8027, 8314, 9245, 9302, 9303, 9681, 9680, 9964, 9965, 10022, 10023, 10097, 10098, 10104, 10124, 10205, 10232, 10237, 10241, 10242, 10244, 10272, 10273);
INSERT INTO `areatrigger_teleport` (`ID`, `PortLocID`, `Name`) VALUES
-- to be completed when these instances can be entered
-- (, 4093, 'Mogu''shan Vaults - Exit Target'),
-- (, 4145, 'Terrace of Endless Spring - Exit Target'),
-- (, 4351, 'Heart of Fear - Exit Target'),
-- (, 4573, 'Siege of Orgrimmar - Exit Target'),
(1468, 4501, 'Upper Blackrock Spire Entrance Target'),
(5530, 3918, 'Isle of Conquest - Lighthouse Target'),
(7838, 4094, 'Mogu''shan Vaults - Entrance Target'),
(7999, 4139, 'Ring of Valor - Entrance Target'),
(8001, 4140, 'Ring of Valor - Exit Target'),
(8314, 4350, 'Heart of Fear - Entrance Target'),
(9245, 4572, 'Siege of Orgrimmar - Entrance Target'),
(9302, 4613, 'Deepwind Gorge - Pandaren Mine Catch'),
(9303, 4614, 'Deepwind Gorge - Goblin Mine Catch'),
(9681, 4661, 'Bloodmaul Slag Mines - Entrance'),
(9680, 4662, 'Bloodmaul Slag Mines - Exit'),
(8027, 4144, 'Terrace of Endless Spring - Entrance Target'),
(9964, 4683, 'Auchindoun Dungeon 6.0 - Entrance'),
(9965, 4722, 'Auchindoun Dungeon 6.0 - Exit'),
(10022, 4774, 'Shadowmoon Burial Grounds - Exit Target (Outside)'),
(10023, 4713, 'Shadowmoon Burial Grounds - Entrance Target (Inside)'),
(10097, 4823, 'Iron Docks - Exit Target (Outside)'),
(10098, 4680, 'Iron Docks - Entrance Target (Inside)'),
(10104, 4831, 'Grimrail Depot - Exit Target - KJD'),
(10124, 3644, 'Lower Blackrock Spire Entrance Target'),
(10205, 3645, 'Blackrock Spire Exit Target (New)'),
(10232, 4831, 'Grimrail Depot - Exit Target - KJD'),
(10237, 4712, 'Grimrail Depot - Entrance Target - KJD'),
(10241, 4778, 'Blackrock Foundry Raid - Graveyard - Entrance'),
(10242, 4842, 'Gorgrond - Outside Blackrock Foundry'),
(10244, 4856, 'The Everbloom - Entrance Target'),
(10272, 4779, 'Highmaul Raid - Instance Entrance'),
(10273, 4920, 'Lower Blackrock Spire - Exit Teleport');
