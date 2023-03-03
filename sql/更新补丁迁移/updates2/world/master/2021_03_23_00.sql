-- DB update 2021_03_22_02 -> 2021_03_23_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_22_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_22_02 2021_03_23_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1609119138728662700'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1609119138728662700');

/* Anub'Rekhan */

-- Fix enrage for Crypt Guard
UPDATE `smart_scripts` SET `event_phase_mask`=0, `event_flags`=1, `event_param2`=29, `event_param3`=0, `event_param4`=0, `comment`='Crypt Guard - On 30% HP - CastSelf Frenzy' WHERE `entryorguid`=16573 AND `source_type`=0 AND `id`=3 AND `link`=0;
-- Add Frenzy emote for Crypt Guard
DELETE FROM `smart_scripts` WHERE `entryorguid`= 16573 AND `source_type`= 0 AND `id`= 5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16573, 0, 5, 0, 2, 0, 100, 1, 0, 29, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crypt Guard - On 30% HP - Say EMOTE_FRENZY');


/* Heigan the Unclean */

-- Enable random movement and adjust orientation
UPDATE `creature` SET `orientation`=2.40, `wander_distance`=4, `MovementType`=1 WHERE `guid`=127789;
-- Fix EMOTE_DEATH
UPDATE `creature_text` SET `Text`='%s takes his last breath.', `Type`=16, `BroadcastTextId`=13044, `comment`='heigan EMOTE_DEATH' WHERE `CreatureID`=15936 AND `GroupID`=3 AND `ID`=0;


/* Loatheb */

-- Useless, workaround implemented in boss_loatheb.cpp
DELETE FROM `spell_script_names` WHERE `spell_id`=59481;
-- Adjust movement speed for Spores
UPDATE `creature_template` SET `speed_walk`=0.4, `speed_run`=0.4 WHERE `entry` IN (16286, 30068);


/* Instructor Razuvious */

-- Fix all emotes / texts / dialogues / sound files
DELETE FROM `creature_text` WHERE `CreatureID`=16061;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(16061, 0, 0, 'Do as I taught you!', 14, 0, 25, 0, 0, 8855, 13075, 3, 'Razuvious SAY_AGGRO #1'),
(16061, 0, 1, 'The time for practice is over! Show me what you have learned!', 14, 0, 25, 0, 0, 8859, 13078, 3, 'Razuvious SAY_AGGRO #2'),
(16061, 0, 2, 'Show them no mercy!', 14, 0, 25, 0, 0, 8856, 13076, 3, 'Razuvious SAY_AGGRO #3'),
(16061, 0, 3, 'Sweep the leg... Do you have a problem with that?', 14, 0, 25, 0, 0, 8861, 13080, 3, 'Razuvious SAY_AGGRO #4'),
(16061, 1, 0, '%s lets loose a triumphant shout.', 16, 0, 50, 0, 0, 8863, 13082, 3, 'Razuvious SAY_SLAY #1'),
(16061, 1, 1, 'You should have stayed home.', 14, 0, 50, 0, 0, 8862, 13081, 3, 'Razuvious SAY_SLAY #2'),
(16061, 2, 0, 'Hah hah, I\'m just getting warmed up!', 14, 0, 20, 0, 0, 8852, 13072, 3, 'Razuvious SAY_TAUNTED #1'),
(16061, 2, 1, 'Stand and fight!', 14, 0, 20, 0, 0, 8853, 13073, 3, 'Razuvious SAY_TAUNTED #2'),
(16061, 2, 2, 'Show me what you\'ve got!', 14, 0, 20, 0, 0, 8854, 13074, 3, 'Razuvious SAY_TAUNTED #3'),
(16061, 2, 3, 'You disappoint me, students!', 14, 0, 20, 0, 0, 8858, 13077, 3, 'Razuvious SAY_TAUNTED #4'),
(16061, 2, 4, 'You should have stayed home.', 14, 0, 20, 0, 0, 8862, 13081, 3, 'Razuvious SAY_TAUNTED #5'),
(16061, 3, 0, 'An honorable... death.', 14, 0, 100, 0, 0, 8860, 13079, 3, 'Razuvious SAY_DEATH');
-- Fix translation
UPDATE `broadcast_text_locale` SET `MaleText`='%s suelta un grito triunfal.' WHERE `ID`=13082 AND `locale` IN ('esES', 'esMX');


