-- correct the coordonates for Scarlet Monastery trigger in and out
DELETE FROM `areatrigger_teleport` WHERE id IN (45,7802);
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(45, 'Scarlet Monastery (Entrance)', 1004, 1124.55, 511.648, 0.98954, 1.47772),
(7802, 'Scarlet Monastery (Exit)', 0, 2884.30, -822.305, 160.689, 1.83392);
-- make the doors from entrance inside of SM open and openable same for next door-entrance
UPDATE `gameobject` SET `isActive`='1' WHERE guid IN (1238,1237);
UPDATE `gameobject_template` SET `flags`='0' WHERE entry in (101851,101850);
-- add .tele timelessisle
DELETE FROM game_tele WHERE id=1999 AND position_x=-606.361023;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) values('1999','-606.361023','-5004.713379','-6.276514','3.133185','870','timelessisle');
-- apply Temporal Anomaly: Unable to use flying mounts in the timeless isle
DELETE FROM spell_area WHERE spell=145389 AND area=6481;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES (145389, 6481, 0, 0, 0, 0, 2, 1, 64, 11);
DELETE FROM spell_linked_spell WHERE spell_trigger=147649 AND spell_effect=147651;
INSERT INTO `spell_linked_spell` VALUES ( '147649', '147651', '0', 'Pounce SAI stun');
-- add some mobs aura
DELETE FROM `creature_template_addon` WHERE `entry`= 71987;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) values('71987','0','0','0','0','483','144465');
DELETE FROM `creature_template_addon` WHERE `entry`= 73021;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) values('73021','0','0','0','0','533','144465');
DELETE FROM `creature_template_addon` WHERE `entry`= 73025;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) values('73025','0','0','0','1','0','144465');
