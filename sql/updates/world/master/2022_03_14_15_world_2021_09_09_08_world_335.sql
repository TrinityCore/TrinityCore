-- Add ruRU offer rewards for quest 1502
-- https://ru.tbc.wowhead.com/quest=1502/тунгрим-огневзор
SET @ID := 1502;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я так долго глядел на пламя горна, что у меня высохли глаза, но кое-что я по-прежнему вижу. Например, тебе что-то от меня нужно.$B$BИ раз ты $Gдобрался:добралась; до моего жилища, то я могу предположить, что именно.', 0);

-- Add ruRU offer rewards for quest 1503
-- https://ru.tbc.wowhead.com/quest=1503/стальные-слитки
SET @ID := 1503;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот они! И все мои слиточки на месте, что и неудивительно. Откуда иглогривым знать, что делать с такой отличной сталью.$B$BСпасибо, $N. Вот твоя награда. Пусть она служит тебе верой и правдой.', 0);

-- Add ruRU offer rewards for quest 1505
-- https://wowroad.info/goha.ru?quest=1505
SET @ID := 1505;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Приветствую тебя. Ты здесь для обучения?', 0);

-- Add ruRU offer rewards for quest 1516
-- https://ru.tbc.wowhead.com/quest=1516/зов-земли
SET @ID := 1516;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Твой успех доказывает: ты действительно $Gготов:готова;.$B$BСреди стихий именно Земля – основа всего сущего. Это твоя сила, твоя выносливость и твое терпение. Земля защитит тебя, если ты будешь относиться к ней с должным почтением. Но и Земля, как все прочие стихии, может быть своенравной.$B$BТеперь я сделаю для тебя сапту. Прими ее – и постигнешь свой путь!', 0);

-- Add ruRU offer rewards for quest 1519
-- https://ru.tbc.wowhead.com/quest=1519/зов-земли
SET @ID := 1519;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, $N. Ты $Gвернулся:вернулась; – а значит, $Gготов:готова; к следующему шагу.$B$BСтихия земли – это основа всех вещей. Это твоя сила, твоя выносливость и твое терпение. Мать-Земля защитит тебя, но к ней должно относиться с уважением. Она – основа жизни, и следуя ее законам, ты приумножишь мудрость. Никогда не забывай тайны, которые она разделит с тобой.$B$BТеперь я приготовлю для тебя сапту земли, который откроет перед тобой новые пути.', 0);

-- Add ruRU offer rewards for quest 1520
-- https://ru.tbc.wowhead.com/quest=1520/зов-земли
SET @ID := 1520;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ах... $N... Земля ликует от того, что ты $Gпришел:пришла; сюда.$B$BТеперь ты $Gсвязан:связана; с ней духом и телом, и продолжишь свой путь, зная, что горы суть твоя сила, равнины суть твое терпение, и весь мир – основа твоей сущности.$B$BДля прохождения этого обряда довольно было смиренно предстать перед землей. Но другие обряды потребуют более активных действий. Они могут оказаться жестоки и непредсказуемы – но такова уж природа стихий. Тебе следует научиться управляться с вечной борьбой противоположностей, лежащей в их основе.', 0);

-- Add ruRU offer rewards for quest 1521
-- https://ru.tbc.wowhead.com/quest=1521/зов-земли
SET @ID := 1521;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно!$B$BТотем, который я сделаю для тебя – не просто символ. Он обладает тайными свойствами. Его можно использовать для сосредоточения заклинаний Земли. Чем больше мудрости ты обретешь, тем больше способностей земли станет тебе доступно.$B$BНаставники в Калимдоре скажут тебе, когда ты будешь $Gготов:готова; к новым знаниям.$B$BА пока возьми этот тотем Земли...', 0);

-- Add ruRU offer rewards for quest 1522
-- https://ru.tbc.wowhead.com/quest=1522/зов-огня
SET @ID := 1522;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что, тебя Сеарн прислал, да?$B$BНу, на Сеарна положиться можно. Значит, ты уже $Gготов:готова; вкусить следующую сапту – сапту огня.$B$BДа, я уже вижу в твоих глазах огонь стремления к познанию! Тебе довелось вкусить власти, и теперь тебе пора сделать новый шаг... Однако, имей терпение, $N. Помни, чему тебя научила земля. Власть разрушения обрести нетрудно, но следует знать, где остановиться.', 0);

