-- Path and formation added but aren't used
UPDATE `creature` SET `MovementType` = 2 WHERE `id` = 1437;
-- Creatures will never use dist and angle without movement(these shouldn't move)
UPDATE `creature_formations` SET `dist` = 0, `angle` = 0 WHERE `leaderGUID` IN (54579,138249,138252);
