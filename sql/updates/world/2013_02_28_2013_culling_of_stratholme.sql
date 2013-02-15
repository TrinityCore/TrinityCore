/*Outside*/
-- Game Object clean-up
-- Doodad_InstancePortal_Purqq
DELETE FROM `gameobject` WHERE `guid`=17455 LIMIT 1;

/*Inside*/
-- Culling of Stratholme entrance
DELETE FROM `areatrigger_teleport` WHERE `id`=5148 LIMIT 1;
INSERT INTO `areatrigger_teleport` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `name`) VALUES
(5148, 1, -8756.6, -4457.02, -200.481, 1.39626, 'CoT Stratholme - Exit Target');

-- Script Name Updates
-- Grain Crate Helper
UPDATE `creature_template` SET `ScriptName`="npc_grain_crate_helper_cos" WHERE `entry`=27827 LIMIT 1;
-- Chromie Start
UPDATE `creature_template` SET `ScriptName`="npc_chromie_start_cos" WHERE `entry`=26527;
-- Chromie Middle
UPDATE `creature_template` SET `ScriptName`="npc_chromie_middle_cos" WHERE `entry`=27915;

-- Creature Text: Arthas
UPDATE `creature_text` SET `text`="Mal'Ganis appears to have more than Scourge in his arsenal. We should make haste.", `comment`="culling SAY_PHASE306" WHERE `sound`=14301 LIMIT 1;
UPDATE `creature_text` SET `groupid`=21, `comment`="culling SAY_PHASE310" WHERE `text`="One less obstacle to deal with." AND `entry`=26499 LIMIT 1;
UPDATE `creature_text` SET `groupid`=22  WHERE `text`="Let's move on." AND `sound`=14303 LIMIT 1;
UPDATE `creature_text` SET `groupid`=23  WHERE `text`="Watch your backs: they have us surrounded in this hall." AND `sound`=14304 LIMIT 1;