-- Add ruRU offer rewards for quest 1523
-- https://wowroad.info/goha.ru?quest=1523
SET @ID := 1523;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хм, тебя Ксанис прислал ко мне?$B$BНу что ж, Ксанису всегда можно доверять. Должно быть ты уже $Gготов:готова; принять участие в следующей сапе, cапте-огня.$B$BВижу в твоих глазах, огненное желание. Ты $Gпопробовал:попробовала; власть на вкус, и теперь, ты $Gготов:готова; к большему. Терпение, $N. Помни чему учила тебя Земля. Мощь и разрушение, ты всегда $Gдолжен:должна; знать, когда нужно остановить руку.', 0);

-- Add ruRU offer rewards for quest 1529
-- https://ru.tbc.wowhead.com/quest=1529/зов-воды
SET @ID := 1529;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ветер следует за тобой, по земле ты шагаешь твердо, а дух уже согрет огнем – я бы сказала, что пришло время познать чистоту воды.$B$BПуть твой был долог, и сила духа позволит тебе пройти еще дальше. Но первый шаг делать тебе.', 0);

-- Add ruRU offer rewards for quest 1531
-- https://ru.tbc.wowhead.com/quest=1531/зов-воздуха
SET @ID := 1531;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Сейчас я дам тебе то, что потребуется для концентрации твоих заклинаний и призывания духов воздуха. Возьми этот тотем. Возвращайся, когда будешь $Gготов:готова; продолжить обучение.', 0);

-- Add ruRU offer rewards for quest 1532
-- https://ru.tbc.wowhead.com/quest=1532/зов-воздуха
SET @ID := 1532;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Сейчас я дам тебе то, что потребуется для концентрации твоих заклинаний и призывания духов воздуха. Возьми этот тотем. Возвращайся, когда будешь $Gготов:готова; продолжить обучение.', 0);

-- Add ruRU offer rewards for quest 1534
-- https://ru.tbc.wowhead.com/quest=1534/зов-воды
SET @ID := 1534;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Чудесно. Теперь у меня есть все три пробы воды, и я могу наполнить фиал чистейшей водой, которую только способно найти живое существо. Она понадобится тебе на следующем этапе.$B$BЯ рада, что среди избравших наш путь есть такие, как ты, $N. Все шаманы гордятся тобой, и я надеюсь вскоре услышать о твоих подвигах.', 0);

-- Add ruRU offer rewards for quest 1536
-- https://ru.tbc.wowhead.com/quest=1536/зов-воды
SET @ID := 1536;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хорошо, $N. Ты изо всех сил стараешься выполнить порученные тебе задания и добиваешься успеха.$B$BЕще одна проба воды, и я смогу создать реактив, необходимый для сапты. Ислен будет довольна.', 0);

-- Add ruRU offer rewards for quest 1559
-- https://ru.tbc.wowhead.com/quest=1559/секрет-изготовления-световой-бомбы
SET @ID := 1559;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Так ты у нас инженер, да? Ну что ж, за то, что $Gнашел:нашла; для меня жемчужины, вот тебе секрет изготовления световых бомб.$B$BТы с ними только уж поосторожней, как бы $Gсамому:самой; не ослепнуть!', 0);

-- Add ruRU offer rewards for quest 1578
-- https://ru.tbc.wowhead.com/quest=1578/помощь-фронту
SET @ID := 1578;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ох, прости! Я и не понял, что ты $Gпришел:пришла; помочь в деле вооружения наших войск. Изготовленные тобой вещи очень нам помогут!$B$BВот чертежи кое-каких доспехов. Надеюсь, они тебе пригодятся.', 0);

-- Add ruRU offer rewards for quest 1582
-- https://ru.tbc.wowhead.com/quest=1582/жилет-лунного-сияния
SET @ID := 1582;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, славные изделия. У тебя искусные руки и острый глаз. Из тебя может получиться неплохой кожевник.$B$BСлушай, $N. Давай-ка я покажу тебе выкройку жилета Лунного сияния.', 0);

-- Add ruRU offer rewards for quest 1599
-- https://ru.tbc.wowhead.com/quest=1599/в-начале-славных-дел
SET @ID := 1599;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно, прекрасно! В самом деле, $N, неплохая работа. Возможно, те, кто тебя рекомендовал, и не ошиблись...$B$BВпрочем, это не мне решать. Поживем – увидим. Будем надеяться, что первый же вызванный бес не вырвет тебе сердце и не сожрет внутренности – думаю, подобное могло бы серьезно повредить твоей карьере. Пока у меня есть основания полагать, что в качестве чернокнижника ты сумеешь прожить хотя бы несколько месяцев.$B$BКстати, $N, хотел тебе дать тебе совет по поводу бесов. Запомни, размер – еще не главное: даже самый глупый таурен знает, что бесы наделены весьма сильной магией.', 0);

