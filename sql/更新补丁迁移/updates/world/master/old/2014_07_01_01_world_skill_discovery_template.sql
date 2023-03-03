-- Lightning Steel Ignot
DELETE FROM `skill_discovery_template` WHERE `reqSpell` = 138646;
INSERT INTO `skill_discovery_template` (`spellId`, `reqSpell`, `reqSkillValue`, `chance`) VALUES
(137772, 138646, 600, 100), 
(137773, 138646, 600, 100), 
(137774, 138646, 600, 100), 
(137775, 138646, 600, 100), 
(137776, 138646, 600, 100), 
(137777, 138646, 600, 100), 
(137778, 138646, 600, 100), 
(137779, 138646, 600, 100), 
(137780, 138646, 600, 100), 
(137781, 138646, 600, 100), 
(137782, 138646, 600, 100), 
(137783, 138646, 600, 100), 
(137784, 138646, 600, 100), 
(137785, 138646, 600, 100), 
(137786, 138646, 600, 100), 
(137787, 138646, 600, 100), 
(137788, 138646, 600, 100), 
(137789, 138646, 600, 100), 
(137790, 138646, 600, 100), 
(137791, 138646, 600, 100), 
(137792, 138646, 600, 100), 
(137793, 138646, 600, 100), 
(137794, 138646, 600, 100), 
(137795, 138646, 600, 100), 
(137796, 138646, 600, 100), 
(137797, 138646, 600, 100), 
(140841, 138646, 600, 100), 
(140842, 138646, 600, 100), 
(140843, 138646, 600, 100), 
(140844, 138646, 600, 100), 
(140845, 138646, 600, 100), 
(140846, 138646, 600, 100), 
(137766, 138646, 600, 100), 
(137767, 138646, 600, 100), 
(137768, 138646, 600, 100), 
(137769, 138646, 600, 100), 
(137770, 138646, 600, 100), 
(137771, 138646, 600, 100);

DELETE FROM `skill_discovery_template` WHERE `reqSpell` IN
(138882, 138885, 138888, 138890, 138889, 138891, 138877, 138879, 138876, 138878, 138883, 138884);
INSERT INTO `skill_discovery_template` (`spellId`, `reqSpell`, `reqSkillValue`, `chance`) VALUES
-- Drakefist Hammer, Reborn -> Dragonmaw, Reborn
(138885, 138882, 600, 100),
-- Dragonmaw, Reborn -> Dragonstrike, Reborn
(138886, 138885, 600, 100),
-- Fireguard, Reborn -> Blazeguard, Reborn
(138890, 138888, 600, 100),
-- Blazeguard, Reborn -> Blazefury, Reborn
(138892, 138890, 600, 100),
-- Lionheart Blade, Reborn -> Lionheart Champion, Reborn
(138891, 138889, 600, 100),
-- Lionheart Champion, Reborn -> Lionheart Executioner, Reborn
(138893, 138891, 600, 100),
-- Lunar Crescent, Reborn -> Mooncleaver, Reborn
(138879, 138877, 600, 100),
-- Mooncleaver, Reborn -> Bloodmoon, Reborn
(138881, 138879, 600, 100),
-- The Planar Edge, Reborn -> Black Planar Edge, Reborn
(138878, 138876, 600, 100),
-- Black Planar Edge, Reborn -> Wicked Edge of the Planes, Reborn
(138880, 138878, 600, 100),
-- Thunder, Reborn -> Deep Thunder, Reborn
(138884, 138883, 600, 100),
-- Deep Thunder, Reborn -> Stormherald, Reborn
(138887, 138884, 600, 100);
