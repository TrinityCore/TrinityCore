-- Add ruRU offer rewards for quest 742
-- https://ru.classic.wowhead.com/quest=742/большая-охота
SET @ID := 742;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать на новое пограничье, $N. Ясеневый лес – край неограниченных возможностей, где юному |3-2($C) вроде тебя выпадает шанс показать себя. Посмотри на эту заставу и не поленись сходить на Зорамское взморье – у Орды и там форпост есть.$B$BКак понимаю, ты здесь для того, чтобы побольше узнать об охоте. Слушай же внимательно, и я с радостью поделюсь с тобой всем, что тебе следует знать.', 0);

-- Add ruRU offer rewards for quest 908
-- https://wowroad.info/goha.ru?quest=908
SET @ID := 908;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это именно то, что мне было нужно! Глубинный сердечник – неиссякаемая кладезь информации, которую мы сможем оттуда извлечь. Что бы ни затевал Сумеречный Молот – и уж поверь мне, ничего хорошего – мы с моими товарищами сумеем это выяснить. Ты сегодня хорошо $Gпотрудился:потрудилась;, и Служители Земли весьма благодарны тебе за помощь. Ты и всей Орде $Gпомог:помогла;, и имеешь право гордиться собой.', 0);

-- Add ruRU offer rewards for quest 909
-- https://wowroad.info/goha.ru?quest=909
SET @ID := 909;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ого... вот это находка, $N. Говоришь, ты $Gдобыл:добыла; это у барона Акваниса в Черных Глубинах? Барон Акванис давно уже считается оскверненной силой Стихии, а этот шар даст понять, что именно повергло его в скверну. Хотя я не удивлюсь, если это окажется клан Сумеречного Молота, зато мы узнаем, как они сумели это сделать. Хорошо, что ты $Gпринес:принесла; эту штуку мне. Прошу – прими это вместе с горячей благодарностью Служителей Земли.', 0);

-- Add ruRU offer rewards for quest 910
-- https://wowroad.info/goha.ru?quest=910
SET @ID := 910;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ух ты, океан ОГРОМЕН! Там было много чаек и много других вещей. Там много шума и суеты, прям как я и ожидал. Пираты также расположены неподалеку. Клево!$B$BСпасибо, что $Gвзял:взяла; меня в Кабестан, $N. Там было действительно круто!', 0);

-- Add ruRU offer rewards for quest 911
-- https://wowroad.info/goha.ru?quest=911
SET @ID := 911;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ух ты, Ясеневый лес - это место, где происходят настоящие приключения! Ты когда-нибудь $Gсражался:сражалась; в Ясеневом лесу, $N? Когда я подрасту, стану героем, то я хочу прийти в Ясеневый лес и сражаться во славу Орды.$B$BСпасибо, что Gвзял:взяла; меня на фронт, $N. Ты $Gлучший:лучшая;!', 0);

-- Add ruRU offer rewards for quest 915
-- https://wowroad.info/goha.ru?quest=915
SET @ID := 915;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ммммммммм! Я люблю их клубничное мороженое! Тигуля и Форор определенно умеют делать его!$B$BСпасибо огромное, $N. Это лучшее угощение в мире!', 0);

-- Add ruRU offer rewards for quest 925
-- https://wowroad.info/goha.ru?quest=925
SET @ID := 925;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'УХ ТЫ! Ты $Gдостал:достала; для меня отпечаток копыта Кэрна! Спасибо огромное! И... ого! Он написал личное сообщение здесь - мне! Я знал, что он будет действительно крутым, прям как я и думал! Может, когда-нибудь, я сам лично поблагодарю его... когда стану героем Орды!$B$BТы $Gлучший:лучшая;, $N. Спасибо, что $Gбыл:была; так $Gдобр:добра; ко мне.', 0);

-- Add ruRU offer rewards for quest 926
-- https://wowroad.info/goha.ru?quest=926
SET @ID := 926;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Эти камни содержат магическую энергию, но они были умышленно разбиты. Они очень нестабильны и могут в скором времени самоуничтожиться, как только их уберут со стола.', 0);

-- Add ruRU offer rewards for quest 934
-- https://wowroad.info/goha.ru?quest=934
SET @ID := 934;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Находиться в присутствии Древа-оракула... это все равно что увидеть воплощенную мудрость. Позволь мне продолжить...$B$BТельдрассил рос, и верховный друид обратился за благословением к драконам, ведь именно они благословили Нордрассил в древние времена. Однако Ноздорму, Повелитель Времени, отказал друиду, упрекнув его в самонадеянности. Алекстраза также отказала Оленьему Шлему, а без ее благословения рост Тельдрассила стал непредсказуем, и в нем обнаружились изъяны...', 0);