-- Add ruRU offer rewards for quest 1618
-- https://ru.tbc.wowhead.com/quest=1618/экипирование-красногорья
SET @ID := 1618;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N. Это чрезвычайно мне поможет. Орки Черной Горы нападают со стороны крепости Каменной Стражи, а гноллы Красногорья шныряют в северных предгорьях, и мне постоянно приходится чинить доспехи и делать новое оружие для наших войск.$B$BТо, что ты $Gпринес:принесла, даст мне хоть небольшую передышку. И у меня будет время кое-чему тебя научить...', 0);

-- Add ruRU offer rewards for quest 1638
-- https://ru.tbc.wowhead.com/quest=1638/обучение-воина
SET @ID := 1638;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О-хо! Выпей со мной, $N. С первого взгляда ты кажешься $Gкрепким:крепкой;, посмотрим, что с тобой сделает несколько кружек крепкого пива!!!$B$BИли... А, да ты поучиться хочешь?', 0);

-- Add ruRU offer rewards for quest 1639
-- https://ru.tbc.wowhead.com/quest=1639/бартлби-пьянь
SET @ID := 1639;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Эй, $Gкрасавчик:красавица;! Что таким как ты делать в "Свинье и свистке"? Осторожнее, неровен час, ноготь сломаешь...', 0);

-- Add ruRU offer rewards for quest 1641
-- https://ru.tbc.wowhead.com/quest=1641/фолиант-божественности
SET @ID := 1641;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Здесь, в Штормграде, я – наставник паладинов. Я – тот, кто ведет их стезей добродетели к Истинному Свету, дабы они защищали Азерот от нашествия нежити и иных бедствий.$B$BИ для тебя пришло время сделать первый шаг на пути праведности. Если ты решишься принять этот путь, я дам тебе Фолиант Божественности. Изучая его, ты узнаешь кое-что о Свете и о том, чего от тебя ожидают. Постигнув мудрость, заключенную в этой книге, ты откроешь в себе новые, удивительные способности.', 0);

-- Add ruRU offer rewards for quest 1642
-- https://ru.tbc.wowhead.com/quest=1642/фолиант-божественности
SET @ID := 1642;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'И снова рад приветствовать тебя, $N. Как идет изучение Фолианта Божественности?$B$BПомни: тебе предстоит пройти испытание. Каждого из нас ждет множество свершений – как в городе, так и в иных землях. Всегда есть люди, нуждающиеся в помощи, сострадании и понимании, всегда есть враждебные твари, которых необходимо уничтожать во благо людей.$B$BДокажи, что ты можешь помогать своим ближним – в особенности тем, кому меньше повезло в жизни. Тем самым ты докажешь, что твои помыслы чисты и что ты воистину служишь Свету.', 0);

-- Add ruRU offer rewards for quest 1643
-- https://ru.tbc.wowhead.com/quest=1643/фолиант-божественности
SET @ID := 1643;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, привет, $Gдорогой:милашка;. Что, все ищешь приключений? Я так рада, что у тебя все в порядке!$B$BЯ? А что я? Ну, с учетом обстоятельств, у меня тоже дела идут неплохо...$B$BПравда, торговцев у нас тут прибавилось, а пожертвований на сиротский приют стало меньше: зачем отдавать даром то, что можно продать? Но ничего, мы справимся. Под "нами" я имею в виду себя и своего мужа, конечно. Он сейчас в Стальгорне, пытается заручиться помощью тамошних жителей...', 0);

-- Add ruRU offer rewards for quest 1644
-- https://ru.tbc.wowhead.com/quest=1644/фолиант-божественности
SET @ID := 1644;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ах, $N, благодарю, благодарю тебя!$B$BДетишки так рады будут, да и у меня будет побольше времени на них. Надеюсь, теперь Джон сможет возвратиться поскорее.$B$BПрими мою искреннюю признательность, $N. Я всегда верила, что в сердцах людей есть место милосердию. Да пребудет с тобой Извечный Свет.', 0);

-- Add ruRU offer rewards for quest 1645
-- https://ru.tbc.wowhead.com/quest=1645/фолиант-божественности
SET @ID := 1645;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Приятно встретить тебя, $N. Я направляю паладинов на путь высших добродетелей, когда они посвящают себя Свету и защите Азерота от Плети и прочих бед.$B$BПришла пора сделать первый шаг по пути истинных добродетелей. Если ты принимаешь этот путь, я дам тебе Фолиант Божественности. Изучая его, ты узнаешь кое-что о Свете и о том, что тебя ждет. Если ты это поймешь и окажешься способным $Gучеником:ученицей;, то откроешь путь к великим возможностям.', 0);

