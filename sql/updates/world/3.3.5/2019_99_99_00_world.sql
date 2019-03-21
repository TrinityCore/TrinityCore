-- 'npc_wg_demolisher_engineer' Gossip stuff
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` IN (9923, 9904);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (9923, 9904);

DELETE FROM `gossip_menu` WHERE `MenuID` = 9904 AND `TextID` IN (13786, 13761);
DELETE FROM `gossip_menu` WHERE `MenuID` = 9923 AND `TextID` IN (13786, 14172);

UPDATE `creature_template` SET `gossip_menu_id` = 0 WHERE `entry` IN (30400, 30499);

-- Remove 'npc_wg_give_promotion_credit'
UPDATE `creature_template` SET `ScriptName` = '' WHERE `ScriptName` = 'npc_wg_give_promotion_credit';

-- Remove 'spell_wintergrasp_force_building' from 'Activate Robotic Arms'
DELETE FROM `spell_script_names` WHERE `spell_id` = 49899 AND `ScriptName` = 'spell_wintergrasp_force_building';

-- Remove spell_area from 56618 - Horde Controls Factory Phase Shift
-- Remove spell_area from 56617 - Alliance Controls Factory Phase Shift
DELETE FROM `spell_area` WHERE `spell` IN (56618, 56617);

-- Add 'spell_wintergrasp_waiting_to_resurrect'
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_wintergrasp_waiting_to_resurrect';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(2584, 'spell_wintergrasp_waiting_to_resurrect');
