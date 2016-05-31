DELETE FROM `areatrigger_teleport` WHERE `ID` IN (8134, 7705, 7694, 7726, 8315, 7854, 8135, 7755, 7699, 7725, 8312, 7687);
INSERT INTO `areatrigger_teleport` (ID, `PortLocID`, `Name`) VALUES
-- ENTER INSTANCES
(8134, 4265, 'Mogu''shan Palace - Entrance Teleport Target'),
(7705, 4049, 'Stormstout Brewery - Entrance Target'),
(7694, 4026, 'Shadowpan Hideout - Entrance Target (Shado-Pan Monastery)'),
(7726, 4053, 'Gate of the Setting Sun - Entrance Target'),
(8315, 4269, 'Siege of Niuzao Temple - Entrance Teleport Target'),
(7854, 4024, 'Jade Temple - Entrance Target (Temple of the Jade Serpent)'),
-- EXIT INSTANCES
(8135, 4266, 'Mogu''shan Palace - Exit Teleport Target'),
(7755, 4064, 'Stormstout Brewery - Exit Target'),
(7699, 4025, 'Shadowpan Hideout - Exit Target (Shado-Pan Monastery)'),
(7725, 4054, 'Gate of the Setting Sun - Exit Target'),
(8312, 4352, 'Mantid Siege - Exit Target (Siege of Niuzao Temple)'),
(7687, 4023, 'Jade Temple - Exit Target (Temple of the Jade Serpent)');
