-- Eversong Woods -- Immersangwald

-- 8325 - Rückeroberung der Insel der Sonnenwanderer
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8325 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8325, "deDE", "Ihr habt Eure erste Aufgabe erfolgreich gemeistert; lasst mich Euch dafür danken. Ein derartiger Erfolgt bestärkt mich in meinem Glauben, dass Ihr Euch besser anstellen werdet als diese jungen Blutelfen, die sich nicht an die Vorgaben ihrer Meister halten. Weitere Leistungen wie diese werden belohnt werden - nicht nur mit Wissen, sondern auch mit greifbaren Belohnungen.$B$BDennoch, Eure Arbeit hier ist noch nicht getan. Es gibt noch viel zu lernen, mein Kind...", 26972);

-- 8326 - Bedauerliche Maßnahmen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8326 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8326, "deDE", "Es bereitet mir keine Freude, Euch um die Vernichtung dieser Kreaturen zu bitten. Wir haben in der Vergangenheit stets in Harmonie mit den Geschöpfen des Waldes gelebt, aber heute ist es anders. Der Grundsatz der Sin'dorei lautet Überleben; vergesst das nie.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8326 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8326, "deDE", "Der Turm und die unmittelbare Umgebung sollten jetzt einigermaßen sicher sein, zumindest vorerst. Dank Euch haben wir an Sicherheit gewonnen, aber es gilt die Kontrolle über die ganze Insel wiederzuerlangen, wenn wir hier auf Dauer überleben wollen. Es wird weitaus mehr verlangen, als Manawyrms und Luchse auszulöschen.$B$BNehmt dies, $N - es wird Euch bei Euren künftigen Taten sicherlich von Nutzen sein.", 26972);

-- 8327 - Berichterstattung an Lanthan Perilon
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8327 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8327, "deDE", "Magistrix Erona sagte mir bereits, dass Ihr schon bald hier sein würdet, $N. Es steht sehr schlecht um die Akademie von Falthrien, das große schwebende Gebäude mit den kunstvollen Türmchen, das westlich von uns liegt. Ihr werdet den Rückeroberungsversuch gegen einen Getriebenen anführen - einen Blutelfen, der ihrer erbärmlichen Gier auf ewig verfallen ist.$B$BIch hoffe Ihr seid bereit. Dies wird Euch nicht nur einiges über Gefahren lehren, sondern auch etwas über das Schicksal, das Euch ereilt, wenn Ihr Eure Existenz leugnet.", 26972);

-- 8328 - Ausbildung zum Magier
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8328 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8328, "deDE", "Ah, $N - Ihr gehört wohl zu den neuen Magiern hier auf der Insel, ja? Nun, Ihr seid hier richtig. Wenn es die Arkanbeherrschung ist, nach der Ihr sucht, dann kann ich Euch dieses Wissen vermitteln - solange Ihr über die erforderlichen Mittel verfügt, um die Ausbildungskosten zu tragen und solange Ihr Euch auf das konzentrieren könnt, was ich Euch lehre.", 26972);

-- 8330 - Solanians Habe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8330 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8330, "deDE", "Habt Ihr meine Sachen finden können? Sobald wir unsere Herrschaft über die Insel der Sonnenwanderer wiedererlangt haben, werde ich sie für meine Arbeit benötigen. Vorerst muss ich noch über den Sonnenbrunnen wachen... oder was davon übrig ist.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8330 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8330, "deDE", "Gut gemacht – ich wusste, dass Ihr für diese Aufgabe geeignet sein würdet. Sobald wir uns auf der Insel wieder frei bewegen können, werde ich meine Sachen gut einsetzen.$B$BWie ich schon sagte, Ihr könnt den Ranzen behalten. Außerdem könnte auch dieses Rüstungsteil von Nutzen für Euch sein. Betrachtet es als großzügige Entlohnung für eine einfache Pflichterfüllung! ", 26972);

-- 8334 - Aggressivität
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8334 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8334, "deDE", "Der Tod der Borklinge macht mich zwar nicht glücklicher, aber es beweist mir, dass Ihr für die wichtigste Aufgabe hier auf der Insel der Sonnenwanderer bereit seid. Nehmt dies und setzt es mit Bedacht ein; Ihr werdet gute Waffen und einen scharfen Verstand für Euren nächsten Auftrag brauchen. Es liegt an Euch, ob wir die Kontrolle über die Insel erfolgreich wiedererlangen.", 26972);

-- 8335 - Felendren der Verbannte
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8335 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8335, "deDE", "Lasst Euch gewarnt sein - Felendren der Verbannte ist nur das Anzeichen eines viel größeren Problems. Sein Untergang wird lediglich unsere momentanen Schwierigkeiten lösen. Allen Blutelfen könnte das gleiche Schicksal wie ihn ereilen, sollten wir unserem Verlangen gänzlich erliegen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8335 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8335, "deDE", "Felendrens Kopf... Ihr verdient Lob, $N. Wo andere, wie Felendren, versagt haben, habt Ihr Euch erfolgreich gezeigt. Vielleicht seid Ihr wirklich bereit, ein gleichgestelltes Mitglied der Blutelfen zu werden.$B$BEuer Erfolg hier beweist, dass Ihr vor den größeren Bedrohungen Immersangs gefeit seid... und glaubt mir, es gibt genug davon.", 26972);

