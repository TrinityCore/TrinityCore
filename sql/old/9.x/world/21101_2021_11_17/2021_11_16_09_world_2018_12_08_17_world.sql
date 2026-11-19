-- Netherstorm -- Nethersturm
-- RequestItems, OfferReward -- master, 3.3.5

-- 10173 - Der Stab des Erzmagiers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10173 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10173, "deDE", "Ich werde nicht ruhen, bis Erzmagier Vargoth seinen Stab zurück hat. Konntet Ihr ihn den Klauen des Dämons entreißen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10173 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10173, "deDE", "Ah, Ihr habt es also geschafft, den Stab zurückzuholen. Beeindruckend, $N. Vielleicht seid Ihr genau der $C, den ich suche.$B$BOh ja, Eure Belohnung...$B$B$B$BIhr habt sicherlich mehr erwartet, aber das kommt schon noch mit der Zeit. Fürs Erste soll die Möglichkeit Eure Belohnung sein.", 26972);

-- 10174 - Der Fluch des Violetten Turms
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10174 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10174, "deDE", "<Erzmagier Vargoth betrachtet Euch, als Ihr ihm Ravandwyrs Nachricht übermittelt.>$B$BRavandwyr hat alles, was ein Meister sich von einem Lehrling wünschen kann. Als ich ihm den Stab gab und ihm befohlen habe, zu fliehen, habe ich gehofft, dass er ihn benutzen würde, um jemanden zu finden, der mich nach dem Abzug von Kael'thas Truppen aus dem Turm befreien kann. Seitdem habe ich viel über den Fluch herausgefunden.$B$BEr kann gebrochen werden, aber dazu brauche ich Eure Hilfe.", 26972);

-- 10176 - Arkelos der Wächter
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10176 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10176, "deDE", "Das habt Ihr gut gemacht, $N. Ohne das Dämpferfeld wird es viel leichter für mich, die Magie vorzubereiten, mit der ich den Fluch des Turms endlich aufheben kann.", 26972);

-- 10182 - Kampfmagier Dathric
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10182 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10182, "deDE", "Gut gemacht, $N. Ich kann keine Rastlosigkeit mehr in Dathrics Geist spüren. Ich würde viel dafür geben, wenn ich noch einmal mit ihm sprechen könnte, aber es ist schon gut genug, dass er nun in Frieden ruht.", 26972);

-- 10183 - Auf nach Area 52
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10183 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10183, "deDE", "Stress, Stress. Keine Zeit verschwenden! Es gibt ein Raketenschiff, das gebaut werden will!$B$BWas wollt Ihr?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10183 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10183, "deDE", "Oh, Kupfernickel hat sich also endlich entschlossen, seine Entdeckungen zu berichten, was? Faule Wissenschaftler!$B$BWas ist das?$B$B<Der Chef blättert ein paar Mal durch die Notizen mit einem deutlich skeptischen Gesichtsausdruck.>$B$BEr sagt, dass die gewaltigen Netherenergien, die durch den Nethersturm fließen, alles in nur ein paar Monaten in Stücke reißen werden.$B$BDas ist ungünstig - jetzt müssen wir den Zeitplan für das Raketenschiff etwas straffen.", 26972);

-- 10184 - Bösartige Überbleibsel
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10184 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10184, "deDE", "<Hüter Dierwert schüttelt langsam den Kopf.>$B$BSie haben das nicht verdient, aber es ist das Beste, was wir tun können.", 26972);

-- 10185 - Schlimmer als der Tod
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10185 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10185, "deDE", "<Der Hüter sieht bestürzt aus.>$B$BIch kann die nächste Welle schon über den Horizont kommen sehen. Sie auszumerzen hilft vielleicht für den Moment, aber wir brauchen langfristige Maßnahmen.", 26972);

-- 10186 - Ihr seid eingestellt!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10186 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10186, "deDE", "Sieht es etwa aus, als wäre die X-52 Netherrakete bereit zum Abflug? Durchquere ich den Wirbelnden Nether in meinem bequemen Kommandostuhl? Entdecke ich fremde neue Welten? Suche nach neuen Technologien und Geschäftsgelegenheiten? Dringe in Galaxien vor, die nie ein Goblin zuvor gesehen hat?$B$BNein!$B$BAlso hoffe ich, dass Ihr die Kristalle habt, nach denen ich Euch geschickt habe.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10186 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10186, "deDE", "Pah! Die sehen aber grob aus. Vielleicht können wir sie in einer tertiären Antriebsmehrfachkammer einsetzen?$B$BTrotzdem gute Arbeit, Juniortechniker dritten Grades! Ihr werdet es sicher bald zum zweiten Grad schaffen.", 26972);

-- 10188 - Das Siegel von Krasus
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10188 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10188, "deDE", "Wenn ich vom Fluch des Turmes frei sein will, muss ich das Siegel haben.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10188 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10188, "deDE", "Ah, es ist so wundervoll, wie ich es in Erinnerung hatte. Könnt Ihr die Macht, die davon ausgeht, spüren?$B$BNatürlich ist noch viel mehr zu tun, aber Ihr habt meinen tiefsten Dank dafür, dass Ihr mir das Siegel zurückgebracht habt.", 26972);

-- 10189 - Manaschmiede B'naar
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10189 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10189, "deDE", "Habt Ihr bekommen, worum ich Euch gebeten habe, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10189 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10189, "deDE", "Ausgezeichnet! Mit dieser Stammrolle können wir bessere Entscheidungen treffen, wenn wir die Anhänger Kaels bei den Manaschmieden angreifen.$B$BEigentlich schade, ich mochte es irgendwie, seine Lakaien wahllos zu töten.", 26972);

-- 10190 - Batterien aufladen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10190 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10190, "deDE", "Habt Ihr die Batterie schon aufgeladen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10190 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10190, "deDE", "He, passt auf, auf wen Ihr mit dem Ding zeigt! Ihr habt es auf töten gestellt!!!$B$BGut, es sieht so aus, als hättet Ihr die Batterie genügend aufgeladen. Ich baue sie gleich in Nr. V ein.", 26972);

-- 10191 - Nummer V lebt!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10191 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10191, "deDE", "Ihr habt es geschafft! Ihr habt es geschafft! Ich könnte Euch küssen!$B$BOh verdammt... die Batterie von Maxx E. Million Nr. V ist schon wieder leer. Naja, er hat seine Arbeit erledigt, und das ist das Wichtigste.$B$BRaketenchef Doppeldecker wird sich freuen, wenn er diese Draeneimaschinen in der X-52 Netherrakete einbauen kann! Das bedeutet eine Beförderung für mich! Ich bin so glücklich, ich muss Euch einfach belohnen!$B$BHier, sucht Euch etwas davon aus.", 26972);

-- 10192 - Krasus' Kompendium
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10192 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10192, "deDE", "Habt Ihr das Buch besorgt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10192 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10192, "deDE", "<Das Abbild von Erzmagier Vargoth scheint das Kompendium zu begutachten.>$B$BEs ist ein wenig mitgenommen, aber wenn man bedenkt, was es durchmachen musste, ist es ein Wunder, dass es überhaupt überlebt hat. Bewahrt es auf, $N. Ohne das Buch haben wir kaum eine Chance, den Schutzschild des Turms zu durchbrechen.", 26972);

-- 10193 - Hochrangige Ziele
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10193 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10193, "deDE", "Ihr seid ein zuverlässiges Mädel. $N. Wenn es etwas gibt, das ich noch mehr mag, als Kaels Schoßhunde zu töten, dann ist es, wenn das jemand anderes für mich erledigt.$B$BSo habe ich weniger Blut auf meinen Klamotten.", 26972);

-- 10194 - Heimlicher Flug
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10194 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10194, "deDE", "Euren Flug zu organisieren war nicht gerade billig. Ich hoffe, ihr habt das Zeug zu diesem Auftrag.", 26972);

-- 10197 - Eine überzeugende Verkleidung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10197 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10197, "deDE", "Habt Ihr die Kleidungsstücke, um die ich Euch gebeten habe?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10197 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10197, "deDE", "Ausgezeichnet! Wenn ich mit Euch fertig bin, werdet Ihr Euch unbemerkt unter die Ränge des Sonnenzorns mischen können.", 26972);

-- 10198 - Informationen sammeln
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10198 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10198, "deDE", "Wie geht es mit der Bespitzelung voran, $N? Ihr solltet Euch lieber beeilen. Ich werde hier schon ganz kribbelig.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10198 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10198, "deDE", "Die Manaschmiede Duro ist in Schwierigkeiten? Ich bin mir sicher, dass Thalodien sich über diese Neuigkeiten freuen wird. Lasst uns zunächst diese Aufgabe hier fertigstellen.", 26972);

-- 10199 - Der kleine Extrakick
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10199 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10199, "deDE", "Wenn ich das Gift von genügend vielen Netherrochenstacheln extrahieren kann, bekommen wir vielleicht den explosivsten Kraftstoff, der gemischt wurde!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10199 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10199, "deDE", "Wow! Ok, jetzt stimmt die Sache.$B$BLasst mich nur schnell die Boshaftigkeit aus diesen kleinen Schönheiten quetschen. Das sollte ein Raketentreibstoff werden, der alle von den Socken haut!$B$BHier, lasst mich das Schieferöl und das Stachelgift mischen, und dann schauen wir mal, was passiert...", 26972);

-- 10200 - Rückkehr zu Thalodien
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10200 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10200, "deDE", "Ihr überrascht mich immer wieder, $N. Das war beeindruckende Spionagearbeit, die Ihr da in der Manaschmiede Coruu geleistet habt.", 26972);

-- 10202 - Ein Abtrünniger
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10202 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10202, "deDE", "Es ist an der Zeit, dass Ihr auftaucht. Ich habe mich schon gefragt, ob die Seher überhaupt interessiert sind.", 26972);

