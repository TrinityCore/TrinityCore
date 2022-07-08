-- Mechanar
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 15 WHERE `creature_id` IN (21522,21523,21524,21527,21532,21539,21540,21541,21543);
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 6 WHERE `creature_id` IN (19716);
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 8 WHERE `creature_id` IN (21531);
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` IN (19735);
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` IN (21542);

DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (19712,21528);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES
(19712, 935, 0, 7, 0, 12, 0, 0, 0, 0),
(21528, 935, 0, 7, 0, 15, 0, 0, 0, 0);

DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (20478,21062,20481,21538);

-- Arcatraz
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 15 WHERE `creature_id` = 21585;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20869;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21586;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 15 WHERE `creature_id` = 21587;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20867;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21591;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20879;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21595;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 12 WHERE `creature_id` = 22346; -- same value in heroic, not a typo
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 15 WHERE `creature_id` = 21596;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 15 WHERE `creature_id` = 21597;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20898;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21598;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 240 WHERE `creature_id` = 20912;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 21599;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20875;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21604;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20873;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21605;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20864;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21608;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 18 WHERE `creature_id` = 20901;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 23 WHERE `creature_id` = 21610;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 18 WHERE `creature_id` = 20902;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 23 WHERE `creature_id` = 21611;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20882;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21613;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20866;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21614;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20883;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21615;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20881;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21619;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 24 WHERE `creature_id` = 20900;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 21621;

DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (21617,21588,21589,21593,21594,21606,21616,21618);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES
(21617, 935, 0, 7, 0, 30, 0, 0, 0, 0),
(21588, 935, 0, 7, 0, 30, 0, 0, 0, 0),
(21589, 935, 0, 7, 0, 30, 0, 0, 0, 0),
(21593, 935, 0, 7, 0, 30, 0, 0, 0, 0),
(21594, 935, 0, 7, 0, 30, 0, 0, 0, 0),
(21606, 935, 0, 7, 0, 30, 0, 0, 0, 0),
(21616, 935, 0, 7, 0, 30, 0, 0, 0, 0),
(21618, 935, 0, 7, 0, 30, 0, 0, 0, 0);

-- Protean Horror never gives rep, even if not summoned
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (21303,21467,21466,20865,21607,21395,21346,20904,21304);

-- Botanica
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 3 WHERE `creature_id` = 18587; -- requires max standing or wrong
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 12 WHERE `creature_id` = 21552; -- requires max standing or wrong
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 2 WHERE `creature_id` = 19608;
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 12 WHERE `creature_id` = 19557;

DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (19962,19969,19964,19949,20083,20078,19920,19919,19958);

-- Outside of Tempest Keep
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (17261,22892);
