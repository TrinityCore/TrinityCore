--
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175));
DELETE FROM `game_event_creature` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175)) AND `eventEntry` !=2;
DELETE FROM `creature` WHERE `id` IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175) AND `guid` NOT IN (SELECT `guid` FROM `game_event_creature` WHERE `eventEntry` =2);
DELETE FROM `creature_template_addon` WHERE `entry` IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);
UPDATE `creature` SET `equipment_id`=0, `modelid`=0 WHERE `id` IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=`unit_flags`|768 WHERE `entry` IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);

INSERT INTO `game_event_creature` SELECT 12, creature.guid FROM `creature` WHERE creature.id IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);
INSERT INTO `game_event_creature` SELECT 24, creature.guid FROM `creature` WHERE creature.id IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);
INSERT INTO `game_event_creature` SELECT 7, creature.guid FROM `creature` WHERE creature.id IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);
INSERT INTO `game_event_creature` SELECT 1, creature.guid FROM `creature` WHERE creature.id IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);
INSERT INTO `game_event_creature` SELECT 26, creature.guid FROM `creature` WHERE creature.id IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);
INSERT INTO `game_event_creature` SELECT 51, creature.guid FROM `creature` WHERE creature.id IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);
INSERT INTO `game_event_creature` SELECT 50, creature.guid FROM `creature` WHERE creature.id IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);
INSERT INTO `game_event_creature` SELECT 9, creature.guid FROM `creature` WHERE creature.id IN (20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);

SET @entry1:=20102;
SET @entry2:=19172;
SET @entry3:=19169;
SET @entry4:=19173;
SET @entry5:=19171;
SET @entry6:=19148;
SET @entry7:=19177;
SET @entry8:=19176;
SET @entry9:=19178;
SET @entry10:=18927;
SET @entry11:=19175;

