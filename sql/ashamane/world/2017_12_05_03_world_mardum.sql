UPDATE creature_template SET flags_extra = flags_extra | 128 WHERE modelid1 = 1126 AND modelid2 = 21999;
UPDATE creature_template SET scriptname = "npc_mardum_allari" WHERE entry = 94410;
UPDATE creature_template SET modelid1 = modelid2 WHERE entry = 101704;

UPDATE quest_template_addon SET PrevQuestId = 39050 WHERE id IN (38766, 38765);

DELETE FROM creature WHERE guid IN (20541220, 20541246, 20541328, 20541309, 20541326, 20543575, 20549008);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
('20549008','99915','1481','0','0','1','0','0','0','1','1587.85','2543.3','62.0158','3.55335','300','0','0','715508','0','0','0','0','0','0','0','','0');

UPDATE creature_template SET scriptname = "npc_mardum_sevis_brightflame_shivarra" WHERE entry = 99915;

UPDATE creature SET PhaseId = 50 WHERE guid IN (20541415, 20542284);

UPDATE `quest_template_addon` SET `PrevQuestID` = '39663', `ExclusiveGroup` = '0' WHERE `id` = 38728;
UPDATE `quest_template_addon` SET `PrevQuestID` = '39515', `ExclusiveGroup` = '0' WHERE `id` = 39663;
UPDATE `quest_template_addon` SET `PrevQuestID` = '38727', `ExclusiveGroup` = '-39515' WHERE `id` = 39515;
UPDATE `quest_template_addon` SET `PrevQuestID` = '38727', `ExclusiveGroup` = '-39515' WHERE `id` = 39516;
UPDATE `quest_template_addon` SET `PrevQuestID` = '39495', `ExclusiveGroup` = '-38727' WHERE `id` = 38727;
UPDATE `quest_template_addon` SET `PrevQuestID` = '39495', `ExclusiveGroup` = '-38727' WHERE `id` = 38819;
UPDATE `quest_template_addon` SET `PrevQuestID` = '39262', `ExclusiveGroup` = '0' WHERE `id` = 39495;
UPDATE `quest_template_addon` SET `PrevQuestID` = '38813', `ExclusiveGroup` = '0' WHERE `id` = 39262;
UPDATE `quest_template_addon` SET `PrevQuestID` = '38765', `ExclusiveGroup` = '0' WHERE `id` = 38813;
UPDATE `quest_template_addon` SET `ExclusiveGroup` = '-38765' WHERE `id` = 38765;
UPDATE `quest_template_addon` SET `ExclusiveGroup` = '-38765' WHERE `id` = 38766;

UPDATE `quest_template_addon` SET `PrevQuestID` = '40222', `ExclusiveGroup` = '0' WHERE `id` = 40051;
UPDATE `quest_template_addon` SET `PrevQuestID` = '38725', `ExclusiveGroup` = '0' WHERE `id` = 40222;
UPDATE `quest_template_addon` SET `PrevQuestID` = '39495', `ExclusiveGroup` = '0' WHERE `id` = 38725;

UPDATE creature_template SET gossip_menu_id = 19075 WHERE entry = 100429;
UPDATE creature_template SET gossip_menu_id = 20216 WHERE entry = 112198;
UPDATE creature_template SET gossip_menu_id = 18424 WHERE entry = 96666;
UPDATE creature_template SET gossip_menu_id = 19234 WHERE entry = 96666;
UPDATE creature_template SET gossip_menu_id = 19012 WHERE entry = 97644;
UPDATE creature_template SET gossip_menu_id = 18831 WHERE entry = 96675;
UPDATE creature_template SET gossip_menu_id = 18832 WHERE entry = 97643;
UPDATE creature_template SET gossip_menu_id = 18426 WHERE entry = 92986;
UPDATE creature_template SET gossip_menu_id = 19233 WHERE entry = 92986;
UPDATE creature_template SET gossip_menu_id = 18776 WHERE entry = 96653;
UPDATE creature_template SET gossip_menu_id = 18435 WHERE entry = 93127;
UPDATE creature_template SET gossip_menu_id = 18823 WHERE entry = 96652;
UPDATE creature_template SET gossip_menu_id = 18936 WHERE entry = 96420;
UPDATE creature_template SET gossip_menu_id = 18937 WHERE entry = 99045;
UPDATE creature_template SET gossip_menu_id = 18935 WHERE entry = 96655;
UPDATE creature_template SET gossip_menu_id = 19175 WHERE entry = 96436;
UPDATE creature_template SET gossip_menu_id = 17260 WHERE entry = 90247;
UPDATE creature_template SET gossip_menu_id = 18434 WHERE entry = 94435;
UPDATE creature_template SET gossip_menu_id = 18447 WHERE entry = 93693;
UPDATE creature_template SET gossip_menu_id = 18994 WHERE entry = 93127;
UPDATE creature_template SET gossip_menu_id = 19132 WHERE entry = 99915;
UPDATE creature_template SET gossip_menu_id = 19016 WHERE entry = 99915;
UPDATE creature_template SET gossip_menu_id = 18438 WHERE entry = 93759;
UPDATE creature_template SET gossip_menu_id = 19131 WHERE entry = 93759;
UPDATE creature_template SET gossip_menu_id = 19109 WHERE entry = 93759;
UPDATE creature_template SET gossip_menu_id = 19015 WHERE entry = 99914;
UPDATE creature_template SET gossip_menu_id = 18899 WHERE entry = 94410;
UPDATE creature_template SET gossip_menu_id = 18864 WHERE entry = 98229;
UPDATE creature_template SET gossip_menu_id = 18993 WHERE entry = 98229;

UPDATE gossip_menu_option SET OptionType = 1 WHERE OptionType = 0;
UPDATE gossip_menu_option SET OptionNpcFlag = 1 WHERE OptionNpcFlag = 0;

UPDATE creature_template SET scriptname = "npc_mardum_captain" WHERE entry IN (90247, 93693, 94435);
