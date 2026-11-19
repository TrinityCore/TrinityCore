-- Human
UPDATE `playercreateinfo` SET `orientation` = 5.1044426 WHERE `race` = 1 AND `class` != 6;

-- Dwarf
UPDATE `playercreateinfo` SET `zone` = 132, `orientation` = 0.501087 WHERE `race` = 3 AND `class` != 6;

-- Night Elf
UPDATE `playercreateinfo` SET `zone` = 188, `orientation` = 5.48033 WHERE `race` = 4 AND `class` NOT IN (6, 12);

-- Orc
UPDATE `playercreateinfo` SET `zone` = 363, `orientation` = 0 WHERE `race` = 2 AND `class` != 6;

-- Pandaren
UPDATE `playercreateinfo` SET `orientation` = 2.879619 WHERE `race` = 24 AND `class` != 6;

-- Death Knight
UPDATE `playercreateinfo` SET `orientation` = 3.659973 WHERE `class` = 6 AND `race` != 24;
