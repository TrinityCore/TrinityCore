SET @NPC_SIMON_BUNNY           := 22923;
SET @GO_APEXIS_RELIC           := 185890;
SET @GO_APEXIS_MONUMENT        := 185944;

SET @SPELL_SIMON_BLUE_VISUAL   := 40244;
SET @SPELL_SIMON_GREEN_VISUAL  := 40245;
SET @SPELL_SIMON_RED_VISUAL    := 40246;
SET @SPELL_SIMON_YELLOW_VISUAL := 40247;

SET @ITEM_APEXIS_SHARD         := 32569;
SET @QUEST_THE_CRYSTALS        := 11025;
SET @QUEST_GUARDIAN_MONUMENT   := 11059;
SET @GOSSIP_MENU_ID_NORMAL     := 8703;
SET @GOSSIP_MENU_ID_LARGE      := 8704;

SET @ID_SPELL_GROUP            := 1115;

UPDATE `creature_template` SET `ScriptName` = 'npc_simon_bunny',`flags_extra` = 130 WHERE `entry` = @NPC_SIMON_BUNNY;
UPDATE `gameobject_template` SET `ScriptName` = 'go_apexis_relic' WHERE `entry` IN (@GO_APEXIS_MONUMENT,@GO_APEXIS_RELIC);
-- Update is done via displayid since there are 28 entries for each color
UPDATE `gameobject_template` SET `flags` = 16,`ScriptName` = 'go_simon_cluster' WHERE `displayId` IN (7364,7365,7366,7367,7369,7371,7373,7375);

-- Spell stacking rules for Introspection and Apexis reward spells
DELETE FROM `spell_group` WHERE `spell_id` IN (40055,40165,40166,40167,40623,40625,40626);
INSERT INTO `spell_group` (`id`,`spell_id`) VALUES
(@ID_SPELL_GROUP+0,40055),
(@ID_SPELL_GROUP+0,40165),
(@ID_SPELL_GROUP+0,40166),
(@ID_SPELL_GROUP+0,40167),
(@ID_SPELL_GROUP+1,40623),
(@ID_SPELL_GROUP+1,40625),
(@ID_SPELL_GROUP+1,40626);

DELETE FROM `spell_group_stack_rules` WHERE `group_id` IN (@ID_SPELL_GROUP,@ID_SPELL_GROUP+1);
INSERT INTO `spell_group_stack_rules` (`group_id`,`stack_rule`) VALUES
(@ID_SPELL_GROUP+0,1),
(@ID_SPELL_GROUP+1,1);
--

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (@SPELL_SIMON_BLUE_VISUAL,@SPELL_SIMON_GREEN_VISUAL,@SPELL_SIMON_RED_VISUAL,@SPELL_SIMON_YELLOW_VISUAL);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (@GOSSIP_MENU_ID_NORMAL,@GOSSIP_MENU_ID_LARGE);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Apexis Relic gossip option conditions
(15,@GOSSIP_MENU_ID_NORMAL,0,0,8,@QUEST_THE_CRYSTALS ,0,0,0,'','Apexis Relic Gossip Condition - Must have completed quest The Crystals'),
(15,@GOSSIP_MENU_ID_NORMAL,0,0,2,@ITEM_APEXIS_SHARD,1,0,0,'','Apexis Relic Gossip Condition - Must have an Apexis Shard'),
-- Apexis Monument gossip option conditions
(15,@GOSSIP_MENU_ID_LARGE,0,0,9,@QUEST_GUARDIAN_MONUMENT ,0,0,0,'','Apexis Monument Gossip Condition - Must be on quest Guardian of the Monument'),
(15,@GOSSIP_MENU_ID_LARGE,0,0,2,@ITEM_APEXIS_SHARD,35,0,0,'','Apexis Monument Gossip Condition - Must have 35 Apexis Shard'),
-- Visual color spells should target their correspondant cluster color
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185604,0,0,'','Simon Game - Blue visual target Large Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185609,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185617,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185625,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185637,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185640,0,0,'','Simon Game - Blue visual target Large Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185647,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185649,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185652,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185659,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185660,0,0,'','Simon Game - Blue visual target Large Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185665,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185669,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185673,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185770,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185772,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185776,0,0,'','Simon Game - Blue visual target Large Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185780,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185784,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185791,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185795,0,0,'','Simon Game - Blue visual target Large Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185796,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185807,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185808,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185812,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185816,0,0,'','Simon Game - Blue visual target Large Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185820,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185824,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185828,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185832,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185836,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185840,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185844,0,0,'','Simon Game - Blue visual target Large Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185848,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_BLUE_VISUAL,0,18,0,185853,0,0,'','Simon Game - Blue visual target Blue Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185605,0,0,'','Simon Game - Green visual target Large Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185611,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185619,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185627,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185639,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185641,0,0,'','Simon Game - Green visual target Large Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185646,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185651,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185654,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185658,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185661,0,0,'','Simon Game - Green visual target Large Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185667,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185671,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185675,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185768,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185774,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185777,0,0,'','Simon Game - Green visual target Large Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185781,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185786,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185789,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185793,0,0,'','Simon Game - Green visual target Large Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185798,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185805,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185810,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185814,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185818,0,0,'','Simon Game - Green visual target Large Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185822,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185826,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185830,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185834,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185838,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185842,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185846,0,0,'','Simon Game - Green visual target Large Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185850,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_GREEN_VISUAL,0,18,0,185855,0,0,'','Simon Game - Green visual target Green Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185606,0,0,'','Simon Game - Red visual target Large Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185613,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185621,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185626,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185638,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185642,0,0,'','Simon Game - Red visual target Large Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185645,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185650,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185655,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185657,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185662,0,0,'','Simon Game - Red visual target Large Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185666,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185670,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185674,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185771,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185773,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185778,0,0,'','Simon Game - Red visual target Large Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185782,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185785,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185788,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185794,0,0,'','Simon Game - Red visual target Large Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185797,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185804,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185809,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185815,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185817,0,0,'','Simon Game - Red visual target Large Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185823,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185827,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185831,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185835,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185839,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185843,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185845,0,0,'','Simon Game - Red visual target Large Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185851,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_RED_VISUAL,0,18,0,185854,0,0,'','Simon Game - Red visual target Red Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185607,0,0,'','Simon Game - Yellow visual target Large Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185615,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185623,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185624,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185636,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185643,0,0,'','Simon Game - Yellow visual target Large Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185644,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185648,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185653,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185656,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185663,0,0,'','Simon Game - Yellow visual target Large Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185664,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185668,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185672,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185769,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185775,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185779,0,0,'','Simon Game - Yellow visual target Large Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185783,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185787,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185790,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185792,0,0,'','Simon Game - Yellow visual target Large Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185803,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185806,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185811,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185813,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185819,0,0,'','Simon Game - Yellow visual target Large Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185821,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185825,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185829,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185833,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185837,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185841,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185847,0,0,'','Simon Game - Yellow visual target Large Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185849,0,0,'','Simon Game - Yellow visual target Yellow Cluster'),
(13,0,@SPELL_SIMON_YELLOW_VISUAL,0,18,0,185852,0,0,'','Simon Game - Yellow visual target Yellow Cluster');