-- Add ruRU offer rewards for quest 1646
-- https://wowroad.info/goha.ru?quest=1646
SET @ID := 1646;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'С возвращением, $N. Надеюсь, ты $Gнашел:нашла; время на прочтение книги?$B$BТогда ты $Gдолжен:должна; быть $Gготов:готова; к испытанию. Есть задания, которые необходимо сделать по всему нашему городу и на наших землях; акты сострадания и понимания; люди, которые нуждаются в помощи; существа, которых необходимо убить.$B$BДоказав что у тебя есть терпение, особенно в помощи людям, которые менее удачливы, ты докажешь, что ты слуга Света.', 0);

-- Add ruRU offer rewards for quest 1647
-- https://ru.tbc.wowhead.com/quest=1647/фолиант-божественности
SET @ID := 1647;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'СИРОТСКИЙ ПРИЮТ ШТОРМ... о, простите, я вовсе не хотел кричать на вас, сударь.$B$BМеня зовут Джон Тернер. Как поживаете?$B$BРад, искренне рад слышать, что у вас все хорошо. А у меня был трудный день, я тоскую по жене, но такова цена, которую приходится платить, чтобы накормить голодные рты и одеть нагих.', 0);

-- Add ruRU offer rewards for quest 1648
-- https://wowroad.info/goha.ru?quest=1648
SET @ID := 1648;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это так прекрасно с вашей стороны, $N. Снова большое вам спасибо.$B$BВы благородный человек, что так помогли мне. Не удивительно, что вы избрали путь Света. Хотел бы я, чтобы был какой-либо способ отплатить вам за все, что вы сделали... что? Это наименьшее что вы могли сделать? Видите? Это как раз то, о чем я говорю, $N, вы благородны до самого конца.$B$BБерегите себя, и да охранит вас Свет в ваших путешествиях.', 0);

-- Add ruRU offer rewards for quest 1657
-- https://ru.tbc.wowhead.com/quest=1657/чем-пахнет-в-южнобережье
SET @ID := 1657;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, отличная работа! Надеюсь, Альянс задохнётся от нашего подарочка, как мы задыхались от гнёта Плети!$B$BТы правильно $Gуловил:уловила; идею Тыквовина, $N, и за это я благодарю тебя. В добавок, позволь поделиться с тобой некоторыми угощениями Тыквовина. Думаю, ты найдёшь их просто потрясающими!', 0);

-- Add ruRU offer rewards for quest 1661
-- https://ru.tbc.wowhead.com/quest=1661/фолиант-благородства
SET @ID := 1661;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поздравляю! Да пребудет с тобой Свет!', 0);

-- Add ruRU offer rewards for quest 1683
-- https://wowroad.info/goha.ru?quest=1683
SET @ID := 1683;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно сделано, $N. Как приятно знать, что Ворлус побежден и наш лунный колодец очищен. Приятно видеть юных воинов, стремящихся защитить от порчи наш любимый Тельдрассил.$B$BТеперь, давай начнем обучение...', 0);

-- Add ruRU offer rewards for quest 1684
-- https://wowroad.info/goha.ru?quest=1684
SET @ID := 1684;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Приветствую, $N. Говорят, что ты подаешь надежды. Но надо еще убедиться есть ли у тебя сила воли, необходимая выбравшему путь воина.', 0);

-- Add ruRU offer rewards for quest 1685
-- https://ru.tbc.wowhead.com/quest=1685/приглашение-гакина
SET @ID := 1685;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наконец-то ты здесь. Мне следовало послать за тобой кого-нибудь более расторопного, чем Ремен.$B$BНу, неважно.$B$BКогда у тебя было последнее занятие? Слишком давно, слишком... А ты знаешь, что у плохо обученного чернокнижника мало шансов сохранить голову на плечах?', 0);

-- Add ruRU offer rewards for quest 1686
-- https://wowroad.info/goha.ru?quest=1686
SET @ID := 1686;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Браво, $N.$B$BТы $Gдал:дала; Тени Элуры так долго ожидаемый мир, и мы используем этот элунит чтобы сделать тебе оружие.', 0);

-- Add ruRU offer rewards for quest 1688
-- https://ru.tbc.wowhead.com/quest=1688/сурена-каледон
SET @ID := 1688;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Сурена была талантлива, но не настолько, чтобы овладеть чарами самостоятельно. Печально видеть, как погибают молодые и талантливые, но иногда без этого нельзя.$B$BНадеюсь, усилия, вложенные в тебя, прахом не пойдут...', 0);

-- Add ruRU offer rewards for quest 1689
-- https://ru.tbc.wowhead.com/quest=1689/связывание
SET @ID := 1689;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось даже больше, чем я ожидал, $N. На это я и надеялся. Теперь ты можешь научиться управлять покоренным тобой демоном. Он станет твоим помощником в предстоящих испытаниях. Сейчас мне нечему больше учить тебя, но я уверен, что мы с тобой, $N, еще увидимся...', 0);

