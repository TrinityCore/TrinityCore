-- 219 Desaparecido en combate
-- https://es.classic.wowhead.com/quest=219
SET @ID := 219;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has prestado un gran servicio al Reino, $c. Gracias por ayudar al cabo Keeshan a huir de los Roca Negra. Recibirás una recompensa por tus heroicas acciones.', 0),
(@ID, 'esMX', 'Has prestado un gran servicio al Reino, $c. Gracias por ayudar al cabo Keeshan a huir de los Roca Negra. Recibirás una recompensa por tus heroicas acciones.', 0);
-- 220 La llamada del agua
-- https://es.classic.wowhead.com/quest=220
SET @ID := 220;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola de nuevo, $n. Tienes buen aspecto.$B$B¿Qué te trae por aquí tan pronto?', 0),
(@ID, 'esMX', 'Hola de nuevo, $n. Tienes buen aspecto.$B$B¿Qué te trae por aquí tan pronto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, un vial de agua creado y bendecido por Brine y reunido por ti, nada menos.$B$BEl líquido de este vial será vital en la creación de sapta para ti pero también se usará en otra tarea.$B$BLa sapta que cree para ti también servirá para ver los espíritus del agua del altar que se encuentra en el Bosque de Argénteos, al sur de Entrañas. En cuanto a las gotas restantes, pues, te lo contaré si crees que estás $gpreparado:preparada;.$B$B¿Estás $gpreparado:preparada; para otro viaje, $n?', 0),
(@ID, 'esMX', 'Ah, un vial de agua creado y bendecido por Brine y reunido por ti, nada menos.$B$BEl líquido de este vial será vital en la creación de sapta para ti pero también se usará en otra tarea.$B$BLa sapta que cree para ti también servirá para ver los espíritus del agua del altar que se encuentra en el Bosque de Argénteos, al sur de Entrañas. En cuanto a las gotas restantes, pues, te lo contaré si crees que estás $gpreparado:preparada;.$B$B¿Estás $gpreparado:preparada; para otro viaje, $n?', 0);
-- 225 La lápida desgastada
-- https://es.classic.wowhead.com/quest=225
SET @ID := 225;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Morgan Ladimor?$B$BAh, sí, claro. La suya es una historia larga y llena de desgracias. Yo lo conocía bien, bueno, antes de que se fuera a al guerra, pero esa fue la última vez que lo vi. Era un buen hombre, un hombre noble, pero tuvo un trágico final.$B$BTen, tengo algo aquí que podría contarte su historia mejor que yo.', 0),
(@ID, 'esMX', '¿Morgan Ladimor?$B$BAh, sí, claro. La suya es una historia larga y llena de desgracias. Yo lo conocía bien, bueno, antes de que se fuera a al guerra, pero esa fue la última vez que lo vi. Era un buen hombre, un hombre noble, pero tuvo un trágico final.$B$BTen, tengo algo aquí que podría contarte su historia mejor que yo.', 0);
-- 227 Morgan Ladimor
-- https://es.classic.wowhead.com/quest=227
SET @ID := 227;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Morgan Ladimor? No sé quién es...$B$BAh, espera, ¡te refieres a Mor\'Ladim! Supongo que no has oído la historia.$B$BPues te contaré la versión resumida. Un no-muerto que se llama a sí mismo Mor\'Ladim ha estado deambulando por el Bosque del Ocaso. Por lo que sé, parece ser el cuerpo no-muerto de Morgan Ladimor, que es la persona que buscas. Nos ha causado todo tipo de problemas, ha estado atacando a los vigilantes que patrullaban la zona y ha matado a gente.$B$B<Te mira de arriba a abajo.>$B$BParece que tú podrías proporcionarle descanso.', 0),
(@ID, 'esMX', '¿Morgan Ladimor? No sé quién es...$B$BAh, espera, ¡te refieres a Mor\'Ladim! Supongo que no has oído la historia.$B$BPues te contaré la versión resumida. Un no-muerto que se llama a sí mismo Mor\'Ladim ha estado deambulando por el Bosque del Ocaso. Por lo que sé, parece ser el cuerpo no-muerto de Morgan Ladimor, que es la persona que buscas. Nos ha causado todo tipo de problemas, ha estado atacando a los vigilantes que patrullaban la zona y ha matado a gente.$B$B<Te mira de arriba a abajo.>$B$BParece que tú podrías proporcionarle descanso.', 0);
-- 228 Mor'Ladim
-- https://es.classic.wowhead.com/quest=228
SET @ID := 228;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me extraña que te esté dando problemas, $n. Algunos de nuestros guardias más fuertes han perdido la vida a manos de Mor\'Ladim.', 0),
(@ID, 'esMX', 'No me extraña que te esté dando problemas, $n. Algunos de nuestros guardias más fuertes han perdido la vida a manos de Mor\'Ladim.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo mataste? ¡Es toda una hazaña, $n! Te doy las gracias de parte de las gentes de Villa Oscura y de parte de La Guardia Nocturna.$B$BAh... pero hay una cosilla...', 0),
(@ID, 'esMX', '¿Lo mataste? ¡Es toda una hazaña, $n! Te doy las gracias de parte de las gentes de Villa Oscura y de parte de La Guardia Nocturna.$B$BAh... pero hay una cosilla...', 0);
-- 229 La hija superviviente
-- https://es.classic.wowhead.com/quest=229
SET @ID := 229;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? Mi padre...$B$B<Baja la mirada, abatida..>$B$BOjalá hubiera podido hacer algo por él... Si hubiera hablado con él antes de...', 0),
(@ID, 'esMX', '¿Sí? Mi padre...$B$B<Baja la mirada, abatida..>$B$BOjalá hubiera podido hacer algo por él... Si hubiera hablado con él antes de...', 0);
-- 231 El amor de una hija
-- https://es.classic.wowhead.com/quest=231
SET @ID := 231;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Déjame...', 0),
(@ID, 'esMX', 'Déjame...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El viento trae una voz fantasmal...>$B$B¿Esto es...? ¿Sarah? ¿Es posible que siga con vida? Qué peso me has quitado de encima...$B$B$n. Toma mi espada, Archeus. Mi alma descansará. Ya no volveré a necesitarla. Fue forjada para hacer el bien y, aunque yo he demostrado no ser merecedor de portarla, quizás tú consigas acercarla a la Luz.$B$BLys, mi amor...', 0),
(@ID, 'esMX', '<El viento trae una voz fantasmal...>$B$B¿Esto es...? ¿Sarah? ¿Es posible que siga con vida? Qué peso me has quitado de encima...$B$B$n. Toma mi espada, Archeus. Mi alma descansará. Ya no volveré a necesitarla. Fue forjada para hacer el bien y, aunque yo he demostrado no ser merecedor de portarla, quizás tú consigas acercarla a la Luz.$B$BLys, mi amor...', 0);
-- 232 Un recado para la boticaria Zinge
-- https://es.classic.wowhead.com/quest=232
SET @ID := 232;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, ¿en qué puedo ayudarte? ¿Tienes algo que tratar con la Sociedad Real de Boticarios o has venido simplemente a alegrarme el día?', 0),
(@ID, 'esMX', 'Dime, ¿en qué puedo ayudarte? ¿Tienes algo que tratar con la Sociedad Real de Boticarios o has venido simplemente a alegrarme el día?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conque Zinge necesita un equipo? Me entristece que Zinge no me honre con su dulce presencia.$B$BBueno, te procuraremos un equipo.', 0),
(@ID, 'esMX', '¿Conque Zinge necesita un equipo? Me entristece que Zinge no me honre con su dulce presencia.$B$BBueno, te procuraremos un equipo.', 0);
-- 235 La Caza de Vallefresno
-- https://es.classic.wowhead.com/quest=235
SET @ID := 235;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida a la nueva frontera, $n. Vallefresno es una tierra de oportunidades, sobre todo para alguien como tú. Echa un vistazo y ve a La Ensenada de Zoram; allí hay otra avanzada de la Horda.$B$BTu presencia me dice que has venido a aprender sobre la caza. Escucha con atención y yo compartiré mis secretos contigo.', 0),
(@ID, 'esMX', 'Te doy la bienvenida a la nueva frontera, $n. Vallefresno es una tierra de oportunidades, sobre todo para alguien como tú. Echa un vistazo y ve a La Ensenada de Zoram; allí hay otra avanzada de la Horda.$B$BTu presencia me dice que has venido a aprender sobre la caza. Escucha con atención y yo compartiré mis secretos contigo.', 0);
-- 236 Combustible para los demoledores
-- https://es.classic.wowhead.com/quest=236
SET @ID := 236;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Bien? ¿Conseguiste encontrar las ascuas? ¿o la Horda te adelantó y te dejó llorando?', 0),
(@ID, 'esMX', '¿Bien? ¿Conseguiste encontrar las ascuas? ¿o la Horda te adelantó y te dejó llorando?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Esto ayudará a alimentar las llamas de la guerra en los próximos días.', 0),
(@ID, 'esMX', '¡Excelente! Esto ayudará a alimentar las llamas de la guerra en los próximos días.', 0);
-- 238 Un recado para la boticaria Zinge
-- https://es.classic.wowhead.com/quest=238
SET @ID := 238;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, al igual que tú creo que Luca es desconcertante. No importa, dame el equipo de prueba de campo. Tengo que hacerle algunos ajustes para poder recoger los materiales adecuados.$B$BTienes el equipo, ¿verdad?', 0),
(@ID, 'esMX', 'Sí, al igual que tú creo que Luca es desconcertante. No importa, dame el equipo de prueba de campo. Tengo que hacerle algunos ajustes para poder recoger los materiales adecuados.$B$BTienes el equipo, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra que no me hagas perder el tiempo.$B$BCuando haya realizado los ajustes, podrás utilizar este equipo para recoger la información que precises.$B$BEspera un momento a que acabe y, entre tanto, ¿por qué no vas pensando en qué te gustaría llevar contigo al desierto?$B$BSí, sí, he dicho al desierto.', 0),
(@ID, 'esMX', 'Me alegra que no me hagas perder el tiempo.$B$BCuando haya realizado los ajustes, podrás utilizar este equipo para recoger la información que precises.$B$BEspera un momento a que acabe y, entre tanto, ¿por qué no vas pensando en qué te gustaría llevar contigo al desierto?$B$BSí, sí, he dicho al desierto.', 0);
-- 243 In situ
-- https://es.classic.wowhead.com/quest=243
SET @ID := 243;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, nuestras fuentes de alimentación, modelo 4711-FTZ! Solemos utilizarlas para el funcionamiento de los pozos de agua, pero GRACIAS A LOS VILES NÓMADAS, tenemos exceso de existencias ahora mismo.$B$BAsí que, seguro que puedo conseguirte una fuente de alimentación para el nefario experimento científico que tratas de ocultarme, sea el que sea. Aunque no será gratis, $r. Nada es gratis en Gadgetzan.', 0),
(@ID, 'esMX', '¡Ah, nuestras fuentes de alimentación, modelo 4711-FTZ! Solemos utilizarlas para el funcionamiento de los pozos de agua, pero GRACIAS A LOS VILES NÓMADAS, tenemos exceso de existencias ahora mismo.$B$BAsí que, seguro que puedo conseguirte una fuente de alimentación para el nefario experimento científico que tratas de ocultarme, sea el que sea. Aunque no será gratis, $r. Nada es gratis en Gadgetzan.', 0);
-- 247 El fin de la Caza
-- https://es.classic.wowhead.com/quest=247
SET @ID := 247;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, has dado muerte a las tres bestias que comprenden la caza de Vallefresno. Me has traído prueba suficiente de su derrota; no cabe la menor duda acerca de tu fuerza y tenacidad. Por tus venas corre la sangre de $gun cazador:una cazadora; ¡y mereces los más elevados elogios!$B$BTe ruego aceptes este adorno como muestra de reconocimiento a tus descomunales esfuerzos realizados en Vallefresno para la Horda hoy. ¡Que tus ancestros estén contigo!', 0),
(@ID, 'esMX', '$n, has dado muerte a las tres bestias que comprenden la caza de Vallefresno. Me has traído prueba suficiente de su derrota; no cabe la menor duda acerca de tu fuerza y tenacidad. Por tus venas corre la sangre de $gun cazador:una cazadora; ¡y mereces los más elevados elogios!$B$BTe ruego aceptes este adorno como muestra de reconocimiento a tus descomunales esfuerzos realizados en Vallefresno para la Horda hoy. ¡Que tus ancestros estén contigo!', 0);
-- 248 Ver más allá
-- https://es.classic.wowhead.com/quest=248
SET @ID := 248;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este tarro contenía un licor pestilente, pero ahora está vacío, tirado entre dos barriles.', 0),
(@ID, 'esMX', 'Este tarro contenía un licor pestilente, pero ahora está vacío, tirado entre dos barriles.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una vasija adecuada para el Glifo de Azora, que permite a Theocritus explorar las mentes que hay en el Fuerte de Petravista.', 0),
(@ID, 'esMX', 'Es una vasija adecuada para el Glifo de Azora, que permite a Theocritus explorar las mentes que hay en el Fuerte de Petravista.', 0);
-- 249 Morganth
-- https://es.classic.wowhead.com/quest=249
SET @ID := 249;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n, tienes que evitar que Morganth extienda su poder!', 0),
(@ID, 'esMX', '¡$n, tienes que evitar que Morganth extienda su poder!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Al derrotar a Morganth, has librado a Ventormenta de un grave peligro.$B$BAcepta esta recompensa. Te diría que fueras en paz, pero estos no son tiempos de paz.$B$BEn lugar de eso, te deseo suerte en tus pruebas y victoria en combates futuros.', 0),
(@ID, 'esMX', 'Muy bien, $n. Al derrotar a Morganth, has librado a Ventormenta de un grave peligro.$B$BAcepta esta recompensa. Te diría que fueras en paz, pero estos no son tiempos de paz.$B$BEn lugar de eso, te deseo suerte en tus pruebas y victoria en combates futuros.', 0);
-- 264 Hasta que la muerte nos separe
-- https://es.classic.wowhead.com/quest=264
SET @ID := 264;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La piedra está fría y su estado demuestra que se han ensañado con ella. La zona está llena de basura, el féretro presenta golpes y grietas y las malas hierbas empiezan a crecer a su alrededor.$B$BA nadie le importa quién está enterrado aquí, sobre todo a ninguna de las víctimas de la peste.', 0),
(@ID, 'esMX', 'La piedra está fría y su estado demuestra que se han ensañado con ella. La zona está llena de basura, el féretro presenta golpes y grietas y las malas hierbas empiezan a crecer a su alrededor.$B$BA nadie le importa quién está enterrado aquí, sobre todo a ninguna de las víctimas de la peste.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el colgante sobre la tumba y observas que la gema parece perder su brillo.$B$BCuando te incorporas para marcharte, miras de nuevo el collar, que yace inánime en las manos de la escultura que preside el féretro. Una ráfaga de viento frío recorre El Sepulcro, interrumpiendo así tus pensamientos. Por un momento, el silencio reina a tu alrededor.', 0),
(@ID, 'esMX', 'Colocas el colgante sobre la tumba y observas que la gema parece perder su brillo.$B$BCuando te incorporas para marcharte, miras de nuevo el collar, que yace inánime en las manos de la escultura que preside el féretro. Una ráfaga de viento frío recorre El Sepulcro, interrumpiendo así tus pensamientos. Por un momento, el silencio reina a tu alrededor.', 0);
-- 272 La prueba del león marino
-- https://es.classic.wowhead.com/quest=272
SET @ID := 272;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes tu colgante, $n? Si no encuentras las piezas, habla con la gente del lugar. Encontrarás lo que buscas y podrás explorar este lugar sagrado.', 0),
(@ID, 'esMX', '¿Traes tu colgante, $n? Si no encuentras las piezas, habla con la gente del lugar. Encontrarás lo que buscas y podrás explorar este lugar sagrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Enhorabuena por completar la Prueba del León Marino, $n.$B$BHas aprendido que necesitas agilidad y resistencia para moverte en armonía en el agua. y que para ello debes abrazar el aspecto del león marino.$B$BEstas lecciones te serán muy útiles cuando ganes tu forma acuática.', 0),
(@ID, 'esMX', 'Enhorabuena por completar la Prueba del León Marino, $n.$B$BHas aprendido que necesitas agilidad y resistencia para moverte en armonía en el agua. y que para ello debes abrazar el aspecto del león marino.$B$BEstas lecciones te serán muy útiles cuando ganes tu forma acuática.', 0);
-- 312 La reserva robada de Tundra MacGrann
-- https://es.classic.wowhead.com/quest=312
SET @ID := 312;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste entrar en mi almacén de carne, $n?', 0),
(@ID, 'esMX', '¿Conseguiste entrar en mi almacén de carne, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué amabilidad la tuya, $n! ¡Y qué valor! Gracias a ti no me moriré de hambre cuando llegue la estación fría.', 0),
(@ID, 'esMX', '¡Qué amabilidad la tuya, $n! ¡Y qué valor! Gracias a ti no me moriré de hambre cuando llegue la estación fría.', 0);
-- 328 La llave oculta
-- https://es.classic.wowhead.com/quest=328
SET @ID := 328;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La caja fuerte es de bronce. Muy sólida y pesada.', 0),
(@ID, 'esMX', 'La caja fuerte es de bronce. Muy sólida y pesada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Queda claro que, la caja fuerte, es donde Herod guarda sus monedas y objetos más valiosos.', 0),
(@ID, 'esMX', 'Queda claro que, la caja fuerte, es donde Herod guarda sus monedas y objetos más valiosos.', 0);
-- 329 ¡Espía descubierto!
-- https://es.classic.wowhead.com/quest=329
SET @ID := 329;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has descubierto quién sabía el secreto de Thorsen? ¿Hay un traidor entre nosotros?', 0),
(@ID, 'esMX', '¿Has descubierto quién sabía el secreto de Thorsen? ¿Hay un traidor entre nosotros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Esta nota es la pista que necesitábamos para dar con el traidor.', 0),
(@ID, 'esMX', 'Gracias, $n. Esta nota es la pista que necesitábamos para dar con el traidor.', 0);
-- 330 Horarios de patrulla
-- https://es.classic.wowhead.com/quest=330
SET @ID := 330;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, claro que puedo comprobar eso. Veamos... la semana pasada era...$B$B...por qué..., el soldado Merle estaba de guardia con Thorsen. Tenían la misma hora de patrulla durante toda la semana pasada.', 0),
(@ID, 'esMX', 'Ah, sí, claro que puedo comprobar eso. Veamos... la semana pasada era...$B$B...por qué..., el soldado Merle estaba de guardia con Thorsen. Tenían la misma hora de patrulla durante toda la semana pasada.', 0);
-- 331 Informa a Doren
-- https://es.classic.wowhead.com/quest=331
SET @ID := 331;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me duele descubrir que fue Merle quien nos traicionó. Siempre ha sido un buen soldado y yo creí en su lealtad. Pero me alivia haberle descubierto... con un espía como él entre nosotros... no habríamos durado mucho contra el coronel Kurzen.', 0),
(@ID, 'esMX', 'Me duele descubrir que fue Merle quien nos traicionó. Siempre ha sido un buen soldado y yo creí en su lealtad. Pero me alivia haberle descubierto... con un espía como él entre nosotros... no habríamos durado mucho contra el coronel Kurzen.', 0);
-- 335 Una noble cerveza
-- https://es.classic.wowhead.com/quest=335
SET @ID := 335;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pronto, Wishock conseguirá suficientes refuerzos y suministros como para causarnos muchos problemas. ¿Has conseguido obtener la lágrima de Tilloa o la zibética ya?', 0),
(@ID, 'esMX', 'Pronto, Wishock conseguirá suficientes refuerzos y suministros como para causarnos muchos problemas. ¿Has conseguido obtener la lágrima de Tilloa o la zibética ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Soberbio! ¡Por fin tengo lo que necesitaba!', 0),
(@ID, 'esMX', '¡Soberbio! ¡Por fin tengo lo que necesitaba!', 0);