-- 10203 - Unschätzbare Ausrüstung beamen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10203 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10203, "deDE", "Ihr müsst derjenige sein, der uns die ganze Ausrüstung von den Ruinen hergebeamt hat! Ein Hoch auf Euch!$B$BIch habe die Ausrüstung bereits an unsere Grabungsorte weiterverteilt. Jetzt können wir unsere Ausgrabungen im großen Stil überall auf der Insel durchführen! Die Netherrakete wird in null Komma nichts fertig werden!$B$BHmm, merkwürdig. Wartet mal, habt Ihr gesagt, Ihr habt uns vier Dinge zurück geschickt? Ich habe nur drei bekommen...", 26972);

-- 10204 - Blutjuwelenkristalle
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10204 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10204, "deDE", "Hmmm... wie ich erwartet habe.$B$BSolch rohen Energien ausgesetzt zu sein erhöht unsere angeborene Sucht nach Magie gewaltig.$B$BIch bin nicht überrascht, dass Kael mit seinen Taten ungestraft davon kommt, wenn seine Angestellten praktisch die ganze Zeit betrunken sind.", 26972);

-- 10205 - Sphärenräuber Nesaad
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10205 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10205, "deDE", "Ich bin erleichtert zu hören, dass dieser Abschaum endlich vernichtet wurde. Ihr macht Eure Arbeit gut, $N... darf ich so vermessen sein, Euch beim Namen zu nennen?$B$BWenn Ihr möchtet, habe ich eine weitere Aufgabe für Euch. Eine, die besonders wichtig ist. Jemand mit so offensichtlichen Talenten wie Ihr wird sie sicher leicht bewältigen können.", 26972);

-- 10206 - Wählt Eure Rolle
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10206 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10206, "deDE", "So schnell schon zurück? Nehmt mich besser nicht auf den Arm, $C.$B$BDer Erfolg des X-52-Projekts hängt davon ab, dass wir das Zeug so schnell wie möglich bekommen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10206 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10206, "deDE", "Hehe, astrale Deppen!$B$BDanke, dass Ihr uns die Teile gebracht habt, $C. Ich wette, wir können diese Babys gleich in die Rakete einbauen. Ich frage mich, was sie wohl bewirken? Wird sicher lustig, es herauszufinden!$B$BHm, lasst mich mal schauen ob ich noch ein wenig Wechselgeld für Euch in der Hosentasche habe.", 26972);

-- 10209 - Beschwörer Kanthins Preis
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10209 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10209, "deDE", "Habt Ihr den Stein von Gletscharius bekommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10209 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10209, "deDE", "<Ihr wisst nicht, ob es nur eine Verzerrung ist, aber der Erzmagier scheint zu lächeln.>$B$BJetzt, da ich all meine Besitztümer zurück habe, habe ich alles, um Kael'thas' Magie zu durchbrechen. Ich werde den Zauber gleich wirken.", 26972);

-- 10221 - Dr. Bumm!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10221 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10221, "deDE", "Habt Ihr uns vor den Verwüstungen durch Dr. Bumm gerettet? Ich verspreche Euch, dass es diesmal keine explodierenden Wagen gibt, auch wenn das wirklich spaßig war!$B$BWir sollten das wirklich öfter tun!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10221 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10221, "deDE", "Ich werde Sparky immer vermissen. <Schnief> Aber jetzt, da wir wissen, dass Dr. Bumm uns nicht mehr tyrannisieren kann, werden wir alle besser schlafen.$B$BLasst Euch das eine Lehre sein. Kommt hier nicht ohne Netherhelm runter!$B$BNun, wie kann ich Euch dafür belohnen?", 26972);

-- 10222 - Die Garnison des Sonnenzornpostens
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10222 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10222, "deDE", "Was Ihr getan habt, kann die Gefallenen nicht zurückbringen, aber vielleicht kann es ihre Geister beruhigen. Obwohl ehrlich gesagt kein Blut der Welt meinen Zorn über Kael'thas Taten stillen kann.", 26972);

-- 10223 - Nieder mit Daellis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10223 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10223, "deDE", "<Ihr seid Euch nicht sicher, aber es sieht so aus, als würde Hüter Dierwert gleich anfangen zu weinen.>$B$BEndlich ist es geschafft. Wenn ich könnte, würde ich meine Existenz selbst auslöschen, aber die Wahrheit ist, dass ich nicht loslassen kann. Für die Leute im Dorf ist es schwer, aber zumindest ehrlich. Ich schätze, das ist der Preis, den wir dafür bezahlen müssen, dass wir uns so sehr an diesen Ort gebunden haben.", 26972);

-- 10224 - Essenzen für die Motoren
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10224 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10224, "deDE", "Habt Ihr schon alle Essenzen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10224 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10224, "deDE", "Wow, das sind viele Essenzen!$B$BGut, schauen wir mal, was passiert, wenn ich sie mit den Astrallithiummatrixkristallen mische.", 26972);

-- 10225 - Meldung beim Chefingenieur
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10225 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10225, "deDE", "Äh, hallo. Ich bin hier ein wenig beschäftigt. Was habt Ihr da?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10225 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10225, "deDE", "Oh, Astrallithiummatrixkristalle! Ja, die klingen wichtig.$B$BLasst sie uns dort drüben hinstellen und ich kümmere mich gleich um sie.", 26972);

-- 10226 - Elementarenergieextraktor
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10226 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10226, "deDE", "Habt Ihr die Energie von diesen Elementaren schon? Oh, keine Hektik oder so. Hängt ja nur mein Leben und meine Karriere davon ab.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10226 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10226, "deDE", "Das ist besser! Gut, ich glaube, jetzt sind wir im Geschäft.$B$BLasst mich dieses Zeug nur kurz in das Zau-ba-Ding hier tun, und ich bin sicher, dass es gleich einen voll funktionsfähigen Phasenantriebskern ausspuckt.$B$BOh, he, ich sollte Euch vielleicht dafür belohnen, dass Ihr meine Haut gerettet habt. Hehe.", 26972);

-- 10232 - Legion in Trümmern
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10232 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10232, "deDE", "Nun, das sind gute und schlechte Nachrichten zugleich. Wir haben ihnen einen Schlag versetzt, aber ich weiß nicht, wie es weitergehen soll, wenn die Brennende Legion überall im Nethersturm frei herumrennt - und näher kommt.$B$BIch habe das Gefühl, dass wir einen Gang hochschalten müssen. Ich hoffe, Ihr könnt uns dabei helfen, $N.", 26972);

-- 10233 - Den Sonnenzornposten anzünden
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10233 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10233, "deDE", "<Zaubererleutnant Morran nickt grimmig.>$B$BDie Kirin Tor heißen Zerstörung im Allgemeinen nicht gut, aber um unseren Feind zu vernichten überwinden wir jeden Skrupel. Sogar im Tod.", 26972);

-- 10234 - Der Müll eines Dämons
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10234 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10234, "deDE", "Habt Ihr die Teile schon? Wir haben nur wenig Zeit, da die Legion überall gleichzeitig in unser Gebiet vorrückt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10234 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10234, "deDE", "Ich denke, die müssen reichen. Wenn wir sie nur fortjagen könnten!$B$BHe, da fällt mir etwas ein!", 26972);

-- 10235 - Verdammnisklaue die Krallen stutzen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10235 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10235, "deDE", "Schon mit Verdammnisklaue abgerechnet?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10235 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10235, "deDE", "Er, äh... er hat was gesagt? SIE WOLLEN AREA 52 ANGREIFEN?$B$BOh, das ist nicht gut... nicht gut!", 26972);

-- 10237 - Warnt Area 52!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10237 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10237, "deDE", "Ha, Ihr macht Witze, oder? Die Brennende Legion gibt uns die Schuld daran?$B$BAber IHR wart das!$B$BOh, ich habe Kopfschmerzen, die so groß wie diese Rakete sind! Ok, ok, wir müssen uns einen anderen Plan einfallen lassen.$B$BWenn die Brennende Legion denkt, dass sie hierher kommen, unser Dorf zerstören und meinen Traum von einer Reise durch den Wirbelnden Nether ruinieren kann, dann hat sie sich aber getäuscht.$B$BUnd ich kenne genau den richtigen Goblin, der uns dabei helfen kann.", 26972);

-- 10239 - Mögliche Energiequelle
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10239 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10239, "deDE", "Konntet Ihr ein paar ihrer Energiequellen sammeln?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10239 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10239, "deDE", "<Morran dreht einen der Würfel vorsichtig in der Hand.>$B$BIch glaube nicht, dass ich je zuvor so etwas gesehen habe. Es steckt sicher eine Menge Energie darin, aber es ist rohe Energie. Wir müssen vorsichtig damit sein, aber ich glaube, dass wir einen Weg finden können, wie man sie zur Abwehr der Manakreaturen einsetzen kann.", 26972);

-- 10240 - Eine Verteidigung errichten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10240 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10240, "deDE", "Habt Ihr alle Runen aktiviert? Ich bin so gespannt, ob wir die Methode der Blutelfen hier verbessern können. Was einer von Kael'thas' Leuten tun kann, kann ein Kirin Tor noch besser!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10240 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10240, "deDE", "Ausgezeichnete Arbeit. Drückt die Daumen, $N. Ich werde den Schild jetzt aktivieren.", 26972);

-- 10241 - Ablenkung in der Manaschmiede B'naar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10241 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10241, "deDE", "Ausgezeichnete Arbeit, $N. Die Seher haben dank Eures Ablenkungsmanövers wichtige Informationen sammeln können. Vielleicht teilen sie sie dieses Mal tatsächlich mit uns.", 26972);

-- 10243 - Die Technologie der Naaru
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10243 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10243, "deDE", "Die Symbole sehen fremdartig und unlesbar aus.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10243 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10243, "deDE", "Ihr öffnet die Rolle und bereitet Euch vor, die merkwürdigen Symbole abzuschreiben.", 26972);

-- 10245 - Steuerungsabschrift von B'naar
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10245 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10245, "deDE", "Wollen wir mal schauen, was Ihr da habt, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10245 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10245, "deDE", "Gut gemacht, $N. Gebt mir ein paar Augenblicke, um die Abschrift zu lesen.$B$BIhr habt den Dank der Priesterschaft, $C.", 26972);

