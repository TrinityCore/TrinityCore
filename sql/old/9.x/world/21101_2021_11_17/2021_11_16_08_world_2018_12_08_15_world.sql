-- Blade's Edge Mountains -- Schergrat
-- RequestItems, OfferReward -- master, 3.3.5

-- 9794 - Keine Zeit für Neugier
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9794 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9794, "deDE", "<Kialon schaut Euch misstrauisch an.>$B$BIch kenne Euch nicht, $R. Was wollt Ihr von mir?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9794 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9794, "deDE", "Ihr bringt mir also Timothys Antwort?$B$B<Kialon hält einen Moment inne, um den Brief zu lesen, und fängt an zu lachen.>$B$BEr hat alles unter Kontrolle, sagt er, braucht keine Hilfe. Ich hätte es wissen müssen!$B$BManche Leute ändern sich nie. Schaut, er hat sich sogar die Zeit genommen, meine Rechtschreibfehler zu korrigieren.$B$B<Kialon seufzt halbherzig.>$B$BIch hätte ihm den Brief nicht schicken sollen. Ich habe es vergessen. Der Spezialist hat die Situation immer unter Kontrolle. Immer.", 26972);

-- 9795 - Die Ogerbedrohung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9795 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9795, "deDE", "Denjai braucht Hilfe? Ich würde ihm gerne ein paar Leute schicken, aber wir können uns selbst kaum halten. Wir haben hier oben unsere eigenen Probleme mit den Ogern.$B$BSobald ich kann, werde ich ihm alle Informationen, die wir über diesen Ogerstamm und seine Taktiken haben, zukommen lassen. Wenn er lang genug durchhält, können wir die widerlichen Kreaturen vielleicht von zwei Seiten aus angreifen.", 26972);

-- 10455 - Die nahende Wildnis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10455 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10455, "deDE", "Das ging schnell. Seid Ihr sicher, dass Ihr so viele getötet habt, wie es nötig war?$B$BGut, dann könnt Ihr uns bei einer weiteren Angelegenheit helfen, wenn Ihr möchtet.", 26972);

-- 10456 - Marodierende Wölfe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10456 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10456, "deDE", "Ich kann nicht deutlich genug sagen, dass diese Terrorwölfe der Donnerfürsten erledigt werden müssen. Ihre bloße Anwesenheit stört das Gleichgewicht des Lebenden Hains und all unsere Arbeit hier.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10456 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10456, "deDE", "Gut. Ich werde schauen, ob ich aus diesen Schwänzen etwas Nützliches machen kann.$B$BDie Horde wird ohne Zweifel einen Weg finden, Ihr Wolfsrudel wieder zu vergrößern, aber nun können wir etwas freier durchatmen.$B$B$N, wenn Ihr dazu bereit seid, habe ich eine letzte Bitte an Euch, um Sylvanaar und den Lebenden Hain zu verteidigen.", 26972);

-- 10457 - Die Eigenen schützen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10457 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10457, "deDE", "Wie geht es mit der Verstärkung der Verteidigung des Lebenden Hains voran?$B$BSolange wir nicht wissen, was die Arakkoa im Lashhversteck vorhaben und die Horde sich auf der anderen Seite der Klamm befindet, habe ich Angst, dass wir unser neues Heim und unsere Arbeit nicht mehr verteidigen können, wenn wir nicht bald handeln.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10457 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10457, "deDE", "Nun, da Ihr die Verteidigung des Hains verstärkt habt, fühle ich mich viel sicherer.$B$BIhr habt Euch mehr als nur unseren Dank und unsere Wertschätzung verdient.$B$BMir fällt gerade ein, dass es da noch etwas gibt, bei dem ich Eure Hilfe brauchen könnte.", 26972);

-- 10486 - Die nahende Wildnis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10486 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10486, "deDE", "Das ging schnell. Seid Ihr sicher, dass Ihr so viele getötet habt, wie nötig war?$B$BGut. Es gibt noch eine weitere Aufgabe, bei der wir Eure Hilfe benötigen. Eine weitaus wichtigere.", 26972);

-- 10487 - Drachenstaub
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10487 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10487, "deDE", "Es sieht aus, als hätte die Allianz vor, uns überallhin zu folgen. Wir wollen ihnen beweisen, dass ihre Anwesenheit uns keineswegs einschüchtert.$B$BHabt Ihr besorgt, worum ich Euch gebeten habe?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10487 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10487, "deDE", "Ihr habt nicht nur ihre Verteidigung geschwächt. Mit dem Staub werden wir dazu noch unsere eigene Verteidigung gegen die Allianz stärken können.", 26972);

-- 10488 - Die Eigenen schützen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10488 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10488, "deDE", "Wie geht es mit der Verstärkung unserer Terrorwolfverteidigung voran?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10488 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10488, "deDE", "Nun, da Ihr die Wölfe und unsere Verteidigung gestärkt habt, können wir uns wieder einigen tödlicheren Angelegenheiten, wie zum Beispiel den Ogern, zuwenden.$B$BIhr habt uns hier gut geholfen. Wenn Ihr Euch entscheidet zu bleiben, könnten wir auch weiterhin die Dienste von jemandem, der so fähig ist wie Ihr, brauchen.$B$BWie auch immer Ihr Euch entscheiden mögt, Ihr habt meinen Respekt und meine Wertschätzung sicher.", 26972);

-- 10489 - Einen uralten Baum fällen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10489 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10489, "deDE", "Was habt Ihr da? Ihr seid aber stark!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10489 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10489, "deDE", "Starkast Tiefwurz' Stumpf! Habt Ihr ihn selbst gefällt?$B$BSicher habt Ihr das. Wisst Ihr, ein starker $C wie Ihr es seid, ist genau die Hilfe, nach der Rexxar und ich gesucht haben. Besonders bei den ständigen Problemen, die wir mit den Ogern haben, könnten wir Euch brauchen. Setzt Euch mit mir in Verbindung, wenn Ihr Interesse habt.$B$BNun, dieser Stumpf ist ein stichhaltiger Beweis. Ihr seid hier, um das Kopfgeld einzustreichen, nicht um mit mir zu plaudern. Wohlan, sucht Euch etwas aus.", 26972);

-- 10502 - Die Oger der Blutschläger
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10502 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10502, "deDE", "Das ist ein guter Anfang, um Sylvanaar und den Hain zu schützen.$B$BJetzt, da die Oger nicht mehr ganz so zahlreich sind, überlegen die Blutschläger es sich sicher zweimal, bevor sie uns hier angreifen.$B$BWenn das doch nur der einzige Ogerstamm wäre, mit dem wir Probleme hätten.", 26972);

-- 10503 - Die Speerspießerbedrohung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10503 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10503, "deDE", "Das ist ein guter Anfang, um unsere Position hier gegen die Oger zu verteidigen.$B$BJetzt, da die Oger nicht mehr ganz so zahlreich sind, überlegen die Speerspießer es sich sicher zweimal, bevor sie versuchen, die Donnerfeste zurück zu erobern.$B$BWenn das doch nur der einzige Ogerstamm wäre, mit dem wir Probleme hätten.", 26972);

-- 10504 - Die Oger der Speerspießer
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10504 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10504, "deDE", "Eure Taten gegen die Blutschläger und Speerspießer sind ein großer Schritt nach vorne für die Sicherung der Zukunft Sylvanaars. Als wir hier ankamen, fanden wir diesen Flecken Land unbewohnt. Wir haben kein Interesse daran, uns noch weiter auszubreiten, aber wir werden auch nicht dulden, dass man uns vertreibt.$B$BDa Ihr uns gute Dienste geleistet habt, möchte ich Euch mit der Wertschätzung der Allianz belohnen.", 26972);

-- 10505 - Die Oger der Blutschläger
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10505 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10505, "deDE", "Eure Taten gegen die Blutschläger und Speerspießer sind ein großer Schritt nach vorne für die Sicherung der Zukunft der Donnerfeste. Wir werden nicht dulden, dass sich jemand unserem Schicksal in den Weg stellt.$B$BDa Ihr uns gute Dienste geleistet habt, möchte ich Euch mit der Wertschätzung der Horde belohnen.", 26972);

-- 10506 - Eine düstere Lage
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10506 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10506, "deDE", "Hattet Ihr Glück da draußen? Ich weiß, dass es wegen der Oger der Blutschläger sehr gefährlich ist, aber wenn wir es vermeiden können, die Tiere zu töten, bin ich sehr froh.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10506 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10506, "deDE", "Ich bin froh zu hören, dass es geklappt hat. Je weniger Wesen der Natur sterben müssen, desto besser.$B$BIch muss sagen, dass ich Euch nach all dem, was Ihr für uns getan habt, ins Herz geschlossen habe.$B$BGebt auf Euch Acht, $N.", 26972);

-- 10510 - In die Draenethystmine
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10510 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10510, "deDE", "Ist das nicht aufregend? Nach dem ganzen Dreck und den Insekten in Silithus ist dieser Ort hier ein wahres Paradies!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10510 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10510, "deDE", "Ooh, so wie sie aussehen, handelt es sich hierbei um ganz tolle Exemplare! Ich kann es kaum abwarten, sie mit meinen Untersuchungsgeräten genau unter die Lupe zu nehmen!$B$BVielen Dank!", 26972);

-- 10511 - Merkwürdiges Gebräu
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10511 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10511, "deDE", "Ziemlich trocken hier. Wie soll ich denn meinen Urlaub ohne etwas zu Trinken genießen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10511 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10511, "deDE", "Was riecht hier so? Oh nein, bitte sagt mir nicht, dass dies das Ogergebräu ist?$B$BIch habe fast schon Angst, es zu probieren. Ach zur Hölle, was soll's? Hoch die Tassen!", 26972);

-- 10512 - Die Speerspießer abfüllen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10512 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10512, "deDE", "Wie sieht es aus? Sind die Speerspießer so anspruchslos wie die Blutschläger oder sind sie auch fast dabei umgekommen wie ich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10512 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10512, "deDE", "Ah, hahaha! Das habe ich mir gedacht. Oger trinken wahrscheinlich alles.$B$BWas für ein dummer Haufen!$B$BAuch wenn ich mein Gebräu nicht bekommen habe, habt Ihr mir doch einen guten Start in den Urlaub bereitet.$B$BIch sage Euch was... wir haben hier allen möglichen Kram, den wir nicht wirklich brauchen. Kann ich Euch etwas davon anbieten?", 26972);

