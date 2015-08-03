-- Add script to Fire Cyclone
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_fire_cyclone' WHERE `entry`=40164;
-- Add script to Twilight Flame Caller
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_twilight_flame_caller' WHERE `entry`=39708;
-- Add script to Twilight Torturer
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_twilight_torturer' WHERE `entry`=39978;
-- Add script to Twilight Sadist
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_twilight_sadist' WHERE `entry`=39980;
-- Add script to Mad Prisoner
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_mad_prisoner' WHERE `entry`=39985;
-- Add script to Crazed Mage
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_crazed_mage' WHERE `entry`=39982;
-- Add script to Raz The Crazed
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_raz_the_crazed' WHERE `entry`=39670;
-- Add script to Rom'ogg Bonecrusher
UPDATE `creature_template` SET `AIName`='',`ScriptName`='boss_romogg_bonecrusher' WHERE `entry`=39665;
-- Add script to Chains of Woe
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_chains_of_woe' WHERE `entry`=40447;

-- Add Teleport location for Blackrock Caverns
DELETE FROM `game_tele` WHERE `name`= 'BlackrockCaverns';
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(1523, -7570.9165, -1326.4373, 245.537216, 4.827146, 0, 'BlackrockCaverns');

-- Add Instance Template for Blackrock Caverns
DELETE FROM `instance_template` WHERE `map`=645;
INSERT INTO `instance_template` (`map`,`parent`,`script`,`allowMount`) VALUES
(645,0, 'instance_blackrock_caverns',0);

-- Spell Script Names
DELETE FROM `spell_script_names` WHERE `spell_id` IN (75437, 82189, 75649, 75650, 75653, 75654);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75437, 'spell_chains_of_woe_1'),
(82189, 'spell_chains_of_woe_4'),
(75649, 'spell_nether_dragon_essence_1'),
(75650, 'spell_nether_dragon_essence_2'),
(75653, 'spell_nether_dragon_essence_2'),
(75654, 'spell_nether_dragon_essence_2');

-- Add spell condition for Inflict Pain
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=75590;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 75590, 0, 0, 31, 3, 39982, 0, 0, '', 'Inflict Pain targets Crazed Mage'),
(13, 1, 75590, 0, 1, 31, 3, 39985, 0, 0, '', 'Inflict Pain targets Mad Prisoner');

-- Add spell condition for Chains of Woe
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (75437, 75464, 82189, 82192);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 75437, 0, 0, 31, 4, 0, 0, 0, '', 'Chains of Woe targets Player'),
(13, 1, 75464, 0, 0, 31, 4, 0, 0, 0, '', 'Chains of Woe targets Player'),
(13, 1, 82189, 0, 0, 31, 4, 0, 0, 0, '', 'Chains of Woe targets Player'),
(13, 1, 82192, 0, 0, 31, 4, 0, 0, 0, '', 'Chains of Woe targets Player');

