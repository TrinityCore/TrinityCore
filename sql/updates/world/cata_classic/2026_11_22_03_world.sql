UPDATE `creature_template_difficulty` SET `GoldMin`= 0, `GoldMax`= 3 WHERE `Entry`= 39317;
UPDATE `quest_template_addon` SET `PrevQuestID`= 25127 WHERE `ID` IN (2383,3087,3088,3089,3090,25138,25134);
UPDATE `creature_template_gossip` SET `MenuID`= 4652, `VerifiedBuild`= 15595 WHERE `CreatureID`= 3157 AND `MenuID`= 14003;
UPDATE `creature_template_gossip` SET `MenuID`= 4651, `VerifiedBuild`= 15595 WHERE `CreatureID`= 39206 AND `MenuID`= 14227;
UPDATE `creature_template_gossip` SET `MenuID`= 141, `VerifiedBuild`= 15595 WHERE `CreatureID`= 3155 AND `MenuID`= 14001;
UPDATE `creature_template_gossip` SET `MenuID`= 11185, `VerifiedBuild`= 15595 WHERE `CreatureID`= 39214 AND `MenuID`= 14191;
UPDATE `creature_template_gossip` SET `MenuID`= 523, `VerifiedBuild`= 15595 WHERE `CreatureID`= 3153 AND `MenuID`= 13999;

DELETE FROM `creature_trainer` WHERE `CreatureID` IN (3157, 39206, 3155, 39214, 3153);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(3157, 134, 4652, 0),
(39206, 44, 4651, 0),
(3155, 17, 141, 0),
(39214, 15, 11185, 0),
(3153, 145, 523, 0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`= 11185;
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(11185, 112083, 0, 3, 'I seek training in the ways of the Hunter.', 7643, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 59185),
(11185, 112084, 1, 0, 'I wish to unlearn my talents.', 8271, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 59185), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(11185, 112085, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 59185);

UPDATE `trainer_spell` SET `MoneyCost`=55, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=56641); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=90, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=1494); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=221400, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=83245); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=72900, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=83244); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=2505, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (83242,19884)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=14850, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=83243); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=20250, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (87506,20736,19879)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=199800, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=87493); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=3240, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=674); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1555, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=19503); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=13500, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (8737,82654,13813,1543)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=232200, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=82661); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=350, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (82243,5116)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=170, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=2973); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=610, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (1515,34026,1462)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=210600, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=77767); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=253800, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=51753); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=18900, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=77769); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=9450, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (53351,19801,19880)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=151200, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=53271); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=183600, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=19263); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=167400, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=34477); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=83700, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=20043); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=17550, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (19882,13809)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=10800, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (19878,1513)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=5400, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=19885); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=970, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (19883,13165,1978,2974)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=22950, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=13159); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=100, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (2641,6991,1494)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1855, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (6197,136)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=94500, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=34600); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=12150, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (13813,1543)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=4590, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (2643,5118)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1275, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (1130,781)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=8100, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=5384); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=21600, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=3045); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=6750, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=1499); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=3780, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=13795); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=60, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=56641); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=246000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=83245); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=81000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=83244); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=2785, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (83242,19884)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=16500, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=83243); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=22500, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (87506,20736,19879)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=222000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=87493); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=3600, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=674); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1730, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=19503); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=15000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (8737,82654)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=258000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=82661); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=390, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (82243,5116)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=190, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=2973); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=680, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (1515,34026,1462)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=234000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=77767); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=282000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=51753); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=21000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=77769); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=10500, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (53351,19801,19880)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=168000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=53271); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=204000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=19263); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=186000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=34477); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=93000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=20043); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=19500, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (19882,13809)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=12000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (19878,1513)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=6000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=19885); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1075, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (19883,13165,1978,2974)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=25500, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=13159); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=110, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (2641,6991)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=2060, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (6197,136)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=105000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=34600); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=5100, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (2643,5118)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1420, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (1130,781)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=9000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=5384); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=24000, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=3045); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=7500, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=1499); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=4200, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=13795); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=95, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=1494); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=233700, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=83245); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=76950, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=83244); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=2645, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (83242,19884)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=15675, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=83243); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=21375, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (87506,20736,19879)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=210900, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=87493); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=3420, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=674); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1645, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=19503); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=14250, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (8737,82654)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=245100, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=82661); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=370, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (82243,5116)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=180, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=2973); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=645, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (1515,34026,1462)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=222300, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=77767); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=267900, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=51753); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=19950, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=77769); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=9975, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (53351,19801,19880)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=159600, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=53271); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=193800, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=19263); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=176700, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=34477); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=88350, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=20043); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=18525, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (19882,13809)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=11400, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (19878,1513)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=5700, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=19885); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1025, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (19883,13165,1978,2974)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=24225, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=13159); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=105, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (2641,6991)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1955, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (6197,136)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=99750, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=34600); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=12825, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (13813,1543)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=4845, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (2643,5118)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1350, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId` IN (1130,781)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=8550, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=5384); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=22800, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=3045); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=7125, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=1499); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=3990, `VerifiedBuild`=59185 WHERE (`TrainerId`=40 AND `SpellId`=13795); -- MoneyCost recalculated
