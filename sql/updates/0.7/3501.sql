--
-- Enhancements to the waypoint system
--
-- text1..tex5 -> Mob can say up to five texts (one is choosen)
-- aiscript -> An AI script can be executed, when the mob reaches a waypoint, see wpAI.h
-- emote -> a mob can do an emote, eg cutting wood, laughing, etc (make sure you set a waittime, otherwise emote may be omitted)
-- spell -> mob can cast a spell, when he reaches a waypoint
-- wpguid -> if the GM wants to see the waypoints, whisps are spawned, which can only be seen by a GM
--  The GUID of the whisp is stored here
ALTER TABLE `creature_movement` ADD COLUMN `text1` varchar(255) default NULL AFTER `waittime`,
ADD COLUMN `text2` varchar(255) default NULL AFTER `text1`,
ADD COLUMN `text3` varchar(255) default NULL AFTER `text2`,
ADD COLUMN `text4` varchar(255) default NULL AFTER `text3`,
ADD COLUMN `text5` varchar(255) default NULL AFTER `text4`,
ADD COLUMN `aiscript` varchar(255) default NULL AFTER `text5`,
ADD COLUMN `emote` int(10) unsigned default '0' AFTER `aiscript`,
ADD COLUMN `spell` int(5) unsigned default '0' AFTER `emote`,
ADD COLUMN `wpguid` int(11) default '0' AFTER `spell`;

-- The visual waypoint
DELETE FROM creature_template WHERE entry='1';
INSERT INTO creature_template
  (entry, modelid_m, modelid_f, name, subname, minlevel, maxlevel, minhealth, maxhealth, minmana, maxmana, armor, faction, npcflag, speed, rank, mindmg, maxdmg, attackpower, baseattacktime, rangeattacktime, flags, dynamicflags, size, family, bounding_radius, trainer_type, trainer_spell, class, race, minrangedmg, maxrangedmg, rangedattackpower, combat_reach, type, civilian, flag1, equipmodel1, equipmodel2, equipmodel3, equipinfo1, equipinfo2, equipinfo3, equipslot1, equipslot2, equipslot3, lootid, pickpocketloot, skinloot, resistance1, resistance2, resistance3, resistance4, resistance5, resistance6, spell1, spell2, spell3, spell4, mingold, maxgold, AIName, MovementType, ScriptName)
VALUES
  (1, 10045, 0, 'Waypoint (Only GM can see it)', 'Visual', 1, 1, 64, 64, 0, 0, 0, 35, 0, '0.91', 0, 14, 15, 100, 2000, 2200, 4096, 0, '0.5', 8, 2, 0, 0, 0, 0, '1.76', '2.42', 100, '2.56', 8, 1, 5242886, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, '');

-- New commands
DELETE FROM `command` where `name` = 'wp' and `security` = '2';
DELETE FROM `command` where `name` = 'wp add' and `security` = '2';
DELETE FROM `command` where `name` = 'wp modify' and `security` = '2';
DELETE FROM `command` where `name` = 'wp show' and `security` = '2';

INSERT INTO command (name, security, help) VALUES
("wp", 2, "Using WP Command:\r\nEach Waypoint Command has it's own description!"),
("wp add", 2, "Syntax: .wp add [#creature_guid or Select a Creature]"),
("wp modify", 2, "Syntax: .wp modify [#creature_guid or Select a Creature]\r\nadd - Add a waypoint after the selected visual\r\nimport $filename for selected npc\r\nexport $filename for selected npc\r\nwaittime $time\r\nemote ID\r\nspell ID\r\ntext1| text2| text3| text4| text5 <text>\r\nmodel1 ID\r\nmodel2 ID\r\naiscript $Name\r\nmove(moves wp to player pos)\r\ndel (deletes the wp)\r\n\r\nOnly one parameter per time!"),
("wp show", 2, "Syntax: .wp show [#creature_guid or Select a Creature]\r\non\r\nfirst\r\nlast\r\noff\r\ninfo\r\n\r\nFor using info you have to do first show on and than select a Visual-Waypoint and do the show info!");
