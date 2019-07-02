-- Fix spawn location for undead
UPDATE `playercreateinfo` SET `position_x` = 1676.349976, `position_y` = 1677.449951, `position_z` = 121.669998, `orientation` = 2.705260 WHERE `race` = 5 AND `zone`=85;
-- Fix spawn location for night elf
UPDATE `playercreateinfo` SET `position_x` = 10311.299805, `position_y` = 831.463013, `position_z` = 1326.410034, `orientation` = 5.480334 WHERE `race` = 4 AND `zone`=141;
