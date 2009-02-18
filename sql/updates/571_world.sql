ALTER TABLE spell_chain DROP COLUMN first_spell;
ALTER TABLE spell_chain DROP COLUMN rank;
ALTER TABLE spell_chain RENAME TO spell_required;
DELETE FROM spell_required WHERE req_spell=0;


