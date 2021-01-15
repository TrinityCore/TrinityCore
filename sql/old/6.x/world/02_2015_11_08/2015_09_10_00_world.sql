-- Darkmoon Island (5)
UPDATE `creature_template` SET `npcflag` = `npcflag`|2 WHERE `entry` = 90473;

DELETE FROM `creature_queststarter` WHERE `id` IN (67370, 74056, 85519, 85546, 90473);
DELETE FROM `creature_questender` WHERE `id` IN (67370, 74056, 85519, 85546, 90473);

INSERT INTO `creature_queststarter` VALUES
(67370, 32175), -- Jeremy Feasel, Darkmoon Pet Battle!
(74056, 33756), -- Malle Earnhard, Let's Keep Racing!
(74056, 37910), -- Malle Earnhard, The Real Race
(74056, 37819), -- Malle Earnhard, Welcome to the Darkmoon Races
(85519, 36471), -- Christoph VonFeasel, A New Darkmoon Challenger!
(85546, 36481), -- Ziggie Sparks, Firebird's Challenge
(90473, 37868), -- Patti Earnhard, More Big Racing!
(90473, 37911); -- Patti Earnhard, The Real Big Race

INSERT INTO `creature_questender` VALUES
(67370, 32175), -- Jeremy Feasel, Darkmoon Pet Battle!
(74056, 33756), -- Malle Earnhard, Let's Keep Racing!
(74056, 37910), -- Malle Earnhard, The Real Race
(74056, 37819), -- Malle Earnhard, Welcome to the Darkmoon Races
(85519, 36471), -- Christoph VonFeasel, A New Darkmoon Challenger!
(85546, 36481), -- Ziggie Sparks, Firebird's Challenge
(90473, 37868), -- Patti Earnhard, More Big Racing!
(90473, 37911); -- Patti Earnhard, The Real Big Race


-- Depholm (1)
DELETE FROM `creature_queststarter` WHERE `id` IN (66815);
DELETE FROM `creature_questender` WHERE `id` IN (66815);

INSERT INTO `creature_queststarter` VALUES
(66815, 31973); -- Bordin Steadyfist, Bordin Steadyfist

INSERT INTO `creature_questender` VALUES
(66815, 31973); -- Bordin Steadyfist, Bordin Steadyfist