-- 10516 - Die Gefangenschaft der Verteidigerin
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10516 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10516, "deDE", "$C, habt Ihr mein Schwert und meinen Schild?$B$BIch kann zwar jederzeit hier raus, aber es wäre mir sehr peinlich, wenn ich ohne meine Ausrüstung nach Sylvanaar zurückkehren müsste.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10516 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10516, "deDE", "Ich stehe tief in Eurer Schuld, denn Ihr habt mir meine Ehre wiedergegeben. Aber unsere Arbeit hier ist noch nicht vorüber.", 26972);

-- 10517 - Eure Zeit ist gekommen, Gorr'Dim...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10517 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10517, "deDE", "Sehr gut. Ihr seid ein sehr gewitzter $C, so viel ist sicher.$B$BIch frage mich, ob Ihr wohl noch eine Sache für mich und Sylvanaar tun könntet.", 26972);

-- 10518 - Das Banner aufstellen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10518 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10518, "deDE", "Was führt Euch zu mir? Es gibt doch nicht etwa Ärger mit den Blutschlägern?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10518 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10518, "deDE", "Gurn Grubnoshs Helm und ein Banner der Speerspießer?$B$BEin ziemlich gewitzter Plan von der Verteidigerin und Euch.$B$BWenn die Blutschläger weiter mit den Speerspießern beschäftigt sind, nimmt uns das viel von dem Druck, unter dem wir hier in letzter Zeit leiden.$B$BBitte, $N, nehmt dieses bescheidene Geschenk von Sylvanaar an.", 26972);

-- 10524 - Artefakte der Donnerfürsten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10524 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10524, "deDE", "Kenne ich Euch?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10524 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10524, "deDE", "Ich kann meinen Augen nicht trauen! Wenn das ein Scherz sein soll, ziehe ich Euch die Haut vom Leibe, $C!$B$BSchnell, lasst mich diese unschätzbaren Artefakte untersuchen, bevor Ihr sie noch mit Euren zwei linken Händen zerbrecht.", 26972);

-- 10525 - Wegweisende Visionen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10525 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10525, "deDE", "Was habt Ihr gesehen? Sagt es mir! Ich muss wissen, wo es ist!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10525 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10525, "deDE", "In der Draenethystmine? Die Blutschläger müssen es von dem Speerspießern gestohlen haben.$B$BPah! Das ist zu weit weg... zu tief im Blutschlägergebiet, als dass ich dorthin reisen könnte.$B$BAber Ihr! Ihr kennt den Weg. Ihr sollt an meiner statt dorthin gehen.", 26972);

-- 10526 - Die Donnerlanze
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10526 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10526, "deDE", "Ihr könnt sicher nicht verstehen, wie wichtig diese Artefakte sind.$B$BWenn ich alle fünf beisammen habe, werde ich ein Ritual durchführen, das unser Besitzrecht an der Donnerfeste durch die Besänftigung der toten Geister festigen wird.$B$BVersteht Ihr nun, was daran so wichtig ist? Versteht Ihr nun, warum ich keine Zeit für Geplänkel habe?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10526 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10526, "deDE", "Ich bin beeindruckt. Könnt Ihr Euch überhaupt vorstellen, wie viele zuvor bei dem Versuch, die Relikte zu bergen, gestorben sind?$B$BWir können uns glücklich schätzen, dass Ihr hier mit uns zusammenarbeitet, $N. Auch wenn Ihr etwas langsam seid.$B$BErlaubt mir, Eure Aufopferung für unsere Sache zu belohnen. Wählt, aber wählt weise. Wenn Ihr fertig seid, werde ich die Geister der Donnerfeste besänftigen.", 26972);

-- 10542 - Die ham meine Pfeife und mein Gesöff geklaut!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10542 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10542, "deDE", "He, habt Ihr meine Wasserpfeife und das Gebräu schon?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10542 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10542, "deDE", "Ja, genau davon hat T'chali geredet! Ist sich nicht ganz sicher, was die Oger da reingetan ham. Die Pfeife riecht nicht nach T'chalis Tabak.$B$BEgal, T'chali ist glücklich. Sogar so glücklich, dass er Euch um einen weiteren Gefallen bitten will.", 26972);

-- 10543 - Grimnok und Korgaah, ich komm' Euch holen!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10543 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10543, "deDE", "T'chali ist zufrieden, dass Korgaah und Grimnok Schlachttaufe jetzt auch die Radieschen von unten anschauen.$B$BAber T'chalis Rachedurst ist noch nicht gestillt. Ihr müsst noch etwas anders machen!", 26972);

-- 10544 - Verflucht seien Eure beiden Klans!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10544 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10544, "deDE", "T'chali will nicht mehr sprechen, bis $N den Fetisch benutzt hat, um die Häuser der Speerspießer und der Blutschläger zu verfluchen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10544 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10544, "deDE", "Hahaha, Rache ist süss!$B$BAber T'chali sieht, dass Ihr nun, da meine Rache verübt wurde, gerne weiterziehen wollt. Ich versteh' schon, Kumpel... lassen wir das Leben den Lebenden.$B$BIch sag' Euch was, T'chali hat hier immer noch ein paar Sahnestückchen in seinem Grab. Sucht Euch aus, was Euch am besten gefällt!", 26972);

-- 10545 - Saufgelage der Speerspießer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10545 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10545, "deDE", "Sagt es T'chali... hat das Gebräu funktioniert? Haben die Speerspießer es gemocht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10545 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10545, "deDE", "Das sind gute Nachrichten! Das Gebräu wird bei der nächsten Aufgabe, die T'chali für Euch hat, nützlich sein.", 26972);

-- 10555 - Fauler Zauber
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10555 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10555, "deDE", "Die groben Piktogramme in dem uralten Folianten weisen darauf hin, dass eine große Menge von Federn der Lashh'an benötigt wird, um die Sprüche in dem Buch zu wirken.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10555 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10555, "deDE", "Ihr blättert die Seiten voll gekritzelter Notizen in der dünnen Schrift der Arakkoa der Lashh'an durch und findet ein Piktogramm, das die Kreise der Macht, die Ihr im Lashhversteck gesehen habt, darstellt.", 26972);

-- 10556 - Gekritzel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10556 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10556, "deDE", "Das ist so aufregend! Ich kann es kaum abwarten, die Wirkung des Zaubers zu untersuchen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10556 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10556, "deDE", "Ich weiß nicht, was ich sagen soll. Dieser Zauber ist sehr merkwürdig. Es handelt sich nicht um eine einfache Beschwörung oder Verzauberung, sondern eher um eine Art Vereinigungs- oder Kommunikationszauber.$B$BIch weiß nicht, was ich davon halten soll, $N. Ich muss noch ein wenig darüber nachdenken.$B$BAber trotzdem vielen Dank für Eure Hilfe! Ich bin sicher, dass ich früher oder später dahinter komme.", 26972);

-- 10557 - Testflug: Das Zephyriumkapazitorium
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10557 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10557, "deDE", "Wow, Ihr habt es geschafft! Und kein einziger blauer Fleck oder offener Knochenbruch! Seht Ihr, ich habe Euch doch gesagt, dass alles funktionieren wird!$B$BHier ist Eure Bezahlung, $N. Ich habe die Arztkosten gleich dazu gerechnet, aber da Ihr sie nicht gebraucht habt, seht es einfach als kleinen Bonus an!", 26972);

-- 10565 - Die Steine der Vekh'nir
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10565 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10565, "deDE", "Die Arakkoa der Vekh'nir waren viele Jahre lang gütige Wesen., doch nun hat sie etwas aufgehetzt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10565 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10565, "deDE", "Ah, schaut nur, wie er leuchtet! Ich muss ihn sofort ausprobieren.", 26972);

-- 10566 - Probieren geht über Studieren
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10566 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10566, "deDE", "Diese Informationen werden uns sehr viel weiterhelfen, $N. Ich werde den Zauberstab noch verbessern und schauen, ob wir ihn auch für weitere Zwecke einsetzen können.", 26972);

-- 10567 - Die Herstellung des Anhängers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10567 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10567, "deDE", "Sobald der Herold bemerkt, dass Ihr seine Brut angreift, wird er sicher schnell reagieren.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10567 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10567, "deDE", "Ihr habt ihn!$B$BMit diesem Anhänger werde ich dafür sorgen können, dass Ihr die Sprache der Arakkoa aus Grishnath versteht.$B$BHiermit werden wir die Arakkoa und das Wesen des Raben besser verstehen lernen. Ich brauche dazu Eure Hilfe.", 26972);

-- 10580 - Wo sind diese verdammten Gnome hin?
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10580 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10580, "deDE", "SYLVANAAR? KOMMANDANT HIMMELSSCHATTEN?$B$BKEIN DATENBANKEINTRAG!$B$BTRETET ZURÜCK, BEVOR ICH MICH GEZWUNGEN SEHE, EUCH MIT LAUTEN GERÄUSCHEN ZU QUÄLEN!", 26972);

-- 10581 - Folget den Brotkrumen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10581 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10581, "deDE", "In Ordnung, wollt Ihr Euch nützlich machen? Gut, ich habe genau die richtige Aufgabe, mit der Ihr Euch beweisen könnt.$B$BIch glaube, Ihr werdet sie mögen.", 26972);

-- 10584 - Ein paar Stromwandler besorgen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10584 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10584, "deDE", "Diese Forschungsreihe mit den Elektromentaren ist faszinierend! Stellt Euch nur vor... Eine intelligente Kreatur, die wir nach Belieben erschaffen können und die all unseren Anweisungen folgt!$B$BWas kann da schon schiefgehen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10584 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10584, "deDE", "Ausgezeichnet! Mit der ganzen Energie, die Ihr gesammelt habt, werden wir die Maschinerien für eine Weile am Laufen halten können.$B$BDas Zephyriumkapazitorium ist ein echter Schluckspecht, wenn es um den Energieverbrauch geht!$B$BIch hoffe, mit den Elektromentaren fertigzuwerden war nicht allzu schwierig. Ich habe noch eine andere Aufgabe für Euch. Ich fürchte, sie wird etwas schwerer werden.", 26972);

