UPDATE `creature_template` SET `speed_walk`=0.2, `speed_run`=1.142857 WHERE `entry`=49039; -- Glubtok Firewall Platter Creature Level 1b
UPDATE `creature_template` SET `speed_walk`=0.2, `speed_run`=1.142857 WHERE `entry`=48976; -- Glubtok Firewall Platter Creature Level 2a
UPDATE `creature_template` SET `minlevel`=86, `maxlevel`=86 WHERE `entry`=48829; -- Ogre Henchman
UPDATE `creature_template` SET `speed_walk`=0.2, `speed_run`=1.142857 WHERE `entry`=48975; -- Glubtok Firewall Platter Creature Level 1a
UPDATE `creature_template` SET `speed_walk`=0.2, `speed_run`=1.142857 WHERE `entry`=48974; -- Glubtok Firewall Platter
UPDATE `creature_template` SET `speed_walk`=0.2, `speed_run`=1.142857 WHERE `entry`=49041; -- Glubtok Firewall Platter Creature Level 2b
UPDATE `creature_template` SET `speed_walk`=0.2, `speed_run`=1.142857 WHERE `entry`=49040; -- Glubtok Firewall Platter Creature Level 1c
UPDATE `creature_template` SET `speed_walk`=0.2, `speed_run`=1.142857 WHERE `entry`=49042; -- Glubtok Firewall Platter Creature Level 2c
UPDATE `creature_template` SET `BaseAttackTime`=1000 WHERE `entry`=48229; -- Kobold Digger
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `BaseAttackTime`=1000 WHERE `entry`=48834; -- Kobold Digger
UPDATE `creature_template` SET `minlevel`=86, `maxlevel`=86 WHERE `entry`=48830; -- Ogre Bodyguard
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `unit_flags2`=0 WHERE `entry`=48835; -- Mining Powder

