ALTER TABLE spell_learn_spell
  DROP IfNoSpell;

DELETE FROM spell_learn_spell WHERE entry IN (34769,13819,5784);

INSERT INTO spell_learn_spell (entry,spellID) VALUES
 (34769,33388),
 (13819,33388), 
 (5784,33388); 
