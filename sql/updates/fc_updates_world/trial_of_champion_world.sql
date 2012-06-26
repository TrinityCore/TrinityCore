-- Trial of the Champion

-- ScriptName
UPDATE `creature_template` SET `AIName`='PassiveAI' WHERE `entry` IN (35332,35330,35328,35327,35331,35329,35325,35314,35326,35323);
UPDATE `instance_template` SET `script`='instance_trial_of_the_champion' WHERE `map`=650;
UPDATE `creature_template` SET `ScriptName`='generic_vehicleAI_toc5' WHERE `entry` IN (33299, 35637,35633,35768,34658,35636,35638,35635,35640,35641,35634,33298,33416,33297,33414,33301,33408,33300,33409,33418);
UPDATE `creature_template` SET `ScriptName`='boss_warrior_toc5' WHERE `entry` IN (34705,35572);
UPDATE `creature_template` SET `ScriptName`='boss_mage_toc5' WHERE `entry` IN (34702,35569);
UPDATE `creature_template` SET `ScriptName`='boss_shaman_toc5' WHERE `entry` IN (35571,34701);
UPDATE `creature_template` SET `ScriptName`='boss_hunter_toc5' WHERE `entry` IN (35570,34657);
UPDATE `creature_template` SET `ScriptName`='boss_rouge_toc5' WHERE `entry` IN (35617,34703);
UPDATE `creature_template` SET `ScriptName`='npc_announcer_toc5' WHERE `entry`IN (35004,35005);
UPDATE `creature_template` SET `ScriptName`='npc_risen_ghoul' WHERE `entry` IN (35545,35564);
UPDATE `creature_template` SET `ScriptName`='boss_black_knight' WHERE `entry`=35451;
UPDATE `creature_template` SET `ScriptName`='boss_eadric' WHERE `entry`=35119;
UPDATE `creature_template` SET `ScriptName`='boss_paletress' WHERE `entry`=34928;
UPDATE `creature_template` SET `ScriptName`='npc_memory' WHERE `entry` IN (35052,35041,35033,35046,35043,35047,35044,35039,35034,35049,35030,34942,35050,35042,35045,35037,35031,35038,35029,35048,35032,35028,35040,35036,35051);
UPDATE `creature_template` SET `ScriptName`='npc_argent_soldier'  WHERE `entry` IN (35309,35305,35307);
UPDATE `creature_template` SET `ScriptName`='npc_black_knight_skeletal_gryphon' WHERE `entry`=35491;

-- Open Entrance Door
UPDATE `gameobject` SET `state` = 0 WHERE `guid` = 1804;

