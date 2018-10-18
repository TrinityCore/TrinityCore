/*
-- Ghostlands -- Geisterlande

-- 9130 - Waren von Silbermond
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9130 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9130, "deDE", "Ja, was gibt's?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9130 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9130, "deDE", "Sathiel möchte, dass Ihr nach Silbermond geht und ihre Waren zurückbringt, was? Kein Problem, ich kann Euch schnell dorthin bringen... gegen eine kleine Gebühr, versteht sich.", 26972);

-- 9133 - Fliegt nach Silbermond
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9133 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9133, "deDE", "Das ist eine ganz schön lange Liste, die Ihr da habt, meine Freundin. Lasst mich mal sehen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9133 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9133, "deDE", "Was soll das? Sie möchte all das!?$B$BHabt Ihr wenigstens jemanden bei Euch, der Euch beim Rücktransport behilflich ist?", 26972);

-- 9134 - Himmelsmeisterin Abendlicht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9134 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9134, "deDE", "Wow, dieses Warenpaket sieht aber mächtig schwer aus! Möchtet Ihr all das auf eins meiner Prachtstücke laden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9134 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9134, "deDE", "Zurück nach Tristessa in den Geisterlanden, ja? Alles klar, ich kann Euch schnell an Euer Ziel bringen!", 26972);

-- 9135 - Zurück zu Sathiel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9135 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9135, "deDE", "$C, schon zurück? Das kann aber unmöglich alles sein, was auf der Liste stand!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9135 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9135, "deDE", "Hmmm, wenn er gesagt hat, dass der Rest schnell über den Landweg nachgeliefert wird, dann will ich ihn mal beim Wort nehmen. In der kurzen Zeit, in der wir zusammen gearbeitet haben, hat er es noch immer geschafft, die Waren pünktlich zu liefern.$B$BIch danke Euch, $N. Hier, nehmt diese Münzen... sie haben schon den ganzen Tag in meiner Tasche geklimpert.", 26972);

-- 9138 - Sonnenkuppe
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9138 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9138, "deDE", "Hervorragend! Doch es gibt noch viel zu tun, bis auch der letzte Rest dieser Landplage namens Geißel aus dem mächtigen Quel'Thalas vertrieben wurde!$B$BHier, Eure Bezahlung... Es ist zwar nicht viel, doch Ihr habt es Euch verdient.", 26972);

-- 9139 - Goldnebel
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9139 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9139, "deDE", "Euer Erfolg in Goldnebel bringt uns wieder einen Schritt näher an die vollständige Rückeroberung unserer Ländereien. Doch lasst Euch nicht täuschen, $C, diese Schlacht ist noch lange nicht geschlagen.$B$BHier, diese Belohnung habt Ihr Euch mehr als verdient. Sie wird sich als nützlich erweisen, sobald Ihr nach Windläuferdorf aufbrecht.", 26972);

-- 9140 - Windläuferdorf
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9140 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9140, "deDE", "$C, wurde das Windläuferdorf befreit? Diese verdammten Magister des Sanktums der Sonne fordern ständig von mir, dass ich ihnen endlich Überreste der Geißel gebe, die Ihr gerade für mich sammeln sollt.$B$BMacht Euch deshalb aber keine Sorgen! Nehmt Euch alle Zeit, die Ihr braucht, um diesen Auftrag sicher zu Ende zu führen. Ich kümmere mich derweil um die Magister.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9140 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9140, "deDE", "Ihr habt es geschafft, $N. Ihr habt drei Dörfer aus der Umklammerung der Geißel befreit! Nun können wir uns voll und ganz auf die Bekämpfung der Geißel in der Todesschneise und südlich bei der Todesfestung konzentrieren.$B$BSucht Euch eine dieser Belohnungen aus. Ich hoffe, Ihr bleibt noch ein Weilchen. Wir können Eure Hilfe auch weiterhin gut gebrauchen!", 26972);

-- 9143 - Maßnahmen gegen Zeb'Sora
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9143 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9143, "deDE", "Habt Ihr die Trollohren?$B$BWisst Ihr, wenn wir ab und an mal etwas Unterstützung aus Tristessa erhalten würden, wäre die ganze Misere hier so nie passiert. Ich bin wirklich froh über Euer Kommen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9143 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9143, "deDE", "Ich schätze Eure Bemühungen, $C! Habt Dank. Wenigstens können wir jetzt sagen, dass diese ganze Expedition und die vielen Opfer nicht vergebens gewesen sind.", 26972);

-- 9144 - Verschollen in den Geisterlanden
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9144 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9144, "deDE", "Helft mir, Fremder. Ich muss... Tristessa... erreichen... Ich darf nicht versagen.$B$B<Der Blick des Blutelfen entschwindet ins Leere, und er versinkt wieder in Bewusstlosigkeit.>", 26972);

-- 9145 - Hilfe für Waldläuferin Valanna!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9145 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9145, "deDE", "Es ist gut zu hören, dass Lethvalin sich in Sicherheit bringen konnte, und dass er Euch um Hilfe gebeten hat, anstatt einfach nur abzuwarten.$B$BHoffentlich konnte sich Waldläuferin Salissa zur Enklave der Weltenwanderer durchschlagen.", 26972);

-- 9146 - Meldung bei Hauptmann Helios
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9146 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9146, "deDE", "Das sind in der Tat schlechte Nachrichten - Ich habe Tomathrens Führungsqualitäten völlig überschätzt. Ich werde sofort einen Kampftrupp entsenden, um ihn und Valanna sicher zurückzubringen.$B$BUnglücklicherweise haben wir nichts mehr von Waldläuferin Salissa gehört, ich befürchte das Schlimmste.$B$BIhr habt den Weltenwanderern heute einen wertvollen Dienst erwiesen, $C. Bitte nehmt dies als Zeichen unserer Wertschätzung.", 26972);

-- 9147 - Der sterbende Kurier
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9147 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9147, "deDE", "Und? Habt Ihr, was ich benötige? Beeilt Euch oder mit dem hübschen $R ist es gleich aus!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9147 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9147, "deDE", "Gerade noch rechtzeitig, $N! Ich war drauf und dran für unseren Freund hier ein schönes Loch auszuheben.$B$BMein Trank scheint zu wirken; er kommt wieder zu sich.$B$BHey, ich glaube er will Euch etwas sagen. Warum versucht Ihr nicht mal mit ihm zu sprechen?", 26972);

-- 9148 - Zustellung nach Tristessa
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9148 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9148, "deDE", "Ihr habt den Brief?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9148 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9148, "deDE", "Endlich! Wir haben schon seit Wochen auf eine Antwort vom Lordregenten gewartet! Lasst mich mal sehen...$B$B<Vandril beginnt den Brief zu lesen.>$B$BWas soll das? Eine finstere Präsenz? Er spürt eine finstere Präsenz in den Geisterlanden?! Im Ernst, das hätte ich ihm auch sagen können!$B$BIst das die Nachricht, auf die wir gewartet haben?", 26972);

-- 9149 - Die verseuchte Küste
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9149 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9149, "deDE", "Habt Ihr die Exemplare, um die ich Euch gebeten habe, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9149 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9149, "deDE", "Ausgezeichnet! Diese Rückgrate sind für meine Untersuchungen von unschätzbarem Wert! Sollte ich ein Heilmittel gegen die Seuche finden und meinem Namen dadurch Ruhm verleihen, werde ich nicht vergessen, Euch zu erwähnen!$B$BBis dahin, nehmt dies als Belohnung. Ihr könntet davon Gebrauch machen, solltet Ihr noch einmal zur Küste gehen.", 26972);

-- 9150 - Reise zum vergessenen Sanktum
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9150 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9150, "deDE", "Habt Ihr die Essenzen, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9150 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9150, "deDE", "Sie sind in einem bemerkenswert guten Zustand, $N. Ich bin mit Eurer Arbeit sehr zufrieden.", 26972);

-- 9151 - Das Sanktum der Sonne
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9151 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9151, "deDE", "Darenis schickt Euch? Gut, ich schätze, wir können Euch im Kampf gegen Dar'khans Streitmächte brauchen.", 26972);

-- 9152 - Tombers Vorräte
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9152 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9152, "deDE", "Sobald ich den Rest meiner Vorräte habe, kann ich mein Geschäft aufnehmen. Die Streitkräfte werden nicht weit kommen, wenn sie nicht das erhalten, womit sie regelmäßig ihren Handel treiben.$B$BKriegsgebiete können so florierend für das Geschäft sein, findet Ihr nicht auch, $C? So, habt Ihr Euch einen Weg durch all die Ghule zu meinem Karren bahnen können?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9152 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9152, "deDE", "Dank der restlichen Vorräte hier, kann ich jetzt endlich mit meinem Geschäft loslegen. Ich bin mir sicher, dass der Hochexekutor erfreut sein wird, sobald er hört, dass der Krieg gegen Dar'Khan und die Geißel beginnen kann.$B$BNatürlich gibt es da auch noch Eure Belohnung. Nun gut, $C, hier ist die von mir erwähnte Münze. Solltet Ihr irgendwelche Handwerkswaren benötigen, schaut einfach vorbei.", 26972);

-- 9155 - Entlang der Todesschneise
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9155 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9155, "deDE", "Nicht schlecht, $N. Macht weiter so! Leute wie Euch können wir immer gebrauchen.", 26972);

-- 9156 - GESUCHT: Faulbein und Luzran
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9156 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9156, "deDE", "Ihr habt etwas, das Ihr mir zeigen wollt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9156 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9156, "deDE", "Aha! Luzran und Faulbein! Jetzt seht ihr nicht mehr so gefährlich aus, was? Aber immer noch genauso hässlich!$B$BNehmt dies als Belohnung, $N. Ihr habt es Euch verdient.", 26972);

-- 9157 - Vergessene Rituale
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9157 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9157, "deDE", "Konntet Ihr die Medaillons beschaffen, $N? Die Ertrunkenen suchen immer noch diesen See heim!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9157 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9157, "deDE", "Mithilfe dieser Halsketten werden wir Aquantion erneut beschwören. Der rebellische Elementar wird bezahlen und unser Tod wird gerächt werden!", 26972);

-- 9158 - Überträger der Seuche
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9158 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9158, "deDE", "Ihr habt Euch bewährt, $N. Es ist von größter Wichtigkeit, dass die Seuche nicht auch noch die gesunde Fauna des Immersangwalds befällt. Ich habe noch weitere Aufgaben für Euch, sofern Ihr noch auf der Suche nach Arbeit seid.", 26972);

-- 9159 - Gebietet der Seuche Einhalt
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9159 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9159, "deDE", "Ihr habt Eure Aufgabe sehr ernst genommen und daher möchte ich Euch entsprechend belohnen. Wir brauchen mehr Verbündete mit Eurer Hingabe und Tapferkeit, $N!", 26972);

-- 9160 - Untersucht An'daroth
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9160 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9160, "deDE", "Es ist enttäuschend, dass es keine offensichtlichen Hinweise auf die Pläne der Nachtelfen bei An'daroth gab. Wie auch immer, diese Bäume, welche aussahen wie kleine magisch gewachsene Bäume mit Energiekugeln auf ihrer Spitze, sind äußerst interessant. Es scheint mir, als müssten wir die Art unserer Informationsbeschaffung ein wenig direkter gestalten.$B$BHier, nehmt diese Münze und die Tränke. Vermutlich werdet Ihr sie noch brauchen, bevor wir diese Angelegenheit mit den Nachtelfen geklärt haben.", 26972);

-- 9161 - Schatten des Verräters
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9161 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9161, "deDE", "Ihr blättert durch die ersten Einträge des uralten Buchs und kommt zu dem Schluss, dass es einst der Person gehörte, die heute als Dar'khan Drathir bekannt ist.", 26972);

-- 9162 - Die Vergangenheit erwacht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9162 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9162, "deDE", "Sagt mir, $N, was habt Ihr herausgefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9162 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9162, "deDE", "Diese Information ist für uns von hohem Wert, $N. Wir alle wussten von Dar'Khans Plänen, die Macht des Sonnenbrunnens für die Geißel zu stehlen, doch vieles auf diesen Seiten ist völlig neu für uns. Magister Kaendris beim Sanktum der Sonne wird sich sicherlich sehr dafür interessieren.", 26972);

-- 9163 - In besetztem Gebiet
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9163 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9163, "deDE", "Was machen unsere Bemühungen, die Nachtelfenverschwörung auf der Insel Shalandis aufzudecken, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9163 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9163, "deDE", "Äußerst beunruhigend! Die Pläne zeigen die Streitkräfte der Nachtelfen bei An'daroth, von denen wir bereits wussten, doch gibt es wohl eine weitere Gruppe bei An'owyn, einem eher abgelegenen Leyliniennexus im Südosten.$B$BEs existiert noch ein dritter Nexus im Osten, An'telas, der nicht weiter erwähnt wird. Ich habe da ein ganz mieses Gefühl bei der Sache, $C.", 26972);

-- 9164 - Gefangene der Todesfestung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9164 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9164, "deDE", "Hervorragende Arbeit, $N. Ohne Eure Hilfe hätten diese Gefangenen Ihren Verstand und Ihre Seele an die Geißel verloren.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9164 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9164, "deDE", "Ich danke Euch, $N. Ohne Eure Hilfe hätten diese Gefangenen ihren Verstand und ihre Seele an die Geißel verloren.", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Apothekerin Enith befreit", `ObjectiveText2`="Lehrling Varnis befreit", `ObjectiveText4`="Waldläufer Vedoran befreit", `VerifiedBuild`=26972 WHERE `ID` = 9164 AND `locale` = "deDE";

-- 9166 - Bringt die Pläne nach An'telas
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9166 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9166, "deDE", "Gut, dass Ihr hier seid!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9166 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9166, "deDE", "Es war schrecklich! Nachtelfen! Sie haben einen Mondkristall beschworen und irgendeine Niedertracht geplant. Glücklicherweise konnte ich mich davonschleichen und einige unserer Späher und Zauberer aus dem nahegelegenen Sanktum der Sonne zu Hilfe holen. Es gelang uns, die meisten von ihnen zu töten. Die anderen sind daraufhin losgezogen, um die Überlebenden zu jagen!$B$BIch bin so froh, dass Ihr gekommen seid; man hat mich hier nur mit einigen wenigen Spähern zur Verteidigung zurückgelassen!$B$BGebt mir einen Moment, um diese Pläne zu lesen, möglicherweise finde ich heraus, worauf es die Nachtelfen abgesehen haben.", 26972);

-- 9167 - Der Tod des Verräters
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9167 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9167, "deDE", "Ist es getan? Wurde Dar'Khan vernichtet?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9167 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9167, "deDE", "Am heutigen Tage habt Ihr der Geißel in dieser Region einen tödlichen Schlag versetzt.$B$BNach dem Tod des schändlichen Verräters ist die Rückeroberung unserer Länder nur noch eine Frage der Zeit. Schon bald werden wir zu altem Ruhm und Glanz zurückgefunden haben!", 26972);

-- 9169 - Die Abschaltung von An'owyn
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9169 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9169, "deDE", "Ich bin erleichtert, $C! Seid versichert, dass wir ohne Eure Hilfe bei der Abschaltung der Seherkristalle in einer noch viel schwierigeren Lage wären, als wir es sowieso schon sind! Man stelle sich nur vor, umgeben von Feinden und einer von ihnen besäße die Fähigkeit, uns auf Schritt und Tritt zu beobachten!$B$BDank Euch müssen wir uns darüber keine Sorgen mehr machen! Ich habe hier zufällig noch einige Gegenstände herumliegen, für die ich keine weitere Verwendung mehr habe; sicherlich werdet Ihr davon etwas gebrauchen können. Hier, nehmt das als Belohnung.$B$BNochmals vielen Dank, $N!", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Deaktivierte nachtelfische Mondkristalle", `VerifiedBuild`=26972 WHERE `ID` = 9169 AND `locale` = "deDE";

-- 9170 - Dar'Khans Gefolgschaft
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9170 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9170, "deDE", "Dar'Khans Armeen fallen! Die Geißel kann nicht gegen die vereinte Macht der Sin'dorei und der Verlassenen bestehen.", 26972);

-- 9171 - Knusperkost
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9171 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9171, "deDE", "Ich glaube ich kann den Magen der Dame sogar von hier aus knurren hören! Da Ihr hier seid und mich sprechen wollt, gehe ich davon aus, dass Ihr mir meine Zutaten bringt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9171 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9171, "deDE", "Sehr schön, das dürfte den Zweck erfüllen. Nein, erzählt mir nicht, wie die Dinger rumgekrabbelt sind, ich will es nicht wissen! Ich werde etwas Magie verwenden, dann werden diese Beinchen schon schmackhaft. Ein paar Gewürze, eine Messerspitze Kräuter und natürlich ein paar arkane Zutaten – et voilà, ein passendes Mahl für eine Königin... oder in diesem Fall, eine Dame.$B$BEure Dienste waren zufriedenstellend, $C. Hier, nehmt dieses Rezept und ein paar Portionen.", 26972);

-- 9172 - Bericht an Magister Kaendris
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9172 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9172, "deDE", "Ihr wünscht mit mir zu sprechen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9172 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9172, "deDE", "Dieses Buch... das ist unmöglich! Es ist Dar'Khans eigene Handschrift. Irgendwo in diesem Buch muss es einen Hinweis geben, der uns eine Schwäche des Gegners aufzeigt.$B$BIhr habt gut daran getan, uns aufzusuchen, $N. Indem sie diese Angelegenheit in unsere fähigen Hände gaben, haben die Weltenwanderer ihre Weitsicht bewiesen. Diese Rüstung sollte Euch helfen, unsere Sache weiterzuführen.", 26972);

-- 9173 - Rückeroberung des Windläuferturms
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9173 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9173, "deDE", "Ich bin sicher, Fürstin Sylvanas wird über unsere Fortschritte in dieser Sache erfreut sein.$B$BHier, nehmt dies als Bezahlung für Eure Mühen.", 26972);

-- 9174 - Aquantion bezwingen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9174 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9174, "deDE", "Wurde Aquantion schon zerstört?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9174 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9174, "deDE", "Ihr habt unseren Tod gerächt und Aquantions Macht über unsere Seelen gebrochen. Endlich können wir ruhen.", 26972);

-- 9175 - Die Halskette der Fürstin
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9175 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9175, "deDE", "Was habt Ihr da, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9175 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9175, "deDE", "Ihr sagt, Ihr fandet dies bei einem Schergen der Geißel am Windläuferturm, und dass es eine Inschrift gibt? Lasst mich sehen!$B$BHier, nehmt dies für Eure gute Arbeit.", 26972);

-- 9176 - Die Zwillingsziggurats
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9176 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9176, "deDE", "Habt Ihr die Kristalle schon geborgen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9176 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9176, "deDE", "Die Geschichten sind also wahr! Der Stein des Lichts und der Stein der Flamme existieren tatsächlich! Wir werden ihre Macht nutzen, um wirkungsvolle Waffen gegen Dar'Khan zu schmieden.$B$BWenn Ihr die in diesen Artefakten schlummernden Energien zum richtigen Zeitpunkt freisetzt, werden sie Dar'Khan vernichten. Einst wollte er uns diese Macht nehmen, doch jetzt wird sie sein Untergang sein!", 26972);

-- 9192 - Ärger in den Grubenlichtminen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9192 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9192, "deDE", "Da habt Ihr mal ordentlich Blut fließen lassen, $C. Die Minenarbeiter können jetzt wieder an die Arbeit. Sie sind sicher enttäuscht, dass ihre Pause jetzt vorbei ist, aber wir brauchen nun mal mehr Erz, um Rüstungen und Waffen herzustellen.$B$BHier, nehmt dies als Lohn für Eure pflichtbewusste Tat. Lasst Rüstung und Waffen reparieren und trinkt einen auf mich.", 26972);

-- 9193 - Untersucht die Amanikatakomben
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9193 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9193, "deDE", "Das ist eine äußerst makabre und würdelose Angelegenheit, $C. Ich kann Euch doch vertrauen, dass Ihr diesen Auftrag erfüllt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9193 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9193, "deDE", "Abscheulich, aber glaubt mir, es war notwendig. Ihr habt mit Euren Nachforschungen eine gute Tat vollbracht, $C. Bitte, nehmt dies als Zeichen unserer Großzügigkeit und Anerkennung an.", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Mumifizierte Trollüberreste verbrannt", `VerifiedBuild`=26972 WHERE `ID` = 9193 AND `locale` = "deDE";

-- 9199 - Trolljuju
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9199 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9199, "deDE", "Ich muss Euch wohl nicht erst sagen, dass wir uns diesen Ärger mit den von den Toten auferstandenen Trollen hier bei uns kaum leisten können! Wir haben schon genug Probleme mit der Todesfestung im Süden!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9199 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9199, "deDE", "Mumien, die von den Trollpriestern wiedererweckt werden... clever! Die Waldschattentrolle wollen ihre Reihen wohl mithilfe nekromantischer Mittel verstärken. Ich wette, dass diese Orakel das Juju bei ihrem Wiedererweckungsritual verwendet haben.$B$BIhr habt Eure Pflicht wieder einmal so erfüllt, wie es sich für jemanden mit ständig wachsendem Ansehen geziemt. Nehmt diesen Lohn als Dank.", 26972);

-- 9207 - Grubenlichterzproben
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9207 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9207, "deDE", "Wie kann ich Euch helfen, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9207 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9207, "deDE", "Mein Lehrling konnte sich nicht selbst um diese Angelegenheit kümmern? Ich werde noch ein Wörtchen mit ihr zu reden haben, sobald sie wieder da ist, Gnolle hin oder her. Außerdem, warum ist sie nicht mit Euch zurückgekommen?$B$B<Der Magister seufzt.>$B$BSie ist eine schwierige Persönlichkeit und ihre Ausbildung wird mir noch helle Freude bereiten. Danke, dass Ihr mir diese Proben gebracht habt, $C. Wir hoffen ein paar spezielle Eigenschaften darin zu entdecken, die uns im Kampf gegen die Geißel von Nutzen sein können.$B$BBitte nehmt diesen Lohn als Zeichen meiner Wertschätzung.", 26972);

-- 9212 - Flucht aus den Katakomben
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9212 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9212, "deDE", "Ihr seid ein ziemlicher Held, $C, sie da lebend herausbekommen zu haben. Ich denke, wir müssen einen Gegenschlag planen, um diese Katakomben auszuräuchern. Als wenn wir nicht schon genug Ärger mit den lebenden Trollen hätten!$B$BIhr habt heute außerordentlich gute Arbeit geleistet, Ihr verdient eine Belohnung. Sucht Euch etwas aus.", 26972);

-- 9214 - Das Arsenal der Waldschattentrolle
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9214 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9214, "deDE", "Habt Ihr die Waffen beschafft? Sobald wir die Reihen der Waldschattentrolle dezimiert haben, können wir uns wieder dem Kampf gegen die Geißel widmen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9214 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9214, "deDE", "Ich werde umgehend einige Waldläufer entsenden, um den Schaden, den Ihr unter den Waldschattentrollen angerichtet habt, zu begutachten. Wenn die von Euch mitgebrachte Waffensammlung auch nur ansatzweise den Erfolg Eures Angriffs gegen die Trolle widerspiegelt, sollten wir mit den Überlebenden leichtes Spiel haben. Das wird uns einen baldigen Angriff auf die Geißel ermöglichen.$B$BHier, nehmt diese Münze als Zeichen meiner Dankbarkeit, das schafft wieder etwas Platz in meinem Geldbeutel.", 26972);

-- 9215 - Bringt mir Kel'gashs Kopf!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9215 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9215, "deDE", "Was ist das für ein widerlicher Gestank?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9215 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9215, "deDE", "Ah, Kel'gashs Kopf ist der Quell dieses wundervollen Aromas. Ihr habt offensichtlich ganze Arbeit geleistet, $C!$B$BDer Tod ihres Anführers hat die Waldschattentrolle ins Chaos gestürzt. Berücksichtigt man jetzt noch Eure letzten Einsätze zur Dezimierung ihrer Anzahl, denke ich, dass jetzt der Zeitpunkt für unsere Gegenoffensive gekommen ist, um sie ein für alle Mal zu vernichten.$B$BIhr habt meinen Dank, $N. Kann ich Euch vielleicht für einen dieser Gegenstände begeistern?", 26972);

-- 9216 - Faulende Herzen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9216 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9216, "deDE", "Habt Ihr die Zombieherzen, nach denen ich verlangt habe, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9216 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9216, "deDE", "Nehmt dieses Gebräu, $N. Sobald Ihr es getrunken habt, erfährt Eure körperliche Stärke im Kampf gegen die Geißel einen Schub. Wenn Ihr noch mehr von dieser Probe brauchen solltet, bringt mir mehr Herzen.", 26972);

-- 9217 - Mehr faulende Herzen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9217 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9217, "deDE", "Ihr habt mehr faulende Herzen gebracht? Ich kann alle gebrauchen die Ihr sammeln könnt, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9217 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9217, "deDE", "Dies wird Euch mit mehr Stärke im Kampf gegen die Geißel versorgen. Bringt mir mehr Herzen, falls Ihr welche findet, $N.", 26972);

-- 9218 - Wirbelknochenstaub
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9218 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9218, "deDE", "Habt Ihr die Proben, nach denen ich verlangt habe, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9218 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9218, "deDE", "Hier, für Euch, $N. Ihr werdet den Unterschied sofort spüren!$B$BIhr könnt mir jederzeit mehr Wirbelknochenstaub bringen, ich kann so viel davon verarbeiten, wie Ihr mir besorgen könnt. Nebenwirkungen? Naja, Eure Stimme klingt ein bisschen höher, aber das sind lediglich die Rückstände des Staubs, die verrückt spielen.", 26972);

-- 9219 - Mehr Wirbelknochenstaub
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9219 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9219, "deDE", "Ihr habt mehr Wirbelknochenstaub beschafft? Ich kann alles gebrauchen was Ihr mir bringt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9219 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9219, "deDE", "Dieser Wirbelknochenstaub ist nach wie vor mächtig, $N. Bringt mir auch weiterhin welchen, wenn Ihr Verstärkung für Eure magischen Fähigkeiten im Kampf gegen die Geißel benötigt.", 26972);

-- 9220 - Krieg gegen die Todesfestung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9220 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9220, "deDE", "Die Geißel hat unsere Rache zu spüren bekommen, $N. Nicht mehr lange und ihre verfluchte Zitadelle wird in Trümmern liegen.", 26972);

-- 9274 - Geister der Ertrunkenen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9274 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9274, "deDE", "Ich bin dankbar für Eure Hilfe, $N. Es schmerzt mich, die Geister meiner Ahnen in diesem jämmerlichen Zustand zu sehen. Mögen sie in Frieden ruhen.", 26972);

-- 9275 - In der Würze liegt der Tod
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9275 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9275, "deDE", "Ah, hervorragend! Ich wusste es, ein $R war die richtige Wahl, um das Gift hinreichend zu verteilen. Mit etwas Glück werden die Waldschattentrolle schön fett, bevor sie durch die Wirkung des Gifts in den Nether eingehen. Damit dürften die Weltenwanderer ihre Ruhe haben und ich kann endlich meine wohlverdiente Heimreise nach Tristessa antreten.$B$BEs war mir eine Freude mit Euch zu arbeiten, $C!", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Ständer mit rohem Fleisch vergiften", `ObjectiveText2`="Ständer mit Rauchfleisch vergiften", `ObjectiveText3`="Ständer mit frischem Fisch vergiften", `VerifiedBuild`=26972 WHERE `ID` = 9275 AND `locale` = "deDE";

-- 9276 - Angriff auf Zeb'Tela
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9276 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9276, "deDE", "Gut, sehr gut! Das habt Ihr hervorragend gemeistert! Dann wollen wir doch mal sehen, ob Ihr auch der nächsten Herausforderung gewachsen seid.", 26972);

-- 9277 - Angriff auf Zeb'Nowa
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9277 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9277, "deDE", "Unglaublich! Ihr solltet Euch unbedingt mit unserem Hauptmann über einen Beitritt in die Reihen der Weltenwanderer unterhalten.$B$BNun gut, $N, Ihr habt uns die dringende Atempause zum Sammeln unserer Streitkräfte verschafft. Genau genommen scheinen unserer letzten Zählung nach nur wenige Trolle übrig zu sein! Vielleicht können wir uns nun mit den Streitkräften Tristessas vereinen, um gemeinsam die Todesfestung anzugreifen, anstatt unsere Zeit weiter mit den hiesigen Trollen zu verschwenden.$B$BIch denke, Ihr habt Euch eine kleine Belohnung verdient. Greift zu!", 26972);

-- 9281 - Den Weg frei machen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9281 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9281, "deDE", "Vielen Dank für Eure Unterstützung, $N. Mir schaudert bei dem Gedanken, mich so nahe bei der Todesfestung in den Wald zu wagen.", 26972);

-- 9282 - Die Enklave der Weltenwanderer
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9282 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9282, "deDE", "Kaendris hat Euch geschickt? Möglicherweise habe ich eine Aufgabe für Euch, $C.", 26972);

-- 9315 - Anok'suten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9315 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9315, "deDE", "Ich muss mich für die schlechte Aufklärung entschuldigen, $C. Hätte ich vorher etwas von der Existenz dieser Anok'suten gewusst, hätte ich Euch natürlich umgehend davon in Kenntnis gesetzt.$B$BUnsere Kräfte sind einfach zu weit verteilt und manche Dinge schlüpfen uns unter diesen Umständen einfach durchs Netz.", 26972);

-- 9327 - Die Verlassenen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9327 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9327, "deDE", "Ich weiß, wir Verlassenen mögen in Euren Augen monströs erscheinen, aber ich versichere Euch, wir sind für Euer Volk keine Bedrohung. Wir sind hier, weil wir einen gemeinsamen Feind haben: Dar'Khan den Verräter! Er ist zurückgekehrt und befehligt die Geißel von der Todesfestung im Süden aus.$B$BUnsere Anführerin, Fürstin Sylvanas Windläufer, stammt aus dieser Gegend und war früher eine Elfe. Sie hatte schon mit Dar'Khan zu tun und möchte ihn genauso gern tot sehen, wie Euer Volk.$B$BWir werden ihn zusammen besiegen, $C!", 26972);

-- 9328 - Held der Sin'dorei
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9328 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9328, "deDE", "Ihr wünscht eine Audienz bei mir, $C? Ich kann mich nicht an eine Verabredung erinnern.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9328 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9328, "deDE", "Nun, das ist ein Gesicht, das ich noch nicht so früh hier erwartet hätte.$B$BDas sind ziemlich gute Neuigkeiten, $N, in mehr Hinsichten, wie Ihr Euch denken könnt.", 26972);

-- 9329 - Die Verlassenen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9329 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9329, "deDE", "Die Verlassenen sind hier, weil wir und die Blutelfen einen gemeinsamen Feind haben: Dar'Khan! Er ist zurückgekehrt und befehligt die Geißel von der Todesfestung im Süden aus.$B$BFürstin Sylvanas Windläufer, die ursprünglich aus dieser Gegend hier stammt, hatte schon früher mit Dar'Khan zu tun und möchte ihn tot sehen!$B$BWir werden ihn besiegen, $N, und Ihr werdet uns dabei helfen!", 26972);

-- 9487 - Arkanhäscher
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9487 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9487, "deDE", "Ihr seid den Rohlingen nicht zu Nahe gekommen, hoffe ich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9487 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9487, "deDE", "Welche Verschwendung, Magie zu nutzen um Wesen von körperlicher Gewalt zu erschaffen. Ich dachte immer, das wäre der Grund, warum wir uns mit den niederen Völkern verbündet hätten.$B$BEs war gut von Euch, sie zu zerstören. Nun können wir ihre Überreste für angemessenere Zwecke verwenden.", 26972);

-- 9488 - Eine einfache Robe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9488 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9488, "deDE", "Die Robe kann ohne die notwendigen Materialien nicht fertiggestellt werden, aber das ist Euch sicherlich bekannt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9488 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9488, "deDE", "Die Details der Herstellung von magischen Roben brauchen Euch nicht zu interessieren, $B, Ihr müsst nur Wissen, was Ihr mir zu bringen habt.$B$BUm ehrlich zu sein, Ihr habt mir genug für mehrere Roben gebracht. Der Profit, den ich damit machen kann, sollte ausreichen, um die Herstellungskosten Eurer Robe zu decken, und mir selbst noch etwas Nettes zu kaufen. Habt Dank!", 26972);

-- 9621 - Gesandter zur Horde
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9621 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9621, "deDE", "Ah, ein Besucher aus Quel'Thalas! Welche Neuigkeiten bringt Ihr?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9621 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9621, "deDE", "Dann ist es also geschehen. Der gemeine Verräter hat bekommen, was er verdient hat.$B$BIhr habt das selbst getan? Eine beeindruckende Tat, die beweist, dass Euer Volk immer noch würdig ist, $N.$B$BWie ich sehe, hat Lor'themar weitere Nachrichten, die seine Beziehungen zu den Trollen und ihrem Kriegshäuptling deutlich verbessern werden.", 26972);

-- 9626 - Begegnung mit den Orcs
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9626 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9626, "deDE", "Ihr seid weit gereist, um mich zu treffen. Was bringt Euch nach Orgrimmar?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9626 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9626, "deDE", "<Saurfang beginnt, den Brief zu lesen.>$B$BSylvanas ist hartnäckig. Sie geht sogar so weit, einen Champion von Silbermond zu schicken... aber was soll das ändern?", 26972);

-- 9627 - Treue gegenüber der Horde
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9627 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9627, "deDE", "Eure Taten waren den Zielen unseres Volkes sehr dienlich.$B$BBereitet Euch auf große Veränderungen vor, $N. Wir sind nun offiziell ein Teil der Horde.", 26972);

-- 9758 - Rückkehr zu Arkanist Vandril
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9758 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9758, "deDE", "Ah, gut, da seid Ihr ja. Und gerade zur rechten Zeit, es gibt viel zu tun!", 26972);

-- 9811 - Freund der Sin'dorei
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9811 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9811, "deDE", "Ihr wünscht eine Audienz bei mir, $C? Ich kann mich nicht an eine Verabredung erinnern.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9811 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9811, "deDE", "Ihr habt Dar'Khan also getötet, $R? Beeindruckend. Ich habe das Gefühl, dass unsere und Eure Leute bald gute Freunde sein werden.", 26972);

-- 9877 - Ein Regenerationsgebräu
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9877 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9877, "deDE", "Janeda schickt Euch, um die Gefangenen der Todesfestung zu retten? Sie muss eine hohe Meinung von Euch haben, $N.", 18019);
*/
