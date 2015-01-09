UPDATE `creature_template` SET `faction_A`=16,`faction_H`=16,`unit_flags`=0x8040,`speed_run`=2.85714,`InhabitType`=`InhabitType`|4 WHERE `entry`=32358; -- Fumblub Gearwind
UPDATE `creature_template` SET `faction_A`=1885,`faction_H`=1885,`unit_flags`=0x8040,`speed_run`=1.28571 WHERE `entry`=32438; -- Syreian the Bonecarver

UPDATE `creature_model_info` SET `bounding_radius`=1.25,`combat_reach`=3.919432,`gender`=1 WHERE `modelid`=27970; -- Syreian the Bonecarver

UPDATE `creature_addon` SET `mount`=25587, `bytes1`=0x3000000 WHERE `guid`=151938; -- Fumblub Gearwind

DELETE FROM `creature_template_addon` WHERE `entry` IN (32358,32438);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(32358,25587,0x3000000,1,0, NULL), -- Fumblub Gearwind
(32438,0,0,2,0, NULL); -- Syreian the Bonecarver
