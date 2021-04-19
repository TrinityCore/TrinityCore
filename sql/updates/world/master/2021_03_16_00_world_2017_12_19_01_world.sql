--
UPDATE `creature` SET `spawnDifficulties`='1,2' WHERE `id` IN (18956,19511);
UPDATE `smart_scripts` SET `event_flags`=7 WHERE `entryorguid` IN (18956) AND `source_type`=0;
UPDATE `smart_scripts` SET `event_flags`=7 WHERE `entryorguid` IN (1895600) AND `source_type`=9;
UPDATE `gameobject` SET `spawnDifficulties`='1,2' WHERE `spawnDifficulties` = '1' AND `id` IN (181278,181556,181557,181569,183051,182940,186633,185434,181275,184931,181276,181270,184956,184940,183296,183516,182942,182943,183036,183295,184941,183441) AND `map` NOT IN (530,548,568,571); 
