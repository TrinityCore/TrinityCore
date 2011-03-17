-- Template updates (TDB)
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35637; -- Marshal Jacob Alerius' Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35633; -- Ambrose Boltspark's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35768; -- Colosos' Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=34658; -- Jaelyne Evensong's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35636; -- Lana Stouthammer's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35638; -- Mokra the Skullcrusher's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571,`VehicleId`=480 WHERE `entry`=35635; -- Eressea Dawnsinger's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35640; -- Runok Wildmane's Mount
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571,`VehicleId`=485 WHERE `entry`=35641; -- Zul'tore's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.28968 WHERE `entry`=35634; -- Deathstalker Visceri's Mount
-- Addon data (TDB)
DELETE FROM `creature_template_addon` WHERE `entry` IN (35637,35633,35768,34658,35636,35638,35635,35640,35641,35634);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(35637,0,0,1,0, '67870 0'), -- Marshal Jacob Alerius' Mount, Auras: Trample
(35633,0,0,1,0, '67870 0'), -- Ambrose Boltspark's Mount
(35768,0,0,1,0, '67870 0'), -- Colosos' Mount
(34658,0,0,1,0, '67870 0'), -- Jaelyne Evensong's Mount
(35636,0,0,1,0, '67870 0'), -- Lana Stouthammer's Mount
(35638,0,0,1,0, '67870 0'), -- Mokra the Skullcrusher's Mount
(35635,0,0,1,0, '67870 0'), -- Eressea Dawnsinger's Mount
(35640,0,0,1,0, '67870 0'), -- Runok Wildmane's Mount
(35641,0,0,1,0, '67870 0'), -- Zul'tore's Mount
(35634,0,0,1,0, '67870 0'); -- Deathstalker Visceri's Mount
-- Spellclick (TDB)
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (35637,35633,35768,34658,35636,35638,35635,35640,35641,35634);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(35637,46598,0,0,0,1,0,0,0), -- Marshal Jacob Alerius' Mount - Ride Vehicle Hardcoded
(35633,46598,0,0,0,1,0,0,0), -- Ambrose Boltspark's Mount - Ride Vehicle Hardcoded
(35768,46598,0,0,0,1,0,0,0), -- Colosos' Mount - Ride Vehicle Hardcoded
(34658,46598,0,0,0,1,0,0,0), -- Jaelyne Evensong's Mount - Ride Vehicle Hardcoded
(35636,46598,0,0,0,1,0,0,0), -- Lana Stouthammer's Evensong's Mount - Ride Vehicle Hardcoded
(35638,46598,0,0,0,1,0,0,0), --  Mokra the Skullcrusher's Mount - Ride Vehicle Hardcoded
(35635,46598,0,0,0,1,0,0,0), -- Eressea Dawnsinger's Mount - Ride Vehicle Hardcoded
(35640,46598,0,0,0,1,0,0,0), -- Runok Wildmane's Mount - Ride Vehicle Hardcoded
(35641,46598,0,0,0,1,0,0,0), -- Zul'tore's Mount - Ride Vehicle Hardcoded
(35634,46598,0,0,0,1,0,0,0); -- Deathstalker Visceri's Mount - Ride Vehicle Hardcoded
-- Model data (TDB)
UPDATE `creature_model_info` SET `bounding_radius`=0,`combat_reach`=1,`gender`=0 WHERE `modelid`=29255; -- Colosos' Mount
UPDATE `creature_model_info` SET `bounding_radius`=0.525,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=9991; -- Jaelyne Evensong's Mount
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=2,`gender`=0 WHERE `modelid`=2787; -- Lana Stouthammer's Mount
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=1.5,`gender`=2 WHERE `modelid`=29879; -- Mokra the Skullcrusher's Mount
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1,`gender`=2 WHERE `modelid`=28607; -- Eressea Dawnsinger's Mount
UPDATE `creature_model_info` SET `bounding_radius`=0.34,`combat_reach`=1.5,`gender`=2 WHERE `modelid`=29880; -- Runok Wildmane's Mount
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=1.5,`gender`=2 WHERE `modelid`=10718; -- Deathstalker Visceri's Mount
-- Vehicles (TDB) 
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (35637,35633,35768,34658,35636,35638,35635,35640,35641,35634);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(35637, 34705, 0, 0, 'Marshal Jacob Alerius'' Mount', 6, 30000),
(35633, 34702, 0, 0, 'Ambrose Boltspark''s Mount', 6, 30000),
(35768, 34701, 0, 0, 'Colosos'' Mount', 6, 30000),
(34658, 34657, 0, 0, 'Jaelyne Evensong''s Mount', 6, 30000),
(35636, 34703, 0, 0, 'Lana Stouthammer''s Mount', 6, 30000),
(35638, 35572, 0, 0, 'Mokra the Skullcrusher''s Mount', 6, 30000),
(35635, 35569, 0, 0, 'Eressea Dawnsinger''s Mount', 6, 30000),
(35640, 35571, 0, 0, 'Runok Wildmane''s Mount', 6, 30000),
(35641, 35570, 0, 0, 'Zul''tore''s Mount', 6, 30000),
(35634, 35617, 0, 0, 'Deathstalker Visceri''s Mount', 6, 30000);

