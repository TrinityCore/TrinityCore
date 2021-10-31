-- I did not notice last time that the NPC refers to the character by gender. / Не заметил в прошлый раз то, что НПЦ обращается к персонажу по полу.
UPDATE `quest_request_items_locale` SET `VerifiedBuild`=0, `CompletionText`='Тебе было дано задание, $N. Ты $Gпринёс:принесла; мне кристалл лича в доказательство его выполнения?' WHERE  `ID`=211 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Убито мстительных дренеев' WHERE  `ID`=10842 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Детей спасено' WHERE  `ID`=10852 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Освобождено воинов Ша\'тар' WHERE  `ID`=10873 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Сожжено тел павших воздаятелей Ша\'тар', `ObjectiveText2`='Сожжено тел убитых аукенайских воинов' WHERE  `ID`=10913 AND `locale`='ruRU';
-- The NPC does not say that he grabs his head, he just does it. / НПЦ не говорит, что он хватается за голову, он просто делает это.
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='<Командир Ра\'вадж хватается за голову>$B$BЭтого мало... Этого совершенно недостаточно.' WHERE  `ID`=10913 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Содержимое Аукенайского гроба уничтожено' WHERE  `ID`=10915 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Освобождено птенцов' WHERE  `ID`=10861 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Сапфирный огонь потушен', `ObjectiveText2`='Изумрудный огонь потушен', `ObjectiveText3`='Фиолетовый огонь потушен', `ObjectiveText4`='Огонь Кровавого камня потушен' WHERE  `ID`=10874 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Странный предмет исследован' WHERE  `ID`=9971 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Вы поговорили с Мрачным посвящённым', `ObjectiveText2`='Вы поговорили с Мрачным работником', `ObjectiveText3`='Вы поговорили с Мрачным советником' WHERE  `ID`=10040 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText2`='Мана-бомба активирована' WHERE  `ID`=10446 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText2`='Мана-бомба активирована' WHERE  `ID`=10447 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Большой дом уничтожен', `ObjectiveText2`='Западная лачуга уничтожена', `ObjectiveText3`='Южная лачуга уничтожена', `ObjectiveText4`='Восточная лачуга уничтожена' WHERE  `ID`=9805 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Вы поговорили с Глыбом' WHERE  `ID`=9918 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Сожжено трупов селян Солнечного Источника' WHERE  `ID`=9874 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Корки освобождён' WHERE  `ID`=9923 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Корки освобождён в очередной раз' WHERE  `ID`=9924 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Корки свободен' WHERE  `ID`=9955 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Попытайтесь украсть яйцо' WHERE  `ID`=10111 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Знамя огров Боевого Молота установлено' WHERE  `ID`=9927 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Знамя Вечной Скорби установлено' WHERE  `ID`=9931 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Трупы врагов живописно разложены' WHERE  `ID`=9932 AND `locale`='ruRU';
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='Ребёнок прав. Когда-то я в самом деле был "жрецом мертвых".$B$B<Рамдор кривится.>$B$BМалоприятный титул.$B$BЭтот коридор ведёт в Аукенайские гробницы. Там, внутри, ты найдёшь то, что осталось от моей паствы. Разумеется, теперь все они совершенно безумны. Сошли с ума, все до единого. Очевидно, я слишком выделялся среди них, будучи единственным, кто сохранил хотя бы остатки здравого смысла. Конечно же, меня изгнали за мои убеждения.$B$BХочешь знать, за какие?' WHERE  `ID`=10227 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Паруса "Син-лорен" горят', `ObjectiveText2`='Паруса "Кровавой клятвы" горят', `ObjectiveText3`='Паруса "Рассветного Охотника" горят' WHERE  `ID`=11543 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Эмиссар Ненависти пронзён древком' WHERE  `ID`=11537 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Показания Портала получены', `ObjectiveText2`='Показания Святилища получены', `ObjectiveText3`='Показания Кровавого кристалла получены' WHERE  `ID`=11547 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Освобождено зеленожабрых-рабов' WHERE  `ID`=11541 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Введено в действие новообращённых караульных' WHERE  `ID`=11525 AND `locale`='ruRU';
UPDATE `quest_request_items_locale` SET `VerifiedBuild`=0, `CompletionText`='Ты $Gисполнил:исполнила; своё поручение, $N?' WHERE  `ID`=11533 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Убито огров Кровавого Молота' WHERE  `ID`=10505 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Убито огров Кровавого Молота' WHERE  `ID`=10502 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Южная вулканическая почва', `ObjectiveText2`='Центральная вулканическая почва', `ObjectiveText3`='Северная вулканическая почва' WHERE  `ID`=10771 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Позвольте Даранелле изучить дух калири' WHERE  `ID`=10556 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Опьянело Огров Камнерогов' WHERE  `ID`=10512 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Убито огров Камнерогов' WHERE  `ID`=10504 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Усилено лютых волков клана Громоборцев' WHERE  `ID`=10488 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Призвано защитников Живой рощи' WHERE  `ID`=10457 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Ослаблено лютых волков клана Кровавого Молота' WHERE  `ID`=10506 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Поймано электроменталей' WHERE  `ID`=10584 AND `locale`='ruRU';
-- Description in Russian must be feminine. The substance is "she". / Описание на русском языке должно быть в женском роде. Субстанция - это она.
-- UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Постарше, хотя не менее отвратительная.' WHERE  `ID`=30782 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Абсорбировано ударов молний' WHERE  `ID`=10657 AND `locale`='ruRU';
-- Removed the repeating word "она" (she, the trap). / Убрал повторяющееся слово "она" (ловушка).
-- UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `Details`='Эфириалы – Разаани – экспериментировали с одной интересной технологией в лагере Разаана, что на севере отсюда.$B$BЯ уверен, что они не будут против, если вы поставите эту ловушку, чтобы поймать несколько образцов их розовых летучих световых шариков? Они все равно наверняка только для украшения.$B$BУ ловушки есть специальное свойство – когда она открыта, она притягивает к себе эти летучие шарики. Конечно, это может всполошить астральных духов и привлечь их к вам.' WHERE  `ID`=10674 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Поймано световых сфер братства Разаани' WHERE  `ID`=10674 AND `locale`='ruRU';
-- The Bloodmaul ogres are not from Sylvanaar, they attacked him. Fixed a logical error by taking the text from the WoWhead. / Огры клана Кровавого Молота не из Сильванаара, они на него напали. Исправил логическую ошибку, взяв текст на вовхеде.
-- UPDATE `quest_template_locale` SET `Details`='Дурные вести. Горгром Драконоед стоит за недавней вылазкой Кровавых Молотов в Сильванаар!$B$BКак ему удается манипулировать ими, причем не только натравливая на них Камнерогов – я не знаю. Но если мы хотим разделаться с гронном, нам понадобится помощь.$B$BЯ знаю одного человека, который владеет необычной магией. Барон Черногрив зовут его. Ты найдешь его в Круге Крови, если пойдешь вниз по юго-западному склону, а затем на юго-запад по каньону.$B$BПопроси его сделать для нас ловушку на гронна.' WHERE  `ID`=10798 AND `locale`='ruRU';
-- Corrected a typo (the letter was missing). / Исправил опечатку (отсутствовала буква).
-- UPDATE `quest_template_locale` SET `Details`='Мы должны показать этим ограм, что с нами шутки плохи! Так что надо вправить им мозги.$b$bИди в Камен\'мок и перебей тамошних огров. Забери их головы.$b$bА потом ступай к алтарю Горгрома и поставь там на него ловушку. Горгром явится – замани его в ловушку. Когда он сдохнет, поставь свои тотемы гризли возле его туши, чтобы огры, увидев своего убитого хозяина и сородичей поняли, что им будет за нападения на нас!' WHERE  `ID`=10802 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Установлено тотемов гризли' WHERE  `ID`=10802 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Получите первое пророчество', `ObjectiveText2`='Получите второе пророчество', `ObjectiveText3`='Получите третье пророчество', `ObjectiveText4`='Получите четвёртое пророчество' WHERE  `ID`=10607 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Лагерь Легиона Ненависть уничтожен', `ObjectiveText2`='Лагерь Легиона Страх уничтожен' WHERE  `ID`=10011 AND `locale`='ruRU';
-- Again, these double translations into Russian... There is no such character "Ганни" ("Gunny") in the Russian version, but there is "Пушкаренок" ("Pushkarenok", essentially the same as "Gunny") and he stands next to Danat in the  Honor Hold. / Опять эти двойные переводы на русский… Нет такого персонажа "Ганни" в русской версии, зато есть "Пушкаренок" и стоит он рядом с Данатом в Оплоте Чести.
-- UPDATE `quest_offer_reward_locale` SET `RewardText`='Говоришь, на нем стоит подпись Иллидана? Дай-ка взглянуть.$B$B*Командир читает письмо, задумывается на минуту, затем снова его перечитывает."$B$BЭто действительно зловещие новости. Мы должны как можно быстрее воплотить в жизнь наш план атаки на Цитадель Адского Пламени и Кузню Крови. Ты $gдоказал:доказала;, что отлично справляешься с работой, так что именно ты этим и займешься.$B$BПушкаренок даст тебе новое задание, думаю, оно будет куда более смертоносным, чем предыдущее.$B$BДа хранит тебя Свет, $N!' WHERE  `ID`=9587 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Найден землепряд Гневвс', `ObjectiveText2`='Найден натуралист Кус', `ObjectiveText3`='Найден культиватор Зеленопал', `ObjectiveText4`='Найден призыватель ветров Коготь' WHERE  `ID`=9738 AND `locale`='ruRU';
-- Added signs  <> / Добавил знаки <>
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='<Спорлинг издает звук, отдаленно напоминающий хмыканье.>$B$BВеликолепно! Несомненно, боевой дух споровых великанов упадет ниже дна болота, как только они поймут, что тебе удалось совершить.$B$BПравда, возможно, они так разгневаются, что нападут на нас снова...$B$B<Тшу делает такое движение, как будто пожимает плечами.>' WHERE  `ID`=9717 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Перезарядка батарей' WHERE  `ID`=10190 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText2`='Манагорн Б\'наар выключен' WHERE  `ID`=10329 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Гиперротационный Рой-О-Мат возвращён', `ObjectiveText2`='Сервоприводная пневматическая землечерпалка возвращена', `ObjectiveText3`='Радужный световой анализатор грунта возвращён', `ObjectiveText4`='Большой фургон с взрывчаткой возвращён' WHERE  `ID`=10203 AND `locale`='ruRU';
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='Я всегда буду тосковать по Живчику.$B$B<Хлюпает носом.>$B$BНо мы все будем спать спокойнее теперь, зная, что Доктор Бум больше не будет терроризировать нас!$B$BПусть это послужит тебе уроком! Никогда не спускайся сюда без шлема Пустоты!$B$BНу что ж, чем я могу оплатить твои хлопоты?' WHERE  `ID`=10221 AND `locale`='ruRU';
-- Description of the NPC action, which should be in <>, because without the brackets it seems as if the NPC is saying this. / Описание действия НПЦ, которое должно быть в <>, потому что без скобок кажется, будто НПЦ это говорит.
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='*Изображение верховного мага Варгота изучает тебя, пока ты пересказываешь сообщение Равандвира.*$B$BРавандвир наделен всем, что любой учиитель хотел бы видеть в своём ученике. Когда я отдал ему этот посох и приказал бежать, я надеялся, что он использует этот посох, дабы найти помощь и освободить меня, как только войска Кель\'таса отступят от башни. С тех пор я многое узнал о природе проклятья.$B$BПроклятье можно разбить, $N, но для этого потребуется твоя помощь.' WHERE  `ID`=10174 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText2`='Манагорн Коруу выключен' WHERE  `ID`=10330 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText2`='Манагорн Даро выключен' WHERE  `ID`=10338 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText2`='Манагорн Ара выключен' WHERE  `ID`=10365 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Упокойте дух Белмары' WHERE  `ID`=10305 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Упокойте дух Колиена' WHERE  `ID`=10307 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Упокойте дух Люминрата' WHERE  `ID`=10306 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText2`='Упокойте дух Датрика' WHERE  `ID`=10182 AND `locale`='ruRU';
-- There is no "guardian" (блюститель) in the Russian version, but there is a "commandant" (комендант).  / Никакого "блюстителя" в русской версии нет, зато есть "комендант".
-- UPDATE `quest_offer_reward_locale` SET `RewardText`='Комендант выглядит встревоженным.$B$BЯ уже вижу новую волну, вздымающуюся на горизонте. Истребление этих тварей поможет лишь на некоторое время, однако нужны более действенные меры.' WHERE  `ID`=10185 AND `locale`='ruRU';
-- There is no "guardian" (блюститель) in the Russian version, but there is a "commandant" (комендант).  / Никакого "блюстителя" в русской версии нет, зато есть "комендант".
-- UPDATE `quest_offer_reward_locale` SET `RewardText`='Комендант улыбается при упоминании имени Колиена.$B$BНасчёт шляпы – все именно так. Он всё время носил её, а если снимал, то не спускал с неё глаз.$B$BПару раз один из его товарищей-магов, оставшийся неизвестным, "заимствовал" шляпу и прятал её – просто в шутку. Но угроза получить от Колиена одну из его ледяных стрел заставила его отказаться от подобных шуток.$B$BЯ буду скучать по маленькому Колиену. Он умел найти подход к эльфийским дамам.' WHERE  `ID`=10307 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Уничтожено баллист Ярости Солнца', `ObjectiveText2`='Уничтожено шатров Ярости Солнца' WHERE  `ID`=10233 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Пробудите Восточную руну', `ObjectiveText2`='Пробудите Северо-восточную руну', `ObjectiveText3`='Пробудите Западную руну' WHERE  `ID`=10240 AND `locale`='ruRU';
-- Description of the NPC action, which should be in <>, because without the brackets it seems as if the NPC is saying this. / Описание действия НПЦ, которое должно быть в <>, потому что без скобок кажется, будто НПЦ это говорит.
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='<Ты не можешь сказать – искажается ли изображение или верховный маг действительно улыбается.>$B$BТеперь, когда мне возвращено всё, что было отобрано, у меня есть всё необходимое, дабы пробиться сквозь магию Кель\'таса. Я немедленно начинаю работать над заклинанием.' WHERE  `ID`=10209 AND `locale`='ruRU';
-- Description of the NPC action, which should be in <>, because without the brackets it seems as if the NPC is saying this. / Описание действия НПЦ, которое должно быть в <>, потому что без скобок кажется, будто НПЦ это говорит.
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='<Может быть, тебе и кажется, но похоже, что комендант Смертехрон с трудом сдерживает слёзы.>$B$BНаконец-то это свершилось. Если бы я мог по собственной воле завершить свое существование, я бы сделал это, но истина в том, что я не знаю, как уйти. Для обитателей деревни это сложно, однако всё впереди. Я полагаю, такова цена, которую мы платим за сильную привязанность к этому месту.' WHERE  `ID`=10223 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Узнайте, у кого хранятся ключи' WHERE  `ID`=10256 AND `locale`='ruRU';
-- Description of the NPC action, which should be in <>, because without the brackets it seems as if the NPC is saying this. / Описание действия НПЦ, которое должно быть в <>, потому что без скобок кажется, будто НПЦ это говорит.
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='<Ты описываешь результат наблюдения.>$B$BГоворишь, командир Сараннис? Хмм...$B$BОна одна из советников Кель\'таса, но определённо не маг. Я помню её – она была среди тех, кто напал на деревню Кирин\'Вар. Думаю, твоё прозрение оказалось верным, $N. Она не поддерживает проклятье сама, но хранит ключи от него.' WHERE  `ID`=10256 AND `locale`='ruRU';
-- Added a space after the comma. / Добавил пробел после запятой.
-- UPDATE `quest_template_locale` SET `Details`='Похоже, нашим деловым отношениям с эльфами крови наступает конец. Несколько дней назад при Манагорне Даро им была передана большая партия геодезического снаряжения. Они отказались платить за нее.$B$B$n, я хотел бы попросить тебя нанести визит эльфам крови в Манагорн Даро. Похоже, у них там какие-то неприятности в связи с нашествием мана-тварей, так что воспользуйся этим положением. $B$BМне все равно, что случится с ними, но мне очень хотелось бы вернуть назад нашу собственность.' WHERE  `ID`=10267 AND `locale`='ruRU';
-- Description of the NPC action, which should be in <>, because without the brackets it seems as if the NPC is saying this. / Описание действия НПЦ, которое должно быть в <>, потому что без скобок кажется, будто НПЦ это говорит.
UPDATE `quest_request_items_locale` SET `VerifiedBuild`=0, `CompletionText`='<Шаули возвышает голос, словно бы для того, чтобы привлечь внимание всех духов Астрала в округе.>$B$BНу что, есть шкуры на продажу?' WHERE  `ID`=10433 AND `locale`='ruRU';
-- Description of the NPC action, which should be in <>, because without the brackets it seems as if the NPC is saying this. / Описание действия НПЦ, которое должно быть в <>, потому что без скобок кажется, будто НПЦ это говорит.
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='<Шаули демонстративно осматривает шкуры.>$B$BОни великолепны, просто великолепны! Я заплачу по самой высокой цене! Ты не против ещё пару раз оказать мне услугу?' WHERE  `ID`=10433 AND `locale`='ruRU';
-- Description of the NPC action, which should be in <>, because without the brackets it seems as if the NPC is saying this. / Описание действия НПЦ, которое должно быть в <>, потому что без скобок кажется, будто НПЦ это говорит.
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='<Мердад кивает, затем изучает результаты диагностики.>$B$BТревожные показатели. Ущерб гораздо сильнее, чем я считал. Я могу послать в Штормовую Вершину за инструментами для ремонта, но это бесполезно, если мы, в первую очередь, не защитим генератор от того, что так сильно повредило его.' WHERE  `ID`=10417 AND `locale`='ruRU';
-- Fixed a typo in the name (see the title of the quest). / Исправил опечатку в имени (см название квеста).
-- UPDATE `quest_template_locale` SET `Details`='За восточной окраиной города располагается Испытательный полигон. Наш главный экспериментатор, доктор Вомиза, играл там с сочетанием технологий скверноботов, эфириалов и, конечно же, гоблинов.$B$BИ в немалой степени это удалось благодаря твоим усилиям по сбору сведений, младший лаборант 3-й степени $n!$B$BОтправляйся к доктору; я знаю, что он нашел решение проблемы – как спасти Зону 52.$B$BИ поскольку он скорее всего захочет задействовать тебя как объект для испытаний, то на твоем месте я на всякий случай взял бы с собой друга.' WHERE  `ID`=10247 AND `locale`='ruRU';
-- Corrected a typo in the name. / Исправил опечатку в имени.
-- UPDATE `quest_template_locale` SET `Objectives`='Активируйте пульт управления Утилизатора Х6000 и проверьте его возможности. Затем передайте результаты доктору псевдотехнических наук Вомизе, находящемуся на Испытательном полигоне в Пустоверти. Справьтесь со всеми возникающими проблемами.' WHERE  `ID`=10248 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Утилизатор Х6000 проверен' WHERE  `ID`=10248 AND `locale`='ruRU';
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='<Ты представляешься и сообщаешь результаты диагностики, проведенной Мердадом для эко-сферы "Срединные земли".>$B$BМердад – всего лишь техник, однако у него острый глаз на всякие мелочи. Если его наблюдение верно, нам нужно как можно скорее провести диагностику остальных наших генераторов эко-сферы.' WHERE  `ID`=10423 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText2`='Бездействующий сквернобот' WHERE  `ID`=10855 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Испытайте модулятор энергетического поля' WHERE  `ID`=10426 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText2`='Помечено талбуков' WHERE  `ID`=10427 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Первый геодезический знак размещён', `ObjectiveText2`='Второй геодезический знак размещён', `ObjectiveText3`='Третий геодезический знак размещён' WHERE  `ID`=10335 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Западный телепорт уничтожен', `ObjectiveText2`='Центральный телепорт уничтожен', `ObjectiveText3`='Восточный телепорт уничтожен' WHERE  `ID`=10857 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Капитан Тиралиус освобождён' WHERE  `ID`=10422 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText2`='Поговорите с капитаном Саидом' WHERE  `ID`=10439 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Сожжено высохших трупов' WHERE  `ID`=10345 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Стержень Бездны уничтожен' WHERE  `ID`=10438 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `Objectives`='Соберите 15 яиц драконов Пустоты, затем возвращайтесь к Тири и Джораду на Небесный Гребень.' WHERE  `ID`=10272 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `ObjectiveText1`='Убейте Вераку' WHERE  `ID`=10274 AND `locale`='ruRU';
-- The NPC that posted this ad has a different name. Name taken from WoWhead (npc  27042). / НПЦ, разместившего это объявление, зовут по-другому. Имя взято с вовхэда (npc 27042).
-- UPDATE `quest_template_locale` SET `Details`='Размещено: Иллюзия Люн.$B$BМясистый великан Плети, известный как Креуг Клятвопреступник, несет ответственность за смерть моего мужа, детей и моих дорогих друзей семьи Шелестящая Завеса. Тот, у кого хватит смелости претендовать на эту награду, может найти Креуга на юго-восточной оконечности Полей Падальщиков.$B$BЯ взываю о справедливости! Убейте Креуга Клятвопреступника!$B$BНа случай, если Креуг действительно будет убит, я выделила деньги и некоторые вещи и передала верховному лорду Леорику фон Цельдигу, чтобы они были выданы как награда.$B$BПожалуйста, защитите нас!' WHERE  `ID`=12438 AND `locale`='ruRU';
UPDATE `creature_template_locale` SET `VerifiedBuild`=0, `Title`='Боеприпасы' WHERE  `entry`=26901 AND `locale`='ruRU';
UPDATE `creature_template_locale` SET `VerifiedBuild`=0, `Title`='Боеприпасы' WHERE  `entry`=23862 AND `locale`='ruRU';
-- Typo. / Опечатка.
-- UPDATE `page_text_locale` SET `Text`='День 1: Как я и рассчитывал, жалкие людишки не заметили моего присутствия. Они готовятся к бомбежке, и мне не составит труда составить карту их диспозиций. .\r\n\r\nДень 2: Карты готовы – право, для такого опытного шпиона, как я, это было слишком просто. Не понимаю, зачем такое задание поручили мне – с ним справился бы и Дж. С. Правда, у него ужасный акцент. \r\n\r\nДень 3: Первый глоток воздуха уже слегка застоялся. Пожалуй, через несколько дней мне придется снова выглянуть на поверхность. Какая тоска – сидеть здесь и ждать сигнала.\r\n\r\n< Продолжение следует... >' WHERE  `ID`=3103 AND `locale`='ruRU';
-- The preposition "not" is missing, corrected. / Пропущен предлог "не", исправил.
-- UPDATE `quest_template_locale` SET `Details`='Я случайно услышал твой разговор с отцом Левариолом. Смею предположить, он не позволил тебе предпринять решительные действия.$B$BНо ты $gдолжен:должна; уничтожить врайкулов, спящих в глубине чертогов Пробуждения под Гьялерброном!$B$BЯ не сомневаюсь, что ритуалы, в которых они должны принять участие, могут иметь ужасные последствия! Скорее всего, у некролордов есть некое устройство, позволяющее пробудить их на время.$B$BУничтожь спящих – и врайкулы никогда не оправятся от таких потерь.' WHERE  `ID`=11432 AND `locale`='ruRU';
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='Отлично!\n\nОтныне ты $Gмой брат:моя сестра; по крови. Такую связь разорвать невозможно.\n\nА теперь слушай и запоминай, что тебе скажет Дракуру, |3-6($R). Нам предстоит многое совершить.' WHERE  `ID`=11989 AND `locale`='ruRU';
UPDATE `quest_request_items_locale` SET `VerifiedBuild`=0, `CompletionText`='Всё $Gпринёс, друг:принесла, подруга;?' WHERE  `ID`=11990 AND `locale`='ruRU';
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='<Дракуру берет у вас ингредиенты и смешивает их в пузырьке.>\n\nВот так, $Gдруг:подруга;. А теперь – за работу!' WHERE  `ID`=11990 AND `locale`='ruRU';
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='Ай, $Gмолодец, друг:умница, подруга;!\n\nОтсюда мне прекрасно видно надписи на стенах...' WHERE  `ID`=11991 AND `locale`='ruRU';
UPDATE `quest_request_items_locale` SET `VerifiedBuild`=0, `CompletionText`='Ты $Gдобыл:добыла; Око пророка, $Gдруг:подруга;?' WHERE  `ID`=12007 AND `locale`='ruRU';
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='Это впечатляет, $Gдружище:подруга;! Похоже, нас свела сама судьба.\n\nСкоро я отомщу моим братьям и очищу Драк\'Тарон, а ты получишь в награду его величайшее сокровище.' WHERE  `ID`=12802 AND `locale`='ruRU';
-- UPDATE `quest_template_locale` SET `Details`='<Дракуру кладет Око пророка себе на лоб, а Сердце древних – на грудь.>$b$bМы уже почти достигли цели, $Gдружок:подружка;!$b$bОсталось только найти скрижали Драккари. Никто не знает, когда они были написаны, и что именно они гласят, но око и сердце Дракуру помогут расшифровать послание. А лежат они глубоко в склепе Дракил\'джин, что к востоку отсюда. $b$bКак только найдешь скрижали, забери священный настой у оракулов и заступников. С его помощью ты сможешь призвать меня к себе. Не переживай – они будут счастливы умереть во имя благого дела.' WHERE  `ID`=12068 AND `locale`='ruRU';
UPDATE `quest_request_items_locale` SET `VerifiedBuild`=0, `CompletionText`='Рад видеть тебя, $N.\n\nЗначит, ты $Gнашёл:нашла; таблички?' WHERE  `ID`=12068 AND `locale`='ruRU';
-- UPDATE `quest_template_locale` SET `Details`='Скоро Драк\'Тарон будет очищен от этой мерзкой нежити и засияет во всей своей былой славе, а ты в награду за свои великие деяния обретешь великое сокровище!$b$bКогда доберешься до самой вершины, призови меня, чтобы я провел ритуал. $b$bУвы, но тебе снова придется заплатить за мой призыв. Ты $gдолжен:должна; будешь забрать моджо у выживших.' WHERE  `ID`=12238 AND `locale`='ruRU';
UPDATE `quest_offer_reward_locale` SET `VerifiedBuild`=0, `RewardText`='Мы совершили великое дело, $Gдружище:подруга;! И это только начало...\n\nКогда придет время, отыщи меня в Зул\'Драке.\n\nМы с тобой выиграем эту битву!' WHERE  `ID`=12238 AND `locale`='ruRU';
UPDATE `quest_request_items_locale` SET `VerifiedBuild`=0, `CompletionText`='Ты $Gдостал:достала; ингредиенты для старины Пригмона, $N?' WHERE  `ID`=12483 AND `locale`='ruRU';
UPDATE `quest_request_items_locale` SET `VerifiedBuild`=0, `CompletionText`='$GНашёл:Нашла; ли ты древние монолиты?' WHERE  `ID`=12094 AND `locale`='ruRU';
-- The pen is one. The description says that THEY are wonderful.  / Перо, оно одно. В описании написано что ОНИ замечательные.
-- UPDATE `item_template_locale` SET `Description`='Замечательное во всех отношениях.' WHERE  `ID`=37880 AND `locale`='ruRU';


