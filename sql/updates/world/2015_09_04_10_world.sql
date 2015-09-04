--
DELETE FROM `creature_addon` WHERE `guid` IN(45823,656,657,658,659);
UPDATE `creature` SET `spawndist`=0 WHERE `guid`=142524;
UPDATE `creature` SET `spawndist`=5 WHERE `guid` IN (142553,142534,142510,142489);
UPDATE `creature` SET `equipment_id`=1 WHERE `guid`=43467;