-- Add ruRU offer rewards for quest 1692
-- https://ru.tbc.wowhead.com/quest=1692/кузнец-матиль
SET @ID := 1692;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, элунитовая руда. Работать с этим металлом – одно удовольствие, ведь он благословлен самой богиней Элуной. Выковать элунитовое оружие – великая честь.$B$BПодожди, я сейчас примусь за работу...', 0);

-- Add ruRU offer rewards for quest 1693
-- https://ru.tbc.wowhead.com/quest=1693/оружие-из-элунита
SET @ID := 1693;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это оружие я выковал из принесенного тобой элунита. Можешь взять себе любое.$B$BБольшое спасибо. Работать с элунитом – не только удовольствие, но и великая честь.', 0);

-- Add ruRU offer rewards for quest 1700
-- https://ru.tbc.wowhead.com/quest=1700/гриманд-элмор
SET @ID := 1700;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это написал Фьюрен? Как он смел! Да я его всему сам научил! Яйца курицу не учат! Нахал!$B$BХм-м-м... Но в этих записях что-то есть... Надо попробовать...', 0);

-- Add ruRU offer rewards for quest 1701
-- https://ru.tbc.wowhead.com/quest=1701/закаленный-доспех
SET @ID := 1701;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось добыть все необходимое? Вот это да! Я опасался, что химеры слопают тебя с потрохами!$B$BЧто ж, займемся доспехами...', 0);

-- Add ruRU offer rewards for quest 1703
-- https://wowroad.info/goha.ru?quest=1703
SET @ID := 1703;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это интересно, очень интересно. Мой коллега Фьюрен, сделал грандиозное открытие.$B$BСпасибо, $N. Это будет честью для меня, применять новые технологии к моим разработкам.', 0);

-- Add ruRU offer rewards for quest 1704
-- https://ru.tbc.wowhead.com/quest=1704/клацморт-гайкокрут
SET @ID := 1704;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну и ну! Поразительные записи мне прислали! Больше того... Они ошеломляющие и невероятные, я едва на ногах стою от восторга!$B$BФьюрен совершил прорыв в кузнечном деле! Да-да, самый настоящий прорыв! Мне не терпится испробовать новую технологию!', 0);

-- Add ruRU offer rewards for quest 1705
-- https://ru.tbc.wowhead.com/quest=1705/пылающая-кровь
SET @ID := 1705;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Недурно! А теперь, прошу прощения, мне тоже надо поработать...', 0);

-- Add ruRU offer rewards for quest 1706
-- https://ru.tbc.wowhead.com/quest=1706/доспехи-гриманда
SET @ID := 1706;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Глазам своим не верю! Технология Фьюрена оказалась удачной, и этот доспех способен выдержать серьезную нагрузку.$B$BДержи, $N. И огромное тебе спасибо. Если бы ты не $Gпринес:принесла; мне все необходимые материалы, я бы так и не поверил в открытие Фьюрина.', 0);

-- Add ruRU offer rewards for quest 1708
-- https://ru.tbc.wowhead.com/quest=1708/железный-коралл
SET @ID := 1708;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот, то что нужно! $GМолодец:Умница;! А теперь дай-ка я их расплавлю и расплющу. Попробую совместить технологию Фьюрена с моей, и посмотрим что из этого выйдет!$B$BНу-ну, я предчувствую, что доспехи получатся очень-очень-очень прочные!', 0);

-- Add ruRU offer rewards for quest 1709
-- https://ru.tbc.wowhead.com/quest=1709/творение-клацморта
SET @ID := 1709;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот твои доспехи, $N. Идея Фьюрена отлично сработала. Идеально! Чудесно, если правду сказать!$B$BПо этой броне можно осадные орудия прокатить, и она сохранит форму!', 0);

-- Add ruRU offer rewards for quest 1710
-- https://wowroad.info/goha.ru?quest=1710
SET @ID := 1710;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ах, спасибо тебе! Это прекрасно подойдет!$B$BЯ начну создавать броню немедленно.', 0);

-- Add ruRU offer rewards for quest 1711
-- https://wowroad.info/goha.ru?quest=1711
SET @ID := 1711;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я закончил с твоей броней и я доволен. Новый способ Фьюрена прекрасно сочетается с моим и я уверен,что эта броня будет довольно устойчивой.$B$BСпасибо,$N.И пусть она сослужит тебе хорошую службу в будущих сражениях.', 0);