-- Mounts
DELETE FROM `vehicle_template_accessory` WHERE `entry` in (35491,33299,33418,33409,33300,33408,33301,33414,33297,33416,33298);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`) VALUES
(35491,35451,0,0, 'Black Knight'),
(33299,35323,0,1, 'Darkspear Raptor'),
(33418,35326,0,1, 'Silvermoon Hawkstrider'),
(33409,35314,0,1, 'Orgrimmar Wolf'),
(33300,35325,0,1, 'Thunder Bluff Kodo'),
(33408,35329,0,1, 'Ironforge Ram'),
(33301,35331,0,1, 'Gnomeregan Mechanostrider'),
(33414,35327,0,1, 'Forsaken Warhorse'),
(33297,35328,0,1, 'Stormwind Steed'),
(33416,35330,0,1, 'Exodar Elekk'),
(33298,35332,0,1, 'Darnassian Nightsaber');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` in (33299,33418,33409,33300,33408,33301,33414,33297,33416,33298);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(33299, 68503, 1, 0),
(33418, 68503, 1, 0),
(33409, 68503, 1, 0),
(33300, 68503, 1, 0),
(33408, 68503, 1, 0),
(33301, 68503, 1, 0),
(33414, 68503, 1, 0),
(33297, 68503, 1, 0),
(33416, 68503, 1, 0),
(33298, 68503, 1, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry` in (33318,33319,33316,33317,33217,33324,33322,33320,33323,33321);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`minion`,`description`) VALUES
('33318', '35330', '1', 'Exodar Elekk'),
('33319', '35332', '1', 'Darnassian Nightsaber'),
('33316', '35329', '1', 'Ironforge Ram'),
('33317', '35331', '1', 'Gnomeregan Mechanostrider'),
('33217', '35328', '1', 'Stormwind Steed'),
('33324', '35327', '1', 'Forsaken Warhorse'),
('33322', '35325', '1', 'Thunder Bluff Kodo'),
('33320', '35314', '1', 'Orgrimmar Wolf'),
('33323', '35326', '1', 'Silvermoon Hawkstrider'),
('33321', '35323', '1', 'Darkspear Raptor');

UPDATE `creature_template` SET `minlevel` = 80,`maxlevel` = 80 WHERE `entry` in (33298,33416,33297,33301,33408,35640,33299,33300,35634,33418,35638,33409,33414,33299,35635,35641);
UPDATE `creature_template` SET `faction_A` = 14,`faction_H` = 14 WHERE `entry` in (33318, 33319, 33316, 33317, 33217, 33324, 33322, 33320, 33323, 33321, 33298,33416,33297,33301,33408,35545,33299,35564,35590,35119,34928,35309,35305,33414,35307,35325,33300,35327,35326,33418,35638,35314,33409,33299,35635,35640,35641,35634,35633,35636,35768,35637,34658);
UPDATE `creature_template` SET `Health_mod` = 10,`mindmg` = 20000,`maxdmg` = 30000 WHERE `entry` in (33298,33416,33297,33301,33408,33409,33418,33300,33414,33299,33298,33416,33297,33301,33408,35640,35638,35634,35635,35641,35633,35636,35768,35637,34658);
UPDATE `creature_template` SET `speed_run` = 2,`Health_mod` = 40,`mindmg` = 10000,`maxdmg` = 20000,`spell1` =68505,`spell2` =62575,`spell3` =68282,`spell4` =66482 WHERE `entry` in (35644,36558, 36559, 36557);
UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `id` in (35644,36558, 36559, 36557);
UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35 WHERE `entry` in (35644,36558, 36559, 36557);
-- VehicleId
UPDATE `creature_template` SET `VehicleId`=486 WHERE `entry` in (36558, 35644, 36559, 36557);
-- faction for Vehicle
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35 WHERE `entry` in (36558, 35644, 36559, 36557);
UPDATE `creature` SET `id` = 35644 WHERE `id` = 36557;
UPDATE `creature` SET `id` = 36558 WHERE `id` = 36559;

-- Texts
DELETE FROM `script_texts` WHERE `entry` <= -1999926 and `entry` >= -1999956;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(0,-1999926, 'Coming out of the gate Grand Champions other faction.  ' ,0,0,0,1, '' ),
(0,-1999927, 'Good work! You can get your award from Crusader\'s Coliseum chest!.  ' ,0,1,0,1, '' ),
(0,-1999928, 'You spoiled my grand entrance. Rat.' ,16256,1,0,5, '' ),
(0,-1999929, 'Did you honestly think an agent if the Lich King would be bested on the field of your pathetic little tournament?' ,16257,1,0,5, '' ),
(0,-1999930, 'I have come to finish my task ' ,16258,1,0,5, '' ),
(0,-1999931, 'This farce ends here!' ,16259,1,0,5, '' ),
(0,-1999932, '[Zombie]Brains.... .... ....' ,0,1,0,5, '' ),
(0,-1999933, 'My roting flash was just getting in the way!' ,16262,1,0,5, '' ),
(0,-1999934, 'I have no need for bones to best you!' ,16263,1,0,5, '' ),
(0,-1999935, 'No! I must not fail...again...' ,16264,1,0,5, '' ),
(0,-1999936, 'What\'s that. up near the rafters ?' ,0,1,0,5, '' ),
(0,-1999937, 'Please change your weapon! Next battle will be start now!' ,0,3,0,5, '' ),
(0,-1999939, 'Excellent work!' ,0,1,0,1, '' ),
(0,-1999940, 'Coming out of the gate Crusader\'s Coliseum Champion.' ,0,0,0,1, '' ),
(0,-1999941, 'Excellent work! You are win Argent champion!' ,0,3,0,0, '' ),
(0,-1999942, 'The Sunreavers are proud to present their representatives in this trial by combat.' ,0,0,0,1, '' ),
(0,-1999943, 'Welcome, champions. Today, before the eyes of your leeders and peers, you will prove youselves worthy combatants.' ,0,0,0,1, '' ),
(0,-1999944, 'Fight well, Horde! Lok\'tar Ogar!' ,0,1,0,5, '' ),
(0,-1999945, 'Finally, a fight worth watching.' ,0,1,0,5, '' ),
(0,-1999946, 'I did not come here to watch animals tear at each other senselessly, Tirion' ,0,1,0,5, '' ),
(0,-1999947, 'You will first be facing three of the Grand Champions of the Tournament! These fierce contenders have beaten out all others to reach the pinnacle of skill in the joust.' ,0,1,0,5, '' ),
(0,-1999948, 'Will tought! You next challenge comes from the Crusade\'s own ranks. You will be tested against their consederable prowess.' ,0,1,0,5, '' ),
(0,-1999949, 'You may begin!' ,0,0,0,5, '' ),
(0,-1999950, 'Well, then. Let us begin.' ,0,1,0,5, '' ),
(0,-1999951, 'Take this time to consider your past deeds.' ,16248,1,0,5, '' ),
(0,-1999952, 'What is the meaning of this?' ,0,1,0,5, '' ),
(0,-1999953, 'No...I\'m still too young' ,0,1,0,5, '' ),
(0,-1999954, 'Excellent work! You are win Argent champion!' ,0,3,0,0, '' );

-- Griphon of black Knight
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(35491, 0, 0, 0, 0, 0, 29842, 0, 0, 0, 'Black Knight\'s Skeletal Gryphon', '', '', 0, 80, 80, 2, 35, 35, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1048576, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 486, 0, 0, '', 0, 4, 15, 1, 0, 0, 0, 0, 0, 0, 0, 164, 1, 0, 0, 0, 'npc_black_knight_skeletal_gryphon');
DELETE FROM `script_waypoint` WHERE `entry`=35491;
INSERT INTO `script_waypoint` VALUES
(35491,1,781.513062, 657.989624, 466.821472,0,''),
(35491,2,759.004639, 665.142029, 462.540771,0,''),
(35491,3,732.936646, 657.163879, 452.678284,0,''),
(35491,4,717.490967, 646.008545, 440.136902,0,''),
(35491,5,707.570129, 628.978455, 431.128632,0,''),
(35491,6,705.164063, 603.628418, 422.956635,0,''),
(35491,7,716.350891, 588.489746, 420.801666,0,''),
(35491,8,741.702881, 580.167725, 420.523010,0,''),
(35491,9,761.634033, 586.382690, 422.206207,0,''),
(35491,10,775.982666, 601.991943, 423.606079,0,''),
(35491,11,769.051025, 624.686157, 420.035126,0,''),
(35491,12,756.582214, 631.692322, 412.529785,0,''),
(35491,13,744.841,634.505,411.575,0,'');
-- Griphon of black Knight before battle start
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(35492, 0, 0, 0, 0, 0, 29842, 0, 0, 0, 'Black Knight\'s Skeletal Gryphon', '', '', 0, 80, 80, 2, 35, 35, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1048576, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 486, 0, 0, '', 0, 3, 15, 1, 0, 0, 0, 0, 0, 0, 0, 164, 1, 0, 0, 0, 'npc_gr');
DELETE FROM `script_waypoint` WHERE `entry`=35492;
INSERT INTO `script_waypoint` VALUES
(35492,1,741.067078, 634.471558, 411.569366,0,''),
(35492,2,735.726196, 639.247498, 414.725555,0,''),
(35492,3,730.187256, 653.250977, 418.913269,0,''),
(35492,4,734.517700, 666.071350, 426.259247,0,''),
(35492,5,739.638489, 675.339417, 438.226776,0,''),
(35492,6,741.833740, 698.797302, 456.986328,0,''),
(35492,7,734.647339, 711.084778, 467.165314,0,''),
(35492,8,715.388489, 723.820862, 470.333588,0,''),
(35492,9,687.178711, 730.140503, 470.569336,0,'');
-- Announcer for start event
DELETE FROM `creature_template` WHERE `entry` in (35591,35592);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(35591, 0, 0, 0, 0, 0, 29894, 0, 0, 0, 'Jaeren Sunsworn', '', '', 0, 75, 75, 2, 14, 14, 0, 1, 1, 0, 0, 0, 0, 0, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_anstart'),
(35592, 0, 0, 0, 0, 0, 29893, 0, 0, 0, 'Arelas Brightstar', '', '', 0, 75, 75, 2, 14, 14, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 512, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_anstart');
-- Spawn Announcer in normal/heroic mode
DELETE FROM `creature` WHERE `id` in (35004, 35005);
DELETE FROM `creature` WHERE `guid` in (180100, 180101);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(180100, 35591, 650, 3, 64, 0, 0, 746.626, 618.54, 411.09, 4.63158, 86400, 0, 0, 10635, 0, 0),
(180101, 35592, 650, 3, 128, 0, 0, 746.626, 618.54, 411.09, 4.63158, 86400, 0, 0, 10635, 0, 0);
-- Addons
REPLACE INTO `creature_template_addon` VALUES
-- Argent
(35309, 0, 0, 0, 1, 0, '63501'),
(35310, 0, 0, 0, 1, 0, '63501'),
(35305, 0, 0, 0, 1, 0, '63501'),
(35306, 0, 0, 0, 1, 0, '63501'),
(35307, 0, 0, 0, 1, 0, '63501'),
(35308, 0, 0, 0, 1, 0, '63501'),
(35119, 0, 0, 0, 1, 0, '63501'),
(35518, 0, 0, 0, 1, 0, '63501'),
(34928, 0, 0, 0, 1, 0, '63501'),
(35517, 0, 0, 0, 1, 0, '63501'),
-- Faction_champ
(35323, 0, 0, 0, 1, 0, '63399 62852 64723'),
(35570, 0, 0, 0, 1, 0, '63399 62852 64723'),
(36091, 0, 0, 0, 1, 0, '63399 62852 64723'),
(35326, 0, 0, 0, 1, 0, '63403 62852 64723'),
(35569, 0, 0, 0, 1, 0, '63403 62852 64723'),
(36085, 0, 0, 0, 1, 0, '63403 62852 64723'),
(35314, 0, 0, 0, 1, 0, '63433 62852 64723'),
(35572, 0, 0, 0, 1, 0, '63433 62852 64723'),
(36089, 0, 0, 0, 1, 0, '63433 62852 64723'),
(35325, 0, 0, 0, 1, 0, '63436 62852 64723'),
(35571, 0, 0, 0, 1, 0, '63436 62852 64723'),
(36090, 0, 0, 0, 1, 0, '63436 62852 64723'),
(35329, 0, 0, 0, 1, 0, '63427 62852 64723'),
(34703, 0, 0, 0, 1, 0, '63427 62852 64723'),
(36087, 0, 0, 0, 1, 0, '63427 62852 64723'),
(35331, 0, 0, 0, 1, 0, '63396 62852 64723'),
(34702, 0, 0, 0, 1, 0, '63396 62852 64723'),
(36082, 0, 0, 0, 1, 0, '63396 62852 64723'),
(35327, 0, 0, 0, 1, 0, '63430 62852 64723'),
(35617, 0, 0, 0, 1, 0, '63430 62852 64723'),
(36084, 0, 0, 0, 1, 0, '63430 62852 64723'),
(35328, 0, 0, 0, 1, 0, '62594 62852 64723'),
(34705, 0, 0, 0, 1, 0, '62594 62852 64723'),
(36088, 0, 0, 0, 1, 0, '62594 62852 64723'),
(35330, 0, 0, 0, 1, 0, '63423 62852 64723'),
(34701, 0, 0, 0, 1, 0, '63423 62852 64723'),
(36083, 0, 0, 0, 1, 0, '63423 62852 64723'),
(35332, 0, 0, 0, 1, 0, '63406 62852 64723'),
(36086, 0, 0, 0, 1, 0, '63406 62852 64723'),
(34657, 0, 0, 0, 1, 0, '63406 62852 64723');
-- Immunes (crash fix xD )
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|1073741823 WHERE `entry` IN
(35309,35310, -- Argent Lightwielder
35305,35306, -- Argent Monk
35307,35308); -- Argent Priestess
