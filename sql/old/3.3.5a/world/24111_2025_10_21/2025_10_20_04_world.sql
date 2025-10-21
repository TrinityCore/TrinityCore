-- Message in a Bottle - a small typo related to cases.
-- https://www.wowhead.com/wotlk/quest=630/message-in-a-bottle
UPDATE quest_offer_reward_locale SET RewardText='$N, ты $Gспас:спасла; меня от ужасного бесчестия. Если бы это было в моей власти, то я бы предложила тебе место в моём племени. Но пока всё, что я могу тебе предложить, это знак за твою смелость и благородство, которые ты $Gпоказал:показала;. ' WHERE ID=630 AND locale='ruRU';

-- Thresher Oil - a small typo related to cases.
-- https://www.wowhead.com/wotlk/quest=11192/thresher-oil
UPDATE quest_offer_reward_locale SET RewardText='Ну, хотя у меня и есть сомнения на этот счёт, но сейчас это лучшее решение. Как только мы зажжём маяк, у нас наверняка найдётся время подыскать другое топливо для фонаря.' WHERE ID=11192 AND locale='ruRU';

-- Dastardly Denizens of the Deep - Inconsistency with wowhead
-- https://www.wowhead.com/wotlk/quest=11193/dastardly-denizens-of-the-deep
UPDATE quest_request_items_locale SET CompletionText='Что сегодня берём? Рекомендую морскую щуку.' WHERE ID=11193 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='Какая Бабс заботливая... помнит, что я собираю книги. Да и книга отличная. Ты сам-то ее пролистал? Там, кстати, немало правдивых историй. Да, моряки любят приврать, но не все их рассказы – выдумки.' WHERE ID=11193 AND locale='ruRU';

-- The End of the Deserters - Inconsistency with wowhead
-- https://www.wowhead.com/wotlk/quest=11134/the-end-of-the-deserters
UPDATE quest_offer_reward_locale SET RewardText='Просьба Гависа не так нелепа, как может показаться. Если провести операцию должным образом, то леди Джайна сумеет вернуть дезертиров на путь истинный, но решение, конечно же, за ней.\r\n\r\nПриятно было работать с тобой, $N. Сомневаюсь, что без твоей помощи операция прошла бы столь же гладко. Когда буду писать рапорт в Штормград, обязательно скажу, что ты - тот самый $c, который покончил с угрозой дезертирства.' WHERE ID=11134 AND locale='ruRU';

-- The Hermit of Swamplight Manor - The row in the quest_template_locale table exists but is filled in incorrectly... Does anyone even read all these descriptions that I leave?...
-- https://www.wowhead.com/wotlk/quest=11177/the-hermit-of-swamplight-manor
UPDATE quest_template_locale SET Title='Отшельник из сторожки "Болотный огонёк"' WHERE ID=11177 AND locale='ruRU';

-- Ilyenia Moonfire <Weapon Master> - Missing title
-- https://www.wowhead.com/classic/npc=11866/ilyenia-moonfire
UPDATE creature_template_locale SET Title='Эксперт по оружию' WHERE entry=11866 AND locale='ruRU';

-- A Dark Influence - a small typo related to cases.
-- https://www.wowhead.com/wotlk/quest=12220/a-dark-influence
UPDATE quest_template_locale SET ObjectiveText2='Замерен выброс энергии под Ветвями Фордрассила' WHERE ID=12220 AND locale='ruRU';

-- Vordrassil's Sapling - a small typo.
-- https://www.wowhead.com/wotlk/quest=12248/vordrassils-sapling
UPDATE quest_request_items_locale SET CompletionText='Ты $Gпринёс:принесла; мне пепел, $N?' WHERE ID=12248 AND locale='ruRU';

-- ... and Bugs - Inconsistency with wowhead. Due to an incorrect quest description, approximately 10 innocent crabs died in Dustwallow Marsh.
-- https://www.wowhead.com/wotlk/quest=1258/and-bugs
UPDATE quest_template_locale SET Details='Ещё один компонент моего нового рецепта – клешни гигантского краба. К сожалению, те которые водятся в Пылевых топях, – грязнокрабы, не годятся... Зато те, что живут на Болоте Печали, – в самый раз!\r\n\r\nОболочка клешни – важный элемент украшения блюда, поэтому они мне нужны целые и непоцарапанные. К сожалению, у краба всего две клешни, а то и одна, а мне для моих кулинарных экспериментов их нужно гораздо больше. Так что насчёт небольшой прогулки, $N?' WHERE ID=1258 AND locale='ruRU';
UPDATE quest_request_items_locale SET CompletionText='Я придумал чудесное блюдо из языков илистых черепах. Надеюсь, ваша охота прошла удачно?' WHERE ID=1258 AND locale='ruRU';

-- Defias in Dustwallow? - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=11137/defias-in-dustwallow
UPDATE quest_template_locale SET Title='Братство Справедливости в Пылевых топях?' WHERE ID=11137 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='<Капитан Ваймор берёт у вас приказы и просматривает их.>\r\n\r\nЧто значит "драгоценный груз"? Братство Справедливости по мелочам протаскивало контрабанду в Штормград, но язык, которым написаны эти поручения, указывает на богатого и знатного клиента. Это совершенно не похоже на работу Братства.' WHERE ID=11137 AND locale='ruRU';

-- Renn McGill - Inconsistency with wowhead. It's going to be a long day... Looks like there's going to be a lot of these inconsistencies in Dustwallow Marsh.
-- https://www.wowhead.com/wotlk/quest=11138/renn-mcgill
UPDATE quest_request_items_locale SET CompletionText='Здорово, $C. Что привело тебя в такую даль?' WHERE ID=11138 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='<Ренн просматривает приказы.>\r\n\r\nЗначит, на борту был ценный груз! Нужно обойти Братство Справедливости и найти его первыми. Ныряльщики из этих ребят никудышные, но вот их снаряжение мне бы пригодилось.' WHERE ID=11138 AND locale='ruRU';

-- Secondhand Diving Gear - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=11139/secondhand-diving-gear
UPDATE quest_template_locale SET Title='Старое водолазное снаряжение' WHERE ID=11139 AND locale='ruRU';
UPDATE quest_template_locale SET Details='Отсюда и до Алькаца всё дно усеяно обломками затонувших кораблей, и водолазы Братства Справедливости уже вовсю собирают "урожай". С помощью их снаряжения мы и тебя отправим на охоту, но сначала его надо, так сказать, "позаимствовать."\r\n\r\nВ общем, так: обойди остров, найди ящик с испорченным водолазным снаряжением и инструменты для починки. Потом тащи всё это мне, и я тебя быстренько экипирую!' WHERE ID=11139 AND locale='ruRU';
UPDATE quest_request_items_locale SET CompletionText='Ну-ка, посмотрим, что тебе удалось "позаимствовать" у Братства.' WHERE ID=11139 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='М-да... состояние плачевное... Я думал, что будет получше. И инструменты... ну ладно.\r\n\r\nЯ обещал починить снаряжение, и я его починю. Вот прямо сейчас и займусь.' WHERE ID=11139 AND locale='ruRU';