-- 8336 - Für eine Handvoll Fragmente
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8336 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8336, "deDE", "Einst waren uns viele der Lebewesen auf dieser Insel friedlich gesinnt, unsere Magie hielt sie in einem permanenten Zustand der Kontrolle. Doch mit der Zerstörung des Sonnenbrunnens durch die Geißel verloren wir auch unsere Kontrolle über sie. Die Arkanspäne sind das letzte Überbleibsel unserer damaligen Beherrschungsmagie, und als solche können sie uns vielleicht bei der Erschaffung eines neuen Artefakts helfen, mit dessen Macht wir die Kontrolle zurückerlangen werden.$B$BNoch wichtiger, mithilfe der Fragmente könnten wir herausfinden, unter welchem Fluch diese Insel wirklich leidet...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8336 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8336, "deDE", "Großartig, die werden ihren Zweck erfüllen! Ursprünglich habe ich diesen abgelegenen Ort aufgesucht, um in aller Ruhe nachzudenken und zu erforschen, unter welchem Fluch die Insel der Sonnenwanderer leidet. Eine der Möglichkeiten, die ich in Betracht zog, war das Sammeln der Arkanspäne von den Wildtieren auf der Insel. Mit ihnen wollte ich experimentieren, um eine mögliche Ursache zu entdecken.$B$BWie auch immer, ich werde mich weiter auf meine Forschungen konzentrieren. Erlaubt mir, diesen Zauber auf Euch zu wirken. Ich denke, Ihr werdet ihn sehr nützlich finden!", 26972);

-- 8338 - Besudelter Arkanspan
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8338 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8338, "deDE", "Ich entnehme Eurer Haltung, dass es um etwas Dringliches geht. Kann ich Euch irgendwie behilflich sein?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8338 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8338, "deDE", "Das ist... äußerst interessant. Mit interessant meine ich beunruhigender als alles andere.$B$BUnser Bestreben nach der Zerstörung des Sonnenbrunnens wieder die Kontrolle über diese Insel zu erlangen, war eine Herausforderung. Ich vermute, welch Übel auch immer der Grund für diese Verderbnis der Insel ist, dass das Fragment uns weitere Auskünfte über dessen Ursprung geben kann.$B$BEs war weise von Euch, damit zu mir zu kommen, $N. Nehmt dies als Vergütung für Eure Mühen. Ich danke Euch.", 26972);

-- 8345 - Der Schrein von Dath'Remar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8345 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8345, "deDE", "Ah, $N – Danke, dass Ihr mir von Euren Beobachtungen beim Schrein von Dath'Remar erzählt habt. Euer Forscherdrang hat uns und Euch heute ausgezeichnete Dienste geleistet. Ich bin sicher, er wird Euch nicht nur hier, sondern in ganz Azeroth von Nutzen sein.$B$BWas Eure merkwürdigen Empfindungen beim Schrein angeht, ich denke, dass sich dort ein Teil der Verderbnis eingenistet hat, die die gesamte Insel der Sonnenwanderer bedroht. Wir werden die Sache im Auge behalten; danke, dass Ihr uns alarmiert habt!", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Schrein von Dath'Remar gelesen", `VerifiedBuild`=26972 WHERE `ID` = 8345 AND `locale` = "deDE";

-- 8346 - Unstillbarer Durst
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8346 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8346, "deDE", "Wenn es eine Lektion von Eurer Zeit auf der Insel der Sonnenwanderer gibt, die Ihr niemals vergessen dürft, dann ist es diese: Verliert unter keinen Umständen die Kontrolle über Euer Verlangen nach Magie. Dieser Durst ist unstillbar, $N. Verwendet den arkanen Strom, um das, was Ihr absorbiert, zu kontrollieren und in der von Euch gewünschten Form wieder freizulassen. Begeht Ihr dabei einen Fehler, werdet Ihr zu einem Getriebenen... hoffnungslos abhängig und dem Wahnsinn verfallen.$B$BSucht nach einem Manawyrm und fokussiert Euren Manadurst auf ihn. Lernt, Eure Macht zu kontrollieren. Kehrt zu mir zurück, wenn Ihr einen arkanen Strom entfesselt habt - und das zufriedenstellend.", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Arkaner Strom entfesselt", `VerifiedBuild`=26972 WHERE `ID` = 8346 AND `locale` = "deDE";

