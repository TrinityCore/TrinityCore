-- http://ru.wowhead.com/npc=10445 Селина Дорман теперь возвращает потерянный http://ru.wowhead.com/item=71634 Справочник ярмарки Новолуния
update creature_template set gossip_menu_id = 13075, AIName = 'SmartAI' where entry = 10445;

delete from smart_scripts where entryorguid = 10445;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(10445, 0, 0, 1, 62, 0, 100, 0, 13113, 0, 0, 0, 11, 103413, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gossip Select - Cast Replace Darkmoon Adventurer\'s Guide'),
(10445, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Close Gossip');

delete from conditions where SourceTypeOrReferenceId = 15 and SourceGroup = 13113;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 13113, 0, 0, 0, 8, 0, 7905, 0, 0, 0, 0, '', NULL),
(15, 13113, 0, 0, 1, 8, 0, 7926, 0, 0, 0, 0, '', NULL);

delete from gossip_menu_option where menu_id in (6579, 13075, 13076, 13113);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(6579, 0, 0, '<more>', 1, 1, 8848, 0, 0, 0, NULL),
(13075, 0, 0, 'Darkmoon Adventurer\'s Guide?', 1, 1, 13113, 0, 0, 0, ''),
(13075, 1, 0, 'What can I purchase?', 1, 1, 6577, 0, 0, 0, ''),
(13075, 2, 0, 'Darkmoon Faire Prize Tickets?', 1, 1, 6578, 0, 0, 0, ''),
(13075, 3, 0, 'Darkmoon Cards?', 1, 1, 6579, 0, 0, 0, ''),
(13075, 4, 0, 'Attractions?', 1, 1, 13076, 0, 0, 0, ''),
(13076, 0, 0, 'Tonks?', 1, 1, 13077, 0, 0, 0, ''),
(13076, 1, 0, 'Cannon?', 1, 1, 13078, 0, 0, 0, ''),
(13076, 2, 0, 'Whack-a-Gnoll?', 1, 1, 13079, 0, 0, 0, ''),
(13076, 3, 0, 'Ring Toss?', 1, 1, 13080, 0, 0, 0, ''),
(13076, 4, 0, 'Shooting Gallery?', 1, 1, 13081, 0, 0, 0, ''),
(13076, 5, 0, 'Fortune teller?', 1, 1, 13082, 0, 0, 0, ''),
(13113, 0, 0, 'May I have another Darkmoon Adventurer\'s Guide?', 1, 1, 0, 0, 0, 0, '');

-- Исправлены порталы в Элвиннский лес и Мулгор
update gameobject_template set faction = 1732 where entry = 210175;
update gameobject_template set faction = 1735 where entry = 210176;

delete from spell_target_position where id in (101260, 103582);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(101260, 0, -9516.52, 82.46, 59.571, 2.92068),
(103582, 1, -1444.41, 215.34, -7.75, 3.74306);

-- quest It's Hammer Time http://www.wowhead.com/quest=29463
delete from creature where id = 54547;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(54547, 974, 5861, 5870, 1, 1, 0, 0, -3986.13, 6292.59, 13.1169, 3.93807, 300, 0, 0, 84, 1000, 0, 0, 0, 0, 0, 0);

update creature_template set AIName = 'SmartAI' where entry = 54601;
update creature_template set faction_a = 190, faction_h = 190, ScriptName = 'npc_darkmoon_faire_gnoll_holder' where entry = 54547;
update creature_template set ScriptName = 'npc_darkmoon_faire_gnolls' where entry in (54444,54466,54549);

delete from areatrigger_scripts where entry = 7344;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(7344, 'SmartTrigger');

