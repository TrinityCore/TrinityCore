-- 'npc_wg_demolisher_engineer' Gossip stuff
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 9923 AND `SourceEntry` = 14172 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 55629 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 9923 AND `SourceEntry` = 14172 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 33280 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 9923 AND `SourceEntry` = 13798 AND `SourceId` = 0 AND `ElseGroup` = 1 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 55629 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 9923 AND `SourceEntry` = 13798 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 33280 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 9904 AND `SourceEntry` = 13761 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 55629 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 9904 AND `SourceEntry` = 13761 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 33280 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 9904 AND `SourceEntry` = 13759 AND `SourceId` = 0 AND `ElseGroup` = 1 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 55629 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 9904 AND `SourceEntry` = 13759 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 33280 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 9923 AND `SourceEntry` = 0 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 33280 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 9904 AND `SourceEntry` = 2 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 55629 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 9904 AND `SourceEntry` = 1 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 55629 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 9904 AND `SourceEntry` = 0 AND `SourceId` = 0 AND `ElseGroup` = 1 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 55629 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 9904 AND `SourceEntry` = 0 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 33280 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 9923 AND `SourceEntry` = 0 AND `SourceId` = 0 AND `ElseGroup` = 1 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 55629 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 9923 AND `SourceEntry` = 1 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 55629 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 9923 AND `SourceEntry` = 2 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 1 AND `ConditionTarget` = 0 AND `ConditionValue1` = 55629 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;

DELETE FROM `gossip_menu` WHERE `MenuID` = 9904 AND `TextID` IN (13786, 13761);
DELETE FROM `gossip_menu` WHERE `MenuID` = 9923 AND `TextID` IN (13786, 14172);

UPDATE `creature_template` SET `gossip_menu_id` = 0 WHERE `entry` IN (30400, 30499);

-- Remove 'npc_wg_give_promotion_credit'
UPDATE `creature_template` SET `ScriptName` = '' WHERE `ScriptName` = 'npc_wg_give_promotion_credit';

-- Remove 'spell_wintergrasp_force_building' from 'Activate Robotic Arms'
DELETE FROM `spell_script_names` WHERE `spell_id` = 49899 AND `ScriptName` = 'spell_wintergrasp_force_building';

-- Remove spell_area from 56618 - Horde Controls Factory Phase Shift
DELETE FROM `spell_area` WHERE `spell` = 56618 AND `area` = 4538 AND `quest_start` = 0 AND `aura_spell` = 0 AND `racemask` = 0 AND `gender` = 2;
DELETE FROM `spell_area` WHERE `spell` = 56618 AND `area` = 4539 AND `quest_start` = 0 AND `aura_spell` = 0 AND `racemask` = 0 AND `gender` = 2;
DELETE FROM `spell_area` WHERE `spell` = 56618 AND `area` = 4611 AND `quest_start` = 0 AND `aura_spell` = 0 AND `racemask` = 0 AND `gender` = 2;
DELETE FROM `spell_area` WHERE `spell` = 56618 AND `area` = 4612 AND `quest_start` = 0 AND `aura_spell` = 0 AND `racemask` = 0 AND `gender` = 2;
-- Remove spell_area from 56617 - Alliance Controls Factory Phase Shift
DELETE FROM `spell_area` WHERE `spell` = 56617 AND `area` = 4538 AND `quest_start` = 0 AND `aura_spell` = 0 AND `racemask` = 0 AND `gender` = 2;
DELETE FROM `spell_area` WHERE `spell` = 56617 AND `area` = 4539 AND `quest_start` = 0 AND `aura_spell` = 0 AND `racemask` = 0 AND `gender` = 2;
DELETE FROM `spell_area` WHERE `spell` = 56617 AND `area` = 4611 AND `quest_start` = 0 AND `aura_spell` = 0 AND `racemask` = 0 AND `gender` = 2;
DELETE FROM `spell_area` WHERE `spell` = 56617 AND `area` = 4612 AND `quest_start` = 0 AND `aura_spell` = 0 AND `racemask` = 0 AND `gender` = 2;

-- Add 'spell_wintergrasp_waiting_to_resurrect'
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_wintergrasp_waiting_to_resurrect';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(2584, 'spell_wintergrasp_waiting_to_resurrect');