DELETE FROM `creature` WHERE `id` IN (49039, 48976, 48975, 48974, 49041, 49040, 49042);
DELETE FROM `creature_addon` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
UPDATE `creature_template` SET `flags_extra`= 131 WHERE `entry` IN (49039, 48976, 48975, 49041, 49040, 49042);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (89769, 91063, 89697, 91066) AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ScriptName, Comment) VALUES
(13, 1, 89769, 0, 0, 31, 0, 3, 48230, 0, 0, 0, '', 'Explode - Target Ogre Henchman'),
(13, 1, 89769, 0, 1, 31, 0, 3, 48284, 0, 0, 0, '', 'Explode - Target Mining Powder'),
(13, 1, 89769, 0, 2, 31, 0, 3, 48229, 0, 0, 0, '', 'Explode - Target Kobold Digger'),
(13, 1, 89769, 0, 3, 31, 0, 3, 48279, 0, 0, 0, '', 'Explode - Target Goblin Overseer'),
(13, 1, 89769, 0, 4, 31, 0, 3, 48338, 0, 0, 0, '', 'Explode - Target Goblin Bunny'),
(13, 1, 89769, 0, 5, 31, 0, 3, 48278, 0, 0, 0, '', 'Explode - Target Mining Monkey'),
(13, 1, 89769, 0, 6, 31, 0, 3, 48445, 0, 0, 0, '', 'Explode - Target Oaf Lackey'),
(13, 1, 89697, 0, 7, 31, 0, 3, 48419, 0, 0, 0, '', 'Explode - Target Defias Miner'),
(13, 1, 89697, 0, 8, 31, 0, 3, 48418, 0, 0, 0, '', 'Explode - Target Defias Envoker'),
(13, 1, 89697, 0, 9, 31, 0, 3, 48421, 0, 0, 0, '', 'Explode - Target Defias Overseer'),
(13, 1, 89697, 0, 10, 31, 0, 3, 48502, 0, 0, 0, '', 'Explode - Target Defias Enforcer'),
(13, 1, 89697, 0, 11, 31, 0, 3, 48417, 0, 0, 0, '', 'Explode - Target Blood Wizard'),
(13, 1, 89697, 0, 12, 31, 0, 3, 48505, 0, 0, 0, '', 'Explode - Target Defias Shadowguard'),
--
(13, 1, 91063, 0, 0, 31, 0, 3, 48230, 0, 0, 0, '', 'Explode - Target Ogre Henchman'),
(13, 1, 91063, 0, 1, 31, 0, 3, 48284, 0, 0, 0, '', 'Explode - Target Mining Powder'),
(13, 1, 91063, 0, 2, 31, 0, 3, 48229, 0, 0, 0, '', 'Explode - Target Kobold Digger'),
(13, 1, 91063, 0, 3, 31, 0, 3, 48279, 0, 0, 0, '', 'Explode - Target Goblin Overseer'),
(13, 1, 91063, 0, 4, 31, 0, 3, 48338, 0, 0, 0, '', 'Explode - Target Goblin Bunny'),
(13, 1, 91063, 0, 5, 31, 0, 3, 48278, 0, 0, 0, '', 'Explode - Target Mining Monkey'),
(13, 1, 91063, 0, 6, 31, 0, 3, 48445, 0, 0, 0, '', 'Explode - Target Oaf Lackey'),
(13, 1, 91063, 0, 7, 31, 0, 3, 48419, 0, 0, 0, '', 'Explode - Target Defias Miner'),
(13, 1, 91063, 0, 8, 31, 0, 3, 48418, 0, 0, 0, '', 'Explode - Target Defias Envoker'),
(13, 1, 91063, 0, 9, 31, 0, 3, 48421, 0, 0, 0, '', 'Explode - Target Defias Overseer'),
(13, 1, 91063, 0, 10, 31, 0, 3, 48502, 0, 0, 0, '', 'Explode - Target Defias Enforcer'),
(13, 1, 91063, 0, 11, 31, 0, 3, 48417, 0, 0, 0, '', 'Explode - Target Defias Blood Wizard'),
(13, 1, 91063, 0, 12, 31, 0, 3, 48505, 0, 0, 0, '', 'Explode - Target Defias Shadowguard'),
--
(13, 1, 89697, 0, 0, 31, 0, 3, 45979, 0, 0, 0, '', 'Cannonball - Target General Purpose Bunny'),
--
(13, 1, 91066, 0, 0, 31, 0, 3, 45979, 0, 0, 0, '', 'Cannonball - Target General Purpose Bunny');

-- Creature Mining Powder 48284 SAI
SET @ENTRY := 48284;
UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`= 2 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 6, 0, 100, 0, 0, 0, 0, 0, 11, 90096, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell 90096 on Self // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 89769, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 89769 on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 3, 0, 11686, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Morph to model 11686 // ");

-- Creature Kobold Digger 48229 SAI
SET @ENTRY := 48229;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
SET @ENTRY := -375926;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 60, 0, 100, 1, 100, 100, 0, 0, 11, 46598, 0, 0, 0, 0, 0, 10, 375931, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 100 and 100 ms) - Self: Cast spell 46598 on Creature Ogre Henchman 48230 (375931) // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set react state to REACT_PASSIVE // ");

-- Creature Ogre Henchman 48230 SAI
SET @ENTRY := 48230;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
SET @ENTRY := -375931;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 1, 100, 0, 6500, 6500, 13000, 13000, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 6500 and 6500 ms (and later repeats every 13000 and 13000 ms) - Self: Play emote 16 // "),
(@ENTRY, 0, 1, 0, 1, 1, 100, 0, 8000, 8000, 13000, 13000, 86, 89697, 0, 10, 375933, 0, 0, 10, 375992, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 8000 and 8000 ms (and later repeats every 13000 and 13000 ms) - SMART_TARGET_CREATURE_GUID: Cast spell 89697 at Creature General Purpose Bunny JMF 45979 (375992) // "),
(@ENTRY, 0, 2, 0, 4, 0, 100, 1, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Set event phase to 2 // "),
(@ENTRY, 0, 3, 0, 27, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On passenger boarded (vehicle) - Self: Set event phase to 1 // "),
(@ENTRY, 0, 4, 0, 28, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On passenger removed (vehicle) - Action invoker: Set react state to REACT_AGGRESSIVE // ");