-- Creature Template Updates
UPDATE `creature_template` SET `InhabitType`=4, flags_extra=128 WHERE `entry`=39842;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=40164;
UPDATE `creature_template` SET `InhabitType`=4, flags_extra=128 WHERE `entry`=40343;
UPDATE `creature_template` SET `difficulty_entry_1`=39706 WHERE `entry`=39705; -- Ascendant Lord Obsidius
UPDATE `creature_template` SET `difficulty_entry_1`=39701 WHERE `entry`=39700; -- Beauty
UPDATE `creature_template` SET `difficulty_entry_1`=39680 WHERE `entry`=39679; -- Corla, Herald of Twilight
UPDATE `creature_template` SET `difficulty_entry_1`=39699 WHERE `entry`=39698; -- Karsh Steelbender <Twilight Armorer>
UPDATE `creature_template` SET `difficulty_entry_1`=39666 WHERE `entry`=39665; -- Rom'ogg Bonecrusher
UPDATE `creature_template` SET `difficulty_entry_1`=40085 WHERE `entry`=40084; -- Bellows Slave
UPDATE `creature_template` SET `difficulty_entry_1`=40014 WHERE `entry`=40013; -- Buster
UPDATE `creature_template` SET `difficulty_entry_1`=50379 WHERE `entry`=40447; -- Chains of Woe (No spawn data) (Summoned by 39665 using spell 75539)
UPDATE `creature_template` SET `difficulty_entry_1`=39995 WHERE `entry`=39994; -- Conflagration (No spawn data)
UPDATE `creature_template` SET `difficulty_entry_1`=39983 WHERE `entry`=39982; -- Crazed Mage
UPDATE `creature_template` SET `difficulty_entry_1`=39988 WHERE `entry`=39987; -- Evolved Twilight Zealot
UPDATE `creature_template` SET `difficulty_entry_1`=40022 WHERE `entry`=40021; -- Incendiary Spark
UPDATE `creature_template` SET `difficulty_entry_1`=40009 WHERE `entry`=40008; -- Lucky
UPDATE `creature_template` SET `difficulty_entry_1`=39986 WHERE `entry`=39985; -- Mad Prisoner
UPDATE `creature_template` SET `difficulty_entry_1`=40016 WHERE `entry`=40015; -- Runty
UPDATE `creature_template` SET `difficulty_entry_1`=40818 WHERE `entry`=40817; -- Shadow of Obsidius
UPDATE `creature_template` SET `difficulty_entry_1`=40018 WHERE `entry`=40017; -- Twilight Element Warden
UPDATE `creature_template` SET `difficulty_entry_1`=39709 WHERE `entry`=39708; -- Twilight Flame Caller
UPDATE `creature_template` SET `difficulty_entry_1`=40020 WHERE `entry`=40019; -- Twilight Obsidian Borer
UPDATE `creature_template` SET `difficulty_entry_1`=39981 WHERE `entry`=39980; -- Twilight Sadist
UPDATE `creature_template` SET `difficulty_entry_1`=39979 WHERE `entry`=39978; -- Twilight Torturer
UPDATE `creature_template` SET `difficulty_entry_1`=39991 WHERE `entry`=39990; -- Twilight Zealot
UPDATE `creature_template` SET `difficulty_entry_1`=40005 WHERE `entry`=40004; -- Quicksilver
UPDATE `creature_template` SET `difficulty_entry_1`=50285 WHERE `entry`=50284; -- Twilight Zealot
-- Update stats for Blackrock Caverna
UPDATE `creature_template` SET `npcflag`=0, `maxlevel`=82, `flags_extra`=0 WHERE `entry`=39705;
UPDATE `creature_template` SET `npcflag`=0, `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=1.6, `speed_run`=1.71429, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=295744, `flags_extra`=1  WHERE `entry`=39706;
UPDATE `creature_template` SET `npcflag`=0, `maxlevel`=82, `flags_extra`=0 WHERE `entry`=39700;
UPDATE `creature_template` SET `npcflag`=0, `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=1.6, `speed_run`=1.71429, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832, `flags_extra`=1  WHERE `entry`=39701;
UPDATE `creature_template` SET `npcflag`=0, `maxlevel`=82, `flags_extra`=0 WHERE `entry`=39679;
UPDATE `creature_template` SET `npcflag`=0, `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=1.6, `unit_class`=2, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832, `flags_extra`=1  WHERE `entry`=39680;
UPDATE `creature_template` SET `npcflag`=0, `maxlevel`=82, `flags_extra`=0 WHERE `entry`=39698;
UPDATE `creature_template` SET `npcflag`=0, `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=1.6, `speed_run`=1.71429, `unit_class`=2, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832, `flags_extra`=1  WHERE `entry`=39699;
UPDATE `creature_template` SET `npcflag`=0, `maxlevel`=82, `flags_extra`=0 WHERE `entry`=39665;
UPDATE `creature_template` SET `npcflag`=0, `minlevel`=87, `maxlevel`=87,`faction`=16, `speed_walk`=1.6, `speed_run`=1.71429, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832  WHERE `entry`=39666;
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=40084;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832, `flags_extra`=1 WHERE `entry`=40085;
UPDATE `creature_template` SET `maxlevel`=81 WHERE `entry`=40013;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `speed_walk`=1.6, `speed_run`=1.28571, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832  WHERE `entry`=40014;
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=39982;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `unit_class`=2, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=39983;
UPDATE `creature_template` SET `maxlevel`=81 WHERE `entry`=39987;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `speed_walk`=1.6, `speed_run`=1.42857, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=39988;
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=40021;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=40022;
UPDATE `creature_template` SET `maxlevel`=81 WHERE `entry`=40008;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `speed_walk`=1.6, `speed_run`=1.28571, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=40009;
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=39985;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=294976 WHERE `entry`=39986;
UPDATE `creature_template` SET `maxlevel`=81 WHERE `entry`=40015;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `speed_walk`=1.6, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=40016;
UPDATE `creature_template` SET `maxlevel`=82 WHERE `entry`=40817;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `speed_walk`=2.4, `speed_run`=0.857143, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=295680 WHERE `entry`=40818;
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=40017;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32832 WHERE `entry`=40018;
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=39708;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=39709;
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=40019;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=40020;
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=39980;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=39980;
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=39978;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=39979;
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32832, `unit_flags2`=2048, `dynamicflags`=0 WHERE `entry`=39990;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2048, `dynamicflags`=0 WHERE `entry`=39991;
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=40004;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `speed_run`=1.14286, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=33587520, `unit_flags2`=0 WHERE `entry`=40005;
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=50284;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=294912 WHERE `entry`=50285;
UPDATE `creature_template` SET `minlevel`=81, `maxlevel`=81,`faction`=14, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=524288, flags_extra=0 WHERE `entry`=40447;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`faction`=14, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=524288, flags_extra=0 WHERE `entry`=50379;