-- 10594 - Die Klangfrequenz messen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10594 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10594, "deDE", "Nun, habt Ihr die Messungen der singenden Kristalle, um die ich Euch gebeten habe?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10594 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10594, "deDE", "Oh, das ist außergewöhnlich! Ich hatte ja keine Ahnung... Es ist fast so, als wären die Kristalle lebendig!$B$BIch frage mich, ob eine Art symbiotische Beziehung zwischen ihnen und den Netherdrachen besteht.$B$BVielen Dank, vielen Dank! Ihr müsst etwas aus meiner Kuriositätensammlung nehmen, das ich nichtmal im Tode anziehen würde!$B$BAn Euch könnte etwas davon jedoch gut aussehen.", 26972);

-- 10607 - Das Flüstern des Rabengottes
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10607 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10607, "deDE", "Das ist wirklich beunruhigend. Die Arakkoa waren lange ein friedliebendes Volk. Dieser Rabenkult ist nichts als eine Versammlung von Außenseitern und Verrückten.$B$BAber wir können nicht leugnen, dass ihre Macht wächst. Vielleicht steckt hinter diesem Raben mehr, als wir vermuten.", 26972);

-- 10608 - Kristallklar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10608 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10608, "deDE", "Ein Glück, dass ich sie los bin! Verdammte Biester!$B$BWenn Ihr sicher seid, dass Ihr diese Nervensägen ausgelöscht habt, habe ich ein kleines Forschungsprojekt für Euch. Ihr werdet es sicher mögen.", 26972);

-- 10609 - Was war zuerst da, der Drache oder das Ei?
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10609 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10609, "deDE", "Habt Ihr sie? Habt Ihr die Drachenessenzen, die ich so dringend brauche, um meine Experimente weiter zu führen?$B$BWusstet Ihr, dass diese Nethergroßdracheneier einmal Schwarzdracheneier waren? Es ist wahr! Aber als Draenor in tausend Stücke gesprengt wurde, waren die Eier dem Wirbelnden Nether ausgesetzt und sind mutiert.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10609 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10609, "deDE", "Ihr habt ja keine Ahnung, wie wichtig diese Experimente sein werden. Vielen Dank!$B$BEs wird aufregend werden, sich mit diesen Essenzen zu befassen. Ich bin besonders gespannt, ob der Nether, der die schwarzen Dracheneier zu Netherdracheneiern verwandelt hat vielleicht ein besonderer Segen für meine Studien ist.$B$BDa fällt mir gerade ein, dass Ihr die erste Person sein solltet, die die Vorzüge meines kleinen Gebräus genießen sollte. Hier, nehmt diese Proben und benutzt sie, wenn Ihr sie braucht.", 26972);

-- 10614 - Das Flüstern im Wind
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10614 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10614, "deDE", "Was führt Euch in unser Dorf?", 26972);

-- 10615 - Der Ruuanwald
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10615 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10615, "deDE", "Ah, ja, Dertrok. Wir haben kurz über die Arakkoa gesprochen. Ich muss allerdings zugeben, dass unsere... Interessen was sie betrifft deutlich auseinander gehen.", 26972);

-- 10617 - Seidenflügelkokons
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10617 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10617, "deDE", "Für die Ernte braucht man eine schnelle und ruhige Hand. Ich hoffe, Ihr habt Erfolg.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10617 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10617, "deDE", "Diese Kokons sind von guter Qualität. Wie ich sehe, habt Ihr die Ernte im Griff.$B$BWir haben versucht, unsere eigenen Seidenflügellarven zu züchten, aber leider produzieren die kleineren nicht genug Seide, um unseren Bedarf zu decken.", 26972);

-- 10618 - Die weichsten Flügel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10618 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10618, "deDE", "Die Flügel sind sehr zerbrechlich, können aber in vielen unserer Kunstgegenstände als Dekoration dienen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10618 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10618, "deDE", "Vielen Dank, $N. Wir werden sie schon früher benutzen, als Ihr Euch vorstellen könnt.", 26972);

-- 10620 - Gratwirbelbedrohung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10620 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10620, "deDE", "Ziemlich gut für einen Grünschnabel. Es scheint, als gäbe es eine kleine Gruppe von Eierköpfen, die unbedingt die Astralen und ihre Technologie im Norden 'beobachten' möchten. Sie werden sich riesig freuen, dass Ihr ihnen den Weg freigeräumt habt.$B$BHier, nehmt ein paar hiervon. Wir haben nicht viele, aber vielleicht können sie Euch in der Zukunft nützlich sein.", 26972);

-- 10632 - Zähne zeigen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10632 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10632, "deDE", "Wie geht es mit dem Sammeln der Zähne voran?$B$BIch bin davon überzeugt, dass Ihr Eure Arbeit für uns gut machen werdet. Und während Ihr das tut, werden wir diesen Außenposten hier sichern.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10632 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10632, "deDE", "Gute Arbeit, Junge. Der Schmerz ist gerechtfertigt, wenn auch nur einem meiner Soldaten durch Eure Bemühungen das Leben gerettet wird.$B$BIch bin der Meinung, dass auch Ihr von Eurem Blut und Euren Tränen profitieren solltet. Wir werden bald neue Waffen bekommen. Warum nehmt Ihr daher nicht einfach eine von meinen?", 26972);

-- 10657 - Lasst sie abblitzen!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10657 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10657, "deDE", "Der Trick dabei ist, die repolarisierte Magnetsphäre rechtzeitig abzuschalten, bevor Ihr gegrillt werdet.$B$BNatürlich müsst Ihr Euch dabei gut überlegen, wie vielen Schlangen Ihr gleichzeitig gegenübersteht.$B$BWo wir gerade davon sprechen, habt Ihr die Sphäre schon aufgeladen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10657 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10657, "deDE", "Jippieh, es hat geklappt! Ich war mir da ehrlich gesagt nicht so sicher... Ich habe eine Wahrscheinlichkeit von 23,72 Prozent berechnet, dass Ihr beim dritten Treffer implodiert.$B$B<Toshley grinst unschuldig.>$B$BJetzt wissen wir also, dass die Sphäre funktioniert. Es sollte also keine weiteren Probleme geben, den nötigen Saft für unser Zephyriumkapazitorium zu beschaffen. Natürlich nur, wenn ich noch mehr Freiwillige finde, die für mich dort hinaus gehen und sich brutzeln lassen.$B$BAber Ihr habt den Pionier für unsere Bemühungen gespielt und verdient eine Belohnung!", 26972);

-- 10671 - Ein Pfund Geschnetzeltes
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10671 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10671, "deDE", "Habt Ihr mein Geschnetzeltes schon? Wie, das findet Ihr nicht lustig?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10671 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10671, "deDE", "Das sollte genügen. Es stinkt fürchterlich, oder?$B$BIch hoffe, dass es Eure Mühen wert war... Ich bin nur froh, dass ich das Zeug nicht selber sammeln musste!", 26972);

-- 10674 - Das Licht der Phantasie einfangen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10674 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10674, "deDE", "Ich nehme an, dass Ihr die Lichtkugeln bei Razaans Landung schon besorgt habt, wenn Ihr Zeit habt, hier mit mir zu plaudern. Ich würde sie wirklich gerne untersuchen und herausfinden, was die Astralen damit vorhaben.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10674 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10674, "deDE", "He! Wartet mal!!$B$BDas sieht nicht gut aus...", 26972);

-- 10675 - Ein Gnom kennt kein Erbarmen!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10675 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10675, "deDE", "Habt Ihr diesen Dreckskerl Razaan schon erledigt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10675 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10675, "deDE", "Das geschieht ihm ganz Recht! Vielen Dank, dass Ihr dieser makaberen Mischung aus Magie und Technologie ein Ende bereitet habt.$B$BAls wahrer Held der Gnome überall auf dieser Welt, lasse ich Euch nun die höchste unserer Ehren zukommen... ein paar Stromwandler und Eure Wahl aus diesen Dingen hier!$B$BIch weiß, dass Ihr sie gut einsetzen werdet!", 26972);

-- 10682 - Zeit zu verhandeln...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10682 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10682, "deDE", "WAS?! Sie haben Euch fortgeschickt und unser Angebot ausgeschlagen?$B$BDas ist empörend! Wir sind in Frieden zu ihnen gekommen und sie schicken Euch weg, ohne auch nur zu versuchen, einen Kompromiss zu finden?$B$BNun, das wird Folgen haben!", 26972);

-- 10690 - Die Höhlenmutter
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10690 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10690, "deDE", "Unglaublich. Habt Ihr Rema ganz alleine getötet?$B$BSo wie Ihr ausseht, glaube ich das. Wisst Ihr, wir sind auf der Suche nach einem starken $C wie Ihr es seid, um uns hier ein wenig zu helfen. Besonders bei den ständigen Problemen, die wir mit den Ogern haben, könnten wir Euch brauchen. Setzt Euch mit mir in Verbindung, wenn Ihr Interesse habt.$B$BDas Kopfgeld, das auf dem Anschlag versprochen wurde, habt Ihr Euch jedenfalls verdient.$B$BBitte, wählt Euch etwas aus!", 26972);

-- 10709 - Zusammenführung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10709 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10709, "deDE", "Mein Vater ist also tatsächlich am Leben. Ich habe nicht erwartet, dass er mir verzeiht. Das war noch nie seine Art. Aber ich hatte gehofft, dass seine Wut über meine Abreise über die Jahre schwächer geworden ist.$B$BVor dreißig Jahren habe ich die Mok'Nathal verlassen, um der Horde nach Azeroth zu folgen. Leoroxx war strikt dagegen, gab mir aber auch keinen Grund zu bleiben. Und doch hätte ich mir ein herzlicheres Willkommen gewünscht.$B$BEr wollte einen Mok'Nathal als Sohn haben und hat immer noch einen, auch wenn er nichts davon wissen möchte.$B$BIch werde ihm die Augen öffnen.", 26972);

