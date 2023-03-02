DELETE FROM trinity_string WHERE entry=1352;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc2`, `content_loc3`, `content_loc6`, `content_loc8`) 
VALUES ('1352', 'The battle for Temple of Kotmogu begins in 2 minutes!', 'La bataille pour Temple de Kotmogu commence en 2 minutes.', 'La bataille gießen Temple de Kotmogu beginnen en 2 Minuten.', 'La bataille verter Temple de Kotmogu comenzará en 2 minutos.', 'Ла Батай залить Храм-де-Kotmogu начать ан 2 минут.');
UPDATE `gameobject_template` SET `name`='Orb of Power' WHERE entry BETWEEN 212091 AND 212094;
UPDATE `battleground_template` SET `Name_loc1`='Silvershard Mines' WHERE (`id`='708');