DELETE FROM `creature_template_addon` WHERE `entry`=39705;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (39705,1, '75054');
DELETE FROM `creature_template_addon` WHERE `entry`=40817;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (40817,1, '76190 76164 76167 75054');
DELETE FROM `creature_template_addon` WHERE `entry`=51340;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (51340,1, '95014');
DELETE FROM `creature_template_addon` WHERE `entry`=40164;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (40164,1, '74851');
DELETE FROM `creature_template_addon` WHERE `entry`=46476;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (46476,1, '92292');
DELETE FROM `creature_template_addon` WHERE `entry`=53488;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (53488,1, '99201');
DELETE FROM `creature_template_addon` WHERE `entry`=39708;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (39708,1, '74911');
DELETE FROM `creature_template_addon` WHERE `entry`=49526;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES (49526,65536,1, '92282 92284');
DELETE FROM `creature_template_addon` WHERE `entry`=49476;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES (49476,65536,1, '92292');
DELETE FROM `creature_template_addon` WHERE `entry`=50284;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES (50284,8,1, '75608');
DELETE FROM `creature_template_addon` WHERE `entry`=39987;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (39987,1, '18950');

-- Equipment
DELETE FROM `creature_equip_template` WHERE `entry` IN (39665, 39666, 39698, 39699, 39708, 39709, 39679, 39680, 39705, 39980, 39985, 39986, 39978, 39979, 39987, 39988, 39990, 39991, 50284, 50285, 40084, 40085, 40017, 40018, 40019, 40020);
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(39665, 1, 54780, 54780, 0),
(39666, 1, 54780, 54780, 0),
(39698, 1, 58176, 0, 0),
(39699, 1, 58176, 0, 0),
(39708, 1, 49653, 0, 0),
(39709, 1, 49653, 0, 0),
(39679, 1, 52838, 0, 0),
(39680, 1, 52838, 0, 0),
(39705, 1, 60969, 0, 0),
(39980, 1, 52517, 52517, 6886),
(39985, 1, 54827, 0, 0),
(39986, 1, 54827, 0, 0),
(39978, 1, 52520, 0, 0),
(39979, 1, 52520, 0, 0),
(39987, 1, 58176, 0, 0),
(39988, 1, 58176, 0, 0),
(39990, 1, 52517, 0, 0),
(39990, 2, 57007, 58941, 0),
(39990, 3, 57036, 0, 0),
(39990, 4, 58803, 0, 0),
(39991, 1, 52517, 0, 0),
(39991, 2, 57007, 58941, 0),
(39991, 3, 57036, 0, 0),
(39991, 4, 58803, 0, 0),
(50284, 1, 41889, 0, 0),
(50285, 1, 41889, 0, 0),
(40084, 1, 1910, 0, 0),
(40085, 1, 1910, 0, 0),
(40017, 1, 49724, 0, 0),
(40018, 1, 54815, 0, 0),
(40019, 1, 49724, 0, 0),
(40020, 1, 54815, 0, 0);

