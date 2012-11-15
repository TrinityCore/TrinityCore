


UPDATE creature_template SET InhabitType=7 WHERE name LIKE '%flying%'; 

UPDATE `creature_template` SET `InhabitType`=7 WHERE  `entry` in (16168, 3869, 16446, 17906, 24440, 24624, 26491, 26517, 27829, 28749, 29239, 28874, 121212, 8534, 29576, 37544, 38481, 31040, 37920, 37187, 36725, 38004, 37970, 38454, 37955, 37126, 36789, 37970, 37972, 37973, 36678);

UPDATE `creature_template` SET `npcflag`=1 WHERE  `entry`=37187;