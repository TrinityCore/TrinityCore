DROP TABLE IF EXISTS `npc_teleport`;
CREATE TABLE `npc_teleport`(
    `menu` INT(10) UNSIGNED NOT NULL,
    `submenu` INT(10) UNSIGNED NOT NULL,
    `icon` INT(10) UNSIGNED NOT NULL,
    `name` VARCHAR(255) NOT NULL,
    `cost` INT(10) UNSIGNED NOT NULL,
    `faction` INT(10) UNSIGNED NOT NULL,
    `map` INT(10) UNSIGNED NOT NULL,
    `x` FLOAT NOT NULL,
    `y` FLOAT NOT NULL,
    `z` FLOAT NOT NULL,
    `o` FLOAT NOT NULL
); 

DELETE FROM creature_template WHERE entry = 1001000;
INSERT INTO creature_template (entry, modelid1, NAME, subname, minlevel, maxlevel, faction, npcflag, unit_class, scriptname) VALUES
(1001000, 28153, 'Rayze', 'Teleporter', -1, -1, 35, 1, 1, "NPC_Teleport");
