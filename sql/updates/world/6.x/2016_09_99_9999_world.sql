-- Changing subzone 6451 (Durotar, Valley of Trials GY - Durotar). Was zone 14 before, not right.
-- Part of my total fix for graveyard problems (https://github.com/TrinityCore/TrinityCore/issues/14089)
UPDATE `graveyard_zone` SET `GhostZone`= 6170 WHERE `ID`= 709 AND `Faction`= 67;
