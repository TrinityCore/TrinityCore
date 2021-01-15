-- Quest 170 - add missing data
-- https://de.classic.wowhead.com/quest=170/eine-neue-bedrohung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 170 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(170, 'deDE', 'Zähe kleine Biester, was?', 0);

-- Quest 3361 - update data
-- Typo: $Regeran -> Gnomeregan
UPDATE `quest_request_items_locale` SET `CompletionText` = 'Liebe Güte $N, diese Stadt ist für Leute wie mich nicht sehr geeignet. Hier gibt es ja ebenso viele widerliche Kreaturen wie in Gnomeregan vor diesem Unfall!$B$BHabt Ihr meine Habseligkeiten? Falls nicht... oje, wer weiß, was die Trolle damit angestellt haben...', `VerifiedBuild` = 0 WHERE `ID` = 3361 AND `locale` = 'deDE';

-- Quest 3114 - update data
-- Typo: $Regeran -> Gnomeregan
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Oh, ja! Arkane Künste... klaro.$B$BDas müsst Ihr wissen, $N: Geht Ärger möglichst aus dem Weg. Spart einige Münzen auf, um mir ein Bier zu kaufen... oder irgendwelche Zauber, die Ihr wollt. Und bleibt auf jeden Fall weg von Gnomeregan. Ansonsten wünsche ich Euch einen angenehmen Tag! Ich werde hier sein, wenn Ihr mich braucht oder trainieren wollt... oder was auch immer.', `VerifiedBuild` = 0 WHERE `ID` = 3114 AND `locale` = 'deDE';

-- Quest 183 - add missing data
-- https://de.classic.wowhead.com/quest=183/der-eberjäger
DELETE FROM `quest_request_items_locale` WHERE `ID` = 183 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(183, 'deDE', 'Wie läuft die Jagd?', 0);