-- 8347 - Unterstützung für die Kundschafter
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8347 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8347, "deDE", "Oh, hallo $C! Ich hörte schon, dass eine von Magistrix Eronas findigen Blutelfen sich auf den Weg hierher gemacht hat, um uns Kundschaftern ein wenig zur Hand zu gehen. Etwas Hilfe kommt uns sehr gelegen, insbesondere von jemand so tatkräftigem wie Euch.$B$BSeid Ihr bereit, ein oder zwei Botengänge für uns zu erledigen?", 26972);

-- 8350 - Erfolgreiche Lieferung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8350 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8350, "deDE", "Willkommen in meinem bescheidenen Gasthaus, $C. Ich nehme an, Ihr habt etwas für mich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8350 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8350, "deDE", "Vielen Dank, ich weiß Eure prompte Lieferung sehr zu schätzen.$B$BWo Ihr schon mal da seid, könnt Ihr es Euch auch gleich gemütlich machen. Ich habe einige Ruhesteine im Angebot, falls Ihr noch keinen erworben habt. Mit diesem Stein könnt Ihr Euch einmal alle halbe Stunde in ein Gasthaus zurückteleportieren. Macht Euch keine Sorgen, wenn Ihr Euren Ruhestein mal verlieren solltet. Kehrt einfach zu einem Gastwirt Eurer Wahl zurück und er wird Euch mit Freuden einen neuen Stein zur Verfügung stellen.", 26972);

-- 8463 - Instabile Manakristalle
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8463 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8463, "deDE", "Habt Ihr die gestohlenen Kristalle gefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8463 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8463, "deDE", "Hervorragende Arbeit, $N.", 26972);

-- 8468 - GESUCHT: Thaelis der Manadurstige
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8468 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8468, "deDE", "Ihr habt etwas, das Ihr mir zeigen wollt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8468 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8468, "deDE", "Diesen Halunken, Thaelis, hat endlich sein gerechtes Schicksal ereilt. Gute Arbeit, $N. Damit sollten wir einige Zeit lang Ruhe vor den Getriebenen haben.", 26972);

-- 8472 - Schwere Fehlfunktion
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8472 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8472, "deDE", "War Eure Suche nach Arkankernen erfolgreich, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8472 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8472, "deDE", "Ihr habt Euch gut geschlagen, $N. Solange die arkanen Sankten nicht vollständig einsatzbereit sind, werden sich diese Kraftkerne als sehr nützlich erweisen.", 26972);

-- 8473 - Eine traurige Aufgabe
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8473 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8473, "deDE", "Es ist also getan. Ich verfluche diese Zeit, die uns zu solch verzweifelten Maßnahmen treibt... und ich verfluche unseren Feind, die Geißel!$B$BVerinnerlicht diese Lektion, $N. Unser Land muss beschützt werden, ganz egal wie hoch der Preis dafür sein mag. Wir werden obsiegen!", 26972);

-- 8474 - Weißborkes Anhänger
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8474 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8474, "deDE", "Wollt Ihr mir etwas zeigen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8474 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8474, "deDE", "Dieser... dieser Anhänger. Ich gab ihn Weißborke dem Alten, nachdem seine Leute uns beim Wiederaufbau unseres Dorfes geholfen hatten.$B$BIch vermute, das bedeutet, dass er...$B$B<Die Blutelfe räuspert sich und gewinnt ihre Fassung wieder.>$B$BIch weiß zu schätzen, dass Ihr mir den Anhänger gebracht habt, $N. Ich muss Euch um einen Gefallen bitten.", 26972);

-- 8475 - Die Todesschneise
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8475 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8475, "deDE", "Wir denken nicht, dass die Geißel in absehbarer Zeit ihre Angriffe einstellen wird, dennoch sind wir jedem dankbar, der uns bei der Verteidigung der Schneise unterstützt.", 26972);

-- 8476 - Amaniübergriff
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8476 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8476, "deDE", "Gute Arbeit, $N. Mit mehr Leuten wie Euch, wird unser Königreich schon bald zu alter Größe zurückfinden.", 26972);

-- 8477 - Der Hammer des Speermachers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8477 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8477, "deDE", "Habt Ihr mir Otembes Hammer gebracht, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8477 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8477, "deDE", "Die Gerüchte entsprechen der Wahrheit, $N. Dieser Hammer ist leicht und mächtig zugleich; ich werde einige meiner begonnenen Werke fertigstellen können. Natürlich dürft Ihr Euch als Erster etwas von den Gegenständen aussuchen.", 26972);

-- 8479 - Zul'Marosh
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8479 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8479, "deDE", "Habt Ihr mir Zul'Maroshs Kopf gebracht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8479 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8479, "deDE", "Yo, Mann. Zul'Marosh hat' solch ein Ende verdient. Er brannte Ven'jashis Dorf nieder. Ich hab' viele Amani getötet, bevor sie mich in diesen Käfig steckten. Ich habe etwas im Sand versteckt, es ist mein Geschenk an Euch.$B$BAh... ah, das Gift... es wirkt stärker, Mann. Zeit zu ruhen... ", 26972);