-- Add ruRU offer rewards for quest 936
-- https://ru.tbc.wowhead.com/quest=936/помощь-верховному-друиду-руническому-тотему
SET @ID := 936;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, |3-6($C)! Рад, что ты хочешь помочь нам в наших исследованиях. Дел у нас много, и я оказал бы тебе дурную услугу, если бы не предупредил, что работа опасная. Надеюсь, тебя это не отпугнет... Впрочем, судя по твоему виду, тебе не впервой встречаться с опасностями.', 0);

-- Add ruRU offer rewards for quest 961
-- https://ru.tbc.wowhead.com/quest=961/размышление-ону
SET @ID := 961;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Обнаружение культистов клана Сумеречного Молота беспокоит меня. Я должен поразмыслить об их намерениях...$B$BКогда у тебя будет больше информации, поговори со мной посредством гадальной чаши. Если тебе для создания чаши нужен фиал виденья, то... у меня есть еще.', 0);

-- Add ruRU offer rewards for quest 964
-- https://ru.tbc.wowhead.com/quest=964/размышление-ону
SET @ID := 964;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличные образцы! Теперь моя очередь – я закалю их особым образом, чтобы они смогли вынести процесс отковки, через который им придется рано или поздно пройти.$B$BТеперь придется отыскать подходящую форму для отливки. Я знаю одного гоблина-кузнеца из Танариса, который в прошлом делал формы для не менее жутких вещей. Его девиз – как у всех гоблинов – кто платит, тот и музыку заказывает.', 0);

-- Add ruRU offer rewards for quest 968
-- https://ru.tbc.wowhead.com/quest=968/подземные-силы
SET @ID := 968;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, экземпляр "Подземных сил". Интересный текст, да уж. А кое-кто найдет его и полезным тоже...$B$BНо эта книга в ужасном состоянии. И поглядите-ка! Заметки на полях – почти на каждой странице!$B$BХм... Я помню этот экземпляр. Я продал его Болгару в прошлом году. Вы его... его $Gдруг:подруга;? Да, должно быть, так. У вас в глазах такой же огонь горит!$B$BНу, по определению, друг Болгара – мой друг. А мы должны поддерживать близких людей, правда?', 0);

-- Add ruRU offer rewards for quest 972
-- https://ru.tbc.wowhead.com/quest=972/сапта-воды
SET @ID := 972;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Возьми сапту воды и отыщи оскверненную заводь в Серебряном бору. Я возлагаю на тебя большие надежды, Ахахаха.', 0);

-- Add ruRU offer rewards for quest 1000
-- https://ru.tbc.wowhead.com/quest=1000/новое-пограничье
SET @ID := 1000;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Здравствуй, |3-6($C).$B$BЯ рад, что героям, подобным тебе, небезразлична судьба природы. Слава о твоих великих деяниях летела впереди тебя, и тебе здесь рады. Узрев тебя, я исполнился уверенности, что Круг Кенария обретет нужную ему помощь.$B$BНаши связи с Кругом Кенария Лунной поляны превыше расовых и политических предрассудков. Помни это, трудясь во славу Круга, и будет тебе благо.', 0);

-- Add ruRU offer rewards for quest 1004
-- https://ru.tbc.wowhead.com/quest=1004/новое-пограничье
SET @ID := 1004;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Здравствуй, |3-6($C)!$B$BПриятно видеть, что таким, как ты, небезразлично благополучие природы. Рассказы о твоих подвигах опережают тебя, и тебе здесь всегда рады. Твой приход внушает мне уверенность, что Круг Кенария получит помощь, в которой нуждается.$B$BНаша связь с Кругом Кенария на Лунной Поляне превыше расовых и политических противоречий. Помни это, когда будешь действовать от имени Круга, – и добьешься успеха.', 0);

