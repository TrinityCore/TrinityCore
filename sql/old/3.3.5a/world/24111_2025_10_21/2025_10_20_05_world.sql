-- Small correction.
UPDATE item_template_locale SET Description='Основательно сделанное это оружие продолжает работать, работать и работать.' WHERE ID=30757 AND locale='ruRU';

-- I'm Saved! - Small correction.
-- https://www.wowhead.com/wotlk/quest=9897/im-saved
UPDATE quest_template_locale SET Details='Я не жадная. Могу поделиться. Главное, я спаслась от этого паршивца Ганки! С Зангартопи я притащила целую тонну шкур, так что с меня не убудет!' WHERE ID=9897 AND locale='ruRU';

-- Banro <Ammunition> - Missing title locale
-- https://www.wowhead.com/wotlk/npc=21488/banro
UPDATE creature_template_locale SET Title='Боеприпасы' WHERE entry=21488 AND locale='ruRU';

-- Tasaldan <Ammunition> - Missing title locale
-- https://www.wowhead.com/wotlk/npc=21483/tasaldan
UPDATE creature_template_locale SET Title='Боеприпасы' WHERE entry=21483 AND locale='ruRU';

-- The Ultimate Bloodsport - Small correction.
-- https://www.wowhead.com/wotlk/quest=9852/the-ultimate-bloodsport
UPDATE quest_template_locale SET Details='Клыкач – королева животного царства Награнда. Гигантская самка элекка, равных которой нет на свете!$B$BОдно её имя наводит страх, и её не зазорно бояться. Хол\'стяк, Потрошительница и Бантар – жалкие мошки по сравнению с ней. Говорят, её можно найти на отвесной скале неподалёку от Ошу\'гуна, на юго-западе отсюда. Если тебе хватит смелости, принеси мне сердце королевы элекков.$B$BУ тебя есть родные? Не хочешь написать им записку? Если ты не вернёшься... а скорее всего, так и будет... я обязательно передам её безутешным родственникам.' WHERE ID=9852 AND locale='ruRU';

-- Becoming a Mooncloth Tailor - Small correction.
-- https://www.wowhead.com/wotlk/quest=10831/becoming-a-mooncloth-tailor
UPDATE quest_offer_reward_locale SET RewardText='<Насмара осматривает ткань и вертит её в руках.>$B$BЭто очень хороший образец, $N. Из вас получится отличный портной луноткани.' WHERE ID=10831 AND locale='ruRU';

-- Killing the Crawlers - Small correction.
-- https://www.wowhead.com/wotlk/quest=10927/killing-the-crawlers
UPDATE quest_template_locale SET Details='Командир Тень Небес хочет, чтобы этот туннель был очищен от всякой пакости, и чтобы мы могли вести торговлю с Прибежищем Оребор. Я не могу оставить пост, потому поручаю эту задачу вам. Проведите в туннеле зачистку и отчитайтесь командиру Тень Небес немедленно!' WHERE ID=10927 AND locale='ruRU';

-- ...and a Time for Action - Small correction.
-- https://www.wowhead.com/wotlk/quest=10713/and-a-time-for-action
UPDATE quest_template_locale SET Details='Мы не станем сидеть, сложа руки, пока они опустошают Чащобу Рууан! Наш первый долг – защитить деревья.$B$B$C, я хочу, чтобы ты $Gотправился:отправилась; в Чащобу и $Gпередал:передала; им наше особое послание. Я хочу, чтобы ты $Gубивал:убивала; всех их лесорубов, какие только тебе попадутся на пути!$B$BЕсли они не прислушаются к гласу рассудка, может, на них подействует более агрессивный метод убеждения!' WHERE ID=10713 AND locale='ruRU';

 -- Small correction.
UPDATE quest_offer_reward_locale SET RewardText='Невероятно. Вы сами убили Рему?$B$BСудя по вашему виду – можете. Понимаете, нам нужен молодой, крепкий $C, вроде вас, чтобы помочь нам разобраться с вечной проблемой огров. Давайте уж разберёмся с ней окончательно, раз подвернулась возможность.$B$BЛадно, вы определённо заслужили ту награду, которую я назначил в том объявлении.$B$BПрошу, берите.' WHERE ID=10690 AND locale='ruRU';