-- 10246 - Angriff auf Manaschmiede Coruu
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10246 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10246, "deDE", "Ausgezeichnete Arbeit, $N. Mit Eurem Einsatz schaffen wir es sicher, den Feind zu besiegen.", 26972);

-- 10247 - Dr. h. c. tüft. Vomisa
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10247 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10247, "deDE", "Wie es scheint, haben wir großes Glück, junger Mann.$B$BIch habe gerade neulich meine neuste Erfindung, den Schrotthäscher X6000, fertig stellen können!$B$BUnd Ihr habt die Ehre, mir dabei zu helfen, ihn zu testen. Dann können wir ihn zur Verteidigung von Area 52 einsetzen!", 26972);

-- 10248 - Du, der Roboter
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10248 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10248, "deDE", "Was meint Ihr? Muss noch ein wenig optimiert werden, was?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10248 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10248, "deDE", "Nun, mein Junge, das war aber aufregend! Und meiner Meinung nach hat der Schrotthäscher X6000 trotz seines Grünschnabelpiloten gut funktioniert.$B$BHehe, seid nicht beleidigt, ich mache nur Witze. Schließlich habt Ihr gerade Area 52 und die X-52 Netherrakete vor dem sicheren Untergang bewahrt!", 26972);

-- 10249 - Zurück zum Chef!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10249 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10249, "deDE", "$N! Oder sollte ich sagen Juniortechniker ersten Grades $N?! Ach, wem mache ich etwas vor. Einen Grad zu überspringen ist keine angemessene Belohnung für das, was Ihr getan habt. Ich ernenne Euch zu meinem Ersten Offizier!$B$BIhr habt uns alle gerettet, und noch viel wichtiger, die X-52 Netherrakete! Ich könnte Euch küssen... aber das tue ich nicht.$B$BLasst mich Euch stattdessen die Dankbarkeit von Area 52 zeigen. Wählt etwas aus!", 26972);

-- 10256 - Den Schlüsselmeister finden
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10256 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10256, "deDE", "<Ihr beschreibt, was Ihr gesehen habt.>$B$BKommandantin Sarannis sagt Ihr? Hmm...$B$BSie ist eine von Kael'thas Beratern, aber ganz sicher keine Magierin. Ich kenne sie von dem Angriff auf Kirin'Var. Ich glaube, Ihr habt Recht, $N. Sie mag den Fluch vielleicht nicht selbst aufrechterhalten, aber sie hat den Schlüssel zum Schild.", 26972);

-- 10257 - Den Schlüsselstein erobern
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10257 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10257, "deDE", "Habt Ihr den Schlüsselstein?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10257 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10257, "deDE", "<Die Augen des Erzmagiers leuchten auf, als Ihr ihm den Schlüsselstein gebt.>$B$BErstaunlich! Nach dem, was ich von Farahlons Schicksal erblickt habe, bin ich mir nicht sicher, ob ich hinaus will, aber es ist immerhin besser, als für den Rest meiner Tage hier eingesperrt zu sein.", 26972);

-- 10261 - GESUCHT: Vernichterservo!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10261 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10261, "deDE", "Ich hoffe, Ihr kommt wegen meiner Suchanzeige!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10261 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10261, "deDE", "Juhuu! Wisst Ihr, wie schwer man an diese Dinge herankommt? Es ist ja nicht so, als ob ich hier draußen täglich eine Teilelieferung bekommen würde.$B$BWisst Ihr was? Als Belohnung lasse ich Euch etwas aus meiner Kramkiste nehmen. Es ist sicher etwas darin, was Ihr brauchen könnt. Wenn nicht, verkauft es einfach weiter.$B$BIn Ordnung, lasst mich das Euch abnehmen und in meinen langhalsigen Spektrumanalysator einbauen, bevor der alte Servo noch explodiert!", 26972);

-- 10262 - Ein Hügel voll Astraler
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10262 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10262, "deDE", "Ist es vollbracht? Habt Ihr den Abschaum der Zaxxis vom Angesicht der Scherbenwelt ausgerottet und mir ihre Insignien gebracht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10262 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10262, "deDE", "Diese Insignien sind ein guter Anfang.$B$BUnglücklicherweise haben meine anderen Agenten bei den Zaxxis berichtet, dass Sphärenräuber Nesaad immer noch am Leben ist!", 26972);

-- 10263 - Dem Konsortium helfen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10263 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10263, "deDE", "Hallo, $R.$B$BIhr steht steht nicht zufällig für eine wichtige Bergungsmission zur Verfügung?", 26972);

-- 10264 - Dem Konsortium helfen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10264 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10264, "deDE", "Hallo, $R.$B$BIhr steht steht nicht zufällig für eine wichtige Bergungsmission zur Verfügung?", 26972);

-- 10265 - Kristallsammlung des Konsortiums
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10265 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10265, "deDE", "Ich habe den Eindruck, dass der Prinz nach einem ganz bestimmten Kristall sucht, aber ich bin mir nicht sicher, welcher das ist.$B$BHabt ihr dem Schreckenslord schon seinen abgenommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10265 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10265, "deDE", "Lasst mich ihn mal ansehen.$B$BHmm, er scheint nicht besonders zu sein. Ich bezweifle, dass er das ist, obwohl Eure Beschreibung der Vorgehensweisen der Legion in den Ruinen den Anschein erweckt, dass auch sie nach etwas ganz Bestimmten suchen.$B$BWollen wir hoffen, dass es nicht der Kristall ist, den der Nexusprinz so unbedingt haben will.", 26972);

-- 10266 - Bitte um Unterstützung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10266 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10266, "deDE", "Ja, es ist wahr. Die Blutelfen weigern sich auch dieses Mal, die Waren, die ihnen schon geliefert wurden, zu bezahlen.$B$BDa Netherpirscher Khay'ji Euch geschickt hat, hoffe ich, dass Ihr mir bei dieser Angelegenheit helfen könnt.", 26972);

-- 10267 - Rechtmäßiger Besitz
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10267 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10267, "deDE", "Habt Ihr die Vermessungsausrüstung, um die uns die Blutelfen betrogen haben?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10267 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10267, "deDE", "Nun, ich bin froh, dass wir dieses kleine Geschäft abgeschlossen haben. Ich kann mich nicht erinnern, dass das Konsortium je Geschäfte mit solch flegelhaften und unseriösen Wesen gemacht hätte.$B$BIhr scheint jedoch vertrauenswürdig zu sein, $N. Vielleicht wollt Ihr mir ja noch einen Gefallen tun?", 26972);

-- 10268 - Eine Audienz beim Prinzen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10268 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10268, "deDE", "Tretet näher.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10268 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10268, "deDE", "Ich heiße Euch in der Sturmsäule willkommen, $C. Bitte genießt die Gastfreundschaft des Konsortiums.$B$BDie Ausrüstung könnt Ihr irgendwo abstellen. Ich nehme an, dass Ihr sie schon sehr bald wieder mitnehmen werdet.", 26972);

-- 10269 - Triangulationspunkt Eins
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10269 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10269, "deDE", "Hallo, Reisender. Seid Ihr zu Hazzin gekommen, weil Ihr meine Waren begehrt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10269 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10269, "deDE", "<Händler Hazzin senkt seine Stimme zu einem Flüstern.>$B$BAh, ich weiß von Eurem Auftrag. Er ist für Nexusprinz Haramad äußerst wichtig.$B$BJetzt, da wir die Position des ersten Triangulationspunktes herausgefunden haben, müssen wir schnell den zweiten suchen!", 26972);

-- 10270 - Ein nicht-so-bescheidenes Angebot
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10270 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10270, "deDE", "Seid Ihr bereit über das Geschäft zu reden, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10270 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10270, "deDE", "Diese Energiezelle sollte für unsere Zwecke ausreichen. Sobald das Geld zu fließen beginnt, werden wir ihn noch weiter verbessern.$B$BDoch genug davon. Jeder mit Diskussionen verschwendete Augenblick bedeutet verlorenen Gewinn.", 26972);

-- 10271 - Zur Sache
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10271 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10271, "deDE", "Man stelle sich nur vor, dass dieser erbärmliche Astrale diese Essenzen wie Süßigkeiten an die Blutelfen verkaufen wollte...", 26972);

-- 10272 - Ein viel versprechender Anfang
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10272 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10272, "deDE", "Konntet Ihr die Eier sammeln?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10272 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10272, "deDE", "Die sollten ihren Zweck erfüllen, $N. Vielen Dank, dass Ihr uns geholfen habt.$B$BBevor wir weitermachen können gibt es jedoch noch etwas anders, worüber wir sprechen müssen.", 26972);

-- 10273 - Störende Ablenkung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10273 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10273, "deDE", "Jetzt, da dieser lästige Astrale beseitigt ist, können wir uns darauf konzentrieren, die Netherdrachen besser verstehen zu lernen. Ich konnte die Eier untersuchen und habe dabei einiges herausgefunden.", 26972);

-- 10274 - Den Sternensturz sichern
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10274 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10274, "deDE", "Habt Ihr Veraku schon herausgefordert und getötet?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10274 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10274, "deDE", "Gut gemacht, $N. Wirklich gut gemacht. Die Netherdrachkin werden zu Anfang keinen blauen Drachen in ihren Reihen akzeptieren, aber wenn ich meine Autorität beweise, werden sie sich fügen. Zerschlagen, isoliert und ohne Führung sind sie leichte Beute für bösartige Mächte. Wir müssen daher regelmäßig ein Auge auf sie werfen.", 26972);

-- 10275 - Triangulationspunkt Zwei
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10275 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10275, "deDE", "Wollt Ihr kaufen oder verkaufen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10275 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10275, "deDE", "Sehr gut, in der Tat. Der Nexusprinz wird zufrieden sein.$B$BJetzt haben wir den zweiten Punkt, der uns den dritten und damit die Umgebung, in der sich der Kristall befindet, verraten wird.", 26972);

