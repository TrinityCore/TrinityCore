-- Fix Report to Gryan Stoutmantle creature_questrelation values by nelegalno
-- Closes #4461

DELETE FROM `creature_questrelation` WHERE `quest` = 109;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES
(233, 109), -- Farmer Saldean
(237, 109), -- Farmer Furlbrow
(240, 109), -- Marshal Dughan
(261, 109), -- Guard Thomas
(294, 109), -- Marshal Haggard
(963, 109); -- Deputy Rainer