-- 8480 - Zurückgelassene Waffen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8480 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8480, "deDE", "Habt Ihr die zurückgelassenen Waffen an Euch bringen können?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8480 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8480, "deDE", "Gute Arbeit, $N. Jetzt zeigen wir den Getriebenen mal, aus welchem Holz wir geschnitzt sind!", 26972);

-- 8482 - Belastende Dokumente
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8482 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8482, "deDE", "Ihr habt etwas für mich? Lasst mich einen Blick darauf werfen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8482 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8482, "deDE", "Seid Ihr sicher, dass Ihr das bei einem Nachtelfen gefunden habt? Das Geschriebene ist eindeutig zwergisch...$B$BSoweit ich diesen Brief deuten kann, hatte der Verfasser nichts mit der Fehlfunktion zu tun, stattdessen wurde er hierher gesandt, um die Folgen der Katastrophe zu beobachten. Sie bezeichnen unsere Bemühungen als rücksichtslos und gefährlich, aber wer...?$B$BNatürlich! Dieser Gesandte aus Eisenschmiede! Es war ein Fehler von uns, einem Mitglied der Allianz zu vertrauen!", 26972);

-- 8483 - Der Zwergenspion
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8483 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8483, "deDE", "Habt Ihr Euch um den Eindringling gekümmert?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8483 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8483, "deDE", "So, es ist also getan. Hervorragende Arbeit.$B$BWir haben den Waldläufergeneral von der Situation in Kenntnis gesetzt und glaubt mir, die Zwerge werden für ihren Verrat mit Blut bezahlen.$B$BHeute habt Ihr Eurem Volk einen großen Dienst geleistet, $N.", 26972);

-- 8486 - Arkane Instabilität
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8486 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8486, "deDE", "Danke, $N. Jetzt, wo wir die Gespenster unter Kontrolle haben, können wir das Ganze von jemandem begutachten lassen. Hoffentlich handelt es sich nicht um bleibende Schäden.", 26972);

-- 8487 - Besudelte Erde
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8487 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8487, "deDE", "Habt Ihr die von mir benötigten Erdproben eingesammelt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8487 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8487, "deDE", "Ausgezeichnet. Ich werde einen Zauber auf die Proben wirken, damit ich die Besudelung besser analysieren kann.", 26972);

-- 8488 - Ungewöhnliche Ergebnisse
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8488 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8488, "deDE", "Es ist hoffnungslos, $N. Die Beschaffenheit der Erde selbst hat sich verändert... die Besudelung ist unabänderlich. Vielen Dank für Eure Unterstützung. Ich muss Euch noch um einen letzten Gefallen bitten.", 26972);

-- 8490 - Wiederaufladen der Verteidigung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8490 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8490, "deDE", "Konntet Ihr den Runenstein mit Energie versorgen, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8490 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8490, "deDE", "Hervorragend. Die Verteidigungsmaßnahmen sollten die Geißel noch ein wenig länger in Schach halten. Vielen Dank für Eure Hilfe, $N.", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Runenstein wieder aufgeladen", `VerifiedBuild`=26972 WHERE `ID` = 8490 AND `locale` = "deDE";

-- 8491 - Pelzjagd
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8491 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8491, "deDE", "Ihr seid schon zurück? Habt Ihr die Pelze?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8491 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8491, "deDE", "Die werden ihren Zweck erfüllen, $N. Nehmt dieses Rüstungsteil als Belohnung. Mit den Pelzen, die Ihr mir gebracht habt, werde ich noch mehr herstellen können.", 26972);

-- 8884 - Fischköpfe, Fischköpfe...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8884 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8884, "deDE", "Wir Waldläufer von der Zuflucht der Weltenwanderer haben uns der Wiedergutmachung aller Schäden gewidmet, die unser schönes Land so schrecklich verheert haben. Egal, wie lange es auch dauern mag.$B$BIch kann mich doch darauf verlassen, dass Ihr mit den Murlocköpfen zurückgekehrt seid, die ich von Euch verlangt habe?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8884 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8884, "deDE", "Gute Arbeit, $C. Dem Gestank nach zu urteilen, seid Ihr mit der von mir geforderten Beute zurückgekehrt, vielleicht sogar mit mehr. Ich bin mir sicher, dass wir dafür Verwendung haben werden, sei es in einem Eintopf oder etwas Ähnlichem.$B$BLeider scheinen Eure Bemühungen den Zweck nicht erfüllt zu haben; die Murlocs ziehen sich noch immer nicht zurück. Wir müssen noch tatkräftiger handeln!", 26972);

