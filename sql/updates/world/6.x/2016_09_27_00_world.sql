-- Changing subzone 6170 (Northshire, Elwynn). Was zone 12 before.
UPDATE `graveyard_zone` SET `GhostZone`= 6170 WHERE `ID`= 105 AND `Faction`= 469;
-- Changing subzone 6451 (Durotar, Valley of Trials GY - Durotar). Was zone 14 before.
UPDATE `graveyard_zone` SET `GhostZone`= 6145 WHERE `ID`= 709 AND `Faction`= 67;