-- Add ruRU offer rewards for quest 1015
-- https://ru.tbc.wowhead.com/quest=1015/новое-пограничье
SET @ID := 1015;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'С чего вы решили, что я собираюсь тратить время на таких, как вы, |3-6($C)? Хотя погодите...Дайте мне разобраться с моими повседневными обязанностями, и тогда, может быть, у меня для вас найдется пара минут. Нет, ну разумеется, благо Дарнасса, да что там – Тельдрассила! – это такая ерунда по сравнению с вашим желанием получить новую побрякушку...$B$BЭти недоумки из Лунной поляны, с их призывом на помощь, тратят мое время – не представляю, как выдержу все это?!', 0);

-- Add ruRU offer rewards for quest 1018
-- https://ru.tbc.wowhead.com/quest=1018/новое-пограничье
SET @ID := 1018;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Здравствуй, |3-6($C)!$B$BПриятно видеть, что таким, как ты, небезразлично благополучие природы. Рассказы о твоих подвигах опережают тебя, и тебе здесь всегда рады. Твой приход внушает мне уверенность, что Круг Кенария получит помощь, в которой нуждается.$B$BНаша связь с Кругом Кенария на Лунной Поляне превыше расовых и политических противоречий. Помни это, когда будешь действовать от имени Круга, – и добьешься успеха.', 0);

-- Add ruRU offer rewards for quest 1019
-- https://ru.tbc.wowhead.com/quest=1019/новое-пограничье
SET @ID := 1019;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'С чего ты $Gрешил:решила;, что я буду утруждать себя беседой с $Gтаким:такой;, как ты, |3-6($C)? Вот сейчас я брошу мои великие каждодневные труды и стану искать для тебя эту безделицу! Ведь благополучие Дарнасса – нет, всего Тельдрассила – в сравнение не идет с важностью поиска этой пустяковины для твоей коллекции!$B$BСначала эти недоумки из Лунной поляны отнимают у меня время своими просьбами о помощи, а теперь я еще и это сносить должен?', 0);

-- Add ruRU offer rewards for quest 1036
-- https://wowroad.info/goha.ru?quest=1036
SET @ID := 1036;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Стоять, прохвост. Болтают, будто ты не прочь кое-кому бошки посшибать. Ну, если ты не $Gдруг:подруга; Пиратской Бухте, то для тебя найдется особое местечко у пиратов Кровавого Паруса. Грррр...', 0);

-- Add ruRU offer rewards for quest 1051
-- https://ru.tbc.wowhead.com/quest=1051/месть-воррела
SET @ID := 1051;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Воррел был мне добрым супругом...$B$BПроклятые смертные!$B$BНикогда нам более не быть вместе. По крайней мере, я найду утешение в свершенной тобой мести. Благодарю тебя.$B$BА теберь оставь меня наедине с моим горем.', 0);

-- Add ruRU offer rewards for quest 1081
-- https://ru.tbc.wowhead.com/quest=1081/приглашение-от-тиранды
SET @ID := 1081;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Приветствую тебя, $N. Мне доводилось и прежде слышать твое имя, и я рада видеть, что, не взирая на твою молодость, ты уже $Gизбрал:избрала; свой путь.$B$BТы окажешь мне великую честь, если примешь это как дар в знак нашего уважения к тебе.', 0);

-- Add ruRU offer rewards for quest 1082
-- https://ru.tbc.wowhead.com/quest=1082/новости-для-часового-тенисил
SET @ID := 1082;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Благодарю тебя, $N. Ты $Gсослужил:сослужила; Стражам хорошую службу.$B$BЯ рада узнать, что Каэла... и даже Гаксим живы и здоровы.$B$BТы заслуживаешь нашего уважения.', 0);

-- Add ruRU offer rewards for quest 1083
-- https://ru.tbc.wowhead.com/quest=1083/разъяренные-духи
SET @ID := 1083;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Останки нашего врага... твоя сила сослужила нам добрую службу, $N. Благодарю тебя.', 0);

-- Add ruRU offer rewards for quest 1084
-- https://ru.tbc.wowhead.com/quest=1084/раны-дерев
SET @ID := 1084;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N.Этого должно быть более чем достаточно, чтобы Гаксим выяснил, каким образом скверна пала на древней. Я немедленно передам ему этот образец.', 0);

-- Add ruRU offer rewards for quest 1100
-- https://ru.tbc.wowhead.com/quest=1100/дневник-хмурня
SET @ID := 1100;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Говорите, что нашли этот дневник у мертвого дворфа? Дайте мне на минутку, хочу взглянуть...', 0);

