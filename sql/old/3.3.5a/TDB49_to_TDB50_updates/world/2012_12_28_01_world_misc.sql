-- fix startups
UPDATE `creature` SET `MovementType`=0 WHERE `id`=3939 AND `guid` BETWEEN 48823 AND 45831;