-- 10710 - Testflug: Der Singende Bergrücken
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10710 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10710, "deDE", "Wow! Ihr habt schon wieder überlebt! Ich bin ein besserer Ingenieur, als ich immer dachte!$B$BHier ist Eure Bezahlung! Und schaut doch später nochmal bei mir vorbei... Ich habe noch mehr Experimente, für die ich Versuchspersonen brauche!", 26972);

-- 10711 - Testflug: Razaans Landeplatz
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10711 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10711, "deDE", "Oh, beeindruckend! So schnell schon zurück! Ich habe gesehen, wie Ihr abgehoben habt und wie eine Rakete in die Luft geschossen seid! Ich dachte, es würde mindestens einen Monat Genesung brauchen, bis Eure gebrochenen Beine wieder geheilt sind! Ihr seid hart im Nehmen, mutig und kühn! Aber vor allem... mutig!", 26972);

-- 10712 - Testflug: Ruuanwald
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10712 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10712, "deDE", "Hallo hallo! Mein Klo... äh... mein Vetter Tally hat mir gesagt, dass Ihr vorbeikommen würdet. Habt Ihr etwas für mich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10712 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10712, "deDE", "Oh, Ihr habt Aufzeichnungen mit der Netherwetterfahne gemacht? Ausgezeichnet! Die Daten dieses Instruments werden zusammen mit meinen Messungen druidischer Magie sicher viele Früchte tragen!$B$BOh, die Einsatzmöglichkeiten werden Euch um den Verstand bringen!", 26972);

-- 10713 - ...und Zeit zu Handeln
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10713 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10713, "deDE", "Danke, $N.$B$BWir werden uns darum kümmern, dass die Wildtiere sich selbst wieder schnell vermehren. Bei den Bäumen ist dies jedoch ein sehr viel zeitaufwändigerer Prozess.", 26972);

-- 10714 - Auf geisterhaften Schwingen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10714 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10714, "deDE", "Was habt Ihr erfahren, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10714 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10714, "deDE", "<Geisterschwinge lässt sich auf Rexxars Schulter nieder, während Rexxar aufmerksam zuhört.>$B$BDie Söhne des Gruul stecken also hinter den Handlungen der Oger. Sie befehlen den Ogern der Blutschlägern, die Mok'Nathal zu vernichten, um ihre Gunst zu erlangen.", 26972);

-- 10715 - In die Grabenschlucht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10715 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10715, "deDE", "Habt Ihr die Giftdrüsen? Wenn nicht, dann hinfort mit Euch und wagt nicht, meine Zeit zu verschwenden, bevor Ihr sie habt!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10715 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10715, "deDE", "Sehr gut, Ihr habt eine einfache, wenn nicht gar banale Aufgabe erfüllt. Nun gebt mir die Drüsen, damit ich den schwierigen Teil erledigen kann.", 26972);

-- 10717 - Wilderer wildern
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10717 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10717, "deDE", "Wie geht es mit der Beschaffung der Netze voran? Meiner Einschätzung nach sind diese Netze der Wilderer stark genug, um unserer Sache dienlich zu sein.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10717 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10717, "deDE", "Oh, die sehen hervorragend aus. Diese Kultisten wissen wirklich, was wahre Handwerkskunst ist.$B$BZu schade, dass sie sie missbrauchen.$B$BJetzt, da wir die Netze haben, bräuchte ich Eure Hilfe bei ein oder zwei Angelegenheiten. Habt Ihr Lust?", 26972);

-- 10718 - Die Stimme der Geister
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10718 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10718, "deDE", "Wovon redet Ihr?$B$BGarm Wolfsbruder? Er war der letzte Häuptling der Donnerfürsten. Wenn Ihr mit seinem Geist gesprochen habt, muss es wahr sein.", 26972);

-- 10719 - Ihr seid eingeladen!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10719 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10719, "deDE", "Was habt Ihr da? Ist da ein Blutfleck auf der Einladung?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10719 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10719, "deDE", "Das ist interessant, aber auch beunruhigend. Vielleicht sollten wir Samia fragen, wer dieser Kolphis Dunkelschuppe ist?", 26972);

-- 10720 - Die kleinsten Wesen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10720 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10720, "deDE", "Ist es vollbracht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10720 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10720, "deDE", "Viele Jahre lang habe ich versucht, die Kommunikation mit der Natur zu perfektionieren. Dies ist nur ein Bruchteil dessen, was die Tiere für Euch tun können.", 26972);

-- 10721 - Grulloc einen Eber aufbinden
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10721 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10721, "deDE", "So schnell schon zurück? Seid Ihr hier, um Rexxars Schulden zurückzuzahlen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10721 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10721, "deDE", "<Baron Zobelmähne lugt in den Sack des Gronns und scheint zufrieden.>$B$BSehr gut, Ihr habt Euren Teil der Abmachung gehalten. Nun, da der Preis bezahlt ist, werde ich Rexxar geben, was er begehrt.", 26972);

-- 10722 - Treffen am Pechschwingenkoven
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10722 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10722, "deDE", "Uns angreifen? Uns auslöschen? Das glaube ich aber nicht!$B$BDieser Pechschwingenkoven muss noch viel lernen, wenn sie denken, dass man die Expedition des Cenarius so leicht loswerden kann!$B$BWie sagt man so schön? Wie du mir, so ich dir!", 26972);

-- 10723 - Gorgrom der Drachenfresser
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10723 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10723, "deDE", "Die Oger der Blutschläger werden uns nie mehr belästigen, wenn Ihr Eure Aufgabe erfüllt habt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10723 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10723, "deDE", "Die Oger der Blutschläger und ihr Meister, Gorgrom, werden die Mok'Nathal nie wieder belästigen.$B$BIch mache mir jedoch Sorgen über die Auswirkungen unserer Tat auf die anderen Gronn. Ich glaube, wir müssen diesem Kampf ein für alle Mal ein Ende setzen.", 26972);

-- 10724 - Gefangener der Speerspießer
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10724 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10724, "deDE", "Leokk hat uns den Kopf eines schwarzen Drachen von Drachenend gebracht, damit können wir Goc, den Gronn, der ihn gefangen genommen hat, erzürnen und ihn in die Schlacht locken.", 26972);

-- 10742 - Finale
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10742 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10742, "deDE", "Nur wenn Goc und Gorgrom der Drachenfresser tot sind, werden die Mok'Nathal frei sein.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10742 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10742, "deDE", "Der Kampf war hart und Ihr habt Euch gut geschlagen, $N. Ich bin stolz, dass ich in der Schlacht gegen Goc an Eurer Seite kämpfen durfte.$B$BDie Mok'Nathal sollten von diesen großartigen Siegen erfahren, aber ich bin noch nicht bereit, ihnen gegenüberzutreten. Ich kenne meinen Vater und ich kenne mein Herz. Es gibt immer noch vieles, was ich lernen und tun kann, um stärker zu werden und ihm zu beweisen, dass ich sein wahrer Sohn bin.", 26972);

-- 10747 - Welpen des Wyrmkults
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10747 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10747, "deDE", "Hattet Ihr viel Ärger beim Versuch, die Welpen zu fangen? Ich hoffe, Ihr habt Euch nicht verbrannt!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10747 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10747, "deDE", "Ach herrje, das sind ja mehr, als ich gehofft hatte! Für Euren Heldenmut habt Ihr gewiss ein Lob verdient!$B$BDiese Welpenbrut sieht sehr gut aus. Sie sind wie gemacht für meine Untersuchungen.$B$BBitte, nehmt eine kleine Belohnung von mir an. Ich bestehe darauf!", 26972);

-- 10748 - Maxnar muss sterben!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10748 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10748, "deDE", "Jetzt, da der Anführer unserer Feinde tot ist, können wir endlich wieder ein wenig aufatmen. Und Ihr habt auch noch das gesamte Gebirge vor ihrer Verwüstung bewahrt.$B$BWas auch immer ihre endgültigen Pläne gewesen sein mögen, Ihr habt sie vereitelt!$B$BIhr habt unseren Dank, $N. Bitte nehmt dieses Zeichen unserer Wertschätzung sowie unsere ewig währende Gastfreundschaft.", 26972);

-- 10749 - Baron Zobelmähnes Gift
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10749 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10749, "deDE", "$C, so schnell schon zurück? Habt Ihr das Gift?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10749 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10749, "deDE", "Die Verwendung von Giften ist ein dreckiges Geschäft. Aber so werden wir unsere Ziele erreichen.", 26972);

-- 10753 - Die Verderbnis ausmerzen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10753 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10753, "deDE", "Es erfüllt mich nicht mit Stolz zu zerstören, was Elune erschaffen hat, aber die Verderbnis muss aufgehalten werden. Ihr habt Eure Arbeit gut gemacht, $C.", 26972);

-- 10770 - Kleine Funken
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10770 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10770, "deDE", "Es gibt so viele, dass wir sie nie alle töten können, aber Ihr habt mir Hoffnung gegeben. Vielleicht sollte ich noch ein paar Jahrhunderte lang stärker versuchen, meinen geliebten Wald wieder zum Leben zu erwecken.", 26972);

-- 10771 - Aus der Asche
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10771 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10771, "deDE", "Ist es vollbracht? Habt Ihr etwas Leben in mein altes Zuhause zurückgebracht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10771 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10771, "deDE", "Ihr habt viele dieser verderbten Kreaturen getötet. Mit dieser Gewissheit kann ich nun etwas ruhiger schlafen.", 26972);

-- 10783 - Baron Zobelmähne
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10783 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10783, "deDE", "Hallo, $R. Ich bin Baron Zobelmähne. Ein Freund Rexxars ist auch mein Freund.", 26972);

-- 10784 - Vernichtet das Lager der Blutschläger!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10784 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10784, "deDE", "<Tor'chunk nickt und scheint dabei sichtlich zufrieden mit Eurer mörderischen Kühnheit.>$B$BIhr erstaunt mich immer wieder, $N. Jedes Mal, wenn einer dieser stinkenden Oger zu Boden geht, sind wir einen Schritt näher daran, einen unwürdigen Feind loszuwerden.", 26972);

