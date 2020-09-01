UPDATE `creature_template` SET `gossip_menu_id`= 0 WHERE `entry` IN (3603, 4258, 4752, 4753, 4772, 5164, 7230, 7231, 7946, 7953, 7954, 9584, 10578, 11146, 11177, 11178, 20914, 45540);

-- remove outdated / hacky npcflags from trainer
UPDATE `creature_template` SET `npcflag`= 1 WHERE `entry`= 7232;
UPDATE `creature_template` SET `npcflag`= 16 | 64 WHERE `entry` IN (3603, 3604, 30713, 9584);
UPDATE `creature_template` SET `npcflag`= 1 | 16 | 64 WHERE `entry` IN (44582, 1346);
UPDATE `creature_template` SET `npcflag`= 1 | 16 | 64 WHERE `entry`= 5493;
UPDATE `creature_template` SET `npcflag`= 1 | 2 | 16 | 64 WHERE `entry` IN (1317, 5566, 5518);

-- 4.3.4 sniff confirmed trainer
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (44582, 5493, 1346, 5566, 5511, 5518, 5482, 5564, 1292, 44238);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(44582, 2, 11861, 0),
(5493, 10, 645, 0),
(1346, 163, 4353, 0),
(5566, 101, 643, 0),
(5511, 58, 581, 0),
(5518, 407, 4146, 0),
(5482, 136, 646, 0),
(5564, 143, 4203, 0),
(1292, 155, 648, 0),
(44238, 373, 11821, 0);