-- 10276 - Das volle Dreieck
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10276 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10276, "deDE", "Willkommen zurück, Freund. Wie geht es mit der Suche nach dem Kristall voran?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10276 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10276, "deDE", "In meinen wildesten Träumen habe ich nicht gedacht, dass Ihr den Kristall tatsächlich beschaffen könnt!$B$BUnd Ihr gebt mir ihn sogar! Habt Ihr eine Ahnung, wie mächtig er ist?$B$BEure Selbstlosigkeit ist sehr inspirierend und unvergleichlich, $N! Ihr habt mir viel zum Nachdenken gegeben.", 26972);

-- 10280 - Sonderlieferung nach Shattrath
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10280 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10280, "deDE", "<Das musikalische Klingen der Naarusprache erfüllt Euren Geist.>$B$BIch spüre, dass Ihr einen Gegenstand von großer Macht bei Euch tragt, $R. Was bringt Ihr mir?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10280 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10280, "deDE", "Ihr habt mir den Gesang der Geister zurückgebracht! Prophet Velen hat den Kristall von Ata'mal zur Sicherheit bei seinem Volk zurückgelassen, bevor er auf seine schicksalsträchtige Mission zur Exodar ging.$B$BMerkwürdig, dass er nicht vorhergesehen hat, dass er in die Hände der Brennenden Legion fallen würde, wenn auch nur für kurze Zeit.$B$BOder vielleicht hat er das ja? Es könnte sein, dass er all dies vorhergesehen hat, und ihn dort ließ, damit Ihr ihn mir bringen könnt.$B$BIch spüre, dass dies die Wahrheit ist. Ihr seid ein großer Held unseres Volkes, $N.", 26972);

-- 10281 - Formelle Vorstellung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10281 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10281, "deDE", "Mein Name ist Tyrygosa von Malygos' Brut, aber nennt mich einfach Tyri. Mein Begleiter ist der Paladin Jorad Knüpp.$B$BDie Kunde von den merkwürdigen Drachkin hier verbreitet sich schnell, und ich fürchte, dass sehr viele kommen werden, um sie auszubeuten, bevor sie überhaupt ihre wahre Natur erkannt haben. Wir hoffen, dass wir mit Eurer Hilfe diese Kreaturen kennenlernen können, bevor andere von ihnen erfahren.", 26972);

-- 10290 - Auf der Suche nach Farahlit
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10290 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10290, "deDE", "Ich bin mir bewusst, dass das Sammeln von Farahlit sehr gefährlich ist, aber die Möglichkeiten sind gewaltig. Ein Händler, der nicht bereit ist, Risiken auf sich zu nehmen, kann seine Türen gleich schließen und sich den Ärger ersparen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10290 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10290, "deDE", "Ah ja, genau die Qualität, die ich mir erhofft habe. Wenn wir genügend Nachschub von den Riesen bekommen, brauchen wir die Kristalle nicht mehr abbauen.", 26972);

-- 10293 - Die Kristallader anzapfen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10293 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10293, "deDE", "Ihr seid immer noch am Leben, was bedeutet, dass Ihr entweder den Kern besorgt oder Eure Meinung geändert habt. Was davon stimmt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10293 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10293, "deDE", "Gut gemacht! Ich kann kaum abwarten, es auszuprobieren.", 26972);

-- 10299 - Manaschmiede B'naar abschalten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10299 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10299, "deDE", "Wart Ihr bei Eurer Aufgabe erfolgreich, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10299 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10299, "deDE", "Das Licht ist Euch wohlgesinnt, $N. Wir haben alle für Euren Erfolg gebetet.", 26972);

-- 10300 - Den Stab wiederherstellen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10300 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10300, "deDE", "Habt Ihr schon ein paar geeignete Kristalle für ein neues Kopfstück des Stabs gefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10300 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10300, "deDE", "<Ravandwyr untersucht die Kristalle genau und wählt dann einen aus.>$B$BDieser Kristall sollte funktionieren. Ich werde den Sockel des Stabs umformen, damit das neue Kopfstück passt.$B$BErzmagier Vargoth wird enttäuscht sein, wenn er ihn sieht, aber ich bin bereit, die Enttäuschung meines Meisters in Kauf zu nehmen, wenn er nur endlich wieder frei ist.", 26972);

-- 10301 - Das Kompendium öffnen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10301 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10301, "deDE", "Habt Ihr das Oculus besorgt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10301 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10301, "deDE", "Ausgezeichnet, $N. Jetzt haben wir fast alles, was wir benötigen, um Kael'thas' Magie zu durchbrechen.$B$BUnd wenn die Blutelfen unter dem Verlust ihres Kommandanten hier leiden, dann umso besser.", 26972);

-- 10305 - Bannzauberin Belmara
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10305 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10305, "deDE", "Ja, ich habe davon gehört, dass Bannzauberin Belmara ein altes Buch mit Geschichten hatte, aber ich wusste nicht, dass sie es mit in die Scherbenwelt gebracht hatte. Ich bin mir sicher, dass ihr Geist nun, da Ihr es gefunden und zurückgebracht habt, ruhen kann.", 26972);

-- 10306 - Beschwörer Luminrath
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10306 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10306, "deDE", "Wir haben immer Scherze darüber gemacht, dass Luminrath zu allem diesen Mantel tragen würde. Für ihn passte Rot genauso gut zu Weiß wie zu Schwarz, Violett, Blau, Gelb, Orange und Grün. Er hätte niemals zwei Tage hintereinander dieselbe Robe getragen, aber der Mantel war immer dabei...", 26972);

-- 10307 - Cohlien Frostwirker
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10307 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10307, "deDE", "<Der Hüter lächelt, als Ihr Cohliens Name erwähnt.>$B$BIhr habt absolut Recht mit der Kappe. Er trug sie die ganze Zeit und lies sie nicht aus den Augen.$B$BEin paar Mal hat sich einer seiner Kollegen die Kappe ausgeliehen und sie zum Scherz versteckt. Ich brauche nicht zu erwähnen, dass die Androhung eines Frostblitzes von Cohlien ihn schnell zum Umdenken bewegt hat.$B$BIch werde den kleinen Cohlien vermissen. Er war sehr beliebt bei den Elfendamen.", 26972);

-- 10308 - Noch ein Hügel voller Astraler
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10308 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10308, "deDE", "Das Konsortium ist sehr daran interessiert, alle Rebellen der Zaxxis beim Hügel im Süden auszulöschen.$B$B$C, wenn Ihr Euch bei uns noch beliebter machen wollt, dann geht zurück und besorgt noch mehr ihrer Insignien.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10308 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10308, "deDE", "Verräter, alle!$B$BGute Arbeit, $C! Wenn Ihr nochmals dort hinunter gehen solltet, bin ich immer noch auf der Suche nach weiteren Insignien für meine Sammlung.", 26972);

-- 10309 - Teufelshäscher mit Herz
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10309 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10309, "deDE", "Meine Augen müssen von der ganzen Netherstrahlung hier schlechter werden. Habt Ihr schon das Herz des Teufelshäschers?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10309 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10309, "deDE", "Wow, schaut Euch das an... ein schlagendes Teufelshäscherherz! Nun, es schlägt nicht wirklich, aber Ihr wisst schon, was ich meine.$B$BIch kann es kaum abwarten, dieses Ding zu benutzen. Oder ich verkaufe es. Ich kenne ein paar Depp... äh Kunden, die daran interessiert sein könnten.$B$BHier, Ihr habt Euch die Belohnung verdient!", 26972);

-- 10310 - Sabotage am Warptor!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10310 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10310, "deDE", "Das sind ausgezeichnete Neuigkeiten, mein Freund!$B$BIhr und Drijya haben uns einen großen Dienst erwiesen. Jetzt, da das Warptor außer Gefecht ist, können die Dämonen in der Nähe keine Verstärkung mehr holen.$B$BBitte erlaubt mir, Euch in der Art des Konsortiums zu belohnen.", 26972);

-- 10311 - Drijya braucht Eure Hilfe
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10311 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10311, "deDE", "Ich hoffe, dass Gahruj Euch hierher geschickt hat, um mir bei meinem Auftrag zu helfen.", 26972);

-- 10312 - Die Annalen von Kirin'Var
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10312 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10312, "deDE", "Konntet Ihr das Stadtregister finden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10312 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10312, "deDE", "<Hüter Dierwert nimmt Euch das Buch ab und blättert es durch.>$B$BHmm...$B$BSieht aus, als hätte ich Recht gehabt. Es scheint ein Muster zu geben.$B$BDie aggressivsten und gefährlichsten Geister stimmen mit den mächtigsten und hochrangigsten Kirin Tor, die in dem Dorf gelebt haben, überein. Dagegen scheint man die Dorfleute und Händler übersehen zu haben. Was könnte das bedeuten?", 26972);

-- 10313 - Warpenergien messen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10313 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10313, "deDE", "Das sind schlimme Nachrichten, $N. Die Warpenergien, die aus den Rohren herausströmen, sind gefährlich hoch.$B$BWir müssen einen Weg finden, um die Manaschmieden abzuschalten, oder der kleine Rest, der noch von der Scherbenwelt übrig ist, wird in tausend Stücke gesprengt.", 26972);

-- 10314 - Ein hartnäckiger Verdacht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10314 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10314, "deDE", "Was habt Ihr herausgefunden, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10314 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10314, "deDE", "<Wächter Dierwert untersucht die Überreste.>$B$BDas Gerät, das Ihr beschreibt, klingt nach einem nekromantischen Fokus... Ich hätte wissen sollen, dass dieser bösartige Lehrling sich dazu herablassen würde. Ich dachte, seine Ausbildung würde ihn daran hindern, so weit zu gehen, aber ich schätze, ich habe mich getäuscht.", 26972);

-- 10315 - Die Nethermanten neutralisieren
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10315 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10315, "deDE", "Alles, was wir tun, um sie von ihren Taten in den Manaschmieden abzuhalten, ist gut.$B$BMan kann offenbar nicht vernünftig mit ihnen reden. Und was auch immer ihre Anführer vorhaben, sie müssen verrückt sein.$B$BAls Belohnung für Eure treuen Dienste für die Ziele des Konsortiums möchte ich Euch in Eurer Landeswährung bezahlen, wenn Ihr nichts dagegen habt.", 26972);

