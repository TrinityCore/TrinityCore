delete from creature where id in (70270,70271);
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(70270, 530, 3520, 3520, 1, 1, 0, 0, -3553.78, 1882.82, 47.744, 2.67501, 300, 0, 0, 840, 1000, 0, 0, 0, 0, 0, 0),
(70271, 530, 3520, 3520, 1, 1, 0, 0, -3556.75, 1870.72, 57.1393, 2.82816, 300, 0, 0, 4334, 1000, 0, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `gossip_menu_id`=15555, `MinLevel`=90, `MaxLevel`=90, `faction`=35, `npcflag`=3, `unit_class`=8, `unit_flags`=768, AIName = 'SmartAI' WHERE `entry`=70270;
UPDATE `creature_template` SET iconName = 'openhandglow', `MinLevel`=93, `MaxLevel`=93, `faction`=35, `npcflag`=16777216, `npcflag2`=0, `unit_class`=8 WHERE `entry`=70271;

delete from creature_template_addon where entry = 70271;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(70271, 0, 0, 0, 1, 0, '138557 138556 138555 139388');

DELETE FROM `gossip_menu` WHERE (`entry`=15555 AND `text_id`=22350);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(15555, 22350); -- 70270

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=15555 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `box_coded`, `box_money`, `box_text`) VALUES
(15555, 0, 0, 'Джубека, я больше не хочу нести в себе энергию Скверны.', 1, 1, 0, 5000000, 'Тебе точно больше не нужен Кодекс Зеррата?'); -- 70270

delete from npc_spellclick_spells where npc_entry = 70271;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(70271, 139200, 1, 0);

delete from conditions where SourceTypeOrReferenceId = 15 and SourceGroup = 15555;
delete from conditions where SourceTypeOrReferenceId = 18 and SourceGroup = 70271;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 15555, 0, 0, 0, 8, 0, 32325, 0, 0, 0, 0, '', NULL),
(15, 15555, 0, 0, 0, 1, 0, 101508, 0, 0, 0, 0, '', NULL),
(15, 15555, 0, 0, 0, 1, 0, 137206, 0, 0, 0, 0, '', NULL),
(18, 70271, 139200, 0, 0, 8, 0, 32325, 0, 0, 0, 0, '', NULL),
(18, 70271, 139200, 0, 0, 1, 0, 101508, 0, 0, 1, 0, '', NULL),
(18, 70271, 139200, 0, 0, 1, 0, 137206, 0, 0, 1, 0, '', NULL);

delete from smart_scripts where entryorguid = 70270;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(70270, 0, 0, 1, 62, 0, 100, 0, 15555, 0, 0, 0, 11, 139366, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gossip Select - Cast Purge Xerrath'),
(70270, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Close Gossip');

delete from npc_text where ID = 22350;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (22350, 'Сила Канретада слишком велика, чтобы оставлять его на свободе. Поэтому до конца своей жизни я буду следить за тем, чтобы он оставался в изгнании.

Но небольшое количество энергии Скверны, которая переполняет его, не причинит вреда. Поэтому ты можешь позаимствовать немного. Если когда-либо ты устанешь от нее, я смогу очистить тебя от энергии Скверны за небольшую плату.');
