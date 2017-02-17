-- Every gnome should start with Irradiated Aura
DELETE FROM playercreateinfo_cast_spell WHERE raceMask=64;
INSERT INTO playercreateinfo_cast_spell VALUES
(64,1,80653,'Warrior - Gnome - Irradiated Aura'),
(64,8,80653,'Rogue - Gnome - Irradiated Aura'),
(64,16,80653,'Priest - Gnome - Irradiated Aura'),
(64,128,80653,'Mage - Gnome - Irradiated Aura'),
(64,256,80653,'Warlock - Gnome - Irradiated Aura');
--