-- The Den Mother- Small correction.
-- https://www.wowhead.com/wotlk/quest=10690/the-den-mother
UPDATE quest_template_locale SET Title='Шёпот Бога-ворона', Objectives='Убейте араккоа Гришны, чтобы на две минуты обрести Понимание речи Ворона. Находясь под действием этого заклятия, вы можете найти и получить пророчества в четырёх святилищах.' WHERE ID=10607 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='Это очень тревожная весть. Араккоа долгое время жили мирно. Но этот культ Ворона – ничто иное, как сборище неудачников и безумцев.$B$BНо сила их растёт, и не обращать на это внимания мы не можем. Возможно, нам ещё много придётся узнать об этом самом Вороне.' WHERE ID=10607 AND locale='ruRU';

-- What Illidan Wants, Illidan Gets... - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=10577/what-illidan-wants-illidan-gets
UPDATE quest_offer_reward_locale SET RewardText='Теперь тебе осталось только заполучить Код. Сущие пустяки, не правда ли?' WHERE ID=10577 AND locale='ruRU';

-- The Cipher of Damnation - Borak's Charge - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=10578/the-cipher-of-damnation-boraks-charge
UPDATE quest_offer_reward_locale SET RewardText='Наконец-то! Фрагмент шифра у нас в руках!\r\n\r\n<Борак кладет его в сейф.>' WHERE ID=10578 AND locale='ruRU';

-- Assisting the Consortium - Small correction. NPC Skryer says he represents the interests of the Aldor. There is a similar Aldor quest with almost the same text.
-- https://www.wowhead.com/wotlk/quest=10264/assisting-the-consortium
UPDATE quest_template_locale SET Details='Наару города Шаттрат пытаются донести до Консорциума свою точку зрения.$B$BХорошо ещё, что деловые отношения между эфириалами и эльфами крови здесь, в Пустоверти, в последнее время разладились.$B$BВ городе находится представитель Консорциума ловчий Пустоты Кай\'джи, который недавно попал в неприятности по вине шайки астральных духов-изменников. Как представитель Провидцев, я хотел бы попросить тебя помочь ему во всём, в чём только можно.' WHERE ID=10264 AND locale='ruRU';

-- Arcanist Ivrenne <Emblem of Heroism Quartermaster> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=31580/arcanist-ivrenne
UPDATE creature_template_locale SET Title='Награды за эмблемы героизма' WHERE entry=31580 AND locale='ruRU';

-- Arcanist Adurin <Emblem of Valor Quartermaster> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=31579/arcanist-adurin
UPDATE creature_template_locale SET Title='Награды за эмблемы доблести' WHERE entry=31579 AND locale='ruRU';

-- Arcanist Miluria <Emblem of Triumph Quartermaster> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=35494/arcanist-miluria
UPDATE creature_template_locale SET Title='Награды за эмблемы триумфа' WHERE entry=35494 AND locale='ruRU';

-- Arcanist Uovril <Emblem of Frost Quartermaster> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=37942/arcanist-uovril
UPDATE creature_template_locale SET Title='Награды за эмблемы льда' WHERE entry=37942 AND locale='ruRU';

-- Arcanist Firael <Emblem of Conquest Quartermaster> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=33964/arcanist-firael
UPDATE creature_template_locale SET Title='Награды за эмблемы завоевания' WHERE entry=33964 AND locale='ruRU';

-- Magistrix Vesara <Emblem of Triumph Quartermaster> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=35495/magistrix-vesara
UPDATE creature_template_locale SET Title='Награды за эмблемы триумфа' WHERE entry=35495 AND locale='ruRU';

-- Magistrix Lambriesse <Emblem of Heroism Quartermaster> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=31582/magistrix-lambriesse
UPDATE creature_template_locale SET Title='Награды за эмблемы героизма' WHERE entry=31582 AND locale='ruRU';

