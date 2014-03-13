
-- -----------------
-- Some extra fixes
-- -----------------
DELETE FROM `rbac_permissions` WHERE id IN('614','632','633');

UPDATE `rbac_permissions` SET `name` = 'Command: debug Mod32Value' WHERE `id` = '313'; 
UPDATE `rbac_permissions` SET `name` = 'Command: debug play cinematic' WHERE `id` = '316';
UPDATE `rbac_permissions` SET `name` = 'Command: debug transport' WHERE `id` = '400'; 
UPDATE `rbac_permissions` SET `name` = 'Command: npc delete' WHERE `id` = '576'; 
UPDATE `rbac_permissions` SET `name` = 'Command: npc delete item' WHERE `id` = '577'; 
UPDATE `rbac_permissions` SET `name` = 'Command: npc follow' WHERE `id` = '578'; 
UPDATE `rbac_permissions` SET `name` = 'Command: npc follow stop' WHERE `id` = '579'; 

UPDATE `rbac_permissions` SET `help` = NULL WHERE `id` = '567'; 
UPDATE `rbac_permissions` SET `help` = 'UNUSED.' WHERE `id` = '614'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .reload warden_action\r\nReload warden_action table.' WHERE `id` = '705'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .reload reputation_reward_rate\r\nReload reputation_reward_rate table.' WHERE `id` = '683'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .reload reputation_spillover_template\r\nReload reputation_spillover_template table.' WHERE `id` = '684'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .reload npc_spellclick_spells\r\nReload npc_spellclick_spells table.' WHERE `id` = '671'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .reload locales_achievement_reward\r\nReload locales_achievement_reward table.' WHERE `id` = '657'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .reload creature_ai_texts\r\nReload creature_ai_texts table.' WHERE `id` = '633'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .reload creature_ai_scripts\r\nReload creature_ai_scripts table.' WHERE `id` = '632'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .reload creature_texts\r\nReload creature_texts table.' WHERE `id` = '631'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .bf $subcommand\r\nType .bf to see the list of possible subcommands or .help bf $subcommand to see info on subcommands' WHERE `id` = '257'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .arena $subcommand\r\nType .arena to see the list of possible subcommands or .help arena $subcommand to see info on subcommands' WHERE `id` = '232'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .lock $subcommand\r\nType .lock to see the list of possible subcommands or .help lock $subcommand to see info on subcommands' WHERE `id` = '221'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .character $subcommand\r\nType .character to see the list of possible subcommands or .help character $subcommand to see info on subcommands' WHERE `id` = '273'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .character deleted $subcommand\r\nType .character deleted to see the list of possible subcommands or .help character deleted $subcommand to see info on subcommands' WHERE `id` = '277'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .debug $subcommand\r\nType .debug to see the list of possible subcommands or .help debug $subcommand to see info on subcommands' WHERE `id` = '300'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .deserter $subcommand\r\nType .deserter to see the list of possible subcommands or .help deserter $subcommand to see info on subcommands' WHERE `id` = '341'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .deserter bg $subcommand\r\nType .deserter bg to see the list of possible subcommands or .help deserter bg $subcommand to see info on subcommands' WHERE `id` = '342'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .deserter instance $subcommand\r\nType .deserter instance to see the list of possible subcommands or .help deserter instance $subcommand to see info on subcommands' WHERE `id` = '345'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .disable $subcommand\r\nType .disable to see the list of possible subcommands or .help disable $subcommand to see info on subcommands' WHERE `id` = '348'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .disable add $subcommand\r\nType .disable add to see the list of possible subcommands or .help disable add $subcommand to see info on subcommands' WHERE `id` = '349'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .disable remove $subcommand\r\nType .disable remove to see the list of possible subcommands or .help disable remove $subcommand to see info on subcommands' WHERE `id` = '358'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .gobject set $subcommand\r\nType .gobject set to see the list of possible subcommands or .help gobject set $subcommand to see info on subcommands' WHERE `id` = '395'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .learn all $subcommand\r\nType .learn all to see the list of possible subcommands or .help learn all $subcommand to see info on subcommands' WHERE `id` = '418'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .learn all my $subcommand\r\nType .learn all my to see the list of possible subcommands or .help learn all my $subcommand to see info on subcommands' WHERE `id` = '419'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .lfg $subcommand\r\nType .lfg to see the list of possible subcommands or .help lfg $subcommand to see info on subcommands' WHERE `id` = '430'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .lookup player $subcommand\r\nType .lookup player to see the list of possible subcommands or .help lookup player $subcommand to see info on subcommands' WHERE `id` = '451'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .channel $subcommand\r\nType .channel to see the list of possible subcommands or .help channel $subcommand to see info on subcommands' WHERE `id` = '463'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .send $subcommand\r\nType .send to see the list of possible subcommands or .help send $subcommand to see info on subcommands' WHERE `id` = '483'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .npc set $subcommand\r\nType .npc set to see the list of possible subcommands or .help npc set $subcommand to see info on subcommands' WHERE `id` = '580'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .server set $subcommand\r\nType .server set to see the list of possible subcommands or .help server set $subcommand to see info on subcommands' WHERE `id` = '729'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .titles $subcommand\r\nType .titles to see the list of possible subcommands or .help titles $subcommand to see info on subcommands' WHERE `id` = '761'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .wp $subcommand\r\nType .wp to see the list of possible subcommands or .help wp $subcommand to see info on subcommands' WHERE `id` = '767'; 
UPDATE `rbac_permissions` SET `help` = 'Syntax: .debug play $subcommand\r\nType .debug play to see the list of possible subcommands or .help debug play $subcommand to see info on subcommands' WHERE `id` = '315'; 
