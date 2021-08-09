delete from conditions where SourceTypeOrReferenceId = 15 and SourceGroup = 15257;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 15257, 0, 0, 0, 9, 0, 32325, 0, 0, 0, 0, '', NULL);

delete from gossip_menu_option where menu_id = 15257;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(15257, 0, 0, 'Войти в храм.', 21, 1, 0, 0, 0, 594, NULL);


update creature_template set scriptName = 'npc_asthongue_primalist' where entry = 68129;

delete from creature_addon where guid in (1150301,1150302,1150304,1150305,1150306,1150307,1150308,1150309,1150310,1150311);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(1150301, 1150301, 0, 0, 1, 0, ''),
(1150302, 1150302, 0, 0, 1, 0, '');

update creature set movementType = 2 where guid in (1150301,1150302);
delete from creature where id = 68096;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 867.014, 51.5417, 112.823, 4.55281, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 884.347, 77.5017, 112.825, 4.55281, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 867.014, 51.5417, 112.823, 4.55281, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 884.347, 77.5017, 112.825, 4.55281, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6614, 4096, 1, 0, 0, 652.108, 834.856, 61.2042, 3.56323, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6614, 4096, 1, 0, 0, 721.453, 791.826, 62.9234, 1.56443, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 656.995, 618.498, 93.379, 1.36167, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 703.281, 609.365, 100.291, 1.56443, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6614, 4096, 1, 0, 0, 674.885, 792.378, 64.1097, 1.36167, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 749.524, 618.741, 92.8543, 1.56443, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6614, 4096, 1, 0, 0, 708.394, 935.571, 53.1428, 6.11146, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 688.823, 77.0087, 112.831, 1.35385, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 820.668, 48.8316, 112.821, 5.64324, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 833.984, 51.6007, 112.821, 4.55281, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6614, 4096, 1, 0, 0, 802.715, 849.005, 60.8101, 2.76671, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6614, 4096, 1, 0, 0, 604.694, 832.733, 66.3112, 5.20224, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 820.668, 48.8316, 112.821, 5.64324, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68096, 1112, 6613, 6613, 4096, 1, 0, 0, 833.984, 51.6007, 112.821, 4.55281, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

delete from waypoint_data where id in (1150301,1150302);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `entry`, `wpguid`) VALUES 
(1150301, 1, 785.385, 425.05, 112.737, 0, 0, 0, 0, 100, 0, 0),
(1150301, 2, 626.555, 420.94, 112.715, 0, 0, 0, 0, 100, 0, 0),
(1150302, 1, 626.47, 425.055, 112.718, 0, 0, 0, 0, 100, 0, 0),
(1150302, 2, 785.943, 425.257, 112.736, 0, 0, 0, 0, 100, 0, 0);

delete from areatrigger_data where entry = 581;
INSERT INTO `areatrigger_data` (`entry`, `spellId`, `customEntry`, `customVisualId`, `Radius`, `RadiusTarget`, `Height`, `HeightTarget`, `Float4`, `Float5`, `isMoving`, `moveType`, `waitTime`, `speed`, `activationDelay`, `updateDelay`, `maxCount`, `hitType`, `MoveCurveID`, `ElapsedTime`, `MorphCurveID`, `FacingCurveID`, `ScaleCurveID`, `HasFollowsTerrain`, `HasAttached`, `HasAbsoluteOrientation`, `HasDynamicShape`, `HasFaceMovementDir`, `windX`, `windY`, `windZ`, `windSpeed`, `windType`, `polygon`, `comment`) VALUES 
(581, 134110, 3764, 29310, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Searching for Intruders');

delete from areatrigger_actions where entry = 581;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) VALUES 
(581, 0, 1, 0, 4104, 134109, 0, 0, 0, 0, 0, 0, 0, 'Detected Pulse');

update creature_template set gossip_menu_id = 15252 where entry = 68137;
update creature_template set dynamicflags = 0 where entry in (select id from creature where map = 1112);

delete from conditions where SourceTypeOrReferenceId = 15 and SourceGroup = 15252;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 15252, 0, 0, 0, 6, 0, 469, 0, 0, 0, 0, '', NULL),
(15, 15252, 1, 0, 0, 6, 0, 67, 0, 0, 0, 0, '', NULL);

DELETE FROM `gossip_menu` WHERE entry in (15250, 15252);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(15250, 21861),
(15252, 21859);