-- Recover the Cargo! - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=11140/recover-the-cargo
UPDATE quest_template_locale SET Details='Ну что ж, я кое-как заштопал снаряжение, так что немного понырять ты сможешь. Но особо долго сидеть под водой не советую.\r\n\r\nОбломки корабля разбросаны по дну, начиная от восточного побережья этого острова и до самого острова Алькац. Пока шлем держится, походи по дну между островами и поищи обломки, а потом попытайся извлечь из них груз с помощью этого набора спасателя. Но слишком близко к Алькацу не подходи, а то тебя там гидры сожрут.' WHERE ID=11140 AND locale='ruRU';
UPDATE quest_request_items_locale SET CompletionText='Ну что, нашлось какое-нибудь добро Братства Справедливости?' WHERE ID=11140 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='<Ренн копается в содержимом сейфов, которые вы нашли.>\r\n\r\nТы молодец. Посмотрим, что это за ценный груз такой...' WHERE ID=11140 AND locale='ruRU';

-- Jaina Must Know - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=11141/jaina-must-know
UPDATE quest_template_locale SET Details='Немедленно оповести леди Джайну о том, что нам удалось узнать! Бандиты перевозили пленника, и мы не знаем, кто это и жив ли он или она до сих пор!\r\n\r\nНо в одном нет сомнений, $N. Эти бандюги в петлю по мелочам не полезут. Наверняка их пленник – очень важная персона. Леди Джайна должна знать об этом больше, чем кто-либо другой. Найди её на вершине башни магов в центре Терамора.' WHERE ID=11141 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='Вы с Ренном просто молодцы, что вывели на свет эти сведения и тотчас же доложились мне. Несомненно, Братство Справедливости затевает что-то недоброе против Штормграда и его союзников. Но для них этот замысел уж слишком хитроумен, стало быть, у них где-то завелся богатенький покровитель.' WHERE ID=11141 AND locale='ruRU';

-- Survey Alcaz Island - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=11142/survey-alcaz-island
UPDATE quest_offer_reward_locale SET RewardText='<Леди Джайна внимательно выслушивает ваш доклад по результатам обследования острова Алькац.>\r\n\r\nКруг рун, драконид? Я знаю, что в Братстве Справедливости есть тайные маги, но не особенно могущественные, чтобы пользоваться такими вещами!\r\n\r\nИ почему черные дракониды вдруг заинтересовались островом, кишащим нагами? Слишком много вопросов без ответов, но в одном я точно уверена: у Братства Справедливости есть сильный союзник в высшем руководстве Альянса.' WHERE ID=11142 AND locale='ruRU';

-- Kreldig Ungor <Reclaimers Inc.> - Missing greeting
-- https://www.wowhead.com/wotlk/npc=5638/kreldig-ungor
DELETE FROM quest_greeting_locale WHERE ID=5638 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('5638', 'ruRU', 'У меня много дел здесь, в Пустошах, $N. Ройттен хочет, чтобы мы раздобыли кое-какие реагенты для одного из наших клиентов, а также доставили некоторые из этих потерянных вещей.$B$BПоскольку вы здесь, чтобы помочь, почему бы нам не начать?', '0');

-- Captain Pentigast - Missing greeting
-- https://www.wowhead.com/wotlk/npc=5396/captain-pentigast
DELETE FROM quest_greeting_locale WHERE ID=5396 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('5396', 'ruRU', 'У Альянса много интересов в Пустошах, и наше положение здесь неустойчиво.$B$BВы нам поможете?', '0');

-- Krom Stoutarm - Missing greeting - WTH? Why doesn't it work?! Аh, this is why the value in table quest_greeting is absent...
-- https://www.wowhead.com/wotlk/npc=6294/krom-stoutarm
DELETE FROM quest_greeting_locale WHERE ID=6294 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('6294', 'ruRU', 'Приветствую, $n.', '0');
DELETE FROM quest_greeting WHERE ID=6294;
INSERT INTO quest_greeting (ID, Greeting, VerifiedBuild) VALUES ('6294', 'Greetings, $n.', '0');

-- Highvale Ranger - PH MODEL WIP. WIP title? This is also in other localizations. Applicable only to ruRU.
-- https://www.wowhead.com/wotlk/npc=2694/highvale-ranger
UPDATE creature_template_locale SET Title='' WHERE entry=2694 AND locale='ruRU';

-- Find OOX-09/HL! - Small typo.
-- https://www.wowhead.com/wotlk/quest=485/find-oox-09-hl
UPDATE quest_offer_reward_locale SET RewardText='Вы помещаете яйцевидный аварийный маяк в механического цыпленка.$B$BС гудением и жужжанием робот поднимается на ноги, после чего из его механических внутренностей слышится голос Карлса:$B$B"Что ж, по крайней мере, КПХ-9/HL работает, но ему требуется капитальный ремонт! Он тяжёлый, и нести его ты не сможешь, но вообще у меня есть одна мысль... Не хочешь ли присмотреть за ним ещё немного?"' WHERE ID=485 AND locale='ruRU';

-- Mazen's Behest - Small typo.
-- https://www.wowhead.com/wotlk/quest=1364/mazens-behest
UPDATE quest_offer_reward_locale SET RewardText='Какое счастье!$B$BДо сего момента я считал, что мой запрос на "Рассуждения Кадгара о пространственной сходимости", который я отправлял в Академию Тайных Наук и Искусств, был отклонен мастером Мазеном.$B$BОн, должно быть, просто потонул в запросах, поскольку в последнее время происходит множество странных событий.$B$BТеперь прошу меня простить – мне пора приступить к исследованиям. Понимаете, сама возможность прикоснуться к творению величайшего Кадгара повергает меня в трепет...' WHERE ID=1364 AND locale='ruRU';

-- Quartermaster Lungertz - Missing greeting.
-- https://www.wowhead.com/wotlk/npc=5393/quartermaster-lungertz
DELETE FROM quest_greeting_locale WHERE ID=5393 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('5393', 'ruRU', 'Приветствую, $N.', '0');

-- Bixi Wobblebonk <Weapon Master> - Missing title
-- https://www.wowhead.com/wotlk/npc=13084/bixi-wobblebonk
UPDATE creature_template_locale SET Title='Эксперт по оружию' WHERE entry=13084 AND locale='ruRU';

-- Buliwyf Stonehand <Weapon Master> - Missing title
-- https://www.wowhead.com/wotlk/npc=11865/buliwyf-stonehand
UPDATE creature_template_locale SET Title='Эксперт по оружию' WHERE entry=11865 AND locale='ruRU';