-- Missing description of all 4-in-1 totems. / Отсутствующее описание всех тотемов 4-в-1.
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=22345 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=22395 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=22396 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=23005 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=23199 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=23200 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=24413 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=25645 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=27544 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=27815 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=27947 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=27984 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=28066 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=28248 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=28357 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=28523 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=29389 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=30023 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=31031 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=32330 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=33078 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=33505 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=33506 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=33507 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=33843 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=33939 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=33940 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=33941 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=33951 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=33952 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=33953 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=35104 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=35105 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=35106 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=37575 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=38361 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=38367 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=38368 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=39728 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=40267 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=40322 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=40708 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=40709 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=40710 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=42597 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=42598 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=42599 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=42602 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=42603 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=42604 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=42607 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=42608 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=42609 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=45114 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=45169 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=45255 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=46978 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=47665 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=47666 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=47667 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=50458 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=50463 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=50464 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=51501 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=51507 AND `locale`='ruRU';
UPDATE `item_template_locale` SET `VerifiedBuild`=0, `Description`='Расценивается как тотем воздуха, земли, огня и воды.' WHERE  `ID`=51513 AND `locale`='ruRU';  


DELETE FROM `quest_greeting_locale` WHERE `ID` IN (22292) AND `locale` = 'ruRU';
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`) VALUES
(22292, 0, 'ruRU', 'Свет ещё не воссиял над Скеттисом.');

--  It is unlikely that players will ever see this text, but let it be. By the way, this item should start the quest, but it doesn't start it! / Вряд ли игроки когда-либо увидят эти записи, но пусть будут. Кстати этот предмет должен начинать квест, но он его не начинает!
DELETE FROM `page_text_locale` WHERE `ID` IN (2637) AND `locale` = 'ruRU';
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`) VALUES ('2637', 'ruRU', 'Компендиум Форора по убийству драконов - это толстая исписанная книга. К сожалению, текст выглядит искажённым и не имеет для вас смысла.');


DELETE FROM `item_template_locale` WHERE `ID` IN (21044) AND `locale` = 'ruRU';
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`) VALUES (21044, 'ruRU', 'Поводья северного оленя');
DELETE FROM `item_template_locale` WHERE `ID` IN (27808) AND `locale` = 'ruRU';
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`) VALUES ('27808', 'ruRU', 'Ключ от прыготрона 4000', 'Сбоку выгравировано: Вазат не несёт ответственности за несчастные случаи при использовании прыготрона 4000.');

