DELETE FROM `gameobject` WHERE `guid` IN(62187,62190,62198);
UPDATE `smart_scripts` SET `target_type`=7 WHERE  `entryorguid`=11448 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `gameobject` SET `phaseMask`=64 WHERE  `guid`IN(16974,16976,99723);
