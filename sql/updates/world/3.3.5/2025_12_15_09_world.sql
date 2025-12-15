--
UPDATE `creature` SET `spawnMask` = `spawnMask`&~(1) WHERE `guid` IN (68283,68284) AND `id1` = 31104;
