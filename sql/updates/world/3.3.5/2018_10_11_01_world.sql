-- 
DELETE FROM `npc_text` WHERE `ID` IN (10201, 10638);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`) VALUES
(10201,"...they told us not to go... but we went anyway... they told us not to go... but we went anyway...","...they told us not to go... but we went anyway... they told us not to go... but we went anyway...",18578,0,1,0,0,0,0,0,0),
(10638,"You are always welcome with us here in the Raven's Wood, $n.","",19951,0,1,0,0,0,0,0,0);

DELETE FROM `gossip_menu` WHERE (`MenuId`=8206 AND `TextId`=10201);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(8206, 10201, 26124); -- 20876 (Human Refugee)

DELETE FROM `gossip_menu` WHERE (`MenuId`=8736 AND `TextId`=11056) OR (`MenuId`=8506 AND `TextId`=10638) OR (`MenuId`=8508 AND `TextId`=10641);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(8736, 11056, 26124), -- 23473 (Aether-tech Apprentice)
(8506, 10638, 26124), -- 22215 (Treebole)
(8508, 10641, 26124); -- 22053 (Mosswood the Ancient)
