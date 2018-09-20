-- Edwin VanCleef changes

-- Remove two spawned Blackguards
DELETE FROM `creature` WHERE `guid` IN (79369, 79370);
-- Adjust VanCleef's template
UPDATE `creature_template` SET `AIName`='', `DamageModifier`='7.5', `ScriptName`='boss_vancleef' WHERE `entry`=639;
-- Delete old SAI script
DELETE FROM `smart_scripts` WHERE `entryorguid`=639 AND `source_type`=0;