-- 10316 - Auf der Suche nach Beweisen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10316 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10316, "deDE", "Eine leuchtende Kugel liegt auf einem quadratischen Podest. Auf den ersten Blick scheint sie ein Behältnis für magische Energie zu sein, aber welche Art von Energie und zu welchem Zweck?", 26972);

-- 10317 - Den Großknecht erledigen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10317 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10317, "deDE", "<Der Großknecht flüstert.>$B$BSeid Ihr hier, um mich zu töten? Hmm. Nun, ich glaube, die Astralen wissen nicht alles, was?$B$BIch bin nicht der, den Ihr sucht, glaubt mir.", 26972);

-- 10318 - Den Übermeister erledigen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10318 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10318, "deDE", "Ein Verdammniswachenübermeister? Das ist merkwürdig! Was macht denn die Brennende Legion dort?$B$BHm, einige der Blutelfen werden also abtrünnig. Wir werden das im Hinterkopf behalten, falls wir uns je entschließen sollten, den Ort mit Gewalt einzunehmen. Zumindest sind das ein paar gute Nachrichten, oder?$B$BBitte, $N, nehmt dieses Zeichen meiner Dankbarkeit.", 26972);

-- 10319 - Das Phylakterium entwenden
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10319 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10319, "deDE", "Wir müssen erst Naberius' Phylakterium beschaffen, bevor wir ihn angreifen können. Er ist sonst unverwundbar!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10319 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10319, "deDE", "Ausgezeichnete Arbeit, $N. Der Besitz des Phylakteriums ist der Schlüssel zu unserem Sieg. Wenn Ihr gegen Naberius in die Schlacht zieht, werde ich es zerstören und ihn so für Eure Angriffe verwundbar machen.", 26972);

-- 10320 - Vernichtet Naberius!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10320 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10320, "deDE", "Der Sieg über Naberius ist eine große Leistung, $N. Ich kann mir nicht helfen, aber ich glaube, wir hätten eine Chance gegen Kael'thas' Streitkräfte gehabt, wenn der Lehrling auf der richtigen Seite gestanden hätte.", 26972);

-- 10321 - Manaschmiede Coruu abschalten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10321 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10321, "deDE", "Habt Ihr Eure Aufgabe schon erledigt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10321 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10321, "deDE", "Ausgezeichnete Arbeit. Jetzt sind nur noch zwei Manaschmieden aktiv.$B$BBald wird Kael'thas von seiner Hauptenergiequelle abgeschnitten sein.", 26972);

-- 10322 - Manaschmiede Duro abschalten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10322 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10322, "deDE", "Habt Ihr Eure Aufgabe schon erledigt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10322 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10322, "deDE", "Ihr seid von den Naaru gesegnet, $N. Euer Einsatz für die Sache wird nicht unbemerkt oder unbelohnt bleiben.", 26972);

-- 10323 - Manaschmiede Ara abschalten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10323 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10323, "deDE", "Habt Ihr die Aufgabe, die ich Euch gegeben habe, schon erledigt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10323 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10323, "deDE", "Die Brennende Legion? Verbündet mit Kael'thas Sonnenwanderer?$B$BDas sind erschütternde Nachrichten. Das erklärt vieles, was wir hier und in Schattenmond beobachtet haben.$B$BWir müssen Shattrath sofort informieren.", 26972);

-- 10328 - Anweisungen des Sonnenzorns
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10328 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10328, "deDE", "Hattet Ihr Glück mit den Anweisungen der Manaschmiede Duro?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10328 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10328, "deDE", "Ausgezeichnete Arbeit, $N! Wollen wir mal schauen, was uns diese Anweisungen verraten.", 26972);

-- 10329 - Manaschmiede B'naar abschalten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10329 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10329, "deDE", "Hat der Plan funktioniert? Ehrlich gesagt habe ich fast befürchtet, dass Ihr in die Luft gejagt werdet.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10329 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10329, "deDE", "Natürlich hat es funktioniert! Ich bin Spionagemeister, meine Informationen sind immer genau.$B$BWie auch immer, da wartet ein brandneuer und spannender Auftrag auf Euch. Wollt Ihr davon hören? Natürlich wollt Ihr das.", 26972);

-- 10330 - Manaschmiede Coruu abschalten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10330 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10330, "deDE", "Habt Ihr Eure Aufgabe schon erledigt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10330 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10330, "deDE", "Wir haben den Aufruhr gehört und wollten gerade gehen. Ich bin froh, dass Ihr nicht allzu viel Prügel einstecken musstet.", 26972);

-- 10331 - Unverzichtbare Werkzeuge
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10331 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10331, "deDE", "Hattet Ihr Glück bei der Suche nach meinem Hammer?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10331 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10331, "deDE", "Dem Himmel sei Dank! Jetzt kann ich zurück an die Arbeit. Ich weiß, dass Ihr denkt, dass ich verrückt bin, so weit von einer richtigen Schmiede an meinem Gesellenstück zu arbeiten, aber ich darf nicht riskieren, dass die anderen Lehrlinge meine Entwürfe stehlen.", 26972);

-- 10332 - Meisterschmied Rhonsus
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10332 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10332, "deDE", "Meister Rhonsus hat mir alles beigebracht, was ich über mein Handwerk wissen muss. Ich werde seine Erinnerung in Ehren halten, indem ich den Leuten von Kirin'Var mit meinem Geschick diene.", 26972);

-- 10333 - Helft Mama Mauschel
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10333 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10333, "deDE", "Was? Er hat mich seine Partnerin genannt? Ich bin seine Frau!$B$BUnd er sagt, ich hätte eine scharfe Zunge. Oh, wenn ich zurück nach Area 52 komme, werde ich ihm die großen grünen Ohren langziehen!$B$BAber ich bin froh, dass Ihr hier seid. Mit einer Sache hatte er Recht; ich kann ganz sicher Eure Hilfe brauchen!", 26972);

-- 10334 - Braucht mehr Kuhglocke
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10334 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10334, "deDE", "<Die Kuh schaut Euch misstrauisch an, bleibt aber stehen.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10334 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10334, "deDE", "<Als Ihr die Glocke aus Eurer Tasche holt, läutet Ihr sie ein paar Mal und zeigt sie Bessy, die sie zu erkennen scheint. Die Kuh lässt zu, dass Ihr ihr die Glocke um den Hals hängt und schaut Euch erwartungsvoll an.>", 26972);

-- 10335 - Die Ruinen beobachten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10335 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10335, "deDE", "Das ging aber schnell. Ihr müsst sehr effektiv arbeiten, wenn Ihr alle drei Markierungen schon aufgestellt habt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10335 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10335, "deDE", "Ihr wollt mir keinen Bären in die Bandagen binden, oder? Das sind ausgezeichnete Nachrichten!$B$BJetzt, da Ihr die Routinearbeiten für die Vermessung für mich ausgeführt habt, kann ich mein Team in die Ruinen führen und schauen, was wir bergen können.$B$BIhr habt meinen Dank, $C.", 26972);

-- 10336 - Diener von Culuthas
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10336 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10336, "deDE", "Wirklich ausgezeichnete Arbeit.$B$BJetzt, da die Dämonen von Culuthas tot sind, kann Zephyrion mit seinem Ausgrabungsteam sicher in die Ruinen von Farahlon zurückkehren.$B$BNehmt dies als Zeichen meiner Dankbarkeit.", 26972);

-- 10337 - Almabtrieb
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10337 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10337, "deDE", "Bessy, bist Du das?$B$B<Der Bauer dreht sich zu Euch um.>$B$BVielen Dank, dass Ihr mir meine Bessy zurückgebracht habt, $N. Ich könnte ohne sie nicht leben!", 26972);

-- 10338 - Manaschmiede Duro abschalten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10338 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10338, "deDE", "Habt Ihr die Konsole abgeschaltet? Ihr solltet Euch beeilen, bevor ich meine Meinung dazu ändere.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10338 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10338, "deDE", "Jetzt habt Ihr schon drei Manaschmieden abgeschaltet, $N. Kael'thas muss sich gerade furchtbar über Euch aufregen.", 26972);

-- 10339 - Das Astraleum
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10339 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10339, "deDE", "Wir müssen alle Daten, die sie in diesem Gebiet aufbewahren, sammeln.", 26972);

-- 10341 - Tretet sie, solange sie am Boden liegen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10341 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10341, "deDE", "Das habt Ihr gut gemacht, $N. Kaels Armee wird sich nicht so leicht von diesem Schlag erholen.", 26972);

-- 10342 - Schieferhautschiefer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10342 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10342, "deDE", "Habt Ihr schon genug Schiefer? Ich brauche eine ganze Menge, wenn ich genug Öl für den Raketentreibstoff der X-52 herstellen will.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10342 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10342, "deDE", "Ok! Zutat Nummer eins erledigt.$B$BWenn Ihr noch Lust habt, besorgen wir jetzt etwas, das dem Schieferöl den kleinen Extrakick gibt, um die Rakete in den Wirbelnden Nether zu katapultieren... oder in Stücke zu sprengen, was immer zuerst geschehen mag.", 26972);

-- 10343 - Die unendliche Invasion
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10343 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10343, "deDE", "Habt Ihr die Überreste der Waffe, die Kael'thas gegen das Dorf eingesetzt habt, gefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10343 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10343, "deDE", "Eine Manabombe?$B$B<Morran dreht das Fragment in den Händen.>$B$BEs ist unglaublich! Sogar die hellsten Köpfe in Dalaran hätte eine Waffe wie diese nicht entwerfen können. Das schiere Ausmaß der Explosion muss einen Riss im Nether geöffnet und diesen Kreaturen einen Zugang zu unserem Land verschafft haben.", 26972);

-- 10345 - Fleisch geworden
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10345 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10345, "deDE", "Konntet Ihr Sechs-Uhr finden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10345 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10345, "deDE", "Ihr habt meine Bandagen gerettet, $N. Dass Protektorat wird erfahren, was Ihr heute getan habt, Freund.", 26972);