-- Rescue OOX-09/HL! - Small correction.
-- https://www.wowhead.com/wotlk/quest=836/rescue-oox-09-hl
UPDATE quest_offer_reward_locale SET RewardText='О, да ты просто $Gспас:спасла; моего робота КПХ-9/HL! Я прям даже не знаю, как тебя благодарить! Моих автономных роботов еще совершенствовать и совершенствовать, но ты $Gизбавил:избавила; меня от многих лишних часов работы, а также от расходов!$B$BПожалуйста, выбери себе что-нибудь в награду. Спасибо тебе ещё раз, $N, я и мои роботы навеки у тебя в долгу.' WHERE ID=836 AND locale='ruRU';

-- Components for the Enchanted Gold Bloodrobe - Menara Voidrender speaks about herself in the masculine gender.
-- https://www.wowhead.com/wotlk/npc=6266/menara-voidrender
-- https://www.wowhead.com/wotlk/quest=4783/components-for-the-enchanted-gold-bloodrobe
UPDATE quest_request_items_locale SET CompletionText='Пустоши – опасное место: наги, гиганты, сатиры, Пылающий Легион... И вдобавок ко всему еще и воинственные кентавры.\n\nЯ уже говорила, что это подвергнет испытанию не только твою силу и ловкость, но и терпение. Не теряй бдительности, $N.' WHERE ID=4783 AND locale='ruRU';

-- Handiir <Weapon Master> - Missing title
-- https://www.wowhead.com/wotlk/npc=16773/handiir
UPDATE creature_template_locale SET Title='Эксперт по оружию' WHERE entry=16773 AND locale='ruRU';

-- The Hermit of Swamplight Manor - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=11177/the-hermit-of-swamplight-manor
UPDATE quest_template_locale SET Details='Есть тут один старикашка по имени Ярл. Его называют "Болотный глаз." Живёт на болоте. Не так давно он "унаследовал" сторожку "Болотный огонёк", когда её предыдущий хозяин пропал при таинственных обстоятельствах.\r\n\r\nМне нужен тот, кто будет периодически проверять, что там происходит у этого "Болотного глаза". Знаешь, он мне чем-то напоминает моего деда. Тоже чуток не в себе, мягко говоря.\r\n\r\nИди на северо-запад по дороге из Терамора. "Болотный огонёк" стоит на Ведьмином холме, как раз перед тем поворотом, где дорога уходит на запад.' WHERE ID=11177 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='Убирайся с моей лужайки... хотя нет, погоди... Может, поможешь старому "Болотному глазу" приготовить обед? Ну как, согласен?' WHERE ID=11177 AND locale='ruRU';

-- Sayoc <Weapon Master> - Missing title
-- https://www.wowhead.com/classic/npc=11868/sayoc
UPDATE creature_template_locale SET Title='Эксперт по оружию' WHERE entry=11868 AND locale='ruRU';

-- Hanashi <Weapon Master> - Missing title
-- https://www.wowhead.com/classic/npc=2704/hanashi
UPDATE creature_template_locale SET Title='Эксперт по оружию' WHERE entry=2704 AND locale='ruRU';

-- Ileda <Weapon Master> - Missing title
-- https://www.wowhead.com/wotlk/npc=16621/ileda
UPDATE creature_template_locale SET Title='Эксперт по оружию' WHERE entry=16621 AND locale='ruRU';

-- Archibald <Weapon Master> - Missing title
-- https://www.wowhead.com/wotlk/npc=11870/archibald
UPDATE creature_template_locale SET Title='Эксперт по оружию' WHERE entry=11870 AND locale='ruRU';

-- Ansekhwa <Weapon Master> - Missing title. It seems that this was the last Weapon Master.
-- https://www.wowhead.com/wotlk/npc=11869/ansekhwa
UPDATE creature_template_locale SET Title='Эксперт по оружию' WHERE entry=11869 AND locale='ruRU';

-- Prisoners of the Grimtotems - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=11145/prisoners-of-the-grimtotems
UPDATE quest_template_locale SET Title='Пленники Зловещего Тотема' WHERE ID=11145 AND locale='ruRU';
UPDATE quest_template_locale SET Details='Мы делаем всё возможное, чтобы сдерживать племя Зловещего Тотема, но они так и продолжают нападать на башню. А хуже всего то, что они похитили патрульных, которых наш капитан посылал на поиски информации и охрану дороги.\r\n\r\nЯ думаю, что заложников держат в деревне Черного Копыта, она на северо-западе. Зная племя Зловещего Тотема, можно сказать, что ключи от клеток с заложниками наверняка у стражей – защитников поселения. Делай что угодно, |3-6($c), только верни наших ребят живыми!' WHERE ID=11145 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='Освобождённые пленники уже возвращаются из деревни Черного Копыта. Информация, которую получит от них капитан, позволит нам лучше подготовиться к следующей битве с племенем Зловещего Тотема.\r\n\r\nБлагодарю тебя от себя лично и от имени всех наших солдат.' WHERE ID=11145 AND locale='ruRU';

-- Wizzle Brassbolts - Missing greeting.
-- https://www.wowhead.com/wotlk/npc=4453/wizzle-brassbolts
DELETE FROM quest_greeting_locale WHERE ID=4453 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('4453', 'ruRU', 'Смотрите под ноги, $g сэр : мэм;. Не всем посчастливилось быть такими высокими.', '0');

-- Favored of Elune? - Small correction.
-- https://www.wowhead.com/wotlk/quest=3661/favored-of-elune
UPDATE quest_request_items_locale SET CompletionText='Старайтесь избегать их, $N. Дикие совухи могут счесть вас за врага.' WHERE ID=3661 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='Спасибо за перья, $N.$B$BЧто вам удалось узнать о диких совухах?$B$BВозможно, эти перья помогут узнать больше и сказать, являются ли они кровожадными монстрами или просто одичавшими питомцами. Надеюсь, когда-нибудь я узнаю правду.$B$BЯ продолжу свои исследования, а вы, пожалуйста, по истечении некоторого времени зайдите ко мне снова.' WHERE ID=3661 AND locale='ruRU';

-- Marie Holdston <Weaponsmith> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=4888/marie-holdston
UPDATE creature_template_locale SET Title='Оружейник' WHERE entry=4888 AND locale='ruRU';

-- Caz Twosprocket - This NPC should not have a title.
-- https://www.wowhead.com/wotlk/npc=4941/caz-twosprocket
UPDATE creature_template_locale SET Title='' WHERE entry=4941 AND locale='ruRU';

-- Doctor Gustaf VanHowzen <Trauma Surgeon> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=12939/doctor-gustaf-vanhowzen
UPDATE creature_template_locale SET Title='Травматолог' WHERE entry=4888 AND locale='ruRU';

