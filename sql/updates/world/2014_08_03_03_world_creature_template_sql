-- Update creature_template damage
ALTER TABLE creature_template CHANGE dmg_multiplier Damage_mod FLOAT NOT NULL DEFAULT 1 AFTER Mana_mod;
ALTER TABLE creature_template ADD Experience_mod FLOAT NOT NULL DEFAULT 1 AFTER Damage_mod;
ALTER TABLE creature_template CHANGE baseattacktime Base_attacktime int(10) NOT NULL DEFAULT 0;
ALTER TABLE creature_template CHANGE rangeattacktime Range_attacktime int(10) NOT NULL DEFAULT 0;
ALTER TABLE creature_template ADD Base_variance FLOAT NOT NULL DEFAULT 0 AFTER Base_attacktime;
ALTER TABLE creature_template ADD Range_variance FLOAT NOT NULL DEFAULT 0 AFTER Range_attacktime;

ALTER TABLE creature_template DROP COLUMN mindmg;
ALTER TABLE creature_template DROP COLUMN maxdmg;
ALTER TABLE creature_template DROP COLUMN attackpower;
ALTER TABLE creature_template DROP COLUMN minrangedmg;
ALTER TABLE creature_template DROP COLUMN maxrangedmg;
ALTER TABLE creature_template DROP COLUMN rangedattackpower;
