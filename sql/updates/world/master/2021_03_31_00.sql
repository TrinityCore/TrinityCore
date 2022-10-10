-- DB update 2021_03_29_01 -> 2021_03_31_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_29_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_29_01 2021_03_31_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616472392022033200'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616472392022033200');

DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN (10119, 10288, 10140, 10254, 10047, 9492, 10058, 9493, 13408, 9494, 10160, 10482, 10483, 10484, 10485, 10903, 10916, 10909, 10935, 10936, 10937, 10919, 10055, 10078, 10050, 10057, 10141, 10142, 10895, 10143, 10144, 10146, 10340, 10344, 10163, 10346, 10382, 10394, 10396, 10397, 10093, 9398, 9383, 9426, 9427, 9390, 9423, 9424, 9543, 9430, 9545, 9399, 9490, 10443, 9355, 10079, 10099, 9558, 9417, 9385, 9563, 9420, 9575, 9607, 11002, 9372, 10255, 10132, 10159, 9912, 10134, 10349, 10351, 10403, 10367, 10368, 10369, 10236, 10238, 10629, 10630, 10161, 9351, 9349, 9361, 9356) AND `locale` IN ('esES');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10119,'esES','Bienvenido a terrallende $N, bienvenido a la pesadilla! Aunque la fuerza expedicionaria inicial salió ilesa, la legión está tratando de retomar el portal oscuro y evitar que lleguen más de nuestros refuerzos.$B$BPor mucho que me gustaría su ayuda aquí, nuestras tropas y los soldados de la horda son capaces de defenderse de los pelotones de la legión que intentan tomar el control de esta plataforma.$B$BTe necesitamos donde tu talento pueda ser mejor utilizado',18019),
(10288,'esES','¿Reportar al bastión de honor? ¡No hay problema! Llegarás rápido y seguro montándote en uno de mis grifos.',18019),
(10140,'esES','Nuestra expedición a este mundo abandonado casi se ha detenido $N, encontramos más resistencia de la que esperábamos.$B$BComo si enfrentarnos a la legión ardiente de nuevo no fuera suficiente.$B$BHay horrores en esta tierra que no se parecen a nada de lo que hemos encontrado...',18019),
(10254,'esES','Bien dicho hermano mío, me alegro de que hayas venido. Soy Danath, líder de los hijos de Lothar y comandante de la fuerza de este bastión.',18019),
(10047,'esES','Tiene mis más sinceros agradecimientos $N. Pensé que quedaba mucho por hacer, pero me alegra saber que hemos ayudado a algunos a encontrar su merecido descanso.',18019),
(9492,'esES','Bien hecho $N. Con su victoria en la ciudadela de fuego infernal, hemos dado un duro golpe contra los orcos.$B$BDebo hablar con el comandante Romus acerca del este seguimiento y asegurar de que los orcos permanezcan a la defensiva. Ahora que hemos sido reforzados podemos hacer mucho más que simplemente defender el bastión de honor.',18019),
(10058,'esES','¿Es realmente eso? Es difícil creer que sobrevivió a la batalla. Las condiciones en ruinas no han sido amables con mi libro, pero aún así, me alegra tenerlo de vuelta.$B$BEs la única cosa que tengo de turalyon.$B$B<El padre Devidicus parece estar evitando llorar>$B$BCuando luchas al lado de alguien durante tantos años, se convierte en algo más cercano que inclusive una familia.',18019),
(9493,'esES','Eso es una excelente noticia $N. Con el progreso de hacernos notar desde la ciudadela de fuego infernal, tal vez podamos permitirnos llamar la atención de nuestra presencia a la horda vil desde otras partes de península y Terrallende.',18019),
(13408,'esES','Bien hecho, $N. Sus acciones en el campo son instrumentales en nuestra batalla por la península de Fuego Infernal.',18019),
(9494,'esES','¡Bien hecho! No puedo esperar para replicar las hazañas del Brujo Supremo Malbisal, no debo aspirar a ser él, pero seríamos muy tontos ignorando el poder de las ascuas viles.$B$BSin embargo, hay quienes prohibirían este tipo de investigaciones, aún así estoy a punto de embarcarme y por esa razón debo mantener mis esfuerzos en secreto. Por favor, no mencione de esto a nadie $N.',18019),
(10160,'esES','<La teniente Amadi acentúa con la cabeza>$B$BBien, necesitamos toda la ayuda que podamos reunir. El aumento de la presencia de orcos viles alrededor de la muralla sur me preocupa. Envié un explorador para investigar, pero aún no ha regresado.',18019),
(10482,'esES','Muy bueno. Estoy segura de que esta pérdida se sintió en la ciudadela de fuego infernal. Aunque ese bastión oscuro se cierna contra nosotros y parece casi insuperable, es sólo con movimientos audaces como usted ha hecho que vamos a encontrar la victoria sobre los orcos viles!',18019),
(10483,'esES','¿Recuperó una insignia de los orcos Foso sangrante? De acuerdo, es escandaloso que usen nuestros propios símbolos en contra ¡Y se burlen de nuestros compañeros caídos a manos de esas bestias pieles rojas!',18019),
(10484,'esES','Gracias $N. Mi corazón se entristece al ver estos talismanes. Subrayan las grandes pérdidas que el bastión de honor ha sufrido contra los orcos viles. Pero estoy alentado de verte exitoso en contra ellos. Si tan sólo matáramos lo suficiente, probablemente podríamos salir de esta guerra victoriosos.',18019),
(10485,'esES','¡Lo has hecho! ¡Morkh ha sido asesinado! ¡Ahora tenemos una oportunidad de pelear en contra de aquellas bestias viles!$B$BGracias $N. Su ayuda en la guerra de este lugar está más allá de lo común.',18019),
(10903,'esES','Sí, es cierto. La situación del coronel Jules ha decrecido estos últimos días. El anacoreta Barada está ocupado orando por él... esperemos que pueda recuperarse.',18019),
(10916,'esES','¡Encontraste los abalorios de oración! Bien hecho $N. Eres una maravilla, matas en un momento a los horrores de península del fuego infernal y luego encuentras tesoros perdidos. ¡Tu gente realmente inspira!$B$BEs bueno que haya recuperado estos abalorios... porque serán invaluables en el ritual del exorcismo que vendrá..',18019),
(10909,'esES','Los orcos mano destrozada son más asquerosos de lo que esperaba. Mi corazón se entristece al saber que el camino de la salvación para el coronel Jules tiene tal derramamiento de sangre',18019),
(10935,'esES','Lo has hecho $N. Usted ha salvado el alma del coronel Jules y ha expulsado a la oscuridad dentro de él de vuelta dónde vino. ¡Es una gran noble obra! ¡Un día de heroe!',18019),
(10936,'esES','¡Ya era hora! Escuché todo lo que hacías con ese sacerdote draenei. ¡Has enloquecido a mi mensajero!$B$BAhora que ya has terminado con eso, tengo una pequeña misión planeada para ti en la ciudadela de fuego infernal.',18019),
(10937,'esES','No iba a creerlo hasta que lo oí de ti personalmente. Ya nuestros exploradores están goteando la información de que la mano destrozada está en caos sin su precioso maestro de maniobras para decirles qué hacer.$B$BHa viajado por un largo camino $N. Confío en que aceptará esta armadura junto con mis agradecimientos. ¡Pórtelo con orgullo, se lo ha ganado!',18019),
(10919,'esES','<Fei Fei ladra felizmente y agarra la chuchería para perros. Mira a la izquierda y a la derecha... decidiendo dónde debe esconder este nuevo tesoro...>',18019),
(10055,'esES','Esto está en mejores condiciones de lo que pensé. Seguro va a tomar tiempo limpiar todo el óxido, carbón y polvo, pero sinceramente no voy a quejarme.',18019),
(10078,'esES','¡Ese es el espíritu!$B$BMe alegro de que finalmente consiguiéramos reunir algunos refuerzos, pero no estoy tan seguro de su actitud hacia la horda. De donde vengo, cualquiera con un arma apuntando hacia usted es un enemigo y necesita ser tratado como uno!',18019),
(10050,'esES','Los hijos de lothar aprecian sus esfuerzos, inclusive si pocos están dispuestos a hablar de la armería.',18019),
(10057,'esES','Sólo podemos esperar que con el silencio de los fantasmas de los oficiales, los espíritus de los soldados puedan encaminarse también hacia su destino. Gracias una vez más por su ayuda $N',18019),
(10141,'esES','El comandante de la Fuerza Danath pudo haber malentendido mi solicitud de refuerzos. Pareces capaz, pero ¡he pedido un batallón de tamaño completo!$B$BVerás, tenemos un poco de problemas de demonios por aquí...',18019),
(10142,'esES','Excelente trabajo soldado. La frecuencia de los ataques está segura de disminuir, al menos hasta que traigan nuevos señores del terror.$B$BAhora las malas noticias: Tengo nuevas órdenes para usted...',18019),
(10895,'esES','¡Podía ver el humo y las llamas desde aquí! ¡Buen trabajo $N! Recibiste unas cuantas palabras de alabanza por parte de nuestros pilotos de grifos, lo que acabas de hacer es de tener agallas...',18019),
(10143,'esES','Encantado de conocerle soldado.$B$BAhora basta de cháchara y escuche. Tengo una misión vital para ti y quiero que tengas éxito... y por supuesto sobreviva!',18019),
(10144,'esES','Bien hecho $N. ¡Desactivar esos portales frenará el flujo de refuerzos de la legión durante mucho tiempo!$B$BPero aún así no podemos descansar todavía...',18019),
(10146,'esES','¡Eso los retrasará, no lo negaré! Creo que me pusiste de un humor no característico $N.',18019),
(10340,'esES','Ja ja! ¡Un $R fresco de la tierra firme! Bueno, no te preocupes. El puesto devastación podría marearte un poco. ¡Pero ella casi no se desvía mucho!$B$BY sólo la he visto volar una vez... o dos veces.',18019),
(10344,'esES','¿Hablaste con Runetog? Es un buen enano. Mantiene sus grifos en buena forma y listos para la batalla.$B$BSoy Grifongar, comandante del puesto devastación. Sé que no es bonito, pero este trozo de roca es un punto vital para la batalla de Fuego Infernal. ¡Verás grifos volando y sin parar!$B$BConsejo? Aquí hay uno: Mantenga su equipo puesto, el estómago vacío, y su ojo fijado en el horizonte ... sí puesto devastación comienza a ser atacado, ¡Entonces agarre algo que flote lejos!',18019),
(10163,'esES','Vuelas como si estuvieses estado haciendo esto toda su vida $N. ¡Excelente actuación allí fuera! ¡Ni siquiera un rasguño en los grifos destructores!',18019),
(10346,'esES','¿Cómo te ha ido esta vez? Estás en muy buena forma... ¡quizás lo suficiente para viajar una vez más!',18019),
(10382,'esES','Bienvenido $C. ¡Me alegro finalmente de que la vieja enana nos haya visto aptos de enviarnos alguna ayuda!',18019),
(10394,'esES','Bueno, debo decir que estoy impresionado $N. No pensé que tuvieses el temple para esta misión. ¡Bien hecho. bien hecho! En efecto.',18019),
(10396,'esES','Tengo que dárselo a usted $N. ¡Eres un luchador nacido! Esos soldados de la horda tal vez nunca sepan lo cerca que estuvieron de morir. Se necesita un carácter real para que alguien se haga daño en nombre de sus enemigos. ¡Ese es el tipo de honor y compromiso que mantiene unida a la Alianza!$B$B<El mariscal de campo Brock te saluda curruscante>',18019),
(10397,'esES','¡Buen trabajo! Eso debería reducir drásticamente el número de demonios que intentan arrastrarse por nuestro lado trasero. No podría agradecerle por tanta ayuda aquí $N.',18019),
(10093,'esES','Ah, así que conociste al vidente Kryv. Él es un hombre sabio y talentoso y cualquier $R al que llamase amigo, también será mi amigo.$B$BPonte cómodo y preséntate ante otros que llaman a este templo hogar.',18019),
(9398,'esES','Has hecho bien $N. Siempre es lamentable tener que recurrir a la toma de una vida, incluso cuando es la de una bestia peligrosa como la guadaña de piedra.$B$BTienes mis agradecimientos por llevar a cabo esta tarea sombría.',18019),
(9383,'esES','Lo has hecho bien. Parece que el cristal de contención se está sosteniendo por ahora, pero saber cuanto tiempo durará así, sigue siendo un misterio. Lo vigilaremos y prepararemos más cristales mientras tanto.',18019),
(9426,'esES','Sí, siento la presencia vil en las pozas debilitándose.$B$BHas hecho bien $N.',18019),
(9427,'esES','La esencia de Aggonar vivió en su corrupto descendiente, Aggonis. Con su éxito en derrotar al demonio, podemos empezar a trabajar para restaurar las pozas hacia su pureza original.$B$BTienes nuestros agradecimientos $N. Su trabajo tendrá un profundo impacto en este mundo.',18019),
(9390,'esES','Has encontrado el cuerpo de un joven paladín draenei. Parece haber sido asesinado por un golpe en la espalda.',18019),
(9423,'esES','Sedai, querido hermano...$B$B¡Esos orcos cobardes! Estaba desarmado, ¿cómo podrían?$B$BDéjeme estar $N. Le agradezco la ayuda, pero necesito estar a solas con mis pensamientos por ahora.',18019),
(9424,'esES','¡Sí... venganza! Lo hiciste bien.$B$BLlévate esto ahora. Fue un regalo de Sedai. Sólo verlo hace triste a Makuru.',18019),
(9543,'esES','¿Puedo ofrecerle alguna ayuda $N? Suenas preocupado.',18019),
(9430,'esES','Eres muy afortunado. Justo como yo esperaba, has encontrado una reliquia muy especial entre tantas otras.',18019),
(9545,'esES','Espero que la visión que has presenciado le haya ayudado a obtener una perspectiva de la muerte de Sedai. La reliquia le mostró una serie probable de eventos que conducen al presente. La verdad puede haber sido distinta, nunca lo sabremos con seguridad.$B$B¿Podrías actuar diferente sabiendo lo que sabes ahora?$B$B¿Quién puede decir que nuestro conflicto con los orcos continuará? Lo que es importante es permanecer abierto ante las posibilidades.',18019),
(9399,'esES','¡Lo lograste! Estoy en deuda contigo. Mira todos los Zarrapucha que se están presentando.$B$BBajo mi dirección aprenderán todo acerca de los viejos caminos, ya verás.',18019),
(9490,'esES','¡Sí, recuerdo estas garras afiladas!$B$BTome esta recompensa $N. La tarea que acabas de hacer fue muy peligrosa. Te mereces cada parte de esta recompensa.',18019),
(10443,'esES','Oh, Dios, tú debes ser la ayuda que pedí del templo de Telhamat.$B$BMe alegro de que estés aquí; hay mucho que hacer, y tengo justo lo que quiero para empezar.',18019),
(9355,'esES','Bien hecho $N. Aunque no deberíamos alegrarnos demasiado rápido. Estoy seguro de que no hemos visto ni el último de esos gusanos. Aún así ¡Sí vuelven a aparecer sus espantosas cabezas alrededor de estas tierras, los hijos estarán listos para matarlos!',18019),
(10079,'esES','Por la barba de Barbabronce... ¡Lo has hecho $N! Eres un héroe.',18019),
(10099,'esES','Me alegra que te la hayas arreglado por cuenta propia...¿cómo dijiste que se llamaba? ¿Z’kral?$B$BDesde tu descripción, suena más como un "eso" que un "él". Pero lo único que me importa es que está muerto.',18019),
(9558,'esES','¿Cómo nos encontraste $C? No importa, imagino que fuiste enviado para darnos una mano. ¡Vamos a trabajar!',18019),
(9417,'esES','¡Gran trabajo $N! Te proclamo un Barbalarga honorario.$B$BQuédate por aquí y tómate un trago con nosotros ¿no?',18019),
(9385,'esES','Bien hecho $N. ¡Eso debería enseñarles a esas bestias quién manda aquí!',18019),
(9563,'esES','¡Sí! Pareces ser bastante agradable $R. Supongo que podría confiar en ti.',18019),
(9420,'esES','Hiciste tu parte. ¡Supongo que un trato es un trato!$B$BAquí tienes amigo. Trátalo bien.',18019),
(9575,'esES','¿Sabías que odio algo peor que el hecho de estar equivocado? Perder oro en una apuesta que no podrías ganar, cariño.$B$B¡Es excepcional! Con estos tres muertos, sus fuerzas deberían estar en caos. ¡Y con su artillería silenciada, tendremos más facilidad de acercarnos lo suficiente y tomar la ciudadela!$B$BTengo la sensación de que hay algo de lo que no nos hemos percatado todavía, aunque con eso basta para tener algo más que hacer por tu parte. Aquí, toma uno de estos de la armería.',18019),
(9607,'esES','¡¿TIENEN UN SEÑOR DEL FOSO?!$B$B<El comandante en jefe fija su mirada en las miradas de los demás y luego baja su voz a un susurro.>$B$BEsto lo ratifica. Deben estar usando la fuerza de este señor del foso para crear nuevos orcos viles que de alguna manera no están alineados con la legión Ardiente. Y si pueden hacer esto con los orcos marrones, también pueden hacerlo con los verdes. Con todos los nuevos orcos de la horda entrando a través del portal oscuro. ¡Eso no es bueno!$B$BDebemos atacar el corazón de su poderío militar ¡Y pronto!',18019),
(11002,'esES','Esta derrota no es solo un golpe para illidan. La legión también se tambalea...Un comandante señor del foso ha sido derrotado. El asedio de la ciudadela de Fuego Infernal ahora no tiene ningún propósito para la legión Ardiente. Todos sus esfuerzos, sin duda, se dirigirán al templo oscuro.$B$BLa redención llegará para Illidan... y pronto.',18019),
(9372,'esES','Bien hecho $N. Estas muestras de sangre resultarán útiles en mi investigación y en los estudios más amplios de la expedición sobre las criaturas de Terrallende.$B$BSi pudiese aislar lo que hace que estas criaturas cambien continuamente, tal vez podría inventar un antídoto.',18019),
(10255,'esES','<El ojo de Thiah Melenarroja se amplía al describir los resultados del experimento.>$B$BPero, ¿cómo pudo pasar? ¡Estoy segura de que preparé el antídoto correctamente!$B$BLo he visto trabajar con venenos de araña y serpiente, así que... ¿Por qué tendría que haber salido mal aquí? Tal vez sea una de las muchas peculiaridades de Terrallende $N. Sería mejor que pasara esta información a mis compañeros.',18019),
(10132,'esES','Buen trabajo.$B$BSí me preguntas, todo lo que debemos hacer es matar bastantes de esos colosales, y así no tendríamos que preocuparnos más por aquella cresta o ese extraño cristal gigante rojo en medio.$B$BTome alguno de estos objetos como un regalo por parte de la expedición cenarion.',18019),
(10159,'esES','Con los devastadores repelidos, los viajeros desde y hacia el Refugio Cenarion en Marisma de Zangar deberían tener un tiempo más fácil de recorrido.$B$BLa Expedición Cenarion está en deuda contigo $N.',18019),
(9912,'esES','Bienvenido al Refugio Cenarion $N. Espero que hayas venido para ayudarnos en nuestra misión. Tenemos mucho trabajo por delante.',18019),
(10134,'esES','Hmph. Sólo parece un gran trozo de cristal sin refinar para mí.$B$BCiertamente, puedo sentir algo enfermizo, un aura malvada emanando desde dentro, aún así esto no estaría en mi línea de trabajo. Estoy aquí para poner fin a la amenaza de los gigantes de la montaña.',18019),
(10349,'esES','¡Excelente! He estado esperando para conseguir un trozo de esa cosa, pero Tola’thion no ha hecho otra cosa más que arrastrar sus pies.$B$BSe supone que él está aquí ayudándome a investigar lo que sea que esté pasando en la cresta cielo estrellado. Pero en vez de eso, sólo se dedica a enviar pobres como tú - sin ofender - directos a la muerte.$B$BSi me das el cristal tal vez pueda encontrar un vínculo entre esa cosa y los colosales.',18019),
(10351,'esES','¿Goliathon? ¿Pathaleon el calculador?$B$B¿¡KAEL’THAS!?$B$B¿El Príncipe Kael’thas tiene que ver en esto?$B$B<La vinculadora terrestre fuma.>$B$B¡Es una locura lo que ha hecho! ¡Arrojar cristales gigantes desde el cielo y diezmar la tierra sólo puede ser obra de un desquiciado!$B$BLe aseguro que la Expedición Cenarion contrarrestará los intentos de sus fuerzas para volver a hacer esta locura.$B$BTenemos una gran deuda contigo $N.',18019),
(10403,'esES','¿Has venido a ayudar a mi tribu $R? Qué inusual. No hay muchos que se preocupan por el destino de los quebrados en esta tierra.',18019),
(10367,'esES','Le agradezco $N. Mi gente será libre gracias a ti.',18019),
(10368,'esES','Puedo sentirlo $N. Los espíritus regresan a nosotros.',18019),
(10369,'esES','Es cierto $N. Fui una vez Naladu, el guardián de la tierra.$B$BFui yo quien traicionó a los otros ancianos Zarrapucha en intercambio por promesas vacías de poder. Ahora puedes despreciarme si deseas. Lo que importa es que mi tribu es libre una vez más y los espíritus han regresado a nosotros.$B$BNo me uniré al resto de la tribu, pero puedo morir en paz ahora. Que el espíritu de la tierra encuentre a un nuevo sirviente entre mis hermanos.',18019),
(10236,'esES','¡Hurra! Encontraste algunas piezas. Ahora tal vez pueda hacer que mi trituradora funcione. Si gano suficiente dinero, podría regresar a bahía del Botín.$B$BEspero que mi primo, screed Sinsuerte, haya estrellado ese estúpido zepelín en tierra. No puedo creer que me haya engañado para que viniese a Terrallende.',18019),
(10238,'esES','Gracias por salvar a mis peones. Ahora tal vez pueda conseguir que arreglen mi trituradora con las piezas que encontraste. Ganar algo de dinero y salir de Terrallende. No puedo esperar para volver a bahía del botín.',18019),
(10629,'esES','Hueles fatal. ¡Pero encontraste mis llaves! Muchas gracias. Ahora puedo hacer que mi trituradora encienda y comience a generar algo de dinero. Muy pronto tendré el dinero suficiente para dejar Terrallende. No sé por qué te quedas aquí, odio este lugar. ¿No preferirías estar de vuelta en Bahía del Botín?$B$B¿Tal vez pescando?',18019),
(10630,'esES','Todos esos Gan’arg están seguros para ser expulsados de la mina.$B$BRegresaré a Bahía dentro de una semana, no puedo esperar para volver a pescar. Venir Terrallende fue un gran error. Sí sigues mi consejo, regresarás como viniste.$B$BQuédate un tiempo en Vega de tuercespina, o tal vez sí te sientes aventurero, diríjase a cráter de Un’Goro. Pero no te quedes aquí.',18019),
(10161,'esES','Algo de esto está en muy mal estado, pero debería haber suficiente para trabajar aquí. ¡Con algo de ingeniería creativa, estoy seguro de que puedo hacer que funcione!',18019),
(9351,'esES','¡Esto es perfecto! De hecho, creo que va a funcionar tan bien que quizás tenga que rediseñar el motor para aprovechar toda esta potencia extra. Sí, quiero decir, cuando salgamos de aquí, ¡tendré que mostrar mi diseño a todos en el Área 52!',18019),
(9349,'esES','Para tener una buena cocina, es necesario tener buenos ingredientes. ¡Y estos huevos se ven geniales!$B$BAcabo de terminar de limpiar mi sartén, ¡así que eres más que bienvenido para acompañarme a comer!',18019),
(9361,'esES','Mmmm...$B$BEsto parece comestible, sí se condimenta adecuadamente. No le digas a Screed de dónde vino su desayuno, ¿de acuerdo?',18019),
(9356,'esES','Huevos de devastador. ¡Bam!$B$BTocino de jabinferno. ¡Bam!$B$B¡Alas de buitre, Bam! ¡Bam!$B$BQué gran comida. Realmente tienes que intentarlo.',18019);


DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN (10119, 10288, 10140, 10254, 10047, 9492, 10058, 9493, 13408, 9494, 10160, 10482, 10483, 10484, 10485, 10903, 10916, 10909, 10935, 10936, 10937, 10919, 10055, 10078, 10050, 10057, 10141, 10142, 10895, 10143, 10144, 10146, 10340, 10344, 10163, 10346, 10382, 10394, 10396, 10397, 10093, 9398, 9383, 9426, 9427, 9390, 9423, 9424, 9543, 9430, 9545, 9399, 9490, 10443, 9355, 10079, 10099, 9558, 9417, 9385, 9563, 9420, 9575, 9607, 11002, 9372, 10255, 10132, 10159, 9912, 10134, 10349, 10351, 10403, 10367, 10368, 10369, 10236, 10238, 10629, 10630, 10161, 9351, 9349, 9361, 9356) AND `locale` IN ('esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10119,'esMX','Bienvenido a terrallende $N, bienvenido a la pesadilla! Aunque la fuerza expedicionaria inicial salió ilesa, la legión está tratando de retomar el portal oscuro y evitar que lleguen más de nuestros refuerzos.$B$BPor mucho que me gustaría su ayuda aquí, nuestras tropas y los soldados de la horda son capaces de defenderse de los pelotones de la legión que intentan tomar el control de esta plataforma.$B$BTe necesitamos donde tu talento pueda ser mejor utilizado',18019),
(10288,'esMX','¿Reportar al bastión de honor? ¡No hay problema! Llegarás rápido y seguro montándote en uno de mis grifos.',18019),
(10140,'esMX','Nuestra expedición a este mundo abandonado casi se ha detenido $N, encontramos más resistencia de la que esperábamos.$B$BComo si enfrentarnos a la legión ardiente de nuevo no fuera suficiente.$B$BHay horrores en esta tierra que no se parecen a nada de lo que hemos encontrado...',18019),
(10254,'esMX','Bien dicho hermano mío, me alegro de que hayas venido. Soy Danath, líder de los hijos de Lothar y comandante de la fuerza de este bastión.',18019),
(10047,'esMX','Tiene mis más sinceros agradecimientos $N. Pensé que quedaba mucho por hacer, pero me alegra saber que hemos ayudado a algunos a encontrar su merecido descanso.',18019),
(9492,'esMX','Bien hecho $N. Con su victoria en la ciudadela de fuego infernal, hemos dado un duro golpe contra los orcos.$B$BDebo hablar con el comandante Romus acerca del este seguimiento y asegurar de que los orcos permanezcan a la defensiva. Ahora que hemos sido reforzados podemos hacer mucho más que simplemente defender el bastión de honor.',18019),
(10058,'esMX','¿Es realmente eso? Es difícil creer que sobrevivió a la batalla. Las condiciones en ruinas no han sido amables con mi libro, pero aún así, me alegra tenerlo de vuelta.$B$BEs la única cosa que tengo de turalyon.$B$B<El padre Devidicus parece estar evitando llorar>$B$BCuando luchas al lado de alguien durante tantos años, se convierte en algo más cercano que inclusive una familia.',18019),
(9493,'esMX','Eso es una excelente noticia $N. Con el progreso de hacernos notar desde la ciudadela de fuego infernal, tal vez podamos permitirnos llamar la atención de nuestra presencia a la horda vil desde otras partes de península y Terrallende.',18019),
(13408,'esMX','Bien hecho, $N. Sus acciones en el campo son instrumentales en nuestra batalla por la península de Fuego Infernal.',18019),
(9494,'esMX','¡Bien hecho! No puedo esperar para replicar las hazañas del Brujo Supremo Malbisal, no debo aspirar a ser él, pero seríamos muy tontos ignorando el poder de las ascuas viles.$B$BSin embargo, hay quienes prohibirían este tipo de investigaciones, aún así estoy a punto de embarcarme y por esa razón debo mantener mis esfuerzos en secreto. Por favor, no mencione de esto a nadie $N.',18019),
(10160,'esMX','<La teniente Amadi acentúa con la cabeza>$B$BBien, necesitamos toda la ayuda que podamos reunir. El aumento de la presencia de orcos viles alrededor de la muralla sur me preocupa. Envié un explorador para investigar, pero aún no ha regresado.',18019),
(10482,'esMX','Muy bueno. Estoy segura de que esta pérdida se sintió en la ciudadela de fuego infernal. Aunque ese bastión oscuro se cierna contra nosotros y parece casi insuperable, es sólo con movimientos audaces como usted ha hecho que vamos a encontrar la victoria sobre los orcos viles!',18019),
(10483,'esMX','¿Recuperó una insignia de los orcos Foso sangrante? De acuerdo, es escandaloso que usen nuestros propios símbolos en contra ¡Y se burlen de nuestros compañeros caídos a manos de esas bestias pieles rojas!',18019),
(10484,'esMX','Gracias $N. Mi corazón se entristece al ver estos talismanes. Subrayan las grandes pérdidas que el bastión de honor ha sufrido contra los orcos viles. Pero estoy alentado de verte exitoso en contra ellos. Si tan sólo matáramos lo suficiente, probablemente podríamos salir de esta guerra victoriosos.',18019),
(10485,'esMX','¡Lo has hecho! ¡Morkh ha sido asesinado! ¡Ahora tenemos una oportunidad de pelear en contra de aquellas bestias viles!$B$BGracias $N. Su ayuda en la guerra de este lugar está más allá de lo común.',18019),
(10903,'esMX','Sí, es cierto. La situación del coronel Jules ha decrecido estos últimos días. El anacoreta Barada está ocupado orando por él... esperemos que pueda recuperarse.',18019),
(10916,'esMX','¡Encontraste los abalorios de oración! Bien hecho $N. Eres una maravilla, matas en un momento a los horrores de península del fuego infernal y luego encuentras tesoros perdidos. ¡Tu gente realmente inspira!$B$BEs bueno que haya recuperado estos abalorios... porque serán invaluables en el ritual del exorcismo que vendrá..',18019),
(10909,'esMX','Los orcos mano destrozada son más asquerosos de lo que esperaba. Mi corazón se entristece al saber que el camino de la salvación para el coronel Jules tiene tal derramamiento de sangre',18019),
(10935,'esMX','Lo has hecho $N. Usted ha salvado el alma del coronel Jules y ha expulsado a la oscuridad dentro de él de vuelta dónde vino. ¡Es una gran noble obra! ¡Un día de heroe!',18019),
(10936,'esMX','¡Ya era hora! Escuché todo lo que hacías con ese sacerdote draenei. ¡Has enloquecido a mi mensajero!$B$BAhora que ya has terminado con eso, tengo una pequeña misión planeada para ti en la ciudadela de fuego infernal.',18019),
(10937,'esMX','No iba a creerlo hasta que lo oí de ti personalmente. Ya nuestros exploradores están goteando la información de que la mano destrozada está en caos sin su precioso maestro de maniobras para decirles qué hacer.$B$BHa viajado por un largo camino $N. Confío en que aceptará esta armadura junto con mis agradecimientos. ¡Pórtelo con orgullo, se lo ha ganado!',18019),
(10919,'esMX','<Fei Fei ladra felizmente y agarra la chuchería para perros. Mira a la izquierda y a la derecha... decidiendo dónde debe esconder este nuevo tesoro...>',18019),
(10055,'esMX','Esto está en mejores condiciones de lo que pensé. Seguro va a tomar tiempo limpiar todo el óxido, carbón y polvo, pero sinceramente no voy a quejarme.',18019),
(10078,'esMX','¡Ese es el espíritu!$B$BMe alegro de que finalmente consiguiéramos reunir algunos refuerzos, pero no estoy tan seguro de su actitud hacia la horda. De donde vengo, cualquiera con un arma apuntando hacia usted es un enemigo y necesita ser tratado como uno!',18019),
(10050,'esMX','Los hijos de lothar aprecian sus esfuerzos, inclusive si pocos están dispuestos a hablar de la armería.',18019),
(10057,'esMX','Sólo podemos esperar que con el silencio de los fantasmas de los oficiales, los espíritus de los soldados puedan encaminarse también hacia su destino. Gracias una vez más por su ayuda $N',18019),
(10141,'esMX','El comandante de la Fuerza Danath pudo haber malentendido mi solicitud de refuerzos. Pareces capaz, pero ¡he pedido un batallón de tamaño completo!$B$BVerás, tenemos un poco de problemas de demonios por aquí...',18019),
(10142,'esMX','Excelente trabajo soldado. La frecuencia de los ataques está segura de disminuir, al menos hasta que traigan nuevos señores del terror.$B$BAhora las malas noticias: Tengo nuevas órdenes para usted...',18019),
(10895,'esMX','¡Podía ver el humo y las llamas desde aquí! ¡Buen trabajo $N! Recibiste unas cuantas palabras de alabanza por parte de nuestros pilotos de grifos, lo que acabas de hacer es de tener agallas...',18019),
(10143,'esMX','Encantado de conocerle soldado.$B$BAhora basta de cháchara y escuche. Tengo una misión vital para ti y quiero que tengas éxito... y por supuesto sobreviva!',18019),
(10144,'esMX','Bien hecho $N. ¡Desactivar esos portales frenará el flujo de refuerzos de la legión durante mucho tiempo!$B$BPero aún así no podemos descansar todavía...',18019),
(10146,'esMX','¡Eso los retrasará, no lo negaré! Creo que me pusiste de un humor no característico $N.',18019),
(10340,'esMX','Ja ja! ¡Un $R fresco de la tierra firme! Bueno, no te preocupes. El puesto devastación podría marearte un poco. ¡Pero ella casi no se desvía mucho!$B$BY sólo la he visto volar una vez... o dos veces.',18019),
(10344,'esMX','¿Hablaste con Runetog? Es un buen enano. Mantiene sus grifos en buena forma y listos para la batalla.$B$BSoy Grifongar, comandante del puesto devastación. Sé que no es bonito, pero este trozo de roca es un punto vital para la batalla de Fuego Infernal. ¡Verás grifos volando y sin parar!$B$BConsejo? Aquí hay uno: Mantenga su equipo puesto, el estómago vacío, y su ojo fijado en el horizonte ... sí puesto devastación comienza a ser atacado, ¡Entonces agarre algo que flote lejos!',18019),
(10163,'esMX','Vuelas como si estuvieses estado haciendo esto toda su vida $N. ¡Excelente actuación allí fuera! ¡Ni siquiera un rasguño en los grifos destructores!',18019),
(10346,'esMX','¿Cómo te ha ido esta vez? Estás en muy buena forma... ¡quizás lo suficiente para viajar una vez más!',18019),
(10382,'esMX','Bienvenido $C. ¡Me alegro finalmente de que la vieja enana nos haya visto aptos de enviarnos alguna ayuda!',18019),
(10394,'esMX','Bueno, debo decir que estoy impresionado $N. No pensé que tuvieses el temple para esta misión. ¡Bien hecho. bien hecho! En efecto.',18019),
(10396,'esMX','Tengo que dárselo a usted $N. ¡Eres un luchador nacido! Esos soldados de la horda tal vez nunca sepan lo cerca que estuvieron de morir. Se necesita un carácter real para que alguien se haga daño en nombre de sus enemigos. ¡Ese es el tipo de honor y compromiso que mantiene unida a la Alianza!$B$B<El mariscal de campo Brock te saluda curruscante>',18019),
(10397,'esMX','¡Buen trabajo! Eso debería reducir drásticamente el número de demonios que intentan arrastrarse por nuestro lado trasero. No podría agradecerle por tanta ayuda aquí $N.',18019),
(10093,'esMX','Ah, así que conociste al vidente Kryv. Él es un hombre sabio y talentoso y cualquier $R al que llamase amigo, también será mi amigo.$B$BPonte cómodo y preséntate ante otros que llaman a este templo hogar.',18019),
(9398,'esMX','Has hecho bien $N. Siempre es lamentable tener que recurrir a la toma de una vida, incluso cuando es la de una bestia peligrosa como la guadaña de piedra.$B$BTienes mis agradecimientos por llevar a cabo esta tarea sombría.',18019),
(9383,'esMX','Lo has hecho bien. Parece que el cristal de contención se está sosteniendo por ahora, pero saber cuanto tiempo durará así, sigue siendo un misterio. Lo vigilaremos y prepararemos más cristales mientras tanto.',18019),
(9426,'esMX','Sí, siento la presencia vil en las pozas debilitándose.$B$BHas hecho bien $N.',18019),
(9427,'esMX','La esencia de Aggonar vivió en su corrupto descendiente, Aggonis. Con su éxito en derrotar al demonio, podemos empezar a trabajar para restaurar las pozas hacia su pureza original.$B$BTienes nuestros agradecimientos $N. Su trabajo tendrá un profundo impacto en este mundo.',18019),
(9390,'esMX','Has encontrado el cuerpo de un joven paladín draenei. Parece haber sido asesinado por un golpe en la espalda.',18019),
(9423,'esMX','Sedai, querido hermano...$B$B¡Esos orcos cobardes! Estaba desarmado, ¿cómo podrían?$B$BDéjeme estar $N. Le agradezco la ayuda, pero necesito estar a solas con mis pensamientos por ahora.',18019),
(9424,'esMX','¡Sí... venganza! Lo hiciste bien.$B$BLlévate esto ahora. Fue un regalo de Sedai. Sólo verlo hace triste a Makuru.',18019),
(9543,'esMX','¿Puedo ofrecerle alguna ayuda $N? Suenas preocupado.',18019),
(9430,'esMX','Eres muy afortunado. Justo como yo esperaba, has encontrado una reliquia muy especial entre tantas otras.',18019),
(9545,'esMX','Espero que la visión que has presenciado le haya ayudado a obtener una perspectiva de la muerte de Sedai. La reliquia le mostró una serie probable de eventos que conducen al presente. La verdad puede haber sido distinta, nunca lo sabremos con seguridad.$B$B¿Podrías actuar diferente sabiendo lo que sabes ahora?$B$B¿Quién puede decir que nuestro conflicto con los orcos continuará? Lo que es importante es permanecer abierto ante las posibilidades.',18019),
(9399,'esMX','¡Lo lograste! Estoy en deuda contigo. Mira todos los Zarrapucha que se están presentando.$B$BBajo mi dirección aprenderán todo acerca de los viejos caminos, ya verás.',18019),
(9490,'esMX','¡Sí, recuerdo estas garras afiladas!$B$BTome esta recompensa $N. La tarea que acabas de hacer fue muy peligrosa. Te mereces cada parte de esta recompensa.',18019),
(10443,'esMX','Oh, Dios, tú debes ser la ayuda que pedí del templo de Telhamat.$B$BMe alegro de que estés aquí; hay mucho que hacer, y tengo justo lo que quiero para empezar.',18019),
(9355,'esMX','Bien hecho $N. Aunque no deberíamos alegrarnos demasiado rápido. Estoy seguro de que no hemos visto ni el último de esos gusanos. Aún así ¡Sí vuelven a aparecer sus espantosas cabezas alrededor de estas tierras, los hijos estarán listos para matarlos!',18019),
(10079,'esMX','Por la barba de Barbabronce... ¡Lo has hecho $N! Eres un héroe.',18019),
(10099,'esMX','Me alegra que te la hayas arreglado por cuenta propia...¿cómo dijiste que se llamaba? ¿Z’kral?$B$BDesde tu descripción, suena más como un "eso" que un "él". Pero lo único que me importa es que está muerto.',18019),
(9558,'esMX','¿Cómo nos encontraste $C? No importa, imagino que fuiste enviado para darnos una mano. ¡Vamos a trabajar!',18019),
(9417,'esMX','¡Gran trabajo $N! Te proclamo un Barbalarga honorario.$B$BQuédate por aquí y tómate un trago con nosotros ¿no?',18019),
(9385,'esMX','Bien hecho $N. ¡Eso debería enseñarles a esas bestias quién manda aquí!',18019),
(9563,'esMX','¡Sí! Pareces ser bastante agradable $R. Supongo que podría confiar en ti.',18019),
(9420,'esMX','Hiciste tu parte. ¡Supongo que un trato es un trato!$B$BAquí tienes amigo. Trátalo bien.',18019),
(9575,'esMX','¿Sabías que odio algo peor que el hecho de estar equivocado? Perder oro en una apuesta que no podrías ganar, cariño.$B$B¡Es excepcional! Con estos tres muertos, sus fuerzas deberían estar en caos. ¡Y con su artillería silenciada, tendremos más facilidad de acercarnos lo suficiente y tomar la ciudadela!$B$BTengo la sensación de que hay algo de lo que no nos hemos percatado todavía, aunque con eso basta para tener algo más que hacer por tu parte. Aquí, toma uno de estos de la armería.',18019),
(9607,'esMX','¡¿TIENEN UN SEÑOR DEL FOSO?!$B$B<El comandante en jefe fija su mirada en las miradas de los demás y luego baja su voz a un susurro.>$B$BEsto lo ratifica. Deben estar usando la fuerza de este señor del foso para crear nuevos orcos viles que de alguna manera no están alineados con la legión Ardiente. Y si pueden hacer esto con los orcos marrones, también pueden hacerlo con los verdes. Con todos los nuevos orcos de la horda entrando a través del portal oscuro. ¡Eso no es bueno!$B$BDebemos atacar el corazón de su poderío militar ¡Y pronto!',18019),
(11002,'esMX','Esta derrota no es solo un golpe para illidan. La legión también se tambalea...Un comandante señor del foso ha sido derrotado. El asedio de la ciudadela de Fuego Infernal ahora no tiene ningún propósito para la legión Ardiente. Todos sus esfuerzos, sin duda, se dirigirán al templo oscuro.$B$BLa redención llegará para Illidan... y pronto.',18019),
(9372,'esMX','Bien hecho $N. Estas muestras de sangre resultarán útiles en mi investigación y en los estudios más amplios de la expedición sobre las criaturas de Terrallende.$B$BSi pudiese aislar lo que hace que estas criaturas cambien continuamente, tal vez podría inventar un antídoto.',18019),
(10255,'esMX','<El ojo de Thiah Melenarroja se amplía al describir los resultados del experimento.>$B$BPero, ¿cómo pudo pasar? ¡Estoy segura de que preparé el antídoto correctamente!$B$BLo he visto trabajar con venenos de araña y serpiente, así que... ¿Por qué tendría que haber salido mal aquí? Tal vez sea una de las muchas peculiaridades de Terrallende $N. Sería mejor que pasara esta información a mis compañeros.',18019),
(10132,'esMX','Buen trabajo.$B$BSí me preguntas, todo lo que debemos hacer es matar bastantes de esos colosales, y así no tendríamos que preocuparnos más por aquella cresta o ese extraño cristal gigante rojo en medio.$B$BTome alguno de estos objetos como un regalo por parte de la expedición cenarion.',18019),
(10159,'esMX','Con los devastadores repelidos, los viajeros desde y hacia el Refugio Cenarion en Marisma de Zangar deberían tener un tiempo más fácil de recorrido.$B$BLa Expedición Cenarion está en deuda contigo $N.',18019),
(9912,'esMX','Bienvenido al Refugio Cenarion $N. Espero que hayas venido para ayudarnos en nuestra misión. Tenemos mucho trabajo por delante.',18019),
(10134,'esMX','Hmph. Sólo parece un gran trozo de cristal sin refinar para mí.$B$BCiertamente, puedo sentir algo enfermizo, un aura malvada emanando desde dentro, aún así esto no estaría en mi línea de trabajo. Estoy aquí para poner fin a la amenaza de los gigantes de la montaña.',18019),
(10349,'esMX','¡Excelente! He estado esperando para conseguir un trozo de esa cosa, pero Tola’thion no ha hecho otra cosa más que arrastrar sus pies.$B$BSe supone que él está aquí ayudándome a investigar lo que sea que esté pasando en la cresta cielo estrellado. Pero en vez de eso, sólo se dedica a enviar pobres como tú - sin ofender - directos a la muerte.$B$BSi me das el cristal tal vez pueda encontrar un vínculo entre esa cosa y los colosales.',18019),
(10351,'esMX','¿Goliathon? ¿Pathaleon el calculador?$B$B¿¡KAEL’THAS!?$B$B¿El Príncipe Kael’thas tiene que ver en esto?$B$B<La vinculadora terrestre fuma.>$B$B¡Es una locura lo que ha hecho! ¡Arrojar cristales gigantes desde el cielo y diezmar la tierra sólo puede ser obra de un desquiciado!$B$BLe aseguro que la Expedición Cenarion contrarrestará los intentos de sus fuerzas para volver a hacer esta locura.$B$BTenemos una gran deuda contigo $N.',18019),
(10403,'esMX','¿Has venido a ayudar a mi tribu $R? Qué inusual. No hay muchos que se preocupan por el destino de los quebrados en esta tierra.',18019),
(10367,'esMX','Le agradezco $N. Mi gente será libre gracias a ti.',18019),
(10368,'esMX','Puedo sentirlo $N. Los espíritus regresan a nosotros.',18019),
(10369,'esMX','Es cierto $N. Fui una vez Naladu, el guardián de la tierra.$B$BFui yo quien traicionó a los otros ancianos Zarrapucha en intercambio por promesas vacías de poder. Ahora puedes despreciarme si deseas. Lo que importa es que mi tribu es libre una vez más y los espíritus han regresado a nosotros.$B$BNo me uniré al resto de la tribu, pero puedo morir en paz ahora. Que el espíritu de la tierra encuentre a un nuevo sirviente entre mis hermanos.',18019),
(10236,'esMX','¡Hurra! Encontraste algunas piezas. Ahora tal vez pueda hacer que mi trituradora funcione. Si gano suficiente dinero, podría regresar a bahía del Botín.$B$BEspero que mi primo, screed Sinsuerte, haya estrellado ese estúpido zepelín en tierra. No puedo creer que me haya engañado para que viniese a Terrallende.',18019),
(10238,'esMX','Gracias por salvar a mis peones. Ahora tal vez pueda conseguir que arreglen mi trituradora con las piezas que encontraste. Ganar algo de dinero y salir de Terrallende. No puedo esperar para volver a bahía del botín.',18019),
(10629,'esMX','Hueles fatal. ¡Pero encontraste mis llaves! Muchas gracias. Ahora puedo hacer que mi trituradora encienda y comience a generar algo de dinero. Muy pronto tendré el dinero suficiente para dejar Terrallende. No sé por qué te quedas aquí, odio este lugar. ¿No preferirías estar de vuelta en Bahía del Botín?$B$B¿Tal vez pescando?',18019),
(10630,'esMX','Todos esos Gan’arg están seguros para ser expulsados de la mina.$B$BRegresaré a Bahía dentro de una semana, no puedo esperar para volver a pescar. Venir Terrallende fue un gran error. Sí sigues mi consejo, regresarás como viniste.$B$BQuédate un tiempo en Vega de tuercespina, o tal vez sí te sientes aventurero, diríjase a cráter de Un’Goro. Pero no te quedes aquí.',18019),
(10161,'esMX','Algo de esto está en muy mal estado, pero debería haber suficiente para trabajar aquí. ¡Con algo de ingeniería creativa, estoy seguro de que puedo hacer que funcione!',18019),
(9351,'esMX','¡Esto es perfecto! De hecho, creo que va a funcionar tan bien que quizás tenga que rediseñar el motor para aprovechar toda esta potencia extra. Sí, quiero decir, cuando salgamos de aquí, ¡tendré que mostrar mi diseño a todos en el Área 52!',18019),
(9349,'esMX','Para tener una buena cocina, es necesario tener buenos ingredientes. ¡Y estos huevos se ven geniales!$B$BAcabo de terminar de limpiar mi sartén, ¡así que eres más que bienvenido para acompañarme a comer!',18019),
(9361,'esMX','Mmmm...$B$BEsto parece comestible, sí se condimenta adecuadamente. No le digas a Screed de dónde vino su desayuno, ¿de acuerdo?',18019),
(9356,'esMX','Huevos de devastador. ¡Bam!$B$BTocino de jabinferno. ¡Bam!$B$B¡Alas de buitre, Bam! ¡Bam!$B$BQué gran comida. Realmente tienes que intentarlo.',18019);


DELETE FROM `quest_request_items_locale` WHERE `ID` IN (10288, 10140, 10047, 9492, 10058, 9493, 13408, 9494, 10482, 10483, 10484, 10485, 10916, 10909, 10935, 10937, 10919, 10055, 10078, 10050, 10057, 10142, 10895, 10144, 10146, 10163, 10346, 10394, 10396, 10397, 9398, 9383, 9426 ,9427, 9424, 9430, 9545, 9399, 9490, 9355, 10079, 10099, 9417, 9385, 9563, 9420, 9575, 9607, 11002, 9372, 10255, 10132, 10159, 10134, 10349, 10351, 10367, 10368, 10369, 10236, 10238, 10629, 10630, 10161, 9351, 9349, 9361, 9356) AND `locale` IN ('esES');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10288,'esES','Vi que hablaste con Duron antes de llegar hasta aquí. ¡Debes de estar en una importante misión!',18019),
(10140,'esES','Gracias a la luz por llegar sano y salvo. El bastión de honor necesita todos los guerreros que se puedan reunir.',18019),
(10047,'esES','Los gritos aparecen de alguna manera... mucho más débiles de lo que eran antes. La concesión de luz es más que un pensamiento deseoso.',18019),
(9492,'esES','¿Has regresado con la prueba de que el "Jefe de Guerra" Kargath Garrafilada ha muerto?',18019),
(10058,'esES','Creí haberte pedido que no me hablaras. ¿Qué es eso?',18019),
(9493,'esES','No soy tan ingenuo como para pensar que la derrota de los legionarios mano destrozada anuncian nuestra victoria sobre el horda vil, aunque ese sería un buen comienzo.',18019),
(13408,'esES','$N, regresa a mí cuando hayas capturado cada uno de los fuertes!',18019),
(9494,'esES','¿Me trajiste las ascuas viles?',18019),
(10482,'esES','Los orcos mascahuesos aparecen en grandes cantidades $N. ¡Debes matarlos o los orcos viles podrían invadirnos!',18019),
(10483,'esES','¿Reportando del Bastión de Honor $N? Eso es bueno, nuestra campaña contra los demonios y los orcos viles se está quedando sin cuerpos capaces!',18019),
(10484,'esES','¿Tiene los talismanes $N? Me duele saber que esos orcos malditos poseen las insignias de nuestros soldados caídos...',18019),
(10485,'esES','¿Tienes la armadura destrozada de Morkh? ¿Has desafiado a Zeth’gor una vez más?',18019),
(10916,'esES','¿Has encontrado los abalorios de oración $N? Sus Poderes son cruciales para muchos ritos sagrados... incluído el exorcismo.',18019),
(10909,'esES','Los espíritus viles de los orcos mano destrozada son una plaga dentro de la pobre alma de Jules. Dime $N.. han sido apaciguados?',18019),
(10935,'esES','Dirígete dónde el anacoreta Barada $N. Debe tener éxito con su ritual para que el coronel pueda ser salvado.',18019),
(10937,'esES','¿El maestro de maniobras está muerto? ¿Quizá mis exploradores estén equivocados?',18019),
(10919,'esES','Fe Fei te mira expectante...',18019),
(10055,'esES','¿fuiste capaz de encontrar algún material útil por ahí debajo de todo ese polvo, cenizas y carbón?',18019),
(10078,'esES','Pareces estar de buen humor. ¿Ha quemado la maquinaria de asedio de la horda poniendo la antorcha detrás de su paso?',18019),
(10050,'esES','Lo que yo te he pedido que hagas es algo impensable y a la vez horroroso. Pero debes entender que muchos de mis hombres no se acercarán a esas ruinas. Los recuerdos y el dolor son demasiado frescos, pero a pesar de ello no podemos permitir que los espíritus sigan vagando.$B$BCuanto más tiempo persistan, más débiles serán sus vínculos con su vida anterior y cederán fácilmente a la malevolencia.',18019),
(10057,'esES','¿Ha vencido a los oficiales en las ruinas?',18019),
(10142,'esES','El Bastión de honor está a salvo mientras los arqueros sigan custodiando nuestros cielos.',18019),
(10895,'esES','El tiempo es crucial $N. ¡Necesitamos esas torres quemadas!',18019),
(10144,'esES','Ojalá pudiera estar ahí para ver el fuego. ¡Estos explosivos son un gran golpe!',18019),
(10146,'esES','Esta es una misión vital $N. Es una de las que no confiaría a casi nadie.',18019),
(10163,'esES','¡Muéstrales que ni siquiera los cielos son seguros!',18019),
(10346,'esES','Todavía hay bastantes objetivos en la plataforma abisal $N. Agarra un grifo cuando estés listo.',18019),
(10394,'esES','No me hables de tus pies fríos $C. Sí terminan la construcción en ese campamento de forja ¡Tendrás más preocupaciones además de aquellos sirvientes! ¡Ve de una vez!',18019),
(10396,'esES','¡La legión podría comenzar a bombardear a la horda en cualquier momento $N! ¡Necesitas destruir esos cañones!',18019),
(10397,'esES','¡Cierra ese portal de la legión $N! Mientras estás aquí arrastrando los pies, ¡Hay más demonios entrando en Terrallende!',18019),
(9398,'esES','Bienvenido de nuevo $N. ¿Has completado la tarea que te pedí?',18019),
(9383,'esES','¿Has usado la magia del cristal contra un abisario sin control herido?',18019),
(9426,'esES','¿Has completado tu tarea $N?',18019),
(9427,'esES','Veo que regresas $N. ¿Has limpiado las Aguas?',18019),
(9424,'esES','¿Has vengado a Sedai por makuru?',18019),
(9430,'esES','¿Recuperaste las reliquias de Sha’naar $N?',18019),
(9545,'esES','¿Has visto la visión $N?',18019),
(9399,'esES','¡Has regresado! ¿Completaste tu tarea?',18019),
(9490,'esES','¿Trajiste pruebas de la muerte de Garfanegra $N?',18019),
(9355,'esES','¿Pudiste limpiar el camino?',18019),
(10079,'esES','Háblame cuando el problema haya terminado, para que así mis muchachos puedan volver al trabajo... ¿Podrías?',18019),
(10099,'esES','Casi me da miedo preguntar. Verte salir de aquella mina vivo significa una de dos cosas: o mataste al bastardo, o perdiste tu valor. Bien, ¿Cuál de las dos es la corecta?',18019),
(9417,'esES','¡Volviste! ¿Cómo te fue?',18019),
(9385,'esES','¿Has hecho algún progreso contra los devastadores?',18019),
(9563,'esES','¿Tienes problemas para encontrar la jarra, verdad? El viejo Bernie en el castillo de Nethergarde podría almacenar los barriles allí mismo.$B$BA menos de que se hayan agotado... ¡Eso sería desastroso!',18019),
(9420,'esES','¿Me trajiste las plumas de Kaliri $C?',18019),
(9575,'esES','$N. ¿Verdad? Mechad me dijo que esperara tu informe.$B$B¿QUÉ estás haciendo en mi presencia?! ¿Está completa tu asignación? ¿Es usted un completo y absoluto deficiente intelectual? ¡Me haces querer vomitar!$B$B¡Ahora escóndete sin ningún valor detrás de esas murallas y haz lo que se te ordenó hacer. ¿Me oyes?',18019),
(9607,'esES','¡Soldado, informe! ¿Has explorado todo el horno de sangre?',18019),
(11002,'esES','Por primera vez desde que tengo memoria hay silencio.',18019),
(9372,'esES','¿Pudiste recoger las muestras de sangre?',18019),
(10255,'esES','¿Tienes los resultados del experimento?',18019),
(10132,'esES','¿Has eliminado la amenaza colosal?',18019),
(10159,'esES','¿Te está costando despejar la colina colmillespinado?',18019),
(10134,'esES','Eso que tienes ahí es un gran cristal. ¿Lo obtuviste mientras estabas en la cresta matando colosos?$B$BDéjame echar un vistazo.',18019),
(10349,'esES','¿Esa es una pieza del fragmento de cristal gigante de la cresta cielo estrellado?',18019),
(10351,'esES','¿Ha funcionado? ¿Qué aprendiste? ¿Has averiguado quién o qué está detrás de lo que pasó en la cresta cielo estrellado?',18019),
(10367,'esES','¿Conseguiste la llave $N?',18019),
(10368,'esES','Cuéntame $N. ¿Los ancianos Zarrapucha han sido liberados?',18019),
(10369,'esES','¿Lo has hecho $N? ¿Arzeth está muerto?',18019),
(10236,'esES','¿Encontraste algunas piezas de repuesto para mi trituradora? Realmente quiero arreglarla para poder volver a la minería. Tengo que ganarme la vida de alguna forma. Sólo así puedo comprarme un billete de vuelta a Bahía del Botín.',18019),
(10238,'esES','¿Ya has salvado a mis peones? Por favor, apresúrate. Me temo que van a ser devorados y probablemente no sepan muy bien. Si saben realmente mal, los orcos viles se enfadarán conmigo.',18019),
(10629,'esES','¿Conseguiste encontrar mis llaves? Estoy seguro de que uno de mis canes las tiene. Probablemente sea aquél que te envié. Probablemente.',18019),
(10630,'esES','¿Ya está muerto? Estoy demasiado asustado para ver.',18019),
(10161,'esES','¿Encontraste suficientes piezas? Si no es así, podría tener que usar esa sartén que Legassi sigue agitando. Entonces, tendría que cambiar el nombre del zepelín a "sartén voladora"',18019),
(9351,'esES','¿Fuiste capaz de obtener las esencias?',18019),
(9349,'esES','¿Ya tienes esos huevos?$B$B<El estómago de Legassi gruñe de anticipación>',18019),
(9361,'esES','¿Tuviste éxito en la purificación de la carne de jabinferno?',18019),
(9356,'esES','No puedo esperar para ver la expresión de su rostro cuando lo pruebe. Desde el accidente, se ha estado quejando de que todo en lo que yo puedo pensar es en comida. Bueno, ¡alguien tiene que darnos de comer mientras repara el zepelín!','18019');


