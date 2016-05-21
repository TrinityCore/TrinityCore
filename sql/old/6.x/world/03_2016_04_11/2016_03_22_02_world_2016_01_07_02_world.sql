-- fix a start-up warning
UPDATE `creature` SET `spawndist`=0 WHERE `guid` IN (79007,79008,79009);
