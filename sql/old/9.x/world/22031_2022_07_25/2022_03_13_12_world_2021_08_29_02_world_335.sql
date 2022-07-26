-- Add ruRU offer rewards for quest 526
-- https://wowroad.info/goha.ru?quest=526
SET @ID := 526;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, ты $Gнашел:нашла; их! Теперь давай эту светосталь скуем в что-нибудь полезное?', 0);

-- Add ruRU offer rewards for quest 615
-- https://wowroad.info/goha.ru?quest=615
SET @ID := 615;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет, привет, $N. Капитан сказал мне, что ты будешь бороться с Неголашем, да?', 0);

-- Add ruRU offer rewards for quest 616
-- https://ru.classic.wowhead.com/quest=616/остров-духов
SET @ID := 616;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Интересно. Кажется, я недавно читал книгу, в которой говорилось о чем-то в этом духе…$B$BА, разумеется, легенды троллей. Если Кразек говорит правду, то вскоре к моей коллекции древних артефактов и реликвий добавится Камень Приливов.', 0);

-- Add ruRU offer rewards for quest 618
-- https://ru.classic.wowhead.com/quest=618/бой-с-неголашем
SET @ID := 618;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gзабрал:забрала; саблю у Неголаша! Я не верил, что мне повезет, $N! Встретив тебя, моя удача вернулась, без сомнения!$B$BСпасибо! И если я когда-нибудь заполучу новый корабль, и ты захочешь прокатиться, то ты будешь на нем почетным гостем.', 0);

-- Add ruRU offer rewards for quest 619
-- https://ru.classic.wowhead.com/quest=619/приманка-для-неголаша
SET @ID := 619;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы нагружаете лодку едой и выпивкой...', 0);

-- Add ruRU offer rewards for quest 620
-- https://wowroad.info/goha.ru?quest=620
SET @ID := 620;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет. У тебя есть ко мне дело?', 0);

-- Add ruRU offer rewards for quest 637
-- https://ru.classic.wowhead.com/quest=637/письмо-салли-балу
SET @ID := 637;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Неужели ты $Gвидел:видела; моего Салли подо льдом? Прошу, скажи, что это не так!$B$BДай-ка я прочитаю, что он написал...', 0);

-- Add ruRU offer rewards for quest 638
-- https://ru.classic.wowhead.com/quest=638/троллебой
SET @ID := 638;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Как дела, $C? Вол\'джин дал нам непростое задание, и если ты хочешь предложить свою помощь, мы с радостью ее примем.', 0);

-- Add ruRU offer rewards for quest 649
-- https://ru.classic.wowhead.com/quest=649/за-медовухой
SET @ID := 649;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, это насчет медовухи, которая нужна папаше? Он собирается торговать ею в таверне. За настоящую "Медовую зыбь" можно выручить много денег... Я знаю того, кто может ее добыть. Он живет во Внутренних землях. Но вот какая штука: он того... эльф он. Высший.$B$BНо ты не бойся, он хороший высший эльф, он не из Альянса. То есть он хороший, как выпьет. А это дело он любит. Очень любит.', 0);

-- Add ruRU offer rewards for quest 650
-- https://ru.classic.wowhead.com/quest=650/за-медовухой
SET @ID := 650;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, ты знаешь Мальтона? Он мой старинный собутыльник! Понимаешь, я нашел средство, преодолевающее все искусственные границы и условности. Это – выпивка! Если бы разумные существа выпивали, вместо того чтобы воевать, мир сделался бы куда лучше и чище.$B$BВпрочем, боюсь, ты здесь не затем, чтобы слушать лекции о благословенных свойствах алкоголя.', 0);

-- Add ruRU offer rewards for quest 654
-- https://ru.classic.wowhead.com/quest=654/полевые-испытания-в-танарисе
SET @ID := 654;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну ладно, на удаление источника энергии мне понадобится пара секунд. После этого можешь делать все, что захочешь, не боясь потерять данные.', 0);