-- Jensen Farran <Bowyer> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=4892/jensen-farran
UPDATE creature_template_locale SET Title='Торговец луками' WHERE entry=4892 AND locale='ruRU';

-- Charity Mipsy <General Goods> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=4896/charity-mipsy
UPDATE creature_template_locale SET Title='Потребительские товары' WHERE entry=4896 AND locale='ruRU';

-- Calia Hastings <SI:7> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=23566/calia-hastings
UPDATE creature_template_locale SET Title='ШРУ' WHERE entry=23566 AND locale='ruRU';

-- Motega Firemane - The row in the creature_template_locale table exists but is filled in incorrectly
-- https://www.wowhead.com/wotlk/npc=10428/motega-firemane
UPDATE creature_template_locale SET Name='Мотега Огненная Грива' WHERE entry=10428 AND locale='ruRU';

-- Grimtotem Battle Plan - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/item=33051/grimtotem-battle-plan
UPDATE page_text_locale SET Text='Старейшина, я послал тебе на помощь большое войско, но ты должен соблюдать осторожность. Твоя первостепенная задача – не дать этим мерзавцам из Альянса продвинуться вглубь наших земель. Некоторые особо безрассудные люди уже начали строить большое здание на границе Степи.\r\n\r\nДай им понять, что за пределами их проклятого Терамора им не рады. И напоследок предупреждаю тебя, старейшина: не позволяй ограм из Гиблотопи узнать о твоих планах. У этих животных нет ни капли благоразумия.\r\n\r\n- Агашем' WHERE ID=3033 AND locale='ruRU';

-- Fizzle Brassbolts - Missing greeting.
-- https://www.wowhead.com/wotlk/npc=4454/fizzle-brassbolts
DELETE FROM quest_greeting_locale WHERE ID=4454 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('4454', 'ruRU', 'Приветствую, $N.', '0');

-- WANTED: Caliph Scorpidsting - Small correction.
-- https://www.wowhead.com/wotlk/quest=2781/wanted-caliph-scorpidsting
UPDATE quest_offer_reward_locale SET RewardText='Наконец-то – правосудие свершилось! Ты $Gнанёс:нанесла; суровый удар подлым кочевникам! Жало Скорпида мёртв, может быть, это отпугнёт этих надоед от колодцев Прибамбасска!$B$BОт лица Водной компании Прибамбасска я вручаю тебе эту награду. Ты $Gоказал:оказала; нам большую услугу.' WHERE ID=2781 AND locale='ruRU';

-- Tran'rek - This NPC should not have a title.
-- https://www.wowhead.com/wotlk/npc=7876/tranrek
UPDATE creature_template_locale SET Title='' WHERE entry=7876 AND locale='ruRU';

-- The Bait for Lar'korwi - Small correction.
-- https://www.wowhead.com/wotlk/quest=4292/the-bait-for-larkorwi
UPDATE quest_offer_reward_locale SET RewardText='Хвала Матери-Земле! Ты $Gсправился:справилась;! Ты $Gпоказал:показала; себя $Gвеликим:великой;, $N. Твой дух силен. Твоей храбрости нет равных. А сила твоя укрепилась. Я склоняюсь пред твоим мастерством.$B$BТолько самым великим из моих предков были под силу подобные свершения.' WHERE ID=4292 AND locale='ruRU';

-- Sprinkle - Missing greeting. Also the value in table quest_greeting is absent.
-- https://www.wowhead.com/wotlk/npc=7583/sprinkle
DELETE FROM quest_greeting_locale WHERE ID=7583 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('7583', 'ruRU', 'Приветствую, $N.', '0');
DELETE FROM quest_greeting WHERE ID=7583;
INSERT INTO quest_greeting (ID, Greeting, VerifiedBuild) VALUES ('7583', 'Greetings, $n.', '0');

-- Doling Justice - Small correction.
-- https://www.wowhead.com/wotlk/quest=2970/doling-justice
UPDATE quest_offer_reward_locale SET RewardText='Да, $N, Кинда была права насчет тебя: у тебя талант к этому делу! Ты – куда более $Gопытный:опытная; искатель приключений, чем мы обе. Спасибо, что ты с нами!$B$BЭтот клан Зловещего Тотема куда опаснее остальных тауренов. Подозреваю, что их боятся даже собственные сородичи!$B$BВпрочем, об этом потом.' WHERE ID=2970 AND locale='ruRU';

-- Find OOX-22/FE! - Small correction.
-- https://www.wowhead.com/wotlk/quest=2766/find-oox-22-fe
UPDATE quest_offer_reward_locale SET RewardText='Вы помещаете яйцо... то есть аварийный маяк... внутрь цыпленка... то есть автономного робота.$B$BВнутри робота слышится гудение и жужжание. Он пытается подняться на ноги. После того как робот оживает, снова слышится голос Карлса, но на этот раз изнутри робота:$B$B"Ну что ж, по крайней мере, КПХ-22/FE работает. Однако он нуждается в серьезном ремонте! Нести его вы не сможете, он слишком тяжелый... О! У меня идея! Не согласитесь ли вы его проводить?"' WHERE ID=2766 AND locale='ruRU';

-- Angelas Moonbreeze - Missing greeting.
-- https://www.wowhead.com/wotlk/npc=7900/angelas-moonbreeze
DELETE FROM quest_greeting_locale WHERE ID=7900 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('7900', 'ruRU', 'Привет, $N. Может быть, у тебя есть время поболтать?', '0');

-- Gobject GUID 49695 (Entry: 142958) - [Feralas: A History X:8727.450195 Y:1002.960022 Z:23.501900 MapId:1] - Missing locale.
DELETE FROM gameobject_template_locale WHERE entry=142958 AND locale='ruRU';
INSERT INTO gameobject_template_locale (entry, locale, name, VerifiedBuild) VALUES ('142958', 'ruRU', 'Фералас: История', 0);

-- A Short Note - Small correction.
-- https://www.wowhead.com/wotlk/item=9329/a-short-note
UPDATE page_text_locale SET Text='Гурдл,\r\n\r\nя с нетерпением ожидаю, когда будет готово твое новое изобретение. Я жду не дождусь, когда смогу с его помощью записывать результаты моих исследований.\r\n\r\nПожалуйста, доверь его моему посланнику.\r\n\r\n\r\nС сердечным приветом,\r\n\r\nДарин Добрый Ветер' WHERE ID=1156 AND locale='ruRU';

-- Emissary Valustraa <Mage Trainer> - Missing title
-- https://www.wowhead.com/wotlk/npc=17105/emissary-valustraa
UPDATE creature_template_locale SET Title='Наставница магов' WHERE entry=17105 AND locale='ruRU';

