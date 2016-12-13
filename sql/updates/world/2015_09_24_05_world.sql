-- Vol'jin Shipyard Start and Endings

DELETE FROM `creature_queststarter` WHERE `id` IN (92400);
DELETE FROM `creature_questender` WHERE `id` IN (92400);

INSERT INTO `creature_queststarter` VALUES
(92400, 38574), -- Vol'jin, All Hands on Deck
(92400, 38568); -- Vol'jin, We Need a Shipwright

INSERT INTO `creature_questender` VALUES
(92400, 38567), -- Vol'jin, Garrison Campaign: War Council
(92400, 38573); -- Vol'jin, Nothing Remains
