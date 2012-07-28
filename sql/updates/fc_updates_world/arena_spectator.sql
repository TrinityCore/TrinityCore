DELETE FROM `command` WHERE `name` = 'spectate';        
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('spectate', 0, 'Syntax: .spectate $subcommand.\nUse .help sppectate');
DELETE FROM `command` WHERE `name` = 'spectatefrom';    
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('spectate view', 0, 'Syntax: .spectate view #player\nAllow player to spectate arena from anotherplayer.');
DELETE FROM `command` WHERE `name` = 'spectate leav';   
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('spectate leave', 0, 'Syntax: .spectate leave\nDisable spectator mode.');
DELETE FROM `command` WHERE `name` = 'spectate player'; 
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('spectate player', 0, 'Syntax: .spectate player #player\nAllow to spectate player.');
DELETE FROM `command` WHERE `name` = 'spectate reset';  
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('spectate reset', 0, 'Syntax: .spectate reset\nSend addon data.');

UPDATE `gameobject_template` SET `flags` = 36 WHERE entry IN (185918, 185917, 183970, 183971, 183972, 183973, 183977, 183979, 183978, 183980);

DELETE FROM creature_template WHERE entry = '190000'; 
INSERT INTO creature_template (entry, modelid1, name, subname, IconName, gossip_menu_id, minlevel, maxlevel, Health_mod, Mana_mod, Armor_mod, faction_A, faction_H, npcflag, speed_walk, speed_run, scale, rank, dmg_multiplier, unit_class, unit_flags, type, type_flags, InhabitType, RegenHealth, flags_extra, ScriptName) VALUES 
('190000', '29348', "Arena Spectator", "Use addon!", 'Speak', '50000', 71, 71, 1.56, 1.56, 1.56, 35, 35, 3, 1, 1.14286, 1.25, 1, 1, 1, 2, 7, 138936390, 3, 1, 2, 'npc_arena_spectator'); 