-- Add ruRU offer rewards for quest 1101
-- https://ru.tbc.wowhead.com/quest=1101/хозяйка-лабиринтов
SET @ID := 1101;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наконец-то старая карга умерла. Это отличная новость, $N!$B$BВ наше опасное время всегда приятно встретить такого храбреца, как ты.$B$BТеперь, когда прислужники Остробок мертвы, мы сможем продолжить наши исследования той области. Возможно, теперь мы сможем узнать, почему место упокоения Агамаггана подверглось такому осквернению.$B$BОднако, боюсь, здесь не обошлось без предательства...', 0);

-- Add ruRU offer rewards for quest 1103
-- https://ru.tbc.wowhead.com/quest=1103/зов-воды
SET @ID := 1103;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хвала тебе, смелый |3-6($C). Рифы побережья Западного Края будут освещены благодаря твоим трудам. Множество жизней будет спасено, пока горит факел.$B$BМеня постигла бессмысленная смерть на этом самом побережье. Мой долг в иной жизни – следить, чтобы никто не повторил моей судьбы.', 0);

-- Add ruRU offer rewards for quest 1123
-- https://ru.tbc.wowhead.com/quest=1123/рабин-сатурна
SET @ID := 1123;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я Рабин Сатурна. От лица хранителя Ремула и всех обитателей сего священного места привествую тебя.$B$BЯ ценю твою заинтересованность и горячую готовность помочь Кругу Кенария. Таурены не раз показывали стойкую приверженность принципам Кенария, и благодаря им Орда может пользоваться безопасностью Лунной поляны. Ведь благо Азерота – наша общая цель.$B$BЗдесь ты среди друзей, $N.', 0);

-- Add ruRU offer rewards for quest 1125
-- https://ru.tbc.wowhead.com/quest=1125/духи-южного-ветра
SET @ID := 1125;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я подозревал, что немалую роль в гибели деревни сыграл огромный улей в башне неподалеку. Похоже, проделанная тобой работа подтверждает мои подозрения, улей представляет опасность для всей нашей деятельности.$B$BБлагодарю тебя за милость, оказанную душам павших. Я знаю, как нелегко это сделать. И все же я хочу вновь воззвать к тебе о помощи...', 0);

-- Add ruRU offer rewards for quest 1126
-- https://ru.tbc.wowhead.com/quest=1126/улей-в-башне
SET @ID := 1126;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что за... Что это?$B$BОно имеет форму... ящика? А дрянью-то как заросло... Стой, здесь видна часть того, что внутри. Неужели под всей этой гадостью скрывается книга?$B$BКажется, тебе удалось найти кое-что интересное, $N… по крайней мере, хочется на это надеяться. Может быть, это дневник или журнал, оставшийся с древних времен, лежавший в целости и сохранности под покровом хитиновой скорлупы.$B$BКажется, я знаю способ выяснить, что это.', 0);

-- Add ruRU offer rewards for quest 1127
-- https://wowroad.info/goha.ru?quest=1127
SET @ID := 1127;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо! Вот твоя плата.$B$BИ вот еще кое-что... за твою осмотрительность.', 0);

-- Add ruRU offer rewards for quest 1135
-- https://ru.tbc.wowhead.com/quest=1135/яд-из-скального-гнездовья
SET @ID := 1135;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О-о-о, некоторые чуть ли не лопаются от яда, $N! Такие обычно собирают с очень юных виверн или с плодовитых самок. Наверное, нелегко вам пришлось в Скальном гнездовье!', 0);

-- Add ruRU offer rewards for quest 1136
-- https://ru.tbc.wowhead.com/quest=1136/ледочрев
SET @ID := 1136;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Для того, чтобы найти и сразить Леочрева, нужно обладать силой и смекалкой, $N. Оба эти качества у тебя есть.$B$BТвой путь привел тебя в долины Тысячи Игл и в высокие горы Альтерака. Однажды он проведет тебя по всем странам матери-земли – ведь именно таков путь охотника.', 0);

-- Add ruRU offer rewards for quest 1139
-- https://ru.tbc.wowhead.com/quest=1139/утерянные-таблички-воли
SET @ID := 1139;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<При виде таблички советник Белграм изумленно качает головой>$B$B$N, это поразительно! Я прослежу, чтобы табличка была доставлена королевским магам как можно скорее. Они непременно пожелают проверить, что в легендах истина, а что ложь. Ты $Gпомог:помогла; нашему народу более, чем я смел надеяться!', 0);

