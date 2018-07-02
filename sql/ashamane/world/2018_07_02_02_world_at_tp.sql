UPDATE `areatrigger` SET ScriptName = "" WHERE guid <= 32 OR guid = 38;
DELETE FROM `areatrigger` WHERE guid IN (46, 47);
INSERT INTO `areatrigger` VALUES
(46, 100007, 1669, 1,       5412.83, 10816.59, 22.501301, ""),
(47, 100007, 1753, 8388870, 5413.99, 10818.29, 20.2127,   "");

DELETE FROM `areatrigger_teleport` WHERE ID IN (45, 614, 10157, -3, -4, -7, -8, -9, -10, -15, -16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31, -32, -38, -46, -47);
INSERT INTO `areatrigger_teleport` VALUES
(45, 4078, "Scarlet Monastery 5.0 Entrance"),
(614, 4077, "Scarlet Halls 5.0 Entrance"),
(10157, 4698, "Skyreach Entrance"),
(-3,  5293, "Assault on Violet Hold Entrance"),
(-4,  5446, "Assault on Violet Hold Exit"),
(-7,  5891, "Cathedral of Eternal Night Entrance"),
(-8,  5892, "Cathedral of Eternal Night Exit"),
(-9,  5432, "Court of Stars Entrance"),
(-10, 5607, "Court of Stars Exit"),
(-15, 5098, "Hall of Valors Entrance"),
(-16, 5099, "Hall of Valors Exit"),
(-17, 5102, "Maw of Souls Entrance"),
(-18, 5123, "Maw of Souls Exit"),
(-19, 5355, "Neltharion's Lair Entrance"),
(-20, 5103, "Neltharion's Lair Exit"),
(-21, 5784, "Return to Karazhan Entrance"),
(-22, 0, "Return to Karazhan Exit"),
(-23, 5194, "The Arcway Entrance"),
(-24, 5472, "The Arcway Exit"),
(-25, 5105, "Vault of the Warden Entrance"),
(-26, 5104, "Vault of the Warden Exit"),
(-27, 5533, "Emerald Nightmare Entrance"),
(-28, 5687, "Emerald Nightmare Exit"),
(-29, 5775, "Trial of Valors Entrance"),
(-30, 5779, "Trial of Valors Exit"),
(-31, 5338, "The Nighthold Entrance"),
(-32, 5708, "The Nighthold Exit"),
(-38, 5707, "Helheim Entrance"),
(-46, 6048, "Seat of Triumvirate Entrance"),
(-47, 6112, "Seat of Triumvirate Exit");