delete from smart_scripts where entryorguid in (54601, 7344);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(54601, 0, 0, 1, 62, 0, 100, 0, 13018, 1, 0, 0, 11, 102188, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gossip Select - Cast Mallet Gossip'),
(54601, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Close Gossip'),
--
(7344, 2, 0, 0, 46, 0, 100, 0, 7344, 0, 0, 0, 85, 109977, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Entry AT - Teleport');

delete from conditions where SourceTypeOrReferenceId = 15 and SourceGroup = 13018;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 13018, 1, 0, 0, 9, 0, 29463, 0, 0, 0, 0, '', NULL),
(15, 13018, 1, 0, 0, 1, 0, 101612, 0, 0, 1, 0, '', NULL);

delete from conditions where SourceTypeOrReferenceId = 22 and SourceEntry = 7344;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 7344, 2, 0, 1, 0, 101612, 0, 0, 1, 0, '', NULL);

delete from spell_linked_spell where spell_trigger in (101604, 101612, -101612);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES 
(101604, 102022, 'Whack!'),
(101612, 110230, 'Apply Whack-a-Gnoll - ENABLE_ALT_POWER'),
(-101612, -110230, 'Remove Whack-a-Gnoll - ENABLE_ALT_POWER'),
(-101612, 110966, 'Remove Whack-a-Gnoll - Apply Stay Out!');

delete from spell_target_position where id in (110966, 109977);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(110966, 974, -4008, 6268, 11.5, 0.8),
(109977, 974, -4008.5, 6270.1, 11.68, 0.746128);

delete from spell_radius where spell_id = 102022;
INSERT INTO `spell_radius` (`spell_id`, `effectradius0`, `effectradius1`, `effectradius2`, `effectradius3`, `effectradius4`, `comments`) VALUES 
(102022, 8, 0, 0, 0, 0, '5_YARDS');

delete from gossip_menu_option where menu_id in (13018, 13065);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(13018, 0, 0, 'How do I play Whack-a-Gnoll?', 1, 1, 13065, 0, 0, 0, ''),
(13018, 1, 0, 'Ready to whack! |cFF0008E8(Darkmoon Game Token)|r', 1, 1, 0, 0, 0, 0, ''),
(13065, 0, 0, 'I understand.', 1, 1, 13018, 0, 0, 0, '');

delete from gameobject where id = 301115;
INSERT INTO `gameobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES 
(301115, 974, 5861, 5870, 1, 1, -3996.67, 6278.71, 13.0871, 3.88232, 0, 0, 0.932195, -0.361957, -300, 0, 1, 0);

delete from gameobject_template where entry = 301115;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`) VALUES 
(301115, 8, 299, 'Standing in the Play Area', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 1731, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '');

-- The Humanoid Cannonball http://www.wowhead.com/quest=29436
update creature_template set inhabittype = 7 where entry = 33068;