-- Rescue OOX-22/FE! - Small correction.
-- https://www.wowhead.com/wotlk/quest=2767/rescue-oox-22-fe
UPDATE quest_offer_reward_locale SET RewardText='О, спаситель! Вы доставили на место КПХ-22/FE! У меня просто слов нет, настолько я вам благодарен! Моя серия автономных роботов постоянно нуждается в усовершенствованиях, однако ваша помощь сберегла мне немало часов кропотливой работы, и дорогостоящих деталей вдобавок!$B$BПрошу вас, выбирайте любую из этих готовых моделей. Еще раз спасибо вам, $N! Мы с моими роботами – ваши должники!' WHERE ID=2767 AND locale='ruRU';

-- An OOX of Your Own - Small correction.
-- https://www.wowhead.com/wotlk/quest=3721/an-oox-of-your-own
UPDATE quest_template_locale SET Title='Собственный КПХ' WHERE ID=3721 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='Тебе удалось выручить всех трех моих роботов серии КПХ! Ты $Gсделал:сделала; всё, что требовалось и даже больше, поэтому я хочу особым образом отблагодарить тебя за помощь. Это миниатюрная версия того же робота, с которым ты $Gпровёл:провела; так много времени и $Gполюбил:полюбила;, КПХ!$B$BОбычно я никому не дарю такие опасные устройства, но ты $Gоказал:оказала; мне неоценимую помощь. Кроме того у этой тварюшки отключены боевые механизмы и устройство самонаведения.$B$BА в остальном это полноценный КПХ!' WHERE ID=3721 AND locale='ruRU';

-- The Borrower - Small correction.
-- https://www.wowhead.com/wotlk/quest=2941/the-borrower
UPDATE quest_offer_reward_locale SET RewardText='А, ты $Gодин:одна; из $Gстудентов:студенток; Дарин? Она очень сведущий историк, $N. Тебе повезло, что ты занимаешься под её руководством.$B$BНу, давай я покажу тебе свой суперщёлк. Он тебе понравится!' WHERE ID=2941 AND locale='ruRU';

-- Confront Yeh'kinya - Small correction.
-- https://www.wowhead.com/wotlk/quest=8181/confront-yehkinya
UPDATE quest_offer_reward_locale SET RewardText='Значит, ты $Gпоговорил:поговорила; с этим старым дворфом Железным Башмаком и $Gотыскал:отыскала; утраченные таблички Мошару? Ох, уж этот геолог, сующий нос не в своё дело…$B$BНеважно. Мир уже не спасти. Хаккар возродился, и сила его растёт с каждым часом... далеко-далеко, в глубинах древнего королевства Зул\'Гуруба! Он вернулся! И теперь затопит мир кровью и ужасом!$B$BСпасибо, $N. Ты $Gпомог:помогла; ускорить возвращение Свежевателя Душ!' WHERE ID=8181 AND locale='ruRU';

-- Moontouched Wildkin - Small correction.
-- https://www.wowhead.com/wotlk/quest=978/moontouched-wildkin
UPDATE quest_template_locale SET Details='Перья диких совухов из Внутренних земель, кажется, содержат следы магии. Эти силы... непохоже, что создания способны их контролировать, больше похоже на то, что магия просто является частью их сущности. $b$bЗа время моих исследований я слыхал, что большая популяция диких совухов населяет заснеженные земли Зимних Ключей. Вдруг у этих существ есть те же свойства? Пожалуйста, $n, помогите мне найти ответ. Отправляйтесь в Зимние Ключи, соберите выпавшие перья и возвращайтесь с ними ко мне.' WHERE ID=978 AND locale='ruRU';

-- The Super Snapper FX - Small correction.
-- https://www.wowhead.com/wotlk/quest=2944/the-super-snapper-fx
UPDATE quest_request_items_locale SET CompletionText='А, $N, вот наконец и ты! У тебя с собой прибор, который изготовила для меня Кургль? Отлично!' WHERE ID=2944 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='О да! Изобретение Кургль оправдало все мои ожидания!$B$BТы только не зазнавайся, $N, но имей в виду, что я тобой довольна.$B$BТак, где же я оставила эту книгу...' WHERE ID=2944 AND locale='ruRU';

-- A Land Filled with Hatred - Small correction.
-- https://www.wowhead.com/wotlk/quest=5536/a-land-filled-with-hatred
UPDATE quest_offer_reward_locale SET RewardText='Отличная работа, $C. Вижу, ты не только $Gсилён:сильна;, но и $Gхитёр:хитра;. Битва с сатирами была испытанием твоей преданности Матери-Земле, даже если ты поклоняешься другим богам. Она пронизывает всё сущее в нашем мире и за его пределами. Два ока её, тёмное и светлое, всегда взирают на нас с небес. Прошу тебя, прими эту скромную плату в знак моей признательности.' WHERE ID=5536 AND locale='ruRU';

