update creature set spawntimesecs = 300 where id = 71876;
update gameobject set phasemask = 2 where id in (220819,222768);

update creature_template set npcflag = 1, AIName = 'SmartAI' where entry = 71876;
update creature_template set AIName = 'SmartAI' where entry = 71869;
update creature_template set speed_walk = '0.5', speed_run = '0.2', speed_fly = '0.2', InhabitType = 7, scriptname = 'npc_timeless_spirit' where entry = 71868;
update gameobject_template set AIName = 'SmartGameObjectAI' where entry = 222768;

delete from smart_scripts where entryorguid in (71876, 71869, 222768);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
-- Zarim start event
(71876, 0, 0, 1, 62, 0, 100, 0, 15978, 0, 0, 0, 85, 144145, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Select gossip - Cast Spirit World'),
(71876, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, 147044, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Cast Summon Spirit'),
(71876, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 85, 149109, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Cast Bone Apart Tracking'),
(71876, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Close Gossip'),
(71876, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Despawn'),
--
(71869, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Just Summon - SetState Passive'),
(71869, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Say Text 0'),
(71869, 0, 2, 3, 38, 0, 100, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SetData - Say Text 1'),
(71869, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Despawn'),
--
(222768, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 71869, 30, 0, 0, 0, 0, 0, 'GossipHello - SendData target');

delete from spell_phase where id = 144145;
INSERT INTO `spell_phase` (`id`, `phasemask`, `terrainswapmap`, `phaseId`) VALUES 
(144145, 2, 0, 0);

delete from conditions where SourceTypeOrReferenceId = 15 and SourceGroup = 15978;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 15978, 0, 0, 0, 8, 0, 32962, 0, 0, 1, 0, '', NULL);

delete from spell_area where spell = 144145;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(144145, 6780, 0, 0, 0, 0, 2, 0, 64, 11);

delete from areatrigger_scripts where entry = 9211;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(9211, 'at_tom_bone_apart');

delete from gossip_menu where entry = 15978;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(15978, 23010);

delete from gossip_menu_option where menu_id = 15978;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(15978, 0, 0, 'Я готов войти в мир духов.', 1, 1, 0, 0, 0, 0, NULL);

delete from creature_text where entry in (71876, 71869);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(71876, 0, 0, 'Hey, meat sack! If you got five minutes, come talk to me! I got no body!', 12, 0, 0, 0, 0, 0, ''),
(71869, 0, 0, 'Good deal. Welcome to the spirit world. Kinda. Let\'s check out the chests for any goodies, and see if you can find my body somewhere!', 12, 0, 0, 0, 0, 0, ''),
(71869, 1, 0, 'Wicked! You found my body! Look at them old bones.', 12, 0, 0, 0, 0, 0, '');

delete from locales_creature_text where entry in (71876, 71869);
INSERT INTO `locales_creature_text` (`entry`, `textGroup`, `id`, `text_loc8`) VALUES 
(71876, 0, 0, 'Эй, ты! Подойди сюда! У меня ведь нет тела!'),
(71869, 0, 0, 'Отлично. Добро пожаловать в мир духов. Ну, или вроде того. Давай обыщем сундуки на предмет добычи. А может, ты где-нибудь найдешь и мое тело?'),
(71869, 1, 0, 'О-о-о! Нашел мое тело! Ах вы мои старые косточки...');

DELETE FROM `creature` WHERE `id` = 71868;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(71868, 870, 1, 2, -278.9601, -5216.191, -10.95073, 0.7853982, 120, 0, 0),
(71868, 870, 1, 2, -278.7917, -5214.262, 17.81833, 2.711078, 120, 0, 0),
(71868, 870, 1, 2, -376.7447, -5126.686, 8.319639, 2.356179, 120, 0, 0),
(71868, 870, 1, 2, -325.5191, -5211.788, -4.414467, 2.265284, 120, 0, 0),
(71868, 870, 1, 2, -363.8542, -5210.757, 9.943748, 5.497787, 120, 0, 0),
(71868, 870, 1, 2, -279.4166, -5172.005, 19.41631, 2.356179, 120, 0, 0),
(71868, 870, 1, 2, -289.559, -5167.599, 7.370006, 3.356564, 120, 0, 0),
(71868, 870, 1, 2, -340.539, -5227.153, -4.879858, 0.3339051, 120, 0, 0),
(71868, 870, 1, 2, -256.3281, -5159.163, 2.020491, 0, 120, 0, 0),
(71868, 870, 1, 2, -396.5462, -5134.38, 7.432887, 3.141593, 120, 0, 0),
(71868, 870, 1, 2, -373.3966, -5163.551, 7.432899, 5.448546, 120, 0, 0),
(71868, 870, 1, 2, -265.4531, -5187.624, 15.4866, 3.064929, 120, 0, 0),
(71868, 870, 1, 2, -283.9318, -5146.957, 3.76505, 0, 120, 0, 0),
(71868, 870, 1, 2, -258.776, -5130.139, 2.152369, 5.448558, 120, 0, 0),
(71868, 870, 1, 2, -351.4257, -5198.587, 8.827385, 1.553812, 120, 0, 0),
(71868, 870, 1, 2, -295.6828, -5210.896, -10.95072, 2.649574, 120, 0, 0),
(71868, 870, 1, 2, -278.6228, -5155.827, 10.75721, 0.9319767, 120, 0, 0),
(71868, 870, 1, 2, -295.4816, -5126.745, 2.547471, 0, 120, 0, 0),
(71868, 870, 1, 2, -408.0458, -5147.841, 7.432893, 2.356179, 120, 0, 0),
(71868, 870, 1, 2, -327.0243, -5195.635, 6.848917, 2.597181, 120, 0, 0),
(71868, 870, 1, 2, -278.8455, -5250.377, -9.478174, 1.570796, 120, 0, 0),
(71868, 870, 1, 2, -261.3899, -5226.374, -8.263095, 0.7733457, 120, 0, 0),
(71868, 870, 1, 2, -227.849, -5234.875, -16.42413, 2.729874, 120, 0, 0),
(71868, 870, 1, 2, -235.026, -5197.53, -10.88598, 0, 120, 0, 0),
(71868, 870, 1, 2, -263.1875, -5115.488, 2.367209, 4.712389, 120, 0, 0),
(71868, 870, 1, 2, -234.2101, -5138.897, 1.892638, 5.448558, 120, 0, 0);

update creature set spawndist = 10, movementtype = 1 where id = 71868;