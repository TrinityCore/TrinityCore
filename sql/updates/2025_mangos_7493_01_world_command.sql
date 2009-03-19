/*ALTER TABLE db_version CHANGE COLUMN required_7472_01_mangos_mangos_string required_7493_01_mangos_command bit;*/

DELETE FROM `command` WHERE `name` IN ('gobject near','gobject phase','gobject setphase');

INSERT INTO `command` VALUES
('gobject near',2,'Syntax: .gobject near  [#distance]\r\n\r\nOutput gameobjects at distance #distance from player. Output gameobject guids and coordinates sorted by distance from character. If #distance not provided use 10 as default value.'),
('gobject setphase',2,'Syntax: .gobject setphase #guid #phasemask\r\n\r\nGameobject with DB guid #guid phasemask changed to #phasemask with related world vision update for players. Gameobject state saved to DB and persistent.');