-- Gobjects GUID 48453 (Entry: 149482) - [Rune of Markri X:3465.709961 Y:-5272.910156 Z:89.200104 MapId:1], 
-- Gobjects GUID 48452 (Entry: 149481) - [Rune of Beth'Amara X:3543.909912 Y:-5148.910156 Z:82.913597 MapId:1],
-- Gobjects GUID 48450 (Entry: 149480) - [Rune of Jin'yael X:3642.439941 Y:-5283.040039 Z:90.283203 MapId:1],
-- Gobjects GUID 48455 (Entry: 149483) - [Rune of Sael'hai X:3172.750000 Y:-5426.290039 Z:90.584198 MapId:1] 
-- Missing locale.
DELETE FROM gameobject_template_locale WHERE entry=149482 AND locale='ruRU';
DELETE FROM gameobject_template_locale WHERE entry=149481 AND locale='ruRU';
DELETE FROM gameobject_template_locale WHERE entry=149480 AND locale='ruRU';
DELETE FROM gameobject_template_locale WHERE entry=149483 AND locale='ruRU';
INSERT INTO gameobject_template_locale (entry, locale, name, VerifiedBuild) VALUES ('149482', 'ruRU', 'Руна Маркри', 0);
INSERT INTO gameobject_template_locale (entry, locale, name, VerifiedBuild) VALUES ('149481', 'ruRU', 'Руна Бет\'Амары', 0);
INSERT INTO gameobject_template_locale (entry, locale, name, VerifiedBuild) VALUES ('149480', 'ruRU', 'Руна Джин\'яэль', 0);
INSERT INTO gameobject_template_locale (entry, locale, name, VerifiedBuild) VALUES ('149483', 'ruRU', 'Руна Саэл\'Хаи', 0);

-- Impsy <Niby's Minion> - Missing greeting. Also the value in table quest_greeting is absent.
-- https://www.wowhead.com/wotlk/npc=14470/impsy
DELETE FROM quest_greeting_locale WHERE ID=14470 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('14470', 'ruRU', 'Приветствую, $N.', '0');
DELETE FROM quest_greeting WHERE ID=14470;
INSERT INTO quest_greeting (ID, Greeting, VerifiedBuild) VALUES ('14470', 'Greetings, $n.', '0');

-- Collection of the Corrupt Water - Small correction.
-- https://www.wowhead.com/wotlk/quest=5157/
UPDATE quest_request_items_locale SET CompletionText='Как только у нас будет вода из Лунного колодца, мы её очистим и с её помощью погасим эти жаровни защиты в Оплоте Теней. Это даст мне достаточно времени, чтобы заглянуть в ещё более глубокие чертоги и понять, кто же на самом деле возглавляет этот... культ.$B$BМолю Мать-Землю о помощи!' WHERE ID=5157 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='Это то, что надо, $N. Теперь нам остаётся только очистить воду и залить ей жаровни. Это будет нетрудно – придётся только совершить небольшое путешествие.$B$BНадеюсь, это мы провернём быстро.' WHERE ID=5157 AND locale='ruRU';

-- A Final Blow - Small correction.
-- https://www.wowhead.com/wotlk/quest=5242/a-final-blow
UPDATE quest_request_items_locale SET CompletionText='Теперь, без Скверн\'дана, Совет Теней потеряет цель и будет беспомощен. Они перегрызутся между собой за власть и сокровища - плату за будущие планы. А мы воспользуемся этим времением и вырежем и их, и их рабов-демонов.' WHERE ID=5242 AND locale='ruRU';

-- Nalesette Wildbringer <Pet Trainer> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=543/nalesette-wildbringer
UPDATE creature_template_locale SET Title='Дрессировщица' WHERE entry=543 AND locale='ruRU';

-- Wasteland - Small correction.
-- https://www.wowhead.com/wotlk/quest=1124/wasteland
UPDATE quest_request_items_locale SET CompletionText='Эти земли не прощают беспечности, $C. Что привело тебя в пустоши Силитуса?' WHERE ID=1124 AND locale='ruRU';

-- Small correction.
UPDATE quest_offer_reward_locale SET RewardText='Я просто в шоке от терродактилей! Спасибо тебе, $N! Теперь я хотя бы смогу спокойно высунуть нос из Укрытия Маршалла!' WHERE ID=4501 AND locale='ruRU';

-- Beware of Pterrordax - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=4501/beware-of-pterrordax
UPDATE quest_offer_reward_locale SET RewardText='Да, да, та самая смола…\r\n\r\nЭй, минуточку, руки мои, руки... Я не могу их разлепить…\r\n\r\nМожет быть, это не такая уж хорошая идея. Впрочем, стоп! Растворитель суперлипкой смолы! Вот что разойдется за полдня!' WHERE ID=4504 AND locale='ruRU';

-- Inconsistency with wowhead.
UPDATE quest_offer_reward_locale SET RewardText='Кровоцвет, говоришь? Хмм... В общем, сначала расскажи мне, что собираешься делать, а уж потом я скажу тебе, смогу ли помочь.' WHERE ID=4142 AND locale='ruRU';

-- A Visit to Gregan - Inconsistency with wowhead.
-- https://www.wowhead.com/wotlk/quest=4142/a-visit-to-gregan
UPDATE quest_offer_reward_locale SET RewardText='Поразительно! Сегодня мы одержали победу. Впрочем, нам понадобится время, чтобы разобраться с полученными материалами. Не волнуйся, всё пойдёт в дело.\r\n\r\nЧто до силитидов, я искренне сомневаюсь, что мы сумели остановить их нашествие. К сожалению, это было бы слишком легко.' WHERE ID=4507 AND locale='ruRU';

-- Noggle's Lost Satchel - Small correction.
-- https://www.wowhead.com/wotlk/quest=8282/noggles-lost-satchel
UPDATE quest_request_items_locale SET CompletionText='Ты ещё не $Gнашёл:нашла; мою сумку? С другой стороны, грех жаловаться, от яда-то меня излечили.' WHERE ID=8282 AND locale='ruRU';

-- Still Believing - Small correction.
-- https://www.wowhead.com/wotlk/quest=8324/still-believing
UPDATE quest_request_items_locale SET CompletionText='Ты $gнашёл:нашла; новые зашифрованные тексты? Принеси мне целую кипу, на расшифровку уходит немало времени.' WHERE ID=8324 AND locale='ruRU';

-- Winterfall Ritual Totem - Small correction.
-- https://www.wowhead.com/wotlk/quest=8471/winterfall-ritual-totem
UPDATE quest_request_items_locale SET CompletionText='$C, ты пришёл к нам с миром, но я вижу, что у тебя очень важная цель. Важная не только для фурболгов, но и для твоих соплеменников, $R. О чём ты хочешь нам поведать?' WHERE ID=8471 AND locale='ruRU';

-- Enraged Wildkin - Small correction.
-- https://www.wowhead.com/wotlk/quest=4864/enraged-wildkin
UPDATE quest_offer_reward_locale SET RewardText='Ну, примерно это я и ожидал услышать, $Gпарень:подруга;. Я уж было думал, что свихнувшиеся звери раздраконили все мои пожитки…$B$BНо тебе удалось найти мои инструменты и, что еще важнее, амулет! Интересно, почему дикие совухи так яростно его защищали… В любом случае, я теперь дважды подумаю, прежде чем сунуться к ним опять!' WHERE ID=4864 AND locale='ruRU';

-- Shy-Rotam - Small correction.
-- https://www.wowhead.com/wotlk/quest=5056/shy-rotam
UPDATE quest_offer_reward_locale SET RewardText='Ты $Gдоказал:доказала; как свою силу, так и решимость. Ещё много испытаний ждёт тебя впереди. Я показал тебе всё, что мог.' WHERE ID=5056 AND locale='ruRU';

-- Missing locale
UPDATE quest_template_locale SET Details='Слушай мой план, $N: пойди и собери для меня немного ростков кровоцвета – молодых, которые ещё не успели полностью развиться. А потом посмотрим, как они отреагируют на туман Аталаи.\r\n\r\nТы думаешь, я слишком злопамятен? Ну, в общем так и есть.\r\n\r\nНа самом деле, я знаю дорогу отсюда, но пока Ларион не признает мою правоту, я отсюда не уйду.\r\n\r\nНу, иди, принеси мне ростков, и мы славно повеселимся!', Objectives='Ростки кровоцвета' WHERE ID=4144 AND locale='ruRU';

-- Bloodpetal Sprouts - Small correction.
-- https://www.wowhead.com/wotlk/quest=4144/bloodpetal-sprouts
UPDATE quest_offer_reward_locale SET RewardText='Отлично! Благодарю тебя, $N!$B$BТеперь надо подумать, как именно приготовить эти языки, чтобы наилучшим образом подчеркнуть их изысканный вкус.$B$BНаконец-то у меня есть блюдо, достойное завсегдатаев "Печального отшельника" в Штормграде.' WHERE ID=1204 AND locale='ruRU';

-- Stinky's Escape - Small correction. (Blue Recluse = Sad Recluse in ruRU)
-- https://www.wowhead.com/wotlk/quest=1222/stinkys-escape
UPDATE quest_offer_reward_locale SET RewardText='Мистер Игнац не так давно приносил листья болотного боба, и он расказал мне, что вы помогли ему выбраться из весьма затруднительной ситуации.$B$BБлагодарю вас, $n. Я попрошу своего дядю принять вас по-королевски, когда вы в следующий раз окажетесь в "Печальном отшельнике", в Штормграде.' WHERE ID=1222 AND locale='ruRU';

-- Snickerfang Jowls - Small correction.
-- https://www.wowhead.com/wotlk/quest=2581/snickerfang-jowls
UPDATE quest_template_locale SET Details='Хорошо известно, что челюсти гиены невероятно сильны, но чтобы они были способны прокусить три дюйма ториевой стали? Невозможно, невероятно, и тем не менее я видел это своими глазами.$B$BОтправляйся в Выжженные земли и принеси мне три челюсти гиены-хохотуна. А пока ищешь гиен, высматривай также кабанов и скорпоков: для дополнения к изначальной эссенции требуется также два обожженных легких вепря и одна клешня скорпока.' WHERE ID=2581 AND locale='ruRU';

-- Snickerfang Jowls - Small correction.
-- https://www.wowhead.com/wotlk/quest=2581/snickerfang-jowls
UPDATE quest_offer_reward_locale SET RewardText='Как самочувствие, $N? Ты излучаешь ауру гиены-хохотуна – силу, с которой никто из смертных не сравнится!$B$BК несчастью, из принесенных тобой компонентов я смогу сделать эссенции только на одну таблетку. Если тебе понадобится еще одна таблетка, мне нужно будет больше компонентов.' WHERE ID=2581 AND locale='ruRU';

-- The Dark Missive - Small correction.
-- https://www.wowhead.com/wotlk/quest=10395/the-dark-missive
UPDATE quest_template_locale SET Details='Текст, судя по всему, написан на каком-то странном языке, неразборчивым и спутанным почерком. Чем больше вы на него смотрите, тем труднее что-нибудь разобрать, и в конце концов буквы начинают прыгать перед глазами. Похоже, понять этот странный почерк сможет одно существо в Оплоте Чести – дренейский провидец бед Крив.' WHERE ID=10395 AND locale='ruRU';

-- Warlord of the Bleeding Hollow - Small correction.
-- https://www.wowhead.com/wotlk/quest=10485/warlord-of-the-bleeding-hollow
UPDATE quest_template_locale SET Details='Должно быть, ты необычайно $gловок и удачлив:ловка и удачлива;, если тебе удалось проникнуть в Зет\'Гор и выбраться оттуда $gживым:живой;. Надеюсь, удача и дальше тебя не оставит, потому что у меня есть новое дело.$B$BВ Зет\'Горе засел Предводитель Морк, который командует армиями орков Скверны. Он превосходный полководец, и, с прискорбием вынуждена отметить, он раз за разом одерживает над нами победу. Так что у меня к тебе просьба, $n, – надо бы отправить этого Морка в отставку. Принеси мне его броню, мы покажем её солдатам для поднятия боевого духа.' WHERE ID=10485 AND locale='ruRU';

-- Fei Fei's Treat - Small correction.
-- https://www.wowhead.com/wotlk/quest=10919/fei-feis-treat
UPDATE quest_request_items_locale SET CompletionText='Шар-Ик выжидающе смотрит на тебя...' WHERE ID=10919 AND locale='ruRU';

-- The Balance of Light and Shadow - Small correction.
-- https://www.wowhead.com/wotlk/quest=7622/the-balance-of-light-and-shadow
UPDATE quest_offer_reward_locale SET RewardText='Твои смелость и упорство не имеют себе равных, $C. Ты $Gобрёл:обрела; право владеть расщепителем Нордрассила. Тебе осталось исполнить лишь одно: найти Око Тени. Найди его, даже если тебе придется обыскать весь мир.' WHERE ID=7622 AND locale='ruRU';

-- Lord Banehollow - Small correction.
-- https://www.wowhead.com/wotlk/quest=7623/lord-banehollow
UPDATE page_text_locale SET Text='Чтобы подчинить коня погибели, нужно сделать три вещи:\r\n\r\nсотворить Круг Великого Призыва.\r\n\r\nВнутри этого круга открыть портал в Зорот и вывести коня через него.\r\n\r\nПобедить его и покорить его дух.\r\n\r\nНа следующих страницах подробно описан каждый из трех шагов. Сделать это непросто, но ты $gдоказал:доказала;, что способности у тебя есть. Я уверен, что ты со своей целеустремленностью подчинишь себе коня гибели.\r\n\r\nЧитай дальше.\r\n-Мор\'зул Вестник Крови' WHERE ID=2691 AND locale='ruRU';
UPDATE `quest_offer_reward_locale` SET `RewardText`='Моё терпение бесконечно, $c. Но это не значит, что я уделю тебе больше секунды времени...' WHERE  `ID`=7623 AND `locale`='ruRU';

-- Dreadsteed - Small correction.
UPDATE page_text_locale SET Text='Составляющие Ритуала\r\n\r\nПеред началом ритуала у тебя должны быть следующие компоненты:\r\n\r\nКувшин Д\'жииви\r\nЧёрный Магнит\r\nЗоротианские Иероглифы\r\n\r\nЗа определённую цену мой слуга Горзиеки добудет их для тебя. Без них ни одно действие ритуала выполнять нельзя. Каждый компонент очень важен.\r\n\r\nНа следующих страницах я подробно опишу их применение.' WHERE ID=2692 AND locale='ruRU';

-- Dreadsteed - Small correction.
UPDATE page_text_locale SET Text='Колокол, Колесо и Свеча\r\n\r\nОсвободившись, Д\'жииви разместит Колокол, Колесо и Свечу, после чего появится круг. Так начинается ритуал. Нужно сохранять бдительность: упомянутые предметы испускают мощные потоки энергии и могут разрушиться. Если это случится, скорее используй Черный магнит, чтобы восстановить их, прежде чем весь ритуал пойдет насмарку.\r\nЕсли все три предмета разрушатся прежде, чем ты сумеешь их восстановить, ритуал закончится и его надо будет начинать заново.' WHERE ID=2694 AND locale='ruRU';

-- Dreadsteed - Small correction.
UPDATE page_text_locale SET Text='Завершение ритуала\r\n\r\nХод ритуала можно проследить по волшебным рунам на краю круга. Когда там проступят девять рун, ритуал полностью завершится, и ты увидишь, как из заряженного Круга исходит энергия.\r\n\r\nЗатем ты сможешь использовать Зоротианские Иероглифы, чтобы открыть портал в Зорот и вывести через него коня погибели.\r\n\r\nПобеди коня и выпусти его дух. Одержи победу над духом, и тогда он будет порабощен, а ты узнаешь секрет его призыва.' WHERE ID=2697 AND locale='ruRU';

-- Overlord - Small correction.
-- https://www.wowhead.com/wotlk/quest=10400/overlord
UPDATE quest_offer_reward_locale SET RewardText='Хвала Свету, я знал, что ты справишься! Больше нет Араззиуса и его прислужников! Скоро, очень скоро мы заставим Легион убраться с этих исстрадавшихся земель, и здесь снова воцарится мир. На эти земли придет справедливость, а мы сами сможем вернуться домой.$B$BСегодня Альянс и Сыны Лотара возносят тебе хвалу, $N!' WHERE ID=10400 AND locale='ruRU';

-- Arzeth's Demise - Small correction. Read it letter by letter!
-- https://www.wowhead.com/wotlk/quest=10369/arzeths-demise
UPDATE quest_request_items_locale SET CompletionText='Ты $gсправился:справилась; $N? Арзет мёртв?' WHERE ID=10369 AND locale='ruRU';

-- The Seer's Relic - Small correction.
-- https://www.wowhead.com/wotlk/quest=9545/the-seers-relic
UPDATE quest_template_locale SET Objectives='Вернитесь к телу Седаи, которое находится к северо-востоку от храма Телхамат, и используйте там реликвию ясновидца по просьбе Амаана Мудрейшего из храма Телхамат на полуострове Адского Пламени. После выполнения задания возвращайтесь к Амаану.' WHERE ID=9545 AND locale='ruRU';

-- Road signs in Zangarmarsh. See location name from official translation
-- https://www.wowhead.com/wotlk/ru/zone=3522/острогорье
UPDATE gameobject_template_locale SET name='Острогорье' WHERE entry=182379 AND locale='ruRU';
UPDATE gameobject_template_locale SET name='Острогорье' WHERE entry=182411 AND locale='ruRU';
UPDATE gameobject_template_locale SET name='Острогорье' WHERE entry=182373 AND locale='ruRU';
UPDATE gameobject_template_locale SET name='Острогорье' WHERE entry=182286 AND locale='ruRU';

-- Drain Schematics - Small correction.
-- https://www.wowhead.com/wotlk/quest=9731/drain-schematics
UPDATE quest_template_locale SET Details='На добытой вами схеме изображена система подземных труб и насосов, ведущих от крупных озер Зангартопи к Змеиному озеру.$b$bЕсли верить этой схеме, в центре Змеиного озера находится огромная труба, куда и уходит вода. Проверьте эту информацию и передайте ее в Кенарийский оплот.' WHERE ID=9731 AND locale='ruRU';

-- More Spore Sacs - Small correction.
-- https://www.wowhead.com/wotlk/quest=9742/more-spore-sacs
UPDATE quest_offer_reward_locale SET RewardText='Да! Благодаря тебе спасено ещё несколько мешочков со спорами!$B$BТы не $Gтакой:такая;, как другие пришельцы. Я поведаю моему народу о твоих деяниях!$B$B<Это задание можно выполнять повторно до тех пор, пока не добьёшься дружелюбного отношения.>' WHERE ID=9742 AND locale='ruRU';

-- Emissary Valustraa <Mage Trainer> - Missing title
-- https://www.wowhead.com/wotlk/npc=25195/marksman-bova
UPDATE creature_template_locale SET Title='Продавец особых боеприпасов' WHERE entry=25195 AND locale='ruRU';

-- Emissary Valustraa <Mage Trainer> - Missing title
-- https://www.wowhead.com/wotlk/npc=25196/archer-delvinar
UPDATE creature_template_locale SET Title='Продавец особых боеприпасов' WHERE entry=25196 AND locale='ruRU';

-- Road signs in Tanaris - Small correction.
UPDATE gameobject_template_locale SET name='Порт Хитрой Шестерёнки' WHERE entry=151975 AND locale='ruRU';
UPDATE gameobject_template_locale SET name='Порт Хитрой Шестерёнки' WHERE entry=151979 AND locale='ruRU';
UPDATE gameobject_template_locale SET name='Порт Хитрой Шестерёнки' WHERE entry=151984 AND locale='ruRU';

-- Spring Collector - Missing greeting. Also the value in table quest_greeting is absent.
-- https://www.wowhead.com/wotlk/npc=32799
DELETE FROM quest_greeting_locale WHERE ID=32799 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('32799', 'ruRU', 'Приветствую, $N.', '0');
DELETE FROM quest_greeting WHERE ID=32799;
INSERT INTO quest_greeting (ID, Greeting, VerifiedBuild) VALUES ('32799', 'Greetings, $n.', '0');

-- Ossirian the Unscarred - missing locale
-- https://www.wowhead.com/wotlk/npc=15339/ossirian-the-unscarred
DELETE FROM creature_text_locale WHERE CreatureID=15339 AND Locale='ruRU';
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15339', '1', '1', 'ruRU', 'По местам! Защищайте город!');
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15339', '1', '2', 'ruRU', 'Нарушители будут уничтожены!');
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15339', '0', '0', 'ruRU', 'Я омолодился!');
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15339', '0', '1', 'ruRU', 'Мои силы восстановлены!');
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15339', '0', '2', 'ruRU', 'Мои силы возвращаются!');
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15339', '1', '0', 'ruRU', 'Защитите город любой ценой!');
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15339', '2', '0', 'ruRU', 'Пески пустыни, поднимитесь и затмите солнце!');
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15339', '3', '0', 'ruRU', 'Вы ликвидированы.');
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15339', '4', '0', 'ruRU', 'Я...потерпел... неудачу.');
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15339', '5', '0', 'ruRU', 'Стены были проломлены!');
DELETE FROM creature_text_locale WHERE CreatureID=15263 AND Locale='ruRU';
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15263', '0', '2', 'ruRU', 'Трепещите! Ваш конец близок.');
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15263', '2', '0', 'ruRU', 'Приготовьтесь к возвращению Древних!');
INSERT INTO creature_text_locale (CreatureID, GroupID, ID, Locale, Text) VALUES ('15263', '0', '1', 'ruRU', 'Трепещите, смертные! Наступает эпоха тьмы.');

-- Shroud of Unspoken Names - Small correction.
-- https://www.wowhead.com/wotlk/quest=8694/shroud-of-unspoken-names
UPDATE quest_offer_reward_locale SET RewardText='О да... Эта пелерина безукоризненна.$B$BВозьми её, $N. Пусть она защитит тебя от нечистой магии киражей.' WHERE ID=8694 AND locale='ruRU';