-- 10348 - Neue Möglichkeiten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10348 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10348, "deDE", "Konntet Ihr die Pflanzen sammeln?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10348 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10348, "deDE", "Interessante Wahl, oder? Die heilende Wirkung der Pflanze muss überragend sein. Ich bekomme eine Menge Geld für eine Blume, die eine der unspektakulärsten der Kuppeln ist.", 26972);

-- 10353 - Arconus der Unersättliche
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10353 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10353, "deDE", "Und Sechs-Uhr? Hat er es geschafft?$B$BWollen wir verdammt noch mal hoffen. Ich konnte keine Verstärkung zu ihnen schicken... Das Astraleum hat nun die ganze Gegend in Beschlag genommen.$B$BEntschuldigt, fast hätte ich Eure Belohnung vergessen.", 26972);

-- 10365 - Manaschmiede Ara abschalten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10365 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10365, "deDE", "Habt Ihr die Aufgabe, die ich Euch gegeben habe, schon erledigt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10365 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10365, "deDE", "Die Brennende Legion? Unter einer Decke mit Kael? Daran wird Voren'thal sicher seine Freude haben.$B$BDenkt ihr, dass Tausende von Pilgern von Azeroth hierher kommen, um sich mit der Brennenden Legion zu verbünden? Ich glaube kaum!", 26972);

-- 10380 - Ein dunkler Pakt
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10380 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10380, "deDE", "Es ist also vollbracht. Wir kommen im Auftrag unserer Herren hierher, jagen und töten sie. Es gibt kein Pardon.$B$BManchmal gibt das einem zu denken.", 26972);

-- 10381 - Nie mehr Aldor
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10381 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10381, "deDE", "Die schlechten Nachrichten, die Ihr mir bringt, erfüllen mein Herz mit Traurigkeit. Zwei unserer tödlichsten Feinde schließen sich zusammen und einer der teuersten Söhne Shattraths hat seinen Glauben verloren.", 26972);

-- 10384 - Daten der Astralen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10384 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10384, "deDE", "Habt Ihr die Datenzelle sichergestellt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10384 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10384, "deDE", "<Ihr haltet die Datenzelle so, dass Ameer die Pläne lesen kann.>$B$BNichts... Verdammt! Sie sind klug, aber nicht so klug wie Ameer!$B$BWorum ich Euch nun bitte, wird etwas gefährlich werden. Ich kann verstehen, wenn Ihr nicht weitermachen wollt, Fleischling.", 26972);

-- 10385 - Hirnschadengefahr = hoch
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10385 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10385, "deDE", "Habt Ihr die Melderdaten schon besorgt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10385 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10385, "deDE", "Der Existenzgrund des Protektorats ist nun vollkommen bestätigt.$B$BDas Astraleum ist nicht hier, um Dimensius zu jagen! Sie sind hier, um Leere zu werden!$B$BSie manipulieren die Leerenergien bei dieser Manaschmiede um ihre eigenen Energien an eine Kreatur namens Dunkelpirscher zu binden.$B$BSie benutzen sicherlich einen Protobeschleuniger um die Umwandlung zu vervollständigen.", 26972);

-- 10405 - S-A-B-O-T-A-G-E
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10405 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10405, "deDE", "Habt Ihr die Bandage besorgt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10405 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10405, "deDE", "Ausgezeichnet! Jetzt kann ich das Gerät einstellen.", 26972);

-- 10406 - Die Nachricht überbringen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10406 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10406, "deDE", "Dank Euch sind ihre Pläne gescheitert! Jetzt bleibt nur noch Eines übrig... Salhadaar.", 26972);

-- 10407 - Socrethars Schatten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10407 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10407, "deDE", "Habt Ihr Socrethars Teleportationsstein schon besorgt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10407 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10407, "deDE", "Eure Aufopferung für unsere Sache ist beispielhaft, $N. Jetzt, da wir Socrethars Teleportationsstein in unserem Besitz haben, gibt es nur noch Eines zu tun.", 26972);

-- 10408 - Nexuskönig Salhadaar
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10408 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10408, "deDE", "Ist... Ist er wirklich tot? Vernichtet?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10408 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10408, "deDE", "Seit tausend Jahren, vielleicht mehr, führt Salhadaar nun seinen Kreuzzug, bei dem er alles vernichtet, was ihm im Weg steht. Ich kann kaum glauben, dass wir ihn nun zum letzten Mal gesehen haben... Ihr habt uns einen großen Dienst erwiesen, $N, und dafür sollt Ihr belohnt werden.", 26972);

-- 10409 - Todesstoß für die Legion
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10409 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10409, "deDE", "Das Licht sei mit Euch, $C.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10409 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10409, "deDE", "Es ist vollbracht, $N. Socrethar wurde vernichtet.$B$BIch und die anderen werden uns von unseren Wunden erholen, $N. Der Zorn der Magie Socrethars war jedoch zu viel für den jungen Kaylaan. Nicht einmal meine stärksten Gebete konnten ihn wiederbeleben.$B$BEs ist unendlich schade, dass jemand, der so jung ist, in der Schlacht sterben musste. Am Ende war jedoch sein Wille stark genug, um sich von der Verderbtheit der Legion zu erholen. Dies soll uns ein Trost sein.", 26972);

-- 10410 - Ishanahs Hilfe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10410 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10410, "deDE", "Was bereitet Euch Kummer, Kind?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10410 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10410, "deDE", "Socrethar... Ich erinnere mich an den Namen. Er war einst ein berühmter Krieger des Lichts. Sein einziger Fehler war sein Stolz.", 26972);

-- 10411 - Elektroschock!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10411 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10411, "deDE", "Sowohl der Schlick als auch der Abschaum sind extrem giftig. Wenn wir uns nicht um sie kümmern, verwandeln sie sich in erstarrte Leerenschrecken!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10411 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10411, "deDE", "Ich hoffe, es ist nicht zu spät. Habt Ihr irgendwelche abnormal große Schleime in der Gegend des Leerenabschaums gesehen?", 26972);

-- 10413 - Die Schrecken der Verschmutzung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10413 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10413, "deDE", "Hm, Ihr seht dreckig aus... Was ist geschehen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10413 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10413, "deDE", "WAS!? Ihr habt gegen einen Leerenschrecken gekämpft? Und überlebt?! Unglaublich!$B$BDiese Probe ist ihr Gewicht in Gold wert. Ein Fund wie dieser verlangt eine Belohnung.", 26972);

-- 10417 - Führt eine Diagnose durch!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10417 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10417, "deDE", "Habt Ihr die Diagnoseergebnisse?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10417 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10417, "deDE", "<Mehrdad nickt und betrachtet die Diagnoseergebnisse.>$B$BDas ist beunruhigend. Der Schaden ist größer, als ich befürchtet habe. Ich kann mir aus der Sturmsäule einige Werkzeuge schicken lassen, um Reparaturen durchzuführen, aber das ist sinnlos, wenn wir nicht einmal wissen, was den Schaden verursacht hat.", 26972);

-- 10418 - Die Saboteure ausschalten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10418 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10418, "deDE", "Das Gebiet sieht schon aufgeräumter aus. Die Kuppeln sind sehr hilfreich, aber ein großer Nachteil ist der unkontrollierte Wuchs, den sie an manchen Orten begünstigen, der die einheimischen Arten schneller wachsen und sich schneller vermehren lässt.", 26972);

-- 10421 - Teuflische Waffen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10421 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10421, "deDE", "Habt Ihr in letzter Zeit ein paar teuflische Waffen gefunden? Lasst das Licht seine Wirkung tun, $N. Erlaubt diesen verderbten Dingen nicht, in dieser Welt zu verweilen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10421 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10421, "deDE", "Die teuflischen Materialien wurden aus dieser Welt entfernt. Nur das Licht bleibt.", 26972);

-- 10422 - Hauptmann Tyralius
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10422 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10422, "deDE", "Danke, $N. Tyralius hat schwere Wunden erlitten, aber wir denken, dass er es schaffen wird.$B$BEr hat ganze Felder voller Gefängnisse erwähnt, die so ähnlich sind wie das, aus dem Ihr ihn errettet habt. Gefängnisse voller Kreaturen aus dem ganzen Universum!$B$BWir werden uns bei Euch melden, wenn wir entschließen sollten, sie zu öffnen. Das Konsortium hat schon angemeldet, dass sie planen, ein paar Teams dorthin zu schicken. Sie arbeiten bereits an einer Technologie, mit der sie die Schlösser des Astraleums aufbrechen können.", 26972);

-- 10423 - Zur Sturmsäule
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10423 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10423, "deDE", "<Ihr stellt Euch vor und meldet die Ergebnisse von Mehrdads Diagnose bei der Biokuppel Mittelreich.>$B$BMehrdad ist nur ein einfacher Techniker, aber er hat ein gutes Auge fürs Detail. Wenn seine Beobachtungen richtig sind, müssen wir auch bei den restlichen Kuppelgeneratoren so schnell wie möglich Diagnosen durchführen.", 26972);

-- 10424 - Diagnose: kritisch
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10424 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10424, "deDE", "Habt Ihr die Diagnoseergebnisse?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10424 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10424, "deDE", "Diese Ergebnisse entsprechen denen von Mehrdad genau, aber warum? Der einzige Grund, den ich mir vorstellen kann, ist, dass etwas von der Ausrüstung der Kuppelgeneratoren kaputtgegangen ist oder fehlt. Das würde dazu führen, dass die Kuppeln stark geschwächt werden und aus dem Gleichgewicht geraten, so wie es in der Diagnose deutlich wird.", 26972);

-- 10425 - Ausbruch aus dem Stützpunkt
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10425 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10425, "deDE", "<Kommandant Ameer scheint zufrieden zu sein.>$B$BGut gemacht, Fleischling! Dieser Soldat ist vielleicht der Schlüssel zur Vereitelung aller Pläne des Astraleums.", 26972);

-- 10426 - Flora der Biokuppel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10426 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10426, "deDE", "Habt Ihr schon versucht, die Energie der Kuppel zu fokussieren?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10426 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10426, "deDE", "Oh je! Die Energie der Kuppel zu bündeln hat zur Folge, dass die Kreaturen bis zu dem Punkt wachsen, an dem sich eine große Aggressivität entwickelt. Wenn wir die Möglichkeit bekommen, diese Technologie einzusetzen, müssen wir sie auf jeden Fall richtig einstellen.", 26972);

