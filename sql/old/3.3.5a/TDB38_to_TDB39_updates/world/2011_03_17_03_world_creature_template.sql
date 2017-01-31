-- Razaani Light Orb Fixup
SET @ENTRY := 20635; -- NPC entry
UPDATE `creature` SET `modelid`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=@ENTRY;
-- Blade's Edge - Orb Trigger 01 Fixup and set as trigger
SET @ENTRY := 20666; -- NPC entry
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
-- Blade's Edge - Flesh Beast Zap Trigger Fixup and set as trigger
SET @ENTRY := 20670; -- NPC entry
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
-- Razaani Light Orb - Mini Fixup and set as trigger
SET @ENTRY := 20771; -- NPC entry
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
-- Blade's Edge - Deadsoul Orb Fixup and set as trigger
SET @ENTRY := 20845; -- NPC entry
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
-- Blade's Edge - Deadsoul Orb Flight 01 Fixup and set as trigger
SET @ENTRY := 20851; -- NPC entry
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
-- Blade's Edge - Deadsoul Orb Flight 02 Fixup and set as trigger
SET @ENTRY := 20852; -- NPC entry
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
-- Blade's Edge - Deadsoul Orb Flight 03 Fixup and set as trigger
SET @ENTRY := 20853; -- NPC entry
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
-- Blade's Edge - Deadsoul Orb Flight 04 Fixup and set as trigger
SET @ENTRY := 20855; -- NPC entry
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
-- Blade's Edge - Deadsoul Orb Flight 05 Fixup and set as trigger
SET @ENTRY := 20856; -- NPC entry
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
-- Blade's Edge - Nexus Prince Event - Orb01 Fixup and set as trigger
SET @ENTRY := 21025; -- NPC entry
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
