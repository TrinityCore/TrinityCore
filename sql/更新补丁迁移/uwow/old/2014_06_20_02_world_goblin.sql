/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;


-- Misc
UPDATE `creature_template` SET `spell1` = '66300' WHERE `creature_template`.`entry` = 34840;

-- q14115 Phase 4
DELETE FROM `spell_area` WHERE `spell` in (59074) AND area in (4737);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('59074', '4737', '14115', '0', '0', '0', '2', '1', '10', '11');    -- add zone 4737

-- q14116 phase spell 59087
UPDATE `quest_template` SET `RewardSpell` = '0' WHERE `Id` = 14116;

-- Start phase 8 at start 59087 (QUEST_STATUS_COMPLETE|QUEST_STATUS_INCOMPLETE|QUEST_STATUS_REWARDED)
-- end phase by end quest
DELETE FROM `spell_area` WHERE `spell` in (59087) AND area in (4737);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('59087', '4737', '14116', '0', '0', '0', '2', '1', '74', '11');    -- add zone 4737

-- q14124 Liberate the Kaja'mite
UPDATE `gameobject_template` SET `data5` = '1', `data3` = '1', `flags` = '16', `ScriptName` = 'go_kajamite_deposit' WHERE `entry` = 195488;
UPDATE `gameobject` SET `id` = 195488 WHERE `id` = 202593 AND `phaseMask` = 15;
UPDATE`gameobject` SET `spawntimesecs` = '60' WHERE `id` = 195488;
DELETE FROM `gameobject` WHERE `id` = 195492;
UPDATE `gameobject_template` SET `data0` = '43', `data3` = '0', `data8` = '0', `data14` = '19676', `WDBVerified` = '15595' WHERE `entry` = 195492;

-- q14121 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 66301;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 66301, 0, 0, 31, 0, 3, 35234, 0, 0, 0, '', 'Hot Rod - Knockback - q14121 NPC_HIRED_LOOTER'),
(13, 1, 66301, 0, 1, 31, 0, 3, 35063, 0, 0, 0, '', 'Hot Rod - Knockback - Kezan Citizen'),
(13, 1, 66301, 0, 2, 31, 0, 3, 35075, 0, 0, 0, '', 'Hot Rod - Knockback - Kezan Citizen');

-- q14125
UPDATE `quest_template` SET  `CompleteScript` =  '14125' WHERE  `Id` =14125;
DELETE FROM `quest_end_scripts` WHERE `id` = 14125;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('14125', '1', '0', '0', '0', '2000014125', '0', '0', '0', '0');
DELETE FROM `db_script_string` WHERE `entry` = 2000014125;
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc8`) VALUES 
('2000014125', 'Еще одна жертва несчастного случая с "электричеством, газом, легковоспламеняющейся кроватью и фейерверками"?..', 'Еще одна жертва несчастного случая с "электричеством, газом, легковоспламеняющейся кроватью и фейерверками"?..');

-- q14126 Life Savings
DELETE FROM `gameobject` WHERE `id` = 207355;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, isActive) VALUES
(207355, 648, 1, 8, -7880.95, 1827.93, 4.15528, 0.349065, 0, 0, 0, 1, 120, 255, 1, 1);
DELETE FROM `spell_scripts` WHERE `id` = 92629;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('92629', '0', '0', '15', '92633', '1', '0', '0', '0', '0', '0');
UPDATE `quest_template` SET  `CompleteScript` =  '14126' WHERE  `Id` =14126;
DELETE FROM `quest_end_scripts` WHERE id in( 11, 14126);
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(14126, 30, 14, 69010, 0, 0, 0, 0, 0, 0),
(14126, 0, 34, 22, 0, 0, 0, 0, 0, 0),
(14126, 2, 6, 648, 0, 0, 533.77, 3274.62, 0.198194, 4.90527);