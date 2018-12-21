DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (39381, 48654, 39854, 48661, 39855, 48745, 39962, 48597, 41073, 48611, 39890, 48595, 39956, 48666, 39415, 48677, 39414, 48676, 39954, 48669, 39626, 48682, 39909, 48680, 40167, 48695, 40166, 48693, 40268, 48744, 40270, 48750, 39870, 48748, 40291, 48746, 40273, 48753, 40272, 48751, 39873, 48754, 39392, 48818, 40290, 48653, 40448, 48667, 40306, 48610, 39405, 48652);

-- Normal Mode
-- Grim Batol
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`) VALUES
(39381, 1162, 7, 0, 10, 0),
(39854, 1162, 7, 0, 10, 0),
(39855, 1162, 7, 0, 10, 0),
(39962, 1162, 7, 0, 10, 0),
(41073, 1162, 7, 0, 10, 0),
(39890, 1162, 7, 0, 10, 0),
(39956, 1162, 7, 0, 10, 0),
(39415, 1162, 7, 0, 10, 0),
(39414, 1162, 7, 0, 10, 0),
(39954, 1162, 7, 0, 10, 0),
(39626, 1162, 7, 0, 10, 0),
(39909, 1162, 7, 0, 10, 0),
(40167, 1162, 7, 0, 10, 0),
(40166, 1162, 7, 0, 10, 0),
(40268, 1162, 7, 0, 10, 0),
(40270, 1162, 7, 0, 10, 0),
(39870, 1162, 7, 0, 10, 0),
(40291, 1162, 7, 0, 10, 0),
(40273, 1162, 7, 0, 10, 0),
(40272, 1162, 7, 0, 10, 0),
(39873, 1162, 7, 0, 10, 0),
(39392, 1162, 7, 0, 10, 0),
(40290, 1162, 7, 0, 10, 0),
(40448, 1162, 7, 0, 10, 0),
(40306, 1162, 7, 0, 10, 0),
(39405, 1162, 7, 0, 10, 0);

UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 150 WHERE `creature_id`= 39625;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 150 WHERE `creature_id`= 40177;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 150 WHERE `creature_id`= 40319;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 150 WHERE `creature_id`= 40484;

-- Heroic Mode
-- Grim Batol
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`) VALUES
(48654, 1162, 7, 0, 15, 0),
(48661, 1162, 7, 0, 15, 0),
(48745, 1162, 7, 0, 15, 0),
(48597, 1162, 7, 0, 15, 0),
(48611, 1162, 7, 0, 15, 0),
(48595, 1162, 7, 0, 15, 0),
(48666, 1162, 7, 0, 15, 0),
(48677, 1162, 7, 0, 15, 0),
(48676, 1162, 7, 0, 15, 0),
(48669, 1162, 7, 0, 15, 0),
(48682, 1162, 7, 0, 15, 0),
(48680, 1162, 7, 0, 15, 0),
(48695, 1162, 7, 0, 15, 0),
(48693, 1162, 7, 0, 15, 0),
(48744, 1162, 7, 0, 15, 0),
(48750, 1162, 7, 0, 15, 0),
(48748, 1162, 7, 0, 15, 0),
(48746, 1162, 7, 0, 15, 0),
(48753, 1162, 7, 0, 15, 0),
(48751, 1162, 7, 0, 15, 0),
(48754, 1162, 7, 0, 15, 0),
(48818, 1162, 7, 0, 15, 0),
(48653, 1162, 7, 0, 15, 0),
(48667, 1162, 7, 0, 15, 0),
(48610, 1162, 7, 0, 15, 0),
(48652, 1162, 7, 0, 15, 0);

UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 48337;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 48702;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 48784;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 48822;
