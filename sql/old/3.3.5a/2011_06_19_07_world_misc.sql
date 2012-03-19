UPDATE `areatrigger_teleport` SET `target_position_x`=-4464.919922,`target_position_y`=-1666.23999,`target_position_z`=81.892769,`target_orientation`=4.288273 WHERE `id`=242;
UPDATE `game_event` SET `start_time`='2011-09-04 00:01:00' WHERE `eventEntry`=4; -- Darkmoon Faire (Elwynn Forest)
SET @EquiEntry = 2473; -- (creature_equip_template.entry - need 2)
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|32768,`equipment_id`=@EquiEntry+0 WHERE `entry`=29333; -- Onslaught Gryphon Rider
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|32768,`equipment_id`=@EquiEntry+1 WHERE `entry`=29329; -- Onslaught Paladin
DELETE FROM `creature_equip_template` WHERE `entry` IN (@EquiEntry,@EquiEntry+1);
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES 
(@EquiEntry+0,38488,0,0),
(@EquiEntry+1,40452,12932,0);
UPDATE `creature_model_info` SET `bounding_radius`=0.3366,`combat_reach`=1.65,`gender`=0 WHERE `modelid`=26179; -- Onslaught Gryphon Rider
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=26166; -- Onslaught Paladin
DELETE FROM `creature_template_addon` WHERE `entry` IN (29333,29329);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29333,24688,50331648,1,0, NULL), -- Onslaught Gryphon Rider
(29329,19085,0,1,0, NULL); -- Onslaught Paladin