-- Add ruRU offer rewards for quest 1166
-- https://ru.tbc.wowhead.com/quest=1166/заботы-властителя-мокморокка
SET @ID := 1166;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хороший |3-6($R). Моя скучать по этим вещам. Моя теперь дружить с твоя.', 0);

-- Add ruRU offer rewards for quest 1168
-- https://ru.tbc.wowhead.com/quest=1168/армия-черного-дракона
SET @ID := 1168;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gубил:убила; многих из войска Черного дракона. Ты – отважный |3-6($R)! Тхарг счастлив!', 0);

-- Add ruRU offer rewards for quest 1169
-- https://ru.tbc.wowhead.com/quest=1169/корни-угрозы
SET @ID := 1169;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Рискованное было дельце, добывать все эти сердца и языки, а? Теперь я проникну в глубины тайн, чтобы выяснить, откуда на наш прежний дом свалилась такая напасть.', 0);

-- Add ruRU offer rewards for quest 1170
-- https://ru.tbc.wowhead.com/quest=1170/выводок-ониксии
SET @ID := 1170;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Почему ты говорить с моя про драконы? Моя не любить драконы. Моя не хотеть здесь никакие драконы.', 0);

-- Add ruRU offer rewards for quest 1171
-- https://ru.tbc.wowhead.com/quest=1171/выводок-ониксии
SET @ID := 1171;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Жалкий трус!$B$BМок\'Морокк выказывал силу, пока нашим вождем был Рексар. Но после его ухода Мок\'Морокк начал сам стремиться к власти. Он предпочитал требовать, вместо того чтобы руководить. Он не заботится о своих подданых, а наоборот хочет, чтобы мы заботились о нем.$B$BС этим надо что-то делать!', 0);

-- Add ruRU offer rewards for quest 1172
-- https://ru.tbc.wowhead.com/quest=1172/выводок-ониксии
SET @ID := 1172;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! Теперь Ониксия не скоро отложит очередную кладку.$B$BБлагодарю тебя, $N, от имени моего народа.$B$BЯ уже о многом просил тебя, но, может, ты окажешь последнюю услугу клану Каменного Молота.$B$BМок\'Морокк не достоин править нами. Тхарг стал бы отличным вождем, но он стар и изранен. Изгони силой из этих мест Мок\'Морокка. Только тогда мы сможем избрать нового вождя, который отведет нас на родину, в южные земли.', 0);

-- Add ruRU offer rewards for quest 1173
-- https://ru.tbc.wowhead.com/quest=1173/вызов-властителю-мокморокку
SET @ID := 1173;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Эта трусливая туша, Мок\'Морокк, сбежал как испуганный младенец при виде розги. Ты $Gоказал:оказала; нам огромную услугу, $N.$B$BТеперь мой народ может выбрать себе нового лидера, того, кто поможет восстановить наши жилища и защитить их.', 0);

-- Add ruRU offer rewards for quest 1177
-- https://ru.tbc.wowhead.com/quest=1177/моя-голодный
SET @ID := 1177;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Моя любить рыбья голова!$B$BМоя пока твоя не есть.', 0);

-- Add ruRU offer rewards for quest 1185
-- https://ru.tbc.wowhead.com/quest=1185/а-под-хитином-было
SET @ID := 1185;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, опять ты! В смысле, это ты – а ты, то есть, $N! Да, это ты!$B$BСлушай-ка!$B$BТа штука, что ты $Gнашел:нашла; в Силитусе, оказалась книгой. Дневник, написанный на очень древнем диалекте того, что теперь называется дарнассийским. Это займет некоторое время, но я намерен как следует в нем разобраться. Мне показалось, что тебе следует знать, что твоя находка оказалась просто бесценной для Круга.$B$BМать-медведица в восхищении, и все такое!', 0);

-- Add ruRU offer rewards for quest 1193
-- https://ru.tbc.wowhead.com/quest=1193/сломанная-западня
SET @ID := 1193;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ториевое устройство беспрепятственно встает на место, создавая канал, в который нужно влить масло льда. Как только последние капли масла падают в канал, западня готова к работе.$B$BИ горе неосторожному огру, который подойдет слишком близко!', 0);

-- Add ruRU offer rewards for quest 1198
-- https://ru.tbc.wowhead.com/quest=1198/в-поисках-талрида
SET @ID := 1198;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хорошо, что Рассветный дозорный Шедласс прислал вас. В этом испоганенном месте и правда затевается коварный план.', 0);
