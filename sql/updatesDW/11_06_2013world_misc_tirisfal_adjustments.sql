  

    -- fix quest for 28608 where the Darnell was not appear to asist you doing that  quest
    DELETE FROM `creature_template` WHERE (`entry`=49141);
    INSERT INTO `creature_template` VALUES ('49141', '0', '0', '0', '0', '0', '36383', '0', '0', '0', 'Darnell', '', '', '0', '2', '2', '0', '0', '5', '5', '0', '1', '1.14286', '1', '0', '2', '2', '0', '24', '1', '2000', '2000', '1', '32776', '2048', '0', '0', '0', '0', '0', '0', '1', '1', '0', '7', '4096', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1392', '0', '0', 'SmartAI', '0', '3', '1', '1', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '49141', '0', '0', '', '13623');
    DELETE FROM `creature_equip_template` WHERE (`entry`=49141);
    INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES (49141, 1895, 1957, 0);
    UPDATE `creature_template` SET `unit_flags` = 32776 WHERE `entry` = 49141;
    DELETE FROM `creature_text` WHERE (`entry`=49141);
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (49141, 0, 0, 'Greetings, $N.', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 1, 0, 'The shadow grave is in this direction. Follow me, $N.', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 2, 0, 'This way!', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 3, 0, 'Let''s see now... WHERE could they be...', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 4, 0, 'Maybe they''re over here?', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 5, 0, 'Nice work! You''ve found them. Let''s bring these back to Mordo.', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 6, 0, 'I saw someone up there whose jaw fell off. I wonder if Mordo can fix him up?', 12, 0, 100, 1, 0, 0, 'Darnell');
    UPDATE `creature_template` SET `faction_A` = 5, `faction_H` = 5 WHERE `entry` = 49141;
    -- Darnell
    DELETE FROM `smart_scripts` WHERE `entryorguid`=49141 AND `source_type`=0;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=49141 LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (49141,0,0,0,54,0,100,0,0,0,0,0,80,4914100,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On summoned call time action 4914100"),
    (49141,0,1,0,38,0,100,1,0,1,0,0,80,4914101,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On data set do event 4914101"),
    (49141,0,3,0,38,0,100,0,0,2,0,0,41,1000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On data set 2 despawn self");
    -- Darnell
    DELETE FROM `smart_scripts` WHERE `entryorguid`=4914100 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (4914100,9,0,0,0,0,100,0,1500,1500,1500,1500,1,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Talk to owner"),
    (4914100,9,1,0,0,0,100,0,2000,2000,2000,2000,1,1,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Talk to player");
    -- Darnell
    DELETE FROM `smart_scripts` WHERE `entryorguid`=4914101 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (4914101,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"Talk to owner"),
    (4914101,9,1,0,0,0,100,0,0,0,0,0,53,1,4914100,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Do WP 4914100"),
    (4914101,9,2,0,0,0,100,0,8000,8000,8000,8000,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Talk text 3"),
    (4914101,9,3,0,0,0,100,0,3000,3000,3000,3000,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Say text 4"),
    (4914101,9,4,0,0,0,100,0,4000,4000,4000,4000,29,0,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"And follow Player");
    DELETE FROM waypoints WHERE entry=4914100;
    INSERT INTO waypoints(entry, pointid, position_x, position_y, position_z) VALUES
    (4914100, 1, 1659.16, 1662.94, 141.817),
    (4914100, 2, 1643.49, 1663.24, 132.478),
    (4914100, 3, 1642.96, 1677.41, 126.932),
    (4914100, 4, 1658.07, 1677.88, 120.719),
    (4914100, 5, 1664.8, 1661.36, 120.939);
            DELETE FROM waypoint_data WHERE id=63965;
        INSERT INTO `waypoint_data` VALUES ('63965', '8', '1843.12', '1609.91', '96.2524', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '7', '1843.17', '1612', '96.9644', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '6', '1843.25', '1615.37', '96.9335', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '5', '1843.34', '1619.57', '96.9335', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '4', '1843.35', '1623.42', '96.9335', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '3', '1843.2', '1626.81', '96.9335', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '2', '1842.99', '1631.23', '96.9335', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '1', '1843.14', '1634.15', '96.9335', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '9', '1843.06', '1607.69', '95.173', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '10', '1842.96', '1603.73', '94.5533', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '11', '1842.86', '1599.64', '94.4846', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '12', '1842.71', '1593.69', '93.5986', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '13', '1842.65', '1591.25', '93.3628', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '14', '1842.86', '1589.51', '93.3425', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '15', '1843.82', '1586.74', '93.4051', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '16', '1845.98', '1585.57', '93.4809', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '17', '1848.41', '1585.59', '93.4063', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '18', '1849.12', '1585.68', '93.3693', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '19', '1855.42', '1588.08', '92.8019', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '20', '1855.76', '1588.14', '92.7799', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '21', '1860.88', '1588.16', '92.3715', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '22', '1861.01', '1585.59', '92.4803', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '23', '1861.01', '1583.84', '92.5922', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '24', '1860.93', '1580.81', '93.1207', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '25', '1860.86', '1578.61', '94.1555', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '26', '1860.77', '1576.18', '94.3136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '27', '1860.73', '1572.66', '94.3136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '28', '1860.94', '1569.99', '94.3136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '29', '1860.97', '1566.95', '94.3136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '30', '1861.52', '1564.83', '94.3136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '31', '1862.92', '1565.4', '94.3136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '32', '1863.31', '1567.11', '94.3136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '33', '1863.34', '1570.26', '94.3136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '34', '1862.69', '1572.01', '94.3136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '35', '1861.72', '1574.52', '94.3136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '36', '1861.16', '1577.1', '94.3136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '37', '1860.82', '1579.76', '93.63', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '38', '1860.42', '1582.9', '92.7635', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '39', '1860.15', '1586.39', '92.4982', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '40', '1858.27', '1588.2', '92.5997', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '41', '1856', '1588.43', '92.7729', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '42', '1852.51', '1588.63', '92.9217', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '43', '1849.01', '1588.79', '93.136', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '44', '1843.31', '1588.98', '93.3144', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '45', '1843.36', '1594.7', '93.6993', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '46', '1843.33', '1600.52', '94.5431', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '47', '1843.3', '1604.01', '94.5566', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '48', '1843.25', '1609.37', '96.0199', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '49', '1843.23', '1612.87', '96.9543', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '50', '1843.21', '1616.37', '96.9337', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '51', '1843.18', '1623.37', '96.9337', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '52', '1843.16', '1626.87', '96.9337', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '53', '1843.13', '1633.27', '96.9337', '0', '0', '0', '0', '100', '0');
        INSERT INTO `waypoint_data` VALUES ('63965', '54', '1843.05', '1633.96', '96.9337', '0', '0', '0', '0', '100', '0');
    -- http://old.wowhead.com/npc=1741
    -- http://wow.magelo.com/en/npc/1741
    DELETE FROM `creature_template` WHERE `entry`=1741 LIMIT 1;
    INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 1741, 0, 0, 0, 0, 0, 1587, 0, 0, 0, "Deathguard Bartrand", "", "", 0, 65, 65, 0, 71, 71, 0, 1.0, 1.42857, 1.0, 0, 200, 281, 0, 278, 1.0, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 0, 0, 200, 281, 278, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 33, "SmartAI", 0, 3, 3.3564, 0.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, "", "12340");
    -- http://old.wowhead.com/npc=1739
    -- http://wow.magelo.com/en/npc/1739
    DELETE FROM `creature_template` WHERE `entry`=1739 LIMIT 1;
    INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 1739, 0, 0, 0, 0, 0, 1589, 0, 0, 0, "Deathguard Phillip", "", "", 0, 65, 65, 0, 71, 71, 0, 1.0, 1.42857, 1.0, 0, 200, 281, 0, 278, 1.0, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 0, 0, 200, 281, 278, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 33, "SmartAI", 0, 3, 3.3564, 0.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, "", "12340");
    -- http://old.wowhead.com/npc=1736
    -- http://wow.magelo.com/en/npc/1736
    DELETE FROM `creature_template` WHERE `entry`=1736 LIMIT 1;
    INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 1736, 0, 0, 0, 0, 0, 1590, 0, 0, 0, "Deathguard Randolph", "", "", 0, 65, 65, 0, 71, 71, 0, 1.0, 1.42857, 1.0, 0, 200, 281, 0, 278, 1.0, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 0, 0, 200, 281, 278, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 33, "SmartAI", 0, 3, 3.3564, 0.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, "", "12340");
    -- http://old.wowhead.com/npc=1737
    -- http://wow.magelo.com/en/npc/1737
    DELETE FROM `creature_template` WHERE `entry`=1737 LIMIT 1;
    INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 1737, 0, 0, 0, 0, 0, 1588, 0, 0, 0, "Deathguard Oliver", "", "", 0, 65, 65, 0, 71, 71, 0, 1.0, 1.42857, 1.0, 0, 200, 281, 0, 278, 1.0, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 0, 0, 200, 281, 278, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 33, "SmartAI", 0, 3, 3.3564, 0.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, "", "12340");
    -- http://old.wowhead.com/npc=1740
    -- http://wow.magelo.com/en/npc/1740
    DELETE FROM `creature_template` WHERE `entry`=1740 LIMIT 1;
    INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 1740, 0, 0, 0, 0, 0, 3523, 0, 0, 0, "Deathguard Saltain", "", "", 0, 7, 7, 0, 68, 68, 3, 1.0, 1.42857, 1.0, 0, 9, 12, 0, 36, 1.0, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 0, 0, 9, 12, 36, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 33, "SmartAI", 0, 3, 2.0, 0.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 2, "", "12340");
    -- http://old.wowhead.com/npc=7980
    -- http://wow.magelo.com/en/npc/7980
    DELETE FROM `creature_template` WHERE `entry`=7980 LIMIT 1;
    INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 7980, 0, 0, 0, 0, 0, 7117, 7118, 14369, 14370, "Deathguard Elite", "", "", 0, 85, 85, 3, 71, 71, 0, 1.0, 1.14286, 1.0, 0, 530, 713, 0, 827, 1.0, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 0, 0, 530, 713, 827, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "SmartAI", 0, 3, 1.6915, 0.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "", "12340");
    -- http://wow.magelo.com/en/npc/51850
    DELETE FROM `creature_template` WHERE `entry`=51850 LIMIT 1;
    INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 51850, 0, 0, 0, 0, 0, 14369, 7117, 7118, 0, "Deathguard Elite", "", "", 0, 65, 65, 1, 71, 71, 0, 1.0, 1.14286, 1.0, 0, 0, 0, 0, 0, 1.0, 2000, 2000, 1, 32768, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95826, 95826, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "SmartAI", 0, 1, 3.5966, 0.0, 1.0, 0, 4161536, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "", "13623");
    -- duplicate creature must be delete
    DELETE FROM creature WHERE guid IN (31627,32241,64215,64213,31001,30872,64120,63995,63474,63997,30787,31732,63472);
    -- missing total number of object
    -- http://www.wowhead.com/object=375/tirisfal-pumpkin
    DELETE FROM gameobject WHERE guid IN (601059,601060,601061,601062,601063,601064,601065,601066,601067);
    INSERT INTO `gameobject` VALUES ('601059', '375', '0', '1', '1', '2277.13', '1206.02', '31.4428', '2.22806', '0', '0', '0.897484', '0.441046', '1', '0', '1');
    INSERT INTO `gameobject` VALUES ('601060', '375', '0', '1', '1', '2280.24', '1269.11', '31.4431', '5.45989', '0', '0', '0.40012', '-0.916463', '1', '0', '1');
    INSERT INTO `gameobject` VALUES ('601061', '375', '0', '1', '1', '2288.49', '1348.15', '33.3337', '0.963048', '0', '0', '0.46313', '0.88629', '1', '0', '1');
    INSERT INTO `gameobject` VALUES ('601062', '375', '0', '1', '1', '2265.32', '1371.2', '33.3346', '5.55523', '0', '0', '0.355996', '-0.934488', '1', '0', '1');
    INSERT INTO `gameobject` VALUES ('601063', '375', '0', '1', '1', '2283.04', '1390.81', '33.3338', '2.11213', '0', '0', '0.870425', '0.492301', '1', '0', '1');
    INSERT INTO `gameobject` VALUES ('601064', '375', '0', '1', '1', '2300.83', '1373.21', '33.3335', '5.53428', '0', '0', '0.365763', '-0.930708', '1', '0', '1');
    INSERT INTO `gameobject` VALUES ('601065', '375', '0', '1', '1', '2307.52', '1404.04', '33.3343', '2.32696', '0', '0', '0.918187', '0.396146', '1', '0', '1');
    INSERT INTO `gameobject` VALUES ('601066', '375', '0', '1', '1', '2318.66', '1425.87', '33.3334', '2.35707', '0', '0', '0.924047', '0.38228', '1', '0', '1');
    INSERT INTO `gameobject` VALUES ('601067', '375', '0', '1', '1', '2343.38', '1389.44', '33.3334', '5.52419', '0', '0', '0.370455', '-0.92885', '1', '0', '1');
-- console error fix
DELETE FROM `creature_addon` WHERE (`guid`=45928);
-- rong  place or position
DELETE FROM creature WHERE guid IN (64044,64046,12633);
-- i use the same guid to insert becose its free
INSERT INTO `creature` VALUES ('12633', '38895', '0', '0', '0', '1', '1', '0', '0', '1757.99', '1667.15', '121.251', '3.528', '300', '0', '0', '42', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('64046', '1741', '0', '0', '0', '1', '1', '0', '1', '1877.51', '1582.92', '90.9247', '1.70151', '300', '0', '0', '11828', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('64044', '1739', '0', '0', '0', '1', '1', '0', '1', '1845.49', '1579.17', '95.1793', '1.40975', '300', '0', '0', '11828', '0', '0', '0', '0', '0');
-- missing hes wp 
DELETE FROM  waypoint_data WHERE  id=31534;
INSERT INTO `waypoint_data` VALUES ('31534', '1', '1882.75', '1588.64', '89.7941', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '2', '1880.32', '1587.57', '90.1115', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '3', '1876.23', '1586.65', '90.6133', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '4', '1871.34', '1586.52', '91.2207', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '5', '1865.75', '1586.56', '91.808', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '6', '1861.67', '1586.6', '92.3397', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '7', '1854.67', '1586.71', '92.9106', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '8', '1851.17', '1586.77', '93.1101', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '9', '1844.17', '1586.88', '93.3662', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '10', '1838.11', '1587.03', '93.8047', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '11', '1834.62', '1587.18', '93.9724', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '12', '1827.62', '1587.46', '94.6624', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '13', '1824.37', '1587.68', '95.1438', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '14', '1817.41', '1588.42', '96.2578', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '15', '1815.66', '1589.16', '96.672', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '16', '1815.53', '1589.85', '96.7335', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '17', '1819.08', '1591.42', '96.0157', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '18', '1824.2', '1591.49', '95.0124', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '19', '1829.43', '1591.31', '94.2628', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '20', '1834.88', '1590.71', '93.9034', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '21', '1841.17', '1590.59', '93.4499', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '22', '1844.67', '1590.66', '93.2749', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '23', '1850.96', '1590.83', '93.0367', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '24', '1856.56', '1591.02', '92.8367', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '25', '1861.92', '1591.13', '92.4009', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '26', '1867.17', '1591.1', '91.7429', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '27', '1870.67', '1591.08', '91.2765', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '28', '1877.67', '1590.91', '90.3695', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '29', '1880.35', '1590.8', '90.0482', '0', '0', '0', '0', '100', '0');
INSERT INTO `waypoint_data` VALUES ('31534', '30', '1882.8', '1590.7', '89.8221', '0', '0', '0', '0', '100', '0');


