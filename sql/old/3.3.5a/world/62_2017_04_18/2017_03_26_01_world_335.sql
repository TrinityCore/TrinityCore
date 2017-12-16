-- Verifonix <The Surveyor>
UPDATE `creature_template` SET `faction`=47 WHERE `entry`=14492;

DELETE FROM `creature_onkill_reputation` WHERE `creature_id`=14492;
INSERT INTO `creature_onkill_reputation` (`creature_id`,`RewOnKillRepFaction1`,`RewOnKillRepFaction2`,`MaxStanding1`,`IsTeamAward1`,`RewOnKillRepValue1`,`MaxStanding2`,`IsTeamAward2`,`RewOnKillRepValue2`,`TeamDependent`) VALUES
(14492, 21, 0, 5, 0, 5, 0, 0, 0, 0);
