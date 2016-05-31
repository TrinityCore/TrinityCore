-- DB/Gossip: Update some data for trainer NPCs from sniffs

SET @ALLCLASMASK := 1535;
SET @CLASSMASK_PAL := 2;
SET @CLASSMASK_HUN := 4;
SET @CLASSMASK_MAGE := 128;
SET @CLASSMASK_DRU := 1024;

SET @TRAINEROPT := 0;
SET @TALENTOPT := 1;

-- NPCS:
-- Milstaff Stormeye, 2489, Mage trainer 15050_2012-01-29_21-59-26_aliance_pali_Trainers_with_mage.pkt
SET @MENU1 := 4823;
SET @TEXTOK1 := 5878;
SET @TEXTERR1 := 5877;

-- Kal, 3602, Druid trainer, source https://gist.github.com/Kinzcool/a34dce9b128e6cc5ca6d
SET @MENU2 := 3923;
SET @TEXTOK2 := 4779;
SET @TEXTERR2 := 4780;

-- Dargh Trueaim, 10930, Hunter trainer, source https://gist.github.com/Kinzcool/a34dce9b128e6cc5ca6d
SET @NPC3 := 10930;
SET @MENU3 := 4674;
SET @TEXT3 := 5000;

-- Ysuria, 27703, Mage trainer, source https://gist.github.com/Kinzcool/a34dce9b128e6cc5ca6d
SET @MENU4 := 9581;

-- Brother Wilhelm, 927, Paladin trainer, verified that only has training option with TDB434, UDB
SET @MENU5 := 4664;
SET @TEXTOK5 := 3976;
SET @TEXTERR5 := 3977;

-- Gart Mistrunner, 3060, Druid trainer, verified that only has training option with TDB434
SET @MENU6 := 4644;
SET @TEXTOK6 := 5716;
SET @TEXTERR6 := 5717;

-- Archmage Celindra, 29156, Mage trainer, verified that only has training option with TDB434, UDB
SET @MENU7 := 9777;
SET @TEXTOK7 := 13456;
SET @TEXTERR7 := 13455;

-- Deal with the new data
DELETE FROM `gossip_menu` WHERE
(`entry` = @MENU1 AND `text_id` = @TEXTOK1)
OR (`entry` = @MENU2 AND `text_id` = @TEXTOK2)
OR (`entry` = @MENU3 AND `text_id` = @TEXT3);

DELETE FROM `gossip_menu_option` WHERE
(`menu_id` = @MENU1 AND `id` = @TRAINEROPT)
OR (`menu_id` = @MENU2 AND `id` IN (@TRAINEROPT, @TALENTOPT));

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND
(
    (`SourceEntry` IN (@TEXTOK1, @TEXTERR1) AND `SourceGroup` = @MENU1)
    OR (`SourceEntry` IN (@TEXTOK2, @TEXTERR2) AND `SourceGroup` = @MENU2)
    OR (`SourceEntry` IN (@TEXTOK5, @TEXTERR5) AND `SourceGroup` = @MENU5)
    OR (`SourceEntry` IN (@TEXTOK6, @TEXTERR6) AND `SourceGroup` = @MENU6)
    OR (`SourceEntry` IN (@TEXTOK7, @TEXTERR7) AND `SourceGroup` = @MENU7)
);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceEntry` = @TRAINEROPT AND `SourceGroup` IN (@MENU1, @MENU4, @MENU5, @MENU6, @MENU7);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceEntry` IN (@TRAINEROPT, @TALENTOPT) AND `SourceGroup` = @MENU2;

INSERT INTO `gossip_menu` (entry, text_id) VALUES
(@MENU1, @TEXTOK1),
(@MENU2, @TEXTOK2),
(@MENU3, @TEXT3);

INSERT INTO `gossip_menu_option` (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(@MENU1, @TRAINEROPT, 3, 'Please teach me.', 5, 16, 0, 0, 0, 0, ''),
(@MENU2, @TRAINEROPT, 3, 'I seek training as a druid.', 5, 16, 0, 0, 0, 0, ''),
(@MENU2, @TALENTOPT, 0, 'I wish to unlearn my talents.', 16, 16, 0, 0, 0, 0, '');

INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES
(14, @MENU1, @TEXTOK1, 0, 0, 15, 0, @CLASSMASK_MAGE, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Mage'),
(14, @MENU1, @TEXTERR1, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_MAGE), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Mage'),
(15, @MENU1, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_MAGE, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Mage'),
(14, @MENU2, @TEXTOK2, 0, 0, 15, 0, @CLASSMASK_DRU, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Druid'),
(14, @MENU2, @TEXTERR2, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_DRU), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Druid'),
(15, @MENU2, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_DRU, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Druid'),
(15, @MENU2, @TALENTOPT, 0, 0, 15, 0, @CLASSMASK_DRU, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Druid'),
(15, @MENU4, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_MAGE, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Mage'),
(14, @MENU5, @TEXTOK5, 0, 0, 15, 0, @CLASSMASK_PAL, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Paladin'),
(14, @MENU5, @TEXTERR5, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_PAL), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Paladin'),
(15, @MENU5, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_PAL, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Paladin'),
(14, @MENU6, @TEXTOK6, 0, 0, 15, 0, @CLASSMASK_PAL, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Druid'),
(14, @MENU6, @TEXTERR6, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_PAL), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Druid'),
(15, @MENU6, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_PAL, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Druid'),
(14, @MENU7, @TEXTOK7, 0, 0, 15, 0, @CLASSMASK_MAGE, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a Mage'),
(14, @MENU7, @TEXTERR7, 0, 0, 15, 0, (@ALLCLASMASK & ~@CLASSMASK_MAGE), 0, 0, 0, 0, 0, '', 'Show gossip text if player is not a Mage'),
(15, @MENU7, @TRAINEROPT, 0, 0, 15, 0, @CLASSMASK_MAGE, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a Mage');

UPDATE `creature_template` SET `gossip_menu_id` = @MENU3 WHERE `entry` = @NPC3;

