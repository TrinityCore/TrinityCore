/* cs_npc.cpp */

SET @id = 570;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'npc';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'npc add';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'npc add formation';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'npc add item';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'npc add move';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'npc add temp';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'npc add delete';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'npc add delete item';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'npc add follow';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'npc add follow stop';
UPDATE `command` SET `permission` = @id+10 WHERE `name` = 'npc set';
UPDATE `command` SET `permission` = @id+11 WHERE `name` = 'npc set allowmove';
UPDATE `command` SET `permission` = @id+12 WHERE `name` = 'npc set entry';
UPDATE `command` SET `permission` = @id+13 WHERE `name` = 'npc set factionid';
UPDATE `command` SET `permission` = @id+14 WHERE `name` = 'npc set flag';
UPDATE `command` SET `permission` = @id+15 WHERE `name` = 'npc set level';
UPDATE `command` SET `permission` = @id+16 WHERE `name` = 'npc set link';
UPDATE `command` SET `permission` = @id+17 WHERE `name` = 'npc set model';
UPDATE `command` SET `permission` = @id+18 WHERE `name` = 'npc set movetype';
UPDATE `command` SET `permission` = @id+19 WHERE `name` = 'npc set phase';
UPDATE `command` SET `permission` = @id+20 WHERE `name` = 'npc set spawndist';
UPDATE `command` SET `permission` = @id+21 WHERE `name` = 'npc set spawntime';
UPDATE `command` SET `permission` = @id+22 WHERE `name` = 'npc set data';
UPDATE `command` SET `permission` = @id+23 WHERE `name` = 'npc info';
UPDATE `command` SET `permission` = @id+24 WHERE `name` = 'npc near';
UPDATE `command` SET `permission` = @id+25 WHERE `name` = 'npc move';
UPDATE `command` SET `permission` = @id+26 WHERE `name` = 'npc playemote';
UPDATE `command` SET `permission` = @id+27 WHERE `name` = 'npc say';
UPDATE `command` SET `permission` = @id+28 WHERE `name` = 'npc textemote';
UPDATE `command` SET `permission` = @id+29 WHERE `name` = 'npc whisper';
UPDATE `command` SET `permission` = @id+30 WHERE `name` = 'npc yell';
UPDATE `command` SET `permission` = @id+31 WHERE `name` = 'npc tame';
