-- Add 10 reputation gaining from killing NPC Monstrous Kaliri towards Sha'tari Skyguard
DELETE FROM  `creature_onkill_reputation` WHERE `creature_id`=23051;
INSERT INTO `creature_onkill_reputation` (`creature_id`,`RewOnKillRepFaction1`,`MaxStanding1`,`RewOnKillRepValue1`) VALUES
(23051,1031,7,10);
