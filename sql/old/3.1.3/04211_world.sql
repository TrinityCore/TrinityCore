ALTER TABLE spell_pet_auras ADD effectId TINYINT( 3 ) UNSIGNED NOT NULL AFTER spell;
ALTER TABLE spell_pet_auras DROP PRIMARY KEY, ADD PRIMARY KEY(spell,effectId,pet);
