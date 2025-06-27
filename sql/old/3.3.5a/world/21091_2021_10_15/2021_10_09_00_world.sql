-- Stormwind graveyard for the Alliance
UPDATE `graveyard_zone` SET `ID`=106, `Comment`='Elwynn Forest, Goldshire - Stormwind' WHERE `ID`=107 AND `GhostZone`=1519;
-- Champions' Hall is no longer a separate zone
DELETE FROM `graveyard_zone` WHERE `ID`=107 AND `GhostZone`=2918;