-- Trial of the champion
-- Faction of Argent Warhorse and Argent Battleworg
UPDATE `creature_template` SET `faction_H`=16 WHERE `entry`=35644;
UPDATE `creature_template` SET `faction_A`=16 WHERE `entry`=36558;
-- Unit flags Battleworg
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=36558;
-- Spells for Battleworg
UPDATE `creature_template` SET `spell1`=68505, `spell2`=62575, `spell3`=68282, `spell4`=66482 WHERE `entry`=36558;
-- Vehicleid of Warhorse
UPDATE `creature_template` SET `VehicleId`=486 WHERE `entry`=35644;
-- Speeds
UPDATE `creature_template` SET `speed_run`=2 WHERE `entry` IN (36558, 35644);
-- Attacktime
UPDATE `creature_template` SET `baseattacktime`=0 WHERE `entry` IN (36558, 35644);
-- Vehicle template accessory for minions
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (33321, 33323, 33320, 33322, 33316, 33317, 33324, 33217, 33318, 33319);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`) VALUES
(33321,35323,0,1, 'Darkspear Raptor'),
(33323,35326,0,1, 'Silvermoon Hawkstrider'),
(33320,35314,0,1, 'Orgrimmar Wolf'),
(33322,35325,0,1, 'Thunder Bluff Kodo'),
(33316,35329,0,1, 'Ironforge Ram'),
(33317,35331,0,1, 'Gnomeregan Mechanostrider'),
(33324,35327,0,1, 'Forsaken Warhorse'),
(33217,35328,0,1, 'Stormwind Steed'),
(33318,35330,0,1, 'Exodar Elekk'),
(33319,35332,0,1, 'Darnassian Nightsaber');
-- Equipements ids 
UPDATE `creature_template` SET `equipment_id`=2049 WHERE `entry` in (35314,35326,35327,35325,35323,35331,35330,35329,35328,35332);
UPDATE `creature_template` SET `equipment_id`=2025 WHERE `entry` in (35571,36090);
UPDATE `creature_template` SET `equipment_id`=2021 WHERE `entry` in (35569,36085);
UPDATE `creature_template` SET `equipment_id`=2018 WHERE `entry` in (35572,36089);
UPDATE `creature_template` SET `equipment_id`=2020 WHERE `entry` in (35617,36084);
UPDATE `creature_template` SET `equipment_id`=2019 WHERE `entry` in (35570,36091);
UPDATE `creature_template` SET `equipment_id`=2096 WHERE `entry` in (34701,36803);
UPDATE `creature_template` SET `equipment_id`=2093 WHERE `entry` in (34703,36087);
UPDATE `creature_template` SET `equipment_id`=2095 WHERE `entry` in (34657,36086);
UPDATE `creature_template` SET `equipment_id`=2092 WHERE `entry` in (34705,36088);
UPDATE `creature_template` SET `equipment_id`=834 WHERE `entry` in (35119,35518);
UPDATE `creature_template` SET `equipment_id`=235 WHERE `entry` in (34928,35517);
UPDATE `creature_template` SET `equipment_id`=0 WHERE `entry` in (35451,35490);

-- Scriptname, hp, damage, level
UPDATE `creature_template` SET `ScriptName`='generic_vehicleAI_toc5', `minlevel`='80', `maxlevel`='80', `rank`='1', `mindmg`='420', `maxdmg`='630', `attackpower`='157', `Health_mod`='5,95238' WHERE `entry` IN (33324, 33321, 33322, 33320, 33323, 33319, 33318, 33317, 33316, 33324);

-- Hp, damage and level.. 
UPDATE `creature_template` SET `unit_flags`=0 , `minlevel`='80', `maxlevel`='80', `mindmg`='420', `rank`='1', `maxdmg`='630', `attackpower`='157', `Health_mod`='15' WHERE `entry` IN (35635, 35640, 35634, 35638, 35641, 34658, 35633, 35768, 35636, 35637);

-- Npcs on vehicle should be passive and untargettable 
-- (not blizzlike, but only way to make the event works. On offy players must kill the champions not the vehicles..)
UPDATE `creature_template` SET `AIName`='PassiveAI', `unit_flags`=33554434 WHERE `entry` IN (SELECT `accessory_entry` FROM `vehicle_template_accessory` WHERE `entry` IN (33324, 33321, 33322, 33320, 33323, 33319, 33318, 33317, 33316, 33324));

-- scale of mokra mount
UPDATE `creature_template` SET `scale`=1.5 WHERE `entry`=35638;

-- Revert PassiveAI for champions on mount
UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (SELECT `accessory_entry` FROM `vehicle_template_accessory` WHERE `entry` IN (33324, 33321, 33322, 33320, 33323, 33319, 33318, 33317, 33316, 33324));

-- Template update of all Memories of boss "Argent Confessor Paletress"
UPDATE `creature_template` SET `faction_A`=16, `faction_H`=16, `rank`=1, `minlevel`=82, `maxlevel`=82, `exp`=2 WHERE `name` LIKE 'Memory of %';

-- Faction of vehicles
UPDATE `creature_template` SET `Faction_A`=16, `Faction_H`=16 WHERE `entry` IN (33324, 33321, 33322, 33320, 33323, 33319, 33318, 33317, 33316, 33324);

-- Scriptname of all Memories of boss "Argent Confessor Paletress"
UPDATE `creature_template` SET `scriptname`='npc_memory' WHERE `name` LIKE 'Memory of %';

-- Vehicle for black knight
DELETE FROM `vehicle_template_accessory` WHERE `entry` = 35491;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`) VALUES
(35491,35451,0,0, 'Trial of the Champion - Black Knight on his gryphon');

