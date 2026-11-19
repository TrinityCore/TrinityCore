UPDATE `game_tele` SET `name`='PlainOfThieves' WHERE `id`=1574;

UPDATE `areatrigger_teleport` SET `Name`='Jade Temple - Exit Target' WHERE `ID`=7687;
UPDATE `areatrigger_teleport` SET `Name`='Jade Temple - Entrance Target' WHERE `ID`=7854;
UPDATE `areatrigger_teleport` SET `Name`='Shadowpan Hideout - Exit Target' WHERE `ID`=7699;
UPDATE `areatrigger_teleport` SET `Name`='Shadowpan Hideout - Entrance Target' WHERE `ID`=7694;
UPDATE `areatrigger_teleport` SET `PortLocID`=4353, `Name`='Mantid Siege - Entrance Target' WHERE `ID`=8315;
UPDATE `areatrigger_teleport` SET `Name`='Mantid Siege - Exit Target' WHERE `ID`=8312;


DELETE FROM `areatrigger_teleport` WHERE `ID` IN (1468, 1470, 4352, 5530, 7838, 7999, 8001, 8027, 8314, 9245, 9302, 9303, 9681, 9680, 9964, 9965, 10022, 10023, 10097, 10098, 10104, 10124, 10205, 10232, 10237, 10241, 10242, 10244, 10272, 10273);
INSERT INTO `areatrigger_teleport` (`ID`, `PortLocID`, `Name`) VALUES
-- to be completed when these instances can be entered
-- (, 4093, 'Mogu''shan Vaults - Exit Target'),
-- (, 4145, 'Terrace of Endless Spring - Exit Target'),
-- (, 4351, 'Heart of Fear - Exit Target'),
-- (, 4573, 'Garrosh Raid - Exit Target'),
(1468, 4501, 'Upper Blackrock Spire Entrance Target'),
(5530, 3918, 'Isle of Conquest - Lighthouse Target'),
(7838, 4094, 'Mogu''shan Vaults - Entrance Target'),
(7999, 4139, 'Ring of Valor - Entrance Target'),
(8001, 4140, 'Ring of Valor - Exit Target'),
(8314, 4350, 'Heart of Fear - Entrance Target'),
(9245, 4572, 'Garrosh Raid - Entrance Target'),
(9302, 4613, 'Gold Rush BG - Pandaren Mine Catch'),
(9303, 4614, 'Gold Rush BG - Goblin Mine Catch'),
(9681, 4661, 'Bloodmaul Slave Mines - Entrance'),
(9680, 4662, 'Bloodmaul Slave Mines - Exit'),
(8027, 4144, 'Terrace of Endless Spring - Entrance Target'),
(9964, 4683, 'Auchindoun Dungeon 6.0 - Entrance'),
(9965, 4722, 'Auchindoun Dungeon 6.0 - Exit'),
(10022, 4774, 'Shadowmoon Dungeon - Exit Target (Outside)'),
(10023, 4713, 'Shadowmoon Dungeon - Entrance Target (Inside)'),
(10097, 4823, 'Iron Docks - Exit Target (Outside)'),
(10098, 4680, 'Iron Docks - Entrance Target (Inside)'),
(10104, 4831, 'Blackrock Train Depot - Exit Target - KJD'),
(10124, 3644, 'Lower Blackrock Spire Entrance Target'),
(10205, 3645, 'Blackrock Spire Exit Target (New)'),
(10232, 4831, 'Blackrock Train Depot - Exit Target - KJD'),
(10237, 4712, 'Blackrock Train Depot - Entrance Target - KJD'),
(10241, 4778, 'Foundry Raid - Graveyard - Entrance'),
(10242, 4842, 'Gorgrond - Outside Foundry'),
(10244, 4856, 'Overgrown Outpost - Entrance Target'),
(10272, 4779, 'Highmaul Raid - Instance Entrance'),
(10273, 4920, 'Lower Blackrock Spire - Exit Teleport');
