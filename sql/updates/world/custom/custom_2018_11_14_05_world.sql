DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (49667, 49660, 49662, 49663, 49647, 49665, 49664, 49661);

-- Heroic Mode
-- Stonecore
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`) VALUES
(49667, 1162, 7, 0, 15, 0),
(49660, 1162, 7, 0, 15, 0),
(49662, 1162, 7, 0, 15, 0),
(49663, 1162, 7, 0, 15, 0),
(49647, 1162, 7, 0, 15, 0),
(49665, 1162, 7, 0, 15, 0),
(49664, 1162, 7, 0, 15, 0),
(49661, 1162, 7, 0, 15, 0);

UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 49642;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 49538;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 49654;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 49624;
