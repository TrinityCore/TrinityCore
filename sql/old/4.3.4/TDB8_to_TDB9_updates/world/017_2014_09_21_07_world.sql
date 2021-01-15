-- ModelID Fix For NPC: 21749
-- Also Remove Dwarf ModelID From ModelID of 21749
DELETE FROM `creature_model_info` WHERE `modelid` IN (20447, 20448, 20449, 20450, 18790);
INSERT INTO `creature_model_info` (`modelid`, `bounding_radius`, `combat_reach`, `gender`, `modelid_other_gender`) VALUES
(20447, 0.372, 1.5, 0, 20449), -- Male Green Orc
(20448, 0.372, 1.5, 0, 20450), -- Male Dark Green Orc
(20449, 0.236, 1.5, 1, 20448), -- Female Dark Green Orc
(20450, 0.236, 1.5, 1, 20447), -- Female Green Orc
(18790, 0.347, 1.5, 1, 18791); -- Dwarf
