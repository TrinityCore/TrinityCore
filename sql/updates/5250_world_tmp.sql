UPDATE `creature` SET `id` = '29519' WHERE `guid` IN ('128557','128558','128559','128561','128563','128740','128742','128743','128744','128747','128748','128749');

-- Temporary fix for The Endless Hunger
-- When the final fix is made in core/DB the following will revert it

-- UPDATE `creature` SET `id` = '29519' WHERE `guid` IN ('128557','128558','128559');
-- UPDATE `creature` SET `id` = '29520' WHERE `guid` IN ('128561','128563');
-- UPDATE `creature` SET `id` = '29565' WHERE `guid` IN ('128740');
-- UPDATE `creature` SET `id` = '29566' WHERE `guid` IN ('128742','128743','128744');
-- UPDATE `creature` SET `id` = '29567' WHERE `guid` IN ('128747','128748','128749');