-- Add ruRU offer rewards for quest 665
-- https://ru.classic.wowhead.com/quest=665/утонувшее-сокровище
SET @ID := 665;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Теперь очки работают превосходно! Отличная работа, $N.', 0);

-- Add ruRU offer rewards for quest 683
-- https://ru.classic.wowhead.com/quest=683/просьба-сары-балу
SET @ID := 683;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Подожите минутку, я прочту письмо...', 0);

-- Add ruRU offer rewards for quest 686
-- https://ru.classic.wowhead.com/quest=686/королевские-почести
SET @ID := 686;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Значит, вас послал лично король Магни Бронзобород?$B$BПодумать только! Стало быть, дело важное!', 0);

-- Add ruRU offer rewards for quest 689
-- https://ru.classic.wowhead.com/quest=689/королевские-почести
SET @ID := 689;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Замечательно! Лучше, чем я представить мог!$B$BА воображение у меня, между прочим...', 0);

-- Add ruRU offer rewards for quest 698
-- https://ru.classic.wowhead.com/quest=698/нехватка-ресурсов
SET @ID := 698;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! Свежее мясо к ужину! Спасибо, $N.$B$BНынешний вечерок будет куда приятнее прошлого – мы наедимся досыта.$B$BПускай Дар – орк на морду ужасный, зато добрый внутри.', 0);

-- Add ruRU offer rewards for quest 699
-- https://ru.classic.wowhead.com/quest=699/нехватка-ресурсов
SET @ID := 699;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Рад видеть тебя живым и здоровым, $N.$B$BЭти когти нам весьма пригодятся, ведь чем больше оружия у нас будет в момент атаки, тем лучше.$B$BНачну работу над твоим экземпляром как можно скорее, много времени это не займет, я уже наловчился его изготавливать.', 0);

-- Add ruRU offer rewards for quest 700
-- https://ru.classic.wowhead.com/quest=700/королевские-почести
SET @ID := 700;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Гранит – такая малость по сравнению с жизнью достойного дворфа. Но ни один дворф в этом мире не вечен.$B$BБудем надеяться, что этот мемориал станет напоминанием будущим поколениям великого Азерота. Мы никогда не забудем, что за них отдали жизнь отважные солдаты вроде Салли Баллу.', 0);

-- Add ruRU offer rewards for quest 721
-- https://ru.tbc.wowhead.com/quest=721/предвестник-надежды
SET @ID := 721;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, я так ослабел... <кашляет> Подойди ко мне, $C?$B$BТебя прислал Рейдол? Клянусь Мурадином, парень вовсе не так туп, как кажется.<кашляет>', 0);

-- Add ruRU offer rewards for quest 722
-- https://ru.tbc.wowhead.com/quest=722/амулет-тайн
SET @ID := 722;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ха!<кхе, кхе>$B$BЯ знал, что ты справишься! <сморкается> Отличная работа, $N.<кашляет>', 0);

-- Add ruRU offer rewards for quest 723
-- https://ru.tbc.wowhead.com/quest=723/клятва-верности
SET @ID := 723;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Амулет Тяжелоступа! Если раньше в моем сердце еще теплилась надежда, что он жив, то теперь ничто не снимет с моей души этот камень. Этот амулет – дело всей его жизни. Нельзя допустить, чтобы его смерть была напрасной!', 0);

-- Add ruRU offer rewards for quest 724
-- https://ru.tbc.wowhead.com/quest=724/клятва-верности
SET @ID := 724;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, а вот это совсем другой разговор! Возможно, ты еще не $Gосознал:осознала; всей серьезности происходящего, ведь так?$B$BМы оплачем Тяжелоступа позже.$B$BСейчас я объясню тебе, почему этот амулет так важен.', 0);

-- Add ruRU offer rewards for quest 725
-- https://ru.tbc.wowhead.com/quest=725/слухи-об-угрозе
SET @ID := 725;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, весточка от историка Карника. Прекрасно.$B$BДля него у меня всегда найдется минутка.$B$B<Советник Белграм разворачивает записку и погружается в чтение.>', 0);

