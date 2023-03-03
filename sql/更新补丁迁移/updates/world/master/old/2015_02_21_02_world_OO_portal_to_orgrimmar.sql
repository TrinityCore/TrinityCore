delete from creature where id = 73536;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(73536, 1136, 6738, 6738, 16632, 1, 0, 0, 1427.97, 356.15, 289.19, 4.91, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(73536, 1136, 6738, 6738, 16632, 1, 0, 0, 1454.52, 355.82, 289.19, 4.46, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(73536, 1136, 6738, 6738, 16632, 1, 0, 0, 783.54, 1168.18, 356.15, 4.22, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(73536, 1136, 6738, 6738, 16632, 1, 0, 0, 691.1, 1149.94, 356.15, 5.84, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

update creature_template set IconName = 'interact', npcflag = 16777216, `unit_flags` = '512', `unit_flags2` = '34816' where entry = 73536;

REPLACE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('73536', '148034', '1', '0'),  -- aliance
('73536', '148032', '1', '0');

DELETE FROM `conditions` WHERE SourceGroup = 73536;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('18', '73536', '148034', '0', '0', '6', '0', '469 ', '0', '0', '0', '0', '', 'Aliance'), 
('18', '73536', '148032', '0', '0', '6', '0', '67', '0', '0', '0', '0', '', 'Horde');

delete from spell_target_position where id = 148034;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(148032, 1136, 1439.95, -5013.35, 12.287, 1.647),
(148034, 1136, 1439.95, -5013.35, 12.287, 1.647);

DELETE FROM `creature_text` WHERE entry in (73598, 73605);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(73598, 0, 0, 'Гордыня Гарроша выпустила последнего ша. Я не удивлена.', 12, 0, 100, 1, 0, 38090, 0),
(73598, 1, 0, 'Кровавый Вой.', 12, 0, 100, 5, 0, 28232, 'Лор''темар Терон'),
(73598, 2, 0, 'Это уже не новость, лорд. Пока мы с вами беседуем, флот короля Ринна уже подходит к Оргриммару.', 12, 0, 100, 5, 0, 38092, 'Лор''темар Терон'),
(73598, 3, 0, 'Предупреждаю, Лор''темар. Альянс осаждает город, мы уничтожим Адского Крика. Вам и вашим людям лучше не стоять у нас на пути.', 12, 0, 100, 25, 0, 38093, 'Лор''темар Терон'),
(73598, 4, 0, 'Вперед, герои! В портал! Осада Оргриммара началась!', 12, 0, 100, 1, 0, 38094, 'Леди Джайна Праудмур'),
--
(73605, 0, 0, 'Смотрите! Он оставил оружие!', 14, 0, 100, 25, 0, 38158, 0),
(73605, 1, 0, 'Гаррош совсем обезумел.', 12, 0, 100, 6, 0, 38159, 'Леди Джайна Праудмур'),
(73605, 2, 0, 'Как и наш. Мы с Сильваной направили корабли для поддержки восстания Вол''джина.', 12, 0, 100, 5, 0, 38160, 'Леди Джайна Праудмур'),
(73605, 3, 0, 'Всегда рад встрече с вами, леди Праудмур.', 12, 0, 100, 1, 0, 38161, 'Леди Джайна Праудмур');