-- Add Utgarde GY for Howling Fjord Area for both factions
DELETE FROM `graveyard_zone` WHERE `ID` IN (1337,1376) AND `GhostZone`=495;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(1337, 495, "Howling Fjord, Utgarde GY - Howling Fjord"),
(1376, 495, "Howling Fjord, Utgarde 2 GY - Howling Fjord");