-- Add ruRU offer rewards for quest 1712
-- https://ru.tbc.wowhead.com/quest=1712/циклониан
SET @ID := 1712;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gсумел:сумела; собрать все необходимое для заклинания призыва, доказав тем самым свою силу и ловкость. Но следующий шаг будет гораздо опаснее.$B$BБудем надеяться, что сила тебя не покинет.', 0);

-- Add ruRU offer rewards for quest 1713
-- https://ru.tbc.wowhead.com/quest=1713/призыв
SET @ID := 1713;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gсправился:справилась;! Циклониан повержен, а у тебя в руках сердце Вихря!', 0);

-- Add ruRU offer rewards for quest 1714
-- https://ru.tbc.wowhead.com/quest=1714/субстанция-изгнанников
SET @ID := 1714;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Обереги медленно опускаются на дно котла…$B$BИз глубины поднимается большой пузырь воздуха, лопается и…$B$B... на поверхности оказывается оплавленный камень.', 0);

-- Add ruRU offer rewards for quest 1715
-- https://ru.tbc.wowhead.com/quest=1715/таверна-забитый-ягненок
SET @ID := 1715;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Так тебя послал Злобноверт? Нет, пора бы уже этим стальгорнским растяпам как-то разобраться с ситуацией. Штормград не резиновый, и наставников тут сколько есть, и не больше. Если сюда повалит народ, то рано или поздно мы привлечем к себе внимание.', 0);

-- Add ruRU offer rewards for quest 1716
-- https://ru.tbc.wowhead.com/quest=1716/пожирательница-душ
SET @ID := 1716;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N, как вы добрались? Вы проделали долгий путь, чтобы поговорить со мной. Но не бойтесь: я знаю, зачем Гакин прислал вас. Это было мудро с его стороны, потому что я могу вам помочь.', 0);

-- Add ruRU offer rewards for quest 1717
-- https://wowroad.info/goha.ru?quest=1717
SET @ID := 1717;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хорошо, что кто-то, наконец, поймал тебя, $N. Я уже опасался худшего. В тебя вложено слишком много и было бы жалко тебя потерять.$B$BМы еще поговорим на эту тему позднее.. Твоя тренировка более важна в данный момент.', 0);

-- Add ruRU offer rewards for quest 1718
-- https://ru.tbc.wowhead.com/quest=1718/островитянин
SET @ID := 1718;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, воин. Хорошо, что тебе удалось добраться до Острова Битв. Надеюсь, он тебе нравится...', 0);

-- Add ruRU offer rewards for quest 1719
-- https://ru.tbc.wowhead.com/quest=1719/побоище
SET @ID := 1719;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Молодец, $N. Ты $Gпрошел:прошла; испытание Побоищем!$B$BТы могучий воин, и учить тебя – великая честь...', 0);

-- Add ruRU offer rewards for quest 1738
-- https://ru.tbc.wowhead.com/quest=1738/сердцедрево
SET @ID := 1738;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, сердцедрево нам подойдет. Дай-ка я немного обработаю древесину...$B$BТакар – настоящий кладезь премудростей; с таким не пропадешь, правда? Если б я только мог убедить его вернуться к цивилизации...', 0);

-- Add ruRU offer rewards for quest 1739
-- https://ru.tbc.wowhead.com/quest=1739/связывание
SET @ID := 1739;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Неплохо, $N, неплохо... Я не ошибся, когда решил обучать тебя. Твои успехи меня не разочаровывают.$B$BПора научить тебя обращению с только что подчиненным суккубом. Только не забывай про осторожность!', 0);

-- Add ruRU offer rewards for quest 1758
-- https://ru.tbc.wowhead.com/quest=1758/фолиант-заговора
SET @ID := 1758;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Фолиант Заговора? Хм-м... Знакомое название. Я его никогда не видел – а уж поверьте, я помню все прочитанные книги.$B$BХм…$B$BА, да! Я видел ссылки на этот фолиант в библиотечных каталогах.', 0);

-- Add ruRU offer rewards for quest 1778
-- https://ru.tbc.wowhead.com/quest=1778/фолиант-божественности
SET @ID := 1778;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Итак, ты быстро $Gвернулся:вернулась;, а? И чего же ты $Gдостиг:достигла; за это время?$B$BИтак, ты $Gпомог:помогла; достойному делу? Возможно ты уже $Gзаслужил:заслужила; уважение граждан Азерота. Скажи мне кому ты $Gпомог:помогла; – и я скажу кто ты…$B$BУдивительно, $N , ты действительно следуешь пути Света.$B$BТакая жертва будет обязательно вознаграждена в свое время..', 0);