-- This fix may not work and needs to be tested. / Это исправление может не сработать, нужно тестировать.
-- DELETE FROM `npc_text_locale` WHERE `ID` IN (9125) AND `locale` = 'ruRU';
-- INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`) VALUES (9125, 'ruRU', 'Как стыдно быть питомцем охотника!$B$BЯ обязан тебе жизнью, но, пожалуйста, не беспокойся больше о моем благополучии. Теперь, когда ты освободил меня от Мусел\'ека, я найду выход. Может, по дороге встречу Гневвса.');

DELETE FROM `quest_request_items_locale` WHERE `ID` IN (9492,9494,9714,2969,9900,9999,9991,9977,9973,9962,9972,9967,9970,9956,9852,9853,9849,9925,9915,9914,9873,9871,9883,9882,9932,9934,9931,9928,9927,9924,9955,9923,9922,9921,9918,9874,9878,9917,9939,9937,9935,9938,9940,9936,9819,9810,9805,9804,9800,9815,9916,9933,9821,9892,9858,9857,9859,9851,9850,9789,9855,9854,9856,9897,9794,9996,9994,9997,9995,9990,9951,9968,9971,10878,10896,10024,10033,10034,10035,10036,10918,10840,10852,10848,10873,10915,10112,10447,10446,10040,10042,10412,10414,10415,10557,10710,10711,10657,10584,10620,10632,10674,10675,10479,10231,10111,10109,10476,10477,11521,10690,10927,10928,10455,10456,10457,10506,10486,10510,10502,10504,10505,10503,10511,10512,10555,10556,10682,10717,10747,10713,10770,10771,10795,10753,10796,10784,10609,10608,10594,11549,10516,10517,10518,10712,10671,10719,10894,10893,10722,10748,10797,10799,10800,10801,10802,10805,10806,10803,10567,10607,10004,10011,11040,10701,10191,10189,10204,10193,10329,10197,10198,10330,10338,10365,10308,10205,10232,10341,10432,10508,10507,10332,10185,10184,10320,10222,10223,10233,10257,10418,10855,10268,10435,10426,10427,10429,10430,10436,10315,10318,10850,10335,10856,10336,10290,10857,10293,10425,10411,10269,10275,10276,10280,10704,10882,10422,10437,10438,10439,10345,10353,10270,10271,10272,10273,10274,10656,10658,10754,10762,10763,10764) AND `locale` = 'ruRU';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`) VALUES 
(9492, 'ruRU', 'Вы вернулись с доказательствами кончины вождя Каргата Острорука?'),
(9494, 'ruRU', 'Ты $Gпринёс:принесла;, эээ, уголь?'),
(9714, 'ruRU', 'Кровавый гибискус, который можно найти у шаркунов, болотоходов и подболотных скатов в Нижетопи, в резервуаре Кривого Клыка, нам всегда пригодится. Приноси его мне связками по пять штук, я буду очень тебе благодарен!'),
(2969, 'ruRU', 'Мы не можем позволить клану Зловещего Тотема уничтожить этих прекрасных существ. Их надо освободить из плена!'),
(9900, 'ruRU', 'О, кто вернулся, $R. Гава\'си мёртв?'),
(9999, 'ruRU', 'Так скоро $Gвернулся:вернулась;?'),
(9991, 'ruRU', 'Никогда не $Gлетал:летала; на спине дракона Пустоты, а?'),
(9977, 'ruRU', 'Поединок закончится только тогда, когда один из вас упадёт замертво.'),
(9973, 'ruRU', 'Поединок закончится только тогда, когда один из вас упадёт замертво.'),
(9962, 'ruRU', 'Поединок закончится только тогда, когда один из вас упадёт замертво.'),
(9972, 'ruRU', 'Поединок закончится только тогда, когда один из вас упадёт замертво.'),
(9967, 'ruRU', 'Поединок закончится только тогда, когда один из вас упадёт замертво.'),
(9970, 'ruRU', 'Поединок закончится только тогда, когда один из вас упадёт замертво.'),
(9956, 'ruRU', 'Вот незадача... Корки, сын Арехрона, спросил меня, что случилось. Выслушав новости, он снова пропал!'),
(9852, 'ruRU', 'Нет ничего постыдного в том, чтобы признаться, что тебе не хватает смелости выйти на самого могучего и страшного зверя на этой земле, $N.'),
(9853, 'ruRU', 'Гордауг поедать силу Гурок.'),
(9849, 'ruRU', 'Гордог хочет вернуть валун.'),
(9925, 'ruRU', 'Ты $Gпозаботился:позаботилась; о порождениях Бездны?'),
(9915, 'ruRU', 'Мне всё ещё нужно больше пар клыков из слоновой кости диких элекков, бродящих по этой земле. К сожалению, мой бюджет больше не будет покрывать твою долю прибыли.'),
(9914, 'ruRU', 'Вот та самая кость, которая мне нужна. Только такая и никакая иная. Разумеется, если желаешь, мы можем пересмотреть наше давешнее соглашение насчёт размера твоей доли прибыли. Однако я сомневаюсь, что ты будешь $Gдоволен:довольна; результатом.'),
(9873, 'ruRU', 'Помни, $N, Ортор - шаман великой силы.'),
(9871, 'ruRU', 'Что это?'),
(9883, 'ruRU', 'У тебя есть ещё осколки кристаллов? Убедись, что ты не берешь ничего, что прикреплено к горе. Мы бы не хотели создавать проблемы с наару.'),
(9882, 'ruRU', 'Ты $Gпринёс:принесла; осколки кристалла, $N?'),
(9932, 'ruRU', 'Теперь ты понимаешь, почему меня невозможно победить?'),
(9934, 'ruRU', '<Гаррош, похоже, не рад подаркам.>'),
(9931, 'ruRU', 'Сможешь предугадать, что будет дальше?'),
(9928, 'ruRU', 'Мы разожжём пламя доселе невиданной ненависти между этими двумя кланами!'),
(9927, 'ruRU', '<Глаза Лантрезора широко раскрываются от изумления.>$B$BТы всё $Gсделал:сделала;?!'),
(9924, 'ruRU', 'Ты его $Gнашёл:нашла;?'),
(9955, 'ruRU', 'Где Корки?'),
(9923, 'ruRU', 'Это мальчишка...$B$B<Арехрон качает головой.>$B$BОн меня точно в могилу сведёт.'),
(9922, 'ruRU', 'Остерегайся элементалей в бассейне, $N.'),
(9921, 'ruRU', 'Мы только недавно вернули Телаар. Мы не потеряем его снова!'),
(9918, 'ruRU', 'Вероятно, он будет спать на гребне.'),
(9874, 'ruRU', 'Орки нас не поймут. Но мы должны это сделать. Во имя общего блага – и орков, и Сломленных.'),
(9878, 'ruRU', 'Тёмная кровь - гнусное племя Сломленных, $N. Они могут выглядеть как Куренай, но, несомненно, они дикие звери-убийцы.'),
(9917, 'ruRU', 'Есть какие-то новости?'),
(9939, 'ruRU', 'Ты здесь, чтобы получить награду?'),
(9937, 'ruRU', 'Ради маг\'харов!'),
(9935, 'ruRU', 'Ты здесь, чтобы получить награду?'),
(9938, 'ruRU', 'Не теряйте времени зря! Дарн должен быть остановлен!'),
(9940, 'ruRU', 'Ты здесь, чтобы получить награду?'),
(9936, 'ruRU', 'Ты здесь, чтобы получить награду?'),
(9819, 'ruRU', 'Они спят?'),
(9810, 'ruRU', 'Земляное кольцо поможет всем, чем только возможно.'),
(9805, 'ruRU', 'С великим стыдом говорю тебе, что это мои родственники стремятся залезть в воды Награнда и создать болота.'),
(9804, 'ruRU', 'Прежде чем слишком глубоко погрузиться в озеро, используй вишню из Награнда.'),
(9800, 'ruRU', '<Ло\'ап берёт бобы в руки и неодобрительно качает головой.>$B$BЯ же сказал, по меркам огров...'),
(9815, 'ruRU', 'Смотри, чтобы там не осталось ни единой крупинки грязи!'),
(9916, 'ruRU', 'Дети смогут протянуть ещё один день без еды...'),
(9933, 'ruRU', 'Значит, мир?'),
(9821, 'ruRU', 'Гордауг есть камни. Гордауг найти захватчика. Неси камни!'),
(9892, 'ruRU', 'У тебя есть ещё боевые бусы? Ты найдешь множество огров на крайнем севере, недалеко от границы с Зангартопью.'),
(9858, 'ruRU', 'Я не думаю ... что ты уже $Gразобрался:разобралась; с этими ... шипоедами.'),
(9857, 'ruRU', 'Я просто полежу здесь ещё немного. Я скоро поправлюсь.'),
(9859, 'ruRU', '<Гарольд смотрит на вас и улыбается слабой бледной улыбкой.>$B$BТы $Gпринёс:принесла;... <кашляет>.. копыто?'),
(9851, 'ruRU', 'Домашний очаг, супруга под боком, досужие сплетни – эти обывательские радости не для нас. Мы охотимся за крупной дичью и рискуем при этом жизнью.'),
(9850, 'ruRU', 'Ты думаешь, что копытни просто упадут замертво у твоих ног здесь, у костра?'),
(9789, 'ruRU', 'Копытень Награнда - хорошее испытание.$B$BКак у тебя дела с этим?'),
(9855, 'ruRU', 'Ты ещё не $Gнаучился:научилась; успокаивать биение своего сердца? Быть $Gнеподвижным:неподвижной;, как спокойное озеро и $Gтерпеливым:терпеливой;, ожидая подходящего момента, чтобы поразить свою добычу?'),
(9854, 'ruRU', 'Ты $Gохотник:охотница; или жертва?'),
(9856, 'ruRU', 'Ты уже $Gсразился:сразилась; с Потрошительницей?'),
(9897, 'ruRU', 'Кристен такая приятная... <кашляет>... барышня... Правда? Шкурами вот поделилась... Очень мило с её стороны.'),
(9794, 'ruRU', '<Киалон смотрит на вас с подозрением.>$B$BЯ тебя не знаю, $R. У тебя ко мне дело?'),
(9996, 'ruRU', 'Отчёт. Какие новости вы принесли?'),
(9994, 'ruRU', 'Вас что-то тревожит. Что такое, $C?'),
(9997, 'ruRU', 'Отчёт. Какие новости вы принесли?'),
(9995, 'ruRU', 'Вас что-то тревожит. Что такое, $C?'),
(9990, 'ruRU', 'Какие новости, $N?'),
(9951, 'ruRU', 'Не надо нам было приглашать его на ужин, это точно!$B$BИли, по крайней мере, надо было настоять хотя бы на паре блюд перед десертом, который они принесли!'),
(9968, 'ruRU', 'Вы принесли образцы?'),
(9971, 'ruRU', 'Удалось что-нибудь найти?'),
(10878, 'ruRU', 'Ты $Gсделал:сделала; то, о чём я тебя просил, $N? Я боюсь за нашу жизнь.'),
(10896, 'ruRU', 'Вы уничтожили источник заражений?'),
(10024, 'ruRU', 'Вы добыли глаза василисков, необходимые для изготовления эликсира для Ворен\'таля?'),
(10033, 'ruRU', 'Полагаю, ты тоже гонишься за наградой за Костеклювов?'),
(10034, 'ruRU', 'Я чувствую запах крови на твоих руках?'),
(10035, 'ruRU', 'Принесли перо? Вас можно достойно наградить?'),
(10036, 'ruRU', 'Вы убили его? Торгос мертв?!$B$BА доказательство?'),
(10918, 'ruRU', 'Псы Скеттиса всё ещё следят за нами, изгнанниками. Стоит нам только сунуться за пределы Шаттрата, как нас убьют на месте.$B$BПринесите мне ещё перьев в доказательство вашей победы над ними.'),
(10840, 'ruRU', 'Сколько эфириалов ты $Gуничтожил:уничтожила;? Надеюсь, этого будет достаточно, чтобы выгнать их из Гробницы Света.'),
(10852, 'ruRU', 'Мне скучно, играть не с кем. Ты $Gнашёл:нашла; моих друзей?'),
(10848, 'ruRU', 'Зло растёт в гнездовье Рейз. Положи этому конец, $R.'),
(10873, 'ruRU', 'Вы нашли наших пропавших без вести?'),
(10915, 'ruRU', 'Вы должны уничтожить древнее зло, прежде чем оно восстановит свои силы.'),
(10112, 'ruRU', 'Хммм, неужто моя память улучшается?'),
(10447, 'ruRU', 'Сержант Чавни держит нас в курсе ситуации в Лагере Огнекрылов. Все в порядке?'),
(10446, 'ruRU', 'Лейтенант Меридиан предупредил нас о ситуации в Лагере Огнекрылов. Всё в порядке?'),
(10040, 'ruRU', 'Ты уже $Gразговаривал:разговаривала; со всеми? Что они сказали?'),
(10042, 'ruRU', 'Ну, что ты $Gвыяснил:выяснила;?'),
(10412, 'ruRU', 'Ну же, $N. Говорите.'),
(10414, 'ruRU', 'Даже самая маленькая помощь нашему делу не останется незамеченной, $N. Армия врага велика, но победа будет за нами!'),
(10415, 'ruRU', 'Что вы сделали для нас в последнее время, $N? Война против Кель\'таса не продолжится сама по себе!'),
(10557, 'ruRU', 'Не бойся! Это для науки, а наука болезненна!'),
(10710, 'ruRU', 'Не бойтесь, $N! Ракет бояться - в небо не летать!'),
(10711, 'ruRU', 'Что? Вы не хотите проводить эксперимент? Не волнуйтесь, $N! У меня всё под контролем!'),
(10657, 'ruRU', 'Вся хитрость реполяризованной магнитной сферы в том, что нужно точно знать, когда ее выключить, чтобы не поджариться окончательно.$B$BКонечно, надо учитывать, встречу со сколькими крылатыми змеями вы намерены пережить.$B$BКстати, к слову – вы сумели зарядить сферу?'),
(10584, 'ruRU', 'Кого угодно впечатлит ход наших исследований электроменталей! Подумай только – разумные электрические существа, которых мы можем по желанию создавать, и которые будут подчиняться всем наши приказаниям!$B$BЧто тут может не получиться?'),
(10620, 'ruRU', 'Эти пауки убиты? Несколько человек, направлявшихся на север, исчезли.$B$BЕсли это из-за пауков, я хочу убедиться, что это больше не повторится.'),
(10632, 'ruRU', 'Ну, как добыча зубов?$B$BУверен, что вы добудете их нам без проблем. Пока будете этим заниматься, мы будем удерживать здешнюю заставу.'),
(10674, 'ruRU', 'Как понимаю, после нашего разговора вы наловили световых шариков в лагере Разаана? Интересно будет посмотреть на них и понять, что на уме у духов Астрала.'),
(10675, 'ruRU', 'Вы ещё не разделались с этим мерзавцем, этим душекрадом Разааном?'),
(10479, 'ruRU', 'Надеюсь, ты $Gвернулся:вернулась; не с пустыми руками, $N?'),
(10231, 'ruRU', 'Чего ты хочешь?'),
(10111, 'ruRU', 'Я говорил, как люблю яйца?'),
(10109, 'ruRU', 'Газ $Gдостал:достала;?'),
(10476, 'ruRU', 'Ну что, $N? У тебя есть что мне показать?'),
(10477, 'ruRU', 'Ты $Gпринёс:принесла; нам ещё обсидиановых боевых ожерелий, $N?'),
(11521, 'ruRU', 'Честное слово, $N, мне не до разговоров.$B$BПросто дай мне знать, когда добудешь корни.'),
(10690, 'ruRU', 'Что я могу сделать для тебя сегодня?'),
(10927, 'ruRU', 'Я сказал Стражу Лунного Шепота отдавать прямые приказы. Вы ему не подчиняетесь?'),
(10928, 'ruRU', 'Я сказал Грунту Гракху отдавать прямые приказы. Вы ему не подчиняетесь?'),
(10455, 'ruRU', 'Разве я не сказала правду? Лесные рыси стали угрозой не только для тех, кто пойдёт сюда по тропе, но и для самого Сильванаара.$B$BВесь смысл нашего создания Живой рощи состоит в том, чтобы окружить Сильванаар защитным регионом с природной красотой и спокойствием.'),
(10456, 'ruRU', 'Мне даже трудно выразить, насколько важно уничтожить этих лютых волков Громоборцев! Само их существование угрожает стабильности Живой рощи и всей нашей работе здесь.'),
(10457, 'ruRU', 'Как идёт укрепление защиты Рощи?$B$BПоскольку мы не знаем о намерениях араккоа из Лашш, а Орда засела прямо на другой стороне ущелья, то я боюсь, что если мы не поторопимся, то не сумеем защитить ни наш дом, ни Рощу, ни все наши труды.'),
(10506, 'ruRU', 'Ну, как, удалось? Понимаю, что среди огров Кровавого Молота бродить опасно, но если можно избежать убийства зверей, то мне это по сердцу.'),
(10486, 'ruRU', 'Выживание здесь зависит от нашей способности сконцентрировать усилия против тех, кто действительно нам мешает, это острокрылые кровопускатели.$B$BТы снова здесь, должно ли это означать, что ты $Gсправился:справилась; с заданием?'),
(10510, 'ruRU', 'Разве не замечательно? После всей этой грязи и насекомых Силитуса здешние места – сущий край обетованный!'),
(10502, 'ruRU', 'Наши разведчики доложили, что огры Кровавого Молота начали подкрадываться к перекрестку, ведущему из их лощины в Живую рощу.$B$BК сожалению, мы не можем найти способ жить вместе в мире с ограми. Когда мы когда-либо были в состоянии сделать это?'),
(10504, 'ruRU', 'Камнероги или Кровавый Молот, это не имеет значения. Все огры кланов борются друг против друга, соперничают за господство, которое идёт за благосклонность Груула Драконобоя.$B$BКаждый - все ещё наш враг, независимо от того, на кого упала эта благосклонность, и мы будем гнать их перед нами!'),
(10505, 'ruRU', 'Камнероги или Кровавый Молот, это не имеет значения. Все огры кланов борются друг против друга, соперничают за господство, которое идёт за благосклонность Груула Драконобоя.$B$BКаждый - все ещё наш враг, независимо от того, на кого упала эта благосклонность, и мы будем гнать их перед нами!'),
(10503, 'ruRU', 'Наши разведчики сообщили, что огры Камнерогов создали лагеря ещё ближе к Зазубренной гряде, которая ведет их к нам.$B$BЖаль, что мы просто не можем подчинить этих Огров нашей воле, но если это борьба, которую они хотят, то они получат Орды больше, чем размещена здесь.'),
(10511, 'ruRU', 'Тут прямо великий сушняк! И как же мне оттянуться-то без выпивки?'),
(10512, 'ruRU', 'Ну, что скажешь? Эти Камнероги тоже пьют что попало, как и Кровавые Молоты, или они от этого пойла чуть не окочурились, как я?'),
(10555, 'ruRU', 'По грубым рисункам в древнем фолианте вы понимаете, что для творения заклинаний из этой книги понадобится очень много перьев Лашш.'),
(10556, 'ruRU', 'Невероятно! Мне не терпится посмотреть, как работает это заклинание!'),
(10682, 'ruRU', 'Всё в порядке?'),
(10717, 'ruRU', 'Как добыча сетей? Судя по тому, что я видела, сети у этих браконьеров достаточно крепкие, чтобы сгодиться для наших целей.'),
(10747, 'ruRU', 'У вас не возникло сложностей при ловле дракончиков? Надеюсь, вы не обожглись!'),
(10713, 'ruRU', 'Вы защитили деревья? Лесорубы убиты?'),
(10770, 'ruRU', 'Скоро я усну глубоким сном леса. Прежде чем я закопаю свои корни глубоко и навсегда закрою эти старые глаза, я надеюсь узнать, что эти несчастные бесы страдали и погибли.'),
(10771, 'ruRU', 'Дело сделано? Тебе удалось возродить хоть какую-то жизнь на моей древней родине?'),
(10795, 'ruRU', 'Я не могу выразить достаточно чётко, насколько важно убить Доргока как можно быстрее.'),
(10753, 'ruRU', 'Справедливость восторжествовала?'),
(10796, 'ruRU', 'Вы уже разрушили лагерь Кровавого Молота?'),
(10784, 'ruRU', 'Ты уже $Gуничтожил:уничтожила; лагерь Кровавого Молота?'),
(10609, 'ruRU', 'Вы их добыли? Вы принесли по три драконьих субстанции, которые были мне так необходимы для продолжения моих исследований?$B$BВы знаете, ведь эти яйца драконов Пустоты прежде были яйцами чёрного дракона! Это факт! Но когда Дренор разнесло в клочья, внутрь хлынула Пустота, и яйца мутировали!'),
(10608, 'ruRU', 'Вы уже убрали этих пожирателей кристаллов с Поющего хребта? Мы не сможем начать моё исследование, пока вы задание не сделаете.'),
(10594, 'ruRU', 'Ну, сняли с поющих кристаллов те показания, которые я просил?'),
(11549, 'ruRU', 'Вы готовы сделать пожертвование?'),
(10516, 'ruRU', '$C, вы принесли мой меч и щит?$B$BХотя я и могу уйти в любой момент, мне не хочется возвращаться в Сильванаар без моего оружия.'),
(10517, 'ruRU', 'Что это был за шум? Это вы с Горр\'Димом?'),
(10518, 'ruRU', 'Что это у тебя? Надеюсь, огры клана Кровавого Молота больше нас не побеспокоят?'),
(10712, 'ruRU', 'Привет-привет! Мой кло... то есть кузен Талли сказал, что ты заглянешь. Ты что-то мне $Gпривёз:привезла;?'),
(10671, 'ruRU', 'Ну, где мой фунт мяса? Что, ты не понимаешь юмора?'),
(10719, 'ruRU', 'Что это у нас тут? А это не пятно ли крови на записке?'),
(10894, 'ruRU', 'Чем могу помочь? У тебя новости из Вечной рощи?'),
(10893, 'ruRU', 'Она мертва?$B$B$N, если у нас есть шанс побороться, нам нужно, чтобы вы посеяли смятение в их рядах, убив Драаку Длиннохвостую!'),
(10722, 'ruRU', 'Какие новости вы несёте? Вы знаете, что задумали культисты?'),
(10748, 'ruRU', 'Ты уже $Gразобрался:разобралась; с Макснаром?$B$BТы не можешь его найти? Насколько я понимаю, если ты пойдёшь направо после того, как войдёшь в их пещеры, они в конечном итоге приведут тебя к нему.'),
(10797, 'ruRU', 'Привет, $gпарень:девочка;, какие новости?'),
(10799, 'ruRU', 'Ну как, $Gдобыл:добыла; ядовитые железы? Если нет, то отстань и не трать моё время, пока не сделаешь, как я велел.'),
(10800, 'ruRU', 'И снова передо мной ты, $R. Стало быть, ты $Gстянул:стянула; мешок прямо из-под носа у Груллока'),
(10801, 'ruRU', 'Барон изготовил ловушку? Она способна прикончить гронна?'),
(10802, 'ruRU', 'Ну, ты $Gоставил:оставила; им послание?'),
(10805, 'ruRU', 'Тебе ещё не удалось уничтожить огров Камнерогов в Логове Груула?$B$BНе приходи ко мне с извинениями, $Gмальчик:девочка;! Справься с работой!'),
(10806, 'ruRU', 'Настанет время, и всем сынам Груула придёт конец.'),
(10803, 'ruRU', 'Осмелюсь сказать, что Вы - $Gсамый способный охотник:самая способная охотница; на огров, $Gкоторого:которую; я когда-либо знала.$B$BЯ надеюсь, что вы скоро разберётесь с ограми.'),
(10567, 'ruRU', 'Как только Вестник узнает о вашем нападении на его стаю, он тут же отзовется.'),
(10607, 'ruRU', 'Что это за $N? Что, по их мнению, он сделает? Куда, по их мнению, он их поведёт?'),
(10004, 'ruRU', '<Сальсалабим чешет в затылке.>$B$B[говорит на языке демонов] Ик ил ромат сардон!'),
(10011, 'ruRU', 'Готово, $N?'),
(11040, 'ruRU', 'Похоже, что это ящик гномского мастера-инженера. Стало быть, вас Босси прислала?'),
(10701, 'ruRU', 'Какие? Что?! Быстрее ... Здесь так много дел.$B$BЯ хочу когда-нибудь сдвинуть эту штуку с мертвой точки, понимаешь?'),
(10191, 'ruRU', 'Так скоро $Gвернулся:вернулась;?$B$BВсё в порядке с Маккс А. Миллионом ?!'),
(10189, 'ruRU', 'Удалось ли тебе раздобыть то, о чём я тебя просил, $N?'),
(10204, 'ruRU', 'Вы исследовали кровавые камни, которые использовали магистры Ярости Солнца, $N?'),
(10193, 'ruRU', 'Как дела, $N? Есть новости? Что ты сделал для меня в последнее время?'),
(10329, 'ruRU', 'Сработал ли план? Правду говоря, я наполовину ожидал, что тебя схватят.'),
(10197, 'ruRU', 'Удалось ли тебе добыть те детали одежды, о которых я тебе говорил?'),
(10198, 'ruRU', 'Ну и как, удалось что-то подслушать, $N? Поспеши. У меня полно срочных дел.'),
(10330, 'ruRU', 'Удалось ли тебе выполнить задачу, $N?'),
(10338, 'ruRU', 'Отключение завершено? Поспеши, пока я не передумал насчёт всех этих планов!'),
(10365, 'ruRU', 'Удалось ли тебе выполнить задачу, о которой я говорил тебе, $N?'),
(10308, 'ruRU', 'Консорциум весьма заинтересован в уничтожении всех мятежников-заксисов в Груде на юге.$B$B$C, если хочешь вновь оказать нам помощь, возвращайся туда и принеси нам ещё больше их знаков отличия.'),
(10205, 'ruRU', 'Всё кончено? Астральный налётчик Несаад мёртв?'),
(10232, 'ruRU', 'Я очень надеюсь, что ты справишься в битве с Пылающим Легионом.$B$BВсей душой испытываю ненависть к демонам.'),
(10341, 'ruRU', 'Вы выполнили свою задачу, $N?'),
(10432, 'ruRU', 'Ну? Что хотел сказать мне Тельдорн?'),
(10508, 'ruRU', 'Удалось ли тебе добыть камень телепортации Сокретара, $N?'),
(10507, 'ruRU', 'Готово, $N?'),
(10332, 'ruRU', '<Похоже, что когда ученик говорит, в глазах его выступают слезы.>$B$BВы ... имели дело с мастером Ронсусом?'),
(10185, 'ruRU', 'Вам удалось избавиться от мановых существ из деревенских руин?'),
(10184, 'ruRU', 'Мне больно знать, что для наших товарищей так мало можно сделать.'),
(10320, 'ruRU', 'Ты $Gуничтожил:уничтожила; лича этого несчастного Набериуса?'),
(10222, 'ruRU', 'Готово, $N? Вы отомстили за павших в деревне Кирин\'Вар?'),
(10223, 'ruRU', 'Вы выполнили задание, $N?'),
(10233, 'ruRU', 'Дым поднимается от укреплений Крепости Ярости Солнца. Это твоя работа?'),
(10257, 'ruRU', 'Тебе удалось добыть краеугольный камень?'),
(10418, 'ruRU', 'Вы избавили этих существ от страданий? Не поймите меня неправильно, я действительно любитель животных, но не тогда, когда животные кусают руку, которая их кормит и укрывает.'),
(10855, 'ruRU', 'Ты $Gпопробовал:попробовала; мой небольшой эксперимент, $N?'),
(10268, 'ruRU', 'Подойди.'),
(10435, 'ruRU', 'Всё ли удалось собрать?'),
(10426, 'ruRU', 'Удалось ли тебе сфокусировать энергию сферы?'),
(10427, 'ruRU', 'Тебе удалось пометить достаточное число талбуков?'),
(10429, 'ruRU', 'Удалось ли тебе добыть образец тканей этой чудовищной гидры?'),
(10430, 'ruRU', 'Похоже, это у тебя прототип. Тебя послал Гхабар?'),
(10436, 'ruRU', 'Вы очистили тестовую площадку?'),
(10315, 'ruRU', 'Сколько адептов пустоты тебе удалось повергнуть?'),
(10318, 'ruRU', 'Какие новости ты несёшь из Манагорна Ара?'),
(10850, 'ruRU', 'Вы находите отверстие, через которое в сквернобот загружается топливо.'),
(10335, 'ruRU', 'Ого, как быстро! Ты, должно быть, работаешь очень эффективно, если установил все три знака за такое короткое время.'),
(10856, 'ruRU', 'Как дела? У тебя была возможность преподать Легиону урок?'),
(10336, 'ruRU', 'Вы уже убили всех демонов в Руинах Фаралона?'),
(10290, 'ruRU', 'Я понимаю, что собирать фаралит очень опасно, но таковы обстоятельства. Торговец, не желающий рисковать, может попросту закрыть двери и тем самым уберечься от неприятностей.'),
(10857, 'ruRU', 'Всё сделано как надо? Телепорты закрыты?'),
(10293, 'ruRU', 'Тебе удалось остаться в живых – значит, или фаралитовая сердцевина при тебе, или ты $Gпередумал:передумала;. Так то или другое?'),
(10425, 'ruRU', 'Да?'),
(10411, 'ruRU', 'И грязь, и отходы чрезвычайно токсичны. Если оставить всё как есть, они превратятся в густой ужас Бездны!'),
(10269, 'ruRU', 'Привет тебе, $Gпутешественник:путешественница;. Тебе нужно приобрести у Хаззина какие-то товары?'),
(10275, 'ruRU', 'Желаешь что-нибудь купить или продать?'),
(10276, 'ruRU', 'Вновь приветствую тебя. Как продвигается поиск кристалла?'),
(10280, 'ruRU', '<Музыкальный перезвон речи наару наполняет твой разум>$B$BЯ чувствую, что у тебя с собой вещь великой силы, $R. Что ты $Gпринёс:принесла; мне?'),
(10704, 'ruRU', '<В вашей голове раздаётся мелодичный голос А\'дала.>$B$BТы $Gвернулся:вернулась;. $GПринёс:Принесла; ли ты два обломка ключа от Аркатраца?'),
(10882, 'ruRU', '<А\'дал сосредотачивает своё внимание на вас, его взгляд почти невыносим.>$B$B$N, может быть, ты не понимаешь масштабов своей миссии? Некогда терять время зря... собери группу соотечественников и войди в Аркатрац.$B$BПоложи конец Предвестнику Скайриссу.'),
(10422, 'ruRU', 'Ты $Gнашёл:нашла; Тиралия?'),
(10437, 'ruRU', 'Удалось ли тебе собрать достаточно фрагментов?'),
(10438, 'ruRU', 'Вы попали в цель?'),
(10439, 'ruRU', 'Что насчёт владыки пустоты?'),
(10345, 'ruRU', 'Удалось ли тебе найти Йасека?'),
(10353, 'ruRU', 'Статус? Какой у вас статус?'),
(10270, 'ruRU', 'Как насчёт того, чтобы обсудить деловые вопросы, $N?'),
(10271, 'ruRU', 'Я уверена, у тебя множество вопросов, но все ответы будут получены в должное время.'),
(10272, 'ruRU', 'Удалось ли тебе набрать яиц?'),
(10273, 'ruRU', 'Этот Марид - дурак, точнее он был дураком.'),
(10274, 'ruRU', 'Удалось ли тебе вызвать на бой Вераку и победить его?'),
(10656, 'ruRU', 'Ну же, $N. Говорите.'),
(10658, 'ruRU', 'Что вы сделали для нас в последнее время, $N? Война против Кель\'таса не продолжится сама по себе!'),
(10754, 'ruRU', 'Тебе есть что мне показать, $N?'),
(10762, 'ruRU', 'Что это?'),
(10763, 'ruRU', 'Ты $Gдостал:достала;, запрошенные мной материалы?'),
(10764, 'ruRU', 'Ты $Gсделал:сделала; то, о чем я тебя просил, $N?');

DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN (9492,9494,9714,2969,9900,9991,9983,9982,9956,9853,9849,9913,9925,9915,9914,9873,9871,9883,9882,9932,9934,9931,9928,9927,9955,9954,9924,9923,9922,9921,9920,9918,9874,9878,9792,9869,9870,9917,9939,9937,9935,9938,9940,9936,9819,9818,9810,9805,9804,9800,9815,9944,9933,9821,9892,9858,9857,9859,9851,9850,9789,9855,9854,9856,9897,9794,9996,9994,9997,9995,9990,9979,9978,9971,9968,9951,10863,10033,10034,10035,10036,10918,10112,10448,10447,10444,10446,10005,10038,10040,10042,10051,10052,10414,10412,10415,10111,10114,10479,10113,10109,10108,10476,10477,11556,10690,10927,10928,10455,10456,10457,10506,10486,10510,10502,10504,10505,10503,10511,10512,10555,10556,10682,10717,10747,10713,10770,10771,10795,10753,10796,10784,10609,10608,10594,11549,10516,10517,10518,10580,10712,10716,10671,10719,10894,10893,10722,10748,10797,10798,10799,10800,10801,10802,10818,10805,10806,10803,10567,10607,10004,11040,10264,10189,10204,10193,10329,10194,10652,10197,10198,10330,10200,10338,10365,10308,10341,10202,10432,10508,10509,10507,10257,10855,10434,10268,10435,10426,10427,10429,10430,10436,10440,10315,10317,10318,10850,10335,10856,10857,10336,10290,10293,10425,10411,10269,10275,10276,10280,10704,10882,10422,10437,10438,10439,10345,10353,10270,10271,10281,10272,10273,10274,10656,10658,10754,10762,10763,10764,11043) AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`) VALUES
(9492, 'ruRU', '$GМолодец:Умница;, $N. Благодаря вашей победе в Цитадели Адского Пламени мы нанесли серьезный удар по оркам.$B$BЯ должен поговорить с полевым командиром Ромусом о последующих действиях и обеспечении того, чтобы орки продолжали обороняться. Теперь, когда мы получили подкрепление, мы можем сделать гораздо больше, чем просто защитить Оплот Чести.'),
(9494, 'ruRU', 'Отлично, отлично! В мои планы не входит повторять подвиги чернокнижника Пустоклята, но надо быть полным дураком, чтобы не замечать силы угля Скверны.$B$BПравда, исследования вроде моего хотят запретить, так что всё нужно держать в секрете. $N, ты ведь никому не расскажешь?'),
(9714, 'ruRU', 'Эти цветки отлично подойдут. Но кровавый гибискус нам нужен постоянно. Может быть, как-нибудь ты ещё раз заглянешь в Нижетопь?'),
(2969, 'ruRU', 'Хвала Элуне, $N! Ты настоящий подарок судьбы! Нам с Джер\'Кай в одиночку никогда бы не удалось спасти бедных дракончиков.$B$BПожалуйста, поговори теперь с Джер\'Кай. А мне нужно приготовиться к мести! Если дракончики на свободе, это ещё не значит, что таурены не наловят новых! Так что мы с Джер\'Кай собираемся перейти в наступление.'),
(9900, 'ruRU', 'Теперь, когда ты $Gприкончил:прикончила; Гава\'кси, мы избавились от лишнего повода для беспокойства. Большое спасибо. А сейчас давай определимся с твоим вознаграждением.'),
(9991, 'ruRU', 'Отлично сработано, $N! Теперь мы знаем слабые места врага и можем планировать контратаку.'),
(9983, 'ruRU', 'Тебя пугает мой вид? Ты знаешь, кто я?'),
(9982, 'ruRU', 'Тебя пугает мой вид? Ты знаешь, кто я?'),
(9956, 'ruRU', 'Поразительно! Как тебе удалось утащить это всё в одиночку?!'),
(9853, 'ruRU', '<Гордауг вгрызается в голову Гурока, размалывая камень почти что в пыль.>$B$BВласть Гурока кончилась. Свобода духам земли. Теперь все спать. Награду ты получать!'),
(9849, 'ruRU', 'ГУРОК! Гурок предал стихии!'),
(9913, 'ruRU', '$GГотов:Готова; приступить к работе? У нас как раз есть для тебя отличное задание.'),
(9925, 'ruRU', 'Благодаря тебе, $N, моё лицо вновь озарилось улыбкой. То есть озарилось БЫ, будь у меня лицо. Продолжай в том же духе, и мы станем лучшими друзьями.'),
(9915, 'ruRU', 'Отличные, более тонкие образцы бивней, хотя некоторые выглядят немного тусклыми.$B$BУ тебя огромная благодарность Консорциума, $N.'),
(9914, 'ruRU', 'Я не сомневался в тебе ни секунды, $Gдружище:подруга;. Это именно то, что нужно, хотя бивни могли бы быть немного почище. И без царапин. Тем не менее, это хороший товар, и наш договор остаётся в силе.$B$BТы получишь оговоренную долю прибыли, и я очень надеюсь, что мы будем сотрудничать и в дальнейшем.'),
(9873, 'ruRU', 'Говоришь, тысяча мёртвых орков? Что могло вызвать столь дерзкое вторжение на орочьи земли? Я рад, что с этим мерзавцем покончено, но впереди нас ждёт ещё много серьёзных дел.'),
(9871, 'ruRU', '<Арехрон бьёт кулаком по ладони.>$B$BОртор... Гнусный предатель!'),
(9883, 'ruRU', 'Принеси нам ещё осколков, $N. Все, которые сумеешь собрать. Нельзя позволять этим ворам расхищать нашу собственность.$B$BПусть даже она ещё не совсем наша. Хотя, разумеется, уже почти наша. Во всяком случае, на бумаге.'),
(9882, 'ruRU', 'Прекрасный цвет. И качество в основном отличное.$B$BЯ сообщу нашим людям, как ты нам помогаешь.'),
(9932, 'ruRU', 'Давненько я ничего подобного не проворачивал! Спасибо за помощь, $N!'),
(9934, 'ruRU', '<Гаррош с пренебрежением пинает сундук.>$B$BТы только зря тратишь время, $R. Бери всё, что хочешь, из этого сундука. Или вообще забирай всё, что есть. Ни мне лично, ни Гарадару не нужны эти никчёмные побрякушки.'),
(9931, 'ruRU', 'У меня отличный план, $N. Я уже вижу, каковы будут плоды твоих трудов.'),
(9928, 'ruRU', 'Замечательно! Наша следующая мишень – руины Весёлого Черепа.'),
(9927, 'ruRU', 'Надо думать, они были изрядно удивлены, $N? Ты $Gпотрудился:потрудилась; на славу!'),
(9955, 'ruRU', 'Спасибо, $N. Мы отправили Корки к ночным эльфам в Острогорье. Будем надеяться, они присмотрят за ним и сумеют уберечь его от неприятностей.$B$BТеперь, что касается твоей награды...'),
(9954, 'ruRU', 'На этот раз они меня заперли надёжно, $N. А ключ – у Чо\'вара, главы Боевого Молота.'),
(9924, 'ruRU', 'Большое спасибо, $N. А Корки теперь займётся его матушка. Может, хоть она его вразумит.'),
(9923, 'ruRU', 'Мне очень жаль, $r, что всё так получилось. У моего дорогого сыночка редкий талант находить приключения на свою голову. Ладно, будет ему приключение... розгой по мягкому месту...'),
(9922, 'ruRU', 'Отлично сработано! Я сейчас собираю сведения о клане Боевого Молота, о котором упоминал лейтенант из клана Тяжёлого Кулака. Ты $Gпроделал:проделала; большую работу, пришло время проверить её результаты.'),
(9921, 'ruRU', 'Отлично. Кстати, тебе удалось обнаружить Лантрезора, о котором было упомянуто в письме этого болвана?$B$BКак бы там ни было, это ещё далеко не конец. Мне донесли, что огры опять что-то затевают, так что у нас есть чем заняться в ближайшее время!'),
(9920, 'ruRU', '<Мо\'мор озадаченно хмурится.>$B$BСтало быть, новый клан огров оттесняет клан Тяжёлого Кулака всё дальше и дальше на юг. Это тревожные новости. Сначала мы должны разобраться с опасностью, грозящей нашему дому...'),
(9918, 'ruRU', 'Вот чёрт! Говоришь, небольшой разведывательный отряд? Надо немедленно сообщить Мо\'мору!'),
(9874, 'ruRU', '<Отонбу вздыхает.>$B$BПосле того что мы сделали, на ближайшие десять лет можно оставить всякую надежду заключить с орками мир. Но, во всяком случае, у нас будет шанс прожить это десятилетие. А если бы мы не уничтожили эти тела... даже страшно подумать, чем бы всё это закончилось!'),
(9878, 'ruRU', 'Сомневаюсь, что орки поймут и оценят то, что ты для них $Gсделал:сделала;, но с этой поры Награнд станет намного чище. Спасибо тебе.'),
(9792, 'ruRU', 'Икути мне как брат! Его друзья – мои друзья! Добро пожаловать в Телаар, $N. Мы благодарны тебе за помощь нашему народу.'),
(9869, 'ruRU', 'Большое спасибо за новости. Не желаешь ли ты оказать содействие Служителям Земли? Стихии находятся в движении. Сейчас мы не откажемся от любой помощи.'),
(9870, 'ruRU', 'Большое спасибо за новости. Не желаешь ли ты оказать содействие Служителям Земли? Стихии находятся в движении. Сейчас мы не откажемся от любой помощи.'),
(9917, 'ruRU', '<Бинтук просматривает планы.>$B$BВо имя Света! Почерк отвратительный. Не могу понять, то ли они собираются "съесть синекожих и захватить их деревню", то ли испечь пирог с голубикой. И так и так можно прочесть. Надо с этим разобраться!'),
(9939, 'ruRU', 'Это великая победа для Гарадара! Ты – $Gгерой:героиня;, $N!'),
(9937, 'ruRU', 'Ты $Gизбавил:избавила; Награнд от страшной угрозы. Ты – $Gнастоящий:настоящая; $Gгерой:героиня;, поистине $Gвеличайший:величайшая; из всех!'),
(9935, 'ruRU', 'Мегера мертва! Отличные новости, $N. Вот твоя награда.'),
(9938, 'ruRU', 'Ты $Gизбавил:избавила; Награнд от страшной угрозы. Ты – $Gнастоящий:настоящая; $Gгерой:героиня;, поистине $Gвеличайший:величайшая; из всех!'),
(9940, 'ruRU', 'Это великая победа для Телаара! Ты – $Gгерой:героиня;, $N!'),
(9936, 'ruRU', 'Мегера мертва! Отличные новости, $N. Вот твоя награда.'),
(9819, 'ruRU', '<Гордауг одобрительно кивает.>$B$BХорошо. Духи уснули.'),
(9818, 'ruRU', '<Гордауг, кажется, кивает вам.>$B$BСадись.'),
(9810, 'ruRU', 'Стихии воспели твою победу в ту же секунду, когда ты $Gуничтожил:уничтожила; искажённого духа! Служители Земли благодарны тебе, $N. Ты можешь выбрать любую награду.'),
(9805, 'ruRU', 'Твои усилия приостановили распространение скверны, но теперь возникли иные трудности.'),
(9804, 'ruRU', '<Повелитель стихий Ло\'ап встает на колени в воде и читает молитву.>$B$BСлужители Земли скорбят о содеянном. Но мы делаем все, что в наших силах, чтобы исцелить раны земли.'),
(9800, 'ruRU', 'Только, пожалуйста, не вздумай купаться в священных водах Трона.$B$B<Ло\'ап протягивает вам готовую пилюлю из семян караколлы.>$B$BПоложи её под язык и дождись, пока она полностью не растворится. После этого ты сможешь дышать под водой подобно рыбам.'),
(9815, 'ruRU', 'Служители Земли благодарят тебя, $N. Стихии также передают тебе благодарность. Мы отметили и оценили твои усилия по очищению этого мира.'),
(9944, 'ruRU', 'Тридцать орков, $r! Из тех тридцати в живых остались лишь Унгриз да я. Мы нашли молодого орка, Саурфанга, близ заставы Солнечного Источника. Он был едва жив. Как я понимаю, он случайно попал ограм под горячую руку...'),
(9933, 'ruRU', 'Ты $Gзаслужил:заслужила; награду, $N. Бери всё, что хочешь, из этих даров. В конце концов, если бы не ты, никаких бы даров и не было.'),
(9821, 'ruRU', '<Гордауг разжёвывает камни и с отвращением сплёвывает их, обдавая вас градом осколков.>$B$BЯд. Эти камни не из Награнда. Эти камни – яд. Уничтожь ядовитые скалы. Найди захватчика.'),
(9892, 'ruRU', 'Теперь мы получим хорошую прибыль, $N. Я позабочусь о том, чтобы Хораади узнал, как ты нам помогаешь.'),
(9858, 'ruRU', '<кашляет> Поздравляю, $N! Ты всё-таки $Gсправился:справилась; с ними! Значит, у нас остаётся... <кашляет>... всего одно дело.'),
(9857, 'ruRU', 'Ты славно $Gуправился:управилась;... <кашляет>...с этими талбуками, $c. Но мне кажется, ты $Gспособен:способна; на большее. У меня есть для тебя ещё одно задание...'),
(9859, 'ruRU', 'Ничего себе! Это и вправду копыто Хол\'стяка!$B$BПохоже, мне уже лучше. Вот, держи подарок. Ты его $Gзаслужил:заслужила;!'),
(9851, 'ruRU', 'У тебя получилось! Ты $Gубил:убила; саму Бантар! Впрочем, я в тебе не сомневался, $N.$B$BВот, возьми. Ты $Gзаслужил:заслужила; награду.'),
(9850, 'ruRU', 'Очень даже неплохо.$B$BИз тебя может выйти хороший охотник, $Gмалыш:малышка;. Пора дать тебе шанс позабавиться по-настоящему.'),
(9789, 'ruRU', 'Для начала неплохо. Но лишь для начала.$B$BМелкие копытни – это несерьёзно. Надо поручить тебе более сложное задание!'),
(9855, 'ruRU', 'Ты ещё раз $Gподтвердил:подтвердила; своё мастерство, $c. Теперь тебе предстоит охота на самого свирепого и лютого ветруха.'),
(9854, 'ruRU', 'Каждый прожитый день – это великий дар. И этим даром надо воспользоваться в полной мере. И, может быть, уже завтра наши шаги по земле станут еще стремительнее и легче. А наши руки протянутся немного дальше в извечном стремлении схватить ускользающую мечту.'),
(9856, 'ruRU', 'Глаз – как живой! Как ты считаешь, может быть, Потрошительница по-прежнему заглядывает тебе прямо в душу?$B$B$N, теперь можешь считать, что тебя приняли в ряды лучших охотников. И ты $Gприблизился:приблизилась; еще на шаг к величайшей добыче на этой земле, гигантскому элекку!$B$BТы $Gзаслужил:заслужила; достойную награду.'),
(9897, 'ruRU', 'Ну, меня там не было, так что я не знаю, действительно ли ты $Gспас:спасла; Кристен. Впрочем, если она поделилась с тобой шкурами – то больше мне ничего знать не надо.'),
(9794, 'ruRU', 'А, так ты $Gпринёс:принесла; ответ Тимоти?$B$B<Киалон пробегает глазами письмо, потом разражается хохотом.>$B$BНу конечно же, у него всё под контролем, и помощь ему не нужна! Я так и знал!$B$BНекоторые всё-таки никогда не меняются. Ты погляди, у него даже нашлось время указать мне на ошибки в правописании!$B$B<Киалон вздыхает.>$B$BНе стоило ему и писать. Я совсем забыл, что он за человек. Ну разумеется, у настоящего специалиста всегда все под контролем!'),
(9996, 'ruRU', 'Для начала неплохо, но судя по тому, что вы там видели, и тому, что мне донесла разведка, у нас появилось куда более неотложное дело!'),
(9994, 'ruRU', 'О нет! Какие ужасные вести! Неужели из всех наших друзей в живых осталось только двое?!$B$BХорошо, дайте-ка взглянуть на эти части. Надеюсь, это не то, о чём я думаю.$B$BДа, всё именно так, как я и боялась – это детали бомбы. Наши разведчики из Шаттрата передавали нам информацию о том, что некоторые духи Астрала ввозят запрещённые товары из других измерений, с которыми у них налажены связи.'),
(9997, 'ruRU', 'Для начала неплохо, но судя по тому, что вы там видели, и тому, что мне донесла разведка, у нас появилось куда более неотложное дело!'),
(9995, 'ruRU', 'О нет! Какие ужасные вести! Неужели из всех наших друзей в живых осталось только двое?!$B$BХорошо, дайте-ка взглянуть на эти части. Надеюсь, это не то, о чём я думаю.'),
(9990, 'ruRU', 'Эфириалы? Товары, доставляемые в Туурем? Странные детали? И эльф крови, готовый доставить последний ящик в Лагерь Огнекрылов?$B$BЧто всё это означает?! Какое отношение это имеет к тому, что случилось с друидами в Перелеске Кенария?$B$BНадо посмотреть, что там в коробке.'),
(9979, 'ruRU', 'Да? Чем могу помочь, $R?'),
(9978, 'ruRU', 'Хорошо, хорошо... Я расскажу тебе, что знаю, только знаю я не так уж много!'),
(9971, 'ruRU', 'Значит, я был прав. Это и в самом деле был труп Сломленного? И вы можете точно сказать, что рядом с ним на земле лежал странный предмет?$B$BЧто-то тут не сходится... С чего бы Сломленному соваться сюда? И что за предмет он с собой притащил?$B$BИ что послужило причиной его смерти - уж не этот ли самый предмет?'),
(9968, 'ruRU', 'Странно. Образцы агрессивных пухоспинок словно бы пропитаны чистейшей маной...$B$BПохоже то, что убило друидов, оставило после себя сильное энергетическое поле. Но пухоспинки почему-то не погибли от него, а только стали очень агрессивными.$B$BНо в одном я теперь уверен – эта странная энергия является побочным продуктом того, что убило всех друидов в чащобе.'),
(9951, 'ruRU', 'Ну что ж, это только к лучшему. Если ему не хватает вежливости принять приглашение, значит, больше не будем его звать.$B$B<На лице хранителя Древлоса на миг застывает растерянное выражение.>$B$BКто вы и что здесь делаете? Уходите отсюда, пока не стало слишком поздно!'),
(10863, 'ruRU', 'Хорошо, что вы нашли меня. Мне многое надо вам показать.'),
(10033, 'ruRU', 'О, разумеется, вы убили целую стаю костеклювов! Вы читали сообщение капитана о том, что нужно приносить мне доказательства?$B$B<Таэла смотрит на вас с сарказмом>$B$BЛадно, поверю на слово. Не знаю уж, за что мне такое наказание, но благодарю вас за ваши усилия от имени всего Альянса. Вот вам награда за труды.'),
(10034, 'ruRU', 'Вы, должно быть, убили много костеклювов! Тьфу, как я ненавижу этих тварей! С тех пор, как меня покусал один из них, у меня случаются периодические обмороки.$B$BПредставляете, как это неприятно? Вот, возьмите это в благодарность за то, что отомстили за меня.'),
(10035, 'ruRU', 'Впечатляет, $C! Торгос был одним из самых страшных существ на этой стороне Награнда.$B$BЧто ж, думаю, вы заслужили кое-что из сокровищницы Бастиона Аллерии. Выбирайте.'),
(10036, 'ruRU', 'Спасибо, $N! Вы отомстили за меня, а я, как и обещал, награжу вас.$B$BВот, выбирайте и пользуйтесь на здоровье.'),
(10918, 'ruRU', '<Векакс издаёт радостный клекот, увидев доказательства смерти своих врагов>$B$BДа, теперь-то Скеттис узнает, что мы, Изгнанники, не будем молча терпеть их притеснения! А вот и обещанная награда. Если принесёте мне ещё перьев, то получите больше.'),
(10112, 'ruRU', 'Да, в самом деле, я всё вспомнил!$B$BИ я думаю, что вы заработали чуть больше, чем ваша драгоценная информация.'),
(10448, 'ruRU', 'Детали бомб. Значит, я была права, хотя именно здесь я предпочла бы ошибиться.$B$BЛадно, значит, нам с вами предстоит одно очень серьезное дело.'),
(10447, 'ruRU', 'У ВАС ВСЁ ПОЛУЧИЛОСЬ! ВЫ СПАСЛИ ФОРТ КАМНЕЛОМОВ!$B$BТеперь, когда их силы ослаблены, предводитель мертв, а бомба обезврежена, мы все сможем вздохнуть спокойно.$B$B$N, я никогда еще не встречал такой самоотверженности и такого... героизма! Пожалуйста, примите это в благодарность ото всех нас!'),
(10444, 'ruRU', 'Детали бомб. Значит, я был прав, хотя именно здесь мне хотелось бы ошибиться.$B$BЛадно, тогда нам с вами предстоит одно очень серьёзное дело.'),
(10446, 'ruRU', 'У ВАС ВСЁ ПОЛУЧИЛОСЬ! ВЫ СПАСЛИ БАСТИОН АЛЛЕРИИ!$B$BТеперь, когда их силы ослаблены, предводитель мертв, а бомба обезврежена, мы все сможем вздохнуть спокойно.$B$B$N, я никогда еще не встречала такой самоотверженности и такого... героизма! Пожалуйста, примите это в благодарность ото всех нас!'),
(10005, 'ruRU', 'Бомба на чистейшей мане, способная стирать с лица земли целые города! Но зачем? Зачем эльфам крови создавать нечто подобное и сбрасывать на нас? Перелесок Кенария всегда был мирным и спокойным местом.$B$BКаковы бы ни были причины, они наверняка сокрыты в сознании хранителя Древлоса, и я не имею ни малейшего понятия о том, как вылечить его. Быть может, его разум со временем излечится сам?$B$BЯ могу лишь надеяться на то, что такое несчастье больше никогда не постигнет нас!'),
(10038, 'ruRU', 'Наконец-то хоть кто-то пришел! Я отправил донесение в Бастион Аллерии неделю назад.$B$BБюрократы!'),
(10040, 'ruRU', 'Наконец-то вы вернулись! Ну, что удалось узнать? Кто они такие?'),
(10042, 'ruRU', 'Это ужасные новости! Похоже, я правильно поступил, что отправил вас на помощь Виксу. Чего нам не надо, так это чтобы Совет Теней обосновался прямо у нас под носом.$B$B$N, в знак признательности за проявленное вами мужество в деревне Грангол\'вар я даю вам право выбрать себе одну из этих прекрасных наград.'),
(10051, 'ruRU', 'Исла Звездная Грива только что ушла, но она рассказала мне обо всем, что произошло в Лагере Огнекрылов. Вполне понятно, что она очень расстроена тем происшествием в Перелеске Кенария... Проклятые эльфы крови!$B$BОна рассказала мне и о том, как вы помогли ей спастись и донести до нас эту информацию, так что Бастион Аллерии перед вами в долгу.$B$BПожалуйста, примите это в благодарность ото всех нас.'),
(10052, 'ruRU', 'Исла Звездная Грива только что ушла, но она рассказала мне обо всём, что произошло в Лагере Огнекрылов. Вполне понятно, что она очень расстроена тем происшествием в Перелеске Кенария... Проклятые эльфы крови!$B$BОна рассказала мне и о том, как вы помогли ей спастись и донести до нас эту информацию, так что Форт Камнеломов перед вами в долгу.$B$BПожалуйста, примите это в благодарность ото всех нас.'),
(10414, 'ruRU', 'Да... Армия Келя скудеет, а наши ряды, наоборот, растут.$B$B<Это задание можно повторять до тех пор, пока вы не заслужите уважительное отношение.>'),
(10412, 'ruRU', 'Хорошая работа, $N. Возможно, вы и впрямь сможете оказаться нам $Gполезным:полезной;.'),
(10415, 'ruRU', 'Прекрасно! Пусть все наши враги исчезнут!$B$B<Это задание можно повторять до тех пор, пока вы не заслужите уважительное отношение.>'),
(10111, 'ruRU', 'Э... это не яйцо... Погоди-ка! Цыпляток я тоже люблю! Их огромные коготочки так славно хрустят на зубах! Вот спасибо!'),
(10114, 'ruRU', 'Отрадно слышать, что он в безопасности. Ты хочешь присоединиться к охоте?'),
(10479, 'ruRU', 'Ты действительно $Gсильный:сильная; $Gсоюзник:союзница;, $N. Пойти в одиночку на огров Запределья... на такое способен не каждый.'),
(10113, 'ruRU', 'М-да, придётся искать нового мальчика на побегушках. Э...Ну или девочку. Ты мне подойдёшь, $c. Может, поработаешь на меня? Или ты собираешься охотиться?'),
(10109, 'ruRU', 'Великолепно! Ещё пара деталей – и будет как новенький. Ах да, вот твой ключ. Держи!$B$BПрыготрон ещё не отлажен. Так что… поосторожнее с ним.'),
(10108, 'ruRU', 'Так что ты $Gрешил:решила;? Мы будем воевать или ты окажешь нам помощь?'),
(10476, 'ruRU', 'Ты действительно $Gверный:верная; $Gсоюзник:союзница; и $Gдобрый:добрая; $Gсоратник:соратница;. Надеюсь, ты ещё не раз докажешь это.'),
(10477, 'ruRU', 'Ты по-прежнему служишь нам верой и правдой, $N. Пусть твоя сила пребудет с тобой всегда.'),
(11556, 'ruRU', 'Без тебя мы не смогли бы сделать того, что сделали, $N. Объединённых сил Алдоров и Провидцев недостаточно, чтобы сокрушить Легион и Келя. Мы рады, что у нас есть такие могучие союзники, как ты.'),
(10690, 'ruRU', 'Невероятно. Вы сами убили Рему?$B$BСудя по вашему виду – можете. Понимаете, мы ищем молодого, крепкого $C, вроде вас, чтобы помочь нам разобраться с вечной проблемой огров. Давайте уж разберёмся с ней окончательно, раз подвернулась возможность.$B$BЛадно, вы определённо заслужили ту награду, которую я назначил в том объявлении.$B$BПрошу, берите.'),
(10927, 'ruRU', 'Хорошая работа, $C. Этот туннель – наша дорога жизни до болот.'),
(10928, 'ruRU', 'Хорошая работа, $C. Этот туннель – наша дорога жизни до болот.'),
(10455, 'ruRU', 'Как быстро... Ты $Gуверен:уверена;, что $Gуничтожил:уничтожила; столько, сколько надо?$B$BОтлично. Есть ещё дела, в которых нам нужна помощь. Как ты на это смотришь?'),
(10456, 'ruRU', 'Славно. Постараюсь сделать из этих хвостов что-нибудь приличное.$B$BНе сомневаюсь, что Орда сумеет восполнить потерю этой волчьей стаи, но пока мы можем перевести дух.$B$BЕсли ты не против, $N, я попросила бы тебя сделать ещё кое-что ради блага Сильванаара и Живой рощи.'),
(10457, 'ruRU', 'Теперь, когда защита Рощи укреплена, я чувствую себя куда спокойнее.$B$BТы $Gзаслужил:заслужила; нашу благодарность и хвалу, $N.$B$BИ, конечно, я сразу же вспомнила об ещё одном важном деле!'),
(10506, 'ruRU', 'Рада, что получилось! Чем меньше детей Природы гибнет, тем лучше.$B$BНадо сказать, что после всего, что ты для нас уже $Gсделал:сделала;, мне начинает очень нравиться твое общество!$B$BБереги себя, $N.'),
(10486, 'ruRU', 'Не такое уж и долгое дело, как оказалось. Ты $Gуверен:уверена; что $Gуложил:уложила; достаточно этих тварей?$B$BОтлично, у меня есть для тебя ещё дельце. Куда более важное.'),
(10510, 'ruRU', 'Оооо, какие прекрасные образцы! Скорее бы распаковать исследовательское оборудование и как следует рассмотреть их!$B$BСпасибо тебе!'),
(10502, 'ruRU', 'Это большой успех в защите Сильванаара и Рощи.$B$BТеперь, когда их число поубавилось, эти Кровавые Молоты семь раз подумают прежде, чем нападать на нас.$B$BЕсли бы только они были единственным кланом огров, с которым у нас проблемы!'),
(10504, 'ruRU', 'Твои подвиги в сражениях против кланов Кровавого Молота и Камнерогов надолго обеспечили будущее Сильванаара. Хотя мы не хотим ни пяди земли кроме той, что нашли пустой с самого начала, мы не дадим себя уничтожить!$B$BПоскольку ты $Gсослужил:сослужила; нам хорошую службу, я награжу тебя от имени Альянса.'),
(10505, 'ruRU', 'Твои подвиги в сражениях против кланов Кровавого Молота и Камнерогов надолго обеспечили будущее Оплота Громоборцев. Мы не дадим спуску тем, кто становится у нас на пути!$B$BПоскольку ты $Gсослужил:сослужила; нам хорошую службу, я награжу тебя от имени Орды.'),
(10503, 'ruRU', 'Это большой успех в укреплении нашего положения в здешних краях.$B$BТеперь, когда их число поубавилось, эти Камнероги семь раз подумают прежде, чем нападать на Оплот Громоборцев.$B$BЕсли бы только они были единственным кланом огров, с которым у нас проблемы!'),
(10511, 'ruRU', 'Что это за запах? Ой, не говори только мне, что это огрское пойло!!!$B$BПрям жуть берёт. Да ладно, где наша не пропадала? Залпом!'),
(10512, 'ruRU', 'Ах ты, ха-ха-ха! Так я и думал. Я так и думал, что они всё без разбору хлебают!$B$BТупые твари!$B$BЛадно, хотя я и остался без выпивки, с твоей помощью мой отдых начался лучше некуда!$B$BВот что я тебе скажу... У нас тут полно барахла, которое нам на самом деле и не нужно. Хочешь что-нибудь взять?'),
(10555, 'ruRU', 'Пролистывая страницы с нацарапанными на них замечаниями и тонкими письменами араккоа Лашш, вы обнаруживаете страницу с изображениями кругов Силы, которые вы видели в Гнездовье Лашш.'),
(10556, 'ruRU', 'Не знаю, что и сказать. Очень странное заклинание. Это не просто заклинание или чары, но какой-то вид заклинания общения или связи.$B$BЯ не знаю, что с этим делать, $N. Мне придётся ещё некоторое время над этим подумать.$B$BНо всё равно спасибо за помощь! Рано или поздно я с этим разберусь, я уверена.'),
(10682, 'ruRU', 'ЧТО?! Они сразу отмахнулись от наших предложений и прогнали тебя?$B$BЯ в бешенстве! Мы пришли к ним с добром, а они даже не хотят попытаться найти общий язык?$B$BНу-ну, они своё получат!'),
(10717, 'ruRU', 'О, замечательно. У этих служителей культа на хорошую работу глаз намётан.$B$BОчень жаль, что они выбрали не ту сторону.$B$BА теперь, когда у нас есть сети, не поможете ли вы старой больной женщине в одном дельце?'),
(10747, 'ruRU', 'О, невероятно, здесь даже больше, чем я надеялась! Вы определённо достойны похвал за свой героизм!$B$BОтличный выводок чёрных дракончиков. Как раз то, что нужно для начала. Начну исследования.$B$BПрошу примите это в награду. Я настаиваю!'),
(10713, 'ruRU', 'Спасибо тебе, $N.$B$BМы проследим, чтобы природа побыстрее залечила нанесённые ей раны, но выращивание деревьев, особенно естественным путём, потребует куда больше времени.'),
(10770, 'ruRU', 'Их столько, что всех не перебить, но ты $Gдал:дала; мне надежду. Возможно, несколько следующих столетий я потрачу на возрождение моего любимого леса.'),
(10771, 'ruRU', 'Ты $Gуничтожил:уничтожила; множество этих мерзостных мелких тварей. Это приносит мне облегчение.'),
(10795, 'ruRU', 'Раз Доргок убит, огры Кровавого Молота остались без руководства и будут в панике, пока у них не появится новый предводитель.$B$BСпасибо тебе, $C, теперь мы легче вздохнем.'),
(10753, 'ruRU', 'Нет во мне радости, ибо мы убиваем сотворённых Элуной, но распространение порчи надо остановить. Ты $Gсделал:сделала; благое дело, $C.'),
(10796, 'ruRU', '<Лейтенант кивает, откровенно довольная вашими убойными способностями.>$B$BВы поражаете меня, $N. Похоже, вы не зря заслужили свою репутацию.$B$BС каждым убитым огром мы приближаемся к нашей цели – избавлению от опасности, ибо мы хотим жить в мире.'),
(10784, 'ruRU', '<Тор\'чанк кивает, откровенно довольный вашей боевой мощью.>$B$BТы не перестаёшь меня удивлять, $N. С каждым заваленным вонючим огром мы становимся всё ближе к избавлению от этих пакостных племён!'),
(10609, 'ruRU', 'Вы понятия не имеете, насколько важными могут оказаться мои исследования! Благодарю вас!$B$BКак же интересно будет покопаться в сущности этих субстанций! А в особенности мне интересно посмотреть, не выйдет ли из эффекта Пустоты, который превратил яйца чёрного дракона в яйца дракона Пустоты, каких выгод для моих будущих исследований.$B$BНа самом деле, я думаю, что вы первым испробуете на себе благие качества моего состава. Вот, возьмите эти пробные образцы и используйте по мере надобности.'),
(10608, 'ruRU', 'Туда им и дорога, вот что я вам скажу! Вонючие твари!$B$BИтак, если вы уверены в том, что истребили этих паразитов, то у меня для вас есть маленький исследовательский проектик. Думаю, вам понравится.'),
(10594, 'ruRU', 'Как неожиданно! Я и понятия не имел... эти кристаллы как будто живые!$B$BА вдруг есть какая-то симбиотическая связь между ними и драконами Пустоты?$B$BСпасибо вам, огромное спасибо! Вы просто должны принять в награду кое-что из моей коллекции всякой всячины, из тех штуковин, что я под страхом смерти не надену.$B$BНо вам может подойти.'),
(11549, 'ruRU', 'У вас благородная душа, и вы – $Gдостойный:достойная; $Gсоюзник:союзница;. Отныне вас будут называть $N из Расколотого Солнца, и все, кто здесь сражается, узнают о ваших деяниях!'),
(10516, 'ruRU', 'Ныне я в великом долгу перед вами, ибо вы помогли мне вернуть мою честь. Но наши труды здесь ещё не окончены.'),
(10517, 'ruRU', 'Отлично. Из тебя выйдет толк, $C, это несомненно.$B$BНе согласишься ли ты сделать ещё одно дело для меня и Сильванаара?'),
(10518, 'ruRU', 'Шлем Гурна Обжоры и знамя Камнерогов?$B$BВы с поборником придумали весьма хитроумный план!$B$BОбратив ярость клана Кровавого Молота на форт Камнерогов, вы ослабили их натиск в здешних местах.$B$BПрошу, $N, прими этот скромный дар Сильванаара.'),
(10580, 'ruRU', 'СИЛЬВАНААР? КОМАНДИР ТЕНЬ НЕБЕС?$B$BИДЕНТИФИКАЦИЯ НЕВОЗМОЖНА!$B$BОТОЙДИТЕ ПРЕЖДЕ ЧЕМ Я БУДУ ВЫНУЖДЕН СКАЗАТЬ ВАМ ГРОМКИЙ ЗВУК!'),
(10712, 'ruRU', 'О, ты $Gснял:сняла; данные с флюгера Пустоты? Замечательно! Данные, полученные с этого прибора – вместе с моими измерениями друидической магии – принесут великие плоды!$B$BО, применения моих открытий будут просто сногсшибательны, уж будь $Gуверен:уверена;!'),
(10716, 'ruRU', 'Я рада, что ты $Gвыжил:выжила;! Ты $Gпервый:первая;!'),
(10671, 'ruRU', 'То, что надо. Ну и воняет же, правда?$B$BНадеюсь, оно стоило твоих трудов... Я просто счастлива, что ты $Gсделал:сделала; это за меня!'),
(10719, 'ruRU', 'Интересно – но тревожно. Не знает ли Самия, кто такой этот Колфис Чёрная Чешуя?'),
(10894, 'ruRU', 'Я так и думал, и это весть недобрая!$B$BЯ знаю, как тебе можно помочь, но сначала ты нам помоги.$B$BУслуга за услугу.'),
(10893, 'ruRU', 'Теперь, когда Драаку можно сбросить со счетов, мы воспользуемся ситуацией. Сейчас они передерутся за власть, и нам станет полегче.$B$BРазве только инспектор, упомянутый в той записке, что ты мне $Gдоставил:доставила; не займёт её место.$B$BМожет, ты сумеешь этому помешать!'),
(10722, 'ruRU', 'Напасть на нас? Стереть нас с лица земли? Не выйдет!$B$BЭтим сектантам из пещеры Крыла Тьмы придётся усвоить, что Кенарийская экспедиция им не по зубам!$B$BКак там говорят? Не рой другому яму!'),
(10748, 'ruRU', 'Теперь, когда мы знаем, что глава наших врагов убит, мы вздохнём свободнее. Но ты $Gспас:спасла; целую горную гряду от их злобы.$B$BЧто бы они ни задумывали, ты $Gразрушил:разрушила; их планы!$B$BПрими нашу благодарность, $N. И прими это в знак нашей признательности, как и наше бесконечное гостеприимство.'),
(10797, 'ruRU', 'Ух ты, прелесть какая. Очень похоже на тех гроннов, которые вечно гоняют огров из клана Камнерогов. Но странно, что ты $Gнашёл:нашла; её у одного из главарей огров Кровавого Молота.'),
(10798, 'ruRU', 'А, посланник напыщенного Альянса. Ну, говори мне, жалкая тварь, чего ради ты здесь? Почему твоё блистательное командование само сюда не пришло с просьбой?$B$BНеужто они боятся меня? Это кое-что говорит о тебе, хотя я ещё не решил, что именно.'),
(10799, 'ruRU', 'Очень хорошо. Простая, прямо-таки тупая задача решена. Теперь давай мне железы, и я займусь самым трудным делом.'),
(10800, 'ruRU', '<Барон Черногрив заглядывает в мешок. Похоже, он доволен.>$B$BЧто же, свою часть сделки ты $Gвыполнил:выполнила;. И теперь я, так и быть, дам твоему командиру Каменной Стене ловушку.'),
(10801, 'ruRU', 'Хмм, ловушка из субстанции драконьего огня? Интересно, откуда Черногрив берёт такие редкие субстанции?$B$BДа ладно. Важно, что мы с помощью этой штуковины прикончим сына Груула.'),
(10802, 'ruRU', 'Славно, славно, $N. Отлично!$B$BДумаю, теперь об ограх и их хозяине мы ничего не услышим.'),
(10818, 'ruRU', 'А, вижу у тебя нашлось время ответить на моё приглашение.$B$BЛадно, у меня была уйма времени на подготовку отмщения, и ты будешь моим мечом в грядущей битве!'),
(10805, 'ruRU', 'Очень хорошо. Я не ошибся, поставив на тебя, как на моего поборника. Пора, думаю, сделать шаг вперед.$B$BПомнишь ту маленькую штучку, которую ты $Gстянул:стянула; для меня прямо из-под носа у Груллока? Теперь тебе выпал шанс использовать её по назначению.'),
(10806, 'ruRU', 'Ты сражаешься на удивление хорошо, $R, и для меня большая честь биться рядом с тобой. Наверное, моё преображение весьма удивило тебя. Надеюсь, я не слишком тебя напугал?$B$BПусть это останется нашей маленькой тайной, ладно? А я за твою верную службу даю тебе на выбор любую из этих вещиц.'),
(10803, 'ruRU', '<Лейтенант Файрвезер с ухмылкой выслушивает рассказ о ваших приключениях в Камен\'моке.>$B$BКак жаль, что меня там не было! Вот что я вам скажу, $N: никогда не беритесь за дело, которое не сулит воинской славы!$B$BХа! Небось, после такого кровопускания на мою долю в этих горах ни огра не осталось!'),
(10567, 'ruRU', 'Ты $Gдобыл:добыла; её!$B$BПри помощи этой подвески я смогу настроить тебя на араккоа Гришната таким образом, что ты сможешь понимать их речь.$B$BТак мы сможем продвинуться в понимании араккоа и сущности Ворона. Для этого мне понадобится твоя помощь.'),
(10607, 'ruRU', 'Это очень тревожная весть. Араккоа долгое время жили мирно. Но этот культ Ворона – ничто иное, как сборище неудачников и безумцев.$B$BНо сила их растёт, и не обращать на это внимания мы не можем. Возможно, нам еще много придётся узнать об этом самом Вороне.'),
(10004, 'ruRU', 'Тихо, $Gясноглазый:ясноглазая;! Сальсалабим помочь.'),
(11040, 'ruRU', 'Чтоб я ещё знал, на кой нужны некоторые из этих деталей... Нет, я найду им применение, но никогда не думал, что однажды придется научиться думать по-гномски!'),
(10264, 'ruRU', 'Привет тебе, $R.$B$BНе возьмёшься ли ты за довольно важную миссию по изъятию имущества?'),
(10189, 'ruRU', 'Превосходно! При наличии этого списка мы сможем принимать более взвешенные решения, намечая целью кого-нибудь из последоватей Келя в манагорнах.$B$BКак ни печально, мне уже начало нравиться убивать всех его приспешников без разбора.'),
(10204, 'ruRU', 'Хмм... как я и подозревала.$B$BВоздействие такого уровня сырой энергии во много раз увеличивает нашу природную зависимость от магии.$B$BЯ не удивлена, что Келю сходит с рук то, что он творит; все его подчиненные в основном упиваются этим.'),
(10193, 'ruRU', 'Ты $Gнадёжный:надёжная; $Gпарень:девушка;, $N. Если мне что-то и нравится больше, нежели убийство приспешников Келя, - это когда кто-то убивает их вместо меня. Чем меньше крови на моей одежде, тем лучше.'),
(10329, 'ruRU', 'Конечно же, это сработало! Я глава шпионов, и мои сведения всегда точны.$B$BВ любом случае, у меня для тебя есть отличная новая работа. Хочешь услышать, что именно? Несомненно, хочешь.'),
(10194, 'ruRU', 'Устроить всё для твоего полёта стоило немалых денег. Будем надеяться, что ты сумеешь как следует справиться со своей работой.'),
(10652, 'ruRU', 'Добро пожаловать, $C. Постарайся не демаскировать наше местоположение.$B$BМы не продержимся долго, если ищейки Келя вынюхают нас.'),
(10197, 'ruRU', 'Превосходно! Когда я закончу работу, ты сможешь неузнанным проникнуть в ряды армии Келя!'),
(10198, 'ruRU', 'Проблемы в манагорне Даро? Я уверен, Талодиен не прочь услышать такие новости. Но сначала закончим работу здесь.'),
(10330, 'ruRU', 'Мы слышали весь этот шум и уже собирались убраться отсюда. Хорошо, что тебе досталось не очень сильно.'),
(10200, 'ruRU', 'Ты не перестаёшь удивлять меня, $N. Тебе удалось многое узнать в манагорне Коруу.'),
(10338, 'ruRU', 'Итак, $N, ты уже $Gотключил:отключила; три манагорна. Должно быть, у Кель\'таса теперь начались настоящие проблемы.'),
(10365, 'ruRU', 'Кель в сговоре с Пылающим Легионом? Ха! Ворен\'таль по потолку будет бегать от таких сведений.$B$BТы думаешь, тысячи паломников, собравшихся со всего Азерота, захотят союзничать с Пылающим Легионом? Я думаю, нет!'),
(10308, 'ruRU', 'Предатели, все они предатели!$B$BА ты – молодец, $C! Если снова окажешься там, то приноси новые знаки отличия в мою коллекцию!'),
(10341, 'ruRU', 'Хорошая работа, $N. Армия Келя нескоро оправится от нанесённого тобою удара.'),
(10202, 'ruRU', 'Ты вовремя. Я уже начал думать, что Провидцам нет никакого дела.'),
(10432, 'ruRU', 'Это важно, $N. Очень важно!$B$BВорен\'талю нужно услышать это как можно скорее.'),
(10508, 'ruRU', 'Ты не перестаёшь удивлять меня, $N! Хорошо, что ты на нашей стороне.'),
(10509, 'ruRU', 'Ты даже не представляешь, $N, какое значение это имеет для Провидцев. Прошу меня извинить, мне нужно перевести дыхание и оценить сложившуюся ситуацию.'),
(10507, 'ruRU', 'Ты необычайно сильная личность, $N. Провидцы счастливы видеть тебя среди своих союзников.$B$BКогда слух о том, кому ныне служит Кель, распространится достаточно широко, еще больше народа примет нашу точку зрения. Тот факт, что мы можем одержать столь решительную победу над новыми хозяевами Кель\'таса, ставит нас в весьма выгодное положение.$B$BЯ не забуду твои деяния.'),
(10257, 'ruRU', '<Когда вы протягиваете верховному магу Ключ-камень, глаза мага озаряются светом.>$B$BВеликолепно! Хотя я видел немногое из того, что случилось с Фаралоном, я не уверен, что хочу оказаться снаружи. Но это лучше, чем быть запертым здесь до конца дней своих.'),
(10855, 'ruRU', 'Это превосходные новости, $N. Теперь, когда мы знаем, как справляться со скверноботами, я могу провести саботаж в отношении оставшихся машин.'),
(10434, 'ruRU', '<Вы представляетесь и говорите Оди, что вас послал Шоли.>$B$BАх да, мы ждали, что кто-нибудь придёт и поможет нам... э-э... переместить кое-какие товары.'),
(10268, 'ruRU', 'Приветствую тебя на Штормовой Вершине, $C. Наслаждайся гостеприимством Консорциума.$B$BСнаряжение ты можешь положить где угодно. Подозреваю, что довольно скоро ты вновь заберёшь его.'),
(10435, 'ruRU', 'Прекрасно! Самая трудная часть проекта завершена. Теперь всё, что нам нужно, – это вернуться обратно в Зону 52 и привлечь внимание Кенарийской экспедиции. Здесь достаточно для того, чтобы и самим применить это на деле, и немного заработать на стороне.'),
(10426, 'ruRU', 'Ничего себе! Фокусирование энергии сферы, похоже, продолжает ускорять рост до той степени, на которой он порождает необычайную агрессию. Если мы действительно получим возможность использовать эту технологию, мы должны убедиться, что взяли правильные значения.'),
(10427, 'ruRU', 'Превосходно. Я буду присматривать за помеченными особями и проверю, взрослеют ли они так же быстро, как другие формы жизни в сфере.$B$BПри наличии должного контроля мы сможем использовать эту технологию, чтобы восстановить разрушенные участки Запределья и Азерота.'),
(10429, 'ruRU', '<Аурин берёт сердце.>$B$BЭто сердце слишком велико, даже для существа такого размера. Оно росло так быстро, чтобы угнаться за ростом гидры. Не сомневаюсь, что это создание умерло бы, не прожив и половины отпущенного природой срока.$B$BНо даже при наличии подобного риска я намереваюсь убедить Консорциум поделиться их технологиями. Они слишком многообещающи, чтобы мы могли сдаться.'),
(10430, 'ruRU', 'Выглядит несколько странно. Гхабар определённо не думал о Пустоверти, когда разрабатывал это.$B$BНе смотри так удивлённо, $N. Пустоверть – просто курорт по сравнению с некоторыми местами, где мне приходилось работать. Тем не менее, отказ генератора сферы – это всегда неприятно.'),
(10436, 'ruRU', 'Отлично. Похоже, всё в порядке. Мы готовы приступать.'),
(10440, 'ruRU', 'Я немедленно пошлю своих техников на работу по починке.$B$BОднако подозрения Ташара относительно саботажа тревожат меня. Не могу вспомнить никого, кто оказался бы достаточно дерзок, чтобы взяться за похищение наших технологий. Во всяком случае, из тех, кто знает, на что мы способны. Быть может, настало время ограничить доступ в Штормовую Вершину.'),
(10315, 'ruRU', 'Что бы мы ни сделали ради того, чтобы заставить их прекратить работу манагорнов, всё это будет благим делом.$B$BПохоже, разумные доводы на них не действуют. И мне ясно, что какие бы замыслы ни лелеяли их вожди, они, несомненно, безумны.$B$BВ качестве вознаграждения за твою верную службу целям Консорциума я хотел бы предложить тебе денежную единицу твоего мира, если это не оскорбит тебя.'),
(10317, 'ruRU', '<Штейгер говорит едва ли не шепотом.>$B$BТы здесь для того, чтобы убить меня? Ха. Полагаю, духи Астрала знают не так-то много, верно?$B$BЯ не тот, кто тебе нужен, поверь.'),
(10318, 'ruRU', 'Надсмотрщиком там был страж ужаса? Странно! Что здесь делает Пылающий Легион?$B$BИтак, кое-кто из эльфов крови дезертирует. Мы будет иметь это в виду, если попытаемся захватить этот регион силой. По крайней мере, хоть какие-то хорошие новости во всём этом есть, не так ли?$B$BПрими мою глубочайшую благодарность, $N, а вместе с ней вот это.'),
(10850, 'ruRU', 'Сквернобот начинает трястись и чихать, по мере того как вы загружаете его неправильным топливом.'),
(10335, 'ruRU', 'Это ведь не шутки, верно? Отличная новость!$B$BТеперь, когда геодезическая разметка участка проведена, я могу откомандировать бригаду в руины и посмотреть, что там можно найти.$B$BПрими мою благодарность, $C.'),
(10856, 'ruRU', 'Прекрасно, $N. Продолжай в том же духе, и я замолвлю за тебя слово перед принцем.'),
(10857, 'ruRU', 'Благодаря твоим деяниям, $N, я могу вздохнуть с облегчением. Это, конечно, лишь словесный оборот.$B$BПолагаю, за это ты хочешь получить какую-нибудь награду.'),
(10336, 'ruRU', 'Поистине отличная работа.$B$BТеперь, когда демоны Кулутаса убиты, Зефирион сможет безопасно заняться раскопками в Руинах Фаралона.$B$BПрими эти деньги в знак моей признательности.'),
(10290, 'ruRU', 'О да! Именно то качество, на которое я надеялся. Можно не разбивать скопления кристаллов, если можно добыть минерал непосредственно от производителя.'),
(10293, 'ruRU', 'Превосходно! Жду не дождусь, когда я смогу приступить к проверке.'),
(10425, 'ruRU', '<Командир Амир выглядит довольным.>$B$BХорошая работа, существо из плоти и крови! Этот солдат может дать нам ключ к разрушению всех планов Братства Эфириум.'),
(10411, 'ruRU', 'Надеюсь, ещё не слишком поздно. Не встретились тебе необычайно большие слизнюки в том районе, куда стекают отходы Бездны, или поблизости от этого района?'),
(10269, 'ruRU', '<Делец Хаззин понижает голос до шепота.>$B$BА, я знаю о твоей миссии. Она очень важна для принца Харамада!$B$BТеперь, когда мы знаем местонахождение первой точки триангуляции, тебе следует побыстрее отыскать вторую!'),
(10275, 'ruRU', 'Просто прекрасно. Принц будет доволен!$B$BТеперь у нас есть вторая точка, благодаря чему мы сможем найти третью, а потом – приблизительное местоположение кристалла!'),
(10276, 'ruRU', 'Это превзошло мои самые смелые ожидания, я не думал, что тебе удастся забрать этот кристалл!$B$BИ ты отдаешь его мне? Ты понимаешь, какую силу он таит?$B$BТвое бескорыстие поистине впечатляюще и непревзойдённо, $N! Твоё поведение заставляет меня лучше думать о разумных существах.'),
(10280, 'ruRU', 'Тебе удалось обрести Песню Духа! Это кристалл Ата\'мала, который пророк Велен оставил на сохранение своему народу, прежде чем отправиться в свою злосчастную миссию в Экзодар.$B$BКак ни странно, он не предвидел, что кристалл попадёт в руки Пылающего Легиона, пусть и на короткое время.$B$BА может быть, и нет? Может быть, он предвидел всё это и оставил кристалл здесь, чтобы ты мог забрать его и доставить ко мне?$B$BЯ чувствую, что истина именно такова. Поистине велик твой героизм, $N!'),
(10704, 'ruRU', 'Я впечатлён, $N, хотя именно этого и следовало ожидать от $Gгероя:героини;, $Gкоторый:которая; $Gвернул:вернула; нам кристалл Ата\'мала.$B$BДай мне обломки, и я соединю их вместе. Тогда тебе будет открыт доступ в Аркатрац.'),
(10882, 'ruRU', '<Хрустальный мелодичный голос А\'дала звучит спокойнее, чем при ваших прошлых разговорах.>$B$BВы снова проявили недюжинную смелость. Если бы предвестник Скайрисс освободился, то унес бы тысячи жизней, как и другой слуга Древних Богов - Скерам, в вашем мире Азерота.$B$BТо, что я предложу вам взамен, может показаться несравнимой малостью, но помните, что вместе с этим вы получаете вечную благодарность Ша\'тар.'),
(10422, 'ruRU', 'Спасибо, $N. Тиралиус получил тяжёлые ранения, но мы думаем, он выживет.$B$BОн упоминал, что тюрьмы, подобные той, в которой держали его, занимают целые поля. И эти тюрьмы полны существ со всей вселенной!$B$BХорошо, что мы в курсе – на случай, если потребуется открыть все эти темницы. Консорциум уже выразил некий интерес в том, чтобы выслать туда специальные команды и поработать над технологией взлома замков Эфириума.'),
(10437, 'ruRU', 'Превосходно! При помощи этих фрагментов мы сможем настроить бомбу, которая уничтожит стержень Бездны над Ультрисом. Когда стержень Бездны будет уничтожен, связь Пространствуса с Бездной оборвется и он останется без защиты.'),
(10438, 'ruRU', 'Настало время нанести удар! Когда разрыв исчезнет, Пространствус будет уязвим для физических и магических атак!'),
(10439, 'ruRU', 'На протяжении тысяч лет мы не знали ничего, кроме войны. Мы защищали наш народ от нападений тварей Бездны и эфириалов в равной степени.$B$BНыне один из самых ненавистных наших врагов мертв – наконец-то.$B$BО существо из плоти и крови, знай, что тебе благодарны сотни миллионов эфириалов!'),
(10345, 'ruRU', 'Ты $Gспас:спасла; мои обмотки, $N. Протекторат узнает о твоих деяниях.'),
(10353, 'ruRU', 'А Йасек? Он это сделал?$B$BБудем надеяться, что да. Мне не удалось послать им подкрепление... Теперь весь регион захвачен Братством Эфириум.$B$BПрошу прощения, я едва не забыл про твою награду.'),
(10270, 'ruRU', 'Эта энергетическая ячейка подойдёт для наших целей. Как только начнётся оборот денег, мы дополнительно улучшим её.$B$BНу, довольно. Каждый момент, проведённый за обсуждением, приводит к потере прибыли.'),
(10271, 'ruRU', 'И подумать только, этот коварный дух Астрала собирался продавать эту эссенцию эльфам Крови, словно какие-нибудь сласти...'),
(10281, 'ruRU', 'Моё имя Тиригоса из рода Малигоса, но большинство называют меня Тири. Мой товарищ – паладин Джорад Мейс.$B$BСлухи об этих странных драконах уже распространились достаточно широко, и я боюсь, что очень многие поспешат воспользоваться этим ради выгоды, не осознавая истинной природы того, с чем имеют дело. С твоей помощью мы надеемся понять суть этих созданий, прежде чем другие обнаружат их присутствие.'),
(10272, 'ruRU', 'Это прекрасно подойдет, $N. Спасибо за помощь нам.$B$BОднако прежде, чем мы сможем продолжить, нам нужно обратиться к другому вопросу.'),
(10273, 'ruRU', 'Теперь, когда с этим назойливым эфириалом покончено, мы можем сосредоточить наши усилия на исследовании драконов Пустоты. У меня была возможность изучить их яйца, и я сделала несколько открытий.'),
(10274, 'ruRU', 'Хорошая работа, $N, поистине хорошая. Сначала драконы Пустоты не примут в свою среду синего дракона, однако со временем, при жёсткой демонстрации моей власти, они придут под мое крыло. Они разъединены, разбросаны, у них нет решительного лидера. Мы должны быть бдительными, чтобы не дать им пасть под натиском злых сил. Необходимо постоянно следить за ними.'),
(10656, 'ruRU', 'Армия Келя отлично обучена, но, несмотря на это, вы прекрасно справились, $N.'),
(10658, 'ruRU', 'Прекрасно! Теперь Кель\'тас перестанет нас недооценивать!'),
(10754, 'ruRU', 'Не может быть! Дай-ка мне поближе взглянуть на эту форму.'),
(10762, 'ruRU', 'Какой такой ключ? Данат что, забыл, – нам надо работать над осадными орудиями!'),
(10763, 'ruRU', 'Ну, давай попробуем. Посмотрим, на что годится кузнечное дело орков Скверны.'),
(10764, 'ruRU', 'О, $Gприятель:подруга;, у тебя получилось! Единственное, что теперь осталось – отправиться с этим ключом в цитадель Адского Пламени и прикончить побольше орков!'),
(11043, 'ruRU', '<Брюнн начинает медленно багроветь, пока лицо его не становится такого же цвета, что его борода.>$B$BЧТО он хочет сделать с моими грифонами?$B$BЕсли эта мелочь пузатая привяжет к моим грифонам что-то кроме седла, я лично доберусь до Острогорья и затолкаю эту ракету ему в глотку!');