-- 8885 - Mmmrrrgggllls Ring
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8885 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8885, "deDE", "Ihr verhelft mir zu Erfolg und Rache, $C. Habt Ihr den Ring?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8885 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8885, "deDE", "Endlich! Die Grimmschuppen sind zwar noch immer nicht gewichen, wie erhofft, aber es war ein herrliches Schauspiel, als sie nach dem Tod ihres Anführers in Panik und Verwirrung umhergeirrt sind. Ihr habt meinen Dank und den der Sin'dorei von Silbermond!$B$BBitte, nehmt eine dieser Belohnungen für Eure Mühen.", 26972);

-- 8886 - Piraten der Grimmschuppen!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8886 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8886, "deDE", "Ich bin dankbar für die Unterstützung von jemandem wie Euch, $N. Es stimmt mich fast schon wieder fröhlich. Allerdings erinnert es mich auch daran, was diese Monster meinem Schiff angetan haben und was mit Quel'Thalas geschieht.$B$BHabt Ihr es geschafft, Teile meiner Fracht wiederzuerlangen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8886 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8886, "deDE", "Ihr habt es geschafft! Ihr habt mich vor dem Ruin bewahrt und die scheußlichen Kreaturen meine Vergeltung spüren lassen!$B$BWenn ich es jetzt noch schaffe, dass mir diese hübschen Waldläufer mit meiner Fracht helfen, dann komme ich endlich weg von hier! Ich muss noch einmal zurückkehren, wenn Velendris die Schiffswerft zurückerobert hat.$B$BHier, nehmt diese Münze. Ich kann Euch leider nicht mehr geben, aber ich hoffe, es entlohnt Eure Mühen.", 26972);

-- 8887 - Kapitänin Kelisendras verlorene Seekarten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8887 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8887, "deDE", "Hallo, $C, Euer Anblick ist ein gutes Zeichen. Ich weiß, es ist verrückt, dass ich überhaupt hier bin, wo der Ankerplatz doch von den Getriebenen überfallen wurde. Velendris und seine Waldläufer haben geschworen mich zu beschützen, unter der Bedingung, dass ich von hier verschwinde, sobald ich meine Fracht wiedererlangt habe.$B$BWas habt Ihr da... das kommt mir so bekannt vor?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8887 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8887, "deDE", "Oh, Ihr herzensguter, herzensguter $C! Ich hatte ja keine Ahnung, dass diese widerlichen Grimmschuppenmurlocs auch noch meine Seekarten entwendet hatten! Ohne diese Karten hätte ich niemals wieder in See stechen können, sobald wir den Ankerplatz zurückerobert und das Schiff repariert haben.$B$BIch bin Euch zutiefst dankbar! Hier, nehmt diese Münze als Zeichen meiner Anerkennung.", 26972);

-- 8888 - Der Lehrling des Magisters
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8888 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8888, "deDE", "Der Magister sorgt sich um mein Wohlergehen? Wie süß von ihm; ich wünschte, er hätte ein derartiges Interesse etwas früher gezeigt, als wir noch im Turm waren.$B$BNaja, das tut jetzt nichts zur Sache. Hört gut zu, $C, ich muss Euch um einen Gefallen bitten.", 26972);

-- 8889 - Deaktivierung des Turms
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8889 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8889, "deDE", "Ich kann es aus dieser Entfernung nicht mit Sicherheit sagen... habt Ihr den Nachtschimmerturm bereits deaktiviert?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8889 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8889, "deDE", "Ich bin Euch für Eure Hilfe dankbar, aber es betrübt mich zu hören, dass einige meiner Lehrlingsfreunde der Abhängigkeit verfallen sind.$B$BJetzt, da die Kraftquellen des Turms deaktiviert wurden, werde ich wohl noch eine Weile hier bleiben. Ich möchte sehen, ob sich die Lage beruhigt, damit ich mich hineinschleichen kann, um ihre Überreste zu bergen.", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Erste Kraftquelle deaktiviert", `ObjectiveText2`="Zweite Kraftquelle deaktiviert", `ObjectiveText3`="Dritte Kraftquelle deaktiviert", `VerifiedBuild`=26972 WHERE `ID` = 8889 AND `locale` = "deDE";

-- 8890 - Nachricht vom Turm
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8890 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8890, "deDE", "Nein! Ich war zu spät. Es ist alles meine Schuld.$B$BMeine Untersuchungen hinsichtlich der Aufbereitung alternativer Magiequellen sind mir außer Kontrolle geraten und ich konnte nichts mehr tun, was dies hätte aufhalten können. Wäre ich nur selbst gegangen... oder hätten sie auf mich gehört und meine Warnungen befolgt!$B$BMeine Hände sind mit Blut befleckt, $C. Ich danke Euch dennoch, dass Ihr diese armen Seelen meiner ehemaligen Lehrlinge erlöst habt. Es ist ein kleiner Trost zu wissen, dass sie nicht länger in dem Zustand verweilen müssen, an dessen Stelle ein Blutelf besser tot wäre.", 26972);

