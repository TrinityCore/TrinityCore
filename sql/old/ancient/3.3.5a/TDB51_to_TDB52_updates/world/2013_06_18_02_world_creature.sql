-- Part fix for NPC Hut Fire for Quest: This Just In: Fire Still Hot!
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=29692;
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=128 WHERE `entry`=29692;
