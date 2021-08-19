-- Delete the following spells from the trainer: Artisan Riding, Cold Weather Flying, Flight Masters License
DELETE FROM `trainer_spell` WHERE `SpellId` IN (34093, 54198, 90269);

-- Apprentice riding skill
UPDATE `trainer_spell` SET `MoneyCost` = 10000, `ReqLevel` = 10 WHERE `SpellId` = 33389;

-- Journeyman riding skill
UPDATE `trainer_spell` SET `MoneyCost` = 500000, `ReqLevel` = 20 WHERE `SpellId` = 33392;

-- Expert riding skill 
UPDATE `trainer_spell` SET `MoneyCost` = 2500000, `ReqLevel` = 30 WHERE `SpellId` = 34092;

-- Master riding skill 
UPDATE `trainer_spell` SET `MoneyCost` = 50000000, `ReqLevel` = 40, `ReqAbility1` = 34090 WHERE `SpellId` = 90266;
