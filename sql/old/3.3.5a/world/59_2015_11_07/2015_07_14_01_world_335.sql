--
UPDATE `quest_template_addon` SET `AllowableClasses`=128 WHERE `id`=10068;
UPDATE `quest_template_addon` SET `AllowableClasses`=2 WHERE `id`=10069;
UPDATE `quest_template_addon` SET `AllowableClasses`=4 WHERE `id`=10070;
UPDATE `quest_template_addon` SET `AllowableClasses`=8 WHERE `id`=10071;
UPDATE `quest_template_addon` SET `AllowableClasses`=16 WHERE `id`=10072;
UPDATE `quest_template_addon` SET `AllowableClasses`=256 WHERE `id`=10073;

UPDATE `creature_queststarter` SET `quest`=10068 WHERE `id`=15279 AND `quest`=10069;
UPDATE `creature_queststarter` SET `quest`=10069 WHERE `id`=15280 AND `quest`=10068;
UPDATE `creature_queststarter` SET `quest`=10073 WHERE `id`=15283 AND `quest`=10073;
UPDATE `creature_queststarter` SET `quest`=10072 WHERE `id`=15284 AND `quest`=10070;
UPDATE `creature_queststarter` SET `quest`=10071 WHERE `id`=15285 AND `quest`=10071;
UPDATE `creature_queststarter` SET `quest`=10070 WHERE `id`=15513 AND `quest`=10072;
UPDATE `locales_quest` SET 
`Title_loc2`="Veilleur du puits Solanian",
`Title_loc3`="Brunnenbehüter Solanian",
`Title_loc6`="Vigía del pozo Solanian",
`Title_loc7`="Vigía del pozo Solanian",
`Title_loc8`="Хранитель Колодца Соланиан",
`Details_loc2`="Et maintenant, je voudrais que vous fassiez quelque chose.$B$BLe veilleur du puits Solanian a besoin de vos services. C’est quelqu’un avec qui vous avez intérêt à bien vous entendre.$B$BIl vous attend sur la plate-forme extérieure. Lorsque vous serez dans ses appartements, prenez la rampe, elle y conduit.",
`Details_loc3`="Erweist mir jetzt bitte einen Gefallen.$B$BBrunnenbehüter Solanian braucht Eure Unterstützung. Ihr würdet gut daran tun, Euch bei ihm beliebt zu machen.$B$BEr erwartet Euch auf der äußeren Plattform, geht einfach den Aufgang in diesem Raum hinauf.",
`Details_loc6`="Y ahora, necesito que hagas algo.$B$BEl vigía del pozo Solanian necesita tus servicios. No te vendría mal congraciarte con él.$B$BTe espera en la plataforma exterior hasta la que lleva la rampa de su cámara.",
`Details_loc7`="Y ahora, necesito que hagas algo.$B$BEl vigía del pozo Solanian necesita tus servicios. No te vendría mal congraciarte con él.$B$BTe espera en la plataforma exterior hasta la que lleva la rampa de su cámara.",
`Details_loc8`="А теперь мне нужно, чтобы ты кое-что $g.$B$BХранителю Колодца Соланиану нужна твоя помощь. Тебе будет полезно заслужить его благосклонность.$B$BОн ждет тебя на внешней платформе, на которую выходит пандус из этого зала.",
`Objectives_loc2`="Parlez au veilleur du puits Solanian à la Flèche solaire sur l'île de Haut-soleil.",
`Objectives_loc3`="Sprecht mit Brunnenbehüter Solanian im Sonnenturm auf der Insel der Sonnenwanderer.",
`Objectives_loc6`="Habla con el vigía del pozo Solanian en La Aguja del Sol, en la Isla del Caminante del Sol.",
`Objectives_loc7`="Habla con el vigía del pozo Solanian en La Aguja del Sol, en la Isla del Caminante del Sol.",
`Objectives_loc8`="Поговорите с хранителем Колодца Соланианом в Солнечном Шпиле на острове Солнечного Скитальца.",
`OfferRewardText_loc2`="Ah bien, $gun:une; $c. Je t'attendais.$B$BJ'ai quelques tâches pour vous qui vous iront à merveille.",
`OfferRewardText_loc3`="Ah, wie schön, ein $c. Ich habe Euch bereits erwartet.$B$BIch hätte da ein paar Aufgaben zu vergeben, für die Ihr Euch besonders gut eignet.",
`OfferRewardText_loc6`="Ah bien, $gun:una; $c. Te he estado esperando.$B$BTengo unas tareas que son especialmente adecuadas para ti.",
`OfferRewardText_loc7`="Ah bien, $gun:una; $c. Te he estado esperando.$B$BTengo unas tareas que son especialmente adecuadas para ti.",
`OfferRewardText_loc8`="Я ждал тебя, $c.У меня есть несколько поручений, для выполнения которых ты подходишь как нельзя лучше."
WHERE `id` IN (10068, 10069, 10070, 10071, 10072, 10073);