-- 10427 - Fauna der Biokuppel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10427 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10427, "deDE", "Konntet Ihr ausreichend viele Talbuks markieren?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10427 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10427, "deDE", "Ausgezeichnete Arbeit. Ich werde die, die Ihr markiert habt, genau im Auge behalten, um zu beobachten, ob sie genauso schnell wie die anderen Lebensformen in der Kuppel wachsen.$B$BMit der richtigen Überwachung könnten wir diese Technologie benutzen, um die zerstörten Gegenden in der Scherbenwelt und Azeroth wiederzubeleben.", 26972);

-- 10429 - Wenn die Natur zu weit geht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10429 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10429, "deDE", "Habt Ihr eine Probe von der monströsen Hydra?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10429 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10429, "deDE", "<Aurine nimmt das Herz an sich.>$B$BSogar für eine Kreatur von dieser Größe ist das Herz viel zu groß. Es musste sich sehr anstrengen, um mit dem riesigen Körper Schritt halten zu können. Ich habe keine Zweifel, dass sie nach der Hälfte ihrer normalen Lebenserwartung gestorben wäre.$B$BTrotz dieser Risiken bin ich entschlossen, die Astralen davon zu überzeugen, ihre Technologie mit anderen zu teilen. Es ist zu viel versprechend, als dass wir jetzt aufgeben sollten.", 26972);

-- 10430 - Den Prototyp testen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10430 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10430, "deDE", "Sieht aus, als hättet Ihr den Prototyp. Hat Ghabar Euch geschickt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10430 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10430, "deDE", "Er sieht ein wenig merkwürdig aus. Ghabar hatte sicher nicht den Nethersturm im Hinterkopf, als er ihn entwickelt hat.$B$BSchaut nicht so überrascht drein, $N. Der Nethersturm ist harmlos im Vergleich zu einigen Orten, an denen ich gearbeitet habe. Doch eine kaputte Kuppel ist immer ein Grund zur Sorge.", 26972);

-- 10431 - Hilfe von außen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10431 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10431, "deDE", "Seid Ihr die ganze Hilfe, die Orelis schickt? Er muss eine hohe Meinung von Euch haben.$B$BLasst es uns hinter uns bringen.", 26972);

-- 10432 - Eindeutige Beweise
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10432 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10432, "deDE", "Nun? Was hatte Theledorn zu sagen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10432 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10432, "deDE", "Das ist eine große Sache, $N. Sehr groß!$B$BVoren'thal möchte sicher so früh wie möglich davon erfahren.", 26972);

-- 10433 - Den Schein wahren
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10433 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10433, "deDE", "<Shauly hebt die Stimme, um die Aufmerksamkeit der Astralen in der Nähe zu erregen.>$B$BHabt Ihr ein paar Pelze für mich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10433 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10433, "deDE", "<Shauly gibt vor, die Pelze zu bewundern.>$B$BSie sind wundervoll, wirklich wundervoll! Ich werde Euch den besten Preis dafür bezahlen! Was kosten mich Eure Dienste?", 26972);

-- 10434 - Das dynamische Duo
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10434 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10434, "deDE", "<Ihr stellt Euch vor und sagt, dass Shauly Euch geschickt hat.>$B$BAh, ja, wir haben jemanden erwartet, der uns dabei hilft, äh - ein paar, mh, Güter zu transportieren.", 26972);

-- 10435 - Die Waren zurückholen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10435 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10435, "deDE", "Habt Ihr alles gesammelt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10435 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10435, "deDE", "Ausgezeichnete Arbeit! Der schwierigste Teil unseres Projekts ist damit erledigt. Jetzt müssen wir nur noch einen Weg finden, diese hier zurück zu Area 52 zu bringen und auch das Interesse der Expedition des Cenarius zu wecken. Es sollte hier genug geben, um unsere eigenen Interessen zu decken und noch ein wenig Gewinn zu machen.", 26972);

-- 10436 - Freie Bahn!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10436 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10436, "deDE", "Gut gemacht. Wie es aussieht, ist alles in Ordnung. Wir können anfangen.", 26972);

-- 10437 - Anleitung zur Zerstörung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10437 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10437, "deDE", "Habt Ihr genügend Fragmente gesammelt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10437 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10437, "deDE", "Ausgezeichnet. Mit diesen Fragmenten können wir die Bombe einstellen, die die Leerenergieversorgung auf der Manaschmiede Ultris zerstören kann. Dann wird Dimensius' Verbindung zur Leere unterbrochen und er kann sich nicht mehr verteidigen.", 26972);

-- 10438 - Auf netherischen Schwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10438 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10438, "deDE", "Es ist Zeit zuzuschlagen! Nun, da der Riss fort ist, kann Dimensius mit Kraft und Magie angegriffen werden!", 26972);

-- 10439 - Dimensius der alles Verschlingende
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10439 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10439, "deDE", "Seit tausend Jahren kennen wir nur noch Krieg. Wir haben unser Volk gegen die Angriffe der Leerwesen und der Astralen verteidigt.$B$BJetzt ist einer unserer schlimmsten Feinde gefallen - endlich.$B$BIch überbringe Euch den Dank von Milliarden von Astralen, Fleischling.", 26972);

-- 10440 - Erfolg!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10440 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10440, "deDE", "Ich setzte meine Techniker sofort auf die Reparaturen an.$B$BTashars Vermutung, dass es sich um Sabotage handelt, macht mir jedoch Sorgen. Ich kann mir nicht vorstellen, dass jemand waghalsig genug wäre, unsere Technologie zu stehlen. Zumindest niemand, der weiß, wozu wir fähig sind. Vielleicht ist es an der Zeit, die Sturmsäule abzuriegeln.", 26972);

-- 10507 - Der Wendepunkt
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10507 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10507, "deDE", "Ist es Erledigt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10507 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10507, "deDE", "Ich verfügt über unglaubliche Kraft, $N. Die Seher können sich glücklich schätzen, Euch als Verbündeten zu haben.$B$BWenn sich die Nachricht von Kaels neuem Bündnis verbreitet, werden mehr Leute die Sache wie wir sehen. Die Tatsache, dass wir einen solch entscheidenden Sieg über Kael'thas errungen haben, bringt uns in eine äußerst günstige Lage.$B$BIch werde Eure Taten nicht vergessen.", 26972);

-- 10508 - Ein Geschenk für Voren'thal
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10508 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10508, "deDE", "Habt Ihr Socrethars Teleportationsstein schon besorgt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10508 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10508, "deDE", "Ihr erstaunt mich immer wieder, $N! Gut, dass Ihr auf unserer Seite steht.", 26972);

-- 10509 - Für Ruhm bestimmt
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10509 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10509, "deDE", "Ihr habt keine Ahnung, was das für die Seher bedeutet, $N. Ihr müsst mich entschuldigen, während ich nach Atem ringe und die Situation einschätze.", 26972);

-- 10652 - Hinter feindlichen Linien
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10652 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10652, "deDE", "Willkommen, $C. Bemüht Euch, unsere Position nicht zu verraten.$B$BWenn Kaels Spießgesellen uns entdecken, leben wir nicht mehr lange.", 26972);

-- 10653 - Male des Sargeras
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10653 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10653, "deDE", "Tragt Ihr irgendwelche Insignien des Feindes bei Euch, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10653 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10653, "deDE", "Sich den Dämonen der Brennenden Legion und den wahnsinnigen Kultisten, die sie verehren, zu stellen ist keine geringe Tat, $N. Ihr habt viel Hingabe und Mut bewiesen. Macht so weiter, und Euer Ruf bei den Aldor wird weiter steigen.", 26972);

-- 10654 - Mehr Male des Sargeras
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10654 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10654, "deDE", "Beweist Euch weiterhin als würdig, $N. Besiegt die Feinde des Lichts, wo immer Ihr sie findet. Eure Taten sollen angemessen belohnt werden.", 26972);

-- 10655 - Einzelne Male des Sargeras
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10655 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10655, "deDE", "Ihr beweist Euch weiterhin als würdig, $N. Besiegt die Feinde des Lichts, wo immer Ihr sie findet. Eure Taten sollen angemessen belohnt werden.", 26972);

-- 10656 - Siegel des Sonnenzorns
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10656 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10656, "deDE", "Los, $N. Sprecht.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10656 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10656, "deDE", "Kaels Armee des Sonnenzorns ist sehr gut ausgebildet. Ihr habt beeindruckende Arbeit geleistet, $N.", 26972);

-- 10658 - Mehr Siegel des Sonnenzorns
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10658 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10658, "deDE", "Was habt Ihr in letzter Zeit für uns getan, $N? Der Krieg gegen Kael'thas kämpft sich nicht von alleine, verstanden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10658 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10658, "deDE", "Ausgezeichnet! Das wird Kael'thas zeigen, dass unsere Macht nicht zu unterschätzen ist.", 26972);

-- 10659 - Einzelne Siegel des Sonnenzorns
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10659 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10659, "deDE", "Sogar der kleinste Beitrag zu unserer Sache wird bemerkt, $N. Unsere Feinde sind stark, aber wir werden siegen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10659 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10659, "deDE", "Kaels Armee wird bald fallen.", 26972);

-- 10701 - Netherbrock zerschmettern
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10701 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10701, "deDE", "Oh! Oh... Ihr habt Netherbrock erledigt. Das sind gute Nachrichten!$B$BJetzt, da dieser lästige Bergriese von der Bildfläche verschwunden ist, können wir die Rohstoffe der Schwindenden Weiten leichter ausbeut... äh, verwalten.$B$BIch bin froh, dass diese armen, unschuldigen Elementare da unten jetzt nicht mehr von ihm zerquetscht werden.$B$BWie kann ich Euch je dafür entlohnen?", 26972);