-- Magister Arlan <Emblem of Frost Quartermaster> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=37941/magister-arlan
UPDATE creature_template_locale SET Title='Награды за эмблемы льда' WHERE entry=37941 AND locale='ruRU';

-- Magister Brasael <Emblem of Valor Quartermaster> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=31581/magister-brasael
UPDATE creature_template_locale SET Title='Награды за эмблемы доблести' WHERE entry=31581 AND locale='ruRU';

-- Magister Sarien <Emblem of Conquest Quartermaster> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=33963/magister-sarien
UPDATE creature_template_locale SET Title='Награды за эмблемы завоевания' WHERE entry=33963 AND locale='ruRU';

-- Keeping Up Appearances- Small correction.
-- https://www.wowhead.com/wotlk/quest=10433/keeping-up-appearances
UPDATE quest_request_items_locale SET CompletionText='<Шоли возвышает голос, словно бы для того, чтобы привлечь внимание всех духов Астрала в округе.>$B$BНу что, есть шкуры на продажу?' WHERE ID=10433 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='<Шоли демонстративно осматривает шкуры.>$B$BОни великолепны, просто великолепны! Я заплачу по самой высокой цене! Ты не против ещё пару раз оказать мне услугу?' WHERE ID=10433 AND locale='ruRU';

-- Bot-Specialist Alley <B.O.O.M.>- Small correction.
-- https://www.wowhead.com/wotlk/npc=19578/bot-specialist-alley
UPDATE creature_template_locale SET Name='Роботехник Элли' WHERE entry=19578 AND locale='ruRU';

-- Mark V is Alive!- Small correction.
-- https://www.wowhead.com/wotlk/quest=10191/mark-v-is-alive
UPDATE quest_offer_reward_locale SET RewardText='Получилось! Получилось! Я готова тебя расцеловать!\n\nОй... у Маккса А. Миллиона модели V опять кончилась энергия. Ну ладно, он сегодня хорошо поработал, а остальное неважно!\n\nКомандующий ракетами Фьюзеляж будет доволен – он сможет подключить эти дренейские машины к своей ракете Х-52! А я получу продвижение! Я так рада! Сейчас, я чем-нибудь тебя вознагражу.\n\nВот, выбирай из этого.' WHERE ID=10191 AND locale='ruRU';

-- Information Gathering- Small correction.
-- https://www.wowhead.com/wotlk/quest=10198/information-gathering
UPDATE quest_template_locale SET Details='Я подготовил форму вместе с добытыми тобою деталями. Она усилена магией для довершения иллюзии.$B$BМы заметили, что несколько минут назад командир Кузня Солнца в сопровождении охраны отправился на встречу с чародеем Ардонисом. Видимо, встреча будет невероятно важной; посмотрим, сможешь ли ты что-либо разузнать.$B$BО, чуть не забыл: тебе нужно держаться подальше от чародейских големов, патрулирующих манагорн. Они могут видеть сквозь иллюзию.' WHERE ID=10198 AND locale='ruRU';

-- Bloody Imp-ossible! - Small correction.
-- https://www.wowhead.com/wotlk/quest=10924/bloody-imp-ossible
UPDATE quest_template_locale SET Details='Кровь прыгуан-ловцов, обитающих в этом районе – это очень сильный и редкий реактив. Торговля им идет весьма успешно.$B$BОбычно я посылаю за ней Зеппита, моего беса. Кровь прыгуана-ловца слишком едкая, чтобы ты или я могли без опаски обращаться с ней, но Зеппита это не волнует.$B$BУ меня тут много дел в лавке, так что, если я пошлю с тобой Зеппита, ты не поможешь в сборе крови? Зеппиту трудно на чём-то сосредоточиться надолго, так что тебе нужно быть поблизости от прыгуаны в момент её смерти, чтобы заставить Зеппита выполнить работу.' WHERE ID=10924 AND locale='ruRU';

