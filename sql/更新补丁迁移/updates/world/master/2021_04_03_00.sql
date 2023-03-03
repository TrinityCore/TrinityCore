-- DB update 2021_04_02_00 -> 2021_04_03_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_02_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_02_00 2021_04_03_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617043134287362500'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617043134287362500');

/* Environment */

-- PhaseMask to 1 for all Naxx end wing eyes
UPDATE `gameobject` SET `phaseMask`=1 WHERE `guid` IN (268045, 268044, 268047, 268046);
-- Set gobject flag "GO_FLAG_NOT_SELECTABLE" for all Naxx end wing eyes
UPDATE `gameobject_template_addon` SET `flags`=16 WHERE `entry` IN (181577, 181575, 181578, 181576);
-- Fix Horsemen end wing eye location
UPDATE `gameobject` SET `position_x`=2493.02, `position_y`=-2921.78, `position_z`=241.193, `orientation`=3.14159 WHERE `guid`=268046;
-- Adjust normal portal & phased glow portal on the same location
DELETE FROM `gameobject` WHERE `id` IN (181230, 181231, 181232, 181233);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(65855, 181231, 533, 0, 0, 3, 1, 2909, -4025.02, 273.475, 3.14159, 0, 0, 1, 0, 180, 0, 1, 0), -- Plague Wing Eye Portal Boss
(65856, 181232, 533, 0, 0, 3, 1, 3507.95, -2900.4, 302.459, 0.369949, 0, 0, 0.183921, 0.982941, 180, 0, 1, 0), -- Abom Wing Eye Portal Boss
(65857, 181233, 533, 0, 0, 3, 1, 3465.16, -3940.45, 308.788, 0.441179, -0.305481, 0.637715, 0.305481, 0.637716, 180, 0, 1, 0), -- Spider Wing Eye Portal Boss
(65854, 181230, 533, 0, 0, 3, 1, 2493.02, -2921.78, 241.193, 3.14159, 0, 0, 0.411143, -0.911571, 180, 0, 1, 0); -- Deathknight Wing Eye Portal Boss
-- Update flags & faction for glow eyes at boss-side
UPDATE `gameobject_template_addon` SET `faction`=0, `flags`=16 WHERE `entry` IN (181230, 181231, 181232, 181233);
-- Fix Thaddius end wing eye location and its glow ramp
UPDATE `gameobject` SET `position_x`=3539.016, `position_y`=-2936.821, `position_z`=302.4756, `orientation`=3.141593 WHERE `guid` IN (268047, 65856);
-- Kelthuzad's throne should not be selectable otherwise player can see the name file of the gobject
UPDATE `gameobject_template_addon` SET `flags`=16 WHERE `entry`=181640;
-- Remove first and third Naxxramas trigger
DELETE FROM `creature` WHERE `guid` IN (1971312, 1971314);


/* Fix SAI */
-- source for timers: https://wowgaming.altervista.org/aowow/
-- source for spells: https://wowhead.com/
-- Add comments on the SAI that I fix/touch

