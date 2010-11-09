-- Rename changed learn commands
DELETE FROM `command` WHERE `name` LIKE 'learn%';
INSERT INTO `command` (`name`, `security`, `help`) VALUES (
('learn',3,'Syntax: .learn #spell [all]\r\n\r\nSelected character learn a spell of id #spell. If ''all'' provided then all ranks learned.'),
('learn all',3,'Syntax: .learn all\r\n\r\nLearn all big set different spell maybe useful for Administaror.'),
('learn all crafts',2,'Syntax: .learn crafts\r\n\r\nLearn all professions and recipes.'),
('learn all default',1,'Syntax: .learn all default [$playername]\r\n\r\nLearn for selected/$playername player all default spells for his race/class and spells rewarded by completed quests.'),
('learn all gm',2,'Syntax: .learn all gm\r\n\r\nLearn all default spells for Game Masters.'),
('learn all lang',1,'Syntax: .learn all lang\r\n\r\nLearn all languages'),
('learn all my class',3,'Syntax: .learn all my class\r\n\r\nLearn all spells and talents available for his class.'),
('learn all my pettalents',3,'Syntax: .learn all my pettalents\r\n\r\nLearn all talents for your pet available for his creature type (only for hunter pets).'),
('learn all my spells',3,'Syntax: .learn all my spells\r\n\r\nLearn all spells (except talents and spells with first rank learned as talent) available for his class.'),
('learn all my talents',3,'Syntax: .learn all my talents\r\n\r\nLearn all talents (and spells with first rank learned as talent) available for his class.'),
('learn all recipes',2,'Syntax: .learn all recipes [$profession]\r\rLearns all recipes of specified profession and sets skill level to max.\rExample: .learn all recipes enchanting')
);
-- Rename changed npc commands
DELETE FROM `command` WHERE `name` LIKE 'npc%';
INSERT INTO `command` (`name`, `security`, `help`) VALUES (
('npc',1,'Syntax: .npc $subcommand\nType .npc to see the list of possible subcommands or .help npc $subcommand to see info on subcommands'),
('npc add',2,'Syntax: .npc add #creatureid\r\n\r\nSpawn a creature by the given template id of #creatureid.'),
('npc add formation',1,'Syntax: .npc add formation $leader\nAdd selected creature to a leader''s formation.'),
('npc add item',2,'Syntax: .npc add item #itemId <#maxcount><#incrtime><#extendedcost>r\r\n\r\nAdd item #itemid to item list of selected vendor. Also optionally set max count item in vendor item list and time to item count restoring and items ExtendedCost.'),
('npc add move',2,'Syntax: .npc add move #creature_guid [#waittime]\r\n\r\nAdd your current location as a waypoint for creature with guid #creature_guid. And optional add wait time.'),
('npc set allowmove',3,'Syntax: .npc set allowmove\r\n\r\nEnable or disable movement creatures in world. Not implemented.'),
('npc set entry',3,'Syntax: .npc set entry $entry\nSwitch selected creature with another entry from creature_template. - New creature.id value not saved to DB.'),
('npc set level',2,'Syntax: .npc set level #level\r\n\r\nChange the level of the selected creature to #level.\r\n\r\n#level may range from 1 to (CONFIG_MAX_PLAYER_LEVEL) + 3.'),
('npc delete',2,'Syntax: .npc delete [#guid]\r\n\r\nDelete creature with guid #guid (or the selected if no guid is provided)'),
('npc delete item',2,'Syntax: .npc delete item #itemId\r\n\r\nRemove item #itemid from item list of selected vendor.'),
('npc set factionid',2,'Syntax: .npc set factionid #factionid\r\n\r\nSet the faction of the selected creature to #factionid.'),
('npc set flag',2,'Syntax: .npc set flag #npcflag\r\n\r\nSet the NPC flags of creature template of the selected creature and selected creature to #npcflag. NPC flags will applied to all creatures of selected creature template after server restart or grid unload/load.'),
('npc follow',2,'Syntax: .npc follow start\r\n\r\nSelected creature start follow you until death/fight/etc.'),
('npc follow stop',2,'Syntax: .npc follow stop\r\n\r\nSelected creature (non pet) stop follow you.'),
('npc info',3,'Syntax: .npc info\r\n\r\nDisplay a list of details for the selected creature.\r\n\r\nThe list includes:\r\n- GUID, Faction, NPC flags, Entry ID, Model ID,\r\n- Level,\r\n- Health (current/maximum),\r\n\r\n- Field flags, dynamic flags, faction template, \r\n- Position information,\r\n- and the creature type, e.g. if the creature is a vendor.'),
('npc move',2,'Syntax: .npc move [#creature_guid]\r\n\r\nMove the targeted creature spawn point to your coordinates.'),
('npc playemote',3,'Syntax: .npc playemote #emoteid\r\n\r\nMake the selected creature emote with an emote of id #emoteid.'),
('npc say',1,'Syntax: .npc say $message\nMake selected creature say specified message.'),
('npc set deathstate',2,'Syntax: .npc set deathstate on/off\r\n\r\nSet default death state (dead/alive) for npc at spawn.'),
('npc set link',2,'Syntax: .npc set link $creatureGUID\r\n\r\nLinks respawn of selected creature to the condition that $creatureGUID defined is alive.'),
('npc set model',2,'Syntax: .npc set model #displayid\r\n\r\nChange the model id of the selected creature to #displayid.'),
('npc set movetype',2,'Syntax: .npc set movetype [#creature_guid] stay/random/way [NODEL]\r\n\r\nSet for creature pointed by #creature_guid (or selected if #creature_guid not provided) movement type and move it to respawn position (if creature alive). Any existing waypoints for creature will be removed from the database if you do not use NODEL. If the creature is dead then movement type will applied at creature respawn.\r\nMake sure you use NODEL, if you want to keep the waypoints.'),
('npc set phase',2,'Syntax: .npc set phase #phasemask\r\n\r\nSelected unit or pet phasemask changed to #phasemask with related world vision update for players. In creature case state saved to DB and persistent. In pet case change active until in game phase changed for owner, owner re-login, or GM-mode enable/disable..'),
('npc set spawndist',2,'Syntax: .npc set spawndist #dist\r\n\r\nAdjust spawndistance of selected creature to dist.'),
('npc set spawntime',2,'Syntax: .npc set spawntime #time \r\n\r\nAdjust spawntime of selected creature to time.'),
('npc add temp',2,'Syntax: .npc add temp\r\n\r\nAdds temporary NPC, not saved to database.'),
('npc textemote',1,'Syntax: .npc textemote #emoteid\r\n\r\nMake the selected creature to do textemote with an emote of id #emoteid.'),
('npc whisper',1,'Syntax: .npc whisper #playerguid #text\r\nMake the selected npc whisper #text to  #playerguid.'),
('npc yell',1,'Syntax: .npc yell $message\nMake selected creature yell specified message.')
);
