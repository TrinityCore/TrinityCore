-- Spawn Elder Ohanzee in Normal and Heroic modes of Gundrak and relocate near Drakkari Colossus (45.7,62) boss (v3.3.2 change). Coordinates are guessed based on https://www.youtube.com/watch?v=FRXgZthksN8 ( ~12min )
UPDATE `creature` SET `spawnMask`=3,`position_x`=1697.94,`position_y`=752.121,`position_z`=142.765,`orientation`=3.78933 WHERE `guid`=200841;
-- Spawn Elder Kilias in Normal and Heroic modes of Drak'Tharon Keep
UPDATE `creature` SET `spawnMask`=3 WHERE `guid`=200842;
-- Spawn Elder Nurgen in Normal and Heroic modes of Azjol-Nerub
UPDATE `creature` SET `spawnMask`=3 WHERE `guid`=200843;
-- Spawn Elder Yurauk in Normal and Heroic modes of Halls of Stone
UPDATE `creature` SET `spawnMask`=3 WHERE `guid`=200844;
-- Spawn Elder Jarten in Normal and Heroic modes of Utgarde Keep
UPDATE `creature` SET `spawnMask`=3 WHERE `guid`=200845;
-- Spawn Elder Chogan'gada in Normal and Heroic modes of Utgarde Pinnacle
UPDATE `creature` SET `spawnMask`=3 WHERE `guid`=200846;
-- Spawn Elder Igasho in Normal and Heroic modes of The Nexus
UPDATE `creature` SET `spawnMask`=3 WHERE `guid`=200847;
