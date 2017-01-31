-- Gorilla Fang should always be able to drop (Exodius)
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = ABS(`ChanceOrQuestChance`) WHERE `item`=2799;
-- Update "Count" Ungula's Mandible drop rate does not require quest to drop it starts one (gecko32)
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = ABS(`ChanceOrQuestChance`) WHERE `item`=25459;
-- Tainted Hellboar Meat fix (ZxBiohazardZx)
UPDATE `quest_template` SET `RequiredSourceItemId1`=23270,`RequiredSourceItemCount1`=8 WHERE `Id`=9361;
