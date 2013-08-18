-- Fixing some Gameobjects which state was "24"

UPDATE `world`.`gameobject` SET `state`=1 WHERE  `state`=24;