DELETE FROM `quest_request_items_locale` WHERE `ID` IN (10288, 10140, 10047, 9492, 10058, 9493, 13408, 9494, 10482, 10483, 10484, 10485, 10916, 10909, 10935, 10937, 10919, 10055, 10078, 10050, 10057, 10142, 10895, 10144, 10146, 10163, 10346, 10394, 10396, 10397, 9398, 9383, 9426 ,9427, 9424, 9430, 9545, 9399, 9490, 9355, 10079, 10099, 9417, 9385, 9563, 9420, 9575, 9607, 11002, 9372, 10255, 10132, 10159, 10134, 10349, 10351, 10367, 10368, 10369, 10236, 10238, 10629, 10630, 10161, 9351, 9349, 9361, 9356) AND `locale` IN ('esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10288,'esMX','Vi que hablaste con Duron antes de llegar hasta aquí. ¡Debes de estar en una importante misión!',18019),
(10140,'esMX','Gracias a la luz por llegar sano y salvo. El bastión de honor necesita todos los guerreros que se puedan reunir.',18019),
(10047,'esMX','Los gritos aparecen de alguna manera... mucho más débiles de lo que eran antes. La concesión de luz es más que un pensamiento deseoso.',18019),
(9492,'esMX','¿Has regresado con la prueba de que el "Jefe de Guerra" Kargath Garrafilada ha muerto?',18019),
(10058,'esMX','Creí haberte pedido que no me hablaras. ¿Qué es eso?',18019),
(9493,'esMX','No soy tan ingenuo como para pensar que la derrota de los legionarios mano destrozada anuncian nuestra victoria sobre el horda vil, aunque ese sería un buen comienzo.',18019),
(13408,'esMX','$N, regresa a mí cuando hayas capturado cada uno de los fuertes!',18019),
(9494,'esMX','¿Me trajiste las ascuas viles?',18019),
(10482,'esMX','Los orcos mascahuesos aparecen en grandes cantidades $N. ¡Debes matarlos o los orcos viles podrían invadirnos!',18019),
(10483,'esMX','¿Reportando del Bastión de Honor $N? Eso es bueno, nuestra campaña contra los demonios y los orcos viles se está quedando sin cuerpos capaces!',18019),
(10484,'esMX','¿Tiene los talismanes $N? Me duele saber que esos orcos malditos poseen las insignias de nuestros soldados caídos...',18019),
(10485,'esMX','¿Tienes la armadura destrozada de Morkh? ¿Has desafiado a Zeth’gor una vez más?',18019),
(10916,'esMX','¿Has encontrado los abalorios de oración $N? Sus Poderes son cruciales para muchos ritos sagrados... incluído el exorcismo.',18019),
(10909,'esMX','Los espíritus viles de los orcos mano destrozada son una plaga dentro de la pobre alma de Jules. Dime $N.. han sido apaciguados?',18019),
(10935,'esMX','Dirígete dónde el anacoreta Barada $N. Debe tener éxito con su ritual para que el coronel pueda ser salvado.',18019),
(10937,'esMX','¿El maestro de maniobras está muerto? ¿Quizá mis exploradores estén equivocados?',18019),
(10919,'esMX','Fe Fei te mira expectante...',18019),
(10055,'esMX','¿fuiste capaz de encontrar algún material útil por ahí debajo de todo ese polvo, cenizas y carbón?',18019),
(10078,'esMX','Pareces estar de buen humor. ¿Ha quemado la maquinaria de asedio de la horda poniendo la antorcha detrás de su paso?',18019),
(10050,'esMX','Lo que yo te he pedido que hagas es algo impensable y a la vez horroroso. Pero debes entender que muchos de mis hombres no se acercarán a esas ruinas. Los recuerdos y el dolor son demasiado frescos, pero a pesar de ello no podemos permitir que los espíritus sigan vagando.$B$BCuanto más tiempo persistan, más débiles serán sus vínculos con su vida anterior y cederán fácilmente a la malevolencia.',18019),
(10057,'esMX','¿Ha vencido a los oficiales en las ruinas?',18019),
(10142,'esMX','El Bastión de honor está a salvo mientras los arqueros sigan custodiando nuestros cielos.',18019),
(10895,'esMX','El tiempo es crucial $N. ¡Necesitamos esas torres quemadas!',18019),
(10144,'esMX','Ojalá pudiera estar ahí para ver el fuego. ¡Estos explosivos son un gran golpe!',18019),
(10146,'esMX','Esta es una misión vital $N. Es una de las que no confiaría a casi nadie.',18019),
(10163,'esMX','¡Muéstrales que ni siquiera los cielos son seguros!',18019),
(10346,'esMX','Todavía hay bastantes objetivos en la plataforma abisal $N. Agarra un grifo cuando estés listo.',18019),
(10394,'esMX','No me hables de tus pies fríos $C. Sí terminan la construcción en ese campamento de forja ¡Tendrás más preocupaciones además de aquellos sirvientes! ¡Ve de una vez!',18019),
(10396,'esMX','¡La legión podría comenzar a bombardear a la horda en cualquier momento $N! ¡Necesitas destruir esos cañones!',18019),
(10397,'esMX','¡Cierra ese portal de la legión $N! Mientras estás aquí arrastrando los pies, ¡Hay más demonios entrando en Terrallende!',18019),
(9398,'esMX','Bienvenido de nuevo $N. ¿Has completado la tarea que te pedí?',18019),
(9383,'esMX','¿Has usado la magia del cristal contra un abisario sin control herido?',18019),
(9426,'esMX','¿Has completado tu tarea $N?',18019),
(9427,'esMX','Veo que regresas $N. ¿Has limpiado las Aguas?',18019),
(9424,'esMX','¿Has vengado a Sedai por makuru?',18019),
(9430,'esMX','¿Recuperaste las reliquias de Sha’naar $N?',18019),
(9545,'esMX','¿Has visto la visión $N?',18019),
(9399,'esMX','¡Has regresado! ¿Completaste tu tarea?',18019),
(9490,'esMX','¿Trajiste pruebas de la muerte de Garfanegra $N?',18019),
(9355,'esMX','¿Pudiste limpiar el camino?',18019),
(10079,'esMX','Háblame cuando el problema haya terminado, para que así mis muchachos puedan volver al trabajo... ¿Podrías?',18019),
(10099,'esMX','Casi me da miedo preguntar. Verte salir de aquella mina vivo significa una de dos cosas: o mataste al bastardo, o perdiste tu valor. Bien, ¿Cuál de las dos es la corecta?',18019),
(9417,'esMX','¡Volviste! ¿Cómo te fue?',18019),
(9385,'esMX','¿Has hecho algún progreso contra los devastadores?',18019),
(9563,'esMX','¿Tienes problemas para encontrar la jarra, verdad? El viejo Bernie en el castillo de Nethergarde podría almacenar los barriles allí mismo.$B$BA menos de que se hayan agotado... ¡Eso sería desastroso!',18019),
(9420,'esMX','¿Me trajiste las plumas de Kaliri $C?',18019),
(9575,'esMX','$N. ¿Verdad? Mechad me dijo que esperara tu informe.$B$B¿QUÉ estás haciendo en mi presencia?! ¿Está completa tu asignación? ¿Es usted un completo y absoluto deficiente intelectual? ¡Me haces querer vomitar!$B$B¡Ahora escóndete sin ningún valor detrás de esas murallas y haz lo que se te ordenó hacer. ¿Me oyes?',18019),
(9607,'esMX','¡Soldado, informe! ¿Has explorado todo el horno de sangre?',18019),
(11002,'esMX','Por primera vez desde que tengo memoria hay silencio.',18019),
(9372,'esMX','¿Pudiste recoger las muestras de sangre?',18019),
(10255,'esMX','¿Tienes los resultados del experimento?',18019),
(10132,'esMX','¿Has eliminado la amenaza colosal?',18019),
(10159,'esMX','¿Te está costando despejar la colina colmillespinado?',18019),
(10134,'esMX','Eso que tienes ahí es un gran cristal. ¿Lo obtuviste mientras estabas en la cresta matando colosos?$B$BDéjame echar un vistazo.',18019),
(10349,'esMX','¿Esa es una pieza del fragmento de cristal gigante de la cresta cielo estrellado?',18019),
(10351,'esMX','¿Ha funcionado? ¿Qué aprendiste? ¿Has averiguado quién o qué está detrás de lo que pasó en la cresta cielo estrellado?',18019),
(10367,'esMX','¿Conseguiste la llave $N?',18019),
(10368,'esMX','Cuéntame $N. ¿Los ancianos Zarrapucha han sido liberados?',18019),
(10369,'esMX','¿Lo has hecho $N? ¿Arzeth está muerto?',18019),
(10236,'esMX','¿Encontraste algunas piezas de repuesto para mi trituradora? Realmente quiero arreglarla para poder volver a la minería. Tengo que ganarme la vida de alguna forma. Sólo así puedo comprarme un billete de vuelta a Bahía del Botín.',18019),
(10238,'esMX','¿Ya has salvado a mis peones? Por favor, apresúrate. Me temo que van a ser devorados y probablemente no sepan muy bien. Si saben realmente mal, los orcos viles se enfadarán conmigo.',18019),
(10629,'esMX','¿Conseguiste encontrar mis llaves? Estoy seguro de que uno de mis canes las tiene. Probablemente sea aquél que te envié. Probablemente.',18019),
(10630,'esMX','¿Ya está muerto? Estoy demasiado asustado para ver.',18019),
(10161,'esMX','¿Encontraste suficientes piezas? Si no es así, podría tener que usar esa sartén que Legassi sigue agitando. Entonces, tendría que cambiar el nombre del zepelín a "sartén voladora"',18019),
(9351,'esMX','¿Fuiste capaz de obtener las esencias?',18019),
(9349,'esMX','¿Ya tienes esos huevos?$B$B<El estómago de Legassi gruñe de anticipación>',18019),
(9361,'esMX','¿Tuviste éxito en la purificación de la carne de jabinferno?',18019),
(9356,'esMX','No puedo esperar para ver la expresión de su rostro cuando lo pruebe. Desde el accidente, se ha estado quejando de que todo en lo que yo puedo pensar es en comida. Bueno, ¡alguien tiene que darnos de comer mientras repara el zepelín!','18019');


DELETE FROM `npc_text_locale` WHERE `ID` = 50016 AND `locale` IN ('esES');
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`) VALUES(50016,'esES','Hola, $C. Normalmente estaría al ritmo de cuidar de la gente de Ventormenta, pero muchos de los guardias están luchando en otras tierras. Así que estoy aquí, supliendo y ofreciendo recompensas cuando preferiría estar patrullando...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


DELETE FROM `npc_text_locale` WHERE `ID` = 50016 AND `locale` IN ('esMX');
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`) VALUES(50016,'esMX','Hola, $C. Normalmente estaría al ritmo de cuidar de la gente de Ventormenta, pero muchos de los guardias están luchando en otras tierras. Así que estoy aquí, supliendo y ofreciendo recompensas cuando preferiría estar patrullando...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


DELETE FROM `npc_text_locale` WHERE `ID` = 16211 AND `locale` IN ('esES');
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`) VALUES(16211,'esES','Agg, ¡Es bastante difícil mantener el orden aquí sin que surjan todos estos nuevos problemas! Espero que tengas buenas noticias, $N...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


DELETE FROM `npc_text_locale` WHERE `ID` = 16211 AND `locale` IN ('esMX');
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`) VALUES(16211,'esMX','Agg, ¡Es bastante difícil mantener el orden aquí sin que surjan todos estos nuevos problemas! Espero que tengas buenas noticias, $N...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


DELETE FROM `npc_text_locale` WHERE `ID` = 50028 AND `locale` IN ('esES');
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`) VALUES(50028,'esES','¡Ajá! ¡Buen día, buen día, ¡Maestro $C! Venga, siéntese y tome un trago. Tienes una mirada emprendedora y pienso que encontrarás que hablar conmigo vale la pena...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


DELETE FROM `npc_text_locale` WHERE `ID` = 50028 AND `locale` IN ('esMX');
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`) VALUES(50028,'esMX','¡Ajá! ¡Buen día, buen día, ¡Maestro $C! Venga, siéntese y tome un trago. Tienes una mirada emprendedora y pienso que encontrarás que hablar conmigo vale la pena...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


DELETE FROM `npc_text_locale` WHERE `ID` = 50017 AND `locale` IN ('esES');
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`) VALUES(50017,'esES','Hola amigo. Mi nombre es Remy.$BSoy de Crestagrana, hacia el este, y vine aquí buscando negocios, buscando negocios. Tienes algo... ¿¿algo??',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


DELETE FROM `npc_text_locale` WHERE `ID` = 50017 AND `locale` IN ('esMX');
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`) VALUES(50017,'esMX','Hola amigo. Mi nombre es Remy.$BSoy de Crestagrana, hacia el este, y vine aquí buscando negocios, buscando negocios. Tienes algo... ¿¿algo??',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


DELETE FROM `creature_text_locale` WHERE `CreatureID` = 22431 AND `locale` IN ('esES');
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`) VALUES
(22431,2,1,'esES','¡El poder de la luz te obliga! ¡De vuelta a tu pozo!'),
(22431,2,2,'esES','¡Purifícate con Luz, humano! No dejes que la corrupción demoníaca te abrume.'),
(22431,2,3,'esES','La luz es mi guía... ¡es mi sustento!'),
(22431,2,4,'esES','Yo... ¡no debo... vacilar!'),
(22431,2,5,'esES','¡En nombre de la Luz! ¡Es la Luz la que te manda! ¡Es la Luz que te arrojó a las profundidades de la oscuridad!');


DELETE FROM `creature_text_locale` WHERE `CreatureID` = 22432 AND `locale` IN ('esES');
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`) VALUES
(22432,1,1,'esES','Danos tiempo... Deja que el hombre muera... No soy nadie... No soy nadie... Teme al anacoreta... Teme al anacoreta... Barada... Barada.'),
(22432,1,2,'esES','¡Esto es infructuoso, draenei! Tú y tu pequeño ayudante no pueden arrebatar el control de este patético humano.'),
(22432,1,3,'esES','Haré pedazos su alma y lo asaré lentamente sobre fuego demoníaco.'),
(22432,1,4,'esES','¡Todo está perdido, Anacoreta! Abandona la esperanza que queda.'),
(22432,1,5,'esES','¡Veo a tus antepasados, Anacoreta! Se retuercen y gritan en la oscuridad... ¡están con nosotros!');


