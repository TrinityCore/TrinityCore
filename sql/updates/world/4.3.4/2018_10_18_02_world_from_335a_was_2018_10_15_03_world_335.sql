/*
-- Azuremyst Isle -- Azurmythosinsel

-- 9290 - Ausbildung zum Magier
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9290 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9290, "deDE", "Es ehrt mich, dass Ihr mich wegen meines Wissens aufsucht. Es gibt viel zu tun, wenn sich Eure magischen Fähigkeiten gänzlich entfalten sollen.$B$BSeit mehr als hundert Jahren lehre ich die Künste der arkanen Magie, Frost- und Feuerzauber. Auch auf dieser Welt kann ich ihre Macht spüren. Möchtet Ihr, dass ich Euch an meinen Kenntnissen teilhaben lasse?", 26972);

-- 9279 - Ihr habt überlebt!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9279 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9279, "deDE", "$N, bei meiner ewigen Seele, es ist gut, Euch zu sehen! Ich weiß nicht, warum die Exodar abgestürzt ist. Nur diejenigen von uns, die in diesem Teil des Schiffs waren, sind noch am Leben.$B$BUns bleibt nicht viel Zeit, wenn wir so viele wie möglich retten wollen!", 26972);

-- 9280 - Wiederaufladen der Heilkristalle
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9280 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9280, "deDE", "$N, habt Ihr schon das benötigte Mottenblut für die Heilkristalle? Überlebende sind über das gesamte Tal verstreut und die Zeit drängt!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9280 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9280, "deDE", "Wie bedauernswert, dass diese Kreaturen sterben mussten, damit wir überleben können - wahlloses Töten entspricht nicht dem Weg der $R. Wie auch immer, das von Euch gesammelte Blut wird unsere Heilkristalle wieder aufladen, somit war ihr Opfer nicht umsonst.", 26972);

-- 9283 - Rettet die Überlebenden!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9283 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9283, "deDE", "Dem Licht sei Dank! Ihr habt getan, was nur eine wahre Heldin vollbringen kann, $N! Jeder $R, den Ihr gerettet habt, verdankt Eurer Selbstlosigkeit sein Leben!$B$BBitte, nehmt diesen Vorratsbeutel. Ihr könnt ihn sicher besser gebrauchen als ich.", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Überlebende der Draenei gerettet", `VerifiedBuild`=26972 WHERE `ID` = 9283 AND `locale` = "deDE";

-- 9289 - Ausbildung zum Krieger
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9289 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9289, "deDE", "Es ist gut, dass Ihr meine Weisung ersucht. Ich habe seit Jahrhunderten junge Draeneikrieger ausgebildet, also werde ich Euch schon auf die eine oder andere Weise auf den richtigen Weg eines Kriegers verhelfen können. Ich sehe eine Zukunft als mächtiger $C für Euch voraus, aber nur, wenn Ihr auch wirklich beherzigt, was ich Euch beibringe.$B$BSeid Ihr bereit, junger $C?", 26972);

-- 9293 - Die große Mondweidenjagd
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9293 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9293, "deDE", "Der Zustand aller Proben muss einwandfrei sein, damit wir eine Chance haben, den See zu entseuchen.$B$BUns bleibt nicht viel Zeit, $C!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9293 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9293, "deDE", "Genau das habe ich gebraucht. Danke, $C!$B$BWährend Ihr unterwegs wart, habe ich bereits meine Ausrüstung aufgebaut, um die Proben auswerten zu können. Ich sollte lediglich ein paar Augenblicke benötigen.", 26972);

-- 9294 - Die Heilung des Sees
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9294 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9294, "deDE", "Euren Schilderungen zufolge hat der Neutralisierungswirkstoff funktioniert! Ich wünschte nur, ich wüsste, wie lange er anhält. Wir müssen den Energiekristall gänzlich aus dem See entfernen.$B$BDanke, $N! Ich werde Tedon bitten, den Neutralisierungswirkstoff sofort an einem der gefangenen Tiere auszuprobieren.", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Verwendet den Neutralisierungswirkstoff", `VerifiedBuild`=26972 WHERE `ID` = 9294 AND `locale` = "deDE";

-- 9303 - Immunisierung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9303 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9303, "deDE", "Je mehr wir tun können, um den Nistelwald aufzuräumen, desto schneller kann Zhanaa zurück an die Arbeit.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9303 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9303, "deDE", "Da jetzt viele der Eulkin immunisiert wurden, können wir uns auf unseren Aufbruch von hier konzentrieren, ohne die gesamte Eulkinpopulation ausrotten zu müssen.$B$BHier, sucht Euch etwas aus. Ihr habt eine so wunderbare Arbeit geleistet, Ihr verdient eine Belohnung!", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Nisteleulkin immunisiert", `VerifiedBuild`=26972 WHERE `ID` = 9303 AND `locale` = "deDE";

-- 9305 - Ersatzteile
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9305 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9305, "deDE", "Ich bin mir sicher, dass wir den Emitter mit den Ersatzteilen reparieren können! Mit etwas Glück, werden wir da draußen noch andere finden, mit denen wir uns in Verbindung setzen können.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9305 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9305, "deDE", "Lasst mich mal sehen.$B$BJa, ich denke, das wird gehen; gute Arbeit, $N! Der Emitter ist ziemlich komplex und deshalb kann die Reparatur ein Weilchen dauern. Ich sage Euch Bescheid, sobald ich fertig bin.$B$BSchaut in der Zwischenzeit bei Verteidiger Aldar vorbei und fragt ihn, ob er Euch brauchen kann.", 26972);

-- 9309 - Der vermisste Späher
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9309 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9309, "deDE", "Hilfe... Blutelfen! Ein... ein Hinterhalt. Ich habe... nicht mehr lange...", 26972);

-- 9311 - Blutelfenspionage
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9311 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9311, "deDE", "Danke, dass Ihr Euch um die Gutachterin gekümmert habt. Sie war ganz sicher ihre Anführerin. Ich versichere Euch, dass wir uns um den restlichen Haufen, der sich eventuell noch hier in der Nähe aufhält, kümmern werden.$B$BBitte, nehmt eine dieser Waffen als Zeichen unserer Dankbarkeit.", 26972);

-- 9312 - Der Emitter
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9312 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9312, "deDE", "Ja, ja! Ich glaube, ich habe den Emitter reparieren können! Hier, ich muss lediglich den letzten Kristall aktivieren und das sollte es gewesen sein.$B$BSeht, $N, der Emitter. Er scheint zu funktionieren... es erscheint jemand", 26972);

-- 9313 - Reise zur Azurwacht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9313 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9313, "deDE", "Ah, es ist gut, Euch wiederzusehen! Ich bin froh, dass wir beide unsere Emitter reparieren konnten, sonst hätten wir uns wohl nie gefunden. Sorgt Euch nicht, wir werden natürlich Hilfe und Vorräte ins Am'mental schicken.$B$BDa wir gerade von Hilfe sprechen... jetzt wo Ihr hier seid, könnt Ihr Euch ja mal umsehen und Euch bei den anderen vorstellen. Ich weiß, dass es jede Menge zu tun gibt.", 26972);

-- 9314 - Nachricht von der Azurwacht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9314 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9314, "deDE", "Oh, Ihr müsst einer der Überlebenden sein, von denen wir gehört haben!$B$BIch bin froh, dass Ihr gekommen seid. Keine Sorge, wir schicken jemanden los, der sich Aeuns verletztes Bein ansehen wird.$B$BIch will unbedingt alles über Eure aufregende Überlebensgeschichte hören! Wenn Ihr bis hierhergekommen seid, müsst Ihr sehr tapfer sein.", 26972);

-- 9371 - Botanikerin Taerix
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9371 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9371, "deDE", "Oh, welch Glück, dass Ihr hier seid! Wir haben Einiges zu tun.", 26972);

-- 9369 - Wiederaufladen der Heilkristalle
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9369 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9369, "deDE", "$N, habt Ihr schon das benötigte Mottenblut für die Heilkristalle? Überlebende sind über das gesamte Tal verstreut und die Zeit drängt!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9369 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9369, "deDE", "Wie bedauernswert, dass diese Kreaturen sterben mussten, damit wir überleben können - wahlloses Töten entspricht nicht dem Weg der $R. Wie auch immer, das von Euch gesammelte Blut wird unsere Heilkristalle wieder aufladen, somit war ihr Opfer nicht umsonst.", 26972);

-- 9409 - Eilige Lieferung!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9409 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9409, "deDE", "Hallo, $C. Was habt Ihr da? Ist das für mich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9409 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9409, "deDE", "Gute Arbeit! Das wird die erschöpften Heilkristalle wieder aufladen.$B$BDa Ihr nun schon einmal hier seid... ich hätte da noch eine Aufgabe für Euch, solltet Ihr gewillt sein?", 26972);

-- 9421 - Ausbildung zum Schamanen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9421 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9421, "deDE", "Ich bin Firmanvaar und mich aufzusuchen war weise von Euch. Ich bin dazu berufen, Schamanen den richtigen Weg zu weisen, besonders denen, die wie Ihr noch unerfahren sind.$B$BDer Schamanismus wird von uns Draenei gerade erst wiederentdeckt, $N. Ihr seid wahrhaft mutig, dieser Lehre zu folgen, denn unter Unseresgleichen wird sie mit Argwohn betrachtet.$B$BIch bin hier, solltet Ihr meine Unterweisung wünschen. ", 26972);

-- 9449 - Ruf der Erde
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9449 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9449, "deDE", "Es ist sehr kühn von Euch, meinen Rat zu ersuchen, nach all dem, was Eure Leute diesen Inseln angetan haben, $GFremder:Fremde;! Dennoch, Euer Mut spricht für sich, also werde ich Teile meines Wissens preisgeben.$B$BDie Erde unter Euren Füßen ist die Grundlage aller Dinge. Der Himmel, das Wasser, sogar große Feuer - alle lasten auf ihren Schultern. Während die anderen oft in wilden Stürmen toben, hält die Erde geduldig aus. Sie verleiht Eurem Innern Stärke und Kraft.$B$BJetzt werdet Ihr Euch beweisen, $C.", 26972);

-- 9450 - Ruf der Erde
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9450 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9450, "deDE", "Das Gleichgewicht der Elemente scheint noch immer gestört, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9450 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9450, "deDE", "Ihr habt Euch gut geschlagen, $C. Indem Ihr die Zahl der ruhelosen Geister reduziert habt, habt Ihr geholfen, das Gleichgewicht der Elemente wiederherzustellen, das Eure Leute unbeabsichtigterweise zerstört hatten.$B$BDas Gleichgewicht muss immer gewahrt bleiben. Auf Eurem Lebensweg als Schamane, dürft Ihr diese Lehre nie vergessen.", 26972);

-- 9451 - Ruf der Erde
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9451 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9451, "deDE", "Zusammen werden die Zerschlagenen und die Draenei ein tieferes Verständniss für die Mysterien der Elemente wiedererlangen.$B$BSeid Ihr mit der für die Herstellung Eures Erdtotems notwendigen Komponenten zurückgekehrt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9451 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9451, "deDE", "Ausgezeichnet, $N. Indem Ihr das Gleichgewicht der Elemente im Hain wieder hergestellt habt, habt Ihr auch für einen Einklang zwischen den Erdelementen dieser Welt und den Draenei gesorgt. Möglicherweise zeigen diejenigen unter uns, die unseren Weg ablehnen, nun mehr Verständnis?$B$BIch werde ein Totem für Euch erschaffen, das mit den Elementen der Erde verbunden ist. Mit dessen Hilfe werdet Ihr die Kräfte der Erde auf Euren Wunsch herbeirufen können. Mit mehr Weisheit, werden sich Euch auch noch mehr Geheimnisse der Erde erschließen.$B$BHier, nehmt Euer Totem, $C.", 26972);

-- 9452 - Schnapper - sehr, sehr lecker!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9452 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9452, "deDE", "Nehmt Euch vor den Murlocs in Acht: seltsame und extrem lästige kleine Kreaturen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9452 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9452, "deDE", "Ich hoffe Ihr hattet nicht zu viele Scherereien wegen der Murlocs, $N. Ich bin Euch sehr dankbar für alles, was Ihr getan habt.$B$BSoll ich Euch vielleicht das Angeln beibringen? Ich kann Euch sogar eine Angelrute und ein glänzendes Schmuckstück geben.", 26972);

-- 9453 - Findet Acteon!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9453 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9453, "deDE", "Was haltet Ihr von meiner Rüstung? Habe sie selbst hergestellt! Sie unterscheidet sich zwar etwas von den traditionellen Rüstungen, die wir normalerweise tragen, ist aber sehr bequem.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9453 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9453, "deDE", "Arme Diktynna... der Murloc hat ihr wohl einen ziemlichen Schrecken eingejagt.$B$B<Acteon seufzt.>$B$BHoffentlich heilen ihre Verletzungen bald...$B$BIhr haltet also nach Arbeit Ausschau, nun, davon gibt es bei der Azurwacht jede Menge!", 26972);

-- 9454 - Die große Mondweidenjagd
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9454 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9454, "deDE", "Die Bälge der Hirsche taugen nichts, dafür ist ihr Fleisch köstlich zart.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9454 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9454, "deDE", "Gut gemacht, $N, gut gemacht!$B$BHier, während Ihr fort wart, habe ich ein paar der Lenden, die Ihr mir gebracht habt, zubereitet. Vielleicht wollt Ihr ja auch das Rezept haben?", 26972);

-- 9455 - Seltsame Funde
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9455 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9455, "deDE", "Was habt Ihr gefunden? Wo?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9455 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9455, "deDE", "Wie konnte solch ein Ding nur im Magen eines Nachtpirschers enden? Könnten die Trümmer des Absturzes noch mehr Kreaturen verseucht haben?", 26972);

-- 9456 - Nachtpirscherjagd
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9456 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9456, "deDE", "Ich hoffe nur, dass es nicht schon zu spät ist...", 26972);

-- 9461 - Ruf des Feuers
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9461 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9461, "deDE", "Hallo, $N, ich habe Euch erwartet. Heute scheint Euer Tag zu sein, nicht?", 26972);

-- 9462 - Ruf des Feuers
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9462 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9462, "deDE", "Hallo, $N, ich habe Euch erwartet. Ich hoffe, Ihr seid bereit, Eure Ausbildung fortzusetzen. Die nächste Aufgabe wird schwierig werden.", 26972);

-- 9463 - Medizinische Notwendigkeit
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9463 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9463, "deDE", "Ich fürchte, ihr Zustand verschlimmert sich zusehends.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9463 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9463, "deDE", "Lasst uns hoffen, dass diese Salbe ihren Lebenswillen neu belebt!", 26972);

-- 9464 - Ruf des Feuers
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9464 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9464, "deDE", "Sehe ich richtig, dass das Funkeln in Euren Augen Euren Wunsch heranzuwachsen und zu verstehen widerspiegelt? Gut!$B$BTuluun hat Euch hierher geschickt, da er erkannt hat, dass Ihr fähig seid zu lernen und uns bei einem Problem zu helfen, das durch den Absturz der Exodar verursacht wurde.$B$BWir werden sehen.", 26972);

-- 9465 - Ruf des Feuers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9465 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9465, "deDE", "Habt Ihr die Fackel?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9465 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9465, "deDE", "Seht Ihr? Das Feuer geht niemals aus. Das ist das Werk Hauteurs. Es ist das Symbol seines Hochmuts. Flammen sollen verzehren, was sie selbst brennen lässt und dann sterben, um ein andermal wieder entfacht zu werden.$B$BIch würde Euch ja beim Löschen der Fackel helfen, aber sie muss noch brennen, damit Ihr Euch Hauteur stellen könnt. Lassen wir sie noch ein wenig länger am Leben.", 26972);

-- 9467 - Ruf des Feuers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9467 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9467, "deDE", "Sprecht erst wieder mit mir, wenn Ihr Hauteurs Asche habt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9467 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9467, "deDE", "Ihr habt heute eine besonders wichtige Lektion gelernt. Es ist die Geschichte vom Ende und vom neuanfang.$B$BAls wir und das erste Mal unterhielten, sagte ich Euch, dass das Feuer nicht nur Zerstörung verkörpert, sondern auch die erneuernde Kraft der Elemente. Durch Euer Handeln habt Ihr Hauteur zerstört und gleichzeitig gerettet, auf das er aus seiner Asche wiedergeboren wird.", 26972);

-- 9468 - Ruf des Feuers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9468 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9468, "deDE", "Ihr scheint Euch an ein paar Ecken versengt zu haben. Wie erging es Euch bei der Zusammenkunft mit der Flamme, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9468 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9468, "deDE", "Ihr habt das reinigende Feuer der Zerstörung erfahren und seid erneuert worden, $N. Dies ist nichts im Gegensatz zu dem Elend, das die Draenei derzeit erleiden. Ihr habt Hauteur vor sich selbst gerettet und somit Eure Bindung zu dem Element des Feuers in dieser Welt gesichert.", 26972);

-- 9473 - Eine alternative Alternative
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9473 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9473, "deDE", "Verschwendet keine Zeit, Junge.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9473 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9473, "deDE", "Seht, wie die Pflanze ihre wundersame Wirkung entfaltet.", 26972);

-- 9505 - Die Prophezeiung von Velen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9505 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9505, "deDE", "Ihr sagt, dass Ihr eines unserer Besatzungsmitglieder gefunden habt und dass sie schwer verletzt ist? Ich werde umgehend ein Mitglied meiner Besatzung in Euer Dorf entsenden!", 26972);

-- 9506 - Ein kleiner Anfang
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9506 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9506, "deDE", "Hattet Ihr Erfolg, Fremder?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9506 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9506, "deDE", "Ihr seid verdammt einfallsreich! Jetzt, da wir unsere Navigationsinstrumente zurückerhalten haben, sollte es leicht sein, herauszufinden, wie weit wir vom Kurs abgekommen sind.$B$BAber wartet, was ist das? Da ist etwas in der Karte eingerollt. Lasst mich mal sehen...$B$BDas sind Befehle von Mogul Raztunk der Venture Company. Laut diesen Plänen sind sie hier, um die Insel ihrer Kristalle zu berauben und unsere Schiffe zu kapern, wenn sie fertig sind!$B$BBei Bronzebarts buschiger Braue! Deswegen haben sie uns an Land gezwungen? Wie konnten sie von unseren Plänen erfahren?$B$BDas riecht nach einem Verräter...", 26972);

-- 9512 - Kräckas Jumboeintopf
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9512 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9512, "deDE", "Arrr... Jarr... beim Klabautermann... Eh, 'tschuldigung Junge, ich muss mal wieder 'n bisschen Pirat spielen, bevor ich's ganz vergesse...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9512 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9512, "deDE", "Erste Sahne, $GFremder:Fremde;. Das wird helfen, die Moral der Mannschaft wieder mächtig aufzumöbeln.", 26972);

-- 9513 - Die Rückeroberung der Ruinen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9513 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9513, "deDE", "Gelobt sei Elune! Mögen die ruhelosen Geister endlich Frieden finden.", 26972);

-- 9514 - Runenbesetzte Schrifttafel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9514 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9514, "deDE", "Ihr habt etwas entdeckt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9514 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9514, "deDE", "Ich kann diese Runen leider nicht entziffern, doch ich kenne jemanden, der dies zu tun vermag...", 26972);

-- 9515 - Kriegsherr Sriss'tiz
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9515 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9515, "deDE", "Nach dem Tod von Kriegsherr Sriss'tiz dürfte die Gefahr einer Nagainvasion fürs Erste gebannt sein...$B$BIch muss gestehen, es war falsch von mir, so schlecht über Euch zu denken, $N. Ihr habt bewiesen, dass Ihr weit entfernt seid vom Abschaum, der sich Archimonde nannte. Bitte nehmt dieses Geschenk der Nachtelfen als ein Zeichen der Freundschaft entgegen.", 26972);

-- 9523 - Marmor, Stein und Eisen bricht, aber uralte Nachtelfenrelikte nicht...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9523 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9523, "deDE", "Kommt nicht ohne uralte Relikte zurück.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9523 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9523, "deDE", "Mein Paps wäre stolz! Sein Junge hat bei den ersten Nachtelfenruinen, auf die er gestoßen ist, das große Los gezogen... dank Eurer Hilfe natürlich. Ja, macht Euch keine Sorgen, ich werde Euch nicht von der Entdeckung ausschließen. Euer Name ist $N, stimmt's? In Eisenschmiede werden alle von Euch hören.", 26972);

-- 9527 - Was noch bleibt
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9527 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9527, "deDE", "Meine Frau hieß Thalrisa und meine Tochter Magwin.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9527 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9527, "deDE", "Ich danke Euch, $N. Ihre Geister können nun in Frieden ruhen.", 26972);

-- 9528 - Ein Hilferuf
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9528 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9528, "deDE", "<Freudentränen strömen über Cowlens Gesicht.>$B$BWie kann ich Euch dafür jemals genug danken, $N? Bitte, nehmt dieses Erbstück. Es symbolisiert die heiligen Bande der Freundschaft sowie das Vertrauen und die Verbundenheit zwischen den Nachtelfen. Ihr seid wie ein Bruder für mich - vom heutigen Tag bis in alle Ewigkeit...", 26972);

-- 9530 - Einen Plan aus Hecken
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9530 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9530, "deDE", "Ich liebe es, wenn ein Plan aufgeht...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9530 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9530, "deDE", "Ich muss Euch warnen: Das, was ich als Nächstes von Euch verlangen werde, ist sehr gefährlich. Ich würde es Euch nicht verdenken, wenn Ihr mir dabei lieber nicht aushelfen wollt, $N.", 26972);

-- 9531 - Laubangriff
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9531 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9531, "deDE", "Der Verräter wird noch bereuen, dass er sich mit dem Marinekommando der Allianz angelegt hat!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9531 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9531, "deDE", "Ich kann es nicht glauben! Der Gnom war es, die ganze Zeit über... Ich hätte es wissen sollen!", 26972);
UPDATE `quest_template_locale` SET `ObjectiveText1`="Verräter entlarvt", `VerifiedBuild`=26972 WHERE `ID` = 9531 AND `locale` = "deDE";

-- 9537 - Keine Gnade mit dem Gnom
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9537 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9537, "deDE", "Habt Ihr den elenden Lügner gefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9537 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9537, "deDE", "Unglaublich! Das gehörte alles zu ihrem perfiden Plan!$B$BIhr müsst diese Informationen dem König und Euren eigenen Anführern zukommen lassen. Die Folgen sind erschütternd.", 26972);

-- 9538 - Erlernen der Sprache
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9538 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9538, "deDE", "Das Totem weist zahlreiche Symbole der Fibel auf. Ihr könnt Eulen, Bären, Wölfe und Hirsche erkennen, die darauf eingraviert wurden.$B$BEuch fällt eine seltsame Ansammlung von Symbolen auf, die Eure Lippen das Wort A-K-I-D-A formen lassen.", 26972);

-- 9539 - Totem von Coo
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9539 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9539, "deDE", "Das Totem weist zahlreiche Symbole der Fibel auf. Ihr könnt Eulen, Bären, Wölfe und Hirsche erkennen, die darauf eingraviert wurden.$B$BEuch fällt eine seltsame Ansammlung von Symbolen auf, die Eure Lippen das Wort C-O-O formen lassen.", 26972);

-- 9540 - Totem von Tikti
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9540 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9540, "deDE", "Das Totem weist zahlreiche Symbole der Fibel auf. Ihr könnt Eulen, Bären, Wölfe und Hirsche erkennen, die darauf eingraviert wurden.$B$BEuch fällt eine seltsame Ansammlung von Symbolen auf, die Eure Lippen das Wort T-I-K-T-I formen lassen.", 26972);

-- 9541 - Totem von Yor
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9541 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9541, "deDE", "Das Totem weist zahlreiche Symbole der Fibel auf. Ihr könnt Eulen, Bären, Wölfe und Hirsche erkennen, die darauf eingraviert wurden.$B$BEuch fällt eine seltsame Ansammlung von Symbolen auf, die Eure Lippen das Wort Y-O-R formen lassen.", 26972);

-- 9542 - Totem von Vark
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9542 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9542, "deDE", "Beim Lesen des Totems formen Eure Lippen das Wort V-A-R-K. Ihr versteht die Bedeutung, sie lautet Gerechtigkeit.", 26972);

-- 9544 - Die Prophezeiung von Akida
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9544 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9544, "deDE", "[Furbolg] Die Prophezeiung sprach von jemandem, der sich erheben und uns aus dem gewaltsamen Griff der Sichelklauen befreien würde; dass die Geister selbst die Ankunft dieses Helden verkünden würden.$B$BJetzt seid Ihr gekommen.$B$BIch beuge mich vor Euch in Demut, Großartiger.", 26972);

-- 9555 - Ruf des Feuers
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9555 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9555, "deDE", "Seid gegrüßt. Es ist stets ermutigend, einen Draenei zu treffen, der sich dem Weg des Schamanismus eröffnet. Es gibt leider nur wenige.$B$BIhr habt nun gelernt, das Feuer nicht nach seinem Äußeren zu beurteilen, genauso, wie Ihr mein Äußeres nicht beurteilen solltet.$B$BIhr seid hier, weil Ihr bereit seid, Euer Feuertotem zu erschaffen.", 26972);

-- 9559 - Tannenruhfeste
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9559 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9559, "deDE", "Jahrhunderte lang lebten wir in verhältnismäßigem Frieden mit den Kreaturen des Landes. Vor einigen Monaten begann Kurz, dunkle Vorzeichen zu sehen. Der Frieden, den wir so lange genossen hatten, schien in Gefahr. Keiner konnte die Ausmaße dieser Katastrophe erahnen!$B$BUnd so kam es, dass die Götter unser Land straften und sowohl Feinde als auch Freunde gegen uns richteten. Aber es gab da noch etwas... inmitten des Chaos sollte sich ein Held erheben: ein Held, in dessen Adern nicht das Blut der Tannenruh fließt. Der Auserwählte würde uns vor der Zerstörung erretten.$B$BDer prophezeite Held wart Ihr.", 26972);
UPDATE `quest_template_locale` SET `Details`="$GAuserwählter:Auserwählte;, Ihr müsst nach Norden zur Heimstätte meiner Leute reisen – zur Tannenruhfeste. Dort werdet Ihr auf Eure schrecklichste Herausforderung treffen.$B$BGeht jetzt, der Oberhäuptling der Tannenruhfeste erwartet Euch.", `VerifiedBuild`=26972 WHERE `ID` = 9559 AND `locale` = "deDE";

-- 9560 - Biester aus der Apokalypse!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9560 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9560, "deDE", "Es sind hässliche kleine Kreaturen. Sogar der blinde Behüter könnte sie sehen... und er ist blind.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9560 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9560, "deDE", "Nicht nur, dass die Prophezeiung wahr ist, nein, diese Rüstung ist ebenso erstaunlich! Eine Rüstung für einen Helden! Ich werde sie Euch für einen besonders günstigen Preis verkaufen, Fellloser.$B$BDas war ein Scherz... das erste Teil gibt's umsonst.", 26972);

-- 9562 - Murlocs... Warum hier? Warum jetzt?
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9562 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9562, "deDE", "Ein Murloc hat mir in den Hintern getreten und mich angespuckt... und das am helllichten Tag!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9562 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9562, "deDE", "Mmmmm... köstliches Getreide... Parkat wird sich freuen!", 26972);

-- 9564 - Gurfs Würde
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9564 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9564, "deDE", "Ist das etwa das, was ich vermute?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9564 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9564, "deDE", "<Gurf spuckt auf den Fellfetzen und versucht ihn auf die kahle Stelle auf seinem Hintern anzubringen.>$B$BDas muss vorerst halten! Ich hoffe, dass einer der Schamanen den Schaden wieder beheben kann.", 26972);

-- 9565 - Sucht in der Tannenruhfeste
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9565 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9565, "deDE", "Der Blutkristall verstrahlt eine kränkliche Aura, die in das Wasser im Keller sickert.", 26972);

-- 9566 - Blutkristalle
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9566 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9566, "deDE", "Von den Blutkristallen, wie Ihr sie gesehen habt, wurden von meinen Spähern noch viele weitere im Norden gesichtet.$B$BIch danke Euch für die Hilfe, muss Euch nun aber bitten zu gehen, weil ich mich noch mit den Ältesten beraten muss. Ich werde nach Euch rufen lassen, sobald ich mit den anderen Ältesten des Dorfes gesprochen habe.", 26972);

-- 9570 - Kurken lauert
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9570 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9570, "deDE", "<Kurz schnaubt Euch an.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9570 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9570, "deDE", "Der Held ist erfolgreich zurückgekehrt!$B$BDie Prophezeihung hat sich fast vollständig bewahrheitet. Jetzt zu dem Balg...", 26972);

-- 9571 - Kurkens Balg
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9571 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9571, "deDE", "Hallo, Held!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9571 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9571, "deDE", "Das ist die stärkste Rüstung, die ich jemals angefertigt habe! Nutzt sie weise, $N.", 26972);

-- 9573 - Häuptling Oomooroo
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9573 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9573, "deDE", "Das könnte die Gelegenheit sein, auf die wir so lange gewartet haben! Ich werde sofort angreifen lassen! Der Stamm der Tannenruhfeste dankt Euch für Euren Einsatz, $N!", 26972);

-- 9602 - Unheilvolle Mitteilung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9602 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9602, "deDE", "Ihr seid zurück!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9602 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9602, "deDE", "<Exarch Menelaous nimmt die Mitteilung von Euch entgegen und beginnt sie zu lesen.>$B$BVerdammt... verdammt sie alle in den Nether. Sie hatten einen Spion, der sie über all unsere Aktivitäten informiert hat! Und seit wann?$B$BIch werde sofort Velen informieren!$B$BIhr habt uns einen großen Dienst erwiesen, $N. Haltet die Augen offen, ich werde mich an Euch wenden, sobald der Prophet mir mitgeteilt hat, was es zu tun gilt.", 26972);

-- 9603 - Betten, Verbände und noch viel mehr
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9603 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9603, "deDE", "Guten Tag, $N. Interessiert Ihr Euch für einen Hippogryphenflug?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9603 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9603, "deDE", "Ihr müsst also zu der Exodar?$B$BDas ist ein ganz schön weiter Weg, aber keine Sorge, ich weiß schon, wie Ihr auf dem schnellsten Weg an Euer Ziel kommt.", 26972);

-- 9604 - Auf dem Rücken eines Hippogryphen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9604 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9604, "deDE", "Seid gegrüßt, Freund. Ihr seht aus, als hättet Ihr einen langen Weg hinter Euch. Wie kann ich Euch helfen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9604 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9604, "deDE", "Ah, Ihr habt also Chellans Liste mitgebracht. Ausgezeichnet! Ich hatte gehofft, dass ich sie heute erhalten würde. Lasst mal sehen, was sie braucht.$B$B<Nurguni überfliegt die Liste und beginnt verschiedene Gegenstände in eine Kiste zu packen.>$B$BDas sind fast alle Dinge, die sie aufgelistet hat. Die Teile für die Betten sind einfach zu groß, um auf einem Hippogryphen transportiert werden zu können. Ich werde dafür sorgen, dass sie mit einem Wagen nachgeliefert werden.", 26972);

-- 9605 - Hippogryphenmeister Stephanos
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9605 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9605, "deDE", "Wohin wollt Ihr, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9605 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9605, "deDE", "Ihr wollt also mit dieser Kiste zurück zur Azurwacht? Kein Problem, $C. Sagt einfach Bescheid, wenn's losgehen soll.", 26972);

-- 9606 - Zurück zu Versorgerin Chellan
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9606 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9606, "deDE", "Willkommen zurück, $N. Konnte Nurguni Euch alle Vorräte mitgeben, die auf der Liste standen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9606 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9606, "deDE", "<Ihr überreicht die Kiste und erklärt, dass Nurguni dafür sorgt, dass die größeren Gegenstände mit einem Wagen nachgeliefert werden.>$B$BGroßartig! Ich werde jetzt endlich ein paar Lagerstätten und eine Versorgungsstation einrichten können. Hier wird man sich in Zukunft um Verwundete und mögliche weitere Überlebende kümmern können.$B$BIch weiß gar nicht, wie ich Euch für Eure Hilfe danken kann, $N. Die Anerkennung von mir und den Verteidigern der Azurwacht ist Euch sicher.", 26972);

-- 9612 - Herzlichen Dank!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9612 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9612, "deDE", "Gut gemacht, $N. Sehr gut gemacht! Ihr seid $Gein besonderer:eine besondere; $R - Weiter als andere in Eurem Alter. Nehmt dies als Belohnung!", 26972);

-- 9616 - Banditen!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9616 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9616, "deDE", "Ja? Ich bin wirklich sehr beschäftigt, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9616 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9616, "deDE", "Beim bartlosen, quadratischen Schädel von O'ros! Gut, dass Ihr das zu mir gebracht habt, $N. Diese Blutelfen haben es... nun ja, auf Blut abgesehen. Velen wird davon sofort in Kenntnis gesetzt werden! Nehmt dies als Anerkennung.", 26972);

-- 9622 - Warnt vor der Gefahr
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9622 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9622, "deDE", "Visionen sagt Ihr? Interessant... und diese Prophezeiung hat sich also bewahrheitet?$B$BIhr sagt jedoch, dass man den Kraftkern der Exodar gesehen hat? O'ros erschien auch in der Vision? Was kann das nur bedeuten?", 26972);

-- 9623 - Reifer werden
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9623 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9623, "deDE", "<Torallius rückt seine Augenklappe zurecht und sieht Euch an.>$B$BHaben wir der Hand von Argus nichts Besseres anzubieten?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9623 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9623, "deDE", "<Torallius seufzt.>$B$BNun gut, lasst mich einen Blick auf diese Befehle werfen.", 26972);

-- 9625 - Elekk sind starker Tobak
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9625 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9625, "deDE", "Naja, zumindest habt Ihr's bis hierher geschafft! Jetzt schicken wir Euch lieber an die Arbeit, bevor Ihr noch zertrampelt werdet.", 26972);

-- 9798 - Blutelfenpläne
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9798 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9798, "deDE", "Was habt Ihr denn da?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9798 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9798, "deDE", "Hier, lasst mich einen Blick auf diese Pläne werfen.$B$BDie Blutelfen sind uns hierher gefolgt? Sie sind durch und durch bösartig und sollten ganz und gar ausgelöscht werden!$B$B<Der Verteidiger braucht einen Moment, um sich wieder zu fassen.>$B$BEntschuldigung, ich hätte mich beherrschen sollen. Wir stehen für die Entdeckung dieser Informationen in Eurer Schuld, $N.", 26972);

-- 9799 - Botanische Hilfsarbeit
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9799 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9799, "deDE", "Hallo, $C. Habt Ihr die Blumen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9799 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9799, "deDE", "Das sieht mir nach ein paar guten Exemplaren aus. Danke für Eure kleine Hilfsarbeit. Sobald ich Zeit zum Untersuchen der Blumen habe, sollte ich bestimmen können, was es zur Wiederherstellung der Felder bedarf.", 26972);

-- 10302 - Unberechenbare Mutanten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10302 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10302, "deDE", "Ihr seid fertig? Das sind gute Nachrichten. Hoffentlich finden wir einen Weg, bei dem wir diese mutierten Kreaturen nicht töten müssen.$B$BIch glaube, ich habe einen Plan entwickelt, der uns eine alternative Lösungsmöglichkeit für unser Problem bietet, aber ich werde Eure Hilfe brauchen.", 26972);

-- 10303 - Die Blutelfen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10303 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10303, "deDE", "Diese Blutelfen wollen uns alle töten. Wie können wir sie davon abhalten?", 26972);

-- 10304 - Verteidiger Aldar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10304 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10304, "deDE", "$N, richtig? Ich habe viel Gutes über Euch und die Arbeit, die Ihr in der kurzen Zeit, in der Ihr hier wart, geleistet habt, gehört.$B$BWir sind auf Eure Hilfe angewiesen, um die Dinge wieder zu normalisieren. Ich bin mir sicher, dass auch Zhanaa da drüben Eure Hilfe brauchen könnte.", 26972);

-- 10324 - Die große Mondweidenjagd
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10324 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10324, "deDE", "Die Bälge der Böcke sind grob und stark und halten das Fleisch zäh. Es ist kaum essbar, aber wir können es für andere Zwecke einsetzen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10324 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10324, "deDE", "Wunderbar! Ihr entwickelt Euch zu einem beachtlichen Jäger, $N.$B$BWürdet Ihr mir gerne ähnlich sehen? Nun, hier ist Eure Chance! Während Ihr auf der Jagd wart, habe ich diese Gegenstände aus den Bälgen, die ich hier noch herumliegen hatte, gefertigt.", 26972);

-- 10428 - Der vermisste Fischer
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10428 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10428, "deDE", "Meine Familie... Was habe ich getan... Was hätte ich tun sollen?$B$BWarum werde ich so bestraft?", 26972);
*/
