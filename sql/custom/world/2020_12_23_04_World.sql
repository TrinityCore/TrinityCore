-- fix spawndifficulties again

UPDATE `gameobject` SET `spawndifficulties` = '', `phaseid` = 0, `areaid` = 1519, `zoneid` = 1519 WHERE `guid` = 500000 and `id` = 215457;

-- DELETE temp spawn

DELETE FROM `gameobject` WHERE `guid` = 1001028 and `id` = 215457;
