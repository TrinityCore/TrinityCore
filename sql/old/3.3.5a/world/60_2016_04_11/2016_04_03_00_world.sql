-- Remove duplicate spawn of "Big Roy" (24785)
DELETE FROM `creature` WHERE `guid`=203496 AND `id`=24785;