-- 10785 - Das ist eine Falle!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10785 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10785, "deDE", "Habt Ihr bekommen, was auch immer in diesem Sack des Gronns war? Habt Ihr es Zobelmähne gebracht? Hat er Euch etwas für mich mitgegeben?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10785 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10785, "deDE", "Hm, eine Falle, die aus der Essenz einer Drachenflamme gebaut wurde? Ich frage mich, wie Zobelmähne an eine so seltene Substanz gekommen ist!$B$BNun, ganz egal. Nicht egal ist allerdings, dass wir sie benutzen werden, um einen Sohn des Gruul zu töten!", 26972);

-- 10786 - Gemetzel in Fels'mok
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10786 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10786, "deDE", "<Tor'chunk grinst, als Ihr ihm von Euren Abenteuern in Fels'mok erzählt.>$B$BAch, ich wünschte, ich hätte mit Euch kommen können. Ich will Euch etwas sagen, $N, lasst Euch nie auf Pflichten ein, die Euch vom Ruhm der Schlacht fernhalten!$B$BHa! Habt Ihr mir überhaupt noch ein paar Oger in den Bergen übrig gelassen?", 26972);

-- 10795 - Ein Treffen mit Dorgok
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10795 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10795, "deDE", "Jetzt, da Dorgok tot ist, sind die Oger der Blutschläger ohne Anführer und hoffentlich verwirrt, bis ein neuer Anführer aus ihren Rängen gewählt wird.$B$BVielen Dank, $C. Ich glaube, wir können nun ein wenig aufatmen.", 26972);

-- 10796 - Vernichtet das Lager der Blutschläger!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10796 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10796, "deDE", "<Der Leutnant nickt und scheint mit Eurer mörderischen Kühnheit sichtlich zufrieden.>$B$BIch bin beeindruckt, $N. Euer Ruf scheint wohlverdient zu sein.$B$BJedes Mal, wenn einer dieser Oger zu Boden geht, sind wir einen Schritt näher daran, einen Feind loszuwerden, der uns niemals in Frieden lassen wird.", 26972);

-- 10797 - Die Gunst der Gronn
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10797 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10797, "deDE", "Hallo, Junge! Was gibt es Neues?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10797 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10797, "deDE", "Oh, das ist aber hübsch. Sieht ein bisschen aus wie diese Gronn, die die Oger der Speerspießer immer durch die Gegend scheuchen.$B$BKomisch, dass Ihr es in der Hand eines Anführers der Blutschläger gefunden habt.", 26972);

-- 10798 - Dem Baron einen Besuch abstatten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10798 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10798, "deDE", "Ah, ein Gesandter der gerühmten Allianz. Sagt mir, Lakai, warum seid Ihr es, der hierhergekommen ist und mich um dieses Ding bittet, und nicht Eurer illustrer Kommandant?$B$BKann es etwa sein, dass er Angst vor mir hat? Irgendetwas an Euch sagt mir, dass Ihr keine habt, aber ich weiß noch nicht, was das ist.", 26972);

-- 10799 - In die Grabenschlucht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10799 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10799, "deDE", "Habt Ihr die Giftdrüsen? Wenn nicht, dann hinfort mit Euch und wagt nicht, meine Zeit zu verschwenden, bevor Ihr sie habt!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10799 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10799, "deDE", "Sehr gut, Ihr habt eine einfache, wenn nicht gar banale Aufgabe erfüllt. Nun gebt mir die Drüsen, damit ich den schwierigen Teil erledigen kann.", 26972);

-- 10800 - Gute Nacht, Gronn
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10800 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10800, "deDE", "Ihr steht mir wieder gegenüber, $C. Das muss bedeuten, dass Ihr den Sack unter Grullocs Nase weggeschnappt habt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10800 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10800, "deDE", "<Baron Zobelmähne lugt in den Sack des Gronns und scheint zufrieden.>$B$BSehr gut, Ihr habt Euren Teil der Abmachung gehalten. Nun werde ich Euren Kommandanten mit der Falle beschenken.", 26972);

-- 10801 - Das ist eine Falle!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10801 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10801, "deDE", "Hat der Baron uns eine Falle gebaut? Eine, die stark genug ist, um einen Gronn zu töten?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10801 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10801, "deDE", "Hm, eine Falle, die aus der Essenz einer Drachenflamme gebaut wurde? Ich frage mich, wie Zobelmähne an eine so seltene Substanz gekommen ist!$B$BNun, ganz egal. Nicht egal ist allerdings, dass wir sie benutzen werden, um einen Sohn des Gruul zu töten!", 26972);

-- 10802 - Gorgrom der Drachenfresser
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10802 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10802, "deDE", "Wurde die Nachricht schon überbracht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10802 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10802, "deDE", "Gut gemacht, $N. Sehr gut gemacht!$B$BIch nehme an, dass wir nun nicht mehr von den Ogern und ihrem Herrn hören werden.", 26972);

-- 10803 - Gemetzel in Fels'mok
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10803 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10803, "deDE", "<Leutnant Schönwetter grinst, als Ihr ihr von Euren Abenteuern in Fels'mok erzählt.>$B$BAch, ich wünschte, ich hätte mit Euch kommen können. Ich will Euch etwas sagen, $N, lasst Euch nie auf Pflichten ein, die Euch vom Ruhm der Schlacht fernhalten!$B$BHa! Habt Ihr mir überhaupt noch ein paar Oger in den Bergen übrig gelassen?", 26972);

-- 10805 - Massaker in Gruuls Unterschlupf
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10805 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10805, "deDE", "Sehr gut. Ich habe eine weise Wahl getroffen, als ich Euch zur Speerspitze meines Kampfes gemacht habe. Ich schätze, es ist an der Zeit, die Dinge auf eine ganz neue Ebene zu tragen.$B$BErinnert Ihr Euch an den kleinen Leckerbissen, den Ihr Grolloc für mich unter der Nase weggeschnappt habt? Ihr werdet die Gelegenheit bekommen, ihn sinnvoll einzusetzen.", 26972);

-- 10806 - Finale
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10806 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10806, "deDE", "Bald werden alle Söhne des Gruul vernichtet sein.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10806 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10806, "deDE", "Für jemanden von Eurem Schlag habt Ihr erstaunlich gut gekämpft. Es war mir eine Ehre, Euch an meiner Seite zu wissen. Meine Verwandlung muss Euch wohl ein wenig überrascht haben. Ich hoffe, ich habe Euch nicht allzu sehr erschreckt.$B$BWir sollten meine wahre Identität jedoch für uns behalten. Als Belohnung für Eure treuen Dienste biete ich Euch eines dieser Schmuckstücke an.", 26972);

-- 10810 - Die beschädigte Maske
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10810 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10810, "deDE", "Geht mir nicht auf die Nerven! Könnt Ihr nicht sehen, dass ich dabei bin, mysteriöse Kräfte zu entfesseln?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10810 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10810, "deDE", "Ah, was habt Ihr denn da? Lasst mich das mal genauer ansehen, $C. Ja, ja... es ist genau das, was ich dachte. Lasst mich die Maske für Euch reparieren.", 26972);

-- 10812 - Die geheimnisvolle Maske
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10812 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10812, "deDE", "Ich traue meinen Augen nicht.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10812 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10812, "deDE", "Diese Maske, die Ihr da in den Händen haltet, ist eine Gasmaske der Teufelsbrut! Und wie es aussieht, ist sie nicht beschädigt! Der Ärger, den wir damit im Konstruktionslager: Groll anrichten können, ist grenzenlos! Habt Ihr Lust, uns dabei zu helfen?", 26972);

-- 10818 - Baron Zobelmähne verlangt nach Euch
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10818 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10818, "deDE", "Ah, wie ich sehe habt Ihr beschlossen, Euch ganz schön Zeit zu lassen, bis Ihr meinem Aufruf Folge geleistet habt.$B$BWie auch immer, ich hatte genug Zeit, um an meinen Racheplänen zu feilen, und Ihr sollt in der kommenden Schlacht mein Vollstrecker sein.", 26972);

-- 10819 - Die Gasmaske der Teufelsbrut
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10819 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10819, "deDE", "Was soll das bedeuten? Niemand ruft mich! Sprecht, oder ich werde Euch für immer zum Schweigen bringen!", 26972);

-- 10820 - Täuscht den Feind
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10820 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10820, "deDE", "Das wird ihnen sicher zeigen, dass sie besser tun sollten, was ich ihnen sage...$B$BÜbrigens... wo ist Schicksalsrufer? Warum habt Ihr mir von dieser Revolte berichtet und nicht sie?", 26972);

-- 10821 - Ihr seid gefeuert!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10821 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10821, "deDE", "Das sind wirklich großartige Nachrichten, $N. Ich hätte es mir nicht besser wünschen können. Eure Dienste gegenüber meinem Volk sind sehr geschätzt. Bitte wählt Euch einen dieser Gegenstände aus.$B$BEuer Name wird für immer in den Herzen unseres Volkes klingen.", 26972);

-- 10825 - Die kugellose Wahrheit
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10825 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10825, "deDE", "$C, könnt Ihr das spüren? Ich fühle, dass etwas Unnatürliches und Böses in der Nähe ist.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10825 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10825, "deDE", "Ja, es ist die Kugel, die Ihr da habt! Merkwürdig, sie scheint von den Arakkoa zu stammen. Wart Ihr kürzlich in Grishnath?$B$BAh, das erklärt das Ganze. Aber ich frage mich, welchem teuflischen Zweck dieses Objekt dient. Obwohl das Böse eindeutig darin schlummert, scheint sie doch mit der Natur verbunden zu sein.$B$BBitte erlaubt mir zu versuchen, sie zu aktivieren. Das Böse darin ist so stark, es erinnert mich an etwas...", 26972);

-- 10829 - Baumriese muss es wissen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10829 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10829, "deDE", "Grüße, kleiner $R. Die Vögel in meinen Zweigen haben mir zugeflüstert, dass Ihr kommen würdet.$B$BIhr seid hier, um die Bäume des Waldes von ihrer Besessenheit zu heilen?", 26972);

