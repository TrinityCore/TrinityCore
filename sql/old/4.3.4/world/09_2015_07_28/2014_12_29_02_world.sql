--
UPDATE `creature` SET `spawndist`=0 WHERE `guid` IN (99225, 99226, 99233, 99246);
DELETE FROM `creature_addon` WHERE `guid`=99232;
UPDATE `creature` SET `orientation`=0 WHERE `guid`=29978;
