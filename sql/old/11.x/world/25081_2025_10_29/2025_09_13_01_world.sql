-- Creature templates
UPDATE `creature_template_addon` SET `PvpFlags`=0 WHERE `entry`=64868; -- 64868 (Kor'kron Dubs)

UPDATE `vehicle_template` SET `despawnDelayMs`=1 WHERE `despawnDelayMs`=0;

-- Difficulties
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000 WHERE (`Entry`=66915 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x12080000, `StaticFlags3`=0x40000, `VerifiedBuild`=61967 WHERE (`Entry`=66190 AND `DifficultyID`=0); -- 66190 (General Nazgrim) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x12080000, `StaticFlags3`=0x40000, `VerifiedBuild`=61967 WHERE (`Entry`=55135 AND `DifficultyID`=0); -- 55135 (General Nazgrim) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x22000100, `VerifiedBuild`=61967 WHERE (`Entry`=67032 AND `DifficultyID`=0); -- 67032 (Gunship Turret) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x12080000, `StaticFlags3`=0x40000, `VerifiedBuild`=61967 WHERE (`Entry`=55054 AND `DifficultyID`=0); -- 55054 (General Nazgrim) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x12080000, `StaticFlags3`=0x40000, `VerifiedBuild`=61967 WHERE (`Entry`=54870 AND `DifficultyID`=0); -- 54870 (General Nazgrim) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x22000100, `VerifiedBuild`=61967 WHERE (`Entry`=66183 AND `DifficultyID`=0); -- 66183 (Gunship Turret) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x22000100, `VerifiedBuild`=61967 WHERE (`Entry`=66674 AND `DifficultyID`=0); -- 66674 (Gunship Turret) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x22000100, `VerifiedBuild`=61967 WHERE (`Entry`=66676 AND `DifficultyID`=0); -- 66676 (Gunship Turret) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x22000100, `VerifiedBuild`=61967 WHERE (`Entry`=66677 AND `DifficultyID`=0); -- 66677 (Gunship Turret) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x32080100, `VerifiedBuild`=61967 WHERE (`Entry`=66210 AND `DifficultyID`=0); -- 66210 (Thunder Hold Explosive Barrel) - Sessile, Amphibious, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x32080100, `VerifiedBuild`=61967 WHERE (`Entry`=66203 AND `DifficultyID`=0); -- 66203 (Thunder Hold Cannon) - Sessile, Amphibious, CanSwim, Floating - CannotTurn

-- Spells
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (130162,130237,130248,130265,130970,130996,130997,130998,131202,131992);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,130162,0,0,51,0,5,66200,0,0,0,0,'','Spell "Shredder Round" targets Thunder Hold Soldier'),
(13,1,130162,0,1,51,0,5,66202,0,0,0,0,'','Spell "Shredder Round" targets Thunder Hold Laborer'),
(13,1,130162,0,2,51,0,5,66203,0,0,0,0,'','Spell "Shredder Round" targets Thunder Hold Cannon'),
(13,1,130162,0,3,51,0,5,66210,0,0,0,0,'','Spell "Shredder Round" targets Thunder Hold Explosive Barrel'),
(13,1,130162,0,4,51,0,5,66291,0,0,0,0,'','Spell "Shredder Round" targets Thunder Hold Soldier'),
(13,3,130237,0,0,51,0,5,66200,0,0,0,0,'','Spell "Cannon Explosion" targets Thunder Hold Soldier'),
(13,3,130237,0,1,51,0,5,66202,0,0,0,0,'','Spell "Cannon Explosion" targets Thunder Hold Laborer'),
(13,3,130237,0,2,51,0,5,66203,0,0,0,0,'','Spell "Cannon Explosion" targets Thunder Hold Cannon'),
(13,3,130237,0,3,51,0,5,66210,0,0,0,0,'','Spell "Cannon Explosion" targets Thunder Hold Explosive Barrel'),
(13,3,130237,0,4,51,0,5,66291,0,0,0,0,'','Spell "Cannon Explosion" targets Thunder Hold Soldier'),
(13,1,130248,0,0,51,0,5,66200,0,0,0,0,'','Spell "Barrel Explosion" targets Thunder Hold Soldier'),
(13,1,130248,0,1,51,0,5,66202,0,0,0,0,'','Spell "Barrel Explosion" targets Thunder Hold Laborer'),
(13,1,130248,0,2,51,0,5,66203,0,0,0,0,'','Spell "Barrel Explosion" targets Thunder Hold Cannon'),
(13,1,130248,0,3,51,0,5,66210,0,0,0,0,'','Spell "Barrel Explosion" targets Thunder Hold Explosive Barrel'),
(13,1,130248,0,4,51,0,5,66291,0,0,0,0,'','Spell "Barrel Explosion" targets Thunder Hold Soldier'),
(13,1,130265,0,0,51,0,5,66203,0,0,0,0,'','Spell "Cannon Blast" targets Thunder Hold Cannon'),
(13,1,130970,0,0,51,0,5,40789,0,0,0,0,'','Spell "Rappelling Rope Aura" targets Generic Controller Bunny (CSA)'),
(13,1,130996,0,0,51,0,5,66674,0,0,0,0,'','Spell "Summon Gunship Turret, Left" targets Gunship Turret'),
(13,1,130997,0,0,51,0,5,66676,0,0,0,0,'','Spell "Summon Gunship Turret, Middle" targets Gunship Turret'),
(13,1,130998,0,0,51,0,5,66677,0,0,0,0,'','Spell "Summon Gunship Turret, Right" targets Gunship Turret'),
(13,1,131202,0,0,51,0,5,66795,0,0,0,0,'','Spell "Douse Flames" targets Gunship Fire Bunny'),
(13,1,131992,0,0,51,0,5,67129,0,0,0,0,'','Spell "Rappelling Rope Aura" targets Rapelling Manfred');

-- Creature spawns
UPDATE `creature` SET `PhaseId`=0, `PhaseGroup`=742 WHERE `id`=66915 AND `guid` IN (4000753,4000754,4000755,4000756);

DELETE FROM `creature_static_flags_override` WHERE `SpawnId` IN (4000753, 4000754, 4000755, 4000756);
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(4000753,0,0x10080100,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(4000754,0,0x10080100,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(4000755,0,0x10080100,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(4000756,0,0x10080100,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- Gameobject spawns
UPDATE `gameobject` SET `PhaseId`=0, `PhaseGroup`=742 WHERE `id`=215967 AND `guid` IN (4000235,4000236,4000237,4000238,4000239);

-- Smart scripts
UPDATE `smart_scripts` SET `comment`='Areatrigger 8514 - On enter - Invoker casts ''The Mission Scene - JF''' WHERE `entryorguid`=8514 AND `source_type`=2 AND `id`=0;
UPDATE `smart_scripts` SET `comment`='Areatrigger 8190 - On enter - Store invoker in target list 1' WHERE `entryorguid`=8190 AND `source_type`=2 AND `id`=0;
UPDATE `smart_scripts` SET `comment`='Areatrigger 8189 - On enter - Store invoker in target list 1' WHERE `entryorguid`=8189 AND `source_type`=2 AND `id`=0;
UPDATE `smart_scripts` SET `comment`='Areatrigger 8130 - On enter - Store invoker in target list 1' WHERE `entryorguid`=8130 AND `source_type`=2 AND `id`=0;
UPDATE `smart_scripts` SET `comment`='Areatrigger 8045 - On enter - Invoker casts ''Into the Mists Scene - JF''' WHERE `entryorguid`=8045 AND `source_type`=2 AND `id`=0;
UPDATE `smart_scripts` SET `comment`='Areatrigger 7046 - On enter - Invoker casts ''The King''s Command Movie Aura''' WHERE `entryorguid`=7046 AND `source_type`=2 AND `id`=0;
UPDATE `smart_scripts` SET `comment`='Areatrigger 7045 - On enter - Invoker casts ''The King''s Command Movie Aura''' WHERE `entryorguid`=7045 AND `source_type`=2 AND `id`=0;

SET @ACTIONLIST := 66203 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=66203 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(66203,0,0,1,'',11,0,100,0,0,0,0,0,0,'',42,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On respawn - Set invincibility'),
(66203,0,1,0,'',61,0,100,0,0,0,0,0,0,'',116,15,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - Event linked - Set corpse delay'),
(66203,0,2,0,'',8,0,100,0x1,130162,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On spell hit - Store invoker in target list'),
(66203,0,3,0,'',8,0,100,0x1,130237,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On spell hit - Store invoker in target list'),
(66203,0,4,5,'',8,0,100,0x1,130248,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On spell hit - Store invoker in target list'),
(66203,0,5,0,'',61,0,100,0,0,0,0,0,0,'',102,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - Event linked - Disable health regen'),
(66203,0,6,0,'',2,0,100,0x1,0,10,0,0,0,'',80,@ACTIONLIST+0,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On health pct (0-10%) - Call timed actionlist (Not repeatable)'),
(66203,0,7,0,'',11,0,100,0,0,0,0,0,0,'',48,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On respawn - Set active (TEMP)');

SET @ACTIONLIST := 66210 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=66210 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(66210,0,0,0,'',11,0,100,0,0,0,0,0,0,'',42,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On respawn - Set invincibility'),
(66210,0,1,0,'',8,0,100,0x1,130162,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On spell hit - Store invoker in target list'),
(66210,0,2,0,'',8,0,100,0x1,130237,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On spell hit - Store invoker in target list'),
(66210,0,3,4,'',8,0,100,0x1,130248,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On spell hit - Store invoker in target list'),
(66210,0,4,0,'',61,0,100,0,0,0,0,0,0,'',102,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - Event linked - Disable health regen'),
(66210,0,5,0,'',2,0,100,0x1,0,10,0,0,0,'',80,@ACTIONLIST+0,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On health pct (0-10%) - Call timed actionlist (Not repeatable)'),
(66210,0,6,0,'',11,0,100,0,0,0,0,0,0,'',48,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On respawn - Set active (TEMP)');

SET @ACTIONLIST := 66291 * 100;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ACTIONLIST;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ACTIONLIST+0,9,0,0,'',0,0,100,0,0,0,0,0,0,'',66,0,0,0,0,0,0,0,NULL,19,66203,5,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Soldier - Face closest Thunder Hold Cannon'),
(@ACTIONLIST+0,9,1,0,'',0,0,100,0,0,0,0,0,0,'',17,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Soldier - Remove emote state'),
(@ACTIONLIST+0,9,2,0,'',0,0,100,0x20,0,0,0,0,0,'',11,130265,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Soldier - Cast ''Cannon Blast'''),
(@ACTIONLIST+0,9,3,0,'',0,0,100,0,200,200,0,0,0,'',17,27,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Soldier - Set emote state');
