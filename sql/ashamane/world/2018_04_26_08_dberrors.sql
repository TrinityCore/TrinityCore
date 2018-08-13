
-- Table `creature_template`
UPDATE `creature_template` SET `npcflag` = 4305 WHERE (entry = 4888);
UPDATE `creature_template` SET `npcflag` = 4307 WHERE (entry = 16583);
UPDATE `creature_template` SET `npcflag` = 4307 WHERE (entry = 16823);
UPDATE `creature_template` SET `npcflag` = 82 WHERE (entry = 56227);
UPDATE `creature_template` SET `npcflag` = 81 WHERE (entry = 19341);
UPDATE `creature_template` SET `npcflag` = 4305 WHERE (entry = 57620);
UPDATE `creature_template` SET `npcflag` = 81 WHERE (entry = 65043);
UPDATE `creature_template` SET `npcflag` = 80 WHERE (entry = 65114); --
UPDATE `creature_template` SET `npcflag` = 80 WHERE (entry = 95794);
UPDATE `creature_template` SET `npcflag` = 80 WHERE (entry = 84619);
UPDATE `creature_template` SET `npcflag` = 80 WHERE (entry = 98908);
UPDATE `creature_template` SET `npcflag` = 80 WHERE (entry = 98912);
UPDATE `creature_template` SET `npcflag` = 80 WHERE (entry = 99121);
UPDATE `creature_template` SET `npcflag` = 80 WHERE (entry = 99954);
UPDATE `creature_template` SET `npcflag` = 80 WHERE (entry = 104664);
UPDATE `creature_template` SET `npcflag` = 80 WHERE (entry = 107890);
UPDATE `creature_template` SET `npcflag` = 82 WHERE (entry = 43769);
UPDATE `creature_template` SET `npcflag` = 209 WHERE (entry = 18752);
UPDATE `creature_template` SET `npcflag` = 209 WHERE (entry = 18775);
UPDATE `creature_template` SET `npcflag` = 81 WHERE (entry = 19576);
UPDATE `creature_template` SET `npcflag` = 17 WHERE (entry = 47253);
UPDATE `creature_template` SET `npcflag` = 18 WHERE (entry = 48513);
UPDATE `creature_template` SET `npcflag` = 17 WHERE (entry = 96786);
UPDATE `creature_template` SET `npcflag` = 17 WHERE (entry = 97529);
DELETE FROM npc_trainer WHERE ID IN (20214,19341,98118);
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`, `Index`) VALUES ('19341', '-201004', '0', '0', '0', '0', '0');

