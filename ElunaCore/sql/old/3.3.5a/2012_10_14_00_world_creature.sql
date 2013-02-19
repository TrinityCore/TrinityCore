-- Spawnmask updates
UPDATE `creature` SET `spawnMask`=15 WHERE `id` IN(40091, 40081);

-- Auras updates (Now in script, can't be used in creature_addon because dynamically spawned)
DELETE FROM `creature_template_addon` WHERE `entry` IN(39863, 40142);

-- Blazing Aura
-- NOTE: This still does not work, no clue why. Probably a core-side bug ?
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,2,75886,0,0,31,0,3,40683,0,0,0, '', 'Blazing Aura can only target Living Embers');