update creature_template set AIName = 'SmartAI' where entry in (15303, 57850);
delete from smart_scripts where entryorguid in (15303, 57850);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15303, 0, 0, 1, 62, 0, 100, 0, 6575, 1, 0, 0, 85, 102113, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gossip Select - Cast Cannon Prep'),
(15303, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link Gossip - Gossip Close'),
--
(57850, 0, 0, 1, 62, 0, 100, 0, 13352, 0, 0, 0, 11, 109244, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gossip Select - Cast Back to the Cannon'),
(57850, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link Gossip - Gossip Close');

delete from spell_linked_spell where spell_trigger in (102113, 102112, 102120, 102116, -102116);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(102113, 102112, 0, 'Cannon Prep - Apply Stun'),
(102120, 62244, 0, 'Apply Core Check'),
(102112, 102121, 0, 'Apply Cannon Prep - Cast Cannon Blast'),
(102116, -62173, 0, 'Apply Magic Wings - Remove Bullseye'),
(102116, -62175, 0, 'Apply Magic Wings - Remove Great Shot'),
(102116, -62179, 0, 'Apply Magic Wings - Remove Poor Shot'),
(-102116, -102121, 0, 'Remove Cannon Blas Panel');

delete from spell_script_names where spell_id in (102112, 62244);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(102112, 'spell_darkmoon_cannon_prep'),
(62244, 'spell_darkmoon_cannonball');

delete from spell_target_position where id in (102113, 109244);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(102113, 974, -4021.6, 6299.7, 17.1062, 3.10545),
(109244, 974, -4017.5, 6288.9, 12.8, 1.07687);

delete from gossip_menu_option where menu_id in (6575, 13352);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(6575, 0, 0, 'Tell me how to use the Blastenheimer 5000 Ultra Cannon.', 1, 1, 6574, 0, 0, 0, NULL),
(6575, 1, 0, 'Launch me! |cFF0008E8(Darkmoon Game Token)|r', 1, 1, 0, 0, 0, 0, NULL),
(13352, 0, 0, 'Teleport me to the cannon.', 1, 1, 0, 0, 0, 500, 'Teleportation to the cannon will cost:'),
(13352, 1, 0, 'I don\'t need a teleport.', 1, 1, 0, 0, 0, 0, '');

-- quest He Shoots, He Scores http://www.wowhead.com/quest=29438
update creature_template set ScriptName = 'npc_darkmoon_faire_rinling' where entry = 14841;

update creature_template set InhabitType = 7, AIName = 'SmartAI' where entry = 24171;
delete from smart_scripts where entryorguid = 24171;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24171, 0, 0, 1, 8, 0, 100, 0, 101872, 0, 0, 0, 11, 43300, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Spellhit - Cast Hit Credit'),
(24171, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 101012, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link SpellHit - Cast Bonus Credit');

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry = 101872;
delete from conditions where SourceTypeOrReferenceId = 22 and SourceEntry = 24171;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 101872, 0, 0, 1, 0, 43313, 0, 0, 0, 0, '', NULL),
(22, 1, 24171, 0, 0, 1, 1, 43313, 0, 0, 0, 0, '', NULL);

delete from gossip_menu_option where menu_id in (6225, 13068);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(6225, 0, 0, 'How does the Shooting Gallery work?', 1, 1, 13068, 0, 0, 0, ''),
(6225, 1, 0, 'Let\'s shoot! |cFF0008E8(Darkmoon Game Token)|r', 1, 1, 0, 0, 0, 0, ''),
(13068, 1, 0, 'I understand.', 1, 1, 6225, 0, 0, 0, '');

delete from gameobject where id = 300129;
INSERT INTO `gameobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES 
(300129, 974, 5861, 5870, 1, 1, -4072, 6351, 13.1011, 0.845177, 0, 0, 0.410123, 0.91203, -300, 0, 1, 0);

-- Tonk Commander http://www.wowhead.com/quest=29434
delete from creature where id = 33081;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4129.63, 6301.34, 13.1165, 4.2443, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4127.1, 6305.12, 13.1165, 2.68371, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4131.91, 6309.42, 13.1165, 4.73518, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4136.54, 6314.94, 13.1165, 0.424126, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4130.39, 6289.23, 13.1165, 3.32617, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4125.34, 6293.7, 13.1165, 3.97412, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4143.62, 6310.58, 13.1165, 0.326737, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4123.56, 6298.37, 13.1165, 5.83552, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4137.9, 6304.97, 13.1165, 2.51486, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4142.6, 6290.64, 13.1165, 2.30358, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4137.3, 6289.17, 13.1165, 2.77718, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4146.4, 6305.54, 13.1165, 0.814469, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4146.49, 6294.74, 13.1165, 1.66191, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4143.63, 6299.04, 13.1165, 0.816822, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4143.43, 6316.43, 13.1165, 5.3792, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0),
(33081, 974, 5861, 5870, 1, 1, 0, 0, -4125.74, 6312.96, 13.1165, 3.75578, 1, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0);

update creature_template set spell1 = 102292, spell2 = 102297, VehicleId = 1734 where entry = 54588;
update creature_template set unit_flags = 33554432, AIName = 'SmartAI' where entry = 33081;
update creature_template set unit_flags = 33554432 where entry = 54642;
update creature_template set unit_flags = 33554432 where entry = 54643;

update gameobject_template set data1 = 3 where entry = 209342;

update creature_template set AIName = 'SmartAI' where entry = 54605;
delete from smart_scripts where entryorguid in (54605, 33081);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(54605, 0, 0, 1, 62, 0, 100, 0, 13019, 1, 0, 0, 11, 102191, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gossip Select - Cast Tonk'),
(54605, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Close Gossip'),
--
(33081, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - invincibility hp level 1'),
(33081, 0, 1, 0, 8, 0, 100, 0, 102292, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spellhit - Despawn');

delete from spell_linked_spell where spell_trigger in (-102178, -100752, 102190);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(-102178, -100752, 0, 'Remove Tonk Aura'),
(-100752, -102178, 0, 'Remove Tonk Alter bar'),
(102190, 100752, 0, 'Summon Tonk'),
(102190, 102178, 0, 'Apply Tonk Alter Bar');

delete from spell_script_names where spell_id = 102292;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(102292, 'spell_darkmoon_faire_cannon');

delete from spell_target_position where id in (100752, 109976);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(100752, 974, -4128, 6317, 13.1, 0),
(109976, 974, -4122.7, 6338.68, 10.64, 4.35512);

delete from areatrigger_scripts where entry = 7340;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(7340, 'SmartTrigger');

delete from smart_scripts where entryorguid = 7340;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(7340, 2, 0, 0, 46, 0, 100, 0, 7340, 0, 0, 0, 85, 109976, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Entry AT - Teleport');

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry = 102292;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 102292, 0, 0, 31, 0, 3, 33081, 0, 0, 0, '', NULL);

delete from gossip_menu_option where menu_id in (13019, 13066);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(13019, 0, 0, 'How do I play the Tonk Challenge?', 1, 1, 13066, 0, 0, 0, ''),
(13019, 1, 0, 'Ready to play! |cFF0008E8(Darkmoon Game Token)|r', 1, 1, 0, 0, 0, 0, ''),
(13066, 1, 0, 'I understand.', 1, 1, 13019, 0, 0, 0, '');

-- Target: Turtle http://www.wowhead.com/quest=29455
update creature set spawndist = 5, movementtype = 1 where id = 54490;

delete from gameobject_template where entry = 301114;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`) VALUES 
(301114, 8, 299, 'Standing at the Ring Toss Booth', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 1729, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '');

delete from gameobject where id = 301114;
INSERT INTO `gameobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES 
(301114, 974, 5861, 5870, 1, 1, -4288.58, 6309.45, 13.1171, 4.07936, 0, 0, 0.892073, -0.451892, -300, 0, 1, 0);

delete from areatrigger_scripts where entry = 7338;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(7338, 'SmartTrigger');

update creature_template set AIName = 'SmartAI' where entry in (54485, 54490);
delete from smart_scripts where entryorguid in (54485, 54490, 5449000, 5449001, 5449002, 7338);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(54485, 0, 0, 1, 62, 0, 100, 0, 13012, 1, 0, 0, 11, 101808, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gossip Select - Cast Ring Toss Gossip'),
(54485, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Close Gossip'),
--
(54490, 0, 0, 0, 8, 0, 100, 0, 101807, 0, 0, 0, 88, 5449000, 5449002, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SpellHit - Random Visual Cast'),
(5449000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 101734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast 1'),
(5449001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 101736, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast 2'),
(5449002, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 101738, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast 3'),
--
(7338, 2, 0, 0, 46, 0, 100, 0, 7338, 0, 0, 0, 85, 109972, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Entry AT - Teleport');

delete from spell_script_names where spell_id = 101695;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(101695, 'spell_darkmoon_ring_toss');

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (101695, 101807);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 101695, 0, 0, 31, 0, 3, 54490, 0, 0, 0, '', NULL),
(13, 2, 101807, 0, 0, 31, 0, 3, 54490, 0, 0, 0, '', NULL);

delete from spell_target_position where id = 109972;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(109972, 974, -4285.47, 6319, 12.95, 4.31184);

delete from gossip_menu_option where menu_id in (13012, 13013);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(13012, 0, 0, 'How do I play the Ring Toss?', 1, 1, 13013, 0, 0, 0, ''),
(13012, 1, 0, 'Ready to play! |cFF0008E8(Darkmoon Game Token)|r', 1, 1, 0, 0, 0, 0, ''),
(13013, 1, 0, 'I understand.', 1, 1, 13012, 0, 0, 0, '');

-- Quest Talkin Tonks http://www.wowhead.com/quest=29511
delete from creature where id = 54504;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(54504, 974, 0, 0, 1, 1, 15381, 0, -4133.97, 6326.1, 13.2084, 1.69297, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4165.78, 6329.17, 13.2001, 1.78024, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4226.92, 6232, 13.2467, 1.76278, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4099.02, 6372.39, 13.2001, 1.85005, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4082.47, 6392.81, 13.2346, 3.52556, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4268.2, 6371.27, 13.2001, 3.66519, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4145.65, 6324.41, 13.2001, 1.09956, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4112.22, 6386.49, 13.2001, 0.0523599, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4117.59, 6311.72, 13.2024, 0.191986, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4096.26, 6404.28, 13.2001, 4.99164, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4106.99, 6396.72, 13.2001, 5.58505, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4086.44, 6375.21, 13.2273, 2.25148, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4138.57, 6387.13, 13.2001, 5.48033, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4121.74, 6381.7, 13.1607, 4.55531, 120, 0, 0, 100, 100, 0, 0, 0, 0),
(54504, 974, 0, 0, 1, 1, 15381, 0, -4316.97, 6317.85, 13.1495, 0.802851, 120, 0, 0, 100, 100, 0, 0, 0, 0);

update creature_template set AIName = 'SmartAI' where entry = 54504;
delete from smart_scripts where entryorguid = 54504;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(54504, 0, 0, 1, 8, 0, 100, 1, 101838, 0, 0, 0, 28, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SpellHit - Remove Aura'),
(54504, 0, 1, 2, 61, 0, 100, 1, 0, 0, 0, 0, 33, 54504, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - KillCredit'),
(54504, 0, 2, 3, 61, 0, 100, 1, 0, 0, 0, 0, 89, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Random Move'),
(54504, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 9000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Despawn 3s');

delete from creature_template_addon where entry = 54504;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(54504, 0, 0, 0, 1, 0, '29266');

delete from conditions where SourceTypeOrReferenceId = 17 and SourceEntry = 101838;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 101838, 0, 0, 31, 1, 3, 54504, 0, 0, 0, '', NULL);

-- Writing the Future http://www.wowhead.com/quest=29515
update quest_template set RequiredSkillId = 773 where id = 29515;

-- Darkmoon Arena event
delete from game_event where eventEntry = 101;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`) VALUES 
(101, '2015-1-1 00:00:00', '2020-1-1 00:00:00', 180, 120, 0, 'Darkmoon Arena', 0);

delete from gameobject where id = 209620;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES 
(72395, 209620, 974, 5861, 5877, 1, 1, -4299.35, 6438.88, 15.3994, 4.69494, 0, 0, 0, 1, 7200, 255, 1, 0);

delete from game_event_gameobject where guid = 72395;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES 
(101, 72395);

update gameobject_template set AIName = 'SmartGameObjectAI' where entry = 209620;
delete from smart_scripts where entryorguid = 209620;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(209620, 1, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 84, 0, 0, 0, 0, 0, 0, 10, 8973, 55402, 0, 0, 0, 0, 0, 'Spawn - Target-Talk - Text 0'),
(209620, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 44, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link Spawn- Visible Off'),
(209620, 1, 2, 3, 60, 0, 100, 1, 15000, 15000, 0, 0, 84, 1, 0, 0, 0, 0, 0, 10, 8973, 55402, 0, 0, 0, 0, 0, 'Time - Target-Talk - Text 1'),
(209620, 1, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 44, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link Time - Visible On');

delete from spell_target_position where id in (108919, 113212, 113213, 113216, 113219, 113224, 113227, 113228, 113246);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(108919, 974, -4300.6, 6406.6, 16, 1.53589),
(113212, 974, -4320.9, 6416.3, 16, 0.844739),
(113213, 974, -4328.6, 6437, 16, 0.0785398),
(113216, 974, -4320.3, 6457.6, 16, 5.64963),
(113219, 974, -4299.2, 6466.2, 16, 4.71588),
(113224, 974, -4278.2, 6457, 16.1, 3.85718),
(113227, 974, -4270.2, 6435.6, 16.1, 3.03687),
(113228, 974, -4278.9, 6414.2, 16, 2.26893),
(113246, 974, -4300.9, 6397.3, 17, 4.71763);

delete from spell_script_names where spell_id = 108941;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(108941, 'spell_darkmoon_deathmatch_teleport');

delete from creature_text where entry = 55402;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(55402, 0, 0, 'Attention, fairegoers! The Darkmoon Deathmatch is about to begin! In mere moments the prize chest will appear at the center of the arena.', 14, 0, 0, 0, 0, 0, ''),
(55402, 1, 0, 'Let the Darkmoon Deathmatch BEGIN!', 14, 0, 0, 0, 0, 0, ''),
(55402, 2, 0, 'The Darkmoon Deathmatch is over! $n is the victor!', 14, 0, 0, 0, 0, 0, '');

delete from locales_creature_text where entry = 55402;
INSERT INTO `locales_creature_text` (`entry`, `textGroup`, `id`, `text_loc8`) VALUES 
(55402, 0, 0, 'Внимание! Дорогие гости! До начала поединка Новолуния остались считанные секунды! Сундук с призом вот-вот появится в центре арены!'),
(55402, 1, 0, 'Начать поединок Новолуния!'),
(55402, 2, 0, 'Итак, поединок Новолуния закончился! Победитель $n!');

-- Кладбище
delete from game_graveyard_zone where id = 3212;
INSERT INTO `game_graveyard_zone` (`id`, `ghost_zone`, `faction`) VALUES 
(3212, 5861, 0);

delete from creature where id = 6491 and map = 974;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(6491, 974, 0, 0, 1, 1, 0, 0, -4246.83, 6387.35, 13.2001, 4.67748, 7200, 0, 0, 1, 0, 0, 0, 0, 0);

-- I Was Promised a Pony http://www.wowhead.com/achievement=6025
update creature_template set npcflag = 16777216 where entry = 55715;

delete from npc_spellclick_spells where npc_entry = 55715;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(55715, 104515, 1, 0);