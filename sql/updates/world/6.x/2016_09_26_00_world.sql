-- Changing subzone 6170 (Northshire, Elwynn). Was zone 12 before, not right.
-- Part of my total fix for graveyard problems (https://github.com/TrinityCore/TrinityCore/issues/14089)
UPDATE graveyard_zone SET GhostZone=6170 WHERE ID=105 AND Faction=469;
