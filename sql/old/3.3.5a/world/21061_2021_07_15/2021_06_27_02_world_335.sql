-- Quest titles / Названия квестов
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `Title`='Перо Кровавой Топи' WHERE `ID`=11158 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `Title`='Разыскивается: Кровокоготь Ненасытный' WHERE `ID`=11184 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `Title`='Спасти груз!' WHERE `ID`=11207 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `Title`='Налетчики Дикого Рога' WHERE `ID`=11156 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `Title`='Крушение дирижабля' WHERE `ID`=11172 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `Title`='Оружие клана Зловещего Тотема' WHERE `ID`=11169 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `Title`='Подсунуть реактив' WHERE `ID`=11173 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `Title`='Предотвращение коррозии' WHERE `ID`=11174 AND `locale`='ruRU';

-- Quest completion texts / Тексты завершения квестов
DELETE FROM `quest_request_items_locale` WHERE `ID` = 179 AND `locale` = 'ruRU';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(179, 'ruRU', 'Что, потрепали тебя волки? Да уж, когти и клыки – это тебе не шуточки!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 179 AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES
(179, 'ruRU', 'О! Прекрасно! Волчье мясо – это то, что надо!.. Не беспокойся, $N, свою часть сделки я выполню честно. Вот, посмотри, что из этого тебе подойдет.');
DELETE FROM `quest_request_items_locale` WHERE `ID` = 3107 AND `locale` = 'ruRU';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(3107, 'ruRU', 'Итак, ты здесь – и очень вовремя. Нам многое предстоит сделать в Холодной долине – а может, и за ее пределами. Мне понадобится твоя помощь, а тебе, несомненно, будет нелишней моя.$B$BТеперь ты рыцарь Серебряной Длани: не забывай об этом!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 3107 AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES
(3107, 'ruRU', 'Люди многое поведали нам о Священном Свете и о том, как орден паладинов необходим им – и всему Азероту. Мы испытываем огромное уважение к традициям ордена. Поистине поразительно, что один человек, одна жертва может обратить погибель в спасение.$B$BДумаю, нам обоим придется немного поработать вместе. Когда ты решишь, что время пришло, возвращайся ко мне: тебе нужно будет научиться кое-чему новому, прежде чем браться за дело. Негоже отправляться в далекие странствия $Gнеподготовленным:неподготовленной;, верно?');
DELETE FROM `quest_request_items_locale` WHERE `ID` = 233 AND `locale` = 'ruRU';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(233, 'ruRU', 'А? Что? Для меня что-то есть?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 233 AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES
(233, 'ruRU', 'Благодарю тебя, я уже давно ждал этих писем...$B$BКонечно, они не все для меня. Вот это, скажем, для Грелина Белоборода. Он тут неподалеку живет, может, зайдешь к нему?');
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 417 AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(417, 'ruRU', 'Злая весть. Хилдельв был хорошим другом. Жаль, что не довелось мне с тобой пойти на этого Паршивого Когтя!$B$BСпасибо тебе, $N. Пилоты Осадной бригады Стальгорна тебя не забудут.', 0);

-- Road signs in Thousand Needles / Дорожные указатели в Тысяче Игл
DELETE FROM `gameobject_template_locale` WHERE `entry` IN (19856,19859,19857,19858,19848,19850,19852,19849,19851) AND `locale` = 'ruRU';
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `VerifiedBuild`) VALUES
(19856, 'ruRU', 'Степи', 0),
(19859, 'ruRU', 'Фералас', 0),
(19857, 'ruRU', 'Мерцающая равнина', 0),
(19858, 'ruRU', 'Таланаар', 0),
(19848, 'ruRU', 'Застава Вольного Ветра', 0),
(19850, 'ruRU', 'Танарис', 0),
(19852, 'ruRU', 'Степи', 0),
(19849, 'ruRU', 'Мерцающая равнина', 0),
(19851, 'ruRU', 'Великий Подъемник', 0);

-- Names of some items / Названия некоторых предметов
DELETE FROM `item_template_locale` WHERE `ID` IN (24490,30633,30622,30637,30634,30623,30635,23162) AND `locale` = 'ruRU';
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`) VALUES
(24490, 'ruRU', 'Хозяйский ключ', '', 0),
(30633, 'ruRU', 'Аукенайский ключ', '', 0),
(30622, 'ruRU', 'Ключ, выкованный в пламени', '', 0),
(30637, 'ruRU', 'Ключ, выкованный в пламени', '', 0),
(30634, 'ruRU', 'Деформированный ключ', '', 0),
(30623, 'ruRU', 'Ключ от Резервуара', '', 0),
(30635, 'ruRU', 'Ключ Времени', '', 0),
(23162, 'ruRU', 'Ящик с бесконечными припасами для сопротивления Форора', 'Дно сундука протекает. Оттуда текут слезы...', 0);