-- Creature text
DELETE FROM `creature_text` WHERE `entry` IN (39665,39679,39698,39705,39670,39985,49476);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(39665, 0, 0, 'Boss Cho''gall not gonna be happy ''bout dis!', 14, 0, 100, 0, 0, 18925, 'Rom''ogg Bonecrusher - Aggro'),
(39665, 1, 0, 'Dat''s what you get! Noting!', 14, 0, 100, 0, 0, 18926, 'Rom''ogg Bonecrusher - Killing a player'),
(39665, 2, 0, 'Stand still! Rom''ogg crack your skulls!', 14, 0, 100, 0, 0, 18927, 'Rom''ogg Bonecrusher - Skullcracker'),
(39665, 3, 0, 'Rom''ogg sorry...', 14, 0, 100, 0, 0, 18928, 'Rom''ogg Bonecrusher - Death'),
(39665, 4, 0, '%s calls for help!', 16, 0, 100, 0, 0, 0, 'Rom''ogg Bonecrusher - Emote call for help'),
(39665, 5, 0, '%s prepares to unleash The Skullcracker on nearby enemies!', 41, 0, 100, 0, 0, 0, 'Rom''ogg Bonecrusher - Skullcracker emote'),
(39679, 0, 0, 'HERETICS! You will suffer for this interruption!', 14, 0, 100, 0, 0, 18589, 'Corla, Herald of Twilight - Aggro'),
(39679, 1, 0, 'There is only one true path of enlightenment! DEATH!', 14, 0, 100, 0, 0, 18590, 'Corla, Herald of Twilight -  - Killing a player'),
(39679, 2, 0, 'Bask in his power! Rise as an agent of the master''s rage!', 14, 0, 100, 0, 0, 18592, 'Corla, Herald of Twilight - Evolved Zealot'),
(39679, 3, 0, 'For the master I''d die a thousand times... A thousan...', 14, 0, 100, 0, 0, 18594, 'Corla, Herald of Twilight - Death'),
(39679, 4, 0, 'A Twilight Zealot has evolved!', 41, 0, 100, 0, 0, 0, 'Corla, Herald of Twilight - Evolved Zealot emote'),
(39698, 0, 0, 'Bodies to test my armaments upon!', 14, 0, 100, 0, 0, 18852, 'Karsh Steelbender - Aggro'),
(39698, 1, 0, 'Merely an impurity in the compound!', 14, 0, 100, 0, 0, 18853, 'Karsh Steelbender - Killing a player'),
(39698, 2, 0, 'Feel the burn!', 14, 0, 100, 0, 0, 18854, 'Karsh Steelbender to Karsh Steelbender - Superheated Quicksilver Armor'),
(39698, 3, 0, 'We number in the millions! Your efforts are wasted...', 14, 0, 100, 0, 0, 18855, 'Karsh Steelbender - Death'),
(39698, 4, 0, '%s''s armor shimmers with heat. Strike now!', 41, 0, 100, 0, 0, 0, 'Karsh Steelbender to Karsh Steelbender - Aura Emote'),
(39705, 0, 0, 'You come seeking answers? Then have them! Look upon your answer to living!', 14, 0, 100, 0, 0, 18899, 'Ascendant Lord Obsidius - Aggro'),
(39705, 1, 0, 'Your kind has no place in the master''s world!', 14, 0, 100, 0, 0, 18900, 'Ascendant Lord Obsidius - Killing a player'),
(39705, 2, 0, 'Earth can be shaped, molded... You cannot! You are useless!', 14, 0, 100, 0, 0, 18901, 'Ascendant Lord Obsidius - Switching shadows'),
(39705, 3, 0, 'I cannot be destroyed... Only... de... layed...', 14, 0, 100, 0, 0, 18902, 'Ascendant Lord Obsidius - Death'),
(39705, 4, 0, '%s prepares to trade places with one of his shadows!', 41, 0, 100, 0, 0, 0, 'Ascendant Lord Obsidius - Switching shadows emote'),
(39670, 0, 0, 'RAZ SMASH!', 14, 0, 100, 0, 0, 18919, 'Raz the Crazed'),
(39670, 1, 0, 'Raz... Tired...', 14, 0, 100, 0, 0, 18920, 'Raz the Crazed'),
(39985, 0, 0, '%s becomes enraged!', 16, 0, 100, 0, 0, 0, 'Mad Prisoner'),
(49476, 0, 0, 'RAZ, NOOOOOOOOOOO!!!!', 14, 0, 100, 0, 0, 0, 'Finkle Einhorn');