-- Retrieving the Goods - Small correction. Come on, why specify what all these corrections are for?! No one will check it anyway. The main thing is that in the ruRU version the inscriptions will not look like junk after my corrections. ruRU players should definitely appreciate my edits.
-- https://www.wowhead.com/wotlk/quest=10435/retrieving-the-goods
UPDATE quest_template_locale SET Details='<Оди озирается по сторонам и понижает голос.>$B$BЯ уверена, что Шоли кое-что рассказывал тебе о нашей работе здесь. Когда мы с Бондсом ходили на "охоту", мы собирали детали генераторов экосфер эфириалов и прятали их в гнёздах ящеров, на которых охотились в заповеднике "Дальнее поле".$B$BЭто удалённый регион к северо-востоку от Штормовой Вершины, поблизости от Осколков Пустоты. Вряд ли тебе там встретится много эфириалов, так что не согласишься ли ты помочь нам забрать детали генераторов экосферы?' WHERE ID=10435 AND locale='ruRU';

-- Brother Against Brother - Small correction. Lakka - is she, not he, becous she is a sister, as NPC said.
-- https://www.wowhead.com/wotlk/quest=10097/brother-against-brother
UPDATE quest_offer_reward_locale SET RewardText='Я не могу вас отблагодарить, $N. Зная, что Лакка свободна, я могу разорвать остальные связи с Сетекками.$B$BЧасть меня никогда не простит себе смерти Сита, но это нужно было сделать. Когда я доберусь до Скеттиса, я проведу для него обряд смерти. Возможно, его дух найдет покой, как только он искупит то, что сбил наш народ с пути.' WHERE ID=10097 AND locale='ruRU';

-- Spy To'gun - Missing greeting. Also the value in table quest_greeting is absent.
-- https://www.wowhead.com/wotlk/npc=18891
DELETE FROM quest_greeting_locale WHERE ID=18891 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('18891', 'ruRU', 'Приветствую, $N.', '0');
DELETE FROM quest_greeting WHERE ID=18891;
INSERT INTO quest_greeting (ID, Greeting, VerifiedBuild) VALUES ('18891', 'Greetings, $n.', '0');

-- The Crystals - Small correction. A player can be male or female, and in ruRU this is very important.
-- https://www.wowhead.com/wotlk/quest=11025/the-crystals
UPDATE quest_request_items_locale SET CompletionText='Когда ты постигнешь осколки и кристаллы, ты лучше сможешь помогать нам защищать нас и наших братьев-огров внизу.\n\nСами осколки получили своё назание от древней ныне мёртвой цивилизации араккоа, что жили на вершниах здешних гор.\n\nТы $gпринёс:принесла; осколки?' WHERE ID=11025 AND locale='ruRU';

-- Maggoc's Treasure Chest - Small correction. A player can be male or female, and in ruRU this is very important.
-- https://www.wowhead.com/wotlk/quest=10996/maggocs-treasure-chest
UPDATE quest_offer_reward_locale SET RewardText='Говоришь, он пуст? Жаль – но ты $gсам:сама; видишь ту тупую жестокость, с которой нам приходится сталкиваться.\n\nТеперь, когда Маггок мёртв, мы на шаг приблизились к осуществлению моей мечты о доме для огров и о том времени, когда мы сами будем определять нашу судьбу.' WHERE ID=10996 AND locale='ruRU';

-- A Special Thank You - Small correction. A player can be male or female, and in ruRU this is very important.
-- https://www.wowhead.com/wotlk/quest=11091/a-special-thank-you
UPDATE quest_offer_reward_locale SET RewardText='Ох ты, $gдруг:подруга;, мы рады! Мы слышали, что ты много хорошего нам $gсделал:сделала;! Круто! Нам сдаётся, разберёшься с проблемами Огри\'лы и спасёшь нас, и всё будет в шоколаде!\n\nВот, бери. Это мелочь, просто неприкосновенный запас да индивидуальный пакет, кототрый мы тебе собрали в благодарность за труды.\n\nПолюбуйся на наши товары. У нас много что есть тебе полезного.' WHERE ID=11091 AND locale='ruRU';