-- Fix timer for Acid Spit on Crypt Guard
UPDATE `smart_scripts` SET `event_param3`=4000 WHERE `entryorguid`=16573 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `event_param3`=4000 WHERE `entryorguid`=16573 AND `source_type`=0 AND `id`=2 AND `link`=0;
-- Fix timer for Frenzy on Crypt Guard
UPDATE `smart_scripts` SET `event_flags`=0, `event_param3`=120000, `event_param4`=120000 WHERE `entryorguid`=16573 AND `source_type`=0 AND `id`=5 AND `link`=0;
UPDATE `smart_scripts` SET `event_flags`=0, `event_param3`=120000, `event_param4`=120000 WHERE `entryorguid`=16573 AND `source_type`=0 AND `id`=3 AND `link`=0;
-- Fix Frenzy on Crypt Reaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=15978 AND `id` IN (1, 2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15978, 0, 1, 0, 2, 0, 100, 0, 0, 29, 120000, 120000, 0, 11, 56625, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crypt Reaver - On 30% HP - CastSelf Frenzy'),
(15978, 0, 2, 0, 2, 0, 100, 0, 0, 29, 120000, 120000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crypt Reaver - On 30% HP - Say EMOTE_FRENZY');
-- Fix timer for Shadow Bolt Volley on Naxxramas Acolyte
UPDATE `smart_scripts` SET `event_param4`=16000 WHERE `entryorguid`=15981 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `event_param4`=16000 WHERE `entryorguid`=15981 AND `source_type`=0 AND `id`=3 AND `link`=0;
-- Fix timer for Crypt Scarab Swarm on Tomb Horror
UPDATE `smart_scripts` SET `event_param2`=19000 WHERE  `entryorguid`=15979 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `event_param2`=19000 WHERE  `entryorguid`=15979 AND `source_type`=0 AND `id`=3 AND `link`=0;
-- Fix Frenzy on Infectious Ghoul
DELETE FROM `smart_scripts` WHERE `entryorguid`=16244 AND `source_type`=0 AND `id` IN (4, 5);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16244, 0, 4, 0, 2, 0, 100, 0, 0, 30, 60000, 60000, 0, 11, 54701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Infectious Ghoul - On 30% HP - CastSelf Frenzy'),
(16244, 0, 5, 0, 2, 0, 100, 0, 0, 30, 60000, 60000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Infectious Ghoul - On 30% HP - Say EMOTE_FRENZY');
-- Fix elemental immunity mechanic on Plague Slime (immunity based on elemental selection)
UPDATE `smart_scripts` SET `event_type`=4 WHERE `entryorguid`=16243 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16243 AND `source_type`=0 AND `id` IN (5, 6, 7, 8);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16243, 0, 5, 0, 23, 0, 100, 0, 28987, 1, 0, 0, 0, 75, 7743, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Plague Slime - On has aura - Add aura Immunity: Shadow'),
(16243, 0, 6, 0, 23, 0, 100, 0, 28988, 1, 0, 0, 0, 75, 7940, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Plague Slime - On has aura - Add aura Immunity: Frost'),
(16243, 0, 7, 0, 23, 0, 100, 0, 28989, 1, 0, 0, 0, 75, 7941, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Plague Slime - On has aura - Add aura Immunity: Nature'),
(16243, 0, 8, 0, 23, 0, 100, 0, 28990, 1, 0, 0, 0, 75, 7942, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Plague Slime - On has aura - Add aura Immunity: Fire');
-- Add Disease/Poison immunity on Plague Slime
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|2097152 WHERE `entry`=16243;
-- Fix timer for Acid Volley on Stoneskin Gargoyle
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=5000, `event_param3`=5000, `event_param4`=7000, `comment`='Stoneskin Gargoyle - In Combat - Cast Acid Volley' WHERE  `entryorguid`=16168 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Fix timer for Stoneskin on Stoneskin Gargoyle
UPDATE `smart_scripts` SET `event_param3`=60000, `event_param4`=60000, `event_phase_mask`=0, `comment`='Stoneskin Gargoyle - At 30% HP - Cast Stoneskin' WHERE  `entryorguid`=16168 AND `source_type`=0 AND `id` IN (2, 3) AND `link`=0;
-- Fix target for Frenzied Dive on Frenzied Bat
UPDATE `smart_scripts` SET `target_type`=2, `comment`='Frenzied Bat - In Combat - Cast Frenzied Dive' WHERE `entryorguid`=16036 AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Fix timer for Putrid Bite on Plagued Bat
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=6000, `event_param3`=9000, `event_param4`=13000, `comment`='Plagued Bat - In combat - Cast Putrid Bite' WHERE `entryorguid`=16037 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Fix aura of Mutated Spores on Plague Beast (must be on all of them, not just some)
DELETE FROM `creature_addon` WHERE `guid` IN (128171, 128172, 128173, 128174, 128175, 128176, 128177, 128178, 128179, 128180, 128181, 128182, 128183);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `isLarge`, `auras`) VALUES 
(128171, 0, 0, 0, 1, 0, 1, '30110'),
(128172, 0, 0, 0, 1, 0, 1, '30110'),
(128173, 0, 0, 0, 1, 0, 1, '30110'),
(128174, 0, 0, 0, 1, 0, 1, '30110'),
(128175, 0, 0, 0, 1, 0, 1, '30110'),
(128176, 0, 0, 0, 1, 0, 1, '30110'),
(128177, 1281770, 0, 0, 1, 0, 1, '30110'),
(128178, 1281780, 0, 0, 1, 0, 1, '30110'),
(128179, 1281790, 0, 0, 1, 0, 1, '30110'),
(128180, 0, 0, 0, 1, 0, 1, '30110'),
(128181, 0, 0, 0, 1, 0, 1, '30110'),
(128182, 0, 0, 0, 1, 0, 1, '30110'),
(128183, 1281830, 0, 0, 1, 0, 1, '30110');
-- Fix timer and trigger for Plague Splash on Plague Beast
UPDATE `smart_scripts` SET `event_type`=2, `event_param1`=0, `event_param2`=50, `event_param3`=25000, `event_param4`=30000, `comment`='Plague Beast - Between 0-50% HP - Cast Plague Splash' WHERE `entryorguid`=16034 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Fix trigger for Plague contamination on Plagued Ghoul (sniffed from shadowlands)
UPDATE `smart_scripts` SET `event_type`=6, `event_param1`=0, `event_param2`=0, `event_param3`=0, `event_param4`=0, `comment`='Plagued Ghoul - On death - Cast Plague contamination' WHERE `entryorguid`=16447 AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Fix Blood Presence on Death Knight
UPDATE `smart_scripts` SET `event_type`=4, `event_phase_mask`=0, `event_param2`=0, `comment`='On Aggro - Cast Self - Blood Presence' WHERE `entryorguid`=16146 AND `source_type`=0 AND `id`=2 AND `link`=0;
-- Fix timer and target selection for Death Coil (damage) on Death Knight
UPDATE `smart_scripts` SET `event_param1`=1000, `event_param2`=1400, `event_param3`=8500, `event_param4`=20500, `target_type`=5, `comment`='Death Knight - In combat - Cast Death Coil (damage)' WHERE  `entryorguid`=16146 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Fix Hysteria on Death Knight
UPDATE `smart_scripts` SET `event_type`=0, `event_param1`=1000, `event_param2`=7400, `event_param3`=10100, `event_param4`=17300, `target_type`=26, `target_param1`=20, `comment`='Death Knight - In combat - Cast Hysteria' WHERE  `entryorguid`=16146 AND `source_type`=0 AND `id`=3 AND `link`=0;
-- Add SAI for healing with Death Coil to friendly undead
DELETE FROM `smart_scripts` WHERE `entryorguid`=16146 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16146, 0, 4, 0, 14, 0, 50, 0, 80, 20, 16600, 17300, 0, 11, 55210, 0, 0, 0, 0, 0, 26, 20, 0, 0, 0, 0, 0, 0, 0, 'Death Knight - On Friendly HP Deficit - Cast Death Coil (heal)');
-- Recreate the whole SAI for Necro Knight (they will pick one magic school on aggro)
DELETE FROM `smart_scripts` WHERE entryorguid=16165 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16165, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 30, 1, 2, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Necro Knight - On Agro - Pick random Event Phase (1-2-3)'),
(16165, 0, 1, 0, 0, 1, 100, 0, 1000, 3200, 2800, 5200, 0, 11, 15453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Necro Knight - In combat - Cast Arcane Explosion'),
(16165, 0, 2, 0, 0, 1, 100, 0, 250, 500, 13200, 18500, 0, 11, 29883, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Necro Knight - In combat - Cast Blink'),
(16165, 0, 3, 0, 0, 2, 100, 0, 7600, 8100, 15000, 20000, 0, 11, 30092, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Necro Knight - In combat - Cast Blast Wave'),
(16165, 0, 4, 0, 0, 2, 100, 0, 1800, 8900, 9600, 15700, 0, 11, 30091, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 'Necro Knight - In combat - Cast Flamestrike'),
(16165, 0, 5, 0, 0, 4, 100, 0, 3000, 6000, 25000, 35000, 0, 11, 30094, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Necro Knight - In combat - Cast Frost Nova'),
(16165, 0, 6, 0, 0, 4, 100, 0, 17000, 21000, 17000, 23000, 0, 11, 30095, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Necro Knight - In combat - Cast Cone of Cold');
-- Fix timer for Shadow Bolt Volley on Shade of Naxxramas
UPDATE `smart_scripts` SET `event_param1`=2800, `event_param2`=5100, `event_param3`=4500, `event_param4`=12000, `comment`='Shade of Naxxramas - In combat - Cast Shadow Bolt Volley' WHERE `entryorguid`=16164 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Create SAI for Portal of Shadows on Shade of Naxxramas
DELETE FROM `smart_scripts` WHERE `entryorguid`=16164 AND `source_type`=0 AND `id` IN (2, 3) AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16164, 0, 2, 0, 0, 0, 100, 0, 4100, 8700, 60000, 60000, 0, 11, 28383, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Shade of Naxxramas - In combat - Cast Portal of Shadows'),
(16164, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 19, 16420, 0, 0, 0, 0, 0, 0, 0, 'Shade of Naxxramas - On reset - Despawn Portal of Shadows');
-- Fix timer for Whirlwind on Dark Touched Warrior
UPDATE `smart_scripts` SET `event_param1`=3300, `event_param2`=8900, `event_param3`=18900, `comment`='Dark Touched Warrior - In combat - Cast Whirlwind' WHERE `entryorguid`=16156 AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Fix timer for Plague Strike on Death Knight Captain
UPDATE `smart_scripts` SET `event_param1`=1600, `event_param2`=7200, `event_param3`=8100, `event_param4`=14100, `comment`='Death Knight Captain - In combat - Cast Plague Strike' WHERE `entryorguid`=16145 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Fix Unholy Presence on Death Knight Captain
UPDATE `smart_scripts` SET `event_type`=4, `event_phase_mask`=0, `event_param2`=0, `comment`='Death Knight Captain - On aggro - Cast Unholy Presence' WHERE `entryorguid`=16145 AND `source_type`=0 AND `id`=2 AND `link`=0;
-- Fix Raise Dead on Death Knight Captain
UPDATE `smart_scripts` SET `event_phase_mask`=0, `event_param1`=3500, `event_param2`=10200, `comment`='Death Knight Captain - In combat - Cast Raise Dead' WHERE `entryorguid`=16145 AND `source_type`=0 AND `id`=3 AND `link`=0;
-- Update Deathchill Servant's values as they were unused AC
UPDATE `creature_template` SET `DamageModifier`=2 WHERE `entry`=16390; -- naxx 10mode
UPDATE `creature_template` SET `DamageModifier`=4 WHERE `entry`=29901; -- naxx 25mode
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry` IN (16390, 29901); -- both versions
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=16390; -- Add AI
DELETE FROM `smart_scripts` WHERE `entryorguid`=16390 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0; /* Create SAI */
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16390, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathchill Servant - On spawn - Set in combat with zone'),
(16390, 0, 1, 0, 1, 0, 100, 0, 200, 200, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathchill Servant - On OOC - Despawn if OOC');
-- Fix timer for Crush Armor on Skeletal Smith
UPDATE `smart_scripts` SET `event_param1`=1700, `event_param2`=7900, `event_param3`=10500, `event_param4`=12900, `comment`='Skeletal Smith - In combat - Cast Crush Armor' WHERE `entryorguid`=16193 AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Fix timer for Disarm on Skeletal Smith
UPDATE `smart_scripts` SET `event_param1`=6200, `event_param2`=6700, `comment`='Skeletal Smith - In combat - Cast Disarm' WHERE `entryorguid`=16193 AND `source_type`=0 AND `id`=1 AND `link`=0;
-- Fix timer for Brutal Swipe on Bony Construct
UPDATE `smart_scripts` SET `event_param2`=20000, `comment`='Bony Construct - In combat - Cast Brutal Swipe' WHERE `entryorguid`=16167 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Fix timer and target selection for Strangulate on Death Knight Cavalier
UPDATE `smart_scripts` SET `event_param3`=4600, `event_param4`=7300, `target_type`=6, `comment`='Death Knight Cavalier - In combat - Cast Strangulate' WHERE `entryorguid`=16163 AND `source_type`=0 AND `id` IN (4, 5) AND `link`=0;
-- Fix timer and target selection for Icy Touch on Death Knight Cavalier
UPDATE `smart_scripts` SET `event_param1`=1100, `event_param2`=2200, `event_param3`=4100, `event_param4`=6200, `target_type`=5, `comment`='Death Knight Cavalier - In combat - Cast Icy Touch' WHERE `entryorguid`=16163 AND `source_type`=0 AND `id` IN (2, 3) AND `link`=0;
-- Fix timer for Bone Armor on Death Knight Cavalier
UPDATE `smart_scripts` SET `event_param1`=4700, `event_param2`=6100, `event_param3`=15700, `event_param4`=19800, `comment`='Death Knight Cavalier - In combat - Cast Bone Armor' WHERE `entryorguid`=16163 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Add SAI for Dismount Deathcharger on Death Knight Cavalier
DELETE FROM `smart_scripts` WHERE `entryorguid`=16163 AND `source_type`=0 AND `id`=6 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16163, 0, 6, 0, 2, 0, 100, 0, 0, 30, 0, 0, 0, 11, 55294, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Death Knight Cavalier - At 30% HP - Cast Dismount Deathcharger');
-- Adjust Charge for Deathcharger Steed
UPDATE `smart_scripts` SET `event_flags`=0, `comment`='Deathcharger Steed - In combat - Cast Charge' WHERE `entryorguid`=29818 AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Create SAI mechanic for appropiate mount/dismount of Deathcharger Steed (summon)
DELETE FROM `smart_scripts` WHERE `entryorguid`=29818 AND `source_type`=0 AND `id` IN (1, 2, 3) AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29818, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 43, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathcharger Steed - On spawn - Unmount summoner'),
(29818, 0, 2, 0, 1, 0, 100, 0, 200, 200, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathcharger Steed - On OOC - Despawn if OOC'),
(29818, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathcharger Steed - On spawn - Set in combat with zone');
-- Fix timer for Pierce Armor on Risen Squire
UPDATE `smart_scripts` SET `event_param1`=4000, `event_param2`=7000, `event_param4`=48000, `comment`='Risen Squire - In combat - Cast Pierce Armor' WHERE `entryorguid`=16154 AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Fix timer and target selection for Charge on Deathcharger Steed (non-summon)
UPDATE `smart_scripts` SET `event_param1`=3300, `event_param2`=7500, `event_param3`=10000, `event_param4`=10900, `target_type`=2, `comment`='Deathcharger Steed - On aggro - Cast Charge' WHERE `entryorguid`=16067 AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Fix timer for Mortal Strike on Unholy Axe
UPDATE `smart_scripts` SET `event_param1`=6100, `event_param2`=13100, `event_param3`=20100, `event_param4`=20100, `comment`='Unholy Axe - In combat - Cast Mortal Strike' WHERE `entryorguid`=16194 AND `source_type`=0 AND `id`=1 AND `link`=0;
-- Fix timer for Whirlwind on Unholy Axe
UPDATE `smart_scripts` SET `event_param1`=2200, `event_param2`=8600, `event_param3`=8800, `event_param4`=13300, `comment`='Unholy Axe - In combat - Cast Whirlwind' WHERE `entryorguid`=16194 AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Fix timer for Arcane Explosion on Unholy Staff
UPDATE `smart_scripts` SET `event_param1`=2400, `event_param2`=8400, `event_param3`=8400, `event_param4`=16100, `comment`='Unholy Staff - In combat - Cast Arcane Explosion' WHERE `entryorguid`=16215 AND `source_type`=0 AND `id`=0 AND `link`=0; -- (10mode)
UPDATE `smart_scripts` SET `event_param1`=9000, `event_param2`=16000, `event_param3`=20000, `event_param4`=30000, `comment`='Unholy Staff - In combat - Cast Arcane Explosion' WHERE `entryorguid`=16215 AND `source_type`=0 AND `id`=1 AND `link`=0; -- (25mode)
-- Fix timer for Frost Nova on Unholy Staff
UPDATE `smart_scripts` SET `event_param1`=6100, `event_param2`=10800, `comment`='Unholy Staff - In combat - Cast Frost Nova' WHERE `entryorguid`=16215 AND `source_type`=0 AND `id`=2 AND `link`=0;
-- Fix timer for Polymorph on Unholy Staff
UPDATE `smart_scripts` SET `event_param1`=4800, `event_param2`=6200, `event_param3`=14800, `event_param4`=14900, `target_type`=6, `comment`='Unholy Staff - In combat - Cast Polymorph' WHERE `entryorguid`=16215 AND `source_type`=0 AND `id`=3 AND `link`=0;
-- Fix timer for Cleave on Unholy Swords
UPDATE `smart_scripts` SET `event_param2`=4700, `event_param3`=9200, `event_param4`=15500, `comment`='Unholy Swords - In combat - Cast Cleave' WHERE `entryorguid`=16216 AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Recreate SAI for Thrash on Unholy Swords
UPDATE `smart_scripts` SET `event_type`=0, `event_param1`=2400, `event_param2`=7800, `event_param3`=12000, `event_param4`=13600, `action_param1`=12787, `comment`='Unholy Swords - In combat - Cast Thrash' WHERE `entryorguid`=16216 AND `source_type`=0 AND `id`=1 AND `link`=0;
-- Add Disarm immunity for Unholly (Axe/Staff/Swords)
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|4 WHERE `entry` IN (16194, 16215, 16216);
-- Re-do Invisibility on Vigilant Shade
UPDATE `smart_scripts` SET `event_type`=1, `event_param1`=1000, `event_param2`=1000, `event_param3`=5000, `event_param4`=5000, `action_type`=75, `comment`='Vigilant Shade - In OOC - Add aura Invisibility' WHERE `entryorguid`=30085 AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Adjust SAI in order to remove Invisibility on Vigilant Shade when there is a player around
UPDATE `smart_scripts` SET `event_type`=101, `event_param1`=1, `event_param2`=20, `event_param3`=1000, `event_param4`=1000, `comment`='Vigilant Shade - On Player near - Remove Invisibility' WHERE `entryorguid`=30085 AND `source_type`=0 AND `id`=1 AND `link`=0;
-- Fix timer for Shadow Bolt Volley on Shadow Shade
UPDATE `smart_scripts` SET `event_param1`=2300, `event_param2`=2300, `event_param3`=9600, `event_param4`=9900, `target_type`=2, `comment`='Vigilant Shade - In combat - Cast Shadow Bolt Volley' WHERE `entryorguid`=30085 AND `source_type`=0 AND `id` IN (2, 3) AND `link`=0;
-- Fix timer for Cleave on Patchwork Golem
UPDATE `smart_scripts` SET `event_param2`=9300, `event_param3`=15200, `event_param4`=15200, `comment`='Patchwork Golem - In combat - Cast Cleave' WHERE `entryorguid`=16017 AND `source_type`=0 AND `id`=2 AND `link`=0;
-- Fix timer for War Stomp on Patchwork Golem
UPDATE `smart_scripts` SET `event_param1`=4800, `event_param2`=10700, `comment`='Patchwork Golem - In combat - Cast War Stomp' WHERE `entryorguid`=16017 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Fix spell difficulty and timer for Execute on Patchwork Golem
UPDATE `smart_scripts` SET `event_phase_mask`=0, `event_flags`=4, `event_param4`=43000, `comment`='Patchwork Golem - On target HP 0-20% - Cast Execute' WHERE `entryorguid`=16017 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `event_phase_mask`=0, `event_flags`=2, `event_param4`=43000, `comment`='Patchwork Golem - On target HP 0-20% - Cast Execute' WHERE `entryorguid`=16017 AND `source_type`=0 AND `id`=4 AND `link`=0;
-- Fix timer for Bile Vomit on Bile Retcher
UPDATE `smart_scripts` SET `event_param1`=3600, `event_param2`=6800, `event_param3`=13700, `event_param4`=19700, `comment`='Bile Retcher - In combat - Cast Bile Vomit' WHERE `entryorguid`=16018 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Fix timer for Acidic Sludge on Sludge Belcher
UPDATE `smart_scripts` SET `event_param1`=1900, `event_param2`=3000, `event_param3`=6000, `event_param4`=7300, `comment`='Sludge Belcher - In combat - Cast Acidic Sludge' WHERE `entryorguid`=16029 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Add SAI for Disease Cloud on Sludge Belcher
DELETE FROM `smart_scripts` WHERE `entryorguid`=16029 AND `source_type`=0 AND `id`=2 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16029, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 28362, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sludge Belcher - On reset - Cast Disease Cloud');
-- Fix timer for Chain Lightning on Living Monstrosity
UPDATE `smart_scripts` SET `event_param1`=7100, `event_param2`=12500, `event_param3`=18100, `event_param4`=20900, `target_type`=5, `comment`='Living Monstrosity - In combat - Cast Chain Lightning' WHERE `entryorguid`=16021 AND `source_type`=0 AND `id`=0 AND `link`=0; -- (10mode)
UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=8000, `event_param4`=24000, `target_type`=5, `comment`='Living Monstrosity - In combat - Cast Chain Lightning' WHERE `entryorguid`=16021 AND `source_type`=0 AND `id`=1 AND `link`=0; -- (25mode)
-- Fix timer for Lightning Totem on Living Monstrosity
UPDATE `smart_scripts` SET `event_param1`=6400, `event_param2`=10000, `event_param3`=16900, `event_param4`=18500, `comment`='Living Monstrosity - In combat - Cast Lightning Totem' WHERE `entryorguid`=16021 AND `source_type`=0 AND `id`=2 AND `link`=0;
-- Fix timer and target for Mana Burn on Mad Scientist
UPDATE `smart_scripts` SET `event_param1`=7600, `event_param2`=17300, `event_param3`=6000, `event_param4`=13300, `target_param1`=0, `comment`='Mad Scientist - In combat - Cast Mana Burn' WHERE `entryorguid`=16020 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Fix timer and target for Great Heal on Mad Scientist
UPDATE `smart_scripts` SET `event_type`=2, `event_param1`=0, `event_param2`=30, `event_param3`=18000, `event_param4`=21000, `target_type`=1, `target_param1`=0, `comment`='Mad Scientist - At 30% HP - Cast Great Heal' WHERE `entryorguid`=16020 AND `source_type`=0 AND `id` IN (2, 3) AND `link`=0;
-- Fix timer for Mind Flay on Surgical Assistant
UPDATE `smart_scripts` SET `event_param1`=1600, `event_param2`=2800, `event_param3`=7700, `event_param4`=11900, `comment`='Surgical Assistant - In combat - Cast Mind Flay' WHERE `entryorguid`=16022 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Adjust timer for Knockback on Stitched Giant
UPDATE `smart_scripts` SET `event_param1`=5100, `event_param2`=10400, `event_param3`=18800, `event_param4`=21300 WHERE `entryorguid`=16025 AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Update comment for Unstoppable Enrage on Stitched Giant
UPDATE `smart_scripts` SET `comment`='Stitched Giant - At 30% HP - Cast self Unstoppable Enrage' WHERE `entryorguid`=16025 AND `source_type`=0 AND `id`=1 AND `link`=0;
-- Fix timer for Massive Stomp on Stitched Colossus
UPDATE `smart_scripts` SET `event_param1`=5400, `event_param2`=12200, `event_param3`=15500, `event_param4`=22300, `comment`='Stitched Colossus - In combat - Cast Massive Stomp' WHERE `entryorguid`=30071 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
-- Fix Unstoppable Enrage on Stitched Colossus
UPDATE `smart_scripts` SET `event_phase_mask`=0, `event_flags`=1, `comment`='Stitched Colossus - At 30% HP - Cast Unstoppable Enrage' WHERE `entryorguid`=30071 AND `source_type`=0 AND `id`=2 AND `link`=0;
-- Fix movement speed for KT minions
UPDATE `creature_template` SET `speed_walk`=0.1, `speed_run`=0.2 WHERE `entry` IN (16429, 30018); -- Soul Weaver
UPDATE `creature_template` SET `speed_walk`=0.2, `speed_run`=0.3 WHERE `entry` IN (16427, 30015); -- Soldier of the Frozen Wastes


-- Fix "Portal of Shadows" spell-mechanic which is used by Shade of Naxxramas

-- Portal of Shadows (NPC)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=16420;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16420 AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16420, 0, 0, 0, 101, 0, 100, 0, 1, 40, 5000, 5000, 0, 12, 16419, 3, 10000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Portal of Shadows - On player near - Summon Ghost of Naxxramas');

-- Ghost of Naxxramas
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=16419;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16419 AND `source_type`=0 AND `id` IN (0, 1) AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16419, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ghost of Naxxramas - On spawn - Set in combat with zone'),
(16419, 0, 1, 0, 1, 0, 100, 0, 100, 100, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ghost of Naxxramas - On OOC - Despawn if OOC');


-- Fix Vigilant Shade population in Naxxramas
UPDATE `creature` SET `position_x`=2798.932, `position_y`=-2985.458, `position_z`=244.387, `orientation`=6.2765, `wander_distance`=40 WHERE `guid`=128065;
DELETE FROM `creature` WHERE `guid` IN (128062, 128063, 128064, 128081, 128125, 128126, 128127);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(128062, 30085, 533, 0, 0, 3, 1, 19329, 0, 2556.97, -3231.98, 246.370, 3.10938, 3600, 40, 0, 130330, 0, 1, 0, 0, 0, 0),
(128063, 30085, 533, 0, 0, 3, 1, 19329, 0, 2557.78, -3633.28, 273.809, 3.18988, 3600, 40, 0, 130330, 0, 1, 0, 0, 0, 0),
(128064, 30085, 533, 0, 0, 3, 1, 19329, 0, 2795.33, -3882.25, 279.417, 3.12988, 3600, 40, 0, 130330, 0, 1, 0, 0, 0, 0),
(128081, 30085, 533, 0, 0, 3, 1, 19329, 0, 3204.13, -3881.97, 273.901, 3.10888, 3600, 40, 0, 130330, 0, 1, 0, 0, 0, 0),
(128125, 30085, 533, 0, 0, 3, 1, 19329, 0, 3453.84, -3638.10, 276.313, 3.15988, 3600, 40, 0, 130330, 0, 1, 0, 0, 0, 0),
(128126, 30085, 533, 0, 0, 3, 1, 19329, 0, 3454.06, -3232.31, 275.430, 3.10488, 3600, 40, 0, 130330, 0, 1, 0, 0, 0, 0),
(128127, 30085, 533, 0, 0, 3, 1, 19329, 0, 3206.94, -2985.55, 275.347, 3.12938, 3600, 40, 0, 130330, 0, 1, 0, 0, 0, 0);


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