DELETE FROM `creature_text_locale` WHERE `CreatureID` = 22431 AND `locale` IN ('esMX');
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`) VALUES
(22431,2,1,'esMX','¡El poder de la luz te obliga! ¡De vuelta a tu pozo!'),
(22431,2,2,'esMX','¡Purifícate con Luz, humano! No dejes que la corrupción demoníaca te abrume.'),
(22431,2,3,'esMX','La luz es mi guía... ¡es mi sustento!'),
(22431,2,4,'esMX','Yo... ¡no debo... vacilar!'),
(22431,2,5,'esMX','¡En nombre de la Luz! ¡Es la Luz la que te manda! ¡Es la Luz que te arrojó a las profundidades de la oscuridad!');


DELETE FROM `creature_text_locale` WHERE `CreatureID` = 22432 AND `locale` IN ('esMX');
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`) VALUES
(22432,1,1,'esMX','Danos tiempo... Deja que el hombre muera... No soy nadie... No soy nadie... Teme al anacoreta... Teme al anacoreta... Barada... Barada.'),
(22432,1,2,'esMX','¡Esto es infructuoso, draenei! Tú y tu pequeño ayudante no pueden arrebatar el control de este patético humano.'),
(22432,1,3,'esMX','Haré pedazos su alma y lo asaré lentamente sobre fuego demoníaco.'),
(22432,1,4,'esMX','¡Todo está perdido, Anacoreta! Abandona la esperanza que queda.'),
(22432,1,5,'esMX','¡Veo a tus antepasados, Anacoreta! Se retuercen y gritan en la oscuridad... ¡están con nosotros!');


