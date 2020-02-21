-- 
ALTER TABLE `npc_text`
CHANGE COLUMN `em0_0` `EmoteDelay0_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Probability0`,
CHANGE COLUMN `em0_1` `Emote0_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay0_0`,
CHANGE COLUMN `em0_2` `EmoteDelay0_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote0_0`,
CHANGE COLUMN `em0_3` `Emote0_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay0_1`,
CHANGE COLUMN `em0_4` `EmoteDelay0_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote0_1`,
CHANGE COLUMN `em0_5` `Emote0_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay0_2`,
CHANGE COLUMN `em1_0` `EmoteDelay1_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Probability1`,
CHANGE COLUMN `em1_1` `Emote1_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay1_0`,
CHANGE COLUMN `em1_2` `EmoteDelay1_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote1_0`,
CHANGE COLUMN `em1_3` `Emote1_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay1_1`,
CHANGE COLUMN `em1_4` `EmoteDelay1_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote1_1`,
CHANGE COLUMN `em1_5` `Emote1_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay1_2`,
CHANGE COLUMN `em2_0` `EmoteDelay2_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Probability2`,
CHANGE COLUMN `em2_1` `Emote2_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay2_0`,
CHANGE COLUMN `em2_2` `EmoteDelay2_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote2_0`,
CHANGE COLUMN `em2_3` `Emote2_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay2_1`,
CHANGE COLUMN `em2_4` `EmoteDelay2_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote2_1`,
CHANGE COLUMN `em2_5` `Emote2_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay2_2`,
CHANGE COLUMN `em3_0` `EmoteDelay3_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Probability3`,
CHANGE COLUMN `em3_1` `Emote3_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay3_0`,
CHANGE COLUMN `em3_2` `EmoteDelay3_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote3_0`,
CHANGE COLUMN `em3_3` `Emote3_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay3_1`,
CHANGE COLUMN `em3_4` `EmoteDelay3_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote3_1`,
CHANGE COLUMN `em3_5` `Emote3_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay3_2`,
CHANGE COLUMN `em4_0` `EmoteDelay4_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Probability4`,
CHANGE COLUMN `em4_1` `Emote4_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay4_0`,
CHANGE COLUMN `em4_2` `EmoteDelay4_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote4_0`,
CHANGE COLUMN `em4_3` `Emote4_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay4_1`,
CHANGE COLUMN `em4_4` `EmoteDelay4_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote4_1`,
CHANGE COLUMN `em4_5` `Emote4_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay4_2`,
CHANGE COLUMN `em5_0` `EmoteDelay5_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Probability5`,
CHANGE COLUMN `em5_1` `Emote5_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay5_0`,
CHANGE COLUMN `em5_2` `EmoteDelay5_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote5_0`,
CHANGE COLUMN `em5_3` `Emote5_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay5_1`,
CHANGE COLUMN `em5_4` `EmoteDelay5_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote5_1`,
CHANGE COLUMN `em5_5` `Emote5_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay5_2`,
CHANGE COLUMN `em6_0` `EmoteDelay6_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Probability6`,
CHANGE COLUMN `em6_1` `Emote6_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay6_0`,
CHANGE COLUMN `em6_2` `EmoteDelay6_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote6_0`,
CHANGE COLUMN `em6_3` `Emote6_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay6_1`,
CHANGE COLUMN `em6_4` `EmoteDelay6_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote6_1`,
CHANGE COLUMN `em6_5` `Emote6_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay6_2`,
CHANGE COLUMN `em7_0` `EmoteDelay7_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Probability7`,
CHANGE COLUMN `em7_1` `Emote7_0` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay7_0`,
CHANGE COLUMN `em7_2` `EmoteDelay7_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote7_0`,
CHANGE COLUMN `em7_3` `Emote7_1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay7_1`,
CHANGE COLUMN `em7_4` `EmoteDelay7_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Emote7_1`,
CHANGE COLUMN `em7_5` `Emote7_2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `EmoteDelay7_2`;

