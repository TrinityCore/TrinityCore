-- strings used by the BG
DELETE FROM trinity_string WHERE entry > 1204 AND entry <1225;
INSERT INTO trinity_string (`entry`,`content_default`) VALUES
(1205,'The battle will begin in two minutes.'),
(1206,'The battle will begin in 1 minute.'),
(1208,'The battle has begun!'),
(1207,'The battle will begin in 30 seconds!'),
(1209,'the alliance keep'),
(1210,'the horde keep'),
(1211,'%s wins!'),
(1212,'The west gate of %s is destroyed!'),
(1213,'The east gate of %s is destroyed!'),
(1214,'The south gate of %s is destroyed!'),
(1215,'The north gate of %s is destroyed!'),
(1216,'$n has assaulted the %s'),
(1217,'$n has defended the %s'),
(1218,'$n claims the %s! If left unchallenged, the %s will control it in 1 minute!'),
(1219,'The %s has taken the %s'),
(1220,'Workshop'),
(1221,'Docks'),
(1222,'Refinery'),
(1223,'Quarry'),
(1224,'Hangar');