-- 8891 - Aufgegebene Untersuchungen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8891 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8891, "deDE", "Was ist das? Es kommt mir bekannt vor. Oh nein, dieses Tagebuch... meine Untersuchungen... dies hat all die schrecklichen Ereignisse verursacht.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8891 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8891, "deDE", "Hier ist er also, $N, der Beweis für mein Verbrechen. Dieses Tagebuch enthält all meine schlecht durchdachten Studien.$B$BIch schenkte den Warnungen keine Beachtung und führte meine Untersuchungen fort, bis es schon fast zu spät war. Als ich endlich meine Fehler einsah, tat ich alles in meiner Macht Stehende. Allerdings sind einige meiner Schüler zu diesem Zeitpunkt bereits zu weit gegangen. Ich evakuierte den Turm, um sie vor der Verderbnis in Schutz zu bringen. Jedoch vergaß ich in meiner Eile, die Kraftquellen zu deaktivieren.$B$BIch werde diese Aufzeichnungen verbrennen, damit sie zukünftig keinen Schaden mehr anrichten können. Ich wollte den Sin'dorei doch nur helfen.", 26972);

-- 8892 - Vorfall beim Ankerplatz der Sonnensegel
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8892 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8892, "deDE", "Das wird ihnen zeigen, dass man es sich mit uns besser nicht verscherzt. Gute Arbeit, $N.", 26972);

-- 8894 - Sicherung des Grunds
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8894 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8894, "deDE", "Nun, ich denke, das dürfte fürs Erste genügen, oder nicht? Danke für die Hilfe, $C. Ich hoffe nur, dass ich hier alles rechtzeitig absichern kann, bevor der Magister zum Nachtschimmerturm zurückkommt.$B$BNehmt dies bisschen Kleingeld; es ist nicht viel, aber ich habe im Moment nicht mehr. Ihr könnt ruhig noch ein paar Bestien mehr töten, wenn Ihr hier unterwegs seid, das wäre nett von Euch.", 26972);

-- 8895 - Lieferung an das Sanktum des Nordens
DELETE FROM `quest_request_items_locale` WHERE `ID` = 8895 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (8895, "deDE", "Ja, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 8895 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (8895, "deDE", "Vielen Dank, $N. Ich habe diesen Brief bereits erwartet.", 26972);

-- 9035 - Hinterhalt am Straßenrand
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9035 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9035, "deDE", "Sie sind jetzt weg. Hab' ihnen mit einem gut platzierten Feuerball eine Heidenangst eingejagt! Unglücklicherweise haben sie unsere wertvollen Güter in den Fluss geworfen.", 26972);

-- 9062 - Aufgeweichte Seiten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9062 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9062, "deDE", "Kein Glück? Na dann, sucht weiter. Das Buch ist überaus wichtig, $C.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9062 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9062, "deDE", "Das Buch ist völlig aufgeweicht. Instrukteur Antheol wird alles andere als erfreut sein.$B$BHier, nehmt das Geld. Ich habe eine Idee.", 26972);

-- 9064 - Die Sache ausbaden
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9064 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9064, "deDE", "Warum unterbrecht Ihr meine Vorlesung, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9064 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9064, "deDE", "Ihr sagt, dass Euch diese zwei unfähigen Narren bestochen haben, damit Ihr mich anlügt? Es war richtig von Euch, zu mir zu kommen, $N.", 26972);

-- 9066 - Disziplin muss sein
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9066 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9066, "deDE", "Habt Ihr meine Anweisungen befolgt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9066 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9066, "deDE", "Ausgezeichnete Arbeit, $N. Keine Sorge, sie werden nicht auf Dauer in dieser Gestalt ausharren müssen. Allerdings geht es mit ihrer Lehre erst dann weiter, wenn sie es sich verdient haben.", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Lehrling Meledor diszipliniert", `ObjectiveText2`="Lehrling Ralen diszipliniert", `VerifiedBuild`=26972 WHERE `ID` = 9066 AND `locale` = "deDE";

-- 9067 - Die Feier ist nie zu Ende
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9067 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9067, "deDE", "Habe ich Euch nicht gerade losgeschickt, um mehr Festvorräte zu beschaffen? Oh, also man kann wirklich nicht von mir erwarten, dass ich mich an jedes Gesicht erinnere, nicht wahr? Ich treffe so viele... interessante Leute.$B$BWas ist Euer Anliegen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9067 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9067, "deDE", "Ihr seid in der Tat $Gein aufgeweckter junger Mann:eine aufgeweckte junge Dame;, nicht wahr?$B$BDiese Waren erscheinen mir dem Zwecke angemessen. Für Eure Mühen habt Ihr eine angemessene Entschädigung verdient und vielleicht ein kleines Trinkgeld.$B$BOh, das hätte ich beinahe vergessen! Hier ist eine Einladung zu meinem Fest. Und $C, wenn Ihr das nächste Mal mein Anwesen betretet, stellt sicher, dass Ihr ein wenig, sagen wir... festlicher gekleidet seid.", 26972);