-- 10704 - Wie man in Arkatraz einbricht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10704 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10704, "deDE", "<A'dals Stimme summt melodisch in Eurem Geist.>$B$BIhr seid zurück. Habt Ihr die beiden Fragmente des Schlüssels zur Arkatraz bei Euch?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10704 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10704, "deDE", "Ich bin beeindruckt, $N, auch wenn ich von $Gdem Helden, der:der Heldin, die; den Kristall von Ata'mal zurückgebracht hat, nichts anderes erwartet habe.$B$BGebt mir die Fragmente, damit ich sie zu ihrer endgültigen Form zusammenfügen kann. Dann werdet Ihr Zugang zur Arkatraz haben.", 26972);

-- 10822 - Einzelne Siegel des Sonnenzorns
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10822 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10822, "deDE", "Sogar der kleinste Beitrag zu unserer Sache wird bemerkt, $N. Unsere Feinde sind stark, aber wir werden siegen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10822 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10822, "deDE", "Sieg für die Seher! Kaels Streitmächte werden bald fallen!", 26972);

-- 10823 - Mehr Siegel des Sonnenzorns
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10823 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10823, "deDE", "Wie verläuft der Kampf gegen Keals Streitmacht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10823 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10823, "deDE", "Ihr macht Euch einen Namen, $N. Weiter so!", 26972);

-- 10824 - Siegel des Sonnenzorns
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10824 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10824, "deDE", "Los, $N. Sprecht.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10824 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10824, "deDE", "Kaels Armee des Sonnenzorns ist sehr gut ausgebildet. Ausgezeichnete Arbeit.", 26972);

-- 10826 - Male des Sargeras
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10826 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10826, "deDE", "Tragt Ihr irgendwelche Insignien des Feindes bei Euch, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10826 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10826, "deDE", "Sich den Dämonen der Brennenden Legion und den wahnsinnigen Kultisten, die sie verehren, zu stellen ist keine geringe Tat, $N. Ihr habt viel Hingabe und Mut bewiesen. Macht so weiter, und Euer Ruf bei den Aldor wird weiter steigen.", 26972);

-- 10827 - Mehr Male des Sargeras
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10827 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10827, "deDE", "Beweist Euch weiterhin als würdig, $N. Besiegt die Feinde des Lichts, wo immer Ihr sie findet. Eure Taten sollen angemessen belohnt werden.", 26972);

-- 10828 - Einzelne Male des Sargeras
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10828 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10828, "deDE", "Ihr beweist Euch weiterhin als würdig, $N. Besiegt die Feinde des Lichts, wo immer Ihr sie findet. Eure Taten sollen angemessen belohnt werden.", 26972);

-- 10850 - Nethergas in einem Teufelsfeuermotor
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10850 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10850, "deDE", "Als Ihr den falschen Treibstoff einfüllt, beginnt der Motor des Teufelshäschers zu rumpeln und zu stottern.", 26972);

-- 10855 - Teufelshäscher, nein Danke!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10855 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10855, "deDE", "Das sind ausgezeichnete Nachrichten, $N. Jetzt, da wir wissen, wie wir mit ihnen zu verfahren haben, kann ich ein paar Leute anheuern, um die übrigen Häscher zu sabotieren.", 26972);

-- 10856 - Die beste Verteidigung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10856 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10856, "deDE", "Gute Arbeit, $N. Macht weiter so, dann werde ich beim Nexusprinzen ein gutes Wort für Euch einlegen.", 26972);

-- 10857 - Teleportiert das!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10857 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10857, "deDE", "Ist es vollbracht? Sind die Teleporter außer Gefecht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10857 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10857, "deDE", "Dank Euch kann ich wieder etwas durchatmen, $N. Das meine ich natürlich im übertragenen Sinne!$B$BIch nehme an, Ihr wollt nun eine Art Belohnung, oder?", 26972);

-- 10882 - Herold der Verdammnis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10882 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10882, "deDE", "<Das kristallene Klingen von A'dals Stimme fließt in einer deutlich ruhigeren Melodie als die letzten beiden Male, in denen Ihr miteinander gesprochen habt.>$B$BWieder einmal habt Ihr Euren Eifer bewiesen. Wenn Herold Horizontiss ausgebrochen wäre, wären Tausende dem Konflikt zum Opfer gefallen, genauso, wie es bei einem anderen Diener der alten Götter, Skeram, auf Eurer Welt Azeroth geschehen ist.$B$B$N, was ich Euch als Belohnung anbiete, scheint im Vergleich erbärmlich zu sein, aber seid Euch bewusst, dass die ewige Dankbarkeit der Sha'tar damit verbunden ist.", 26972);

-- 10924 - Verwichtelt und zugenäht!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10924 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10924, "deDE", "War Zeppit freundlich genug, das Blut für Euch zusammeln?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10924 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10924, "deDE", "Das sollte genügend Vorrat für meine Zwecke sein.$B$BIch hoffe, der Wichtel hat Euch nicht allzu viel Ärger gemacht. Er hat manchmal Haare auf den Zähnen.", 26972);

-- 10969 - Sucht Ameer!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10969 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10969, "deDE", "Ja, das stimmt. Doch das Konsortium ist nicht die einzige Gruppierung, die Verluste zu vermelden hat.", 26972);

-- 10970 - Ein barmherziger Auftrag
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10970 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10970, "deDE", "Hattet Ihr Glück?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10970 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10970, "deDE", "Tretet zurück, $N. Es könnte auch eine Falle des Astraleums sein.", 26972);

-- 10971 - Geheimnisse des Astraleums
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10971 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10971, "deDE", "Habt Ihr ein paar Identifizierungsmarken finden können?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10971 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10971, "deDE", "Es scheint sich hierbei um mehr als eine einfache Identifizierungsmarke zu handeln. Auf den Marken ist eine Art Code zu sehen. Ich stehe kurz davor, ihn zu entschlüsseln. Wenn ich doch nur mehr Marken hätte!", 26972);

-- 10972 - Katalog der Gefangenen des Astraleums
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10972 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10972, "deDE", "Ich brauche mehr Identifikationsmarken, $N. Ich konnte bisher herausfinden, dass sie nicht nur die Gefangenen katalogisieren, sondern auch Aussagen über ihre Aufenthaltsorte machen!$B$BSobald wir diesen Code entschlüsselt haben, können wir genau feststellen, wo unsere Verbündeten festgehalten werden und sie mit minimalem Gewalteinsatz befreien.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10972 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10972, "deDE", "Wir sind der Wahrheit auf der Spur, $N.", 26972);

-- 10973 - Tausend Welten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10973 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10973, "deDE", "<Ameer fügt die Schlüssel geschickt zusammen und betrachtet die Markierungen auf der so hergestellten Schlüsseltafel.>$B$B\"Tausend Welten zerschlagen, tausend weitere noch zu bezwingen... So lautet der Wille des Nexuskönigs.\"$B$B<Ameer dreht die Tafel um und liest die Rückseite.>$B$BStasiskammern von Bash'ir?", 26972);

-- 10975 - Die Reinigung der Kammern von Bash'ir
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10975 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10975, "deDE", "Wir sitzen in der Sackgasse, $N. Die Daten, die Ihr gesammelt habt, haben uns genügend Informationen geliefert, um unsere Verbündeten aus den kleineren Gefängnissen des Nethersturms retten zu können. Wir müssen uns jedoch dringend um die Bedrohung kümmern, die von den Kammern hier im Ladeplatz von Bash'ir ausgeht.$B$BSchließt Euch dem Kampf gegen das Astraleum an! Bringt mir die Gefängnisschlüssel des Astraleums, damit ich Stasiskammerschlüssel für die Stasiskammern von Bash'ir für Euch herstellen kann. ", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10975 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10975, "deDE", "Es gibt immer noch mehr Arbeit, die erledigt werden muss, $N. Begebt Euch nun auf die Suche nach einer Stasiskammer und vernichtet, was auch immer darin lauern mag!", 26972);

-- 10977 - Stasiskammern der Managruft
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10977 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10977, "deDE", "Ich könnte verstehen, wenn Ihr lieber nicht weitermachen wollt, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10977 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10977, "deDE", "Ich habe von Euren Heldentaten erfahren, $N. Haramad und ich sind uns beide einig, dass Ihr dafür eine großartige Belohnung verdient habt.$B$BObwohl... Ach, Ihr habt schon genug getan. Ich kann Euch nicht guten Gewissens um noch mehr bitten.", 26972);

-- 11036 - Außerirdische Früchte!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11036 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11036, "deDE", "Ist das die Lieferung vom alten Orok?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11036 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11036, "deDE", "<Der Raketenchef überprüft den Inhalt der Kiste.>$B$BSieht soweit gut aus. Wieder etwas, das ich von der Liste streichen kann. Nun müssen wir noch nur dafür sorgen, dass die Rakete vom Boden abhebt.", 26972);

-- 11037 - Eine seltsame Vision
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11037 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11037, "deDE", "<Der Raketenchef hört Euch aufmerksam zu, als Ihr ihm von der Vision des Sehers erzählt.>$B$BNun, das ist alles völlig neu für mich, aber Eure Hilfe können wir allemal gebrauchen. Seht Euch die Rakete hinter mir an! Das ist die X-52...$B$BIst sie nicht das Schönste, was Ihr je gesehen habt?", 26972);

-- 11040 - Ersatzteile für den Raketenchef
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11040 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11040, "deDE", "Diese Kiste sieht aus, als stamme sie von einem Goblinmeisteringenieur. Hat Bossi Euch geschickt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11040 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11040, "deDE", "Ich weiß nicht einmal, was einige dieser Teile bewirken! Einige von ihnen werden mir sicherlich sehr nutzen. Ich hätte niemals gedacht, dass ich mal lernen müsste, wie ein Gnom zu denken!", 26972);

-- 11042 - Eine verblüffende Vision
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11042 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11042, "deDE", "<Der Raketenchef hört Euren Ausführungen über die Vision des Sehers aufmerksam zu.>$B$BNun, das ist alles völlig neu für mich, aber Eure Hilfe können wir allemal gebrauchen. Seht Euch das Ungetüm hinter mir an. Das ist die X-52...$B$BIst sie nicht das Schönste, was Ihr je gesehen habt?", 26972);
