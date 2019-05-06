-- Dumphry <Blacksmithing Trainer>
UPDATE `creature_template` SET `npcflag` = `npcflag` |16 |64, `trainer_type` = 2 WHERE `entry` = 21209;
DELETE FROM `npc_trainer` WHERE `ID`=21209;
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES (21209,-201004,0,0,0,0);
