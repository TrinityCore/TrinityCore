SET @Zul = 23863; -- Zul'jin (ZA)
UPDATE `creature_template` SET `speed_walk`=2.4,`speed_run`=2.14286 WHERE `entry`=@Zul;
UPDATE `creature_model_info` SET `bounding_radius`=1.566,`combat_reach`=3.6,`gender`=0 WHERE `modelid`=21899;
DELETE FROM `creature_template_addon` WHERE `entry`=@Zul;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@Zul,0,0,1,0, NULL);

/* should this be set by core script or DB?
SET @EquiEntry = XXX; -- (creature_equip_template.entry - need 1)
UPDATE `creature_template` SET `equipment_id`=@EquiEntry WHERE `entry`=@Zul;
DELETE FROM `creature_equip_template` WHERE `entry`=@EquiEntry;
INSERT INTO `creature_equip_template` (`entry`,`equipentry1`,`equipentry2`,`equipentry3`) VALUES
(@EquiEntry,33975,0,0);*/