DELETE FROM `creature_text_locale` WHERE `CreatureID` = 21504 AND `locale` IN ('esES');
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`) VALUES
(21504,20,0,'esES','¿Y qué crees que estás haciendo? ¿Te atreves a interferir con el experimento de mi maestro?'),
(21504,21,0,'esES','¿Te gusta lo que hemos hecho aquí? Quizás arrojemos estos cristales desde el cielo por todo Terrallende.'),
(21504,22,0,'esES','Me aburro en tu intento de curar la tierra y sofocar las energías que convocan y vuelven locos a los colosos. ¡Goliathon rey de los colosos, el príncipe Kael’thas y yo exigimos que defiendas el cristal!'),
(21504,23,0,'esES','Nos volveremos a encontrar, pronto.');


DELETE FROM `creature_text_locale` WHERE `CreatureID` = 21504 AND `locale` IN ('esMX');
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`) VALUES
(21504,20,0,'esMX','¿Y qué crees que estás haciendo? ¿Te atreves a interferir con el experimento de mi maestro?'),
(21504,21,0,'esMX','¿Te gusta lo que hemos hecho aquí? Quizás arrojemos estos cristales desde el cielo por todo Terrallende.'),
(21504,22,0,'esMX','Me aburro en tu intento de curar la tierra y sofocar las energías que convocan y vuelven locos a los colosos. ¡Goliathon rey de los colosos, el príncipe Kael’thas y yo exigimos que defiendas el cristal!'),
(21504,23,0,'esMX','Nos volveremos a encontrar, pronto.');

