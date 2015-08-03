ALTER TABLE creature_classlevelstats ADD COLUMN basehp4 MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 1 AFTER basehp3;
ALTER TABLE creature_classlevelstats ADD COLUMN basehp5 MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 1 AFTER basehp4;
ALTER TABLE creature_classlevelstats ADD COLUMN damage_exp4 FLOAT NOT NULL DEFAULT 0 AFTER damage_exp3;
ALTER TABLE creature_classlevelstats ADD COLUMN damage_exp5 FLOAT NOT NULL DEFAULT 0 AFTER damage_exp4;