-- 10830 - Der Exorzismus der Bäume
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10830 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10830, "deDE", "Das Böse verschwindet aus dem Rabenwald! Könnt Ihr es fühlen, $N?$B$BIhr habt uns und alle Wildtiere hier vor der unweigerlichen Zerstörung gerettet, kleines Wesen!$B$BFür solche Gelegenheiten trage ich vier magische Ringe in meinen Zweigen und verschenke sie, wenn ein Held sich erhebt, um eine große Tat zu vollbringen.$B$BIhr seid solch ein Held! Im Namen des gesamten Rabenwaldes danke ich Euch.", 26972);

-- 10843 - Seit ich denken kann...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10843 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10843, "deDE", "<Leoroxx mustert Euch aufmerksam.>$B$BGnosh Brognats Tod ist ein Segen für alle Mok'Nathal. Das ist gut für Euch.$B$BMal schauen, ob Ihr immer noch so heldenhaft seid, wenn wir die Messlatte etwas anheben.", 26972);

-- 10845 - Tötet die Brutmutter
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10845 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10845, "deDE", "Nein! Ihr habt Unheilschwinge getötet? Vielleicht habe ich mich in Euch getäuscht, $C.$B$BVielleicht.$B$BDennoch habt Ihr die Anführer der drei größten Bedrohungen für unser Volk erschlagen. Darauf könnt Ihr stolz sein.$B$BIch werde Euch ein Zeichen meiner Wertschätzung geben, aber lasst es Euch nicht zu Kopf steigen. Ihr habt immer noch keine Ahnung davon, was es bedeutet, ein Mok'Nathal zu sein. Vielleicht werden wir immer noch auf Eure Fähigkeiten zurückkommen müssen.", 26972);

-- 10846 - Verständnis für die Mok'Nathal
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10846 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10846, "deDE", "Die Vekh'nir sind noch die harmlosesten unserer Feinde.$B$BIhr habt also einen übergroßen Vogel getötet. Das macht Euch noch lange nicht zu einem wahren Krieger. Das lässt Euch auch nicht unser Wesen verstehen.$B$BAber es ist ein Anfang.", 26972);

-- 10851 - Die Totems meines Feindes
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10851 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10851, "deDE", "Wart Ihr im Außenposten der Speerspießer und habt ihnen die Totems abgenommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10851 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10851, "deDE", "Das sieht nach einer guten Sammlung aus. Wir sollten einen Weg finden können, sie respektvoll einzusetzen.$B$BIn der Tat habe ich sogar schon eine Idee!", 26972);

-- 10853 - Geisteranrufung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10853 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10853, "deDE", "Die Drachen des Singenden Bergrückens sind vielleicht eine Bedrohung für uns, doch sie sind majestätische Wesen.$B$BOder sie waren es zumindest. Ich hoffe, dass Ihr ihre Geister retten könnt.$B$BUnd falls Ihr noch mehr Totems brauchen solltet, habe ich noch ein paar über.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10853 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10853, "deDE", "Ihr habt heute eine große Tat vollbracht, $C. Die Geister der Drachen werden nun wieder singen können, denn sie sind frei. Und die Überreste ihrer Geister, die sie hinterlassen, dienen als mächtiges Heilmittel.$B$BHabt Ihr vielleicht Lust auf eine Reise in den Norden? Es gibt da eine Sache im Zusammenhang mit den Astralen, die mich brennend interessiert.$B$BIch fühle großen Schmerz aus dieser Richtung kommen.", 26972);

-- 10859 - Sammelt die Kugeln
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10859 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10859, "deDE", "Habt Ihr alle Lichtkugeln der Razaani, die ich brauche, gesammelt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10859 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10859, "deDE", "Etwas fühlt sich hier falsch an.$B$BBitte, $N, reicht mir das Totem. Ich muss diese Kugeln untersuchen.", 26972);

-- 10860 - Leckerbissen der Mok'Nathal
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10860 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10860, "deDE", "Habt Ihr alle Zutaten schon? Darüber zu reden hat mir das Wasser im Munde zusammenlaufen lassen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10860 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10860, "deDE", "Mmm, ich kann sie schon schmecken! Schnell, reicht mir die Zutaten... Ich werde sie rasch klein würfeln und dann ab damit aufs Feuer!$B$BZu Eurem Glück hält sich das Zeug lange, und ich meine damit sehr lange! So, nehmt dies. Und da Ihr so freundlich wart, meine Speisekammer aufzufüllen, gebe ich Euch die Rezepte gleich noch dazu.", 26972);

-- 10865 - Informiert Leoroxx!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10865 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10865, "deDE", "Ist das, was Ihr da sagt, überhaupt möglich? Was sage ich da? Natürlich ist es das, wenn der Geistrufer davon überzeugt ist.$B$BErinnert Ihr Euch noch, als ich sagte, dass wir vielleicht wieder Eure Hilfe brauchen würden? Wie es scheint, kann ich in die Zukunft sehen.", 26972);

-- 10867 - Es kann nur eine Antwort geben
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10867 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10867, "deDE", "Habt Ihr es getan? Sind die Seelen unserer Vorfahren sicher vom Bösen der Astralen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10867 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10867, "deDE", "Es ist gut, dass der Abschaum der Astralen und ihr Anführer tot sind. Ich wünsche ihren Brüdern tausend Plagen auf den Hals!$B$BIhr sollt für Eure Taten im Namen aller Mok'Nathal belohnt werden, $N! Ihr seid wirklich ein Held für uns!$B$BLasst uns nun die Seelen unserer Vorfahren dem reinigenden Feuer übergeben.", 26972);

-- 10893 - Langschweif ist der springende Punkt
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10893 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10893, "deDE", "Nun, da Draaca unschädlich gemacht wurde, sollten wir in der Lage sein, unseren Vorteil aus der Situation zu ziehen. Sie werden sich jetzt untereinander darum streiten, wer die Leitung übernehmen soll, und das wird uns viel Druck nehmen.$B$BEs sei denn der Aufseher aus dieser Einladung, die Ihr mir gegeben habt, nimmt ihren Platz ein.$B$BWir sollten sicherstellen, dass das niemals passieren wird!", 26972);

-- 10894 - Behüter des Wyrmschädels
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10894 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10894, "deDE", "Wie kann ich Euch helfen? Bringt Ihr Nachrichten aus dem Ewigen Hain?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10894 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10894, "deDE", "Es ist genau so, wie ich es befürchtet habe, und das ist nicht gut!$B$BIch habe schon eine Idee, wie ich Euch helfen kann, aber vielleicht könnt zunächst Ihr uns helfen?$B$BEine Hand wäscht die andere.", 26972);

-- 10904 - Teufelsmunition
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10904 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10904, "deDE", "Habt Ihr die Kanonenkugeln schon?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10904 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10904, "deDE", "Diese Dinger stinken ja schlimmer, als ich dachte!$B$BSchnell, gebt sie mir, damit ich die mit der Macht der Natur erfüllen kann. Dann werden sie zu tödlichen Waffen gegen die teuflischen Meister und ihre unnatürlichen Schöpfungen.", 26972);

-- 10910 - Die Schwelle des Todes
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10910 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10910, "deDE", "Ich bin sehr erleichtert, dass Wildfürst Antelarion Euch zu uns geschickt hat. Das Problem ist noch viel schlimmer, als wir befürchtet haben!", 26972);

-- 10911 - Feuer frei!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10911 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10911, "deDE", "Habt Ihr beide Warpportale schon zerstört?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10911 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10911, "deDE", "Euer Heldenmut ist beeindruckend!$B$BSehr gut. Nun, da die Warpportale außer Gefecht sind, bleibt nur noch eines zu tun.", 26972);

-- 10912 - Der Hundehetzer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10912 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10912, "deDE", "Ist es vorbei? Ist die Gefahr an der Schwelle des Todes abgewendet?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10912 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10912, "deDE", "Ihr seid wirklich ein ganz erstaunlicher $R! Wenn ich schon zuvor dachte, dass wir in Eurer Schuld stehen, so gibt es nun einfach keinen Weg mehr, Euch je für Eure Taten zu danken.$B$BAber wir wollen es dennoch versuchen. Vielen Dank, Held des Ewigen Hains!", 26972);

-- 10927 - Die Krabbler erschlagen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10927 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10927, "deDE", "Gute Arbeit, $C. Dieser Tunnel ist unsere direkte Verbindung zum Sumpf.", 26972);

-- 10928 - Die Krabbler erschlagen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10928 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10928, "deDE", "Gute Arbeit, $C. Dieser Tunnel ist unsere direkte Verbindung zum Sumpf.", 26972);

-- 10974 - Stasiskammern von Bash'ir
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10974 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10974, "deDE", "Ihr habt es geschafft! Hattet Ihr Glück?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10974 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10974, "deDE", "<Das Bild von Kommandant Ameer kramt in den Beweisstücken.>$B$BEs ist schlimmer, als ich dachte... Diese Kammern enthalten wilde Bestien und Kreaturen von vielen verschiedenen Welten. Das Astraleum hofft, eines Tages Kontrolle über diese Bestien zu gewinnen und sie ihrem Willen zu unterwerfen. Wir müssen sie alle vernichten!", 26972);

-- 10975 - Die Reinigung der Kammern von Bash'ir
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10975 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10975, "deDE", "Es gibt immer noch mehr Arbeit, die erledigt werden muss, $N. Begebt Euch nun auf die Suche nach einer Stasiskammer und vernichtet, was auch immer darin lauern mag!", 26972);

-- 10976 - Das Abzeichen des Nexuskönigs
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10976 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10976, "deDE", "Dies wird Eure furchteinflößendste Aufgabe sein, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10976 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10976, "deDE", "Endlich!$B$B<Kommandant Ameer liest die Inschrift auf dem Abzeichen des Nexuskönigs.>$B$BZwei Gefängnisse? Schon der Gedanke an die Schrecken, die darin hausen mögen, lässt mich erzittern...", 26972);

-- 10982 - Das Auge des Haramad
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10982 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10982, "deDE", "Ihr habt viel für das Protektorat und das Konsortium getan, $N. Daher ist es nur gerecht, dass einer unserer neuen Schlüssel an Euch geht. Mit diesem Schlüssel könnt Ihr Shaffars persönliche Stasiskammer jederzeit öffnen, ohne den Schlüssel dabei zu zerstören.$B$BEr ist von Dauer und wird auf ewig Euch gehören. ", 26972);

