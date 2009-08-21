UPDATE `creature` SET `id` = '29519' WHERE `id` IN ('29520','29565','29566','29567');
						    
-- Temporary fix for The Endless Hunger		    
-- When the final fix is made in core/DB the following will revert it for UDB
-- May not fix YTDB or other DBs.

-- UPDATE `creature` SET `id` = '29519' WHERE `guid` IN ('128557','128558','128559');
-- UPDATE `creature` SET `id` = '29520' WHERE `guid` IN ('128561','128563');
-- UPDATE `creature` SET `id` = '29565' WHERE `guid` IN ('128740');
-- UPDATE `creature` SET `id` = '29566' WHERE `guid` IN ('128742','128743','128744');
-- UPDATE `creature` SET `id` = '29567' WHERE `guid` IN ('128747','128748','128749');
