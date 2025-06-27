-- Fixed ruRU translation of the objectives field for quest 5624
UPDATE `quest_template_locale` SET `VerifiedBuild`=0, `Objectives`='Разыщите стражника Робертса и исцелите его раны, пользуясь "Малым исцелением" (уровень 2), а затем одарите его заклинанием "Слово силы: Стойкость", после чего вернитесь в Златоземье к жрице Жозетте.' WHERE `ID`=5624 AND `locale`='ruRU';