-- Add ruRU offer rewards for quest 1779
-- https://ru.tbc.wowhead.com/quest=1779/фолиант-божественности
SET @ID := 1779;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '*кашляет*$B$BДоброго тебе здравия, |3-6($C). Не волнуйся о моих ранах, добрый жрец сумеет вылечить Майридона. Так что сила твоего знака Жизни пока мне не нужна.$B$BЗначит, моя женушка тебя послала потолковать со мной, да? Славно, славно. У меня найдется времечко поговорить с тобой, я расскажу тебе в точности, что произошло с Майридоном и его лучшим другом Нармом, паладином вроде тебя.', 0);

-- Add ruRU offer rewards for quest 1780
-- https://ru.tbc.wowhead.com/quest=1780/фолиант-божественности
SET @ID := 1780;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты уже здесь, $N? Однако, странствия заняли у тебя не так много времени, как я полагал. И что же тебе удалось свершить за время, проведенное вдали от Храма? Может быть, тебе довелось сражаться за справедливость? Или удалось постичь смысл милосердия? Или помочь кому-либо из нуждающихся жителей Азерота? Расскажи мне все...$B$BЧто ж, $N, это производит впечатление. Поверь, это поистине поступки того, кто следует путем Света и ставит благо других выше своего собственного.$B$BРано или поздно такое самопожертвование всегда вознаграждается.', 0);

-- Add ruRU offer rewards for quest 1781
-- https://ru.tbc.wowhead.com/quest=1781/фолиант-божественности
SET @ID := 1781;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '*кашляет*$B$BЯ рад встрече с тобой, |3-6($C). Не обращай внимания на мои раны: добрые служители Света смогут обо всем позаботиться. Сила знака Жизни, которого ты держишь в руках, мне без надобности... по крайней мере пока.$B$BЗначит, Даториан послал тебя поговорить со мной, да? Что ж, это правильно. Я тебе расскажу, что случилось со мной и моим другом Хензом. Если нам повезет и тебе хватит сил и умения, ты еще сможешь всех нас спасти...', 0);

-- Add ruRU offer rewards for quest 1782
-- https://ru.tbc.wowhead.com/quest=1782/доспехи-фьюрена
SET @ID := 1782;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот твои доспехи, $N. Они выдержат любой удар, не будь я Фьюрен Длиннобород!$B$BИ спасибо большое. Я многому научился, работая с принесенными тобой материалами. Думаю, в один прекрасный день я совершу новое открытие!$B$BА результаты этого я отправлю другим кузнецам Альянса.$B$BЯ скажу им, что ты мне очень $Gпомог:помогла;, может быть, они тоже решат отблагодарить тебя.', 0);

-- Add ruRU offer rewards for quest 1783
-- https://ru.tbc.wowhead.com/quest=1783/фолиант-божественности
SET @ID := 1783;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не знаю, как мне отблагодарить тебя, $Gбрат:сестра;!$B$BВидать, тебя прислали мне в подмогу Тиза с Майридоном, раз на тебе знак Жизни.$B$BДа, это правда, я пал в бою с дворфами Черного Железа, пытаясь получить одну из их бумаг. Я довольно долго продержался и дал Майридону уйти, но я почти уже погрузился в Свет, когда ты $Gпоявился:появилась;. То, что тебе хватило мощи воспользоваться знаком, очень многое значит, но мы поговорим об этом позже.', 0);

-- Add ruRU offer rewards for quest 1784
-- https://wowroad.info/goha.ru?quest=1784
SET @ID := 1784;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хаха! Тебе удалось! Ты $Gспас:спасла; Нарма и $Gнашел:нашла; доказательство, которое нужно моей жене, чтобы показать его в совете. Ты просто единственное благословление Света, если я в них хоть что-то понимаю... не считая, конечно, моей жены.$B$BПрими снова мою благодарность, $N.', 0);

-- Add ruRU offer rewards for quest 1785
-- https://ru.tbc.wowhead.com/quest=1785/фолиант-божественности
SET @ID := 1785;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Сегодня ты $Gоказал:оказала; большую услугу Стальгорну, $N. Я горда, что ты среди нас, и если ты $Gготов:готова;, я хотела бы благословить тебя этим свитком. Знак Жизни подействовал бы только в руках паладина, готового принять одну из самых великих благостей Света, – силу возвращать умерших к жизни.$B$BЯ научу тебя возрождать к жизни твоих соратников. Используй это умение мудро, $N, и прими благодарность от меня, моего мужа и всего Стальгорна.', 0);

-- Add ruRU offer rewards for quest 1786
-- https://ru.tbc.wowhead.com/quest=1786/фолиант-божественности
SET @ID := 1786;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прими мою благодарность, $Gбрат:сестра;.$B$BВ твоих руках я вижу знак Жизни – тебя послал Даториан или Газин.$B$BМы с Газином пытались похитить планы Братства Справедливости, но на нас напали их чародеи. Мне удалось продержаться достаточно долго для того, чтобы Газин успел скрыться, но в конце концов я был побежден...$B$BНо тебе удалось вернуть меня – а далеко не всем дана способность управлять знаком Жизни, $N, можешь мне поверить. Это свидетельство крепости твоей веры...', 0);

