ALTER TABLE db_version CHANGE COLUMN required_7209_01_mangos_spell_bonus_data required_7214_01_mangos_command bit;

DELETE FROM `command` WHERE `name` IN ('gps','modify phase','npc phase','gobject phase');
INSERT INTO `command` VALUES
('gps',1,'Syntax: .gps [$name|$shift-link]\r\n\r\nDisplay the position information for a selected character or creature (also if player name $name provided then for named player, or if creature/gameobject shift-link provided then pointed creature/gameobject if it loaded). Position information includes X, Y, Z, and orientation, map Id and zone Id'),
('modify phase',3,'Syntax: .modify phase #phasemask\r\n\r\nSelected character phasemask changed to #phasemask with related world vision update. Change active until in game phase changed, or GM-mode enable/disable, or re-login. Character pts pasemask update to same value.'),
('npc phase',3,'Syntax: .npc phase #phasemask\r\n\r\nSelected unit or pet phasemask changed to #phasemask with related world vision update for players. In creature case state saved to DB and persistent. In pet case change active until in game phase changed for owner, owner re-login, or GM-mode enable/disable..'),
('gobject phase',3,'Syntax: .gobject phase #guid #phasemask\r\n\r\nGameobject with DB guid #guid phasemask changed to #phasemask with related world vision update for players. Gameobject state saved to DB and persistent.');
