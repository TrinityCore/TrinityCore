-- Rename changed gobject commands
DELETE FROM `command` WHERE `name` IN ('gobject setphase','gobject tempadd','gobject set phase','gobject add temp');
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('gobject set phase',2,'Syntax: .gobject set phase #guid #phasemask\r\n\r\nGameobject with DB guid #guid phasemask changed to #phasemask with related world vision update for players. Gameobject state saved to DB and persistent.'),
('gobject add temp',2,'Adds a temporary gameobject that is not saved to DB.');

-- Rename changed honor commands
DELETE FROM `command` WHERE `name` IN ('honor addkill','honor add kill');
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('honor add kill',2,'Syntax: .honor add kill\r\n\r\nAdd the targeted unit as one of your pvp kills today (you only get honor if it''s a racial leader or a player)');

-- Add wp add command
DELETE FROM `command` WHERE `name` IN ('wp add','wp addwp');
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('wp add',2,'Syntax: .wp add\r\n\r\nAdd a waypoint for the selected creature at your current position.');

-- Rename changed loadpath command and move it to wp reload
DELETE FROM `command` WHERE `name` IN ('loadpath','wp reload');
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('wp reload',3,'Syntax: .wp reload $pathid\nLoad path changes ingame - IMPORTANT: must be applied first for new paths before .wp load #pathid ');

DELETE FROM `command` WHERE `name` LIKE 'reload all%';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('reload all',3,'Syntax: .reload all\r\n\r\nReload all tables with reload support added and that can be _safe_ reloaded.'),
('reload all gossips',3,'Syntax: .reload all gossips\nReload gossip_menu, gossip_menu_option, gossip_scripts, npc_gossip, points_of_interest tables.'),
('reload all item',3,'Syntax: .reload all item\nReload page_text, item_enchantment_table tables.'),
('reload all locales',3,'Syntax: .reload all locales\r\n\r\nReload all `locales_*` tables with reload support added and that can be _safe_ reloaded.'),
('reload all loot',3,'Syntax: .reload all loot\r\n\r\nReload all `*_loot_template` tables. This can be slow operation with lags for server run.'),
('reload all npc',3,'Syntax: .reload all npc\nReload npc_gossip, npc_option, npc_trainer, npc vendor, points of interest tables.'),
('reload all quest',3,'Syntax: .reload all quest\r\n\r\nReload all quest related tables if reload support added for this table and this table can be _safe_ reloaded.'),
('reload all scripts',3,'Syntax: .reload all scripts\nReload gameobject_scripts, event_scripts, quest_end_scripts, quest_start_scripts, spell_scripts, db_script_string, waypoint_scripts tables.'),
('reload all spell',3,'Syntax: .reload all spell\r\n\r\nReload all `spell_*` tables with reload support added and that can be _safe_ reloaded.');

DELETE FROM `command` WHERE `name` IN ('titles setmask','titles set mask');
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('titles set mask',2,'Syntax: .titles set mask #mask\r\n\r\nAllows user to use all titles from #mask.\r\n\r\n #mask=0 disables the title-choose-field');