-- Add ruRU offer rewards for quest 1787
-- https://ru.tbc.wowhead.com/quest=1787/фолиант-божественности
SET @ID := 1787;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Тебе удалось спасти Хенза и выполнить задание. Теперь я знаю: воистину, Свет озаряет твой путь, $N!', 0);

-- Add ruRU offer rewards for quest 1788
-- https://ru.tbc.wowhead.com/quest=1788/фолиант-божественности
SET @ID := 1788;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что ж, $N, полагаю, ты можешь гордиться своими свершениями.$B$BСкажу больше: ты можешь также гордиться своими способностями. Далеко не каждый может использовать силу, которой наделен знак Жизни. Если в твоих силах призвать исцеляющую силу Света, ты $Gдостоин:достойна; того, чтобы принять величайший дар паладинов, – дар воскрешения.$B$BТы сможешь возвращать к жизни павших спутников так же, как $Gвернул:вернула; к жизни Хенза.$B$BГорний Свет озарил тебя, $N, открой же ему душу.', 0);

-- Add ruRU offer rewards for quest 1789
-- https://wowroad.info/goha.ru?quest=1789
SET @ID := 1789;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поспеши, $N, еще одна жизнь висит на волоске.$B$BЕсли по каким-то причинам тебе не удастся спасти Майридона и Нарма, возвращайся ко мне, и дам тебе еще один символ Жизни.$B$BНе путай мою помощь с благотворительностью, тебе нужно доказать, что ты достойный |3-6($C) и отказ, может отразиться в будущем.', 0);

-- Add ruRU offer rewards for quest 1790
-- https://ru.tbc.wowhead.com/quest=1790/знак-жизни
SET @ID := 1790;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поспеши, $N! Слишком много жизней зависит от твоего успеха или неудачи.$B$BЕсли ты не сумеешь помочь Газину и Хензу, возвращайся: я дам тебе новый знак Жизни.$B$BНе думай, что я помогаю тебе просто так, нет: тебе, как и всякому другому паладину, нужно доказать, что ты достоин своего звания. Постоянные неудачи – не лучшая рекомендация...', 0);

-- Add ruRU offer rewards for quest 1791
-- https://ru.tbc.wowhead.com/quest=1791/ветростраж
SET @ID := 1791;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе пришлось проделать долгий путь, $юный:юная $C. Как у тебя горят глаза! Тебе ведь нужно мощное оружие?$B$BЯ помогу тебе... в обмен на твою помощь.', 0);

-- Add ruRU offer rewards for quest 1792
-- https://ru.tbc.wowhead.com/quest=1792/оружие-смерча
SET @ID := 1792;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'У меня есть сердце Вихря, и я могу подобрать ему вместилище по твоему выбору.$B$BВозьми любое оружие, и знай, что его сила – сила Циклониана.', 0);

-- Add ruRU offer rewards for quest 1793
-- https://ru.tbc.wowhead.com/quest=1793/фолиант-доблести
SET @ID := 1793;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Теперь доказано, что ты – приверженец сил Света, $N, но времена наступают все более опасные, и поэтому важно знать, какая сила скрывается в твоем сердце. Когда демоны, драконы или какое другое зло ступят на нашу землю, тогда и подвергнется испытанию твой дух. Достанет ли у тебя сил?$B$BХрабрость в любой ситуации – такая же неотъемлемая часть сущности паладина, как Свет, доспех и оружие. Необходимость защищать слабых и не терять веры – вот еще два урока, которые ты $Gдолжен:должна; усвоить, пока проходишь обучение в Соборе Света.', 0);

-- Add ruRU offer rewards for quest 1795
-- https://ru.tbc.wowhead.com/quest=1795/связывание
SET @ID := 1795;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Впечатляюще, $N. Когда я сражался с охотником скверны, то едва выжил. Предчувствую, что ты станешь одним из сильнейших чернокнижников нашей эры.', 0);

-- Add ruRU offer rewards for quest 1798
-- https://ru.tbc.wowhead.com/quest=1798/на-поиски-страхада
SET @ID := 1798;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N? Ах да, конечно. Наше новое чудо. Но, боюсь, настоящее чудо вряд ли успеет стать легендой при жизни.$B$BВпрочем, неважно – ты здесь для того, чтобы пройти обучение, а не слушать, как я шучу сам с собой.', 0);