-- Black Knight Gryphon
UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35, `mindmg`=0, `maxdmg`=0, `attackpower`=0, `dmg_multiplier`=0, `baseattacktime`=0, `unit_flags`=33554432, `dynamicflags`=0, `minrangedmg`=0, `maxrangedmg`=0, `rangedattackpower`=0, `VehicleId`=486 WHERE `entry`=35491;

-- Boss immune mask
UPDATE `creature_template` SET `mechanic_immune_mask`=805257215 WHERE `entry` IN (35490,35451,35518,35517);

-- Spellids fix for mounts 
UPDATE `creature_template` SET `spell1`=62544, `spell3`=63010 WHERE `entry`IN(35644,36558);

-- Black Knight gryphon
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 35491;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(35491,46598,0,0,0,0,0,0,0);

-- Script texts
DELETE FROM `script_texts` WHERE `entry` <= -1999926 and `entry` >= -1999970;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(0,-1999926, 'Coming out of the gate Grand Champions other faction.  ' ,0,0,0,1, 'SAY_START' ),
(0,-1999927, 'Good work! You can get your award from Crusader\'s Coliseum chest!.  ' ,0,1,0,1, 'Win' ),
(0,-1999928, 'You spoiled my grand entrance. Rat.' ,16256,1,0,5, 'SAY_AGGRO' ),
(0,-1999929, 'Did you honestly think an agent if the Kich King would be bested on the field of your pathetic little tournament?' ,16257,1,0,5, 'SAY_AGGRO_1' ),
(0,-1999930, 'I have come to finish my task ' ,16258,1,0,5, 'SAY_AGGRO_2' ),
(0,-1999931, 'This farce ends here!' ,16259,1,0,5, 'SAY_AGGRO_3' ),
(0,-1999932, '[Zombie]Brains.... .... ....' ,0,1,0,5, 'SAY_SLAY' ),
(0,-1999933, 'My roting flash was just getting in the way!' ,16262,1,0,5, 'SAY_DEATH_1' ),
(0,-1999934, 'I have no need for bones to best you!' ,16263,1,0,5, 'SAY_DEATH_2' ),
(0,-1999935, 'No! I must not fail...again...' ,16264,1,0,5, 'SAY_DEATH_3' ),
(0,-1999936, 'What\'s that. up near the rafters ?' ,0,1,0,5, 'detected' ),
(0,-1999937, 'Please change your weapon! Next battle will be start now!' ,0,3,0,5, 'nx' ),
(0,-1999939, 'Excellent work!' ,0,1,0,1, 'work' ),
(0,-1999940, 'Coming out of the gate Crusader\'s Coliseum Champion.' ,0,0,0,1, 'SAY_START3' ),
(0,-1999941, 'Excellent work! You are win Argent champion!' ,0,3,0,0, 'win' ),
(0,-1999942, 'The Sunreavers are proud to present their representatives in this trial by combat.' ,0,0,0,1, 'an1' ),
(0,-1999943, 'Welcome, champions. Today, before the eyes of your leeders and peers, you will prove youselves worthy combatants.' ,0,0,0,1, 'an2' ),
(0,-1999944, 'Fight well, Horde! Lok\'tar Ogar!' ,0,1,0,5, 'Thrall' ),
(0,-1999945, 'Finally, a fight worth watching.' ,0,1,0,5, 'Garrosh' ),
(0,-1999946, 'I did not come here to watch animals tear at each other senselessly, Tirion' ,0,1,0,5, 'King' ),
(0,-1999947, 'You will first be facing three of the Grand Champions of the Tournament! These fierce contenders have beaten out all others to reach the pinnacle of skill in the joust.' ,0,1,0,5, 'Hightlord' ),
(0,-1999948, 'Will tought! You next challenge comes from the Crusade\'s own ranks. You will be tested against their consederable prowess.' ,0,1,0,5, 'Hightlord2' ),
(0,-1999949, 'You may begin!' ,0,0,0,5, 'text' ),
(0,-1999951, 'Take this time to consider your past deeds.' ,16248,1,0,5, 'palsum' ),
(0,-1999952, 'What is the meaning of this?' ,0,1,0,5, 'dk_hightlord' ),
(0,-1999953, 'No...I\'m still too young' ,0,1,0,5, 'die' ),
(0,-1999954, 'Excellent work! You are win Argent champion!' ,0,3,0,0, 'win' ),
(0,-1999969, 'Pathetic.' ,16260, 1, 0, 0, NULL),
(0,-1999955, 'Well then, let us begin.' ,16247, 1, 0, 0, 'start'),
(0,-1999960, 'Take your rest.' ,16250, 1, 0, 0, NULL),
(0,-1999959, 'Be at ease.' ,16251, 1, 0, 0, NULL),
(0,-1999957, 'You... You need more practice.' ,16137, 1, 0, 0, NULL),
(0,-1999958, 'Nay! Nay! And I say yet again nay! Not good enough!' ,16138, 1, 0, 0, NULL),
(0,-1999961, 'Prepare yourselves!' ,16135, 1, 0, 0, NULL),
(0,-1999962, 'I yield! I submit. Excellent work. May I run away now?' ,16139, 1, 0, 0, NULL),
(0,-1999963, 'Hammer of the Righteous!' ,16136, 1, 0, 0, NULL),
(0,-1999964, 'Are you up to the challenge? I will not hold back.' ,16134, 1, 0, 0, NULL),
(0,-1999965, 'Thank you, good herald. Your words are too kind.' ,16245, 1, 0, 0, NULL),
(0,-1999966, 'May the Light give me strength to provide a worthy challenge.' ,16246, 1, 0, 0, NULL),
(0,-1999967, 'Excellent work!' ,16252, 1, 0, 0, NULL),
(0,-1999968, 'Even the darkest memory fades when confronted.' ,16249, 1, 0, 0, NULL),
(0,-1999970, 'A waste of flesh.' ,16261, 1, 0, 0, NULL);

