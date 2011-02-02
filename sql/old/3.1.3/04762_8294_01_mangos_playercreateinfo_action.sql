-- ALTER TABLE db_version CHANGE COLUMN required_8254_01_mangos_spell_proc_event required_8294_01_mangos_playercreateinfo_action bit;

-- Remove Double attack icons for Night Elf Warrior
DELETE FROM playercreateinfo_action WHERE race=4 AND class=1 AND button=73;
-- Move Heroic Strike to correct location for Night Elf Warrior
DELETE FROM playercreateinfo_action WHERE race=4 AND class=1 AND button=74;
INSERT INTO playercreateinfo_action VALUES (4,1,73,78,0);
-- Moved Shadowmeld to correct location for Night Elf Warrior
DELETE FROM playercreateinfo_action WHERE race=4 AND class=1 AND button IN (82,83);
INSERT INTO playercreateinfo_action VALUES (4,1,82,58984,0);
-- Add correct Tough Jerky location for Night elf Warrior
DELETE FROM playercreateinfo_action WHERE race=4 AND class=1 AND button=84;
INSERT INTO playercreateinfo_action VALUES (4,1,83,117,128);

-- Moved Shadowmeld to correct location for Night Elf Druid
DELETE FROM playercreateinfo_action WHERE race=4 AND class=11 AND button IN (3,9);
INSERT INTO playercreateinfo_action VALUES (4,11,9,58984,0);

-- Moved Shadowmeld to correct location for Night Elf Rogue
DELETE FROM playercreateinfo_action WHERE race=4 AND class=4 AND button IN (4,10);
INSERT INTO playercreateinfo_action VALUES (4,4,10,58984,0);
-- Add Shadowmeld For Night Elf Rogue Shadow form bar
DELETE FROM playercreateinfo_action WHERE race=4 AND class=4 AND button = 82;
INSERT INTO playercreateinfo_action VALUES (4,4,82,58984,0);

-- Replace Tough Jerky for Gnome Death Knight Action Bar
DELETE FROM playercreateinfo_action WHERE race=7 AND class=6 AND button IN (11,83);
INSERT INTO playercreateinfo_action VALUES
(7,6,11,41751,128),
(7,6,83,41751,128);

-- Moved Gift of Naaru to correct location for Draenei Death Knight
DELETE FROM playercreateinfo_action WHERE race=11 AND class=6 AND button IN (6,10);
INSERT INTO playercreateinfo_action VALUES (11,6,10,59545,0);
-- Add Black Mushroom to Draenei Death Knight Action Bar
DELETE FROM playercreateinfo_action WHERE race=11 AND class=6 AND button IN (11);
INSERT INTO playercreateinfo_action VALUES
(11,6,11,41751,128);

-- Moved Blood Fury to correct action bar location for Orc Hunter
DELETE FROM playercreateinfo_action WHERE race=2 AND class=3 AND button IN (4,9);
INSERT INTO playercreateinfo_action VALUES (2,3,9,20572,0);

-- Moved Berserking to correct action bar location for Non-Heroic Troll classes 
DELETE FROM playercreateinfo_action WHERE race=8 AND class IN (3,5,7,8) AND button IN (3,76);
INSERT INTO playercreateinfo_action VALUES
(8,3,3,20554,0),
(8,5,3,20554,0),
(8,7,3,20554,0),
(8,8,3,20554,0);

-- Updated and moved Berserking skill for Troll Rogue
DELETE FROM playercreateinfo_action WHERE race=8 AND class=4 AND button IN (4,76);
INSERT INTO playercreateinfo_action VALUES (8,4,4,26297,0);
