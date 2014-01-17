DELETE FROM `creature_template_addon` WHERE `entry`=17976;
DELETE FROM `creature_addon` WHERE `guid`=82986;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(82986,829860,0,0,1,0,'19818'); -- Converted from c_t_a, works on both normal and heroic entry