-- Unused gate
DELETE FROM `gameobject` WHERE `guid`=150077;

-- Despawn old announcer
DELETE FROM `creature` WHERE `guid`=200038;
-- Insert new announcer
DELETE FROM `creature_template` WHERE `entry` in (35591,35592);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES 
(35591, 0, 0, 0, 0, 0, 29894, 0, 0, 0, 'Jaeren Sunsworn', '', '', 0, 75, 75, 2, 14, 14, 0, 1, 1, 0, 0, 0, 0, 0, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_anstart'),
(35592, 0, 0, 0, 0, 0, 29893, 0, 0, 0, 'Arelas Brightstar', '', '', 0, 75, 75, 2, 14, 14, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 512, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_anstart');-- Spawn new announcer
DELETE FROM `creature` WHERE `guid` = 230961;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`) VALUES 
(230961, 35591, 650, 3, 1, 0, 0, 746.626, 618.54, 411.09, 4.63158, 86400, 0, 0, 10635, 0, 0, 0);

DELETE FROM `creature` WHERE `guid` = 230961; -- Despwan an_start
DELETE FROM `creature` WHERE `guid` = 200038; -- despwan announcer
INSERT INTO `creature` VALUES (200038, 35004, 650, 3, 1, 0, 0, 748.309, 619.488, 411.172, 4.71239, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0); -- spawn announcer
-- Modify faction for mounts of players
UPDATE `creature_template` SET `faction_A`=84, `faction_H`=84 WHERE `entry`=35644;
UPDATE `creature_template` SET `faction_A`=83, `faction_H`=83 WHERE `entry`=36558;

-- Stormwind steed template 
UPDATE `creature_template` SET `rank`=1, `Health_mod`=5, `faction_A`=16, `faction_H`=16, `ScriptName`='generic_vehicleAI_toc5' WHERE `entry`=33217;
-- Stomwind champion template
UPDATE `creature_template` SET `unit_flags`=33554434, `AIName`='' WHERE `entry`=35328;

DELETE FROM `spell_script_names` WHERE `spell_id` = 66515;
INSERT INTO `spell_script_names` VALUES
('66515', 'spell_gen_reflective_shield');

DELETE FROM `spell_script_names` WHERE `spell_id` = 68504;
INSERT INTO `spell_script_names` VALUES
('68504', 'spell_gen_npcshieldbreaker');

DELETE FROM `spell_script_names` WHERE `spell_id` in (62575, 63010);
INSERT INTO `spell_script_names` VALUES
('62575', 'spell_gen_shieldbreaker'),
('63010', 'spell_gen_atcharge');