-- Quest 234 - add missing data
-- https://de.classic.wowhead.com/quest=234/postbeförderung-im-coldridgetal
DELETE FROM `quest_request_items_locale` WHERE `ID` = 234 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(234, 'deDE', 'Kann ich Euch behilflich sein?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 234 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(234, 'deDE', 'Ah, ausgezeichnet. Es ist schon eine Weile her, dass ich Nachricht aus Eisenschmiede hatte.', 0);

-- Quest 218 - update data
-- Typo: "Text: ..."
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Großartig, $N! Vielen Dank, dass Ihr mein Notizbuch zurückgeholt habt. Nun, es scheint, als sei das Trollproblem hier im Eisklammtal unter Kontrolle und als müssten wir uns nicht allzu viele Sorgen machen.$B$BNachdem ich meinem Bericht den letzten Schliff gegeben habe, werde ich jemanden brauchen, der ihn meinem Bruder Senir bringt.', `VerifiedBuild` = 0 WHERE `ID` = 218 AND `locale` = 'deDE';

-- Quest 420 - add missing data
-- https://de.classic.wowhead.com/quest=420/senirs-beobachtungen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 420 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(420, 'deDE', 'Wie geht es Euch? Wollt Ihr vielleicht etwas mit mir trinken? Es gibt in der Kälte sonst nichts zu tun.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 420 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(420, 'deDE', 'Was ist das? Ah, der Bericht meines Bruders. Hmm...$B$BIch habe ihm gesagt, er soll den Namen des Königs nur dezent einsetzen, aber er wollte ja nicht auf mich hören. Es kann nicht schaden, schätze ich, aber es werden sich auf alle Fälle einige im Senat die Haare raufen. Nicht, dass die diese Rauferei nicht mal nötig hätten! Ha!$B$BNichtsdestotrotz heißt das wohl, dass ich meinen Bericht ebenfalls nach Eisenschmiede schicken sollte, aber ich muss zugeben, dass ich etwas im Rückstand bin. Verdammte Kälte.$B$BIch dürfte später etwas Arbeit für Euch haben, wenn Ihr Interesse habt.', 0);

-- Quest 400 - add missing data
-- https://de.classic.wowhead.com/quest=400/werkzeuge-für-steelgrill + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 400 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(400, 'deDE', 'Hm? Ihr seht etwas zu jung aus für einen Piloten der Belagerungsmaschinen. Aber egal... Braucht Ihr eine Reparatur?$B$BDann zieht eine Nummer und macht es Euch bequem. Ich arbeite gerade an ein paar Maschinen und werde wenigstens einige Tage lang keine Zeit für weitere Aufträge haben.$B$BOder seid Ihr wegen etwas anderem hier...?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 400 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(400, 'deDE', 'Ihr habt meine Werkzeuge? Gut gemacht, $GJunge:Mädchen;, gut gemacht! Ich habe gerade vor einer Stunde meine letzte Zahnratsche zerbrochen, und ich brauche eine, um die Reparatur an Pilot Steinsegels Belagerungsmaschine abzuschließen. Gut, dass Ihr diese Werkzeuge hierher geschafft habt, $N.$B$BHier, nehmt diese Münzen, für Eure Hilfe.', 0);

-- Quest 5541 - add missing data
-- https://de.classic.wowhead.com/quest=5541/munition-für-rumbleshot
DELETE FROM `quest_request_items_locale` WHERE `ID` = 5541 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5541, 'deDE', 'Ich hoffe, Ihr seid nicht wegen Munition hier, denn ich habe fast keine mehr!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 5541 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5541, 'deDE', 'Wunderbar, mehr Munition! Die Lieferung vom alten Loslor ist endlich da! Na ja, die Munition mag etwas verspätet ankommen, aber wie schon mein Großvater mir immer gesagt hat: Besser spät als nie!$B$BVielen herzlichen Dank, $N. Ich habe bereits Käufer, die begierig auf dieses Zeug warten!', 0);

-- Quest 317 - add missing data
-- https://de.classic.wowhead.com/quest=317/vorräte-für-jetsteam
DELETE FROM `quest_request_items_locale` WHERE `ID` = 317 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(317, 'deDE', 'Die Vorbereitungen laufen gut. Wie geht es mit der Jagd voran?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 317 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(317, 'deDE', 'Bei Magnis Bart, Ihr habt wirklich ganz schön viel gejagt!! Danke, $N.', 0);

-- Quest 313 - update data
-- https://de.classic.wowhead.com/quest=313/der-altgediente-bau + old GTDB WotLK files
UPDATE `quest_template_locale` SET `Title` = 'Der Graufelsbau', `Details` = 'Nicht jeder ist dazu geschaffen, eine Belagerungsmaschine zu fahren. Dazu braucht man eine eiserne Hand und Nerven aus Stahl... zum Glück besitze ich beides! Wie steht\'s mit Euch? Wie groß ist euer Talent? Wollt Ihr es mir nicht zeigen?$B$BWie auch immer... ich versuche gerade, meine Maschine, Trollpflug, etwas gemütlicher zu machen. Wie wäre es, wenn Ihr mir einen Haufen Wendigomähnen aus dem Graufelsbau westlich von Kharanos besorgt? Diese Mähnen könnten einen tollen Teppich für das Innendeck abgeben!', `Objectives` = 'Sammelt 8 Wendigomähnen und bringt sie Pilot Steinsegel.', `CompletedText` = 'Kehrt zu Pilot Steinsegel in Stahlrosts Depot in Dun Morogh zurück.', `VerifiedBuild` = 0 WHERE `ID` = 313 AND `locale` = 'deDE';
UPDATE `quest_request_items_locale` SET `CompletionText` = 'He, $N. Wart Ihr schon im Graufelsbau? Diese Wendigos können ziemlich heftig sein.', `VerifiedBuild` = 0 WHERE `ID` = 313 AND `locale` = 'deDE';
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Oh ja, diese Mähnen sind genau richtig! Ihr zeigt viel Schneid, $C - ich wette, man kann noch viele großartige Taten von Euch erwarten.', `VerifiedBuild` = 0 WHERE `ID` = 313 AND `locale` = 'deDE';

-- Quest 318 - add missing data
-- https://de.classic.wowhead.com/quest=318/immerschimmer + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 318 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(318, 'deDE', 'Bellfiz braucht etwas von meinem Immerschimmer? Hm... in Ordnung.', 0);

-- Quest 319 - add missing data
-- https://de.classic.wowhead.com/quest=319/ein-gefallen-für-etwas-immerschimmer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 319 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(319, 'deDE', 'Habt Ihr Euch um die wilden Tiere gekümmert? ', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 319 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(319, 'deDE', 'Danke, $N. Es wird angenehm sein, unser Handwerk auszuüben, ohne ständig irgendwelches Knurren und Schnauben vor dem Dorf zu hören. ', 0);

-- Quest 315 - update data
-- https://de.classic.wowhead.com/quest=315/das-perfekte-starkbier + old GTDB WotLK files
UPDATE `quest_template_locale` SET `Details` = 'Ich bin von einem Vorhaben besessen, dem Vorhaben, das perfekte Starkbier herzustellen. Ich weiß, dass ich es schaffen kann - das Brauen liegt mir im Blut. Ich muss nur das richtige Rezept finden...$B$BWeit oben in den Bergen im Osten bauen die Trolle der Frostmähnen eine Pflanze an, Schimmerkraut genannt. Sie verwenden sie in ihren seltsamen Stammesritualen. Wir Zwerge haben bisher keine wirkliche Verwendung dafür gefunden, aber sie hat einen einzigartigen Geschmack... und ich möchte damit in meinen Gebräuen herumexperimentieren.$B$BBesorgt mir etwas Schimmerkraut von den Sehern der Frostmähnen oder klaut es aus den Schimmerkrautkörben der Trolle.', `Objectives` = 'Bringt Rejold Gerstenbräu in Bräuhall 6 Schimmerkräuter.', `CompletedText` = 'Kehrt zu Rejold Gerstenbräu nach Bräuhall in Dun Morogh zurück.', `VerifiedBuild` = 0 WHERE `ID` = 315 AND `locale` = 'deDE';

-- Quest 412 - update data
-- https://de.classic.wowhead.com/quest=412/operation-rekombobulationsgerät + old GTDB WotLK files
UPDATE `quest_template_locale` SET `Details` = 'Nach genauerer Analyse der Situation in Gnomeregan sieht es so aus, als hätten wir nicht nur dabei versagt, die Troggs auszulöschen, sondern als hätten wir dabei auch noch einen Großteil des Volkes der Gnome in schreckliche, hirnlose, bösartige Lepragnome verwandelt.$B$BOzzie und ich haben vor, den schrecklichen Lepraeffekt mit unserer jüngsten Erfindung wieder rückgängig zu machen: der Rekombobulator. Die Maschine ist beinahe fertig, aber wir brauchen dringend einige Restabilisationszahnräder und gyromechanische Getriebeteile. Besorgt uns ein paar davon bei den Lepragnomen drüben in Gnomeregan.', `Objectives` = 'Bringt Razzle Flinkspross in Kharanos 8 Restabilisationszahnräder und 8 gyromechanische Getriebeteile.', `CompletedText` = 'Kehrt zu Razzle Flinkspross in Dun Morogh zurück.', `VerifiedBuild` = 0 WHERE `ID` = 412 AND `locale` = 'deDE';
UPDATE `quest_request_items_locale` SET `CompletionText` = 'Der Rekombobulator wird laufen wie geschmiert, sobald wir ausreichend Restabilisationszahnräder und gyromechanische Getriebeteile haben.', `VerifiedBuild` = 0 WHERE `ID` = 412 AND `locale` = 'deDE';
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Diese gyromechanischen Getriebeteile und Restabilisationszahnräder stimmen genau mit Ozzies Bauplan für das Rekombobulationsgerät überein. Sobald ich jetzt etwas Hydroschmiermittel auf die inneren Verbrennungskolben gebe, die Kurbelratsche justiere und die Zähflüssigkeit des Electrogumgels erhöhe, wird das gnomische Volk wieder wie neu sein.', `VerifiedBuild` = 0 WHERE `ID` = 412 AND `locale` = 'deDE';

-- Quest 320 - add missing data
-- https://de.classic.wowhead.com/quest=320/rückkehr-zu-bellowfiz + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 320 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(320, 'deDE', 'Habt Ihr den Immerschimmer bekommen können?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 320 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(320, 'deDE', 'Ja, das ist genau richtig. Ich denke, ich werde gleich mal eine Flasche aufmachen und einen Schluck zu mir nehmen...', 0);

-- Quest 287 - update and add missing data
-- https://de.classic.wowhead.com/quest=287/höhle-der-frostmane + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 287 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(287, 'deDE', 'Findet Ihr nicht hin? Meine Richtungsangaben waren eindeutig! Wir haben nicht viel Zeit, beeilt Euch! Kommt nicht wieder, bevor Ihr die Höhle nicht gefunden habt.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 287 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(287, 'deDE', 'Ah, $N! Ich hätte nicht gedacht, dass Ihr Probleme hättet, dorthin zu finden. Meine Richtungsangaben sind vortrefflich, wisst Ihr...$B$BLasst mich gerade noch schnell meinen Bericht fertig stellen.$B$B<Er holt etwas Papier hervor und kritzelt kurz darauf herum.>$B$BHier! Nun, haha, ja, das ist jetzt wirklich lustig... Kann ich davon ausgehen, $N, dass es Euch nichts ausmachen würde, mir einen letzten Gefallen zu tun?', 0);

-- Quest 403 - add missing data
-- https://de.classic.wowhead.com/quest=403/das-bewachte-fass-mit-donnerbier
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 403 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(403, 'deDE', 'Dieses Fass Bier wird von Jarven Donnerbräu bewacht. Solange er im Keller ist, kann man sich nicht an den Fässern zu schaffen machen.', 0);

-- Quest 308 - add missing data
-- https://de.classic.wowhead.com/quest=308/jarvens-ablenkung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 308 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(308, 'deDE', 'Hmpf! Hier steht soviel Alkohol herum, aber ich habe strikte Befehle, ihn nicht anzurühren. Wenn ich nur einen Schluck unseres Donnerbiers bekommen könnte... Das würde meinen Verstand anregen, ehrlich!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 308 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(308, 'deDE', 'Für mich? Ihr seid ein wahrer Held, $N!', 0);

-- Quest 310 - add missing data
-- https://de.classic.wowhead.com/quest=310/bittere-rivalen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 310 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(310, 'deDE', 'Die Datumsangabe auf diesem Fass legt nahe, dass es demnächst angestochen werden wird.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 310 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(310, 'deDE', 'Schnell stellt Ihr Marleths Fass voll Gerstenbräu zwischen die Fässer der Brauerei Donnerbräu.', 0);

-- Quest 311 - add missing data
-- https://de.classic.wowhead.com/quest=311/rückkehr-zu-marleth
DELETE FROM `quest_request_items_locale` WHERE `ID` = 311 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(311, 'deDE', 'Habt Ihr den Austausch vollzogen?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 311 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(311, 'deDE', 'Nicht schlecht, $N! War es schwierig, an der Wache vorbeizukommen?$B$BEgal - vielen Dank, und wenn Ihr jemals ein Starkbier mit Pepp haben wollt, denkt an die Gerstenbräus!', 0);

-- Quest 433 - update data
-- https://de.classic.wowhead.com/quest=433/im-dienste-des-volkes + old GTDB WotLK files
UPDATE `quest_template_locale` SET `Details` = 'Als Mitglied des Senats und der Forscherliga habe ich mir vorgenommen, mich um den Teil der Troggplage zu kümmern, der unser Land heimsucht.$B$BSie haben den Steinbruch von Gol\'Bolar wirklich ziemlich verwüstet, und das ohne erkennbaren Grund. Als wir tiefer in die Erde hineingruben, strömten sie heraus, zerstörten unsere Ausrüstung und verjagten die Minenarbeiter. Wir können nicht viel mehr tun, als das ganze Pack auszulöschen, alles wieder aufzubauen und dann wieder an die Arbeit zu gehen.$B$BWenn Ihr mir mit den Troggs helft, werde ich Euch gern für Eure Zeit, die Ihr dafür opfert, entschädigen.', `Objectives` = 'Tötet für Senator Mehr Steingunst im Steinbruch von Gol\'Bolar 10 Knochenknacker der Felsenkiefer.', `VerifiedBuild` = 0 WHERE `ID` = 433 AND `locale` = 'deDE';
UPDATE `quest_request_items_locale` SET `CompletionText` = 'Wenn wir die Troggs vom Gol\'Bolar Steinbruch entfernen können, wäre das der Erste von vielen Schritten, die wir unternehmen müssen, um uns von dieser Bedrohung zu befreien.', `VerifiedBuild` = 0 WHERE `ID` = 433 AND `locale` = 'deDE';
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Das ist ein Anfang. Hoffentlich können wir ihn nutzen und einige Gebirgsjäger hineinschicken, um das Gebiet zu sichern. Dann können wir damit anfangen, unsere Infrastruktur wieder aufzubauen und unsere Minenarbeiter wieder an die Arbeit schicken.$B$BDanke für Eure Unterstützung, $N.', `VerifiedBuild` = 0 WHERE `ID` = 433 AND `locale` = 'deDE';

-- Quest 413 - add missing data
-- https://de.classic.wowhead.com/quest=413/schimmerstarkbier + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 413 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(413, 'deDE', 'Hallo, $C! Na, welche Geschäfte treiben Euch den weiten Weg bis nach hier draußen?$B$BHoffentlich etwas Aufregendes. Ich hatte seit Tagen keinen ordentlichen Kampf mehr, und dieses Fass Bier ist so gut wie leer...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 413 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(413, 'deDE', '<Gebirgsjäger Gerstenbräu probiert das Schimmerstarkbier... >$B$BOh, wow! Dieses Zeug treibt einem wirklich Glanz in die Augen. Ich fühle mich, als könnte ich im Dunkeln sehen!', 0);

-- Quest 419 - correct deDE locales and add missing data
-- https://de.classic.wowhead.com/quest=419/der-vermisste-pilot + old GTDB WotLK files
UPDATE `quest_template_locale` SET `Details` = 'Mein Freund Mori Hangflug, ebenfalls ein Pilot der Belagerungsmaschinen, hat sich in den Hügeln verirrt. Wir haben nach einem seltenen Erz gesucht, das man für hochwertiges Sprengpulver benötigt, und während unserer Suche hat er seine Maschine einen steilen Hügel hinaufgefahren und sie dabei kaputt gemacht!$B$BImmer noch überzeugt davon, dass es in diesen Bergen Erz gibt, hat er mich beauftragt, unsere Maschinen zu bewachen, während er zu Fuß weitersuchen wollte.$B$BDas ist jetzt mehrere Tage her, und ich habe in den Hügeln des Nachts das Knurren von Raubtieren gehört. Mori ist ein zäher Bursche, aber ich mache mir Sorgen.$B$BBitte, $N. Sucht ihn.', `Objectives` = 'Findet Pilot Hangflug.', `VerifiedBuild` = 0 WHERE `ID` = 419 AND `locale` = 'deDE';
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 419 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(419, 'deDE', 'Hier liegt die Leiche eines Zwergs - zerfetzt, gefroren und von Aasfressern blankgefressen. Seine Hand umklammert ein Buch, das die grob hingekritzelten Aufzeichnungen von Mori Hangflug enthält. Um ihn gehüllt, nach wie vor in sehr gutem Zustand, ist eine Brigadiersweste.$B$BAn diesem grausigen Ort muss der Pilot der Belagerungsmaschinen sein Ende gefunden haben.', 0);

-- Quest 417 - correct deDE locales and add missing data
-- https://de.classic.wowhead.com/quest=417/pilotenrache + old GTDB WotLK files
UPDATE `quest_template_locale` SET `Objectives` = 'Tötet Marterklaue.$B$BBringt Pilot Hammerfuß die räudige Klaue des Bären und Hangflugs Tagebuch.', `CompletedText` = 'Kehrt zu Pilot Hammerfuß am Nordtoraußenposten in Dun Morogh zurück.', `VerifiedBuild` = 0 WHERE `ID` = 417 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 417 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(417, 'deDE', 'Hallo, $N. Wisst Ihr etwas über den Verbleib meines Freundes Hangflug? ', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 417 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(417, 'deDE', 'Das sind traurige Neuigkeiten, denn Hangflug war ein guter Freund. Ich wünschte, ich hätte dort mit Euch sein können, als Ihr die Bestie Marterklaue gefunden habt!$B$BDanke, $N. Eure Tat wird den Piloten der Belagerungsbrigade von Eisenschmiede in Erinnerung bleiben.', 0);

-- Quest 6075 - add missing data
-- https://de.classic.wowhead.com/quest=6075/der-weg-des-jägers
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 6075 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6075, 'deDE', 'Ja, ich glaube, es ist an der Zeit, dass Ihr ausgebildet werdet...', 0);

-- Quest 414 - correct deDE locales and add missing data
-- https://de.classic.wowhead.com/quest=414/starkbier-für-kadrell + old GTDB WotLK files
UPDATE `quest_template_locale` SET `Objectives` = 'Bringt das Fässlein mit Schimmerstarkbier zu Gebirgsjäger Kadrell nach Loch Modan.', `VerifiedBuild` = 0 WHERE `ID` = 414 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 414 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(414, 'deDE', 'Seid gegrüßt, $C, und willkommen in Thelsamar!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 414 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(414, 'deDE', 'Und jetzt lasst mich mal versuchen... $B$BBeim Barte Magnis! Dieses Zeug haut einem die Birne weg! Und macht dabei die Gliedmaßen so leicht.$B$BIch fühle mich, als könnte ich fliegen!', 0);

-- Quest 466 - add missing data
-- https://de.classic.wowhead.com/quest=466/auf-der-suche-nach-pyrophor  + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 466 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(466, 'deDE', 'Wo ist denn das Erz, $N?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 466 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(466, 'deDE', 'Ihr habt das Erz! Gut gemacht, $N! Ich werde sofort jemanden damit arbeiten lassen. Wollen wir hoffen, dass er sich dabei nicht in die Luft sprengt!', 0);

-- Quest 291 - add missing data
-- https://de.classic.wowhead.com/quest=291/die-berichte + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 291 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(291, 'deDE', 'Hmm... Es scheint, als würden meine Wachen neuerdings jeden Bittsteller durchlassen. Nun, was wollt Ihr? Fasst Euch kurz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 291 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(291, 'deDE', '<Er überfliegt das Dokument.>$B$BVollmacht des KÖNIGS!? Hat Magni jetzt völlig den Verstand verloren? Und dieser schändliche Weißbart... hat die Dinge selbst in die Hand genommen, was? Der Senat wird nicht erfreut sein, hiervon zu hören, nicht das kleinste bisschen.$B$BWas, Ihr seid immer noch hier? Geht, bevor ich die Wachen rufe!', 0);

-- Creature 714 Quest Greeting - add missing data
-- https://www.youtube.com/watch?v=jRe4NcXEEqg 43:48
DELETE FROM `quest_greeting_locale` WHERE `ID` = 714 AND `locale` = 'deDE';
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(714, 0, 'deDE', 'Grüße, $C! Herrlicher Tag zum Jagen, meint Ihr nicht auch? Ich selbst hatte bereits ziemliches Glück mit den Ebern. Möchtet Ihr es auch versuchen?', 0);

-- Creature 1374 Quest Greeting - add missing data
-- https://www.youtube.com/watch?v=fae7kcF3E5I 37:33
DELETE FROM `quest_greeting_locale` WHERE `ID` = 1374 AND `locale` = 'deDE';
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(1374, 0, 'deDE', 'Verflucht sei die Brauerliga! Die Leute können sich die besten Zutaten besorgen, während wir uns hier verzweifelt ein bisschen Hopfen und Getreide zusammenkratzen müssen!$B$BWie gern würde ich denen als Ausgleich ein bisschen bittere Medizin zu schlucken geben...', 0);
