/*
-- Bloodmyst Isle -- Blutmythosinsel

-- 9501 - Ruf des Wassers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9501 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9501, "deDE", "Ja?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9501 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9501, "deDE", "Fürchtet Euch nicht, $N. Wir werden hier mit Hilfe unserer Gedanken miteinander kommunizieren.$B$BIch bin Weissager Nobundo dankbar, dass er Euch zu mir gesandt hat. Etwas verunreinigt das Wasser auf und um die Blutmythosinsel herum. Nicht einmal einem Blinden würde der Effekt entgehen, den diese Störung auf die Kreaturen hat.$B$BIhr und ich werden zusammen gegen diese Verderbnis vorgehen, bevor sie sich noch weiter ausbreitet.", 26972);

-- 9504 - Ruf des Wassers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9504 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9504, "deDE", "Habt Ihr die Probe Reinsten Wassers aus den Ruinen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9504 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9504, "deDE", "Wasser schwindet schnell, vereinigt man aber genug davon, bildet es eine unaufhaltsame Kraft. Es spült Erde und Feuer hinfort und bahnt sich auch durch die Luft seinen Weg.$B$BWir sind diese unaufhaltsame Kraft, $N, nicht diejenigen, die die Blutmythosinsel vergiftet haben!", 26972);

-- 9508 - Ruf des Wassers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9508 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9508, "deDE", "Wart Ihr Erfolgreich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9508 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9508, "deDE", "Wir haben es geschafft! Der Katastrophe wurde vorgebeugt und Ihr habt die Erholung der Gewässer von der Blutmythosinsel in Gang gesetzt. Mit der Zeit wird sich das Wasser, in Verbindung mit den anderen Elementen, wieder von selbst heilen.$B$BEs ist wirklich traurig, die Blutelfen sehen einfach nicht, wie sie sich durch die Zerstörung ihrer Umgebung langsam selbst vernichten!", 26972);

-- 5921 - Mondlichtung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 5921 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (5921, "deDE", "Und so beginnt es, Vater Cenarius. Und so beginnt es.$B$BDendrite macht eine schnelle, unsichtbare Geste in die Luft über ihm. Eine leichte Aura der Macht fällt über ihn.$B$BDie erste Perspektive der Natur, die Ihr Euch aneignen müsst, ist die des Bären. Ich werde Euch auf den Weg bringen, um diesen Aspekt des Druidenlebens zu verstehen, aber Ihr müsst ihn Euch zu Eigen machen und pflegen - von nun an und für immer!", 26972);

-- 5925 - Dem Ruf folgen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 5925 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (5925, "deDE", "Ich bin froh, dass Ihr heute Euren Weg hierher gefunden habt. Es ist an der Zeit für Euch, einen großen Schritt in eine noch viel größere Welt zu tun.$B$BIn jedem von Cenarius' Kindern steckt die Berufung, der Natur zu dienen. Tiere und Pflanzen sind unsere Freunde wie auch unsere Schützlinge. Wir haben uns entschlossen, sowohl zu ihrem wie auch unserem Wohl unsere Leben dem Erhalt des Gleichgewichts zu widmen. Euer erster Schritt in diese Welt wird es sein, etwas über den Weg des Bären und die Stärke von Körper und Herz zu erlernen.$B$BMacht Euch bereit!", 26972);

-- 5929 - Großer Bärengeist
DELETE FROM `quest_request_items_locale` WHERE `ID` = 5929 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (5929, "deDE", "Kehrt erst zurück, wenn der große Bärengeist Euch wieder zu mir zurückschickt. Eure Ausbildung kann ohne seinen Segen nicht weitergehen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 5929 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (5929, "deDE", "Dendritte macht eine weitere unsichtbare Geste in der Luft über ihm, als Ihr Euch ihm nähert. Eine erneute Aura der Macht legt sich auf ihn und er lächelt ein wenig.$B$BIch spüre Weisheit in Euch, Weisheit, die nicht zugegen war, als wir uns das erste Mal trafen. Ihr blickt mit Stärke und verständnisvollem Eifer zu mir auf, auch wenn dieser Eifer noch nicht sehr zielgerichtet ist. Ihr werdet nun lernen, Eure Stärke zu fokussieren und das Wesen des Bären in Eure Arbeit anzuwenden.", 26972);

-- 5931 - Zurück nach Darnassus
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 5931 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (5931, "deDE", "Willkommen, $N. Ich spüre, dass Eure erste Begegnung mit dem großen Bärengeist genauso verlief wie bei allen Druiden, wenn sie die ersten Schritte auf dem Pfad der Klaue tun... etwas verwirrend, aber sehr eindrucksvoll. Ich weiß, dass es für mich damals auch so war.$B$BDer große Bärengeist ist schon so lange ein Teil von Azeroth wie Azeroth in den Himmeln existiert. Wir verlassen uns heute auf seine Weisheit und seine Macht, um unseren Absichten Antrieb zu verleihen. Nun ist es an der Zeit für Eure erste Prüfung dieser Absichten. Hört mir gut zu...", 26972);

-- 6001 - Körper und Herz
DELETE FROM `quest_request_items_locale` WHERE `ID` = 6001 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (6001, "deDE", "Wenn Ihr der Herausforderung getrotzt habt, die vor Euch liegt, wird Euch das ganze Wissen über die Kraft des Körpers und des Herzens zuteil werden. Bis dahin kann ich Euch nicht weiter behilflich sein.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 6001 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (6001, "deDE", "Endlich habt Ihr den Schritt in eine viel größere Welt getan, $N. Ich spüre die Lehre des großen Bärengeistes in Euch, und auch, dass Ihr die Kraft erhalten habt, die Mondklaue besaß.$B$BKein weiteres Hindernis versperrt Euren Weg... lasst mich Euch jetzt lehren, was es bedeutet, ein $C der Klaue zu sein.", 26972);

-- 9548 - Gestohlene Ausrüstung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9548 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9548, "deDE", "Konntet Ihr meine Ausrüstung finden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9548 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9548, "deDE", "Das ist fantastisch! Der Diebstahl meiner Ausrüstung hat mir zu noch mehr Einsicht in das Verhalten der Murlocs verholfen, als ich womöglich mittels wochenlanger Beobachtungen hätte gewinnen können!$B$BIch weiß schon, was ich in meinen Bericht schreiben werde.$B$B'Beim Aufeinandertreffen mit Erzeugnissen einer technologisch höher gestellten Kultur, zeigten die Murlocs der Schwarzschlammküste nicht die sonst typische Neugier wie humanoide Entwicklungskulturen.$B$B'Das ist großartig! Die Herren in Eisenschmiede werden es lieben! Ich kann Euch nicht genug danken, $N.", 26972);

-- 9549 - Schwarzschlammartefakte
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9549 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9549, "deDE", "Habt Ihr die Gegenstände, die ich nach Eisenschmiede bringen möchte?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9549 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9549, "deDE", "Verblüffend, einfach verblüffend! Diese Stücke sind perfekt, $N. Ich kann sie mir bereits unter Glas im Museum von Eisenschmiede vorstellen. Der Text für die Vitrine schreibt sich in meinem Kopf gewissermaßen von selbst!$B$BEure Hilfe war für den Fortgang meiner Studien von unschätzbarem Wert. Wie schreibt sich Euer Name doch gleich? Ich werde dafür sorgen, dass Ihr in meinem Bericht als Mitautor auftaucht.$B$BEiner der Burschen auf dem Schiff gab mir diese 'Schatzkarte', um seine Spielschulden bei mir zu begleichen, allerdings ist Mythologie keines meiner Fachgebiete. Abergläubiges Pack, diese Seefahrer.", 26972);

-- 9550 - Wohin führt die Karte?
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9550 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9550, "deDE", "Vielleicht bezieht sich die Karte ja auf dieses alte Tagebuch.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9550 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9550, "deDE", "Nachdem Ihr Euch das Buch sorgfältig angesehen habt, kommt Ihr zu dem Schluss, dass es sich um ein Tagebuch handelt. Die Eintragungen auf den Seiten weisen eine elegante Handschrift auf, die sich von der auf der Karte unterscheidet. Zahlreiche Texte sind durch hinzugefügte Beschriftungen und Zeichnungen im Stil der Karte unleserlich geworden.$B$BDurch das Geschreibsel des Kartenverfassers, in dem er von Trinkgelagen während des Landgangs faselt, sind die eigentlichen Eintragungen fast nicht mehr auszumachen.", 26972);

-- 9557 - Entziffern des Buchs
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9557 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9557, "deDE", "Möge das Licht bei all Euren Bemühungen mit Euch sein, $C. Was habt Ihr da?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9557 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9557, "deDE", "Hmm... das ist äußerst faszinierend. Ja, ich sollte in der Lage sein, die eigentlichen Einträge des Schreibers in diesem Buch entziffern zu können.$B$BIch verfüge über die benötigten Mittel hier. Es sollte nur einen Augenblick dauern.", 26972);

-- 9561 - Nolkais Worte
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9561 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9561, "deDE", "Gras und Gestrüpp bedecken eine unnatürliche Wölbung am Boden.$B$BNach nur kurzem Graben entdeckt Ihr einen alten Kasten. Es muss sich dabei um den, der in Nolkais Tagebuch beschriebenen ist, handeln.", 26972);

-- 9567 - Kenne deinen Feind
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9567 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9567, "deDE", "Habt Ihr schon etwas Wissenswertes von den Satyn der Nazzivus erlangt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9567 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9567, "deDE", "Gut gemacht, $N. Mal sehen, was ich von dieser Glyphe in Erfahrung bringen kann. Dann können wir unseren nächsten Schritt planen.", 26972);

-- 9569 - Die Bedrohung bekämpfen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9569 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9569, "deDE", "<Verteidigerin Aalesia scheint eher durch Euch hindurch, als Euch anzusehen, sie ist voll und ganz mit den Satyrn beschäftigt.>$B$BSeid Ihr schon gegen den Anführer der Satyrn vorgegangen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9569 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9569, "deDE", "Ohne ihren Anführer und die entwendeten Kristalle können wir die Satyrn bedenkenlos in Schach halten. Nur das Licht weiß, wie viele dieser erbärmlichen Kreaturen da draußen noch lauern.$B$BHerold Mikolaas und ich sind Euch für Eure Hilfe sehr dankbar. Ihr habt uns geholfen, eine noch größere Bedrohung durch die Satyrn abzuwenden. Euer Einsatz wird alle daran erinnern, dass Wachsamkeit der Schlüssel zum Erfolg ist, wenn es darum geht, gegen die Legion und ihre Diener vorzugehen.", 26972);

-- 9574 - Opfer der Verderbnis
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9574 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9574, "deDE", "Konntet Ihr die Proben bekommen, die ich benötige?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9574 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9574, "deDE", "Ich habe jetzt mehr als genug für meine Untersuchungen. Ich danke Euch, $N. Solltet Ihr noch etwas anderes auftreiben können, das beweist, dass die Kristalle die einheimischen Kreaturen der Blutmythosinsel beeinträchtigen, so lasst es mich sofort wissen.", 26972);

-- 9578 - Suche nach Galaen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9578 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9578, "deDE", "Ja?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9578 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9578, "deDE", "Der Leichnam trägt die für einen Techniker der Exodar übliche Kleidung, aber der von Morae beschriebene Anhänger fehlt.", 26972);

-- 9579 - Galaens Schicksal
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9579 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9579, "deDE", "<Morae sieht Euch voller Hoffnung an.>$B$BSeid Ihr bei Eurer Suche auf Spuren von Galaen gestoßen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9579 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9579, "deDE", "<Ihr berichtet Morae von Eurem Fund in den Trümmern des Kryokerns.>$B$BAlso... er ist...$B$BIch denke, dass ich es bereits wusste, wollte es aber einfach nicht glauben. Es sind zwar nicht die Neuigkeiten, die ich mir erhofft hatte, aber ich bin Euch für das Auffinden von Galaen zutiefst dankbar.", 26972);

-- 9580 - Bärdarfsgüter
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9580 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9580, "deDE", "Wie verläuft Eure Jagd, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9580 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9580, "deDE", "Mit diesen Vorräten werden wir fürs Erste versorgt sein und die Zubereitung für den späteren Verzehr wird mich sicherlich ein Weilchen beschäftigen. Ich danke Euch für Eure Hilfe, $N.", 26972);

-- 9581 - Von den Kristallen lernen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9581 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9581, "deDE", "Konntet Ihr die erste Kristallprobe bekommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9581 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9581, "deDE", "Dieser Kristallsplitter wird unseren Forschern als Vergleichsgrundlage für Proben von anderen Teilen der Insel dienen, da er aus einem weniger verseuchten Gebiet der Blutmythosinsel stammt.$B$BIch werde die Probe erst losschicken können, wenn ich ein vollständiges Probenset habe, aber der Anfang ist getan. Wenn Ihr mir helfen möchtet, die anderen Proben einzusammeln, werde ich Euch für Eure Mühe natürlich belohnen.", 26972);

-- 9584 - Die zweite Probe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9584 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9584, "deDE", "Habt Ihr die zweite Kristallprobe?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9584 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9584, "deDE", "<Herold Mikolaas untersucht den Kristallsplitter.>$B$BDieser Splitter unterscheidet sich stark von der ersten Probe.$B$B<Herold Mikolaas hält den Kristall ins Licht.>$B$BSeht Ihr, wie das Licht darin pulsiert? Das ist bedenklich. Ich werde in meinem Bericht vermerken, dass die Blutelfen diesen Kristall verändert zu haben scheinen. Ich danke Euch für Eure erneute Hilfe, $N.", 26972);

-- 9585 - Die zweite Probe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9585 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9585, "deDE", "Habt Ihr die letzte Probe für mein Set?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9585 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9585, "deDE", "<Herold Mikolaas nimmt den letzten Kristall von Euch entgegen.>$B$BDamit ist das Set vollständig. Ich muss nur noch alles verpacken und zur Exodar senden.$B$B<Der Herold scheint erleichtert, dass die Sache erledigt ist.>$B$BVersteht mich nicht falsch, $N, ich bin mir sicher, dass die Forschungsarbeit wertvoll ist, aber wir haben es hier draußen noch mit zahlreichen anderen Problemen zu tun, die dringend sind.", 26972);

-- 9620 - Das vermisste Vermessungsteam
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9620 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9620, "deDE", "Auf dem Boden liegen überall die Körper der $R, die dem Vermessungsteam angehörten - von Waffen der Naga durchbohrt. Ihr seht die verstreuten Überreste ihrer Vorräte und Vermessungsausrüstung, aber ihre Datenkristalle befinden sich nicht darunter.", 26972);

-- 9624 - Lieblingsleckerli
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9624 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9624, "deDE", "Man findet die Sandbirnen immer seltener, was natürlich weniger Kuchen und somit weniger Leckerli für die Elekk hier bedeutet. Konntet Ihr die benötigten Früchte auftreiben?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9624 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9624, "deDE", "War das Auffinden der Früchte schwierig? Ich brauche mit jedem Mal länger.$B$BIch werde allmählich ganz damit aufhören müssen, da ich keine Zeit mehr dafür habe. Danke für das Sammeln der Birnen, $N. Jetzt kann ich zumindest noch ein oder zwei Kuchen backen, bevor die Saison vorüber ist.", 26972);

-- 9628 - Bergung der Daten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9628 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9628, "deDE", "Konntet Ihr herausfinden, was das Vermessungsteam von seiner Rückkehr abgehalten hat?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9628 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9628, "deDE", "<Ihr erzählt Herold Mikolaas vom Schicksal des Vermessungsteams. Er nimmt den Kristall von Euch entgegen, aber schweigt für einen langen Augenblick.>$B$BEs waren gute Männer, Saphirus, sie wussten, dass ihre Mission gefährlich sein würde. Ich bin Euch dankbar für das Auffinden des Teams und die Wiederbeschaffung des Kristalls.$B$B<Der Herold ballt seine Faust.>$B$BWie haben bereits zu viele unserer Männer verloren, dabei hat unsere Mission gerade erst begonnen.", 26972);

-- 9629 - Kurz geschnappt
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9629 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9629, "deDE", "Hat der Apparat funktioniert? Habt Ihr die Murlocs für meine Untersuchungen makiert?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9629 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9629, "deDE", "Gut gemacht, $N. Ich hatte befürchtet, dass der Sender beim Markieren beschädigt werden könnte, aber scheinbar ist ja alles wie geplant verlaufen.", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Späher der Schwarzschlammküste markiert", `VerifiedBuild`=26972 WHERE `ID` = 9629 AND `locale` = "deDE";

-- 9632 - Neue Verbündete
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9632 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9632, "deDE", "Seid gegrüßt, $C. Was habt Ihr da?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9632 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9632, "deDE", "Ich kann Euch helfen, nach Auberdine zu kommen. Glücklicherweise ist es nur eine kurze Fahrt mit dem Schiff von hier!", 26972);

-- 9633 - Der Weg nach Auberdine
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9633 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9633, "deDE", "Willkommen in Auberdine. Was bringt Euch zur Dunkelküste?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9633 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9633, "deDE", "<Thundris nimmt das Schreiben von Euch entgegen, liest es und nickt.>$B$BDie Inseln der $R, die Azurmythosinsel und die Blutmythosinsel, wurden vor langer Zeit von meinen Leuten bewohnt. Einige der Bedrohungen, denen sich Anachoret Paetheus und seine Brüder und Schwestern jetzt stellen müssen, sind alte Feinde der Nachtelfen.$B$BIch bin mir sicher, dass man unseren neuen Verbündeten hier in Auberdine alles zur Verfügung stellen möchte, das benötigt wird. Sobald ich mit den Bewohnern der Stadt und den Schildwachen gesprochen habe, werde ich Paetheus benachrichtigen.", 26972);

-- 9634 - Raubtiere aus einer anderen Welt
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9634 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9634, "deDE", "Wir müssen handeln, bevor die Felshetzer die einheimischen Raubtiere der Blutmythosinsel verdrängen. Konntet Ihr den Felshetzerbestand bereits etwas dezimieren?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9634 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9634, "deDE", "Gut gemacht, $N. Der Felshetzerbestand wird zwar nur für einige Zeit begrenzt bleiben, aber es ist ein guter Anfang.", 26972);

-- 9641 - Bestrahlte Kristallsplitter
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9641 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9641, "deDE", "Konntet Ihr Kristallsplitter von den Kreaturen der Blutmythosinsel einsammeln?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9641 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9641, "deDE", "Gut gemacht. Diese Splitter werden als Rohmaterial für weitere Stärkungskristalle dienen.$B$BIhr könnt Euch einen der drei Typen aussuchen, die ich herstellen kann. Ich finde sie alle recht nützlich, je nachdem auf welche Beute man es abgesehen hat.", 26972);

-- 9642 - Mehr bestrahlte Kristallsplitter
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9642 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9642, "deDE", "Solltet Ihr noch über mehr bestrahlte Kristallsplitter verfügen, tausche ich sie gerne gegen einen weiteren meiner Kristalle ein.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9642 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9642, "deDE", "Sehr schön, hier sind meine Kristalle, $N. Verwendet sie weise.", 26972);

-- 9643 - Würgeranken
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9643 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9643, "deDE", "Habt Ihr die Würgeranken bekommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9643 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9643, "deDE", "Das scheint mir stabil genug für meine Konstruktion. Danke für die Hilfe, $N. Euer Unterstützung bei der Verteidigung der Blutwacht wird nicht vergessen werden.", 26972);

-- 9646 - GESUCHT: Todespranke
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9646 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9646, "deDE", "Wie kann ich Euch helfen, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9646 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9646, "deDE", "Gut gemacht. Von dem, was ich gehört habe, war es wohl kein leichter Kampf. Ihr habt Euch Eure Belohnung mehr als verdient, $N.", 26972);

-- 9647 - Ausmerzen der Falter
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9647 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9647, "deDE", "Es gilt jetzt, eine längerfristige Lösung zu finden, um die Arten wieder in ihren Urzustand zurückzuführen. Momentan ist das zeitweilige Ausmerzen ihres Bestandes jedoch die beste Methode. Danke für Eure Hilfe, $N.", 26972);

-- 9648 - Pilzsammlung von Mac'Aree
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9648 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9648, "deDE", "Vergesst nicht, die von mir benötigten Pilze sind einzigartig in unterschiedlichen Gebieten der Blutmythosinsel.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9648 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9648, "deDE", "Nun, ich hatte Euch gewarnt - oder etwa nicht? Ich hoffe diese kleine Bezahlung wird Euch für Eure Unannehmlichkeiten etwas entschädigen können. Kehrt zu mir zurück, sobald Ihr Euch ein wenig erholt habt, dann habe ich vielleicht noch eine Aufgabe für Euch - mit Pilzen natürlich!", 26972);

-- 9649 - Yseras Tränen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9649 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9649, "deDE", "Schon wieder zurück?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9649 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9649, "deDE", "Ich hoffe diese Aufgabe hat nicht zu viel von Euch abverlangt, $N. Ihr habt erneut bewiesen, dass Ihr $Gein fähiger und aufmerksamer:eine fähige und aufmerksame; $R seid. Habt meinen Dank und natürlich eine kleine Abfindung.", 26972);

-- 9663 - Der Korsallauf
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9663 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9663, "deDE", "Ihr habt jetzt keine Zeit zum Ausruhen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9663 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9663, "deDE", "Gut gemacht, $N. Dies war ein Test Eurer Fähigkeiten, aber Ihr habt mit wehenden Fahnen bestanden. Um ein Soldat der Hand von Argus zu werden, gilt es viele dieser Tests zu bestehen.", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Oberhäuptling der Tannenruhfeste gewarnt", `ObjectiveText2`="Exarch Menelaous gewarnt", `ObjectiveText3`="Admiral Odesyus gewarnt", `VerifiedBuild`=26972 WHERE `ID` = 9663 AND `locale` = "deDE";

-- 9666 - Machtdemonstration
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9666 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9666, "deDE", "Es tut mir leid, dass Ihr das tun musstet, $N. Rohe Gewalt entspricht nicht der Natur der $R, aber manchmal ist sie der einzige Weg.$B$BUnglücklicherweise gehört dies zum Leben und man versteht es oft erst dann, wenn es zu spät ist. Genau wie mit den Orcs, die unsere Brüder und Schwestern abschlachteten.$B$BEin Mitglied der Hand von Argus zu werden, ist ein Prozess der Wiedergeburt. Mit der Geburt kommt bekanntlich auch der Schmerz...", 26972);

-- 9667 - Rettet die Prinzessin der Tannenruhfeste
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9667 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9667, "deDE", "Ihr habt erneut bewiesen, dass Ihr all dem entsprecht, was in der Prophezeiung vorhergesagt wurde. Ihr habt den ewigen Dank des Oberhäuptlings, $N - und Ihr habt die Wahl zwischen diesen Relikten der Tannenruhfeste...", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Prinzessin der Tannenruhfeste gerettet", `VerifiedBuild`=26972 WHERE `ID` = 9667 AND `locale` = "deDE";

-- 9668 - Erstattet Exarch Admetius Bericht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9668 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9668, "deDE", "Ich hatte es bereits im Gefühl, dass Ihr es bis hierher schaffen würdet, $C. Wenn Ihr noch weiter kommen möchtet, bin ich gerne bereit Euch zu unterrichten...", 26972);

-- 9669 - Forschungsreise in den Tod
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9669 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9669, "deDE", "Es war einfach grauenhaft...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9669 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9669, "deDE", "Unglaublich! Konntet Ihr andere Überlebende finden?$B$B<Achelus senkt seine Stimme zu einem Flüstern.>$B$BIch möchte ehrlich mit Euch sein, $N, niemand sonst wollte diesen Auftrag annehmen. Ihr seid sehr mutig, $C...", 26972);

-- 9670 - Sie leben! Vielleicht...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9670 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9670, "deDE", "Und, hattet Ihr Glück?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9670 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9670, "deDE", "Ihr habt mehr als die Hälfte des Teams befreit! Der Exarch und die anderen bei der Blutwacht werden mit Sicherheit von Eurer heldenhaften Tat erfahren. Ich danke Euch, $N.", 26972);

-- 9671 - Dringende Nachricht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9671 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9671, "deDE", "Seid Ihr $N? Es wurde auch Zeit! Ich war gerade dabei, die Suche nach Euch aufzugeben!$B$BBeim Briefkasten wartet eine dringende Nachricht auf Euch. Die Person, die sie mir übergeben hatte, war ein Admiral der Menschen von der Azurmythosinsel. Admiral Odesy-irgendwas... der Name ist mir entfallen. Er sagte, Ihr würdet wissen, wer er sei.", 26972);

-- 9672 - Das Vermächtnis des Blutfluchs
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9672 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9672, "deDE", "Habt Ihr von dem Blutfluch gehört, Landratte? Nein, natürlich nicht. Der Blutfluch ist das, was all diese Schiffe hat sinken lassen. Der verderbte, entweihte Teil des Wassers hier wird Riff des Blutfluchs genannt - ein Teil der Welt, den Ihr niemals sehen möchtet. Ich bin hier selbst seit 20 Jahren.$B$BSkorbut, so ein Quatsch! Ich starb an diesen Wilden Ufern als Drachenfutter... Ah, das ist wieder eine andere Geschichte, für ein anderes Mal. Jetzt müssen wir den armen Seelen helfen, die hier im Riff gefangen sind.", 26972);

-- 9674 - Die Naga des Blutfluchs
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9674 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9674, "deDE", "Ein guter Anfang, aber es gibt noch viel mehr zu tun!", 26972);

-- 9675 - Großer Bärengeist
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9675 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9675, "deDE", "Oh, da wäre noch etwas! Ihr solltet mit Ganaar bei der Exodar sprechen. Er wird Euch das letzte bisschen Wissen bezüglich der Pflege und Ausbildung Eures Begleiters lehren.$B$BIhr findet ihn in der südwestlichen Ecke der Händlertreppe.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9675 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9675, "deDE", "Zu wissen, wie man seinen Begleiter füttert und wiederbelebt, ist nicht nur ein zusätzlicher Leckerbissen, wie Euer letzter Lehrer so gelinde sagte - es ist viel mehr. Mit der richtigen Ausbildung kann sich Euer Begleiter auf eine Weise verbessern, wie er es nie von alleine getan hätte.$B$BIch habe bereits viel von den Furbolgs gelernt, also gebt Acht und ich werde dieses Wissen an Euch weitergeben.", 26972);

-- 9682 - Die Hoffnungslosen...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9682 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9682, "deDE", "Trauert ihrem Niedergang nicht nach, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9682 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9682, "deDE", "Ihr habt den Hoffnungslosen einen großen Dienst erwiesen, $N. Es gilt jedoch noch eine letzte Aufgabe zu erledigen: Tötet den Anführer des Blutfluchs.", 26972);

-- 9683 - Bärdarfsgüter
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9683 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9683, "deDE", "Ihr habt es geschafft! Hunderte von Seelen sind Euch für alles, was Ihr getan habt, dankbar.$B$BGestattet mir, Euch etwas zu überreichen...", 26972);

-- 9687 - Wiederherstellung der Heiligkeit
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9687 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9687, "deDE", "Die Kriege der Drachen sind seit langem vorüber. Was noch bleibt, sind die Knochen und die aufgewühlten Überbleibsel von Yseras Brut.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9687 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9687, "deDE", "Ein Ritual? Die Eulkin haben seit tausenden von Jahren mit dem Land in Einklang gelebt. Derartiges ist nicht normal!$B$BWie bedauerlich...", 26972);

-- 9688 - Im Traum
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9688 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9688, "deDE", "Das Zusehen allein schmerzt mich. Bitte, lasst uns nicht noch weiter darüber sprechen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9688 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9688, "deDE", "Wie verwerflich Eure Aufgabe auch war, es musste einfach getan werden. Jetzt müsst Ihr in das Angesicht des Bösen sehen.", 26972);

-- 9689 - Messerrachen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9689 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9689, "deDE", "Ich rate Euch, Verbündete mit Euch zu bringen, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9689 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9689, "deDE", "Wie lange war es noch? Tausend Jahre? Zehntausend Jahre vielleicht? Ihr habt mir und der Erinnerung meiner Leute einen großen Dienst erwiesen, $N. Bitte, nehmt diesen mächtigen Gegenstand als Zeichen der Anerkennung von Loreth'Aran an - für Eure ehrenvollen Taten.", 26972);

-- 9693 - Was Argus für mich bedeutet
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9693 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9693, "deDE", "Ah, $N... ich habe bereits von Euch gehört. Ihr seid also derjenige, der den Korsallauf in unter 15 Minuten gemacht hat. Ts, wahrscheinlich nicht.$B$BSeid Ihr bereit, etwas Blut im Namen des Lichts zu vergießen? Für Velen? Für Argus?$B$B<Boros lacht.>$B$BGut, gut, ich halte mich jetzt besser zurück.", 26972);

-- 9694 - Blutwacht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9694 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9694, "deDE", "Es gibt so viele von ihnen... ich komme einfach nicht von dem Gefühl los, dass sie sich irgendwie vermehren.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9694 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9694, "deDE", "Ihr seid zurück - in einem Stück!$B$BIch habe gute Neuigkeiten, $N. Wir haben neue Informationen zum wahrscheinlichen Aufenthaltsort weiterer Überlebender erhalten. Eine neue Absturzstelle wurde entdeckt! Sobald ich mich eingehender damit befasst habe, werde ich mich an Euch wenden.", 26972);

-- 9696 - Übersetzungen...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9696 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9696, "deDE", "Ich habe hier etwas viel zu tun, $GAgent:Agentin; $N. Ich hoffe Euer Anliegen ist wichtig.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9696 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9696, "deDE", "<Elysia liest das Dokument.>$B$BWenn wirklich stimmt, was hier steht, dann haben die Blutelfen ein Portal zur Scherbenwelt geöffnet! Das würde auch ihre schier endlose Zahl erklären...", 26972);

-- 9698 - Audienz beim Propheten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9698 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9698, "deDE", "<Velen lächelt.>$B$BSeid gegrüßt, $N. Ich habe Euch erwartet.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9698 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9698, "deDE", "<Velen beginnt das Dokument zu lesen.>$B$BInteressant... dies erklärt in der Tat einiges.", 26972);

-- 9699 - Was ist wahr?
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9699 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9699, "deDE", "Ja?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9699 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9699, "deDE", "Es ist ein guter Plan, aber auch ein gefährlicher. Ich bin mir jedoch sicher, dass alles gut verlaufen wird.", 26972);

-- 9700 - Licht ins Dunkel bringen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9700 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9700, "deDE", "Wie viele sagtet Ihr doch gleich, habt Ihr bei der Warpgondel gesichtet? Wie oft haben sie nur dieses Sonnenportal geöffnet? Das sind sehr schlechte Neuigkeiten...$B$BTja, Ihr habt Euch nun alles von mir angeeignet, was ich Euch lehren kann, $N. Kuros wird nach Euch rufen lassen, wenn es an der Zeit ist.", 26972);

-- 9703 - Der Kryokern
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9703 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9703, "deDE", "Waren die Informationen korrekt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9703 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9703, "deDE", "Nur Blutelfen? Keine Überlebenden? Das ist beunruhigend. Ich brauche etwas Zeit zum Nachdenken, $N. Vielleicht haben Aesom oder Boros einen Auftrag für Euch.", 26972);

-- 9706 - Galaens Tagebuch - Das Schicksal von Verteidiger Saruan
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9706 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9706, "deDE", "Was habt Ihr da, $N? Ist das ein Tagebuch?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9706 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9706, "deDE", "<Kuros erbleicht beim Lesen des Tagebuchs und Tränen strömen seine Wangen herab.>$B$BSaruan war mein Meister... mein Lehrer... mein Mentor... Ich nahm seinen Platz im Dreigestirn erst vor Kurzem ein - nachdem wir die Suche nach ihm aufgegeben hatten.$B$B<Kuros' Gesichtsausdruck schlägt in Zorn über.>$B$BMatis...", 26972);

-- 9711 - Matis der Grausame
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9711 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9711, "deDE", "Ein Soldat von Matis' Stand wird nicht alleine unterwegs sein. Gebt da draußen auf Euch Acht.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9711 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9711, "deDE", "Das Dreigestirn hat beschlossen, Matis sofort zu verurteilen. Ihr habt heute einen Erzverbrecher der Gerechtigkeit überführt, junger $R.$B$BIhr habt für zwei von drei außerordentliche Arbeit geleistet, lediglich Aesom fehlt.", 26972);

-- 9740 - Das Sonnentor
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9740 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9740, "deDE", "Fabelhaft! Wir haben ihre Versorgungszufuhr durchtrennt. Jetzt müssen wir sie nur noch kaltmachen!", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Sonnentor zerstört", `VerifiedBuild`=26972 WHERE `ID` = 9740 AND `locale` = "deDE";

-- 9741 - Geschöpfe aus der Leere
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9741 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9741, "deDE", "Dort herrscht ein ganz schönes Durcheinander, was? Gute Arbeit, $N. Ich werde ein paar Anachoreten entsenden, die Loryi und Jorli helfen werden.", 26972);

-- 9746 - Grenze der Erschöpfung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9746 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9746, "deDE", "Dies wird ihre Verteidigung ganz sicher geschwächt haben. Ab sofort werden sie es sich zweimal überlegen, bevor sie uns kopflos überfallen!", 26972);

-- 9748 - Trinkt nicht das Wasser
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9748 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9748, "deDE", "Trinkt nicht das Wasser, $N!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9748 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9748, "deDE", "Wie ich vermutet habe, ist das Wasser von der Verseuchung durch die austretende Kernflüssigkeit rot geworden.$B$BIch hoffe, dass Ihr nicht in dem verseuchten Wasser geschwommen seid.", 26972);

-- 9751 - Das Vermächtnis des Blutfluchs
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9751 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9751, "deDE", "Habt Ihr von dem Blutfluch gehört, Landratte? Nein, natürlich nicht. Der Blutfluch ist das, was all diese Schiffe hat sinken lassen. Der verderbte, entweihte Teil des Wassers hier wird Riff des Blutfluchs genannt - ein Teil der Welt, den Ihr niemals sehen möchtet. Ich bin hier selbst seit 20 Jahren.$B$BSkorbut, so ein Quatsch! Ich starb an diesen Wilden Ufern als Drachenfutter... Ah, das ist wieder eine andere Geschichte, für ein anderes Mal. Jetzt müssen wir den armen Seelen helfen, die hier im Riff gefangen sind.", 26972);

-- 9753 - Was wir wissen...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9753 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9753, "deDE", "Ja?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9753 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9753, "deDE", "Ich brauche Eure Hilfe, $N. Es ist mein Plan, die gesamte Armee der Sonnenfalken zu stürzen. Zuvor gilt es jedoch ein paar grundlegende Informationen zu sammeln.$B$BWir müssen die Schwäche ihrer Verteidigung ausmachen. Unglücklicherweise ist es uns bis jetzt noch nicht gelungen, nahe genug an die Vektorspule heranzukommen und ihre Verteidigung auszukundschaften. Wenn wir den Gefangenen zum Sprechen bringen könnten, würden wir womöglich die Informationen bekommen, die wir brauchen, um durch ihre Verteidigung zu brechen und die Vektorspule zu zerstören.$B$BIhr habt richtig gehört, ich will das verdammte Ding in die Luft jagen.", 26972);

-- 9756 - Was wir nicht wissen...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9756 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9756, "deDE", "Kehrt erst wieder zurück, wenn Ihr erfolgreich gewesen seid!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9756 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9756, "deDE", "A-ha! Gut gemacht, $N. Wirklich sehr gut gemacht. Seid Ihr bereit der Blutelfenbedrohung unserer Insel nun endlich ein Ende zu bereiten?", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Informationen der Sonnenfalken erhalten", `VerifiedBuild`=26972 WHERE `ID` = 9756 AND `locale` = "deDE";

-- 9757 - Sucht Jägerin Kella Nachtbogen auf
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9757 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9757, "deDE", "Lasst uns sofort mit der Ausbildung beginnen!", 26972);

-- 9579 - Ihre Welt enden lassen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9579 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9579, "deDE", "Ihr habt die ganze Blutmythosinsel und Azurmythosinsel gerettet, das Leben der $R in Azeroth gesichert, $N! Dafür wird man Euch niemals genug danken können, keine Belohnung, nichts ist groß genug, um Euch unsere Anerkennung zu zeigen.$B$BLeider blieben noch so viele auf Draenor zurück, die dieses historische Ereignis nicht miterleben können. Ihr müsst Euren Weg zurückfinden. Findet Euren Weg zur Scherbenwelt, Held von Argus. Bringt Eure Leute nach Hause. Nach Hause in das Land, das Ihr gerettet habt. Nach Azeroth...", 26972);

-- 9760 - Verteidigers Ruh'
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9760 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9760, "deDE", "Ja?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9760 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9760, "deDE", "Vielleicht verhelft Ihr unserem Volk ja zu einem neuen Zeitalter des Wohlstands und des Friedens.", 26972);

-- 9761 - Den Weg frei machen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9761 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9761, "deDE", "Seht Ihr hier irgendwo einen ungewöhnlich mutigen und starken Draenei?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9761 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9761, "deDE", "Hoffentlich meldet sich bald ein Held, bevor sie Verstärkung anfordern können, um die gerade von Euch abgesicherte Gegend zu bewachen.", 26972);

-- 9779 - Abfangen der Nachricht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9779 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9779, "deDE", "Schon zurück? Konntet Ihr das Schreiben finden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9779 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9779, "deDE", "<Verteidiger Boros betrachtet das Dokument.>$B$BDas ist Thalassisch. Glücklicherweise kenne ich eine Person, die es übersetzen kann...", 26972);

-- 10063 - Forscherliga, für Gnome geeignet?
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10063 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10063, "deDE", "Dachte ich's mir doch! Dieser mürrische alte Zwerg sollte mir eigentlich beim Transport meiner Ausrüstung und dem Sammeln von Daten helfen, aber stattdessen sitzt er nur in dem komischen Draeneidorf herum und betrinkt sich sinnlos.", 26972);

-- 10064 - Sprecht zu der Hand
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10064 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10064, "deDE", "Ja?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10064 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10064, "deDE", "Ich habe gehofft, dass die Blutwacht uns Verstärkung schicken würde, sobald man dort weiß, mit wem wir es hier zu tun haben.", 26972);

-- 10065 - Eine Schneise schlagen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10065 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10065, "deDE", "Es sieht da draußen schon etwas besser aus, ich bin mir jedoch noch immer nicht sicher, ob es besser wäre, hier auf medizinische Versorgung zu warten.", 26972);

-- 10066 - Alles im Griff
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10066 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10066, "deDE", "Konntet Ihr ein paar mutierte Greifer ausmerzen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10066 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10066, "deDE", "Gut gemacht, $N. Ohne die Tücken der Greifer, wird es jetzt wesentlich einfacher sein, Verstärkung von der Blutwacht zu erhalten oder Angriffe gegen die Sonnenfalken zu starten.", 26972);

-- 10067 - Besudelte Wassergeister
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10067 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10067, "deDE", "Gut gemacht, $N. Es ist besonders wichtig, dass wir keine Möglichkeit außer Acht lassen, die den Sonnenfalken weiterhin ihre Existenz sichern könnte.", 26972);

-- 10350 - Sucht Jägerin Kella Nachtbogen auf
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10350 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10350, "deDE", "Ah, Ihr seid also endlich gekommen. Ich bin Behomat und werde Euch in den Künsten eines Kriegers unterweisen. Ruada hat mir von Eurer Prüfung gegen den Felshetzer erzählt und ich bin sehr beeindruckt. Ich habe ein Geschenk für Euch.$B$BWir konnten nur wenig aus den Trümmern der Exodar retten, und das verteilen wir nur an die Würdigsten. Bitte nehmt Euch eine Waffe, die Eurem Kampfstil entspricht, und führt sie mit dem Wissen, dass Ihr sie verdient habt.$B$BWo wir gerade von Kampfstilen sprechen - es ist Zeit, dass Ihr etwas Neues lernt.", 26972);

-- 10366 - Sucht Jägerin Kella Nachtbogen auf
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10366 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10366, "deDE", "$N, ich habe Euch erwartet.$B$BTullas hat Lobeshymnen auf Euch gesungen, und ich bin sehr begierig darauf, Euch im Weg des Lichts zu unterweisen. Sucht mich auf, wenn Ihr bereit seid, Eure Fähigkeiten und Eure Macht verstehen zu lernen, und ich werde Euch geleiten.", 26972);
*/
