


UPDATE creature_template SET InhabitType=7 WHERE name LIKE '%flying%'; 

UPDATE `creature_template` SET `InhabitType`=7 WHERE  `entry` in (16168, 3869, 16446, 17906, 24440, 24624, 26491, 26517, 27829, 28749, 29239, 28874, 121212, 8534, 29576, 37544, 38481, 31040);

UPDATE `creature_template` SET `npcflag`=1, `InhabitType`=7 WHERE  `entry`=37187;