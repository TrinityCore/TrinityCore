-- 254 Excavar la tierra
-- https://es.classic.wowhead.com/quest=254
SET @ID := 254;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Excavas entre la tierra suelta que hay sobre la tumba... y encuentras los restos de un féretro.$B$BEn el interior del féretro puedes sentir la vibración de unos dedos arañando y el rechinar de unos dientes podridos...$B$B¿Abrirás el féretro y extraerás el corazón del embalsamador?', 0);
-- 343 Hablando de entereza
-- https://es.classic.wowhead.com/quest=343
SET @ID := 343;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Metalurgia? Ah, sí, tenemos muchos libros sobre eso. Estoy encantado de poder ayudar al hermano Kristoff con su discurso. Y ahora... ¿Qué libro en particular necesita el buen hermano?', 0);
-- 1274 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1274
SET @ID := 1274;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. Soy el Obispo DeLavey.$B$BSin duda, si estás aquí preguntándome sobre mi asunto del Castillo, es porque el joven Thomas ha tenido éxito a la hora de pedirte ayuda para nuestro reino. Siempre ha sido experto en hacer lo que le pido.$B$BMe temo que no tengo mucho tiempo para explicarme, así que iré directo al problema... y, por favor, intenta que nadie se entere de esto.', 0);
-- 2923 Maestro manitas Sobrechispa
-- https://es.classic.wowhead.com/quest=2923
SET @ID := 2923;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Sí, hemos perdido el control del tecnobot. ¿Puedes ayudarme?', 0);
-- 1793 Escrito sobre valor
-- https://es.classic.wowhead.com/quest=1793
SET @ID := 1793;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Se ha demostrado que la Luz camina a tu lado, $n, pero el peligro nos acecha cada día y es importante saber qué fuerza se esconde en el interior de cada uno. Tu temple se pondrá a prueba cuando demonios, dragones, o cualquier otro ser malvado entre en tus tierras. ¿Serás lo suficientemente fuerte?$B$BEl coraje, sin tener en cuenta en qué situación, es tan necesario para los paladines como la Luz, tu armadura y tu arma. Proteger a los débiles y no perder la fe, son dos lecciones más que tendrás que aprender cuando estudies en la Catedral de la Luz.', 0);
-- 1649 Escrito sobre valor
-- https://es.classic.wowhead.com/quest=1649
SET @ID := 1649;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, quieres pedirme una prueba de coraje. Espléndido.$B$BHay muchas tareas en la ciudad y en las tierras de alrededor que presentan muchos desafíos, perfectos para alguien con tus habilidades.$B$BEsta prueba no se puede tomar a la ligera, $n. Esto, al igual que muchas cosas con las que te encontrarás en tu camino, podría costarte la vida. La iglesia siempre quiere reforzar sus filas, pero también comprende los sacrificios necesarios para asegurar que los paladines son dignos de ella.$B$B¿Estás preparado?', 0);
-- 1650 Escrito sobre valor
-- https://es.classic.wowhead.com/quest=1650
SET @ID := 1650;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. Por la armadura y todas esas armas que llevas, supongo que estás aquí para intentar conquistar mi tierra, o porque la iglesia por fin ha enviado a alguien para protegerme mientras mi Jordan no está.$B$BBueno, me presentaré: soy Daphne Fontana. Es un placer.$B$BNo llegas demasiado tarde... Solo he matado media docena de esas bestias desde el último amanecer. Han tardado bastante en subir por esa curva de ahí, pero probablemente te hayan visto venir, así que supongo que estarán aquí en cualquier momento.', 0);
-- 270 La flota maldita
-- https://es.classic.wowhead.com/quest=270
SET @ID := 270;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El hierro Forjaluz es un metal precioso, pero parece que tu misión es muy peligrosa. Has hecho un largo camino, $ghermano:hermana;. Con suerte, encontrarás lo que buscas.$B$BY, si consigues el hierro, sé quién puede forjar un arma para luchar contra ese Necromántico del que hablas del Bosque del Ocaso.', 0);
-- 2040 Asalto subterráneo
-- https://es.classic.wowhead.com/quest=2040
SET @ID := 2040;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has encontrado la dentrituradora goblin, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Bien hecho, $n. Gracias a ti, Gnomeregan está a un paso más cerca de su día de liberación.', 0);
-- 2928 Excavadoras gyroagujereamáticas
-- https://es.classic.wowhead.com/quest=2928
SET @ID := 2928;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Si esto fuera una carrera, ya habrías perdido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Esto será perfecto, $n. Una excavadoras gyroagujereamática arreglada, solo quedan 398.', 0);
-- 167 Oh, hermano...
-- https://es.classic.wowhead.com/quest=167
SET @ID := 167;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has encontrado alguna pista de mi hermano? ¿Hay alguna esperanza después de todo este tiempo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Mis sospechas eran ciertas! Mi pobre hermano... Bueno, gracias, al menos ahora tengo la conclusión del misterio, incluso aunque la conclusión sea trágica.', 0);
-- 168 Recolección de recuerdos
-- https://es.classic.wowhead.com/quest=168
SET @ID := 168;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Conseguiste recuperar alguna de las Tarjetas del Sindicato Minero de mis colegas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por esto, $n. Tus esfuerzos contribuirán a traer la paz a los caídos en los comienzos de esta tragedia. Me aseguraré de que se informe a las familias.', 0);
-- 543 La Tiara Perenolde
-- https://es.wowhead.com/quest=543
-- https://wow-es.gamepedia.com/Misión:La Tiara Perenolde
SET @ID := 543;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. Intenta evitar pisar el dobladillo de mis pantalones. Este traje es nuevo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ah, qué bien! Está claro que habrá que limpiar esto pero, realmente, te has superado a ti mismo, $n. Haré que alguien prepare la tiara y la coloque en nuestra colección con presteza.$B$BHas de saber que nuestra gratitud, es tan inmensa como nuestra colección.', 0);
-- 1241 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1241
SET @ID := 1241;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mmm, será mejor que tengas una buena razón para interrumpir a un hombre que está pescando. No me gustan mucho los vendedores ambulantes y mucho menos los vagabundos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mmm... <Jorgen te mira con los ojos entrecerrados.>$B$BMuy bien. Te ayudaré, pero no porque quiero hacerlo, sino porque estoy obligado.$B$BY dejemos una cosa clara: sabes más de lo que deberías saber. Mantengamos esto en secreto y no vayas por las tabernas por ahí hablando de tus descubrimientos. ¿Comprendido?', 0);
-- 344 Hermano Paxton
-- https://es.classic.wowhead.com/quest=344
SET @ID := 344;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Gavilla se pregunta dónde está su libro? ¡Qué vergüenza! Tengo el libro, pero sigo haciendo la copia y todavía no puedo darte el original.', 0);
-- 579 La biblioteca de Ventormenta
-- https://es.classic.wowhead.com/quest=579
SET @ID := 579;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El rey Varian ha otorgado gran importancia al aprendizaje y, por lo tanto, ha proporcionado fondos para hacer disponibles al público copias de varios tomos y escritos. Es muy simple. Tráeme un libreto de la biblioteca y puedo darte una copia de uno de los libros disponibles.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Te interesa alguno de estos títulos, $N?', 0);
-- 1242 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1242
SET @ID := 1242;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. ¿Puedo hacer algo por ti? ¿Quizás te gustaría probar nuestro cheddar de Trias especial? ¿O un trocito de queso azul de Darnassus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Perdona, ¿una carta para mí? Bueno, yo... cuando te pasas el día trabajando, como yo, no se suele recibir algo que no sea una caja o un barril. Veamos de qué va esto.$B$B<Elling te mira mientras abre la carta.>$B$BPareces algo tenso, $n, ¿estás bien?', 0);
-- 345 Suministros de tinta
-- https://es.classic.wowhead.com/quest=345
SET @ID := 345;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡¿Que necesitas qué?! Por si no te has dado cuenta, estamos muy ocupados fortificando las defensas de Villa del Lago y reparando el daño sufrido por los ataques orcos. Si necesitas mineral de hierro de Rethban, ¡vete a buscarlo!', 0);
-- 1243 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1243
SET @ID := 1243;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'No es demasiado seguro ir por el bosque, $n. Ten cuidado y, si ves algo sospechoso o peligroso, avisa a los vigilantes inmediatamente. No intentes nada sin ayuda. No nos hacemos responsables de ninguna cosa terrible que te pueda suceder.$B$BPero ambos sabemos que vas a pasar de mí y a luchar contra cualquier cosa que aparezca en medio de la oscuridad, ¿verdad? ¡Ja, ja! Sí, vosotros, los aventureros... sois todos iguales.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Te envía Trias, eh? Eso cambia la cosa.$B$BEntonces, puedes luchar contra cualquier monstruosidad que salga de la oscuridad. Seguro que podrás vencer lo que sea fácilmente, ya que eres capaz de tratar con gente de su calaña.$B$BY bien, ¿para qué me necesita mi amigo en un día tan funesto como este?', 0);
-- 1651 Escrito sobre valor
-- https://es.classic.wowhead.com/quest=1651
SET @ID := 1651;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Lo hemos logrado, $n! Gracias por tu ayuda. Estuviste realmente increíble ahí fuera. Nunca pensé que un $c pudiera manejar tantos enemigos a la vez.$B$BRealmente has demostrado valentía frente a las abrumadoras probabilidades.', 0);
-- 347 La mena de Rethban
-- https://es.classic.wowhead.com/quest=347
SET @ID := 347;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tienes el mineral de hierro de Rethban?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Oh, excelente! Puedo usar este mineral para hacer la tinta y después terminar de copiar La tensión del hierro.$B$B¡Gracias, $n!', 0);
-- 1244 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1244
SET @ID := 1244;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ten cuidado ahí fuera, $n. Sé que Trias fue quien te envió, pero eso no significa que no haya nada acechando en los bosques que podría causarte un par de problemas... especialmente contigo investigando a los Defias.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Has vuelto de una pieza. Y no se puede pedir mucho más que eso, ¿eh?$B$BAhora, veamos lo que tenemos aquí. Esto parece bastante oficial, a juzgar por los documentos Defias que he visto. Pero podría ser una falsificación, solo para hacerte perder la pista de lo que estés buscando.', 0);
-- 1245 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1245
SET @ID := 1245;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Veo que has vuelto, y que estás de una pieza. Ambos sabemos que no estás aquí por el queso, así que vayamos al grano. ¿Backus te ayudó, o todavía no has terminado en el Bosque del Ocaso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Sí... una lectura interesante. Jorgen y DeLavey fueron inteligentes por avisarme.$B$BParece que los Defias han estado esforzándose mucho por completar este plan. Espera, ¿qué es esto? ¿"Puño"? Ese nombre me suena.', 0);
-- 346 Regresa junto a Kristoff
-- https://es.classic.wowhead.com/quest=346
SET @ID := 346;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has conseguido encontrar el libro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Exacto! Gracias, $n. Que la Luz brille sobre tu cuerpo y tu espíritu.', 0);
-- 1246 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1246
SET @ID := 1246;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡¿Qué?!$B$B¿¿¿Vienes a mi callejón a hacerme preguntas personales sobre mis asuntos??? Asuntos con los que, obviamente, no tienes nada que ver.', 0);