-- 10983 - Mog'dorg der Weise
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10983 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10983, "deDE", "Grok sagt, ich bin weise? Ich weiß ja nicht so recht.$B$BVielleicht liegt das daran, dass ich der Einzige meines Klans bin, der aufrichtig versucht uns vor der Vernichtung durch den Speerspießerklan zu retten. Und natürlich vor Gruul und seinen Söhnen, die sie unterstützen.$B$BIch hoffe, dass Ihr gekommen seid, um uns aus der unaufhaltsamen Verdammnis zu erretten, $C.", 26972);

-- 10989 - Mog'dorg der Weise
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10989 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10989, "deDE", "Endlich hat Chort mir jemanden geschickt, der in der Lage sein könnte, mir zu helfen. Ich bin bemüht, die Blutschläger vor der Auslöschung durch die Speerspießer zu bewahren. Und natürlich durch Gruul und seine Söhne, die sie unterstützen.$B$BIch vertraue fest darauf, dass Ihr unserer Geheimorganisation helfen und uns in die Freiheit führen könnt.", 26972);

-- 10995 - Grulloc hat zwei Schädel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10995 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10995, "deDE", "Ist Grulloc schon Geschichte?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10995 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10995, "deDE", "Das muss ein harter Kampf gewesen sein, $C. Ich bin sehr erleichtert, dass er uns nun nicht mehr auf die Pelle rücken wird.$B$BIch werde diesen Schädel zu Chort schicken, damit er auf ihn aufpasst. Ich glaube, dass wir unser Ziel mit eurer Hilfe erreichen können!", 26972);

-- 10996 - Maggocs Schatztruhe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10996 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10996, "deDE", "Habt Ihr die Truhe?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10996 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10996, "deDE", "Sie war leer? Was ein Pech! Aber nun habt Ihr eine Ahnung von der sinnlosen Gewalt, unter der wir leiden müssen.$B$BJetzt, da Maggoc tot ist, sind wir meinem Traum von einem Zuhause, in dem wir Oger unser Schicksal selbst schmieden können, einen entscheidenden Schritt näher gekommen.", 26972);

-- 10997 - Sogar ein Gronn hat Standards
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10997 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10997, "deDE", "Haltet Ihr Slaags Standarte schon in Euren Händen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10997 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10997, "deDE", "Ich bin erleichtert, dass Slaag nicht mehr unter uns weilt. Nun müssen wir nicht länger in Angst vor seiner drohenden Rückkehr leben!$B$BWenn Ihr nichts dagegen habt, würde ich die Standarte gerne als Symbol der Hoffnung für alle Oger dieser Berge entgegennehmen.$B$BVielen Dank, $N.", 26972);

-- 10998 - In den übelsten Kreisen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10998 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10998, "deDE", "Habt Ihr Vim'gol den Üblen beschworen und seinen toten Klauen den Zauberfolianten entrissen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10998 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10998, "deDE", "Ich scheue mich davor, ein Ding von solcher Abscheulichkeit auch nur anzufassen. Und doch müssen wir den Folianten lesen, wenn wir sein Wissen erkunden und Skulloc aus seinem Versteck locken möchten.", 26972);

-- 11000 - Schänder der Seelen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11000 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11000, "deDE", "Habt Ihr Skullocs Seele schon geraubt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11000 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11000, "deDE", "Es ist also vorüber. Ihr habt uns von den Fesseln der Sklaverei durch die Söhne von Gruul befreit. Ihr habt den Klan der Blutschläger vor der sicheren Auslöschung bewahrt.$B$BEs gibt keine Worte, um zu beschreiben, wie tief ALLE Oger des Schergrats, Blutschläger wie Speerspießer, in Eurer Schuld stehen, $N.$B$BSchaut dort, wie all die Oger sich versammeln, um Euch Tribut zu zollen! Sollen Gruul und seine Marionette, der alte König Maulgar, sich ruhig in ihrem Unterschlupf verkriechen. Geht zu den Ogern als ihr neuer König!", 26972);

-- 11009 - Ogerhimmel
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11009 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11009, "deDE", "Mog'dorg hat eine Nachricht voraus geschickt, um mich über Euer Kommen zu informieren. Ich bin froh, dass Ihr hier seid.$B$BNach dem Fall der Söhne des Gruul, ist es nur noch eine Frage der Zeit - es dürfte nicht sehr lange dauern - bevor die unterschiedlichen Bewohner dieser Bergterrasse und die des Nordens beginnen, Jagd auf unsere Ogerbrüder dort unten zu machen.$B$BDies gilt es zu verhindern und ich vertraue auf Eure Unterstützung, $N.", 26972);

-- 11010 - Bomberangriff
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11010 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11010, "deDE", "Habt Ihr schon ihre Stapel mit Teufelskanonenkugeln vernichtet?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11010 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11010, "deDE", "Gut, gut, anscheinend seid Ihr doch härter im Nehmen, als ich dachte. Ausgezeichnete Arbeit. Möglicherweise hatte der alte Keller doch Unrecht, was Euch anbelangt.$B$B<Himmelsoffizierin Vanderlip grinst.>", 26972);

-- 11022 - Sprecht mit Mog'dorg
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11022 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11022, "deDE", "Mein werter Herr, es freut mich, dass Ihr vor Eurer Abreise noch einmal mit mir zu sprechen gedenkt.", 26972);

-- 11023 - Und wieder ein Bombenangriff!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11023 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11023, "deDE", "Wie steht es mit dem Bombenangriff?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11023 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11023, "deDE", "Hervorragend, $N! Ich würde Euch ja sofort wieder in die Luft schicken und ein paar Bomben werfen lassen, aber unsere Richtlinien hier schreiben vor, dass unsere Piloten ausreichend Ruhe und Erholung erhalten müssen. Es tut mir leid, ich mache die Regeln nicht, aber lasst Euch versichern, dass ich sie durchsetzen werde!$B$BSehen wir uns morgen wieder, Sportskanone?", 26972);

-- 11025 - Die Kristalle
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11025 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11025, "deDE", "Wenn Ihr mehr über die Splitter und Kristalle lernt, werdet Ihr uns und unsere Ogerbrüder dort unten besser beschützen können.$B$BDie Splitter selbst wurden nach einer uralten und mittlerweile ausgelöschten Arakkoazivilisation benannt, die einst auf den Spitzen dieser Berge lebte.$B$BNun, habt Ihr die Splitter bei Euch?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11025 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11025, "deDE", "<Chu'a'lors linker Kopf beginnt zu sprechen.>$B$BDiese sind genau richtig.$B$BDenkt daran, $N, der Wert dieser Splitter liegt nicht in ihrem Verkaufspreis. Es ist nicht einmal das, was sie für Euch tun können, sobald sie ordnungsgemäß zusammengeschmiedet wurden... auch wenn sich darüber streiten lässt.$B$B$B$BDer wahre Wert liegt in dem Unterfangen, das es auf sich zu nehmen gilt, um in den Besitz dieser Splitter zu gelangen.", 26972);

-- 11026 - Bannt die Dämonen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11026 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11026, "deDE", "Das wird ihnen eine Lehre gewesen sein! Kommen wir nun zu Eurer Belohnung.$B$BDie Dämonen des Konstruktionslagers: Rache im Norden haben an ihrer südlichen Grenze einen besonderen Transporter errichtet. Sie verwenden dieses experimentelle Transporttor, um den Einfluss des Lagers weiter auszudehnen. Wir brauchen Euch wohl nicht erst erklären, was passieren wird, wenn sie sich zu weit ausbreiten.$B$BAlso, wenn wir Ihr wären, würden wir diese Dunkelrune zu Gahk schaffen und ihn Fragen, wie Ihr helfen könnt. Geht es langsam mit ihm an, $N, er ist ebenfalls neu hier.", 26972);

-- 11027 - Habt Ihr die Rune der Dunkelheit?
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11027 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11027, "deDE", "Die Dämonen von dem Camp da machen die Transporter immer wieder ganz. Gahk sagt $N muss die Dämonen besser plattmachen diesmal!$B$BAber Gahk braucht noch 'ne Dunkelrune um zu machen eine kristallgeschmiedete Rune.$B$BWenn klein $R nicht haben Dunkelrune, Du sprechen mit Kronk! Er versuchen Dunkelrunen zu machen jeden Tag! Vielleicht Du bekommen eins aus Kronks Grabbelsack?!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11027 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11027, "deDE", "Haha, gut! Gahk mögen Dunkelrunen! Ihr nehmen kristallgeschmiedete Dunkelrune, die Gahk kürzlich gemacht haben.$B$BNicht vergessen, Tokru, erst beherrschen Zerrütter und dann zerschlagen magisches Schild von Shartuuls Transporter. Andere Dämon wird frei sein und dann Ihr auch ihn bekämpfen und beherrschen! Dann Ihr müssen mehr Dämonen bekämpfen und kontrollieren, bis keine mehr kommen!$B$BDann Ihr Ogri'la erretten!", 26972);

-- 11030 - Unser Junge möchte der Himmelswache beitreten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11030 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11030, "deDE", "Habt Ihr das magische Fläschchen schon bekommen? Es würde Torkus Junior alles bedeuten.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11030 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11030, "deDE", "Ihr seid ein wahrer Lebensretter, $N!$B$BUnsere Jungs werden von dieser Neuigkeit begeistert sein!$B$BOkay, eines geschafft und eines fehlt noch. Wir haben Euch doch bestimmt von dem anderen Fläschchen erzählt, das sie benötigen, nicht wahr?", 26972);

-- 11036 - Außerirdische Früchte!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11036 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11036, "deDE", "Ist das die Lieferung vom alten Orok?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11036 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11036, "deDE", "<Der Raketenchef überprüft den Inhalt der Kiste.>$B$BSieht soweit gut aus. Wieder etwas, das ich von der Liste streichen kann. Nun müssen wir noch nur dafür sorgen, dass die Rakete vom Boden abhebt.", 26972);

