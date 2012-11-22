-- Fixup Enslaved Netherwing drake in Shadowmoon Valley
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `id`=21722;
UPDATE `creature_template` SET `InhabitType`=1 WHERE `entry`=21722;

-- Fixup Dragonmaw Drake-Riders in Shadowmoon Valley
UPDATE `creature` SET `position_x`=-4155.54932,`position_y`=386.6152,`position_z`=141.4012,`orientation`=1.20427716 WHERE `guid`=75786;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `id`=21719;
UPDATE `creature_template` SET `InhabitType`=1 WHERE `entry`=21719;

-- fix walk speed for several npc's
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry` IN
(19449, -- Thunderlord Grunt
17855); -- Expedition Warden

-- Inquisitor Salrand shouldn't have random movement & fix inhabit type
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `id`=25584;
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=25584;
-- Beryl Point InvisMan shouldn't have random movement, set as a trigger & fix inhabit type
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=25594;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128,`InhabitType`=7 WHERE `entry`=25594;

-- Surristrasz proper state
DELETE FROM `creature_template_addon` WHERE `entry`=24795;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`) VALUES (24795,3);

-- Grand Magus Telestra shouldn't have random movement
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `id`=26832;
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=26832;

-- Remove spawned Savannah Cubs
-- Savannah Cubs are spawned in EAI
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=5766);
DELETE FROM `creature` WHERE `id`=5766;

-- Set ELM General Purpose Bunny (scale x0.01) as a trigger
UPDATE `creature` SET `modelid`=0 WHERE `id`=24021;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=24021;
-- Set ELM General Purpose Bunny (scale x0.01) Large as a trigger
UPDATE `creature` SET `modelid`=0 WHERE `id`=26298;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=26298;
