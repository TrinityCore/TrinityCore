SET @EQUIP := 10137;

UPDATE `creature_template` SET `faction_A`=1770,`faction_H`=1770,`baseattacktime`=2000,`npcflag`=3,`unit_flags`=33088,`dynamicflags`=0,`speed_run`=1,`flags_extra`=`flags_extra`|2 WHERE `entry`=37597; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `faction_A`=1770,`faction_H`=1770,`baseattacktime`=2000,`unit_flags`=33088,`equipment_id`=1221,`speed_run`=1,`flags_extra`=`flags_extra`|2 WHERE `entry`=38160; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `baseattacktime`=5000,`unit_class`=2,`speed_walk`=0.4,`speed_run`=1.1428571428571 WHERE `entry`=36967; -- Spiteful Apparition (Ambient)
UPDATE `creature_template` SET `baseattacktime`=2000,`speed_walk`=1.111112,`speed_run`=1.1428571428571 WHERE `entry`=36666; -- Spectral Warden
UPDATE `creature_template` SET `equipment_id`=637,`speed_run`=1.1428571428571,`flags_extra`=`flags_extra`|2 WHERE `entry`=37582; -- Archmage Koreln
UPDATE `creature_template` SET `faction_A`=1770,`faction_H`=1770,`baseattacktime`=2000,`unit_flags`=32832,`equipment_id`=637,`speed_run`=1.1428571428571,`flags_extra`=`flags_extra`|2 WHERE `entry`=37774; -- Archmage Elandra
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`unit_flags`=32832,`equipment_id`=@EQUIP,`speed_run`=1.1428571428571 WHERE `entry`=37496; -- Coliseum Champion
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|32832,`speed_run`=1.1428571428571 WHERE `entry`=37779; -- Dark Ranger Loralen
UPDATE `creature_template` SET `baseattacktime`=2000,`npcflag`=`npcflag`|3,`dynamicflags`=0,`speed_run`=1.1428571428571,`flags_extra`=`flags_extra`|2 WHERE `entry`=37596; -- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `baseattacktime`=2000,`speed_walk`=0.4,`speed_run`=1.1428571428571,`InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=36508; -- Soulguard Beam Focus Target

DELETE FROM `creature_equip_template` WHERE `entry`=@EQUIP;
INSERT INTO `creature_equip_template` (`entry`,`equipentry1`,`equipentry2`,`equipentry3`) VALUES
(@EQUIP,47814,46963,0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (36508,37583,37779);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(37779,0,0,1,433, NULL), -- Dark Ranger Loralen
(37583,0,0,2,0, NULL), -- Dark Ranger Kalira
(36508,0,33554432,1,0, NULL); -- Soulguard Beam Focus Target

UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=30684; -- Archmage Elandra
UPDATE `creature_model_info` SET `bounding_radius`=0.347,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=30638; -- Coliseum Champion
UPDATE `creature_model_info` SET `bounding_radius`=0.465,`combat_reach`=0,`gender`=1 WHERE `modelid`=30867; -- Lady Jaina Proudmoore
UPDATE `creature_model_info` SET `bounding_radius`=0.354,`combat_reach`=2.25,`gender`=1 WHERE `modelid`=30168; -- Soulguard Animator
UPDATE `creature_model_info` SET `bounding_radius`=0.465,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=30270; -- Soulguard Bonecaster
UPDATE `creature_model_info` SET `bounding_radius`=0.459,`combat_reach`=2.25,`gender`=1 WHERE `modelid`=30240; -- Soulguard Adept
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=2 WHERE `modelid`=25942; -- Spiteful Apparition (Ambient)
UPDATE `creature_model_info` SET `bounding_radius`=2.5,`combat_reach`=3.75,`gender`=0 WHERE `modelid`=30283; -- Spectral Warden
UPDATE `creature_model_info` SET `bounding_radius`=0.383,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=30862; -- Ebon Blade Commander
UPDATE `creature_model_info` SET `bounding_radius`=0.372,`combat_reach`=1.2,`gender`=1 WHERE `modelid`=28213; -- Lady Sylvanas Windrunner
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=2 WHERE `modelid`=11686; -- Soulguard Beam Focus Target