-- 11047 - Die Bitte des Gesellen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11047 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11047, "deDE", "<Dama hört sich Agadais Bitte an.>$B$BIch kann nicht dafür garantieren, dass wir über genügend Windreiter verfügen, aber ich werde sehen, was ich tun kann. In der momentanen Situation haben wir Schwierigkeiten, die Nachfrage der verschiedenen Käufer und Außenposten abzudecken.", 26972);

-- 11051 - Bannt mehr Dämonen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11051 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11051, "deDE", "Jemand mit Eurer Erfahrung dürfte keine Probleme damit haben, ein paar Dämonen zu bannen. Ihr habt doch keine Schwierigkeiten damit, oder, $R?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11051 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11051, "deDE", "Wir wünschten uns, der Herstellungsprozess für Runen der Dunkelheit wäre narrensicher, $N. Unglücklicherweise ist er das nicht. Nehmt bitte diesen Sack und seht mal, was wir heute hergestellt haben. Wir haben es nicht übers Herz gebracht, selbst nachzusehen.$B$BWenn Ihr eine Rune der Dunkelheit erhaltet, vergesst nicht, Gahk aufzusuchen und sie bei ihm gegen eine kristallgeschmiedete Rune der Dunkelheit einzutauschen. Mit ihr könntet Ihr Shartuuls Transporter erneut ausschalten.$B$BOh, und $N, denkt daran, morgen wiederzukommen und den Bannkristall abzuholen. Es sind genug Dämonen da, die gebannt werden möchten.", 26972);

-- 11057 - Schwierigkeiten in der Tiefe
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11057 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11057, "deDE", "Man hat Euch von hoch oben zu mir geschickt? Wahrlich, meine Mission ist gesegnet! Ich versuche die Blutschläger vor der Ausrottung durch den Speerspießerklan und Gruuls Söhne zu bewahren.$B$BIch nehme an, dass Ihr unsere geheime Organisation unterstützen und uns die Freiheit bringen werdet?", 26972);

-- 11058 - Ein Apexisrelikt
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11058 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11058, "deDE", "<Chu'a'lors Köpfe nicken Euch anerkennend zu.>$B$BIhr habt einen scharfen Verstand, $N. Wir haben erheblich länger gebraucht, um das Relikt erfolgreich zu benutzen.$B$BNun, da Ihr wisst wie, könnt Ihr es so oft Ihr wollt verwenden. Denkt jedoch daran, dass für die Aktivierung eines Relikts immer ein Apexissplitter erforderlich ist.", 26972);

-- 11059 - Wächter des Monuments
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11059 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11059, "deDE", "Wir verabscheuen Gewalt, aber wenigstens ist das Konstrukt, das Ihr vernichten sollt, kein lebendiges Wesen.$B$BWo wir schon davon sprechen, habt Ihr den Kopf?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11059 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11059, "deDE", "<Chu'a'lor mustert Euch voller Respekt.>$B$BEure und die geistige Gewandtheit Eurer Freunde ist wahrlich beeindruckend. Dafür, dass Ihr uns und unsere Lebensweise verteidigt habt, stehen wir, nein, stehen ganz Ogri'la und die Himmelswache in Eurer Schuld.$B$BDenkt daran $N, Ihr könnt jederzeit mit gesammelten Apexissplittern zurückkehren, um die großen Apexismonumente zu benutzen.", 26972);

-- 11060 - Eine kristallgeschmiedete Rune der Dunkelheit
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11060 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11060, "deDE", "Kleiner $R, nicht vergessen, wenn Ihr einen Zerrütter kontrollieren, Ihr müssen seinen Hammer dazu benutzen, um die Schilde von Warptor zu zerschlagen und den gefangenen Dämonen freizulassen.$B$BDann Ihr müssen zerschlagen diesen Dämon und ihn beherrschen. Dann kommen neuer Dämon, den Ihr auch beherrschen müssen, bis der Aufseher der Eredar auftauchen.$B$BDann Ihr auch ihn erschlagen werdet!!!", 26972);

-- 11061 - Die Pflichten eines Vaters
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11061 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11061, "deDE", "Dieses Fläschchen des Zauberers wird meine Jungs sicherlich noch intelligenter machen, als sie es ohnehin schon sind. Damit sollten ihnen die täglichen Pflichten in der Himmelswache der Sha'tari etwas leichter fallen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11061 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11061, "deDE", "Wir können Euch gar nicht genug danken, $N!$B$BSo instabil diese zwei Fläschchen auch sein mögen, mit ihrer Hilfe können wir nun einen unserer Jungs nach Norden zum Außenposten der Himmelswache schicken.$B$BWartet einen kleinen Augenblick, während wir einen von ihnen rufen.", 26972);

-- 11062 - Der Außenposten der Himmelswache
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11062 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11062, "deDE", "Willkommen im Außenposten der Himmelswache. Wisst Ihr, ich habe den gesamten Posten mit meinen eigenen Händen errichtet.$B$BSchon richtig gehört, alles was Ihr hier vor Euch seht!$B$B<Dem Himmelskommandanten scheint es ernst zu sein.>$B$BIhr müsst ja ganz schön scharf auf einen Kampf sein, wenn Ihr extra hierhergekommen seid, um mit mir zu sprechen. Es war nett vom alten Chu'a'lor, Euch vorbeizuschicken. Wir können hier immer etwas Frischfleisch gebrauchen.$B$BWenn es Euch nichts ausmacht, würde ich vorschlagen, Ihr unterhaltet Euch ein wenig mit meinem Himmelsoffizier Vanderlip. Stört Euch nicht an ihrem Gebaren, ihre Zunge ist womöglich schärfer als das Breitschwert, das sie bei sich trägt.", 26972);

-- 11065 - Bändigt ein paar Ätherrochen!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11065 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11065, "deDE", "Habt Ihr schon ein paar Ätherrochen gebändigt? Ihr seht so aus, als könntet Ihr mit einem Lasso umgehen. Sicher habt Ihr Euren Auftrag schnell abgeschlossen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11065 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11065, "deDE", "Juhuu! Gute Arbeit, $N! Diese Rochen werden ein paar hervorragende Reittiere abgeben!$B$BBleibt ruhig noch ein wenig, die Himmelswache der Sha'tari kann Männer mit Euren Talenten immer gut gebrauchen!", 26972);

-- 11066 - Bändigt noch mehr Ätherrochen!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11066 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11066, "deDE", "Ihr leistet hervorragende Arbeit für uns, $N! Ich möchte Euch nur wissen lassen, dass wir Eure Bemühungen, uns mit frischen Reittieren zu versorgen, sehr zu schätzen wissen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11066 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11066, "deDE", "Ihr erstaunt mich immer wieder! Ich sage Euch was, warum lasst Ihr das Lasso nicht für heute ruhen und wir sehen uns morgen wieder?$B$B<Khatie lacht.>$B$BNochmals vielen Dank, $N!", 26972);

-- 11078 - Den Himmel beherrschen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11078 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11078, "deDE", "Wie geht es voran, $N? Ich brauche Euch sicherlich nicht extra zu sagen, wie wichtig die ganze Angelegenheit für unsere Luftüberlegenheit ist.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11078 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11078, "deDE", "Ja! Diese Zähne sehen scharf aus, als könnten sie beinahe alles wie Butter durchschneiden!$B$BErlaubt mir, Euch und Eure Freunde dazu zu ermuntern, weiterhin so gute Arbeit zu leisten! Diese Drachen sind gefährliche Raubtiere, die unseren Himmel lange genug unsicher gemacht haben.$B$BEuch sind sicherlich die Drachenschuppen aufgefallen. Wie ich hörte, kann man aus ihnen einen mächtigen Umhang herstellen, sofern man eine Schuppe von jedem der Drachen besitzt. Sollte Euch der Umhang nicht zusagen, bin ich jederzeit bereit, ihn gegen einen Apexiskristall einzutauschen.", 26972);

-- 11079 - Eine Teufelspeitsche für Gahk
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11079 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11079, "deDE", "Ihr haben Peitsche?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11079 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11079, "deDE", "Gahk mögen Peitsche. Vielleicht Gahk nehmen Peitsche und bearbeiten ein paar Dämonen!$B$BMich sagen zu $R, dass $R kann jederzeit beschwören Dämonenanführer, solange $R haben viele Freunde und 'ne Menge Splitter.", 26972);

-- 11080 - Die Strahlung des Relikts
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11080 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11080, "deDE", "Euer Geschick im Umgang mit den Relikten erstaunt uns immer wieder, $N. Dürften wir Euch vorschlagen, mindestens einmal am Tag den Gebrauch der Relikte zu üben, damit Euer Verstand seine Schärfe bewahrt?", 26972);

-- 11091 - Ein besonderer Dank an Euch
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11091 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11091, "deDE", "Hey, Mann, das ist toll! Wir haben viel von Euren guten Taten gehört. Das ist fantastisch. Wir haben da so ein Gefühl, dass Ihr für Ogri'la alles zum Guten wenden werdet. Ihr werdet uns beschützen und alles wird heiter und sonnig!$B$BHier, nehmt das. Es ist ein kleines Überlebenspaket, dass wir zum Dank für Euch zusammengestellt haben.$B$BWerft doch bitte einen Blick auf unsere Waren. Wir haben eine reichhaltige Auswahl der erlesensten Gegenstände, von denen Euch sicherlich das eine oder andere Stück interessieren wird.", 26972);

-- 11119 - Angriff auf den Landeplatz von Bash'ir!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11119 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11119, "deDE", "Egal, was Keller dazu meint, ich bevorzuge es, unsere Einsätze als Forschungsexkursionen zu betrachten.$B$BEs stimmt allerdings, dass wir dort Vorräte für die Himmelswache beschaffen, jedenfalls, wenn wir lange genug dort bleiben können.$B$BIhr seht so aus, als wäret Ihr bereit, uns den Rücken gegen die Astralen freizuhalten. Wenn Ihr uns die Astralen lange genug vom Leib haltet, werden wir Euch alle zusätzlich an der Kristallschmiede hergestellten Gegenstände zum Verkauf anbieten, also bringt Eure Apexissplitter und Kristalle mit!$B$BWir ziehen in 2 Stunden los.", 26972);