-- Into the Soulgrinder - Small correction. A player can be male or female, and in ruRU this is very important.
-- https://www.wowhead.com/wotlk/quest=11000/into-the-soulgrinder
UPDATE quest_request_items_locale SET CompletionText='Не $gвзял:взяла; ещё душу Скуллока?' WHERE ID=11000 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='Кончено, значит. Ты $gосвободил:освободила; нас от оков сынов Груула. Ты $gспасл:спасла; клан Кровавого Молота от полного укничтожения.\n\nСловами не выразить, в каком долгу перед тобой ВСЕ огры Острогорья, как Кровавые Молоты, так и Камнероги, $N.\n\nСмотри вниз – уже теперь огры собрались воздать тебе почести. Пусть Груул и его марионетка, старый король Молгар, прячутся в его логове. Иди же к ограм вниз, как $gнаш новый король:наша новая королева;!' WHERE ID=11000 AND locale='ruRU';

-- Ogre Heaven - Small correction. A player can be male or female, and in ruRU this is very important.
-- https://www.wowhead.com/wotlk/quest=11009/ogre-heaven
UPDATE quest_offer_reward_locale SET RewardText='Могдорн прислал вперёд весть, говоря чтобы я ждал тебя. Я рад, что ты $gпришёл:пришла;.\n\nРаз с сынами Груула покончено, разные населители этих горных террас и тех что на севере начнут охотиться на наших братьев-огров внизу, и это только вопрос времени.\n\nЯ верю, что ты поможешь нам это не допустить, $N.' WHERE ID=11009 AND locale='ruRU';

-- Ally of the Netherwing - gender again!
-- https://www.wowhead.com/wotlk/quest=10871/ally-of-the-netherwing
UPDATE quest_offer_reward_locale SET RewardText='Ты $gдоказал:доказала;, что являешься настоящим другом Крыльям Пустоты. Наша мать свободна, мои братья и сёстры спасены.\n\nВозможно когда-нибудь нам ещё потребуется твоя помощь, но знай, что когда бы ты ни $Gпришёл:пришла;, тебя встретят с распростёртыми объятьями, $Gбрат:сестра;!' WHERE ID=10870 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='Ты $gдоказал:доказала;, что являешься настоящим другом Крыльям Пустоты. Наша мать свободна, мои братья и сёстры спасены.\n\nВозможно когда-нибудь нам ещё потребуется твоя помощь, но знай, что когда бы ты ни $Gпришёл:пришла;, тебя встретят с распростёртыми объятьями, $Gбрат:сестра;!' WHERE ID=10871 AND locale='ruRU';

-- Kurzel - Missing greeting. Also the value in table quest_greeting is absent. Hmm, for some reason it still doesn't work... After praying to the sacred tables (as is customary among fanatics... oh, I mean experienced members of the project) I had an epiphany: the greeting text of this NPC should be in the broadcast_text table, like many other NPCs in the game (logical!), but for some reason it is not there either. This text must be hardcoded right into the core (doubly logical!).
-- https://www.wowhead.com/wotlk/npc=26664/kurzel
-- https://www.wowhead.com/wotlk/quest=13129/head-games
DELETE FROM quest_greeting_locale WHERE ID=26664 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('26664', 'ruRU', 'Спасибо, что $gосвободил:освободила; меня, $C.\r\n\r\nЯ всё ещё немного одурманена ядом. Думаю, я останусь здесь, пока силы не вернутся.', '0');
DELETE FROM quest_greeting WHERE ID=26664;
INSERT INTO quest_greeting (ID, Greeting, VerifiedBuild) VALUES ('26664', 'Thank you for freeing me, $C.\r\n\r\nI\'m still a bit woozy from the venom. I think I\'ll stay here until my strength returns.', '0');

-- Head Games - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=13129/head-games
UPDATE quest_template_locale SET Objectives='Курцель просит вас приложить клочок ее рубахи к трупу Новоса Призывателя, после чего отнести запятнанную лимфой ткань Маку.' WHERE ID=13129 AND locale='ruRU';
UPDATE quest_template_locale SET CompletedText='Вернитесь к Маку Фирсену в Гранитные Ключи в Седых Холмах.' WHERE ID=13129 AND locale='ruRU';
