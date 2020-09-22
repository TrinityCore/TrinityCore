UPDATE `creature_template` SET `npcflag`= 1 | 2 | 16 | 32 WHERE `entry` IN (5497, 331);
UPDATE `creature_template` SET `gossip_menu_id`= 5061 WHERE `entry`= 51998;
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (5491, 928, 5492, 43277, 44247, 44249, 44396, 44395, 5504, 5489, 376, 5484, 11397, 5498, 5497, 331, 20407, 44394, 44393, 45306, 5496, 918, 13283, 51998);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
-- Stormwind City
-- Paladin
(5491, 164, 4470, 0),
(928, 164, 4470, 0),
(5492, 164, 4470, 0),
-- Hunter
(43277, 40, 11817, 0),
(44247, 40, 11817, 0),
(44249, 40, 11817, 0),
-- Druid
(44396, 39, 11829, 0),
(44395, 39, 11829, 0),
(5504, 39, 4508, 0),
-- Priest
(5489, 3, 4467, 0),
(376, 3, 4466, 0),
(5484, 3, 4468, 0),
(11397, 3, 3643, 0),
-- (45306, 3, 12004, 0), -- Needs gossip menu options.
-- Mage
(5498, 135, 4484, 0),
(5497, 135, 4463, 0),
(331, 135, 4486, 0),
-- Shaman
(20407, 124, 8110, 0),
(44394, 124, 12529, 0),
(44393, 124, 12529, 0),
-- Warlock
(5496, 154, 4504, 0),
-- Rogue
(918, 33, 4502, 0),
(13283, 33, 5061, 0),
(51998, 33, 5061, 0); -- Needs gossip 

UPDATE `conditions` SET `ConditionValue1`= 128 WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 4463 AND `SourceEntry`= 3976;
UPDATE `conditions` SET `ConditionValue1`= 128 WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 4463;
UPDATE `conditions` SET `ConditionValue1`= 1 | 2 | 4 | 8 | 16 | 32 | 64 | 256 | 1024 WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 4463 AND `SourceEntry`= 3977;
UPDATE `gossip_menu_option` SET `OptionIcon`= 3 WHERE `MenuId`= 4463 AND `OptionIndex`= 0;
