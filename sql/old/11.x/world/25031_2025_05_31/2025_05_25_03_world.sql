-- delete duplicate stratholme service entrance gates
DELETE FROM `gameobject` WHERE `guid` IN (200250, 200964, 203081, 212816, 216442);
