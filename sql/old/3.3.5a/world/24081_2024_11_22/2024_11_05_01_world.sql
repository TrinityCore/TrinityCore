-- Portal: Darnassus AND Portal: Thunder Bluff required lvl 50
UPDATE `trainer_spell` SET `ReqLevel`=50 WHERE `SpellID` IN (11419,11420);

-- Teleport: Darnassus AND Teleport: Thunder Bluff required lvl 30
UPDATE `trainer_spell` SET `ReqLevel`=30 WHERE `SpellID` IN (3565,3566);
