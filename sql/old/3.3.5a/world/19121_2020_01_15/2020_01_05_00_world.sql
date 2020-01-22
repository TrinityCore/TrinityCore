-- 
DELETE FROM `quest_request_items_locale` WHERE `ID`=12619 AND `locale` IN ("esES","esMX","frFr","ruRU");
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(12619,"esES","La hojarruna es una extensión de tu ser. Un caballero de la Muerte no puede luchar sin una hojarruna.",18019),
(12619,"esMX","La hojarruna es una extensión de tu ser. Un caballero de la Muerte no puede luchar sin una hojarruna.",18019),
(12619,"frFr","La lame runique est une extension de votre être ! Sans lame runique, vous ne pourrez pas vous battre.",18019),
(12619,"ruRU","Рунический меч – это продолжение твоей руки. Рыцарь смерти – ничто без своего клинка. ",18019);

DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN (12593,12619,12842,12848) AND `locale` IN ("esES","esMX","frFr","ruRU");
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(12593,"esES","Has oído la llamada del Rey Exánime, caballero de la Muerte. Es hora de responder a tu maestro.",18019),
(12593,"esMX","Has oído la llamada del Rey Exánime, caballero de la Muerte. Es hora de responder a tu maestro.",18019),
(12593,"frFr","Vous avez entendu l’appel du roi-liche, chevalier de la mort. L’heure de répondre à votre maître a sonné.",18019),
(12593,"ruRU","Ты $gслышал:слышала; зов Короля-лича, рыцарь смерти. Настало время откликнуться на призыв своего господина.",18019),
(12619,"esES","Bien hecho, $N. Has conseguido crear tu primera arma de hojarruna. ¡Con ella sembrarás las semillas del caos y la destrucción! Dejarás una estela de sangre, un campo de batalla repleto de los cadáveres de todos los que se han atrevido a hacer frente a la Plaga.",18019),
(12619,"esMX","Bien hecho, $N. Has conseguido crear tu primera arma de hojarruna. ¡Con ella sembrarás las semillas del caos y la destrucción! Dejarás una estela de sangre, un campo de batalla repleto de los cadáveres de todos los que se han atrevido a hacer frente a la Plaga.",18019),
(12619,"frFr","Très bien, $N. Vous avez créé votre première arme runique. Avec elle, vous sèmerez chaos et destruction ! Vous laisserez une traînée de carnage derrière vous, jonchée des cadavres de tous ceux qui osent s’opposer au Fléau.",18019),
(12619,"ruRU","Отличная работа, $N. Твой первый рунический клинок готов. С его помощью ты будешь сеять хаос и разрушение, его острием прольешь реки крови и заточишь его лезвие о трупы врагов, осмелившихся бросить вызов могуществу Плети.",18019),
(12842,"esES","Acuérdate de estas palabras, caballero de la Muerte: la forja de runas es un instrumento de la Plaga. ¡Solo existe en Acherus, Naxxramas y en el corazón de Corona de Hielo! Solo puedes blasonar tus armas en una forja de runas.$B$BVuelve con frecuencia y blasona tus armas. ¡Un caballero de la Muerte debe estar preparado para todo lo que se atreva a combatir con él!",18019),
(12842,"esMX","Acuérdate de estas palabras, caballero de la Muerte: la forja de runas es un instrumento de la Plaga. ¡Solo existe en Acherus, Naxxramas y en el corazón de Corona de Hielo! Solo puedes blasonar tus armas en una forja de runas.$B$BVuelve con frecuencia y blasona tus armas. ¡Un caballero de la Muerte debe estar preparado para todo lo que se atreva a combatir con él!",18019),
(12842,"ruRU","Запомни, рыцарь смерти: кузня рун – это инструмент Плети. Найти его можно только в Акерусе, Наксрамасе и в самом сердце Ледяной Короны! Только с помощью рунической кузницы можно наносить гравировку на твое оружие.$B$BНе забывай покрывать рунами любой клинок, которым ты владеешь. Рыцарь смерти должен быть готов к любым опасностям, которые встретятся ему на пути!",18019),
(12848,"esES","Como esperaba, ¡mi caballero elegido ha triunfado! Estás listo, $N.",18019),
(12848,"esMX","Como esperaba, ¡mi caballero elegido ha triunfado! Estás listo, $N.",18019),
(12848,"frFr","Comme je m’y attendais, mon chevalier a triomphé ! Vous êtes prêt, $N. ",18019),
(12848,"ruRU","Как я и ожидал, мой верный рыцарь смерти вернулся с победой! Твое обучение завершено, $N.",18019);

UPDATE `quest_template_locale` SET `ObjectiveText1`="Iniciado indigno dominato" WHERE `ID`=12848 AND (`locale`="esES" OR `locale`="esMX");
UPDATE `quest_template_locale` SET `ObjectiveText1`="Initié indigne dominé" WHERE `ID`=12848 AND `locale`="frFR";
UPDATE `quest_template_locale` SET `ObjectiveText1`="Побеждено недостойных учеников" WHERE `ID`=12848 AND `locale`="ruRU";
UPDATE `quest_template_locale` SET `ObjectiveText1`="Forja de Nuevo Avalon analizada",`ObjectiveText2`="Concejo de Nuevo Avalon analizada",`ObjectiveText3`="Bastión Escarlata analizada",`ObjectiveText4`="Capilla de la Llama Carmesí analizada" WHERE `ID`=12641 AND (`locale`='esES' OR `locale`='esMX');
UPDATE `quest_template_locale` SET `ObjectiveText1`="Forge de la Nouvelle-Avalon analysée",`ObjectiveText2`="Hôtel de ville de la Nouvelle-Avalon analysée",`ObjectiveText3`="Fort écarlate analysée",`ObjectiveText4`="Chapelle de la flamme cramoisie analysée" WHERE `ID`=12641 AND `locale`="frFR";
UPDATE `quest_template_locale` SET `ObjectiveText1`="Осмотрена Кузня Нового Авалона",`ObjectiveText2`="Осмотрена Ратуша Нового Авалона",`ObjectiveText3`="Осмотрена Крепость Алого ордена",`ObjectiveText4`="Осмотрена Часовня Багрового Пламени" WHERE `ID`=12641 AND `locale`="ruRU";
UPDATE `quest_template_locale` SET `ObjectiveText1`="Cruzado Escarlata asesinada",`ObjectiveText2`="Ciudadano de Villa Refugio asesinada" WHERE `ID`=12678 AND (`locale`='esES' OR `locale`='esMX');
UPDATE `quest_template_locale` SET `ObjectiveText1`="Croisé écarlate tué",`ObjectiveText2`="Citoyen de Havre-comté tué" WHERE `ID`=12678 AND `locale`="frFR";
UPDATE `quest_template_locale` SET `ObjectiveText1`="Убито крестоносцев Алого Ордена",`ObjectiveText2`="Убито граждан Тихоземья" WHERE `ID`=12678 AND `locale`="ruRU";