UPDATE `npc_text` AS a
INNER JOIN `broadcast_text` AS b ON a.`BroadcastTextID0`= b.`ID`
SET 
a.`EmoteDelay0_0`= b.`EmoteDelay1`,
a.`Emote0_0`= b.`EmoteID1`,
a.`EmoteDelay0_1`= b.`EmoteDelay2`,
a.`Emote0_1`= b.`EmoteID2`,
a.`EmoteDelay0_2`= b.`EmoteDelay3`,
a.`Emote0_2`= b.`EmoteID3`;

UPDATE `npc_text` AS a
INNER JOIN `broadcast_text` AS b ON a.`BroadcastTextID1`= b.`ID`
SET 
a.`EmoteDelay1_0`= b.`EmoteDelay1`,
a.`Emote1_0`= b.`EmoteID1`,
a.`EmoteDelay1_1`= b.`EmoteDelay2`,
a.`Emote1_1`= b.`EmoteID2`,
a.`EmoteDelay1_2`= b.`EmoteDelay3`,
a.`Emote1_2`= b.`EmoteID3`;

UPDATE `npc_text` AS a
INNER JOIN `broadcast_text` AS b ON a.`BroadcastTextID2`= b.`ID`
SET 
a.`EmoteDelay2_0`= b.`EmoteDelay1`,
a.`Emote2_0`= b.`EmoteID1`,
a.`EmoteDelay2_1`= b.`EmoteDelay2`,
a.`Emote2_1`= b.`EmoteID2`,
a.`EmoteDelay2_2`= b.`EmoteDelay3`,
a.`Emote2_2`= b.`EmoteID3`;

UPDATE `npc_text` AS a
INNER JOIN `broadcast_text` AS b ON a.`BroadcastTextID3`= b.`ID`
SET 
a.`EmoteDelay3_0`= b.`EmoteDelay1`,
a.`Emote3_0`= b.`EmoteID1`,
a.`EmoteDelay3_1`= b.`EmoteDelay2`,
a.`Emote3_1`= b.`EmoteID2`,
a.`EmoteDelay3_2`= b.`EmoteDelay3`,
a.`Emote3_2`= b.`EmoteID3`;

UPDATE `npc_text` AS a
INNER JOIN `broadcast_text` AS b ON a.`BroadcastTextID4`= b.`ID`
SET 
a.`EmoteDelay4_0`= b.`EmoteDelay1`,
a.`Emote4_0`= b.`EmoteID1`,
a.`EmoteDelay4_1`= b.`EmoteDelay2`,
a.`Emote4_1`= b.`EmoteID2`,
a.`EmoteDelay4_2`= b.`EmoteDelay3`,
a.`Emote4_2`= b.`EmoteID3`;

UPDATE `npc_text` AS a
INNER JOIN `broadcast_text` AS b ON a.`BroadcastTextID5`= b.`ID`
SET 
a.`EmoteDelay5_0`= b.`EmoteDelay1`,
a.`Emote5_0`= b.`EmoteID1`,
a.`EmoteDelay5_1`= b.`EmoteDelay2`,
a.`Emote5_1`= b.`EmoteID2`,
a.`EmoteDelay5_2`= b.`EmoteDelay3`,
a.`Emote5_2`= b.`EmoteID3`;

UPDATE `npc_text` AS a
INNER JOIN `broadcast_text` AS b ON a.`BroadcastTextID6`= b.`ID`
SET 
a.`EmoteDelay6_0`= b.`EmoteDelay1`,
a.`Emote6_0`= b.`EmoteID1`,
a.`EmoteDelay6_1`= b.`EmoteDelay2`,
a.`Emote6_1`= b.`EmoteID2`,
a.`EmoteDelay6_2`= b.`EmoteDelay3`,
a.`Emote6_2`= b.`EmoteID3`;

UPDATE `npc_text` AS a
INNER JOIN `broadcast_text` AS b ON a.`BroadcastTextID7`= b.`ID`
SET 
a.`EmoteDelay7_0`= b.`EmoteDelay1`,
a.`Emote7_0`= b.`EmoteID1`,
a.`EmoteDelay7_1`= b.`EmoteDelay2`,
a.`Emote7_1`= b.`EmoteID2`,
a.`EmoteDelay7_2`= b.`EmoteDelay3`,
a.`Emote7_2`= b.`EmoteID3`;
