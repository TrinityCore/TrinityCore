ALTER TABLE creature_classlevelstats ADD attackpower SMALLINT(6) DEFAULT 0 NOT NULL;
ALTER TABLE creature_classlevelstats ADD rangedattackpower SMALLINT(6) DEFAULT 0 NOT NULL;
ALTER TABLE creature_classlevelstats ADD damage_base FLOAT DEFAULT 0 NOT NULL;
ALTER TABLE creature_classlevelstats ADD damage_exp1 FLOAT DEFAULT 0 NOT NULL;
ALTER TABLE creature_classlevelstats ADD damage_exp2 FLOAT DEFAULT 0 NOT NULL;
ALTER TABLE creature_classlevelstats ADD `comment` BLOB;