DELETE FROM smart_scripts WHERE `entryorguid` IN(@entry1,@entry2,@entry3,@entry4,@entry5,@entry6,@entry7,@entry8,@entry9,@entry10,@entry11) AND source_type=0 AND id>12;
DELETE FROM smart_scripts WHERE `entryorguid` IN (@entry1*100, @entry1*100+1, @entry2*100, @entry2*100+1, @entry3*100, @entry3*100+1, @entry4*100, @entry4*100+1, @entry5*100, @entry5*100+1, @entry6*100, @entry6*100+1, @entry7*100, @entry7*100+1, @entry8*100, @entry8*100+1, @entry9*100, @entry9*100+1, @entry10*100, @entry10*100+1, @entry11*100, @entry11*100+1) AND source_type=9;
DELETE FROM smart_scripts WHERE `entryorguid` IN (@entry1*100+2, @entry1*100+3, @entry2*100+2, @entry2*100+3, @entry3*100+2, @entry3*100+3, @entry4*100+2, @entry4*100+3, @entry5*100+2, @entry5*100+3, @entry6*100+2, @entry6*100+3, @entry7*100+2, @entry7*100+3, @entry8*100+2, @entry8*100+3, @entry9*100+2, @entry9*100+3, @entry10*100+2, @entry10*100+3, @entry11*100+2, @entry11*100+3) AND source_type=9;
DELETE FROM smart_scripts WHERE `entryorguid` IN (@entry1*100+4, @entry1*100+5, @entry2*100+4, @entry2*100+5, @entry3*100+4, @entry3*100+5, @entry4*100+5, @entry4*100+4, @entry5*100+4, @entry5*100+5, @entry6*100+4, @entry6*100+5, @entry7*100+4, @entry7*100+5, @entry8*100+4, @entry8*100+5, @entry9*100+4, @entry9*100+5, @entry10*100+4, @entry10*100+5, @entry11*100+4, @entry11*100+5) AND source_type=9;
DELETE FROM smart_scripts WHERE `entryorguid` IN (@entry1*100+6, @entry1*100+7, @entry2*100+6, @entry2*100+7, @entry3*100+6, @entry3*100+7, @entry4*100+6, @entry4*100+7, @entry5*100+6, @entry5*100+7, @entry6*100+6, @entry6*100+7, @entry7*100+6, @entry7*100+7, @entry8*100+6, @entry8*100+7, @entry9*100+6, @entry9*100+7, @entry10*100+6, @entry10*100+7, @entry11*100+6, @entry11*100+7) AND source_type=9;
DELETE FROM smart_scripts WHERE `entryorguid` IN (@entry1*100+8, @entry1*100+9, @entry2*100+8, @entry2*100+9, @entry3*100+8, @entry3*100+9, @entry4*100+8, @entry4*100+9, @entry5*100+8, @entry5*100+9, @entry6*100+8, @entry6*100+9, @entry7*100+8, @entry7*100+9, @entry8*100+8, @entry8*100+9, @entry9*100+8, @entry9*100+9, @entry10*100+8, @entry10*100+9, @entry11*100+8, @entry11*100+9) AND source_type=9;
DELETE FROM smart_scripts WHERE `entryorguid` IN (@entry1*100+10, @entry1*100+11, @entry2*100+10, @entry2*100+11, @entry3*100+10, @entry3*100+11, @entry4*100+10, @entry4*100+11, @entry5*100+10, @entry5*100+11, @entry6*100+10, @entry6*100+11, @entry7*100+10, @entry7*100+11, @entry8*100+10, @entry8*100+11, @entry9*100+10, @entry9*100+11, @entry10*100+10, @entry10*100+11, @entry11*100+10, @entry11*100+11) AND source_type=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@entry1, 0, 13, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry1*100, @entry1*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - On respawn - random action list'), -- Goblin christmas
(@entry1*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 34845, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - random action list - cast '),
(@entry1*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 34849, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - random action list - cast'),
(@entry1, 0, 14, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry1*100+2, @entry1*100+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - On respawn - random action list'), -- Goblin Halloween
(@entry1*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43631, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - random action list - cast '),
(@entry1*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - random action list - cast'),
(@entry1, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry1*100+4, @entry1*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - On respawn - random action list'), -- Goblin Lunar
(@entry1*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 34848, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - random action list - cast '),
(@entry1*100+5, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 34851, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - random action list - cast'),
(@entry1, 0, 16, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @entry1*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin commoner - On respawn - random action list'), -- Goblin Brewfest
(@entry1*100+6, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43911, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin commoner - random action list - cast '),
(@entry1*100+6, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 13861, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin commoner - random action list - Equip'),
(@entry1, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry1*100+7, @entry1*100+8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - On respawn - random action list'), -- Goblin DOTD
(@entry1*100+7, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - random action list - Morph '),
(@entry1*100+8, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29204, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - random action list - Morph'),
(@entry1, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry1*100+9, @entry1*100+10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - On respawn - random action list'), -- Goblin pirates
(@entry1*100+9, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25036, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - random action list - Morph '),
(@entry1*100+10, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25047, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - random action list - Morph'),
(@entry1, 0, 19, 0, 11, 0, 100, 0, 0, 0, 0, 0, 3, 25872, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goblin  commoner - On respawn - Morph'), -- Goblin midsummer
(@entry2, 0, 13, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry2*100, @entry2*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome   commoner - On respawn - random action list'), -- Gnome  christmas
(@entry2*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33448, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome   commoner - random action list - cast '),
(@entry2*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33445, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome   commoner - random action list - cast'),
(@entry2, 0, 14, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry2*100+2, @entry2*100+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome   commoner - On respawn - random action list'), -- Gnome  Halloween
(@entry2*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43629, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome   commoner - random action list - cast '),
(@entry2*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43628, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome   commoner - random action list - cast'),
(@entry2, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry2*100+4, @entry2*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome  - On respawn - random action list'), -- Gnome Lunar
(@entry2*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33446, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome  - random action list - cast '),
(@entry2*100+5, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33449, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome - random action list - cast'),
(@entry2, 0, 16, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @entry2*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome commoner - On respawn - random action list'), -- Gnome Brewfest
(@entry2*100+6, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43910, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome commoner - random action list - cast '),
(@entry2*100+6, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 13861, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome commoner - random action list - Equip'),
(@entry2, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry2*100+7, @entry2*100+8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome  commoner - On respawn - random action list'), -- Gnome DOTD
(@entry2*100+7, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome  commoner - random action list - Morph '),
(@entry2*100+8, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29204, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome  commoner - random action list - Morph'),
(@entry2, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry2*100+9, @entry2*100+10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome  commoner - On respawn - random action list'), -- Gnome pirates
(@entry2*100+9, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25035, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome  commoner - random action list - Morph '),
(@entry2*100+10, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25046, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome  commoner - random action list - Morph'),
(@entry2, 0, 19, 0, 11, 0, 100, 0, 0, 0, 0, 0, 3, 25871, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnome  commoner - On respawn - Morph'), -- Gnome midsummer
(@entry3, 0, 13, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry3*100, @entry3*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - On respawn - random action list'), -- blood elf christmas
(@entry3*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33412, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - random action list - cast '),
(@entry3*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33415, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - random action list - cast'),
(@entry3, 0, 14, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry3*100+2, @entry3*100+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - On respawn - random action list'), -- blood elf Halloween
(@entry3*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43406, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - random action list - cast '),
(@entry3*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - random action list - cast'),
(@entry3, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry3*100+4, @entry3*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - On respawn - random action list'), -- blood elf Lunar
(@entry3*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33413, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - random action list - cast '),
(@entry3*100+5, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33416, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - random action list - cast'),
(@entry3, 0, 16, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @entry3*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - On respawn - random action list'), -- blood elf Brewfest
(@entry3*100+6, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43907, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - random action list - cast '),
(@entry3*100+6, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2703, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodelf commoner - random action list - Equip'),
(@entry3, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry3*100+7, @entry3*100+8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'blood elf  commoner - On respawn - random action list'), -- blood elf DOTD
(@entry3*100+7, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'blood elf  commoner - random action list - Morph '),
(@entry3*100+8, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29204, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'blood elf  commoner - random action list - Morph'),
(@entry3, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry3*100+9, @entry3*100+10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'blood elf   commoner - On respawn - random action list'), -- blood elf pirates
(@entry3*100+9, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25032, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'blood elf   commoner - random action list - Morph '),
(@entry3*100+10, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25043, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'blood elf   commoner - random action list - Morph'),
(@entry3, 0, 19, 0, 11, 0, 100, 0, 0, 0, 0, 0, 3, 25868, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'blood elf  commoner - On respawn - Morph'), -- blood elf midsummer
(@entry4, 0, 13, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry4*100, @entry4*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - On respawn - random action list'), -- night elf christmas
(@entry4*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33439, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - random action list - cast '),
(@entry4*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - random action list - cast'),
(@entry4, 0, 14, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry4*100+2, @entry4*100+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - On respawn - random action list'), -- night elf Halloween
(@entry4*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43635, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - random action list - cast '),
(@entry4*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43634, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - random action list - cast'),
(@entry4, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry4*100+4, @entry4*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - On respawn - random action list'), -- night elf Lunar
(@entry4*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33443, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - random action list - cast '),
(@entry4*100+5, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33440, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - random action list - cast'),
(@entry4, 0, 16, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @entry4*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - On respawn - random action list'), -- night elf Brewfest
(@entry4*100+6, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43913, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - random action list - cast '),
(@entry4*100+6, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2703, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner - random action list - Equip'),
(@entry4, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry4*100+7, @entry4*100+8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner   - On respawn - random action list'), -- night commoner DOTD
(@entry4*100+7, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner   - random action list - Morph '),
(@entry4*100+8, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29204, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night commoner   - random action list - Morph'),
(@entry4, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry4*100+9, @entry4*100+10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night elf   commoner - On respawn - random action list'), -- night elf pirates
(@entry4*100+9, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25038, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night elf   commoner - random action list - Morph '),
(@entry4*100+10, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25049, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night elf   commoner - random action list - Morph'),
(@entry4, 0, 19, 0, 11, 0, 100, 0, 0, 0, 0, 0, 3, 25874, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'night elf  commoner - On respawn - Morph'), -- night elf midsummer
(@entry5, 0, 13, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry5*100, @entry5*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  - On respawn - random action list'), -- Draenei  christmas
(@entry5*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33427, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  - random action list - cast '),
(@entry5*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33430, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei - random action list - cast'),
(@entry5, 0, 14, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry5*100+2, @entry5*100+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  - On respawn - random action list'), -- Draenei  Halloween
(@entry5*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43625, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  - random action list - cast '),
(@entry5*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43623, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei - random action list - cast'),
(@entry5, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry5*100+4, @entry5*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  - On respawn - random action list'), -- Draenei  Lunar
(@entry5*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33428, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  - random action list - cast '),
(@entry5*100+5, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33431, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei - random action list - cast'),
(@entry5, 0, 16, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @entry5*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  - On respawn - random action list'), -- Draenei  Brewfest
(@entry5*100+6, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43908, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  - random action list - cast '),
(@entry5*100+6, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2703, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei commoner - random action list - Equip'),
(@entry5, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry5*100+7, @entry5*100+8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  commoner - On respawn - random action list'), -- Draenei DOTD
(@entry5*100+7, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  commoner - random action list - Morph '),
(@entry5*100+8, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29204, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  commoner - random action list - Morph'),
(@entry5, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry5*100+9, @entry5*100+10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei commoner - On respawn - random action list'), -- Draenei pirates
(@entry5*100+9, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25033, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei commoner - random action list - Morph '),
(@entry5*100+10, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25044, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei commoner - random action list - Morph'),
(@entry5, 0, 19, 0, 11, 0, 100, 0, 0, 0, 0, 0, 3, 25869, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Draenei  commoner - On respawn - Morph'), -- Draenei midsummer
(@entry6, 0, 13, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry6*100, @entry6*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - On respawn - random action list'), -- Dwarf  christmas
(@entry6*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33433, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - random action list - cast '),
(@entry6*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33436, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - random action list - cast'),
(@entry6, 0, 14, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry6*100+2, @entry6*100+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf  - On respawn - random action list'), -- Dwarf  Halloween
(@entry6*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43626, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - random action list - cast '),
(@entry6*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43627, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - random action list - cast'),
(@entry6, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry6*100+4, @entry6*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf  - On respawn - random action list'), -- Dwarf  Lunar
(@entry6*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33437, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - random action list - cast '),
(@entry6*100+5, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33434, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - random action list - cast'),
(@entry6, 0, 16, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @entry6*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - On respawn - random action list'), -- Dwarf Brewfest
(@entry6*100+6, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43909, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - random action list - cast '),
(@entry6*100+6, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 13861, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - random action list - Equip'),
(@entry6, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry6*100+7, @entry6*100+8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf  commoner - On respawn - random action list'), -- Dwarf DOTD
(@entry6*100+7, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf  commoner - random action list - Morph '),
(@entry6*100+8, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29204, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf  commoner - random action list - Morph'),
(@entry6, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry6*100+9, @entry6*100+10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - On respawn - random action list'), -- Dwarf pirates
(@entry6*100+9, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25034, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - random action list - Morph '),
(@entry6*100+10, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25045, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf commoner - random action list - Morph'),
(@entry6, 0, 19, 0, 11, 0, 100, 0, 0, 0, 0, 0, 3, 25870, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dwarf  commoner - On respawn - Morph'), -- Dwarf midsummer
(@entry7, 0, 13, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry7*100, @entry7*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll  - On respawn - random action list'), -- Troll christmas
(@entry7*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33471, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll  - random action list - cast '),
(@entry7*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33468, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll - random action list - cast'),
(@entry7, 0, 14, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry7*100+2, @entry7*100+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll  - On respawn - random action list'), -- Troll Halloween
(@entry7*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43641, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll  - random action list - cast '),
(@entry7*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43640, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll - random action list - cast'),
(@entry7, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry7*100+4, @entry7*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll  - On respawn - random action list'), -- Troll Lunar
(@entry7*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33472, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll  - random action list - cast '),
(@entry7*100+5, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33469, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll - random action list - cast'),
(@entry7, 0, 16, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @entry7*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll commoner - On respawn - random action list'), -- Troll Brewfest
(@entry7*100+6, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43916, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll commoner - random action list - cast '),
(@entry7*100+6, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2705, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll commoner - random action list - Equip'),
(@entry7, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry7*100+7, @entry7*100+8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll  commoner - On respawn - random action list'), -- Troll DOTD
(@entry7*100+7, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll  commoner - random action list - Morph '),
(@entry7*100+8, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29204, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll  commoner - random action list - Morph'),
(@entry7, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry7*100+9, @entry7*100+10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll commoner - On respawn - random action list'), -- Troll pirates
(@entry7*100+9, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25041, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll commoner - random action list - Morph '),
(@entry7*100+10, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25052, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll commoner - random action list - Morph'),
(@entry7, 0, 19, 0, 11, 0, 100, 0, 0, 0, 0, 0, 3, 25877, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Troll  commoner - On respawn - Morph'), -- Troll midsummer
(@entry8, 0, 13, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry8*100, @entry8*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren  - On respawn - random action list'), -- Tauren christmas
(@entry8*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33465, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren  - random action list - cast '),
(@entry8*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33458, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren - random action list - cast'),
(@entry8, 0, 14, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry8*100+2, @entry8*100+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren  - On respawn - random action list'), -- Tauren Halloween
(@entry8*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43638, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren  - random action list - cast '),
(@entry8*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43639, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren - random action list - cast'),
(@entry8, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry8*100+4, @entry8*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren  - On respawn - random action list'), -- Tauren Lunar
(@entry8*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33459, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren  - random action list - cast '),
(@entry8*100+5, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33466, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren - random action list - cast'),
(@entry8, 0, 16, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @entry8*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren commoner - On respawn - random action list'), -- Tauren Brewfest
(@entry8*100+6, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43915, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren commoner - random action list - cast '),
(@entry8*100+6, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2705, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren commoner - random action list - Equip'),
(@entry8, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry8*100+7, @entry8*100+8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren  commoner - On respawn - random action list'), -- Tauren DOTD
(@entry8*100+7, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren  commoner - random action list - Morph '),
(@entry8*100+8, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29204, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren  commoner - random action list - Morph'),
(@entry8, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry8*100+9, @entry8*100+10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren commoner - On respawn - random action list'), -- Tauren pirates
(@entry8*100+9, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25040, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren commoner - random action list - Morph '),
(@entry8*100+10, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25051, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren commoner - random action list - Morph'),
(@entry8, 0, 19, 0, 11, 0, 100, 0, 0, 0, 0, 0, 3, 25876, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tauren  commoner - On respawn - Morph'), -- Tauren midsummer
(@entry9, 0, 13, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry9*100, @entry9*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead   - On respawn - random action list'), -- Undead  christmas
(@entry9*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33474, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead   - random action list - cast '),
(@entry9*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33477, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead  - random action list - cast'),
(@entry9, 0, 14, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry9*100+2, @entry9*100+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead   - On respawn - random action list'), -- Undead  christmas
(@entry9*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43642, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead   - random action list - cast '),
(@entry9*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43643, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead  - random action list - cast'),
(@entry9, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry9*100+4, @entry9*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead   - On respawn - random action list'), -- Undead  Lunar
(@entry9*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33478, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead   - random action list - cast '),
(@entry9*100+5, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33475, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead  - random action list - cast'),
(@entry9, 0, 16, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @entry9*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead commoner - On respawn - random action list'), -- Undead Brewfest
(@entry9*100+6, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43917, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead commoner - random action list - cast '),
(@entry9*100+6, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2705, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead commoner - random action list - Equip'),
(@entry9, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry9*100+7, @entry9*100+8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead  commoner - On respawn - random action list'), -- Undead DOTD
(@entry9*100+7, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead  commoner - random action list - Morph '),
(@entry9*100+8, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29204, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undead  commoner - random action list - Morph'),
(@entry9, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry9*100+9, @entry9*100+10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'undead commoner - On respawn - random action list'), -- undead pirates
(@entry9*100+9, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25042, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'undead commoner - random action list - Morph '),
(@entry9*100+10, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25053, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'undead commoner - random action list - Morph'),
(@entry9, 0, 19, 0, 11, 0, 100, 0, 0, 0, 0, 0, 3, 25878, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'undead  commoner - On respawn - Morph'), -- undead midsummer
(@entry10, 0, 13, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry10*100, @entry10*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human   - On respawn - random action list'), -- Human  christmas
(@entry10*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human   - random action list - cast '),
(@entry10*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human  - random action list - cast'),
(@entry10, 0, 14, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry10*100+2, @entry10*100+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human   - On respawn - random action list'), -- Human  Halloween
(@entry10*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43633, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human   - random action list - cast '),
(@entry10*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43632, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human  - random action list - cast'),
(@entry10, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry10*100+4, @entry10*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human   - On respawn - random action list'), -- Human  Lunar
(@entry10*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33397, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human   - random action list - cast '),
(@entry10*100+5, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33398, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human  - random action list - cast'),
(@entry10, 0, 16, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @entry10*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human commoner - On respawn - random action list'), -- Human Brewfest
(@entry10*100+6, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human commoner - random action list - cast '),
(@entry10*100+6, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2705, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human commoner - random action list - Equip'),
(@entry10, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry10*100+7, @entry10*100+8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human  commoner - On respawn - random action list'), -- Human DOTD
(@entry10*100+7, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human  commoner - random action list - Morph '),
(@entry10*100+8, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29204, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human  commoner - random action list - Morph'),
(@entry10, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry10*100+9, @entry10*100+10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human commoner - On respawn - random action list'), -- Human pirates
(@entry10*100+9, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25037, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human commoner - random action list - Morph '),
(@entry10*100+10, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25048, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human commoner - random action list - Morph'),
(@entry10, 0, 19, 0, 11, 0, 100, 0, 0, 0, 0, 0, 3, 25873, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Human  commoner - On respawn - Morph'), -- Human midsummer
(@entry11, 0, 13, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry11*100, @entry11*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc - On respawn - random action list'), -- Orc   christmas
(@entry11*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33451, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc  - random action list - cast '),
(@entry11*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33455, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc - random action list - cast'),
(@entry11, 0, 14, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry11*100+2, @entry11*100+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc    - On respawn - random action list'), -- Orc   Halloween
(@entry11*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43637, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc - random action list - cast '),
(@entry11*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43636, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc - random action list - cast'),
(@entry11, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry11*100+4, @entry11*100+5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc    - On respawn - random action list'), -- Orc   Lunar
(@entry11*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33456, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc - random action list - cast '),
(@entry11*100+5, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc - random action list - cast'),
(@entry11, 0, 16, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @entry11*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc commoner - On respawn - random action list'), -- Orc Brewfest
(@entry11*100+6, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 43914, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc commoner - random action list - cast '),
(@entry11*100+6, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2705, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc commoner - random action list - Equip'),
(@entry11, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry11*100+7, @entry11*100+8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc  commoner - On respawn - random action list'), -- Orc DOTD
(@entry11*100+7, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc  commoner - random action list - Morph '),
(@entry11*100+8, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 29204, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc  commoner - random action list - Morph'),
(@entry11, 0, 18, 0, 11, 0, 100, 0, 0, 0, 0, 0, 87, @entry11*100+9, @entry11*100+10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc commoner - On respawn - random action list'), -- Orc pirates
(@entry11*100+9, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25039, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc commoner - random action list - Morph '),
(@entry11*100+10, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 25050, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc commoner - random action list - Morph'),
(@entry11, 0, 19, 0, 11, 0, 100, 0, 0, 0, 0, 0, 3, 25875, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orc  commoner - On respawn - Morph'); -- Orc midsummer
 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (20102,18927,19177,19169,19175,19171,19172,19176,19178,19173,19148) AND `SourceGroup` >13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 14, 19148, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winter Veil must be active'),
(22, 14, 20102, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winter Veil must be active'),
(22, 14, 18927, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winter Veil must be active'),
(22, 14, 19171, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winter Veil must be active'),
(22, 14, 19172, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winter Veil must be active'),
(22, 14, 19173, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winter Veil must be active'),
(22, 14, 19175, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winter Veil must be active'),
(22, 14, 19176, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winter Veil must be active'),
(22, 14, 19177, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winter Veil must be active'),
(22, 14, 19178, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winter Veil must be active'),
(22, 14, 19169, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winter Veil must be active'),
(22, 15, 19148, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallow''s End must be active'),
(22, 15, 20102, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallow''s End must be active'),
(22, 15, 18927, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallow''s End must be active'),
(22, 15, 19171, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallow''s End must be active'),
(22, 15, 19172, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallow''s End must be active'),
(22, 15, 19173, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallow''s End must be active'),
(22, 15, 19175, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallow''s End must be active'),
(22, 15, 19176, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallow''s End must be active'),
(22, 15, 19177, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallow''s End must be active'),
(22, 15, 19178, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallow''s End must be active'),
(22, 15, 19169, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallow''s End must be active'),
(22, 16, 19148, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Lunar Festival must be active'),
(22, 16, 20102, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Lunar Festival must be active'),
(22, 16, 18927, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Lunar Festival must be active'),
(22, 16, 19171, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Lunar Festival must be active'),
(22, 16, 19172, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Lunar Festival must be active'),
(22, 16, 19173, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Lunar Festival must be active'),
(22, 16, 19175, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Lunar Festival must be active'),
(22, 16, 19176, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Lunar Festival must be active'),
(22, 16, 19177, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Lunar Festival must be active'),
(22, 16, 19178, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Lunar Festival must be active'),
(22, 16, 19169, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Lunar Festival must be active'),
(22, 17, 19148, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - Brew Fest must be active'),
(22, 17, 20102, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - Brew Fest must be active'),
(22, 17, 18927, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - Brew Fest must be active'),
(22, 17, 19171, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - Brew Fest must be active'),
(22, 17, 19172, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - Brew Fest must be active'),
(22, 17, 19173, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - Brew Fest must be active'),
(22, 17, 19175, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - Brew Fest must be active'),
(22, 17, 19176, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - Brew Fest must be active'),
(22, 17, 19177, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - Brew Fest must be active'),
(22, 17, 19178, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - Brew Fest must be active'),
(22, 17, 19169, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - Brew Fest must be active'),
(22, 18, 19148, 0, 0, 12, 1, 51, 0, 0, 0, 0, 0, '', 'Commoner - DOTD must be active'),
(22, 18, 20102, 0, 0, 12, 1, 51, 0, 0, 0, 0, 0, '', 'Commoner - DOTD must be active'),
(22, 18, 18927, 0, 0, 12, 1, 51, 0, 0, 0, 0, 0, '', 'Commoner - DOTD must be active'),
(22, 18, 19171, 0, 0, 12, 1, 51, 0, 0, 0, 0, 0, '', 'Commoner - DOTD must be active'),
(22, 18, 19172, 0, 0, 12, 1, 51, 0, 0, 0, 0, 0, '', 'Commoner - DOTD must be active'),
(22, 18, 19173, 0, 0, 12, 1, 51, 0, 0, 0, 0, 0, '', 'Commoner - DOTD must be active'),
(22, 18, 19175, 0, 0, 12, 1, 51, 0, 0, 0, 0, 0, '', 'Commoner - DOTD must be active'),
(22, 18, 19176, 0, 0, 12, 1, 51, 0, 0, 0, 0, 0, '', 'Commoner - DOTD must be active'),
(22, 18, 19177, 0, 0, 12, 1, 51, 0, 0, 0, 0, 0, '', 'Commoner - DOTD must be active'),
(22, 18, 19178, 0, 0, 12, 1, 51, 0, 0, 0, 0, 0, '', 'Commoner - DOTD must be active'),
(22, 18, 19169, 0, 0, 12, 1, 51, 0, 0, 0, 0, 0, '', 'Commoner - DOTD must be active'),
(22, 19, 19148, 0, 0, 12, 1, 50, 0, 0, 0, 0, 0, '', 'Commoner - Pirates Day must be active'),
(22, 19, 20102, 0, 0, 12, 1, 50, 0, 0, 0, 0, 0, '', 'Commoner - Pirates Day must be active'),
(22, 19, 18927, 0, 0, 12, 1, 50, 0, 0, 0, 0, 0, '', 'Commoner - Pirates Day must be active'),
(22, 19, 19171, 0, 0, 12, 1, 50, 0, 0, 0, 0, 0, '', 'Commoner - Pirates Day must be active'),
(22, 19, 19172, 0, 0, 12, 1, 50, 0, 0, 0, 0, 0, '', 'Commoner - Pirates Day must be active'),
(22, 19, 19173, 0, 0, 12, 1, 50, 0, 0, 0, 0, 0, '', 'Commoner - Pirates Day must be active'),
(22, 19, 19175, 0, 0, 12, 1, 50, 0, 0, 0, 0, 0, '', 'Commoner - Pirates Day must be active'),
(22, 19, 19176, 0, 0, 12, 1, 50, 0, 0, 0, 0, 0, '', 'Commoner - Pirates Day must be active'),
(22, 19, 19177, 0, 0, 12, 1, 50, 0, 0, 0, 0, 0, '', 'Commoner - Pirates Day must be active'),
(22, 19, 19178, 0, 0, 12, 1, 50, 0, 0, 0, 0, 0, '', 'Commoner - Pirates Day must be active'),
(22, 19, 19169, 0, 0, 12, 1, 50, 0, 0, 0, 0, 0, '', 'Commoner - Pirates Day must be active'),
(22, 20, 19148, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer Fire Festival must be active'),
(22, 20, 20102, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer Fire Festival must be active'),
(22, 20, 18927, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer Fire Festival must be active'),
(22, 20, 19171, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer Fire Festival must be active'),
(22, 20, 19172, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer Fire Festival must be active'),
(22, 20, 19173, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer Fire Festival must be active'),
(22, 20, 19175, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer Fire Festival must be active'),
(22, 20, 19176, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer Fire Festival must be active'),
(22, 20, 19177, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer Fire Festival must be active'),
(22, 20, 19178, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer Fire Festival must be active'),
(22, 20, 19169, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer Fire Festival must be active');

DELETE FROM `game_event_creature_quest` WHERE `quest` IN (13483, 13484);
INSERT INTO `game_event_creature_quest` (`eventEntry`, `id`, `quest`) VALUES
(9, 19148, 13484),
(9, 18927, 13484),
(9, 19178, 13483),
(9, 19177, 13483),
(9, 19176, 13483),
(9, 19175, 13483),
(9, 19169, 13483),
(9, 19171, 13484),
(9, 19172, 13484),
(9, 19173, 13484),
(9, 20102, 13484),
(9, 20102, 13483);

DELETE FROM `creature_queststarter` WHERE `id` IN(20102, 19172, 19169, 19173, 19171, 19148, 19177, 19176, 19178, 18927, 19175);
