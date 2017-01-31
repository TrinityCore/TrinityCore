-- A-Me 01 and Un'Goro Thunderer (only one) were emoting to be dead
UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid` IN (24268,24081);