-- Add ruRU offer rewards for quest 726
-- https://ru.tbc.wowhead.com/quest=726/слухи-об-угрозе
SET @ID := 726;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты действуешь по этому делу с поспешностью, которая сделала бы честь и королю, $N!$B$BХорошо. Я знаю, что делать с Кузней Теней.$B$BИх силы в Ульдамане будут рассеяны, если мы поразим их в самое сердце – ударим по крепости Ангор.', 0);

-- Add ruRU offer rewards for quest 728
-- https://ru.tbc.wowhead.com/quest=728/в-подгород-за-книгой-йагина
SET @ID := 728;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Будь $Gосторожен:осторожена;, $C. Многие на этом свете сомневаются в праведности наших дел. И многие из них сделали бы все возможное, чтобы уничтожить нас!$B$BТы $Gдолжен:должна; всегда сохранять бдительность, осторожность и терпение...', 0);

-- Add ruRU offer rewards for quest 730
-- https://ru.tbc.wowhead.com/quest=730/неприятности-на-темных-берегах
SET @ID := 730;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Как же здорово, что главный археолог Седой Ус прислал вас...', 0);

-- Add ruRU offer rewards for quest 736
-- https://ru.tbc.wowhead.com/quest=736/звезда-рука-и-сердце
SET @ID := 736;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поразительно! Ты обладаешь или великим искусством, или удачей, иначе тебе не удалось бы добыть эти реликвии. Так или иначе, ты очень $Gпомог:помогла; нам.', 0);

-- Add ruRU offer rewards for quest 762
-- https://ru.tbc.wowhead.com/quest=762/посланник-зла
SET @ID := 762;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N, твоя преданность Стальгорну и народу дворфов не будет забыта. Благодарю тебя за помощь.$B$BЯ извещу историка Карника о твоих успехах письмом и отправлю рабочих в Бесплодные земли, чтобы они возобновили работы на раскопках как можно скорее. Еще раз благодарю тебя.$B$BПрежде чем ты уйдешь, выполни еще одну просьбу от имени короля Бронзоборода.', 0);

-- Add ruRU offer rewards for quest 768
-- https://ru.tbc.wowhead.com/quest=768/добывание-шкур
SET @ID := 768;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ах, какая кожа! Из нее выйдут отличные товары.$B$BВот, Ахахаха. Возьми в знак благодарности...', 0);

-- Add ruRU offer rewards for quest 769
-- https://ru.tbc.wowhead.com/quest=769/сумка-из-шкуры-кодо
SET @ID := 769;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро. Спасибо, $N. Мое сердце распирает от гордости, когда я вижу молодежь, взыскующую мастерства в кожевничестве!', 0);

-- Add ruRU offer rewards for quest 782
-- https://ru.tbc.wowhead.com/quest=782/разорванные-союзы
SET @ID := 782;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Теперь, когда от То\'груна остался лишь голый скелет, обглоданный стервятниками и выбеленный солнцем и ветром, огры, лишенные главаря, рассеются по пустыне. Так малая победа принесла с собой великую!$B$BЗнак Земли снова у нас, и мы сможем отомкнуть узилище черных драконов в долине Летлор. Мы спасем их от уготованного им вечного заключения, хотя и свершим их судьбу!', 0);

-- Add ruRU offer rewards for quest 793
-- https://ru.tbc.wowhead.com/quest=793/разорванные-союзы
SET @ID := 793;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Черные драконы вступают в союз с отступниками – орками Черной Горы. И тех, и других должно вернуть в лоно Орды или уничтожить. Теперь, когда мы покончили с Гематусом и Чернохлыстом, мы можем обратить взор на запад, на пик Черной Горы.', 0);

-- Add ruRU offer rewards for quest 795
-- https://ru.tbc.wowhead.com/quest=795/печать-земли
SET @ID := 795;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Как только рунные камни оказались в предназначенных для них нишах, земля задрожала и печать разрушилась.', 0);