DELETE FROM `gossip_menu_option` WHERE menu_id in (15250, 15252);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(15250, 0, 0, 'Акама, покажи дорогу!', 1, 1, 0, 0, 0, 0, NULL),
(15252, 0, 0, 'Король Ринн разыскивает членов совета Мрачной Жатвы, которые недавно были здесь.', 1, 1, 15250, 0, 0, 0, NULL),
(15252, 1, 0, 'Вождь Гаррош разыскивает членов Мрачной Жатвы, которые недавно были здесь.', 1, 1, 15250, 0, 0, 0, NULL);

update creature_template set minlevel = 90, maxlevel = 90, faction = 16, mindmg = 700, maxdmg = 1200, dmg_multiplier = 2 where entry = 68140;
update creature set spawndist = 10, movementType = 1 where id = 68139;
update gameobject_template set data2 = 1 where entry = 216366;
update creature_template set rank = 3, mindmg = 700, maxdmg = 1200, unit_flags = 0 where entry = 68151;
update creature_template set faction = 14, mindmg = 700, maxdmg = 1200 where entry = 68173;
delete from creature where id = 68156;
update creature set spawntimesecs = 86400 where id = 68151;
update gameobject_template set flags = 0 where entry = 216452;
update creature_template set npcflag = 16777216, unit_flags = 768 where entry = 70052;
update creature_template set speed_fly = 0.1, npcflag = 16777216, inhabitType = 7, vehicleId = 2775, flags_extra = 128 where entry = 70504;
update creature_template set unit_flags = 0 where entry = 69964;

delete from creature_text where entry = 68151;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(68151, 0, 0, 'Узри же души, которые погубили твои собратья, чернокнижники!', 14, 0, 100, 0, 0, 0, 'Пеплоуст-рабочий to Player'),
(68151, 1, 0, 'УМРИ!', 14, 0, 100, 0, 0, 0, 'Пеплоуст-рабочий to Player'),
(68151, 2, 0, 'Ты так любишь демонов?.. Теперь у тебя будет возможность встретиться с ними!', 14, 0, 100, 0, 0, 0, 'Пеплоуст-рабочий to Player');

delete from gameobject_involvedrelation where id = 216452;
INSERT INTO `gameobject_involvedrelation` (`id`, `quest`) VALUES 
(216452, 32340);

update spell_script_names set spell_id = 140116 where spell_id = 140164;

delete from creature where id = 70052;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(70052, 1112, 6613, 6613, 4096, 1, 0, 0, 659.852, 304.638, 354.112, 0.154723, 86400, 0, 0, 84, 1000, 0, 0, 0, 0, 0, 0);

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry = 140116;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 140116, 0, 0, 31, 0, 3, 70504, 0, 0, 0, '', NULL);

delete from gameobject_loot_template where entry in (216428, 216430, 216431, 216432, 216433, 216434, 216435, 216436, 216437, 216438, 216439, 216440, 216441, 216442, 216444, 216445, 216446, 216447, 216448, 216449, 216450, 216451);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES 
(216428, 92580, 100, 0, 0, 1, 1, 0),
(216430, 92582, 100, 0, 0, 1, 1, 0),
(216431, 92584, 100, 0, 0, 1, 1, 0),
(216432, 92586, 100, 0, 0, 1, 1, 0),
(216433, 92588, 100, 0, 0, 1, 1, 0),
(216434, 92590, 100, 0, 0, 1, 1, 0),
(216435, 92592, 100, 0, 0, 1, 1, 0),
(216436, 92594, 100, 0, 0, 1, 1, 0),
(216437, 92596, 100, 0, 0, 1, 1, 0),
(216438, 92598, 100, 0, 0, 1, 1, 0),
(216439, 92600, 100, 0, 0, 1, 1, 0),
(216440, 92602, 100, 0, 0, 1, 1, 0),
(216441, 92604, 100, 0, 0, 1, 1, 0),
(216442, 92606, 100, 0, 0, 1, 1, 0),
(216444, 92610, 100, 0, 0, 1, 1, 0),
(216445, 92612, 100, 0, 0, 1, 1, 0),
(216446, 92614, 100, 0, 0, 1, 1, 0),
(216447, 92616, 100, 0, 0, 1, 1, 0),
(216448, 92618, 100, 0, 0, 1, 1, 0),
(216449, 92620, 100, 0, 0, 1, 1, 0),
(216450, 92622, 100, 0, 0, 1, 1, 0),
(216451, 92624, 100, 0, 0, 1, 1, 0);