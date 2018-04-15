ALTER TABLE spell_required
DROP PRIMARY KEY,
ADD PRIMARY KEY (`spell_id`, `req_spell`);
