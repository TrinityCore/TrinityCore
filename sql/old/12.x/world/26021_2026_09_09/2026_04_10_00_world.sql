-- Template
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (166906, 156651);

-- Locales
DELETE FROM `gameobject_template_locale` WHERE (`locale`='ruRU' AND `entry` IN (339770,335718,339769,349962));
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `unk1`, `VerifiedBuild`) VALUES
(339770, 'ruRU', 'Брошенный сундук с сокровищами', 'Открывание', '', 66709),
(335718, 'ruRU', 'Doodad_6DU_HighmaulRaid_Door_ThroneRoom001', '', '', 66709),
(339769, 'ruRU', 'Костер', 'Готовка', '', 66709),
(349962, 'ruRU', 'Костер', 'Готовка', '', 66709);

DELETE FROM `quest_request_items_locale` WHERE (`ID` IN (59932, 55174) AND `locale`='ruRU');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(59932, 'ruRU', 'Прошу... еды...', 66709),
(55174, 'ruRU', 'Прошу... еды...', 66709);

DELETE FROM `quest_offer_reward_locale` WHERE (`ID` IN (59932, 55174) AND `locale`='ruRU');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(59932, 'ruRU', '<Вон\'са быстро съедает приготовленное вами мясо.>\n\nЗначит, я все-таки пока не отправлюсь к Бвонсамди.\n\nЛучше вам поторопиться. Нескольких членов экспедиции сцапали свинобразы!', 66709),
(55174, 'ruRU', '<Алария быстро съедает приготовленное вами мясо.>\n\nКлянусь Светом... Так намного лучше.\n\nЗдесь нельзя оставаться... экспедицию захватили свинобразы!', 66709);