-- 9076 - Getriebener Rädelsführer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9076 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9076, "deDE", "Nun, habt Ihr seinen Kopf? Verschwendet nicht meine Zeit, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9076 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9076, "deDE", "Ihr habt ihn also doch noch bezwungen! Meine Männer hatten ihn natürlich schon geschwächt.$B$BDas war ein Scherz, $C. Ihr habt Euch gut geschlagen. Wenn Ihr weiterhin eine weiße Weste behaltet, werdet Ihr Euch noch einen Namen machen.", 26972);

-- 9119 - Zwischenfall beim Sanktum des Westens
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9119 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9119, "deDE", "Seht Euch um. Hier stimmt so einiges nicht.$B$BBeim Sanktum des Westens kam es zu einem schweren Zwischenfall. Lasst uns alles Erdenkliche tun, um Schlimmeres zu verhindern.", 26972);

-- 9144 - Verschollen in den Geisterlanden
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9144 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9144, "deDE", "Helft mir, Fremder. Ich muss... Tristessa... erreichen... Ich darf nicht versagen.$B$B<Der Blick des Blutelfen entschwindet ins Leere, und er versinkt wieder in Bewusstlosigkeit.>", 26972);

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

-- 9252 - Die Verteidigung von Morgenluft
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9252 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9252, "deDE", "Vielen Dank, $N. Es ist eine undankbare Aufgabe, der wir hier nachgehen, doch Eure heutige Mithilfe hat sie ein wenig einfacher gemacht.", 26972);

-- 9253 - Runenwächter Deryan
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9253 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9253, "deDE", "Jemand aus Morgenluft muss Euch zu mir geschickt haben. Ich wusste doch, dass es nur eine Frage der Zeit war, bevor Hilfe eintrifft.", 26972);

-- 9254 - Der eigensinnige Lehrling
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9254 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9254, "deDE", "Es rührt mich, dass meine ehemalige Mentorin nach mir sehen lässt. Es ist nur traurig, dass sie seit langer Zeit kein Vertrauen mehr in meine Arbeit hat.$B$BIhr verschwendet Eure Zeit, Ihr könnt mich nicht überreden zu ihr zurückzugehen. Entweder helft Ihr mir mit meinen Untersuchungen hier oder Ihr geht.", 26972);

-- 9255 - Forschungsnotizen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9255 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9255, "deDE", "Habt Ihr etwas für mich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9255 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9255, "deDE", "Diese Notizen... es ist schockierend. Wenn das stimmt, dann ist der Schaden, den das Land entlang der Todesschneise erlitten hat, nicht wiedergutzumachen.$B$BIch werde dem Großmagister sofort Bescheid sagen. Ein weiterer Grund für unser Volk, dieser Welt zu entfliehen und sein wahres Schicksal in der Scherbenwelt zu finden.", 26972);

-- 9256 - Morgenluft
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9256 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9256, "deDE", "Danke, dass Ihr gekommen seid, $N. Es steht um einiges schlechter, als wir angenommen hatten. Die Getriebenen haben den Ankerplatz der Sonnensegel bereits gänzlich eingenommen.", 26972);

-- 9258 - Der Versengte Hain
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9258 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9258, "deDE", "Ah, mein Bruder hat Euch geschickt. Es gibt da etwas, wobei ich Eure Hilfe gebrauchen könnte.", 26972);

-- 9352 - Darnassische Eindringlinge
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9352 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9352, "deDE", "Nachtelfen? Hier? Diese Ratten!$B$BGlaubt Ihr, es besteht irgendeine Verbindung zu der Fehlfunktion in meinem Sanktum? Falls Ihr irgendwelche Informationen habt, bringt Ihr sie besser umgehend zu Hauptmann Sonnenmal!", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Besiegte Eindringlinge", `VerifiedBuild`=26972 WHERE `ID` = 9352 AND `locale` = "deDE";

-- 9358 - Waldläuferin Sareyn
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9358 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9358, "deDE", "Ihr seid hier, um zu helfen? Warum habt Ihr das nicht gleich gesagt? Wir können jede helfende Hand gebrauchen!", 26972);

-- 9359 - Zuflucht der Weltenwanderer
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9359 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9359, "deDE", "Ihr seid hier, um zu helfen? Ausgezeichnet!$B$BDer Kampf gegen die Amanitrolle hat uns sehr in Anspruch genommen und fähige Kämpfer wie Ihr sind stets willkommen.", 26972);

-- 9360 - Angriff der Amani
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9360 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9360, "deDE", "Was wollt Ihr mir zeigen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9360 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9360, "deDE", "Die Trolle haben uns hier festgehalten, während sie einen Angriff auf Morgenluft planten. Wir hatten nichts dergleichen erwartet.", 26972);

