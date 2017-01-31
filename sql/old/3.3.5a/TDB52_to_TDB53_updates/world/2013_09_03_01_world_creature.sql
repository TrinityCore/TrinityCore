-- Delete 2 incorrectly spawned mobs
DELETE FROM `creature` WHERE `guid` IN (66177,84663) AND `map` = 530;
