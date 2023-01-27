-- fix event start and end time for 2015
UPDATE `game_event` SET `eventEntry`='2', `start_time`='2015-12-15 05:00:00', `end_time`='2015-12-30 19:00:00', `occurence`='525600', `length`='25920', `holiday`='141', `description`='Winter Veil', `world_event`='0' WHERE (`eventEntry`='2');
-- fix phasing for some vinter veil objects
UPDATE gameobject SET phaseMask=1 WHERE id in(187235, 206937, 178428, 178429,178430, 178431, 178432, 178438, 180769, 178645, 178649,178805, 208578, 181392, 187567, 187194, 181401, 180472);
DELETE FROM `game_event_gameobject` WHERE guid IN(234114, 234115, 234116); 
-- insert some objects into the event
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES ('2', '234114');
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES ('2', '234115');
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES ('2', '234116');

-- these creatures belong to another event
DELETE FROM `game_event_creature` WHERE guid IN(331894,331895,331893);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES ('8', '331894');
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES ('8', '331895');
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES ('8', '331893');

