--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (25099,28000) AND `ConditionValue2` = 15328;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (25032,25029,27745);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,25099,0,1,31,0,3,15328,0,0,0,0,"","Group 1: Spell 'Land Mine Trigger' (Effect 0) targets creature 'Darkmoon Steam Tonk'"),
-- Dunno if owner should be affected or not
(13,1,28000,0,1,31,0,3,15328,0,0,0,0,"","Group 1: Spell 'Detonation' (Effect 0) targets creature 'Darkmoon Steam Tonk'"),
(13,1,25032,0,0,31,0,3,15328,0,0,0,0,"","Group 0: Spell 'Machine Gun' (Effect 0) targets creature 'Darkmoon Steam Tonk'"),
(13,1,25032,0,1,31,0,3,19405,0,0,0,0,"","Group 1: Spell 'Machine Gun' (Effect 0) targets creature 'Steam Tonk'"),
(13,7,25029,0,0,31,0,3,15328,0,0,0,0,"","Group 0: Spell 'Flamethrower' (Effect 0, 1, 2) targets creature 'Darkmoon Steam Tonk'"),
(13,7,25029,0,1,31,0,3,19405,0,0,0,0,"","Group 1: Spell 'Flamethrower' (Effect 0, 1, 2) targets creature 'Steam Tonk'"),
(13,1,27745,0,0,31,0,3,15328,0,0,0,0,"","Group 0: Spell 'Explosion' (Effect 1) targets creature 'Darkmoon Steam Tonk'"),
(13,1,27745,0,1,31,0,3,19405,0,0,0,0,"","Group 1: Spell 'Explosion' (Effect 1) targets creature 'Steam Tonk'");

-- Missing spells for Darkmoon Steam Tonk
DELETE FROM `creature_template_spell` WHERE `CreatureID` = 15328 AND `Index` IN (1,2);
INSERT INTO `creature_template_spell` (`CreatureID`,`Index`,`Spell`,`VerifiedBuild`) VALUES
(15328,1,25003,0),
(15328,2,25024,0);

-- Steam Tonk
UPDATE `creature_model_info` SET `BoundingRadius` = 0.27, `CombatReach` = 5 WHERE `DisplayID` = 15381;
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 0.85714285714, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 33554432, `unit_flags2` = 0 WHERE `entry` = 19405;

-- Mortar
UPDATE `creature_template` SET `speed_run` = 0.85714285714 WHERE `entry` = 16121;
