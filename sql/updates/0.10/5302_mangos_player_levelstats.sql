ALTER TABLE player_levelstats
  ADD COLUMN basehp smallint(5) unsigned NOT NULL AFTER level,
  ADD COLUMN basemana smallint(5) unsigned NOT NULL AFTER basehp;

UPDATE player_levelstats SET basehp = hp - sta               WHERE sta <= 20;
UPDATE player_levelstats SET basehp = hp - 20 - (sta-20)*10  WHERE sta >  20;

UPDATE player_levelstats SET basemana = mana - inte              WHERE mana > 0 and inte <= 20;
UPDATE player_levelstats SET basemana = mana - 20 - (inte-20)*15 WHERE mana > 0 and inte >  20;

ALTER TABLE player_levelstats
  DROP COLUMN hp,
  DROP COLUMN mana;