UPDATE `quest_template_locale` SET `ObjectiveText1` = "Jules vengado" WHERE `ID` = 10909 AND `locale` IN ('esES','esMX');

UPDATE `quest_template_locale` SET `ObjectiveText1` = "Esqueleto pisoteado purificado" WHERE `ID` = 10047 AND `locale` IN ('esES','esMX');

UPDATE `quest_template_locale` SET
`ObjectiveText1` = "Torre norte marcada",
`ObjectiveText2` = "Torre sur marcada",
`ObjectiveText3` = "Torre de forja marcada",
`ObjectiveText4` = "Torre falda de la colina marcada"
WHERE `ID` = 10895 AND `locale` IN ('esES,esMX');

UPDATE `quest_template_locale` SET `ObjectiveText1` = "Presencia de Aggonar limpiada" WHERE `ID` = 9427 AND `locale` IN ('esES','esMX');

UPDATE `quest_template_locale` SET `ObjectiveText1` = "Visión concedida" WHERE `ID` = 9545 AND `locale` IN ('esES','esMX');

UPDATE `quest_template_locale` SET `ObjectiveText1` = "Administrar antídoto" WHERE `ID` = 10255 AND `locale` IN ('esES','esMX');

UPDATE `quest_template_locale` SET `ObjectiveText1` = "Cresta Cielo Estrellado revitalizada" WHERE `ID` = 10351 AND `locale` IN ('esES','esMX');

UPDATE `quest_template_locale` SET
`ObjectiveText1` = "Morod liberado",
`ObjectiveText2` = "Akoru liberado",
`ObjectiveText3` = "Aylaan liberado"
WHERE `ID` = 10368 AND `locale` IN ('esES','esMX');

UPDATE `quest_template_locale` SET `ObjectiveText2` = "Cerrar la Puerta de la Legión Ardiente" WHERE `ID` = 10397 AND `locale` IN ('esES','esMX');

UPDATE `quest_template_locale` SET
`ObjectiveText1` = "Manni Salvado",
`ObjectiveText2` = "Moh Salvado",
`ObjectiveText3` = "Jakk Salvado"
WHERE `ID` = 10238 AND `locale` IN ('esES','esMX');

UPDATE `creature_template_locale` SET `Title` = "Bibliotecario" WHERE `entry` = 951 AND `locale` IN ('esES','esMX');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