/* Gothik the Harvester */

-- Minion difficulty spells
DELETE FROM `spelldifficulty_dbc` WHERE `ID` IN (55604, 27825, 27831, 27989, 56408, 27993, 55606, 27994, 55648);
INSERT INTO `spelldifficulty_dbc` (`id`,`DifficultySpellID_1`,`DifficultySpellID_2`) VALUES
(55604, 55604, 55645), -- death plague
(27831, 27831, 55638), -- shadow bolt volley
(27989, 27989, 56407), -- arcane explosion
(55606, 55606, 55608), -- unholy aura
(27994, 27994, 55646), -- drain life
(55648, 55648, 27995); -- unholy frenzy

-- Rider damage aura + visual aura
DELETE FROM `creature_template_addon` WHERE `entry` IN (16126, 29986, 16148, 29990, 16150, 29988);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`auras`) VALUES
(16126, 25278, '55606'),
(29986, 25278, '55608'),
(16148, 0, '10848'),
(29990, 0, '10848'),
(16150, 0, '55606 10848'),
(29988, 0, '55608 10848');


/* Grobbulus */

-- Fix 'Slime spray' message: emote -> boss emote
UPDATE `creature_text` SET `Type`=41 WHERE `CreatureID`=15931 AND `GroupID`=0 AND `ID`=0;
-- Add spell script for 'mutating injection/explosion'
DELETE FROM `spell_script_names` WHERE `spell_id`=28169;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (28169, 'spell_grobbulus_mutating_injection');
-- Remove 'mutating injection' from DB as now has script)
DELETE FROM `spell_linked_spell` WHERE  `spell_trigger`=-28169 AND `spell_effect`=28206 AND `type`=0;


/* Thaddius */

-- Tesla coil search ignores LoS
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (28096,28098,28110,28111);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,28098,64,"Stalagg Tesla Periodic - Ignore LoS"),
(0,28096,64,"Stalagg Tesla Visual - Ignore LoS"),
(0,28110,64,"Feugen Tesla Periodic - Ignore LoS"),
(0,28111,64,"Feugen Tesla Visual - Ignore LoS");
-- Tesla coil shock visual needs implicit target
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (28096,28111,28159);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
(13,1,28096,0,0,31,0,3,15929,0,0,"Stalagg Chain Visual - Target Stalagg"),
(13,1,28111,0,0,31,0,3,15930,0,0,"Feugen Chain Visual - Target Feugen"),
(13,1,28159,0,0,31,0,3,15928,0,0,"Thaddius Shock Visual - Target Thaddius");
-- Tesla coil visual GOs
DELETE FROM `gameobject` WHERE `id` IN (181477,181478);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(268049, 181478, 533, 0, 0, 3, 1, 3487.32, -2911.38, 318.898, 3.14159, 0, 0, -1, 0, 0, 0, 0, 0),
(268050, 181477, 533, 0, 0, 3, 1, 3527.94, -2952.26, 318.898, 3.14159, 0, 0, -1, 0, 0, 0, 0, 0);


/* Sapphiron */

-- Update Sapphiron's texts comments for better administration
UPDATE `creature_text` SET `comment`='Sapphiron EMOTE_AIR_PHASE' WHERE `CreatureID`=15989 AND `GroupID`=0 AND `ID`=0;
UPDATE `creature_text` SET `comment`='Sapphiron EMOTE_GROUND_PHASE' WHERE `CreatureID`=15989 AND `GroupID`=1 AND `ID`=0;
UPDATE `creature_text` SET `comment`='Sapphiron EMOTE_BREATH' WHERE `CreatureID`=15989 AND `GroupID`=2 AND `ID`=0;
UPDATE `creature_text` SET `comment`='Sapphiron EMOTE_ENRAGE' WHERE `CreatureID`=15989 AND `GroupID`=3 AND `ID`=0;


/* Kel'Thuzad */

-- Guardians of Icecrown should be immune to all CC
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|1|2|4|8|32|64|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|67108864|536870912 WHERE `entry` IN 
(16441, 30057);
-- Fix translation for Spanish
UPDATE `broadcast_text_locale` SET `MaleText`='¡Kel\'Thuzad ataca!' WHERE `ID`=32803 AND `locale` IN ('esES', 'esMX');


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
