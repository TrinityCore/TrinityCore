-- corrected quests in creature_involvedrelation and creature_questrelation
--  Horde npcs 14726 Rashona Straglash
UPDATE `creature_involvedrelation` SET  `quest` = 7824 WHERE `id` =14726 AND `quest` =7836;
UPDATE `creature_questrelation` SET `quest` = 7824 WHERE `id` =14726 AND `quest` =7836;
UPDATE `creature_involvedrelation` SET `quest` = 7832 WHERE `id` =14726 AND `quest` =7837;
UPDATE `creature_questrelation` SET `quest` = 7832 WHERE `id` =14726 AND `quest` =7837;

-- NPC 14727 Vehena
UPDATE `creature_involvedrelation` SET `quest` = 7836 WHERE `id` =14727 AND `quest` =7832;
UPDATE `creature_questrelation` SET `quest` = 7836 WHERE  `id` =14727 AND `quest` =7832;
UPDATE `creature_involvedrelation` SET `quest` = 7837 WHERE `id` =14727 AND `quest` =7824;
UPDATE `creature_questrelation` SET  `quest` = 7837 WHERE  `id` =14727 AND `quest` =7824;

-- Alliance npcs 14725 Raedon Dustriker
UPDATE `creature_involvedrelation` SET `quest` = 10352 WHERE `id` =14725 AND `quest` =7792;
UPDATE `creature_questrelation` SET `quest` = 10352 WHERE  `id` =14725 AND `quest` =7792;
UPDATE `creature_involvedrelation` SET `quest` = 10354 WHERE `id` =14725 AND `quest` =7798;
UPDATE `creature_questrelation` SET `quest` = 10354 WHERE  `id` =14725 AND `quest` =7798;

-- NPC 20604 Dugiru
UPDATE `creature_involvedrelation` SET `quest` = 7792 WHERE `id` =20604 AND `quest` =10352;
UPDATE `creature_questrelation` SET `quest` = 7792 WHERE  `id` =20604 AND `quest` =10352;
UPDATE `creature_involvedrelation` SET `quest` = 7798 WHERE `id` =20604 AND `quest` =10354;
UPDATE `creature_questrelation` SET `quest` = 7798 WHERE  `id` =20604 AND `quest` =10354;

-- NPC 14723 Mistina Steelshield
UPDATE `creature_involvedrelation` SET `quest` = 7802 WHERE `id` =14723 AND `quest` =7807;
UPDATE `creature_questrelation` SET `quest` = 7802 WHERE  `id` =14723 AND `quest` =7807;
UPDATE `creature_involvedrelation` SET `quest` = 7803 WHERE `id` =14723 AND `quest` =7808;
UPDATE `creature_questrelation` SET `quest` = 7803 WHERE  `id` =14723 AND `quest` =7808;

-- NPC 14724 Bublo Acerbus
UPDATE `creature_involvedrelation` SET `quest` = 7807 WHERE `id` =14724 AND `quest` =7802;
UPDATE `creature_questrelation` SET `quest` = 7807 WHERE  `id` =14724 AND `quest` =7802;
UPDATE `creature_involvedrelation` SET `quest` = 7808 WHERE `id` =14724 AND `quest` =7803;
UPDATE `creature_questrelation` SET `quest` = 7808 WHERE  `id` =14724 AND `quest` =7803;