-- 9363 - Warnt Morgenluft
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9363 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9363, "deDE", "Die Informationen, die Ihr mir gebracht habt, sind von entscheidender Bedeutung, $N. Jetzt, da wir über die Pläne der Trolle Bescheid wissen, können wir uns auf einen Angriff vorbereiten.$B$BSie werden uns nicht ahnungslos überrumpeln.", 26972);

-- 9394 - Wo ist Wyllithen?
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9394 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9394, "deDE", "Wer seid Ihr? Ihr seid keiner von den Lehrlingen des Magisters, das steht fest!$B$BMan hat Euch sicherlich hierher geschickt, um mir dabei zu helfen, wieder Ordnung in dieses Chaos zu bringen!", 26972);

-- 9395 - Saltherils Hafen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9395 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9395, "deDE", "Ah, Magistrix Morgenwandler hat zu guter Letzt doch noch auf meine simple Anfrage reagiert. Beizeiten werde ich ihr Benehmen mit dem Lordregenten erörtern. Sie ist eine recht ungehobelte Person!$B$BNichts, worüber Ihr Euch Sorgen machen müsstet. Nun, wo Ihr schon mal hier seid, besteht vielleicht die Möglichkeit, dass ich endlich meine Vorräte für das Fest bekomme, auf die ich schon so lange warte.", 26972);

-- 9402 - Fangt!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9402 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9402, "deDE", "Wie ist das Wasser?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9402 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9402, "deDE", "Oh, gut gemacht... ich sagte Ihr sollt in den Tümpel springen und Ihr habt es getan. Ich kann mir gut vorstellen, was Ihr tun würdet, wenn einer Eurer Freunde Euch um etwas bitten würde.$B$BWollt Ihr für Eure Mühe belohnt werden, dann ist es das: macht keinen Finger krumm, bevor Ihr nicht wisst, was dabei für Euch herausspringt. Der Geist des Magiers ist seine stärkste Waffe. Vergesst das nicht und versucht Euren ein wenig mehr anzustrengen.", 26972);

-- 9403 - Das reinste Wasser
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9403 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9403, "deDE", "Nur das Wasser von den Elrendarfällen hat die erforderliche Reinheit für den Gebrauch von Magie. Habt Ihr es?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9403 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9403, "deDE", "Mal sehen, was Ihr mir gebracht habt...$B$B<Er hält die Phiole gegen das Licht und studiert sie genau.>$B$BJa, das sollte es sein. Gut gemacht, $N.", 26972);

-- 9404 - Noch lebendig
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9404 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9404, "deDE", "Habt Ihr den lebendigen Zweig? Schnell, gebt ihn mir!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9404 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9404, "deDE", "Ihr seid meiner Bitte nachgekommen, $N. Ihr könnt Eure Belohnung jetzt entgegennehmen.", 26972);

-- 9676 - Ausbildung zum Paladin
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9676 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9676, "deDE", "Mit der Zeit werdet Ihr Euch Euren Platz in unseren Reihen verdienen. Doch zunächst müsst Ihr die Mächte des Lichts beherrschen lernen. Eure Waffenkampkünste verfeinern und Eure Würdigkeit unter Beweis stellen.", 26972);

-- 9704 - Von den Getriebenen getötet
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9704 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9704, "deDE", "Die Habseligkeiten der Kundschafterin wurden mit Ausnahme eines Pakets allesamt entwendet. Es scheint der Beschreibung zu entsprechen, die Euch Alarion von Eronas Päckchen gegeben hat.", 26972);

-- 9705 - Bergung des Päckchens
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9705 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9705, "deDE", "Was habt Ihr gefunden, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9705 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9705, "deDE", "Beim Sonnenbrunnen! Es ist der dritte Kundschafter, den wir diesen Monat verloren haben.$B$BIch weiß Euren Mut zu schätzen, den Ihr bei Eurer Reise zum Dämmerweg bewiesen habt. Die Wachen müssen diese verdammten Getriebenen besser im Auge behalten.", 26972);

-- 10068 - Brunnenbehüter Solanian 
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10068 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10068, "deDE", "Ah, wie schön, $Gein:eine; $C. Ich habe Euch bereits erwartet.$B$BIch hätte da ein paar Aufgaben zu vergeben, für die Ihr Euch besonders gut eignet.", 26972);

-- 10166 - Weißborkes Erinnerung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10166 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10166, "deDE", "Ihr seid zurück, $N. Habt Ihr denn noch nicht genug getan?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10166 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10166, "deDE", "Ich gehöre dieser Welt nicht länger an und muss mich geschlagen geben. Das Land hat sich auf ewig verändert, und nichts wird mehr sein wie früher.$B$BLasst den Anhänger hier bei mir, $N. Eines Tages vielleicht, wenn die Elfen schon lange nicht mehr sind, wird ein Baum an genau diesem Ort wachsen - in einem versengten Wald und zwischen toten Treants.", 26972);