-- Add ruRU offer rewards for quest 832
-- https://ru.tbc.wowhead.com/quest=832/пылающие-тени
SET @ID := 832;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Нииру разглядывает Око Пылающей Тени.>$B$BЛюбопытно. Так ты говоришь, голос упоминал мое имя? Я, конечно, известен как непримиримый враг противников нашего вождя, но все же странно, что голос назвал именно меня. Тем более странно, что название секты, у членов которой ты нашел этот амулет, так похоже на мою фамилию.$B$BНадо изучить эту подвеску. Изучить и поразмыслить над тем, что значит это сообщение.$B$BСпасибо, $N, что сообщил мне об этом. Ты оказал своему народу серьезную услугу.', 0);

-- Add ruRU offer rewards for quest 836
-- https://ru.tbc.wowhead.com/quest=836/спасти-кпх-9-hl
SET @ID := 836;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, да ты просто $Gспас:спасла; моего робота OOX-09/HL! Я прям даже не знаю, как тебя благодарить! Моих автономных роботов еще совершенствовать и совершенствовать, но ты $Gизбавил:избавила; меня от многих лишних часов работы, а также от расходов!$B$BПожалуйста, выбери себе что-нибудь в награду. Спасибо тебе еще раз, $N, я и мои роботы навеки у тебя в долгу.', 0);

-- Add ruRU offer rewards for quest 838
-- https://ru.tbc.wowhead.com/quest=838/некроситет
SET @ID := 838;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, $C. Верховный палач упоминал, что тебе можно доверить тайну ключа. В последнее время я посвятил большую часть времени изучению Некроситета, и, кажется, знаю способ, как добыть ключ, позволяющий отомкнуть двери в любой момент.$B$BДело, как всегда, будет непростым. Но судя по всему, тебя такими словами не напугать.', 0);

-- Add ruRU offer rewards for quest 841
-- https://ru.tbc.wowhead.com/quest=841/еще-один-источник-энергии
SET @ID := 841;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ладно, вот еще один источник энергии. Очень советую применить его по назначению, если не хочешь добыть для меня еще десять мехов воды.', 0);

-- Add ruRU offer rewards for quest 864
-- https://ru.tbc.wowhead.com/quest=864/возвращение-к-аптекарю-зинг
SET @ID := 864;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я немедленно займусь анализом данных. Быть может, безумие Чанна обернется моей гениальностью.$B$BЧто до тебя... Ты мне $Gполезен:полезна;, а я хорошо обращаюсь с полезными существами. Прими эту вещь, эти монетки, а в придачу к ним – мою благодарность.$B$BЗаглядывай время от времени – думаю, что мы еще поработаем вместе.', 0);

-- Add ruRU offer rewards for quest 866
-- https://ru.tbc.wowhead.com/quest=866/образцы-корней
SET @ID := 866;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да-да, замечательно! Из этих корней я выращу травы и смогу изучить их. Надеюсь отыскать в них новые свойства. Скрытые ценные свойства...$B$BИ не беспокойся – ты узнаешь об этом $Gпервым:первой;. Потому что в таком случае мне понадобится много корней!', 0);

-- Add ruRU offer rewards for quest 886
-- https://ru.tbc.wowhead.com/quest=886/оазисы-степей
SET @ID := 886;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Мои собратья в Громовом Утесе мудро поступили, прислав тебя сюда, юный $C. Ибо тайну Степей мне в одиночку не раскрыть.$B$BБудем надеяться, что с твоей помощью мы найдем ответ на наш вопрос.', 0);

-- Add ruRU offer rewards for quest 889
-- https://ru.tbc.wowhead.com/quest=889/дух-ветра
SET @ID := 889;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хорошо. Да ведет тебя дух Агамаггана, $R. Возвращайся, если захочешь вновь соприкоснуться с магией Агамаггана.', 0);

-- Add ruRU offer rewards for quest 897
-- https://wowroad.info/goha.ru?quest=897
SET @ID := 897;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я ничего не могу сказать о природе этого существа, так как его дух ушел. Как ты уже $Gдогадался:догадалась;, оно не из Степей. Я боюсь, что это может предвещать мрачное будущее нашему народу...$B$BНо сейчас приготовься, давай надеяться, что время раскроет тайну этого существа.', 0);
