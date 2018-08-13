DELETE FROM creature WHERE guid = 30000015;
INSERT INTO creature (guid, id, map, zoneId, areaId, position_x, position_y, position_z, orientation, spawntimesecs, curhealth) VALUES
(30000015, 11980, 530, 3520, 3939, -4206, 333, 119, 1.44, 600, 95000);

UPDATE creature SET position_x = -4200 , position_y = 381 , position_z = 118 WHERE guid = 77862;
